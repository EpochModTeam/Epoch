/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Hive SETBit

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server_core/compile/epoch_hive/fn_server_hiveSETBIT.sqf
*/
private ["_prefix","_key","_value","_bitIndex"];

_prefix = _this select 0;
_key = _this select 1;
_bitIndex = _this select 2;
_value = _this select 3;

"epochserver" callExtension format["141|%1:%2|%3|%4", _prefix, _key, _bitIndex, _value];
