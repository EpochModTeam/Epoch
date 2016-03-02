private ["_vehicle","_value"];
_vehicle = _this select 0;
_value = _this select 1;
_player = _this select 2;
if (isNull _vehicle) exitWith{};

if !([_player,  _this select 3] call EPOCH_server_getPToken) exitWith{};
if (_player distance _vehicle > 20) exitWith{};
// if (vehicle _player != _player) exitWith{};

if ((_value select 0) isEqualTo "ALL") then {
	_vehicle setDamage 0;
} else {
	if (local _vehicle) then {
		_vehicle setHitIndex _value;
		//diag_log format["REPAIR VEHICLE: %1 server local", _vehicle];
	} else {
		[_vehicle, _value] remoteExec ['EPOCH_client_repairVehicle',(owner _vehicle)];
		//diag_log format["REPAIR VEHICLE: %1 owner: %2", _vehicle, owner _vehicle];
	};
};
_vehicle call EPOCH_server_save_vehicle;
