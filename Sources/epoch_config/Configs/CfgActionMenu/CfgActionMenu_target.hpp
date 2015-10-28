//Build mode enabled
class build_upgrade
{
	condition = "dyna_buildMode select 0";
	//action = "dyna_cursorTarget call EPOCH_QuickUpgrade;"; //TODO: scripted dyna menu
	action = "";
	icon = "x\addons\a3_epoch_code\Data\UI\buttons\build_upgrade.paa";
	tooltip = "Upgrade";
	class special {}; //uses external config, hardcoded
};
class build_remove
{
	condition = "dyna_buildMode select 1";
	action = "dyna_cursorTarget call EPOCH_removeBUILD;";
	icon = "x\addons\a3_epoch_code\Data\UI\buttons\build_remove.paa";
	tooltip = "Remove";
};
class build_move
{
	condition = "dyna_buildMode select 2";
	action = "dyna_cursorTarget call EPOCH_fnc_SelectTargetBuild;";
	icon = "x\addons\a3_epoch_code\Data\UI\buttons\build_move.paa";
	tooltip = "Move";
};

//Vehicle interaction
class veh_gear
{
	condition = "dyna_isVehicle && !dyna_locked";
	action = "call Epoch_client_gearVehicle;";
	icon = "x\addons\a3_epoch_code\Data\UI\buttons\player_inspect.paa";
	tooltip = "Inspect";
};
class veh_lock
{
	condition = "dyna_isVehicle && !dyna_locked";
	action = "EPOCH_lockVehicle_PVS = [dyna_cursorTarget, true, player, Epoch_personalToken]; publicVariableServer 'EPOCH_lockVehicle_PVS';";
	icon = "x\addons\a3_epoch_code\Data\UI\buttons\pad_cannot_lock.paa";
	tooltip = "Lock";
};
class veh_unLock
{
	condition = "dyna_isVehicle && dyna_locked";
	action = "EPOCH_lockVehicle_PVS = [dyna_cursorTarget, false, player, Epoch_personalToken]; publicVariableServer 'EPOCH_lockVehicle_PVS';";
	icon = "x\addons\a3_epoch_code\Data\UI\buttons\pad_can_unlock.paa";
	tooltip = "Unlock";
};

//Trader interaction
class tra_talk
{
	condition = "dyna_isTrader";
	action = "dyna_cursorTarget call EPOCH_startInteractNPC;";
	icon = "x\addons\a3_epoch_code\Data\UI\buttons\talk_green.paa";
	tooltip = "Talk";
};
class tra_shop
{
	condition = "dyna_isTrader";
	action = "call EPOCH_startNPCTraderMenu;";
	icon = "x\addons\a3_epoch_code\Data\UI\buttons\krypto.paa";
	tooltip = "Shop";
};

//User action replacement
class maintain_jammer
{
	condition = "dyna_cursorTargetType isEqualTo 'PlotPole_EPOCH' && (damage dyna_cursorTarget < 1)";
	action = "dyna_cursorTarget call EPOCH_maintainIT;";
	icon = "x\addons\a3_epoch_code\Data\UI\buttons\build_maintain.paa";
	tooltip = "Maintain";
};
//lock unlock
class unlock_lockbox
{
	condition = "(dyna_cursorTargetType in ['LockBox_EPOCH','LockBoxProxy_EPOCH']) && (dyna_cursorTarget getVariable ['EPOCH_Locked',false])";
	action = "dyna_cursorTarget call Epoch_secureStorageHandler";
	icon = "x\addons\a3_epoch_code\Data\UI\buttons\pad_can_unlock.paa";
	tooltip = "Unlock Lockbox";
};
class lock_lockbox
{
	condition = "(dyna_cursorTargetType in ['LockBox_EPOCH','LockBoxProxy_EPOCH']) && !(dyna_cursorTarget getVariable ['EPOCH_Locked',false])";
	action = "dyna_cursorTarget call Epoch_secureStorageHandler";
	icon = "x\addons\a3_epoch_code\Data\UI\buttons\pad_cannot_lock.paa";
	tooltip = "Lock Lockbox";
};
class unlock_safe
{
	condition = "(dyna_cursorTargetType in ['Safe_EPOCH','SafeProxy_EPOCH']) && (dyna_cursorTarget getVariable ['EPOCH_Locked',false])";
	action = "dyna_cursorTarget call Epoch_secureStorageHandler";
	icon = "x\addons\a3_epoch_code\Data\UI\buttons\pad_can_unlock.paa";
	tooltip = "Unlock Safe";
};
class lock_safe
{
	condition = "(dyna_cursorTargetType in ['Safe_EPOCH','SafeProxy_EPOCH']) && !(dyna_cursorTarget getVariable ['EPOCH_Locked',false])";
	action = "dyna_cursorTarget call Epoch_secureStorageHandler";
	icon = "x\addons\a3_epoch_code\Data\UI\buttons\pad_cannot_lock.paa";
	tooltip = "Lock Safe";
};

//pack
class pack_lockbox
{
	condition = "(dyna_cursorTargetType in ['LockBox_EPOCH','LockBoxProxy_EPOCH']) && (dyna_cursorTarget getVariable ['EPOCH_Locked',false])";
	action = "EPOCH_packStorage_PVS = [dyna_cursorTarget,player,Epoch_personalToken]; publicVariableServer 'EPOCH_packStorage_PVS';";
	icon = "#(rgb,8,8,3)color(1,0,1,0.5)";
	tooltip = "Pack Lockbox";
};
class pack_safe
{
	condition = "(dyna_cursorTargetType in ['Safe_EPOCH','SafeProxy_EPOCH']) && (dyna_cursorTarget getVariable ['EPOCH_Locked',false])";
	action = "EPOCH_packStorage_PVS = [dyna_cursorTarget,player,Epoch_personalToken]; publicVariableServer 'EPOCH_packStorage_PVS';";
	icon = "#(rgb,8,8,3)color(1,0,1,0.5)";
	tooltip = "Pack Safe";
};