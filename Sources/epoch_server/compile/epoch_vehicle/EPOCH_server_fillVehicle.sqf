private ["_owner","_vehicle","_value"];
_vehicle = _this select 0;
_player = _this select 2;

if !([_player, _this select 3] call EPOCH_server_getPToken) exitWith{};
if (_player distance _vehicle > 20) exitWith{};

if (!isNull _vehicle) then {
	_value = _this select 1;
	if (local _vehicle) then {
		_vehicle setFuel _value;
	} else {
		// send to player
		[_vehicle, _value] remoteExec ['EPOCH_client_fillVehicle',(owner _vehicle)];
	};
};
