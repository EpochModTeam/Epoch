/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors:

	Description:
	DESC-TBA

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/scripts/craftingv2/EPOCH_crafting_LB_defaults.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_STdesc","_idx","_lbColor","_playerGear","_recipeCTRL","_y"];
//[[[end]]]

_recipeCTRL = rmx_var_crafting_ctrl_main select 0;
_STdesc = rmx_var_crafting_ctrl_main select 2;
_lbColor = rmx_var_crafting_colorScheme select 10;

lbClear _recipeCTRL;
_playerGear = (magazines player) + (items player) + (weapons player);
{
	_idx = if (_x select 0 in _playerGear) then {
		_y = _x select 0;
		_idx = _recipeCTRL lbAdd format (["%1x %2",({_x == _y}count _playerGear),(_x select 1)]);
		_recipeCTRL lbSetColor [_idx,_lbColor];
		_idx
	} else {
		_recipeCTRL lbAdd (_x select 1)
	};
	_recipeCTRL lbSetPictureRight [_idx,(_x select 2)];
	_recipeCTRL lbSetData [_idx,(_x select 0)];
} forEach rmx_var_crafting_SearchConfigData;

_STdesc ctrlSetStructuredText composeText
[
	parseText "<t color='#FD7F30'>Search: <t color='#FFFFFF'>Find recipe, X to clear.</t><br />",
	parseText "<t color='#FD7F30'>Recipes: <t color='#FFFFFF'>Select an item to craft.</t><br />",
	parseText "<t color='#FD7F30'>Ingredients: <t color='#FFFFFF'>Items required to craft.</t><br />",
	parseText "<t color='#FD7F30'>Quantity: <t color='#FFFFFF'>Move slider to set amount.</t><br />",
	parseText "<br /><t color='#E1FD70'>TIP: <t color='#FFFFFF'>Double click an item inside ingredients list to find recipe for it.</t><br />",
	parseText "<br /><t color='#FD7F30'>www: <t color='#FFFFFF'><a href='http://epochmod.com/'>EpochMod.com</a></t>"
];

true
