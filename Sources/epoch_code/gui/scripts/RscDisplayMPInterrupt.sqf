#include "\A3\ui_f\hpp\defineCommonGrids.inc"

_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

#include "RscDebugConsole.sqf"
#include "RscFeedback.sqf"

switch _mode do {

	case "onLoad": {

		private ['_dummy'];
		_dummy = ['Init', _params] execVM '\A3\ui_f\scripts\pauseLoadinit.sqf';
		
		//Hide chat
		showChat false;

		//--- Disable message box
		(_display displayctrl 235106) ctrlenable false;
		(_display displayctrl 235107) ctrlenable false;
		
		//--- set player's name
		(_display displayctrl 109) ctrlSetText profileName;
		[_display, 109] call (uinamespace getvariable 'BIS_fnc_setIDCStreamFriendly');
		
		//Sets all texts toUpper
		["RscDisplayMPInterrupt",["RscText","RscTitle"],["PlayersName"]] call bis_fnc_toUpperDisplayTexts;
		
		//Variable for tracking state of Options accordion (expanded/collapsed)
		uiNamespace setVariable ["BIS_DisplayInterrupt_isOptionsExpanded", false];

		//--- Respawn button
		_buttonRespawn = _display displayctrl 1010;
		_cfgRespawnButton = missionconfigfile >> "respawnButton";
		_respawnButton = if (isnumber _cfgRespawnButton) then {getnumber _cfgRespawnButton} else {-1};
		_cfgRespawnType = missionconfigfile >> "respawn";
		_respawnType = if (istext _cfgRespawnType) then {
			 ["none","bird","instant","base","group","side"] find (tolower gettext _respawnType);
		} else {
			if (isnumber _cfgRespawnType) then {getnumber _cfgRespawnType} else {-1};
		};
		//--- Disable in missions without respawn, when player is virtual, or when mission designer chose to
		if ((_respawnType in [-1,0,1] && _respawnButton != 1) || _respawnButton == 0 || side group player == sidelogic) then {
			_buttonRespawn ctrlenable false;
		};
		_buttonRespawn ctrlseteventhandler ["buttonclick","with uinamespace do {['buttonRespawn',_this,''] spawn RscDisplayMPInterrupt_script;}; true"];

		//--- Options button
		_button = _display displayctrl 101;
		_button ctrladdeventhandler ["buttonclick","with uinamespace do {['optionsButton',_this,''] spawn RscDisplayMPInterrupt_script};"];
		
		//TODO - implementovat promennou, ktera si bude pamatovat stav akordeonu (je potreba pri navratu z jineho dialogu do main menu)			
		(_display displayctrl 301) ctrlSetFade 1;	//Video
		(_display displayctrl 302) ctrlSetFade 1;	//Audio
		(_display displayctrl 303) ctrlSetFade 1;	//Controls
		(_display displayctrl 307) ctrlSetFade 1;	//Game Options
		
		(_display displayctrl 301) ctrlCommit 0;
		(_display displayctrl 302) ctrlCommit 0;
		(_display displayctrl 303) ctrlCommit 0;
		(_display displayctrl 307) ctrlCommit 0;
		
		//--- Hide all buttons from Options - must be here to enable proper focusing
		(_display displayctrl 301) ctrlEnable false;	//Video
		(_display displayctrl 302) ctrlEnable false;	//Audio
		(_display displayctrl 303) ctrlEnable false;	//Controls
		(_display displayctrl 307) ctrlEnable false;	//Game Options
	};
	
		//--- Options button
	case "optionsButton": {

		_ctrl = _params select 0;
		_display = ctrlparent _ctrl;		
		
		//if options are expanded (Video Options button is shown), collapse it and vice versa
		//if (ctrlFade (_display displayCtrl 301) < 0.5) then
		_upperPartTime = 0.2; //0.05 for each button
		_buttonsTime = 0.05;
		
		if (uiNamespace getvariable "BIS_DisplayInterrupt_isOptionsExpanded") then
		{
			//hide buttons and collapse accordion
			//move down - background, title, player's name, play, editor, profile, options
			
			//Title background
			_control = _display displayctrl 1050;
			_control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (14.2 * GUI_GRID_H + GUI_GRID_Y)];																													
			_control ctrlCommit _upperPartTime;
			
			//Title - same position as title background
			_control = _display displayctrl 523;
			_control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (14.2 * GUI_GRID_H + GUI_GRID_Y)];
			_control ctrlCommit _upperPartTime;
			
			//Player's name - same position as title background
			_control = _display displayctrl 109;
			_control ctrlSetPosition [(6 * GUI_GRID_W + GUI_GRID_X), (14.2 * GUI_GRID_H + GUI_GRID_Y)];
			_control ctrlCommit _upperPartTime;
			
			//Continue button
			_control = _display displayctrl 2;
			_control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (15.3 * GUI_GRID_H + GUI_GRID_Y)];
			_control ctrlCommit _upperPartTime;
			
			//Save button
			_control = _display displayctrl 103;
			_control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (16.4 * GUI_GRID_H + GUI_GRID_Y)];
			_control ctrlCommit _upperPartTime;
			
			//Skip button - same position as Save
			_control = _display displayctrl 1002;
			_control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (16.4 * GUI_GRID_H + GUI_GRID_Y)];
			_control ctrlCommit _upperPartTime;
			
			//Respawn
			_control = _display displayctrl 1010;
			_control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (17.5 * GUI_GRID_H + GUI_GRID_Y)];
			_control ctrlCommit _upperPartTime;
			
			//Options button
			_control = _display displayctrl 101;
			_control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (18.6 * GUI_GRID_H + GUI_GRID_Y)];
			_control ctrlCommit _upperPartTime;
			
			
			(_display displayctrl 301) ctrlSetFade 1;		//Video
			(_display displayctrl 302) ctrlSetFade 1;		//Audio
			(_display displayctrl 303) ctrlSetFade 1;		//Controls
			(_display displayctrl 307) ctrlSetFade 1;		//Game Options
			
			(_display displayctrl 301) ctrlCommit _buttonsTime;	//Video
			uiSleep _buttonsTime;
			(_display displayctrl 302) ctrlCommit _buttonsTime;	//Audio
			uiSleep _buttonsTime;
			(_display displayctrl 303) ctrlCommit _buttonsTime;	//Controls
			uiSleep _buttonsTime;
			(_display displayctrl 307) ctrlCommit _buttonsTime;	//Game
			
			(_display displayctrl 301) ctrlEnable false;		//Video
			(_display displayctrl 302) ctrlEnable false;		//Audio
			(_display displayctrl 303) ctrlEnable false;		//Controls
			(_display displayctrl 307) ctrlEnable false;		//Game Options
			
			uiNamespace setVariable ["BIS_DisplayInterrupt_isOptionsExpanded", false];
			//set focus to Options button
			ctrlSetFocus (_display displayctrl 101);	
		}
		else
		{
			//expand accordion and show buttons
			
			//Title background
			_control = _display displayctrl 1050;
			_control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (9.8 * GUI_GRID_H + GUI_GRID_Y)];
			_control ctrlCommit _upperPartTime;
			
			//Title - same position as title background
			_control = _display displayctrl 523;
			_control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (9.8 * GUI_GRID_H + GUI_GRID_Y)];
			_control ctrlCommit _upperPartTime;
			
			//Player's name - same position as title background
			_control = _display displayctrl 109;
			_control ctrlSetPosition [(6 * GUI_GRID_W + GUI_GRID_X), (9.8 * GUI_GRID_H + GUI_GRID_Y)];
			_control ctrlCommit _upperPartTime;
			
			//Continue button
			_control = _display displayctrl 2;
			_control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (10.9 * GUI_GRID_H + GUI_GRID_Y)];
			_control ctrlCommit _upperPartTime;
			
			//Save button
			_control = _display displayctrl 103;
			_control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (12 * GUI_GRID_H + GUI_GRID_Y)];
			_control ctrlCommit _upperPartTime;
			
			//Skip button - same position as Save
			_control = _display displayctrl 1002;
			_control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (12 * GUI_GRID_H + GUI_GRID_Y)];
			_control ctrlCommit _upperPartTime;
			
			//Respawn
			_control = _display displayctrl 1010;
			_control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (13.1 * GUI_GRID_H + GUI_GRID_Y)];
			_control ctrlCommit _upperPartTime;
			
			//Options button
			_control = _display displayctrl 101;
			_control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (14.2 * GUI_GRID_H + GUI_GRID_Y)];
			_control ctrlCommit _upperPartTime;	


			//Enable and show buttons
			(_display displayctrl 301) ctrlEnable true;	//Video
			(_display displayctrl 302) ctrlEnable true;	//Audio
			(_display displayctrl 303) ctrlEnable true;	//Controls
			(_display displayctrl 307) ctrlEnable true;	//Game Options
			
			//--- Show all buttons from Options
			(_display displayctrl 301) ctrlSetFade 0;	//Video
			(_display displayctrl 302) ctrlSetFade 0;	//Audio
			(_display displayctrl 303) ctrlSetFade 0;	//Controls
			(_display displayctrl 307) ctrlSetFade 0;	//Game Options
			
			uiSleep 0.05;
			
			//From bottom to top
			(_display displayctrl 307) ctrlCommit 0.15;	//Game
			uiSleep _buttonsTime;
			(_display displayctrl 303) ctrlCommit 0.15;	//Controls
			uiSleep _buttonsTime;
			(_display displayctrl 302) ctrlCommit 0.15;	//Audio
			uiSleep _buttonsTime;
			(_display displayctrl 301) ctrlCommit 0.15;	//Video		
			
			uiNamespace setVariable ["BIS_DisplayInterrupt_isOptionsExpanded", true];
			//set focus to Options button
			ctrlSetFocus (_display displayctrl 101);
		};
	};

	case "buttonRespawn": {
		_display = ctrlparent (_params select 0);
		_respawn = [localize "str_a3_rscdisplaympinterrupt_respawnprompt",nil,localize "STR_DISP_INT_RESPAWN",true,_display,true] call bis_fnc_guiMessage; //--- ToDo: Localize
		if (_respawn) then {
			if (alive player) then {
				//player setdamage 1;
			};
			_display closedisplay 2;
		};
	};

	case "onUnload": {
		private ["_dummy"];
		//Show chat only if Stream Friendly UI is off
		if (!isStreamFriendlyUIEnabled) then
		{
			showChat true;
		};
		_dummy = ['Unload', _params] call compile preprocessFile '\A3\ui_f\scripts\pauseOnUnload.sqf';
	};
	default {};
};