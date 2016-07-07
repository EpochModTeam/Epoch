/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors:

	Description:
	Spins a 3D dialog

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/scripts/Epoch_3DctrlSpin.sqf

	Usage:
	[control] call epoch_3DctrlSpin;
*/

_this spawn {
	disableSerialization;
	params ["_ctrl3D"];
	rmx_var_3dCtrlSpin = true;

	_ctrlPos = ctrlPosition _ctrl3D;

	if (isNil "rmx_var_3dCtrlSpin_Vector") then {rmx_var_3dCtrlSpin_Vector = 0;};

	while {rmx_var_3dCtrlSpin} do {
		for "_i" from 0 to 360 do {

			_vector = (360 - _i) - 360;
			_ctrl3D ctrlSetModelDirAndUp [[-(sin _vector),cos _vector,0],[cos _vector * rmx_var_3dCtrlSpin_Vector,sin _vector * rmx_var_3dCtrlSpin_Vector,1]];
			if !(rmx_var_3dCtrlSpin) exitWith{};
			uiSleep 0.01;
		};
	};
};
true
