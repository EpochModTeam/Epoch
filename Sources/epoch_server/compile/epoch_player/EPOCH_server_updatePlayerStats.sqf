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
params [ ["_playerObj",objNull], ["_statType",""], ["_adjust",0], ["_toClient",false] ];

if(isNull _playerObj)exitWith{
	diag_log "EPOCHDebug: playerUpdateStats -1- player is null object";
};
if(_statType isEqualTo "")exitWith{
	diag_log "EPOCHDebug: playerUpdateStats -2- stat type not defined";
};
if(_adjust isEqualTo 0)exitWith{
	diag_log "EPOCHDebug: playerUpdateStats -3- stat adjustment is 0";
};
_playerUID = getplayerUID _playerObj;
if(_playerUID isEqualTo "")exitWith{
	diag_log "EPOCHDebug: playerUpdateStats -4- player UID is empty";
};

//get this playerObj stats 
_playerStats = _playerObj getVariable["COMMUNITY_STATS", EPOCH_defaultStatVars];
//get this stats index #
_sIndex = EPOCH_communityStats find _statType;
//get this stat value
_currentStat = _playerStats select _sIndex;
//set the new stat value
_playerStats set[_sIndex, _currentStat + _adjust];
//set the new stats array back onto this playerObj
_playerObj setVariable["COMMUNITY_STATS", _playerStats];

//send to hive
["CommunityStats", _playerUID, EPOCH_expiresCommunityStats, [_playerStats]] call EPOCH_fnc_server_hiveSETEX;

//send to player
if(_toClient)then{
	[_statType,_adjust] remoteExecCall ["EPOCH_client_updatePlayerStat",(owner _playerObj)];
};