/*
	Function Name:			rmx_fnc_ppViewerGetSet
	Author:					Raimonds Virtoss | Raymix
	Description:			PPV profiles and positions
	
	License:				---
*/
#include <\x\Addons\rmx_init\defines.inc>
disableSerialization;


switch (_this) do {
	default {
		(rmx_var_ppCatMain select 0) lbSetCurSel rmx_var_ppSelected;
		(rmx_var_ppCatMain select 1) lbSetCurSel rmx_var_ppiSelected;
		if ((cbChecked (rmx_var_ppCatCC select 23)) && (rmx_var_ppSelected isEqualTo 0)) then {
			{
				_x ctrlShow true;
			} count rmx_var_ppCatCCV;
		};
		
		(rmx_var_ppCatCA select 6) cbSetChecked (rmx_var_ppCaPos select 2);
		(rmx_var_ppCatFG select 12) cbSetChecked (rmx_var_ppFgPos select 5);
		
		{
			_x sliderSetPosition (rmx_var_ppCcPos select _forEachIndex);
		} forEach (rmx_var_ppCatCC select [8,15]);
		{
			_x sliderSetPosition (rmx_var_ppCcvPos select _forEachIndex);
		} forEach (rmx_var_ppCatCCV select [8,7]);
		{
			_x sliderSetPosition (rmx_var_ppCaPos select _forEachIndex);
		} forEach (rmx_var_ppCatCA select [4,2]);
		{
			_x sliderSetPosition (rmx_var_ppFgPos select _forEachIndex);
		} forEach (rmx_var_ppCatFG select [7,5]);
		{
			_x sliderSetPosition (rmx_var_ppRbPos select _forEachIndex);
		} forEach (rmx_var_ppCatRB select [5,4]);
		{
			_x sliderSetPosition (rmx_var_ppWdPos select _forEachIndex);
		} forEach (rmx_var_ppCatWD select [7,15]);
		{
			_x sliderSetPosition (rmx_var_ppDbPos select _forEachIndex);
		} forEach [(rmx_var_ppCatDB select 2)];
		{
			_x sliderSetPosition (rmx_var_ppCiPos select _forEachIndex);
		} forEach (rmx_var_ppCatCI select [4,3]);

	};
	case "range":
	{
		for "_i" from 8 to 22 do {
			(rmx_var_ppCatCC select _i) sliderSetRange [0, 1];
		};
		
		for "_i" from 8 to 14 do {
			(rmx_var_ppCatCCV select _i) sliderSetRange [0, 1];
		};
		
		(rmx_var_ppCatCA select 4) sliderSetRange [0, 1]; //x
		(rmx_var_ppCatCA select 5) sliderSetRange [0, 1]; //y

		(rmx_var_ppCatFG select 7) sliderSetRange [0, 20]; //sharpness
		(rmx_var_ppCatFG select 8) sliderSetRange [0, 1]; //intensity
		(rmx_var_ppCatFG select 9) sliderSetRange [1, 8]; //grain size
		(rmx_var_ppCatFG select 10) sliderSetRange [0, 1]; //x0
		(rmx_var_ppCatFG select 11) sliderSetRange [0, 1]; //x1

		(rmx_var_ppCatRB select 5) sliderSetRange [0, 1]; //Rx
		(rmx_var_ppCatRB select 6) sliderSetRange [0, 1]; //Ry
		(rmx_var_ppCatRB select 7) sliderSetRange [0, 0.5]; //Cx
		(rmx_var_ppCatRB select 8) sliderSetRange [0, 0.5]; //Cy

		for "_i" from 7 to 21 do {
			(rmx_var_ppCatWD select _i) sliderSetRange [-1, 1];
		};
	
		(rmx_var_ppCatDB select 2) sliderSetRange [0, 1]; //db
		
		for "_i" from 4 to 6 do {
			(rmx_var_ppCatCI select _i) sliderSetRange [0, 1];
		};

	};
	case "import":
	{
		private ["_in","_var","_inVal"];
		_in = profileNamespace getVariable ["rmx_var_ppLoadSave",[]];
		if (_in isEqualTo []) exitWith {hint "Nothing to load"};
		_inVal = _in select rmx_var_ppiSelected;
		_var = ["rmx_var_ppCcPos","rmx_var_ppCaPos","rmx_var_ppFgPos","rmx_var_ppRbPos","rmx_var_ppWdPos","rmx_var_ppDbPos","rmx_var_ppCiPos"] select (_inVal select 0);
		missionNamespace setVariable [_var,(_inVal select 2)];
		rmx_var_ppSelected = _inVal select 0;
		"" call rmx_fnc_ppViewerGetSet; //loads default positions and selections
		call rmx_fnc_ppViewerEffects;
	};
	case "export":
	{
		if (ctrlText (rmx_var_ppCatMain select 2) isEqualTo "") exitWith {hint "Effect name cannot be blank"};
		rmx_var_ppLoadSave = profileNamespace getVariable ["rmx_var_ppLoadSave",[]];
		rmx_var_ppLoadSave pushBack [
			rmx_var_ppSelected,
			ctrlText (rmx_var_ppCatMain select 2),
			([rmx_var_ppCcPos,rmx_var_ppCaPos,rmx_var_ppFgPos,rmx_var_ppRbPos,rmx_var_ppWdPos,rmx_var_ppDbPos,rmx_var_ppCiPos] select rmx_var_ppSelected)
		];
		profileNamespace setVariable ["rmx_var_ppLoadSave",rmx_var_ppLoadSave];
		
		lbClear (rmx_var_ppCatMain select 1);
		
		{
			(rmx_var_ppCatMain select 1) lbAdd (_x select 1);
		} forEach rmx_var_ppLoadSave;
	};
};

true
