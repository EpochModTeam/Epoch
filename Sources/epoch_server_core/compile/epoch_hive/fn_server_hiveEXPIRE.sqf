/*
    Hive Expire
    by Aaron Clark - EpochMod.com

    This work is licensed under a Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
    http://creativecommons.org/licenses/by-nc-nd/4.0/

    Improvements and or bugfixes and other contributions are welcome via the github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server_core/compile/epoch_hive/fn_server_hiveEXPIRE.sqf
*/
private ["_prefix","_key","_expires","_call"];
_prefix = _this select 0;
_key = _this select 1;
_expires = _this select 2;

_call = 131;
if !(EPOCH_hiveAsync) then {
	_call = 130;
};

"epochserver" callExtension format ["%1|%2:%3|%4", _call, _prefix, _key, _expires];
