/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Dumps inventory of safe/lockbox to ground

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_vehicle/EPOCH_server_repairVehicle.sqf
*/
private ["_god"];
params ["_vehicle","_value","_player",["_token","",[""]]];
if (isNull _vehicle) exitWith{};
if !([_player,  _token] call EPOCH_server_getPToken) exitWith{};
if (_player distance _vehicle > 20) exitWith{};

if ((_value select 0) isEqualTo "ALL") then {
	_vehicle setDamage (_value select 1);
} 
else {
	if (local _vehicle) then {
		_god = !(isDamageAllowed _vehicle);
		if (_god) then {
			_vehicle allowdamage true;
		};
		{
			if ((_x select 0) isequaltype 0) then {
				_vehicle setHitIndex _x;
			}
			else {
				_vehicle setHitPointDamage _x;
			};
		} foreach _value;
		if (_god) then {
			_vehicle allowdamage false;
		};
	} else {
		[_vehicle, _value] remoteExec ['EPOCH_client_repairVehicle',_vehicle];
	};
};

if !({_x > 0} count ((getAllHitPointsDamage _vehicle) select 2) > 0) then {
	_vehicle setdamage 0;
};

_vehicle call EPOCH_server_save_vehicle;
