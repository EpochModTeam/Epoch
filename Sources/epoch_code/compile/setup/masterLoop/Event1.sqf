// init
_forceUpdate = false;
_forceBloodRise = false;
_forceFatigue = false;
_allowBloodDrop = false;
_forceStaminaDrop = false;
_warnbloodPressure = EPOCH_playerBloodP > 120;
_increaseStamina = true;
_val = 0;

// AR HUD Target start
_currentTarget = objNull;
_currentTargetMode = 0;
_cursorTarget = ([10] call EPOCH_fnc_cursorTarget);
if (!isNull _cursorTarget && {!(EPOCH_target isEqualTo _cursorTarget)}) then {
	_interactType = typeOf _cursorTarget;
	_interaction = (_cfgObjectInteractions >> _interactType);
	if (isClass(_interaction)) then {
		_currentTargetMode = getNumber (_interaction >> "interactMode");
		_allowTarget = switch (getNumber (_interaction >> "aliveState")) do {
		    case 1: {!(alive _cursorTarget)};
			case 2: {(alive _cursorTarget)};
		    default {true};
		};
		if (_allowTarget) then {
			_currentTarget = _cursorTarget;
		};
	} else {
		// AllVehicles = vehicles=0, bases=1
		if (_cursorTarget isKindOf "AllVehicles") then {
			_currentTarget = _cursorTarget;
		} else {
			if (_cursorTarget isKindOf "Constructions_modular_F" || _cursorTarget isKindOf "Constructions_static_F") then {
				_currentTargetMode = 1;
				_currentTarget = _cursorTarget;
			};
		};
	};
};
EPOCH_currentTarget = _currentTarget;
EPOCH_currentTargetMode = _currentTargetMode;
// AR HUD target end

// dynamic HUD start
{
	_x params [["_selectedVar",[]],["_HUDclass","topRight"],["_ctrlText",""],["_criticalAttributes",[]]];
	_selectedVar params [["_selVarName",""],["_selVarType",""],["_selVarSubData",""],["_extraLogicRaw",[]],["_customVarLimits",[]]];

	_varIndex = EPOCH_customVars find _selVarName;
	if (_varIndex != -1 || !(_customVarLimits isEqualTo [])) then {
		if (_customVarLimits isEqualTo []) then {
			_customVarLimits = EPOCH_customVarLimits select _varIndex;
		};
		_currentVarVal = [_selVarName,_varIndex,_selVarType,_selVarSubData] call _fnc_returnHudVar;
		_customVarLimits params [["_playerLimitMax",100],["_playerLimitMin",0],["_playerWarnLimit",101],["_playerCriticalLimit",101],["_playerWarnLow",0],["_playerCriticalLow",0]];

		_extraLogic = false;
		if !(_extraLogicRaw isEqualTo []) then {
			_extraLogicRaw params [["_extraLogicType",""],["_extraLogicCond",""],["_extraLogicData",""]];
			_extraLogicVarName = "";
			_extraLogicDefaultValue = "";
			if (_extraLogicType isEqualType []) then {
				_extraLogicType params [["_extraLogicVarName",""],["_extraLogicType",""],["_extraLogicDefaultValue",""]];
			};
			_extraVarIndex = EPOCH_customVars find _extraLogicVarName;
			_extraLogic = [([_extraLogicVarName,_extraVarIndex,_extraLogicType,_extraLogicDefaultValue] call _fnc_returnHudVar),_extraLogicCond,_extraLogicData] call _fnc_arrayToLogic;
		};

		if (_playerLimitMax isEqualType "") then {
			_playerLimitMax = missionNamespace getVariable [_playerLimitMax, 0];
		};
		if (_playerLimitMin isEqualType "") then {
			_playerLimitMin = missionNamespace getVariable [_playerLimitMin, 0];
		};

		_warnLow = _currentVarVal < _playerWarnLow;
		_warnHigh = _currentVarVal > _playerWarnLimit;
		_criticalLow = _currentVarVal <= _playerCriticalLow;
		_criticalHigh = _currentVarVal >= _playerCriticalLimit;

		if (_warnHigh || _warnLow || _extraLogic) then {
			_hudIndex = missionNamespace getVariable [format["EPOCH_dynHUD_%1",_HUDclass],1];
			_curCtrl = [_HUDclass,_hudIndex] call epoch_getHUDCtrl;
			missionNamespace setVariable [format["EPOCH_dynHUD_%1",_HUDclass], _hudIndex + 1];
			if (_ctrlText isEqualType []) then {
				_ctrlText = if (_warnHigh) then {_ctrlText select 0} else {_ctrlText select 1};
			};
			_curCtrl ctrlSetText _ctrlText;
			_critical = (_criticalHigh || _criticalLow);
			if (_critical) then {
				_forceUpdate = "forceUpdate" in _criticalAttributes;
				_forceFatigue = "forceFatigue" in _criticalAttributes;
				_forceBloodRise = "forceBloodRise" in _criticalAttributes;
                [_curCtrl,0.55] call epoch_2DCtrlHeartbeat;
			};
			// todo make this reversable or even limited to a color range.
			_color = [_playerLimitMin,_playerLimitMax,_currentVarVal,1] call EPOCH_colorRange;
			_curCtrl ctrlSetTextColor _color;
		};
	};
} forEach _hudConfigs;
// dynamic HUD end

