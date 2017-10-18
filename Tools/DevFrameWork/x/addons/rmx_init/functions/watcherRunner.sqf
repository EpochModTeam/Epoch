if (rmx_var_watcher_running) exitWith {false};
rmx_var_watcher_running = true;

disableSerialization;
_fnc_findDisplay = {
	_isPinned = uiNamespace getVariable ["rmx_var_watcher2",displayNull];
	_display = if (_isPinned isEqualTo displayNull) then {
		findDisplay 7500
	} else {
		_isPinned
	};
	_display
};

_scheme = call Epoch_getColorScheme;

while {str(call _fnc_findDisplay) isEqualTo "Display #7500"} do
{
	{
		if !(rmx_var_watcherGrpControls isEqualTo []) then {
			_var = _x select 0;
			_idx = _x select 1;
			_ctrl = rmx_var_watcherGrpControls select _forEachIndex select 2;
			if !(isNil "_ctrl") then {
				switch _idx do {
					case 0: //code
					{	
						_compiled = nil;
						_compiled = call compile _var;
						if !(isNil "_compiled") then {
							_ctrl ctrlSetText (str _compiled);
							_ctrl ctrlSetTextColor [1,1,1,1];
						} else {
							_ctrl ctrlSetText "Syntax Error!";
							_ctrl ctrlSetTextColor [1,0,0,1];
						};
						
					};
					case 1: //bool
					{
						_compiled = nil;
						_compiled = call compile _var;
						if !(isNil "_compiled") then {
							if (_compiled isEqualType true) then {
								if (_compiled) then {
									_ctrl ctrlSetText "x\addons\rmx_init\data\w_on.paa";
									_ctrl ctrlSetTextColor _scheme;
									_ctrl ctrlEnable true;
								} else {
									_ctrl ctrlSetText "x\addons\rmx_init\data\w_off.paa";
									_ctrl ctrlSetTextColor [1,1,1,1];
								};
							} else {
								_ctrl ctrlSetText "x\addons\rmx_init\data\w_error.paa";
								_ctrl ctrlSetTextColor [1,0,0,1];
							};
						} else {
							_ctrl ctrlSetText "x\addons\rmx_init\data\w_error.paa";
							_ctrl ctrlSetTextColor [1,0,0,1];
						};
					};
					case 2: //progress
					{
						_compiled = nil;
						_compiled = call compile _var;
						if !(isNil "_compiled") then {
							if (_compiled isEqualType 0) then {
								if (_compiled <= 1 && _compiled >= 0) then {
									_ctrl progressSetPosition _compiled;
									_ctrl ctrlSetTextColor [1,1,1,1];
								} else {
									_ctrl progressSetPosition 1;
									_ctrl ctrlSetTextColor [1,0,0,1];
								};
							} else {
								_ctrl progressSetPosition 1;
								_ctrl ctrlSetTextColor [1,0,0,1];
							};
						} else {
							_ctrl progressSetPosition 1;
							_ctrl ctrlSetTextColor [1,0,0,1];
						};
					};
					case 3: //mission
					{	
						_variable = missionNamespace getVariable [_var,"nil"];
						_ctrl ctrlSetText (str _variable);
						if (_variable isEqualTo "nil") then {
							_ctrl ctrlSetTextColor [1,0,0,1];
						} else {
							_ctrl ctrlSetTextColor [1,1,1,1];
						};
					};
					case 4: //ui
					{
						_variable = uiNamespace getVariable [_var,"nil"];
						_ctrl ctrlSetText (str _variable);
						if (_variable isEqualTo "nil") then {
							_ctrl ctrlSetTextColor [1,0,0,1];
						} else {
							_ctrl ctrlSetTextColor [1,1,1,1];
						};
					};
					case 5: //profileName
					{
						_variable = profileNamespace getVariable [_var,"nil"];
						_ctrl ctrlSetText (str _variable);
						if (_variable isEqualTo "nil") then {
							_ctrl ctrlSetTextColor [1,0,0,1];
						} else {
							_ctrl ctrlSetTextColor [1,1,1,1];
						};
					};
				};
			};
		};
	} forEach rmx_var_watcherGrpControls_data;
	uiSleep 0.1;
};

rmx_var_watcher_running = false;
true
