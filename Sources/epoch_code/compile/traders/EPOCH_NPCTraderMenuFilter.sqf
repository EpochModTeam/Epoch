/*
	Author: Aaron Clark - EpochMod.com

    Contributors: He-Man

	Description:
	NPC trade filter code

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/traders/EPOCH_NPCTraderMenuFilter.sqf

    Example:
    onLBSelChanged = "_this call EPOCH_NPCTraderMenuFilter";

    Parameter(s):
		_this select 0: CONTROL
        _this select 1: NUMBER - Index ID

	Returns:
	NOTHING
*/
disableSerialization;
//[[[cog import generate_private_arrays ]]]
private ["_FilterArray","_MainCategorie","_MainCategoriearray","_SubCategorieItems","_aiItems","_config","_control","_display","_id","_isPlayerFilter","_item","_itemCount","_itemOfferCount","_items","_name","_offerArray","_picture","_playeritems","_qty","_qtys","_sizeOut","_slot","_sortarray","_subcategories","_type","_vehicles"];
//[[[end]]]
params ["_control","_index"];
_config = 'CfgItemSort' call EPOCH_returnConfig;
_MainCategoriearray = getarray (_config >> "MainCategories" >> "Classes");
_FilterArray = [];
if (_index != 0) then {
	{
		_MainCategorie = _x;
		if (_index == (_MainCategorie select 0)) then {
			_subcategories = _MainCategorie select 2;
			{
				_SubCategorieItems = getArray (_config >> "SubCatergories" >> _x);
				{
					_FilterArray pushback (tolower _x);
				} foreach _SubCategorieItems;
			} forEach _subcategories;
		};
	} forEach _MainCategoriearray;
};
if !(isNull EPOCH_lastNPCtradeTarget) then {
	_slot = EPOCH_lastNPCtradeTarget getVariable["AI_SLOT", -1];
	_isPlayerFilter = (ctrlIDC _control == 42100);
	if (_slot != -1) then {
		if (_isPlayerFilter) then {
			_sizeOut = lbSize 41501;
			_offerArray = [];
			if (_sizeOut > 0) then {
				for "_i" from 0 to (_sizeOut - 1) do {
					_item = lbData [41501, _i];
					_offerArray pushBack _item;
				};
			};
			lbClear 41500;
			_playeritems = ((items player)+(magazines player));
			if (primaryWeapon player != "") then {
				_playeritems pushback primaryWeapon player;
			};
			if (count backpackItems player == 0 && count backpackmagazines player == 0 && backpack player != "") then {
				_playeritems pushback backpack player;
			};

			{
				_item = _x;
				if !(_item isequalto "") then {
					if (_index == 0 || (tolower _item) in _FilterArray) then {
						_itemCount = {_x == _item} count ((items player)+(magazines player)+[backpack player]+[primaryweapon player]);
						_itemOfferCount = {_x == _item} count _offerArray;
						if (_itemCount > _itemOfferCount) then {
							_offerArray pushBack _item;
							_id = lbAdd [41500, _x call EPOCH_itemDisplayName];
							lbSetData [41500, _id, _x];
							lbSetPicture [41500, _id, _x call EPOCH_itemPicture];
						};
					};
				};
			} forEach _playeritems;

			_vehicles = player nearEntities [["LandVehicle","Ship","Air","Tank"], 30];
			{
				if (local _x) then {
					_type = typeOf _x;
					if (_index == 0 || (tolower _type) in _FilterArray) then {
						_itemCount = { typeOf _x == _type } count _vehicles;
						_itemOfferCount = { _x == _type } count _offerArray;
						if (_itemCount > _itemOfferCount) then {
							_offerArray pushBack _type;
							_config = configFile >> "CfgVehicles" >> _type;
							_name = getText(_config >> "displayName");
							_picture = getText(_config >> "picture");
							_id = lbAdd[41500, _name];
							lbSetData[41500, _id, _type];
							lbSetPicture[41500, _id, _picture];
						};
					};
				};
			} forEach _vehicles;
            _display = (findDisplay -8);
			_control = (_display displayCtrl 41500);
			lbsort _control;
		}
		else {
			lbClear 41503;
			_sizeOut = lbSize 41502;
			_offerArray = [];
			if (_sizeOut > 0) then {
				for "_i" from 0 to (_sizeOut - 1) do {
					_id = lbData [41502, _i];
					_offerArray pushBack _id;
				};
			};
			_aiItems = EPOCH_lastNPCtradeTarget getVariable["AI_ITEMS", []];
			if ((count _aiItems) == 2) then {
				_items = _aiItems select 0;
				_qtys = _aiItems select 1;
				_sortarray = [];
				{
					_sortarray pushback [_x call EPOCH_itemDisplayName,_x,_qtys select _foreachindex];
				} foreach _items;
				_sortarray sort true;

				{
					_item = _x select 1;

					if !(_item isequalto "") then {
						if (_index == 0 || (tolower _item) in _FilterArray) then {
							_qty = ((_x select 2) - ({_x == _item} count _offerArray));
							if (_qty > 0) then {
								_id = lnbAddRow[41503, ["", str(_qty),_x select 0]];
								lnbSetData [41503, [_id,0], _item];
								lnbSetValue [41503, [_id,0], _qty];
								lnbSetPicture [41503, [_id,0], _item call EPOCH_itemPicture];
							};
						};
					};
				} forEach _sortarray;
			};
		};
	};
} else {
	closeDialog 0;
};
