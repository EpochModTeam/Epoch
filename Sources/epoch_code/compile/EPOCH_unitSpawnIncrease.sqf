_index = EPOCH_spawnIndex find _this;
if (_index != -1) then{
  EPOCH_playerSpawnArray set[_index, ((EPOCH_playerSpawnArray select _index) + 1) min (EPOCH_spawnLimits select _index)];
};
