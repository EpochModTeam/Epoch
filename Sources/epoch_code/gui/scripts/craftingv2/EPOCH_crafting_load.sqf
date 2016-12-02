/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors:

	Description:
	DESC-TBA

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/scripts/craftingv2/EPOCH_crafting_load.sqf
*/
if (rmx_var_craftingENABLED) exitWith {false};

createDialog "rmx_craftingUI";
_this spawn {
    private ["_in","_cfg","_3DCTRL","_recipeCTRL","_recipeConfigs"];

    disableSerialization;

    _in = param [0,""];

    waitUntil {!isNull findDisplay 77700};
    call EPOCH_crafting_ctrl_collector;

    //Var defs
    rmx_var_craftQTY = 0;
    rmx_var_craftQTYOut = 0;
    rmx_var_craftInProgress = false;

    //Defines
    _cfg = 'CfgCrafting' call EPOCH_returnConfig;

    _cfg call EPOCH_crafting_colorScheme;

    _3DCTRL = rmx_var_crafting_ctrl_DEVMisc select 0;
    _recipeCTRL = rmx_var_crafting_ctrl_main select 0;

    //First Launch
    _recipeConfigs = "true" configClasses _cfg;
    _recipeConfigs deleteRange [0,6]; //delete main templates as they are not real items

    rmx_var_crafting_FullConfigData = _recipeConfigs call EPOCH_crafting_getConfig;
    rmx_var_crafting_SearchConfigData = rmx_var_crafting_FullConfigData;

    [_3DCTRL] call Epoch_3DctrlSpin;
    _3DCTRL ctrlEnable false;

    call EPOCH_crafting_LB_defaults; //Default state

    //Basic EH setup
    if (getNumber (_cfg >> "DeveloperMode") > 0) then {
    	private "_ctrlDevMain";
    	_ctrlDevMain = rmx_var_crafting_ctrl_DEVMisc select 1;
    	_ctrlDevMain ctrlEnable true;
    	_ctrlDevMain ctrlShow true;
    };
    rmx_var_crafting_progressClicked = false;

    ctrlSetFocus _recipeCTRL;

    //puts arguments into search field
    if (_in isEqualType "STRING") then {
    	if (count _in > 0) then { //required, empty string crashes game for some reason
    		(rmx_var_crafting_ctrl_Interact select 4) ctrlSetText _in;
    	};
    };

    //Post Processing
    rmx_var_crafting_PP_CC = ["colorCorrections",11] call epoch_postProcessCreate;
    rmx_var_crafting_PP_DB = ["dynamicBlur",11] call epoch_postProcessCreate;

    [rmx_var_crafting_PP_CC, 0, [1,1,0,0,0,0,1,0,0,0,1,0,0,0,0,1,1,0,0,0,0.296494,1]] call epoch_postprocessAdjust;
    [rmx_var_crafting_PP_DB, 1, [1]] call epoch_postprocessAdjust;

    //Custom textures


    //Manages quantity slider
    [] spawn {
    	private ["_pos","_txt"];
    	while {rmx_var_craftingLOOPS} do {
    		_pos = progressPosition (rmx_var_crafting_ctrl_Interact select 2);
    		rmx_var_craftQTYOut = round (_pos * rmx_var_craftQTY);
    		_txt = format ["[%1/%2]",rmx_var_craftQTYOut,rmx_var_craftQTY];
    		(rmx_var_crafting_ctrl_Interact select 3) ctrlSetText _txt;
    	};
    };

    //Search box
    [] spawn {
    	disableSerialization;
    	private ["_searchCTRL","_searchTextTEMP"];
    	_searchCTRL = rmx_var_crafting_ctrl_Interact select 4;
    	_searchTextTEMP = "";


    	while {rmx_var_craftingLOOPS} do {

    		uiSleep 0.5; //speed of search, should be less or equal to unload delay

    		if !(_searchTextTEMP isEqualTo (ctrlText _searchCTRL)) then {
    			rmx_var_crafting_SearchConfigData = [];
    			{
    				_idx = toLower(_x select 1) find toLower (ctrlText _searchCTRL);
    				if !(_idx isEqualTo -1) then {
    					rmx_var_crafting_SearchConfigData pushBack _x;
    				};
    			} forEach rmx_var_crafting_FullConfigData;

    			_searchTextTEMP = ctrlText _searchCTRL;
    			call EPOCH_crafting_LB_defaults;
    			(rmx_var_crafting_ctrl_main select 0) lbSetCurSel 0;
    			ctrlSetFocus _searchCTRL;
    		};
    	};
    };

    //Craft button states
    [] spawn {
    	private ["_btn","_btn_cancel","_btn_craft","_btn_close"];
    	disableSerialization;
    	_btn = rmx_var_crafting_ctrl_Interact select 0;
    	_btn ctrlEnable true;

    	_btn_cancel = rmx_var_crafting_colorScheme select 0;
    	_btn_craft = rmx_var_crafting_colorScheme select 1;
    	_btn_close = rmx_var_crafting_colorScheme select 2;

    	while {rmx_var_craftingLOOPS} do {
    		uiSleep 0.1;

    		if (rmx_var_craftInProgress) then {
    			_btn ctrlSetText _btn_cancel;
    		} else {
    			if (rmx_var_craftQTYOut > 0) then {
    				_btn ctrlSetText _btn_craft;
    			} else {
    				_btn ctrlSetText _btn_close;
    			};
    		}
    	};
    };

    [] spawn {
    	private "_pos";
    	_pos = position player;
    	while {rmx_var_craftingLOOPS} do {
    		if ((_pos distance (position player)) > 1) exitWith {closeDialog 0;};
    	};
    };
};
true
