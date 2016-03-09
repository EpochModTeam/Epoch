/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Starts epoch function compiler Server side

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server/init/fn_init.sqf
*/
if !(isNil "Epoch_SStart1") exitWith { false };
Epoch_SStart1 = true;
diag_log "Epoch: Init Server Compiler";
"CfgServerFunctions" call EPOCH_fnc_compiler;
true
