/*
	Author: Aaron Clark - EpochMod.com

    Contributors: Raimonds Virtoss

	Description:
	Epoch add item with overflow

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/functions/EPOCH_fnc_addItemOverflow.sqf

    Example:
    _fish call EPOCH_fnc_addItemOverflow;

    Parameter(s):
		_this select 0: STRING - Item Class
        _this select 1: NUMBER - (Optional) Ammo count

	Returns:
	BOOL 	True: item was dropped nearby
			False: item was added to inventory
*/
//[[[cog import generate_private_arrays ]]]
private ["_dropped","_nearByHolder","_wH","_wHPos"];
//[[[end]]]
params [["_item","",[""]],["_count",1]];
_dropped = false;
for "_i" from 1 to _count do
{
    if (player canAdd _item) then {
        player addItem _item;
    } else {
        _wH = objNull;
        if (isNil "_nearByHolder") then {
            _nearByHolder = nearestObjects [player,["groundWeaponHolder"],3];
        };
        if (_nearByHolder isEqualTo []) then {
            _wHPos = player modelToWorld [0,1,0];
            if (surfaceIsWater _wHPos) then {
                _wHPos = ASLToATL _wHPos;
            };
            _wH = createVehicle ["groundWeaponHolder",_wHPos, [], 0, "CAN_COLLIDE"];
        } else {
            _wH = _nearByHolder select 0;
        };
        if !(isNull _wh) then {
            _wh addItemCargoGlobal [_item,1];
        };
		_dropped = true;
    };
};
_dropped
