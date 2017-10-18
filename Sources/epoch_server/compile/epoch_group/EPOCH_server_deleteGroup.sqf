/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Delete Group

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_group/EPOCH_server_deleteGroup.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_groupID","_return"];
//[[[end]]]
params ["_player",["_token","",[""]] ];

if !([_player, _token] call EPOCH_server_getPToken) exitWith{};

_return = false;
_groupID = getPlayerUID _player;
if (_groupID != "") then {

	{
		_x setVariable ["GROUP", nil];
		[["resetGroup", true], _x] call EPOCH_sendRemoteExecClient;
		[_x] joinSilent (createGroup [west, true]);
	} forEach (allPlayers select {(_x getVariable["GROUP", ""]) == _groupID});

	_return = ["Group", _groupID] call EPOCH_fnc_server_hiveDEL;
	[["groupUpdate", []], _player] call EPOCH_sendRemoteExecClient;
};
_return
