/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Player Respawn (unused)

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_player/EPOCH_server_respawnPlayer.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_class","_defaultUniform","_dir","_location","_vest"];
//[[[end]]]
params ["_player",["_token","",[""]],"_isMale"];

if !([_player, _token] call EPOCH_server_getPToken) exitWith{};

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

_player = (group _player) createUnit [_class, _location, [], 0, "CAN_COLLIDE"];
_player disableAI "ALL";

_player setDir _dir;
_player setPosATL _location;

// send player object to player
["_switchPlayer_PVC",_player] remoteExec ['EPOCH_playerGenderInit',_player];

_player setVariable ["REVIVE", true];
true
