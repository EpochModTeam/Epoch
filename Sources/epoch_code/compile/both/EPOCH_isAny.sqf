/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Config compare function

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/both/EPOCH_isAny.sqf

    Example:
    _return = [_item, "CfgVehicles"] call EPOCH_fnc_isAny;

    Parameter(s):
		_this select 0: STRING - Item Class
        _this select 1: STRING - Parent Class

	Returns:
	BOOL
*/
params ["_item","_type"];
(str(configFile >> _type >> _item) != "")
