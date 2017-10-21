/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors:

	Description: Equips or un-equips item (if equipped) instantly. Item has to exist in the inventory.
				to switch weapons slowly use below in your code:
				player playAction "reloadMagazine";

				_item - className
				_drop - drop on ground if inventory full, weapons will be stripped off attachments
						weapons stripped because attachments can only be added while weapon is equipped.
				_forceEquip - disables un-equip and forces new item to be equipped at all times

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/inventory/EPOCH_equip.sqf

	Usage:
	[_item, false] call epoch_equip; //don't drop item if inventory full. Does not equip requested item if another item already equipped, instead un-equips existing one.
	[_item, true,true] call epoch_equip; //drops item if not enough space. Removes existing weapon and equips new one.

	RETURNS:
				0 - fail, item not provided
				1 - success
				2 - success, but item dropped on ground.
				3 - item not found
				4 - not enough space
				5 - accessory not compatible
*/
private ["_item","_drop","_forceEquip","_return","_loadout","_slot","_uniform","_vest","_bpack","_uniformItems","_vestItems","_bPackItems","_itemInInventory",
"_fnc_dropItem","_fnc_findItemInContainers","_fnc_moveWeaponFromContainer","_fnc_MoveWeaponToContainer","_fnc_canMoveToContainer","_fnc_dropEquipWeapon","_fnc_dropAssign",
"_fnc_MoveShellToContainer","_fnc_moveShellFromContainer","_fnc_dropEquipShells","_fnc_findAccessorySlot","_fnc_dropEquipAccessories"];
params [["_item","",[""]],["_drop",false,[false]],["_forceEquip",false,[false]]];

_return = 0;
if (_item == "") exitWith {_return};
_slot = _item call epoch_itemTypeSlot;
_loadout = getUnitLoadout player;
_uniform = _loadout param [3,[]];
_vest = _loadout param [4,[]];
_bpack = _loadout param [5,[]];
_uniformItems = _uniform param [1,[]];
_vestItems = _vest param [1,[]];
_bPackItems = _bPack param [1,[]];

_itemInInventory = _item in ((magazines player) + (items player));

_fnc_dropItem = {
	private ["_item","_nearByHolder","_wH","_wHPos"];
	params [["_item","",[""]],["_count",1]];
	for "_i" from 1 to _count do
	{
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
	};
};

_fnc_findItemInContainers = {
	private ["_item","_container","_index","_found","_currItem"];
	params ["_item"];

	_container = 0;
	_index = 0;
	_found = false;
	{
		_container = _forEachIndex;
		if (!isnil "_x") then {
			{
				_index = _forEachIndex;
				_currItem = _x select 0;
				if (_currItem isEqualType "") then { //if item
					if (_currItem isEqualTo _item) exitWith {_found = true};
				} else { //if weapon
					if ((_currItem select 0) isEqualTo _item) exitWith {_found = true};
				};
				if _found exitWith {};
			} forEach _x;
		};
		if _found exitWith {};
	} forEach [_uniformItems,_vestItems,_bPackItems];

	[_container,_index,_found]
};

_fnc_moveWeaponFromContainer = {
	private ["_idx","_container","_sIdx","_dIdx"]; //_dIdx can only be 0, 1 and 2
	params ["_idx","_dIdx"];
	_idx params ["_container","_sIdx"];

	//copy old entry
	_temp = ((_loadout select (_container + 3)) select 1) select _sIdx select 0;
	//delete old entry
	((_loadout select (_container + 3)) select 1) deleteAt _sIdx;
	//add new entry
	_loadout set [_dIdx,_temp];
	//save changes
	player setUnitLoadout _loadout;
};

_fnc_MoveWeaponToContainer = {
	private ["_container","_sIdx"]; //_sIdx can only be 0, 1 and 2
	params ["_container","_sIdx"];

	/*
	//Delete this block if no issues.
	//Commented out because increasing index alone is not enough due to unique attachement placements or ammo size
	_exists = _item call _fnc_findItemInContainers;
	_exists params ["_container","_idx","_found"];

	if _found then {
		_cnt = ((_loadout select (_container + 3)) select 1) select _idx select 1;
		((_loadout select (_container + 3)) select 1) select _idx set [1,_cnt + 1];
	} else {
		((_loadout select (_container + 3)) select 1) append [[_loadout select _sIdx,1]];
	};
	*/

	((_loadout select (_container + 3)) select 1) append [[_loadout select _sIdx,1]]; //cut out from above comment, looks like appending alone works great
	_loadout set [_sIdx,[]];

	player setUnitLoadout _loadout;
};

