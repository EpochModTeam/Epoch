/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors: Aaron Clark

	Description:
	Action Menu Target Config

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_config/Configs/CfgActionMenu/CfgActionMenu_target.hpp
*/

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
	action = "[dyna_cursorTarget, true, player, Epoch_personalToken] remoteExec ['EPOCH_server_lockVehicle',2];";
	icon = "x\addons\a3_epoch_code\Data\UI\buttons\pad_cannot_lock.paa";
	tooltip = "Lock";
};
class veh_unLock
{
	condition = "dyna_isVehicle && dyna_locked";
	action = "[dyna_cursorTarget, false, player, Epoch_personalToken] remoteExec ['EPOCH_server_lockVehicle',2];";
	icon = "x\addons\a3_epoch_code\Data\UI\buttons\pad_can_unlock.paa";
	tooltip = "Unlock";
};

//Trader interaction
class tra_talk
{
	condition = "dyna_isTrader";
	action = "dyna_cursorTarget call EPOCH_startInteractNPC;";
	icon = "x\addons\a3_epoch_code\Data\UI\buttons\talk_blue.paa";
	tooltip = "Talk";
};
class tra_shop
{
	condition = "dyna_isTrader";
	action = "call EPOCH_startNPCTraderMenu;";
	icon = "x\addons\a3_epoch_code\Data\UI\buttons\krypto.paa";
	tooltip = "Shop";
};

class player_takeCrypto
{
	condition = "dyna_isDeadPlayer || (dyna_cursorTarget getVariable [""Crypto"",0]) > 0";
	action = "dyna_cursorTarget call EPOCH_takeCrypto;";
	icon = "x\addons\a3_epoch_code\Data\UI\buttons\krypto.paa";
	tooltip = "Take Krypto";
};
class player_trade
{
	condition = "dyna_isPlayer";
	action = "[dyna_cursorTarget, player, Epoch_personalToken] call EPOCH_startTRADEREQ;";
	icon = "x\addons\a3_epoch_code\Data\UI\buttons\krypto.paa";
	tooltip = "Make Trade Request";
};
class player_trade_accept
{
	condition = "dyna_isPlayer && dyna_canAcceptTrade";
	action = "EPOCH_p2ptradeTarget = EPOCH_pendingP2ptradeTarget;call EPOCH_startTrade;";
	icon = "x\addons\a3_epoch_code\Data\UI\buttons\krypto.paa";
	tooltip = "Accept Trade Request";
};

//User action replacement
class maintain_jammer
{
	condition = "dyna_cursorTargetType isEqualTo 'PlotPole_EPOCH' && (damage dyna_cursorTarget < 1)";
	action = "dyna_cursorTarget call EPOCH_maintainIT;";
	icon = "x\addons\a3_epoch_code\Data\UI\buttons\build_maintain.paa";
	tooltip = "Maintain";
};
class select_jammer
{
	condition = "dyna_cursorTargetType isEqualTo 'PlotPole_EPOCH' && (damage dyna_cursorTarget < 1)";
	action = "[dyna_cursorTarget,player,Epoch_personalToken] remoteExec [""EPOCH_server_makeSP"",2];";
	icon = "x\addons\a3_epoch_code\Data\UI\buttons\player_inspect.paa";
	tooltip = "Make Spawnpoint";
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
	action = "[dyna_cursorTarget,player,Epoch_personalToken] remoteExec ['EPOCH_server_packStorage',2];";
	icon = "x\addons\a3_epoch_code\Data\UI\buttons\build_pack.paa";
	tooltip = "Pack Lockbox";
};
class pack_safe
{
	condition = "(dyna_cursorTargetType in ['Safe_EPOCH','SafeProxy_EPOCH']) && (dyna_cursorTarget getVariable ['EPOCH_Locked',false])";
	action = "[dyna_cursorTarget,player,Epoch_personalToken] remoteExec ['EPOCH_server_packStorage',2];";
	icon = "x\addons\a3_epoch_code\Data\UI\buttons\build_pack.paa";
	tooltip = "Pack Safe";
};

