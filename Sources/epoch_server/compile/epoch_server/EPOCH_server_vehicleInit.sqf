_this addMPEventHandler["MPKilled", { _this call EPOCH_server_save_killedVehicle }];
_this addMPEventHandler["MPHit", { EPOCH_saveVehQueue pushBackUnique (_this select 0) }];
_this addEventHandler["Local", { EPOCH_saveVehQueue pushBackUnique (_this select 0) }];
_this addEventHandler["GetOut", { EPOCH_saveVehQueue pushBackUnique (_this select 0) }];
