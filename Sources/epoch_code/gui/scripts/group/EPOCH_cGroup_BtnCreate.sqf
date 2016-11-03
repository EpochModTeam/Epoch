/*
	Author: Niklas Wagner - EpochMod.com

    Contributors: Aaron Clark

	Description:
	TODO: DESC-TBA

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/group/EPOCH_cGroup_BtnCreate.sqf
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
	["Your group need a name!","Epoch Group Menu",true,false] spawn BIS_fnc_GUImessage;
} else {
	_groupName = toString(_array);
	_txtCtrl ctrlSetText _groupName;

	_upgradePrice = parseNumber (EPOCH_group_upgrade_lvl select 1);
	if ((EPOCH_playerCrypto-_upgradePrice) >= 0) then {
		[_groupName,_upgradePrice] spawn {
			_txt = format["Do you want to create your group called %1? You cannot change the group name later!",_this select 0];
			_ret = [_txt,"Epoch Group Menu",true,true] call BIS_fnc_GUImessage;
			if (_ret) then {
				[player,_this select 0,Epoch_personalToken] remoteExec ["EPOCH_server_createGroup",2];

				_timeout = diag_tickTime+10;
				waitUntil {
					((Epoch_my_GroupUID != "") && !(Epoch_my_Group isEqualTo [])) || ((_timeout - diag_tickTime) <= 0)
				};
				(findDisplay -1200) closeDisplay 0;
				if ((Epoch_my_GroupUID != "") && !(Epoch_my_Group isEqualTo [])) then {
					createDialog "Epoch_myGroup";
				};
			};
		};
	} else {
		["You don't have enough Krypto to create a group!","Epoch Group Menu",true,false] spawn BIS_fnc_GUImessage;
	};
};
