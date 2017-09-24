/*
	Author: DirtySanchez - ported from DonkeyPunch eXpoch http://DonkeyPunch.INFO

    Contributors:
	
	Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/vehicles/EPOCH_vehicle_checkTurretAmmo.sqf
*/
params["_weaponTurret", "_turretPath"];

if(isNil {_weaponTurret})exitWith{diag_log "[EpochDebug] checkTurretAmmo _weaponTurret was nil"};

if(isNil {_turretPath})exitWith{diag_log "[EpochDebug] checkTurretAmmo _turretPath was nil"};

private _ammoCount = 0;
private _ammoTurret = getArray(configFile >> "CfgWeapons" >> _weaponTurret >> "magazines");
private _items = magazines player;
private _availAmmo = _items arrayIntersect _ammoTurret;
if (count _availAmmo == 0) then
{
	[format["You need a can of %1 or any of its variants",_ammoTurret select 0],5] call Epoch_message;
}
else
{
	private _ammo = _availAmmo select 0;
	private _magazinesAmmoFull = magazinesAmmoFull player;
	{
		if((_x select 0) isEqualTo _ammo) then {
			_ammoCount = _x select 1;
			_magazinesAmmoFull = [];
		};
	}forEach _magazinesAmmoFull;
	[format["You have added 1 can of %1 with %2 rounds",_ammo,_ammoCount],5] call Epoch_message;
	vehicle player addMagazineTurret [_ammo,_turretPath,_ammoCount];
	player removeMagazine _ammo;
};