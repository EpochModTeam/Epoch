/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Hive Get Getbit

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server_core/compile/epoch_hive/fn_server_hiveGETBIT.sqf
*/

private ["_hiveResponse","_hiveStatus","_hiveMessage"];
params ["_prefix","_key","_bit"];

_hiveMessage = false;
_hiveResponse = "epochserver" callExtension format["240|%1:%2|%3", _prefix, _key, _bit];
if (_hiveResponse != "") then {
	_hiveResponse = call compile _hiveResponse;
	if !(isNil "_hiveResponse") then {
		if (_hiveResponse isEqualType [] && !(_hiveResponse isEqualTo[])) then {
			if ((_hiveResponse select 0) == 1) then {
				_hiveMessage = ((_hiveResponse select 1) == "1");
			};
		};
	};
};
_hiveMessage
