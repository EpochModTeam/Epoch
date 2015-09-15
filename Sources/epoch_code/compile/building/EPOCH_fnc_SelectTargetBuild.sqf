private [];
if !(isNil "EPOCH_simulSwap_Lock") exitWith{ false };

if !(isNull EPOCH_Target) exitWith{ false };

if (EPOCH_playerEnergy <= 0) exitWith{ _dt = ["<t size='0.8' shadow='0' color='#99ffffff'>Need energy</t>", 0, 1, 5, 2, 0, 1] spawn bis_fnc_dynamictext; false };

_object = _this;

EPOCH_buildOption = 2;

if (isNull _object) exitWith{ false };
if ((player distance _object) > 9) exitWith { false };

if (!(_object isKindOf "ThingX") && !(_object isKindOf "Constructions_static_F") && !(_object isKindOf "Constructions_foundation_F")) exitWith{ false };


// check if another player has target
_targeter = _object getVariable["last_targeter", objNull];

if (!isNull _targeter && _targeter != player && (player distance _object > _targeter distance _object)) exitWith{ EPOCH_stabilityTarget = objNull; false };

_stability = _object getVariable["stability", 100];
if (_stability > 0) exitWith{
	if (isNull EPOCH_stabilityTarget) then {
		_object setVariable["last_targeter", player, true];
		EPOCH_stabilityTarget = _object;
	};
};

/*
if (_object isKindOf "Infostand_base_F") then {
	if (!(_object in EPOCH_SURVEY)) then {
		EPOCH_SURVEY pushBack _object;
	};
};
*/

[_object] spawn EPOCH_simulSwap;

true
