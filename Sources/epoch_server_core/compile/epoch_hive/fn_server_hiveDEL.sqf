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
//_PREFIX = _this select 0;
//_KEY = _this select 1;
"epochserver" callExtension format["400|%1:%2", _this select 0, _this select 1];
