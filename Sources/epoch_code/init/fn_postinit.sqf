/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Initalize Player

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/init/fn_postinit.sqf
*/
if (!isDedicated && isMultiplayer && hasInterface) then {
	call compile preprocessFileLineNumbers "epoch_code\init\client_init.sqf";
};
true
