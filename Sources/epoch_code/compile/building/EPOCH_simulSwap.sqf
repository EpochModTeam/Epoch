/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Base building base building with physics

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/building/EPOCH_simulSwap.sqf

    Example:
    [_object] spawn EPOCH_simulSwap;

    Parameter(s):
		_this select 0: OBJECT - Base building object

	Returns:
	NOTHING
*/
private ["_simulClassConfig","_energyCost","_allowedSnapObjects","_worldspace","_objSlot","_textureSlot","_newObj","_lastCheckTime","_rejectMove","_nearestObject","_nearestObjectRaw","_distanceNear","_previousDistanceNear","_pOffset","_snapPos","_isSnap","_snapPosition","_snapType","_snapDistance","_prevSnapDistance","_snapPointsPara","_snapPointsPerp","_snapArrayPara","_snapArrayPerp","_pos2","_direction","_vel2","_dir2","_up2","_distance","_playerdistance","_class","_create","_allowedSnapPoints","_snapObjects","_currentTarget","_onContactEH","_offset","_disallowed","_object","_objType","_return","_velocityTransformation","_distanceMod","_oemType","_cfgBaseBuilding"];
if !(isNil "EPOCH_simulSwap_Lock") exitWith{};

_object = param [0,objNull];
if (isNull _object) exitWith{ EPOCH_target = objNull; };

_objType = typeOf _object;

_isSnap = false;

if (EPOCH_playerEnergy <= 0) exitWith {
	["<t size = '1.6' color = '#99ffffff'>Need Energy</t>", 5] call Epoch_dynamicText;
};
if !(_objType call EPOCH_isBuildAllowed) exitWith{};

EPOCH_simulSwap_Lock = true;
_return = _object;
_velocityTransformation = [];
_prevSnapDistance = 0;
_distanceMod = 0;
_oemType = (typeOf _object);

_cfgBaseBuilding = 'CfgBaseBuilding' call EPOCH_returnConfig;

