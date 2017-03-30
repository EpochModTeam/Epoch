params ['_vehicle','_ammotype','_turret','_reloagmags','_ammocount','_costs'];
private ['_magname'];
_vehtype = typeof _vehicle;
_VehName = getText(configFile >> 'cfgVehicles' >> _vehtype >> 'displayName');
if (!local _vehicle) exitWith {
	_line = 'Rearm denied - Vehicle is not local to you!';
	[_line,5] call Epoch_message; 
};
if(count (crew _vehicle) > 1) exitWith {
	_line = 'Rearm denied - All Passengers must exit the Vehicle!';
	[_line,5] call Epoch_message; 
};
if (EPOCH_playerCrypto < _costs) exitWith {
	_line = format ['You need %1 Crypto to re-arm %2', _costs,_VehName];
	[_line,5] call Epoch_message; 
};

if(_costs > 0)then{
	[player,(_costs*-1)] remoteexec ['epoch_server_paycrypto',2];
};
_vehicle removeMagazinesTurret [_ammotype,_turret];
for '_i' from 1 to _reloagmags do {
	_vehicle addMagazineTurret [_ammotype, _turret, _ammocount];
};	
_magname = getText (configFile >> 'CfgMagazines' >> _ammotype >> 'displayName');
if (_magname isequalto '') then {
	_magname = _ammotype;
};
_line = format ['%1 rearmed with %2', _VehName, _magname];
[_line,5] call Epoch_message; 
