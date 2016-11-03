// BIS function
//[[[cog import generate_private_arrays ]]]
private ["_d","_v","_x","_y"];
//[[[end]]]
_v = +(_this select 0);
_d = _this select 1;

_x = _v select 0;
_y = _v select 1;

_v set [0, (cos _d)*_x - (sin _d)*_y];
_v set [1, (sin _d)*_x + (cos _d)*_y];

_v
