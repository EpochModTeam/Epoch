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
private ["_index"];
//[[[end]]]
createDialog "QuickTake";
{
	if ((_x getvariable ["EPOCH_Loot",false]) || _x iskindof "container_epoch") then {
		{
			_index = lbAdd[1500, getText(configfile >> "CfgMagazines" >> (_x select 0) >> "DisplayName")];
			lbSetData[1500, _index, _x select 0];
			lbSetValue[1500, _index, _x select 1];
			lbSetPicture[1500, _index, _x select 0 call EPOCH_itemPicture];
		} foreach (magazinesAmmoCargo _x);

		{
			_index = lbAdd[1500, getText(configfile >> "CfgWeapons" >> _x >> "DisplayName")];
			lbSetData[1500, _index, _x];
			lbSetValue[1500, _index, _x];
			lbSetPicture[1500, _index, _x call EPOCH_itemPicture];
		} foreach (itemcargo _x);

		{
			_index = lbAdd[1500, getText(configfile >> "CfgWeapons" >> _x >> "DisplayName")];
			lbSetData[1500, _index, _x];
			lbSetValue[1500, _index, _x];
			lbSetPicture[1500, _index, _x call EPOCH_itemPicture];
		} foreach (weaponCargo _x);
	};
} foreach (nearestObjects[player, ["container_epoch","weaponholdersimulated","GroundWeaponHolder"], 5]);