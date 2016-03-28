class CfgClientFunctions
{
	version = 1;
	class A3E
	{
		tag = "EPOCH";
		file = "epoch_code\compile";

		class generic {
			file = "epoch_code\compile";
			class localCleanup {};
			class unitSpawnIncrease {};
			class unitSpawnDecrease {};
			class QuickTakeAll {};
			class QuickTakeLoad {};
			class effectCrypto {};
			class handleServerMessage {};
			class updateLoadingScreen {};
			class EnterBuilding {};
			class lootTrash {};
			class debugMonitor {};
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
			class unitSpawn {};
			class antiWall {};
			class onEachFrame {};
		};

		class building
		{
			class maintainIT {};
			class lockCheck {};
			class countdown {};
			class fnc_SelectTargetBuild {};
			class isBuildAllowed {};
			class simulSwap {};
			class staticMove {};
			class upgradeBUILD {};
			class removeBUILD {};
			class changeWallState {};
			class checkBuild {};
		};

		class traders
		{
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
		};

		class interface_event_handlers
		{
			class KeyDown {};
			class KeyUp {};
			class onChar {};
		};

		class setup
		{
			class client_publicEH {};
			class masterLoop {};
			class clientInit {};
			class clientRespawn {};
			class clientRevive {};
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
			class colorRange {};
			class convertTemp {};
			class fnc_playerDeath {};
			class fnc_playerFired {};
			class fnc_isInsideBuilding {};
			class fnc_Weather {};
			class fnc_findSafePos {};
			class fnc_addItemOverflow {};
			class pushCustomVar {};
			class itemData {};
			class itemPicture {};
			class itemDisplayName {};
			class SortArrayByDistance {};
			class fnc_findRandomPosBehind {};
			class fnc_stringLeft {};
			class fnc_findSapperStalkLocation {};
			class fnc_dirToFuzzy {};
			class fnc_cursorTarget {};
		};
		class environment
		{
			class client_earthQuake {};
			class client_loadAnimalBrain {};
			class client_bitePlayer {};
		};
		class vehicles
		{
			class client_repairVehicle {};
			class client_lockVehicle {};
			class client_fillVehicle {};
			class client_gearVehicle {};
		};
		class missions
		{
			class mission_accept {};
			class mission_cage_sapper {};
			class mission_returnObj {};
		};
		class inventory {
			class selectInventoryItem {};
			class itemInteractClick {};
			class itemInteractDblClick {};
			class uniformArmorCalc {};
			class gearArmorCalc {};
			class factorArmor {};
			class maxArmorInit {};
			class initUI {};
			class refeshUI {};
		};
		class looting {
			class spawnLoot {};
		};
		class gui {
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
			class dynamicText {};
			class genderSelection {};
		};

		class config {
			file = "epoch_code\gui\scripts\config";
			class config_keymap {};
		};

		class dynamenu {
			file = "epoch_code\gui\scripts\dynamenu";
			class dynamicMenu {};
			class dynamicMenuPopulate {};
			class dynamicMenuCleanup {};
		};

		class gui_craft {
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
		class group {
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

		class gui_inventory {
			file = "epoch_code\gui\scripts\inventory";
			class Inventory_Group {};
			class Inventory_iGroup {};
		};

		class gui_missions {
			file = "epoch_code\gui\scripts\missions";
			class mission_refresh {};
			class mission_description {};
		};
		class gui_postProcessing {
			file = "epoch_code\gui\scripts\post_process";
			class postprocessCreate {};
			class postprocessAdjust {};
			class postprocessDestroy {};
			class setDrunk {}; //needs a better name
		};
		class worldToScreen {
			file = "epoch_code\gui\scripts\worldToScreen";
			class gui3DCooldown {};
			class gui3DCooldownEH {};
			class gui3DWorldPos {};
			class gui3DWorldPosEH {};
			class gui3DModelPos {};
			class gui3DModelPosEH {};
		};
	};
};
