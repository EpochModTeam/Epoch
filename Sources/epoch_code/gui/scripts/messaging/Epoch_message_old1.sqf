/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors: Aaron Clark

	Description:
	Displays custom text message to player

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/blob/release/Sources/epoch_code/gui/scripts/messaging/Epoch_message_old1.sqf

	Usage:
	"TEST" call Epoch_message_old1
*/
//[[[cog import generate_private_arrays ]]]
private ["_add","_alreadyEnabled","_arr","_centerX","_centerY","_cnt","_controls","_ctrl","_ctrlGroup","_ctrlText","_del","_display","_height","_input","_scale","_text","_tick","_width","_xPos","_y","_yPos"];
//[[[end]]]
#include "\A3\ui_f\hpp\defineCommonGrids.inc"

params [["_text","Missing text",["",(text "")]],["_time",5,[1]],["_color","#ffffff",[""]] ];

if (_text isEqualType "STRING") then {_text = parseText _text};

_alreadyEnabled = uiNamespace getVariable ["rmx_var_dynamicText",false];

_input = count str _text * 2;
_scale = 1;
_width = _scale * GUI_GRID_W;
_height = _scale * GUI_GRID_H;
_centerX = 0.5;
_centerY = -18 * GUI_GRID_H + GUI_GRID_Y;

disableSerialization;
_display = findDisplay 46;

_ctrlGroup = _display ctrlCreate ["RscControlsGroupNoScrollbars", call Epoch_getIDC];
_ctrlGroup ctrlSetPosition [_centerX - _width/2 * _input / 2, _centerY - _height, _width * _input, _height * 2];
_ctrlGroup ctrlCommit 0;

_y = 0;
_cnt = -1;
_controls = [];
for "_i" from 0 to (_input - 1) do {
	_ctrl = _display ctrlCreate ["RscPicture", call Epoch_getIDC,_ctrlGroup];
	_cnt = _cnt + 1;
	if (_cnt == (_input / 2)) then {_y = _height; _cnt = 0;};
	_ctrl ctrlSetPosition [_cnt * _width,_y,_width,_height];
	_ctrl ctrlSetText "#(rgb,8,8,3)color(1,1,1,1)";
	_ctrl ctrlCommit 0;
	_ctrl ctrlSetFade 1-(random 0.2);
	[_ctrl, 1-(random 0.2),0] call BIS_fnc_ctrlSetScale;

	_controls set [_i, _ctrl];
};

_ctrlText = _display ctrlCreate ["rmx_ST1", call Epoch_getIDC,_ctrlGroup];
_ctrlText ctrlSetStructuredText _text;
_ctrlText ctrlSetPosition [0, 0, _width * _input /2, _height * 2];
_ctrlText ctrlCommit 0;


_add = uiNamespace getVariable ["rmx_var_dynamicTextCTRL",[]];
_add pushBack _ctrlGroup;
uiNamespace setVariable ["rmx_var_dynamicTextCTRL",_add];

[_time,_ctrlGroup,_ctrlText,_controls] spawn {
	disableSerialization;
	params ["_time","_ctrlGroup","_ctrlText","_controls"];

	_tick = diag_tickTime;
	while {(diag_tickTime - _tick) < _time} do {
		{
			_x ctrlSetFade 1-(random 0.2);
			[_x, 1-(random 0.2), (random 1)] call BIS_fnc_ctrlSetScale;
		} forEach _controls;
		uiSleep 0.5;
	};
	_arr = uiNamespace getVariable ["rmx_var_dynamicTextCTRL",[]];
	_del =
	{
		if (str _x isEqualTo str _ctrlGroup) exitWith {_forEachIndex};
		0
	} forEach _arr;

	_arr deleteAt _del;
	uiNamespace setVariable ["rmx_var_dynamicTextCTRL",_arr];
	uiSleep 0.01;
	{
		_x call Epoch_getIDC;
		ctrlDelete _x;
	} forEach (_controls + [_ctrlText] + [_ctrlGroup]);
};

if !(_alreadyEnabled) then {
	uiNamespace setVariable ["rmx_var_dynamicText",true];
	[ctrlPosition _ctrlGroup] spawn {
		disableSerialization;
		params ["_defaultPos"];
		_yPos = _defaultPos param [1];
		_height = _defaultPos param [3];
		while {uiNamespace getVariable ["rmx_var_dynamicText",false]} do {
			_arr = uiNamespace getVariable ["rmx_var_dynamicTextCTRL",[]];
			if (_arr isEqualTo []) exitWith {uiNamespace setVariable ["rmx_var_dynamicText",nil];};
			{
				_xPos = (ctrlPosition _x) select 0;
				_x ctrlSetPosition [_xPos,_yPos + _height * _forEachIndex];
				_x ctrlCommit 0;
			} forEach _arr;
		};
	};
};
true
