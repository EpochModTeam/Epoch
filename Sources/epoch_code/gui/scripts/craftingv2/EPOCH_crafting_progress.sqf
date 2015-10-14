if !(isNil "rmx_var_craftProgressInProgress") exitWith {false};
rmx_var_craftProgressInProgress = true;

private ["_txt","_time","_posY","_posX","_w","_h","_idc","_stColor","_out","_display","_ctrl","_ctrl2","_ctrl3","_tick"];
disableSerialization;
_txt = param [0,"No text"];
_time = param [1,1];
_posY = param [2,1.05];
_posX = param [3,0.25];

_w = 0.5;
_h = 0.05;
_idc = 10100;

_stColor = rmx_var_crafting_colorScheme select 22;
_out = true;

_layer = str _idc call BIS_fnc_rscLayer;
_layer cutRsc ["rmx_CraftingProgress","PLAIN",0,false];
_display = uiNamespace getVariable "rmx_var_CraftingProgressDisplay";

_ctrl3 = _display ctrlCreate ["RscText",_idc + 3];
_ctrl3 ctrlSetPosition [_posX,_posY,_w,_h];
_ctrl3 ctrlCommit 0;
_ctrl3 ctrlSetBackgroundColor  (rmx_var_crafting_colorScheme select 21);

_ctrl = _display ctrlCreate ["RscProgress",_idc + 1];
_ctrl ctrlSetPosition [_posX,_posY,_w,_h];
_ctrl ctrlCommit 0;
_ctrl ctrlSetTextColor  (rmx_var_crafting_colorScheme select 20);

_ctrl2 = _display ctrlCreate ["RscStructuredText",_idc + 2];
_ctrl2 ctrlSetPosition [_posX + _w / 2 - (count _txt / 2) / 100,_posY + 0.005,_w,_h];
_ctrl2 ctrlCommit 0;
_ctrl2 ctrlSetStructuredText parseText format ["<t shadow='1'><t color='%2'>%1</t>",_txt,_stColor];

_tick = diag_tickTime;

while {((diag_tickTime - _tick) < _time && rmx_var_craftingLOOPS) } do {
	if !(rmx_var_craftInProgress) exitWith {_out = false;};
	_ctrl progressSetPosition ((diag_tickTime - _tick)/_time);
	
	uiSleep 0.01; //smoothness vs performance
};

_layer cutRsc ["Default","PLAIN"];
rmx_var_craftProgressInProgress = nil;

_out
