/*
	Function Name:			rmx_fnc_watcherActions
	Author:					Raimonds Virtoss | Raymix
	Description:			Display custom in-game code Editor with tabs saved to HDD
							Usage: NONE, required for main FNC
	
	License:				---
*/
#include <\x\Addons\rmx_init\defines.inc>

_switch = param [0, 100];

switch (_switch) do {
	case "load":
	{
		[] spawn rmx_fnc_watcherRunner;
	};
	case "unload":
	{
		rmx_var_watcherPositions = []; //reset positions to save new ones
		{
			rmx_var_watcherPositions pushBack (ctrlPosition _x);
		} forEach rmx_var_ctrl_watcherItems;
		{
			{
				_x call Epoch_getIDC;
				ctrlDelete _x;
			} forEach _x;
		} forEach rmx_var_watcherGrpControls;
		
		rmx_var_watcherGrpControls = [];
		profileNamespace setVariable ["rmx_var_watcherPositions",rmx_var_watcherPositions];
	};
	case "fade":
	{
		_fade = lbCurSel (rmx_var_ctrl_watcherItems select 7);
		
		{
			(rmx_var_ctrl_watcherItems select _x) ctrlSetFade (_fade / 10);
			(rmx_var_ctrl_watcherItems select _x) ctrlCommit 0.5;
		} count [0,1,4,5,6,7];
		
		profileNamespace setVariable ["rmx_var_ctrl_watcherContentFade",_fade];
	};
	case "pin":
	{
		if (rmx_var_watcherPinned) then {
			(rmx_var_ctrl_watcherItems select 2) ctrlSetText "x\addons\rmx_init\data\retardedPinUp.paa";
			rmx_var_watcherPinned = false;
		} else {
			(rmx_var_ctrl_watcherItems select 2) ctrlSetText "x\addons\rmx_init\data\retardedPinDown.paa";
			rmx_var_watcherPinned = true;
		};
	};
	case "execute":
	{
		private ["_sel"];
		_sel = lbCurSel (rmx_var_ctrl_watcherItems select 4);
		_editbox = ctrlText (rmx_var_ctrl_watcherItems select 3);
		
		//if (_editbox isEqualTo "") exitWith {"Edit field cannot be blank!" warning};
		[true, _sel] call rmx_fnc_watcherAddRemove;
	};
};

true
