disableSerialization;
_display = param [0,displayNull];

if (isNull _display) exitWith {false};

private ["_offset","_cfg","_configs","_idc","_getIDC","_mainCTRLS"];

_offset = if (isServer) then { 0.496012 * safezoneW + safezoneX } else {
	if (getNumber (missionConfigFile >> "enableDebugConsole") > 0) then {
		0.496012 * safezoneW + safezoneX
	} else {
		0.208156 * safezoneW + safezoneX
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
