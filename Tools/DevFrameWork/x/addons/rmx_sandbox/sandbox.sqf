#include <\x\Addons\rmx_init\defines.inc>
disableSerialization;

call rmx_fnc_recompile;

//New trader menu
/*
"Epoch_tradeMainLoop" call rmx_fnc_recompile;
"Epoch_tradeLoad" call rmx_fnc_recompile;
"Epoch_tradeUnLoad" call rmx_fnc_recompile;
"Epoch_tradeMouseEvents" call rmx_fnc_recompile;
"Epoch_tradeMouseEvents" call rmx_fnc_recompile;
"Epoch_tradePopulateLB" call rmx_fnc_recompile;
call Epoch_tradeLoad;
*/

// dunno what's this for
/*
for "_i" from 1 to 7 do {
	_c = ["botcenter",_i] call epoch_getHUDCtrl;
	_c ctrlSetText "\x\addons\a3_epoch_code\Data\owner.paa";
};

_c1 = ["botcenter",1] call epoch_getHUDCtrl;
*/


/*
//"epoch_dynamicHUD_adjust" call rmx_fnc_recompile;
findDisplay 46 createDisplay "dUI_sandbox";

_dsp = findDisplay 666666;

_c = _dsp ctrlCreate ["rmx_emailMap", call epoch_getIDC];

_c ctrlSetPosition [0,0,1,1];
_c ctrlSetFade 0.1;
_c ctrlCommit 0;

_c ctrlMapAnimAdd [0, 1, getArray(configFile >> "CfgWorlds" >> worldName >> "centerPosition")];
ctrlMapAnimCommit _c;
_c ctrlMapAnimAdd [2, 0.1, getPosATL player];
ctrlMapAnimCommit _c;
*/
/*
disableSerialization;
findDisplay 46 createDisplay "dUI_sandbox";
_dsp = findDisplay 666666;

_c = _dsp ctrlCreate ["rmx_drag_RscActivePicture", 909090];
_c1 = _dsp ctrlCreate ["rmx_drag_RscActivePicture", 909091];

_c ctrlSetPosition [0,0,0.25,0.25];
_c1 ctrlSetPosition [1,0,0.25,0.25];
_c ctrlCommit 0;
_c1 ctrlCommit 0;

_c ctrlSetText "x\addons\rmx_init\data\retardedPinUp.paa";
_c ctrlSetTextColor [1,0.5,0,0.2];

_c1 ctrlSetText "x\addons\rmx_init\data\retardedPinUp.paa";
_c1 ctrlSetTextColor [1,1,0,1];
*/
/*
for "_i" from 0 to 360 step 2 do {
	_c ctrlSetAngle [_i,0.5,0.5];
	hint str (ctrlAngle _c);
	uiSleep 0.01;
};
*/

/*
rmx_fnc_moveShit = {
	_ctrl = param [0];
	_curr = ctrlPosition _Ctrl;
	_mpos = getmousePosition;
	
	if (rmx_var_drag_MouseDown) then {
		_ctrl ctrlSetPosition [(_mpos select 0) - (_curr select 2) / 2, (_mpos select 1) - (_curr select 3) / 2 ];
		_ctrl ctrlCommit 0;
	};
};

_c ctrlSetEventHandler ["mousemoving", "_this call rmx_fnc_moveShit;"];
_c ctrlSetEventHandler ["MouseButtonDown", "rmx_var_MouseDown = true;"];
_c ctrlSetEventHandler ["MouseButtonUp", "rmx_var_MouseDown = false;"];
_c1 ctrlSetEventHandler ["mousemoving", "_this call rmx_fnc_moveShit;"];
_c1 ctrlSetEventHandler ["MouseButtonDown", "rmx_var_MouseDown = true;"];
_c1 ctrlSetEventHandler ["MouseButtonUp", "rmx_var_MouseDown = false;"];
*/

//'rmx_fnc_epoch' call rmx_fnc_recompile;
/*
_a = "H";
_b = "Hi";
_c = "Hello World";
_d = "Lorem ipsum dolor sit amet, diceret imperdiet consectetuer";
_e = "Lorem ipsum dolor sit amet, diceret imperdiet consectetuer te sed, et qui civibus incorrupte, vis ei eirmod cetero. Vim sint evertitur ea, eum ea euismod commune singulis. Eos essent torquatos elaboraret ea, at per simul adversarium. Vis te homero intellegam. Usu ne tantas quaeque, wisi consectetuer has eu.";
_f = "xiiiiiiIiiiiiiiiiiiiiiiiiiiiiiiiix";
_g = "xWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWx";
_h = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
_i = "abcdefghijklmnopqrstuvwxyz";
*/

