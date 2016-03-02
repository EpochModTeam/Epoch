_unit = _this select 0;
_player = _this select 1;

if !([_player, _this select 2] call EPOCH_server_getPToken) exitWith{};
if (isNull _unit) exitWith{};
if (_player distance _unit > 20) exitWith{};

if (typeOf _unit == "Jack_SIM_EPOCH") then {
	deleteVehicle _unit;
	_player addMagazine["JackKit", 1];
	// diag_log format["added JackKit to %1", _player];
};
