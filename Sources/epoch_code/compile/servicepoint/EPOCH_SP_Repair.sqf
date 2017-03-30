private ['_Ignatz_vehicle','_args','_servicePoint','_costs','_repairTime','_type','_name','_hitpoints','_allRepaired'];
_Ignatz_vehicle = _this select 0;
if (!local _Ignatz_vehicle) exitWith {
	diag_log format['Error: called service_point_repair.sqf with non-local vehicle: %1', _Ignatz_vehicle]
};
_args = _this select 1;
_costs = _args select 0;
_repairTime = _args select 1;
_type = typeOf _Ignatz_vehicle;
_name = getText(configFile >> 'cfgVehicles' >> _type >> 'displayName');
if (EPOCH_playerCrypto < _costs) exitWith {
	_line = format ['You need %1 Crypto to Repair %2', _costs,_name];
	[_line,5] call Epoch_message; 
};
if(_costs > 0)then{
	[player,(_costs*-1),Epoch_personalToken] remoteexec ['epoch_server_paycrypto',2];
};
_Ignatz_vehicle engineOn false;
_repaired = []; 
_allRepaired = true;
_allHitPointsDamage = getAllHitPointsDamage _Ignatz_vehicle;
{
	if ((vehicle player != _Ignatz_vehicle) || (!local _Ignatz_vehicle) || speed _Ignatz_vehicle < -2 || speed _Ignatz_vehicle > 2) exitWith {
		_allRepaired = false;
		_line = format ['Repairing of %1 stopped', _name];
		[_line,5] call Epoch_message; 
	};
	if (!(_x in _repaired) && !(_x isequalto "") && (_allHitPointsDamage select 2 select _foreachindex) > 0) then {
		_partName = toarray _x; 
		_partName set [0,20]; 
		_partName set [1,45]; 
		_partName set [2,20]; 
		_partName = toString _partName; 
		_Ignatz_vehicle setHitPointDamage [_x,0]; 
		_line = format ['Repairing%1 ...', _partName]; 
		[_line,5] call Epoch_message;  
		_repaired pushback _x; 
		uisleep _repairTime; 
	}; 
} foreach (_allHitPointsDamage select 0); 
if (_allRepaired) then {
	if ((damage _Ignatz_vehicle) > 0) then {
		[_Ignatz_vehicle,["ALL",0],player,Epoch_personalToken] remoteExec ["EPOCH_server_repairVehicle",2];
	};
	_pos = getposatl _Ignatz_vehicle;
	_pos set [2,(_pos select 2)+0.25];
	_Ignatz_vehicle setposatl _pos;
	_line = format ['%1 full Repaired', _name];
	[_line,5] call Epoch_message; 
};
