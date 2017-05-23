/*
	Function Name:			rmx_fnc_buffer
	Author:					Raimonds Virtoss | Raymix
	Description:			Buffers the debug messages each cycle then processes them when console is open
	
	License:				---
*/
#include <\x\Addons\rmx_init\defines.inc>
[] spawn {
	private ["_updateConsole","_appendToBuffer","_fnc_composeST"];

	_fnc_updateConsole = {
		private ["_this","_tmp"];
		rmx_var_console_list resize 39;
		_tmp = [_this];
		_tmp append rmx_var_console_list;
		rmx_var_console_list = _tmp;
		call rmx_fnc_consoleUpdate;
	};

	_fnc_appendToBuffer = {
		private ["_this","_cntBuffer","_cntInput"];
		_cntBuffer = count rmx_var_logBuffer;
		_cntInput = count _this;
		
		if (_cntBuffer >= rmx_var_logBufferSize) then {
			rmx_var_logBuffer deleteRange [0,_cntInput];
		};
		rmx_var_logBuffer append _this;
	};

	_fnc_composeST = {
		private ["_type","_msg","_fnc","_img","_fncName","_txt","_final"];
		_type = _this select 0;
		_fnc = _this select 1;
		_msg = _this select 2;
		
		switch (_type) do {
			default //anything else, TODO: ability to colorize
			{
				_fncName = parseText format ["<t %2%3%4%5> [%1] </t>",_fnc,ST_SIZE18,ST_GREEN,ST_TAHOMAB,ST_SHADOW1];
				_txt = parseText format ["<t %2%3%4%5>%1</t>",_msg,ST_SIZE18,ST_WHITE,ST_PURISTAMEDIUM,ST_SHADOW2];
				_final = composeText [_fncName, _txt];
			};
			case 0: //info
			{
				_fncName = parseText format ["<t %2%3%4%5> [%1] </t>",_fnc,ST_SIZE18,ST_SKYBLUE,ST_TAHOMAB,ST_SHADOW1];
				_txt = parseText format ["<t %2%3%4%5>%1</t>",_msg,ST_SIZE18,ST_WHITE,ST_PURISTAMEDIUM,ST_SHADOW2];
				_final = composeText [_fncName, _txt];
			};
			case 1: //warning
			{
				_img = parseText format ["<t %2%3%4>%1</t>",ST_WARNING,ST_SIZE18,ST_WHITE,ST_SHADOW1];
				_fncName = parseText format ["<t %2%3%4%5> [%1] </t>",_fnc,ST_SIZE18,ST_ORANGE,ST_TAHOMAB,ST_SHADOW1];
				_txt = parseText format ["<t %2%3%4%5>%1</t>",_msg,ST_SIZE18,ST_WHITE,ST_PURISTAMEDIUM,ST_SHADOW2];
				_final = composeText [_img,_fncName,_txt];
			};
			case 2: //critical
			{
				_img = parseText format ["<t %2%3%4>%1</t>",ST_CRITICAL,ST_SIZE18,ST_WHITE,ST_SHADOW1];
				_fncName = parseText format ["<t %2%3%4%5> [%1] </t>",_fnc,ST_SIZE18,ST_RED,ST_TAHOMAB,ST_SHADOW1];
				_txt = parseText format ["<t %2%3%4%5>%1</t>",_msg,ST_SIZE18,ST_WHITE,ST_PURISTAMEDIUM,ST_SHADOW2];
				_final = composeText [_img,_fncName,_txt];
			};
		};
		[_type, _final]
	}; 

	//TODO: add console filters
	while {true} do
	{
		private ["_cycleTimer","_snapShot","_queue","_st"];
		_cycleTimer = diag_tickTime;
		_snapShot = rmx_var_logMsg;
		_snapShotST = [];
		rmx_var_logMsg = [];
		
		{
			_st = _x call _fnc_composeST;
			_snapShotST pushBack _st;
		} forEach _snapShot;
		
		_snapShotST call _fnc_appendToBuffer;
		
		if (!rmx_var_consoleCheckbox_pause && rmx_var_consoleEnabled) then {
			{
				_queue = _forEachIndex;
				if !(rmx_var_consoleEnabled) exitWith {rmx_var_logBuffer deleteRange [0,_queue];};

				switch (_x select 0) do {
					case 0:
					{
						if (rmx_var_consoleCheckbox_info) then {(_x select 1) call _fnc_updateConsole;};
					};
					case 1:
					{
						if (rmx_var_consoleCheckbox_warnings) then {(_x select 1) call _fnc_updateConsole;};
					};
					case 2:
					{
						if (rmx_var_consoleCheckbox_critical) then {(_x select 1) call _fnc_updateConsole;};
					};
					default {(_x select 1) call _fnc_updateConsole;};
				};
			}forEach rmx_var_logBuffer;
			if (rmx_var_consoleEnabled) exitWith {rmx_var_logBuffer = [];};
		};
		
		//format ["Cycle finished in %1 seconds, new cycle in %2 seconds",(diag_tickTime - _cycleTimer),rmx_var_logSweepCycle] warning; //If cycle takes too long, try to optimize script
		UISleep rmx_var_logSweepCycle;
	};
};
true

