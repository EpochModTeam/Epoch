/*
	Author: He-Man - Ignatz-Gaming

    Contributors:

	Description:
	Reads Cargo Inventory and push it back in a Variable

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
	https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_vehicle/EPOCH_server_CargoSave.sqf
	
    Example:
    _Inventory = [_vehicle, _dominimize] call EPOCH_server_CargoSave;

    Parameter(s):
		_this select 0: OBJ - Storage or Vehicle
        _this select 1: BOOL - Minimize the Magazine Array

	Returns:
	ARRAY
*/


private [
	"_wepsItemsCargo","_magsAmmoCargo","_containers","_allContainers","_cargo","_magsAmmoCargox","_wepsItemsCargox","_magsAmmoCargoMinimized","_cargoIndex","_wepsItemsCargoNormalized","_selectedWeaponComponents","_selectedWeapon",
	"_weaponComponents","_weapon","_newComponents","_inventory","_ItemCargo","_ItemCargox"];
params [["_vehicle",objnull],["_unpack",true]];
// may not be needed but should prevent <null> in DB.
_wepsItemsCargo = weaponsItemsCargo _vehicle;
if (isNil "_wepsItemsCargo") then {
	_wepsItemsCargo = [];
};
_magsAmmoCargo = magazinesAmmoCargo _vehicle;
if (isNil "_magsAmmoCargo") then {
	_magsAmmoCargo = [];
};
_ItemCargo = getItemCargo _vehicle;
if (isNil "_ItemCargo") then {
	_ItemCargo = [[],[]];
};

_containers = [];
_allContainers = (everycontainer _vehicle);
{
	_x params ["_type","_cargo"];
	if (_unpack) then {
		_magsAmmoCargox = magazinesAmmoCargo _cargo;
		{
			_magsAmmoCargo pushback _x;
		} foreach _magsAmmoCargox;
		_wepsItemsCargox = weaponsItemsCargo _cargo;
		{
			_wepsItemsCargo pushback _x;
		} foreach _wepsItemsCargox;
		_ItemCargox = getItemCargo _cargo;
		_ItemCargox params ["_items","_itemcounts"];
		{
			_cargoIndex = (_ItemCargo select 0) find _x;
			if (_cargoIndex >= 0) then {
				(_ItemCargo select 1) set [_cargoIndex,(_ItemCargo select 1 select _cargoIndex) + (_itemcounts select _foreachindex)];
			}
			else {
				(_ItemCargo select 0) pushback (_items select _foreachindex);
				(_ItemCargo select 1) pushback (_itemcounts select _foreachindex);
			};
		} foreach _items;
	}
	else {
		_containerInventory = _cargo call EPOCH_server_CargoSave;
		_containers pushback [_type , _containerInventory];
	};
} foreach _allContainers;

// minimize magazine ammo cargo
_magsAmmoCargoMinimized = [[],[]];
{
	(_magsAmmoCargoMinimized select 0) pushBack (_x select 0);
	(_magsAmmoCargoMinimized select 1) pushBack (_x select 1);
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
	_ItemCargo,
	_containers
];
_inventory
