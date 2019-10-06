// make sure we wait for Display #46
waitUntil {!isNull (findDisplay 46) && (!isNil "EPOCH_loadingScreenDone")};

// load favBar
'load' spawn epoch_favBar_draw;

// force update within 15 seconds
EPOCH_forceUpdate = false;
_forceUpdate = false;
// force update within 1 second
EPOCH_forceUpdateNow = false;

// start alive timer
_clientAliveTimer = diag_tickTime;

// Fade Black Screen
_fadedblack = false;
_UnFadeCheck = {
	if(_fadedblack) then {
		[] spawn {
			uisleep 1.5;
			TitleText ['','PLAIN DOWN'];
		};
		_fadedblack = false;
	};
};

// init player stat vars
_gmVarsInit = ["CfgEpochClient", "gmVars", [["Temp",98.6],["Hunger",500],["Thirst",500],["Toxicity",0],["Stamina",10],["BloodP",100],["Alcohol",0],["Radiation",0]]] call EPOCH_fnc_returnConfigEntryV2;
_gModeVarNames = _gmVarsInit apply {_x param [0,""]};
_gModeVarValues = _gmVarsInit apply {_x param [1,0]};

_customVarsInit = ["CfgEpochClient", "customVarsDefaults", EPOCH_customVarsDefaults] call EPOCH_fnc_returnConfigEntryV2;
_customVarNames = _customVarsInit apply {_x param [0,""]};
_defaultVarValues = _customVarsInit apply {_x param [1,0]};
_customVarLimits = _customVarsInit apply {_x param [2,[]]};

(_customVarLimits select (_customVarNames find "Temp")) params [["_playerTempMax",100],["_playerTempMin",0]];
(_defaultVarValues select (_customVarNames find "Temp")) params [["_playerTempDefault",0]];
(_customVarLimits select (_customVarNames find "Hunger")) params [["_playerHungerMax",100],["_playerHungerMin",0]];
(_defaultVarValues select (_customVarNames find "Hunger")) params [["_playerHungerDefault",0]];
(_customVarLimits select (_customVarNames find "Thirst")) params [["_playerThirstMax",100],["_playerThirstMin",0]];
(_defaultVarValues select (_customVarNames find "Thirst")) params [["_playerThirstDefault",0]];
(_customVarLimits select (_customVarNames find "Energy")) params [["_playerEnergyMax",100],["_playerEnergyMin",0]];
(_defaultVarValues select (_customVarNames find "Energy")) params [["_playerEnergyDefault",0]];
(_customVarLimits select (_customVarNames find "Wet")) params [["_playerWetMax",100],["_playerWetMin",0]];
(_defaultVarValues select (_customVarNames find "Wet")) params [["_playerWetDefault",0]];
(_customVarLimits select (_customVarNames find "Soiled")) params [["_playerSoiledMax",100],["_playerSoiledMin",0]];
(_defaultVarValues select (_customVarNames find "Soiled")) params [["_playerSoiledDefault",0]];
(_customVarLimits select (_customVarNames find "Immunity")) params [["_playerImmunityMax",100],["_playerImmunityMin",0]];
(_defaultVarValues select (_customVarNames find "Immunity")) params [["_playerImmunityDefault",0]];
(_customVarLimits select (_customVarNames find "Toxicity")) params [["_playerToxicityMax",100],["_playerToxicityMin",0]];
(_defaultVarValues select (_customVarNames find "Toxicity")) params [["_playerToxicityDefault",0]];
(_customVarLimits select (_customVarNames find "Stamina")) params [["_playerStaminaMax",100],["_playerStaminaMin",0]];
(_defaultVarValues select (_customVarNames find "Stamina")) params [["_playerStaminaDefault",0]];
(_customVarLimits select (_customVarNames find "BloodP")) params [["_playerBloodPMax",100],["_playerBloodPMin",0]];
(_defaultVarValues select (_customVarNames find "BloodP")) params [["_playerBloodPDefault",0]];
(_customVarLimits select (_customVarNames find "Alcohol")) params [["_playerAlcoholMax",100],["_playerAlcoholMin",0]];
(_defaultVarValues select (_customVarNames find "Alcohol")) params [["_playerAlcoholDefault",0]];
(_customVarLimits select (_customVarNames find "Radiation")) params [["_playerRadiationMax",100],["_playerRadiationMin",0]];
(_defaultVarValues select (_customVarNames find "Radiation")) params [["_playerRadiationDefault",0]];
(_customVarLimits select (_customVarNames find "Nuisance")) params [["_playerNuisanceMax",100],["_playerNuisanceMin",0]];
(_defaultVarValues select (_customVarNames find "Nuisance")) params [["_playerNuisanceDefault",0]];

