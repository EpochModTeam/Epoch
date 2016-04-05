/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Add or remove members from a group

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server/compile/epoch_group/EPOCH_server_updatePlayerGroup.sqf
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

	//_groupName = _contentArray select 0;
	//_leaderName = _contentArray select 1;
	//_groupSize = _contentArray select 2;
	_modArray = _contentArray select 3;
	_memberArray = _contentArray select 4;

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
				}count playableUnits;

				if (isNull _group) then {
					_group = createGroup west;
				};
				[_x] joinSilent _group;
			};
		} forEach (allPlayers select {getPlayerUID _x == _selectedPlayerUID});

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
			[_x] joinSilent (createGroup west);
			[["resetGroup", true], _x] call EPOCH_sendRemoteExecClient;
		} forEach (allPlayers select {getPlayerUID _x == _selectedPlayerUID});

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
	} forEach (allPlayers select {(_x getVariable["GROUP", ""]) == _groupID});

	// Save Group Data
	["Group", _groupID, _contentArray] call EPOCH_fnc_server_hiveSET;
};
