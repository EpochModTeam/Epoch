if !(isNil "Epoch_SStart1") exitWith { false };
Epoch_SStart1 = true;
diag_log "Epoch: Init Server Compiler";
"CfgServerFunctions" call EPOCH_fnc_compiler;
true
