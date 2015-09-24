/*
Player Disconnect

Epoch Mod - EpochMod.com
All Rights Reserved.
*/

private["_plyr", "_return"];

_plyr = _this select 0;
//_id = _this select 1;
//_uid = _this select 2;
//_name = _this select 3;
// diag_log format["Handle Disconnect: %1 return: %2", _this, _return];
_return = false;
if (!isNull _plyr) then {
	if (_plyr getVariable["SETUP", false]) then {
		[_plyr, _plyr getVariable["VARS", []], true, true] call EPOCH_server_savePlayer;
		if (alive _plyr) then {
			deleteVehicle _plyr;
		};
	} else {
		deleteVehicle _plyr;
	};
};
_return