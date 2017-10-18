/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Add HiveFunction: Create Group / Set Data

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_group/EPOCH_server_createGroup.sqf

	Return:

	true = group has been created and / or successfully saved!
	false = group exist already and hasn't been saved!
*/
//[[[cog import generate_private_arrays ]]]
private ["_cIndex","_contentArray","_current_crypto","_groupID","_groupName","_leaderName","_playerCryptoLimit","_return","_textArr","_upgradePrice","_vars"];
//[[[end]]]
params ["_leader", "_groupName", ["_token","",[""]] ];
if !([_leader, _token] call EPOCH_server_getPToken) exitWith{};

_return = false;
_textArr = toArray(_groupName);

if (count _textArr > 24) exitWith{};
// remove any disallowed chars in group name "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 -_"
{
	if !(_x in [97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,49,50,51,52,53,54,55,56,57,48,32,45,95]) then {
		_textArr = _textArr - [_x];
	};
} forEach _textArr;
_groupName = toString _textArr;

// get vars array and current Crypto value
_cIndex = EPOCH_customVars find "Crypto";
_vars = _leader getVariable["VARS", call EPOCH_defaultVars_SEPXVar];
_current_crypto = _vars select _cIndex;

_upgradePrice = parseNumber (EPOCH_group_upgrade_lvl_SEPXVar select 1);

if (_current_crypto >= _upgradePrice) then {
	if (_groupName != "") then {

		_playerCryptoLimit = EPOCH_customVarLimits select _cIndex;
		_playerCryptoLimit params ["_playerCryptoLimitMax","_playerCryptoLimitMin"];
		_current_crypto = ((_current_crypto - _upgradePrice) min _playerCryptoLimitMax) max _playerCryptoLimitMin;

		_vars set[_cIndex, _current_crypto];
		_leader setVariable["VARS", _vars];

		_current_crypto remoteExec ['EPOCH_effectCrypto',_leader];

		_groupID = getPlayerUID _leader;

		_leaderName = if (alive _leader) then {name _leader} else {"Dead Player"};

		_contentArray = [_groupName, _leaderName, EPOCH_group_upgrade_lvl_SEPXVar select 0, [], []];

		[["groupUpdate", _contentArray], _leader] call EPOCH_sendRemoteExecClient;
		[["groupUidUpdate", _groupID], _leader] call EPOCH_sendRemoteExecClient;

		_leader setVariable ["GROUP", _groupID];

		// Save Group Data
		["Group", _groupID, _contentArray] call EPOCH_fnc_server_hiveSET;
		_return = true;
	};
};
_return
