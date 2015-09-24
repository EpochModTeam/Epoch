private["_posWH", "_item", "_nearbyWH", "_payout", "_object", "_type", "_player"];
_player = _this select 2;
if !([_player, _this select 3] call EPOCH_server_getPToken) exitWith{};

_object = _this select 0;
if (isNull _object) exitWith{};
if (_player distance2D (getposATL _object) > 6) exitWith{};

if !(_object isKindOf "All") then {
	if (alive _object) then {
		_posWH = getPosATL _object;
		_posWH set[2, 0];
		if (damage _object > 0.7) then {
			_object setdamage 1;
			_type = _this select 1;
			
			_lootType = "Tree";
			if (_type == 1) then {
				_lootType = "Bush";
			};
			
			_nearbyWH = nearestObjects[_posWH, ["groundWeaponHolder"], 2];
			if !(_nearbyWH isEqualTo[]) then {
				[(_nearbyWH select 0), _lootType] call EPOCH_serverLootObject;
			} else {
				_item = createVehicle["groundWeaponHolder", _posWH, [], 0, "CAN_COLLIDE"];
				_item setPosATL _posWH;
				[_item, _lootType] call EPOCH_serverLootObject;
			};
		} else {
			_object setdamage((damage _object) + 0.25) min 1;
		};
	};
};
true
