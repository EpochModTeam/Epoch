private ["_owner","_vehicle","_value"];
_vehicle = _this select 0;
_plyr = _this select 2;

if !([_plyr, _this select 3] call EPOCH_server_getPToken) exitWith{};
if (_plyr distance _vehicle > 20) exitWith{};

if (!isNull _vehicle) then {
	_value = _this select 1;
	if (local _vehicle) then {
		_vehicle setFuel _value;
	} else {
		[["fillVehicle", [_vehicle, _value]], (owner _vehicle)] call EPOCH_sendPublicVariableClient;
	};
};