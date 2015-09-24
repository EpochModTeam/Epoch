_this addMPEventHandler["MPKilled", { _this call EPOCH_server_save_killedVehicle }];
_this addMPEventHandler["MPHit", { if !((_this select 0) in EPOCH_saveVehQueue) then { EPOCH_saveVehQueue pushBack(_this select 0) } }];
_this addEventHandler["Local", { if !((_this select 0) in EPOCH_saveVehQueue) then { EPOCH_saveVehQueue pushBack(_this select 0) } }];
_this addEventHandler["GetOut", { if !((_this select 0) in EPOCH_saveVehQueue) then { EPOCH_saveVehQueue pushBack(_this select 0) } }];