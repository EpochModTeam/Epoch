
if !(isNil "Epoch_SStart1") exitWith { false };
Epoch_SStart1 = true;

diag_log "Epoch: Init Compiles";
call compile preprocessFileLineNumbers "\x\addons\a3_epoch_server\init\server_compiles.sqf";

true
