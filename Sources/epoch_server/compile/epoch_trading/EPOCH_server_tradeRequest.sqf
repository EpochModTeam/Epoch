/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Epoch Mod - Server side take crypto

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server/compile/epoch_trading/EPOCH_server_tradeRequest.sqf
*/
private ["_tradeKey"];
params ["_target","_source",["_token","",[""]]];

if !([_source, _token] call EPOCH_server_getPToken) exitWith{};
if (isNull _target) exitWith{};
if (_source distance _target > 10) exitWith{};

// Generate Unique Key good for only this trade request between these two players.
_tradeKey = floor(diag_tickTime + random 9999);
_source setVariable["currentTradeKey", _tradeKey];
_target setVariable["currentTradeKey", _tradeKey];

// send to player
_source remoteExec ['EPOCH_tradeRequest',_target];
