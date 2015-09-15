private["_distance"];

_otherPlyr = _this select 0;
if (!isNull _otherPlyr) then {

	_distance = player distance _otherPlyr;
	if (_distance < 10) then  {

		// restict to only players not in vehicles
		if (vehicle player == player && vehicle _otherPlyr == _otherPlyr) then {

			EPOCH_MAKETRADEREQ = _this;
			publicVariableServer "EPOCH_MAKETRADEREQ";

			// target other player
			EPOCH_p2ptradeTarget = _otherPlyr;
			call EPOCH_startTrade;
		};
	};
};
