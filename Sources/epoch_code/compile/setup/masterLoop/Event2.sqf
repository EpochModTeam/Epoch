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

// Sets visual effect
if (EPOCH_playerAlcohol > 20) then {
	_drunkVal = linearConversion [0,100,EPOCH_playerAlcohol,0.1,1,true];
	[(round(_drunkVal * 10)/10), 2] call epoch_setDrunk;
} else {
	[0, 2] call epoch_setDrunk;
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
		_dt = ["<t size = '0.8' shadow = '0' color = '#99ffffff'>Build Mode Disabled: Need Energy< / t>", 5] call Epoch_dynamicText;
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
