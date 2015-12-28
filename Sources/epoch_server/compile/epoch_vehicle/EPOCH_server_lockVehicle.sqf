private ["_vehicle","_value"];

_vehicle =  _this select 0;
_player =  _this select 2;

if (isNull _vehicle) exitWith {};

// Token check
if !([_player,_this select 3] call EPOCH_server_getPToken) exitWith {};
if (_player distance _vehicle > 20) exitWith {};

// Group access
_plyrUID = getPlayerUID _player;
_plyrGroup = _player getVariable["GROUP", ""];

_lockOwner = _plyrUID;
if (_plyrGroup != "") then {
	_lockOwner = _plyrGroup;
};

_lockedOwner = "-1";
_vehSlot = _vehicle getVariable["VEHICLE_SLOT", "ABORT"];
_vehLockHiveKey = format["%1:%2", (call EPOCH_fn_InstanceID), _vehSlot];
if (_vehSlot != "ABORT") then {
	_response = ["VehicleLock", _vehLockHiveKey] call EPOCH_fnc_server_hiveGETRANGE;
	if ((_response select 0) == 1 && typeName(_response select 1) == "ARRAY" && !((_response select 1) isEqualTo[])) then {
		_lockedOwner = _response select 1 select 0;
	};
};

// get locked state
_isLocked = locked _vehicle in[2, 3];

_driver = driver _vehicle;
// check if player is driver
_isDriver = _player isEqualTo _driver;
// check if player is inside vehicle without driver
_isInsideVehicle = _player in (crew _vehicle);

// Lockout mech
if (!_isLocked || _lockedOwner == _lockOwner || _lockedOwner == "-1" || _isDriver || (isNull(_driver) && _isInsideVehicle)) then {

	_value = _this select 1;

	if (_value) then {
		["VehicleLock", _vehLockHiveKey, EPOCH_vehicleLockTime, [_lockOwner]] call EPOCH_fnc_server_hiveSETEX;
	};

	if (local _vehicle) then {
		_vehicle lock _value;
	} else {
		if (_value) then {
			[["lockVehicle", _vehicle], (owner _vehicle)] call EPOCH_sendPublicVariableClient;
		} else {
			[["unlockVehicle", _vehicle], (owner _vehicle)] call EPOCH_sendPublicVariableClient;
		};
	};
};
