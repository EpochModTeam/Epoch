/*
	Author: Aaron Clark - EpochMod.com

    Contributors: DirtySanchez

	Description:
	Epoch add magazine with overflow toggle

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/functions/EPOCH_fnc_addMagazineOverflow.sqf

    Example:
    [_mag,_magAmmo,true] call EPOCH_fnc_addMagazineOverflow;

    Parameter(s):
		_this select 0: STRING - Magazine Class
        _this select 1: NUMBER - (Optional) Ammo count
		_this select 2: BOOLEAN - (Optional) drop to groundWeaponHolder

	Returns:
	NUMBER 	1: magazine was added to inventory
			2: not enough room in inventory 
			3: magazine was dropped nearby
			0: failed
*/
//[[[cog import generate_private_arrays ]]]
private ["_return","_nearByHolder","_wH","_wHPos"];
//[[[end]]]
params [["_item","",[""]],["_count",1],["_canDrop",true]];
_return = 0;
if (player canAdd _item) then {
	player addMagazine [_item,_count];
	_return = 1;
} else {
	_return = 3;
	if(_canDrop)then{
        _wH = objNull;
		if (player != vehicle player && vehicle player canAdd _item) then {
			_return = 4;
			_wh = vehicle player;
		}
		else {
			_return = 2;
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
		};
        if !(isNull _wh) then {
            //_wh addItemCargoGlobal [_item,1];
			_wh addMagazineAmmoCargo [_item, 1, _count];
        };
    };
};
_return
