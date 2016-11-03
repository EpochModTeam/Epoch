/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors:

	Description:
	DESC-TBA

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/scripts/craftingv2/EPOCH_crafting_LB_click.sqf
*/
if (rmx_var_crafting_SearchConfigData isEqualTo []) exitWith {false};

//[[[cog import generate_private_arrays ]]]
private ["_3DCTRL","_STdesc","_c","_cfg","_countData","_data","_idx","_ingredientCTRL","_ingredientData","_itemsNearby","_itemsPlayer","_itemsRequired","_lbColor","_nearbyCount","_p","_r","_recipes","_selection","_usedIn","_x"];
//[[[end]]]

_cfg = 'CfgCrafting' call EPOCH_returnConfig;
_ingredientCTRL = rmx_var_crafting_ctrl_main select 1;
_STdesc = rmx_var_crafting_ctrl_main select 2;
_3DCTRL = rmx_var_crafting_ctrl_DEVMisc select 0;
_selection = lbCurSel (rmx_var_crafting_ctrl_main select 0);
_ingredientData = rmx_var_crafting_SearchConfigData select _selection;
_recipes = _ingredientData select 7;
_usedIn = _ingredientData select 9;

_nearbyCount = []; //required

lbClear _ingredientCTRL;

if !(_recipes isEqualTo []) then {
	_nearbyCount = [_recipes] call EPOCH_crafting_checkGear;
	_idx = _ingredientCTRL lbAdd (rmx_var_crafting_colorScheme select 8 select 0);
	_ingredientCTRL lbSetColor [_idx,(rmx_var_crafting_colorScheme select 8 select 1)];
	{
		if !(_x isEqualType []) then {_x = [_x,1]};
		_data = ([(_cfg >> (_x select 0))] call EPOCH_crafting_getConfig) select 0;
		_idx = _ingredientCTRL lbAdd format ["%2 x %1",(_data select 1),_x select 1];
		_ingredientCTRL lbSetPictureRight [_idx,(_data select 2)];
		_ingredientCTRL lbSetData [_idx, (_data select 1)];

		_countData = _nearbyCount select _forEachIndex;
		_itemsPlayer = _countData select 0;
		_itemsNearby = _countData select 1;
		_itemsRequired = _countData select 2;
		_ingredientCTRL lbSetTooltip [_idx,format ["On player: [%1/%2], Nearby: [%3/%2], Crafting time: %4 second(s)",_itemsPlayer,_itemsRequired,_itemsNearby,_ingredientData select 6]];

		_lbColor = if (_itemsPlayer >= _itemsRequired) then {
			rmx_var_crafting_colorScheme select 11
		} else {
			if (_itemsNearby >= _itemsRequired) then {
				rmx_var_crafting_colorScheme select 12
			} else {
				rmx_var_crafting_colorScheme select 13
			};
		};
		_ingredientCTRL lbSetColor [_idx,_lbColor];

	} forEach _recipes;
};
if !(_usedIn isEqualTo []) then {
	_ingredientCTRL lbAdd "";
	_idx = _ingredientCTRL lbAdd (rmx_var_crafting_colorScheme select 9 select 0);
	_ingredientCTRL lbSetColor [_idx,(rmx_var_crafting_colorScheme select 9 select 1)];

	{
		//if !(_x isEqualType []) then {_x = [_x,1]};
		_data = ([(_cfg >> _x)] call EPOCH_crafting_getConfig) select 0;
		_idx = _ingredientCTRL lbAdd format ["%1",(_data select 1)];
		_ingredientCTRL lbSetPictureRight [_idx,(_data select 2)];
		_ingredientCTRL lbSetData [_idx, (_data select 1)];
		_ingredientCTRL lbSetColor [_idx,(rmx_var_crafting_colorScheme select 14)];
		_ingredientCTRL lbSetTooltip [_idx,"Double click to search for this item"];
	} forEach _usedIn;
};
_STdesc ctrlSetStructuredText (composeText [(_ingredientData select 3),parseText "<br /><br />",parseText(_ingredientData select 14)]);

_3DCTRL ctrlSetModel (_ingredientData select 4);
_3DCTRL ctrlSetPosition (_ingredientData select 10);
_3DCTRL ctrlSetModelScale (_ingredientData select 11);
rmx_var_3dCtrlSpin_Vector = (_ingredientData select 12);

ctrlSetFocus _ingredientCTRL;
(rmx_var_crafting_ctrl_Interact select 2) progressSetPosition 0;

//Crafting quantity math
rmx_var_craftQTY = if !(_nearbyCount isEqualTo []) then {
	private ["_c","_p","_r","_arr"];
	_c = 1e39; //infinite
	{
		_p = _x select 0;
		_r = _x select 2;
		if (_p < _r) exitWith {_c = 0};
		_c = _c min (_p / _r);
	} forEach _nearbyCount;
	floor _c
} else { 0 };

true call EPOCH_crafting_checkResources;

if (ctrlShown (rmx_var_crafting_ctrl_DEV select 0)) then {
	call rmx_fnc_crafting3DPosText;
	(rmx_var_crafting_ctrl_DEV select 6) ctrlSetText str (_ingredientData select 11); //scale
	(rmx_var_crafting_ctrl_DEV select 10) ctrlSetText str (_ingredientData select 12); //vector
};

true
