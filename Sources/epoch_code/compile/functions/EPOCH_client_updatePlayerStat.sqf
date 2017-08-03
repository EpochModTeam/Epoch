/*

	Author: DirtySanchez - EpochMod.com

    Contributors:

	Description:
	Update player community stat
	Can function as inbound stat adjustment from server side change
	Can also function as client side adjustment and send to server for saving

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/functions/EPOCH_client_updatePlayerStat.sqf
	
	usage: 
	// This will add +15 to the "ZedKills" index and will also update the server variable
	["ZedKills",15,true] call EPOCH_client_updatePlayerStat;
	
	_statType - STRING: the name of the variable as set in the EpochClientConfig defineCommunityStats[] = {};

	_adjust - NUMBER: set the positive or negative adjustment, a value of 0 will exit the script

	_toServer - BOOLEAN: (OPTIONAL): false by default
	
*/
params [ ["_statType",""], ["_adjust",0], ["_toServer",false] ];

if(_statType isEqualTo "")exitWith{
	diag_log "EPOCHDebug: updatePlayerStats -2- stat type not defined";
};
if(_adjust isEqualTo 0)exitWith{
	diag_log "EPOCHDebug: updatePlayerStats -3- stat adjustment is 0";
};

private _statVarName = format["EPOCH_total%1",_statType];
private _currentStat = missionNameSpace getVariable[_statVarName,0];
private _newStat = _currentStat + _adjust;
missionNameSpace setVariable[_statVarName,_newStat];

if(_toServer)then{
	[player, _statType, _adjust, false, Epoch_personalToken] remoteExec ["EPOCH_fnc_updatePlayerStats",2];
};