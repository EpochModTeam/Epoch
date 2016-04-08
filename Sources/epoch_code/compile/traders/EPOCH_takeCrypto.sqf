private["_getCrypto"];
if !(isNil "EPOCH_takeCryptoLock") exitWith {};
EPOCH_takeCryptoLock = true;
if (!isNull _this) then {
	if ((typeof _this) == "Land_MPS_EPOCH") then {
		_getCrypto = _this getVariable["Crypto", 0];
		[player, Epoch_personalToken, _this] remoteExec ["EPOCH_server_takeCrypto",2];
		[format["<t size='1.6' color='#99ffffff'>You found %1 Krypto.</t>", _getCrypto], 5] call Epoch_dynamicText;
	};
};
[] spawn{
	uiSleep 2;
	EPOCH_takeCryptoLock = nil;
};