_fnc_canMoveToContainer = {
	private "_item";
	params ["_item"];
	if (player canAddItemToUniform _item) exitWith {0};
	if (player canAddItemToVest _item) exitWith {1};
	if (player canAddItemToBackpack _item) exitWith {2};
	4
};

_fnc_dropEquipWeapon = {
	private ["_equipped","_slot"];
	params ["_equipped","_slot"];

	if (!_itemInInventory && (_item != _equipped)) exitWith {_return = 3}; //Item not found

	if (_equipped != "") then { //something equipped already
		if (player canAdd _equipped) then { //can we move it?
			_container = _equipped call _fnc_canMoveToContainer;

			if (_container != 4) then {
				[_container,_slot] call _fnc_MoveWeaponToContainer;
				_return = 1;
			} else {
				_return = 4;
			};
		} else { //drop it and strip from attachments?
			if !(_drop) exitWith {_return = 4;}; //drop not allowed
			/* //Delete this block if no issues with dropping on ground
			{//Drop equipped items first
				_x call _fnc_dropItem;
				player removePrimaryWeaponItem _x;
			}forEach primaryWeaponItems player;
			{
				_x call _fnc_dropItem;
			}forEach primaryWeaponMagazine player;
			*/
			_equipped call _fnc_dropItem;
			player removeWeaponGlobal _equipped;
			_return = 2; //success, but dropped
		};
		if (_forceEquip && _return != 4) then {//Equip new weapon after old one removed
			_idx = _item call _fnc_findItemInContainers;
			[_idx,_slot] call _fnc_moveWeaponFromContainer;
		};
	} else {
		//Equip weapon
		_idx = _item call _fnc_findItemInContainers;
		[_idx,_slot] call _fnc_moveWeaponFromContainer;
		_return = 1; //success
	};
};

_fnc_dropAssign= {
	private ["_equipped"];
	params ["_equipped"];

	if (!_itemInInventory && (_item != _equipped)) exitWith {_return = 3};

	if (_equipped != "") then {
		if (player canAdd _equipped) then {
			_container = _equipped call _fnc_canMoveToContainer;

			if (_container != 4) then {
				player unassignItem _equipped;
				_return = 1;
			} else {
				_return = 4;
			};
		} else {
			if !(_drop) exitWith {_return = 4;};
			_equipped call _fnc_dropItem;
			player removeItem _equipped;
			_return = 2;
		};
		if (_forceEquip && _return != 4) then {
			player assignItem _item;
		};
	} else {
		player assignItem _item;
		_return = 1;
	};
};
_fnc_MoveShellToContainer = {
	private ["_container"];
	params ["_container"];

	_temp = _loadout select 0 select 5;
	_temp2 = [(_temp select 0), 1, (_temp select 1)];
	if ((_temp select 1) > 0) then { //only move if ammo not empty, delete otherwise
		((_loadout select (_container + 3)) select 1) append [_temp2]; //cut out from above comment, looks like appending alone works great
	};
	(_loadout select 0) set [5,[]];
	player setUnitLoadout _loadout;
};

_fnc_moveShellFromContainer = {
	private ["_idx","_container","_sIdx"]; //_dIdx can only be 0, 1 and 2
	params ["_idx"];
	_idx params ["_container","_sIdx","_found"];

	if (_found) then {
		_temp = ((_loadout select (_container + 3)) select 1) select _sIdx;

		if ((_temp select 1) > 1) then {
			_cnt = (((_loadout select (_container + 3)) select 1) select _sIdx) select 1;
			(((_loadout select (_container + 3)) select 1) select _sIdx) set [1,_cnt - 1];
		} else {
			((_loadout select (_container + 3)) select 1) deleteAt _sIdx;
		};
		(_loadout select 0) set [5,[_temp select 0,_temp select 2]];
		player setUnitLoadout _loadout;
	};
};

