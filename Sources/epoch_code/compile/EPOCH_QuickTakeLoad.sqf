/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Quick take load function concept for underwater looting

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/EPOCH_QuickTakeLoad.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_index","_magazines"];
//[[[end]]]
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
