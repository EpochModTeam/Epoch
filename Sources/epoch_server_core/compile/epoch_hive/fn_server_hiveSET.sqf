/*
	Author: Aaron Clark - EpochMod.com

    Contributors: Florian Kinder

	Description:
	Hive SET 110 sync, 111 async

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server_core/compile/epoch_hive/fn_server_hiveSET.sqf
*/
params ["_prefix","_key","_value"];
"epochserver" callExtension ([111,([_prefix,_key] joinString ":"),"",_value] joinString "|")