_fnc_dropEquipShells = {
	private ["_equipped"];
	params ["_equipped"];

	if (!_itemInInventory && (_item != _equipped)) exitWith {_return = 3};

	if (_equipped != "") then {
		if (player canAdd _equipped) then {
			_container = _equipped call _fnc_canMoveToContainer;

			if (_container != 4) then {
				[_container] call _fnc_MoveShellToContainer;
				_return = 1;
			} else {
				_return = 4;
			};
		} else {
			if !(_drop) exitWith {_return = 4;};
			_equipped call _fnc_dropItem;
			(_loadout select 0) set [5,[]];
			player setUnitLoadout _loadout;
			_return = 2;
		};
		if (_forceEquip && _return != 4) then {
			_idx = _item call _fnc_findItemInContainers;
			[_idx,_slot] call _fnc_moveShellFromContainer;
			player playAction "reloadMagazine";
		};
	} else {
		_idx = _item call _fnc_findItemInContainers;
		[_idx,_slot] call _fnc_moveShellFromContainer;
		player playAction "reloadMagazine";
		_return = 1;
	};
	_muzzle = (getArray (configFile >> "CfgWeapons" >> (primaryWeapon player) >> "muzzles"));
	player selectWeapon (_muzzle select 1);
};
_fnc_findAccessorySlot = {
		_item = toLower _item;

		private ["_found","_slot","_accessory","_compatibleMuzzles","_compatibleCows","_compatiblePointers","_compatibleBipods"];
		_slot = 0;
		_accessory = 0;
		_found = false;
		{
			_slot = _foreachIndex;
			_compatibleMuzzles = getArray(configFile >> "CfgWeapons" >> _x >> "WeaponSlotsInfo" >> "MuzzleSlot" >> "compatibleItems");
			_compatibleCows= getArray(configFile >> "CfgWeapons" >> _x >> "WeaponSlotsInfo" >> "CowsSlot" >> "compatibleItems");
			_compatiblePointers = getArray(configFile >> "CfgWeapons" >> _x >> "WeaponSlotsInfo" >> "PointerSlot" >> "compatibleItems");
			_compatibleBipods = getArray(configFile >> "CfgWeapons" >> _x >> "WeaponSlotsInfo" >> "UnderBarrelSlot" >> "compatibleItems");

			for "_i" from 0 to (count _compatibleMuzzles) do {
				_compatibleMuzzles set [_i,toLower (_compatibleMuzzles select _i)];
			};
			for "_i" from 0 to (count _compatibleCows) do {
				_compatibleCows set [_i,toLower (_compatibleCows select _i)];
			};
			for "_i" from 0 to (count _compatiblePointers) do {
				_compatiblePointers set [_i,toLower (_compatiblePointers select _i)];
			};
			for "_i" from 0 to (count _compatibleBipods) do {
				_compatibleBipods set [_i,toLower (_compatibleBipods select _i)];
			};

			if (_item in _compatibleMuzzles) exitWith {_found = true; _accessory = 1};
			if (_item in _compatibleCows) exitWith {_found = true; _accessory = 3};
			if (_item in _compatiblePointers) exitWith {_found = true; _accessory = 2};
			if (_item in _compatibleBipods) exitWith {_found = true; _accessory = 6};
		} forEach [(primaryWeapon player),(secondaryWeapon player),(handgunWeapon player)];

		[_found,_slot,_accessory]
};

