/*
	Function Name:			rmx_fnc_console
	Author:					Raimonds Virtoss | Raymix
	Description:			Display custom in-game console
							Usage: Press F2 to enable
							Note: Player movement is not disabled
	
	License:				---
*/
#include <\x\Addons\rmx_init\defines.inc>
private ["_display","_item","_currPosItem","_console","_currPos","_newPos"];
disableSerialization;

switch (rmx_var_consoleEnabled) do {
	case false: 
		{
			if (_shift) then {
				findDisplay 46 createDisplay "dUI_console";
				_display = findDisplay 9100;
				_display displayAddEventHandler ["keyDown", "_this call rmx_fnc_keyDown;"];
			} else {
				9100 cutRsc ["dUI_console2","PLAIN"];
				_display = uiNamespace getVariable "rmx_var_console2";
			};
			rmx_var_ctrl_console = [];
			rmx_var_ctrl_consoleItems = [];
			
			for "_i" from 9000 to 9039 do {
				rmx_var_ctrl_console set [count rmx_var_ctrl_console,_display displayCtrl _i];
			};
			
			{rmx_var_ctrl_consoleItems set [count rmx_var_ctrl_consoleItems,_display displayCtrl _x];
			}count [9200,9201,9202,9203,9204,9205,9206,9207,9208,9209,9210,9211,9050];

			(rmx_var_ctrl_consoleItems select 5) cbSetChecked  rmx_var_consoleCheckbox_info;
			(rmx_var_ctrl_consoleItems select 6) cbSetChecked  rmx_var_consoleCheckbox_warnings;
			(rmx_var_ctrl_consoleItems select 7) cbSetChecked  rmx_var_consoleCheckbox_critical;
			(rmx_var_ctrl_consoleItems select 8) cbSetChecked  rmx_var_consoleCheckbox_pause;
			
			if (rmx_var_consoleSetting <= 0) then {rmx_var_consoleSetting = 0}; //correct min
			if (rmx_var_consoleSetting >= 1.6) then {rmx_var_consoleSetting = 1.6}; //correct max
			for "_i" from 0 to 11 do {
				_item = rmx_var_ctrl_consoleItems select _i;
				_currPosItem = ctrlPosition _item;
				_item ctrlSetPosition [_currPosItem select 0,(_currPosItem select 1) + rmx_var_consoleSetting,_currPosItem select 2,_currPosItem select 3];
				_item ctrlCommit 0.2;
			};
			
			_console = rmx_var_ctrl_consoleItems select 12;
			_currPos = ctrlPosition _console;
			_newPos = [_currPos select 0,_currPos select 1,_currPos select 2,(_currPos select 3) + rmx_var_consoleSetting];
			_console ctrlSetPosition _newPos;
			_console ctrlCommit 0.2;
			
			rmx_var_consoleEnabled = true;
			call rmx_fnc_consoleUpdate;
		};
	case true:
		{
			findDisplay 9100 closeDisplay 1;
			9100 cutRsc ["Default","PLAIN"];
			rmx_var_consoleEnabled = false;
		};
};
