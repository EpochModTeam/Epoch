/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description: md5 hash function
    Returns md5 hash if only one string is give as imput.
	Returns array of md5 hashes if input was an array.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server_core/compile/epoch_hive/fn_server_hiveMD5.sqf
*/
params ["_val"];
if (_this isEqualType []) then {
    _val = _this joinString "|";
    parseSimpleArray ("epochserver" callExtension ([840,_val] joinString "|"));
} else {
    (parseSimpleArray ("epochserver" callExtension ([840,_val] joinString "|"))) select 0;
}
