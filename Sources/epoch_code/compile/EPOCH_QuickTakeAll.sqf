/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Quick take concept for underwater looting

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/EPOCH_QuickTakeAll.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_items","_magazines","_weapons"];
//[[[end]]]
closeDialog 0;
{

  _magazines = magazinesAmmoCargo _x;
  clearMagazineCargoGlobal _x;
  {
      [_x select 0,_x select 1] call EPOCH_fnc_addItemOverflow;
  } foreach _magazines;

  _items = itemCargo _x;
  clearItemCargoGlobal _x;
  {
      _x call EPOCH_fnc_addItemOverflow;
  } foreach _items;

  _weapons = weaponCargo _x;
  clearWeaponCargoGlobal _x;
  {
      _x call EPOCH_fnc_addItemOverflow;
  } foreach _weapons;

} foreach nearestObjects[player, ["container_epoch"], 5];
