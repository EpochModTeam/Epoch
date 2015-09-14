createDialog "QuickTake";
{
  _magazines = magazinesAmmoCargo _x;
  {
    _index = lbAdd[1500, getText(configfile >> "CfgMagazines" >> (_x select 0) >> "DisplayName")];
    lbSetData[1500, _index, _x select 0];
    lbSetValue[1500, _index, _x select 1];
    lbSetPicture[1500, _index, _x select 0 call EPOCH_itemPicture];
  } foreach _magazines;
} foreach nearestObjects[player, ["container_epoch"], 5];
