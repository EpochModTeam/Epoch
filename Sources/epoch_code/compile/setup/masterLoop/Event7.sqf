_spawnChance = ((EPOCH_playerNuisance + EPOCH_playerSoiled)/2) max 1;
if (random _droneRndChance < _spawnChance) then {
	"I_UAV_01_F" call EPOCH_unitSpawnIncrease;
};
if (EPOCH_mod_Ryanzombies_Enabled) then {
	if (random _zombieRngChance < _spawnChance) then {
		["EPOCH_RyanZombie_1",12] call EPOCH_unitSpawnIncrease;
	};
};
if (random _sapperRndChance < _spawnChance) then {
	"Epoch_Sapper_F" call EPOCH_unitSpawnIncrease;
};
// diag_log format["DEBUG: _spawnChance %1",_spawnChance];

_spawnUnits = [];
{
	if (_x > 0) then{
		_spawnUnits pushBack(EPOCH_spawnIndex select _forEachIndex);
	};
} forEach EPOCH_playerSpawnArray;

// test spawning one antagonist every 10 minutes select one unit at random to spawn
if !(_spawnUnits isEqualTo[]) then{
	(selectRandom _spawnUnits) call EPOCH_unitSpawn;
};
