/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Initalize both init and run custom client function compiler

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/init/fn_init.sqf
*/
if !(isNil "Epoch_CStart") exitWith { false };
Epoch_CStart = true;
if (!isDedicated && hasInterface) then {
	call compile preprocessFileLineNumbers "epoch_code\init\both_init.sqf";
	// Epoch Client Only function compiler
	"CfgClientFunctions" call EPOCH_fnc_compiler;
};
true
