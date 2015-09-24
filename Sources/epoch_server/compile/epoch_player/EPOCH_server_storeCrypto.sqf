/*
Player Bank

Epoch Mod - EpochMod.com
All Rights Reserved.
*/
private["_plyr", "_bankBalance", "_bankBalanceBefore", "_current_crypto", "_transferBankBalance", "_transferBankBalanceBefore", "_return", "_transferBankData", "_transferTargetUID", "_transferResponse", "_transferAmountIn", "_transferAmountOut", "_transferBalance", "_transferTarget", "_cIndex", "_vars", "_plyrNetID", "_bankData", "_tradeArray", "_plyrUID", "_response"];

_plyr = _this select 0;
_tradeArray = _this select 1;

// handle token check and isnull for _plyr
if !([_plyr, _this select 2] call EPOCH_server_getPToken) exitWith{};

_plyrUID = getPlayerUID _plyr;

// load players account
_response = ["Bank", _plyrUID] call EPOCH_fnc_server_hiveGETRANGE;

if ((_response select 0) == 1 && typeName(_response select 1) == "ARRAY") then {

	_plyrNetID = owner _plyr;

	_bankData = _response select 1;
	_bankBalance = 0;
	_bankBalanceBefore = 0;
	if !(_bankData isEqualTo[]) then {
		_bankBalance = _bankData select 0;
		_bankBalanceBefore = _bankBalance;
	};

	// return balance to player
	if (_tradeArray isEqualTo[]) then {
		[["bankBalance", _bankBalance], _plyrNetID] call EPOCH_sendPublicVariableClient;
	} else {

		// Transaction Data - TODO add check for validity of transaction
		_transferAmountIn = _tradeArray select 0;
		_transferAmountOut = _tradeArray select 1;

		// Send to another player
		_transferBalance = _tradeArray select 2 select 0;
		_transferTarget = objectFromNetId (_tradeArray select 2 select 1);

		// get vars array and current Crypto value
		_cIndex = EPOCH_customVars find "Crypto";
		_vars = _plyr getVariable["VARS", [] + EPOCH_defaultVars_SEPXVar];
		_current_crypto = _vars select _cIndex;

		// Make Transaction
		_playerCryptoLimit = [(configFile >> "CfgSecConf" >> "limits"), "playerCrypto", 25000] call EPOCH_fnc_returnConfigEntry;

		if (_transferAmountIn > 0) then {

			// diag_log format["Store: _current_crypto: %1 _cIndex:%2", _current_crypto, _cIndex];

			if (_current_crypto >= _transferAmountIn) then {
				_bankBalance = _bankBalance + _transferAmountIn;
				_current_crypto = ((_current_crypto - _transferAmountIn) min _playerCryptoLimit) max 0;
				[["effectCrypto", _current_crypto], _plyrNetID] call EPOCH_sendPublicVariableClient;
				_vars set[_cIndex, _current_crypto];
				_plyr setVariable["VARS", _vars];
			};
		};

		if (_transferAmountOut > 0) then {
			if (_bankBalance >= _transferAmountOut) then {
				_bankBalance = _bankBalance - _transferAmountOut;
				_current_crypto = ((_current_crypto + _transferAmountOut) min _playerCryptoLimit) max 0;
				[["effectCrypto", _current_crypto], _plyrNetID] call EPOCH_sendPublicVariableClient;
				_vars set[_cIndex, _current_crypto];
				_plyr setVariable["VARS", _vars];
			};
		};

		// send money to another players account
		if (!(isNull _transferTarget) && _bankBalance >= _transferBalance) then {

			if (_transferBalance > 0) then {

				_transferTargetUID = getPlayerUID _transferTarget;
				_transferResponse = ["Bank", _transferTargetUID] call EPOCH_fnc_server_hiveGETRANGE;

				if ((_transferResponse select 0) == 1 && typeName(_transferResponse select 1) == "ARRAY") then {

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
						[["bankBalance", _transferBankBalance], (owner _transferTarget)] call EPOCH_sendPublicVariableClient;
					};
				};
			};
		};

		if (_bankBalanceBefore != _bankBalance) then {
			_return = ["Bank", _plyrUID, EPOCH_expiresBank, [_bankBalance]] call EPOCH_fnc_server_hiveSETEX;
		};
	};
};
diag_log format["BANK: %1 (%2) TRADE: %3", _plyr, _plyrUID, _tradeArray];
