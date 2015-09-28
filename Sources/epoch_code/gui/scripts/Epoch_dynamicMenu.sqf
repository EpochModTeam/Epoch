//TODO: read key press from global var (profileNamespace config)
//TODO: admin choice to use missionConfigFile
//TODO: (Ask team) suffix code to close dialog when button pressed
//TODO: unlimited categories
//TODO: functionize var Defines, do check before button action
//TODO: nil before closing display
//TODO: add commented out dialog version to display
//TODO: add cooldown
//TODO: prevent from opening and instantly close if known display is on

if !(isNil "rmx_var_dynamicMenuInProgress") exitWith {};
if (isNil "rmx_var_dynamicMenuCat") then {rmx_var_dynamicMenuCat = "";};


if (rmx_var_dynamicMenuCat isEqualTo "" && !isNil "rmx_var_dynamicMenuHOLD") exitWith {};

private ["_display","_cfg","_cat","_buttonSettings","_configs","_subclasses","_action","_entries","_img","_img2","_center","_defaultScaleX","_defaultScaleY","_distance","_scaleLargeX","_scaleLargeY","_scaleSmallX","_scaleSmallY","_scaleSelectedX","_scaleSelectedY","_points","_positions","_positions2","_positions3","_x","_y"];
disableSerialization;

rmx_var_dynamicMenuInProgress = true; //needed to suspend button spam, removed later

_display = (findDisplay 46) createDisplay "rmx_dynamenu";
_display displaySetEventHandler ["keyUp", "[false,_this select 1] call Epoch_dynamicMenuCleanup;"];

//TODO: config choice based on global variable or dynamic config update (slower)
_cfg = configFile;

/** Variable Defines **/
{
	call compile (format ["%1 = %2;",configName _x,getText _x]);
} count (configProperties [(_cfg >> "cfgDynamicMenu" >> "variableDefines"),"true",false]);

_cat = if (rmx_var_dynamicMenuCat isEqualTo "") then {
		(_cfg >> "cfgDynamicMenu" >> "dynaButtons")
	} else {
		(_cfg >> "cfgDynamicMenu" >> "dynaButtons" >> rmx_var_dynamicMenuCat)
	};

/** Button configs **/
_buttonSettings = [];

_configs = "true" configClasses (_cat);
{
	if (call compile (getText(_x >> "condition"))) then {
	
		_subclasses = configProperties [_x, "isClass _x",true];
		
		_action = if (_subclasses isEqualTo []) then {
			compile (format ["%1",getText(_x >> "action")])
		} else {
			compile (format ["[true,57] call Epoch_dynamicMenuCleanup; rmx_var_dynamicMenuCat = '%1'; %2",(configName _x),getText(_x >> "action")])
		};
		//diag_log _action;
		_buttonSettings pushBack [
			getText(_x >> "icon"),
			getText(_x >> "tooltip"),
			_action
		];
	};
} forEach _configs;

_entries = count _buttonSettings;
if (_entries <= 0) exitWith {rmx_var_tabmenu = true; rmx_var_dynamicMenuInProgress = nil;};

//Post processing
if (isNil "rmx_var_dynamenuPPHandle") then {
	rmx_var_dynamenuPPHandle = ["dynamicBlur",10] call epoch_postProcessCreate;
	[rmx_var_dynamenuPPHandle, 1, [1]] call epoch_postprocessAdjust;
};

_img = "#(rgb,8,8,3)color(0,0,0,0)";
_img2 = "x\addons\a3_epoch_code\Data\UI\buttons\dm_selection.paa";

//defaults don't edit
_center = 0.5;
_defaultScaleX = 0.4;
_defaultScaleY = 0.5;
_distance = 0.7 + _entries / 100;

//edit scaling here (divisor only, larger values produce smaller image)
_scaleLargeX = _defaultScaleX / (1.5 + _entries / 10); //anim invisible
_scaleLargeY = _defaultScaleY / (1.5 + _entries / 10);
_scaleSmallX = _defaultScaleX / (2.5 + _entries / 10); //icons
_scaleSmallY = _defaultScaleY / (2.5 + _entries / 10);
_scaleSelectedX = _defaultScaleX / (1.75 + _entries / 10); //anim selected
_scaleSelectedY = _defaultScaleY / (1.75 + _entries / 10);

_points = 360 / _entries;

_positions = [];
_positions2 = [];
_positions3 = [];
for "_p" from 0 to 360 step _points do {

	_x = cos _p * (0.3 * _distance);
	_y = sin _p * (0.4 * _distance);
	
	_positions pushBack [_x + (_center - (_scaleLargeX / 2)),_y + (_center - (_scaleLargeY / 2)),_scaleLargeX,_scaleLargeY];
	_positions2 pushBack [_x + (_center - (_scaleSmallX / 2)),_y + (_center - (_scaleSmallY / 2)),_scaleSmallX,_scaleSmallY];
	_positions3 pushBack [_x + (_center - (_scaleSelectedX / 2)),_y + (_center - (_scaleSelectedY / 2)),_scaleSelectedX,_scaleSelectedY];
};

rmx_var_controls = [];
//_buttonSettings [icon,tooltip,action]
for "_e" from 0 to (_entries - 1) do {
	private ["_ctrl","_ctrl2"];
	_ctrl = _display ctrlCreate ["rmx_rscPicture",(66600 + _e)];
	_ctrl ctrlSetText _img;
	_ctrl ctrlSetPosition (_positions select _e);
	_ctrl ctrlCommit 0.1;
	_ctrl ctrlSetTooltip (_buttonSettings select _e select 1);
	
	_ctrl ctrlSetTooltipColorBox [0, 0, 0, 0];
	_ctrl ctrlSetTooltipColorShade [0, 0, 0, 0];
	_ctrl ctrlSetEventHandler ["mouseEnter", (format ["_c = _this select 0; _c ctrlSetText '%1'; _c ctrlSetPosition %2; _c ctrlCommit 0.3;",_img2,(_positions3 select _e)])];
	_ctrl ctrlSetEventHandler ["mouseExit", (format ["_c = _this select 0; _c ctrlSetText '%1'; _c ctrlSetPosition %2; _c ctrlCommit 0.3;",_img,(_positions select _e)])];
	_ctrl ctrlSetEventHandler ["mouseButtonDown", (format ["call %1;",(_buttonSettings select _e select 2)])];
	_ctrl ctrlEnable true;
	
	_ctrl2 = _display ctrlCreate ["rmx_rscPicture",-(66600 + _e)];
	_ctrl2 ctrlSetTooltip (_buttonSettings select _e select 1);
	_ctrl2 ctrlSetTooltipColorBox [0, 0, 0, 0];
	_ctrl2 ctrlSetTooltipColorShade [0, 0, 0, 0];
	_ctrl2 ctrlSetText (_buttonSettings select _e select 0);
	_ctrl2 ctrlSetPosition (_positions2 select _e);
	_ctrl2 ctrlCommit 0.1;
	
	rmx_var_controls pushBack _ctrl;
	rmx_var_controls pushBack _ctrl2;
};

/** Variable Cleanup **/
{
	call compile (format ["%1 = nil;",configName _x]);
} count (configProperties [(_cfg >> "cfgDynamicMenu" >> "variableDefines"),"true",false]);
rmx_var_dynamicMenuInProgress = nil;
rmx_var_dynamicMenuCat = "";
true
