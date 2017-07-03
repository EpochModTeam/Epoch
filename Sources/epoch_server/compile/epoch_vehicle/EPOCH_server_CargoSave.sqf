params [["_vehicle",objnull]];
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
_inventory
