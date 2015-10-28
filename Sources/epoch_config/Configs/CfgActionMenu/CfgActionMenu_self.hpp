class veh_lock
{
	condition = "dyna_inVehicle && !dyna_lockedInVehicle";
	action = "EPOCH_lockVehicle_PVS = [vehicle player, true, player, Epoch_personalToken]; publicVariableServer 'EPOCH_lockVehicle_PVS';";
	icon = "x\addons\a3_epoch_code\Data\UI\buttons\pad_cannot_lock.paa";
	tooltip = "Lock";
};
class veh_unLock
{
	condition = "dyna_inVehicle && dyna_lockedInVehicle";
	action = "EPOCH_lockVehicle_PVS = [vehicle player, false, player, Epoch_personalToken]; publicVariableServer 'EPOCH_lockVehicle_PVS';";
	icon = "x\addons\a3_epoch_code\Data\UI\buttons\pad_can_unlock.paa";
	tooltip = "Unlock";
};
class player_inspect
{
	condition = "true";
	action = "hint 'Detective is on the case'";
	icon = "x\addons\a3_epoch_code\Data\UI\buttons\player_inspect.paa";
	tooltip = "Examine";
};