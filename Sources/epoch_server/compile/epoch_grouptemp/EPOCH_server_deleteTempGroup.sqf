/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Delete Group

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_grouptemp/EPOCH_server_deleteTempGroup.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_groupID","_return"];
//[[[end]]]
params ["_player",["_token","",[""]] ];

if !([_player, _token] call EPOCH_server_getPToken) exitWith{};

_return = false;
_groupID = getPlayerUID _player;
if (_groupID != "") then {
	_allPlayers = allPlayers select {alive _x};
	{
		_group = grpNull;
		_permGroup = _x getVariable["GROUP",""];
		if !(_permGroup isEqualTo "")then
		{
			{
				if ((_x getVariable["GROUP",""]) == _groupID) exitWith {
					_group = group _x;
				};
			} forEach _allPlayers;
		};
		
		_x setVariable ["TEMPGROUP", nil];
		[["resetTempGroup", true], _x] call EPOCH_sendRemoteExecClient;
		if (isNull _group) then {
			_group = createGroup [west, true];
		};
		[_x] joinSilent _group;
	} forEach (allPlayers select {(_x getVariable["TEMPGROUP", ""]) == _groupID});

	[["tempGroupUpdate", []], _player] call EPOCH_sendRemoteExecClient;
	_return = true;
};
_return
