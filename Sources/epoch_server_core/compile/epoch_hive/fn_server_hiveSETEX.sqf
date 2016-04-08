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
params ["_prefix","_key","_expires","_value"];

_value       = str (_value);
_valueLength = count _value;

_callStack = [100,101] select EPOCH_hiveAsync;
_call = [120,121] select EPOCH_hiveAsync;

_index = 0;
_charLimit = 8000;

if (_valueLength > _charLimit) then{

	if (isNil "EPOCH_hiveCallID") then{
		EPOCH_hiveCallID = 0;
	} else {
		if (EPOCH_hiveCallID > 1000) then{
			EPOCH_hiveCallID = 0;
		};
		EPOCH_hiveCallID = EPOCH_hiveCallID + 1;
	};

	while {_valueLength > _charLimit} do {
		_valueLength = _valueLength - _charLimit;
		"epochserver" callExtension format["%1|%2:%3|%4|%5", _callStack, _prefix, _key, EPOCH_hiveCallID, _value select[_index, _charLimit]];
		_index = _index + _charLimit;
	};

	"epochserver" callExtension format["%1|%2:%3|%4|%5|%6", _call, _prefix, _key, _expires, EPOCH_hiveCallID, _value select[_index, _charLimit]];

} else {
	"epochserver" callExtension format["%1|%2:%3|%4|%5|%6", _call, _prefix, _key, _expires, "", _value select[_index, _charLimit]];
};
