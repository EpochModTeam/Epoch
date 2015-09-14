disableSerialization;
_BtnInvite = (findDisplay -1300) displayCtrl 30;
_playerUID = getPlayerUID player;
if (_playerUID == Epoch_my_GroupUID || {_x select 0 == _playerUID}count (Epoch_my_Group select 3) > 0) then {
	_currentMember = count(Epoch_my_Group select 3) + count(Epoch_my_Group select 4) + 1;
	_currentMaxMember = Epoch_my_Group select 2;
	if (_currentMember < _currentMaxMember) then {
		_InvitePlayerCombo = (findDisplay -1300) displayCtrl 41;
		_playerUID = _InvitePlayerCombo lbData (lbCurSel _InvitePlayerCombo);
		_playerName = _InvitePlayerCombo lbText (lbCurSel _InvitePlayerCombo);
		if (_playerUID != "" && _playerName != "") then {
			_txt = format["Do you want to add %1 to your Group?",_playerName];
			[_playerUID,_txt] spawn {
				_ret = [_this select 1,"Epoch Group Menu",true,true] call BIS_fnc_GUImessage;
				if (_ret) then {
					EPOCH_GROUP_Invite_PVS = [_this select 0,Epoch_my_GroupUID,Epoch_my_Group select 0,player,Epoch_personalToken];
					publicVariableServer "EPOCH_GROUP_Invite_PVS";
				};
			};
		};
	} else {
		_found = EPOCH_group_upgrade_lvl find _currentMaxMember;
		if (count EPOCH_group_upgrade_lvl >= (_found+3)) then {
			_upgradePrice = parseNumber	(EPOCH_group_upgrade_lvl select (_found+3));
			if ((EPOCH_playerCrypto-_upgradePrice) >= 0) then {
				_upgradeSlots = EPOCH_group_upgrade_lvl select (_found+2);
				_txt = format["Do you want to upgrade your group from %1 to %2 slots for %3 Krypto?",_currentMaxMember,_upgradeSlots,_upgradePrice];
				[_txt,_upgradePrice] spawn {
					_ret = [_this select 0,"Epoch Group Menu",true,true] call BIS_fnc_GUImessage;
					if (_ret) then {
						EPOCH_GROUP_Upgrade_PVS = [Epoch_my_GroupUID,player,Epoch_personalToken];
						publicVariableServer "EPOCH_GROUP_Upgrade_PVS";
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