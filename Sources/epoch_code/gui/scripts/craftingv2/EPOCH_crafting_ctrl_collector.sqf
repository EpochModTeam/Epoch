/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors:

	Description:
	DESC-TBA

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/scripts/craftingv2/EPOCH_crafting_ctrl_collector.sqf
*/

disableSerialization;
//[[[cog import generate_private_arrays ]]]
private ["_display"];
//[[[end]]]

_display = findDisplay 77700;

rmx_var_crafting_ctrl_DEVMisc = [_display displayCtrl 77701,_display displayCtrl 77702];

rmx_var_crafting_ctrl_DEV = [];
{rmx_var_crafting_ctrl_DEV set [count rmx_var_crafting_ctrl_DEV,_display displayCtrl _x];} count

[
	77703, //bckgrnd
	77704, //btn setScale
	77705, //btn export
	77706, //btn setpos
	77707, //btn +
	77708, //btn -				//5
	77709, //edit scale
	77710, //edit x
	77711, //edit z
	77712, //edit y
	77713, //edit vector		//10
	77714,77715,77716,77717,77718,77719 //text

];

rmx_var_crafting_ctrl_Interact = [];
{rmx_var_crafting_ctrl_Interact set [count rmx_var_crafting_ctrl_Interact,_display displayCtrl _x];} count

[
	77801, //btn craft
	77802, //btn clear
	77803, //progress bar
	77804, //progress QTY
	77810 //Search field
];

rmx_var_crafting_ctrl_main = [];
{rmx_var_crafting_ctrl_main set [count rmx_var_crafting_ctrl_main,_display displayCtrl _x];} count

[
	77811, //LB recipes
	77812, //LB ingredients
	77820, //ST description
	77831, //craft frame
	77833, //resource frame
	77843 //resource text
];

rmx_var_crafting_ctrl_colorScheme = [];
{rmx_var_crafting_ctrl_colorScheme set [count rmx_var_crafting_ctrl_colorScheme,_display displayCtrl _x];} count

[
	77830,77831,77832,77833,77834,77835, //frames
	77840, //recipes
	77841, //ingredients
	77842, //preview
	77843, //resources
	77844, //description
	77800	//background
];

rmx_var_craftingENABLED = true;
rmx_var_craftingLOOPS = true;


true
