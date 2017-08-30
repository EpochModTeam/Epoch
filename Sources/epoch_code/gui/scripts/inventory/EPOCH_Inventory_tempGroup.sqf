/*
	Author: Niklas Wagner - EpochMod.com

    Contributors: Aaron Clark

	Description:
	TODO: DESC-TBA

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/inventory/EPOCH_Inventory_tempGroup.sqf
*/
disableSerialization;
(findDisplay 602) closeDisplay 0;
createDialog (if ((Epoch_my_tempGroupUID == "") && (Epoch_my_tempGroup isEqualTo [])) then {"EPOCH_createTempGrp"} else {"Epoch_myTempGroup"});
