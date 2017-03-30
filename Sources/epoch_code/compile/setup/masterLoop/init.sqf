// make sure we wait for Display #46
waitUntil {!(isNull (findDisplay 46))};

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

_prevEquippedItem = [];
_damagePlayer = damage player;
_panic = false;
_prevEnergy = EPOCH_playerEnergy;

// init config data
EPOCH_sapperRndChance = ["CfgEpochClient", "sapperRngChance", 100] call EPOCH_fnc_returnConfigEntryV2;
EPOCH_zombieRngChance = ["CfgEpochClient", "zombieRngChance", 50] call EPOCH_fnc_returnConfigEntryV2;
EPOCH_droneRndChance = ["CfgEpochClient", "droneRngChance", 100] call EPOCH_fnc_returnConfigEntryV2;
_baseHTLoss = ["CfgEpochClient", "baseHTLoss", 8] call EPOCH_fnc_returnConfigEntryV2;
_energyCostNV = ["CfgEpochClient", "energyCostNV", 3] call EPOCH_fnc_returnConfigEntryV2;
_energyRegenMax = ["CfgEpochClient", "energyRegenMax", 5] call EPOCH_fnc_returnConfigEntryV2;
_energyRange = ["CfgEpochClient", "energyRange", 75] call EPOCH_fnc_returnConfigEntryV2;
_hudConfigs = ["CfgEpochClient", "hudConfigs", []] call EPOCH_fnc_returnConfigEntryV2;

EPOCH_chargeRate = 0;
EPOCH_playerIsSwimming = false;

// default data if mismatch
if (count EPOCH_playerSpawnArray != count EPOCH_spawnIndex) then{
	EPOCH_playerSpawnArray = [];
	{ EPOCH_playerSpawnArray pushBack 0 } forEach EPOCH_spawnIndex;
};

// HUD and Logic functions - todo move to client function.
/*
[_selVarName,_varIndex,_selVarType,_selVarSubData] call _fnc_returnHudVar
*/
_fnc_returnHudVar = {
	params [["_selVarName",""],["_varIndex",0],["_selVarType",""],["_selVarSubData",""]];
	switch (_selVarType) do {
		case "getMissionNamespaceVariable": {missionNamespace getVariable[_selVarName,_selVarSubData]};
		case "getPlayerHitPointDamage": {player getHitPointDamage _selVarSubData};
		case "getPlayerOxygenRemaining": {getOxygenRemaining player};
		case "getPlayerDamage": {damage player};
		default {missionNamespace getVariable[format['EPOCH_player%1', _selVarName],EPOCH_defaultVars select _varIndex]};
	}
};
/*
[1,">=",0] call _fnc_arrayToLogic; // returns: true
*/
_fnc_arrayToLogic = {
	params [["_v",""],["_t",""],["_d",""]];
	switch (_t) do {
		case ">=": {_v >= _d};
		case "<=": {_v <= _d};
		case "<": {_v < _d};
		case ">": {_v > _d};
		case "!=": {!(_v isEqualTo _d)};
		default {_v isEqualTo _d};
	}
};

// find radio
{
	if (configName(inheritsFrom(configFile >> "CfgWeapons" >> _x)) == "ItemRadio") exitWith{
		EPOCH_equippedItem_PVS = [_x, true, player];
	};
} forEach assignedItems player;

// lootBubble Init
_buildingJammerRange = ["CfgEpochClient", "buildingJammerRange", 75] call EPOCH_fnc_returnConfigEntryV2;
_masterConfig = 'CfgBuildingLootPos' call EPOCH_returnConfig;

_lootClasses = [];
_lootClassesIgnore = ['Default'];
'_cN = configName _x;if !(_cN in _lootClassesIgnore)then{_lootClasses pushBackUnique _cN};' configClasses _masterConfig;

_lootBubble = {
	private["_jammer", "_others", "_objects", "_nearObjects", "_building", "_lootDist", "_lootLoc", "_playerPos", "_distanceTraveled"];
	_playerPos = getPosATL vehicle player;
	_distanceTraveled = EPOCH_lastPlayerPos distance _playerPos;
	if (_distanceTraveled > 10 && _distanceTraveled < 200) then {
		_lootDist = 30 + _distanceTraveled;
		_lootLoc = player getRelPos [_lootDist, (random [-180,0,180])];
		_objects = nearestObjects[_lootLoc, _lootClasses, 30];
		_jammer = nearestObjects [_lootLoc, ["PlotPole_EPOCH","ProtectionZone_Invisible_F"], _buildingJammerRange];
		if (!(_objects isEqualTo[]) && (_jammer isEqualTo[])) then {
			_building = selectRandom _objects;
			if !(_building in EPOCH_LootedBlds) then {
				_others = _building nearEntities[["Epoch_Male_F", "Epoch_Female_F"], 15];
				if (_others isEqualTo[]) then {
					_nearObjects = nearestObjects[_building, ["WH_Loot", "Animated_Loot"], sizeOf (typeOf _building)];
					//diag_log format["DEBUG: sizeof %1 %2",sizeOf (typeOf _building), typeOf _building];
					if (_nearObjects isEqualTo[]) then {
						[_building] call EPOCH_spawnLoot;
					};
				};
			};
		};
	};
	EPOCH_lastPlayerPos = _playerPos;
};

// [control,bool] call _fadeUI;
_fadeUI = {
	params ["_ctrl","_bool"];
	if (_bool) then {
		if (ctrlFade _ctrl == 0) then {
			_ctrl ctrlSetFade 1;
			_ctrl ctrlCommit 0.5;
		};
		if (ctrlFade _ctrl == 1) then {
			_ctrl ctrlSetFade 0;
			_ctrl ctrlCommit 0.5;
		};
	} else {
		if (ctrlFade _ctrl != 1) then {
			_ctrl ctrlSetFade 0;
			_ctrl ctrlCommit 0;
		};
	};
	_bool
};

_cursorTarget = objNull;

// init cfgBaseBuilding config var
_cfgBaseBuilding = 'CfgBaseBuilding' call EPOCH_returnConfig;
_cfgObjectInteractions = 'CfgObjectInteractions' call EPOCH_returnConfig;
