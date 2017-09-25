/*
	Author: Aaron Clark - EpochMod.com

    Contributors: Raimonds Virtoss

	Description:
	Epoch build countdown

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/building/EPOCH_countdown.sqf

    Example:
    _currentTarget spawn EPOCH_countdown;

    Parameter(s):
		_this select 0: OBJECT - Base building object

	Returns:
	NOTHING
*/
//[[[cog import generate_private_arrays ]]]
private ["_cfgBaseBuilding","_class","_endTime","_newObj","_objClass","_posObj","_previousBuildPos","_saveCheck","_savedBuildPos","_startTime","_worldspace"];
//[[[end]]]

if (!isNull _this) then {

	while {true} do {
		if (!isNull _this) exitWith {};
		_posObj = (getPosATL _this);
		_savedBuildPos = _this getVariable ["BUILD_SAVED_POS", []];
		_previousBuildPos = _this getVariable ["BUILD_POS", []];
		if (_previousBuildPos isEqualTo _posObj) exitWith {};
		_this setVariable ["BUILD_POS",_posObj];
		uiSleep 1;
	};

	// make sure it still there after exiting loop above ^
	if (!isNull _this) then {

		_startTime = diag_tickTime;
		_endTime = _startTime + 30;

		_this setVariable["EPOCH_endTime", _endTime];

		EPOCH_arr_countdown pushBackUnique  _this;

		_saveCheck = true;

		EPOCH_drawIcon3d = true;

		while {diag_tickTime < _endTime} do {
			if (EPOCH_Target == _this) exitWith{ _saveCheck = false; };
			if (isNull _this) exitWith{ _saveCheck = false; };
			if (EPOCH_stabilityTarget == _this) then {
				_endTime = diag_tickTime + 30;
			};
			uiSleep 0.1;
		};

		EPOCH_arr_countdown = EPOCH_arr_countdown - [_this];
		EPOCH_drawIcon3d = !(EPOCH_arr_countdown isEqualTo []);

		_objClass = typeOf _this;
		// Spawn temporary static item insead of saving.
		_cfgBaseBuilding = 'CfgBaseBuilding' call EPOCH_returnConfig;
		if (getNumber(_cfgBaseBuilding >> _objClass >> "isTemporary") == 1) then {
			_worldspace = [getposATL _this, vectordir _this, vectorup _this];
			deleteVehicle _this;
			_class = getText(_cfgBaseBuilding >> _objClass >> "staticClass");
			if (_class != "") then {
				_newObj = createVehicle[_class, (_worldspace select 0), [], 0, "CAN_COLLIDE"];
				_newObj setposATL(_worldspace select 0);
				_newObj setVectorDirAndUp[_worldspace select 1, _worldspace select 2];
			};
		} else {
			if (_saveCheck) then {
				[_this, player, Epoch_personalToken] remoteExec["EPOCH_server_saveBuilding", 2];
			};
		};
	};
};
