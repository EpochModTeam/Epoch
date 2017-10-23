/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors:

	Description:
	DESC-TBA

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/scripts/dynamenu/Epoch_dynamicMenuPopulate.sqf
*/
#include "\A3\ui_f\hpp\defineCommonGrids.inc"
//[[[cog import generate_private_arrays ]]]
private ["_arr","_c","_center","_ctrl","_ctrl2","_defaultScaleX","_defaultScaleY","_display","_distance","_inProgress","_points","_positions","_positions2","_scale","_scaleLargeX","_scaleLargeY","_scaleSmallX","_scaleSmallY","_x","_y"];
//[[[end]]]
params ["_entries","_buttonSettings"];
disableSerialization;

_inProgress = uiNamespace getVariable ["rmx_var_dynamicMenuInProgress", false];

waitUntil{!isNull (findDisplay 66600)};
_display = findDisplay 66600;

if (_inProgress) then {
	{
		ctrlDelete _x;
	} forEach rmx_var_dynaControls;
} else {
	uiNamespace setVariable ["rmx_var_dynamicMenuInProgress", true];
	//Post processing
	if (isNil "rmx_var_dynamenuPPHandle") then {
		rmx_var_dynamenuPPHandle = ["dynamicBlur",10] call epoch_postProcessCreate;
		[rmx_var_dynamenuPPHandle, 1, [1]] call epoch_postprocessAdjust;
	};
};

//defaults don't edit
_center = 0.5;
_scale = 12;
_defaultScaleX = _scale * GUI_GRID_W;
_defaultScaleY = _scale * GUI_GRID_H;

_distance = 0.6 + _entries / 100;

//edit scaling here (divisor only, larger values produce smaller image)
_scaleLargeX = _defaultScaleX / (1 + _entries / 10); //anim
_scaleLargeY = _defaultScaleY / (1 + _entries / 10);
_scaleSmallX = _defaultScaleX / (2 + _entries / 10); //icons
_scaleSmallY = _defaultScaleY / (2 + _entries / 10);

_points = 360 / _entries;

_positions = [];
_positions2 = [];
for "_p" from 0 to 360 step _points do {

	_x = cos _p * (0.3 * _distance);
	_y = sin _p * (0.4 * _distance);

	_positions pushBack [_x + (_center - (_scaleLargeX / 2)),_y + (_center - (_scaleLargeY / 2)),_scaleLargeX,_scaleLargeY];
	_positions2 pushBack [_x + (_center - (_scaleSmallX / 2)),_y + (_center - (_scaleSmallY / 2)),_scaleSmallX,_scaleSmallY];
};

missionNamespace setVariable ["rmx_var_dynaControls",[]];
//_buttonSettings [icon,tooltip,action]
for "_e" from 0 to (_entries - 1) do {
	private ["_ctrl","_ctrl2"];
	_ctrl = _display ctrlCreate ["rmx_rscPicture",(66600 + _e)];
	_ctrl ctrlSetText "x\addons\a3_epoch_code\Data\UI\buttons\dm_selection_b1.paa";
	_ctrl ctrlSetPosition (_positions select _e);
	_ctrl ctrlSetFade 1;
	_ctrl ctrlCommit 0;
	[_ctrl,0.55,0.2] call BIS_fnc_ctrlSetScale;
	_ctrl ctrlSetTooltip (_buttonSettings select _e select 1);

	_ctrl ctrlSetTooltipColorBox [0, 0, 0, 0];
	_ctrl ctrlSetTooltipColorShade [0, 0, 0, 0];
	_ctrl ctrlSetEventHandler ["mouseEnter", "_c = _this select 0; _c ctrlSetFade 0; [_c,0.8,0.2] call BIS_fnc_ctrlSetScale"];
	_ctrl ctrlSetEventHandler ["mouseExit", "_c = _this select 0; _c ctrlSetFade 1; [_c,0.55,0.2] call BIS_fnc_ctrlSetScale"];
	_ctrl ctrlSetEventHandler ["mouseButtonDown", (_buttonSettings select _e select 2)];
	_ctrl ctrlEnable true;

	_ctrl2 = _display ctrlCreate ["RscPictureKeepAspect",-(66600 + _e)];
	_ctrl2 ctrlSetTooltip (_buttonSettings select _e select 1);
	_ctrl2 ctrlSetTooltipColorBox [0, 0, 0, 0];
	_ctrl2 ctrlSetTooltipColorShade [0, 0, 0, 0];
	_ctrl2 ctrlSetText (_buttonSettings select _e select 0);
	
	_ctrl2 ctrlSetPosition [0.5,0.5,0,0];
	_ctrl2 ctrlCommit 0;
	
	_ctrl2 ctrlSetPosition (_positions2 select _e);
	_ctrl2 ctrlCommit 0.2;

	_arr = missionNamespace getVariable ["rmx_var_dynaControls",[]];
	_arr append [_ctrl,_ctrl2];
	missionNamespace setVariable ["rmx_var_dynaControls",_arr];
};

true
