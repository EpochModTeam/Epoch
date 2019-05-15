/*
	Author: He-Man - EpochMod.com

	Contributors:

	Description:
	Update Server TopStats

	Licence:
	Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Github:
	https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_server/EPOCH_server_UpdateTopStats.sqf
*/


private ["_playername","_playeruid","_makepublic","_publicindex","_tempStats","_ThisStatArr","_playerisin","_idx","_playerValue"];
params [['_player',ObjNull],['_vars',[]]];
_playername = name _player;
_playeruid = getplayeruid _player;
if !((_playerUID isequalto '') || (_vars isequalto [])) then {
	_makepublic = 1;
	_publicindex = EPOCH_communityStats find 'PublicStats';
	if !(_publicindex isequalto -1) then {
		_makepublic = _vars select _publicindex;
	};
	_tempStats = EPOCH_TopStats;
	{
		_ThisStatArr = _x;
		_playerisin = false;
		_idx = EPOCH_communityStats find (EPOCH_TopStatsVars select _foreachindex);
		if (_idx > -1) then {
			_playerValue = _vars select _idx;
			{
				_x params ["_value","_UID","_name"];
				if (_UID isequalto _playerUID) exitwith {
					_playerisin = true;
					if (_makepublic isEqualTo 0) exitwith {
						_ThisStatArr deleteat _foreachindex;
					};
					if !(_value isequalto _playerValue) then {
						_x set [0,_playerValue];
						_x set [2,_playername];
					};
				};
			} foreach _x;
			if (!_playerisin && (_makepublic > 0)) then {
				_x pushback [(_vars select _idx),_playerUID,_playername];
			};
			_x sort false;
			if (count _x > 10) then {
				_x resize 10;
			};
		};
	} foreach _tempStats;
	EPOCH_TopStats = _tempStats;
	["CommunityStats", "0_TopStats", EPOCH_expiresCommunityStats, EPOCH_TopStats] call EPOCH_fnc_server_hiveSETEX;
	publicvariable "EPOCH_TopStats";
};
