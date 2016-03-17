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
	_color = [2500,0,EPOCH_playerThirst,1] call EPOCH_colorRange;
	_thirst ctrlSetTextColor _color;
};

_hunger ctrlShow (EPOCH_playerHunger <= 1250);
if (ctrlShown _hunger) then {
	[_hunger,_hungry] call _fadeUI;
	_color = [5000,0,EPOCH_playerHunger,1] call EPOCH_colorRange;
	_hunger ctrlSetTextColor _color;
};

_playerOxygen = getOxygenRemaining player;
_oxygen ctrlShow (_playerOxygen < 1);
if (ctrlShown _oxygen) then {
	[_oxygen,(_playerOxygen <= 0.55)] call _fadeUI;
	_color = [1,0,_playerOxygen,1] call EPOCH_colorRange;
	_oxygen ctrlSetTextColor _color;
};

_hazzard ctrlShow (EPOCH_playerToxicity > 1);
if (ctrlShown _hazzard) then {
	[_hazzard,(EPOCH_playerToxicity >= 55)] call _fadeUI;
	_color = [0,100,EPOCH_playerToxicity,1] call EPOCH_colorRange;
	_hazzard ctrlSetTextColor _color;
};

_legDamage = player getHitPointDamage "HitLegs";
_broken ctrlShow (_legDamage >= 0.5);
if (ctrlShown _broken) then {
	[_broken,true] call _fadeUI;
	_color = [1,0,_legDamage,1] call EPOCH_colorRange;
	_broken ctrlSetTextColor _color;
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
	_color = [180,100,EPOCH_playerBloodP,1] call EPOCH_colorRange;
	_emergency ctrlSetTextColor _color;
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

onEachFrame EPOCH_onEachFrame;
