/*
    Author: Aaron Clark - EpochMod.com

    Contributors:

    Description: md5 hash function
    Returns md5 hash if only one string is given as input.
    Returns array of md5 hashes if input was an array.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server_core/compile/epoch_hive/fn_server_hiveMD5.sqf

    Usage Examples:
    _hash = "Hello World" call EPOCH_fnc_server_hiveMD5;
    // _hash = "b10a8db164e0754105b7a99be72e3fe5"
    or multiple:
    _hashes = ["Hello World","Lorem Ipsum"] call EPOCH_fnc_server_hiveMD5;
    // _hashes = ["b10a8db164e0754105b7a99be72e3fe5", "6dbd01b4309de2c22b027eb35a3ce18b"]

*/
params ["_val"];
if (_this isEqualType []) then {
    _val = _this joinString "|";
    parseSimpleArray ("epochserver" callExtension ([840,_val] joinString "|"));
} else {
    (parseSimpleArray ("epochserver" callExtension ([840,_val] joinString "|"))) select 0;
}
