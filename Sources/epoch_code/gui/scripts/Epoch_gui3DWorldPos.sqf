/*
	Attaches picture and text to World location and projects on UI.
	[_location, _time, _image, _text, _distance, _externalBool] call epoch_gui3dWorldPos;
*/
#include "\A3\ui_f\hpp\defineCommonGrids.inc"
_this spawn {
	private ["_loc","_time","_pic","_txt","_dst","_bool","_display","_ctrl","_imgParsed","_txtParsed","_id","_tick"];
	disableSerialization;
	params
	[
		["_loc", [0,0,0], [[]]],
		["_time", 10, [0]],
		["_pic", "#(argb,8,8,3)color(0,0,0,0)", [""]],
		["_txt", "", [""]],
		["_dst", 10, [0]],
		["_bool", "", [""]]
	];

	_display = findDisplay 46;

	_ctrl = _display ctrlCreate ["RscStructuredText",call epoch_getIDC];
	_ctrl ctrlSetPosition [10 * GUI_GRID_W + GUI_GRID_X,10 * GUI_GRID_H + GUI_GRID_Y,10 * GUI_GRID_W,10 * GUI_GRID_H];
	_ctrl ctrlCommit 0;

	_imgParsed = parseText format ["<t size='4' align = 'center'><img image='%1' /></t>",_pic];
	_txtParsed = parseText format ["<t size='1.5' align = 'center' color='#FFFFFF'>%1</t>",_txt];
	
	_ctrl ctrlSetStructuredText (composeText [_imgParsed, parseText "<br>", _txtParsed]);
	
	_id = call compile format 
	[
	"
		missionNamespace setVariable ['rmx_var_3DWP_temp%1',[_ctrl, _dst, _loc]];
		_id = addMissionEventHandler ['Draw3D',{
			_arr = missionNamespace getVariable 'rmx_var_3DWP_temp%1';
			_pos = worldToScreen (_arr select 2);
			(_arr select 0) ctrlSetPosition _pos;
			(_arr select 0) ctrlCommit 0;
			_scale = linearConversion [0, (_arr select 1), player distance (_arr select 2), 1, 0, false];
			[(_arr select 0), _scale, 0] call BIS_fnc_ctrlSetScale;
		}];
		[_id,'rmx_var_3DWP_temp%1']
	"
	,floor random 10000
	];
	
	_tick = diag_tickTime;
	while {(diag_tickTime - _tick) < _time} do {
		if !(missionNamespace getVariable [_bool, true]) exitWith {};
		if ((player distance _loc) > _dst) exitWith {};
	};
	
	removeMissionEventHandler ["Draw3D", _id select 0];
	missionNamespace setVariable [_id select 1, nil];
	_ctrl call epoch_getIDC;
	ctrlDelete _ctrl;
};

true
