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
//[[[cog import generate_private_arrays ]]]
private ["_allPlayers","_contentArray","_found","_group","_memberrange","_modOrMember","_modOrMemberArray","_modOrMemberRevert","_removePlayerArray","_response","_selectedPlayerName"];
//[[[end]]]
params [["_groupID",""],["_selectedPlayerUID",""],["_addOrRemove",false],["_modOrMemberVar",true],["_player",objnull],["_token",""]];

if !([_player, _token] call EPOCH_server_getPToken) exitWith {};

if (_groupID == "") exitWith{ diag_log format["Epoch: GROUP: No Group Selected %1", _this]; };

diag_log format["Epoch: GROUP: Update %1", _this];

_modOrMember = if (_modOrMemberVar) then [{3},{4}];
_modOrMemberRevert = if (_modOrMemberVar) then [{4},{3}];

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
				_group = grpNull;
				{
					if ((_x getVariable["GROUP",""]) == _groupID) exitWith {
						_group = group _x;
					};
				} forEach _allPlayers;

				if (isNull _group) then {
					_group = createGroup [west, true];
				};
				_x setVariable ["GROUP", _groupID];
				[["groupUidUpdate", _groupID], _x] call EPOCH_sendRemoteExecClient;
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
