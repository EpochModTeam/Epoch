private ["_target"];
_target = _this select 0;
if (!isNull _target) then {
	switch (_this select 1) do {
		case "UAV": {
			"I_UAV_01_F" remoteExec ['EPOCH_unitSpawnIncrease',(owner _target)];
		};
		case "Cloak": {
			if (sunOrMoon < 1) then {
				"Epoch_Cloak_F" remoteExec ['EPOCH_unitSpawnIncrease',(owner _target)];
			} else {
				"Epoch_Sapper_F" remoteExec ['EPOCH_unitSpawnIncrease',(owner _target)];
			};
		};
		case "Sapper": {
			"Epoch_Sapper_F" remoteExec ['EPOCH_unitSpawnIncrease',(owner _target)];
		};
		case "GreatWhite": {
			"GreatWhite_F" remoteExec ['EPOCH_unitSpawnIncrease',(owner _target)];
		};
		case "SapperB": {
			"Epoch_SapperB_F" remoteExec ['EPOCH_unitSpawnIncrease',(owner _target)];
		};
		case "PHANTOM": {
			"PHANTOM" remoteExec ['EPOCH_unitSpawnIncrease',(owner _target)];
		};
	};
};
