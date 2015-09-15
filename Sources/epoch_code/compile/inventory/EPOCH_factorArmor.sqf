private ["_passThrough","_armor","_factor"];
_passThrough = _this select 0;
_armor = _this select 1;
_factor = 2;
((_armor - (_armor*_passThrough))/_factor + _armor)
