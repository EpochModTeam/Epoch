/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Unisex check for vests, gives swing ammo and performs radio changed check

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_code/compile/both/EPOCH_isAny.sqf

    Example:
    _return = [_item, "CfgVehicles"] call EPOCH_fnc_isAny;

    Parameter(s):
		_this select 0: STRING - Parent Class
        _this select 0: STRING - Child Class

	Returns:
	BOOL
*/
private ["_item","_return"];
_item = _this select 0;
_type = _this select 1;
_return = str(configFile >> _type >> _item) != "";
_return
