/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	P2P trade loop

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/p2p_trading/EPOCH_TradeLoop.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_array","_cryptoOffer","_index","_isAccepted","_isAcceptedOther","_item","_offerArray","_removeCount","_sizeOut","_tradeCryptoOffer","_tradeOffer"];
//[[[end]]]

if (EPOCH_p2ptradeTarget distance player > 8) exitWith{ EPOCH_p2ptradeTarget = ObjNull; };
if (vehicle player != player || vehicle EPOCH_p2ptradeTarget != EPOCH_p2ptradeTarget) exitWith { EPOCH_p2ptradeTarget = ObjNull; };
if (!isNull EPOCH_p2ptradeTarget) then {

	_sizeOut = lbSize 1501;
	_array = [];
	if (_sizeOut > 0) then {
		for "_i" from 0 to (_sizeOut - 1) do {
			_item = lbData [1501, _i];
			_array pushBack _item;
		};
	};

	_cryptoOffer = parseNumber(ctrlText 1400) min EPOCH_playerCrypto;
	_offerArray = [_array, _cryptoOffer];

	if !(EPOCH_prevOffer isEqualTo _offerArray) then {
		player setVariable ["Offer", _offerArray, true];
		EPOCH_prevOffer = _offerArray;
	};

	lbClear 1502;
	_tradeOffer = EPOCH_p2ptradeTarget getVariable["Offer", [[],0]];
	{
		_index = lbAdd [1502, _x call EPOCH_itemDisplayName];
		lbSetData [1502, _index, _x];
		lbSetPicture [1502, _index, _x call EPOCH_itemPicture];
	} forEach (_tradeOffer select 0);

	_tradeCryptoOffer = (_tradeOffer select 1);
	if (_tradeCryptoOffer > 0) then {
		_index = lbAdd[1502, format["%1 Krypto", _tradeCryptoOffer]];
		lbSetData[1502, _index, "Krypto"];
		lbSetPicture[1502, _index, "\x\addons\a3_epoch_code\Data\UI\cc_ca.paa"];
	};

	_isAcceptedOther = EPOCH_p2ptradeTarget getVariable["Accept", false];
	_isAccepted = player getVariable ["Accept",false];

	if (_isAccepted && _isAcceptedOther && !EPOCH_tradeDone) then {
		EPOCH_tradeDone = true;
		EPOCH_prevOffer = [];

		_removeCount = 0;
		{
			if ([_x, "CfgWeapons"] call EPOCH_fnc_isAny) then {
				if (_x in items player) then {
					player removeItem _x;
					_removeCount = _removeCount + 1;
				};
			} else {
				if (_x in magazines player) then {
					player removeMagazine _x;
					_removeCount = _removeCount + 1;
				};
			};
		}forEach _array;
		if (_removeCount == count _array) then {
			[player, EPOCH_p2ptradeTarget, _array, _tradeOffer, Epoch_personalToken] remoteExec ["EPOCH_server_makeTrade",2];
		};
		(findDisplay -1900) closeDisplay 1;
	};

	// cancel close menu if men not open on other player
	/*
	if !(EPOCH_p2ptradeTarget getVariable["TRADE_ACTIVE", objNull] == player) then {
		(findDisplay -1900) closeDisplay 1;
	};
	*/
};
