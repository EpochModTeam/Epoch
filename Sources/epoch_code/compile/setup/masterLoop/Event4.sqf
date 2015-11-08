
		_nearByBobbersLocal = [];
		_nearByBobbers = player nearEntities[["Bobber_EPOCH"], 12];
		{
			if (local _x) then {
				_nearByBobbersLocal pushBack _x
			}
		} forEach _nearByBobbers;

		if !(_nearByBobbersLocal isEqualTo []) then {
			if ((random 100) < 50) then {
				_bobber = _nearByBobbersLocal select floor(random(count _nearByBobbers));
				_bobber setVelocity [0,-1,-1];
				_bobber setVariable ["EPOCH_fishOnLine" , diag_tickTime];
			};

		};
