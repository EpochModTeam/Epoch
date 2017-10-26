if !(EPOCH_arr_interactedObjs isEqualTo[]) then {
	[EPOCH_arr_interactedObjs] remoteExec["EPOCH_server_save_vehicles", 2];
	EPOCH_arr_interactedObjs = [];
};

if (damage player != _damagePlayer) then {
	if (alive player) then {
		_forceUpdate = true;
		_damagePlayer = damage player;
	};
};

// calculate total available power
// 1. number of power production devices within range 75m

// find share of power based on factors
// 1. number of players
// 2. Other sources of drain (Lights)

_energyValue = _chargeRate min _energyRegenMax;
_vehicle = vehicle player;
if (_vehicle != player && isEngineOn _vehicle) then {
	if !(_vehicle iskindof "Bicycle") then {
		_energyValue = _energyValue + 5;
	};
};
if (currentVisionMode player == 1) then { //NV enabled
	_energyValue = _energyValue - _energyCostNV;
	_playerEnergy = missionNamespace getVariable [_playerEnergyKey, _playerEnergyDefault];
	if (_playerEnergy == 0) then {
		player action["nvGogglesOff", player];
		["Night Vision Goggles: Need Energy", 5] call Epoch_message;
	};
};

// Sets visual effect
_playerAlcohol = missionNamespace getVariable [_playerAlcoholKey, _playerAlcoholDefault];
if (_playerAlcohol > 20) then {
	_drunkVal = linearConversion [0,100,_playerAlcohol,0.1,1,true];
	[_drunkVal, 2] call epoch_setDrunk;
} else {
	[0, 2] call epoch_setDrunk;
};

// Sets visual effect
_playerRadiation = missionNamespace getVariable [_playerRadiationKey, _playerRadiationDefault];
if (_playerRadiation > 1) then {
	_radiationVal = linearConversion [0,100,_playerRadiation,1,10,true];
	[(ceil _radiationVal)/10, 2] call epoch_setRadiation;
} else {
	[0, 2] call epoch_setRadiation;
};

// Geiger Deplete Energy
if (EPOCH_geiger_shown) then {
	_energyValue = _energyValue - (["CfgEpochClient", "outOfBoundsRadiation", 10] call EPOCH_fnc_returnConfigEntryV2);
};

//  Energy Handler
_playerEnergy = [_playerEnergyKey,_energyValue,_playerEnergyMax,_playerEnergyMin] call EPOCH_fnc_setVariableLimited;

if !(_playerEnergy isEqualTo _prevEnergy) then {
	9993 cutRsc["EpochGameUI3", "PLAIN", 0, false];
	_display3 = uiNamespace getVariable "EPOCH_EpochGameUI3";
	_energyDiff = round(_playerEnergy - _prevEnergy);
	_diffText = if (_energyDiff > 0) then {format["+%1",_energyDiff]} else {format["%1",_energyDiff]};
	(_display3 displayCtrl 21210) ctrlSetText format["%1/%2 %3", round(_playerEnergy), _playerEnergyMax, _diffText];
	_prevEnergy = _playerEnergy;
};