// cause Fatigue if cold or hot, also increase blood pressure if thristy or hungry.
if (_forceBloodRise || _forceFatigue) then {
	_increaseStamina = false;
} else {
	if (EPOCH_playerStamina > 0 && !_panic) then {
		_allowBloodDrop = true;
	};
};

// force Fatigue
if (_forceFatigue) then {
	player setFatigue 1;
} else {
	if (!_warnbloodPressure) then {
		player setFatigue 0;
	};
};

// force Blood Pressure Rise
if (_forceBloodRise) then {
	EPOCH_playerBloodP = (EPOCH_playerBloodP + 0.05) min 190;
} else {
	if (_allowBloodDrop) then {
		// allow player to bleed out
		_lowerBPlimit = [100,0] select (isBleeding player);
		EPOCH_playerBloodP = EPOCH_playerBloodP - 1 max _lowerBPlimit;
	};
};

// check if player On Foot
if (isNull objectParent player) then {
	_val = log(abs(speed player));
	_staminaThreshold = [0.7,0.3] select EPOCH_playerIsSwimming;
	if (_val > _staminaThreshold) then {
		_forceStaminaDrop = true;
	};
};

// Decrease Stamina
if (_forceStaminaDrop) then {
	EPOCH_playerStamina = (EPOCH_playerStamina - (_val/4)) max 0;
} else {
	// Increase Stamina if player is not Fatigued
	if (_increaseStamina && (getFatigue player) == 0) then {
		EPOCH_playerStamina = (EPOCH_playerStamina + 0.5) min EPOCH_playerStaminaMax;
	};
};

// force update
if (_forceUpdate) then {
	true call EPOCH_pushCustomVar;
};

// ~ debug
if (EPOCH_debugMode) then {
	call EPOCH_debugMonitor;
};

// player to player trade loop
call EPOCH_TradeLoop;

// blank out unused hud elements and prepare for next loop
_hudIndex = missionNamespace getVariable [format["EPOCH_dynHUD_%1","topRight"],1];
for "_i" from _hudIndex to 9 do {
    _c = ["topRight",_i] call epoch_getHUDCtrl;
    _c ctrlSetText "";
};
missionNamespace setVariable [format["EPOCH_dynHUD_%1","topRight"], nil];

// EPOCH TraderMissions
if (!isnil "EPOCH_ResetTraderMission") then {
	if (!isNil "EPOCH_taskMarker") then{
		EPOCH_taskMarker params ["_mkrName","_taskMarkerVis"];
		[player,_taskMarkerVis,_mkrName] remoteExec ["EPOCH_server_removeMarker",2];
		EPOCH_taskMarker = nil;
	};
	if !(_EPOCH_TraderMissionArray isequalto []) then {
		_EPOCH_TraderMissionArray params ["_mainblock"];
		_mainblock params ["","","","","",["_missionCleanUpCall",""]];
		call _missionCleanUpCall;
	};
	EPOCH_ActiveTraderMission = [];
	_EPOCH_TraderMissionArray = [];
	_LastMissionTrigger = 0;
	["Mission sucessfully resettet", 5] call Epoch_message;
	EPOCH_ResetTraderMission = nil;
};

