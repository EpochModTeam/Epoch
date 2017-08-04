/*
	Author: DirtySanchez - EpochMod.com

    Contributors: 

	Description:
	Antagonist killed event handler

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/EPOCH_unit_onKilledEH.sqf
*/
params [ ["_killedEH",[]], ["_statType","AIKills"], ["_adjust", 0], ["_toClient", false] ];
if(_killedEH isEqualTo [])exitWith{diag_log "EPOCHDebug: unit_onKilledEH -1- EH sent empty array";};
if(_statType isEqualTo "")exitWith{diag_log "EPOCHDebug: unit_onKilledEH -2- stat Type is empty string";};
if(_adjust isEqualTo 0)exitWith{diag_log "EPOCHDebug: unit_onKilledEH -3- stat adjustment is 0";};

_unit = _killedEH select 0;
_killer = _killedEH select 1;
if(_unit isEqualTo _killer)exitWith{
	//diag_log "EPOCHDebug: unit_onKilledEH -4- unit is killer";
};
[player, _killer, _statType, _adjust, _toClient, Epoch_personalToken] remoteExec ["EPOCH_fnc_updatePlayerStats",2];