/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors:

	Description:
	Sorts an array based on distance to input array. (unused)

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/functions/Epoch_SortArrayByDistance.sqf

    Example(s):
		_displayName = _item call epoch_itemData; // string
		_pic = [_item,["Picture"]] call epoch_itemData; //string
		_data = [_item,["picture","model","displayName"]] call epoch_itemData; //array

    Parameter(s):
		_this select 0: STRING - Vehicle, Weapon, or Magazine config class name
		_this select 1: STRING or ARRAY of config variables

	Returns:
	Returns STRING if only one element in second param, otherwise returns ARRAY
*/
//[[[cog import generate_private_arrays ]]]
private ["_arr","_data","_displayName","_pic","_single"];
//[[[end]]]
params [["_item",""],["_entries",["DisplayName"],[[]] ] ];
_single = (count _entries) == 1;
_arr = [];
{
	if ([_item, "CfgMagazines"] call EPOCH_fnc_isAny) then {
	  _arr pushBack (getText(configfile >> "CfgMagazines" >> _item >> _x));
	} else {
		if ([_item, "CfgWeapons"] call EPOCH_fnc_isAny) then {
		  _arr pushBack (getText(configfile >> "CfgWeapons" >> _item >> _x));
		} else {
			if ([_item, "CfgVehicles"] call EPOCH_fnc_isAny) then {
			   _arr pushBack (getText(configfile >> "CfgVehicles" >> _item >> _x));
			};
		};
	};
} forEach _entries;
if (_arr isEqualTo []) then {_arr = [""]};
// return
if (_single) then {_arr select 0} else {_arr}
