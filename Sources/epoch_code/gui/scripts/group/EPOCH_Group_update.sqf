/*
	Author: Niklas Wagner - EpochMod.com

    Contributors: Aaron Clark

	Description:
	TODO: DESC-TBA

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/group/EPOCH_Group_update.sqf
*/
if (!isNull (findDisplay -1300)) then {
	(findDisplay -1300) closeDisplay 0;
	uisleep 0.2; 
	createDialog "Epoch_myGroup";
};