(_defaultVarValues select (_customVarNames find "AliveTime")) params [["_playerAliveTimeDefault",0]];
(_defaultVarValues select (_customVarNames find "HitPoints")) params [["_playerHitPointsDefault",0]];
(_defaultVarValues select (_customVarNames find "SpawnArray")) params [["_playerSpawnArrayDefault",0]];
(_defaultVarValues select (_customVarNames find "MissionArray")) params [["_playerMissionArrayDefault",0]];

// push inital vars to new gvars
{
	_varDefault = _defaultVarValues select _foreachindex;
	_varName = format["EPOCH_player%1",_x];
	_varNameTmp = call compile format["_player%1Key",_x];
	if !(isNil "_varNameTmp") then {_varName = _varNameTmp};
	missionNamespace setVariable [_varName, missionNamespace getVariable [format["EPOCH_player%1",_x], _varDefault]];
} forEach _customVarNames;
missionNamespace setVariable [call compile "_playerRandomVarKey", round (diag_tickTime + random 99999)];

// only changed within this loop
_playerAliveTime = missionNamespace getVariable [_playerAliveTimeKey, _playerAliveTimeDefault];

// init Energy Max
EPOCH_playerEnergyMax = _playerEnergyMax;

// inline function to sync player stats to server
_fnc_forceUpdate = {
	private _customVars = [];
	{
		private _varName = format["EPOCH_player%1",_x];
		private _varNameTmp = call compile format["_player%1Key",_x];
		if !(isNil "_varNameTmp") then {_varName = _varNameTmp};
		_customVars pushBack (missionNamespace getVariable [_varName,_defaultVarValues select _foreachindex]);
	} forEach _customVarNames;
	_stats = [
		["WalkDist",round _TotalWalkDist,true],
		["MaxAliveTime",_MaxAliveTime,true],
		["PlayTime", round _PlayTime, true],
		["PublicStats",missionnamespace getvariable ["EPOCH_totalPublicStats",1], true]
	];
	[player,_customVars,Epoch_personalToken,_stats,_UpdateTopStats] remoteExec ["EPOCH_fnc_savePlayer",2];
	_UpdateTopStats = false;
};

// disable fuel sources client side.
{_x setFuelCargo 0;} foreach (missionNamespace getVariable ["EPOCH_staticFuelSources", []]);

// setup display EH's
if (isNil "EPOCH_display_setup_complete") then {
	EPOCH_display_setup_complete = true;
	{
		(findDisplay 46) displayAddEventHandler [_x,(["CfgEpochClient", _x, ""] call EPOCH_fnc_returnConfigEntryV2)];
	} forEach (["CfgEpochClient", "displayAddEventHandler", []] call EPOCH_fnc_returnConfigEntryV2);
	// reset anim state
	player switchMove "";
	// setup Epoch Hud
	call epoch_dynamicHUD_start;
};

player setVariable["BIS_noCoreConversations", true];

