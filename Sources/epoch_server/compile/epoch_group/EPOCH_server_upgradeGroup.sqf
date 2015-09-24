private [
	"_groupID","_player"
	,"_contentArray","_found"
	,"_newGroupSize","_groupMemberPUID"
];

_groupID = _this select 0;
_player = _this select 1;

if !([_player, _this select 2] call EPOCH_server_getPToken) exitWith{};

diag_log format["GROUP: Upgrade %1", _this];

// get vars array and current Crypto value
_cIndex = EPOCH_customVars find "Crypto";
_vars = _player getVariable["VARS", [] + EPOCH_defaultVars_SEPXVar];
_current_crypto = _vars select _cIndex;

// [_groupName, _leaderName, _groupSize, _modArray, _memberArray]
_response = ["Group", _groupID] call EPOCH_fnc_server_hiveGETRANGE;
if ((_response select 0) == 1 && typeName (_response select 1) == "ARRAY") then {
	_contentArray = (_response select 1);
	_found = EPOCH_group_upgrade_lvl_SEPXVar find (_contentArray select 2);

	if ((_found != -1) && count EPOCH_group_upgrade_lvl_SEPXVar >= (_found + 3)) then {
		_newGroupSize = EPOCH_group_upgrade_lvl_SEPXVar select (_found + 2);

		_upgradePrice = parseNumber	(EPOCH_group_upgrade_lvl_SEPXVar select (_found+3));

		if (_current_crypto >= _upgradePrice) then {

			_playerCryptoLimit = [(configFile >> "CfgSecConf" >> "limits"), "playerCrypto", 25000] call EPOCH_fnc_returnConfigEntry;
			_current_crypto = ((_current_crypto - _upgradePrice) min _playerCryptoLimit) max 0;
			[["effectCrypto", _current_crypto], (owner _player)] call EPOCH_sendPublicVariableClient;
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
				if (getPlayerUID _x in _groupMemberPUID) then {
					[["groupUpdate", _contentArray], (owner _x)] call EPOCH_sendPublicVariableClient;
				};
			} forEach playableUnits;

			// Save Group Data
			["Group", _groupID, _contentArray] call EPOCH_fnc_server_hiveSET;
		};
	};
};