_simulClassConfig = (_cfgBaseBuilding >> _oemType >> "simulClass");
if (isText(_simulClassConfig)) then {
	_class = getText(_simulClassConfig);
	_create = true;
	_allowedSnapPoints = getArray(_cfgBaseBuilding >> _class >> "allowedSnapPoints");
	_allowedSnapObjects = ["Constructions_static_F"];
	_snapObjects = _cfgBaseBuilding >> _class >> "allowedSnapObjects";
	_energyCost = getNumber(_cfgBaseBuilding >> _class >> "energyCost");
	if (_energyCost == 0) then {
		_energyCost = 0.1;
	};
	if (isArray(_snapObjects)) then {
		_allowedSnapObjects = getArray(_snapObjects);
	};
	_newObj = _object;
	if (_create) then {
		_worldspace = [(getposATL _object),(vectordir _object),(vectorup _object)];
		_objSlot = _object getVariable["BUILD_SLOT", -1];
		_textureSlot = _object getVariable["TEXTURE_SLOT", 0];
		deleteVehicle _object;
		waitUntil {sleep 0.01; isNull _object};
		_newObj = createVehicle [_class, (_worldspace select 0), [], 0, "CAN_COLLIDE"];
		if (_objSlot != -1) then {
			_newObj setVariable ["BUILD_SLOT",_objSlot,true];
		};

		_newObj setposATL (_worldspace select 0);
		_newObj setVectorDirAndUp [_worldspace select 1,_worldspace select 2];
		if (_textureSlot != 0) then {
			[_newObj, _textureSlot, player, Epoch_personalToken] remoteExec ["EPOCH_server_paintBUILD",2];
		};
	};
	EP_velocityTransformation = [];
	EPOCH_oldTarget = EPOCH_target;
	EPOCH_target = _newObj;
	_currentTarget = EPOCH_target;
	EPOCH_velTransform = true;
	EPOCH_objHold = 0;
	_onContactEH = _currentTarget addEventHandler["EpeContactStart", { if ((_this select 1) isKindOf "LandVehicle" || (_this select 1) isKindOf "Air" || (_this select 1) isKindOf "Ship" || (_this select 1) isKindOf "Tank") then{ EPOCH_target = objNull }; }];
	EP_snap = objNull;
	_previousDistanceNear = 0;
	_offset = player worldToModel (getposATL _currentTarget);
	EPOCH_X_OFFSET = _offset select 0;
	EPOCH_Y_OFFSET = _offset select 1;
	EPOCH_Z_OFFSET = _offset select 2;
	_lastCheckTime = diag_tickTime;
	while {EPOCH_target == _currentTarget} do {
		if (EPOCH_playerEnergy <= 0) exitWith { EPOCH_target = objNull; };
		_rejectMove = false;
		if ((diag_tickTime - _lastCheckTime) > 10) then {
			_lastCheckTime = diag_tickTime;
			_rejectMove = !(EPOCH_target call EPOCH_isBuildAllowed);
		};
		if (_rejectMove) exitWith{
			// remove object and refund items
			deleteVehicle EPOCH_target;
			_removeParts = getArray(('CfgBaseBuilding' call EPOCH_returnConfig) >> _objType >> "removeParts");
			{
				[_x select 0,_x select 1] call EPOCH_fnc_addItemOverflow;
			} forEach _removeParts;
		};
		_playerdistance = player distance EPOCH_target;
		if (_playerdistance < 10) then {
			_isSnap = false;
			_snapPosition = [0,0,0];
			_snapType = "para";
			_nearestObject = objNull;

			// see if this can prevent riding on object
			if (EPOCH_Y_OFFSET < 3.6) then {
				EPOCH_Y_OFFSET = EPOCH_Y_OFFSET + 0.1;
			};

			_pos2 = player modelToWorld[EPOCH_X_OFFSET, EPOCH_Y_OFFSET, EPOCH_Z_OFFSET];
			_distance = _pos2 distance EPOCH_target;
			if (EPOCH_buildMode == 1) then {
				if (isNull _nearestObject) then {
					{
						_nearestObjectRaw = nearestObject [EPOCH_target,_x];
						_distanceNear = EPOCH_target distance _nearestObjectRaw;
						if (_distanceNear < _previousDistanceNear) then {
							_nearestObject = _nearestObjectRaw;
						};
						_previousDistanceNear = _distanceNear;
					} forEach _allowedSnapObjects;
				};
				if (!isNull _nearestObject) then {
					_snapPointsPara = getArray(_cfgBaseBuilding >> (typeOf _nearestObject) >> "snapPointsPara");
					_snapPointsPerp = getArray(_cfgBaseBuilding >> (typeOf _nearestObject) >> "snapPointsPerp");
					_snapArrayPara = [];
					{
						if (_x in _allowedSnapPoints) then {
							_pOffset = _nearestObject selectionPosition _x;
							_snapPos = _nearestObject modelToWorld _pOffset;
							if ((_pos2 distance _snapPos) < 3) then {
								_snapArrayPara pushBackUnique _snapPos;
							};
						};
					} forEach _snapPointsPara;
					_snapArrayPerp = [];
					{
						if (_x in _allowedSnapPoints) then {
							_pOffset = _nearestObject selectionPosition _x;
							_snapPos = _nearestObject modelToWorld _pOffset;
							if ((_pos2 distance _snapPos) < 3) then {
								_snapArrayPerp pushBackUnique _snapPos;
							};
						};
					} forEach _snapPointsPerp;
					{
						_snapDistance = _pos2 distance _x;
						if (_snapDistance < 1 && (_snapDistance < _prevSnapDistance)) exitWith {
							_isSnap = true;
							_snapPosition = _x;
							_snapType = "para";
						};
						_prevSnapDistance = _snapDistance;
					} forEach _snapArrayPara;
					{
						_snapDistance = _pos2 distance _x;
						if (_snapDistance < 1 && (_snapDistance < _prevSnapDistance)) exitWith {
							_isSnap = true;
							_snapPosition = _x;
							_snapType = "perp";
						};
						_prevSnapDistance = _snapDistance;
					} forEach _snapArrayPerp;
				};
				if (_isSnap && _distance < 5) then {
					_pos2 = AGLToASL _snapPosition;
					_vel2 = (velocity _nearestObject);
					_direction = getDir _nearestObject;
					if (_snapType == "perp") then {
						_direction = _direction - (_snapPosition getDir _nearestObject);
					} else {
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
					_dir2 = [vectorDir _nearestObject, _direction] call BIS_fnc_returnVector;
					_up2 = (vectorUp _nearestObject);
					EP_velocityTransformation = [_pos2,_vel2,_dir2,_up2];
				};
			};
			if (!_isSnap) then {
				if !(surfaceIsWater _pos2) then {
					_pos2 = ATLtoASL _pos2;
				};
				if (EPOCH_doRotate) then {
					_vel2 = (velocity player);
					_dir2 = [vectorDir player, EPOCH_buildDirection] call BIS_fnc_returnVector;
					_up2 = (vectorUp player);
					EPOCH_doRotate = false;
					EP_velocityTransformation = [_pos2,_vel2,_dir2,_up2];
				} else {
					EP_velocityTransformation = [];
				};
			};
		};
		EPOCH_playerEnergy = (EPOCH_playerEnergy - _energyCost) max 0;
		uiSleep 0.1;
	};
	_currentTarget removeEventHandler["EpeContactStart", _onContactEH];
	EPOCH_velTransform = false;
	_disallowed = ["Tarp_SIM_EPOCH", "Freezer_SIM_EPOCH", "Fridge_SIM_EPOCH", "Shelf_SIM_EPOCH", "Pelican_SIM_EPOCH", "Wardrobe_SIM_EPOCH", "Bed_SIM_EPOCH", "Couch_SIM_EPOCH", "Cooker_SIM_EPOCH", "Chair_SIM_EPOCH", "Filing_SIM_EPOCH", "Table_SIM_EPOCH", "Locker_SIM_EPOCH", "ToolRack_SIM_EPOCH", "Shoebox_SIM_EPOCH", "Bunk_SIM_EPOCH", "Jack_SIM_EPOCH"];
	if !(_class in _disallowed) then {
		_currentTarget spawn EPOCH_countdown;
	};
	_currentTarget setVelocity [0,0,-0.01];
};
[] spawn{
	uiSleep 2;
	EPOCH_simulSwap_Lock = nil;
};
