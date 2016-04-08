/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Hive Expire

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server_core/compile/epoch_hive/fn_server_hiveEXPIRE.sqf
*/
private ["_call"];
params ["_prefix","_key","_expires"];
_call = [130,131] select EPOCH_hiveAsync;
"epochserver" callExtension format ["%1|%2:%3|%4", _call, _prefix, _key, _expires];
