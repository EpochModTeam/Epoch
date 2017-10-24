// Epoch Events
_pvehTime = diag_tickTime;
_newEvents = [];
{
	_x params ["_time", "_scriptName", ["_runAtStart",0], ["_usePrePostfix",1], ["_runNumTimes",-1], ["_input",[]], ["_disallowedWorlds",[]] ];
	_scriptParams = [];
	if (_scriptName isEqualType []) then {
		_scriptParams = _scriptName param [0,[]];
		_scriptcmdMode = _scriptName param [1,"call"];
		_scriptName = _scriptName param [2,""];
	};
	_eventKey = format["EPOCH_EVENT_%1", _scriptName];
	_eventCounter = format["EPOCH_EVENT_COUNTER_%1", _scriptName];
	_lastTime = missionNamespace getVariable _eventKey;
	_counter = missionNamespace getVariable [_eventCounter,0];
	if (isNil "_lastTime") then {
		_startTime = diag_tickTime;
		if (_runAtStart isEqualTo 1) then {
			_startTime = diag_tickTime - _time;
		};
		missionNamespace setVariable[_eventKey, _startTime];
		_lastTime = _startTime;
	};
	if ((_counter >= _runNumTimes && _runNumTimes != -1) || worldName in _disallowedWorlds) then {
			diag_log format["DEBUG: server event removed %1", _scriptName];
			missionNamespace setVariable[_eventKey, nil];
			missionNamespace setVariable[_eventCounter, nil];
	} else {
			_newEvents pushBack _x;
		if ((diag_tickTime - _lastTime) >= _time) then {
			missionNamespace setVariable[_eventKey, diag_tickTime];
			_preFix = "";
			_postFix = "";
			if (_usePrePostfix == 1) then {
				_preFix = "\epoch_server_settings\EpochEvents\";
				_postFix = ".sqf";
			};
			if (_usePrePostfix == 2) then {
				_preFix = "\epoch_server_events\EpochEvents\";
				_postFix = ".sqf";
			};
			switch (_scriptcmdMode) do {
			    case ("call"): {
			        // call
					_handle = _scriptParams call (missionNamespace getVariable [_scriptName, {}]);
			    };
				case ("spawn"): {
				    // spawn
					_handle = _scriptParams spawn (missionNamespace getVariable [_scriptName, {}]);
				};
				default {
				    // execVM
					_handle = _input execVM format["%1%2%3",_preFix,_scriptName,_postFix];
				};
			};
			_counter =  _counter + 1;
			missionNamespace setVariable[_eventCounter, _counter];
			diag_log format["DEBUG: server event %1", _scriptName];
		};
	};
} forEach _events;
// remove expired events
_events = _newEvents;

// restart script
if (_scriptBasedRestart) then {
	if (diag_tickTime >=  _forceRestartTimeWarning) then {
		if (!_serverLocked) then {
			diag_log "server shutdown: locked";
			_serverLocked = true;
			["lock"] call EPOCH_serverCommand;
		} else {
			if (allPlayers isEqualTo []) then {
				["shutdown"] call EPOCH_serverCommand;
				diag_log "server shutdown: now";
			};
		};
		_restartIn = round((_forceRestartTime-diag_tickTime)/60);
		if (_prevRestartIn != _restartIn) then {
			_prevRestartIn = _restartIn;
			if (_restartIn > 1) then {
				["message", format["Server restart in %1 minutes",_restartIn]] call EPOCH_serverCommand;
			} else {
				["message", format["Server restart in %1 minute",1]] call EPOCH_serverCommand;
			};
		};
	};
	// kick all remaining players before shutdown to force player save
	if (diag_tickTime >=  _forceRestartTime) then {
		if (_serverRestarting) then {
				["shutdown"] call EPOCH_serverCommand;
				diag_log "server shutdown: now";
		} else {
			{
				["kick", _x , "Server Restarting"] call EPOCH_serverCommand;
			} forEach allPlayers;
			_serverRestarting = true;
		};
	};
};
