/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Player Disconnect

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_player/EPOCH_server_onPlayerDisconnect.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_return"];
//[[[end]]]
params ["_player","_id","_uid","_name"];
_return = false;
if (!isNull _player) then {
	if (_player getVariable["SETUP", false]) then {
		[_player, _player getVariable["VARS", []] ] call EPOCH_server_savePlayer;
		if (alive _player) then {
			_player setVariable ["VARS", nil];
			deleteVehicle _player;
		};
	} else {
		deleteVehicle _player;
	};
};
// Delete any left over units with same PUID
{
    deleteVehicle _x;
} forEach (allUnits select {_x getVariable["PUID", "0"] == _uid});
_uid call EPOCH_server_disconnect;
['Disconnected', [_uid, _name]] call EPOCH_fnc_server_hiveLog;
_return
