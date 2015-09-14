private ["_warming","_isNearFire","_airTemp","_waterTemp","_playerPosATL"];
_airTemp = EPOCH_CURRENT_WEATHER;
_waterTemp = EPOCH_CURRENT_WEATHER/2;
_warming = true;
_wet = false;
_maxTemp = 98.6;
_increaseWet = 0;
_wetsuit = (getText(configfile >> "cfgweapons" >> uniform player >> "itemInfo" >> "uniformType") == "Neopren");

if (vehicle player == player) then {
	_playerPosATL = getPosATL player;
	if (surfaceIsWater _playerPosATL) then {
		// do nothing if player is wearing a wetsuit
		if (!_wetsuit) then {
			if (_waterTemp <= 50) then {
				_warming = false;
			};
			_wet = true;
			_increaseWet = 10;
		};
	} else {
		if (EPOCH_playerWet > 50 && _airTemp <= 32) then {
			_isNearFire = {inflamed _x} count (nearestObjects [_playerPosATL, ["ALL"], 3]);
			if (!(call EPOCH_fnc_isInsideBuilding) && _isNearFire == 0) then {
				_warming = false;
			};
		};
		if (rain >= 0.25) then {
			if (!_wetsuit) then {
				_isNearFire = { inflamed _x } count(nearestObjects[_playerPosATL, ["ALL"], 3]);
				if (!(call EPOCH_fnc_isInsideBuilding) && _isNearFire == 0) then {
					_wet = true;
					_increaseWet = rain * 10;
				};
			};
		};
	};
};

if (EPOCH_playerToxicity > 0) then {
	EPOCH_playerImmunity = (EPOCH_playerImmunity + 0.1) min 100;
	EPOCH_playerToxicity = (EPOCH_playerToxicity - 0.1) max 0;
	_maxTemp = 106.7 + 10;
};

if (_warming) then {
	EPOCH_playerTemp = (EPOCH_playerTemp + 0.01) min _maxTemp;
} else {
	EPOCH_playerTemp = (EPOCH_playerTemp - 0.01) max (95.0 - 10);
};

if (_wet) then {
	EPOCH_playerWet = (EPOCH_playerWet + _increaseWet) min 100;
	if (EPOCH_playerWet > 50) then {
		EPOCH_playerSoiled = (EPOCH_playerSoiled - 1) max 0;
	};
} else {
	if (_warming) then {
		EPOCH_playerWet = (EPOCH_playerWet - 1) max 0;
	};
};


true
