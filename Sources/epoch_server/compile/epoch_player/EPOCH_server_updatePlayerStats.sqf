/*

	Author: DirtySanchez - EpochMod.com

    Contributors:

	Description:
	Save player community stats - default server only update, _this select 3 = true will send stat update to client

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_player/EPOCH_server_updatePlayerStats.sqf
	
	usage: 
	
		example 1:
		[_playerObj, "AIKills", 1] call Epoch_server_updatePlayerStats;
		
		usage example
		[_playerObj, _statType, _adjust, true] call Epoch_server_updatePlayerStats;
	
	_playerObj - OBJECT: the player object to receive the stat adjust and send to database/player

	_statType - STRING: the name of the variable as set in the EpochClientConfig defineCommunityStats[] = {};

	_adjust - NUMBER: set the positive or negative adjustment, a value of 0 will exit the script

	_toClient - BOOLEAN: (OPTIONAL) by default this script is server side variables/hive changes only.
								by setting this true the client will receive the stat update.
								Use true when the stat change originates from the server and not the client.
*/
params [ ["_playerObj",objNull], ["_statType",""], ["_adjust",0], ["_toClient",false], ["_isTotal",false]];

if(isNull _playerObj)exitWith{
	diag_log "EPOCHDebug: playerUpdateStats -1- player is null object";
};
if(_statType isEqualTo "")exitWith{
	diag_log "EPOCHDebug: playerUpdateStats -2- stat type not defined";
};
if(_adjust isEqualTo 0 && !_isTotal)exitWith{
	diag_log "EPOCHDebug: playerUpdateStats -3- stat adjustment is 0";
};
_playerUID = getplayerUID _playerObj;
if(_playerUID isEqualTo "")exitWith{
	diag_log "EPOCHDebug: playerUpdateStats -4- player UID is empty";
};
if(!isplayer _playerObj)exitWith{
	diag_log "EPOCHDebug: playerUpdateStats -5- is not a player";
};

//get this playerObj stats 
_playerStats = _playerObj getVariable["COMMUNITY_STATS", EPOCH_defaultStatVars];
//get this stats index #
_sIndex = EPOCH_communityStats find _statType;
if (_sIndex > -1) then {
	//get this stat value
	_currentStat = _playerStats select _sIndex;
	//set the new stat value
	if (_isTotal) then {
		_playerStats set[_sIndex, _adjust min 3.4028235e+37 max -3.4028235e+37];	// +/- 3.4028235e+38 is Epoch Extension limit!
	}
	else {
		_playerStats set[_sIndex, (_currentStat + _adjust) min 3.4028235e+37 max -3.4028235e+37];
	};
	//set the new stats array back onto this playerObj
	_playerObj setVariable["COMMUNITY_STATS", _playerStats];

	//send to hive
//	["CommunityStats", _playerUID, EPOCH_expiresCommunityStats, [_playerStats]] call EPOCH_fnc_server_hiveSETEX;
	// Prevent saving to DB too much often, as it is already saved on Player Save Loop / Disconnect / Kill

	//send to player
	if(_toClient)then{
		[_statType,_adjust,false,_isTotal] remoteExecCall ["EPOCH_client_updatePlayerStat",(owner _playerObj)];
	};
};