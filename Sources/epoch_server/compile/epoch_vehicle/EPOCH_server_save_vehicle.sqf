/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Save Storage Object

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_vehicle/EPOCH_server_save_vehicle.sqf
*/
private ["_wepsItemsCargo","_magsAmmoCargo","_cargoIndex","_vehHiveKey","_hitpoints","_magsAmmoCargoMinimized","_inventory","_colorSlot","_VAL","_vehSlot"];
params [["_vehicle",objNull]];

if (!isNull _vehicle) then {

	if (!alive _vehicle) exitWith {diag_log format["DEBUG DEAD VEHICLE SKIPPED SAVE: %1 %2", _vehicle]};
	_vehSlot = _vehicle getVariable["VEHICLE_SLOT", "ABORT"];
	if (_vehSlot != "ABORT") then {

		_vehHiveKey = format ["%1:%2", (call EPOCH_fn_InstanceID),_vehSlot];

		_hitpoints = (getAllHitPointsDamage _vehicle) param [2,[]];

		// may not be needed but should prevent <null> in DB.
		_wepsItemsCargo = weaponsItemsCargo _vehicle;
		if (isNil "_wepsItemsCargo") then {
			_wepsItemsCargo = [];
		};
		_magsAmmoCargo = magazinesAmmoCargo _vehicle;
		if (isNil "_magsAmmoCargo") then {
			_magsAmmoCargo = [];
		};

		{
			_cargo = _x select 1;
			_magsAmmoCargox = magazinesAmmoCargo _cargo;
			{
				_magsAmmoCargo pushback _x;
			} foreach _magsAmmoCargox;
			_wepsItemsCargox = weaponsItemsCargo _cargo;
			{
				_wepsItemsCargo pushback _x;
			} foreach _wepsItemsCargox;
		} foreach everycontainer _vehicle;

		// minimize magazine ammo cargo
		_magsAmmoCargoMinimized = [[],[]];
		{
			// find cargo in temp var
			_cargoIndex = _magsAmmoCargoMinimized find (_x select 0);
			if (_cargoIndex >= 0) then {
				(_magsAmmoCargoMinimized select 1) set [_cargoIndex, ((_magsAmmoCargoMinimized select 1) select _cargoIndex) + (_x select 1)]; // get count & add current
			}
			else {
				(_magsAmmoCargoMinimized select 0) pushBack (_x select 0); // classname
				(_magsAmmoCargoMinimized select 1) pushBack (_x select 1); // count
			};
		} forEach _magsAmmoCargo;

		// convert and normalize
		_startTime = diag_tickTime;
		//diag_log format ["DEBUG: BIS_fnc_weaponComponents start %1", _startTime];
		_wepsItemsCargoNormalized = [];
		{
			_selectedWeaponComponents = _x;
			_selectedWeapon = _selectedWeaponComponents deleteAt 0;
			// find actual weapon components - todo this BIS call maybe slow
			_weaponComponents = _selectedWeapon call BIS_fnc_weaponComponents;
			//diag_log format ["DEBUG: BIS_fnc_weaponComponents end %1", diag_tickTime - _startTime];
			// base weapon (without attachments)
			_weapon = _weaponComponents deleteAt 0;
			_newComponents = [];
			{
				// remove attachments that are already linked via config
				if (_x isEqualType "" && {(tolower _x) in _weaponComponents}) then {
					_newComponents pushBack "";
					//diag_log format ["DEBUG: suppressed saving of %1 for weapon %2 config %3", _x, [_selectedWeapon,_selectedWeaponComponents],[_weapon,_weaponComponents]];
				} else {
					_newComponents pushBack _x;
				};
			} forEach _selectedWeaponComponents;
			_wepsItemsCargoNormalized pushBack ([_selectedWeapon] + _newComponents);
		} forEach _wepsItemsCargo;
		// diag_log format ["DEBUG: convert and normalize end %1", diag_tickTime - _startTime];

		_inventory = [
			_wepsItemsCargoNormalized,
			_magsAmmoCargoMinimized,
			getBackpackCargo _vehicle,
			getItemCargo _vehicle
		];
		_colorSlot = _vehicle getVariable ["VEHICLE_TEXTURE",0];

		_VAL = [typeOf _vehicle,[(getposATL _vehicle call EPOCH_precisionPos),vectordir _vehicle,vectorup _vehicle],damage _vehicle,_hitpoints,fuel _vehicle,_inventory,[true,magazinesAllTurrets _vehicle],_colorSlot];
		["Vehicle", _vehHiveKey, EPOCH_expiresVehicle, _VAL] call EPOCH_fnc_server_hiveSETEX;
	};
};
