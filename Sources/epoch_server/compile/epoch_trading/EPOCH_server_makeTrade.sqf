/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Epoch Mod P2P Trading

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_trading/EPOCH_server_makeTrade.sqf
*/
private ["_current_crypto1","_overFlowItems","_playerCryptoLimit","_tradeOffer2","_tradeOffer1","_trade1","_trade2","_cIndex","_player1_vars","_player2_vars","_current_crypto2","_tradeCryptoOffer1","_tradeCryptoOffer2"];
params ["_player1", "_player2","_array","_tradeOffer",["_token","",[""]]];

if (isNull _player2) exitWith{};
if !([_player1, _token] call EPOCH_server_getPToken) exitWith{};
if (_player1 distance _player2 > 10) exitWith{};

if ((_player1 getVariable["currentTradeKey", -1]) isEqualto (_player2 getVariable["currentTradeKey", -2])) then{
	if ((_player1 getVariable["Accept", false]) && (_player2 getVariable["Accept", false])) then{

		_trade1 = _player1 getVariable["Offer", [[], 0]];
		_trade2 = _player2 getVariable["Offer", [[], 0]];

		_trade1 params ["_tradeOffer1","_tradeCryptoOffer1"];
		_trade2 params ["_tradeOffer2","_tradeCryptoOffer2"];

		_cIndex = EPOCH_customVars find "Crypto";
		_player1_vars = _player1 getVariable["VARS", call EPOCH_defaultVars_SEPXVar];
		_player2_vars = _player2 getVariable["VARS", call EPOCH_defaultVars_SEPXVar];
		_current_crypto1 = _player1_vars select _cIndex;
		_current_crypto2 = _player2_vars select _cIndex;

		// test this may work since players crypto is
		if (_current_crypto1 >= _tradeCryptoOffer1 && _current_crypto2 >= _tradeCryptoOffer2) then{

			_playerCryptoLimit = EPOCH_customVarLimits select _cIndex;
			_playerCryptoLimit params ["_playerCryptoLimitMax","_playerCryptoLimitMin"];

			if (_tradeCryptoOffer1 > 0) then{

				_current_crypto1 = ((_current_crypto1 - _tradeCryptoOffer1) min _playerCryptoLimitMax) max _playerCryptoLimitMin;
				// send to player
				_current_crypto1 remoteExec ['EPOCH_effectCrypto',_player1];
				_player1_vars set[_cIndex, _current_crypto1];
				_player1 setVariable["VARS", _player1_vars];
			};

			if !(_tradeOffer2 isEqualTo[]) then{
				_overFlowItems = createVehicle["groundWeaponHolder", getPosATL _player1, [], 0, "CAN_COLLIDE"];
				{
					if ([_x, "CfgWeapons"] call EPOCH_fnc_isAny) then{
						_overFlowItems addItemCargoGlobal[_x, 1];
					} else {
						_overFlowItems addMagazineCargoGlobal[_x, 1];
					};
				} forEach _tradeOffer2;
			};

			if (_tradeCryptoOffer2 > 0) then{

				_current_crypto1 = ((_current_crypto1 + _tradeCryptoOffer2) min _playerCryptoLimitMax) max _playerCryptoLimitMin;
				// send to player
				_current_crypto1 remoteExec ['EPOCH_effectCrypto',_player1];
				_player1_vars set[_cIndex, _current_crypto1];
				_player1 setVariable["VARS", _player1_vars];
			};

			diag_log format["ADMIN: P1:%1 P2:%2 In:%3:%4 Out:%5:%6", _player1, _player2, _tradeOffer2, _tradeCryptoOffer2, _tradeOffer1, _tradeCryptoOffer1];
		};
	};

};
