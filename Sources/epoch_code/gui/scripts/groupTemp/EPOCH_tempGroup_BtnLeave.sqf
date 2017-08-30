/*
	Author: Niklas Wagner - EpochMod.com

    Contributors: Aaron Clark

	Description:
	TODO: DESC-TBA

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/groupTemp/EPOCH_tempGroup_BtnLeave.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_BtnLeave","_ret","_txt"];
//[[[end]]]
disableSerialization;
Epoch_my_tempGroup params [
    ["_groupName",""],
    ["_leaderName",""],
    ["_groupSize",0],
    ["_modArray",[]],
    ["_memberArray",[]]
];
if (getPlayerUID player == Epoch_my_tempGroupUID) then {
	_txt = format["Do you want to delete your Temp Group called %1?",_groupName];
	_txt spawn {
		_ret = [_this,"Epoch Temp Group Menu",true,true] call BIS_fnc_GUImessage;
		if (_ret) then {
			[player,Epoch_personalToken] remoteExec ["EPOCH_server_deleteTempGroup",2];
		};
	};
} else {
	_txt = format["Do you want to leave the %1 Temp Group?",_groupName];
	_txt spawn {
		_ret = [_this,"Epoch Temp Group Menu",true,true] call BIS_fnc_GUImessage;
		if (_ret) then {
			[Epoch_my_tempGroupUID,getPlayerUID player,false,false,player,Epoch_personalToken] remoteExec ["EPOCH_server_updatePlayerTempGroup",2];
		};
	};
};
