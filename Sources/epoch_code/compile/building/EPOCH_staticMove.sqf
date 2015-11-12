private["_allowedSnapObjects", "_currentZoffset", "_nearestObject", "_pOffset", "_snapPos", "_snapPosition", "_snapType", "_snapDistance", "_prevSnapDistance", "_pos2", "_dir", "_snapPointsPara", "_snapPointsPerp", "_distance", "_objSlot", "_currentTarget", "_allowedSnapPoints", "_snapObjects", "_class", "_buildingPos"];
if !(isNil "EPOCH_simulSwap_Lock") exitWith{};

_object = _this select 0;
_item = _this select 1;
if (isNull _object) exitWith{ EPOCH_target = objNull; };

if (EPOCH_playerEnergy <= 0) exitWith{
	_dt = ["<t size = '0.8' shadow = '0' color = '#99ffffff'>Need Energy</t>", 0, 1, 5, 2, 0, 1] spawn bis_fnc_dynamictext;
};
if !("" call EPOCH_isBuildAllowed) exitWith{};
EPOCH_simulSwap_Lock = true;

_objType = typeOf _object;

_energyCost = getNumber(configfile >> "cfgVehicles" >> _objType >> "energyCost");
if (_energyCost == 0) then {
	_energyCost = 0.1;
};

_class = getText(configfile >> "cfgVehicles" >> _objType >> "GhostPreview");
_maxHeight = getNumber(configfile >> "cfgVehicles" >> _objType >> "maxHeight");
_simulClass = getText(configFile >> "CfgVehicles" >> _objType >> "simulClass");
_snapChecks = getArray(configFile >> "CfgSnapChecks" >> _objType >> "nails");
_maxSnapDistance = 1;
_lastCheckTime = diag_tickTime;
_stabilityCheck = false;

// force sim check if object has sim class and default max height to 9m if not already specified
if (_simulClass != "") then {
	_stabilityCheck = true;
	if (_maxHeight == 0) then {
		_maxHeight = 500;
	};
};

