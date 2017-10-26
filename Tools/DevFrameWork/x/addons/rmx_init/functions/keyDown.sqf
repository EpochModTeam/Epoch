/*
	Function Name:			rmx_fnc_keyDown
	
	Author:					Raimonds Virtoss | Raymix
	Description:			This file detects keystrokes released and calls a function
					
							List of all keys:
							https://community.bistudio.com/wiki/ListOfKeyCodes
	
	License:				---
*/
private ["_handled","_key","_dev","_shift","_ctrl","_alt"];

_key = param [1,0];
_shift = param [2,false];
_ctrl = param [3,false];
//_alt = param [4,false];

_handled = false;

//disable annoying cmd menu in SP
//if (isServer) then {
	if (_this select 1 in [
		2,3,4,5,6,7,8,9,10,11, //1-0
		59,60,61,62,63,64,65,66,67,68, //F1-F0
		14, //backspace
		41 //tilde
	]) then {
		[] spawn {
			waitUntil {commandingMenu != ""}; 
			showCommandingMenu "";
		};
	};
//};

switch (_this select 1) do
{
/*
	case 5:
	{
		_rnd = "";
		for "_i" from 0 to (floor random 50) + 2 do {
			_rnd = _rnd + (["a","b","c","d","1","2","3","4"," ","!"] select (floor random 10));
		};
		_st = composeText [parseText "<t color='#ff0000' size='1'>red text here </t>", linebreak, parseText "<t color='#00ff00' size='1'>green text here </t>"];
		[_st,floor random 10] call Epoch_dynamicText;
	};

	case 57:
	{
		//[cursorTarget modelToWorld [0,0,0], floor random 10, 10] call Epoch_gui3DCooldown;
		//[cursorTarget, 10, "x\addons\a3_epoch_code\Data\UI\buttons\player_inspect.paa", "Testtesttest", [0,0,0]] call epoch_gui3dModelPos;
		//[player modelToWorld [0,2,2],10,"x\addons\a3_epoch_code\Data\UI\buttons\player_inspect.paa", "Testtesttest"] call epoch_gui3dWorldPos;
		//[cursorTarget,0] call epoch_guiObjHP;
		_handled = true;
	};
*/
	case 14: //BACKSPACE
	{
		if (_ctrl) then {
			'rmx_fnc_sandbox' call rmx_fnc_recompile; [] spawn rmx_fnc_sandbox;
		};
	};
	case 28: //ENTER
	{
		if (_ctrl) then {
			call rmx_fnc_codeEditor;
		_handled = true;
		};
	};
	case 74: {rmx_var_3dCtrlSpin_Vector = rmx_var_3dCtrlSpin_Vector - 0.1;};
	case 78: {rmx_var_3dCtrlSpin_Vector = rmx_var_3dCtrlSpin_Vector + 0.1;};
	case 60: //F2
	{
		call rmx_fnc_console;
		_handled = true;
	};
	case 61: //F3
	{
		call rmx_fnc_quickFnc;
		_handled = true;
	};
	case 62: //F4
	{
		call rmx_fnc_watcher;
		_handled = true;
	};
	case 63: //F5
	{
		call rmx_fnc_atmosFear;
		_handled = true;
	};
	case 64: //F6
	{
		call rmx_fnc_ppViewer;
		_handled = true;
	};
	case 65: //F7
	{
		["Reserved for particle effects GUI editor","Hotkey reserved!"] spawn bis_fnc_guiMessage;
		_handled = true;
	};
	case 66: //F8
	{
		["Reserved for camera director GUI editor","Hotkey reserved!"] spawn bis_fnc_guiMessage;
		_handled = true;
	};

};

//uncomment to find keys on the go
//hint format ["Key [%1] pressed", (_this select 1)];
_handled;