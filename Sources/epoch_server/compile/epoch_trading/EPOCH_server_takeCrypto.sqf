/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Epoch Mod - Server side take crypto

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_trading/EPOCH_server_makeTrade.sqf
*/
private ["_cIndex","_vars","_current_crypto","_change","_player","_object","_player1","_player2","_getCrypto"];
params ["_player",["_token","",[""]],"_object"];

if !([_player,_token] call EPOCH_server_getPToken) exitWith {};
if (isNull _object) exitWith {};
if (_player distance _object > 10) exitWith {};

_getCrypto = _object getVariable["Crypto", 0];
if (_getCrypto > 0) then {

	// remove crypto from object
	_object setVariable["Crypto", nil, true];
	[_player,_getCrypto] call EPOCH_server_effectCrypto;
	// debug and logging.
	diag_log format["Epoch: ADMIN: %1 picked up %2 Crypto from object %3 with puid %4 at %5", getPlayerUID _player, _current_crypto, [_object, typeOf _object],_object getVariable['PUID', ''],getposATL _object];
};
