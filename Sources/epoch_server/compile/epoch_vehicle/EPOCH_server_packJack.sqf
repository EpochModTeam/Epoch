/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Pack object into magazine item

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_vehicle/EPOCH_server_packJack.sqf
*/
params ["_unit","_player",["_token","",[""]]];
if !([_player, _token] call EPOCH_server_getPToken) exitWith{};
if (isNull _unit) exitWith{};
if (_player distance _unit > 20) exitWith{};

// TODO configize
if (typeOf _unit == "Jack_SIM_EPOCH") then {
	deleteVehicle _unit;
	// TODO handle overflow
	_player addMagazine["JackKit", 1];
};
