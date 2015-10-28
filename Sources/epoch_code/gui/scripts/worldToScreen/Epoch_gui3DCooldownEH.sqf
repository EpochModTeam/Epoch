params ["_ctrlGrp", "_loc","_pos","_dst"];
_pos2 = worldToScreen _loc;
if (_pos2 isEqualTo []) then {_pos2 = [-2,-2]};
_pos set [0, (_pos2 select 0)-((_pos select 2)/2)];
_pos set [1, (_pos2 select 1)-((_pos select 3)/2)];
_ctrlGrp ctrlSetPosition _pos;
_scale = linearConversion [0, _dst, player distance _loc, 0, 1, false];
_ctrlGrp ctrlSetFade _scale;
_ctrlGrp ctrlCommit 0;
true
