
		if ((EPOCH_playerSpawnArray select(EPOCH_spawnIndex find "Epoch_Sapper_F")) <= 0) then{
			_sapperChance = 1 + (EPOCH_playerSoiled / 2);
			if !(EPOCH_nearestLocations isEqualTo[]) then{
				_sapperChance = _sapperChance + 2;
			};
			// 1% - 55% if soiled (+ 2% if in city) chance to spawn sapper every 10 minutes
			if (random _sapperRndChance < _sapperChance) then{
				"Epoch_Sapper_F" call EPOCH_unitSpawnIncrease;
			};
		};

		_spawnUnits = [];
		{
			if (_x > 0) then{
				_spawnUnits pushBack(EPOCH_spawnIndex select _forEachIndex);
			};
		} forEach EPOCH_playerSpawnArray;

		// test spawning one antagonist every 10 minutes select one unit at random to spawn
		if !(_spawnUnits isEqualTo[]) then{
			(_spawnUnits select(floor random(count _spawnUnits))) call EPOCH_unitSpawn;
		};
