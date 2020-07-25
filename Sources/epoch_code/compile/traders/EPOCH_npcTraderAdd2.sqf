/*
	Author: He-Man - Ignatz-Gaming

    Contributors: Raimonds Virtoss

	Description:
	Move Items in Tradermenu from Traderinventory to TraderOut window

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/traders/EPOCH_npcTraderAdd2.sqf
*/

private [	"_PlayerItemsOutBox","_TraderItemsBox","_TraderItemsOutBox","_CryptoInCtrl","_CryptoOutCtrl","_allowAdd","_uiItem","_rounds","_itemIcon","_itemName","_itemColor","_errormsg","_soldrounds","_tooltip","_config",
			"_ItemIndex","_sizeOut","_item","_maxrnd","_uiQty","_index","_cryptoCount","_worth","_itemTax","_tax"
];
params ["_control","_selected"];
_selected params ["_CurControl","_id"];

_PlayerItemsOutBox = 41501;
_TraderItemsBox = 41503;
_TraderItemsOutBox = 41502;
_CryptoInCtrl = 41004;
_CryptoOutCtrl = 41005;



if !(isNull EPOCH_lastNPCtradeTarget) then {
	_allowAdd = true;
	_uiItem = _CurControl lnbData [_id, 0];
	_rounds = _CurControl lnbValue [_id, 0];
	_itemIcon = _CurControl lnbPicture [_id, 0];
	_itemName = _CurControl lnbText [_id, 2];
	_itemColor = _CurControl lnbColor [_id, 2];
	_errormsg = "";
	_soldrounds = 0;
	_tooltip = "";
	
	
	_config = 'CfgPricing' call EPOCH_returnConfig;
	if (isClass (_config >> _uiItem)) then{
		_ItemIndex = (EPOCH_NpcTradeTraderItems select 0) find _uiItem;
		if (_ItemIndex > -1) then {
			if (_uiItem isKindOf "Air" || _uiItem isKindOf "Ship" || _uiItem isKindOf "LandVehicle" || _uiItem isKindOf "Tank") then {
				_sizeOut = lbSize _PlayerItemsOutBox;
				if (_sizeOut > 0) then {
					for "_i" from 0 to(_sizeOut - 1) do {
						_item = lbData [_PlayerItemsOutBox, _i];
						if (_item isKindOf "Air" || _item isKindOf "Ship" || _item isKindOf "LandVehicle" || _item isKindOf "Tank") exitWith{
							_allowAdd = false;
							_errormsg = "Limit one per trade";
						};
					};
				};
				if (!_allowAdd) exitwith {};
				_sizeOut = lbSize _TraderItemsOutBox;
				if (_sizeOut > 0) then {
					for "_i" from 0 to(_sizeOut - 1) do {
						_item = lbData [_TraderItemsOutBox, _i];
						if (_item isKindOf "Air" || _item isKindOf "Ship" || _item isKindOf "LandVehicle" || _item isKindOf "Tank") exitWith{
							_allowAdd = false;
							_errormsg = "Limit one per trade";
						};
					};
				};
			};
			if (_allowAdd) then {
				_BlackMarketPurchaseMulti = ["CfgBlackMarket", "BlackMarketPurchaseMulti", 1] call EPOCH_fnc_returnConfigEntryV2;
				_BlackMarketSellMulti = ["CfgBlackMarket", "BlackMarketSellMulti", 1] call EPOCH_fnc_returnConfigEntryV2;
				_Blackmarket_SpecialPrices = ["CfgBlackMarket", "Blackmarket_SpecialPrices", []] call EPOCH_fnc_returnConfigEntryV2;
			
				_maxrnd = 1;
				if ([_uiItem,"cfgMagazines"] call Epoch_fnc_isAny) then {
					_maxrnd = getnumber (configfile >> "cfgMagazines" >> _uiItem >> "count");
				};
				if ((_rounds/_maxrnd) >= 1) then {
					_soldrounds = _maxrnd;
				}
				else {
					_soldrounds = _rounds;
				};
				_rounds = _rounds - _soldrounds;
				if (_rounds < 1) then {
					_CurControl lnbDeleteRow _id;
				}
				else {
					_uiQty = _rounds /_maxrnd;
					if (_uiQty >= 1) then {
						_uiQty = floor _uiQty;
					}
					else {
						_uiQty = ceil _uiQty;
						_tooltip = format ["%1 rounds left in Magazine",_rounds];
					};
					lnbSetText [_TraderItemsBox, [_id, 1], str (_uiQty)];
					lnbSetValue [_TraderItemsBox, [_id, 0], _rounds];
					if !(_tooltip isequalto "") then {
						lbSetTooltip [_TraderItemsBox, _id*3, _tooltip];
						lnbSetColor [_TraderItemsBox,[_id,2],[1,(_rounds/_maxrnd),0,1]];
					};
				};
				if (_soldrounds > 0) then {
					_index = lbAdd [_control, _itemName];
					lbSetData [_control, _index, _uiItem];
					lbSetValue [_control,_index, _soldrounds];
					lbSetPicture [_control, _index, _itemIcon];
					lbSetColor [_control,_index,_itemColor];
					if ([_uiItem,"cfgMagazines"] call Epoch_fnc_isAny) then {
						_maxrnd = getnumber (configfile >> "cfgMagazines" >> _uiItem >> "count");
						if !((_soldrounds/_maxrnd) >= 1) then {
							_tooltip = format ["%1 rounds left in Magazine",_soldrounds];
							lbSetTooltip [_control,_index,_tooltip];
						};
					};
				};
				(EPOCH_NpcTradeTraderItems select 1) set [_ItemIndex,_rounds];
				_cryptoCount = 0;
				_sizeOut = lbSize _PlayerItemsOutBox;
				if (_sizeOut > 0) then {
					for "_i" from 0 to (_sizeOut - 1) do {
						_item = lbData [_PlayerItemsOutBox, _i];
						_rounds = lbValue [_PlayerItemsOutBox, _i];
						_worth = getNumber (_config >> _item >> "price");
						_maxrnd = 1;
						if ([_item,"cfgMagazines"] call Epoch_fnc_isAny) then {
							_maxrnd = getnumber (configfile >> "cfgMagazines" >> _item >> "count");
						};
						_worth = round (_worth*(_rounds/_maxrnd));
						_cryptoCount = _cryptoCount + _worth;
					};
				};
				ctrlSetText [_CryptoInCtrl, (format["%1 Crypto", _cryptoCount])];
				_cryptoCount = 0;
				_sizeOut = lbSize _TraderItemsOutBox;
				if (_sizeOut > 0) then {
					for "_i" from 0 to (_sizeOut - 1) do {
						_item = lbData [_TraderItemsOutBox, _i];
						_rounds = lbValue [_TraderItemsOutBox, _i];
						_worth = getNumber (_config >> _item >> "price");
						_itemTax = getNumber (_config >> _item >> "tax");
						_tax = _worth * (EPOCH_taxRate + _itemTax);
						_worth = ceil(_worth + _tax);
						if (EPOCH_lastNPCtradeTarget getvariable ["Epoch_BlackMarketTrader",false]) then {
							_worth = _worth * _BlackMarketPurchaseMulti;
							{
								if (_item isEqualTo (_x select 0)) exitwith {
									_worth = _x select 2;
								};
							} foreach _Blackmarket_SpecialPrices;
						};
						_maxrnd = 1;
						if ([_item,"cfgMagazines"] call Epoch_fnc_isAny) then {
							_maxrnd = getnumber (configfile >> "cfgMagazines" >> _item >> "count");
						};
						_worth = round (_worth*(_rounds/_maxrnd));
						_cryptoCount = _cryptoCount + _worth;
					};
				};
				ctrlSetText [_CryptoOutCtrl, (format["%1 Crypto", _cryptoCount])];
			}
			else {
				["Limit one per trade", 5] call Epoch_message;
			};
		};
	};
};
