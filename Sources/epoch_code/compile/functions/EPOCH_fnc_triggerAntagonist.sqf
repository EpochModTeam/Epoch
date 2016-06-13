/*
	Author: Andrew Gregory - EpochMod.com

    Contributors: Aaron Clark

	Description:
	Send server message to trigger antagonist on another client. Server returns antagonist object where required. Designed to support additional tap out options (Morphing).

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/functions/EPOCH_fnc_triggerAntagonist.sqf

    Example:
    [_killer, "Epoch_Sapper_F", player, true] call EPOCH_fnc_triggerAntagonist;

    Parameter(s):
		_this select 0: Target client to trigger antagonist on. (Killer)
		_this select 1: Antagonist class to spawn, e.g. "Epoch_Sapper_F", see EPOCH_unitSpawn.sqf for full list
        _this select 2: On target, set variable containing antagonist object. Allows other players / requesting player to attach to antagonist object.
        
	Returns:
	
*/
params ["_target","_antagonist","_doVariable"];
[_target,_antagonist,_doVariable,player,Epoch_personalToken] remoteExec ["EPOCH_server_triggerAntagonist",2];