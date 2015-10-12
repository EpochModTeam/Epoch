//dialog closed
if (!rmx_var_craftingENABLED || !rmx_var_craftingLOOPS) exitWith {rmx_var_craftInProgress = false;};

//cancel craft button
if (rmx_var_craftInProgress) exitWith {rmx_var_craftInProgress = false;};

//close button
if (rmx_var_craftQTYOut isEqualTo 0) exitWith {closeDialog 0;};

//exit early if missing nearby
if !(false call EPOCH_crafting_checkResources) exitWith {};

//craft button
[] spawn {

	private ["_fnc_UILock","_itemCraftTime","_selection","_craftItem","_item","_itemName","_itemCraftTime","_itemRecipeItems","_itemType","_nearbyReq","_hasNearby","_canCraft","_wH","_nearByHolder","_wHPos"];
	disableSerialization;
	
	_fnc_UILock = {
		private "_lock";
		_lock = param [0,true];
		(rmx_var_crafting_ctrl_main select 0) ctrlEnable _lock;
		(rmx_var_crafting_ctrl_main select 1) ctrlEnable _lock;
		(rmx_var_crafting_ctrl_Interact select 1) ctrlEnable _lock;
		(rmx_var_crafting_ctrl_Interact select 4) ctrlEnable _lock;
	};
	
	rmx_var_craftInProgress = true;
	
	_selection = lbCurSel (rmx_var_crafting_ctrl_main select 0);
	_craftItem = rmx_var_crafting_SearchConfigData select _selection;
	_item = _craftItem select 0;
	_itemName = _craftItem select 1;
	_itemCraftTime = _craftItem select 6;
	_itemRecipeItems = _craftItem select 7;
	_itemType = _craftItem select 13;
	_nearbyReq = _craftItem select 8;
	_needBench = {"WorkBench_EPOCH" in (_x select 3 select 1)} count (_craftItem select 8);

	for "_c" from 1 to rmx_var_craftQTYOut do {
		false call _fnc_UILock;
		_hasNearby = false call EPOCH_crafting_checkResources;
		
		if !(_hasNearby) exitWith {};
		
		_canCraft = [format ["Crafting: %1, %2 seconds",_itemName,_itemCraftTime],_itemCraftTime] call  EPOCH_crafting_progress;
	
		if !(_canCraft && rmx_var_craftingLOOPS) exitWith {};

		{
			if !(typeName _x isEqualTo typeName []) then {_x = [_x,1]};
			for "_r" from 1 to (_x select 1) do {
				player removeItem (_x select 0); //removes any type of item, but only if not in special slots
			};
		} forEach _itemRecipeItems;
		
		_nearByBench = nearestObjects [position player,["WorkBench_EPOCH"],3];
		
		if (!(_nearByBench isEqualTo []) && (_needBench > 0)) then { //adds item on top of bench if bench was required
		
			(_nearByBench select 0) addItemCargoGlobal [_item,1];
			
		} else {
			if (player canAdd _item) then { //Puts in a weaponholder nearby if can't add to inventory
			
				player addItem _item; //adds any type of item, but does not assign

			} else {
			
				_wH = objNull;
				_nearByHolder = nearestObjects [position player,["groundWeaponHolder"],3]; //TODO: adjust best range to reuse existing holders
				
				if (_nearByHolder isEqualTo []) then {
				
					_wHPos = player modelToWorld [0,1,0];
					
					if (surfaceIsWater _wHPos) then { //should work anywhere, even on water
					
						_wHPos = ASLToATL _wHPos;
						
					};
					
					_wH = createVehicle ["groundWeaponHolder",_wHPos, [], 0, "CAN_COLLIDE"];

				} else {
				
					_wH = _nearByHolder select 0;
				};
				
				_wh addItemCargoGlobal [_item,1];
			};
		};
		call EPOCH_crafting_LB_click;
	};
	call EPOCH_crafting_LB_defaults;
	true call _fnc_UILock;
	rmx_var_craftInProgress = false;
};
true
