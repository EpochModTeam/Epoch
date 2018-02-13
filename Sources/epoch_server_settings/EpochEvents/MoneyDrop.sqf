/*
	Money Drop Event
	by He-Man - EpochMod.com
	
	Improvements and or bugfixes and other contributions are welcome via the github:
	https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server_settings/EpochEvents/MoneyDrop.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_cfgEpoch", "_debug", "_limit", "_counter", "_others", "_distFromOthers", "_position", "_goodPos", "_playersNearEpicenter", "_chance", "_values","_spawncount" ,"_scatter" ,"_packs" ,"_packPos" , "_item", "_debugMkr", "_markers", "_originalColors", "_showMarkers", "_decayMarkerColor", "_compromisedColor", "_spawned", "_decayTime", "_serverSettingsConfig", "_timeMultiplier", "_rEvents", "_thisEvent"];
//[[[end]]]
_cfgEpoch = configFile >> "CfgEpoch" >> worldname;
_debug = if(getNumber(_cfgEpoch >> "debugMoneyDrop") isEqualTo 1)then{true}else{false};
_limit = getNumber(_cfgEpoch >> "maxMoneyDrops");
_counter = missionNameSpace getVariable["EPOCH_MoneyDropCounter",0];
_others = missionNameSpace getVariable["EPOCH_MoneyDrops", [[0,0,0]] ];
_distFromOthers = getNumber(_cfgEpoch >> "distFromOtherMoneyDrops");

//STOP THE SCRIPT AND EXIT IF THE COUNTER IS TOO HIGH.
if (_counter >= _limit) exitWith {
	if (_debug) then {diag_log "DEBUG: suppressed MONEYDROP spawn over limit"};
};

for "_i" from 0 to 100 step 1 do {
	_position = [epoch_centerMarkerPosition, 0, EPOCH_dynamicVehicleArea, 10, 0, 1000, 0] call BIS_fnc_findSafePos;
	_goodPos = true;
	
	_goodPos = [_position, true, true, false, _others, _distFromOthers] call EPOCH_server_isNearChecks;
	
	if(_goodPos)then{
		_i = 100;
	}else{
		_position = [];
	};
};

if ((count _position) == 2) then{
	_playersNearEpicenter = _position nearEntities[["Epoch_Male_F", "Epoch_Female_F"], 1000];
	// decrease chance with more players
	_chance = 0.2 + (linearConversion [1, 100, (count allPlayers), 0, 0.5, true]);
	if ((random 1) < _chance) then {

		_values = getArray(_cfgEpoch >> "MoneyDropValues");
		_values params ["_PacksArr","_ValueArr"];
		_PacksArr params ["_packsmin","_packsmax"];
		_ValueArr params ["_minvalue","_maxvalue"];
		
		_spawncount = round (_packsmin + random (_packsmax-_packsmin));
		
		// Spawn Scattered Money
		_scatter = 10;
		_packs = [];
		for "_i" from 0 to (_spawncount - 1) step 1 do  {
			_value = round (_minvalue + random (_maxvalue-_minvalue));
			_item = createVehicle["Land_Money_F", _position, [], _scatter, "NONE"];
			_item setVariable ["Crypto",_value,true];
			_item setVariable ["RemoveOnTake",true];
			_packs pushBack _item;
			if(_debug)then{
				_packPos = getPosATL _item;
				_debugMkr = createMarker [str(_packPos), _packPos];
				_debugMkr setMarkerShape "ICON";
				_debugMkr setMarkerType "mil_dot";
				_debugMkr setMarkerColor "ColorRed";
			};
		};
		
		// Place markers and get decay, compromised and original colors
		_markers = [];
		_originalColors = [];
		_showMarkers = if(getNumber(_cfgEpoch >> "showMoneyMarkers") isEqualTo 1)then{true}else{false};
		_decayMarkerColor = getText(_cfgEpoch >> "MoneyDropDecayMarkerColor");
		_compromisedColor = getText(_cfgEpoch >> "MoneyDropCompromisedColor");
		if (_showMarkers) then{
			_markers = ["MoneyDrop",_position] call EPOCH_server_createGlobalMarkerSet;
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
		missionNameSpace setVariable["EPOCH_MoneyDropCounter",_counter];
		
		// ADD POSITION TO OTHERS ARRAY
		missionNameSpace setVariable["EPOCH_MoneyDrops", _others + [_position]];

		// SEND EVENT TO MONITOR
		_decayTime = getNumber(_cfgEpoch >> "MoneyDropDecayTime");
		_serverSettingsConfig = configFile >> "CfgEpochServer";
		_timeMultiplier = ([_serverSettingsConfig, "timeMultiplier", 1] call EPOCH_fnc_returnConfigEntry);
		_rEvents = missionNameSpace getVariable["EPOCH_RunningEvents",[]];
		_thisEvent = [_position, _packs, [], "MoneyDropCounter", diag_tickTime, (_decayTime * _timeMultiplier), _showMarkers, _markers, _originalColors, _decayMarkerColor, _compromisedColor];
		missionNameSpace setVariable["EPOCH_RunningEvents",_rEvents + [_thisEvent]];
		if (_debug) then {
			diag_log format["EPOCHDebug: earthquakeSpawner-%1",  missionNameSpace getVariable["EPOCH_RunningEvents",[]]];
		};
	};
};
