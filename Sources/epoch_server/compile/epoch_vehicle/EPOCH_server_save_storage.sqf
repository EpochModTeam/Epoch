/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Save Storage Object

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_vehicle/EPOCH_server_save_storage.sqf
*/
private ["_wepsItemsCargo","_magsAmmoCargo","_cargoIndex","_vehHiveKey","_damage","_vehiclePos","_magsAmmoCargoMinimized","_inventory","_colorSlot","_storageOwners","_locked","_worldspace","_VAL","_class","_vehSlot"];
params [["_vehicle",objNull]];

if (!isNull _vehicle) then {
	_class = typeOf _vehicle;
	_vehSlot = _vehicle getVariable["STORAGE_SLOT", "ABORT"];
	if (_vehSlot != "ABORT") then {

		_vehHiveKey = format ["%1:%2", (call EPOCH_fn_InstanceID),_vehSlot];

		_damage = 0;
		_vehicle setDamage 0;
		_vehiclePos = getposATL _vehicle;

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
		_wepsItemsCargoNormalized = [];
		{
			_selectedWeaponComponents = _x;
			_selectedWeapon = _selectedWeaponComponents deleteAt 0;
			// find actual weapon components - todo this BIS call maybe slow
			_weaponComponents = _selectedWeapon call BIS_fnc_weaponComponents;
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

		_inventory = [
			_wepsItemsCargoNormalized,
			_magsAmmoCargoMinimized,
			getBackpackCargo _vehicle,
			getItemCargo _vehicle
		];

		_colorSlot = _vehicle getVariable ["STORAGE_TEXTURE",0];
		_storageOwners = _vehicle getVariable["STORAGE_OWNERS",[]];
		_locked = if (_vehicle getVariable["EPOCH_Locked", true]) then {1} else {-1};
		_worldspace = [(_vehiclePos call EPOCH_precisionPos), vectordir _vehicle, vectorup _vehicle];

		_VAL = [_class, _worldspace, _damage, _inventory, _colorSlot, _storageOwners, _locked];
		["Storage", _vehHiveKey, EPOCH_expiresBuilding, _VAL] call EPOCH_fnc_server_hiveSETEX;
		diag_log format["STORAGE: saved to hive %1 Pos %2 Owners %3 Locked %4", _class, _worldspace, _storageOwners, _locked];
	};

};
