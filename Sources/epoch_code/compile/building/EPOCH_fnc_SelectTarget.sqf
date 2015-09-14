private [];
if !(isNil "EPOCH_simulSwap_Lock") exitWith{ false };

if !(isNull EPOCH_Target) exitWith{ false };

if (EPOCH_playerEnergy <= 0) exitWith{ _dt = ["<t size='0.8' shadow='0' color='#99ffffff'>Need energy</t>", 0, 1, 5, 2, 0, 1] spawn bis_fnc_dynamictext; false };

_object = _this;

if (isNull _object) exitWith{ false };
if ((player distance _object) > 9) exitWith { false };

_objType = typeOf _object;

_isFoundation = _object isKindOf "Constructions_foundation_F";
_isJammer = _object isKindOf "PlotPole_EPOCH";
_isStorage = _object isKindOf "Buildable_Storage";

if (!(_object isKindOf "ThingX") && !(_object isKindOf "Constructions_static_F") && !_isFoundation && !_isStorage && !_isJammer) exitWith{ false };

_dialog = "InteractBaseBuilding";
_handled = createdialog _dialog;

// disable actions if no upgrade options

_config = 'CfgBaseBuilding' call EPOCH_returnConfig;

_upgrade = getArray(_config >> _objType >> "upgradeBuilding");
if (_upgrade isEqualTo[]) then{
	ctrlEnable[2400, false];
};
_remove = getArray(_config >> _objType >> "removeParts");
if (_remove isEqualTo[]) then{
	ctrlEnable[2401, false];
};

// disable Move option if foundation or jammer
if (_isFoundation || _isJammer || _isStorage) then{
	ctrlEnable[2402, false];
};

true
