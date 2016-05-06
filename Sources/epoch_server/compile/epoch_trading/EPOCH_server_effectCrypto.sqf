/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Epoch Mod - Server side effect crypto main function

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server/compile/epoch_trading/EPOCH_server_effectCrypto.sqf

	Example:
    [_player,100] call EPOCH_server_effectCrypto; // adds 100
    [_player,-100] call EPOCH_server_effectCrypto; // removes 100

    Parameter(s):
		_this select 0: OBJECT - player
        _this select 1: NUMBER - amount to add to existing crypto
	Returns:
	MIXED
*/
private ["_cIndex","_vars","_current_crypto"];
params [["_player",objNull,[objNull]],["_crypto",0,[0]]];
if (!isNull _player && isPlayer _player) then {
	// get index of custom variable
	_cIndex = EPOCH_customVars find "Crypto";
	// get custom variables
	_vars = _player getVariable["VARS", call EPOCH_defaultVars_SEPXVar];
	// select current value
	_current_crypto = _vars select _cIndex;
	// get min and max limits for selected custom variable
	(EPOCH_customVarLimits select _cIndex) params ["_playerCryptoLimitMax","_playerCryptoLimitMin"];
	// add input number to existing variable while keeping it within min and max range.
	_current_crypto = ((_current_crypto + _crypto) min _playerCryptoLimitMax) max _playerCryptoLimitMin;
	// send final value back to the player
	_current_crypto remoteExec ['EPOCH_effectCrypto',_player];
	// set final variable
	_vars set[_cIndex, _current_crypto];
	// save modified custom variables array
	_player setVariable["VARS", _vars];
};
