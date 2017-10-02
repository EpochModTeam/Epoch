/*
	Author: He-Man - Ignatz-Gaming

    Contributors:

	Description:
	Repair / replac and remove Vehicle-parts

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/vehicles/EPOCH_client_VehicleMaintananceDo.sqf
*/
private ["_secondlocalcheck","_repairarrays","_config","_VehicleRepairs","_reqiredMat","_searchname","_line","_returnmat"];
params ["_veh","_do","_hitpointname"];
_secondlocalcheck = false;
_returnmat = "";
_repairarrays = [];
_config = 'CfgEpochClient' call EPOCH_returnConfig;
_VehicleRepairs = getArray (_config >> "VehicleRepairs");
if (isnull _veh) exitwith {
	['Error - No Vehicle found',5] call Epoch_message;
};
if !(alive _veh) exitwith {
	['Error - Vehicle already dead',5] call Epoch_message;
};

if (EPOCH_Vehicle_MaintainLock) exitwith {};
EPOCH_Vehicle_MaintainLock = true;

switch _do do {
	case 'repair': {
		_reqiredMat = "";
		_searchname = _hitpointname;
		if (["glass",tolower _hitpointname] call Bis_fnc_instring) then {
			_searchname = "glass";
		};
		{
			_x params ["_name","","","_repairmat"];
			if (_searchname isequalto _name) exitwith {
				_reqiredMat = _repairmat;
			};
		} foreach _VehicleRepairs;
		if (_reqiredMat isequalto "") exitwith {
			['Error - Can not find required Material',5] call Epoch_message;
		};
		if !(_reqiredMat in (magazines player)) exitwith {
			_line = format ['You need %1 to repair',_reqiredMat call EPOCH_itemDisplayName];
			[_line,5] call Epoch_message;
		};
		player removemagazine _reqiredMat;
		if (_hitpointname isequalto "glass") then {
			{
				if (["glass",tolower _x] call Bis_fnc_instring) then {
					_repairarrays pushback [_x,0];
				};
			} foreach ((getAllHitPointsDamage _veh) select 0);
		}
		else {
			_repairarrays pushback [_hitpointname,0];
		};
	};
	case 'replace': {
		_reqiredMat = "";
		_searchname = _hitpointname;
		if (["glass",tolower _hitpointname] call Bis_fnc_instring) then {
			_searchname = "glass";
		};
		{
			_x params ["_name","","","","_replacemat"];
			if (_searchname isequalto _name) exitwith {
				_reqiredMat = _replacemat;
			};
		} foreach _VehicleRepairs;
		if (_reqiredMat isequalto "") exitwith {
			['Error - Can not find required Material',5] call Epoch_message;
		};
		if !(_reqiredMat in (magazines player)) exitwith {
			_line = format ['You need %1 to repair',_reqiredMat call EPOCH_itemDisplayName];
			[_line,5] call Epoch_message;
		};
		player removemagazine _reqiredMat;
		if (_hitpointname isequalto "glass") then {
			{
				if (["glass",tolower _x] call Bis_fnc_instring) then {
					_repairarrays pushback [_x,0];
				};
			} foreach ((getAllHitPointsDamage _veh) select 0);
		}
		else {
			_repairarrays pushback [_hitpointname,0];
		};
	};
	case 'remove': {
		if !(local _veh) exitwith {
			_line = 'Error - You must get into drivers seat first!';
			['Error - You must get into drivers seat first!',5] call Epoch_message;
		};
		_searchname = _hitpointname;
		{
			_x params ["_name","","","","_replacemat"];
			if (_searchname isequalto _name) exitwith {
				_returnmat = _replacemat;
			};
		} foreach _VehicleRepairs;
		if (_returnmat isequalto "") exitwith {
			['Error - Could not find Return Material!',5] call Epoch_message;
		};
		_repairarrays pushback [_hitpointname,1];
		_secondlocalcheck = true;
	};
};

if !(_repairarrays isequalto []) then {
	player playMove 'AinvPknlMstpSnonWrflDnon_medic0';
	player playMove 'AinvPknlMstpSnonWrflDnon_medicEnd';
	_veh say3d 'vehicle_repair';
	uisleep 5;
	if (_secondlocalcheck && !local _veh) exitwith {
		['Vehicle owner Changed - Go in as driver and try again!',5] call Epoch_message;
	};
	if !(_returnmat isequalto "") then {
		_returnmat call EPOCH_fnc_addItemOverflow;
	};
	if (local _veh) then {
		[_veh, _repairarrays] call EPOCH_client_repairVehicle;
	} else {
		[_veh,_repairarrays,player,Epoch_personalToken] remoteExec ["EPOCH_server_repairVehicle",2];
	};
};

EPOCH_Vehicle_MaintainLock = false;
