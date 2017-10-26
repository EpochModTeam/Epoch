/*
	Function Name:			rmx_fnc_watcher
	Author:					Raimonds Virtoss | Raymix
	Description:			Display custom in-game code Editor with tabs saved to HDD
							Usage: Press CTRL + ENTER to enable
	
	License:				---
*/
#include <\x\Addons\rmx_init\defines.inc>
private ["_display"];

_display = displayNull;

if (str (findDisplay 7500) isEqualTo "Display #7500") then {
	"unload" call rmx_fnc_watcherActions;
};

findDisplay 7500 closeDisplay 1;
7500 cutRsc ["Default","PLAIN"];



if (!rmx_var_watcherControl) then {
	
	findDisplay 46 createDisplay "dUI_watcher";
	_display = findDisplay 7500;
	_display displayAddEventHandler ["keyDown", "_this call rmx_fnc_keyDown;"];
	rmx_var_watcherControl = true;
} else {

	if (rmx_var_watcherPinned) then {
		7500 cutRsc ["dUI_watcher2","PLAIN"];
		_display = uiNamespace getVariable "rmx_var_watcher2";
	};
	rmx_var_watcherControl = false;
};

//Exit if not pinned
if (isNull _display) exitWith {false};

setMousePosition [0.5,0.5];

rmx_var_ctrl_watcherItems = [];

for "_i" from 7501 to 7508 do {
	rmx_var_ctrl_watcherItems set [count rmx_var_ctrl_watcherItems,_display displayCtrl _i];
};

//Load positions, create if doesn't exist anywhere
rmx_var_watcherPositions = profileNamespace getVariable ["rmx_var_watcherPositions",nil];
if (isNil "rmx_var_watcherPositions") then {
	rmx_var_watcherPositions = [];
	{
		rmx_var_watcherPositions pushBack (ctrlPosition _x);
	} forEach rmx_var_ctrl_watcherItems;
};

{
	 _x ctrlSetPosition (rmx_var_watcherPositions select _forEachIndex);
	 _x ctrlCommit 0;
} forEach rmx_var_ctrl_watcherItems;

if (!rmx_var_watcherPinned) then {
	(rmx_var_ctrl_watcherItems select 2) ctrlSetText "x\addons\rmx_init\data\retardedPinUp.paa";
} else {
	(rmx_var_ctrl_watcherItems select 2) ctrlSetText "x\addons\rmx_init\data\retardedPinDown.paa";
};

(rmx_var_ctrl_watcherItems select 1) ctrlSetBackgroundColor (call rmx_fnc_getColorScheme);

if (!rmx_var_watcherControl && rmx_var_watcherPinned) then {
	(rmx_var_ctrl_watcherItems select 1) ctrlSetText "";
	(rmx_var_ctrl_watcherItems select 1) ctrlSetBackgroundColor [0,0,0,0];
	{
		(rmx_var_ctrl_watcherItems select _x) ctrlShow false;
	}count [0,1,2,3,4,5,7];
};

{
	_idx = (rmx_var_ctrl_watcherItems select 4) lbadd _x;
} count 
[
	"{code} String",
	"{code} Boolean",
	"{code} Progress Bar",
	"[string] missionNamespace",
	"[string] uiNamespace",
	"[string] profileNamespace"
];

{
	_idx = (rmx_var_ctrl_watcherItems select 7) lbadd _x;
} count 
[
	"Fade 0%",
	"Fade 10%",
	"Fade 20%",
	"Fade 30%",
	"Fade 40%",
	"Fade 50%",
	"Fade 60%",
	"Fade 70%",
	"Fade 80%",
	"Fade 90%"
];

(rmx_var_ctrl_watcherItems select 7) ctrlSetEventHandler ["LBSelChanged","'fade' call rmx_fnc_watcherActions;"];
(rmx_var_ctrl_watcherItems select 7) lbsetCurSel (profileNamespace getVariable ["rmx_var_ctrl_watcherContentFade",0]);
(rmx_var_ctrl_watcherItems select 4) lbSetCurSel 0;
(rmx_var_ctrl_watcherItems select 3) ctrlSetText "";

[] spawn {
	disableSerialization;
	if (count rmx_var_watcherGrpControls_data > 0) then {
		_tmp = rmx_var_watcherGrpControls_data;
		"unload" call rmx_fnc_watcherActions;
		rmx_var_watcherGrpControls_data = [];
		{
			(rmx_var_ctrl_watcherItems select 3) ctrlSetText (_x select 0);
			(rmx_var_ctrl_watcherItems select 4) lbSetCurSel (_x select 1);
			[true, (_x select 1)] call rmx_fnc_watcherAddRemove;
			uiSleep 0.01;
		}forEach _tmp;
		
		(rmx_var_ctrl_watcherItems select 4) lbSetCurSel 0;
		(rmx_var_ctrl_watcherItems select 3) ctrlSetText "";
	};
};



























true
