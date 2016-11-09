/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors:

	Description:
	Creates special HUD Groups defined in CfgDynamicHUD.hpp at the start of the game.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/scripts/dynamicHUD/Epoch_dynamicHUD_start.sqf
*/
#include "\A3\ui_f\hpp\defineCommonGrids.inc"
//[[[cog import generate_private_arrays ]]]
private ["_angle","_arraySize","_c","_cPos","_center","_cfg","_classname","_configs","_defaultPopulate","_defaultPos","_dsp","_evenOdd","_group","_groupPos","_h","_hCtrl","_height","_oX","_oY","_offsetX","_offsetY","_result","_scale","_w","_wCtrl","_width"];
//[[[end]]]
_cfg = "rmx_dynamicHUD" call EPOCH_returnConfig;
_configs = "true" configClasses _cfg;

// diag_log format ["Epoch_dynamicHUD_start: %1", _configs];

setMousePosition [0.5,0.5];

disableSerialization;
_dsp = findDisplay 46;

{
	_group = _dsp ctrlCreate ["rmx_rscControlsGroup", call Epoch_getIDC];
	rmx_var_dynamicHUD_groups set [_forEachIndex, _group];

	_defaultPopulate = getNumber (_x >> "defaultPopulate");
	_defaultPos = getNumber (_x >> "defaultPos");
	_arraySize = getNumber (_x >> "arraySize");
	_classname = getText (_x >> "classname");
	_offsetX = getNumber (_x >> "offSetX");
	_offsetY = getNumber (_x >> "offSetY");
	_height = getNumber (_x >> "height");
	_width = getNumber (_x >> "width");

	(getArray (_x >> "angle")) params [["_deg",0],["_xCenter",0.5],["_yCenter",0.5],["_tilt",0]];
	(getArray (_x >> "scale")) params [["_scale",1.0],["_reduction",0]];

	_wCtrl = _width * GUI_GRID_W;
	_hCtrl = _height * GUI_GRID_H;
	_oX = _offsetX * _wCtrl;
	_oY = _offsetY * _hCtrl;

	_w = 0; _h = 0;
	if (_defaultPopulate in [0,1,4]) then {
		_w = _arraySize * _width * GUI_GRID_W;
		_h = _height * GUI_GRID_H;
	} else {
		_w = _width * GUI_GRID_W;
		_h = _arraySize * _height * GUI_GRID_H;
	};

	_groupPos = switch _defaultPos do {
		case 0: {[SafezoneX, safezoneY, _w, _h]};
		case 1: {[0.5 - _w/2, safezoneY, _w, _h]};
		case 2: {[(safezoneW + safezoneX) - _w, safezoneY, _w, _h]};
		case 3: {[SafezoneX, 0.5 - _h/2, _w, _h]};
		case 4: {[0.5 - _w/2, 0.5 - _h/2, _w, _h]};
		case 5: {[(safezoneW + safezoneX) - _w, 0.5 - _h/2, _w, _h]};
		case 6: {[SafezoneX, (safezoneH + safezoneY) - _h, _w, _h]};
		case 7: {[0.5 - _w/2, (safezoneH + safezoneY) - _h, _w, _h]};
		case 8: {[(safezoneW + safezoneX) - _w, (safezoneH + safezoneY) - _h, _w, _h]};
		default {[0,0,0,0]};
	};

	_groupPos set [0, (_groupPos select 0)+_oX];
	_groupPos set [1, (_groupPos select 1)+_oY];
	_group ctrlSetPosition _groupPos;

	_group ctrlCommit 0;

	_evenOdd = true;
	rmx_var_dynamicHUD_groupCTRL set [_forEachIndex, [(configName _x)]];

	_angle = [_deg,_xCenter,_yCenter];


	for "_i" from 0 to (_arraySize - 1) do {
		_c = _dsp ctrlCreate [_classname, call Epoch_getIDC, _group];
		_c ctrlSetAngle _angle;

		_angle set [0, (_angle select 0) - _tilt];

		(rmx_var_dynamicHUD_groupCTRL select _forEachIndex) pushBack _c;

		_cPos = switch _defaultPopulate do {
			case 0: {[_i * _wCtrl,0,_wCtrl, _hCtrl]};
			case 1: {[(_arraySize - 1 - _i) * _wCtrl,0,_wCtrl, _hCtrl]};
			case 2: {[0,_i * _hCtrl,_wCtrl, _hCtrl]};
			case 3: {[0,(_arraySize - 1 - _i) * _hCtrl,_wCtrl, _hCtrl]};
			case 4:
			{
				_center = _w/2 - _wCtrl/2;

				_result = if (_i == 0) then {
					[_center, 0, _wCtrl, _hCtrl]
				} else {
					if _evenOdd then {
						[_wCtrl * _i/2 + _center, 0, _wCtrl, _hCtrl]
					} else {
						[(_center - _wCtrl/2) - (_wCtrl * _i/2), 0, _wCtrl, _hCtrl]
					};
				};
				_evenOdd = !_evenOdd;
				_result
			};
			case 5:
			{
				_center = _h/2 - _hCtrl/2;

				_result = if (_i == 0) then {
					[0, _center, _wCtrl, _hCtrl]
				} else {
					if _evenOdd then {
						[0, _hCtrl * _i/2 + _center, _wCtrl, _hCtrl]
					} else {
						[0, (_center - _hCtrl/2) - (_hCtrl * _i/2), _wCtrl, _hCtrl]
					};
				};
				_evenOdd = !_evenOdd;
				_result
			};
			default {[0,0,0,0]};
		};
		_c ctrlSetPosition _cPos;
		_c ctrlSetScale _scale;
		_c setVariable ["ctrl_scale", _scale];
		_scale = _scale - _reduction;
		_c ctrlCommit 0;
	};
} forEach _configs;

	//dump default positions into an array

true
