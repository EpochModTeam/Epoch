/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Request mine rocks and scrap metal

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/EPOCH_mineRocks.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_currentPos","_found","_foundIndex","_getWorldTypes","_object","_objects","_worldTypes"];
//[[[end]]]
if ((diag_tickTime - EPOCH_lastMineRocks) >= 2) then {
	EPOCH_lastMineRocks = diag_tickTime;
	if (random 1 < 0.16) then {

		_currentPos = player modelToWorld[0, 5, 0];
		if !(surfaceIsWater _currentPos) then {
			_currentPos = ATLtoASL _currentPos;
		};

		_objects = lineIntersectsWith[eyePos player, _currentPos, player, objNull, true];
		_object = objNull;

		_found = false;
		_foundIndex = -1;
		{
			_worldTypes = ["rock","cinder","wreck"];
			_getWorldTypes = [_x, _worldTypes] call EPOCH_worldObjectType;
			{
				if (_getWorldTypes param [_worldTypes find _x, false]) exitWith {
					_found = true;
					_foundIndex = _forEachIndex - 1;
				};
			} forEach _worldTypes;
			if (_found)exitWith{_object = _x};
		}foreach _objects;

		if (!isNull _object) then {
			if (alive _object) then {
				[_object, _foundIndex, player, Epoch_personalToken] remoteExec ["EPOCH_server_mineRocks",2];
			};
		};
	};
};
