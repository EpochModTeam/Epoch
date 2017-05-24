/*
	Function Name:			rmx_fnc_codeEditor
	Author:					Raimonds Virtoss | Raymix
	Description:			Display custom in-game code Editor with tabs saved to HDD
							Usage: Press ENTER to toggle menu on or off
	
	License:				---
*/
#include <\x\Addons\rmx_init\defines.inc>
private ["_display"];
disableSerialization;

if (rmx_var_editorControl) exitWith {
	findDisplay 7100 closeDisplay 1;
	rmx_var_editorControl = false;
};

rmx_var_editorControl = true;

findDisplay 46 createDisplay "dUI_editor";
_display = findDisplay 7100;
_display displayAddEventHandler ["keyDown", "_this call rmx_fnc_keyDown;"];

rmx_var_ctrl_editorMain = [_display displayCtrl 7200, _display displayCtrl 7300];
rmx_var_ctrl_editorItems = [];

for "_i" from 7200 to 7216 do {
	rmx_var_ctrl_editorItems set [count rmx_var_ctrl_editorItems,_display displayCtrl _i];
};

true

