// Background radiation
_outOfBoundsRadiation = ["CfgEpochClient", "outOfBoundsRadiation", 10] call EPOCH_fnc_returnConfigEntryV2;
_radsLevel = 0;
// Radiation screen effects threshold
_radiationEffectsThreshold = ["CfgEpochClient", "radiationEffectsThreshold", 10] call EPOCH_fnc_returnConfigEntryV2;

_prevEquippedItem = [];
_damagePlayer = damage player;
_isOnFoot = isNull objectParent player;
_panic = false;
_prevEnergy = missionNamespace getVariable [_playerEnergyKey, _playerEnergyDefault];

_EPOCH_Autorunspeed = 1;
// init config data
_antagonistRndChance = ["CfgEpochClient", "antagonistRngChance", 100] call EPOCH_fnc_returnConfigEntryV2;

_LootCleanupTime = ["CfgBuildingLootPos", "LootCleanupTime", 300] call EPOCH_fnc_returnConfigEntryV2;
_baseRadiationLoss = ["CfgEpochClient", "baseRadiationLoss", -0.1] call EPOCH_fnc_returnConfigEntryV2;
_baseRadiationLossImmunityPenalty = ["CfgEpochClient", "baseRadiationLossImmunityPenalty", -0.1] call EPOCH_fnc_returnConfigEntryV2;
_baseHungerLoss = ["CfgEpochClient", "baseHungerLoss", 2] call EPOCH_fnc_returnConfigEntryV2;
_baseThirstLoss = ["CfgEpochClient", "baseThirstLoss", 2] call EPOCH_fnc_returnConfigEntryV2;
_baseAlcoholLoss = ["CfgEpochClient", "baseAlcoholLoss", 0.17] call EPOCH_fnc_returnConfigEntryV2;
_lossMultiplier = if (["CfgEpochClient", "accelerateHTALoss", true] call EPOCH_fnc_returnConfigEntryV2) then {timeMultiplier} else {1};
_energyCostNV = ["CfgEpochClient", "energyCostNV", 3] call EPOCH_fnc_returnConfigEntryV2;
_energyPowerSources = ["CfgEpochClient", "energyPowerSources", ["Land_spp_Tower_F","Land_wpp_Turbine_V2_F","Land_wpp_Turbine_V1_F","SolarGen_EPOCH","Land_Wreck_Satellite_EPOCH"]] call EPOCH_fnc_returnConfigEntryV2;
_energyRegenInVeh = ["CfgEpochClient", "energyChargeInVeh", 5] call EPOCH_fnc_returnConfigEntryV2;
_energyRegenMax = ["CfgEpochClient", "energyRegenMax", 5] call EPOCH_fnc_returnConfigEntryV2;
_energyRange = ["CfgEpochClient", "energyRange", 75] call EPOCH_fnc_returnConfigEntryV2;
_hudConfigs = ["CfgEpochClient", "hudConfigs", []] call EPOCH_fnc_returnConfigEntryV2;
_radioactiveLocations = ["CfgEpochClient", "radioactiveLocations", ["NameCityCapital", "NameCity", "Airport"]] call EPOCH_fnc_returnConfigEntryV2;
_radiatedObjMaxRange = ["CfgEpochClient", "radiatedObjMaxFalloutDist", 75] call EPOCH_fnc_returnConfigEntryV2;
_PlayerMarkerArray = getArray(('CfgMarkerSets' call EPOCH_returnConfig) >> 'PlayerMarker' >> 'markerArray');
_PlayerMarkerName = (_PlayerMarkerArray param [0,[]]) param [0,"EPOCH_PlayerMarker1"];
_DeathMarkerName = ((getArray (('CfgMarkerSets' call EPOCH_returnConfig) >> 'DeathMarker' >> 'markerArray')) param [0,[]]) param [0,"EPOCH_DeathMarker1"];
_mapOnZoomSetMarkerSize = ["CfgEpochClient", "mapOnZoomSetMarkerSize", 0] call EPOCH_fnc_returnConfigEntryV2;
_PlayerMarkerEnabled = (["CfgEpochClient", "playerLocationMarkerGPSOnly", 0] call EPOCH_fnc_returnConfigEntryV2) isequalto 1;
_DeathMarkerEnabled = (["CfgEpochClient", "playerDeathMarkerGPSOnly", 0] call EPOCH_fnc_returnConfigEntryV2) isequalto 1;
_DeathMarker = profileNameSpace getVariable ['EPOCHLastKnownDeath',[]];
_chargeRate = 0;

