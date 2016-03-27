private ["_stockLimit","_allowAdd","_limit","_slot","_aiItems","_itemClasses","_itemQtys","_qtyIndex","_item","_sizeOut","_worth","_cryptoCount","_itemWorth","_itemTax","_tax","_index","_uiItem","_config"];
params ["_control","_selected"];

if !(isNull EPOCH_lastNPCtradeTarget) then {

	_allowAdd = true;
	_stockLimit = false;
	_uiItem = (_selected select 0) lbData (_selected select 1);

	_config = 'CfgPricing' call EPOCH_returnConfig;
	if (isClass(_config >> _uiItem)) then{

		if !(_control in[41500, 41503]) then {

			// limit adding more if item is over stocked
			if (_control == 41501) then {
				_slot = EPOCH_lastNPCtradeTarget getVariable["AI_SLOT", -1];
				_aiItems = EPOCH_lastNPCtradeTarget getVariable["AI_ITEMS", [[], []]];
				_itemClasses = _aiItems select 0;
				_itemQtys = _aiItems select 1;

				// find item and get current qty
				_qtyIndex = _itemClasses find _uiItem;
				if (_qtyIndex != -1) then {
					_limit = ["CfgTraderLimits", _uiItem, 100] call EPOCH_fnc_returnConfigEntryV2;
					if (_itemQtys select _qtyIndex >= _limit) then{
						_stockLimit = true;
						_allowAdd = false;
					};
				};
			};

			if (_uiItem isKindOf "Air" || _uiItem isKindOf "Ship" || _uiItem isKindOf "LandVehicle" || _uiItem isKindOf "Tank") then {

				// check if a vehicle is already on the list
				_sizeOut = lbSize 41501;
				if (_sizeOut > 0) then {
					for "_i" from 0 to(_sizeOut - 1) do {
						_item = lbData[41501, _i];
						if (_item isKindOf "Air" || _item isKindOf "Ship" || _item isKindOf "LandVehicle" || _item isKindOf "Tank") exitWith{
							_allowAdd = false;
						};
					};
				};
				_sizeOut = lbSize 41502;
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
		};

		if (_allowAdd) then {
			_index = lbAdd[_control, ((_selected select 0) lbText(_selected select 1))];
			lbSetData[_control, _index, _uiItem];

			lbSetPicture[_control, _index, ((_selected select 0) lbPicture(_selected select 1))];
			(_selected select 0) lbDelete(_selected select 1);

			_cryptoCount = 0;
			_sizeOut = lbSize 41501;
			//_array = [];
			if (_sizeOut > 0) then {
				for "_i" from 0 to(_sizeOut - 1) do {
					_item = lbData[41501, _i];
					//_array pushBack _item;
					_worth = getNumber(_config >> _item >> "price");
					_cryptoCount = _cryptoCount + _worth;
				};
			};
			ctrlSetText[41004, (format["%1 Krypto", _cryptoCount])];

			_cryptoCount = 0;
			_sizeOut = lbSize 41502;
			if (_sizeOut > 0) then {
				for "_i" from 0 to(_sizeOut - 1) do {
					_item = lbData[41502, _i];
					_itemWorth = getNumber(_config >> _item >> "price");
					_itemTax = getNumber(_config >> _item >> "tax");
					_tax = _itemWorth * (EPOCH_taxRate + _itemTax);
					_itemWorth = ceil(_itemWorth + _tax);
					_cryptoCount = _cryptoCount + _itemWorth;
				};
			};
			ctrlSetText[41005, (format["%1 Krypto", _cryptoCount])];
		} else {
			if (_stockLimit) then{
				["<t size='1.6' color='#99ffffff'>Trader has the maximum amount of this item</t>", 5] call Epoch_dynamicText;
			} else {
				["<t size='1.6' color='#99ffffff'>Limit one per trade</t>", 5] call Epoch_dynamicText;
			};
		};
	};
} else {
	closeDialog 0;
};
