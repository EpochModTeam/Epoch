if !(_prevEquippedItem isEqualTo EPOCH_equippedItem_PVS) then {
	_EPOCH_15 = _tickTime;
	_prevEquippedItem = EPOCH_equippedItem_PVS;
	EPOCH_equippedItem_PVS remoteExec ["EPOCH_server_equippedItem",2];
};
