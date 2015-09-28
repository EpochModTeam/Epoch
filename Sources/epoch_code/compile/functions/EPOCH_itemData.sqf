/*
Returns string if only one element in second param, otherwise returns array

	_displayName = _item call epoch_itemData; // string
	_pic = [_item,["Picture"]] call epoch_itemData; //string
	_data = [_item,["picture","model","displayName"]] call epoch_itemData; //array
*/

private ["_item","_entries","_single","_arr","_return"];
_item = param [0,""];
_entries = param [1,["DisplayName"],[[]]];

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
_return = if (_single) then {_arr select 0} else {_arr};

_return
