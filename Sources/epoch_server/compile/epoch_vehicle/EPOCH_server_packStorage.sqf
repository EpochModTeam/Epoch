/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Dumps inventory of safe/lockbox to ground

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server/compile/epoch_vehicle/EPOCH_server_packStorage.sqf
*/
private ["_wepsItemsCargo","_magsAmmoCargo","_objTypes","_objQty","_wMags","_wMagsArray","_attachments","_arrCount","_magazineName","_magazineSize","_qty","_objType","_posWH","_inventory","_gwh","_returnItems","_owners","_class"];
params ["_unit","_player",["_token","",[""]]];

if !([_player, _token] call EPOCH_server_getPToken) exitWith{};
if (isNull _unit) exitWith{};
if (_player distance _unit > 20) exitWith{};

_class = typeOf _unit;
if (_class isKindOf 'Constructions_lockedstatic_F') then {

	_owners = _unit getVariable["STORAGE_OWNERS", []];
	if ((getPlayerUID _player) in _owners) then {

		_posWH = getPosATL _unit;

		// may not be needed but should prevent <null> in DB.
		_wepsItemsCargo = weaponsItemsCargo _unit;
		if (isNil "_wepsItemsCargo") then {
			_wepsItemsCargo = [];
		};
		_magsAmmoCargo = magazinesAmmoCargo _unit;
		if (isNil "_magsAmmoCargo") then {
			_magsAmmoCargo = [];
		};

		// dump items on ground
		_inventory = [
			_wepsItemsCargo,
			_magsAmmoCargo,
			getBackpackCargo _unit,
			getItemCargo _unit
		];

		[_unit, _player] call EPOCH_server_save_killedStorage;
		deleteVehicle _unit;

		_gwh = createVehicle["groundWeaponHolder", _posWH, [], 0, "CAN_COLLIDE"];
		_gwh setPosATL _posWH;
		_config = 'CfgBaseBuilding' call EPOCH_returnConfig;
		_returnItems = getArray(_config >> _class >> "returnOnPack");
		{
			_gwh addMagazineCargoGlobal _x;
		} forEach _returnItems;

		{
			_objType = _forEachIndex;

			_objTypes = _x;
			_objQty = [];

			if (_objType in[2, 3]) then {
				_objTypes = _x select 0;
				_objQty = _x select 1;
			};

			{
				switch _objType do {
					case 0: {
						if (_x isEqualType []) then {
							_arrCount = count _x;
							if (_arrCount >= 4) then {

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
						if (_x isEqualType []) then {
							if ((count _x) == 2) then {
								_magazineName = _x select 0;
								_magazineSize = _x select 1;

								if ((_magazineName isEqualType "STRING") && (_magazineSize isEqualType 0)) then {
									_gwh addMagazineAmmoCargo[_magazineName, 1, _magazineSize];
								};
							};
						};
					};
					case 2: {
						if (_x isEqualType "STRING") then {
							_qty = _objQty select _forEachIndex;
							_gwh addBackpackCargoGlobal[_x, _qty];
						};
					};
					case 3: {
						if (_x isEqualType "STRING") then {
							_qty = _objQty select _forEachIndex;
							_gwh addItemCargoGlobal[_x, _qty];
						};
					};
				};
			}forEach _objTypes;
		}forEach _inventory;
	};
};