_antagonistChanceDefaults = [
	"Epoch_Cloak_F",0.07,
	"Epoch_Sapper_F",0.25,
	"Epoch_SapperG_F",0.12,
	"Epoch_SapperB_F",0.06,
	"I_UAV_01_F",0.2,
	"PHANTOM",0.01,
	"EPOCH_RyanZombie_1",0.25
];
_antagonistChances = ["CfgEpochClient", "antagonistChances", _antagonistChanceDefaults] call EPOCH_fnc_returnConfigEntryV2;


// Init antagonist spawn limits
_spawnIndex = [];
_spawnLimits = [];
_antagonistSpawnDefaults = [
	["Epoch_Cloak_F", 1],
	["GreatWhite_F", 2],
	["Epoch_Sapper_F",2],
	["Epoch_SapperG_F",1],
	["Epoch_SapperB_F",1],
	["I_UAV_01_F",2],
	["PHANTOM",1],
	["B_Heli_Transport_01_F",1],
	["EPOCH_RyanZombie_1",12]
];
_antagonistSpawnLimits = ["CfgEpochClient", "antagonistSpawnIndex", _antagonistSpawnDefaults] call EPOCH_fnc_returnConfigEntryV2;

_mod_Ryanzombies_Enabled = missionNamespace getVariable ["EPOCH_mod_Ryanzombies_Enabled",false];
{
	_x params ["_spawnName","_spawnLimit"];
	if (_spawnName isEqualTo "EPOCH_RyanZombie_1") then {
		if (_mod_Ryanzombies_Enabled) then {
			_spawnIndex pushBack _spawnName;
			_spawnLimits pushBack _spawnLimit;
		};
	} else {
		_spawnIndex pushBack _spawnName;
		_spawnLimits pushBack _spawnLimit;
	};
} forEach _antagonistSpawnLimits;

EPOCH_spawnIndex = _spawnIndex;
EPOCH_spawnLimits = _spawnLimits;

// default data if mismatch
_playerSpawnArray = missionNamespace getVariable [_playerSpawnArrayKey, _playerSpawnArrayDefault];
if !(_playerSpawnArray isEqualTypeParams _spawnIndex) then{
	_playerSpawnArray = [];
	{ _playerSpawnArray pushBack 0 } forEach _spawnIndex;
};
missionNamespace setVariable [_playerSpawnArrayKey, _playerSpawnArray];

// find radio
{
	if (configName(inheritsFrom(configFile >> "CfgWeapons" >> _x)) == "ItemRadio") exitWith{
		EPOCH_equippedItem_PVS = [_x, true, player];
	};
} forEach assignedItems player;

// lootBubble Init
_masterConfig = 'CfgBuildingLootPos' call EPOCH_returnConfig;

_lootClasses = [];
_lootClassesIgnore = ['Default'];
'_cN = configName _x;if !(_cN in _lootClassesIgnore)then{_lootClasses pushBackUnique (toLower _cN)}; true' configClasses _masterConfig;

_lastPlayerPos = getPosATL player;
_lastPlayerPos2 = getPosATL player;
_TotalWalkDist = missionnamespace getvariable ["EPOCH_totalWalkDist",0];
_MaxAliveTime = missionnamespace getvariable ["EPOCH_totalMaxAliveTime",0];
_PlayTime = missionnamespace getvariable ["EPOCH_totalPlayTime",0];
_PlayTimeTimer = diag_ticktime;
_UpdateTopStats = false;
EPOCH_MyStatsPublic = !((missionnamespace getvariable ["EPOCH_totalPublicStats",1]) isEqualTo 0);

