/*
Player Death

Epoch Mod - EpochMod.com
All Rights Reserved.
*/
private ["_playerObj","_pos","_veh","_triggerType","_playerName","_bankBalance","_bankData","_response","_killer","_plyrUID","_cIndex","_vars","_current_crypto"];
_playerObj = _this select 0;
_killer = _this select 1;

// handle token check and isnull for _plyr
if !([_playerObj, _this select 3] call EPOCH_server_getPToken) exitWith{};
_plyrUID = getPlayerUID _playerObj;
_pos = getposATL _playerObj;

if (_playerObj != _killer) then {
	if (random 1 <= EPOCH_antagonistChancePDeath) then {
		_triggerType = 2;
		if (surfaceIsWater _pos) then {
			_triggerType = 3;
		};
		[_killer, "Sapper"] call EPOCH_server_triggerEvent;
	};

	// backwards compat for now - 
	_playerName = _this select 2;
	if (typeName _playerName == "ARRAY") then{
		_playerName = toString (_this select 2);
	};

	['deathlog', format['%1 (%2) Killed By %3 (%4) with weapon %5 from %6m at %7', _playerName, _plyrUID, name _killer, getPlayerUID _killer, currentWeapon _killer, _playerObj distance _killer, _pos]] call EPOCH_fnc_server_hiveLog;
};

// get vars array and current Crypto value
_cIndex = EPOCH_customVars find "Crypto";
_vars = _playerObj getVariable["VARS", [] + EPOCH_defaultVars_SEPXVar];
_current_crypto = _vars select _cIndex;

if (_current_crypto > 0) then{
	_veh = createVehicle["Land_MPS_EPOCH", _pos, [], 1.5, "NONE"];
	diag_log format["ADMIN: Created crypto device for %1 with %2 at %3", getPlayerUID _playerObj, _current_crypto, _pos];
	_veh setVariable["Crypto", _current_crypto, true];
};

[_playerObj, [] + EPOCH_defaultVars_SEPXVar] call EPOCH_server_savePlayer;

// death cost
if (EPOCH_cloneCost > 0) then {
	_response = ["Bank", _plyrUID] call EPOCH_fnc_server_hiveGETRANGE;
	if ((_response select 0) == 1 && typeName(_response select 1) == "ARRAY") then {
		_bankData = _response select 1;
		_bankBalance = 0;

		if !(_bankData isEqualTo[]) then {
			_bankBalance = _bankData select 0;
		};

		_bankBalance = _bankBalance - EPOCH_cloneCost;
		["Bank", _plyrUID, EPOCH_expiresBank, [_bankBalance]] call EPOCH_fnc_server_hiveSETEX;
	};
};
