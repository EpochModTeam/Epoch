
_prevEquippedItem = [];
_damagePlayer = damage player;
_panic = false;
_prevEnergy = EPOCH_playerEnergy;

// init config data
EPOCH_sapperRndChance = ["CfgEpochClient", "sapperRngChance", 100] call EPOCH_fnc_returnConfigEntryV2;
EPOCH_zombieRndChance = ["CfgEpochClient", "zombieRndChance", 50] call EPOCH_fnc_returnConfigEntryV2;
EPOCH_droneRndChance = ["CfgEpochClient", "droneRngChance", 100] call EPOCH_fnc_returnConfigEntryV2;
_baseHTLoss = ["CfgEpochClient", "baseHTLoss", 8] call EPOCH_fnc_returnConfigEntryV2;
_energyCostNV = ["CfgEpochClient", "energyCostNV", 3] call EPOCH_fnc_returnConfigEntryV2;
_energyRegenMax = ["CfgEpochClient", "energyRegenMax", 5] call EPOCH_fnc_returnConfigEntryV2;
_energyRange = ["CfgEpochClient", "energyRange", 75] call EPOCH_fnc_returnConfigEntryV2;

EPOCH_chargeRate = 0;
EPOCH_playerIsSwimming = false;

// default data if mismatch
if (count EPOCH_playerSpawnArray != count EPOCH_spawnIndex) then{
	EPOCH_playerSpawnArray = [];
	{ EPOCH_playerSpawnArray pushBack 0 } forEach EPOCH_spawnIndex;
};

//9990 cutRsc ["EpochGameUI","PLAIN",2,false];
//_display = uiNamespace getVariable "EPOCH_EpochGameUI";
/*
EPOCH_fnc_makeCtrl = {
	params [["_picture",""],["_HUDclass","topRight"]];
	private _index =  missionNamespace getvariable ["EPOCH_dynamicCtrlIndex",1];
	private _ctrl = [_HUDclass,_index] call epoch_getHUDCtrl;
	_ctrl ctrlSetText _picture;
	missionNamespace setvariable ["EPOCH_dynamicCtrlIndex",_index + 1];
	_ctrl
};

_thirst = ["x\addons\a3_epoch_code\Data\UI\thirst_ca.paa"] call EPOCH_fnc_makeCtrl;
_hunger = ["x\addons\a3_epoch_code\Data\UI\hunger_ca.paa"] call EPOCH_fnc_makeCtrl;
_broken = ["x\addons\a3_epoch_code\Data\UI\broken_ca.paa"] call EPOCH_fnc_makeCtrl;
_oxygen = ["x\addons\a3_epoch_code\Data\UI\oxygen_ca.paa"] call EPOCH_fnc_makeCtrl;
_hazzard = ["x\addons\a3_epoch_code\Data\UI\hazzard_ca.paa"] call EPOCH_fnc_makeCtrl;
_emergency = ["x\addons\a3_epoch_code\Data\UI\bleeding_ca.paa"] call EPOCH_fnc_makeCtrl;

diag_log format ["init HUD: %1 %2 %3 %4 %5 %6", _thirst,_hunger,_broken,_oxygen,_hazzard,_emergency];

{

	_x ctrlShow false;
}forEach[_thirst,_hunger,_broken,_oxygen,_hazzard,_emergency];

*/
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
_scaleUI = {
	params ["_ctrl","_bool"];
	private _oemScale = _ctrl getVariable ["ctrl_scale", 1];
	private _curScale = ctrlScale _ctrl;
	if (_bool) then {
		if (_curScale isEqualTo _oemScale) then {
			_ctrl ctrlSetScale (_oemScale - 0.1);
			_ctrl ctrlCommit 0.5;
		} else {
			_ctrl ctrlSetScale _oemScale;
			_ctrl ctrlCommit 0.5;
		};
	} else {
		if !(_curScale isEqualTo _oemScale) then {
			_ctrl ctrlSetScale _oemScale;
			_ctrl ctrlCommit 0.5;
		};
	};
	_bool
};

_cursorTarget = objNull;

// init cfgBaseBuilding config var
_cfgBaseBuilding = 'CfgBaseBuilding' call EPOCH_returnConfig;
_cfgObjectInteractions = 'CfgObjectInteractions' call EPOCH_returnConfig;
