/****************************************************************************
Copyright (C) 2015 - ARMA 3 EPOCH MOD [EpochMod.com] (v0.3.0.1)
*****************************************************************************/

#define _ARMA_

class CfgPatches {
	class A3_epoch_server {
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"A3_epoch_server_core","A3_epoch_config","A3_server_settings","A3_server_events"};
		#include "build.hpp"
	};
};
class CfgServerFunctions
{
	version = 1;
	class A3E
	{
		tag = "EPOCH";
		file = "\epoch_server\compile";
		class epoch_group {
			class server_upgradeGroup {};
			class server_updatePlayerGroup {};
			class server_createGroup {};
			class server_deleteGroup {};
			class server_invitePlayer {};
		};
		class epoch_grouptemp {
			class server_upgradeTempGroup {};
			class server_updatePlayerTempGroup {};
			class server_createTempGroup {};
			class server_deleteTempGroup {};
			class server_invitePlayerTempGroup {};
		};
		class epoch_bases {
			class swapBuilding {};
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
            class fnc_addItemToX {};
			class fnc_savePlayer {};
			class server_savePlayer {};
            class server_makeSP {};
			class server_loadPlayer {};
			class server_checkPlayer {};
			class server_onPlayerDisconnect {};
			class server_deadPlayer {};
			class server_revivePlayer {};
			class server_SetUnitLoadout {};
			class server_storeCrypto {};
			class server_equippedItem {};
			class server_unpackBackpack {};
			class server_deadPlayerDetonate{};
			class server_playerSetVariable{};
			class server_PayCrypto{};
			class fnc_updatePlayerStats{};
			class server_updatePlayerStats{};
			class server_SetFinalPlayerPos{};
		};
		class epoch_traders {
			class server_loadTraders {};
			class server_spawnTraders {};
		};
		class epoch_trading {
			class server_effectCrypto {};
			class server_makeTrade {};
			class server_tradeRequest {};
			class server_makeNPCTrade {};
			class server_takeCrypto {};
		};
		class epoch_vehicle {
			class server_save_vehicles {};
			class server_save_vehicle {};
			class server_save_killedVehicle {};
			class server_save_killedStorage {};
			class server_save_killedBuilding {};
			class load_vehicles {};
			class load_vehicles_old {};
			class load_storage {};
			class server_save_storage {};
			class spawn_vehicles {};
			class server_lockVehicle {};
			class server_fillVehicle {};
			class server_repairVehicle {};
			class server_lockStorage {};
			class server_packStorage {};
			class server_packJack {};
			class spawn_vehicle {};
			class server_upgrade_vehicle {};
			class server_CargoSave {};
			class server_CargoFill {};
			class server_removemagoritemcargo {};
		};
		class epoch_server {
			class precisionPos {};
			class serverLootObject {};
			class server_vehicleInit {};
			class server_storageInit {};
			class server_buildingInit {};
			class server_traderKilled {};
			class localCleanup {};
			class server_createTeleport {};
			class server_getRealTime {};
			class server_teleportPlayer {};
			class returnConfig {};
			class serverCommand {};
			class server_makeMarker {};
			class server_removeMarker {};
			class server_createGlobalMarkerSet {};
			class server_deleteGlobalMarkerSet {};
			class server_isNearChecks {};
			class server_DefuseBomb {};
			class server_PutCrypto {};
		};
		class epoch_missions {
			class Server_createObject {};
			class server_airDropCrate {};
			class server_fillContainer {};
			class Server_createAirDrop {};
			class Server_missionComms{};
		};
		class epoch_antagonists {
			class server_triggerEvent {};
			class server_handle_say3D {};
			class server_handle_switchMove {};
			class server_handle_sapperObjs {};
			class server_triggerAntagonist{};
		};
	};
};
class CfgServerVersion
{
	client = "1.3.1";
	config = "1.3.1";
	hive = "0.6.0.0";
};
