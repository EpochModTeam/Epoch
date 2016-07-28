if (isNull(findDisplay -13)) exitWith{};
// perform wait while menu is still open

if (isNil "EPOCH_bankTransferActive") then {
	EPOCH_bankTransferActive = true;

	ctrlEnable[1600, false];

	[] spawn {
		private ["_transferTarget","_progress","_sleep","_deposit","_withdraw","_transfer","_totalTransfer"];

		ctrlSetText[1004,"Transfer started, please wait."];

		_deposit = parseNumber(ctrlText 1401) min EPOCH_playerCrypto;
		_withdraw = parseNumber(ctrlText 1402) min EPOCH_bankBalance;
		_transfer = parseNumber(ctrlText 1400) min EPOCH_bankBalance;

		_config = 'CfgEpochClient' call EPOCH_returnConfig;
		getArray(_config >> "bankTransferTime") params [["_timePerCrypto",0.0006],["_maxWait",1.2],["_minWait",0.06]];

		_totalTransfer = (_deposit + _withdraw) + _transfer;
		_progress = 0;

		uiSleep 1;

		_transferTarget = "";
		if (_transfer > 0) then {
			_transferTarget = lbData[21500, (lbCurSel 21500)];
		};

		if (_deposit > 0 || _withdraw > 0 || (_transfer > 0 && _transferTarget != "")) then {

			_sleep = ((_totalTransfer * _timePerCrypto) min _maxWait) max _minWait;
			for "_i" from 0 to 100 do {
				if (isNull(findDisplay -13)) exitWith{};
				_progress = _progress + 1;
				if (_progress >= 100) exitWith{};
				ctrlSetText[1200, format["\x\addons\a3_epoch_code\Data\UI\loading_bar_%1.paa", _progress]];
				uiSleep _sleep;
			};

			if (_progress >= 100) then {
				// if player waited the full time then send upload
				[player, [_deposit, _withdraw, [_transfer, _transferTarget]], Epoch_personalToken] remoteExec ["EPOCH_server_storeCrypto",2];
				ctrlSetText[1004, "Transfer complete."];
				uiSleep 1;
				closeDialog 0;
			}
			else {
				ctrlSetText[1004, "Transfer failed."];
			};
		};
		EPOCH_bankTransferActive = nil;
		ctrlEnable[1600, true];
	};
};
