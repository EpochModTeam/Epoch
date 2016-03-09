/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Epoch Mod - Server side take crypto

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server/compile/epoch_trading/EPOCH_server_makeTrade.sqf
*/
private ["_cIndex","_vars","_current_crypto","_change","_player","_object","_player1","_player2","_getCrypto"];
params ["_player","_token","_object"];

if !([_player,_token] call EPOCH_server_getPToken) exitWith {};
if (isNull _object) exitWith {};
if (_player distance _object > 10) exitWith {};

_getCrypto = _object getVariable["Crypto", 0];
if (_getCrypto > 0) then {

	deleteVehicle _object;

	// get vars array and current Crypto value
	_cIndex = EPOCH_customVars find "Crypto";
	_vars = _player getVariable["VARS", [] + EPOCH_defaultVars_SEPXVar];
	_current_crypto = _vars select _cIndex;

	_playerCryptoLimit = [(configFile >> "CfgSecConf" >> "limits"), "playerCrypto", 250000] call EPOCH_fnc_returnConfigEntry;

	_current_crypto = ((_current_crypto + _getCrypto) min _playerCryptoLimit) max 0;
	// send to player
	_current_crypto remoteExec ['EPOCH_effectCrypto',(owner _player)];
	_vars set[_cIndex, _current_crypto];
	_player setVariable["VARS", _vars];
};
