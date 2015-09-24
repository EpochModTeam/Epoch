/*
Add HiveFunction: Create Group / Set Data
Return:

true = group has been created and / or successfully saved!
false = group exist already and hasn't been saved!
*/
_return = false;
diag_log format["GROUP: Create %1", _this];
_leader = _this select 0;
_groupName = _this select 1;

_textArr = toArray(_groupName);

// exit if greater than 24 chars
if (count _textArr > 24) exitWith{};

// remove any disallowed chars in group name "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 -_"
{
	if !(_x in [97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,49,50,51,52,53,54,55,56,57,48,32,45,95]) then {
		_textArr = _textArr - [_x];
	};
} forEach _textArr;
_groupName = toString _textArr;

if !([_leader,  _this select 2] call EPOCH_server_getPToken) exitWith{};

// get vars array and current Crypto value
_cIndex = EPOCH_customVars find "Crypto";
_vars = _leader getVariable["VARS", [] + EPOCH_defaultVars_SEPXVar];
_current_crypto = _vars select _cIndex;

_upgradePrice = parseNumber (EPOCH_group_upgrade_lvl_SEPXVar select 1);

if (_current_crypto >= _upgradePrice) then {
	if (_groupName != "") then {
		
		_playerCryptoLimit = [(configFile >> "CfgSecConf" >> "limits"), "playerCrypto", 25000] call EPOCH_fnc_returnConfigEntry;
		_current_crypto = ((_current_crypto - _upgradePrice) min _playerCryptoLimit) max 0;
		[["effectCrypto", _current_crypto], (owner _leader)] call EPOCH_sendPublicVariableClient;
		_vars set[_cIndex, _current_crypto];
		_leader setVariable["VARS", _vars];

		_groupID = getPlayerUID _leader;
		//diag_log format["GROUP: Created _groupID %1", _groupID];

		_leaderName = if (alive _leader) then {name _leader} else {"Dead Player"};

		_contentArray = [_groupName, _leaderName, EPOCH_group_upgrade_lvl_SEPXVar select 0, [], []];
		
		[["groupUpdate", _contentArray], (owner _leader)] call EPOCH_sendPublicVariableClient;
		[["groupUidUpdate", _groupID], (owner _leader)] call EPOCH_sendPublicVariableClient;

		_leader setVariable ["GROUP", _groupID];

		// Save Group Data
		["Group", _groupID, _contentArray] call EPOCH_fnc_server_hiveSET;
		_return = true;

	};
};
_return
