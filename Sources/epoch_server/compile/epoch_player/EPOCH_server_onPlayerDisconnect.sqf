/*
Player Disconnect

Epoch Mod - EpochMod.com
All Rights Reserved.
*/

private["_player", "_return"];

_player = _this select 0;
//_id = _this select 1;
//_uid = _this select 2;
//_name = _this select 3;
// diag_log format["Handle Disconnect: %1 return: %2", _this, _return];
_return = false;
if (!isNull _player) then {
	if (_player getVariable["SETUP", false]) then {
		[_player, _player getVariable["VARS", []], true, true] call EPOCH_server_savePlayer;
		if (alive _player) then {
			deleteVehicle _player;
		};
	} else {
		deleteVehicle _player;
	};
};
_return