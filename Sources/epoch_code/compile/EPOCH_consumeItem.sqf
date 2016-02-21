/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Epoch consume item function

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_code/compile/EPOCH_consumeItem.sqf
*/
private ["_type","_interactOption","_previewClass","_object","_isStorage","_isOk","_buildClass","_vehicle","_currentFuel","_canCapacity","_fuelCapacity","_newFuel","_vehicles","_highestDMG","_currentHIT","_currentDMG","_newDMG","_paintCanIndex","_paintCanColor","_msg","_color","_text","_item","_pic","_removeItem"];

_text = EPOCH_InteractedItem select 0;
_item = EPOCH_InteractedItem select 1;
_pic = EPOCH_InteractedItem select 2;

_type = "CfgMagazines";
if (isClass (configfile >> "CfgWeapons" >> _item)) then {_type = "CfgWeapons"};

_config = (configfile >> _type >> _item);
_type = getNumber(_config >> "type");
_interactOption = getNumber(_config >> "interactAction");
_interactReturnOnUse = getText(_config >> "interactReturnOnUse");
_interactAttributes = getArray(_config >> "interactAttributes");

_removeItem = {([player,_this] call BIS_fnc_invRemove) == 1};

_giveAttributes = {
	_index = _this select 0;
	_data = _this select 1;
	_addPlus = if (_data > 0) then {"+"} else {""};
	_return = "";
	if (_data != 0) then {
		switch _index do {
			case 0: {
				EPOCH_playerTemp = ((EPOCH_playerTemp + _data) min 106.7) max 95; // data = 1
				_return = format["Temp: %1%2 (%3 F)<br />", _addPlus, _data, EPOCH_playerTemp];
			};
			case 1: {
				EPOCH_playerHunger = ((EPOCH_playerHunger + _data) min 5000) max 0;
				_return = format["Hunger: %1%2 (%3/%4)<br />", _addPlus, _data, EPOCH_playerHunger, 5000];
			};
			case 2: {
				EPOCH_playerThirst = ((EPOCH_playerThirst + _data) min 2500) max 0;
				_return = format["Thirst: %1%2 (%3/%4)<br />", _addPlus, _data, EPOCH_playerThirst, 2500];
			};
			case 3: {
				EPOCH_playerEnergy = ((EPOCH_playerEnergy + _data) min EPOCH_playerEnergyMax) max 0;
				_return = format["Energy: %1%2 (%3/%4)<br />", _addPlus, _data, EPOCH_playerEnergy, EPOCH_playerEnergyMax];
			};
			case 4: {
				EPOCH_playerSoiled = ((EPOCH_playerSoiled + _data) min 100) max 0; // data -25
				_return = format["Soiled: %1%2 (%3/%4)<br />", _addPlus, _data, EPOCH_playerSoiled, 100];
			};
			case 5: {
				EPOCH_playerImmunity = ((EPOCH_playerImmunity + _data) min 100) max 0;
				_return = format["Immunity: %1%2 (%3/%4)<br />", _addPlus, _data, EPOCH_playerImmunity, 100];
			};
			case 6: {
				_randomData = round(random _data);
				EPOCH_playerToxicity = ((EPOCH_playerToxicity + _randomData) min 100) max 0;
				_return = format["Toxicity: %1%2 (%3/%4)<br />", _addPlus, _randomData, EPOCH_playerToxicity, 100];
			};
			case 7: {
				EPOCH_playerStamina = ((EPOCH_playerStamina + _data) min EPOCH_playerStaminaMax) max 0;
				_return = format["Stamina: %1%2 (%3/%4)<br />", _addPlus, _data, EPOCH_playerStamina, EPOCH_playerStaminaMax];
			};
			case 8: {
				// this is handled server side
			};
			case 9: {
				EPOCH_playerBloodP = ((EPOCH_playerBloodP + _data) min 190) max 0;
				_return = format["Blood Pressure: %1%2 (%3/%4)<br />", _addPlus, _data, EPOCH_playerBloodP, 100];
			};
			case 10: {
				EPOCH_playerKarma = ((EPOCH_playerKarma + _data) min 50000) max -50000;
				_return = format["Karma: %1%2 (%3/%4)<br />", _addPlus, _data, EPOCH_playerKarma, 50000];
			};
			case 11: {
				EPOCH_playerAlcohol = ((EPOCH_playerAlcohol + _data) min 100) max 0;
				_return = format["Alcohol: %1%2 (%3/%4)<br />", _addPlus, _data, EPOCH_playerAlcohol, 100];
			};
			case 12: {
				EPOCH_playerRadiation = ((EPOCH_playerRadiation + _data) min 100) max 0;
				_return = format["Radiation: %1%2 (%3/%4)<br />", _addPlus, _data, EPOCH_playerRadiation, 100];
			};


		};
	};
	_return
};

