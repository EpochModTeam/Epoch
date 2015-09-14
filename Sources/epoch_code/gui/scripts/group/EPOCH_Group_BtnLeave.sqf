disableSerialization;

_BtnLeave = (findDisplay -1300) displayCtrl 31;
if (getPlayerUID player == Epoch_my_GroupUID) then {
	_BtnLeave ctrlSetText "Delete Group";
	_txt = format["Do you want to delete your Group called %1?",Epoch_my_Group select 0];
	_txt spawn {
		_ret = [_this,"Epoch Group Menu",true,true] call BIS_fnc_GUImessage;
		if (_ret) then {
			EPOCH_GROUP_Delete_PVS = [player,Epoch_personalToken];
			publicVariableServer "EPOCH_GROUP_Delete_PVS";
		};
	};
} else {
	_txt = format["Do you want to leave the %1 Group?",Epoch_my_Group select 0];
	_txt spawn {
		_ret = [_this,"Epoch Group Menu",true,true] call BIS_fnc_GUImessage;
		if (_ret) then {
			EPOCH_GROUP_Player_PVS = [Epoch_my_GroupUID,getPlayerUID player,false,false,player,Epoch_personalToken];
			publicVariableServer "EPOCH_GROUP_Player_PVS";
		};
	};
};