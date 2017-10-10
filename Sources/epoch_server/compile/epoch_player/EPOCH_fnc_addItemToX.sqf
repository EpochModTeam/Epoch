/*
	Author: Aaron Clark - EpochMod.com

    Contributors: He-Man

	Description:
	Add items/weapons to player containers

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_player/EPOCH_fnc_addItemToX.sqf

    Example:
    [_player, _itemsInContainers] call EPOCH_fnc_addItemToX;

    Parameter(s):
		_this select 0: OBJECT - player
        _this select 1: ARRAY -
        [
            [["itemClass",1],["anotherClass",5]], // addItemToUniform
            [["thatClass",2],["thisClass",2]], // addItemToVest
            [["yourClass",4],["myClass",3]] // addItemToBackpack
        ]
*/
params ["_player","_slots"];
{
	private _itemSlot = _forEachIndex;
    _x params ["_items","_itemqtys"];
	{
		for "_i" from 1 to (_itemqtys select _forEachIndex) do {
			switch _itemSlot do {
				case 0: { _player addItemToUniform _x };
				case 1: { _player addItemToVest _x };
				case 2: { _player addItemToBackpack _x };
			};
		};
	} forEach(_items);
} forEach (_slots);
