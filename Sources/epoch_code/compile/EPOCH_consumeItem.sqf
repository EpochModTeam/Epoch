/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Epoch consume item function

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/EPOCH_consumeItem.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_buildClass","_buildingCountLimit","_buildingJammerRange","_canCapacity","_cfgBaseBuilding","_cfgItemInteractions","_color","_currentDMG","_currentFuel","_currentHIT","_fuelCapacity","_ghostClass","_highestDMG","_inputCount","_interactAttributes","_interactOption","_interactReturnOnUse","_isOk","_isStorage","_magazineSize","_magazineSizeMax","_magazinesAmmoFull","_msg","_newDMG","_newFuel","_object","_otherObjects","_output","_paintCanColor","_paintCanIndex","_partCheck","_pos","_removeItem","_transportFuel","_unifiedInteract","_vehicle","_vehicles"];
//[[[end]]]

EPOCH_InteractedItem params ["_text","_item","_pic"];

_cfgBaseBuilding = 'CfgBaseBuilding' call EPOCH_returnConfig;
_cfgItemInteractions = ["CfgItemInteractions", _item] call EPOCH_returnConfigV2;
// _cfgItemInteractions = (('CfgItemInteractions' call EPOCH_returnConfig) >> _item);

_interactOption = getNumber(_cfgItemInteractions >> "interactAction");
_interactAttributes = getArray(_cfgItemInteractions >> "interactAttributes");
_interactReturnOnUse = getText(_cfgItemInteractions >> "interactReturnOnUse");

_inputCount = count _this;
if (_inputCount >= 1) then {
    _interactOption = param [0,0];
};
if (_inputCount >= 2) then {
    _interactAttributes = param [1,[]];
};
if (_inputCount >= 3) then {
    _interactReturnOnUse = param [2,""];
};

// diag_log format["DEBUG: %1",[_interactOption,_interactAttributes,_interactReturnOnUse]];

_removeItem = {([player,_this] call BIS_fnc_invRemove) == 1};

_unifiedInteract = {
	private _removed = _item call _removeItem;
	if (_removed) then {
		if (_interactReturnOnUse != "") then {
			_interactReturnOnUse call EPOCH_fnc_addItemOverflow;
		};
		{
			_output = _x call EPOCH_giveAttributes;
			if (_output != "") then {
				[_output, 5] call Epoch_message;
			};
		} foreach _interactAttributes;
	};
	_removed
};

