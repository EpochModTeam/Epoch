/*
	Function Name:			rmx_fnc_ppViewerUpdate
	Author:					Raimonds Virtoss | Raymix
	Description:			PPV updater, responsible for main category and slider positions
	
	License:				---
*/
#include <\x\Addons\rmx_init\defines.inc>
private ["_args","_selection","_ctrl"];
disableSerialization;

_args = _this select 0;
_selection = _this select 1;
_ctrl = [rmx_var_ppCatCC, rmx_var_ppCatCA, rmx_var_ppCatFG, rmx_var_ppCatRB, rmx_var_ppCatWD, rmx_var_ppCatDB, rmx_var_ppCatCI, rmx_var_ppCatCCV];
if (typeName _args != "STRING") then {_args = str _args};
//hintSilent format ["U: %1",_this];

switch (_args) do {
	case "load":
	{
		{
			{
				_x ctrlShow false;
			} count _x;
		} forEach _ctrl;
		
		lbClear (rmx_var_ppCatMain select 0);
		
		{
			(rmx_var_ppCatMain select 0) lbAdd _x;
		} forEach ["Color Correction","Chromatic Aberration","Film Grain","Radial Blur","Wet Distortion","Dynamic Blur","Color inversion"]; //does not like count
		
		lbClear (rmx_var_ppCatMain select 1);
		
		{
			(rmx_var_ppCatMain select 1) lbAdd (_x select 1);
		} forEach rmx_var_ppLoadSave;
	};
	case "unload":
	{
		rmx_var_ppViewerEnabled = false;
		rmx_var_ppCatMain = [];
		rmx_var_ppCatCC = [];
		rmx_var_ppCatCCV = [];
		rmx_var_ppCatCA = [];
		rmx_var_ppCatFG = [];
		rmx_var_ppCatRB = [];
		rmx_var_ppCatWD = [];
		rmx_var_ppCatDB = [];
		rmx_var_ppCatCI = [];
	};
	case "import":
	{
		{
			{
				if (ctrlShown _x) then {_x ctrlShow false;};
			} count _x;
		} forEach _ctrl;
		
		{
			_x ctrlShow true;
		} count (_ctrl select (rmx_var_ppLoadSave select rmx_var_ppiSelected select 0));
	};
	case "Control #6110": //main combo
	{
		{
			{
				if (ctrlShown _x) then {_x ctrlShow false;};
			} count _x;
		} forEach _ctrl;
		
		{
			_x ctrlShow true;
		} count (_ctrl select _selection);
		rmx_var_ppSelected = _selection;
	};
	case "Control #6111": //loadsave combo
	{
		rmx_var_ppiSelected = _selection;
	};
	case "Control #6132": //reset
	{
		private "_currEffect";
		_currEffect = rmx_var_ppHandles select rmx_var_ppSelected;
		_currEffect ppEffectEnable false;
	};
	case "Control #6133": //random
	{
		switch (rmx_var_ppSelected) do {
			case 0: //cc
			{
				rmx_var_ppCcPos = [random 1,random 1,random 1,random 1,random 1,random 1,random 1,random 1,random 1,random 1,random 1,random 1,random 1,random 1,random 1];
				if (cbChecked (rmx_var_ppCatCC select 23)) then {
					rmx_var_ppCcvPos = [random 1,random 1,random 1,random 1,random 1,random 1,random 1];
					rmx_var_ppCcPos append rmx_var_ppCcvPos;
				};
			};
			case 1: //ca
			{
				private "_bool";
				_bool = if (random 1 > 0.5) then {true} else {false};
				rmx_var_ppCaPos = [random 1,random 1,_bool];
				(rmx_var_ppCatCA select 6) cbSetChecked _bool;
			};
			case 2: //fg
			{
				private "_bool";
				_bool = if (random 1 > 0.5) then {true} else {false};
				rmx_var_ppFgPos = [random 20,random 1,(random 7) + 1,random 1,random 1,_bool];
				(rmx_var_ppCatFG select 12) cbSetChecked _bool;
			};
			case 3: //rb
			{
				rmx_var_ppRbPos = [random 1,random 1,random 0.5,random 0.5];
			};
			case 4: //wd
			{
				rmx_var_ppWdPos = [(random 2 ) - 1,(random 2 ) - 1,(random 2 ) - 1,(random 2 ) - 1,(random 2 ) - 1,(random 2 ) - 1,(random 2 ) - 1,(random 2 ) - 1,(random 2 ) - 1,(random 2 ) - 1,(random 2 ) - 1,(random 2 ) - 1,(random 2 ) - 1,(random 2 ) - 1,(random 2 ) - 1];
			};
			case 5: //db
			{
				rmx_var_ppDbPos = [random 1];
			};
			case 6: //ci
			{
				rmx_var_ppCiPos = [random 1,random 1,random 1];
			};

		};
		"" call rmx_fnc_ppViewerGetSet; 
		call rmx_fnc_ppViewerEffects;
	};
	case "Control #6134": //del
	{
		if (profileNamespace getVariable ["rmx_var_ppLoadSave",[]] isEqualTo [] ) exitWith {hint "Nothing saved"};
		
		private ["_in","_rem"];
		_in = profileNamespace getVariable "rmx_var_ppLoadSave";
		_rem = _in deleteAt rmx_var_ppiSelected;
		profileNamespace setVariable ["rmx_var_ppLoadSave",_in];
		(format ["Deleted effect: %1 = %2",_rem select 1,_rem select 2]) warning;
		lbClear (rmx_var_ppCatMain select 1);
		
		{
			(rmx_var_ppCatMain select 1) lbAdd (_x select 1);
		} forEach rmx_var_ppLoadSave;
		
	};
	case "Control #6135": // RPT
	{
		{
			diag_log format ["<< %1 >>",(_x select 0)];
			diag_log (_x select 1);
		} forEach
		[
			["colorCorrections", rmx_var_ppCcPos],
			["chromAberration", rmx_var_ppCaPos],
			["filmGrain", rmx_var_ppFgPos],
			["radialBlur", rmx_var_ppRbPos],
			["wetdistortion", rmx_var_ppWdPos],
			["dynamicBlur", rmx_var_ppDbPos],
			["colorInversion", rmx_var_ppCiPos]
		];
	};
	case "Control #6136": //reset all
	{
		{
			_x ppEffectEnable false;
		} forEach rmx_var_ppHandles;
		rmx_var_ppCcPos = [1,1,0,0,0,0,0,0,0,0,1,0,0,0,0];
		rmx_var_ppCcvPos = [0,0,0,0,0,0,0];
		rmx_var_ppCaPos = [0,0,false];
		rmx_var_ppFgPos = [0,0,1,0,0,false];
		rmx_var_ppRbPos = [0,0,0,0];
		rmx_var_ppWdPos = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0];
		rmx_var_ppDbPos = [0];
		rmx_var_ppCiPos = [0,0,0];
		"" call rmx_fnc_ppViewerGetSet;
	};
	
	case "Control #6251": //vignette bool
	{
		private "_bool";
		_bool = if (_selection isEqualTo 0) then {false} else {true};
		{
			_x ctrlShow _bool;
		} count rmx_var_ppCatCCV;
		
	};
	default
	{

	};
};

true
