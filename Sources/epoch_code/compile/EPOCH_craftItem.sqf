_craftItem = EPOCH_CraftItemData;
_abort = false;
_msg = "";
_craftedItemCount = 0;

// _craftingConfig = configfile >> "CfgCrafting" >> _craftItem;
_config = 'CfgCrafting' call EPOCH_returnConfig;
_craftingConfig = _config >> _craftItem;
if (isClass (_craftingConfig)) then {
	_recipe = [] + getArray(_craftingConfig >> "recipe");
	_nearby = [] + getArray(_craftingConfig >> "nearby");

	//diag_log format["DEBUG craftitem: _nearby %1", _nearby];

	_proceed = true;
	// check nearby
	{
		_needType = _x select 0; // fire. alive,	noclass
		_needClasses = _x select 1; // ["ALL"].		["filename.p3d"]
		_needRange = _x select 2; // 3
		_needCount = _x select 3; // 1
		_needReason = _x select 4; // "Fire", "Water Source"

		_nearObjects = nearestObjects[player, _needClasses, _needRange];

		_nearbyCount = 0;
		switch (_needType) do
		{
			case "fire": {_nearbyCount = {inflamed _x} count _nearObjects; };
			case "alive": {_nearbyCount = {alive _x} count _nearObjects; };
			case "noclass":  {
				{
					_needName = _x;
					_nearbyCount = {((str(_x) find _needName) != -1)} count nearestObjects[player, [], _needRange];

					if (_nearbyCount > 0) exitWith{};
				} foreach _needClasses;
			};
		}; 
		if (_nearbyCount < _needCount)exitWith{
			_proceed = false;
			_msg = format["Need %1", _needReason];
		};
	} forEach _nearby;

	if (_proceed) then {

		_countIndex = lbCurSel 2100;
		_craftCount = lbValue[2100, _countIndex];

		//diag_log format["CRAFT COUNT: index %1 count %2", _countIndex, _craftCount];

		closeDialog 0;

		for "_r" from 1 to _craftCount do {

			if (player canAdd _craftItem) then {
				_recipeCount = 0;
				_numRemoved = 0;
				{
					_recipeItem = _x;
					_recipeQty = 1;

					if (typeName _x == "ARRAY") then {
						_recipeItem = _x select 0;
						_recipeQty = _x select 1;
					};
					_recipeCount = _recipeCount + _recipeQty;

					// TODO dry run before removing anything
					if ([_recipeItem, "CfgWeapons"] call EPOCH_fnc_isAny) then {
						_items = items player;
						_currentCount = { _x == _recipeItem } count _items;
						if (_currentCount >= _recipeQty) then {
							for "_i" from 1 to _recipeQty do {
								if (_recipeItem in _items) then {
									player removeItem _recipeItem;
									_numRemoved = _numRemoved + 1;
								};
							};
						};
					}
					else {
						_mags = magazines player;
						_currentCount = { _x == _recipeItem } count _mags;
						if (_currentCount >= _recipeQty) then {
							for "_i" from 1 to _recipeQty do {
								if (_recipeItem in _mags) then {
									player removeMagazine _recipeItem;
									_numRemoved = _numRemoved + 1;
								};
							};
						};
					};
				} forEach _recipe;

				if (_numRemoved == _recipeCount) then {
					if (player canAdd _craftItem) then {
						if ([_craftItem, "CfgWeapons"] call EPOCH_fnc_isAny) then {
							player addItem _craftItem;
						}
						else {
							player addMagazine _craftItem;
						};
						_craftedItemCount = _craftedItemCount + 1;
					}
					else {
						_abort = true;
						_msg = "Not enough space";
					};
				} else {
					_abort = true;
					_msg = "Incorrect item count";
				};
			} else {
				_abort = true;
				_msg = "Not enough space";
			};
			if (_abort) exitWith{};
		};
	};

	if (_craftedItemCount > 0) then {
		_dt = [format["<t size='0.8' shadow='0' color='#99ffffff'>Crafted %1 %2</t>",_craftedItemCount,_craftItem call EPOCH_itemDisplayName], 0, 1, 5, 2, 0, 1] spawn bis_fnc_dynamictext;
	} else {
		_dt = [format["<t size='0.8' shadow='0' color='#99ffffff'>%1</t>", _msg], 0, 1, 5, 2, 0, 1] spawn bis_fnc_dynamictext;
	};
};