#include <\x\Addons\rmx_init\defines.inc>
disableSerialization;
if !(_this isEqualTypeParams [true,0]) exitWith {false};
params ["_add","_idx"];
//TODO: ONLOAD to populate controls
//TODO: 

//if ((_idx < 0) || (_idx > count rmx_var_watcherGrpControls)) exitWith {false};
if (_idx < 0) exitWith {false};

//_display = if (rmx_var_watcherPinned) then {uiNamespace getVariable "rmx_var_watcher2"} else {findDisplay 7500};

_isPinned = uiNamespace getVariable ["rmx_var_watcher2",displayNull];
_display = if (_isPinned isEqualTo displayNull) then {
	findDisplay 7500
} else {
	_isPinned
};

_grp = _display displayCtrl 7507;
_codeBox = _display displayCtrl 7504;
_grpPos = ctrlPosition _grp;

if (_add) then {
	_grpPos set [3, (_grpPos select 3) + 0.108];
	_grp ctrlSetPosition _grpPos;
	_grp ctrlCommit 0;
	_color = call Epoch_getColorScheme;
	
	//Create debug elements
	_cTop = _display ctrlCreate ["RscText", call Epoch_getIDC, _grp];
	_cVarBG = _display ctrlCreate ["RscText", call Epoch_getIDC, _grp];
	_cVar = switch (_idx) do {
		case 1: {_display ctrlCreate ["RscPicture", call Epoch_getIDC, _grp]};
		case 2: {_display ctrlCreate ["RscProgress", call Epoch_getIDC, _grp]};
		default {_display ctrlCreate ["RscEdit", call Epoch_getIDC, _grp]};
	};
	_cX = _display ctrlCreate ["RscButton", call Epoch_getIDC, _grp];
	_cOk = _display ctrlCreate ["RscButton", call Epoch_getIDC, _grp];
	_cEdit = _display ctrlCreate ["RscEdit", call Epoch_getIDC, _grp];

	//store debug elements into an array
	_cArr = [_cTop, _cVarBG, _cVar, _cX, _cOk, _cEdit];
	
	//store group of debug elements with others
	rmx_var_watcherGrpControls pushBack _cArr;
	rmx_var_watcherGrpControls_data pushBack [ctrlText _codeBox,_idx]; //index of execute
	profileNamespace setVariable ["rmx_var_watcherGrpControls_data",rmx_var_watcherGrpControls_data];
	
	//Give position and parent variable data
	_ctrlSettings = 
	[
		[[0,0,0.465,0.012],[0,0,0,0], "", [0,0,0,0]],
		[[0,0.012,0.4225,0.048],[0,0,0,0.6], "", [0,0,0,0]],
		[[0,0.06,0.4225,0.048],[1,1,1,0.1], "", [1,1,1,1]],
		[[0.4225,0.06,0.0425,0.048],[1,1,1,1], "X", _color],
		[[0.4225,0.012,0.0425,0.048],[1,1,1,1], "Ok", _color],
		[[0,0.012,0.4225,0.048],[0,0,0,0.6], ctrlText _codeBox, _color]
	];
	
	{
		_x ctrlSetPosition (_ctrlSettings select _forEachIndex select 0);
		_x ctrlSetBackgroundColor (_ctrlSettings select _forEachIndex select 1);
		_x ctrlSetText (_ctrlSettings select _forEachIndex select 2);
		_x ctrlSetTextColor (_ctrlSettings select _forEachIndex select 3);
		_x ctrlCommit 0;
	} forEach _cArr;
	
} else {
	if (rmx_var_watcherGrpControls isEqualTo []) exitWith {false};
	
	_grpPos set [3, (_grpPos select 3) - 0.108];
	_grp ctrlSetPosition _grpPos;
	_grp ctrlCommit 0;
	
	{
		_x call Epoch_getIDC;
		ctrlDelete _x;
	} forEach (rmx_var_watcherGrpControls select _idx);
	rmx_var_watcherGrpControls deleteAt _idx;
	rmx_var_watcherGrpControls_data deleteAt _idx; //generated index from buttonSetAction (see below)
	profileNamespace setVariable ["rmx_var_watcherGrpControls_data",rmx_var_watcherGrpControls_data];
};
// y
// 0.012 + 0.108 * rmx_var_watcherGrpIndex
_ctrlSettingsY = [0, 0.012, 0.06, 0.06, 0.012, 0.012];

//Refresh/Update positions after changes
{
	_count = _forEachIndex;
	{
		_yPos = ctrlPosition _x;
		_yPos set [1, (_ctrlSettingsY select _forEachIndex) + 0.108 * _count];
		_x ctrlSetPosition _yPos;
		_x ctrlCommit 0;
	} forEach _x;
	
	(_x select 3) buttonSetAction (format ["[false, %1] call rmx_fnc_watcherAddRemove;",_forEachIndex]);
	(_x select 4) buttonSetAction (format ["(rmx_var_watcherGrpControls_data select %1) set [0, ctrlText(rmx_var_watcherGrpControls select %1 select 5)]",_forEachIndex]);
	
	
	
} forEach rmx_var_watcherGrpControls;

//Don't delete yet, used to visualize group size
/*
_c = _display ctrlCreate ["RscText", 909090];
_c = _display displayCtrl 909090;
_c ctrlSetPosition _grpPos;
_c ctrlCommit 0;
_c ctrlSetBackgroundColor [1,0,0,0.1];
*/

true
