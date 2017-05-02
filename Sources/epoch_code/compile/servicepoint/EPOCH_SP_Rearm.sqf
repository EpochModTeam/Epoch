/*
	Author: [Ignatz] He-Man

    Contributors: Aaron Clark - EpochMod.com

	Description:
	Rearm Vehicles for A3 Epoch

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/servicepoint/EPOCH_SP_Rearm.sqf
*/

//[[[cog import generate_private_arrays ]]]
private ["_line","_magname","_vehName","_vehtype"];
//[[[end]]]
params ['_vehicle','_ammotype','_turret','_reloagmags','_ammocount','_costs'];

if (!local _vehicle) exitWith {
	_line = 'Rearm denied - Go in as driver first!';
	[_line,5] call Epoch_message;
};
_vehtype = typeof _vehicle;
_vehName = getText(configFile >> 'cfgVehicles' >> _vehtype >> 'displayName');
if (EPOCH_playerCrypto < _costs) exitWith {
	_line = format ['You need %1 Crypto to Rearm %2', _costs,_vehName];
	[_line,5] call Epoch_message;
};
if(_costs > 0)then{
	[player,(_costs*-1),Epoch_personalToken] remoteexec ['epoch_server_paycrypto',2];
};
_vehicle removeMagazinesTurret [_ammotype,_turret];
for '_i' from 1 to _reloagmags do {
	_vehicle addMagazineTurret [_ammotype, _turret, _ammocount];
};
_magname = getText (configFile >> 'CfgMagazines' >> _ammotype >> 'displayName');
if (_magname isequalto '') then {
	_magname = _ammotype;
};
_line = format ['%1 rearmed with %2', _vehName, _magname];
[_line,5] call Epoch_message;
