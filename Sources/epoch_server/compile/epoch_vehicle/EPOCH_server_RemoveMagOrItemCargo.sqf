/*
	Author: He-Man - Ignatz-Gaming

    Contributors:

	Description:
	Removes Items or Magazines from any Cargo

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
	https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_vehicle/Epoch_Server_RemoveMagOrItemCargo.sqf
	
    Example:
    _done = [_vehicle,[_itemtype,_itemcount,_rounds]] call Epoch_Server_RemoveMagOrItemCargo;

    Parameter(s):
		_this select 0: OBJ - Storage or Vehicle
        _this select 1: STRING - ItemType to remove
        _this select 2: SCALAR - ItemQuantity to remove (optional)
        _this select 2: SCALAR - Magazine Rounds to find and remove (optional)
	Returns:
	BOOL - If the Magazine(s) / Item(s) are successfully removed then "true", else "false"
*/
private ["_return","_removed","_items","_objType","_arr","_size"];
params ["_cargo","_class",["_count",1],["_bulletfind",0]];
_return = false;
_removed = 0;
_items = [_cargo,false] call Epoch_Server_CargoSave;
_objType = -1;
if ([_class,"cfgMagazines"] call Epoch_fnc_isAny) then {
	_objType = 1;
}
else {
	if ([_class, "CfgWeapons"] call EPOCH_fnc_isAny) then {
		_objType = 3;
	};
};
if (_objType > -1) then {
	_arr = _items select _objType;
	_arr params ["_objTypes","_objQty"];
	{
		_size = _objQty select _forEachIndex;
		switch _objType do {
			case 1: {
				if ((_x isEqualTo _class) && ((_size isEqualTo _bulletfind) || _bulletfind == 0)) then {
					_objQty set [_foreachindex,0];
					_removed = _removed + 1;
				};
			};
			case 3: {
				if (_x isEqualTo _class && _size >= _count) then {
					_objQty set [_foreachindex,_size - _count];
					_removed = _removed + _count;
				};
			};
		};
		if (_removed >= _count) exitwith {_return = true;};
	} forEach _objTypes;
};
if (_return) then {
	clearWeaponCargoGlobal _cargo;
	clearMagazineCargoGlobal _cargo;
	clearBackpackCargoGlobal _cargo;
	clearItemCargoGlobal _cargo;
	[_cargo,_items] call Epoch_Server_CargoFill;
};

_return
