/*
	Author: Andrew Gregory - EpochMod.com

    Contributors:

	Description:
	Init and pass vars to mission / task control fsm. fsm will dispose if not being used, this function will restart it as required.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_missions/EPOCH_Server_missionComms.sqf
*/
params["_plyr","_token",["_cmd",-1],["_tmpVar", nil],{"_missionIndex",-1],["_item",objNull],["_pos"],[]];

if !([_plyr, _token] call EPOCH_server_getPToken) exitWith{};

if(isNil "missionControlHandle")then{
missionControlHandle = [] execFSM "x\addons\a3_epoch_server\system\mission_control.fsm";
diag_log format ["MISSION CONTROL INIT: %1",missionControlHandle];

	//Catch first instant if fsm slow to start - may not be necessary.
	["_clientCmd",[_plyr, _cmd, _missionIndex,_item,_pos]] spawn{
	waitUntil {!(isNil "missionControlHandle")};
	missionControlHandle setFSMVariable [_this select 0, _this select 1];
	};
}else{
missionControlHandle setFSMVariable ["_clientCmd",[_plyr, _cmd, _missionIndex,_item,_pos]];
};
