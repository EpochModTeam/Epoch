if (isNil "Epoch_SStart") then {
	Epoch_SStart = true;
	[] spawn {
		call compile preprocessFileLineNumbers "\x\addons\a3_epoch_code\init\both_init.sqf";
		call compile preprocessFileLineNumbers "\x\addons\a3_epoch_server\init\server_init.sqf";
	};
};

true