if (_class != "") then {

	_objSlot = _object getVariable["BUILD_SLOT", -1];

	deleteVehicle _object;

	_pos2 = player modelToWorldVisual[EPOCH_X_OFFSET, EPOCH_Y_OFFSET, EPOCH_Z_OFFSET];

	EPOCH_target = createVehicle[_class, _pos2, [], 0, "CAN_COLLIDE"];
	EPOCH_TEMPOBJ_PVS = EPOCH_target;
	publicVariableServer "EPOCH_TEMPOBJ_PVS";

	if (_pos2 select 2 > _maxHeight) then {
		_pos2 set[2, _maxHeight];
	};

	_pos2ATL = _pos2;
	if (surfaceIsWater _pos2ATL) then {
		_pos2ATL = ASLtoATL _pos2ATL;
	};
	EPOCH_target setposATL _pos2ATL;

	EPOCH_target attachTo[player];
	_currentTarget = EPOCH_target;

	if (_objSlot != -1) then {
		_currentTarget setVariable["BUILD_SLOT", _objSlot, true];
	};

	_allowedSnapPoints = getArray(configfile >> "cfgVehicles" >> _class >> "allowedSnapPoints");
	_allowedSnapObjects = getArray(configfile >> "cfgVehicles" >> _class >> "allowedSnapObjects");

	_currentOffSet = [];
	EP_snap = objNull;
	EP_snapPos = [0, 0, 0];
	_isSnap = false;

	_EPOCH_1 = diag_tickTime;
	_nearestObjects = [];

	while {EPOCH_target == _currentTarget} do {

		_rejectMove = false;
		if ((diag_tickTime - _lastCheckTime) > 10) then {
			_lastCheckTime = diag_tickTime;
			_rejectMove = !(_objType call EPOCH_isBuildAllowed);
		};
		if (_rejectMove) exitWith{
			deleteVehicle EPOCH_target;
		};

		_offSet = [EPOCH_X_OFFSET, EPOCH_Y_OFFSET, EPOCH_Z_OFFSET];
		_pos2 = player modelToWorldVisual _offSet;

		if (surfaceIsWater _pos2) then {
			_pos2 set[2, ((getPosASL player) select 2) + EPOCH_Z_OFFSET];
		};

		if !(_currentOffSet isEqualTo _offSet) then {
			_currentOffSet = _offSet;
			{
				detach _x;
			} forEach attachedObjects player;

			if (_pos2 select 2 > _maxHeight) then {
				_pos2 set[2, _maxHeight];
			};
			_pos2ATL = _pos2;
			if (surfaceIsWater _pos2ATL) then {
				_pos2ATL = ASLtoATL _pos2ATL;
			};

			EPOCH_target setposATL _pos2ATL;
			EPOCH_target attachTo[player];
		};

		if (EPOCH_space) then {
			_dir2 = [vectorDir player, EPOCH_buildDirection] call EPOCH_returnVector;
			_up2 = (vectorUp player);
			EPOCH_space = false;
			EPOCH_target setVectorDirAndUp [_dir2,_up2];
		};

		{
			_nearestObject = _x;
			if !(isNull EP_snap) then {
				if ((_pos2 distance EP_snapPos) < _maxSnapDistance) then {
					_nearestObject = EP_snap;
				};
			};

			if (!isNull _nearestObject && _nearestObject isEqualTo _x) then {

				_isSnap = false;
				_snapPosition = [0, 0, 0];
				_snapConfig = configfile >> "cfgVehicles" >> (typeOf _nearestObject);
				_snapPointsPara = getArray(_snapConfig >> "snapPointsPara");
				_snapPointsPerp = getArray(_snapConfig >> "snapPointsPerp");

				// base line for z height offset
				_baselineSnapPos = _nearestObject modelToWorldVisual [0,0,0];

				if (EPOCH_buildMode == 1) then {
					{
						if (_x in _allowedSnapPoints) then {
							_pOffset = _nearestObject selectionPosition _x;
							_snapPos = _nearestObject modelToWorldVisual _pOffset;
							if (surfaceIsWater _snapPos) then {
								_snapPos set[2, ((getPosASL _nearestObject) select 2) + (_pOffset select 2)];
							};
							_snapDistance = _pos2 distance _snapPos;
							if (_snapDistance < _maxSnapDistance) exitWith{
								_isSnap = true;
								_snapPosition = _snapPos;
								_snapType = "para";
							};
						};
					} forEach _snapPointsPara;

					{
						if (_x in _allowedSnapPoints) then {
							_pOffset = _nearestObject selectionPosition _x;
							_snapPos = _nearestObject modelToWorldVisual _pOffset;
							if (surfaceIsWater _snapPos) then {
								_snapPos set[2, ((getPosASL _nearestObject) select 2) + (_pOffset select 2)];
							};
							_snapDistance = _pos2 distance _snapPos;
							if (_snapDistance < _maxSnapDistance) exitWith{
								_isSnap = true;
								_snapPosition = _snapPos;
								_snapType = "perp";
							};
						};
					} forEach _snapPointsPerp;
				};

				_distance = _pos2 distance _currentTarget;

				if (_isSnap && _distance < 5) then {

					EP_snap = _nearestObject;
					EP_snapPos = _snapPosition;

					_direction = getDir _nearestObject;
					if (_snapType == "perp") then {
						_snapPos1 = [_snapPosition select 0, _snapPosition select 1, 0];
						_pos_snapObj = getposATL _nearestObject;
						_pos_snapObj set[2, 0];

						_direction = _direction - ([_snapPos1, _pos_snapObj] call BIS_fnc_dirTo);
					}
					else {
						_direction = 0;
					};
					if (EPOCH_snapDirection > 0) then {
						if (EPOCH_snapDirection == 1) then {
							_direction = _direction + 90;
						};
						if (EPOCH_snapDirection == 2) then {
							_direction = _direction + 180;
						};
						if (EPOCH_snapDirection == 3) then {
							_direction = _direction + 270;
						};
					};
					if (_direction > 360) then {
						_direction = _direction - 360;
					};
					if (_direction < 0) then {
						_direction = 360 + _direction;
					};

					if !(attachedObjects player isEqualTo[]) then {
						{
							detach _x;
						} forEach attachedObjects player;
						if (EPOCH_snapDirection > 0) then {
							if (EPOCH_snapDirection == 1) then {
								_direction = _direction + 90;
							};
							if (EPOCH_snapDirection == 2) then {
								_direction = _direction + 180;
							};
							if (EPOCH_snapDirection == 3) then {
								_direction = _direction + 270;
							};
						};
						if (_direction > 360) then {
							_direction = _direction - 360;
						};
						if (_direction < 0) then {
							_direction = 360 + _direction;
						};

						_dir2 = [vectorDir _nearestObject, _direction] call EPOCH_returnVector;

						if (_pos2 select 2 > _maxHeight) then {
							_pos2 set[2, _maxHeight];
						};
						if (surfaceIsWater _snapPosition) then {
							_snapPosition = ASLtoATL _snapPosition;
						};

						_currentTarget setVectorDirAndUp[_dir2, (vectorUp _nearestObject)];
						_currentTarget setposATL _snapPosition;
					};

				} else {

					if !(attachedObjects player isEqualTo[]) then {
						_offSet = [EPOCH_X_OFFSET, EPOCH_Y_OFFSET, EPOCH_Z_OFFSET];
						_pos1 = player modelToWorldVisual _offSet;
						if (surfaceIsWater _pos1) then {
							_pos1 set[2, ((getPosASL player) select 2) + EPOCH_Z_OFFSET];
							_pos1 = ASLtoATL _pos1;
						};
						EPOCH_target setposATL _pos1;
						EPOCH_target attachTo[player];
					};
				};
			};

		} forEach _nearestObjects;

		if ((diag_tickTime - _EPOCH_1) > 1) then {
			_EPOCH_1 = diag_tickTime;
			_nearestObjects = nearestObjects[EPOCH_target, _allowedSnapObjects, 12];
			EPOCH_playerEnergy = (EPOCH_playerEnergy - _energyCost) max 0;
		};

	};

	{
		detach _x;
	} forEach attachedObjects player;


	if !(isNull _currentTarget) then {

		// check if touching ground
		_currentPos = getPosATL _currentTarget;
		if (_currentPos select 2 > _maxHeight) then {
			_currentPos set[2, _maxHeight];
			_currentTarget setPosATL _currentPos;
		};

		_currentPos set[2, (_currentPos select 2) + 0.1];

		// remove item here
		if (([player, _item] call BIS_fnc_invRemove) == 1) then {

			if (_stabilityCheck && !isTouchingGround _currentTarget) then {

				_offsetZPos = [_currentPos select 0, _currentPos select 1, (_currentPos select 2) - 0.5];
				if !(terrainIntersect[_currentPos, _offsetZPos]) then {

					_numberOfContacts = 0;
					{
				        _pos1 = _currentTarget modelToWorld (_x select 0);
				        _pos2 = _currentTarget modelToWorld (_x select 1);
				        _ins = lineIntersectsSurfaces [AGLToASL _pos1, AGLToASL _pos2,player,_currentTarget,true,1,"VIEW","FIRE"];
				        if (count _ins > 0) then {
				            _numberOfContacts = _numberOfContacts + 1;
				        };
				    } forEach _snapChecks;

					if (_numberOfContacts < 2) then {
						// TODO: foundations need to be handled
						// change to sim
						_worldspace = [getposATL _currentTarget, vectordir _currentTarget, vectorup _currentTarget];
						deleteVehicle _currentTarget;
						_currentTarget = createVehicle[_simulClass, (_worldspace select 0), [], 0, "CAN_COLLIDE"];
						_currentTarget setVectorDirAndUp[_worldspace select 1, _worldspace select 2];
						_currentTarget setposATL(_worldspace select 0);
					};
				};
			};
			_currentTarget spawn EPOCH_countdown;
		};
	};
};

[] spawn{
	uiSleep 2;
	EPOCH_simulSwap_Lock = nil;
};
