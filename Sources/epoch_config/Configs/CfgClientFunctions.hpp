/*[[[cog from arma_config_tools import *; json_to_arma()]]]*/
/*
	@author = "Aaron Clark - https://EpochMod.com";
	@contributors[] = {"Raimonds Virtoss","Andrew Gregory"};
	@description = "Custom Epoch Client Only functions";
	@licence = "Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike";
	@github = "https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_config/Configs/CfgClientFunctions.hpp";
*/
class CfgClientFunctions
{
	version = 1;
	class A3E
	{
		tag = "EPOCH";
		file = "epoch_code\compile";
		class generic
		{
			file = "epoch_code\compile";
			class localCleanup {};
			class unitSpawnIncrease {
				customHeader = 1;
			};
			class unitSpawnDecrease {
				customHeader = 1;
			};
			class QuickTakeAll {};
			class QuickTakeLoad {};
			class effectCrypto {};
			class handleServerMessage {};
			class updateLoadingScreen {};
			class EnterBuilding {};
			class lootTrash {};
			class interact {};
			class chopWood {};
			class fish {};
			class mineRocks {};
			class UnisexCheck {};
			class PutHandler {};
			class niteLight {};
			class LootIT {};
			class supportCopter {};
			class consumeItem {};
			class unitSpawn {
				customHeader = 1;
			};
			class onEachFrame {};
			class callSapperMigration {};
			class zombieSpawn {};
			class makeMarker {};
			class removeMarker {};
			class unit_onKilledEH {};
		};
		class building
		{
			class maintainIT {};
			class lockCheck {};
			class countdown {};
			class fnc_SelectTargetBuild {};
			class isBuildAllowed {};
			class simulSwap {
				customHeader = 1;
			};
			class staticMove {
				customHeader = 1;
			};
			class upgradeBUILD {};
			class removeBUILD {};
			class changeWallState {};
			class checkBuild {};
		};
		class traders
		{
			class NpcTrade_return {};
			class startInteract {};
			class startInteractNPC {};
			class npcTraderAdd {};
			class npcTraderAdd2 {};
			class npcTraderAdd3 {};
			class startNPCTraderMenu {};
			class NPCTraderMenuFilter {};
			class startNpcTrade {};
			class tradeFilter {};
			class takeCrypto {};
			class startBankTransfer {};
			class calcDamageCost {};
		};
		class interface_event_handlers
		{
			class KeyDown {
				customHeader = 1;
			};
			class KeyUp {};
			class onChar {};
		};
		class event_handlers
		{
			class getInMan {};
			class getOutMan {};
			class InventoryClosed {};
			class InventoryOpened {};
		};
		class setup
		{
			class masterLoop {
				customHeader = 1;
			};
			class clientInit {};
			class clientRespawn {};
			class clientRevive {
				customHeader = 1;
			};
			class client_rejectPlayer {};
			class clientKeyMap {};
		};
		class p2p_trading
		{
			class startTRADEREQ {};
			class startTrade {};
			class tradeRequest {};
			class TradeLoop {};
			class makep2pTrade {};
		};
		class functions
		{
			class worldObjectType {};
			class returnConfig {};
			class returnConfigV2 {};
			class colorRange {};
			class convertTemp {};
			class fnc_playerDeath {
				customHeader = 1;
			};
			class fnc_playerFired {
				customHeader = 1;
			};
			class fnc_isInsideBuilding {};
			class fnc_findSafePos {};
			class fnc_addItemOverflow {};
			class fnc_addMagazineOverflow {};
			class itemData {};
			class itemPicture {};
			class itemDisplayName {};
			class SortArrayByDistance {};
			class fnc_findRandomPosBehind {};
			class fnc_stringLeft {};
			class fnc_findSapperStalkLocation {};
			class fnc_dirToFuzzy {};
			class fnc_cursorTarget {};
			class fnc_returnHudVar {
				customHeader = 1;
			};
			class fnc_triggerAntagonist {};
			class fnc_playerDeathDetonate {};
			class fnc_playerDeathMorph {};
			class fnc_playerSetVariable {};
			class fnc_playerAttachToAntagonist {};
			class fnc_dynamicFSM {};
			class fnc_vectorDivide {};
			class giveAttributes {
				customHeader = 1;
			};
			class fnc_spawnEffects {};
			class fnc_arrayStringToBool {};
			class client_updatePlayerStat {};
			class fnc_getHitPointsDamageAverage {};
			class fnc_setVariableLimited {};
			class fnc_createLocalMarkerSet {};
			class fnc_deleteLocalMarkerSet {};
		};
		class environment
		{
			class client_earthQuake {};
			class client_loadAnimalBrain {};
			class client_bitePlayer {
				customHeader = 1;
			};
		};
		class vehicles
		{
			class client_repairVehicle {};
			class client_lockVehicle {};
			class client_fillVehicle {};
			class client_gearVehicle {};
			class client_upgradeVehicle {};
			class client_upgradeVehicleCheck {};
			class client_VehicleMaintananceCheck {};
			class client_VehicleMaintananceDo {};
			class vehicle_checkTurretAmmo {};
			class vehicle_removeTurretAmmo {};
		};
		class missions
		{
			class mission_accept {};
			class mission_cage_sapper {};
			class mission_returnObj {};
		};
		class inventory
		{
			class selectInventoryItem {};
			class itemInteractClick {};
			class itemInteractDblClick {};
			class uniformArmorCalc {};
			class gearArmorCalc {};
			class factorArmor {};
			class maxArmorInit {};
			class initUI {};
			class refeshUI {};
			class equip {};
			class itemTypeSlot {};
		};
		class servicepoint
		{
			class SP_Check {};
			class SP_Rearm {};
			class SP_Refuel {};
			class SP_Repair {};
			class SP_Start {};
		};
		class customs
		{
			file = "epoch_code\customs";
			class custom_EH_FiredMan {};
			class custom_EH_GetInMan {};
			class custom_EH_GetOutMan {};
			class custom_EH_InventoryClosed {};
			class custom_EH_InventoryOpened {};
			class custom_EH_KeyDown {};
			class custom_EH_KeyUp {};
			class custom_EH_Killed {};
			class custom_EH_Put {};
			class custom_EH_Take {};
			class custom_KeyMap {};
			class custom_OnEachFrame {};
			class custom_radioActions {};
		};
		class messaging
		{
			file = "epoch_code\gui\scripts\messaging";
			class message {};
			class message_old1 {};
			class message_old2 {};
		};
		class looting
		{
			class spawnLoot {};
		};
		class gui
		{
			file = "epoch_code\gui\scripts";
			class onPause {};
			class showStats {};
			class 3DctrlPitchYaw {};
			class 3DctrlSpin {};
			class 3DctrlYaw {};
			class InterruptConfig {};
			class InterruptConfigActions {};
			class getIDC {};
			class guiObjHP {};
			class secureStorageHandler {};
			class genderSelection {};
			class getColorScheme {};
			class dragControl {};
		};
		class animations
		{
			file = "epoch_code\gui\scripts\animations";
			class 2DCtrlShake {};
			class 2DCtrlHeartbeat {};
		};
		class config
		{
			file = "epoch_code\gui\scripts\config";
			class config_keymap {};
		};
		class dynamenu
		{
			file = "epoch_code\gui\scripts\dynamenu";
			class dynamicMenu {};
			class dynamicMenuPopulate {};
			class dynamicMenuCleanup {};
		};
		class dynamicHUD
		{
			file = "epoch_code\gui\scripts\dynamicHUD";
			class dynamicHUD_adjust {};
			class dynamicHUD_loadSave {};
			class dynamicHUD_start {};
			class getHUDCtrl {};
		};
		class gui_craft
		{
			file = "epoch_code\gui\scripts\craftingv2";
			class crafting_animate {};
			class crafting_ctrl_collector {};
			class crafting_dev_toggle {};
			class crafting_getConfig {};
			class crafting_checkGear {};
			class crafting_checkNearby {};
			class crafting_checkResources {};
			class crafting_craft {};
			class crafting_progress {};
			class crafting_load {};
			class crafting_unload {};
			class crafting_LB_click {};
			class crafting_LB_defaults {};
			class crafting_LB_doubleClick {};
			class crafting_colorScheme {};
		};
		class group
		{
			file = "epoch_code\gui\scripts\group";
			class Group_invitePlayer {};
			class Group_BtnMod {};
			class Group_BtnInvite {};
			class Group_onLoad {};
			class Group_List {};
			class Group_Combo {};
			class Group_BtnLeave {};
			class Group_BtnKick {};
			class cGroup_groupText {};
			class cGroup_onLoad {};
			class cGroup_BtnCreate {};
			class iGroup_acceptInvite {};
			class iGroup_onLoad {};
			class iGroup_refresh {};
			class Group_update {};
		};
		 class groupTemp
        {
            file = "epoch_code\gui\scripts\groupTemp";
			class tempGroup_invitePlayer {};
            class tempGroup_BtnMod {};
            class tempGroup_BtnInvite {};
            class tempGroup_onLoad {};
            class tempGroup_List {};
            class tempGroup_Combo {};
            class tempGroup_BtnLeave {};
            class tempGroup_BtnKick {};
            class cTempGroup_onLoad {};
            class cTempGroup_BtnCreate {};
            class iTempGroup_acceptInvite {};
            class iTempGroup_onLoad {};
            class iTempGroup_refresh {};
            class tempGroup_update {};
		};
		class gui_inventory
		{
			file = "epoch_code\gui\scripts\inventory";
			class Inventory_Group {};
			class Inventory_iGroup {};
			class Inventory_tempGroup {};
            class Inventory_itempGroup {};
		};
		class gui_missions
		{
			file = "epoch_code\gui\scripts\missions";
			class mission_refresh {};
			class mission_description {};
		};
		class gui_postProcessing
		{
			file = "epoch_code\gui\scripts\post_process";
			class postprocessCreate {};
			class postprocessAdjust {};
			class postprocessDestroy {};
			class setDrunk {};
			class setRadiation {};
		};
		class worldToScreen
		{
			file = "epoch_code\gui\scripts\worldToScreen";
			class gui3DCooldown {};
			class gui3DCooldownEH {};
			class gui3DWorldPos {};
			class gui3DWorldPosEH {};
			class gui3DModelPos {};
			class gui3DModelPosEH {};
		};
		class favBar {
			file = "epoch_code\gui\scripts\favBar";
			class favBar_draw {};
			class favBar_drawCurrent {};
			class favBar_refresh {};
			class favBar_action{};
			class favBar_getItemByIDC {};
			class favBar_inventory {};
			class favBar_getGearItem {};
			class favBar_modifier {};
		};
		class geiger {
			file = "epoch_code\gui\scripts\geiger";
			class geiger_animate {};
			class geiger_show_hide {};
			class geiger_simulate {};
		};
	};
};

/*[[[end]]]*/
