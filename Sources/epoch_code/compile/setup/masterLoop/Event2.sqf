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
	_energyValue = _energyValue + 5;
};

if (currentVisionMode player == 1) then { //NV enabled
	_energyValue = _energyValue - _energyCostNV;
	if (_playerEnergy == 0) then {
		player action["nvGogglesOff", player];
		["Night Vision Goggles: Need Energy", 5] call Epoch_message;
	};
};

// Sets visual effect
if (_playerAlcohol > 20) then {
	_drunkVal = linearConversion [0,100,_playerAlcohol,0.1,1,true];
	[_drunkVal, 2] call epoch_setDrunk;
} else {
	[0, 2] call epoch_setDrunk;
};

// Sets visual effect
if (_playerRadiation > 1) then {
	_radiationVal = linearConversion [0,100,_playerRadiation,0.1,1,true];
	[_radiationVal, 2] call epoch_setRadiation;

	// if player has geiger counter make sound based on rads level
	if ('ItemGeigerCounter_EPOCH' in assignedItems player) then {
		_level = round(linearConversion [0,100,_radsLevel,0,3,true]);
		_sound = format ["geiger_%1",_level];
		playSound _sound;
	};
} else {
	[0, 2] call epoch_setRadiation;
};

//  Energy Handler
_digestEnergy = missionNamespace getVariable ["EPOCH_digestEnergy", 0];
if (_digestEnergy > 0) then {
	_energyValue = _energyValue + _digestEnergy;
	missionNamespace setVariable ["EPOCH_digestEnergy", 0];
};
_playerEnergy = ((_playerEnergy + _energyValue) min _playerEnergyMax) max _playerEnergyMin;

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
	_toxicObjs = player nearobjects["SmokeShellCustom", 6];
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
	if (EPOCH_playerIsSwimming) then {
		// do nothing if player is wearing a wetsuit
		if (!_wetsuit) then {
			if (_waterTemp <= 50) then {
				_warming = false;
			};
			_wet = true;
			_increaseWet = 10;
		};
	} else {
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

// Immunity Handler
_digestImmunity = missionNamespace getVariable ["EPOCH_digestImmunity", 0];
if (_digestImmunity > 0) then {
	_playerImmunity = ((_playerImmunity + _digestImmunity) min _playerImmunityMax) max _playerImmunityMin;
	missionNamespace setVariable ["EPOCH_digestImmunity", 0];
};

// toxic fever and immunity increase
if (_playerToxicity > 0) then {
	_playerImmunity = ((_playerImmunity + 0.1) min _playerImmunityMax) max _playerImmunityMin;
	_playerToxicity = ((_playerToxicity - 0.1) min _playerToxicityMax) max _playerToxicityMin;
	_maxTemp = 106.7 + 10;
};

if (_warming) then {
	_playerTemp = (_playerTemp + 0.01) min _maxTemp;
} else {
	_playerTemp = (_playerTemp - 0.01) max (95.0 - 10);
};

// wet/dry
if (_wet) then {
	_playerWet = ((_playerWet + _increaseWet) min _playerWetMax) max _playerWetMin;
	if (_playerWet > 50) then {
		_playerSoiled = ((_playerSoiled - 1) min _playerSoiledMax) max _playerSoiledMin;
	};
} else {
	if (_warming) then {
		_playerWet = ((_playerWet - 1) min _playerWetMax) max _playerWetMin;
	};
};

// Hunger / Thirst
_hungerlossRate = _baseHungerLoss * timeMultiplier;
_thirstlossRate = _baseThirstLoss * timeMultiplier;

// Increase hunger if player is Fatigued
if (_playerStamina < 100) then {
	if ((getFatigue player) > 0) then {
		_hungerlossRate = _hungerlossRate + (_hungerlossRate*(getFatigue player));
	};
} else {
    // reduce hunger loss if player stamina is greater than 100
	_hungerlossRate = (_hungerlossRate / 2);
};

_digestAlcohol = missionNamespace getVariable ["EPOCH_digestAlcohol", 0];
//  Alcohol Handler
if (_digestAlcohol > 0) then {
	_playerAlcohol = ((_playerAlcohol + _digestAlcohol) min _playerAlcoholMax) max _playerAlcoholMin;
	missionNamespace setVariable ["EPOCH_digestAlcohol", 0];
} else {
	// downtick Alcohol
	_alcoholLossRate = 0.17;
	_playerAlcohol = ((_playerAlcohol - _alcoholLossRate) min _playerAlcoholMax) max _playerAlcoholMin;
};

// Hunger Handler
_digestHunger = missionNamespace getVariable ["EPOCH_digestHunger", 0];
if (_digestHunger > 0) then {
	_playerHunger = ((_playerHunger + _digestHunger) min _playerHungerMax) max _playerHungerMin;
	missionNamespace setVariable ["EPOCH_digestHunger", 0];
} else {
	// downtick Hunger
	_playerHunger = ((_playerHunger - _hungerlossRate) min _playerHungerMax) max _playerHungerMin;
};

// Thirst Handler
_digestThirst = missionNamespace getVariable ["EPOCH_digestThirst", 0];
if (_digestThirst > 0) then {
	_playerThirst = ((_playerThirst + _digestThirst) min _playerThirstMax) max _playerThirstMin;
	missionNamespace setVariable ["EPOCH_digestThirst", 0];
} else {
	// downtick Thirst
	_playerThirst = ((_playerThirst - _thirstlossRate) min _playerThirstMax) max _playerThirstMin;
};

// Nuisance Handler, this only allows var to increse not decrease
_digestNuisance = missionNamespace getVariable ["EPOCH_digestNuisance", 0];
if (_digestNuisance > 0) then {
	_playerNuisance = ((_playerNuisance + _digestNuisance) min _playerNuisanceMax) max _playerNuisanceMin;
	missionNamespace setVariable ["EPOCH_digestNuisance", 0];
} else {
	// downtick Nuisance
	_playerNuisance = ((_playerNuisance - 1) min _playerNuisanceMax) max _playerNuisanceMin;
};

// Radiation Handler
_digestRadiation = missionNamespace getVariable ["EPOCH_digestRadiation", 0];
if (_digestRadiation < 0 && _radsLevel == 0) then {
	// only lower rads if player has taken medicine and it no longer in a radiation zone.
	_playerRadiation = ((_playerRadiation - 0.01) min _playerRadiationMax) max _playerRadiationMin;
	missionNamespace setVariable ["EPOCH_digestRadiation", (_digestRadiation + 1) min 0];
} else {
	// allow increase rads based on radiation levels and consumed rads
	if (_digestRadiation > 0) then {
		_radsLevel = _radsLevel + _digestRadiation;
		missionNamespace setVariable ["EPOCH_digestRadiation", 0];
	};
	_playerRadiation = ((_playerRadiation + _radsLevel) min _playerRadiationMax) max _playerRadiationMin;
};

EPOCH_playerStaminaMax = (100 * (round(_playerAliveTime/360)/10)) min 2500;

// process loot
call _lootBubble;
