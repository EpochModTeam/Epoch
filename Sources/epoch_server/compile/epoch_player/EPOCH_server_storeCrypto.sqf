/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Player Bank

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_player/EPOCH_server_storeCrypto.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_bankBalance","_bankBalanceBefore","_bankData","_cIndex","_current_crypto","_playerCryptoLimit","_playerUID","_response","_return","_transferAmountIn","_transferAmountOut","_transferBalance","_transferBankBalance","_transferBankBalanceBefore","_transferBankData","_transferResponse","_transferTarget","_transferTargetUID","_vars"];
//[[[end]]]
params ["_player","_tradeArray",["_token","",[""]] ];

if !([_player, _token] call EPOCH_server_getPToken) exitWith{};

_playerUID = getPlayerUID _player;

// load players account
_response = ["Bank", _playerUID] call EPOCH_fnc_server_hiveGETRANGE;

if ((_response select 0) == 1 && (_response select 1) isEqualType []) then {

	_bankData = _response select 1;
	_bankBalance = 0;
	_bankBalanceBefore = 0;
	if !(_bankData isEqualTo[]) then {
		_bankBalance = _bankData select 0;
		_bankBalanceBefore = _bankBalance;
	};

	// return balance to player
	if (_tradeArray isEqualTo[]) then {
		[["bankBalance", _bankBalance], _player] call EPOCH_sendRemoteExecClient;
	} else {

		// Transaction Data - TODO add check for validity of transaction
		_transferAmountIn = _tradeArray select 0;
		_transferAmountOut = _tradeArray select 1;

		// Send to another player
		_transferBalance = _tradeArray select 2 select 0;
		_transferTarget = objectFromNetId (_tradeArray select 2 select 1);

		// get vars array and current Crypto value
		_cIndex = EPOCH_customVars find "Crypto";
		_vars = _player getVariable["VARS", call EPOCH_defaultVars_SEPXVar];
		_current_crypto = _vars select _cIndex;

		// Make Transaction
		_playerCryptoLimit = EPOCH_customVarLimits select _cIndex;
		_playerCryptoLimit params ["_playerCryptoLimitMax","_playerCryptoLimitMin"];

		if (_transferAmountIn > 0) then {
			if (_current_crypto >= _transferAmountIn) then {
				_bankBalance = _bankBalance + _transferAmountIn;
				_current_crypto = ((_current_crypto - _transferAmountIn) min _playerCryptoLimitMax) max _playerCryptoLimitMin;
				_current_crypto remoteExec ['EPOCH_effectCrypto',_player];
				_vars set[_cIndex, _current_crypto];
				_player setVariable["VARS", _vars];
			};
		};

		if (_transferAmountOut > 0) then {
			if (_bankBalance >= _transferAmountOut) then {
				_bankBalance = _bankBalance - _transferAmountOut;
				_current_crypto = ((_current_crypto + _transferAmountOut) min _playerCryptoLimitMax) max _playerCryptoLimitMin;
				// send to player
				_current_crypto remoteExec ['EPOCH_effectCrypto',_player];
				_vars set[_cIndex, _current_crypto];
				_player setVariable["VARS", _vars];
			};
		};

		// send money to another players account
		if (!(isNull _transferTarget) && _bankBalance >= _transferBalance) then {

			if (_transferBalance > 0) then {

				_transferTargetUID = getPlayerUID _transferTarget;
				_transferResponse = ["Bank", _transferTargetUID] call EPOCH_fnc_server_hiveGETRANGE;

				if ((_transferResponse select 0) == 1 && (_transferResponse select 1) isEqualType []) then {

					_transferBankData = _transferResponse select 1;
					_transferBankBalance = 0;
					_transferBankBalanceBefore = 0;

					if !(_transferBankData isEqualTo[]) then {
						_transferBankBalance = _transferBankData select 0;
						_transferBankBalanceBefore = _transferBankBalance;
					};

					// take from player
					_bankBalance = _bankBalance - _transferBalance;

					// give to player
					_transferBankBalance = _transferBankBalance + _transferBalance;

					if (_transferBankBalanceBefore != _transferBankBalance) then {
						_return = ["Bank", _transferTargetUID, EPOCH_expiresPlayer, [_transferBankBalance]] call EPOCH_fnc_server_hiveSETEX;
						[["bankBalance", _transferBankBalance], _transferTarget] call EPOCH_sendRemoteExecClient;
					};
				};
			};
		};

		if (_bankBalanceBefore != _bankBalance) then {
			_return = ["Bank", _playerUID, EPOCH_expiresBank, [_bankBalance]] call EPOCH_fnc_server_hiveSETEX;
		};
	};
};
diag_log format["Epoch: BANK - %1 (%2) TRADE: %3", _player, _playerUID, _tradeArray];
