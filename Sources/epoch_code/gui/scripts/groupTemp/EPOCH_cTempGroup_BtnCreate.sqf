/*
	Author: Niklas Wagner - EpochMod.com

    Contributors: Aaron Clark

	Description:
	TODO: DESC-TBA

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/groupTemp/EPOCH_cTempGroup_BtnCreate.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_array","_groupName","_ret","_timeout","_txt","_txtCtrl","_upgradePrice"];
//[[[end]]]
disableSerialization;
_txtCtrl = (findDisplay -1200) displayCtrl 21;
_array = toArray(ctrlText _txtCtrl);

if (count _array > 24) then {
	_array resize 24;
};

if (count (_array-[32]) == 0) then { //32 = SPACE
	["Your group need a name!","Epoch Temp Group Menu",true,false] spawn BIS_fnc_GUImessage;
} else {
	_groupName = toString(_array);
	_txtCtrl ctrlSetText _groupName;

	_groupName spawn {
		_txt = format["Do you want to create your temp group called %1? You can disband/leave this group to create a new one!",_this];
		_ret = [_txt,"Epoch Temp Group Menu",true,true] call BIS_fnc_GUImessage;
		if (_ret) then {
			[player,_this,Epoch_personalToken] remoteExec ["EPOCH_server_createTempGroup",2];
			_timeout = diag_tickTime+10;
			waitUntil {
				((Epoch_my_tempGroupUID != "") && !(Epoch_my_tempGroup isEqualTo [])) || ((_timeout - diag_tickTime) <= 0)
			};
			(findDisplay -1200) closeDisplay 0;
			if ((Epoch_my_tempGroupUID != "") && !(Epoch_my_tempGroup isEqualTo [])) then {
				createDialog "Epoch_myTempGroup";
			};
		};
	};
};
