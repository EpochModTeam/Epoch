/*
	Author: He-Man - Ignatz-Gaming

    Contributors:

	Description:
	Check for repairable / replaceable and removeable Vehicle-parts

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/vehicles/EPOCH_client_VehicleMaintananceCheck.sqf
*/
private ["_veh","_config","_VehicleRepairs","_repairs","_removes","_replaces","_wheels","_wheelcounter","_torepair","_HitPointName","_Hit","_wheel","_repairarrays"];
_veh = _this;
_config = 'CfgEpochClient' call EPOCH_returnConfig;
_VehicleRepairs = getArray (_config >> "VehicleRepairs");
_repairs = [];
_removes = [];
_replaces = [];
_wheels = getnumber (configfile >> "cfgvehicles" >> (typeof _veh) >> "numberPhysicalWheels");
if (_veh iskindof "ebike_epoch") then {
	_wheels = 2;
};
_wheelcounter = 0;
_torepair = (getAllHitPointsDamage _veh) select 0;
{
	_HitPointName = _x;
	_Hit = (getAllHitPointsDamage _veh) select 2 select _foreachindex;
	{
		_x params ["_searchedhit","_limit1","_limit2"];
		if (_searchedhit isequalto _HitPointName) then {
			_wheel = ["wheel",tolower _searchedhit] call bis_fnc_instring;
			if (_wheel) then {
				_wheelcounter = _wheelcounter + 1;
			};
			if (_wheel && _wheelcounter > _wheels) exitwith {};
			if (_Hit >= _limit2) exitwith {
				_replaces pushback _searchedhit;
			};
			if (_Hit >= _limit1) exitwith {
				_repairs pushback _searchedhit;
			};
			if !((_veh getvariable ["vehicle_slot","-1"]) isequalto "-1") then {
				if (_searchedhit in ["HitLFWheel","HitLF2Wheel","HitLMWheel","HitLBWheel","HitRFWheel","HitRF2Wheel","HitRMWheel","HitRBWheel","HitEngine"]) then {
					_removes pushback _searchedhit;
				};
			};
		}
		else {
			if (_searchedhit isequalto "glass") then {
				if ("glass" in _repairs) exitwith {};
				_glass = ["glass",tolower _HitPointName] call bis_fnc_instring;
				if (_glass) then {
					if (_Hit >= _limit1) exitwith {
						_repairs pushback _searchedhit;
					};
				};
			};
		};
	} foreach _VehicleRepairs;
} foreach ((getAllHitPointsDamage _veh) select 0);

{
	if (_x in _repairs || _x in _replaces) then {
		_torepair = _torepair - [_x];
	}
	else {
		if (["glass",tolower _x] call Bis_fnc_instring) then {
			_torepair = _torepair - [_x];
		};
	};
} foreach ((getAllHitPointsDamage _veh) select 0);

if !(_torepair isequalto []) then {
	_repairarrays = [];
	{
		_repairarrays pushback [_x,0];
	} foreach _torepair;
	if (local _veh) then {
		[_veh, _repairarrays] call EPOCH_client_repairVehicle;
	} else {
		[_veh,_repairarrays,player,Epoch_personalToken] remoteExec ["EPOCH_server_repairVehicle",2];
	};
};

EPOCH_VehicleRepairs = [_repairs,_removes,_replaces];