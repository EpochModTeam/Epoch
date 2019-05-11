/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Save player with token check for use with RemoteExec

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_player/EPOCH_fnc_savePlayer.sqf
*/
params ["_player","",["_token","",[""]],["_stats",[]]];
if([_player,_token] call EPOCH_server_getPToken)then{
	{
		_x params ["_statType","_adjust","_isTotal"];
		[_player, _statType, _adjust, false,_isTotal] call Epoch_server_updatePlayerStats;
	} foreach _stats;
    _this call EPOCH_server_savePlayer;
};
