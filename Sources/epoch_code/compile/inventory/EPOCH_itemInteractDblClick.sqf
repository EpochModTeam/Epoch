/*
	Author: Aaron Clark - EpochMod.com

    Contributors: Raimonds Virtoss

	Description:
	Epoch Item Interact when double clicked

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/inventory/EPOCH_itemInteractDblClick.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_config","_data"];
//[[[end]]]
_this call EPOCH_selectInventoryItem;
_data = EPOCH_InteractedItem select 1;
_config = 'CfgCrafting' call EPOCH_returnConfig;
if (isClass (_config >> _data)) then {
	(EPOCH_InteractedItem select 0) call EPOCH_crafting_load;
} else {
	//TODO: eat, drink, build ... etc
};
