/*
	Function Name:			rmx_fnc_keyUp
	Author:					Raimonds Virtoss | Raymix
	Description:			This file detects keystrokes released and calls a function
					
							List of all keys:
							https://community.bistudio.com/wiki/ListOfKeyCodes
	
	License:				---
*/
private ["_handled","_key","_dev"];

_key = _this select 1;
_handled = false;

switch (_this select 1) do
{
	default {_handled = true;};
};

//uncomment to find keys on the go
//hint format ["Key [%1] released", (_this select 1)];
_handled;