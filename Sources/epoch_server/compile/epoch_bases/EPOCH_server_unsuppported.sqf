/*
Building - Unsupported building check

Epoch Mod - EpochMod.com
All Rights Reserved.
*/

private["_worldspace", "_newObj", "_class", "_objSlot", "_config", "_isSupported", "_lastPosition", "_currentPosition", "_objectPos"];

if !(isNil "EPOCH_unsupportedCheckRunning") exitWith{ diag_log "UnsupportedCheck: Already running aborted"};
EPOCH_unsupportedCheckRunning = true;

// Check unsupported
_start = diag_tickTime; 
_simulatedCount = 0; 
_stableCount = 0;
{
	if (!isNull _x) then {

		_config = (configFile >> "CfgVehicles" >> (typeOf _x) >> "simulClass");
		if (isText(_config)) then {

			_objectPos = getPosASL _x;
			_isSupported = isTouchingGround _x;
			if (!_isSupported) then {
				_isSupported = if (terrainIntersectASL[_objectPos, [_objectPos select 0, _objectPos select 1, (_objectPos select 2) - 1]]) then { true } else {
					lineIntersects[_objectPos, [_objectPos select 0, _objectPos select 1, (_objectPos select 2) - 5], _x, objNull]
				};
			};
			if (!_isSupported) then {
				_class = getText(_config);
				_objSlot = _x getVariable["BUILD_SLOT", -1];
				if (_objSlot != -1) then {
					_vDir = vectordir _x;
					_vUP = vectorup _x;
					_plyrUID = _x getVariable["BUILD_OWNER", "-1"];
					_slot = _x getVariable["EPOCH_secureStorage", "-1"];
					deleteVehicle _x;
					_newObj = createVehicle[_class, _objectPos, [], 0, "CAN_COLLIDE"];
					_newObj setVariable["BUILD_SLOT", _objSlot, true];
					_newObj setVectorDirAndUp[_vDir, _vUP];
					_newObj setposASL _objectPos;
					_newObj setVariable["BUILD_OWNER", _plyrUID, true];
					_newObj setVariable["EPOCH_secureStorage", _slot];
					_newObj setVelocity[0, 0, -1];
					_simulatedCount = _simulatedCount + 1;
					uiSleep 1;
				};
			} else {
				_stableCount = _stableCount + 1;
			};
		};
	};
} forEach(allMissionObjects "Constructions_static_F");
diag_log format["Speed %1 Count %2  Stable %3", (diag_tickTime - _start), _simulatedCount, _stableCount];
EPOCH_unsupportedCheckRunning = nil;