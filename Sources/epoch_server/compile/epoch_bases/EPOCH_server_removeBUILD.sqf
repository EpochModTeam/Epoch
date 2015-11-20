/*
Building Remove

Epoch Mod - EpochMod.com
All Rights Reserved.
*/
private["_vehSlot", "_building", "_player", "_gwh", "_wepsItemsCargo", "_magsAmmoCargo", "_objTypes", "_objQty", "_magazine", "_weapon", "_suppressor", "_laser", "_optics", "_arrCount", "_magazineName", "_magazineSize", "_qty", "_objType", "_inventory", "_posWH", "_nearbyWH", "_removeParts", "_isTemporary", "_storageSlot"];

_building = _this select 0;
_player = _this select 1;

if !([_player, _this select 2] call EPOCH_server_getPToken) exitWith{};
if (isNull _building) exitWith{};
if (_player distance _building > 20) exitWith{};

// TODO add group check here since this should only be removed by group or owner of pole
_objType = typeOf _building;

_isTemporary = getNumber(configFile >> "CfgVehicles" >> _objType >> "isTemporary");

// check that object has building or storage slot
_vehSlot = _building getVariable["BUILD_SLOT", -1];
_storageSlot = _building getVariable["STORAGE_SLOT", "ABORT"];

if (_vehSlot != -1 || _storageSlot != "ABORT" || _isTemporary == 1) then{

	_removeParts = getArray(('CfgBaseBuilding' call EPOCH_returnConfig) >> _objType >> "removeParts");
	if !(_removeParts isEqualTo []) then {

		_posWH = getPosATL _player;
		_gwh = objNull;
		// give player a refund of parts
		_nearbyWH = nearestObjects[_posWH, ["groundWeaponHolder"], 2];
		if !(_nearbyWH isEqualTo[]) then{
			_gwh = _nearbyWH select 0;
			// _posWH = getPosATL _gwh;
		} else {
			_gwh = createVehicle["groundWeaponHolder", _posWH, [], 0, "CAN_COLLIDE"];
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
							if (typeName _x == "ARRAY") then{
								_arrCount = count _x;
								if (_arrCount >= 4) then{

									_gwh addWeaponCargoGlobal[_x deleteAt 0, 1];

									_attachments = [];
									_wMags = false;
									_wMagsArray = [];
									// suppressor, laser, optics, magazines(array), bipods
									{
										// magazines
										if (typeName(_x) == "ARRAY") then{
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
										if (typeName _wMagsArray == "ARRAY" && (count _wMagsArray) >= 2) then{
											_gwh addMagazineAmmoCargo[_wMagsArray select 0, 1, _wMagsArray select 1];
										};
									};

								};
							};
						};
						case 1: {
							if (typeName _x == "ARRAY") then{
								if ((count _x) == 2) then{
									_magazineName = _x select 0;
									_magazineSize = _x select 1;

									if ((typeName _magazineName == "STRING") && (typeName _magazineSize == "SCALAR")) then{
										_gwh addMagazineAmmoCargo[_magazineName, 1, _magazineSize];
									};
								};
							};
						};
						case 2: {
							if (typeName _x == "STRING") then{
								_qty = _objQty select _forEachIndex;
								_gwh addBackpackCargoGlobal[_x, _qty];
							};
						};
						case 3: {
							if (typeName _x == "STRING") then{
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
