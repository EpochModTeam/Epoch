/*
	Author: He-Man - EpochMod.com

	Contributors:

	Description:
	Set final Player position on login

	Licence:
	Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Github:
	https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_player/EPOCH_server_SetFinalPlayerPos.sqf
*/

params ["_player","_newPlyr"];
private ["_finalpos","_fallbackpos"];
if (isnull _player || isnull _newPlyr) exitwith {
	diag_log "DEBUG: SetFinalPlayerPos failed - Player or PlayerObj is Null";
};
if !(typeof _player isequalto "VirtualMan_EPOCH") exitwith {
	diag_log "DEBUG: SetFinalPlayerPos failed - PlayerObj != VirtualMan_EPOCH";
};
_finalpos = _newPlyr getvariable ["FinalDest",[]];
if (_finalpos isequalto []) exitwith {
	diag_log "DEBUG: SetFinalPlayerPos failed - No FinalPos Variable set";
};
if !(_finalpos isequaltype []) exitwith {
	diag_log "DEBUG: SetFinalPlayerPos failed - FinalPos is not an Array";
};
if (count _finalpos < 2) exitwith {
	diag_log "DEBUG: SetFinalPlayerPos failed - count FinalPos < 2";
};
_fallbackpos = getmarkerpos "respawn_west";
_fallbackpos set [2,0];
_finalpos params [["_location",_fallbackpos],["_dir",0]];
_newPlyr setDir _dir;
_newPlyr setPosATL _location;
_newPlyr setVariable["SETUP", true, true];
_player setPosATL _location;
_newPlyr allowdamage true;
_newPlyr hideobjectglobal false;

