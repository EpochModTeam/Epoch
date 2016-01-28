private["_ok"];
if (isNull _this) exitWith {};
if !(alive _this) exitWith {};
_ok = createdialog "MissionSelect";
if (!_ok) exitWith {};
