/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors:

	Description:
	Attaches picture and text to model's local space and projects on UI.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/blob/release/Sources/epoch_code/gui/scripts/worldToScreen/Epoch_gui3DModelPos.sqf

	Example:
	[_object, _time, _image, _text, _objectSpace, _distance, _externalBool] call epoch_gui3dModelPos;
*/
#include "\A3\ui_f\hpp\defineCommonGrids.inc"
_this spawn {
	private ["_obj","_loc","_time","_pic","_txt","_dst","_bool","_display","_ctrl","_rnd","_var","_imgParsed","_txtParsed","_id","_tick"];
	disableSerialization;
	params
	[
		["_obj", objNull, [objNull]],
		["_time", 10, [0]],
		["_pic", "#(argb,8,8,3)color(0,0,0,0)", [""]],
		["_txt", "", [""]],
		["_loc", [0,0,0], [[]]],
		["_dst", 10, [0]],
		["_bool", "", [""]]
	];

	if (_obj isEqualTo objNull) exitWith {hint "Wrong params, missing object"};

	_display = findDisplay 46;

	_ctrl = _display ctrlCreate ["RscStructuredText",call epoch_getIDC];
	_ctrl ctrlSetPosition [10 * GUI_GRID_W + GUI_GRID_X,10 * GUI_GRID_H + GUI_GRID_Y,10 * GUI_GRID_W,10 * GUI_GRID_H];
	_ctrl ctrlCommit 0;

	_imgParsed = parseText format ["<t size='4' align = 'center'><img image='%1' /></t>",_pic];
	_txtParsed = parseText format ["<t size='1.5' align = 'center' color='#FFFFFF'>%1</t>",_txt];

	_ctrl ctrlSetStructuredText (composeText [_imgParsed, parseText "<br>", _txtParsed]);

	_rnd = format ["rmx_var_temp%1%2",floor random 100, selectRandom ["A","B","C","D","E","F"]];
	uiNamespace setVariable [_rnd,[_ctrl, _obj, _loc, (ctrlPosition _ctrl),_dst/2]];
	_var = format ["uiNamespace getVariable '%1'",_rnd];

	_id = addMissionEventHandler ['Draw3D',_var + "call epoch_gui3dModelPosEH;"];

	_tick = diag_tickTime;
	while {(diag_tickTime - _tick) < _time} do {
		if !(missionNamespace getVariable [_bool, true]) exitWith {};
		if ((player distance (_obj modelToWorld _loc)) > _dst) exitWith {};
	};

	removeMissionEventHandler ["Draw3D", _id];
	uiNamespace setVariable [_rnd, nil];
	_ctrl call epoch_getIDC;
	ctrlDelete _ctrl;
};

true
