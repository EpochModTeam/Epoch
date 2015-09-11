/*
    Hive Delete by Key
    by Aaron Clark - EpochMod.com

    This work is licensed under a Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
    http://creativecommons.org/licenses/by-nc-nd/4.0/

    Improvements and or bugfixes and other contributions are welcome via the github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server_core/compile/epoch_hive/fn_server_hiveDEL.sqf
*/
//_PREFIX = _this select 0;
//_KEY = _this select 1;
"epochserver" callExtension format["400|%1:%2", _this select 0, _this select 1];
