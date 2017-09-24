/*

	Author: DirtySanchez - ported from DonkeyPunch eXpoch http://DonkeyPunch.INFO

    Contributors:
	
	Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/vehicles/EPOCH_vehicle_removeCommanderAmmo.sqf
*/
params["_weaponTurret", "_turretPath"];

if(isNil {_weaponTurret})exitWith{diag_log "[EpochDebug] removeCommanderAmmo _weaponTurret was nil"};

if(isNil {_turretPath})exitWith{diag_log "[EpochDebug] removeCommanderAmmo _turretPath was nil"};

private _magAmmo = 0;
private _magsTurret = "";
private _ammoTurret = getArray(configFile >> "CfgWeapons" >> _weaponTurret >> "magazines");
private _magsAllTurrets = magazinesAllTurrets vehicle player;
{
	if(_x select 0 in _ammoTurret)then{
		_magsTurret = _x select 0;
		_magAmmo = _x select 2;
		_magsAllTurrets = [];
	};
}forEach _magsAllTurrets;

if(_magAmmo isEqualTo 0)exitWith{
	private _nameTurret = getText(configFile >> "CfgWeapons" >> _weaponTurret >> "displayName");
	[format["The %1 does not have any ammo",_nameTurret],5] call Epoch_message;
};

[format["You have removed 1 can of %1 with %2 rounds",_magsTurret, _magAmmo],5] call Epoch_message;
player addMagazine [_magsTurret,_magAmmo];
vehicle player removeMagazineTurret [_magsTurret,_turretPath];
reload vehicle player;