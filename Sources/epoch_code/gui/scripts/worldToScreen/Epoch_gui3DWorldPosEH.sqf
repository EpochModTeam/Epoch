params ["_ctrl","_loc","_pos","_dst"];
_pos2 = worldToScreen _loc;
if (_pos2 isEqualTo []) then {_pos2 = [-2,-2]};
_pos set [0, (_pos2 select 0)-((_pos select 2)/2)];
_pos set [1, (_pos2 select 1)-((_pos select 3)/2)];
_ctrl ctrlSetPosition _pos;
_scale = linearConversion [0, _dst, player distance _loc, 0, 1, false];
_ctrl ctrlSetFade _scale;
_ctrl ctrlCommit 0;

//[_ctrl, _scale, 0] call BIS_fnc_ctrlSetScale;
true
