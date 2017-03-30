params [["_player",objNull,[objNull]],["_crypto",0,[0]],["_token","",[""]]];
if !([_player, _token] call EPOCH_server_getPToken) exitWith{};
if (_crypto > 0) exitwith {	// This is only for pay Crypto, not for give Crypto ;)
	diag_log format ['Player %1 (%2) killed for Code hack',name _player, getplayeruid _player];
	_player setdamage 1
};
_this call EPOCH_server_effectCrypto;
