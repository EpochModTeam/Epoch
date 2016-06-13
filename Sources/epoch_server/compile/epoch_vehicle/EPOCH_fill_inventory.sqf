/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Fill vehicle inventory

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_vehicle/EPOCH_fill_inventory.sqf
*/
params ["_vehicle","_type","_class","_qty"];
if (!isNull _vehicle) then {
	switch (_type) do {
		case 0: { _vehicle addWeaponCargoGlobal[_class, _qty] };
		case 1: { _vehicle addBackpackCargoGlobal[_class, _qty] };
		case 2: { _vehicle addMagazineCargoGlobal[_class, _qty] };
		case 3: { _vehicle addItemCargoGlobal[_class, _qty] };
	};
};