if !(EPOCH_ActiveTraderMission isequalto []) then {
	if (_EPOCH_TraderMissionArray isequalto []) then {
		_EPOCH_TraderMissionArray = EPOCH_ActiveTraderMission call _EPOCH_BuildTraderMisson;
	};
	_EPOCH_TraderMissionArray params ["_mainblock","_taskDelay","_triggerintervall","_taskDialogues","_taskEvents","_taskFailed","_taskComplete"];
	if (diag_ticktime < _taskDelay) exitwith {};
	if (diag_ticktime < _LastMissionTrigger + _triggerintervall) exitwith {};
	_LastMissionTrigger = diag_ticktime;
	_mainblock params ["_inGameTasksconfig","_taskName","_unit","_taskItem","_taskTitle","_missionCleanUpCall","_taskCleanup"];
	_taskComplete params ["_taskCompleteCond","_taskReward","_taskCompleteDiags","_taskCompleteCall","_taskNextTrigger"];
	_taskFailed params ['_taskFailedCond','_taskFailTime','_taskFailedDiags','_taskFailedSQF','_taskFailedCall'];
	if (diag_ticktime > _taskFailTime || call _taskFailedCond) exitwith {
		if (count _taskFailedDiags > 0) then {
			_diag = selectRandom _taskFailedDiags;
			[format ["%1",_diag], 5] call Epoch_message;
		};
		if !(_taskFailedSQF isequalto '') then {
			call compile format ["[_taskName,_plyr,_unit,_taskItem] execVM ""%1""",_taskFailedSQF];
		};
		if !(str(_taskFailedCall) == "{}") then {
			call _taskFailedCall;
		};
		if (!isNil "EPOCH_taskMarker") then{
			EPOCH_taskMarker params ['_mkrName','_taskMarkerVis'];
			[player,_taskMarkerVis,_mkrName] remoteExec ["EPOCH_server_removeMarker",2];
			EPOCH_taskMarker = nil;
		};
		call _missionCleanUpCall;
		EPOCH_ActiveTraderMission = [];
		_EPOCH_TraderMissionArray = [];
		_LastMissionTrigger = 0;
	};
	if (call _taskCompleteCond) exitwith {
		if (count _taskCompleteDiags > 0) then {
			_diag = selectrandom _taskCompleteDiags;
			[format ["%1",_diag], 5] call Epoch_message;
		};
		if(count _taskReward > 0) then {
			[player,Epoch_personalToken,_taskReward,[],objNull,false] remoteExec ["EPOCH_Server_createObject",2];
		};
		if !(str(_taskCompleteCall) == "{}") then {
			call _taskCompleteCall;
		};
		if (_taskCleanup isequalto 1) then {
			if (!isNil "EPOCH_taskMarker") then{
				EPOCH_taskMarker params ['_mkrName','_taskMarkerVis'];
				[player,_taskMarkerVis,_mkrName] remoteExec ["EPOCH_server_removeMarker",2];
				EPOCH_taskMarker = nil;
			};
			call _missionCleanUpCall;
		};
		if (count _taskNextTrigger > 0) then {
			_nexttask = selectrandom _taskNextTrigger;
			_EPOCH_TraderMissionArray = [_inGameTasksconfig,_nexttask] call _EPOCH_BuildTraderMisson;
		}
		else {
			EPOCH_ActiveTraderMission = [];
			_EPOCH_TraderMissionArray = [];
		};
		_LastMissionTrigger = 0;
	};
	{
		_x params ["_taskEventCond","_taskEventCALL","_taskEventTasks"];
		if (call _taskEventCond) exitwith {
			call _taskEventCALL;
			if (count _taskEventTasks > 0) exitwith {
				_task = selectrandom _taskEventTasks;
				_EPOCH_TraderMissionArray = [_inGameTasksconfig,_task] call _EPOCH_BuildTraderMisson;
			};
			_taskEvents deleteat _foreachindex;
		};
	} foreach _taskEvents;
	{
		_x params ['_taskDiagCond','_taskDiag'];
		if (call _taskDiagCond) exitwith {
			_diag = selectRandom _taskDiag;
			if !(_diag isequalto "") then {
				[format ["%1",_diag], 5] call Epoch_message;
			};
			_taskDialogues deleteat _foreachindex;
		};
	} foreach _taskDialogues;
};
