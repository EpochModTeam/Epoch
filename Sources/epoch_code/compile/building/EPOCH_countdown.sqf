private["_color", "_distance", "_previous"];

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

		if !(_this in EPOCH_arr_countdown) then {
			EPOCH_arr_countdown pushBack _this;
		};

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
		
		if (typeOf _this == "Fireplace_SIM_EPOCH") then {

			_worldspace = [getposATL _this, vectordir _this, vectorup _this];
			deleteVehicle _this;

			_newObj = createVehicle["Fireplace_EPOCH", (_worldspace select 0), [], 0, "CAN_COLLIDE"];
			_newObj setVectorDirAndUp[_worldspace select 1, _worldspace select 2];
			_newObj setposATL(_worldspace select 0);

		} else {
			if (_saveCheck) then {
				EPOCH_SAVEBUILD = [_this, player, Epoch_personalToken];
				publicVariableServer "EPOCH_SAVEBUILD";
				//diag_log format["DEBUG SAVE: %1", _this];
			};
		};
	};
};
