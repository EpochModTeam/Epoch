// runs every 0.4 seconds

if (EPOCH_IsAutoRunning) then {
	if (call EPOCH_AutoRun_Check) then {
		call EPOCH_AutoRun
	}
	else {
			EPOCH_IsAutoRunning = false;
			player switchMove "";
			["Autorun stopped",5] call Epoch_Message;
	};
};