/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Adds killed handler to storage object.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server/compile/epoch_server/EPOCH_server_teleportPlayer.sqf
*/
private ["_tp"];
params ["_player","_teleporter","_token"];
if !([_player, _token] call EPOCH_server_getPToken) exitWith{};
if (isNull _teleporter) exitWith{};
if (_player distance _teleporter > 20) exitWith{};
	
_tp = _teleporter getVariable["ParentBuilding", []];
if !(_tp isEqualTo []) then {
	_player setPosATL _tp;
};
