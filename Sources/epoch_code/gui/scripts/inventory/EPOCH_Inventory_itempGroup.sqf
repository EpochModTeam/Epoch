/*
	Author: Niklas Wagner - EpochMod.com

    Contributors: Aaron Clark

	Description:
	TODO: DESC-TBA

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/inventory/EPOCH_Inventory_itempGroup.sqf
*/
disableSerialization;
(findDisplay 602) closeDisplay 0;
if !(Epoch_invited_tempGroupUIDs isEqualTo[]) exitWith {
	createDialog "tempGroupRequests";
};
["No pending requests", 5] call Epoch_message;
