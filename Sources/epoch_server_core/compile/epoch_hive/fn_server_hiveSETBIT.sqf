/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Hive SETBit

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server_core/compile/epoch_hive/fn_server_hiveSETBIT.sqf
*/
params ["_prefix","_key","_bitIndex","_value"];
"epochserver" callExtension format["141|%1:%2|%3|%4", _prefix, _key, _bitIndex, _value];
