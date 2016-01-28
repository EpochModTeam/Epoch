private["_distance"];

_otherPlyr = _this select 0;
if (!isNull _otherPlyr) then {

	_distance = player distance _otherPlyr;
	if (_distance < 10) then  {

		// restict to only players not in vehicles
		if (vehicle player == player && vehicle _otherPlyr == _otherPlyr) then {

			// send
			_this remoteExec ["EPOCH_server_tradeRequest",2];

			// target other player
			EPOCH_p2ptradeTarget = _otherPlyr;
			call EPOCH_startTrade;
		};
	};
};
