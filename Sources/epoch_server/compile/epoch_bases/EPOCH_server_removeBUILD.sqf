/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Remove Building

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server/compile/epoch_bases/EPOCH_server_removeBUILD.sqf
*/
private["_cfgBaseBuilding","_vehSlot", "_gwh", "_wepsItemsCargo", "_magsAmmoCargo", "_objTypes", "_objQty", "_magazine", "_weapon", "_suppressor", "_laser", "_optics", "_arrCount", "_magazineName", "_magazineSize", "_qty", "_objType", "_inventory", "_posWH", "_nearbyWH", "_removeParts", "_isTemporary", "_storageSlot"];
params ["_building","_player",["_token","",[""]]];

if !([_player, _token] call EPOCH_server_getPToken) exitWith{};
if (isNull _building) exitWith{};
if (_player distance _building > 20) exitWith{};

// TODO add group check here since this should only be removed by group or owner of pole
_objType = typeOf _building;
_cfgBaseBuilding = 'CfgBaseBuilding' call EPOCH_returnConfig;
_isTemporary = getNumber(_cfgBaseBuilding >> _objType >> "isTemporary");

// check that object has building or storage slot
_vehSlot = _building getVariable["BUILD_SLOT", -1];
_storageSlot = _building getVariable["STORAGE_SLOT", "ABORT"];

if (_vehSlot != -1 || _storageSlot != "ABORT" || _isTemporary == 1) then{

	_removeParts = getArray(_cfgBaseBuilding >> _objType >> "removeParts");
	if !(_removeParts isEqualTo []) then {

		_posWH = getPosATL _player;
		_gwh = objNull;
		// give player a refund of parts
		_nearbyWH = nearestObjects[_posWH, ["groundWeaponHolder"], 2];
		if !(_nearbyWH isEqualTo[]) then{
			_gwh = _nearbyWH select 0;
			// _posWH = getPosATL _gwh;
		} else {
			_gwh = createVehicle["groundWeaponHolder", [0,0,0], [], 0, "CAN_COLLIDE"];
			_gwh setPosATL _posWH;
		};

		if !(isNull _gwh) then{

			// if normal storage device dump items on ground.
			if (_building isKindOf "Buildable_Storage") then {

				// may not be needed but should prevent <null> in DB.
				_wepsItemsCargo = weaponsItemsCargo _building;
				if (isNil "_wepsItemsCargo") then{
					_wepsItemsCargo = [];
				};
				_magsAmmoCargo = magazinesAmmoCargo _building;
				if (isNil "_magsAmmoCargo") then{
					_magsAmmoCargo = [];
				};

				// dump items on ground
				_inventory = [
					_wepsItemsCargo,
					_magsAmmoCargo,
					getBackpackCargo _building,
					getItemCargo _building
				];

				[_building, _player] call EPOCH_server_save_killedStorage;
				deleteVehicle _building;

				{
					_objType = _forEachIndex;

					_objTypes = _x;
					_objQty = [];

					if (_objType in[2, 3]) then{
						_objTypes = _x select 0;
						_objQty = _x select 1;
					};

					{
						switch _objType do {
						case 0: {
							if (_x isEqualType []) then{
								_arrCount = count _x;
								if (_arrCount >= 4) then{

									_gwh addWeaponCargoGlobal[_x deleteAt 0, 1];

									_attachments = [];
									_wMags = false;
									_wMagsArray = [];
									// suppressor, laser, optics, magazines(array), bipods
									{
										// magazines
										if (_x isEqualType []) then{
											_wMags = true;
											_wMagsArray = _x;
										}
										else {
											// attachments
											if (_x != "") then{
												_attachments pushBack _x;
											};
										};
									} forEach _x;

									// add all attachments to vehicle
									// TODO replace with adding attachments directly to gun (Arma feature dependant)
									{
										_gwh addItemCargoGlobal[_x, 1];
									} forEach _attachments;

									if (_wMags) then{
										if (_wMagsArray isEqualType [] && (count _wMagsArray) >= 2) then{
											_gwh addMagazineAmmoCargo[_wMagsArray select 0, 1, _wMagsArray select 1];
										};
									};

								};
							};
						};
						case 1: {
							if (_x isEqualType []) then{
								if ((count _x) == 2) then{
									_magazineName = _x select 0;
									_magazineSize = _x select 1;

									if ((_magazineName isEqualType "STRING") && (_magazineSize isEqualType 0)) then{
										_gwh addMagazineAmmoCargo[_magazineName, 1, _magazineSize];
									};
								};
							};
						};
						case 2: {
							if (_x isEqualType "STRING") then{
								_qty = _objQty select _forEachIndex;
								_gwh addBackpackCargoGlobal[_x, _qty];
							};
						};
						case 3: {
							if (_x isEqualType "STRING") then{
								_qty = _objQty select _forEachIndex;
								_gwh addItemCargoGlobal[_x, _qty];
							};
						};
						};
					}forEach _objTypes;
				}forEach _inventory;

			} else {

				// Remove trap object
				_ammoObj = _building getVariable ["EPOCH_TRAP_OBJ",objNull];
				if !(isNull _ammoObj) then {
					deleteVehicle _ammoObj;
				};

				[_building, _player] call EPOCH_server_save_killedBuilding;
				deleteVehicle _building;
			};

			// Normal config based payout
			{
				_gwh addMagazineCargoGlobal[_x select 0, _x select 1];
			} forEach _removeParts;
		};
	};
};
