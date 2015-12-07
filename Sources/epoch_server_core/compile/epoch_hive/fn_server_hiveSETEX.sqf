/*
	Author: Aaron Clark - EpochMod.com

    Contributors: Florian Kinder

	Description:
    Hive SETEX

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server_core/compile/epoch_hive/fn_server_hiveSETEX.sqf
*/

private ["_prefix","_key","_expires","_value","_valueLength","_callStack","_call","_index","_charLimit"];

_prefix      = _this select 0;
_key         = _this select 1;
_expires     = _this select 2;
_value       = str (_this select 3);
_valueLength = count _value;

_callStack = 101;
_call = 121;
if !(EPOCH_hiveAsync) then {
    _callStack = 100;
    _call = 120;
};

_index = 0;
_charLimit = 8000;

if (_valueLength > _charLimit) then{

	if (isNil "EPOCH_hiveCallID") then{
		EPOCH_hiveCallID = 0;
	} else {
		if (EPOCH_hiveCallID > 10) then{
			EPOCH_hiveCallID = 0;
		};
		EPOCH_hiveCallID = EPOCH_hiveCallID + 1;
	};

	while {_valueLength > _charLimit} do {
		_valueLength = _valueLength - _charLimit;
		"epochserver" callExtension format["%1|%2:%3|%4|%5", _callStack, _prefix, _key, EPOCH_hiveCallID, _value select[_index, _charLimit]];
		//diag_log format["Append: %1", [_index, _callStack, _prefix, _key, _value select[_index, _charLimit]]];
		_index = _index + _charLimit;
	};

	"epochserver" callExtension format["%1|%2:%3|%4|%5|%6", _call, _prefix, _key, _expires, EPOCH_hiveCallID, _value select[_index, _charLimit]];
	//diag_log format["Large: %1", [_index, _call, _prefix, _key, _expires, _value select[_index, _charLimit]]];

} else {
	"epochserver" callExtension format["%1|%2:%3|%4|%5|%6", _call, _prefix, _key, _expires, "", _value select[_index, _charLimit]];
	//diag_log format["Small: %1", [_index, _call, _prefix, _key, _expires, _value select[_index, _charLimit]]];
};
