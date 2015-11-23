
		if !(_prevEquippedItem isEqualTo EPOCH_equippedItem_PVS) then {
			_EPOCH_15 = _tickTime;
			_prevEquippedItem = EPOCH_equippedItem_PVS;
			publicVariableServer "EPOCH_equippedItem_PVS";
		};
