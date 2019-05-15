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
private ["_bankBalance","_bankData","_cIndex","_current_crypto","_defaultVars","_playerName","_playerUID","_pos","_response","_triggerType","_vars","_killerUID","_deathType","_killerCommunityStats","_mIndex","_current_murders","_communityStats","_sIndex","_current_suicides","_dIndex","_current_deaths","_playerKarmaAdj","_killerKarmaAdj","_kIndex","_playerCStats","_playerKarma","_playerIsNeutral","_playerIsBandit","_playerIsHero","_killerCStats","_killerKarma","_karmaLimitsArray","_lowKarmaLevel1","_highKarmaLevel1"];
//[[[end]]]
params ["_playerObj","_killer","_playerName",["_token","",[""]] ];

// handle token check and isnull for _player
if !([_playerObj, _token] call EPOCH_server_getPToken) exitWith{};

_playerUID = getPlayerUID _playerObj;
_killerUID = getPlayerUID _killer;
_pos = getposATL _playerObj;

// find player's Karma status
_kIndex = EPOCH_communityStats find "Karma";
_playerCStats = _playerObj getVariable["COMMUNITY_STATS", EPOCH_defaultStatVars];
_playerKarma = _playerCStats select _kIndex;

// set config karma levels
_karmaLimitsArray = EPOCH_communityStatsLimits select _kIndex;
_lowKarmaLevel1 = ((_karmaLimitsArray select 2) select 0);
_highKarmaLevel1 = ((_karmaLimitsArray select 3) select 0);

_playerIsNeutral = (_playerKarma < _highKarmaLevel1 && _playerKarma > _lowKarmaLevel1);
_playerIsBandit = (_playerKarma <= _lowKarmaLevel1);
_playerIsHero = (_playerKarma >= _highKarmaLevel1);

// default deathType is suicide
_deathType = 666;
_playerKarmaAdj = -2;

if (_playerObj != _killer) then {
	_playerKarmaAdj = -5;
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
	
	// player karma changes
	if(_playerIsNeutral)then{_playerKarmaAdj = abs((-_playerKarma) * 0.03)};
	if(_playerIsBandit)then{_playerKarmaAdj = abs((-_playerKarma) * 0.055)};
	if(_playerIsHero)then{_playerKarmaAdj = abs((-_playerKarma) * 0.025)};
	_deathType = 0;
	if!(_killerUID isEqualTo "")then{
		[_killer, "Murders", 1, true] call EPOCH_server_updatePlayerStats;
		
		// find killer's Karma status
		_killerCStats = _killer getVariable["COMMUNITY_STATS", EPOCH_defaultStatVars];
		_killerKarma = _killerCStats select _kIndex;
		
		// killer karma changes
		_killerKarmaAdj = -5;
		if(_killerKarma < _highKarmaLevel1 && _killerKarma > _lowKarmaLevel1)then{
			if(_playerIsNeutral)then{_killerKarmaAdj = abs((-_killerKarma) * 0.03) + _playerKarmaAdj};
			if(_playerIsBandit)then{_killerKarmaAdj = abs((_killerKarma) * 0.05) + _playerKarmaAdj};
			if(_playerIsHero)then{_killerKarmaAdj = abs((-_killerKarma) * 0.025) + _playerKarmaAdj};
		};
		if(_killerKarma <= _lowKarmaLevel1)then{
			if(_playerIsNeutral)then{_killerKarmaAdj = abs((_killerKarma) * 0.05) + _playerKarmaAdj};
			if(_playerIsBandit)then{_killerKarmaAdj = abs((-_killerKarma) * 0.15) + _playerKarmaAdj};
			if(_playerIsHero)then{_killerKarmaAdj = abs((_killerKarma) * 0.15) + _playerKarmaAdj};
		};
		if(_killerKarma >= _highKarmaLevel1)then{
			if(_playerIsNeutral)then{_killerKarmaAdj = abs((-_killerKarma) * 0.10) + _playerKarmaAdj};
			if(_playerIsBandit)then{_killerKarmaAdj = abs((_killerKarma) * 0.15) + _playerKarmaAdj};
			if(_playerIsHero)then{_killerKarmaAdj = abs((-_killerKarma) * 0.25) + _playerKarmaAdj};
		};
		[_killer, "Karma", _killerKarmaAdj, true] call EPOCH_server_updatePlayerStats;
		_deathType = 1;
	};
};

switch(_deathType)do{
	case 666: {
		[_playerObj, "Suicides", 1, true] call EPOCH_server_updatePlayerStats;
		[_playerObj, "Karma", _playerKarmaAdj, true] call EPOCH_server_updatePlayerStats;
	};
	case 1: {
		[_playerObj, "Deaths", 1, true] call EPOCH_server_updatePlayerStats;
		[_playerObj, "Karma", _playerKarmaAdj, true] call EPOCH_server_updatePlayerStats;
	};
	case 0: {
		[_playerObj, "AIDeaths", 1, true] call EPOCH_server_updatePlayerStats;
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

// save community stats (skipped in EPOCH_server_savePlayer for dead Players)
_stats = _playerObj getVariable["COMMUNITY_STATS", EPOCH_defaultStatVars];
["CommunityStats", _playerUID, EPOCH_expiresCommunityStats, [_stats]] call EPOCH_fnc_server_hiveSETEX;
[_playerObj,_stats] call EPOCH_server_UpdateTopStats;

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
