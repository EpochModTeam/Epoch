/****************************************************************************
Copyright (C) 2015 - ARMA 3 EPOCH MOD [EpochMod.com] (v0.3.0.1)
*****************************************************************************/

#define _ARMA_

class CfgPatches {
	class A3_epoch_server {
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"A3_epoch_server_core","A3_epoch_config","A3_server_settings"};
	};
};
class cfgFunctions
{
	class A3E
	{
		tag = "EPOCH";
		class Epoch_Server
		{
			file = "\x\addons\a3_epoch_server\init";
			class init
			{
				preInit = 1;
			};
			class postinit
			{
				postInit = 1;
			};
		};
	};
};
class CfgServerFunctions
{
	version = 1;
	class A3E
	{
		tag = "EPOCH";
		file = "\x\addons\a3_epoch_server\compile";
		class epoch_group {
			class server_upgradeGroup {};
			class server_updatePlayerGroup {};
			class server_createGroup {};
			class server_deleteGroup {};
			class server_invitePlayer {};
		};
		class epoch_bases {
			class saveBuilding {};
			class server_loadBuildings {};
			class server_saveBuilding {};
			class server_upgradeBUILD {};
			class server_removeBUILD {};
			class server_paintBUILD {};
			class server_maintBUILD {};
			class server_simulSwap {};
			class server_simToStatic {};
			class server_unsuppported {};
		};
		class epoch_looting {
			class server_lootContainer {};
			class server_spawnBoatLoot {};
			class server_destroyTrash {};
			class server_knockDownTree {};
			class server_mineRocks {};
			class server_lootAnimal {};
		};
		class epoch_player {
			class fnc_savePlayer {};
			class server_savePlayer {};
			class server_loadPlayer {};
			class server_checkPlayer {};
			class server_respawnPlayer {};
			class server_onPlayerDisconnect {};
			class server_deadPlayer {};
			class server_revivePlayer {};
			class server_storeCrypto {};
			class server_equippedItem {};
			class server_unpackBackpack {};
		};
		class epoch_traders {
			class server_loadTraders {};
			class server_spawnTraders {};
		};
		class epoch_trading {
			class server_makeTrade {};
			class server_tradeRequest {};
			class server_makeNPCTrade {};
			class server_takeCrypto {};
		};
		class epoch_vehicle {
			class server {};
			class server {};
			class server {};
			class server {};
			class server {};
			class load_vehicles {};
			class load_storage {};
			class server {};
			class spawn_vehicles {};
			class server_lockVehicle {};
			class server_fillVehicle {};
			class server_repairVehicle {};
			class server_lockStorage {};
			class server_packStorage {};
			class server_packJack {};
			class spawn_vehicle {};
		};
		class epoch_server {
			class weightedArray {};
			class precisionPos {};
			class serverLootObject {};
			class server_vehicleInit {};
			class server_storageInit {};
			class server_buildingInit {};
			class server_traderKilled {};
			class localCleanup {};
			class server_createTeleport {};
			class server_teleportPlayer {};
			class returnConfig {};
			class serverCommand {};
		};
		class epoch_missions {
			class Server_createObject {};
			class server_airDropCrate {};
			class server_fillContainer {};
			class Server_createAirDrop {};
		};
		class epoch_antagonists {
			class server_triggerEvent {};
			class server_handle_say {};
			class server_handle_switchMove {};
			class server_handle_sapperObjs {};
		};
	};
};
class CfgServerVersion
{
	client = "0.3.8.0";
	config = "0.3.8.0";
	hive = "0.5.1.7";
};
