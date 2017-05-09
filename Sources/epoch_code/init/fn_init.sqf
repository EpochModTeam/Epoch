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
if !(isNil "Epoch_Survival_Started") exitWith { false };
Epoch_Survival_Started = true;

private _selectedFunction = "CfgClientFunctions";
if (isDedicated) then {
	// dedicated server
	_selectedFunction = "CfgServerFunctions";
	call compile preprocessFileLineNumbers "epoch_code\init\both_init.sqf";
} else {
	if (hasInterface) then {
		// all players
		call compile preprocessFileLineNumbers "epoch_code\init\both_init.sqf";
		if (isServer) then {
			// listen server host
			_selectedFunction = "CfgEpochListenServerFunctions";
		} else {
			// all players
			_selectedFunction = "CfgClientFunctions";
		};
	} else {
		// Headless Clients
		_selectedFunction = "CfgEpochClientHCFunctions";
	};
};
diag_log format["Loading Functions: %1",_selectedFunction];
_selectedFunction call EPOCH_fnc_compiler;
true
