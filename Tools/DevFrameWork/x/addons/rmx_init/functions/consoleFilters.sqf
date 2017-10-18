/*
	Function Name:			rmx_fnc_consoleFilters
	Author:					Raimonds Virtoss | Raymix
	Description:			Manages debug console and saves settings to profile if required
	
	License:				---
*/
#include <\x\Addons\rmx_init\defines.inc>
private ["_case","_checkBoxState"];
disableSerialization;

_case = str (_this select 0);
_checkBoxState = _this select 1;
switch (_case) do { //TODO - save to profile Namespace
	case "Control #9205": //Checkbox: info
	{
		rmx_var_consoleCheckbox_info = if (_checkBoxState == 1) then {true} else {false};
	};
	case "Control #9206": //Checkbox: warnings
	{
		rmx_var_consoleCheckbox_warnings = if (_checkBoxState == 1) then {true} else {false};
	};
	case "Control #9207": //Checkbox: critical
	{
		rmx_var_consoleCheckbox_critical = if (_checkBoxState == 1) then {true} else {false};
	};
	case "Control #9208": //Checkbox: pause
	{
		rmx_var_consoleCheckbox_pause = if (_checkBoxState == 1) then {true} else {false};
	};
	case "Control #9209": //Button -
	{
		private ["_item","_currPosItem","_console","_currPos","_newPos"];
		
		if (rmx_var_consoleSetting <= 0) exitWith {rmx_var_consoleSetting = 0};
		for "_i" from 0 to 11 do {
			_item = rmx_var_ctrl_consoleItems select _i;
			_currPosItem = ctrlPosition _item;
			_item ctrlSetPosition [_currPosItem select 0,(_currPosItem select 1) - 0.2,_currPosItem select 2,_currPosItem select 3];
			_item ctrlCommit 0.2;
		};
		
		_console = rmx_var_ctrl_consoleItems select 12;
		_currPos = ctrlPosition _console;
		_newPos = [_currPos select 0,_currPos select 1,_currPos select 2,(_currPos select 3) - 0.2];
		_console ctrlSetPosition _newPos;
		_console ctrlCommit 0.2;
		rmx_var_consoleSetting = rmx_var_consoleSetting -0.2;
	};
	case "Control #9210": //Button +
	{
		private ["_item","_currPosItem","_console","_currPos","_newPos"];
		
		if (rmx_var_consoleSetting >= 1.6) exitWith {rmx_var_consoleSetting = 1.6};
		for "_i" from 0 to 11 do {
			_item = rmx_var_ctrl_consoleItems select _i;
			_currPosItem = ctrlPosition _item;
			_item ctrlSetPosition [_currPosItem select 0,(_currPosItem select 1) + 0.2,_currPosItem select 2,_currPosItem select 3];
			_item ctrlCommit 0.2;
		};
		
		_console = rmx_var_ctrl_consoleItems select 12;
		_currPos = ctrlPosition _console;
		_newPos = [_currPos select 0,_currPos select 1,_currPos select 2,(_currPos select 3) + 0.2];
		_console ctrlSetPosition _newPos;
		_console ctrlCommit 0.2;
		rmx_var_consoleSetting = rmx_var_consoleSetting + 0.2;
	};
	case "Control #9211": //Button Clear
	{
		for "_i" from 0 to 39 do {
			rmx_var_console_list set [_i,(text "")];
		};
		rmx_var_logBuffer = [];
		call rmx_fnc_consoleUpdate;
	};
	default {format ["Wrong input: %1",_this] warning;};	
};

//save variable settings permanently
profileNamespace setVariable ["rmx_var_consoleSetting",rmx_var_consoleSetting];
profileNamespace setVariable ["rmx_var_consoleCBstate",[rmx_var_consoleCheckbox_info,rmx_var_consoleCheckbox_warnings,rmx_var_consoleCheckbox_critical,rmx_var_consoleCheckbox_pause]];