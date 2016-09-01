/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors: Aaron Clark

	Description:
	TODO: DESC-TBA

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/scripts/EPOCH_InterruptConfig.sqf
*/
#include "\A3\ui_f\hpp\defineCommonGrids.inc"
disableSerialization;
//[[[cog import generate_private_arrays ]]]
private ["_cfg","_color","_configs","_ctrl","_ctrlPos","_getIDC","_group","_groupIDC","_icon","_idc","_idx","_lb","_name","_offset"];
//[[[end]]]
params [["_display",displayNull,[displayNull] ] ];

_offset = if (isServer) then {40 * GUI_GRID_W + GUI_GRID_X;} else {
	if (getNumber (getMissionConfig "enableDebugConsole") > 0) then {
		40 * GUI_GRID_W + GUI_GRID_X;
	} else {
		17 * GUI_GRID_W + GUI_GRID_X;
	};
};

_cfg = 'CfgEpochConfiguration' call EPOCH_returnConfig;
_configs = "true" configClasses _cfg;

_idc = -70000;
_getIDC = {_idc = _idc - 1; _idc};

Epoch_interrupt_controls = [];
if (isNil "Epoch_interrupt_index") then {Epoch_interrupt_index = 0};

{
	_ctrl = _display ctrlCreate [_x,call _getIDC];
	_ctrlPos = ctrlPosition _ctrl;
	_ctrlPos set [0,_offset];
	_ctrl ctrlSetPosition _ctrlPos;
	_ctrl ctrlCommit 0;

	Epoch_interrupt_controls set [_forEachIndex, _ctrl];
} forEach ["Epoch_main_config_combo","Epoch_main_config_group","Epoch_main_config_title"];

_lb = Epoch_interrupt_controls select 0;
_groupIDC = call _getIDC;
{
	_name =		getText (_x >> "name");
	_color =	getArray (_x >> "color");
	_icon =		getText (_x >> "icon");
	_group = 	getText (_x >> "controlGroup"); //convert to actual hidden control

	_idx = _lb lbAdd _name;
	_lb lbSetColor [_idx, _color];
	_lb lbSetPicture [_idx, _icon];
	_lb lbSetData [_idx, _group];
	_lb lbSetValue [_idx, _groupIDC];

} forEach _configs;

//display does not exist yet for whatever reason
[_lb] spawn {
	waitUntil {!isNull findDisplay 49};
	(_this select 0) lbSetCurSel Epoch_interrupt_index;
};
true