_lootBubble = {
	private["_jammer", "_others", "_objects", "_nearObjects", "_building", "_lootDist", "_lootLoc", "_playerPos", "_distanceTraveled","_AddBias","_dir","_minlootdist","_maxlootdist"];
	if (!alive player) exitwith {};
	if (speed vehicle player > 30) exitwith {};
	_playerPos = getPosATL vehicle player;
	if (_lastPlayerPos distance2D _playerPos < 30) exitwith {};
	_lastPlayerPos = _playerPos;
	if (missionnamespace getvariable ["InSafeZone",false]) exitwith {};
	_objects = (player nearObjects ["Building", 60]) select {
		!((_x getvariable ["Epoch_LastLootCheck",-10000]) > (diag_ticktime - _LootCleanupTime)) &&
		{!(_x getvariable ["EPOCH_Skiploot",false])} &&
		{(_x nearObjects ["PlotPole_Epoch", 100]) isEqualTo []} &&
		{(_x nearObjects ["ProtectionZone_Invisible_F", 25]) isEqualTo []} &&
		{(_x nearEntities[["Epoch_Male_F", "Epoch_Female_F"], 15]) isEqualTo []} &&
		{!(isObjectHidden _x)}
	};
	if !(_objects isEqualTo[]) then {
		_LootsArray = [];
		{
			_building = _x;
			_building setvariable ["Epoch_LastLootCheck",diag_ticktime];
			_selectedConfig = typeOf _building;
			if (_selectedConfig isEqualTo "") then {
				(getModelInfo _building) params [["_modelName",""]];
				if (!isnil "_modelName") then {
					_selectedConfig = (_modelName splitString " .") joinString "_";
				};
			};
			_config = _masterConfig >> _selectedConfig;
			if (isClass(_config)) then {
				_buildingLoot = [];
				if ((random 100) < (getNumber (_config >> "EpochLootChance"))) then {
					_buildingLoot = [_building,"EpochLoot",[]];
					_cfgBaseBuilding = 'CfgBaseBuilding' call EPOCH_returnConfig;
					_loots = getArray(_config >> "loottypes");
					_lootLimit = (round random(getNumber(_config >> "limit"))) max 1;
					_possibleLoots = [];
					{
						_x params ["_posNameTMP","_class","_randomColor"];
						_posName = _posNameTMP;
						_positions = getArray(_config >> _posName);
						{
							_possibleLoots pushBack [_class,_randomColor,_x];
						} forEach _positions;
					} forEach _loots;
					if !(_possibleLoots isEqualTo []) then {
						for "_i" from 1 to _lootLimit do {
							_possibleCount = count _possibleLoots;
							if (_possibleCount > 0) then {
								_randomIndex = (floor random(_possibleCount));
								_selectedLoot = _possibleLoots deleteAt _randomIndex;
								_selectedLoot params ["_class","_randomColor","_position"];
								_position params ["_m2WPos","_relDir"];
								_pos = _building modelToWorld _m2WPos;
								if (_pos select 2 < 0) then {
									_pos set[2, 0];
								};
								if (_class isEqualType []) then {
									_class = selectRandom _class;
								};
								_dir = _relDir + (getDir _building);
								_color = "";
								if (_randomColor isEqualTo "true") then {
									_colors = getArray(_cfgBaseBuilding >> _class >> "availableTextures");
									if !(_colors isEqualTo[]) then {
										_color = selectRandom _colors;
									};
								};
								(_buildingLoot select 2) pushback [_class, _pos, _dir, _color];
							};
						};
					};
				}
				else {
					if ((random 100) < (getNumber (_config >> "GroundSpawnChance"))) then {
						_buildingLoot = [_building,"GroundLoot",[]];
						_MinGroundContainers = getNumber (_config >> "MinGroundContainers");
						_MaxGroundContainers = getNumber (_config >> "MaxGroundContainers");
						_lootType = getText(_config >> "lootType");
						_loots = getArray(_config >> "loottypes");
						_positions = [];
						{
							_x params ["_posName","_class","_randomColor"];
							if !((tolower _posName) in ["cabinetpos","toolrackpos"]) then {
								_positions = _positions + getArray (_config >> _posName);
							};
						} forEach _loots;
						if !(_positions isEqualTo []) then {
							for "_i" from 1 to (_MinGroundContainers + (round (random (_MaxGroundContainers - _MinGroundContainers)))) do {
								if ((count _positions) > 0) then {
									_position = _positions deleteat (floor (random (count _positions)));
									_position params ["_m2WPos","_relDir"];
									_pos = _building modelToWorld _m2WPos;
									_pos vectoradd [0,0,0.1];
									if (_pos select 2 < 0) then {
										_pos set[2, 0];
									};
									(_buildingLoot select 2) pushback [_lootType,_pos];
								};
							};
						};
					};
				};
				if !(_buildingLoot isEqualTo []) then {
					_LootsArray pushback _buildingLoot;
				};
			};
		} foreach _objects;	
		if !(_LootsArray isEqualTo []) then {
			[player,Epoch_personalToken,_LootsArray] remoteExec ["EPOCH_server_spawnLoot",2];
		};
	};
};

