/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors:

	Description:
	DESC-TBA

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/scripts/craftingv2/EPOCH_crafting_dev_toggle.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_3DCTRL","_3DPos","_ctrlPos","_curLB","_devBtnExport","_devBtnSetPos","_devBtnSetScale","_devX","_devY","_devZ","_mainDevBtn"];
//[[[end]]]
_mainDevBtn = rmx_var_crafting_ctrl_DEVMisc select 1;
_3DCTRL = rmx_var_crafting_ctrl_DEVMisc select 0;

switch (ctrlShown (rmx_var_crafting_ctrl_DEV select 0)) do {
	case true: //off
	{
		disableSerialization;
		{
			_x ctrlShow false;
		} forEach rmx_var_crafting_ctrl_DEV;
		_mainDevBtn ctrlSetText "x\addons\a3_epoch_code\Data\UI\dev_mode_off.paa";
		_3DCTRL ctrlEnable false;
		_3DCTRL ctrlRemoveAllEventHandlers "MouseButtonUp";
		rmx_fnc_craftingExport = nil;
		rmx_fnc_crafting3DPosText = nil;
		rmx_fnc_crafting3DMove = nil;
	};
	case false: //on
	{
		disableSerialization;
		{
			_x ctrlShow true;
		} forEach rmx_var_crafting_ctrl_DEV;
		_mainDevBtn ctrlSetText "x\addons\a3_epoch_code\Data\UI\dev_mode_on.paa";

		private ["_devBtnSetScale","_devBtnExport","_devBtnSetPos"];
		_devBtnSetScale = rmx_var_crafting_ctrl_DEV select 1;
		_devBtnExport = rmx_var_crafting_ctrl_DEV select 2;
		_devBtnSetPos = rmx_var_crafting_ctrl_DEV select 3;

		_3DCTRL ctrlEnable true;

		rmx_fnc_craftingExport = {
			private ["_ctrlPos","_curLB"];

			_ctrlPos = ctrlPosition (rmx_var_crafting_ctrl_DEVMisc select 0);
			_curLB = rmx_var_crafting_ctrl_main select 0;

			//weird UI bug that outputs 1.49012e-008 if setting vector too fast
			if (rmx_var_3dCtrlSpin_Vector < 0.1 && rmx_var_3dCtrlSpin_Vector > -0.1) then {rmx_var_3dCtrlSpin_Vector = 0;};

			diag_log format [
				"
		<< Exporting settings for [%1] >>

		previewPosition[] = {%2,%3,%4};
		previewScale = %5;
		previewVector = %6;
				",
				_curLB lbData (lbCurSel _curLB),
				_ctrlPos select 0,
				_ctrlPos select 1,
				_ctrlPos select 2,
				ctrlModelScale (rmx_var_crafting_ctrl_DEVMisc select 0),
				rmx_var_3dCtrlSpin_Vector
			];
			true
		};
		rmx_fnc_crafting3DPosText = {
			private ["_3DPos","_devX","_devZ","_devY"];
			disableSerialization;
			_devX = rmx_var_crafting_ctrl_DEV select 7;
			_devZ = rmx_var_crafting_ctrl_DEV select 8;
			_devY = rmx_var_crafting_ctrl_DEV select 9;
			_3DPos = ctrlPosition (rmx_var_crafting_ctrl_DEVMisc select 0);

			_devX ctrlSetText str (_3DPos select 0);
			_devZ ctrlSetText str (_3DPos select 1);
			_devY ctrlSetText str (_3DPos select 2);
			true
		};
		rmx_fnc_crafting3DMove = {
			private ["_devX","_devZ","_devY"];
			disableSerialization;
			_devX = rmx_var_crafting_ctrl_DEV select 7;
			_devZ = rmx_var_crafting_ctrl_DEV select 8;
			_devY = rmx_var_crafting_ctrl_DEV select 9;
			(rmx_var_crafting_ctrl_DEVMisc select 0) ctrlSetPosition [(call compile (ctrlText _devX)),(call compile (ctrlText _devZ)),(call compile (ctrlText _devY))];
			true
		};

		_3DCTRL ctrlSetEventHandler ["MouseButtonUp","call rmx_fnc_crafting3DPosText;"];

		_devBtnSetScale buttonSetAction
		"
			(rmx_var_crafting_ctrl_DEVMisc select 0) ctrlSetModelScale ( call compile ctrlText (rmx_var_crafting_ctrl_DEV select 6));
		";

		_devBtnExport buttonSetAction "call rmx_fnc_craftingExport";

		_devBtnSetPos buttonSetAction "call rmx_fnc_crafting3DMove;";

	};
};
