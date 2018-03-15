/*
	Author: He-Man - Ignatz-Gaming

    Contributors: Raimonds Virtoss

	Description:
	Move Items in Tradermenu from TraderOut window to Traderinventory

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/traders/EPOCH_npcTraderAdd3.sqf
*/

private ["_TraderFilerDropDown","_PlayerItemsOutBox","_TraderItemsOutBox","_CryptoInCtrl","_CryptoOutCtrl","_uiItem","_rounds","_config","_ItemIndex","_cryptoCount","_sizeOut","_item","_worth","_maxrnd","_itemTax","_tax"];
params ["_control","_selected"];
_selected params ["_CurControl","_id"];

_TraderFilerDropDown = 42101;
_PlayerItemsOutBox = 41501;
_TraderItemsOutBox = 41502;
_CryptoInCtrl = 41004;
_CryptoOutCtrl = 41005;

_uiItem = _CurControl lbData _id;
_rounds = _CurControl lbValue _id;

_config = 'CfgPricing' call EPOCH_returnConfig;
if (isClass (_config >> _uiItem)) then {
	_ItemIndex = (EPOCH_NpcTradeTraderItems select 0) find _uiItem;
	if (_ItemIndex >= 0) then {
		(EPOCH_NpcTradeTraderItems select 1) set [_ItemIndex,(EPOCH_NpcTradeTraderItems select 1 select _ItemIndex) + _rounds];
	};	
	_CurControl lbDelete _id;
	lbSetCurSel [_TraderFilerDropDown, 0];
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
	ctrlSetText [_CryptoInCtrl, (format["%1 Krypto", _cryptoCount])];
	_cryptoCount = 0;
	_sizeOut = lbSize _TraderItemsOutBox;
	if (_sizeOut > 0) then {
		for "_i" from 0 to (_sizeOut - 1) do {
			_item = lbData [_TraderItemsOutBox, _i];
			_rounds = lbValue [_TraderItemsOutBox, _i];
			_worth = getNumber (_config >> _item >> "price");
			_itemTax = getNumber (_config >> _item >> "tax");
			_tax = _worth * (EPOCH_taxRate + _itemTax);
			_worth = ceil (_worth + _tax);
			_maxrnd = 1;
			if ([_item,"cfgMagazines"] call Epoch_fnc_isAny) then {
				_maxrnd = getnumber (configfile >> "cfgMagazines" >> _item >> "count");
			};
			_worth = round (_worth*(_rounds/_maxrnd));
			_cryptoCount = _cryptoCount + _worth;
		};
	};
	ctrlSetText [_CryptoOutCtrl, (format["%1 Krypto", _cryptoCount])];
};
