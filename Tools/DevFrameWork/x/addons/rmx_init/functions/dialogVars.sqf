/*
	Function Name:			rmx_fnc_dialogVars
	Author:					Raimonds Virtoss | Raymix
	Description:			Variable defines used for currently developed functions or debugging. 
	
							This function is recompiled and called during preInit
	
	License:				---
*/
#include <\x\Addons\rmx_init\defines.inc>

rmx_var_logMsg = []; 
rmx_var_logBufferSize = 200;
rmx_var_logBuffer = [];
rmx_var_logsweepcycle = 0.01;

"Use Shift + F2 to open console as a display with ability to click buttons" warning;

rmx_var_quickFnc_items = [[[0,1,0,1],"Example","call doSTUFF;"]];

//Default dialog toggle state defines
if (isNil "rmx_var_consoleEnabled") then {rmx_var_consoleEnabled = false;};
if (isNil "rmx_var_quickFncEnabled") then {rmx_var_quickFncEnabled = false;};
if (isNil "rmx_var_atmosFearEnabled") then {rmx_var_atmosFearEnabled = false;};
if (isNil "rmx_var_ppViewerEnabled") then {rmx_var_ppViewerEnabled = false;};
if (isNil "rmx_var_editorControl") then {rmx_var_editorControl = false;};
if (isNil "rmx_var_watcherControl") then {rmx_var_watcherControl = false;};
if (isNil "rmx_var_watcherPinned") then {rmx_var_watcherPinned = false;};

//gather default saved variables for console state from profile namespace (checkbox selection and console size)
rmx_var_consoleSetting = profileNamespace getVariable ["rmx_var_consoleSetting",0];
rmx_var_consoleCBstate = profileNamespace getVariable ["rmx_var_consoleCBstate",[true,true,true,false]];
rmx_var_consoleCheckbox_info = rmx_var_consoleCBstate select 0;
rmx_var_consoleCheckbox_warnings = rmx_var_consoleCBstate select 1;
rmx_var_consoleCheckbox_critical = rmx_var_consoleCBstate select 2;
rmx_var_consoleCheckbox_pause = rmx_var_consoleCBstate select 3;

//generate structured array for console early to avoid problems
if (isNil "rmx_var_console_list") then {
	rmx_var_console_list = []; rmx_var_console_list resize 40;
	for "_i" from 0 to 39 do {
		rmx_var_console_list set [_i,(text "")];
	};
};

/* -------------------- PP VIEWER -------------------- */
rmx_var_ppCatMain = [];
rmx_var_ppCatCC = [];
rmx_var_ppCatCCV = [];
rmx_var_ppCatCA = [];
rmx_var_ppCatFG = [];
rmx_var_ppCatRB = [];
rmx_var_ppCatWD = [];
rmx_var_ppCatDB = [];
rmx_var_ppCatCI = [];
rmx_var_ppTemplate = [["colorCorrections",1501],["chromAberration",201],["filmGrain",2001],["radialBlur",101],["wetdistortion",301],["dynamicBlur",401],["colorInversion",2501]];
rmx_var_ppSelected = 0;
rmx_var_ppiSelected = 0;

rmx_var_ppCcPos = [1,1,0,0,0,0,0,0,0,0,1,0,0,0,0];
rmx_var_ppCcvPos = [0,0,0,0,0,0,0];
rmx_var_ppCaPos = [0,0,false];
rmx_var_ppFgPos = [0,0,1,0,0,false];
rmx_var_ppRbPos = [0,0,0,0];
rmx_var_ppWdPos = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0];
rmx_var_ppDbPos = [0];
rmx_var_ppCiPos = [0,0,0];

with profileNamespace do {
	if !(isNil "rmx_var_ppLoadSave") then {
		if (rmx_var_ppLoadSave isEqualTo []) then {rmx_var_ppLoadSave = nil};
	};
};
rmx_var_ppLoadSave = profileNamespace getVariable ["rmx_var_ppLoadSave",[[0,"Nothing saved",[1,1,0,0,0,0,0,0,0,0,1,0,0,0,0]]]];
rmx_var_ppHandles = [];
{
	private "_hndl";
	_hndl = ppEffectCreate [(_x select 0),(_x select 1)];
	_hndl ppEffectEnable false;
	rmx_var_ppHandles set [count rmx_var_ppHandles,_hndl]; //pushBack suddenly started giving error
} forEach rmx_var_ppTemplate;
//profileNamespace setVariable ["rmx_var_ppLoadSave",nil]; //deletes profileNS var

/* -------------------- AtmosFEAR -------------------- */
rmx_var_afProgress = [];
rmx_var_afInput = [];
rmx_var_afSliders = [];
rmx_var_afMisc = [];
rmx_var_afText = [];
rmx_var_afSelected = 0;

with profileNamespace do {
	if !(isNil "rmx_var_afLoadSave") then {
		if (rmx_var_afLoadSave isEqualTo []) then {rmx_var_afLoadSave = nil};
	};
};
rmx_var_afProfile = profileNamespace getVariable ["rmx_var_afProfile",[0,0,0,0,[0,0],[0,[0,0,0]],[0,0],[0,0],[0,0],[0,0],[0,0,false]]];
rmx_var_afLoadSave = profileNamespace getVariable ["rmx_var_afLoadSave",[["Nothing saved",[]]]];

/* -------------------- Code Editor -------------------- */
rmx_var_ctrl_editorContentFade = profileNamespace getVariable ["rmx_var_ctrl_editorContentFade",0];
rmx_var_editorIndex = profileNamespace getVariable ["rmx_var_editorIndex",1];
rmx_var_ctrl_editorTabContent = profileNamespace getVariable ["rmx_var_ctrl_editorTabContent",["", "", "", "", "", "", "", "", ""]];

/* -------------------- Variable Watcher -------------------- */
if (isNil "rmx_var_watcher_running") then {rmx_var_watcher_running = false;};
if (isNil "rmx_var_watcherGrpControls") then {rmx_var_watcherGrpControls = []};
rmx_var_watcherGrpControls_data = profileNamespace getVariable ["rmx_var_watcherGrpControls_data",[]];


true
