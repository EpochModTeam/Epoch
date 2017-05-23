/*
	Function Name:			rmx_dev_output
	Author:					Raimonds Virtoss | Raymix
	Description:			outputs params from quick function
	
	Usage: 					["hint","Test"] call d_dev_output;
							"Test" call d_dev_output;
	
	License:				---
*/
#include <\x\Addons\rmx_init\defines.inc>

if (typeName _this != typeName []) then {_this = [_this];};
if (typeName (_this select 0) == "CONTROL") then {_this = ["No params"]};

switch (_this select 0) do {
	default {
		diag_log str _this;
	};
	case "hint":
	{
		hint str (_this select 1);
	};
	case "hintSilent":
	{
		hintSilent str (_this select 1);
	};
	case "diag_log":
	{
		diag_log str (_this select 1);
	};
	case "systemChat":
	{
		systemChat str (_this select 1);
	};
	case "info":
	{
		(_this select 1) info;
	};
	case "warning":
	{
		(_this select 1) warning;
	};
	case "critical":
	{
		(_this select 1) critical;
	};
};