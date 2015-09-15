private["_vehicle","_value"];

_vehicle = _this select 0;
_value = _this select 1;
if (local _vehicle) then {
	_vehicle lock _value;
};