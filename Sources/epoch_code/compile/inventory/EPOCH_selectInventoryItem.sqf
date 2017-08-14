/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	workaround for weapons not returning class in the inventory listboxes

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/inventory/EPOCH_selectInventoryItem.sqf

    Example:
        [_control,_index] call EPOCH_selectInventoryItem;

    Parameter(s):
		_this select 0: CONTROL - control
        _this select 1: NUMBER - listbox index

	Returns:
	NOTHING
*/
//[[[cog import generate_private_arrays ]]]
private ["_container","_craftingArray","_craftingArrayNames","_data","_idc","_index","_pic","_text","_val","_weaponsAndItems"];
//[[[end]]]
params ["_control","_index"];
EPOCH_InteractedItem = [];

if (_index isEqualType []) then {
  _index = (_index select 0) select 1;
};

_idc = ctrlIDC _control;
_text = _control lbText _index;
_data = _control lbData _index;
_pic = _control lbPicture _index;
_val = _control lbValue _index;

_craftingArray = [];
_craftingArrayNames = [];

// weapons and items do not return a class so a workaround is used to find the class
if (_data == "") then {
    _container = switch (_idc) do {
        case 633: { uniformContainer player };
        case 638: { vestContainer player };
        case 632: { if (isnull EPOCH_secondaryContainer) then {EPOCH_targetContainer} else {EPOCH_secondaryContainer} };
        case 640: { EPOCH_targetContainer };
        default { backpackContainer player };
    };
    _weaponsAndItems = ((getWeaponCargo  _container) select 0);
    _weaponsAndItems append ((getItemCargo _container) select 0);
    _data = _weaponsAndItems param [_val,""];
};
EPOCH_InteractedItem = [_text,_data,_pic];
