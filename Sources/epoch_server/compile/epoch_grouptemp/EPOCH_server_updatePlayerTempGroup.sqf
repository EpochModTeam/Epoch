/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Add or remove members from a group

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_grouptemp/EPOCH_server_updatePlayerTempGroup.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_allPlayers","_contentArray","_found","_group","_memberrange","_modOrMember","_modOrMemberArray","_modOrMemberRevert","_removePlayerArray","_response","_selectedPlayerName","_playerObj"];
//[[[end]]]
params [["_groupID",""],["_selectedPlayerUID",""],["_addOrRemove",false],["_modOrMemberVar",true],["_player",objnull],["_token",""]];

if !([_player, _token] call EPOCH_server_getPToken) exitWith {};

if (_groupID == "") exitWith{ diag_log format["Epoch: GROUP: No Temp Group Selected %1", _this]; };

diag_log format["Epoch: Temp GROUP: Update %1", _this];

_modOrMember = if (_modOrMemberVar) then [{3},{4}];
_modOrMemberRevert = if (_modOrMemberVar) then [{4},{3}];
_contentArray = [];
{
	_contentArray = _x getVariable ["TEMPGROUPARRAY",[]];
} forEach (allPlayers select {getPlayerUID _x == _groupID});

if !(_contentArray isEqualTo []) then {

    _contentArray params ["_groupName","_leaderName","_groupSize","_modArray","_memberArray"];
    _allPlayers = allPlayers select {alive _x};

	if (_addOrRemove) then { //Add
		_selectedPlayerName = "Dead Player";

		{
			_selectedPlayerName = if (alive _x) then {name _x};
			if ((_x getVariable ["TEMPGROUP",""]) != _groupID) then {
				_group = grpNull;
				{
					_group = group _x;
				} forEach (_allPlayers select {(_x getVariable["TEMPGROUP", ""]) == _groupID});

				if (isNull _group) then {
					_group = createGroup [west, true];
				};
				_x setVariable ["TEMPGROUP", _groupID];
				[["tempGroupUidUpdate", _groupID], _x] call EPOCH_sendRemoteExecClient;
				[_x] joinSilent _group;
			};
		} forEach (_allPlayers select {getPlayerUID _x == _selectedPlayerUID});


		// find player name from DB
		if (_selectedPlayerName == "Dead Player") then {
			_memberrange = ["PlayerData", _selectedPlayerUID] call EPOCH_fnc_server_hiveGETRANGE;
			if (count (_memberrange select 1) > 0) then {
				if ((_memberrange select 1 select 0) isEqualType "STRING") then {
					_selectedPlayerName = _memberrange select 1 select 0;
				};
			};
		};

		_removePlayerArray = _contentArray select _modOrMemberRevert;

		{
			if (_x select 0 == _selectedPlayerUID) exitWith {
				_removePlayerArray deleteAt _forEachIndex;
				_contentArray set [_modOrMemberRevert, _removePlayerArray];
			};
		} forEach _removePlayerArray;

		_modOrMemberArray = _contentArray select _modOrMember;
		_modOrMemberArray pushBack [_selectedPlayerUID, _selectedPlayerName];

		_contentArray set [_modOrMember, _modOrMemberArray];

	} else {

		//Remove
		_found = false;
		_group = grpNull;
		_permGroup = "";
		{
			_permGroup = _x getVariable["GROUP",""];
			_playerObj = _x;
		} forEach (_allPlayers select {getPlayerUID _x == _selectedPlayerUID});
		if !(_permGroup isEqualTo "")then
		{
			{
				_group = group _x;
			} forEach (_allPlayers select {(_x getVariable["GROUP", ""]) == _permGroup});
		};
		_playerObj setVariable ["TEMPGROUP", nil];
		if (isNull _group) then {
			_group = createGroup [west, true];
		};
		[_playerObj] joinSilent _group;
		[["resetTempGroup", true], _playerObj] call EPOCH_sendRemoteExecClient;
		[["tempGroupUpdate", []], _playerObj] call EPOCH_sendRemoteExecClient;
		{
			if (_x select 0 == _selectedPlayerUID) exitWith {
				_memberArray deleteAt _forEachIndex;
				_found = true;
			};
		} forEach _memberArray;

		if (_found) then {
			_contentArray set [4, _memberArray];
		} else {
			{
				if (_x select 0 == _selectedPlayerUID) exitWith {
					_modArray deleteAt _forEachIndex;
					_found = true;
				};
			} forEach _modArray;
			_contentArray set [3, _modArray];
		};

		if (!_found) then {
			diag_log format ["Epoch: %1 cannot remove Player! (%1)", __FILE__, _this]
		};
	};

	{
		[["tempGroupUpdate", _contentArray], _x] call EPOCH_sendRemoteExecClient;
	} forEach (_allPlayers select {(_x getVariable["TEMPGROUP", ""]) == _groupID});

};
