/*
	Author: DirtySanchez - ported from DonkeyPunch eXpoch http://DonkeyPunch.INFO

    Contributors: He-Man
	
	Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/vehicles/EPOCH_vehicle_checkTurretAmmo.sqf
*/
private ["_ammoTurret","_availAmmo","_ammo","_magazinesAmmoFull","_readd","_selectedmag","_magAmmoCount","_return","_AllFlares","_removeveh","_readdveh"];
params["_vehicle","_weaponTurret", "_turretPath"];

// Fix for not reloadable Flares
if ((["flare", tolower _weaponTurret] call BIS_fnc_inString) || (["smoke", tolower _weaponTurret] call BIS_fnc_inString)) then {
	_AllFlares = ((magazinesAllTurrets _vehicle) select {_x param [1] isequalto _turretPath}) select {(["flare", tolower (_x param [0])] call BIS_fnc_inString) || (["smoke", tolower (_x param [0])] call BIS_fnc_inString)};
	_removeveh = [];
	_readdveh = [];
	{
		_removeveh pushbackunique (_x select 0);
		if !((_x select 2) isequalto 0) then {
			_readdveh pushback _x;
		};
	} foreach _AllFlares;
	{
		_vehicle removeMagazinesTurret [_x,_turretPath];
	} foreach _removeveh;
	{
		_vehicle addMagazineTurret [_x select 0, _turretPath, _x select 2];
	} foreach _readdveh;
};

_ammoTurret = getArray(configFile >> "CfgWeapons" >> _weaponTurret >> "magazines");
_availAmmo = (magazines player) arrayIntersect _ammoTurret;
if (count _availAmmo == 0) then {
	[format["You need a can of %1 or any of its variants",getText (configFile >> 'CfgMagazines' >> (_ammoTurret select 0) >> 'displayName')],5] call Epoch_message;
}
else {
	_ammo = _availAmmo select 0;
	_magazinesAmmoFull = magazinesAmmoFull player;
	_readd = [];
	{
		if((_x select 0) isEqualTo _ammo) then {
			_readd pushback _x;
		};
	} forEach _magazinesAmmoFull;
	_selectedmag = _readd deleteat 0;
	_magAmmoCount = _selectedmag select 1;
	_vehicle addMagazineTurret [_ammo,_turretPath,_magAmmoCount];
	player removeMagazines _ammo;
	{
		_return = _x call EPOCH_fnc_addMagazineOverflow;
	} foreach _readd;
	_vehicle call EPOCH_interact;
	if !(EPOCH_arr_interactedObjs isEqualTo[]) then {
		[EPOCH_arr_interactedObjs] remoteExec['EPOCH_server_save_vehicles', 2];
		EPOCH_arr_interactedObjs = [];
	};
	[format["Added 1 can %1 with %2 rounds to %3",getText (configFile >> 'CfgMagazines' >> _ammo >> 'displayName'),_magAmmoCount,getText (configFile >> 'CfgWeapons' >> _weaponTurret >> 'displayName')],5] call Epoch_message;
};
