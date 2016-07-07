/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Sets marker for trader to red and triggers drone to spawn on killer

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_server/EPOCH_server_traderKilled.sqf
*/
private ["_marker","_slot","_objHiveKey"];
params ["_trader","_player"];
if (!isNull _trader) then {
	_marker = _trader getVariable["MARKER_REF",""];
	if (_marker != "") then {
		_marker setMarkerColor "ColorRed";
	};
	_slot = _trader getVariable["AI_SLOT", -1];
	if (_slot != -1) then {
		// Spawn Drone on player
		[_player, "UAV"] call EPOCH_server_triggerEvent;
		_objHiveKey = format ["%1:%2", (call EPOCH_fn_InstanceID), _slot];
		["AI", _objHiveKey] call EPOCH_fnc_server_hiveDEL;
	};
};