if (_playerEnergy == 0) then {
	if (EPOCH_buildMode > 0) then {
		EPOCH_buildMode = 0;
		EPOCH_snapDirection = 0;
		["Build Mode Disabled: Need Energy", 5] call Epoch_message;
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
	_toxicObjs = player nearobjects["SmokeShellCustom", 12];
	if!(_toxicObjs IsEqualTo[]) then {
		(_toxicObjs select 0) call EPOCH_client_bitePlayer;
		_panic = true;
	} else {
		_panic = false;
	};
};

// weather stats
_airTemp = EPOCH_CURRENT_WEATHER;
_waterTemp = EPOCH_CURRENT_WEATHER/2;
_warming = true;
_wet = false;
_maxTemp = 98.6; // normal body temp
_increaseWet = 0;
_wetsuit = (getText(configfile >> "cfgweapons" >> uniform player >> "itemInfo" >> "uniformType") == "Neopren");

if (_isOnFoot) then {
	if (underwater player) then {
		// do nothing if player is wearing a wetsuit
		if (!_wetsuit) then {
			if (_waterTemp <= 50) then {
				_warming = false;
			};
			_wet = true;
			_increaseWet = 10;
		};
	} else {
		_playerWet = missionNamespace getVariable [_playerWetKey, _playerWetDefault];
		if (_playerWet > 50 && _airTemp <= 32) then {
			_isNearFire = {inflamed _x} count (nearestObjects [player, ["ALL"], 3]);
			if (!(call EPOCH_fnc_isInsideBuilding) && _isNearFire == 0) then {
				_warming = false;
			};
		};
		if (rain >= 0.25) then {
			if (!_wetsuit) then {
				_isNearFire = { inflamed _x } count(nearestObjects[player, ["ALL"], 3]);
				if (!(call EPOCH_fnc_isInsideBuilding) && _isNearFire == 0) then {
					_wet = true;
					_increaseWet = rain * 10;
				};
			};
		};
	};
};

// allow player to over heat if air temp is high and player is Fatigued
if ((getFatigue player) >= 0.7 && _airTemp > 100) then {
	_maxTemp = _airTemp;
};

// toxic fever and immunity increase
_playerToxicity = missionNamespace getVariable [_playerToxicityKey, _playerToxicityDefault];
// _playerImmunity = missionNamespace getVariable [_playerImmunityKey, _playerImmunityDefault];
if (_playerToxicity > 0) then {
	_playerImmunity = [_playerImmunityKey,0.1,_playerImmunityMax,_playerImmunityMin] call EPOCH_fnc_setVariableLimited;
	_playerToxicity = [_playerToxicityKey,-0.1,_playerToxicityMax,_playerToxicityMin] call EPOCH_fnc_setVariableLimited;
	// allow player to overheat
	_maxTemp = _playerTempMax + 10;
};

// Body Temp handler
if (_warming) then {
	_playerTemp = [_playerTempKey,0.01,_maxTemp,_playerTempMin] call EPOCH_fnc_setVariableLimited;
} else {
	_playerTemp = [_playerTempKey,-0.01,_maxTemp,(_playerTempMin - 10)] call EPOCH_fnc_setVariableLimited;
};

// wet/dry
if (_wet) then {
	_playerWet = [_playerWetKey,_increaseWet,_playerWetMax,_playerWetMin] call EPOCH_fnc_setVariableLimited;
	if (_playerWet > 50) then {
		_soiledLossRate = 1;
		_playerSoiled = [_playerSoiledKey,-_soiledLossRate,_playerSoiledMax,_playerSoiledMin] call EPOCH_fnc_setVariableLimited;
	};
} else {
	if (_warming) then {
		_wetLossRate = 1;
		_playerWet = [_playerWetKey,-_wetLossRate,_playerWetMax,_playerWetMin] call EPOCH_fnc_setVariableLimited;
	};
};

// Hunger / Thirst
_hungerlossRate = _baseHungerLoss * _lossMultiplier;
_thirstlossRate = _baseThirstLoss * _lossMultiplier;
_alcoholLossRate = _baseAlcoholLoss * _lossMultiplier;

// Increase hunger if player is Fatigued
_playerStamina = missionNamespace getVariable [_playerStaminaKey, _playerStaminaDefault];
if (_playerStamina < 100) then {
	if ((getFatigue player) > 0) then {
		_hungerlossRate = _hungerlossRate + (_hungerlossRate*(getFatigue player));
	};
} else {
    // reduce hunger loss if player stamina is greater than 100
	_hungerlossRate = (_hungerlossRate / 2);
};

//  Alcohol Handler
_playerAlcohol = [_playerAlcoholKey,-_alcoholLossRate,_playerAlcoholMax,_playerAlcoholMin] call EPOCH_fnc_setVariableLimited;

// Hunger Handler
_playerHunger = [_playerHungerKey,-_hungerlossRate,_playerHungerMax,_playerHungerMin] call EPOCH_fnc_setVariableLimited;

// Thirst Handler
_playerThirst = [_playerThirstKey,-_thirstlossRate,_playerThirstMax,_playerThirstMin] call EPOCH_fnc_setVariableLimited;

// Nuisance Handler
_playerNuisance = [_playerNuisanceKey,-1,_playerNuisanceMax,_playerNuisanceMin] call EPOCH_fnc_setVariableLimited;


// calculate max stamina
EPOCH_playerStaminaMax = (100 * (round(_playerAliveTime/360)/10)) min 2500;

// process loot
call _lootBubble;
