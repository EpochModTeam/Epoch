/*
	Author: He-Man - Ignatz-Gaming

    Contributors: Raimonds Virtoss

	Description:
	Move Items in Tradermenu between Playerinventory <-> PlayerOut window

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/traders/EPOCH_npcTraderAdd.sqf
*/

private [	"_PlayerFilerDropDown","_PlayerItemsBox","_PlayerItemsOutBox","_TraderItemsOutBox","_CryptoInCtrl","_CryptoOutCtrl","_allowAdd","_uiItem","_rounds","_itemIcon","_itemColor","_errormsg","_config",
			"_sizeOut","_item","_vehicle","_itemName","_index","_maxrnd","_ItemIndex","_cryptoCount","_worth","_itemTax","_tax"
];
params ["_control","_selected"];
_selected params ["_CurControl","_id"];

_PlayerFilerDropDown = 42100;
_PlayerItemsBox = 41500;
_PlayerItemsOutBox = 41501;
_TraderItemsOutBox = 41502;
_CryptoInCtrl = 41004;
_CryptoOutCtrl = 41005;

if !(isNull EPOCH_lastNPCtradeTarget) then {
	_allowAdd = true;
	_uiItem = _CurControl lbData _id;
	_rounds = _CurControl lbValue _id;
	_itemIcon = _CurControl lbPicture _id;
	_itemColor = _CurControl lbColor _id;
	_errormsg = "";

	_config = 'CfgPricing' call EPOCH_returnConfig;
	if (isClass (_config >> _uiItem)) then {
		if (_control == _PlayerItemsOutBox) then {
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
						_item = lbData[_TraderItemsOutBox, _i];
						if (_item isKindOf "Air" || _item isKindOf "Ship" || _item isKindOf "LandVehicle" || _item isKindOf "Tank") exitWith{
							_allowAdd = false;
							_errormsg = "Limit one per trade";
						};
					};
				};
				if (!_allowAdd) exitwith {};
				if (["CfgEpochClient", "DisallowSellOnDamage", false] call EPOCH_fnc_returnConfigEntryV2) then {
					{
						_vehicle = _x;
						if (local _vehicle && (typeof _vehicle) isequalto _uiItem) then {
							{
								if ((["wheel",tolower _x] call bis_fnc_instring) || _x isequalto "HitEngine") then {
									if (((getAllHitPointsDamage _vehicle) select 2 select _foreachindex) >= 1) then {
										_allowAdd = false;
										_errormsg = "Cannot be sold - too much damage";
									};
								};
								if (!_allowAdd) exitwith {};
							} foreach ((getAllHitPointsDamage _vehicle) select 0);
						};
						if (!_allowAdd) exitwith {};
					} foreach (EPOCH_lastNPCtradeTarget nearEntities [[_uiItem], 30]);
				};
			};
		};

		if (_allowAdd) then {
			_itemName = _CurControl lbText _id;
			_index = lbAdd [_control, _itemName];
			lbSetData [_control, _index, _uiItem];
			lbSetValue [_control,_index, _rounds];
			lbSetPicture [_control, _index, _itemIcon];
			lbSetColor [_control,_index,_itemColor];
			if (_control == _PlayerItemsBox && !(_uiItem iskindof "Landvehicle" || _uiItem iskindof "SHIP" || _uiItem iskindof "AIR" || _uiItem iskindof "TANK")) then {
				if ((_itemName find " (in Hand)") > -1) then {
					EPOCH_NpcTradePlayerItems pushback [_uiItem,"Hand"];
				}
				else {
					EPOCH_NpcTradePlayerItems pushback [_uiItem,_rounds];
				};
			}
			else {
				if ([_uiItem,"cfgMagazines"] call Epoch_fnc_isAny) then {
					_maxrnd = getnumber (configfile >> "cfgMagazines" >> _uiItem >> "count");
					if !((_rounds/_maxrnd) >= 1) then {
						_tooltip = format ["%1 rounds left in Magazine",_rounds];
						lbSetTooltip [_control,_index,_tooltip];
					};
				};
				_ItemIndex = -1;
				if ((_itemName find " (in Hand)") > -1) then {
					_ItemIndex = EPOCH_NpcTradePlayerItems find [_uiItem,"Hand"];
				};
				if (_ItemIndex < 0) then {
					_ItemIndex = EPOCH_NpcTradePlayerItems find _uiItem;
					if (_ItemIndex < 0) then {
						_ItemIndex = EPOCH_NpcTradePlayerItems find [_uiItem,_rounds];
					};
				};
				if (_ItemIndex > -1) then {
					EPOCH_NpcTradePlayerItems deleteat _ItemIndex;
				};
			};
			_CurControl lbDelete _id;
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
					_maxrnd = 1;
					if ([_item,"cfgMagazines"] call Epoch_fnc_isAny) then {
						_maxrnd = getnumber (configfile >> "cfgMagazines" >> _item >> "count");
					};
					_worth = round (_worth*(_rounds/_maxrnd));
					_cryptoCount = _cryptoCount + _worth;
				};
			};
			ctrlSetText [_CryptoOutCtrl, (format["%1 Crypto", _cryptoCount])];
			if (_control == _PlayerItemsBox) then {
				lbSetCurSel [_PlayerFilerDropDown, 0];
			};
		}
		else {
			[_errormsg, 5] call Epoch_message;
		};
	};
}
else {
	closeDialog 0;
};
