/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Gear Armor factor for passThrough calculation with support for A3 1.54+.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/inventory/EPOCH_factorArmor.sqf

    Example:
    _gearArmor = ([_passThrough,_armor] call EPOCH_factorArmor);

    Parameter(s):
		_this select 0: NUMBER - passThrough
        _this select 1: NUMBER - armor

	Returns:
	NUMBER
*/
params ["_passThrough","_armor"];
((_armor - (_armor*_passThrough))/2 + _armor)
