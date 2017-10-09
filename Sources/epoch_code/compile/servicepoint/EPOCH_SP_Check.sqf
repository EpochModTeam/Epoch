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

//[[[cog import generate_private_arrays ]]]
private ["_ServicePointClasses","_config","_inSP","_nearClasses","_servicepointDist","_servicepoints","_vehicle"];
//[[[end]]]

_vehicle = vehicle player;
if (_vehicle == player) exitwith {false};
// if !(local _vehicle) exitwith {false};
if (speed _vehicle > 2 || speed _vehicle < -2) exitwith {false};
if (((getpos _vehicle) select 2) > 1) exitwith {false};
if (!(_vehicle iskindof 'ship') && (((getposasl _vehicle)  select 2) < 1)) exitwith {false};

_config = 					'CfgServicePoint' call EPOCH_returnConfig;
_servicepoints = 			getArray (_config >> worldname >> 'ServicePoints');
_servicepointDist = 		["CfgServicePoint", "ServicePointDist", 40] call EPOCH_fnc_returnConfigEntryV2;
_ServicePointClasses = 		["CfgServicePoint", "ServicePointClasses", []] call EPOCH_fnc_returnConfigEntryV2;

if (_servicepoints isequalto [] && _ServicePointClasses isequalto []) exitwith {false};

_inSP = false;
{
	if (count _x > 3) then {
		_x params ["_pos","_dist","_vehtypes"];
		{
			if (_vehicle iskindof _x && _vehicle distance _pos < _dist) exitwith {
				_inSP = true;
			};
		} foreach _vehtypes;
	}
	else {
		if (_vehicle distance _x < _servicepointDist) then {
			_inSP = true;
		};
	};
	if (_inSP) exitwith {};
} foreach _servicepoints;

if (!_inSP) then {
	if !(_ServicePointClasses isequalto []) then {
		_nearClasses = nearestobjects [_vehicle,_ServicePointClasses,_servicepointDist];
		if !(_nearClasses isequalto []) then {
			_inSP = true;
		};
	};
};
_inSP
