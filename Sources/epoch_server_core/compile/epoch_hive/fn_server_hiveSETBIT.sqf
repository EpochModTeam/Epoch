/*
    Hive SETBit
    by Aaron Clark - EpochMod.com

    This work is licensed under a Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
    http://creativecommons.org/licenses/by-nc-nd/4.0/

    Improvements and or bugfixes and other contributions are welcome via the github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server_core/compile/epoch_hive/fn_server_hiveSETBIT.sqf
*/

private ["_prefix","_key","_value","_bitIndex"];

_prefix = _this select 0;
_key = _this select 1;
_bitIndex = _this select 2;
_value = _this select 3;

"epochserver" callExtension format["141|%1:%2|%3|%4", _prefix, _key, _bitIndex, _value];
