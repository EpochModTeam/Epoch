call EPOCH_clientInit;
[] spawn EPOCH_masterLoop;
[5,100] call EPOCH_niteLight;

Epoch_canBeRevived = true;

[] execFSM "\x\addons\a3_epoch_code\system\gender_selection.fsm";


true