// init weather temperature var if not already set
if (isNil "EPOCH_CURRENT_WEATHER") then {
	EPOCH_CURRENT_WEATHER = 75;
};

_cursorTarget = objNull;

// init cfgBaseBuilding config var
_cfgBaseBuilding = 'CfgBaseBuilding' call EPOCH_returnConfig;
_cfgObjectInteractions = 'CfgObjectInteractions' call EPOCH_returnConfig;


_EPOCH_BuildTraderMisson = {
	params ['_inGameTasksconfig','_taskName',['_unit',objnull],['_taskItem',objnull]];
	_taskTitle = getText ( _inGameTasksconfig >> _taskName >> "title");
	_taskSQF = getText ( _inGameTasksconfig >> _taskName >> "initsqf");
	if !(_taskSQF isequalto '') then {
		call compile format ["[_taskName,player,_unit,_taskItem] execVM ""%1""",_taskSQF];
	};
	_taskCall = getText ( _inGameTasksconfig >> _taskName >> "initcall");
	if !(_taskCall isequalto '') then {
		call compile _taskCall;
	};

	_taskDelay = diag_ticktime + (getNumber ( _inGameTasksconfig >> _taskName >> "triggerDelay"));
	_triggerintervall = getNumber ( _inGameTasksconfig >> _taskName >> "triggerintervall");
	_taskItems = getArray ( _inGameTasksconfig >> _taskName >> "items");
	if !(_taskItems isequalto []) then {
		[player,Epoch_personalToken,_taskItems,[],objNull,false] remoteExec ["EPOCH_Server_createObject",2];
	};

	_taskMarkerType = getnumber (_inGameTasksconfig >> _taskName >> 'markerType');
	if (_taskMarkerType > 0) then {
		_taskMarkerVis = getNumber ( _inGameTasksconfig >> _taskName >> "markerVisible");
		_markerPos = [0,0,0];
		 if (isNil "EPOCH_taskMarkerPos") then {
			if !(isNull _trgt) then {
				_markerPos = getPos _trgt;
			};
			if !(isNull _unit) then{
				_markerPos = getPos _unit;
			};
			if !(isNull _taskItem) then {
				_markerPos = getPos _taskItem;
			};
		}
		else {
			_markerPos = EPOCH_taskMarkerPos;
		};
		_mkrName = format ["EPOCHTaskMark%1%2",_taskName,diag_tickTime];
		EPOCH_taskMarker = [_mkrName,_taskMarkerVis];
		_taskMarkerText = getText ( _inGameTasksconfig >> _taskName >> "markerText");
		_taskMarkerRad = getNumber ( _inGameTasksconfig >> _taskName >>  "markerRadius");
		if(_taskMarkerType == 2)then{
			_markerPos set [0, (_markerPos select 0) + (floor (random _taskMarkerRad) - (_taskMarkerRad / 2))];
			_markerPos set [1, (_markerPos select 1) + (floor (random _taskMarkerRad) - (_taskMarkerRad / 2))];
		};
		[[_taskMarkerVis,player],_markerPos,"ELLIPSE","mil_dot",_taskMarkerText,"ColorYellow",[_taskMarkerRad,_taskMarkerRad], "SolidBorder", 42, 0.6,_mkrName] remoteExec ["EPOCH_server_makeMarker",2];
	};
	_taskDialogues = [];
	{
		_x params [["_condition",""],["_dialogue",""]];
		if !(_condition isequalto "" || _dialogue isequalto "") then {
			_taskDialogues pushback [compile _condition,_dialogue];
		};
	} foreach (getarray (_inGameTasksconfig >> _taskName >> 'dialogues'));
	_taskEvents = [];
	{
		_x params [["_condition",""],["_taskEventCALL",""],["_taskEventTasks",[]]];
		if !(_condition isequalto "") then {
			_taskEvents pushback [compile _condition,compile _taskEventCALL,_taskEventTasks];
		};
	} foreach (getarray (_inGameTasksconfig >> _taskName >> 'callevents'));
	_taskFailedCond = compile getText ( _inGameTasksconfig >> _taskName >> "failedCondition");
	_taskFailTime = (getNumber ( _inGameTasksconfig >> _taskName >> "abandonTime"));
	if (_taskFailTime < 1) then {_taskFailTime=999999} else {_taskFailTime = _taskFailTime + diag_ticktime};
	_taskFailedDiags = getArray ( _inGameTasksconfig >> _taskName >> "faileddialogues");
	_taskFailedSQF = getText ( _inGameTasksconfig >> _taskName >> "failedSQF");
	_taskFailedCall = compile getText ( _inGameTasksconfig >> _taskName >> "failedCall");
	_nextTask = getArray ( _inGameTasksconfig >> _taskName >> "failedTask");

	_taskCompleteCond = compile getText ( _inGameTasksconfig >> _taskName >> "completeCondition");
	_taskReward = getArray ( _inGameTasksconfig >> _taskName >> "reward");
	_taskCompleteDiags = getArray ( _inGameTasksconfig >> _taskName >> "completedialogues");
	_taskCompleteCall = compile getText ( _inGameTasksconfig >> _taskName >> "completedCALL");
	_taskNextTrigger = getArray ( _inGameTasksconfig >> _taskName >> "nextTask");

	_missionCleanUpCall = compile getText ( _inGameTasksconfig >> _taskName >>  "cleanUpCall");
	_taskCleanup = getNumber ( _inGameTasksconfig >> _taskName >>  "cleanUp");
	_return = [
		[_inGameTasksconfig,_taskName,_unit,_taskItem,_taskTitle,_missionCleanUpCall,_taskCleanup],
		_taskDelay,
		_triggerintervall,
		_taskDialogues,
		_taskEvents,
		[_taskFailedCond,_taskFailTime,_taskFailedDiags,_taskFailedSQF,_taskFailedCall,_nextTask],
		[_taskCompleteCond,_taskReward,_taskCompleteDiags,_taskCompleteCall,_taskNextTrigger]
	];
	EPOCH_task_startTime = diag_ticktime;
	_return
};
_epoch_tradermissionarray = [];
EPOCH_ActiveTraderMission = [];
_LastMissionTrigger = 0;
