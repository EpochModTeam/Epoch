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
private ["_object","_foundIndex","_found","_str","_objects","_lootables","_currentPos","_p3dName","_findStart","_config","_cinderList","_rocksList"];

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
				_findStart = _str find ": ";
				if (_findStart != -1) then{

					_start = _findStart + 2;
					_end = (_str find ".") - _start;
					_p3dName = _str select[_start, _end];
					if (_p3dName find " " != -1) then {
						(_p3dName splitString " ") joinString "_"; // replace spaces with underscores
					};
					_finalConfig = (_config >> "WorldInteractions" >> (_p3dName + "_p3d"));

					_found = (getNumber(_finalConfig >> "rock") == 1);
					if (getNumber(_finalConfig >> "wreck") == 1) then{
						_found = true;
						_foundIndex = 1;
					};
					if (getNumber(_finalConfig >> "cinder") == 1) then{
						_found = true;
						_foundIndex = 0;
					};
				};
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
