//[[[cog import generate_private_arrays ]]]
private ["_ok"];
//[[[end]]]
if (isNull _this) exitWith {};
if !(alive _this) exitWith {};
_ok = createdialog "MissionSelect";
if (!_ok) exitWith {};
