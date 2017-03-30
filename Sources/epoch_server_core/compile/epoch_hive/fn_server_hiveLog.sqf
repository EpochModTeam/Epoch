/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Hive Log

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server_core/compile/epoch_hive/fn_server_hiveLog.sqf
*/
params ["_prefix","_val"];
"epochserver" callExtension ([701, _prefix, _val] joinString "|")