_unifiedInteract = {
	if (_item call _removeItem) then {
		_interactReturnOnUse call EPOCH_fnc_addItemOverflow;
		_output = "";
		{
			_output = _output + ([_forEachIndex, _x] call _giveAttributes);
		} foreach _interactAttributes;
		if (_output != "") then {
			_dt = [format["<t size='0.8' shadow='0' color='#99ffffff'>%1</t>", _output], 0, 1, 5, 2, 0, 1] spawn bis_fnc_dynamictext;
		};
	};
};

switch _interactOption do {
	case 0: {
		_magazineSizeMax = getNumber (_config >> "count");
		// allow repack for all magazines with greater than 1 bullet
		if (_magazineSizeMax > 1) then {

			_magazineSize = 0;
			_magazinesAmmoFull = magazinesAmmoFull player;
			{
				if (_item isEqualTo (_x select 0)) then {
					if (!(_x select 2)) then {
						_magazineSize = _magazineSize + (_x select 1);
					};
				};
			} forEach _magazinesAmmoFull;

			// remove all
			player removeMagazines _item;

			// Add full magazines back to player
			for "_i" from 1 to floor (_magazineSize / _magazineSizeMax) do
			{
			    player addMagazine [_item, _magazineSizeMax];
				//diag_log format ["DEBUG: added full mag %1", _magazineSizeMax];
			};
			// Add last non full magazine
			if ((_magazineSize % _magazineSizeMax) > 0) then {
				player addMagazine [_item, floor (_magazineSize % _magazineSizeMax)];
				//diag_log format ["DEBUG: added remainder %1", floor (_magazineSize % _magazineSizeMax)];
			};
 			_dt = ["<t size='0.8' shadow='0' color='#99ffffff'>Ammo Repacked</t>", 0, 1, 5, 2, 0, 1] spawn bis_fnc_dynamictext;
		};
	};
	case 1: _unifiedInteract; // Eat 1
	case 2: _unifiedInteract; //Drink 2
	case 3: { // Build 3
		closeDialog 0;
		_buildClass = getText(configfile >> "CfgMagazines" >> _item >> "buildClass");
		if (_buildClass != "") then {
			_isStorage = getNumber(configfile >> "CfgMagazines" >> _item >> "isStorage");

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
								_object=createVehicle[_buildClass,_pos,[],0,"CAN_COLLIDE"];
								_object setDir ((getDir player) - 180);

								if (_buildClass != "PlotPole_EPOCH") then {
									if (_object isKindOf "ThingX") then {
										if (([player, _item] call BIS_fnc_invRemove) == 1) then {
											[_object] spawn EPOCH_simulSwap;
										};
									} else {
										[_object,_item] spawn EPOCH_staticMove;
									};
								} else {
									_object spawn EPOCH_countdown;
								};

								_dt = [format["<t size='0.8' shadow='0' color='#99ffffff'>Press '%1' to drop object.</t>", "1"], 0, 1, 5, 2, 0, 1] spawn bis_fnc_dynamictext;


							} else {
								_dt = ["<t size = '0.8' shadow = '0' color = '#99ffffff'>Need Energy< / t>", 0, 1, 5, 2, 0, 1] spawn bis_fnc_dynamictext;
							};
						};
					} else {
						_dt = ["<t size='0.8' shadow='0' color='#99ffffff'>World limit reached</t>", 0, 1, 5, 2, 0, 1] spawn bis_fnc_dynamictext;
					};
				};
			};
		};
	};
	case 4: { // Refuel 4
		_vehicles = player nearEntities [["LandVehicle","Ship","Air","Tank"], 6];
		if (cursorTarget in _vehicles) then {
			_vehicle = cursorTarget;
			_currentFuel = fuel _vehicle;
			_canCapacity = _interactAttributes param [0,10];
			_fuelCapacity = getNumber (configfile >> "CfgVehicles" >> (typeOf _vehicle) >> "fuelCapacity");
			_currentFuel = _currentFuel * _fuelCapacity;
			_newFuel = _currentFuel + _canCapacity;
			_newFuel = _newFuel / _fuelCapacity;

			if (_item call _removeItem) then {
				_interactReturnOnUse call EPOCH_fnc_addItemOverflow;
				// send
				[_vehicle,_newFuel,player,Epoch_personalToken] remoteExec ["EPOCH_server_fillVehicle",2];

				_dt = ["<t size='0.8' shadow='0' color='#99ffffff'>Fuel Added</t>", 0, 1, 5, 2, 0, 1] spawn bis_fnc_dynamictext;
			};
		};
	};
	case 5: {
		_vehicles = player nearEntities [["LandVehicle","Ship","Air","Tank"], 6];
		_canCapacity = _interactAttributes param [0,10];

		if (cursorTarget in _vehicles) then {
			_vehicle = cursorTarget;
			_fuelCapacity = getNumber (configfile >> "CfgVehicles" >> (typeOf _vehicle) >> "fuelCapacity");
			_newFuel = (((fuel _vehicle) * _fuelCapacity) - _canCapacity) / _fuelCapacity;
			if (_newFuel > 0) then {
				if (_item call _removeItem) then {
					_interactReturnOnUse call EPOCH_fnc_addItemOverflow;
					[_vehicle,_newFuel,player,Epoch_personalToken] remoteExec ["EPOCH_server_fillVehicle",2];
					_dt = ["<t size='0.8' shadow='0' color='#99ffffff'>Fuel Siphoned</t>", 0, 1, 5, 2, 0, 1] spawn bis_fnc_dynamictext;
				};
			} else {
				_dt = ["<t size='0.8' shadow='0' color='#99ffffff'>Not Enough Fuel</t>", 0, 1, 5, 2, 0, 1] spawn bis_fnc_dynamictext;
			};
		} else {

			// find any other nearby fuel sources
			_transportFuel = 0;
			{
				_transportFuel = _transportFuel + getNumber (configFile >> "CfgVehicles" >> (typeOf _x) >> "transportFuel");
			} forEach (player nearObjects["ALL", 6]);

			if (_transportFuel > _canCapacity) then {
				if (_item call _removeItem) then {
					_interactReturnOnUse call EPOCH_fnc_addItemOverflow;
					_dt = ["<t size='0.8' shadow='0' color='#99ffffff'>Fuel Siphoned</t>", 0, 1, 5, 2, 0, 1] spawn bis_fnc_dynamictext;
				};
			} else {
				_dt = ["<t size='0.8' shadow='0' color='#99ffffff'>Not Enough Fuel</t>", 0, 1, 5, 2, 0, 1] spawn bis_fnc_dynamictext;
			};
		};
	};
	case 6: _unifiedInteract; //Clean -25
	case 7: _unifiedInteract; //Warm + 1
	case 8: _unifiedInteract; //Cold -1
	case 9: _unifiedInteract; //Energy 100
	case 10: { // Repair 10 - Lite
		_vehicles = player nearEntities [["LandVehicle","Ship","Air","Tank"], 6];
		_vehicle = cursorTarget;
		if (_vehicle in _vehicles) then {

			if (_item call _removeItem) then {

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
						[_vehicle, [_currentHIT, _newDMG]] call EPOCH_client_repairVehicle;
					} else {
						[_vehicle,[_currentHIT,_newDMG],player,Epoch_personalToken] remoteExec ["EPOCH_server_repairVehicle",2];
					};

					//diag_log format["DEBUG HITPOINT REPAIRED: %1 %2 %3", _currentHIT, _newDMG, _item];
				} else {
					if ((damage _vehicle) > 0) then {
						[_vehicle,["ALL",0],player,Epoch_personalToken] remoteExec ["EPOCH_server_repairVehicle",2];
					};
				};
				_dt = ["<t size='0.8' shadow='0' color='#99ffffff'>Vehicle Partially Repaired</t>", 0, 1, 5, 2, 0, 1] spawn bis_fnc_dynamictext;
			};
		};
	};
	case 11: { // Repair 11 - Heavy
		_vehicles = player nearEntities [["LandVehicle","Ship","Air","Tank"], 6];
		_vehicle = cursorTarget;
		if (_vehicle in _vehicles) then {
			if (_item call _removeItem) then {
				[_vehicle,["ALL",0],player,Epoch_personalToken] remoteExec ["EPOCH_server_repairVehicle",2];
				_dt = ["<t size='0.8' shadow='0' color='#99ffffff'>Vehicle Fully Repaired</t>", 0, 1, 5, 2, 0, 1] spawn bis_fnc_dynamictext;
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
				_color = getArray(configFile >> "CfgVehicles" >> (typeOf _vehicle) >> "availableTextures");
				if !(_color isEqualTo[]) then {

					if (_item call _removeItem) then {

						// find _paintCanIndex from config
						_paintCanIndex = getNumber(configfile >> "CfgMagazines" >> _item >> "textureIndex");
						_paintCanColor = getText(configfile >> "CfgMagazines" >> _item >> "colorName");

						[_vehicle,_paintCanIndex,player,Epoch_personalToken] remoteExec ["EPOCH_server_paintBUILD",2];

						_msg = format["Wall Painted %1", _paintCanColor];
						_dt = [format["<t size='0.8' shadow='0' color='#99ffffff'>%1</t>", _msg], 0, 1, 5, 2, 0, 1] spawn bis_fnc_dynamictext;
					};
				};
			}
			else {
				_dt = ["<t size = '0.8' shadow = '0' color = '#99ffffff'>Disallowed</t>", 0, 1, 5, 2, 0, 1] spawn bis_fnc_dynamictext;
			};
		};
	};

	case 13: { //Heal Player
		_vehicles = player nearEntities[["Epoch_Male_F", "Epoch_Female_F"], 6];
		_vehicle = cursorTarget;
		if (_vehicle in _vehicles) then {
			if (damage _vehicle != 0) then {
				if (_item call _removeItem) then {
					[_vehicle,["ALL",0],player,Epoch_personalToken] remoteExec ["EPOCH_server_repairVehicle",2];
					_dt = ["<t size = '0.8' shadow = '0' color = '#99ffffff'>Healed other player</t>", 0, 1, 5, 2, 0, 1] spawn bis_fnc_dynamictext;
				};
			};
		} else {
			if (damage player != 0) then {
				if (_item call _removeItem) then {
					[player,["ALL",0],player,Epoch_personalToken] remoteExec ["EPOCH_server_repairVehicle",2];
					_dt = ["<t size = '0.8' shadow = '0' color = '#99ffffff'>Healed yourself</t>", 0, 1, 5, 2, 0, 1] spawn bis_fnc_dynamictext;
				};
			};
		};
	};

	case 14: { // Unpack Backpack
		if (_item call _removeItem) then {
			[_interactReturnOnUse,player,Epoch_personalToken] remoteExec ["EPOCH_server_unpackBackpack",2];
			_dt = ["<t size = '0.8' shadow = '0' color = '#99ffffff'>Unpacked backpack</t>", 0, 1, 5, 2, 0, 1] spawn bis_fnc_dynamictext;
		};
	};

	default {
		// bottom
		_dt = ["<t size='0.8' shadow='0' color='#99ffffff'>Found nothing</t>", 0, 1, 5, 2, 0, 1] spawn bis_fnc_dynamictext;
		// center
		// _dt = ["<t size='0.8' shadow='0' color='#99ffffff'>text</t>", 0, 0.4, 5, 2, 0, 2] spawn bis_fnc_dynamictext;
	};
};


// diag_log format["DEBUG: EPOCH_consumeItem %1 type: %2",_item,_type];
