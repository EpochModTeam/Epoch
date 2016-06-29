_nearByBobbersLocal = (player nearEntities[["Bobber_EPOCH"], 12]) select {local _x};
if !(_nearByBobbersLocal isEqualTo []) then {
	if ((random 100) < 50) then {
		_bobber = selectRandom _nearByBobbersLocal;
		_bobber setVelocity [0,-1,-10];
		_bobber setVariable ["EPOCH_fishOnLine" , diag_tickTime];
	};
};
