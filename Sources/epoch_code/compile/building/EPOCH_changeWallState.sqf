/*
Author: Aaron Clark - EpochMod.com

Contributors:

Description:
Epoch Change wall state

Licence:
Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

Github:
https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/building/EPOCH_changeWallState.sqf

Example:
[_this,"NWall",1] call EPOCH_changeWallState;

Parameter(s):
_this select 0: OBJECT - Base building object
_this select 1: STRING - Name of animation
_this select 1: SCALAR - state
0: true = add wall
1: false = remove wall

Returns:
NOTHING
*/
//[[[cog import generate_private_arrays ]]]
private ["_config","_craftItem","_craftQty","_currentCount","_hasRecipeItems","_items","_mags","_msg","_numRemoved","_objClass","_recipe","_recipeCount","_recipeItem","_recipeQty"];
//[[[end]]]
params[
	["_object", objNull],
	["_anim", ""],
	["_state", 0]
];
if !(isNull _object) then{
	_msg = "Missing Items";
	// Get config
	_config = 'CfgBaseBuilding' call EPOCH_returnConfig;
	// upgradeBuildingPart
	_objClass = typeOf _object;
	// Add part
	if (_state == 1) then{
		_recipe = getArray(_config >> _objClass >> "upgradeBuildingPart");
		_mags = magazines player;
		_recipeCount = 0;
		_numRemoved = 0;
		_hasRecipeItems = true;
		// Dry Run
		{
			_recipeItem = _x;
			_recipeQty = 1;
			_x params [["_recipeItem",_recipeItem],["_recipeQty",_recipeQty]];
			_recipeCount = _recipeCount + _recipeQty;
			_currentCount = { _x == _recipeItem } count _mags;
			if (_currentCount < _recipeQty) exitWith{
				_hasRecipeItems = false;
				_msg = format["Need %2 %1 Have %3", _recipeItem call EPOCH_itemDisplayName, _recipeCount, _currentCount];
			};
		}forEach _recipe;
		// remove item
		if (_hasRecipeItems) then{
			{
				_recipeItem = _x;
				_recipeQty = 1;
                _x params [["_recipeItem",_recipeItem],["_recipeQty",_recipeQty]];
				if ([_recipeItem, "CfgWeapons"] call EPOCH_fnc_isAny) then{
					_items = items player;
					_currentCount = { _x == _recipeItem } count _items;
					if (_currentCount >= _recipeQty) then{
						for "_i" from 1 to _recipeQty do {
							if (_recipeItem in _items) then{
								player removeItem _recipeItem;
								_numRemoved = _numRemoved + 1;
							};
						};
					};
				} else {
					_mags = magazines player;
					_currentCount = { _x == _recipeItem } count _mags;
					if (_currentCount >= _recipeQty) then{
						for "_i" from 1 to _recipeQty do {
							if (_recipeItem in _mags) then{
								player removeMagazine _recipeItem;
								_numRemoved = _numRemoved + 1;
							};
						};
					};
				};
			}forEach _recipe;
		};
		if (_numRemoved == _recipeCount) then{
			_object animate[_anim, _state, true];
			// push interacted object to queue to save later
			EPOCH_arr_interactedObjs pushBackUnique _object;
			[format["%1 part on %2", "Added", _objClass call EPOCH_itemDisplayName], 5] call Epoch_message;
		} else {
			[_msg, 5] call Epoch_message;
		};
	} else {
		// Remove part
		_recipe = getArray(_config >> _objClass >> "removeBuildingPart");
		_object animate[_anim, _state, true];
		// push interacted object to save queue to save later
		EPOCH_arr_interactedObjs pushBackUnique  _object;
		{
			_craftItem = _x;
			_craftQty = 1;
			if (_x isEqualType[]) then{
				_craftItem = _x select 0;
				_craftQty = _x select 1;
			};
			for "_i" from 1 to _craftQty do {
				_craftItem call EPOCH_fnc_addItemOverflow;
			};
		}forEach _recipe;
		[format["%1 part on %2", "Removed", _objClass call EPOCH_itemDisplayName], 5] call Epoch_message;
	};
};
