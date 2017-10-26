/*

	Author: DirtySanchez - ported from DonkeyPunch eXpoch http://DonkeyPunch.INFO

    Contributors: He-Man
	
	Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/vehicles/EPOCH_vehicle_removeTurretAmmo.sqf
*/
private ["_AllMagsDetailTurret","_selectedmag","_magAmmoCount","_return","_magtxt","_weapontxt","_msg"];
params["_vehicle","_weaponTurret","_ammo", "_turretPath"];

_AllMagsDetailTurret = ((magazinesAllTurrets _vehicle) select {_x param [1] isequalto _turretPath}) select {_x param [0] isequalto _ammo};
if (_AllMagsDetailTurret isequalto []) exitwith {
	["Error - No ammo found",5] call Epoch_message;
};
_selectedmag = _AllMagsDetailTurret deleteat 0;
_magAmmoCount = _selectedmag select 2;
_vehicle removeMagazinesTurret [_ammo,_turretPath];
{
	_vehicle addMagazineTurret [_x select 0, _turretPath, _x select 2];
} foreach _AllMagsDetailTurret;
reload _vehicle;
_return = [_ammo,_magAmmoCount] call EPOCH_fnc_addMagazineOverflow;

_vehicle call EPOCH_interact;
if !(EPOCH_arr_interactedObjs isEqualTo[]) then {
	[EPOCH_arr_interactedObjs] remoteExec['EPOCH_server_save_vehicles', 2];
	EPOCH_arr_interactedObjs = [];
};

_magtxt = getText (configFile >> 'CfgMagazines' >> _ammo >> 'displayName');
_weapontxt = getText (configFile >> 'CfgWeapons' >> _weaponTurret >> 'displayName');
_msg = switch _return do {
	case 0: {"Error - return epoch_equip failed"};
	case 1: {format ["Removed 1 can %1 with %2 rounds from %3",_magtxt,_magAmmoCount, _weapontxt]};
	case 2: {format ["Dropped 1 can of %1 with %2 rounds on the ground!",_magtxt,_magAmmoCount, _weapontxt]};
	case 3: {format ["You dont have enough space for %1!",_magtxt]};
	case 4: {format ["Put 1 can of %1 with %2 rounds into Vehicle!",_magtxt,_magAmmoCount, _weapontxt]};
};
[_msg,5] call Epoch_message;
