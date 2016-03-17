
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
_loots = ["CfgEpochClient", "lootClasses", EPOCH_lootClasses] call EPOCH_fnc_returnConfigEntryV2;
_masterConfig = 'CfgBuildingLootPos' call EPOCH_returnConfig;

_lootClasses = [];
_lootClassesIgnore = ['Default'];
'_cN = configName _x;if !(_cN in _lootClassesIgnore)then{_lootClasses pushBack _cN};' configClasses _masterConfig;

_lootBubble = {
	private["_pos", "_others", "_objects", "_nearObjects", "_building", "_travelDir", "_lootDist", "_xPos", "_yPos", "_lootLoc", "_playerPos", "_distanceTraveled", "_class", "_dir", "_color", "_colors", "_item", "_randomColor", "_positions", "_lootBiasPos", "_lootType", "_config"];
	_playerPos = getPosATL vehicle player;
	_distanceTraveled = EPOCH_lastPlayerPos distance _playerPos;
	if (_distanceTraveled > 10 && _distanceTraveled < 200) then {
		_travelDir = [EPOCH_lastPlayerPos, _playerPos] call BIS_fnc_dirTo;
		_lootDist = 30 + _distanceTraveled;
		_xPos = (_playerPos select 0) + (_lootDist * sin(_travelDir));
		_yPos = (_playerPos select 1) + (_lootDist * cos(_travelDir));
		_lootLoc = [_xPos, _yPos, 0];

		_objects = nearestObjects[_lootLoc, _lootClasses, 30];

		_buildingJammerRange = getNumber(_masterConfig >> "buildingJammerRange");
		if (_buildingJammerRange == 0) then { _buildingJammerRange = 75; };

		_jammer = nearestObjects [_lootLoc, ["PlotPole_EPOCH"], _buildingJammerRange];

		if (!(_objects isEqualTo[]) && (_jammer isEqualTo[])) then {

			_building = selectRandom _objects;

			if !(_building in EPOCH_LootedBlds) then {

				_pos = getPosATL _building;
				_others = _building nearEntities[["Epoch_Male_F", "Epoch_Female_F"], 15];
				if (_others isEqualTo[]) then {

					_nearObjects = nearestObjects[_pos, ["WH_Loot", "Animated_Loot"], 35];
					if (_nearObjects isEqualTo[]) then {

						_config = _masterConfig >> (typeOf _building);

						if (isClass(_config)) then {

							_lootBiasPos = getNumber(_config >> "lootBiasPos");
							_lootType = getText(_config >> "lootType");

							EPOCH_LootedBlds pushBackUnique _building;
							if (count EPOCH_LootedBlds >= 100) then {
								EPOCH_LootedBlds deleteAt 0;
							};

							{
								_positions = [] + getArray(_config >> (_x select 0));
								if !(_positions isEqualTo[]) then {
									_class = _x select 1;
									_randomColor = _x select 2;
									{

										if ((random 100) < _lootBiasPos) then {

											_pos = _building modelToWorld(_x select 0);

											if (nearestObjects[_pos, ["WH_Loot", "Animated_Loot"], 2] isEqualTo[]) then {

												if (_class isEqualType []) then {
													_class = selectRandom _class;
												};

												_dir = (_x select 1) + (getDir _building);
												if (_dir > 360) then {
													_dir = _dir - 360;
												};

												// Temp for now till we get more
												if (_lootType == "mil" && _class == "Bed_EPOCH") then {
													_class = "Bunk_EPOCH";
												};

												_item = createVehicle[_class, _pos, [], 0.0, "CAN_COLLIDE"];
												_item setDir _dir;


												// force item to ground level is resulting z pos is below ground.
												if (_pos select 2 < 0) then {
													_pos set[2, 0];
												};

												if (surfaceIsWater _pos) then {
													_item setPosASL _pos;
												} else {
													_item setPosATL _pos;
												};

												if (_randomColor isEqualType "STRING") then {
													_randomColor = _randomColor isEqualTo "true";
												};

												if (_randomColor) then {
													_colors = [] + getArray(configFile >> "CfgVehicles" >> _class >> "availableTextures");
													if !(_colors isEqualTo[]) then {
														_color = selectRandom _colors;
														_item setObjectTextureGlobal[0, _color];
													};
												};
											};
										};
									}forEach _positions;
								};
							}forEach _loots;
						};
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
