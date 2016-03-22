/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Epoch add item with overflow

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_code/compile/functions/EPOCH_fnc_addItemOverflow.sqf

    Example:
    _fish call EPOCH_fnc_addItemOverflow;

    Parameter(s):
		_this select 0: STRING - Item Class
        _this select 1: NUMBER - (Optional) Ammo count

	Returns:
	BOOL
*/
private ["_wHPos","_wH","_nearByHolder"];
params [["_item","",[""]],["_count",0]];

if (player canAdd _item) then {
    if (_count >= 1) then {
        player addMagazine [_item, _count];
    } else {
        player addItem _item;
    };
} else {
    _wH = objNull;
    _nearByHolder = nearestObjects [position player,["groundWeaponHolder"],3];
    if (_nearByHolder isEqualTo []) then {
        _wHPos = player modelToWorld [0,1,0];
        if (surfaceIsWater _wHPos) then {
            _wHPos = ASLToATL _wHPos;
        };
        _wH = createVehicle ["groundWeaponHolder",_wHPos, [], 0, "CAN_COLLIDE"];
    } else {
        _wH = _nearByHolder select 0;
    };

    if (_count >= 1) then {
        _wh addMagazineAmmoCargo[_item, 1, _count];
    } else {
        _wh addItemCargoGlobal [_item,1];
    };
};
true
