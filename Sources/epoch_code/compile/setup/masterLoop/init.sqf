
_prevEquippedItem = [];
_damagePlayer = damage player;
_panic = false;
_prevEnergy = EPOCH_playerEnergy;

// init config data
_sapperRndChance = ["CfgEpochClient", "sapperRngChance", 100] call EPOCH_fnc_returnConfigEntryV2;
EPOCH_droneRndChance = ["CfgEpochClient", "droneRngChance", 100] call EPOCH_fnc_returnConfigEntryV2;
_baseHTLoss = ["CfgEpochClient", "baseHTLoss", 8] call EPOCH_fnc_returnConfigEntryV2;
_energyCostNV = ["CfgEpochClient", "energyCostNV", 3] call EPOCH_fnc_returnConfigEntryV2;
_energyRegenMax = ["CfgEpochClient", "energyRegenMax", 5] call EPOCH_fnc_returnConfigEntryV2;
_energyRange = ["CfgEpochClient", "energyRange", 75] call EPOCH_fnc_returnConfigEntryV2;

EPOCH_chargeRate = 0;
EPOCH_playerIsSwimming = false;

// default data if mismatch
if (count EPOCH_playerSpawnArray != count EPOCH_spawnIndex) then{
	{ EPOCH_playerSpawnArray pushBack 0 } forEach EPOCH_spawnIndex;
};

9990 cutRsc ["EpochGameUI","PLAIN",2,false];
_display = uiNamespace getVariable "EPOCH_EpochGameUI";

_thirst = _display displayCtrl 21201;
_hunger = _display displayCtrl 21202;
_broken = _display displayCtrl 21203;
_oxygen = _display displayCtrl 21204;
_hazzard = _display displayCtrl 21205;
_emergency = _display displayCtrl 21206;

{
	_x ctrlShow false;
}forEach[_thirst,_hunger,_broken,_oxygen,_hazzard,_emergency];

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
		_jammer = nearestObjects [_lootLoc, ["PlotPole_EPOCH"], _buildingJammerRange];
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
