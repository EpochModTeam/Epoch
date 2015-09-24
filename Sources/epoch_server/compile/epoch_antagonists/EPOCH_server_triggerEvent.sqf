private ["_target"];
_target = _this select 0;
if (!isNull _target) then {
	switch (_this select 1) do {
		case "UAV": {
			[["unitSpawn", "I_UAV_01_F"], (owner _target)] call EPOCH_sendPublicVariableClient;
		};
		case "Cloak": {
			if (sunOrMoon < 1) then {
				[["unitSpawn", "Epoch_Cloak_F"], (owner _target)] call EPOCH_sendPublicVariableClient;
			} else {
				[["unitSpawn", "Epoch_Sapper_F"], (owner _target)] call EPOCH_sendPublicVariableClient;
			};
		};
		case "Sapper": {
			[["unitSpawn", "Epoch_Sapper_F"], (owner _target)] call EPOCH_sendPublicVariableClient;
		};
		case "GreatWhite": {
			[["unitSpawn", "GreatWhite_F"], (owner _target)] call EPOCH_sendPublicVariableClient;
		};
		case "SapperB": {
			[["unitSpawn", "Epoch_SapperB_F"], (owner _target)] call EPOCH_sendPublicVariableClient;
		};
		case "PHANTOM": {
			[["unitSpawn", "PHANTOM"], (owner _target)] call EPOCH_sendPublicVariableClient;
		};
	};
};
