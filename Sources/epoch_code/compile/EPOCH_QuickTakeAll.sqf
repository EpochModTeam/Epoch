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
	if ((_x getvariable ["EPOCH_Loot",false]) || _x iskindof "container_epoch") then {
		_nearplayers = (player nearEntities ["Man", 12]) select {alive _x && isplayer _x && !(_x == player)};
		if (count _nearplayers > 0) exitwith {
			["Take all not allowed near other Players",5] call Epoch_message;
		};
		_magazines = magazinesAmmoCargo _x;
		clearMagazineCargoGlobal _x;
		{
			[_x select 0,1] call EPOCH_fnc_addItemOverflow;
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
	};
} foreach nearestObjects[player, ["container_epoch","weaponholdersimulated","GroundWeaponHolder"], 5];
