/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Trigger antagonists

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server/compile/epoch_antagonists/EPOCH_server_triggerEvent.sqf
*/
params ["_target", "_type"];
if (!isNull _target) then {
	switch (_type) do {
		case "UAV": {
			"I_UAV_01_F" remoteExec ['EPOCH_unitSpawnIncrease',_target];
		};
		case "Cloak": {
			if (sunOrMoon < 1) then {
				"Epoch_Cloak_F" remoteExec ['EPOCH_unitSpawnIncrease',_target];
			} else {
				"Epoch_Sapper_F" remoteExec ['EPOCH_unitSpawnIncrease',_target];
			};
		};
		case "Sapper": {
			"Epoch_Sapper_F" remoteExec ['EPOCH_unitSpawnIncrease',_target];
		};
		case "GreatWhite": {
			"GreatWhite_F" remoteExec ['EPOCH_unitSpawnIncrease',_target];
		};
		case "SapperB": {
			"Epoch_SapperB_F" remoteExec ['EPOCH_unitSpawnIncrease',_target];
		};
		case "PHANTOM": {
			"PHANTOM" remoteExec ['EPOCH_unitSpawnIncrease',_target];
		};
		case "EPOCH_RyanZombie_1": {
			"EPOCH_RyanZombie_1" remoteExec ['EPOCH_unitSpawnIncrease',_target];
		};
	};
};
