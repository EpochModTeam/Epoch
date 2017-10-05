/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors:

	Description: manages actions when user presses favorites key

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/scripts/favBar/epoch_favBar_action.sqf

	Usage: none
*/
private ["_throw","_item","_slot","_dsp","_kee","_tileIdx","_itemHasInteraction","_force","_errorCode","_curSlot","_Fav_DropIfOverflow","_Fav_FastWeaponSwitching"];
params ["_dsp","_kee"];

_tileIdx = switch (_kee) do {
	case EPOCH_keysfav1:{0};
	case EPOCH_keysfav2:{1};
	case EPOCH_keysfav3:{2};
	case EPOCH_keysfav4:{3};
	case EPOCH_keysfav5:{4};
};

_item = rmx_var_favBar_current select _tileIdx;
if (_item isequalto "") exitwith {false};
_throw = "";
	{
		if (_item in (getarray (_x >> "Magazines"))) exitwith {
			_throw = configname _x;
		};
	} foreach ("true" configClasses (configfile >> "CfgWeapons" >> "Throw"));
if !(_throw isequalto "") then {
	player forceWeaponFire [_throw,_throw];
}
else {
	_itemHasInteraction = str(missionConfigFile >> "CfgItemInteractions" >> _item) != "";
	if (_itemHasInteraction) then {
		EPOCH_InteractedItem = ["",_item,""];
		[] call EPOCH_consumeItem;
		EPOCH_favBar_itemConsumed = true;
	} else {
		_Fav_DropIfOverflow = ["CfgEpochClient", "Fav_DropIfOverflow", false] call EPOCH_fnc_returnConfigEntryV2;
		_slot = _item call epoch_itemTypeSlot;
		_force = if (_slot in [3,4,5,7,8,10,11,16]) then {true} else {false}; //see how it works with other items, definitely keep true for weapons
		_errorCode = [_item,_Fav_DropIfOverflow,_force] call epoch_equip;
		player selectWeapon _item;

		if (_slot in [3,4,5]) then {
			_curSlot = _item call epoch_itemTypeSlot;
			_Fav_FastWeaponSwitching = ["CfgEpochClient", "Fav_FastWeaponSwitching", false] call EPOCH_fnc_returnConfigEntryV2;
			if (_curSlot == _slot && !_Fav_FastWeaponSwitching && _errorCode in [1,2]) then {player playAction "reloadMagazine";};
		};
	
		if (_errorCode isEqualTo 2) then {"Not enough space, item dropped on the ground!" call epoch_message;};
		if (_errorCode isEqualTo 4 && _item != (currentWeapon player)) then {"Not enough space!" call epoch_message;};
		if (_errorCode isEqualTo 3) then {"Item not found!" call epoch_message;};
		if (_errorCode isEqualTo 5) then {"No compatible weapon found!" call epoch_message;};
	};
};
true
