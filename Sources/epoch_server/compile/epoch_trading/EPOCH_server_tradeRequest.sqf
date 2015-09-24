private ["_target","_source","_token"];
_target = _this select 0;
_source = _this select 1;

if !([_source, _this select 2] call EPOCH_server_getPToken) exitWith{};
if (isNull _target) exitWith{};
if (_source distance _target > 10) exitWith{};

// Generate Unique Key good for only this trade request between these two players.
_tradeKey = floor(diag_tickTime + random 9999);
_source setVariable["currentTradeKey", _tradeKey];
_target setVariable["currentTradeKey", _tradeKey];

[["tradeRequest", _source], (owner _target)] call EPOCH_sendPublicVariableClient;