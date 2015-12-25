private ["_player","_teleporter","_pos","_telePosArray"];

_player = _this select 0;
_teleporter = _this select 1;

if !([_player, _this select 2] call EPOCH_server_getPToken) exitWith{};
if (isNull _teleporter) exitWith{};
if (_player distance _teleporter > 20) exitWith{};

_tp = _teleporter getVariable["ParentBuilding", []];
if !(_tp isEqualTo []) then {
	_player setPosATL _tp;
};
