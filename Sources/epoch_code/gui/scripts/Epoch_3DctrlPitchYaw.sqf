/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors: Aaron Clark

	Description:
	Spins 3D dialog along X and Z axis following mouse input
	Requires source control to read coords from and destination 3D control
	Can be applied to 3D control itself, but not recommended, pref use transparent rscPicture (enable it).

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/scripts/Epoch_3DctrlPitchYaw.sqf

	Usage:
	_ctrl ctrlSetEventHandler ["MouseMoving", "[_this,control3D] call Epoch_3DctrlPitchYaw"];
*/
//[[[cog import generate_private_arrays ]]]
private ["_dirX","_dirY","_inX","_inY","_upX","_upY"];
//[[[end]]]
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