switch _interactOption do {
	case 0: {
		_magazineSizeMax = getNumber (configfile >> "CfgMagazines" >> _item >> "count");
		// allow repack for all magazines with greater than 1 bullet
		if (_magazineSizeMax > 1) then {
			[_item,_magazineSizeMax] spawn {
				params ["_item","_magazineSizeMax"];
				if (player == vehicle player) then {
					closeDialog 0;
					player playMove 'AinvPknlMstpSnonWrflDnon_medic0';
					player playMove 'AinvPknlMstpSnonWrflDnon_medicEnd';
					uisleep 5;
				};
				_magazineSize = 0;
				_magazinesAmmoFull = magazinesAmmoFull player;
				{
					if (_item isEqualTo (_x select 0)) then {
						if (!(_x select 2)) then {
							_magazineSize = _magazineSize + (_x select 1);
						};
					};
				} forEach _magazinesAmmoFull;
				player removeMagazines _item;
				for "_i" from 1 to floor (_magazineSize / _magazineSizeMax) do
				{
					player addMagazine [_item, _magazineSizeMax];
				};
				if ((_magazineSize % _magazineSizeMax) > 0) then {
					player addMagazine [_item, floor (_magazineSize % _magazineSizeMax)];
				};
				["Ammo Repacked", 5] call Epoch_message;
			};
		};
	};
	case 1: _unifiedInteract; // Eat 1
	case 2: _unifiedInteract; //Drink 2
	case 3: { // Build 3
		closeDialog 0;
		_buildingJammerRange = ["CfgEpochClient", "buildingJammerRange", 75] call EPOCH_fnc_returnConfigEntryV2;
		_buildingCountLimit = ["CfgEpochClient", "buildingCountLimit", 200] call EPOCH_fnc_returnConfigEntryV2;
		_partCheck = _item in (magazines player);

		_buildClass = getText(_cfgItemInteractions >> "buildClass");
		if (_buildClass != "" && _partCheck) then {
			_isStorage = getNumber(_cfgItemInteractions >> "isStorage");

			_isOk = if (_isStorage == 1 || _buildClass isKindOf "Secure_Storage_Temp") then { EPOCH_StorageSlotsCount > 0 } else { EPOCH_BuildingSlotCount > 0 };

			if (isNil "EPOCH_simulSwap_Lock") then {
				if !(isNil "_isOk") then {
					if (_isOk) then {

						if (_buildClass call EPOCH_isBuildAllowed) then {

							if (EPOCH_playerEnergy > 0) then {

								EPOCH_buildMode = 1;
								EPOCH_buildDirection = 0;

								// base building
								_pos = player modelToWorldVisual[0, 5, 0];
								_pos set[2, getPosATL player select 2];

								if (_buildClass isKindOf "ThingX") then {
									// prevent spawning if another simulated object exists still
									_otherObjects = nearestObjects[player, [_buildClass], _buildingJammerRange];
									if (_otherObjects isEqualTo []) then {
										_object=createVehicle[_buildClass,_pos,[],0,"CAN_COLLIDE"];
										_object setDir ((getDir player) - 180);
										[format["Press '%1' to drop object.", "1"], 5] call Epoch_message;
										if (([player, _item] call BIS_fnc_invRemove) == 1) then {
											[_object] spawn EPOCH_simulSwap;
										};
									}
									else {
										["Building Disallowed: Frequency Unstable", 5] call Epoch_message;
									};
								}
								else {
									// use ghost GhostPreview if set
									_ghostClass = getText(_cfgBaseBuilding >> _buildClass >> "GhostPreview");
									if !(_ghostClass isEqualTo "") then {
										_buildClass = _ghostClass;
									};
									_object=createVehicle[_buildClass,_pos,[],0,"CAN_COLLIDE"];
									_object setDir ((getDir player) - 180);
									[format["Press '%1' to drop object.", "1"], 5] call Epoch_message;
									[_object,_item] spawn EPOCH_staticMove;
								};
							}
							else {
								["Need Energy", 5] call Epoch_message;
							};
						};
					} else {
						["World limit reached", 5] call Epoch_message;
					};
				};
			};
		};
	};
	case 4: { // Refuel 4
		if !(player == vehicle player) exitwith {
			["Fill from outside!", 5] call Epoch_message;
		};
		_vehicles = player nearEntities [["LandVehicle","Ship","Air","Tank"], 30];
		if (cursorTarget in _vehicles) then {
			_vehicle = cursorTarget;
			_currentFuel = fuel _vehicle;
			_canCapacity = _interactAttributes param [0,10];
			_fuelCapacity = getNumber (configfile >> "CfgVehicles" >> (typeOf _vehicle) >> "fuelCapacity");
			_currentFuel = _currentFuel * _fuelCapacity;
			_newFuel = _currentFuel + _canCapacity;
			_newFuel = _newFuel / _fuelCapacity;

			if (_item call _removeItem) then {
				[_interactReturnOnUse,_vehicle,_newFuel] spawn {
					params ["_interactReturnOnUse","_vehicle","_newFuel"];
					closeDialog 0;
					player playMove 'AinvPknlMstpSnonWrflDnon_medic0';
					player playMove 'AinvPknlMstpSnonWrflDnon_medicEnd';
					uisleep 5;
					_interactReturnOnUse call EPOCH_fnc_addItemOverflow;
					[_vehicle,_newFuel,player,Epoch_personalToken] remoteExec ["EPOCH_server_fillVehicle",2];
					["Fuel Added", 5] call Epoch_message;
				};
			};
		};
	};
	case 5: {
		if !(player == vehicle player) exitwith {
			["Siphon from outside!", 5] call Epoch_message;
		};
		_vehicles = player nearEntities [["LandVehicle","Ship","Air","Tank"], 30];
		_canCapacity = _interactAttributes param [0,10];
		if (cursorTarget in _vehicles) then {
			_vehicle = cursorTarget;
			_fuelCapacity = getNumber (configfile >> "CfgVehicles" >> (typeOf _vehicle) >> "fuelCapacity");
			_newFuel = (((fuel _vehicle) * _fuelCapacity) - _canCapacity) / _fuelCapacity;
			if (_newFuel > 0) then {
				if (_item call _removeItem) then {
					[_interactReturnOnUse,_vehicle,_newFuel] spawn {
						params ["_interactReturnOnUse","_vehicle","_newFuel"];
						closeDialog 0;
						player playMove 'AinvPknlMstpSnonWrflDnon_medic0';
						player playMove 'AinvPknlMstpSnonWrflDnon_medicEnd';
						uisleep 5;
						_interactReturnOnUse call EPOCH_fnc_addItemOverflow;
						[_vehicle,_newFuel,player,Epoch_personalToken] remoteExec ["EPOCH_server_fillVehicle",2];
						["Fuel Siphoned", 5] call Epoch_message;
					};
				};
			} else {
				["Not Enough Fuel", 5] call Epoch_message;
			};
		} else {

			// find any other nearby fuel sources
			_transportFuel = 0;
			{
				_transportFuel = _transportFuel + getNumber (configFile >> "CfgVehicles" >> (typeOf _x) >> "transportFuel");
			} forEach (player nearObjects["ALL", 6]);

			if (_transportFuel > _canCapacity) then {
				if (_item call _removeItem) then {
					[_interactReturnOnUse] spawn {
						params ["_interactReturnOnUse"];
						closeDialog 0;
						player playMove 'AinvPknlMstpSnonWrflDnon_medic0';
						player playMove 'AinvPknlMstpSnonWrflDnon_medicEnd';
						uisleep 5;
						_interactReturnOnUse call EPOCH_fnc_addItemOverflow;
						["Fuel Siphoned", 5] call Epoch_message;
					};
				};
			} else {
				["Not Enough Fuel", 5] call Epoch_message;
			};
		};
	};
	case 6: _unifiedInteract; //Clean -25
	case 7: _unifiedInteract; //Warm + 1
	case 8: _unifiedInteract; //Cold -1
	case 9: _unifiedInteract; //Energy 100
	case 10: { // Repair 10 - Lite
		if !(player == vehicle player) exitwith {
			["Repair from outside!", 5] call Epoch_message;
		};
		_vehicles = player nearEntities [["LandVehicle","Ship","Air","Tank"], 30];
		_vehicle = cursorTarget;
		if (_vehicle in _vehicles) then {

			if (_item call _removeItem) then {
				[_vehicle] spawn {
					params ["_vehicle"];
					closeDialog 0;
					player playMove 'AinvPknlMstpSnonWrflDnon_medic0';
					player playMove 'AinvPknlMstpSnonWrflDnon_medicEnd';
					_vehicle say3d 'vehicle_repair';
					uisleep 5;
					_highestDMG = 0;
					_currentHIT = -1;
					_currentDMG = 0;
					{
						_currentDMG = _x;
						if (_currentDMG > _highestDMG) then {
							_highestDMG = _currentDMG;
							_currentHIT = _forEachIndex;
						};
					}forEach ((getAllHitPointsDamage _vehicle) param [2,[]]);
					if (_highestDMG > 0) then {
						_newDMG = ((_highestDMG - 0.5) max 0);
						if (local _vehicle) then {
							[_vehicle, [[_currentHIT, _newDMG]] ] call EPOCH_client_repairVehicle;
						} else {
							[_vehicle,[[_currentHIT,_newDMG]],player,Epoch_personalToken] remoteExec ["EPOCH_server_repairVehicle",2];
						};
					} else {
						if ((damage _vehicle) > 0) then {
							[_vehicle,["ALL",0],player,Epoch_personalToken] remoteExec ["EPOCH_server_repairVehicle",2];
						};
					};
					["Vehicle Partially Repaired", 5] call Epoch_message;
				};
			};
		};
	};
	case 11: { // Repair 11 - Heavy
		if !(player == vehicle player) exitwith {
			["Repair from outside!", 5] call Epoch_message;
		};
		_vehicles = player nearEntities [["LandVehicle","Ship","Air","Tank"], 30];
		_vehicle = cursorTarget;
		if (_vehicle in _vehicles) then {
			if (_item call _removeItem) then {
				[_vehicle] spawn {
					params ["_vehicle"];
					closeDialog 0;
					player playMove 'AinvPknlMstpSnonWrflDnon_medic0';
					player playMove 'AinvPknlMstpSnonWrflDnon_medicEnd';
					uisleep 5;
					_vehicle say3d 'vehicle_repair';
					[_vehicle,["ALL",0],player,Epoch_personalToken] remoteExec ["EPOCH_server_repairVehicle",2];
					["Vehicle Fully Repaired", 5] call Epoch_message;
				};
			};
		};
	};

	// case 12  consume paincan and set texture on base object (only if has slot and is static)
	case 12: {
		closeDialog 0;
		_vehicles = player nearObjects["Const_WoodWalls_static_F", 5];
		_vehicle = cursorTarget;
		if (_vehicle in _vehicles) then {
			if ("" call EPOCH_isBuildAllowed) then {
				_color = getArray(_cfgBaseBuilding >> (typeOf _vehicle) >> "availableTextures");
				if !(_color isEqualTo[]) then {

					if (_item call _removeItem) then {

						// find _paintCanIndex from config
						_paintCanIndex = getNumber(_cfgItemInteractions >> "textureIndex");
						_paintCanColor = getText(_cfgItemInteractions >> "colorName");

						[_vehicle,_paintCanIndex,player,Epoch_personalToken] remoteExec ["EPOCH_server_paintBUILD",2];

						[format["Wall Painted %1", _paintCanColor], 5] call Epoch_message;
					};
				};
			}
			else {
				["Disallowed", 5] call Epoch_message;
			};
		};
	};

	case 13: { //Heal Player
		_vehicles = player nearEntities[["Epoch_Male_F", "Epoch_Female_F"], 6];
		_vehicle = cursorTarget;
		if !(_vehicle in _vehicles) then {
			_vehicle = player;
		};
		if (damage _vehicle != 0 || {_x > 0} count ((getallhitpointsdamage _vehicle) select 2) > 0) then {
			if (_item call _removeItem) then {
				[_vehicle] spawn {
					params ["_vehicle"];
					if (player == vehicle player) then {
						closeDialog 0;
						player playMove 'AinvPknlMstpSnonWrflDnon_medic0';
						player playMove 'AinvPknlMstpSnonWrflDnon_medicEnd';
						uisleep 5;
					};
					[_vehicle,["ALL",0],player,Epoch_personalToken] remoteExec ["EPOCH_server_repairVehicle",2];
					if (_vehicle isEqualTo player) then {
						["Healed yourself", 5] call Epoch_message;
					} else {
						["Healed other player", 5] call Epoch_message;
					};
				};
			};
		};
	};

	case 14: { // Unpack Backpack
		if (_item call _removeItem) then {
			[_interactReturnOnUse,player,Epoch_personalToken] remoteExec ["EPOCH_server_unpackBackpack",2];
			["Unpacked backpack", 5] call Epoch_message;
		};
	};

	case 15: { // Read
		_msg = getArray(missionConfigFile >> "CfgReadingDocuments" >> _item >> "displayMessage");
		if!(_msg isEqualTo [])then{
			{
				[_x,5] call Epoch_message;
			}forEach _msg;
		}else{
			["This document can't be read yet. Blame DirtySanchez!",5] call Epoch_message;
		};
	};

	case 16: { // Morphine
		_vehicle = player;
		if (damage _vehicle != 0 || {_x > 0} count ((getallhitpointsdamage _vehicle) select 2) > 0) then {
			if (call _unifiedInteract) then {
				[_vehicle,_item] spawn {
					params ["_vehicle","_item"];
					if (player == vehicle player) then {
						closeDialog 0;
						player playMove 'AinvPknlMstpSnonWrflDnon_medic0';
						player playMove 'AinvPknlMstpSnonWrflDnon_medicEnd';
						uisleep 5;
					};
					private _out = [];
					{
						if (_x > 0) then {
							_out pushback [_foreachindex,((_x - 0.2) min 0.45) max 0];
						};
					}forEach ((getAllHitPointsDamage _vehicle) param [2,0]);
					if (_out isequalto []) then {
						if ((damage _vehicle) > 0) then {
							_out = ["ALL",0];
						};
					};
					if !(_out isequalto []) then {
						[_vehicle,_out,player,Epoch_personalToken] remoteExec ["EPOCH_server_repairVehicle",2];
					};
					[format["Used %1 on yourself",_item call EPOCH_itemDisplayName], 5] call Epoch_message;
				};
			};
		} else {
			[format["%1 is not needed at this time",_item call EPOCH_itemDisplayName], 5] call Epoch_message;
		};
	};

	default {
		["Found nothing", 5] call Epoch_message;
	};
};
