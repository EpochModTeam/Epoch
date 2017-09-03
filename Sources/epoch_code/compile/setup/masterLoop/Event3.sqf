// runs every 15 seconds
if !(_prevEquippedItem isEqualTo EPOCH_equippedItem_PVS) then {
	_prevEquippedItem = EPOCH_equippedItem_PVS;
	EPOCH_equippedItem_PVS remoteExec ["EPOCH_server_equippedItem",2];
};
// force update
if (_forceUpdate || EPOCH_forceUpdate) then {
	_forceUpdate = false;
	EPOCH_forceUpdate = false;
	call _fnc_forceUpdate;
};
