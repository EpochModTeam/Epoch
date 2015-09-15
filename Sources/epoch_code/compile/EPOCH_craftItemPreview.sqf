disableSerialization;

ctrlShow[1600, false];
ctrlShow[2100, false];
ctrlShow[1000, false];
ctrlShow[41008, true];
ctrlShow[42000, true];


_index = _this select 0;

EPOCH_CraftItemData = "";

_activeDisplay = findDisplay -15;

_data = EPOCH_InteractedItem select 1;
// _craftingConfig = configfile >> "CfgCrafting" >> (_data);
_config = 'CfgCrafting' call EPOCH_returnConfig;
_craftingConfig = _config >> _data;
if (isClass (_craftingConfig)) then {
	_usedIn = getArray (_craftingConfig >> "usedIn");

	_selectedRecipe = _usedIn select _index;

	EPOCH_CraftItemData = _selectedRecipe;

	_craftingConfig = _config >> _selectedRecipe;
	if (isClass (_craftingConfig)) then {
		_recipe = getArray(_craftingConfig >> "recipe");
		_nearby = getArray(_craftingConfig >> "nearby");

		_recipeItems = [1200,1201,1202,1203,1204,1205];
		_recipeStatus = [42200,42201,42202,42203,42204,42205];
		_recipetooltip = [43200,43201,43202,43203,43204,43205];
		_recipeCounts = [41001,41002,41003,41004,41005,41006];

		_recipeResources = [45202,45203,45204,45205,45206,45207];
		_recipeResourcesbtn = [44202,44203,44204,44205,44206,44207];


		{
			ctrlShow[_x, false];
		} forEach _recipeItems;

		{
			ctrlShow[_x, false];
		} forEach _recipeStatus;

		{
			ctrlShow[_x, false];
		} forEach _recipeCounts;
		
		
		
		// check for nearby resources 
		_proceed = true;
		// check nearby
		{
			_needType = _x select 0; // fire. alive,	noclass
			_needClasses = _x select 1; // ["ALL"].		["filename.p3d"]
			_needRange = _x select 2; // 3
			_needCount = _x select 3; // 1
			_needReason = _x select 4; // "Fire", "Water Source" 
			_needImage = _x select 5; // fire, fuel, water, electricity

			_nearObjects = nearestObjects[player, _needClasses, _needRange];

			_nearbyCount = 0;
			switch (_needType) do
			{
				case "fire": {_nearbyCount = {inflamed _x} count _nearObjects; };
				case "alive": {_nearbyCount = {alive _x} count _nearObjects; };
				case "noclass": {
					{
						_needName = _x;
						_nearbyCount = {((str(_x) find _needName) != -1)} count nearestObjects[player, [], _needRange];
						if (_nearbyCount > 0) exitWith{};
					} foreach _needClasses;
				};
			}; 

			(_activeDisplay displayCtrl(_recipeResourcesbtn select _forEachIndex)) ctrlSetTooltip _needReason;

			if (_nearbyCount < _needCount) then {
				_proceed = false;
				// display needed icons
				_icon = format["\x\addons\a3_epoch_code\Data\UI\need_%1_ca.paa", _needImage];
				//diag_log format["%1", _icon];
				ctrlSetText[(_recipeResources select _forEachIndex), _icon];

			} else {
				// display needed icons
				_icon = format["\x\addons\a3_epoch_code\Data\UI\has_%1_ca.paa", _needImage];
				//diag_log format["%1", _icon];
				ctrlSetText[(_recipeResources select _forEachIndex), _icon];
			};

		} forEach _nearby;

		

		_recipeCount = 0;
		_itemCount = 0;
		_mags = magazines player;
		_items = items player;
		{
			_recipeItem = _x;
			_recipeQty = 1;

			if (typeName _x == "ARRAY") then {
				_recipeItem = _x select 0;
				_recipeQty = _x select 1;
			};

			_recipeCount = _recipeCount + _recipeQty;

			_index = _forEachIndex;
			_recipePic = _recipeItem call EPOCH_itemPicture;
			ctrlSetText [(_recipeItems select _index), _recipePic];

			_actualCount = 0;
			if (isClass(configfile >> "cfgweapons" >> _recipeItem)) then {
				_actualCount = { _x == _recipeItem } count _items;
			} else {
				_actualCount = { _x == _recipeItem } count _mags;
			};


			ctrlSetText[(_recipeCounts select _index), format["%1/%2", _actualCount, _recipeQty]];

			ctrlShow[(_recipeItems select _index), true];
			ctrlShow[(_recipeStatus select _index), true];
			ctrlShow[(_recipeCounts select _index), true];
			
			(_activeDisplay displayCtrl (_recipetooltip select _index)) ctrlSetTooltip format["%1",(_recipeItem call EPOCH_itemDisplayName)];

			if (_actualCount >= _recipeQty) then {
				ctrlSetText [(_recipeStatus select _index), ""];
				_itemCount = _itemCount + _recipeQty;
				(_activeDisplay displayCtrl (_recipeCounts select _index)) ctrlSetTextColor[1, 1, 1, 1];
			} else {
				ctrlSetText [(_recipeStatus select _index), "\x\addons\a3_epoch_assets\ui\xicon.paa"];
				(_activeDisplay displayCtrl (_recipeCounts select _index)) ctrlSetTextColor[1, 0, 0, 1];
			};

		} forEach _recipe;

		if (_itemCount == _recipeCount && _proceed) then {
			ctrlShow [1600, true];
			ctrlShow [2100, true];
			ctrlShow [1000, true];
			for "_i" from 0 to 9 do {
				_num = _i + 1;
				_index = lbAdd[2100, str(_num)]; lbSetValue[2100, _index, _num];
			};
			lbSetCurSel[2100, 0];
		};
		//diag_log format["DEBUG: EPOCH_craftItem %1 index: %2",_selectedRecipe,_index];
	};
	//diag_log format["DEBUG: EPOCH_craftItem %1 index: %2",_selectedRecipe,_index];
};

