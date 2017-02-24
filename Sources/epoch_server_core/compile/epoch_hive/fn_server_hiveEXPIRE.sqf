/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Hive Expire 130 sync, 131 async

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server_core/compile/epoch_hive/fn_server_hiveEXPIRE.sqf
*/
params ["_prefix","_key","_expires"];
"epochserver" callExtension format ["%1|%2:%3|%4", 131, _prefix, _key, _expires];
