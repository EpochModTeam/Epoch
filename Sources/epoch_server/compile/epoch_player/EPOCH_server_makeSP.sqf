/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Select spawn point

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_player/EPOCH_server_selectSpawnpoint.sqf
*/
params [["_jammer",objNull],["_player",objNull],["_token",""]];
// check token
if !([_player, _token] call EPOCH_server_getPToken) exitWith{};
// require object
if (isNull _jammer) exitWith {};
// reject if player is too far away
if (_player distance _jammer > 20) exitWith{};
// check if in group with owner
if (alive _jammer) then {
    if ((_jammer getVariable["BUILD_OWNER", "-1"]) in [getPlayerUID _player, _player getVariable["GROUP", ""]]) then {
        // set position of spawnpoint to players SERVER_VARS
        _server_vars = _player getVariable["SERVER_VARS", []];
        _server_vars set [0, getposATL _jammer]; // 0 = RESPAWN POS
        _player setVariable ["SERVER_VARS", _server_vars];
    };
};
