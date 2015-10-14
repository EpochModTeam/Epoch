/*
	Spins 3D dialog along X and Z axis following mouse input
	Requires source control to read coords from and destination 3D control
	Can be applied to 3D control itself, but not recommended, pref use transparent rscPicture (enable it).
	_ctrl ctrlSetEventHandler ["MouseMoving", "[_this,control3D] call Epoch_3DctrlPitchYaw"];
*/
params ["_arr","_ctrl3D"];

disableSerialization;

_inX = (_arr select 2) * 720;
_inY = (_arr select 1) * 720;

_dirY = cos _inX;
_upY = -sin _inX;

_dirX =  -(_dirY * sin _inY);
_dirY = _dirY * cos _inY;

_upX =  -(_upY * sin _inY);
_upY = _upY * cos _inY;

_ctrl3D ctrlSetModelDirAndUp [[_dirX,_dirY,sin _inX],[_upX,_upY,cos _inX]];

true
