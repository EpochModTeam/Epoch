private ["_vehicle","_value"];
_vehicle = _this select 0;
_value = _this select 1;
_plyr = _this select 2;
if (isNull _vehicle) exitWith{};

if !([_plyr,  _this select 3] call EPOCH_server_getPToken) exitWith{};
if (_plyr distance _vehicle > 20) exitWith{};
// if (vehicle _plyr != _plyr) exitWith{};

if ((_value select 0) isEqualTo "ALL") then {
	_vehicle setDamage 0;
} else {
	if (local _vehicle) then {
		_vehicle setHitIndex _value;
		//diag_log format["REPAIR VEHICLE: %1 server local", _vehicle];
	} else {
		[["repairVehicle", [_vehicle, _value]], (owner _vehicle)] call EPOCH_sendPublicVariableClient;
		//diag_log format["REPAIR VEHICLE: %1 owner: %2", _vehicle, owner _vehicle];
	};
};
_vehicle call EPOCH_server_save_vehicle;
