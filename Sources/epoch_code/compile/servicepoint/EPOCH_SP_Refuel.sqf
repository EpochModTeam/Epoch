private ['_vehicle','_args','_servicePoint','_costs','_updateInterval','_amount','_type','_name','_textMissing'];
_vehicle = _this select 0;
if (!local _vehicle) exitWith {};
_args = _this select 1;
_costs = _args select 0;
_updateInterval = _args select 1;
_amount = _args select 2;
_type = typeOf _vehicle;
_name = getText(configFile >> 'cfgVehicles' >> _type >> 'displayName');
if (EPOCH_playerCrypto < _costs) exitWith {
	_line = format ['You need %1 Crypto to refuel %2', _costs,_name];
	[_line,5] call Epoch_message; 
};
if(_costs > 0)then{
	[player,(_costs*-1)] remoteexec ['epoch_server_paycrypto',2];
};
_vehicle engineOn false;
if ((vehicle player != _vehicle) || (!local _vehicle) || speed _vehicle < -2 || speed _vehicle > 2) exitWith {
	_line = format ['Fueling of %1 stopped', _name];
	[_line,5] call Epoch_message; 
};
while {(vehicle player == _vehicle) && (local _vehicle)} do {
	if (speed _vehicle > 2 || speed _vehicle < -2 ) exitWith {
		_line = format ['Refueling of %1 stopped', _name];
		[_line,5] call Epoch_message; 
	};
	_vehicle setFuel ((Fuel _vehicle)+_amount);
	if (Fuel _vehicle > 0.99) exitWith {
		_line = format ['%1 Refueled', _name];
		[_line,5] call Epoch_message; 
	};
	uisleep _updateInterval;
};
