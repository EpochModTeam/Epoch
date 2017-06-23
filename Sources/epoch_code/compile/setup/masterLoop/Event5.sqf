_position = getPosATL player;

EPOCH_nearestLocations = nearestLocations[player, ["NameCityCapital", "NameCity", "Airport"], 300];

EPOCH_playerIsSwimming = false;

if !(surfaceIsWater _position) then {
	if (EPOCH_nearestLocations isEqualTo []) then{
		if (count(player nearEntities["Animal_Base_F", 800]) < 2) then {
			call EPOCH_client_loadAnimalBrain;
		};
	};
} else {
	// spawn shark if player is deep water and not in vehicle
	if (vehicle player == player) then{
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
_powerSources = nearestObjects[player, ["Land_spp_Tower_F","Land_wpp_Turbine_V2_F","Land_wpp_Turbine_V1_F","SolarGen_EPOCH"], _energyRange];
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
