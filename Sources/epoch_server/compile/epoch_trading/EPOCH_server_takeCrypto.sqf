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
//[[[cog import generate_private_arrays ]]]
private ["_getCrypto"];
//[[[end]]]
params ["_player",["_token","",[""]],["_CryptoItems",[]]];

if !([_player,_token] call EPOCH_server_getPToken) exitWith {};

_getCrypto = 0;
{
	if (_player distance _x < 10) then {
		_getCrypto = _getCrypto + (_x getVariable ["Crypto", 0]);
		_x setVariable ["Crypto", nil, true];
		if (_x getvariable ["RemoveOnTake",false]) then {
			deletevehicle _x;
		};
	};
} foreach _CryptoItems;
if (_getCrypto > 0) then {
	[_player,_getCrypto] call EPOCH_server_effectCrypto;
	diag_log format["Epoch: ADMIN: %1 picked up %2 Crypto at %3", getPlayerUID _player, _getCrypto, getposATL _player];
};