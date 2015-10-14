private ["_idx","_txt"];

_idx = lbCurSel (rmx_var_crafting_ctrl_main select 1);
_txt = (rmx_var_crafting_ctrl_main select 1) lbData _idx;
(rmx_var_crafting_ctrl_Interact select 4) ctrlSetText _txt;

true
