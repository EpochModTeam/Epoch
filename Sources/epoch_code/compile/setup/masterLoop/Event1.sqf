_currentTarget = objNull;
_currentTargetMode = 0;
_cursorTarget = ([10] call EPOCH_fnc_cursorTarget);
if (!isNull _cursorTarget && {!(EPOCH_target isEqualTo _cursorTarget)}) then {
	_interactType = typeOf _cursorTarget;
	_interaction = (_cfgObjectInteractions >> _interactType);
	if (isClass(_interaction)) then {
		_currentTargetMode = getNumber (_interaction >> "interactMode");
		_allowTarget = switch (getNumber (_interaction >> "aliveState")) do {
		    case 1: {!(alive _cursorTarget)};
			case 2: {(alive _cursorTarget)};
		    default {true};
		};
		if (_allowTarget) then {
			_currentTarget = _cursorTarget;
		};
	} else {
		// AllVehicles = vehicles=0, bases=1
		if (_cursorTarget isKindOf "AllVehicles") then {
			_currentTarget = _cursorTarget;
		} else {
			if (_cursorTarget isKindOf "Constructions_modular_F" || _cursorTarget isKindOf "Constructions_static_F") then {
				_currentTargetMode = 1;
				_currentTarget = _cursorTarget;
			};
		};
	};
};
EPOCH_currentTarget = _currentTarget;
EPOCH_currentTargetMode = _currentTargetMode;

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
		["BUILD MODE: DISABLED", 5] call Epoch_message;
		EPOCH_Target = objNull;
	};
	_increaseStamina = true;

	// TODO: move back to vehicle configs
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

//_thirst ctrlShow (EPOCH_playerThirst <= 625);
/*
if (EPOCH_playerThirst <= 625) then {
	_thirst = ["topRight",_hudIndex] call epoch_getHUDCtrl;
	_hudIndex = _hudIndex + 1;

	_thirst ctrlSetText "x\addons\a3_epoch_code\Data\UI\thirst_ca.paa";
	[_thirst,_thirsty] call _scaleUI;
	_color = [2500,0,EPOCH_playerThirst,1] call EPOCH_colorRange;
	_thirst ctrlSetTextColor _color;
};

if (EPOCH_playerHunger <= 1250) then {
	_hunger = ["topRight",_hudIndex] call epoch_getHUDCtrl;
	_hudIndex = _hudIndex + 1;
	_hunger ctrlSetText "x\addons\a3_epoch_code\Data\UI\hunger_ca.paa";

	[_hunger,_hungry] call _scaleUI;
	_color = [5000,0,EPOCH_playerHunger,1] call EPOCH_colorRange;
	_hunger ctrlSetTextColor _color;
};
*/

_playerOxygen = getOxygenRemaining player;
//_oxygen ctrlShow (_playerOxygen < 1);
if (_playerOxygen < 1) then {
	_hudIndex = missionNamespace getVariable [format["EPOCH_dynHUD_%1","topRight"],1];
	_oxygen = ["topRight",_hudIndex] call epoch_getHUDCtrl;
	missionNamespace setVariable [format["EPOCH_dynHUD_%1","topRight"], _hudIndex + 1];
	_oxygen ctrlSetText "x\addons\a3_epoch_code\Data\UI\oxygen_ca.paa";

	[_oxygen,(_playerOxygen <= 0.55)] call _scaleUI;
	_color = [0,1,_playerOxygen,1] call EPOCH_colorRange;
	_oxygen ctrlSetTextColor _color;
};

