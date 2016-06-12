/*
	Author: Raimonds Virtoss - EpochMod.com

	Description:
	Displays custom text message to player

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_code/gui/scripts/Epoch_dynamicText.sqf

	Usage:
	"TEST" call Epoch_dynamicText
*/
#include "\A3\ui_f\hpp\defineCommonGrids.inc"

_in = param [0, "No input given"];
_timer = param [1, 5];

if !(_in isEqualType "STRING") then {_in = str _in};

if (!isnil "rmx_var_dtEnabled") then {
	rmx_var_dtDisable = true;
};

[_in, _timer, GUI_GRID_W, GUI_GRID_H] spawn {
	params ["_in","_timer","_gridW","_gridH"];
	disableSerialization;
	
	rmx_var_dtEnabled = true;
	rmx_var_dtDisable = false;
	
	_dsp = findDisplay 46;
	
	_c = _dsp ctrlCreate ["dUI_rscText", -8777];
	_c2 = _dsp ctrlCreate ["RscText", -8776];
	_c3 = _dsp ctrlCreate ["RscText", -8775];

	_c ctrlSetBackgroundColor [1,1,1,0.2];
	_c2 ctrlSetBackgroundColor (call Epoch_getColorScheme);
	_c3 ctrlSetBackgroundColor (call Epoch_getColorScheme);

	_c ctrlSetText _in;

	_cnt = 0;

	{
		_ct = if (_x in [65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90]) then {0.8} else {0.3};
		_cnt = _cnt +_ct;
	} count (toArray _in);

	_w = ((_cnt max 5) min 80) * _gridW;
	_w2 = 0.2 * _gridW;
	_h = 2 * _gridH;

	_c ctrlSetPosition [0.5 - _w / 2,1,_w,_h];
	_c2 ctrlSetPosition[0.5 - _w / 2,1,_w2,_h];
	_c3 ctrlSetPosition[0.5 + _w / 2,1,_w2,_h];

	_c ctrlCommit 0;
	_c2 ctrlCommit 0;
	_c3 ctrlCommit 0;


	_tick = diag_tickTime;
	while {((diag_tickTime - _tick) < _timer) && !rmx_var_dtDisable} do {};
	ctrlDelete _c;
	ctrlDelete _c2;
	ctrlDelete _c3;
	
	rmx_var_dtEnabled = nil;
	rmx_var_dtDisable = nil;
};