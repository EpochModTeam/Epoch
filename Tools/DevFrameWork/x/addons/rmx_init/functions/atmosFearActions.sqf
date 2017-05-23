/*
	Function Name:			rmx_fnc_atmosFearActions
	Author:					Raimonds Virtoss | Raymix
	Description:			Button actions
	
	License:				---
*/
#include <\x\Addons\rmx_init\defines.inc>
private ["_args"];

_args = _this select 0;
if (typeName _args != "STRING") then {_args = str _args};
//hintSilent str _this;

switch (_args) do {
	case "load":
	{
		{
			_x sliderSetRange [0,1];
		} forEach rmx_var_afSliders;
		
		(rmx_var_afSliders select 7) sliderSetRange [0,1000]; //fog altitude in meters
		(rmx_var_afSliders select 11) sliderSetRange [0,360]; //wind direction in degrees
		
		private "_date";
		_date = date; //[2035,5,28,13,41]
		(rmx_var_afInput select 9) ctrlSetText str (_date select 2); //day
		(rmx_var_afInput select 10) ctrlSetText str (_date select 1); //month
		(rmx_var_afInput select 11) ctrlSetText str (_date select 0); //year
		(rmx_var_afInput select 12) ctrlSetText str (_date select 3); //hours
		(rmx_var_afInput select 13) ctrlSetText str (_date select 4); //minutes
		
		//set saved slider positions and inputs
		// [0,0,0,0,[0,0],[0,[0,0,0]],[0,0],[0,0],[0,0],[0,0],[0,0,false]]
		(rmx_var_afSliders select 0) sliderSetPosition (rmx_var_afProfile select 0);
		(rmx_var_afSliders select 1) sliderSetPosition (rmx_var_afProfile select 1);
		(rmx_var_afSliders select 2) sliderSetPosition (rmx_var_afProfile select 2);
		(rmx_var_afSliders select 3) sliderSetPosition (rmx_var_afProfile select 3);
		
		(rmx_var_afInput select 0) ctrlSetText str (rmx_var_afProfile select 4 select 0); //rain
		(rmx_var_afSliders select 4) sliderSetPosition (rmx_var_afProfile select 4 select 1);
		
		(rmx_var_afInput select 1) ctrlSetText str (rmx_var_afProfile select 5 select 0); //fog
		(rmx_var_afSliders select 5) sliderSetPosition (rmx_var_afProfile select 5 select 1 select 0);
		(rmx_var_afSliders select 6) sliderSetPosition (rmx_var_afProfile select 5 select 1 select 1);
		(rmx_var_afSliders select 7) sliderSetPosition (rmx_var_afProfile select 5 select 1 select 2);
		
		(rmx_var_afInput select 2) ctrlSetText str (rmx_var_afProfile select 6 select 0); //Wind str
		(rmx_var_afSliders select 8) sliderSetPosition (rmx_var_afProfile select 6 select 1);
		
		(rmx_var_afInput select 3) ctrlSetText str (rmx_var_afProfile select 7 select 0); //Wind force
		(rmx_var_afSliders select 9) sliderSetPosition (rmx_var_afProfile select 7 select 1);
		
		(rmx_var_afInput select 4) ctrlSetText str (rmx_var_afProfile select 8 select 0); //Waves
		(rmx_var_afSliders select 10) sliderSetPosition (rmx_var_afProfile select 8 select 1);
		
		(rmx_var_afInput select 5) ctrlSetText str (rmx_var_afProfile select 9 select 0); //Direction
		(rmx_var_afSliders select 11) sliderSetPosition (rmx_var_afProfile select 9 select 1);
		
		(rmx_var_afInput select 6) ctrlSetText str (rmx_var_afProfile select 10 select 0); //x
		(rmx_var_afInput select 7) ctrlSetText str (rmx_var_afProfile select 10 select 1); //y
		(rmx_var_afMisc select 0) cbSetChecked (rmx_var_afProfile select 10 select 2);
		
		lbClear (rmx_var_afMisc select 1);
		{
			(rmx_var_afMisc select 1) lbAdd (_x select 0);
		} forEach rmx_var_afLoadSave;
		(rmx_var_afMisc select 1) lbSetCurSel rmx_var_afSelected;
	};
	case "unload":
	{
		["save"] call rmx_fnc_atmosFearActions;
		rmx_var_atmosFearEnabled = false;
		rmx_var_afProgress = [];
		rmx_var_afInput = [];
		rmx_var_afSliders = [];
		rmx_var_afText = [];
		rmx_var_afMisc = [];
	};
	case "save":
	{
		// [0,0,0,0,[0,0],[0,[0,0,0]],[0,0],[0,0],[0,0],[0,0],[0,0,false]]
		rmx_var_afProfile =
		[
			sliderPosition (rmx_var_afSliders select 0),
			sliderPosition (rmx_var_afSliders select 1),
			sliderPosition (rmx_var_afSliders select 2),
			sliderPosition (rmx_var_afSliders select 3),
			[
				call compile (ctrlText (rmx_var_afInput select 0)),
				sliderPosition (rmx_var_afSliders select 4)
			],
			[
				call compile (ctrlText (rmx_var_afInput select 1)),
				[
					sliderPosition (rmx_var_afSliders select 5),
					sliderPosition (rmx_var_afSliders select 6),
					sliderPosition (rmx_var_afSliders select 7)
				]
			],
			[
				call compile (ctrlText (rmx_var_afInput select 2)),
				sliderPosition (rmx_var_afSliders select 8)
			],
			[
				call compile (ctrlText (rmx_var_afInput select 3)),
				sliderPosition (rmx_var_afSliders select 9)
			],
			[
				call compile (ctrlText (rmx_var_afInput select 4)),
				sliderPosition (rmx_var_afSliders select 10)
			],
			[
				call compile (ctrlText (rmx_var_afInput select 5)),
				sliderPosition (rmx_var_afSliders select 11)
			],
			[
				call compile (ctrlText (rmx_var_afInput select 6)),
				call compile (ctrlText (rmx_var_afInput select 7)),
				cbChecked (rmx_var_afMisc select 0)
			]
		];
		
		profileNamespace setVariable ["rmx_var_afProfile",rmx_var_afProfile];
	};
	case "Control #8190": //RPT
	{
		diag_log format ["<<<<<<<<<< AtmosFEAR Template output >>>>>>>>>>
		
		class RENAME_ME
		{
			setLightnings = %1;
			setOvercast = %2;
			setRainbow = %3;
			setGusts = %4;
			setRain[] = %5;
			setFog[] = %6;
			setWindStr[] = %7;
			setWindForce[] = %8;
			setWaves[] = %9;
			setWindDir[] = %10;
			setWind[] = %11;
		};
		
		<<<<<<<<<<							>>>>>>>>>>",
		rmx_var_afProfile select 0,rmx_var_afProfile select 1,
		rmx_var_afProfile select 2,rmx_var_afProfile select 3,
		rmx_var_afProfile select 4,rmx_var_afProfile select 5,
		rmx_var_afProfile select 6,rmx_var_afProfile select 7,
		rmx_var_afProfile select 8,rmx_var_afProfile select 9,
		rmx_var_afProfile select 10];
	};
	case "Control #8191": //Apply
	{
		private "_time";
		
		_time = 24*60*60;
		skipTime -24;
		_time setLightnings sliderPosition (rmx_var_afSliders select 0);
		_time setOvercast sliderPosition (rmx_var_afSliders select 1);
		_time setRainbow sliderPosition (rmx_var_afSliders select 2);
		_time setGusts sliderPosition (rmx_var_afSliders select 3);
		
		_time setRain 0;
		_time setFog [0, 0, 0];
		
		skipTime 24;
		simulWeatherSync;
		call compile (ctrlText(rmx_var_afInput select 0)) setRain sliderPosition (rmx_var_afSliders select 4);
		call compile (ctrlText(rmx_var_afInput select 1)) setFog 
			[
				sliderPosition (rmx_var_afSliders select 5),
				sliderPosition (rmx_var_afSliders select 6),
				sliderPosition (rmx_var_afSliders select 7)
			];
		call compile (ctrlText(rmx_var_afInput select 2)) setWindStr sliderPosition (rmx_var_afSliders select 8);
		call compile (ctrlText(rmx_var_afInput select 3)) setWindForce sliderPosition (rmx_var_afSliders select 9);
		call compile (ctrlText(rmx_var_afInput select 4)) setWaves sliderPosition (rmx_var_afSliders select 10);
		call compile (ctrlText(rmx_var_afInput select 5)) setWindDir sliderPosition (rmx_var_afSliders select 11);
		
		setWind 
		[
			call compile (ctrlText(rmx_var_afInput select 6)),
			call compile (ctrlText(rmx_var_afInput select 7)),
			cbChecked (rmx_var_afMisc select 0)
		];
		
	};
	case "Control #8180": //combo
	{
		rmx_var_afSelected = _this select 1;
	};
	case "Control #8192": //Import
	{
		private ["_in","_inVal"];
		_in = profileNamespace getVariable ["rmx_var_afLoadSave",[]];
		if (_in isEqualTo []) exitWith {hint "Nothing to load"};
		_inVal = _in select rmx_var_afSelected;
		rmx_var_afProfile = _inVal select 1;
		["load"] call rmx_fnc_atmosFearActions;
		//(format ["Importing: %1",rmx_var_afProfile]) info;
	};
	case "Control #8193": //Export
	{
		if (ctrlText (rmx_var_afInput select 8) isEqualTo "") exitWith {hint "Name cannot be blank"};
		rmx_var_afLoadSave = profileNamespace getVariable ["rmx_var_afLoadSave",[]];
		rmx_var_afLoadSave pushBack [
			ctrlText (rmx_var_afInput select 8),
			rmx_var_afProfile
		];
		profileNamespace setVariable ["rmx_var_afLoadSave",rmx_var_afLoadSave];
		
		lbClear (rmx_var_afMisc select 1);
		
		{
			(rmx_var_afMisc select 1) lbAdd (_x select 0);
		} forEach rmx_var_afLoadSave;
		//(format ["Exporting: %1",rmx_var_afLoadSave select ((count rmx_var_afLoadSave)-1)]) info;
	};
	case "Control #8197": //delete
	{
		if (profileNamespace getVariable ["rmx_var_afLoadSave",[]] isEqualTo [] ) exitWith {hint "Nothing saved"};
		private ["_in","_rem"];
		_in = profileNamespace getVariable "rmx_var_afLoadSave";
		_rem = _in deleteAt rmx_var_afSelected;
		profileNamespace setVariable ["rmx_var_afLoadSave",_in];
		(format ["Deleted setting: %1 = %2",_rem select 0,_rem select 1]) warning;
		lbClear (rmx_var_afMisc select 1);
		
		{
			(rmx_var_afMisc select 1) lbAdd (_x select 0);
		} forEach rmx_var_afLoadSave;
	};
	case "Control #8194": //set time
	{
		private "_arr";
		_arr = [
			call compile (ctrlText(rmx_var_afInput select 11)),
			call compile (ctrlText(rmx_var_afInput select 10)),
			call compile (ctrlText(rmx_var_afInput select 9)),
			call compile (ctrlText(rmx_var_afInput select 12)),
			call compile (ctrlText(rmx_var_afInput select 13))
		];
		setDate _arr;
	};
	case "Control #8195": //skipTime +
	{
		skipTime (call compile (ctrlText(rmx_var_afInput select 14)));
		
		private "_date";
		_date = date; //[2035,5,28,13,41]
		(rmx_var_afInput select 9) ctrlSetText str (_date select 2); //day
		(rmx_var_afInput select 10) ctrlSetText str (_date select 1); //month
		(rmx_var_afInput select 11) ctrlSetText str (_date select 0); //year
		(rmx_var_afInput select 12) ctrlSetText str (_date select 3); //hours
		(rmx_var_afInput select 13) ctrlSetText str (_date select 4); //minutes
	};
	case "Control #8196": //skipTime -
	{
		skipTime -(call compile (ctrlText(rmx_var_afInput select 14)));
		
		private "_date";
		_date = date; //[2035,5,28,13,41]
		(rmx_var_afInput select 9) ctrlSetText str (_date select 2); //day
		(rmx_var_afInput select 10) ctrlSetText str (_date select 1); //month
		(rmx_var_afInput select 11) ctrlSetText str (_date select 0); //year
		(rmx_var_afInput select 12) ctrlSetText str (_date select 3); //hours
		(rmx_var_afInput select 13) ctrlSetText str (_date select 4); //minutes
	};
};

true
