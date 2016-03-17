/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Request mine rocks and scrap metal

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_code/compile/EPOCH_mineRocks.sqf
*/
private ["_currentPos","_found","_foundIndex","_start","_end","_p3dName","_finalConfig","_str","_findStart","_object","_objects","_config"];

if ((diag_tickTime - EPOCH_lastMineRocks) >= 2) then {
	EPOCH_lastMineRocks = diag_tickTime;
	if (random 1 < 0.16) then {

		_currentPos = player modelToWorld[0, 5, 0];
		if !(surfaceIsWater _currentPos) then {
			_currentPos = ATLtoASL _currentPos;
		};

		_objects = lineIntersectsWith[eyePos player, _currentPos, player, objNull, true];
		_object = objNull;

		_config = 'CfgEpochClient' call EPOCH_returnConfig;

		_found = false;
		_foundIndex = -1;
		{
			if !(_x isKindOf "All") then {
				_str = str(_x);
				_worldTypes = ["rock","cinder","wreck"];
				_getWorldTypes = [_str, _worldTypes] call EPOCH_worldObjectType;
				{
					if (_getWorldTypes param [_worldTypes find _x, false]) exitWith {
						_found = true;
						_foundIndex = _forEachIndex - 1;
					};
				} forEach _worldTypes;
			};
			if (_found)exitWith{_object = _x};
		}foreach _objects;

		if (!isNull _object) then {
			if (alive _object) then {
				[_object, _foundIndex, player, Epoch_personalToken] remoteExec ["EPOCH_server_mineRocks",2];
			};
		};
	};
};