// dynamic start (greater than)
{
	_x params [["_selVarName",""],["_HUDclass","topRight"],["_ctrlText",""]];
	_varIndex = EPOCH_customVars find _selVarName;
	if (_varIndex != -1) then {
		_currentVarVal = missionNamespace getVariable[format['EPOCH_player%1', _selVarName],EPOCH_defaultVars select _varIndex];
		(EPOCH_customVarLimits select _varIndex) params [["_playerLimitMax",100],["_playerLimitMin",0],["_playerWarnLimit",25],["_playerCriticalLimit",75],["_playerWarnLow",0],["_playerCriticalLow",0]];
		if (_playerLimitMax isEqualType "") then {
			_playerLimitMax = missionNamespace getVariable [_playerLimitMax, 0];
		};
		if (_playerLimitMin isEqualType "") then {
			_playerLimitMin = missionNamespace getVariable [_playerLimitMin, 0];
		};
		_warnLow = _currentVarVal < _playerWarnLow;
		_warnHigh = _currentVarVal > _playerWarnLimit;
		_criticalLow = _currentVarVal <= _playerCriticalLow;
		_criticalHigh = _currentVarVal >= _playerCriticalLimit;
		if (_warnHigh || _warnLow) then {
			_hudIndex = missionNamespace getVariable [format["EPOCH_dynHUD_%1",_HUDclass],1];
			_curCtrl = [_HUDclass,_hudIndex] call epoch_getHUDCtrl;
			missionNamespace setVariable [format["EPOCH_dynHUD_%1",_HUDclass], _hudIndex + 1];
			if (_ctrlText isEqualType []) then {
				_ctrlText = if (_warnHigh) then {_ctrlText select 0} else {_ctrlText select 1};
			};
			_curCtrl ctrlSetText _ctrlText;
			_critical = (_criticalHigh || _criticalLow);
			[_curCtrl,_critical] call _scaleUI;
			_color = [_playerLimitMin,_playerLimitMax,_currentVarVal,1] call EPOCH_colorRange;
			_curCtrl ctrlSetTextColor _color;
		};
	};
} forEach
[
	[
		'Temp',
		"topRight",
		[
			"x\addons\a3_epoch_code\Data\UI\hot_ca.paa",
			"x\addons\a3_epoch_code\Data\UI\cold_ca.paa"
		]
	],
	[
		'Hunger',
		"topRight",
		"x\addons\a3_epoch_code\Data\UI\hunger_ca.paa"
	],
	[
		'Thirst',
		"topRight",
		"x\addons\a3_epoch_code\Data\UI\thirst_ca.paa"
	],
	[	'Toxicity',
		"topRight",
		"x\addons\a3_epoch_code\Data\UI\hazzard_ca.paa"
	],
	[
		'Wet',
		"topRight",
		"x\addons\a3_epoch_code\Data\UI\wet_ca.paa"
	],
	[
		'BloodP',
		"topRight",
		"x\addons\a3_epoch_code\Data\UI\bleeding_ca.paa"
	],
	[
		'Alcohol',
		"topRight",
		"x\addons\a3_epoch_code\Data\UI\drunk_ca.paa"
	],
	[
		'Soiled',
		"topRight",
		"x\addons\a3_epoch_code\Data\UI\soiled_ca.paa"
	],
	[
		'Radiation',
		"topRight",
		"x\addons\a3_epoch_code\Data\UI\rads_ca.paa"
	]
];
// dynamic end

_legDamage = player getHitPointDamage "HitLegs";
// _broken ctrlShow (_legDamage >= 0.5);
if (_legDamage >= 0.5) then {
	_hudIndex = missionNamespace getVariable [format["EPOCH_dynHUD_%1","topRight"],1];
	_broken = ["topRight",_hudIndex] call epoch_getHUDCtrl;
	missionNamespace setVariable [format["EPOCH_dynHUD_%1","topRight"], _hudIndex + 1];
	_broken ctrlSetText "x\addons\a3_epoch_code\Data\UI\broken_ca.paa";
	[_broken,true] call _scaleUI;
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
// _emergency ctrlShow _critical;
if (_critical) then {
	_hudIndex = missionNamespace getVariable [format["EPOCH_dynHUD_%1","topRight"],1];
	_emergency = ["topRight",_hudIndex] call epoch_getHUDCtrl;
	missionNamespace setVariable [format["EPOCH_dynHUD_%1","topRight"], _hudIndex + 1];
	_emergency ctrlSetText "x\addons\a3_epoch_code\Data\UI\bleeding_ca.paa";
	[_emergency,(EPOCH_playerBloodP > 140)] call _scaleUI;
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

// blank out unused hud elements

_hudIndex = missionNamespace getVariable [format["EPOCH_dynHUD_%1","topRight"],1];
for "_i" from _hudIndex to 9 do {
    _c = ["topRight",_i] call epoch_getHUDCtrl;
    _c ctrlSetText "";
};
missionNamespace setVariable [format["EPOCH_dynHUD_%1","topRight"], nil];
