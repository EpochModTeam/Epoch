private ["_vehicle","_value"];
_vehicle = _this select 0;
_value = _this select 1;
if (local _vehicle) then {
	_currentDMG = _vehicle getHitIndex (_value select 0);
	_vehicle setHitIndex[_value select 0, (_currentDMG - 0.5) max 0];
};