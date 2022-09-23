// run every 300s

_playerNuisance = missionNamespace getVariable [_playerNuisanceKey, _playerNuisanceDefault];
_playerSoiled = missionNamespace getVariable [_playerSoiledKey, _playerSoiledDefault];
_spawnChance = ((_playerNuisance + _playerSoiled)/2) max 1;

if (random _antagonistRndChance < _spawnChance) then {
	(selectRandomWeighted _antagonistChances) call EPOCH_unitSpawnIncrease;
};


_spawnUnits = [];
{
	if (_x > 0) then{
		_spawnUnits pushBack(EPOCH_spawnIndex select _forEachIndex);
	};
} forEach (missionNamespace getVariable [_playerSpawnArrayKey, _playerSpawnArrayDefault]);

diag_log format["DEBUG: _spawnUnits %1",_spawnUnits];

// select one random antagonist to spawn
if !(_spawnUnits isEqualTo[]) then{
	(selectRandom _spawnUnits) call EPOCH_unitSpawn;
};
_UpdateTopStats = true;