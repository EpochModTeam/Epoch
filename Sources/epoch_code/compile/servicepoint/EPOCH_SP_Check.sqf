if (vehicle player == player) exitwith {false};
if !(local vehicle player) exitwith {false};
if (speed vehicle player > 2 || speed vehicle player < -2) exitwith {false};
if (((getpos vehicle player) select 2) > 1) exitwith {false};

_config = 					'CfgServicePoint' call EPOCH_returnConfig;
_servicepoints = 			getArray (_config >> worldname >> 'ServicePoints');
_servicepointDist = 		["CfgServicePoint", "ServicePointDist", 40] call EPOCH_fnc_returnConfigEntryV2;

if (_servicepoints isequalto []) exitwith {false};
if !(({player distance _x < _servicepointDist} count _servicepoints > 0)) exitwith {false};
_Vehicle = vehicle player;
if (!(_Vehicle iskindof 'ship') && (((getposasl _Vehicle)  select 2) < 1)) exitwith {false};
true
