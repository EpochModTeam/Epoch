/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Player Respawn (unused)

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server/compile/epoch_player/EPOCH_server_respawnPlayer.sqf
*/
private["_defaultUniform", "_class", "_vest", "_dir", "_location", "_playerObj"];
params ["_playerObj",["_token","",[""]],"_isMale"];

if !([_playerObj, _token] call EPOCH_server_getPToken) exitWith{};

_defaultUniform = "U_Test_uniform";
_class = "Epoch_Female_F";
_vest = "V_F41_EPOCH";
if (_isMale) then {
	_defaultUniform = "U_Test1_uniform";
	_class = "Epoch_Male_F";
	_vest = "V_41_EPOCH";
};

_dir = random 360;
_location = getMarkerPos "respawn_west";
_location set[2, 0];

_playerObj = (group _player) createUnit [_class, _location, [], 0, "CAN_COLLIDE"];
{
	_playerObj disableAI _x;
} forEach["FSM", "MOVE", "AUTOTARGET", "TARGET"];

_playerObj setDir _dir;
_playerObj setPosATL _location;

// send player object to player
["_switchPlayer_PVC",_playerObj] remoteExec ['EPOCH_playerGenderInit',_player];

_playerObj setVariable ["REVIVE", true];
true
