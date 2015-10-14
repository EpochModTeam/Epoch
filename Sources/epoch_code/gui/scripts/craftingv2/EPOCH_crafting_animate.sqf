
params ["_ctrl","_first","_second",["_speed",0.5]];

_ctrl ctrlSetPosition _first;
_ctrl ctrlCommit 0;
_ctrl ctrlSetPosition _second;
_ctrl ctrlCommit _speed;

true
