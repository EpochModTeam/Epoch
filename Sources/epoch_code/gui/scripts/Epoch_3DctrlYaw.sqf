/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors: Aaron Clark

	Description:
	Spins 3D dialog along Z axis following mouse input
	Requires source control to read coords from and destination 3D control
	Can be applied to 3D control itself, but not recommended, pref use transparent rscPicture (enable it).

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/scripts/Epoch_3DctrlYaw.sqf

	Usage:
	_ctrl ctrlSetEventHandler ["MouseMoving", "[_this,control3D] call Epoch_3DctrlPitchYaw"];
*/
//[[[cog import generate_private_arrays ]]]
private ["_inX","_inY"];
//[[[end]]]
params ["_arr","_ctrl3D"];

disableSerialization;

_inX = (_arr select 2) * 180;
_inY = (_arr select 1) * 180;

_ctrl3D ctrlSetModelDirAndUp [[-(cos _inX * sin _inY),cos _inX * cos _inY,0],[0,0,1]];

true
