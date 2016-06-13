/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors:

	Description:
	DESC-TBA

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/scripts/craftingv2/EPOCH_crafting_unload.sqf
*/
rmx_var_craftingLOOPS = false;
rmx_var_3dCtrlSpin = false;
//post processing fade to defaults
[rmx_var_crafting_PP_CC, 1, [1,1,0,0,0,0,0,0,0,0,1,0,0,0,0]] call epoch_postprocessAdjust;
[rmx_var_crafting_PP_DB, 1, [0]] call epoch_postprocessAdjust;

[] spawn {
	uiSleep 1; //delay required for loops to finish
	rmx_var_crafting_PP_CC call epoch_postprocessDestroy;
	rmx_var_crafting_PP_DB call epoch_postprocessDestroy;
	rmx_var_crafting_PP_CC = nil;
	rmx_var_crafting_PP_DB = nil;
	rmx_var_crafting_ctrl_DEV = nil;
	rmx_var_crafting_ctrl_Interact = nil;
	rmx_var_crafting_ctrl_main = nil;
	rmx_var_crafting_ctrl_colorScheme = nil;
	rmx_var_crafting_ctrl_GROUP = nil;
	rmx_var_crafting_progressClicked = nil;
	rmx_var_crafting_SearchConfigData = nil;
	rmx_var_craftQTY = nil;
	rmx_var_craftQTYOut = nil;
	rmx_var_craftInProgress = nil;
	rmx_var_crafting_colorScheme = nil;

	rmx_var_craftingENABLED = false;
};

true
