// Epoch Mod - Server isde take crypto 

private ["_cIndex","_vars","_current_crypto","_change","_player","_object","_player1","_player2","_getCrypto"];

_player = _this select 0;
if !([_player,_this select 1] call EPOCH_server_getPToken) exitWith {};

_object = _this select 2;
if (isNull _object) exitWith {};

if (_player distance _object > 10) exitWith {};

_getCrypto = _object getVariable["Crypto", 0];

if (_getCrypto > 0) then {

	deleteVehicle _object;

	// get vars array and current Crypto value
	_cIndex = EPOCH_customVars find "Crypto";
	_vars = _player getVariable["VARS", [] + EPOCH_defaultVars_SEPXVar];
	_current_crypto = _vars select _cIndex;
	
	_playerCryptoLimit = [(configFile >> "CfgSecConf" >> "limits"), "playerCrypto", 25000] call EPOCH_fnc_returnConfigEntry;

	_current_crypto = ((_current_crypto + _getCrypto) min _playerCryptoLimit) max 0;
	[["effectCrypto", _current_crypto], (owner _player)] call EPOCH_sendPublicVariableClient;
	_vars set[_cIndex, _current_crypto];
	_player setVariable["VARS", _vars];
};
