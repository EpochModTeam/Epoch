/*
	Spins 3D dialog along Z axis following mouse input

	Requires source control to read coords from and destination 3D control
	Can be applied to 3D control itself, but not recommended, pref use transparent rscPicture (enable it).
	_ctrl ctrlSetEventHandler ["MouseMoving", "[_this,control3D] call Epoch_3DctrlPitchYaw"];
*/
params ["_arr","_ctrl3D"];

disableSerialization;

_inX = (_arr select 2) * 180;
_inY = (_arr select 1) * 180;

_ctrl3D ctrlSetModelDirAndUp [[-(cos _inX * sin _inY),cos _inX * cos _inY,0],[0,0,1]];

true
