/*
	Author: Raimonds Virtoss - EpochMod.com

	Description:
	Displays custom text message to player, supports any variable and structured text

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/blob/release/Sources/epoch_code/gui/scripts/messaging/Epoch_message_old2.sqf

	Usage:
	"TEST" call Epoch_message_old2
*/
//[[[cog import generate_private_arrays ]]]
private ["_c","_c2","_c3","_clr","_cmt","_cnt","_ct","_dsp","_height","_in","_timer","_w2","_width"];
//[[[end]]]
#include "\A3\ui_f\hpp\defineCommonGrids.inc"

_in = param [0, "No input given"];
_timer = param [1, 2];

if !(_in isEqualType "STRING") then {_in = str _in};

if (isnil "rmx_var_dtMessageArr") then {
	rmx_var_dtMessageArr = [];
};

if (!isnil "rmx_var_dtEnabled") exitWith {
	if !([_in, _timer] in rmx_var_dtMessageArr) then  //spam protection
	{
		rmx_var_dtMessageArr pushBack [_in, _timer];
	};
};
rmx_var_dtEnabled = true;
rmx_var_dtMessageArr pushBack [_in, _timer];

[GUI_GRID_W, GUI_GRID_H] spawn {
	params ["_gridW","_gridH"];
	disableSerialization;

	_dsp = findDisplay 46;

	_c = _dsp ctrlCreate ["rmx_ST2", -8777];
	_c2 = _dsp ctrlCreate ["RscText", -8776];
	_c3 = _dsp ctrlCreate ["RscText", -8775];

	_clr = call Epoch_getColorScheme;

	_c ctrlSetBackgroundColor [_clr select 0, _clr select 1, _clr select 2, 0.5];
	_c2 ctrlSetBackgroundColor _clr;
	_c3 ctrlSetBackgroundColor _clr;

	//first animation
	_width = 0.2 * _gridW;
	_height = 2 * _gridH;

	_c ctrlSetPosition [0.5 - _gridW / 2,1,_gridW,_height];
	_c2 ctrlSetPosition[0.5 - _gridW / 2,1,_width,_height];
	_c3 ctrlSetPosition[0.5 + _gridW / 2,1,_width,_height];
	_c ctrlCommit 0;
	_c2 ctrlCommit 0;
	_c3 ctrlCommit 0;

	_cmt = 0.25;

	//Main queue
	while {!(rmx_var_dtMessageArr isEqualTo [])} do
	{

		_in = parseText (rmx_var_dtMessageArr select 0 select 0);
		_timer = rmx_var_dtMessageArr select 0 select 1;
		rmx_var_dtMessageArr deleteAt 0;

		_c ctrlSetStructuredText _in;

		_cnt = 0;

		{
			_ct = if (_x in [65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90]) then {1} else {0.5};
			_cnt = _cnt +_ct;
		} count (toArray str _in);

		_w2 = ((_cnt max 5) min 80) * _gridW;

		_c ctrlSetPosition [0.5 - _w2 / 2,1,_w2,_height];
		_c2 ctrlSetPosition[0.5 - _w2 / 2,1,_width,_height];
		_c3 ctrlSetPosition[0.5 + _w2 / 2,1,_width,_height];

		_c ctrlCommit _cmt;
		_c2 ctrlCommit _cmt;
		_c3 ctrlCommit _cmt;

		uiSleep _timer;
	};

	//exit with animation
	_c ctrlSetPosition [0.5 - _gridW / 2,1,_gridW,_height];
	_c2 ctrlSetPosition[0.5 - _gridW / 2,1,_width,_height];
	_c3 ctrlSetPosition[0.5 + _gridW / 2,1,_width,_height];
	_c ctrlCommit _cmt;
	_c2 ctrlCommit _cmt;
	_c3 ctrlCommit _cmt;

	uiSleep _cmt;

	ctrlDelete _c;
	ctrlDelete _c2;
	ctrlDelete _c3;

	rmx_var_dtEnabled = nil;
};
