/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors:

	Description:
	DESC-TBA

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/scripts/craftingv2/EPOCH_crafting_colorScheme.sqf
*/
params ["_cfg"];

rmx_var_crafting_colorScheme = getArray (_cfg >> "colorScheme");

//frames
for "_i" from 0 to 5 do {
	(rmx_var_crafting_ctrl_colorScheme select _i) ctrlSetTextColor (rmx_var_crafting_colorScheme select 16);
};

//recipes
(rmx_var_crafting_ctrl_colorScheme select 6) ctrlSetText (rmx_var_crafting_colorScheme select 3 select 0);
(rmx_var_crafting_ctrl_colorScheme select 6) ctrlSetBackgroundColor (rmx_var_crafting_colorScheme select 3 select 1);
(rmx_var_crafting_ctrl_main select 0) ctrlSetBackgroundColor (rmx_var_crafting_colorScheme select 18);

//ingredients
(rmx_var_crafting_ctrl_colorScheme select 7) ctrlSetText (rmx_var_crafting_colorScheme select 4 select 0);
(rmx_var_crafting_ctrl_colorScheme select 7) ctrlSetBackgroundColor (rmx_var_crafting_colorScheme select 4 select 1);
(rmx_var_crafting_ctrl_main select 0) ctrlSetBackgroundColor (rmx_var_crafting_colorScheme select 19);

//preview
(rmx_var_crafting_ctrl_colorScheme select 8) ctrlSetText (rmx_var_crafting_colorScheme select 5 select 0);
(rmx_var_crafting_ctrl_colorScheme select 8) ctrlSetBackgroundColor (rmx_var_crafting_colorScheme select 5 select 1);

//resources
(rmx_var_crafting_ctrl_colorScheme select 9) ctrlSetText (rmx_var_crafting_colorScheme select 6 select 0);
(rmx_var_crafting_ctrl_colorScheme select 9) ctrlSetBackgroundColor (rmx_var_crafting_colorScheme select 6 select 1);

//description
(rmx_var_crafting_ctrl_colorScheme select 10) ctrlSetText (rmx_var_crafting_colorScheme select 7 select 0);
(rmx_var_crafting_ctrl_colorScheme select 10) ctrlSetBackgroundColor (rmx_var_crafting_colorScheme select 7 select 1);
(rmx_var_crafting_ctrl_main select 2) ctrlSetBackgroundColor (rmx_var_crafting_colorScheme select 17);

//background
(rmx_var_crafting_ctrl_colorScheme select 11) ctrlSetBackgroundColor (rmx_var_crafting_colorScheme select 15);

//QTY
(rmx_var_crafting_ctrl_Interact select 3) ctrlSetTextColor (rmx_var_crafting_colorScheme select 23);
