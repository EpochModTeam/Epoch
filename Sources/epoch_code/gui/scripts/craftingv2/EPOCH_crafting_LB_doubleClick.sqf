/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors:

	Description:
	DESC-TBA

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_code/gui/scripts/craftingv2/EPOCH_crafting_LB_doubleClick.sqf
*/
private ["_idx","_txt"];

_idx = lbCurSel (rmx_var_crafting_ctrl_main select 1);
_txt = (rmx_var_crafting_ctrl_main select 1) lbData _idx;
(rmx_var_crafting_ctrl_Interact select 4) ctrlSetText _txt;

true
