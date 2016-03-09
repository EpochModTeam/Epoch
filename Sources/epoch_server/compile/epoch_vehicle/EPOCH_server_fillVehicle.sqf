/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Refuel Vehicles

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server/compile/epoch_vehicle/EPOCH_server_fillVehicle.sqf
*/
params ["_vehicle","_value","_player","_token"];
if !([_player, _token] call EPOCH_server_getPToken) exitWith{};
if (_player distance _vehicle > 20) exitWith{};
if (!isNull _vehicle) then {
	if (local _vehicle) then {
		_vehicle setFuel _value;
	} else {
		[_vehicle, _value] remoteExec ['EPOCH_client_fillVehicle',_vehicle];
	};
};
