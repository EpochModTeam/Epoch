createDialog "rmx_traderUI";
_dsp = findDisplay 55500;

//_slider progressSetPosition 1;
rmx_var_traderCategories= ["All","Air1","Air2","Land1","Land2","Land3","Ship","Terminal"];
_clrScheme = call Epoch_getColorScheme;

rmx_var_tradeCtrls = [];

for "_i" from 55600 to 55620 do {
	rmx_var_tradeCtrls pushBack (_dsp displayCtrl _i);
};

{
	_idxL = (rmx_var_tradeCtrls select 5) lbAdd _x;
	_idxR = (rmx_var_tradeCtrls select 8) lbAdd _x;
	(rmx_var_tradeCtrls select 5) lbSetCurSel  0;
	(rmx_var_tradeCtrls select 8) lbSetCurSel  0;	
} count ["No Sorting", "Alphabet", "Price: Low", "Price: High"];


_leftCategories = ["Gear", "Nearby", "Vehicle Gear", "Owned Vehicles"]; //make multidimensional with pics

rmx_var_traderLeftMenuCTRLs = [];
_leftCtrlGroup = _dsp ctrlCreate ["rmx_rscControlsGroup", call epoch_getIDC];
_leftCtrlGroup ctrlSetPosition [-0.2,0,0.2,1];
_leftCtrlGroup ctrlCommit 0;

for "_i" from 0 to (count _leftCategories)-1 do {
	_LBG = _dsp ctrlCreate ["RscPicture", call epoch_getIDC,_leftCtrlGroup];
	_LIcon = _dsp ctrlCreate ["RscPicture", call epoch_getIDC,_leftCtrlGroup];
	_LText = _dsp ctrlCreate ["RscText", call epoch_getIDC,_leftCtrlGroup];
	rmx_var_traderLeftMenuCTRLs pushBack [_LBG, _LIcon, _LText];
	
	_displayName = (_leftCategories select _i);
	_LText ctrlEnable true; //create rsctext with EH in configs
	_LText ctrlSetEventHandler ["mouseEnter", format ["(_this select 0) ctrlSetTextColor %1",_clrScheme]];
	_LText ctrlSetEventHandler ["mouseExit", format ["(_this select 0) ctrlSetTextColor %1",[1,1,1,1]]];
	_LText ctrlSetEventHandler ["MouseButtonUp", format ["['left', 'click', '%1'] call Epoch_tradeMouseEvents;",_displayName]];
	
	_LBG ctrlSetText "x\addons\rmx_sandbox\epoch\trader_menu_v2\tradebg.paa";
	_LIcon ctrlSetText "x\addons\rmx_sandbox\epoch\trader_menu_v2\trade_placeholder.paa";
	_LText ctrlSetText _displayName;
	
	_LBG ctrlSetPosition [0.14,_i * 0.06,0.06,0.06];
	_LBG ctrlCommit 0;

	_LText ctrlSetPosition [0.05,_i * 0.06,0.15,0.06];
	_LText ctrlSetFade 1;
	_LText ctrlCommit 0;
	
	_LIcon ctrlSetPosition [0.15,_i * 0.06 + 0.012,0.0375,0.04];
	_LIcon ctrlCommit 0;
};



_mainCategories = "true" configClasses ("CfgPricing2" call EPOCH_returnConfig);

rmx_var_RCatConfigs = [];
{
	rmx_var_RCatConfigs append ("true" configClasses _x);
} count _mainCategories;

rmx_var_traderRightMenuCTRLs = [];
_rightCtrlGroup = _dsp ctrlCreate ["rmx_rscControlsGroup", call epoch_getIDC];
_rightCtrlGroup ctrlSetPosition [1,0,0.2,1];
_rightCtrlGroup ctrlCommit 0;

_cnt = 0;
{
	if (configName _x in rmx_var_traderCategories) then {
		_RBG = _dsp ctrlCreate ["RscPicture", call epoch_getIDC,_rightCtrlGroup];
		_RIcon = _dsp ctrlCreate ["RscPicture", call epoch_getIDC,_rightCtrlGroup];
		_RText = _dsp ctrlCreate ["RscText", call epoch_getIDC,_rightCtrlGroup];
		rmx_var_traderRightMenuCTRLs pushBack [_RBG, _RIcon, _RText];
		
		_displayName = (getText (_x >> "displayName"));
		_RText ctrlEnable true;
		_RText ctrlSetEventHandler ["mouseEnter", format ["(_this select 0) ctrlSetTextColor %1",_clrScheme]];
		_RText ctrlSetEventHandler ["mouseExit", format ["(_this select 0) ctrlSetTextColor %1",[1,1,1,1]]];
		_RText ctrlSetEventHandler ["MouseButtonUp", format ["['right', 'click', '%1'] call Epoch_tradeMouseEvents;",_displayName]];
		
		_RBG ctrlSetText "x\addons\rmx_sandbox\epoch\trader_menu_v2\tradebg.paa";
		_RIcon ctrlSetText (getText (_x >> "picture"));
		_RText ctrlSetText _displayName;
		
		_RBG ctrlSetPosition [0,_cnt * 0.06,0.06,0.06];
		_RBG ctrlCommit 0;

		_RText ctrlSetPosition [0,_cnt * 0.06,0.15,0.06];
		_RText ctrlSetFade 1;
		_RText ctrlCommit 0;
		
		_RIcon ctrlSetPosition [0.01,_cnt * 0.06 + 0.012,0.0375,0.04];
		_RIcon ctrlCommit 0;
		
		_cnt = _cnt + 1;
	};
} forEach rmx_var_RCatConfigs;

rmx_var_traderGroupCTRLs = [_leftCtrlGroup, _rightCtrlGroup];

rmx_var_traderMenuActive = true;

[] spawn epoch_tradeMainLoop;

["right","All"] call epoch_tradePopulateLB;

/*
	0	left trigger
	1 	right trigger
	2	left BG
	3	right BG
	4	left LB
	5 	left CB
	6	left search
	7	right LB	
	8	right CB
	9	right search
	10	desc pic
	11	desc descShort
	12	transaction LB
	13	desc left ST
	14	desc right ST
	15	desc multiline ST
	16	hide BG
	17	hide progress
	18	hide edit
	19	hide btn ok
	20	hide btn X	
*/