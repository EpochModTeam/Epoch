params ["_ctrl", "_obj", "_loc","_pos","_dst"];
_m2w = _obj modelToWorld _loc;
_pos2 = worldToScreen _m2w;
if (_pos2 isEqualTo []) then {_pos2 = [-2,-2]};
_pos set [0, (_pos2 select 0)-((_pos select 2)/2)];
_pos set [1, (_pos2 select 1)-((_pos select 3)/2)];
_ctrl ctrlSetPosition _pos;
_scale = linearConversion [0, _dst, player distance _m2w, 0, 1, false];
_ctrl ctrlSetFade _scale;
_ctrl ctrlCommit 0;
true
