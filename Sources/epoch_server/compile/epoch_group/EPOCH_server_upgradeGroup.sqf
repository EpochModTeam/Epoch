/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Upgrade group size

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server/compile/epoch_group/EPOCH_server_upgradeGroup.sqf
*/
private ["_playerCryptoLimit","_current_crypto","_groupMemberPUID","_return","_newGroupSize","_upgradePrice","_contentArray","_found","_cIndex","_vars","_response"];
params ["_groupID","_player","_token"];
if !([_player, _token] call EPOCH_server_getPToken) exitWith{};

_return = false;

// get vars array and current Crypto value
_cIndex = EPOCH_customVars find "Crypto";
_vars = _player getVariable["VARS", [] + EPOCH_defaultVars_SEPXVar];
_current_crypto = _vars select _cIndex;

// [_groupName, _leaderName, _groupSize, _modArray, _memberArray]
_response = ["Group", _groupID] call EPOCH_fnc_server_hiveGETRANGE;
if ((_response select 0) == 1 && (_response select 1) isEqualType []) then {
	_contentArray = (_response select 1);
	_found = EPOCH_group_upgrade_lvl_SEPXVar find (_contentArray select 2);

	if ((_found != -1) && count EPOCH_group_upgrade_lvl_SEPXVar >= (_found + 3)) then {
		_newGroupSize = EPOCH_group_upgrade_lvl_SEPXVar select (_found + 2);

		_upgradePrice = parseNumber	(EPOCH_group_upgrade_lvl_SEPXVar select (_found+3));

		if (_current_crypto >= _upgradePrice) then {

			_playerCryptoLimit = [(configFile >> "CfgSecConf" >> "limits"), "playerCrypto", 250000] call EPOCH_fnc_returnConfigEntry;
			_current_crypto = ((_current_crypto - _upgradePrice) min _playerCryptoLimit) max 0;
			// send to player
			_current_crypto remoteExec ['EPOCH_effectCrypto',(owner _player)];
			_vars set[_cIndex, _current_crypto];
			_player setVariable["VARS", _vars];

			_contentArray set [2, _newGroupSize];

			_groupMemberPUID = [_groupID];
			{
				{
					_groupMemberPUID pushback(_x select 0);
				} forEach _x;
			} forEach [_contentArray select 3, _contentArray select 4];

			{
				[["groupUpdate", _contentArray], _x] call EPOCH_sendPublicVariableClient;
			} forEach (allPlayers select {getPlayerUID _x in _groupMemberPUID});

			// Save Group Data
			_return = ["Group", _groupID, _contentArray] call EPOCH_fnc_server_hiveSET;
		};
	};
};
_return
