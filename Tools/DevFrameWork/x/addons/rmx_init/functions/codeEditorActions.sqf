/*
	Function Name:			rmx_fnc_codeEditorActions
	Author:					Raimonds Virtoss | Raymix
	Description:			Actions required for Editor
	
	License:				---
*/
private ["_action","_tab"];

_action = param [0, 100];
_tab = param [1, 0];

switch (_action) do
{
	case "execute":
	{
		playSound "click";
		_code = ctrlText (rmx_var_ctrl_editorItems select 1);
		call compile _code; //add try catch
	};
	case "save":
	{
		playSound "click";
		rmx_var_ctrl_editorTabContent set [rmx_var_editorIndex, ctrlText (rmx_var_ctrl_editorItems select 1)];
		profileNamespace setVariable ["rmx_var_ctrl_editorTabContent",rmx_var_ctrl_editorTabContent];
	};
	case "clear":
	{
		playSound "click";
		(rmx_var_ctrl_editorItems select 1) ctrlSetText "";
		rmx_var_ctrl_editorTabContent set [rmx_var_editorIndex, ctrlText (rmx_var_ctrl_editorItems select 1)];
	};
	case "slider":
	{
		playSound "click";
		_pos = (sliderPosition (rmx_var_ctrl_editorItems select 12)) / 10;
		{
			_x ctrlSetFade (_pos min 0.7);
			_x ctrlCommit 1;
		} forEach rmx_var_ctrl_editorItems + rmx_var_ctrl_editorMain;
	};
	case "load":
	{
		setMousePosition [0.5,0.5];
		[] spawn {
			waitUntil {!isNull (rmx_var_ctrl_editorItems select 1)};
			(rmx_var_ctrl_editorItems select 1) ctrlSetText (rmx_var_ctrl_editorTabContent select rmx_var_editorIndex);
			
			//read positions
			disableSerialization;
			if (!isnil "rmx_var_editorPosition") then 
			{
				{
					_x ctrlSetPosition (rmx_var_editorPosition select _forEachIndex);
					_x ctrlCommit 0;
				} forEach rmx_var_ctrl_editorItems + rmx_var_ctrl_editorMain;
			};
			
			(rmx_var_ctrl_editorItems select 12) sliderSetPosition rmx_var_ctrl_editorContentFade;
			"slider" call rmx_fnc_codeEditorActions;
			
			for "_i" from 2 to 10 do
			{
				(rmx_var_ctrl_editorItems select _i) ctrlSetTextColor [0.2,0.2,0.2,0.4];
			};
			(rmx_var_ctrl_editorItems select rmx_var_editorIndex + 2) ctrlSetTextColor (call rmx_fnc_getColorScheme);
			(rmx_var_ctrl_editorMain select 1) ctrlSetBackgroundColor (call rmx_fnc_getColorScheme);
			
			for "_c" from 13 to 15 do {
				(rmx_var_ctrl_editorItems select _c) ctrlSetTextColor (call rmx_fnc_getColorScheme);
			};
		};
	};
	case "unload":
	{
		rmx_var_editorControl = false;
		rmx_var_ctrl_editorTabContent set [rmx_var_editorIndex, ctrlText (rmx_var_ctrl_editorItems select 1)];
		
		//store positions
		rmx_var_editorPosition = [];
		
		{
			rmx_var_editorPosition pushBack (ctrlPosition _x);
		} forEach rmx_var_ctrl_editorItems + rmx_var_ctrl_editorMain;
		rmx_var_ctrl_editorContentFade = sliderPosition (rmx_var_ctrl_editorItems select 12);
		profileNamespace setVariable ["rmx_var_ctrl_editorContentFade", rmx_var_ctrl_editorContentFade];
	};
	case "tabs":
	{
		playSound "click";
		rmx_var_editorIndex = _tab;
		profilenamespace setVariable ["rmx_var_editorIndex", rmx_var_editorIndex];
		
		for "_i" from 2 to 10 do
		{
			(rmx_var_ctrl_editorItems select _i) ctrlSetTextColor [0.2,0.2,0.2,0.4];
		};
		(rmx_var_ctrl_editorItems select _tab + 2) ctrlSetTextColor (call rmx_fnc_getColorScheme);
		
		(rmx_var_ctrl_editorItems select 1) ctrlSetText (rmx_var_ctrl_editorTabContent select _tab);
	};
};