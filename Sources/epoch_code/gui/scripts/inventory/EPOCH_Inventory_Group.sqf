/*
	Author: Niklas Wagner - EpochMod.com

    Contributors: Aaron Clark

	Description:
	TODO: DESC-TBA

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/inventory/EPOCH_Inventory_Group.sqf
*/
disableSerialization;
(findDisplay 602) closeDisplay 0;
createDialog (if ((Epoch_my_GroupUID == "") && (Epoch_my_Group isEqualTo [])) then {"EPOCH_createGrp"} else {"Epoch_myGroup"});
