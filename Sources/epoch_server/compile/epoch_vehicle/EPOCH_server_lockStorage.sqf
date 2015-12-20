_unit = _this select 0;
_lockStatus = _this select 1;
_plyr = _this select 2;

if !([_plyr, _this select 3] call EPOCH_server_getPToken) exitWith{};
if (isNull _unit) exitWith{};
if (_plyr distance _unit > 20) exitWith{};

_type = typeOf _unit;

_plyrUID = getPlayerUID _plyr;
_plyrGroup = _plyr getVariable ["GROUP",""];

// functions
_fnc_lock = {
	_this setVariable ["EPOCH_Locked", true, true];
	// force save on lock
	if !(_this in EPOCH_saveStorQueue) then { EPOCH_saveStorQueue pushBack _this };
	//_this enableSimulationGlobal false;
};
_fnc_unlock = {
	_this setVariable ["EPOCH_Locked", false, true];
	//_this enableSimulationGlobal true;
};
// functions

if (getNumber(configFile >> "CfgVehicles" >> _type >> "isSecureStorage") == 1) then{

	_owners = _unit getVariable["STORAGE_OWNERS", []];

	// locked > unlocked
	if !(_unit getVariable ["EPOCH_Locked", true]) then {

		// allow group members and owner access
		if (_plyrGroup != "") then {
			if (_plyrGroup in _owners) then {
				_unit call _fnc_lock;
			} else {

				_response = ["Group", _plyrGroup] call EPOCH_fnc_server_hiveGETRANGE;
				if ((_response select 0) == 1 && typeName (_response select 1) == "ARRAY") then {
					_gArray = _response select 1;
					if (
						{(_x select 0) in _owners}count(_gArray select 3) > 0 ||
						{(_x select 0) in _owners}count(_gArray select 4) > 0 ||
						_plyrUID in _owners
					) then {
						_unit call _fnc_lock;
					};
				};
			};

		} else {
			if (_plyrUID in _owners) then {
				_unit call _fnc_lock;
			};
		};

	// unlocked > locked
	} else {

		// allow group members and owner access
		if (_plyrGroup != "") then {
			if (_plyrGroup in _owners) then {
				_unit call _fnc_unlock;
			} else {
				_response = ["Group", _plyrGroup] call EPOCH_fnc_server_hiveGETRANGE;
				if ((_response select 0) == 1 && typeName(_response select 1) == "ARRAY") then {
					_gArray = _response select 1;
					if (
						{(_x select 0) in _owners }count(_gArray select 3) > 0 ||
						{(_x select 0) in _owners}count(_gArray select 4) > 0 ||
						_plyrUID in _owners
					) then {
						_unit call _fnc_unlock;
					};
				};
			};
		} else {
			if (_plyrUID in _owners) then {
				_unit call _fnc_unlock;
			};
		};
	};
};
