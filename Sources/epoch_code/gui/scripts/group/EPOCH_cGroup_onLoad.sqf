if (Epoch_my_GroupUID != "") exitWith {(findDisplay -1200) closeDisplay 0};
disableSerialization;
_textCtrl = (findDisplay -1200) displayCtrl 22;
if (EPOCH_playerCrypto < parseNumber(EPOCH_group_upgrade_lvl select 1)) then {
	_textCtrl CtrlSetText format ["Need %1 Krypto to create your own group",EPOCH_group_upgrade_lvl select 1];
} else {
	_textCtrl CtrlSetText format["Cost to create group %1 Krypto", EPOCH_group_upgrade_lvl select 1];
};