/*
sleep 1;
disableSerialization;
createDialog "rmx_rscContainer";
_dsp = findDisplay 99440;
_c = _dsp displayCtrl 99441;

_c ctrlSetModelScale 0.2;
_c ctrlSetModelDirAndUp [[0,1,0],[0,0,1]];
*/
//launch again to refresh memory
/*
rmx_test = false;
uiSleep 1;
rmx_test = true;
_IDC = 28901;
_getIDC = {_IDC = _IDC + 1; _IDC};

rmx_var_testControls = [];

_stuff = nearestOBjects [player, ["K03"],100];

{
	_ctrl = (findDisplay 46) ctrlCreate ["RscPicture",call _getIDC];
	_ctrl ctrlSetText "\x\addons\a3_epoch_code\Data\owner.paa";
	_ctrl ctrlSetPosition [0,0,0.1,0.1];
	_ctrl ctrlCommit 0;
	rmx_var_testControls set [_forEachIndex, [_x, _ctrl]];
}forEach _stuff;

while {rmx_test} do {
	{
		(_x select 1) ctrlSetPosition (worldToScreen getPos(_x select 0));
		(_x select 1) ctrlCommit 0;
	}forEach rmx_var_testControls;
	//uiSleep 0.5;
};

{
	ctrlDelete (_x select 1);
}forEach rmx_var_testControls;

rmx_var_testControls = [];

*/
//for "_i" from 0 to 200 do {_veh = "K03" createVehicle position player};

/*
{
	if ((str _x find "barrelwater_f.p3d") != -1) exitWith {player setPosATL(getPosATL _x)};
} forEach nearestObjects [position player,[],3000];

*/

/******** POST PROCESSING
[] spawn {
	_priority = 10;
	_fullBlur = [1];
	_noBlur = [0];
	_animSpeed = 2;
	
	_handle = ["dynamicBlur",_priority] call epoch_postProcessCreate; //create effect
	[_handle, _animSpeed, _fullBlur] call epoch_postprocessAdjust; //adds blur for 2 sec till max
	uiSleep _animSpeed;
	[_handle, _animSpeed, _noBlur] call epoch_postprocessAdjust; //removes blurr for 2 sec till min
	uiSleep _animSpeed;
	_handle call epoch_postprocessDestroy; //remove effect
};
**************************/

//("<img image='x\addons\rmx_init\data\critical.paa'/>") critical;

/******** 3D ctrl
disableSerialization;
_display = (findDisplay 46) createDisplay "rmx_rscObject";
_display displaySetEventHandler ["unload","rmx_var_3dCtrlSpin = false;"];
_ctrl = _display displayCtrl 77771;
_ctrl2 = _display ctrlCreate ["rmx_rscPicture",77772];
_ctrl2 ctrlSetText "#(rgb,8,8,3)color(1,1,1,0.1)";
_ctrl2 ctrlSetPosition [0,0,1,1];
_ctrl2 ctrlCommit 0;
_ctrl2 ctrlEnable true;
_ctrl2 ctrlSetEventHandler ["MouseMoving", "[_this,(findDisplay 77770) displayCtrl 77771] call Epoch_3DctrlYaw;"];
_ctrl2 ctrlSetEventHandler ["MouseEnter", "rmx_var_3dCtrlSpin = false;"];
_ctrl2 ctrlSetEventHandler ["MouseExit", "[(findDisplay 77770) displayCtrl 77771] call Epoch_3DctrlSpin;"];

_model1 = "\x\addons\a3_epoch_assets_1\models\chainsaw.p3d";
_model2 = "\x\addons\a3_epoch_vehicles\jetski.p3d";
_model3 = "\x\addons\a3_epoch_assets_3\cfgVehicles\Characters\female_ghillie.p3d";

_ctrl ctrlSetModel _model3;
_ctrl ctrlSetPosition [0.5, 1, 0.5];
_ctrl ctrlSetModelScale 0.5;
**************************/