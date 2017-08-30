/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Upgrade group size

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_grouptemp/EPOCH_server_upgradeTempGroup.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_cIndex","_contentArray","_current_crypto","_found","_groupMemberPUID","_newGroupSize","_playerCryptoLimit","_response","_return","_upgradePrice","_vars"];
//[[[end]]]
params ["_groupID","_player",["_token","",[""]] ];
if !([_player, _token] call EPOCH_server_getPToken) exitWith{};

_return = false;

// [_groupName, _leaderName, _groupSize, _modArray, _memberArray]
//_response = ["TempGroup", _groupID] call EPOCH_fnc_server_hiveGETRANGE;
if ((_response select 0) == 1 && (_response select 1) isEqualType []) then {
	_contentArray = (_response select 1);
	_found = EPOCH_group_upgrade_lvl_SEPXVar find (_contentArray select 2);

	if ((_found != -1) && count EPOCH_group_upgrade_lvl_SEPXVar >= (_found + 3)) then {
		_newGroupSize = EPOCH_group_upgrade_lvl_SEPXVar select (_found + 2);

		_upgradePrice = parseNumber	(EPOCH_group_upgrade_lvl_SEPXVar select (_found+3));

			_contentArray set [2, _newGroupSize];

			_groupMemberPUID = [_groupID];
			{
				{
					_groupMemberPUID pushback(_x select 0);
				} forEach _x;
			} forEach [_contentArray select 3, _contentArray select 4];

			{
				[["tempGroupUpdate", _contentArray], _x] call EPOCH_sendRemoteExecClient;
			} forEach (allPlayers select {getPlayerUID _x in _groupMemberPUID});

			// Save Group Data
			//_return = ["TempGroup", _groupID, _contentArray] call EPOCH_fnc_server_hiveSET;
			_return = true;
	};
};
_return
