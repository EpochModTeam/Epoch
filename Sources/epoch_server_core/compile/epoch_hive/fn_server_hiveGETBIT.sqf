/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Hive Get Getbit

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server_core/compile/epoch_hive/fn_server_hiveGETBIT.sqf
*/

private ["_hiveResponse","_hiveMessage"];
params ["_prefix","_key","_bit"];
_hiveMessage = false;
_hiveResponse = "epochserver" callExtension format["240|%1:%2|%3", _prefix, _key, _bit];
if !(_hiveResponse isEqualTo "") then {
	_hiveResponse = parseSimpleArray _hiveResponse;
    _hiveResponse params [
        ["_status", 0],
        ["_data", "0"]
    ];
    if (_status == 1) then {
    	_hiveMessage = (_data isEqualTo "1");
    };
};
_hiveMessage
