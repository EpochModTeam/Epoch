/*
	Author: Raimonds Virtoss - EpochMod.com

	Description:
	Displays custom text message to player

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/blob/release/Sources/epoch_code/gui/scripts/messaging/Epoch_message_stack.sqf

	Usage:
	"TEST" call Epoch_message_stack

	["===================================",5,[[0,0,0,0.2],[1,0.5,0,1]]] call Epoch_message_stack;
	["World!",5,[[0,0,0,0.2],[1,1,1,1]]] call Epoch_message_stack;
	["Hello",5,[[0,0,0,0.2],[1,1,1,1]]] call Epoch_message_stack;
	["===================================",5,[[0,0,0,0.2],[1,0.5,0,1]]] call Epoch_message_stack;
*/

#include "\A3\ui_f\hpp\defineCommonGrids.inc"
_msg = param [0, "No input"];
_time = param [1, 2];
_customCol = param[2,[]];
private["_bgCol","_txtCol"];
if(_customCol isEqualTo [])then{
	_config = 'CfgEpochClient' call EPOCH_returnConfig;
	_bgCol = getArray(_config >> "epochMessageBackgroundCol");
	_txtCol = getArray(_config >> "epochMessageTextCol");
	if !(_bgCol isEqualTypeAll 0)then{_bgCol = [0,0,0,0.2]};
	if !(_txtCol isEqualTypeAll 0)then{_txtCol = [1,1,1,0.95]};
}else{
	_bgCol = if((_customCol select 0)isEqualTypeAll 0) then [{_customCol select 0},{_bgCol = [0,0,0,0.2]}];
	_txtCol = if((_customCol select 1)isEqualTypeAll 0) then [{_customCol select 1},{_txtCol = [1,1,1,0.95]}];
};
if !(_msg isEqualType "STRING") then { //Needed to remove quotations from strings
	_msg = str (parseText str _msg); //Parses and converts text back to small string
};


if !(isNil "rmx_var_msgStackQueue") exitWith {rmx_var_msgStackQueue pushBack [_msg, _time, [_bgCol,_txtCol]]};

rmx_var_msgStackQueue = [[_msg, _time, [_bgCol,_txtCol]] ];

[] spawn {
	private ["_dsp"];

	disableSerialization;
	_dsp = findDisplay 46;
	_yPos = 15;
	_ySize = 2;
	_cStartPos = [safeZoneX,((_yPos - _ySize) * GUI_GRID_H + GUI_GRID_Y),safeZoneW, _ySize * GUI_GRID_H];

	_ctrlArr = [1];

	_fnc_reorganizeCtrls = {
		if !(_ctrlArr isEqualTo []) then {
			{
				_newPos = [safeZoneX,(((_yPos - 3) - (_ySize * _forEachIndex)) * GUI_GRID_H + GUI_GRID_Y),safeZoneW, _ySize * GUI_GRID_H];
				_c = _x select 0;
				_c ctrlSetPosition _newPos;
				_c ctrlCommit 0;
			} forEach _ctrlArr;
		};
	};

	while {(count _ctrlArr) > 0} do {
		if ((_ctrlArr select 0) isEqualTo 1) then {_ctrlArr = [];};
		if !(rmx_var_msgStackQueue isEqualTo []) then {
			_msg = (rmx_var_msgStackQueue select 0 select 0);
			_time = diag_tickTime + (rmx_var_msgStackQueue select 0 select 1);
			_col = (rmx_var_msgStackQueue select 0)select 2;
			rmx_var_msgStackQueue deleteAt 0;

			_c = _dsp ctrlCreate ["rmx_t1", call epoch_getIDC];
			_c ctrlSetBackgroundColor (_col select 0);
			_c ctrlSetText _msg;
			_c ctrlSetTextColor (_col select 1);

			_c ctrlSetPosition _cStartPos;
			_c ctrlSetFade 1;
			_c ctrlCommit 0;

			_c ctrlSetFade 0;
			_c ctrlCommit 0.5;

			_ctrlArr pushBack [_c,_time];
			call _fnc_reorganizeCtrls;
		};

		{
			_time = _x select 1;
			_c = _x select 0;
			if (_time <= diag_tickTime) then {
			ctrlDelete _c;
			[_c] call epoch_getIDC;
			_ctrlArr deleteAt _forEachIndex;
			call _fnc_reorganizeCtrls;
			};
		} forEach _ctrlArr;
	};
	rmx_var_msgStackQueue = nil;
};

true
