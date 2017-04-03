/*
	Author: [Ignatz] He-Man

    Contributors: Aaron Clark - EpochMod.com

	Description:
	Check if in Service Point for A3 Epoch

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/servicepoint/EPOCH_SP_Check.sqf
*/

private ['_inSP','_vehicle','_vehName','_allRepaired'];

_vehicle = vehicle player;
if (_vehicle == player) exitwith {false};
if !(local _vehicle) exitwith {false};
if (speed _vehicle > 2 || speed _vehicle < -2) exitwith {false};
if (((getpos _vehicle) select 2) > 1) exitwith {false};
if (!(_vehicle iskindof 'ship') && (((getposasl _vehicle)  select 2) < 1)) exitwith {false};

_config = 					'CfgServicePoint' call EPOCH_returnConfig;
_servicepoints = 			getArray (_config >> worldname >> 'ServicePoints');
_servicepointDist = 		["CfgServicePoint", "ServicePointDist", 40] call EPOCH_fnc_returnConfigEntryV2;
_ServicePointClasses = 		["CfgServicePoint", "ServicePointClasses", []] call EPOCH_fnc_returnConfigEntryV2;

if (_servicepoints isequalto [] && _ServicePointClasses isequalto []) exitwith {false};
if (_vehicle == player) exitwith {false};
if !(local _vehicle) exitwith {false};
if (speed _vehicle > 2 || speed _vehicle < -2) exitwith {false};
if (((getpos _vehicle) select 2) > 1) exitwith {false};
if (!(_vehicle iskindof 'ship') && (((getposasl _vehicle)  select 2) < 1)) exitwith {false};
_inSP = false;
if (({player distance _x < _servicepointDist} count _servicepoints > 0)) then {
	_inSP = true;
};
if (!_inSP) then {
	if !(_ServicePointClasses isequalto []) then {
		_nearClasses = nearestobjects [_vehicle,_ServicePointClasses,_servicepointDist];
		if !(_nearClasses isequalto []) then {
			_inSP = true;
		};
	};
};
_inSP
