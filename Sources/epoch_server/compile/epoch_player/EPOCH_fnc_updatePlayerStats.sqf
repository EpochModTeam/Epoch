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
params ["_player",["_killer",ObjNull],["_statType",""],["_adjust",0],["_toClient",false],["_token","",[""]],["_isTotal",false]];

if(isNull _player)exitWith{
	diag_log "EPOCHDebug: fnc_updatePlayerStats -1a- player is Null";
};
if(!isplayer _player)exitWith{
	diag_log "EPOCHDebug: fnc_updatePlayerStats -1b- is not a player";
};

if([_player,_token] call EPOCH_server_getPToken)then{
	if (!isnull _killer) then {
		_player = _killer;
	};
	[_player, _statType, _adjust, _toClient, _isTotal] call EPOCH_server_updatePlayerStats;
};