class VehMaintanance
{
	condition = "dyna_isVehicle && !EPOCH_Vehicle_MaintainLock && EPOCH_AdvancedVehicleRepair_Enabled";
	action = "dyna_cursorTarget call EPOCH_client_VehicleMaintananceCheck;";
    icon = "x\addons\a3_epoch_code\Data\UI\buttons\Repair_man.paa";
	tooltip = "Vehicle Maintanance";
	class Repair
	{
		condition = "!((EPOCH_VehicleRepairs select 0) isequalto []) || !((EPOCH_VehicleRepairs select 2) isequalto [])";
		action = "";
		icon = "epoch_code\customs\Repair_Wheel.paa";
		tooltip = "Repair Vehicle";
		class RepairHull
		{
			condition = "'HitHull' in (EPOCH_VehicleRepairs select 0)";
			action = "[dyna_cursorTarget,'repair','HitHull'] spawn EPOCH_client_VehicleMaintananceDo";
			icon = "epoch_code\customs\Repair_HullBody.paa";
			tooltip = "Repair Hull";
		};
		class ReplaceHull
		{
			condition = "'HitHull' in (EPOCH_VehicleRepairs select 2)";
			action = "[dyna_cursorTarget,'replace','HitHull'] spawn EPOCH_client_VehicleMaintananceDo";
			icon = "epoch_code\customs\Replace_HullBody.paa";
			tooltip = "Repair Hull";
		};
		class RepairEngine
		{
			condition = "'HitEngine' in (EPOCH_VehicleRepairs select 0)";
			action = "[dyna_cursorTarget,'repair','HitEngine'] spawn EPOCH_client_VehicleMaintananceDo";
			icon = "epoch_code\customs\Repair_Engine.paa";
			tooltip = "Repair Engine";
		};
		class ReplaceEngine
		{
			condition = "'HitEngine' in (EPOCH_VehicleRepairs select 2)";
			action = "[dyna_cursorTarget,'replace','HitEngine'] spawn EPOCH_client_VehicleMaintananceDo";
			icon = "epoch_code\customs\Replace_Engine.paa";
			tooltip = "Replace Engine";
		};
		class ReplaceGlass
		{
			condition = "'glass' in (EPOCH_VehicleRepairs select 0) || 'glass' in (EPOCH_VehicleRepairs select 2)";
			action = "[dyna_cursorTarget,'replace','glass'] spawn EPOCH_client_VehicleMaintananceDo";
			icon = "epoch_code\customs\Replace_Glass.paa";
			tooltip = "Replace Glass";
		};
		class RepairBody
		{
			condition = "'HitBody' in (EPOCH_VehicleRepairs select 0)";
			action = "[dyna_cursorTarget,'repair','HitBody'] spawn EPOCH_client_VehicleMaintananceDo";
			icon = "epoch_code\customs\Repair_HullBody.paa";
			tooltip = "Repair Body";
		};
		class ReplaceBody
		{
			condition = "'HitBody' in (EPOCH_VehicleRepairs select 2)";
			action = "[dyna_cursorTarget,'replace','HitBody'] spawn EPOCH_client_VehicleMaintananceDo";
			icon = "epoch_code\customs\Replace_HullBody.paa";
			tooltip = "Repair Body";
		};
		class RepairFuel
		{
			condition = "'HitFuel' in (EPOCH_VehicleRepairs select 0)";
			action = "[dyna_cursorTarget,'repair','HitFuel'] spawn EPOCH_client_VehicleMaintananceDo";
			icon = "epoch_code\customs\Repair_Fuel.paa";
			tooltip = "Repair Fuel Hose";
		};
		class RepairMainRotor
		{
			condition = "'HitHRotor' in (EPOCH_VehicleRepairs select 0)";
			action = "[dyna_cursorTarget,'repair','HitHRotor'] spawn EPOCH_client_VehicleMaintananceDo";
			icon = "epoch_code\customs\Repair_MainRotor.paa";
			tooltip = "Repair Main Rotor";
		};
		class ReplaceFuel
		{
			condition = "'HitFuel' in (EPOCH_VehicleRepairs select 2)";
			action = "[dyna_cursorTarget,'replace','HitFuel'] spawn EPOCH_client_VehicleMaintananceDo";
			icon = "epoch_code\customs\Repair_Fuel.paa";
			tooltip = "Replace Fuel Hose";
		};
		class ReplaceMainRotor
		{
			condition = "'HitHRotor' in (EPOCH_VehicleRepairs select 2)";
			action = "[dyna_cursorTarget,'replace','HitHRotor'] spawn EPOCH_client_VehicleMaintananceDo";
			icon = "epoch_code\customs\Replace_MainRotor.paa";
			tooltip = "Replace Main Rotor";
		};
		class RepairTailRotor
		{
			condition = "'HitVRotor' in (EPOCH_VehicleRepairs select 0)";
			action = "[dyna_cursorTarget,'repair','HitVRotor'] spawn EPOCH_client_VehicleMaintananceDo";
			icon = "epoch_code\customs\Repair_TailRotor.paa";
			tooltip = "Repair Tail Rotor";
		};
		class ReplaceTailRotor
		{
			condition = "'HitVRotor' in (EPOCH_VehicleRepairs select 2)";
			action = "[dyna_cursorTarget,'replace','HitVRotor'] spawn EPOCH_client_VehicleMaintananceDo";
			icon = "epoch_code\customs\Replace_TailRotor.paa";
			tooltip = "Replace Tail Rotor";
		};
		class ReplaceWinch
		{
			condition = "'HitWinch' in (EPOCH_VehicleRepairs select 0) || 'HitWinch' in (EPOCH_VehicleRepairs select 2)";
			action = "[dyna_cursorTarget,'replace','HitWinch'] spawn EPOCH_client_VehicleMaintananceDo";
			icon = "epoch_code\customs\Replace_SLG.paa";
			tooltip = "Replace Winch";
		};
		class RepairTire1
		{
			condition = "'HitLFWheel' in (EPOCH_VehicleRepairs select 0)";
			action = "[dyna_cursorTarget,'repair','HitLFWheel'] spawn EPOCH_client_VehicleMaintananceDo";
			icon = "epoch_code\customs\Repair_Wheel.paa";
			tooltip = "Repair 1st Left Wheel";
		};
		class RepairTire2
		{
			condition = "'HitLF2Wheel' in (EPOCH_VehicleRepairs select 0)";
			action = "[dyna_cursorTarget,'repair','HitLF2Wheel'] spawn EPOCH_client_VehicleMaintananceDo";
			icon = "epoch_code\customs\Repair_Wheel.paa";
			tooltip = "Repair 2nd Left Wheel";
		};
		class RepairTire3
		{
			condition = "'HitLMWheel' in (EPOCH_VehicleRepairs select 0)";
			action = "[dyna_cursorTarget,'repair','HitLMWheel'] spawn EPOCH_client_VehicleMaintananceDo";
			icon = "epoch_code\customs\Repair_Wheel.paa";
			tooltip = "Repair 3rd Left Wheel";
		};
		class RepairTire4
		{
			condition = "'HitLBWheel' in (EPOCH_VehicleRepairs select 0)";
			action = "[dyna_cursorTarget,'repair','HitLBWheel'] spawn EPOCH_client_VehicleMaintananceDo";
			icon = "epoch_code\customs\Repair_Wheel.paa";
			tooltip = "Repair 4th Left Wheel";
		};
		class RepairTire5
		{
			condition = "'HitRFWheel' in (EPOCH_VehicleRepairs select 0)";
			action = "[dyna_cursorTarget,'repair','HitRFWheel'] spawn EPOCH_client_VehicleMaintananceDo";
			icon = "epoch_code\customs\Repair_Wheel.paa";
			tooltip = "Repair 1st Right Wheel";
		};
		class RepairTire6
		{
			condition = "'HitRF2Wheel' in (EPOCH_VehicleRepairs select 0)";
			action = "[dyna_cursorTarget,'repair','HitRF2Wheel'] spawn EPOCH_client_VehicleMaintananceDo";
			icon = "epoch_code\customs\Repair_Wheel.paa";
			tooltip = "Repair 2nd Right Wheel";
		};
		class RepairTire7
		{
			condition = "'HitRMWheel' in (EPOCH_VehicleRepairs select 0)";
			action = "[dyna_cursorTarget,'repair','HitRMWheel'] spawn EPOCH_client_VehicleMaintananceDo";
			icon = "epoch_code\customs\Repair_Wheel.paa";
			tooltip = "Repair 3rd Right Wheel";
		};
		class RepairTire8
		{
			condition = "'HitRBWheel' in (EPOCH_VehicleRepairs select 0)";
			action = "[dyna_cursorTarget,'repair','HitRBWheel'] spawn EPOCH_client_VehicleMaintananceDo";
			icon = "epoch_code\customs\Repair_Wheel.paa";
			tooltip = "Repair 4th Right Wheel";
		};
		class ReplaceTire1
		{
			condition = "'HitLFWheel' in (EPOCH_VehicleRepairs select 2)";
			action = "[dyna_cursorTarget,'replace','HitLFWheel'] spawn EPOCH_client_VehicleMaintananceDo";
			icon = "epoch_code\customs\Replace_Wheel.paa";
			tooltip = "Replace 1st Left Wheel";
		};
		class ReplaceTire2
		{
			condition = "'HitLF2Wheel' in (EPOCH_VehicleRepairs select 2)";
			action = "[dyna_cursorTarget,'replace','HitLF2Wheel'] spawn EPOCH_client_VehicleMaintananceDo";
			icon = "epoch_code\customs\Replace_Wheel.paa";
			tooltip = "Replace 2nd Left Wheel";
		};
		class ReplaceTire3
		{
			condition = "'HitLMWheel' in (EPOCH_VehicleRepairs select 2)";
			action = "[dyna_cursorTarget,'replace','HitLMWheel'] spawn EPOCH_client_VehicleMaintananceDo";
			icon = "epoch_code\customs\Replace_Wheel.paa";
			tooltip = "Replace 3rd Left Wheel";
		};
		class ReplaceTire4
		{
			condition = "'HitLBWheel' in (EPOCH_VehicleRepairs select 2)";
			action = "[dyna_cursorTarget,'replace','HitLBWheel'] spawn EPOCH_client_VehicleMaintananceDo";
			icon = "epoch_code\customs\Replace_Wheel.paa";
			tooltip = "Replace 4th Left Wheel";
		};
		class ReplaceTire5
		{
			condition = "'HitRFWheel' in (EPOCH_VehicleRepairs select 2)";
			action = "[dyna_cursorTarget,'replace','HitRFWheel'] spawn EPOCH_client_VehicleMaintananceDo";
			icon = "epoch_code\customs\Replace_Wheel.paa";
			tooltip = "Replace 1st Right Wheel";
		};
		class ReplaceTire6
		{
			condition = "'HitRF2Wheel' in (EPOCH_VehicleRepairs select 2)";
			action = "[dyna_cursorTarget,'replace','HitRF2Wheel'] spawn EPOCH_client_VehicleMaintananceDo";
			icon = "epoch_code\customs\Replace_Wheel.paa";
			tooltip = "Replace 2nd Right Wheel";
		};
		class ReplaceTire7
		{
			condition = "'HitRMWheel' in (EPOCH_VehicleRepairs select 2)";
			action = "[dyna_cursorTarget,'replace','HitRMWheel'] spawn EPOCH_client_VehicleMaintananceDo";
			icon = "epoch_code\customs\Replace_Wheel.paa";
			tooltip = "Replace 3rd Right Wheel";
		};
		class ReplaceTire8
		{
			condition = "'HitRBWheel' in (EPOCH_VehicleRepairs select 2)";
			action = "[dyna_cursorTarget,'replace','HitRBWheel'] spawn EPOCH_client_VehicleMaintananceDo";
			icon = "epoch_code\customs\Replace_Wheel.paa";
			tooltip = "Replace 4th Right Wheel";
		};
		class RepairAvionics
		{
			condition = "'HitAvionics' in (EPOCH_VehicleRepairs select 0) || 'HitAvionics' in (EPOCH_VehicleRepairs select 2)";
			action = "[dyna_cursorTarget,'replace','HitAvionics'] spawn EPOCH_client_VehicleMaintananceDo";
			icon = "epoch_code\customs\Repair_Avionics.paa";
			tooltip = "Repair Avionics";
		};
	};
	class Remove
	{
		condition = "!((EPOCH_VehicleRepairs select 1) isequalto [])";
		action = "";
		icon = "epoch_code\customs\Remove_Wheel.paa";
		tooltip = "Remove Parts";
		class RemoveEngine
		{
			condition = "'HitEngine' in (EPOCH_VehicleRepairs select 1)";
			action = "[dyna_cursorTarget,'remove','HitEngine'] spawn EPOCH_client_VehicleMaintananceDo";
			icon = "epoch_code\customs\Remove_Engine.paa";
			tooltip = "Remove Engine";
		};
		class RemoveTire1
		{
			condition = "'HitLFWheel' in (EPOCH_VehicleRepairs select 1)";
			action = "[dyna_cursorTarget,'remove','HitLFWheel'] spawn EPOCH_client_VehicleMaintananceDo";
			icon = "epoch_code\customs\Remove_Wheel.paa";
			tooltip = "Remove 1st Left Wheel";
		};
		class RemoveTire2
		{
			condition = "'HitLF2Wheel' in (EPOCH_VehicleRepairs select 1)";
			action = "[dyna_cursorTarget,'remove','HitLF2Wheel'] spawn EPOCH_client_VehicleMaintananceDo";
			icon = "epoch_code\customs\Remove_Wheel.paa";
			tooltip = "Remove 2nd Left Wheel";
		};
		class RemoveTire3
		{
			condition = "'HitLMWheel' in (EPOCH_VehicleRepairs select 1)";
			action = "[dyna_cursorTarget,'remove','HitLMWheel'] spawn EPOCH_client_VehicleMaintananceDo";
			icon = "epoch_code\customs\Remove_Wheel.paa";
			tooltip = "Remove 3rd Left Wheel";
		};
		class RemoveTire4
		{
			condition = "'HitLBWheel' in (EPOCH_VehicleRepairs select 1)";
			action = "[dyna_cursorTarget,'remove','HitLBWheel'] spawn EPOCH_client_VehicleMaintananceDo";
			icon = "epoch_code\customs\Remove_Wheel.paa";
			tooltip = "Remove 4th Left Wheel";
		};
		class RemoveTire5
		{
			condition = "'HitRFWheel' in (EPOCH_VehicleRepairs select 1)";
			action = "[dyna_cursorTarget,'remove','HitRFWheel'] spawn EPOCH_client_VehicleMaintananceDo";
			icon = "epoch_code\customs\Remove_Wheel.paa";
			tooltip = "Remove 1st Right Wheel";
		};
		class RemoveTire6
		{
			condition = "'HitRF2Wheel' in (EPOCH_VehicleRepairs select 1)";
			action = "[dyna_cursorTarget,'remove','HitRF2Wheel'] spawn EPOCH_client_VehicleMaintananceDo";
			icon = "epoch_code\customs\Remove_Wheel.paa";
			tooltip = "Remove 2nd Right Wheel";
		};
		class RemoveTire7
		{
			condition = "'HitRMWheel' in (EPOCH_VehicleRepairs select 1)";
			action = "[dyna_cursorTarget,'remove','HitRMWheel'] spawn EPOCH_client_VehicleMaintananceDo";
			icon = "epoch_code\customs\Remove_Wheel.paa";
			tooltip = "Remove 3rd Right Wheel";
		};
		class RemoveTire8
		{
			condition = "'HitRBWheel' in (EPOCH_VehicleRepairs select 1)";
			action = "[dyna_cursorTarget,'remove','HitRBWheel'] spawn EPOCH_client_VehicleMaintananceDo";
			icon = "epoch_code\customs\Remove_Wheel.paa";
			tooltip = "Remove 4th Right Wheel";
		};
	};
};