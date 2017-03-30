/*
	Author: Niklas Wagner - EpochMod.com

    Contributors: Aaron Clark

	Description:
	TODO: DESC-TBA

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/group/EPOCH_Group_BtnMod.sqf
*/
disableSerialization;
//[[[cog import generate_private_arrays ]]]
private ["_group","_isMember","_playerUID","_ret","_selected","_txt"];
//[[[end]]]
if (getPlayerUID player == Epoch_my_GroupUID) then {
	_group = (findDisplay -1300) displayCtrl 40;
	_selected = lbCurSel _group;
	if (_selected >= 0) then {
		_playerUID = _group lbData _selected;
		if (_playerUID != "") then {
			_isMember = (_group lbPicture _selected) == (EPOCH_group_level_img select 2);
			_txt = if (_isMember) then {
				format["Do you want to give %1 moderator permissions?",_group lbText _selected];
			} else {
				format["Do you want to remove %1 moderator permissions?",_group lbText _selected];
			};

			[_playerUID,_isMember,_txt] spawn {
                params ["_playerUID","_isMember","_txt"];
				_ret = [_txt,"Epoch Group Menu",true,true] call BIS_fnc_GUImessage;
				if (_ret) then {
					[Epoch_my_GroupUID,_playerUID,true,_isMember,player,Epoch_personalToken] remoteExec ["EPOCH_server_updatePlayerGroup",2];
				};
			};
		};
	} else {
		["You need to select a player!", 5] call Epoch_message;
	};
	true
} else {
	false
};
