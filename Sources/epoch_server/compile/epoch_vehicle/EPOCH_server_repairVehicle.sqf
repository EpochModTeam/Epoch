/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Dumps inventory of safe/lockbox to ground

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server/compile/epoch_vehicle/EPOCH_server_repairVehicle.sqf
*/
params ["_vehicle","_value","_player",["_token","",[""]]];
if (isNull _vehicle) exitWith{};
if !([_player,  _token] call EPOCH_server_getPToken) exitWith{};
if (_player distance _vehicle > 20) exitWith{};

if ((_value select 0) isEqualTo "ALL") then {
	_vehicle setDamage 0;
} else {
	if (local _vehicle) then {
		_vehicle setHitIndex _value;
	} else {
		[_vehicle, _value] remoteExec ['EPOCH_client_repairVehicle',_vehicle];
	};
};
_vehicle call EPOCH_server_save_vehicle;
