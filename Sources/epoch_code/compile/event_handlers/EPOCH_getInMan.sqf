/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Get In handler for A3 Epoch

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/EPOCH_getInMan_EH.sqf
*/
params ["_unit","_position","_vehicle"];
call EPOCH_niteLight;
if (_unit == player) then {
	// Disable build mode
	if (EPOCH_buildMode > 0) then {
		EPOCH_buildMode = 0;
		EPOCH_snapDirection = 0;
		["BUILD MODE: DISABLED", 5] call Epoch_message;
		EPOCH_Target = objNull;
	};
	if (missionnamespace getvariable ["EPOCH_AutoEarplug",false]) then {
		systemchat 'Earplugs have been auto-inserted...';
		EPOCH_Earplugsin = true;
		1 fadeSound 0.15;
	};
};
