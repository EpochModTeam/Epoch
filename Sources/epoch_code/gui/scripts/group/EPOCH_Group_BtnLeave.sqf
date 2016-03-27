/*
	Author: Niklas Wagner - EpochMod.com

    Contributors: Aaron Clark

	Description:
	TODO: DESC-TBA

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_code/gui/group/EPOCH_Group_BtnLeave.sqf
*/
private ["_txt","_BtnLeave"];
disableSerialization;
_BtnLeave = (findDisplay -1300) displayCtrl 31;
if (getPlayerUID player == Epoch_my_GroupUID) then {
	_BtnLeave ctrlSetText "Delete Group";
	_txt = format["Do you want to delete your Group called %1?",Epoch_my_Group select 0];
	_txt spawn {
		_ret = [_this,"Epoch Group Menu",true,true] call BIS_fnc_GUImessage;
		if (_ret) then {
			[player,Epoch_personalToken] remoteExec ["EPOCH_server_deleteGroup",2];
		};
	};
} else {
	_txt = format["Do you want to leave the %1 Group?",Epoch_my_Group select 0];
	_txt spawn {
		_ret = [_this,"Epoch Group Menu",true,true] call BIS_fnc_GUImessage;
		if (_ret) then {
			[Epoch_my_GroupUID,getPlayerUID player,false,false,player,Epoch_personalToken] remoteExec ["EPOCH_server_updatePlayerGroup",2];
		};
	};
};
