//[[[cog import generate_private_arrays ]]]
private ["_getCrypto"];
//[[[end]]]
if !(isNil "EPOCH_takeCryptoLock") exitWith {};
EPOCH_takeCryptoLock = true;
if (!isNull _this) then {
	_getCrypto = _this getVariable["Crypto", 0];
	if (_getCrypto > 0) then {
		[player, Epoch_personalToken, _this] remoteExec ["EPOCH_server_takeCrypto",2];
		[format["You found %1 Krypto", _getCrypto], 5] call Epoch_message;
	} else {
		["No Krypto found", 5] call Epoch_message;
	};
};
[] spawn{
	uiSleep 2;
	EPOCH_takeCryptoLock = nil;
};
