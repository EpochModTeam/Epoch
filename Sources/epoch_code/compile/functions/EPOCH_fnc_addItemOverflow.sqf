// Epoch add item with overflow
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
