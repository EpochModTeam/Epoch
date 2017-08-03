/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors:

	Description: loaded every time Gear menu is opened
	
	
	Developer's FYI:
	To increase amount of favorite bars you need to edit:
	CfgDynamicHUD.hpp - increase array sizes for fav_*, maybe even width/height
	EPOCH_clientKeyMap.sqf - add keys to keymap array
	EPOCH_keyDown.sqf - add new keys to dikCode check array
	epoch_favBar_action.sqf - add tile indexes for new keymaps
	epoch_favBar_draw.sqf - increase FOR loop accordingly
	epoch_favBar_refresh.sqf - increase FOR loop accordingly
	THIS script - increase FOR loop accordingly

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/scripts/favBar/epoch_favBar_inventory.sqf

	Usage: none
*/
private ["_display","_c","_gIdx","_g"];

if !(["CfgEpochClient", "Fav_enableFavoriteBar", true] call EPOCH_fnc_returnConfigEntryV2) exitWith {false};
disableSerialization;
waitUntil {!isNull findDisplay 602};

_display = (findDisplay 602);
_display displayAddEventHandler ["MouseButtonUp","[] spawn {rmx_var_fav_selected = false}"];
rmx_var_fav_selected = false;
{
	_c = _display displayCtrl _x;
	_c ctrlAddEventHandler ["LBDrag","rmx_var_favBar_Item = (_this call epoch_favBar_getGearItem); rmx_var_fav_selected = true"];
} forEach [619,638,633];
// call epoch_getGearItem;
//(_this select 1 select 0 select 2)
{
	_c = _display displayCtrl _x;
	_c ctrlAddEventHandler ["MouseButtonDown",(format ["call epoch_favBar_modifier; rmx_var_favBar_Item = %1 call epoch_favBar_getItemByIDC; rmx_var_fav_selected = true",_x])];
} forEach [610,620,641,622,621,644,623,611,624,642,626,625,627,612,628,643,630,629,631,6240,6216,6217,6238];

_gIdx = 0;

{
	if ((_x select 0) isEqualTo "fav_pic") exitWith {_gIdx = _forEachIndex};
} forEach rmx_var_dynamicHUD_groupCTRL;

_g = _display ctrlCreate ["rmx_rscControlsGroup",125342];
_g ctrlSetPosition (ctrlPosition (rmx_var_dynamicHUD_groups select _gIdx));
_g ctrlCommit 0;
for "_i" from 0 to 4 do {
	
	_c = _display ctrlCreate ["RscPictureKeepAspect",125342+_i,_g];
	_c ctrlSetPosition (ctrlPosition (["fav_pic", _i + 1] call epoch_getHUDCtrl));
	_c ctrlSetText "#(rgb,8,8,3)color(1,1,1,0.1)";
	_c ctrlCommit 0;
	_c ctrlSetEventHandler ["MouseButtonUp",format["['remove',%1,(_this select 1)] call epoch_favBar_draw;",_i]];
	_c ctrlSetEventHandler ["MouseEnter",format ["if (rmx_var_fav_selected) then {['add',%1] call epoch_favBar_draw; rmx_var_fav_dragging = false}",_i]];
	_c ctrlEnable true;
	
	_c = _display ctrlCreate ["RscPictureKeepAspect",125342+_i,_g];
	_c ctrlSetPosition (ctrlPosition (["fav_pic_bg", _i + 1] call epoch_getHUDCtrl));
	_c ctrlSetText "x\addons\a3_epoch_code\Data\UI\favbar\fav_bg2.paa";
	_c ctrlSetTextColor [0,0,0,0.5];
	_c ctrlCommit 0;
};

for "_i" from 1 to 5 do {
	(["fav_keymap", _i] call epoch_getHUDCtrl) ctrlShow true;
	(["fav_pic_bg", _i] call epoch_getHUDCtrl) ctrlShow true;
};

true 
/*
{
_crl = _display displayCtrl _x;
_c = _display ctrlCreate ["RscText",1253422+_forEachIndex];
_c ctrlSetPosition (ctrlPosition _crl);
_c ctrlSetText (format ["%2",ctrlClassName _crl, _x]);
_c ctrlCommit 0;
}foreach [610,620,641,622,621,644,623,611,624,642,626,625,627,612,628,643,630,629,631,6240,6216,6217,6238];
*/
//Listboxes?
//6325,1241
//619,638,633