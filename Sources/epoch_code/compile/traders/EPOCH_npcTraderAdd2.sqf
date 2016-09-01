//[[[cog import generate_private_arrays ]]]
private ["_allowAdd","_array","_config","_cryptoCount","_index","_item","_itemIcon","_itemName","_itemTax","_itemWorth","_qty","_sizeOut","_tax","_uiItem","_uiQty","_worth"];
//[[[end]]]
params ["_control","_selected"];

_allowAdd = true;

_uiItem = (_selected select 0) lnbData[(_selected select 1), 0];

_config = 'CfgPricing' call EPOCH_returnConfig;
if (isClass (_config >> _uiItem)) then{

	if (_uiItem isKindOf "Air" || _uiItem isKindOf "Ship" || _uiItem isKindOf "LandVehicle" || _uiItem isKindOf "Tank") then {

		// check if a vehicle is already on the list
		_sizeOut = lbSize 41501;
		//_array = [];
		if (_sizeOut > 0) then {
			for "_i" from 0 to(_sizeOut - 1) do {
				_item = lbData[41501, _i];
				//_array pushBack _item;
				if (_item isKindOf "Air" || _item isKindOf "Ship" || _item isKindOf "LandVehicle" || _item isKindOf "Tank") exitWith{
					_allowAdd = false;
				};
			};
		};
		_sizeOut = lbSize 41502;
		//_array = [];
		if (_sizeOut > 0) then {
			for "_i" from 0 to(_sizeOut - 1) do {
				_item = lbData[41502, _i];
				if (_item isKindOf "Air" || _item isKindOf "Ship" || _item isKindOf "LandVehicle" || _item isKindOf "Tank") exitWith{
					_allowAdd = false;
				};
			};
		};
		// disallow adding item to list of already one


	};

	if (_allowAdd) then {
		_itemName = (_selected select 0) lnbText[(_selected select 1), 2];
		_index = lbAdd [_control, _itemName];
		lbSetData [_control, _index, _uiItem];

		_itemIcon = (_selected select 0) lnbPicture [(_selected select 1), 0];
		lbSetPicture [_control, _index, _itemIcon];

		_uiQty = (_selected select 0) lnbValue [(_selected select 1), 0];
		if (_uiQty <= 1) then {
			(_selected select 0) lnbDeleteRow (_selected select 1);
		} else {
			_qty = _uiQty - 1;
			lnbSetText[41503, [(_selected select 1), 1], str(_qty)];
			lnbSetValue[41503, [(_selected select 1), 0], _qty];
		};

		_cryptoCount = 0;
		_sizeOut = lbSize 41501;
		//_array = [];
		if (_sizeOut > 0) then {
			for "_i" from 0 to (_sizeOut - 1) do {
				_item = lbData [41501, _i];
				//_array pushBack _item;
				_worth = getNumber(_config >> _item >> "price");
				_cryptoCount = _cryptoCount + _worth;
			};
		};
		ctrlSetText [41004, (format ["%1 Krypto", _cryptoCount])];

		_cryptoCount = 0;
		_sizeOut = lbSize 41502;
		if (_sizeOut > 0) then {
			for "_i" from 0 to (_sizeOut - 1) do {
				_item = lbData [41502, _i];
				_itemWorth = getNumber(_config >> _item >> "price");
				_itemTax = getNumber(_config >> _item >> "tax");
				_tax = _itemWorth * (EPOCH_taxRate + _itemTax);
				_itemWorth = ceil(_itemWorth + _tax);
				_cryptoCount = _cryptoCount + _itemWorth;
			};
		};
		ctrlSetText [41005, (format ["%1 Krypto", _cryptoCount])];
	} else {
		["Limit one per trade", 5] call Epoch_message;
	};
};
