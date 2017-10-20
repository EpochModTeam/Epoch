// init
_forceBloodRise = false;
_forceBloodDrop = false;
_forceFatigue = false;
_allowBloodDrop = false;
_forceStaminaDrop = false;
_playerBloodP = missionNamespace getVariable [_playerBloodPKey, _playerBloodPDefault];
_warnbloodPressure = _playerBloodP > 120;
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
	_selectedVar params [["_selVarName",""],["_selVarType",""],["_selVarSubData",""],["_extraLogicRaw",[]],["_selVarLimits",[]]];

	_varIndex = _customVarNames find _selVarName;
	if (_varIndex != -1 || !(_selVarLimits isEqualTo [])) then {
		if (_selVarLimits isEqualTo []) then {
			_selVarLimits = _customVarLimits select _varIndex;
		};
		_currentVarVal = [_selVarName,_varIndex,_selVarType,_selVarSubData] call EPOCH_fnc_returnHudVar;
		_selVarLimits params [["_playerLimitMax",100],["_playerLimitMin",0],["_playerWarnLimit",101],["_playerCriticalLimit",101],["_playerWarnLow",0],["_playerCriticalLow",0]];

		_extraLogic = false;
		if !(_extraLogicRaw isEqualTo []) then {
			_extraLogicRaw params [["_extraLogicType",""],["_extraLogicCond",""],["_extraLogicData",""]];
			_extraLogicVarName = "";
			_extraLogicDefaultValue = "";
			if (_extraLogicType isEqualType []) then {
				_extraLogicType params [["_extraLogicVarName",""],["_extraLogicType",""],["_extraLogicDefaultValue",""]];
			};
			_extraVarIndex = _customVarNames find _extraLogicVarName;
			_extraLogic = [([_extraLogicVarName,_extraVarIndex,_extraLogicType,_extraLogicDefaultValue] call EPOCH_fnc_returnHudVar),_extraLogicCond,_extraLogicData] call EPOCH_fnc_arrayToLogic;
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
				if ((_criticalAttributes param [0,""]) isEqualType []) then {
					_criticalAttributes = _criticalAttributes select _criticalLow;
				};
				_forceUpdate = "forceUpdate" in _criticalAttributes;
				_forceFatigue = "forceFatigue" in _criticalAttributes;
				_forceBloodRise = "forceBloodRise" in _criticalAttributes;
				_forceBloodDrop = "forceBloodDrop" in _criticalAttributes;
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
	_playerStamina = missionNamespace getVariable [_playerStaminaKey, _playerStaminaDefault];
	if (_playerStamina > 0 && !_panic) then {
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
	_playerBloodP = [_playerBloodPKey, 0.05, _playerBloodPMax , _playerBloodPMin] call EPOCH_fnc_setVariableLimited;
} else {
	if (_allowBloodDrop || _forceBloodDrop) then {
		// allow player to bleed out or die from hypothermia
		_lowerBPlimit = [100,0] select (isBleeding player || _forceBloodDrop);
		_playerBloodP = [_playerBloodPKey, -1, _playerBloodPMax , _lowerBPlimit] call EPOCH_fnc_setVariableLimited;
	};
};

// check if player On Foot
_isOnFoot = isNull objectParent player;
if (_isOnFoot) then {
	_val = log(abs(speed player));
	_staminaThreshold = [0.7,0.3] select (underwater player);
	if (_val > _staminaThreshold) then {
		_forceStaminaDrop = true;
	};
};

// Decrease Stamina
if (_forceStaminaDrop) then {
	_playerStamina = [_playerStaminaKey, -(_val/4), EPOCH_playerStaminaMax , 0] call EPOCH_fnc_setVariableLimited;
} else {
	// Increase Stamina if player is not Fatigued
	if (_increaseStamina && (getFatigue player) == 0) then {
		// EPOCH_playerStamina = (EPOCH_playerStamina + 0.5) min EPOCH_playerStaminaMax;
		_playerStamina = [_playerStaminaKey, 0.5, EPOCH_playerStaminaMax , 0] call EPOCH_fnc_setVariableLimited;
	};
};



// ~ debug
if (EPOCH_debugMode) then {
	private _hours = floor(servertime/60/60);
	private _customVars = "";
	{
		if !(_x in ["AliveTime","SpawnArray","HitPoints","MissionArray","NotUsed"]) then {
			private _varName = format["EPOCH_player%1",_x];
			private _varNameTmp = call compile format["_player%1Key",_x];
			if !(isNil "_varNameTmp") then {_varName = _varNameTmp};
			private _val = missionNamespace getVariable [_varName,_defaultVarValues select _forEachIndex];
			if (_x == "Temp") then {
				_customVars = _customVars + format["<t size='1.15' font='puristaLight' align='left'>%1: </t><t size='1.15' font='puristaLight' align='right'>%2°F | %3°C</t><br/>", _x,_val,_val call EPOCH_convertTemp];
			} else {
				_customVars = _customVars + format["<t size='1.15' font='puristaLight' align='left'>%1: </t><t size='1.15' font='puristaLight' align='right'>%2</t><br/>", _x,_val];
			};
		}
	}forEach _customVarNames;
	hintSilent parseText format ["
		<t size='1.25' font='puristaLight' align='center'>Welcome to Epoch!</t><br/>
		<t size='1.18' font='puristaLight' align='center'>Current Version: %1</t><br/>
		<t size='1.0' font='puristaLight' align='center'>Build: %2</t><br/>
		" + _customVars + "
		<t size='1.15' font='puristaLight' align='left'>Karma: </t><t size='1.15' font='puristaLight' align='right'>%17</t><br/>
		<br/>

		<t size='1.15' font='puristaLight' align='left'>Fatigue: </t><t size='1.15' font='puristaLight' align='right'>%3</t><br/>
		<t size='1.15' font='puristaLight' align='left'>Damage: </t><t size='1.15' font='puristaLight' align='right'>%4</t><br/>
		<t size='1.15' font='puristaLight' align='left'>Bleeding: </t><t size='1.15' font='puristaLight' align='right'>%5</t><br/>
		<t size='1.15' font='puristaLight' align='left'>Bleed Time: </t><t size='1.15' font='puristaLight' align='right'>%6</t><br/>
		<t size='1.15' font='puristaLight' align='left'>Oxygen: </t><t size='1.15' font='puristaLight' align='right'>%7</t><br/>
		<br/>
		<t size='1.15' font='puristaLight' align='left'>Air Temp: </t><t size='1.15' font='puristaLight' align='right'>%8</t><br/>
		<t size='1.15' font='puristaLight' align='left'>Water Temp: </t><t size='1.15' font='puristaLight' align='right'>%9</t><br/>
		<t size='1.15' font='puristaLight' align='left'>Rain: </t><t size='1.15' font='puristaLight' align='right'>%10</t><br/>
		<t size='1.15' font='puristaLight' align='left'>Overcast: </t><t size='1.15' font='puristaLight' align='right'>%11</t><br/>
		<br/>
		<t size='1.15' font='puristaLight' align='left'>Hours Alive: </t><t size='1.15' font='puristaLight' align='right'>%12</t><br/>
		<t size='1.15' font='puristaLight' align='left'>FPS: </t><t size='1.15' font='puristaLight' align='right'>%13</t><br/>
		<t size='1.15' font='puristaLight' align='left'>Server uptime: </t><t size='1.15' font='puristaLight' align='right'>%14h %15m</t><br/>
		<t size='1.15' font='puristaLight' align='left'>Server FPS: </t><t size='1.15' font='puristaLight' align='right'>%16</t><br/>",
		getText(configFile >> "CfgMods" >> "Epoch" >> "version"),
		getNumber(missionConfigFile >> "CfgEpochBuild" >> "build"),
		(getFatigue player),
		(damage player),
		(isBleeding player),
		(getBleedingRemaining player),
		(getOxygenRemaining player),
		format ["%1°F | %2°C",EPOCH_CURRENT_WEATHER,EPOCH_CURRENT_WEATHER call EPOCH_convertTemp],
		format ["%1°F | %2°C",(EPOCH_CURRENT_WEATHER/2),(EPOCH_CURRENT_WEATHER/2) call EPOCH_convertTemp],
		rain,
		overcast,

		round(_playerAliveTime/360)/10,
		round diag_fps,
		_hours,
		round((serverTime/60)-(_hours*60)),
		if (EPOCH_diag_fps isEqualType 0) then [{EPOCH_diag_fps},{"MANIPULATED"}],
		missionNamespace getVariable ["EPOCH_totalKarma",0]
	];
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

// AH use only
if !(isNil "EPOCH_GMODE") then {
	{
		_varDefault = _gModeVarValues select _foreachindex;
		_varName = format["EPOCH_player%1",_x];
		_varNameTmp = call compile format["_player%1Key",_x];
		if !(isNil "_varNameTmp") then {_varName = _varNameTmp};
		missionNamespace setVariable [_varName, _varDefault];
	} forEach _gModeVarNames;
};

// Update read only vars
if !(_playerTempKey isEqualTo "EPOCH_playerTemp") then {
	EPOCH_playerTemp = missionNamespace getVariable [_playerTempKey, _playerTempDefault];
	EPOCH_playerHunger = missionNamespace getVariable [_playerHungerKey, _playerHungerDefault];
	EPOCH_playerThirst = missionNamespace getVariable [_playerThirstKey, _playerThirstDefault];
	EPOCH_playerAliveTime = missionNamespace getVariable [_playerAliveTimeKey, _playerAliveTimeDefault];
	EPOCH_playerEnergy = missionNamespace getVariable [_playerEnergyKey, _playerEnergyDefault];
	EPOCH_playerWet = missionNamespace getVariable [_playerWetKey, _playerWetDefault];
	EPOCH_playerSoiled = missionNamespace getVariable [_playerSoiledKey, _playerSoiledDefault];
	EPOCH_playerImmunity = missionNamespace getVariable [_playerImmunityKey, _playerImmunityDefault];
	EPOCH_playerToxicity = missionNamespace getVariable [_playerToxicityKey, _playerToxicityDefault];
	EPOCH_playerStamina = missionNamespace getVariable [_playerStaminaKey, _playerStaminaDefault];
	EPOCH_playerBloodP = missionNamespace getVariable [_playerBloodPKey, _playerBloodPDefault];
	EPOCH_playerAlcohol = missionNamespace getVariable [_playerAlcoholKey, _playerAlcoholDefault];
	EPOCH_playerRadiation = missionNamespace getVariable [_playerRadiationKey, _playerRadiationDefault];
	EPOCH_playerNuisance = missionNamespace getVariable [_playerNuisanceKey, _playerNuisanceDefault];
};

// Check for PlayerMarker and Update or Remove it
_config = 'CfgMarkerSets' call EPOCH_returnConfig;
_markerArray = getArray(_config >> 'PlayerMarker' >> 'markerArray');
_markerName = (_markerArray select 0) select 0;

if(_markerName in allMapMarkers)then{
	if!('ItemGPS' in (assignedItems player))then{
		['PlayerMarker'] call EPOCH_fnc_deleteLocalMarkerSet;
		if(((getArray(_config >> 'DeathMarker' >> 'markerArray') select 0) select 0) in allMapMarkers)then{
			['DeathMarker'] call EPOCH_fnc_deleteLocalMarkerSet;
		};
	}else{
		{
			(_x select 0) setMarkerPosLocal (position player);
			if(count(_x) >= 8)then{(_x select 0) setMarkerTextLocal (call compile (_x select 7))};
		}forEach _markerArray;
	};
};
if(getNumber(('CfgEpochClient' call EPOCH_returnConfig) >> 'mapOnZoomSetMarkerSize') isEqualTo 1)then{
	if(visibleMap)then{
		_mapScale = ctrlMapScale ((findDisplay 12) displayCtrl 51);
		_mapMarkers = allMapMarkers;
		
		if(isNil {EPOCH_lastMapScale})then{EPOCH_lastMapScale = 0};
		
		if(_mapScale != EPOCH_lastMapScale)then{
			EPOCH_lastMapScale = _mapScale;
			for "_i" from 0 to ((count _mapMarkers) - 1) do {
				_zoomMarker = _mapMarkers select _i;
				private "_markerString";
				_markerString = toArray _zoomMarker;
				_markerString resize 6;
				if (toString _markerString == "EPOCH_") then {
					_mSize = missionNamespace getVariable[_zoomMarker,[0.8,0.8]];	
					_adjusted = _mapScale * 2.25;
					_sizeX = (((_mSize select 0) / _adjusted) min 2.333) max 0.666;
					_sizeY = (((_mSize select 1) / _adjusted) min 2.333) max 0.666;
					_zoomMarker setMarkerSizeLocal [_sizeX,_sizeY];
				};
			};
		};
	};
};

// force update
if (EPOCH_forceUpdateNow) then {
	EPOCH_forceUpdateNow = false;
	call _fnc_forceUpdate;
};
