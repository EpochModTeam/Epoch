/*
	Author: Niklas Wagner - EpochMod.com

    Contributors: Aaron Clark

	Description:
	TODO: DESC-TBA

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/group/EPOCH_Group_BtnInvite.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_BtnInvite","_InvitePlayerCombo","_groupSize","_currentMember","_found","_playerName","_playerUID","_ret","_txt","_upgradePrice","_upgradeSlots"];
//[[[end]]]
disableSerialization;
_BtnInvite = (findDisplay -1300) displayCtrl 30;
_playerUID = getPlayerUID player;

Epoch_my_Group params [
    ["_groupName",""],
    ["_leaderName",""],
    ["_groupSize",0],
    ["_modArray",[]],
    ["_memberArray",[]]
];

if (_playerUID == Epoch_my_GroupUID || {_x select 0 == _playerUID}count (_modArray) > 0) then {
	_currentMember = count(_modArray) + count(_memberArray) + 1;
	if (_currentMember < _groupSize) then {
		_InvitePlayerCombo = (findDisplay -1300) displayCtrl 41;
		_playerUID = _InvitePlayerCombo lbData (lbCurSel _InvitePlayerCombo);
		_playerName = _InvitePlayerCombo lbText (lbCurSel _InvitePlayerCombo);
		if (_playerUID != "" && _playerName != "" && ({_playerUID in _x} count (_modArray) == 0) && ({_playerUID in _x} count (_memberArray) == 0) && !(_playerUID == Epoch_my_GroupUID)) then {
			_txt = format["Do you want to add %1 to your Group?",_playerName];
			[_playerUID,_txt,_groupName] spawn {
                params ["_playerUID","_txt","_groupName"];
				_ret = [_txt,"Epoch Group Menu",true,true] call BIS_fnc_GUImessage;
				if (_ret) then {
					[_playerUID,Epoch_my_GroupUID,_groupName,player,Epoch_personalToken] remoteExec ["EPOCH_server_invitePlayer",2];
				};
			};
		};
	} else {
		_found = EPOCH_group_upgrade_lvl find _groupSize;
		if (count EPOCH_group_upgrade_lvl >= (_found+3)) then {
			_upgradePrice = parseNumber	(EPOCH_group_upgrade_lvl select (_found+3));
			if ((EPOCH_playerCrypto-_upgradePrice) >= 0) then {
				_upgradeSlots = EPOCH_group_upgrade_lvl select (_found+2);
				_txt = format["Do you want to upgrade your group from %1 to %2 slots for %3 Krypto?",_groupSize,_upgradeSlots,_upgradePrice];
				[_txt,_upgradePrice] spawn {
                    params ["_txt","_upgradePrice"];
					_ret = [_txt,"Epoch Group Menu",true,true] call BIS_fnc_GUImessage;
					if (_ret) then {
						[Epoch_my_GroupUID,player,Epoch_personalToken] remoteExec ["EPOCH_server_upgradeGroup",2];
					};
				};
			} else {
				["You don't have enough Krypto to upgrade your group!","Epoch Group Menu",true,false] spawn BIS_fnc_GUImessage;
			};
		};
	};
	true
} else {
	false
};
