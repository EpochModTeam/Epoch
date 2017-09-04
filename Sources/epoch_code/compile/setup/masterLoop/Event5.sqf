_position = getPosATL player;

EPOCH_nearestLocations = nearestLocations[player, ["NameCityCapital", "NameCity", "Airport"], 300];
_powerSources = nearestObjects[player, ["Land_spp_Tower_F","Land_wpp_Turbine_V2_F","Land_wpp_Turbine_V1_F","SolarGen_EPOCH","Land_Wreck_Satellite_EPOCH"], _energyRange];

// TODO: add more sources and config based check instead of global var
_nearbyRadioactiveObjects = (_powerSources + EPOCH_nearestLocations) select {_x getVariable ["EPOCH_Rads", 0] > 0};

// check if player is out of map bounds.
_worldSize = worldSize/2;
_outOfBounds = !(player inArea [[_worldSize,_worldSize,0], _worldSize, _worldSize, 0, true ]);
if (_outOfBounds) then {
	// player is out of map bounds, give ten times background rads
	 ["You are out of the play area!", 5] call Epoch_message;
	 _radsLevel = _backgroundRadiation;
	 _playerRadiation = ((_playerRadiation + _radsLevel) min 100) max 0;
} else {
	// radiated objects or locations nearby
	if !(_nearbyRadioactiveObjects isEqualTo []) then {
		// add extra rads based on intensity and distance from site.
		_radioActiveSite = _nearbyRadioactiveObjects select 0;
		_radsLevel = (_radioActiveSite getVariable ["EPOCH_Rads", 0]) / (player distance _radioActiveSite);
		_playerRadiation = ((_playerRadiation + _radsLevel) min 100) max 0;
	} else {
		// TODO handle reduction of rads in master loop
		_anitRadiation = player getVariable ["EPOCH_antiRadiation", 0];
		if (_anitRadiation > 0) then {
			// lower radiation by 0.1 per tick
			_playerRadiation = ((_playerRadiation - 0.1) min 100) max 0;
			// lower anti rad level
			player setVariable ["EPOCH_antiRadiation", _anitRadiation - 1];
		};
	};
};

EPOCH_playerIsSwimming = false;

if !(surfaceIsWater _position) then {
	if (EPOCH_nearestLocations isEqualTo []) then{
		if (count(player nearEntities["Animal_Base_F", 800]) < 2) then {
			call EPOCH_client_loadAnimalBrain;
		};
	};
} else {
	// spawn shark if player is deep water and not in vehicle
	if !(_isOnFoot) then{
		_offsetZ = ((_position vectorDiff getPosASL player) select 2);
		EPOCH_playerIsSwimming = (_offsetZ > 1.7);
		if (_offsetZ > 50) then {
			["GreatWhite_F", player, true] call EPOCH_unitSpawn;
		};
	};
};

// default power state
EPOCH_nearPower = false;
EPOCH_chargeRate = 0;

// energy Charge from nearby power plants
if !(_powerSources isEqualTo[]) then {
	_totalCapacity = 0;
	{
			_powerClass = typeOf _x;
			_powerCap = getNumber(_cfgBaseBuilding >> _powerClass >> "powerCapacity");
			_powerType = getNumber(_cfgBaseBuilding >> _powerClass >> "powerType");
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
// downtick Alcohol
EPOCH_playerAlcohol = ((EPOCH_playerAlcohol - 1) min 100) max 0;

EPOCH_playerAliveTime = round(EPOCH_playerAliveTime + (_tickTime - EPOCH_clientAliveTimer));
EPOCH_clientAliveTimer = _tickTime;

// force update after 60 seconds
_forceUpdate = true;
