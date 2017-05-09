/*
	Author: [Ignatz] He-Man

    Contributors: Aaron Clark - EpochMod.com

	Description:
	Refuel Vehicles for A3 Epoch

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/servicepoint/EPOCH_SP_Refuel.sqf
*/

private ['_vehtype','_vehName'];
params [['_vehicle',objnull],['_args',[]]];
_args params [['_costs',0],['_updateInterval',1],['_amount',0.1]];

if (!local _vehicle) exitWith {
	_line = 'Refuel denied - Go in as driver first!';
	[_line,5] call Epoch_message;
};
_vehtype = typeof _vehicle;
_vehName = getText(configFile >> 'cfgVehicles' >> _vehtype >> 'displayName');
if (EPOCH_playerCrypto < _costs) exitWith {
	_line = format ['You need %1 Crypto to Refuel %2', _costs,_vehName];
	[_line,5] call Epoch_message;
};
if(_costs > 0)then{
	[player,(_costs*-1),Epoch_personalToken] remoteexec ['epoch_server_paycrypto',2];
};
_vehicle engineOn false;
while {(vehicle player == _vehicle) && (local _vehicle) && (alive player)} do {
	if (speed _vehicle > 2 || speed _vehicle < -2 ) exitWith {
		_line = format ['Refueling of %1 stopped', _vehName];
		[_line,5] call Epoch_message;
	};
	_vehicle setFuel ((Fuel _vehicle)+_amount);
	if (Fuel _vehicle > 0.99) exitWith {
		_line = format ['%1 Refueled', _vehName];
		[_line,5] call Epoch_message;
	};
	uisleep _updateInterval;
};
