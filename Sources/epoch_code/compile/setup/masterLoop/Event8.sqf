//Updates favorites bar
call epoch_favBar_refresh;

// process loot
_LootBiasAdd = _LootBiasAdd call _lootBubble;
