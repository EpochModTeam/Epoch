private["_posWH", "_item", "_nearbyWH", "_rock", "_player"];

_object = _this select 0;
_index = _this select 1;
_player = _this select 2;

if !([_player, _this select 3] call EPOCH_server_getPToken) exitWith{};

if !(_object isKindOf "All") then {
	if (alive _object) then {

		_posWH = getPosATL _player;
		_posWH set[2, 0];

		// defaults
		_selectedPayout = ["ItemRock", 4];
		// Not Rock
		if (_index >= 0) then {
			_selectedPayout = ["ItemScraps", 2];
			if (_index == 0) then {
				_selectedPayout = ["CinderBlocks", 1];
			};
		} else {
			_lootables = [["PartOre", 2], ["ItemRock", 4]];
			_selectedPayout = _lootables select(floor random(count _lootables));
		};

		_payout = _selectedPayout select 0;
		_payoutQty = _selectedPayout select 1;
		
		_object setdamage ((damage _object) + (1/_payoutQty)) min 1;

		_nearbyWH = nearestObjects[_posWH, ["groundWeaponHolder"], 2];
		if !(_nearbyWH isEqualTo[]) then {
			_posWH = getPosATL(_nearbyWH select 0);
			(_nearbyWH select 0) addMagazineCargoGlobal[_payout, _payoutQty];
		} else {
			_item = createVehicle["groundWeaponHolder", _posWH, [], 0, "CAN_COLLIDE"];
			_item setPosATL _posWH;
			_item addMagazineCargoGlobal[_payout, _payoutQty];
		};
	};
};
true