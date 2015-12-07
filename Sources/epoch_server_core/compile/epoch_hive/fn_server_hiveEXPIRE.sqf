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
private ["_prefix","_key","_expires","_call"];
_prefix = _this select 0;
_key = _this select 1;
_expires = _this select 2;

_call = 131;
if !(EPOCH_hiveAsync) then {
	_call = 130;
};

"epochserver" callExtension format ["%1|%2:%3|%4", _call, _prefix, _key, _expires];
