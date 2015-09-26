_restartIn = round((EPOCH_forceRestartTime-diag_tickTime)/60);
["message", format["Welcome to Epoch Mod, server wlll restart in %1 minutes",_restartIn]] call EPOCH_serverCommand;
