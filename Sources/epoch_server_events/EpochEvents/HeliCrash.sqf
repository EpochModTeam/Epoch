_cfgEpoch = configFile >> "CfgEpoch" >> worldname;
_debug = if(getNumber(_cfgEpoch >> "debugHeliCrashes") isEqualTo 1)then{true}else{false};
_limit = getNumber(_cfgEpoch >> "maxSpawnedHeliCrashes");
_counter = missionNameSpace getVariable["EPOCH_HeliCrashCounter",0];
_others = missionNameSpace getVariable["EPOCH_HeliCrashes", [[0,0,0]] ];
_distFromOthers = getNumber(_cfgEpoch >> "distFromOtherHeliCrashes");

//STOP THE SCRIPT AND EXIT IF THE COUNTER IS TOO HIGH.
if (_counter >= _limit) exitWith {
	if (_debug) then {diag_log "DEBUG: suppressed HELICRASH spawn over limit"};
};

// decrease chance with more players
if (count (allplayers select {alive _x}) == 0) exitwith {};
_chance = 0.1 + (linearConversion [1, 100, (count allPlayers), 0, 0.5, true]);
if ((random 1) < _chance) then {
	_position = [0,0,0];
	for "_i" from 0 to 100 step 1 do {
		_position = [epoch_centerMarkerPosition, 0, EPOCH_dynamicVehicleArea, 5, 0, 1000, 0] call BIS_fnc_findSafePos;
		_goodPos = true;
		_goodPos = [_position, true, true, false, _others, _distFromOthers] call EPOCH_server_isNearChecks;
		if(_goodPos)then{
			_i = 100;
		}else{
			_position = [];
		};
	};

	if ((count _position) == 2) then{
		_values = getArray(_cfgEpoch >> "availableHeliCrashes");
		if (_values isEqualTo []) exitwith {
			if (_debug) then {diag_log "DEBUG: suppressed HELICRASH no HeliClasses defined"};
		};
		_veharray = selectrandom _values;
		_startpos = [_position, 0, 3000, 5, 0, 1000, 0] call BIS_fnc_findSafePos;
		if ((count _startpos) > 2) then {
			_startpos = [3000,3000];
		};
		_startpos set [2,600];
		_veh = createVehicle [_veharray select 0, _startpos, [], 0, "FLY"];
		_veh setpos _startpos;
		_veh call EPOCH_server_setVToken;
		_group = creategroup east;
		_unit = _group createUnit["I_Soldier_EPOCH", [0,0,0], [], 0, "FORM"];         
		_unit moveInDriver _veh;
		_veh flyinheight 200;
		for '_i' from 0 to 3 do {
			_group move _position;
			uisleep 30;
		};
		_time = diag_ticktime;
		waituntil {uisleep 0.5; !(surfaceiswater (getpos _veh)) || diag_ticktime - _time > 60};
		deletevehicle _unit;
		uisleep 2;
		_veh setdamage 1;
		_starttime = diag_ticktime;
		waituntil {uisleep 0.25; ((getpos _veh) select 2) < 2 || diag_ticktime > _starttime+30};
		_pos = getposatl _veh;
		_pos set [2,0];
		deletevehicle _veh;
		uisleep 0.5;
		if !(surfaceiswater _pos) then {
			_veh = createVehicle [_veharray select 1, _pos, [], 0, "CAN_COLLIDE"];
			_veh setvectorup [0,0,1];
			_veh setPosatl _pos;
			[objnull,"HeliCrash",false,_pos,[true,[6,12]]] call EPOCH_serverLootObject;
			// Place markers and get decay, compromised and original colors
			_markers = [];
			_originalColors = [];
			_showMarkers = if(getNumber(_cfgEpoch >> "showHeliCrashMarkers") isEqualTo 1)then{true}else{false};
			_decayMarkerColor = getText(_cfgEpoch >> "heliCrashDecayMarkerColor");
			_compromisedColor = getText(_cfgEpoch >> "heliCrashCompromisedColor");
			if (_showMarkers) then{
				_markers = ["HeliCrash",_pos] call EPOCH_server_createGlobalMarkerSet;
				{
					_originalColors pushBack (getMarkerColor _x);
				}forEach _markers;
				
				// Check for HeightenedPlayerVsPlayer false and remove comprimised coloring
				if!(getNumber(_cfgEpoch >> "HeightenedPlayerVsPlayer") isEqualTo 1)then{
					_compromisedColor = getMarkerColor (_markers select 0);
				};
			};
			
			// Tick Counter +1
			_counter = _counter + 1;
			missionNameSpace setVariable["EPOCH_HeliCrashCounter",_counter];
			
			// ADD POSITION TO OTHERS ARRAY
			missionNameSpace setVariable["EPOCH_HeliCrashes", _others + [_pos]];

			// SEND EVENT TO MONITOR
			_decayTime = getNumber(_cfgEpoch >> "HeliCrashDecayTime");
			_serverSettingsConfig = configFile >> "CfgEpochServer";
			_timeMultiplier = ([_serverSettingsConfig, "timeMultiplier", 1] call EPOCH_fnc_returnConfigEntry);
			_rEvents = missionNameSpace getVariable["EPOCH_RunningEvents",[]];
			_thisEvent = [_pos, [_veh], [], "EPOCH_HeliCrashCounter", diag_tickTime, (_decayTime * _timeMultiplier), _showMarkers, _markers, _originalColors, _decayMarkerColor, _compromisedColor];
			missionNameSpace setVariable["EPOCH_RunningEvents",_rEvents + [_thisEvent]];

			_effects = [];
			{
				_x params ["_distance","_effect","_sleep"];
				{
					if (!isnull _x) then {
						deletevehicle _x;
					};
				} foreach _effects;
				if (isnull _veh) exitwith {};
				_effects = [];
				_fireArray = switch _effect do {
					case "FIRE_BIG": {
						["BigDestructionFire","BigDestructionSmoke"]
					};
					case "SMOKE_MID": {
						["","MediumSmoke"]
					};
					case "SMOKE_BIG": {
						["","BigDestructionSmoke"]
					};
					default {[]};
				};
				if !(_fireArray isEqualTo []) then {
					_fireArray params ["_fire","_smoke"];
					if (_fire != "") then {
						_eFire = "#particlesource" createVehicle (position _veh) ;
						_eFire setParticleClass _fire;
						_eFire attachto [_veh, [0,0,-1]];
						_effects pushback _eFire;
					};
					if (_smoke != "") then {
						_eSmoke = "#particlesource" createVehicle (position _veh);
						_eSmoke setParticleClass _smoke;
						_eSmoke attachto [_veh, [0,0,-1]];
						_effects pushback _eSmoke;
					};
				};
				waituntil {uisleep _sleep; !((_pos nearentities _distance) select {isplayer _x} isequalto []) || isnull _veh};
			} foreach [[200,"FIRE_BIG",15],[100,"SMOKE_BIG",5],[50,"SMOKE_MID",2]];
		};
	};
};
