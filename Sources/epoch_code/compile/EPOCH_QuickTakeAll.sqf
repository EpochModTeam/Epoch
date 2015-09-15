closeDialog 0;
{
  _magazines = magazinesAmmoCargo _x;
  clearMagazineCargoGlobal _x;
  {
    if !(player canAdd (_x select 0)) exitWith {};
    player addMagazine[_x select 0, _x select 1];
  } foreach _magazines;
} foreach nearestObjects[player, ["container_epoch"], 5];
