/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Add or remove members from a group

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_group/EPOCH_server_updatePlayerGroup.sqf
*/
private ["_groupID","_selectedPlayerUID","_addOrRemove","_modOrMember","_modOrMemberRevert","_response","_contentArray","_modArray","_memberArray","_selectedPlayerName","_group","_removePlayerArray","_modOrMemberArray","_found"];

if !([_this select 4, _this select 5] call EPOCH_server_getPToken) exitWith {};

_groupID = _this select 0;
if (_groupID == "") exitWith{ diag_log format["Epoch: GROUP: No Group Selected %1", _this]; };

diag_log format["Epoch: GROUP: Update %1", _this];

_selectedPlayerUID = _this select 1;
_addOrRemove = _this select 2; //add = true
_modOrMember = if (_this select 3) then [{3},{4}];
_modOrMemberRevert = if (_this select 3) then [{4},{3}];

// [_groupName, _leaderName, _groupSize, _modArray, _memberArray]
_response = ["Group", _groupID] call EPOCH_fnc_server_hiveGETRANGE;
if ((_response select 0) == 1 && (_response select 1) isEqualType []) then {
	_contentArray = _response select 1;
    _contentArray params ["_groupName","_leaderName","_groupSize","_modArray","_memberArray"];
    _allPlayers = allPlayers select {alive _x};

	if (_addOrRemove) then { //Add
		_selectedPlayerName = "Dead Player";

		{
			_selectedPlayerName = if (alive _x) then {name _x};
			if ((_x getVariable ["GROUP",""]) != _groupID) then {
				_x setVariable ["GROUP", _groupID];
				_group = grpNull;
				{
					if ((_x getVariable["GROUP",""]) == _groupID) exitWith {
						_group = group _x;
					};
				} forEach _allPlayers;

				if (isNull _group) then {
					_group = createGroup [west, true];
				};
				[_x] joinSilent _group;
			};
		} forEach (_allPlayers select {getPlayerUID _x == _selectedPlayerUID});

		// find player name from DB
		if (_selectedPlayerName == "Dead Player") then {
			_memberrange = ["PlayerData", _selectedPlayerUID] call EPOCH_fnc_server_hiveGETRANGE;
			if (count (_memberrange select 1) > 0) then {
				if (typename (_memberrange select 1 select 0) == "STRING") then {
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

		{
			_x setVariable ["GROUP", nil];
			[_x] joinSilent (createGroup [west, true]);
			[["resetGroup", true], _x] call EPOCH_sendRemoteExecClient;
		} forEach (_allPlayers select {getPlayerUID _x == _selectedPlayerUID});

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
		[["groupUpdate", _contentArray], _x] call EPOCH_sendRemoteExecClient;
	} forEach (_allPlayers select {(_x getVariable["GROUP", ""]) == _groupID});

	// Save Group Data
	["Group", _groupID, _contentArray] call EPOCH_fnc_server_hiveSET;
};
