/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Hive Delete by Key

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server_core/compile/epoch_hive/fn_server_hiveDEL.sqf
*/
params ["_prefix","_key"];
"epochserver" callExtension format["400|%1:%2", _prefix, _key];
