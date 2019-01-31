/*
	Author: He-Man - Ignatz-Gaming

    Contributors: Raimonds Virtoss

	Description:
	Filter Items in Trader Dialog

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/traders/EPOCH_NPCTraderFilter.sqf
*/

disableSerialization;
private [	"_PlayerFilerDropDown","_PlayerItemsBox","_PlayerItemsOutBox","_TraderItemsBox","_TraderItemsOutBox","_config","_MainCategoriearray","_FilterArray","_MainCategorie","_subcategories","_SubCategorieItems",
			"_slot","_isPlayerFilter","_item","_rounds","_maxrnd","_tooltip","_qty","_id","_vehicles","_VehOfferArray","_sizeOut","_type","_itemCount","_itemOfferCount","_name","_picture","_items","_qtys","_sortarray"
];
params ["_control","_index"];

_PlayerFilerDropDown = 42100;
_PlayerItemsBox = 41500;
_PlayerItemsOutBox = 41501;
_TraderItemsBox = 41503;
_TraderItemsOutBox = 41502;

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
	if (_slot != -1) then {
		_isPlayerFilter = (ctrlIDC _control == _PlayerFilerDropDown);
		if (_isPlayerFilter) then {
			lbClear _PlayerItemsBox;
			{
				_item = _x;
				_rounds = 1;
				_onHand = false;
				if (_item isequaltype []) then {
					_item = _x select 0;
					if ((_x select 1) isequalto "Hand") then {
						_onHand = true;
					}
					else {
						_rounds = _x select 1;
					};
				};
				if !(_item isequalto "") then {
					_maxrnd = 1;
					_tooltip = "";
					if ([_item,"cfgMagazines"] call Epoch_fnc_isAny) then {
						_maxrnd = getnumber (configfile >> "cfgMagazines" >> _item >> "count");
					};
					_qty = _rounds/_maxrnd;
					if (_qty < 1) then {
						_tooltip = format ["%1 rounds left in Magazine",_rounds];
					};
					if (_index == 0 || (tolower _item) in _FilterArray) then {
						_id = lbAdd [_PlayerItemsBox, (_item call EPOCH_itemDisplayName) + (if (_onHand) then {" (in Hand)"} else {""})];
						lbSetData [_PlayerItemsBox, _id, _item];
						lbSetValue [_PlayerItemsBox, _id, _rounds];
						lbSetPicture [_PlayerItemsBox, _id, _item call EPOCH_itemPicture];
						if !(_tooltip isequalto "") then {
							lbSetTooltip [_PlayerItemsBox, _id, _tooltip];
							lbSetColor [_PlayerItemsBox,_id,[1,(_rounds/_maxrnd),0,1]];
						};
						if (_onHand) then {
							lbSetColor [_PlayerItemsBox,_id,[1,1,1,0.5]];
						};
					};
				};
			} forEach EPOCH_NpcTradePlayerItems;

			_vehicles = player nearEntities [["LandVehicle","Ship","Air","Tank"], ["CfgEpochClient", "MaxVehTradeDist", 30] call EPOCH_fnc_returnConfigEntryV2];
			if !(_vehicles isequalto []) then {
				_VehOfferArray = [];
				_sizeOut = lbSize _PlayerItemsOutBox;
				if (_sizeOut > 0) then {
					for "_i" from 0 to (_sizeOut - 1) do {
						_item = lbData [_PlayerItemsOutBox, _i];
						if (_item iskindof "Landvehicle" || _item iskindof "AIR" || _item iskindof "SHIP" || _item iskindof "TANK") then {
							_VehOfferArray pushBack _item;
						};
					};
				};
				{
					if (local _x) then {
						_type = typeOf _x;
						if (_index == 0 || (tolower _type) in _FilterArray) then {
							_itemCount = { typeOf _x == _type } count _vehicles;
							_itemOfferCount = { _x == _type } count _VehOfferArray;
							if (_itemCount > _itemOfferCount) then {
								_config = configFile >> "CfgVehicles" >> _type;
								_name = getText(_config >> "displayName");
								_picture = getText(_config >> "picture");
								_id = lbAdd[_PlayerItemsBox, _name];
								lbSetData[_PlayerItemsBox, _id, _type];
								lbSetValue [_PlayerItemsBox, _id, 1];
								lbSetPicture[_PlayerItemsBox, _id, _picture];
							};
						};
					};
				} forEach _vehicles;
			};
			lbsort ((findDisplay -8) displayCtrl _PlayerItemsBox);
		}
		else {
			lbClear _TraderItemsBox;
			if ((count EPOCH_NpcTradeTraderItems) == 2) then {
				_items = EPOCH_NpcTradeTraderItems select 0;
				_qtys = EPOCH_NpcTradeTraderItems select 1;
				_sortarray = [];
				{
					_sortarray pushback [_x call EPOCH_itemDisplayName,_x,_qtys select _foreachindex];
				} foreach _items;
				_sortarray sort true;
				{
					_x params ["_displayname","_item","_rounds"];
					if !(_item isequalto "") then {
						if (_index == 0 || (tolower _item) in _FilterArray) then {
							_maxrnd = 1;
							_tooltip = "";
							if ([_item,"cfgMagazines"] call Epoch_fnc_isAny) then {
								_maxrnd = getnumber (configfile >> "cfgMagazines" >> _item >> "count");
							};
							_qty = (_rounds/_maxrnd);
							if (_qty >= 1) then {
								_qty = floor _qty;
							}
							else {
								_qty = ceil _qty;
								_tooltip = format ["%1 rounds left in Magazine",_rounds];
							};
							if (_qty > 0) then {
								_id = lnbAddRow [_TraderItemsBox, ["", str(_qty),_displayname]];
								lnbSetData [_TraderItemsBox, [_id,0], _item];
								lnbSetValue [_TraderItemsBox, [_id,0], _rounds];
								lnbSetPicture [_TraderItemsBox, [_id,0], _item call EPOCH_itemPicture];
								if !(_tooltip isequalto "") then {
									lbSetTooltip [_TraderItemsBox, _id*3, _tooltip];
									lnbSetColor [_TraderItemsBox,[_id,2],[1,(_rounds/_maxrnd),0,1]];
								};
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
