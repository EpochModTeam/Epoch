/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Player Death for use with RemoteExec

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_player/EPOCH_server_deadPlayer.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_bankBalance","_bankData","_cIndex","_current_crypto","_defaultVars","_playerName","_playerUID","_pos","_response","_triggerType","_vars","_killerUID","_deathType","_killerCommunityStats","_mIndex","_current_murders","_communityStats","_sIndex","_current_suicides","_dIndex","_current_deaths"];
//[[[end]]]
params ["_playerObj","_killer","_playerName",["_token","",[""]] ];

// handle token check and isnull for _player
if !([_playerObj, _token] call EPOCH_server_getPToken) exitWith{};

_playerUID = getPlayerUID _playerObj;
_killerUID = getPlayerUID _killer;
_pos = getposATL _playerObj;
_deathType = 666;

if (_playerObj != _killer) then {
	if (random 1 <= EPOCH_antagonistChancePDeath) then {
		_triggerType = 2;
		if (surfaceIsWater _pos) then {
			_triggerType = 3;
		};
		[_killer, "Sapper"] call EPOCH_server_triggerEvent;
	};

	// backwards compat for now -
	if (_playerName isEqualType []) then{
		_playerName = toString (_playerName);
	};

	['deathlog', format['%1 (%2) Killed By %3 (%4) with weapon %5 from %6m at %7', _playerName, _playerUID, name _killer, _killerUID, currentWeapon _killer, _playerObj distance _killer, _pos]] call EPOCH_fnc_server_hiveLog;
	
	if!(_killerUID isEqualTo "")then{
		[_killer, "Murders", 1, true] call EPOCH_server_updatePlayerStats;
	};
	_deathType = 1;
};

switch(_deathType)do{
	case 666: {
		[_playerObj, "Suicides", 1] call EPOCH_server_updatePlayerStats;
	};
	case 1: {
		[_playerObj, "Deaths", 1] call EPOCH_server_updatePlayerStats;
	};
};
_defaultVars = call EPOCH_defaultVars_SEPXVar;
// get vars array and current Crypto value
_cIndex = EPOCH_customVars find "Crypto";
_vars = _playerObj getVariable["VARS", _defaultVars];
_current_crypto = _vars select _cIndex;

if (_current_crypto > 0) then{
	_playerObj setVariable["Crypto", _current_crypto, true];
	diag_log format["Epoch: ADMIN: Crypto added to dead body for %1 with %2 at %3", getPlayerUID _playerObj, _current_crypto, _pos];
};

[_playerObj, _defaultVars] call EPOCH_server_savePlayer;

// death cost
if (EPOCH_cloneCost > 0) then {
	_response = ["Bank", _playerUID] call EPOCH_fnc_server_hiveGETRANGE;
	if ((_response select 0) == 1 && (_response select 1) isEqualType []) then {
		_bankData = _response select 1;
		_bankBalance = 0;

		if !(_bankData isEqualTo[]) then {
			_bankBalance = _bankData select 0;
		};

		_bankBalance = _bankBalance - EPOCH_cloneCost;
		["Bank", _playerUID, EPOCH_expiresBank, [_bankBalance]] call EPOCH_fnc_server_hiveSETEX;
	};
};
