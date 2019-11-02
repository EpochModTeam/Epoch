/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors:

	Description:
	DESC-TBA

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/scripts/craftingv2/EPOCH_crafting_craft.sqf
*/

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

	private ["_GiveBackRounds","_TotalroundsIn","_TotalMaxRoundsIn","_roundsCheck","_maxMagrnd","_maxMagRndTmp","_roundsCheckTmp","_magsammosearched","_craftReturn","_needBench","_craftCount","_fnc_UILock","_itemCraftTime","_selection","_craftItem","_item","_itemName","_itemCraftTime","_itemRecipeItems","_itemType","_nearbyReq","_hasNearby","_canCraft","_wH","_nearByHolder","_wHPos","_craftedcount"];
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
	_needBench = {"WorkBench_EPOCH" in (_x select 3 select 1)} count _nearbyReq;
	_craftCount = _craftItem param [15,1];
	_craftReturn = _craftItem param [16,[]];
	
	_BulletCalculateOnCraft = ["CfgEpochClient", "BulletCalculateOnCraft", false] call EPOCH_fnc_returnConfigEntryV2;
	
	_craftedcount = 0;

	for "_c" from 1 to rmx_var_craftQTYOut do {
		false call _fnc_UILock;
		_hasNearby = false call EPOCH_crafting_checkResources;

		if !(_hasNearby) exitWith {};

		_canCraft = [format ["Crafting: %1, %2 seconds",_itemName,_itemCraftTime],_itemCraftTime] call  EPOCH_crafting_progress;

		if !(_canCraft && rmx_var_craftingLOOPS) exitWith {};

		_GiveBackRounds = 0;
		_TotalroundsIn = 0;
		_TotalMaxRoundsIn = 0;
		_roundsCheck = false;
		_maxMagrnd = (getnumber (configfile >> "cfgMagazines" >> _item >> "count")) max 1;
		{
			if !(_x isEqualType []) then {_x = [_x,1]};
			_x params ["_recipetype","_recipetypecount"];
			_recipetype = tolower _recipetype;
			_maxMagRndTmp = getnumber (configfile >> "cfgMagazines" >> _recipetype >> "count");
			_roundsCheckTmp = ([_recipetype,"cfgMagazines"] call Epoch_fnc_isAny && [_item,"cfgMagazines"] call Epoch_fnc_isAny && _maxMagrnd > 1 && _maxMagRndTmp > 1 && _BulletCalculateOnCraft);
			for "_r" from 1 to _recipetypecount do {
				if (_roundsCheckTmp) then {
					_roundsCheck = true;
					_magsammosearched = [];
					{
						_x params ["_type","_rounds"];
						if ((tolower _type) isequalto _recipetype) then {
							_magsammosearched pushback _x;
						};
					} foreach (magazinesammo player);
					_TotalMaxRoundsIn = _TotalMaxRoundsIn + _maxMagRndTmp;
					_TotalroundsIn = _TotalroundsIn + ((_magsammosearched deleteat 0) select 1);
					player removemagazines _recipetype;
					{
						_x call EPOCH_fnc_addMagazineOverflow;
					} foreach _magsammosearched;
				}
				else {
					player removeItem _recipetype; //removes any type of item, but only if not in special slots
				};
			};
		} forEach _itemRecipeItems;
		
		if (_roundsCheck) then {
			_GiveBackRounds = (_maxMagrnd * (_TotalroundsIn / _TotalMaxRoundsIn));
		};

		_nearByBench = nearestObjects [player,["WorkBench_EPOCH"],3];

		if (!(_nearByBench isEqualTo []) && (_needBench > 0)) then { //adds item on top of bench if bench was required
			if (_roundsCheck) then {
				(_nearByBench select 0) addMagazineAmmoCargo [_item, _craftCount, ((ceil (_GiveBackRounds / _craftCount)) min _maxMagrnd) max 1];
			}
			else {
				(_nearByBench select 0) addItemCargoGlobal [_item,_craftCount];
			};
		}
		else {
			if (_roundsCheck) then {
				for "_i" from 1 to _craftCount do {
					[_item,((ceil (_GiveBackRounds / _craftCount)) min _maxMagrnd) max 1] call EPOCH_fnc_addMagazineOverflow;
				};
			}
			else {
				[_item,_craftCount] call EPOCH_fnc_addItemOverflow;
			};
		};

		// return items
		{
			_x call EPOCH_fnc_addItemOverflow;
		} forEach _craftReturn;

		call EPOCH_crafting_LB_click;
		_craftedcount = _craftedcount + 1;
	};
	if (_craftedcount > 0) then {
		["CraftedItems",_craftedcount,true] call EPOCH_client_updatePlayerStat;
	};
	call EPOCH_crafting_LB_defaults;
	true call _fnc_UILock;
	rmx_var_craftInProgress = false;
};
true
