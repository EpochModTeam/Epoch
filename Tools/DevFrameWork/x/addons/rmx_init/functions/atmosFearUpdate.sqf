/*
	Function Name:			rmx_fnc_atmosFearUpdate
	Author:					Raimonds Virtoss | Raymix
	Description:			Updates progress bars
	
	License:				---
*/
#include <\x\Addons\rmx_init\defines.inc>
private ["_doMath","_fog"];

_doMath = {};

while {rmx_var_atmosFearEnabled} do {
	uiSleep 0.1;
	if !(rmx_var_atmosFearEnabled) exitWith{}; //required to avoid RPT error.
	(rmx_var_afProgress select 0) progressSetPosition lightnings;
	(rmx_var_afProgress select 1) progressSetPosition overcast;
	(rmx_var_afProgress select 2) progressSetPosition rainbow;
	(rmx_var_afProgress select 3) progressSetPosition gusts;
	(rmx_var_afProgress select 4) progressSetPosition rain;
	
	_fog = fogParams;
	(rmx_var_afProgress select 5) progressSetPosition (_fog select 0); //density
	(rmx_var_afProgress select 6) progressSetPosition (_fog select 1); //decay value
	(rmx_var_afProgress select 7) progressSetPosition ((_fog select 2) / 1000); //altitude
	
	(rmx_var_afProgress select 8) progressSetPosition windStr; //str
	
	(rmx_var_afProgress select 9) progressSetPosition waves; //waves
	
	(rmx_var_afText select 0) ctrlSetText str wind;
	(rmx_var_afText select 1) ctrlSetText str windDir;
};

true
