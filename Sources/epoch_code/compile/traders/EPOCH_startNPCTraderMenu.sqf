//[[[cog import generate_private_arrays ]]]
private ["_MainCategoriearray","_categorie","_config","_ok","_slot","_target"];
//[[[end]]]
_config = 'CfgItemSort' call EPOCH_returnConfig;
_MainCategoriearray = getarray (_config >> "MainCategories" >> "Classes");
_target = cursorTarget;
if (alive _target) then {
	_slot = _target getVariable ["AI_SLOT",-1];
	if (_slot != -1) then {
		EPOCH_lastNPCtradeTarget = _target;
		closeDialog 0;
		_ok = createdialog "TradeNPCMenu";
		if (!_ok) exitWith {};
		9992 cutRsc["EpochGameUI2", "PLAIN", 2, false];
		((uiNamespace getVariable "EPOCH_EpochGameUI2") displayCtrl 21208) ctrlSetText format["%1", EPOCH_playerCrypto];
		{
			_categorie = _x select 1;
			lbAdd[42100,_categorie];
			lbAdd[42101,_categorie]
		} forEach _MainCategoriearray;
		lbSetCurSel[42100, 0];
		lbSetCurSel[42101, 0];
	};
};
