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
		_lootables = getArray(_config >> worldname >> "Wrecks");
		_cinderList = getArray(_config >> worldname >> "Cinder");
		_rocksList = getArray(_config >> worldname >> "Rocks");

		_found = false;
		_foundIndex = -1;
		{
			_str = str(_x);
			_findStart = _str find ": ";
			if (_findStart != -1) then{
				_p3dName = _str select[_findStart + 2, 999];
				_found = _p3dName in _rocksList;
				if (_p3dName in _lootables) then{
					_found = true;
					_foundIndex = 1;
				};
				if (_p3dName in _cinderList) then{
					_found = true;
					_foundIndex = 0;
				};
			};
			if (_found)exitWith{_object = _x};
		}foreach _objects;

		if (!isNull _object) then {
			if (alive _object) then {
				EPOCH_mineRocks_PVS = [_object, _foundIndex, player, Epoch_personalToken];
				publicVariableServer "EPOCH_mineRocks_PVS";
			};
		};
	};
};
