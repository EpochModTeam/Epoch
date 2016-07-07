/*
	Author: Raimonds Virtoss - EpochMod.com

	Description:
	Displays custom text message to player

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/scripts/Epoch_dynamicText.sqf

	Usage:
	"TEST" call Epoch_message
	
	TODO: Add colors
*/
#include "\A3\ui_f\hpp\defineCommonGrids.inc"
_msg = param [0, "No input"];
_time = param [1, 2];

_msg = str (parseText str _msg); //Parses and converts text back to small string

if !(isNil "rmx_var_msgQueue") exitWith { rmx_var_msgQueue pushBack [_msg, _time];};

rmx_var_msgQueue = [[_msg, _time]];

[] spawn {
	private ["_c1pos","_c2pos","_c3pos","_clr","_dsp"];

	disableSerialization;
	
	_dsp = findDisplay 46;
	
	_yPos = 15;
	_ySize = 2;
	_c1StartPos = [safeZoneX,((_yPos - _ySize) * GUI_GRID_H + GUI_GRID_Y),safeZoneW, _ySize * GUI_GRID_H];
	_c1pos = [safeZoneX,(_yPos * GUI_GRID_H + GUI_GRID_Y),safeZoneW, _ySize * GUI_GRID_H];
	_c2pos = [safeZoneX,((_yPos + _ySize) * GUI_GRID_H + GUI_GRID_Y),safeZoneW, _ySize * GUI_GRID_H];
	_c3pos = [safeZoneX,((_yPos + _ySize * 2) * GUI_GRID_H + GUI_GRID_Y),safeZoneW, _ySize * GUI_GRID_H];
	
	_getClr = call Epoch_getColorScheme;
	_clr = [_getClr select 0, _getClr select 1, _getClr select 2, 0.2];
	
	//Start anim
	_msg = "";
	_time = (rmx_var_msgQueue select 0 select 1);
	
	_fnc_animFirst = {
		private "_ctrl";
	
		_ctrl = param [0];
		_msg = param [1];
		_ctrl ctrlSetBackgroundColor [_clr select 0, _clr select 1, _clr select 2, 0.2];
		_ctrl ctrlSetText _msg;
		
		_ctrl ctrlSetPosition _c1StartPos;
		_ctrl ctrlSetFade 1;
		_ctrl ctrlCommit 0;
		
		_ctrl ctrlSetPosition _c1pos;
		_ctrl ctrlSetFade 0;
		_ctrl ctrlCommit 0.3;
	};
	
	_fnc_animShiftCtrl = {
		private ["_ctrl", "_fade", "_fontSize", "_pos"];
		_ctrl = param [0];
		_fade = param [1];
		_fontSize = param [2];
		_pos = param [3];
		
		_ctrl ctrlSetPosition _pos;
		_ctrl ctrlSetFontHeight _fontSize;
		_ctrl ctrlSetFade _fade;
		_ctrl ctrlCommit 0.3;
	};
	
	_tick = diag_tickTime; _ctrlArr = [];
	while {(diag_tickTime - _tick) < _time} do {

		if !(rmx_var_msgQueue isEqualTo []) then {

			_msg = (rmx_var_msgQueue select 0 select 0);
			_time = (rmx_var_msgQueue select 0 select 1);
			_tick = diag_tickTime;
			rmx_var_msgQueue deleteAt 0;
			_uniqueID = 
			switch (count _ctrlArr) do {
				case 0:
				{
					_c = _dsp ctrlCreate ["rmx_t1", call epoch_getIDC];
					_ctrlArr = [[_c, _msg]];
					[_c, _msg] call _fnc_animFirst;
				};
				case 1:
				{
					_c = _dsp ctrlCreate ["rmx_t1", call epoch_getIDC];
					_ctrlArr set [count _ctrlArr, [_c, _msg]];
					[_c, _msg] call _fnc_animFirst;
					
					[_ctrlArr select 0 select 0, 0.5, 0.035, _c2pos] call _fnc_animShiftCtrl;
				};
				case 2:
				{
					_c = _dsp ctrlCreate ["rmx_t1", call epoch_getIDC];
					_ctrlArr set [count _ctrlArr, [_c, _msg]];
					[_c, _msg] call _fnc_animFirst;
					
					[_ctrlArr select 1 select 0, 0.5, 0.035, _c2pos] call _fnc_animShiftCtrl;
					[_ctrlArr select 0 select 0, 0.75, 0.03, _c3pos] call _fnc_animShiftCtrl;
				};
				case 3:
				{
					_oldCtrl = (_ctrlArr select 0 select 0);
					[_oldCtrl] call epoch_getIDC;
					ctrlDelete _oldCtrl;
					_ctrlArr deleteAt 0;
					
					_c = _dsp ctrlCreate ["rmx_t1", call epoch_getIDC];
					_ctrlArr pushBack [_c, _msg];
					[_c, _msg] call _fnc_animFirst;
					
					[_ctrlArr select 1 select 0, 0.5, 0.035, _c2pos] call _fnc_animShiftCtrl;
					[_ctrlArr select 0 select 0, 0.75, 0.03, _c3pos] call _fnc_animShiftCtrl;
				};
			};
		};
	};
	
	//End anim
	{
		(_x select 0) ctrlSetFade 1;
		(_x select 0) ctrlSetPosition [safeZoneX, ((_yPos + _ySize * (_forEachIndex + 1)) * GUI_GRID_H + GUI_GRID_Y)];
		(_x select 0) ctrlCommit (0.4 - ((_foreachIndex + 1) / 10));
	} forEach _ctrlArr;

	uisleep 0.50;
	
	{
		ctrlDelete (_x select 0);
	} forEach _ctrlArr;
	
	rmx_var_msgQueue = nil;
};

true
