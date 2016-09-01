/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Calculates weather related player stats

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/functions/EPOCH_fnc_Weather.sqf

    Example:
    call EPOCH_fnc_Weather;

    Parameter(s):
		NONE

	Returns:
	NOTHING
*/
//[[[cog import generate_private_arrays ]]]
private ["_airTemp","_increaseWet","_isNearFire","_maxTemp","_playerPosATL","_warming","_waterTemp","_wet","_wetsuit"];
//[[[end]]]

if (isNil "EPOCH_CURRENT_WEATHER") then {
	EPOCH_CURRENT_WEATHER = 75;
};

_airTemp = EPOCH_CURRENT_WEATHER;
_waterTemp = EPOCH_CURRENT_WEATHER/2;
_warming = true;
_wet = false;
_maxTemp = 98.6;
_increaseWet = 0;
_wetsuit = (getText(configfile >> "cfgweapons" >> uniform player >> "itemInfo" >> "uniformType") == "Neopren");

if (vehicle player == player) then {
	_playerPosATL = getPosATL player;
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

if ((getFatigue player) == 1 && _airTemp > 100) then {
	_maxTemp = _airTemp;
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
