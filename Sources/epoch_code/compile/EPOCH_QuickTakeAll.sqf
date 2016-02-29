/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Quick take concept for underwater looting

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_code/compile/EPOCH_QuickTakeAll.sqf
*/
private ["_magazines"];
closeDialog 0;
{
  _magazines = magazinesAmmoCargo _x;
  clearMagazineCargoGlobal _x;
  {
    if !(player canAdd (_x select 0)) exitWith {};
    player addMagazine[_x select 0, _x select 1];
  } foreach _magazines;
} foreach nearestObjects[player, ["container_epoch"], 5];
