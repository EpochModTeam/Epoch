// Random Messages
/*
_messages = [
"Message 1",
"Message 2",
"Message 3",
"Message 4",
];
["message", _messages param [floor(random (count _messages))]] call EPOCH_serverCommand;
*/

// Restart time
_restartIn = round((EPOCH_forceRestartTime-diag_tickTime)/60);
["message", format["Welcome to Epoch Mod, server wlll restart in %1 minutes",_restartIn]] call EPOCH_serverCommand;
