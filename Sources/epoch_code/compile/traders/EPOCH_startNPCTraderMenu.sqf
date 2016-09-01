//[[[cog import generate_private_arrays ]]]
private ["_ok","_slot","_target"];
//[[[end]]]
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
		{lbAdd[42100,_x];lbAdd[42101,_x]} forEach ["All","Magazines","Items","Vehicles"];
		lbSetCurSel[42100, 0];
		lbSetCurSel[42101, 0];
	};
};
