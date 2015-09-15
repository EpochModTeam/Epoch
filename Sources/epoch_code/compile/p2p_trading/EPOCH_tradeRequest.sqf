if !(isNull _this) then {
	// ignore request if either player is in a vehicle
	if (vehicle player == player && vehicle _this == _this) then {
		_dt = ["<t size='0.8' shadow='0' color='#99ffffff'>Trade request received, press 'T' to accept</t>", 0, 1, 5, 2, 0, 1] spawn bis_fnc_dynamictext;
		EPOCH_pendingP2ptradeTarget = _this;
	};
};
