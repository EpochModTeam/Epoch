//[[[cog import generate_private_arrays ]]]
private ["_array","_config","_cryptoCount","_item","_itemTax","_itemWorth","_sizeOut","_tax","_uiItem","_worth"];
//[[[end]]]
params ["_control","_selected"];

_uiItem = (_selected select 0) lbData(_selected select 1);

_config = 'CfgPricing' call EPOCH_returnConfig;
if (isClass (_config >> _uiItem)) then{

	(_selected select 0) lbDelete (_selected select 1);

	lbSetCurSel[42101, 0];

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
};
