/*
	Author: DirtySanchez - ported from DonkeyPunch eXpoch http://DonkeyPunch.INFO

    Contributors:
	
	Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/inventory/EPOCH_usedItemRepack.sqf
	
	Description:
	Allows adjustments to mag with least ammo.
	Can be used server and client side as addMagazine is a global command
	
	Local Usage:
	[player,'lighter_epoch',-1] call EPOCH_usedItemRepack;
	
	Global Usage:
	[_playerObj,'lighter_epoch',-1] call EPOCH_usedItemRepack;
*/
private["_msg","_itemMags","_displayName","_itemAmmoType","_mags","_ammoType","_total","_maxAmmo","_wholeMags","_remainder","_index","_usedItemArray"];
params[
	["_player",objNull],
	["_item",""],
	["_chg",0]
];

if(isNull _player) exitWith {diag_log "[EPOCHDebug] EPOCH_usedItemRepack - player isNull"};

if(_item isEqualTo "") exitWith {diag_log "[EPOCHDebug] EPOCH_usedItemRepack - classname is empty string"};

if!(isClass(configFile >> "CfgMagazines" >> _item)) exitWith {diag_log format["[EPOCHDebug] EPOCH_usedItemRepack - Classname does not exist",_item]};

_msg = "";
_itemMags = [];
_displayName = getText(configFile >> "CfgMagazines" >> _item >> "displayName");

//get all mags of same classname and ammo type
_mags = magazinesAmmo _player;
{
	_x params ["_className","_count"];
	if(_className isEqualTo _item)then{
		_itemMags pushBack _x;
	};
}forEach _mags;

// if more than 1 sort them by ammo count
if(count _itemMags > 1)then{
	_itemMags = [_itemMags,[],{_x select 1},"ASCEND"] call BIS_fnc_sortBy;
};

// adjust the item
if!(_chg isEqualTo 0)then{
	_index = ((count _itemMags) - 1);
	_usedItemArray = _itemMags select _index;
	_usedItemArray params ["_mag","_count"];
	_itemMags pushBack [_mag, (_count + _chg)];
	_itemMags = _itemMags - [_usedItemArray];
	_player removeMagazines _mag;
	{
		_player addMagazine _x;
		[format["You have used your %1", _displayName],5,[[0,0,0,0.2],[1,1,1,1]]] call Epoch_message_stack;
	}forEach _itemMags;
};
