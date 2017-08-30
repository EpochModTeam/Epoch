/*
	Author: Niklas Wagner - EpochMod.com

    Contributors: Aaron Clark

	Description:
	TODO: DESC-TBA

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/groupTemp/EPOCH_tempGroup_BtnInvite.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_BtnInvite","_InvitePlayerCombo","_groupSize","_currentMember","_found","_playerName","_playerUID","_ret","_txt","_upgradePrice","_upgradeSlots"];
//[[[end]]]
disableSerialization;
_BtnInvite = (findDisplay -1300) displayCtrl 30;
_playerUID = getPlayerUID player;

Epoch_my_tempGroup params [
    ["_groupName",""],
    ["_leaderName",""],
    ["_groupSize",0],
    ["_modArray",[]],
    ["_memberArray",[]]
];

Epoch_my_Group params [
    ["_groupName2",""],
    ["_leaderName2",""],
    ["_groupSize2",0],
    ["_modArray2",[]],
    ["_memberArray2",[]]
];

if (_playerUID == Epoch_my_tempGroupUID || {_x select 0 == _playerUID}count (_modArray) > 0) then {
	_currentMember = count(_modArray) + count(_memberArray) + 1;
	if (_currentMember < _groupSize) then {
		_InvitePlayerCombo = (findDisplay -1300) displayCtrl 41;
		_playerUID = _InvitePlayerCombo lbData (lbCurSel _InvitePlayerCombo);
		_playerName = _InvitePlayerCombo lbText (lbCurSel _InvitePlayerCombo);
		if (_playerUID != "" && _playerName != "" && ({_playerUID in _x} count (_modArray) == 0) && ({_playerUID in _x} count (_memberArray) == 0) && ({_playerUID in _x} count (_modArray2) == 0) && ({_playerUID in _x} count (_memberArray2) == 0) && !(_playerUID == Epoch_my_tempGroupUID)) then {
			_txt = format["Do you want to add %1 to your Temp Group?",_playerName];
			[_playerUID,_txt,_groupName] spawn {
                params ["_playerUID","_txt","_groupName"];
				_ret = [_txt,"Epoch Temp Group Menu",true,true] call BIS_fnc_GUImessage;
				if (_ret) then {
					[_playerUID,Epoch_my_tempGroupUID,_groupName,player,Epoch_personalToken] remoteExec ["EPOCH_server_invitePlayerTempGroup",2];
				};
			};
		};
	};
	true
} else {
	false
};
