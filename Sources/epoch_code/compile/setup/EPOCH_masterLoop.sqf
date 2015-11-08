disableSerialization;

_EPOCH_1 = diag_tickTime;
_EPOCH_10 = diag_tickTime;
_EPOCH_15 = diag_tickTime;
_EPOCH_30 = diag_tickTime;
_EPOCH_60 = diag_tickTime;
_EPOCH_300 = diag_tickTime;
_EPOCH_600 = diag_tickTime;

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

_lootClasses = ('CfgBuildingLootPos' call EPOCH_returnConfig) call Bis_fnc_getCfgSubClasses;
_lootClasses = _lootClasses - ["Default"];

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
		_config = 'CfgEpochClient' call EPOCH_returnConfig;
		_buildingJammerRange = getNumber(_config >> "buildingJammerRange");
		if (_buildingJammerRange == 0) then { _buildingJammerRange = 75; };

		_jammer = nearestObjects [_lootLoc, ["PlotPole_EPOCH"], _buildingJammerRange];

		if (!(_objects isEqualTo[]) && (_jammer isEqualTo[])) then {

			_building = _objects select(floor(random(count _objects)));

			if !(_building in EPOCH_LootedBlds) then {

				_pos = getPosATL _building;
				_others = _building nearEntities[["Epoch_Male_F", "Epoch_Female_F"], 15];
				if (_others isEqualTo[]) then {

					_nearObjects = nearestObjects[_pos, ["WH_Loot", "Animated_Loot"], 35];
					if (_nearObjects isEqualTo[]) then {

						_config = ('CfgBuildingLootPos' call EPOCH_returnConfig) >> (typeOf _building);

						if (isClass(_config)) then {

							_lootBiasPos = getNumber(_config >> "lootBiasPos");
							_lootType = getText(_config >> "lootType");

							EPOCH_LootedBlds pushBack _building;
							if (count EPOCH_LootedBlds >= 20) then {
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

												if ((typeName _class) == "ARRAY") then {
													_class = _class select(floor(random(count _class)));
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

												if (typeName _randomColor isEqualTo "STRING") then {
													_randomColor = _randomColor isEqualTo "true";
												};

												if (_randomColor) then {
													_colors = [] + getArray(configFile >> "CfgVehicles" >> _class >> "availableTextures");
													if !(_colors isEqualTo[]) then {
														_color = _colors select floor(random(count _colors));
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
	private ["_ctrl"];
	_ctrl = _this select 0;
	if (_this select 1) then {
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
};

_cursorTarget = objNull;

// Master Loop Start
while {alive player} do {

	_tickTime = diag_tickTime;

	// 1 second
	if ((_tickTime - _EPOCH_1) > 1) then {

		_EPOCH_1 = _tickTime;

		// current target

		_currentTarget = objNull;
		_cursorTarget = ([10] call EPOCH_fnc_cursorTarget);
		if (!isNull _cursorTarget && {!(EPOCH_target isEqualTo _cursorTarget)}) then {
			if (_cursorTarget isKindOf "ThingX" || _cursorTarget isKindOf "Constructions_static_F" || _cursorTarget isKindOf "Constructions_foundation_F" || _cursorTarget isKindOf "WeaponHolder" || _cursorTarget isKindOf "AllVehicles" || _cursorTarget isKindOf "PlotPole_EPOCH") then{
				if (_cursorTarget isKindOf "Animal_Base_F") then {
					if !(alive _cursorTarget) then {
						_currentTarget = _cursorTarget;
					};
				} else {
					_currentTarget = _cursorTarget;
				};
			};
		};
		EPOCH_currentTarget = _currentTarget;

		_increaseStamina = false;
		_vehicle = vehicle player;
		if (_vehicle == player) then {
			_val = log(abs(speed player));
			_staminaThreshold = 0.7;
			if (EPOCH_playerIsSwimming) then {_staminaThreshold = 0.3};
			if (_val>_staminaThreshold) then {
				EPOCH_playerStamina = (EPOCH_playerStamina - (_val/4)) max 0;
			} else {
				_increaseStamina = true;
			};
		} else {
			if (EPOCH_buildMode > 0) then {
				EPOCH_buildMode = 0;
				EPOCH_snapDirection = 0;
				hintsilent "BUILD MODE: DISABLED";
				EPOCH_Target = objNull;
				// EPOCH_SURVEY = [];
			};
			_increaseStamina = true;

			switch (typeOf _vehicle) do {
				case "jetski_epoch": {
					_clock_hour10 = floor ((date select 3)/10);
					_clock_minute10 = floor ((date select 4)/10);
					{
						_vehicle setObjectTexture [_forEachIndex,_x];
					}forEach[
						format["\x\addons\a3_epoch_vehicles\data\num%1_ca.paa",_clock_hour10],
						format["\x\addons\a3_epoch_vehicles\data\num%1_ca.paa",(date select 3)-(_clock_hour10*10)],
						format["\x\addons\a3_epoch_vehicles\data\num%1_ca.paa",_clock_minute10],
						format["\x\addons\a3_epoch_vehicles\data\num%1_ca.paa",(date select 4)-(_clock_minute10*10)],
						format["\x\addons\a3_epoch_vehicles\data\fuel%1_ca.paa",floor(fuel _vehicle*10)]
					];
				};
				case "ebike_epoch": {
					{
						_vehicle setObjectTexture [_forEachIndex,_x];
					}forEach[
						format["\x\addons\a3_epoch_vehicles\data\speed%1_ca.paa",floor(speed _vehicle/9) max 0],
						format["\x\addons\a3_epoch_vehicles\data\energ%1_ca.paa",floor(fuel _vehicle*14)]
					];
				};
			};
		};

		_envCold = EPOCH_playerTemp <= 95.0;
		_envHot = EPOCH_playerTemp >= 106.7;
		_hungry = EPOCH_playerHunger <= 0;
		_thirsty = EPOCH_playerThirst <= 0;
		_warnbloodPressure = EPOCH_playerBloodP > 120;

		_thirst ctrlShow (EPOCH_playerThirst <= 625);
		if (ctrlShown _thirst) then {
			[_thirst,_thirsty] call _fadeUI;
			_thirstScale = linearConversion [0,EPOCH_playerThirst,2500,0.01,1];
			_thirst ctrlSetTextColor [_thirstScale, _thirstScale, 0.9, 1];
		};

		_hunger ctrlShow (EPOCH_playerHunger <= 1250);
		if (ctrlShown _hunger) then {
			[_hunger,_hungry] call _fadeUI;
			_hungerScale = linearConversion [0,EPOCH_playerHunger,5000,0.01,1];
			_hunger ctrlSetTextColor [1, _hungerScale, _hungerScale, 1];
		};

		_playerOxygen = getOxygenRemaining player;
		_oxygen ctrlShow (_playerOxygen < 1);
		if (ctrlShown _oxygen) then {
			[_oxygen,(_playerOxygen <= 0.55)] call _fadeUI;
			_oxygen ctrlSetTextColor [1, _playerOxygen, _playerOxygen, 1];
		};

		_hazzard ctrlShow (EPOCH_playerToxicity > 1);
		if (ctrlShown _hazzard) then {
			[_hazzard,(EPOCH_playerToxicity >= 55)] call _fadeUI;
			_toxicScale = 1-linearConversion [0,EPOCH_playerToxicity,100,0.01,1];
			_hazzard ctrlSetTextColor [_toxicScale, 1, _toxicScale, 1];
		};

		_broken ctrlShow ((player getHitPointDamage "HitLegs") >= 0.5);
		if (ctrlShown _broken) then {
			[_broken,true] call _fadeUI;
		};

		if (_envCold || _envHot || _hungry || _thirsty) then {
			if (_envHot || _envCold) then {
				player setFatigue 1;
			};
			EPOCH_playerBloodP = (EPOCH_playerBloodP + 0.05) min 190;
			_increaseStamina = false;
		} else {
			if (EPOCH_playerStamina > 0) then {
				if !(_panic) then {
					if (!_warnbloodPressure) then {
						player setFatigue 0;
					};
					EPOCH_playerBloodP = EPOCH_playerBloodP - 1 max 100;
				};
			};
		};

		_critical = (damage player >= 0.7 || _warnbloodPressure);
		_emergency ctrlShow _critical;
		if (ctrlShown _emergency) then {
			[_emergency,(EPOCH_playerBloodP > 140)] call _fadeUI;
			_emergencyScale = 1-linearConversion [0,EPOCH_playerBloodP,180,0.01,1];
			_emergency ctrlSetTextColor [1, _emergencyScale, _emergencyScale, 1];
		};

		if (EPOCH_playerBloodP >= 180) then {
			true call EPOCH_pushCustomVar;
		};
		if (_increaseStamina && (getFatigue player) == 0) then {
			EPOCH_playerStamina = (EPOCH_playerStamina + 0.5) min EPOCH_playerStaminaMax;
		};
		if (EPOCH_debugMode) then {
			call EPOCH_debugMonitor;
		};

		call EPOCH_TradeLoop;

		//Good bye onEachFrame hacks ;)
		onEachFrame EPOCH_onEachFrame;
	};

	// 10 seconds
	if ((_tickTime - _EPOCH_10) > 10) then {

		_EPOCH_10 = _tickTime;

		if !(EPOCH_arr_interactedObjs isEqualTo[]) then {
			EPOCH_arr_interactedObjs remoteExec["EPOCH_server_save_vehicles", 2];
			EPOCH_arr_interactedObjs = [];
		};

		if (damage player != _damagePlayer) then {
			if (alive player) then {
				true call EPOCH_pushCustomVar;
				_damagePlayer = damage player;
			};
		};

		if ((rating player) < 0) then {
			player addRating abs(rating player);
		};

		// calculate total available power
		// 1. number of power production devices within range 75m

		// find share of power based on factors
		// 1. number of players
		// 2. Other sources of drain (Lights)

		_energyValue = EPOCH_chargeRate min _energyRegenMax;
		_vehicle = vehicle player;
		if (_vehicle != player && isEngineOn _vehicle) then {
				_energyValue = _energyValue + 5;
		};

		if (currentVisionMode player == 1) then { //NV enabled
			_energyValue = _energyValue - _energyCostNV;
			if (EPOCH_playerEnergy == 0) then {
				player action["nvGogglesOff", player];
			};
		};

		EPOCH_playerEnergy = ((EPOCH_playerEnergy + _energyValue) min EPOCH_playerEnergyMax) max 0;

		if !(EPOCH_playerEnergy isEqualTo _prevEnergy) then {
			9993 cutRsc["EpochGameUI3", "PLAIN", 0, false];
			_display3 = uiNamespace getVariable "EPOCH_EpochGameUI3";
			_energyDiff = round(EPOCH_playerEnergy - _prevEnergy);
			_diffText = if (_energyDiff > 0) then {format["+%1",_energyDiff]} else {format["%1",_energyDiff]};
			// hint str [_energyValue,_prevEnergy,EPOCH_playerEnergy];
			(_display3 displayCtrl 21210) ctrlSetText format["%1/%2 %3", round(EPOCH_playerEnergy), EPOCH_playerEnergyMax, _diffText];
			_prevEnergy = EPOCH_playerEnergy;
		};

		if (EPOCH_playerEnergy == 0) then {
			if (EPOCH_buildMode > 0) then {
				EPOCH_buildMode = 0;
				EPOCH_snapDirection = 0;
				_dt = ["<t size = '0.8' shadow = '0' color = '#99ffffff'>Build Mode Disabled: Need Energy< / t>", 0, 1, 5, 2, 0, 1] spawn bis_fnc_dynamictext;
				EPOCH_Target = objNull;
				EPOCH_Z_OFFSET = 0;
				EPOCH_X_OFFSET = 0;
				EPOCH_Y_OFFSET = 5;
			};
		};

		_attackers = player nearEntities[["Snake_random_EPOCH", "GreatWhite_F", "Epoch_Cloak_F"], 30];
		if !(_attackers isEqualTo[]) then {
			(_attackers select 0) call EPOCH_client_bitePlayer;
			_panic = true;
		} else {
			// custom poision
			_toxicObjs = player nearobjects["SmokeShellCustom", 6];
			if!(_toxicObjs IsEqualTo[]) then {
				(_toxicObjs select 0) call EPOCH_client_bitePlayer;
				_panic = true;
			} else {
				_panic = false;
			};
		};

		call EPOCH_fnc_Weather;

		// Hunger / Thirst
		_HTlossRate = _baseHTLoss;
		if (EPOCH_playerStamina < 100) then {
			if ((getFatigue player) > 0) then {
				_HTlossRate = _HTlossRate + (_HTlossRate*(getFatigue player));
			};
		} else {
			_HTlossRate = (_HTlossRate / 2);
		};

		EPOCH_playerHunger = (EPOCH_playerHunger - _HTlossRate) max 0;
		EPOCH_playerThirst = (EPOCH_playerThirst - _HTlossRate) max 0;

		call _lootBubble;

		EPOCH_playerStaminaMax = (100 * (round(EPOCH_playerAliveTime/360)/10)) min 2500;
	};

	if ((_tickTime - _EPOCH_15) > 15) then {
		_EPOCH_15 = _tickTime-10;

		if !(_prevEquippedItem isEqualTo EPOCH_equippedItem_PVS) then {
			_EPOCH_15 = _tickTime;
			_prevEquippedItem = EPOCH_equippedItem_PVS;
			publicVariableServer "EPOCH_equippedItem_PVS";
		};
	};

	if ((_tickTime - _EPOCH_30) > 30) then {
		_EPOCH_30 = _tickTime;

		_nearByBobbersLocal = [];
		_nearByBobbers = player nearEntities[["Bobber_EPOCH"], 12];
		{
			if (local _x) then {
				_nearByBobbersLocal pushBack _x
			}
		} forEach _nearByBobbers;

		if !(_nearByBobbersLocal isEqualTo []) then {
			if ((random 100) < 50) then {
				_bobber = _nearByBobbersLocal select floor(random(count _nearByBobbers));
				_bobber setVelocity [0,-1,-1];
				_bobber setVariable ["EPOCH_fishOnLine" , diag_tickTime];
			};

		};

	};



	if ((_tickTime - _EPOCH_60) > 60) then {

		_EPOCH_60 = _tickTime;
		_position = getPosATL player;

		EPOCH_nearestLocations = nearestLocations[player, ["NameCityCapital", "NameCity", "Airport"], 300];
		EPOCH_playerIsSwimming = false;

		if !(surfaceIsWater _position) then {
			if (EPOCH_nearestLocations isEqualTo []) then{
				if (count(_position nearEntities["Animal_Base_F", 800]) < 2) then {
					// diag_log "DEBUG: Attempt to spawn animal";
					call EPOCH_client_loadAnimalBrain;
				};
			};
		} else {
			// spawn shark if player is deep water and not in vehicle
			if (vehicle player == player) then{
				_offsetZ = ((_position vectorDiff getPosASL player) select 2);
				if (_offsetZ > 1.7) then {
					EPOCH_playerIsSwimming = true;
				};
				if (_offsetZ > 50) then {
					"GreatWhite_F" call EPOCH_unitSpawn;
				};
			};
		};

		// default power state
		EPOCH_nearPower = false;
		EPOCH_chargeRate = 0;

		// energy Charge from nearby power plants
		_powerSources = nearestObjects[player, ["Land_spp_Tower_F","Land_wpp_Turbine_V2_F","Land_wpp_Turbine_V1_F","SolarGen_EPOCH"], _energyRange];
		if !(_powerSources isEqualTo[]) then {
			_totalCapacity = 0;
			{
					_powerClass = typeOf _x;
					_powerCap = getNumber(configFile >> "CfgVehicles" >> _powerClass >> "powerCapacity");
					_powerType = getNumber(configFile >> "CfgVehicles" >> _powerClass >> "powerType");
					if (_powerCap == 0) then {
						_powerCap = 100;
					};
					if (_powerType == 1) then {
						if (sunOrMoon < 1) then {
							_powerCap = _powerCap/2;
						};
					};
					_totalCapacity = _totalCapacity + _powerCap;
			} forEach _powerSources;
			if (_totalCapacity > 0) then {
				_players = player nearEntities[["Epoch_Male_F", "Epoch_Female_F"], _energyRange];
				if (_players isEqualTo []) then {
					EPOCH_chargeRate = ceil _totalCapacity;
				} else {
					EPOCH_chargeRate = ceil (_totalCapacity / (count _players));
				};
				EPOCH_nearPower = true;
			};
		};

		EPOCH_playerAliveTime = round(EPOCH_playerAliveTime + (_tickTime - EPOCH_clientAliveTimer));
		EPOCH_clientAliveTimer = _tickTime;
	};

	if ((_tickTime - _EPOCH_300) > 300) then {
		_EPOCH_300 = _tickTime;
		false call EPOCH_pushCustomVar;
	};

	if ((_tickTime - _EPOCH_600) > 600) then{
		_EPOCH_600 = _tickTime;

		if ((EPOCH_playerSpawnArray select(EPOCH_spawnIndex find "Epoch_Sapper_F")) <= 0) then{
			_sapperChance = 1 + (EPOCH_playerSoiled / 2);
			if !(EPOCH_nearestLocations isEqualTo[]) then{
				_sapperChance = _sapperChance + 2;
			};
			// 1% - 55% if soiled (+ 2% if in city) chance to spawn sapper every 10 minutes
			if (random _sapperRndChance < _sapperChance) then{
				"Epoch_Sapper_F" call EPOCH_unitSpawnIncrease;
			};
		};

		_spawnUnits = [];
		{
			if (_x > 0) then{
				_spawnUnits pushBack(EPOCH_spawnIndex select _forEachIndex);
			};
		} forEach EPOCH_playerSpawnArray;

		// test spawning one antagonist every 10 minutes select one unit at random to spawn
		if !(_spawnUnits isEqualTo[]) then{
			(_spawnUnits select(floor random(count _spawnUnits))) call EPOCH_unitSpawn;
		};
	};


	if (vehicle player != player) then {
		if (isNull EPOCH_currentVehicle) then {
			EPOCH_currentVehicle = vehicle player;
			EPOCH_currentVehicle addEventHandler["GetOut", "_this call EPOCH_antiWall"];
		};
	};

	uiSleep 0.1;
};
