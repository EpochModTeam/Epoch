/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Initalizes variables and starts functions

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server/init/fn_postinit.sqf
*/
if (isNil "Epoch_SStart") then {
	Epoch_SStart = true;
	[] spawn {
		call compile preprocessFileLineNumbers "epoch_code\init\both_init.sqf";
		call compile preprocessFileLineNumbers "\epoch_server\init\server_init.sqf";
	};
};

true
