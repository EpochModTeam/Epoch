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
		_this: STRING - Item Class

	Returns:
	NOTHING
*/
private ["_wHPos","_wH","_nearByHolder","_item"];
_item = _this;
if (player canAdd _item) then {
  player addItem _item;
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
  _wh addItemCargoGlobal [_item,1];
};
