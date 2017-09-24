/*

	Author: DirtySanchez - ported from DonkeyPunch eXpoch http://DonkeyPunch.INFO

    Contributors:
	
	Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/vehicles/EPOCH_vehicle_removeTurretAmmo.sqf
*/
params["_weaponTurret", "_turretPath"];

if(isNil {_weaponTurret})exitWith{diag_log "[EpochDebug] removeTurretAmmo _weaponTurret was nil"};

if(isNil {_turretPath})exitWith{diag_log "[EpochDebug] removeTurretAmmo _turretPath was nil"};

private _magsTurretDetails = magazinesAmmo vehicle player;
if(_magsTurretDetails isEqualTo [])exitWith{
	private _nameTurret = getText(configFile >> "CfgWeapons" >> _weaponTurret >> "displayName");
	[format["The %1 does not have any ammo",_nameTurret],5] call Epoch_message;
};

private _magsTurret = (_magsTurretDetails select 0) select 0;
private _magAmmo = (_magsTurretDetails select 0) select 1;
[format["You have removed 1 can of %1 with %2 rounds",_magsTurret, _magAmmo],5] call Epoch_message;
player addMagazine [_magsTurret,_magAmmo];
vehicle player removeMagazineTurret [_magsTurret,_turretPath];
reload vehicle player;