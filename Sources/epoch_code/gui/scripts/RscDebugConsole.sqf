#include "\A3\ui_f\hpp\defineResincl.inc"
#include "\A3\ui_f\hpp\defineResinclDesign.inc"
#include "\A3\ui_f\hpp\defineDIKCodes.inc"

disableserialization;

_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

_allowDebugConsole = if (isnil "_allowDebugConsole") then {false} else {_allowDebugConsole};
_enableDebugConsole = ["DebugConsole",getnumber (missionconfigfile >> "enableDebugConsole")] call bis_fnc_getParamValue;

if (
	//--- Editor
	(((uinamespace getvariable "gui_displays") find (finddisplay 26) in [0,1]) && !ismultiplayer)
	||
	//--- In mission with enableDebugConsole entry set to 1 (only for host/admin)
	{(_enableDebugConsole == 1 && (isserver || serverCommandAvailable "#shutdown"))}
	||
	//--- In mission with enableDebugConsole entry set to 2 (for everyone)
	{(_enableDebugConsole == 2)}
	||
	//--- Allowed by script
	{_allowDebugConsole}
	//||
	//--- Dev version
	//cheatsEnabled
) then {

	switch _mode do {

		case "onLoad": {

			_display = _params select 0;

			_ctrlLink = _display displayctrl IDC_RSCDEBUGCONSOLE_LINK;
			_ctrlLink htmlLoad "a3\ui_f\data\html\RscDebugConsole.html";

			Epoch_Debug_GUI_onLoad = compileFinal ('true');
			
			//--- Set focus to expression field
			_ctrlExpression = _display displayctrl IDC_RSCDEBUGCONSOLE_EXPRESSION;
			_ctrlExpression ctrlsettext (profilenamespace getvariable ["RscDebugConsole_expression",""]);
			ctrlsetfocus _ctrlExpression;

			//--- Execute buttons
			RscDebugConsole_execute = {
				_args = _this select 0;
				_mode = _this select 1;

				_display = ctrlparent (_args select 0);
				_input = _display displayctrl IDC_RSCDEBUGCONSOLE_EXPRESSION;
				_inputValue = "";
				with missionnamespace do {
					_inputCode = compile ctrltext _input;
					switch _mode do {
						//--- Local
						case 0: {EPOCH_DebugGUI_exec = ["LOCAL",_inputCode];publicVariableServer "EPOCH_DebugGUI_exec"};
						//--- Global
						case 1: {EPOCH_DebugGUI_exec = ["GLOBAL",_inputCode];publicVariableServer "EPOCH_DebugGUI_exec"};
						//--- Server
						case 2: {EPOCH_DebugGUI_exec = ["SERVER",_inputCode];publicVariableServer "EPOCH_DebugGUI_exec"};
					};
				};
				true
			};

			_ctrlExecuteLocal = _display displayctrl IDC_OK;
			_ctrlExecuteLocal ctrladdeventhandler ["buttonclick","with uinamespace do {[_this,0] call RscDebugConsole_execute};"];

			_ctrlExecuteGlobal = _display displayctrl IDC_RSCDEBUGCONSOLE_BUTTONEXECUTEALL;
			_ctrlExecuteGlobal ctrladdeventhandler ["buttonclick","with uinamespace do {[_this,1] call RscDebugConsole_execute};"];

			_ctrlExecuteServer = _display displayctrl IDC_RSCDEBUGCONSOLE_BUTTONEXECUTESERVER;
			_ctrlExecuteServer ctrladdeventhandler ["buttonclick","with uinamespace do {[_this,2] call RscDebugConsole_execute};"];

			if !(ismultiplayer) then {
				_ctrlExecuteGlobal ctrlenable false;
				_ctrlExecuteServer ctrlenable false;
			};

			//--- Process watch fields
			RscDebugConsole_watchSave = [true,true,true,true];
			/*RscDebugConsole_watch = {
				_display = _this select 0;
				{
					_input = _display displayctrl (_x select 0);
					_output = _display displayctrl (_x select 1);
					_outputBackground = _display displayctrl (_x select 2);
					_backgroundColor = [0,0,0,0.7];
					_save = true;

					_inputValue = ctrltext _input;
					if (_inputValue != "") then {
						_timeStart = diag_ticktime;
						with missionnamespace do {
							_inputValue = if !(isnil {call compile _inputValue}) then {
								_timeStart = diag_ticktime;
								call compile _inputValue;
							} else {
								nil
							};
						};
						//--- Show warnign whn code is taking too long; also disable saving the value
						if (diag_ticktime - _timeStart > 0.003) then {
							_save = false;
							_backgroundColor = [0.5,0.25,0,0.7];
						};
						_inputValue = if !(isnil {_inputValue}) then {str _inputValue} else {""};
					};

					_output ctrlsettext _inputValue;

					_outputBackground ctrlsetbackgroundcolor _backgroundColor;
					_outputBackground ctrlcommit 0;
					RscDebugConsole_watchSave set [_foreachindex,_save];
				} foreach [
					[IDC_RSCDEBUGCONSOLE_WATCHINPUT1,IDC_RSCDEBUGCONSOLE_WATCHOUTPUT1,IDC_RSCDEBUGCONSOLE_WATCHOUTPUTBACKGROUND1],
					[IDC_RSCDEBUGCONSOLE_WATCHINPUT2,IDC_RSCDEBUGCONSOLE_WATCHOUTPUT2,IDC_RSCDEBUGCONSOLE_WATCHOUTPUTBACKGROUND2],
					[IDC_RSCDEBUGCONSOLE_WATCHINPUT3,IDC_RSCDEBUGCONSOLE_WATCHOUTPUT3,IDC_RSCDEBUGCONSOLE_WATCHOUTPUTBACKGROUND3],
					[IDC_RSCDEBUGCONSOLE_WATCHINPUT4,IDC_RSCDEBUGCONSOLE_WATCHOUTPUT4,IDC_RSCDEBUGCONSOLE_WATCHOUTPUTBACKGROUND4]
				];
			};
			_display displayaddeventhandler ["mousemoving","with uinamespace do {_this call RscDebugConsole_watch};"];
			_display displayaddeventhandler ["mouseholding","with uinamespace do {_this call RscDebugConsole_watch};"];
			*/

			//--- Load last values of watch fields
			{
				_input = _display displayctrl _x;
				_input ctrlsettext (profilenamespace getvariable ["RscDebugConsole_watch" + str(_foreachindex + 1),""]);
			} foreach [
				IDC_RSCDEBUGCONSOLE_WATCHINPUT1,
				IDC_RSCDEBUGCONSOLE_WATCHINPUT2,
				IDC_RSCDEBUGCONSOLE_WATCHINPUT3,
				IDC_RSCDEBUGCONSOLE_WATCHINPUT4
			];


			//--- External buttons
			_ctrlSpectatorCamera = _display displayctrl IDC_RSCDEBUGCONSOLE_BUTTONSPECTATORCAMERA;
			_ctrlSpectatorCamera ctrladdeventhandler ["buttonclick","if (isnil {RscSpectator_camera}) then {RscSpectator_allowFreeCam = true; cutrsc ['RscSpectator','plain'];} else {cuttext ['','plain']};"];

			_ctrlSplendidCamera = _display displayctrl IDC_RSCDEBUGCONSOLE_BUTTONSPLENDIDCAMERA;
			_ctrlSplendidCamera ctrladdeventhandler ["buttonclick","[] spawn (uinamespace getvariable 'bis_fnc_camera');"];

			_ctrlConfig = _display displayctrl IDC_RSCDEBUGCONSOLE_BUTTONCONFIG;
			_ctrlConfig ctrladdeventhandler ["buttonclick","[ctrlparent (_this select 0)] spawn (uinamespace getvariable 'bis_fnc_configViewer');"];

			_ctrlFunctions = _display displayctrl IDC_RSCDEBUGCONSOLE_BUTTONFUNCTIONS;
			_ctrlFunctions ctrladdeventhandler ["buttonclick","[ctrlparent (_this select 0)] spawn (uinamespace getvariable 'bis_fnc_help');"];

			_ctrlAnimations = _display displayctrl IDC_RSCDEBUGCONSOLE_BUTTONANIMATIONS;
			_ctrlAnimations ctrladdeventhandler ["buttonclick","[] spawn (uinamespace getvariable 'bis_fnc_animViewer');"];

			_ctrlGUI = _display displayctrl IDC_RSCDEBUGCONSOLE_BUTTONGUI;
			_ctrlGUI ctrladdeventhandler ["buttonclick","[] spawn bis_fnc_guiEditor;"];

			//--- Simulation is not running
			_splendidCameraOpened = if !(isnil "BIS_fnc_camera_display") then {!(isnull BIS_fnc_camera_display)} else {false};
			if (
				isnull ([] call (uinamespace getvariable "BIS_fnc_displayMission"))
				||	
				_splendidCameraOpened
			) then {
				{
					(_display displayctrl _x) ctrlenable false;
				} foreach [
					IDC_RSCDEBUGCONSOLE_BUTTONSPECTATORCAMERA,
					IDC_RSCDEBUGCONSOLE_BUTTONSPLENDIDCAMERA,
					IDC_RSCDEBUGCONSOLE_BUTTONANIMATIONS,
					IDC_RSCDEBUGCONSOLE_BUTTONGUI
				];
			};
		};

		case "onUnload": {
			_display = _params select 0;

			//--- Remember last values
			_ctrlExpression = _display displayctrl IDC_RSCDEBUGCONSOLE_EXPRESSION;
			profilenamespace setvariable ["RscDebugConsole_expression",ctrltext _ctrlExpression];

			{
				_input = _display displayctrl _x;
				_inputValue = if (RscDebugConsole_watchSave select _foreachindex) then {ctrltext _input} else {""};
				profilenamespace setvariable ["RscDebugConsole_watch" + str(_foreachindex + 1),_inputValue];
			} foreach [
				IDC_RSCDEBUGCONSOLE_WATCHINPUT1,
				IDC_RSCDEBUGCONSOLE_WATCHINPUT2,
				IDC_RSCDEBUGCONSOLE_WATCHINPUT3,
				IDC_RSCDEBUGCONSOLE_WATCHINPUT4
			];
			saveprofilenamespace;

			//--- Cleanup
			RscDebugConsole_execute = nil;
			RscDebugConsole_watch = nil;
			RscDebugConsole_watchSave = nil;
		};
	};
} else {
	switch _mode do {

		case "onLoad": {

			//--- Hdie and deactivate the console
			_ctrlConsole = _display displayctrl IDC_RSCDEBUGCONSOLE_RSCDEBUGCONSOLE;
			_ctrlConsole ctrlshow false;
			_ctrlConsole ctrlenable false;
		};
	};
};