//[[[cog import generate_private_arrays ]]]
private ["_nearCrypto","_CryptoItems","_getCrypto","_addmoney"];
//[[[end]]]
if !(isNil "EPOCH_takeCryptoLock") exitWith {};
EPOCH_takeCryptoLock = true;
_nearCrypto = (nearestobjects [player,[],5]) select {(_x getvariable ["Crypto",0]) > 0};
_CryptoItems = [];
_getCrypto = 0;
{
	_addmoney = (_x getvariable ['Crypto',0]);
	if (_addmoney > 0) then {
		_CryptoItems pushback _x;
	};
	_getCrypto = _getCrypto + _addmoney;		
} foreach _nearCrypto;

if (_getCrypto > 0) then {
	[player, Epoch_personalToken, _CryptoItems] remoteExec ["EPOCH_server_takeCrypto",2];
	[format['You found %1 Crypto', _getCrypto], 5] call Epoch_message;
}
else {
	['No Crypto found', 5] call Epoch_message;
};

[] spawn{
	uiSleep 2;
	EPOCH_takeCryptoLock = nil;
};
