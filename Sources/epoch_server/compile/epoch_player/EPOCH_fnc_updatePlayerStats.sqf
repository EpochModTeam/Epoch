/*
	Author: DirtySanchez - EpochMod.com

    Contributors:

	Description:
	Save player with token check for use with RemoteExec

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_player/EPOCH_fnc_updatePlayerStats.sqf
*/
params ["_player","_killer","_statType","_adjust","_toClient",["_token","",[""]]];

if(isNull _player)exitWith{
	diag_log "EPOCHDebug: fnc_updatePlayerStats -1a- player is Null";
};
if(isNull _killer)exitWith{
	diag_log "EPOCHDebug: fnc_updatePlayerStats -1b- non local killer is Null";
};

if([_player,_token] call EPOCH_server_getPToken)then{
	[_killer, _statType, _adjust, _toClient] call EPOCH_server_updatePlayerStats;
};