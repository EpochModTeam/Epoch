/*
	Function Name:			rmx_fnc_consoleUpdate
	Author:					Raimonds Virtoss | Raymix
	Description:			Writes to console
							Can be called to refresh/update console
	License:				---
*/
disableSerialization;

if (!rmx_var_consoleEnabled) exitWith {true}; //required: _ctrl only works when dialog exists

{
	_ctrl = rmx_var_ctrl_console select _forEachIndex;
	_ctrl ctrlSetStructuredText _x;
	_ctrl ctrlCommit 0;
} forEach rmx_var_console_list;

true