_fnc_dropEquipAccessories = {

	_properties = call _fnc_findAccessorySlot;
	_properties params ["_found","_slot","_accessory"];

	if !_found exitWith {_return = 5};

	_itemsPlayer = (primaryWeaponItems player + secondaryWeaponItems player + handgunItems player);
	for "_i" from 0 to (count _itemsPlayer) do {
		_itemsPlayer set [_i,toLower (_itemsPlayer select _i)];
	};
	_item = toLower _item;
	_itemEquipped = _item in _itemsPlayer;
	_equipped = (_loadout select _slot) select _accessory;

	if (!_itemInInventory && !_itemEquipped) exitWith {_return = 3};
	if (_equipped != "") then {
		_equipped = (_loadout select _slot) select _accessory;
		if (player canAdd _equipped) then {
			(_loadout select _slot) set [_accessory,""];
			player setUnitLoadout _loadout;
			player addItem _equipped;
			_return = 1;
		} else {
			if !(_drop) exitWith {_return = 4;};
			_equipped call _fnc_dropItem;
			(_loadout select _slot) set [_accessory,""];
			player setUnitLoadout _loadout;
			_return = 1;
		};
		if (((toLower _equipped) != (toLower _item)) || _forceEquip && _return != 4) then {
			(_loadout select _slot) set [_accessory,_item];
			player setUnitLoadout _loadout;
			player addItem _equipped;
			player removeItem _item;
		};
	} else {
		(_loadout select _slot) set [_accessory,_item];
		player setUnitLoadout _loadout;
		player removeItem _item;
		_return = 1;
	};

	player selectWeapon ((_loadout select _slot) select 0);
	if !(["CfgEpochClient", "Fav_FastWeaponSwitching", false] call EPOCH_fnc_returnConfigEntryV2) then {
		player playAction "reloadMagazine";
	};
	_return
	/*
	 _slot = primary 0, second 1, hand 2
	 _accessory = silencer 1, laser 2, optics 3
	*/
};
/*


*/
//Main
switch _slot do {
	case 3:
	{
		[(primaryWeapon player),0] call _fnc_dropEquipWeapon;
	};
	case 4:
	{
		[(secondaryWeapon player),1] call _fnc_dropEquipWeapon;
	};
	case 5:
	{
		[(handgunWeapon player),2] call _fnc_dropEquipWeapon;
	};
	case 6: //accesories
	{
		_item call _fnc_dropEquipAccessories;
	};
	case 7: //toolbelt
	{
		if (_item in (assignedItems player)) then {
			switch _item do {
				case "ItemGPS":
				{
					//can't find a way to display it in A3
					"Use [Right Ctrl] + M to toggle GPS" call epoch_message;
				};
				case "ItemMap":
				{
					openMap true;
				};
				case "ItemCompass":
				{
					//can't find a way to display it in A3
					"Use [K] to toggle Compass" call epoch_message;
				};
				case "ItemWatch":
				{
					//can't find a way to display it in A3
					"Use [O] to toggle watch" call epoch_message;
				};
				case "ItemGeigerCounter_EPOCH":
				{
					call epoch_geiger_show_hide;
				};
				case default
				{
					//do stuff with radios here
					if (_item in ["EpochRadio0","EpochRadio1","EpochRadio2","EpochRadio3","EpochRadio4","EpochRadio5","EpochRadio6","EpochRadio7","EpochRadio8","EpochRadio9"]) then {_item call EPOCH_custom_radioActions};
				};

			};
		} else {
			_item call _fnc_dropAssign;
		};
	};
	case 8: //headgear
	{
		(headgear player) call _fnc_dropAssign;
	};
	case 9: //hmd
	{
		(hmd player) call _fnc_dropAssign;
	};
	case 10: //bino
	{
		[(binocular player),8] call _fnc_dropEquipWeapon;
	};
	case 11: //goggles
	{
		(hmd player) call _fnc_dropAssign;
	};
	case 12: //mines
	{
		private ["_allMuzzles","_muzzle","_found","_mags"];
			if (_itemInInventory) then {
			_allMuzzles = getArray (configFile >> "CfgWeapons" >> "Put" >> "Muzzles");

			_muzzle = "";
			_found = false;
			{
				_mags = getArray (configFile >> "CfgWeapons" >> "Put" >> _x >> "magazines");
				_muzzle = _x;
				{
					if (_x isEqualTo _item) exitWith {_found = true};
				} forEach _mags;
				if (_found) exitWith {};
			} forEach _allMuzzles;

			player playActionNow "PutDown";
			player selectWeapon _muzzle;
			player fire [_muzzle, _muzzle, _item];
			player setWeaponReloadingTime [player, _muzzle, 0];
		};
	};
	case 16: //Grenade launcher shells.
	{
		_equipped = (primaryWeaponMagazine player) param [1,""];
		_equipped call _fnc_dropEquipShells;
	};
};

_return
