/*
	Author: [Ignatz] He-Man

    Contributors: Aaron Clark - EpochMod.com

	Description:
	Repair Vehicles for A3 Epoch

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/servicepoint/EPOCH_SP_Repair.sqf
*/

//[[[cog import generate_private_arrays ]]]
private ["_allHitPointsDamage","_allRepaired","_line","_partName","_pos","_repaired","_vehName","_vehtype"];
//[[[end]]]
params [['_vehicle',objnull],['_args',[]] ];
_args params [['_costs',0],['_updateInterval',1.2]];

if (!local _vehicle) exitWith {
	_line = 'Repair denied - Go in as driver first!';
	[_line,5] call Epoch_message;
};
_vehtype = typeOf _vehicle;
_vehName = getText(configFile >> 'cfgVehicles' >> _vehtype >> 'displayName');
if (EPOCH_playerCrypto < _costs) exitWith {
	_line = format ['You need %1 Crypto to Repair %2', _costs,_vehName];
	[_line,5] call Epoch_message;
};
if(_costs > 0)then{
	[player,(_costs*-1),Epoch_personalToken] remoteexec ['epoch_server_paycrypto',2];
};
_vehicle engineOn false;
_repaired = [];
_allRepaired = true;
_allHitPointsDamage = getAllHitPointsDamage _vehicle;
{
	if ((vehicle player != _vehicle) || (!local _vehicle) || speed _vehicle < -2 || speed _vehicle > 2) exitWith {
		_allRepaired = false;
		_line = format ['Repairing of %1 stopped', _vehName];
		[_line,5] call Epoch_message;
	};
	if (!(_x in _repaired) && !(_x isequalto "") && (_allHitPointsDamage select 2 select _foreachindex) > 0) then {
		_partName = toarray _x;
		_partName set [0,20];
		_partName set [1,45];
		_partName set [2,20];
		_partName = toString _partName;
		_vehicle setHitPointDamage [_x,0];
		_line = format ['Repairing%1 ...', _partName];
		[_line,5] call Epoch_message;
		_repaired pushback _x;
		uisleep _updateInterval;
	};
} foreach (_allHitPointsDamage select 0);
if (_allRepaired) then {
	if ((damage _vehicle) > 0 || {_x > 0} count ((getallhitpointsdamage _vehicle) select 2) > 0) then {
		[_vehicle,["ALL",0],player,Epoch_personalToken] remoteExec ["EPOCH_server_repairVehicle",2];
	};
	_pos = getposatl _vehicle;
	_pos set [2,(_pos select 2)+0.25];
	_vehicle setposatl _pos;
	_line = format ['%1 full Repaired', _vehName];
	[_line,5] call Epoch_message;
};
