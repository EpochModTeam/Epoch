_out = [false, false, false];

if !(isNil "EPOCH_simulSwap_Lock") exitWith{ _out };
if !(isNull EPOCH_Target) exitWith{ _out };
if (EPOCH_playerEnergy <= 0) exitWith{ _dt = ["<t size='0.8' shadow='0' color='#99ffffff'>Need energy</t>", 0, 1, 5, 2, 0, 1] spawn bis_fnc_dynamictext; _out };

params ["_object"];

if (isNull _object) exitWith{ _out };
if ((player distance _object) > 9) exitWith { _out };

if !(EPOCH_buildMode > 0) exitWith {_out};

_objType = typeOf _object;
_config = 'CfgBaseBuilding' call EPOCH_returnConfig;

_out = 
[
		!(getArray(_config >> _objType >> "upgradeBuilding") isEqualTo []),
		!(getArray(_config >> _objType >> "removeParts") isEqualTo []),
		(_object isKindOf "ThingX")
];
_out
