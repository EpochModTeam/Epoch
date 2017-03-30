/*
	Author: Aaron Clark - EpochMod.com

    Contributors: Florian Kinder

	Description:
    Hive SETEX 120 sync, 121 async

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server_core/compile/epoch_hive/fn_server_hiveSETEX.sqf
*/
params ["_prefix","_key","_expires","_value"];
"epochserver" callExtension ([121,([_prefix,_key] joinString ":"),_expires,"",_value] joinString "|")
