class CfgPatches {
	class A3_epoch_code {
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "A3_epoch_config" };
	};
};
class CfgMods
{
	class Epoch
	{
		dir = "@epoch";
		name = "Epoch Mod";
		picture = "\x\addons\a3_epoch_assets\pictures\loadScreen_ca.paa";
		hidePicture = 0;
		hideName = 0;
		action = "http://www.epochmod.com";
		version = "0.3.3.1";
		majorVersion = 0.3; //MUST BE A NUMBER!; Change this if we release a new major version, don't change if we push just push a hotfix
		ArmAVersion = 150;
		overview = "Open world survival mod set in the year 2035, Just two years after the mass extinction of billions of people. Those that remain are left with remnants of a once technological society. Try to survive, build, or explore your way through the harsh dynamic environment.";
	};
};
class Epoch
{
	class Version
	{
		//Version System, Check if PBO Version is compatible with Code
		A3_epoch_assets = "0.3.3.0";
		A3_epoch_assets_1 = "0.3.3.0";
		epoch_objects = "0.3.3.0";
		A3_epoch_assets_3 = "0.3.3.0";
		A3_epoch_config = "0.3.3.1";
		A3_epoch_language = "0.3.3.0";
		Underground_Epoch = "0.3.3.0";
		A3_epoch_vehicles = "0.3.3.0";
		a3_epoch_weapons = "0.3.3.0";
		a2_epoch_weapons = "0.3.3.0";
		a3_epoch_structures = "0.3.3.0";
		A3_epoch_functions = "0.3.3.0";
		A3_epoch_vehicles_1 = "0.3.3.0";
		Enhanced_Epoch_AiASupport = "0.3.3.0";

	};
};

class cfgScriptPaths
{
	/*default = "A3\ui_f\scripts\GUI\";
	GUI = "A3\ui_f\scripts\GUI\";
	IGUI = "A3\ui_f\scripts\IGUI\";
	Loading = "A3\ui_f\scripts\Loading\";
	CuratorDisplays = "A3\ui_f_curator\UI\displays\";
	CuratorCommon = "A3\ui_f_curator\UI\RscCommon\";
	CuratorTitles = "A3\ui_f_curator\UI\RscTitles\";
	KartDisplays = "A3\ui_f_kart\UI\displays\";*/
	Epoch = "\x\addons\a3_epoch_code\gui\scripts\";
};
class CfgInGameUI
{
	class PeripheralVision
	{
		cueColor[] = { 0, 0, 0, 0 };
		cueFriendlyColor[] = { 0, 0, 0, 0 };
		cueEnemyColor[] = { 0, 0, 0, 0 };
	};
};

#include "\x\addons\a3_epoch_code\Data\UI\defineCommonGrids.inc"

class cfgFunctions
{
	class A3
	{
		tag = "BIS";
		class MP
		{
			file = "A3\functions_f\MP";
			class MP {
				file = "\x\addons\a3_epoch_code\compile\bis_functions\MP\fn_mp.sqf";
			};
			class MPexec {
				file = "\x\addons\a3_epoch_code\compile\bis_functions\MP\fn_MPexec.sqf";
			};
			class initMultiplayer {
				file = "\x\addons\a3_epoch_code\compile\bis_functions\MP\fn_initMultiplayer.sqf";
			};
		};
	};
	class EPOCH
	{
		tag = "EPOCH";
		class functions {
			class returnConfigEntryV2 {
				file = "\x\addons\a3_epoch_code\compile\functions\EPOCH_fn_returnConfigEntryV2.sqf";
			};
			class getHitpoints {
				file = "\x\addons\a3_epoch_code\compile\both\EPOCH_getHitpoints.sqf"
			};
			class isAny {
				file = "\x\addons\a3_epoch_code\compile\both\EPOCH_isAny.sqf"
			};
		};
	};
};

class CfgClientFunctions
{
	version = 1;
	class A3E
	{
		tag = "EPOCH";
		file = "\x\addons\a3_epoch_code\compile";

		class generic {
			file = "\x\addons\a3_epoch_code\compile";
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
			class mineRocks {};
			class UnisexCheck {};
			class PutHandler {};
			class niteLight {};
			class LootIT {};
			class supportCopter {};
			class itemInteract {};
			class consumeItem {};
			class craftItemPreview {};
			class craftItem {};
			class unitSpawn {};
			class antiWall {};
			class onEachFrame {};
		};

		class building
		{
			class maintainIT {};
			class lockCheck {};
			class countdown {};
			class fnc_SelectTarget {};
			class fnc_SelectTargetBuild {};
			class isBuildAllowed {};
			class simulSwap {};
			class staticMove {};
			class returnVector {};
			class upgradeBUILD {};
			class upgradeBUILDv2 {};
			class removeBUILD {};
			class changeWallState {};
			class QuickUpgrade {};
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
			class makep2pTrade {};
			class tradeFilter {};
			class takeCrypto {};
			class startBankTransfer {};
		};

		class interface_event_handlers
		{
			class KeyDown {};
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
		};

		class p2p_trading
		{
			class startTRADEREQ {};
			class startTrade {};
			class tradeRequest {};
			class TradeLoop {};
		};
		class functions
		{
			class returnConfig {};

			class fnc_playerDeath {};
			class fnc_playerFired {};
			class fnc_isInsideBuilding {};
			class fnc_Weather {};
			class fnc_findSafePos {};

			class pushCustomVar {};
			class itemPicture {};
			class itemDisplayName {};
			class SortArrayByDistance {};

			class fnc_findRandomPosBehind {};
			class fnc_stringLeft {};
			class fnc_findSapperStalkLocation {};
			class fnc_dirToFuzzy {};
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
			class itemInteractV2 {};
			class uniformArmorCalc {};
			class gearArmorCalc {};
			class factorArmor {};
			class maxArmorInit {};
			class initUI {};
			class refeshUI {};
		};

		class gui {
				file = "\x\addons\a3_epoch_code\gui\scripts";
				class onPause {};
				class interactVehicle {};
				class showStats {};
		};

		class group {
			file = "\x\addons\a3_epoch_code\gui\scripts\group";
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
			file = "\x\addons\a3_epoch_code\gui\scripts\inventory";
			class Inventory_Group {};
			class Inventory_iGroup {};
		};

		class gui_missions {
			file = "\x\addons\a3_epoch_code\gui\scripts\missions";
			class mission_refresh {};
			class mission_description {};
		};

	};
};
#include "\x\addons\a3_epoch_code\gui\Epoch_GUI_Config.hpp"
