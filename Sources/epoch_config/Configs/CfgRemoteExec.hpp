/*
	Author: Aaron Clark - EpochMod.com

    Contributors: Andrew Gregory

	Description:
	RemoteExec whitelist for Epoch Survival gamemode. This also blacklists default A3 remoteExec commands.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_config/Configs/CfgRemoteExec.hpp
*/
/*[[[cog from arma_config_tools import *; json_to_arma()]]]*/
/*
    @author = "Aaron Clark - https://EpochMod.com";
    @contributors[] = {"Andrew Gregory"};
    @description = "RemoteExec whitelist for Epoch Survival gamemode. This also blacklists default A3 remoteExec commands.";
    @licence = "Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike";
    @github = "https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_config/Configs/CfgRemoteExec.hpp";
*/
class CfgRemoteExec
{
    class Functions
    {
        mode = 1;
        jip = 0;
        class bis_fnc_reviveinitaddplayer
        {
            allowedTargets = 2;
            jip = 0;
        };
        class EPOCH_server_paycrypto
        {
            allowedTargets = 2;
            jip = 0;
        };
        class EPOCH_server_save_vehicles
        {
            allowedTargets = 2;
            jip = 0;
        };
        class EPOCH_server_saveBuilding
        {
            allowedTargets = 2;
            jip = 0;
        };
        class EPOCH_server_upgradeBUILD
        {
            allowedTargets = 2;
            jip = 0;
        };
        class EPOCH_server_removeBUILD
        {
            allowedTargets = 2;
            jip = 0;
        };
        class EPOCH_server_paintBUILD
        {
            allowedTargets = 2;
            jip = 0;
        };
        class EPOCH_server_maintBUILD
        {
            allowedTargets = 2;
            jip = 0;
        };
        class EPOCH_server_loadPlayer
        {
            allowedTargets = 2;
            jip = 0;
        };
        class EPOCH_server_checkPlayer
        {
            allowedTargets = 2;
            jip = 0;
        };
        class EPOCH_server_deadPlayer
        {
            allowedTargets = 2;
            jip = 0;
        };
        class EPOCH_server_destroyTrash
        {
            allowedTargets = 2;
            jip = 0;
        };
        class EPOCH_server_knockDownTree
        {
            allowedTargets = 2;
            jip = 0;
        };
        class EPOCH_server_mineRocks
        {
            allowedTargets = 2;
            jip = 0;
        };
        class EPOCH_server_lootAnimal
        {
            allowedTargets = 2;
            jip = 0;
        };
        class EPOCH_server_handle_say3D
        {
            allowedTargets = 2;
            jip = 0;
        };
        class EPOCH_server_handle_switchMove
        {
            allowedTargets = 2;
            jip = 0;
        };
        class EPOCH_client_bitePlayer
        {
            allowedTargets = 1;
            jip = 0;
        };
        class EPOCH_server_upgradeGroup
        {
            allowedTargets = 2;
            jip = 0;
        };
        class EPOCH_server_updatePlayerGroup
        {
            allowedTargets = 2;
            jip = 0;
        };
        class EPOCH_server_createGroup
        {
            allowedTargets = 2;
            jip = 0;
        };
        class EPOCH_server_deleteGroup
        {
            allowedTargets = 2;
            jip = 0;
        };
        class EPOCH_server_invitePlayer
        {
            allowedTargets = 2;
            jip = 0;
        };
        class EPOCH_server_lootContainer
        {
            allowedTargets = 2;
            jip = 0;
        };
        class EPOCH_server_revivePlayer
        {
            allowedTargets = 2;
            jip = 0;
        };
        class EPOCH_server_storeCrypto
        {
            allowedTargets = 2;
            jip = 0;
        };
        class EPOCH_server_tradeRequest
        {
            allowedTargets = 2;
            jip = 0;
        };
        class EPOCH_server_makeTrade
        {
            allowedTargets = 2;
            jip = 0;
        };
        class EPOCH_server_makeNPCTrade
        {
            allowedTargets = 2;
            jip = 0;
        };
        class EPOCH_server_takeCrypto
        {
            allowedTargets = 2;
            jip = 0;
        };
        class EPOCH_server_repairVehicle
        {
            allowedTargets = 2;
            jip = 0;
        };
        class EPOCH_server_fillVehicle
        {
            allowedTargets = 2;
            jip = 0;
        };
        class EPOCH_server_lockVehicle
        {
            allowedTargets = 2;
            jip = 0;
        };
        class EPOCH_server_equippedItem
        {
            allowedTargets = 2;
            jip = 0;
        };
        class EPOCH_server_lockStorage
        {
            allowedTargets = 2;
            jip = 0;
        };
        class EPOCH_server_packStorage
        {
            allowedTargets = 2;
            jip = 0;
        };
        class EPOCH_server_packJack
        {
            allowedTargets = 2;
            jip = 0;
        };
        class EPOCH_localCleanup
        {
            allowedTargets = 2;
            jip = 0;
        };
        class EPOCH_server_teleportPlayer
        {
            allowedTargets = 2;
            jip = 0;
        };
        class EPOCH_server_fillContainer
        {
            allowedTargets = 2;
            jip = 0;
        };
        class EPOCH_server_handle_sapperObjs
        {
            allowedTargets = 2;
            jip = 0;
        };
        class EPOCH_Server_createAirDrop
        {
            allowedTargets = 2;
            jip = 0;
        };
        class EPOCH_server_airDropCrate
        {
            allowedTargets = 2;
            jip = 0;
        };
        class EPOCH_Server_createObject
        {
            allowedTargets = 2;
            jip = 0;
        };
        class EPOCH_fnc_savePlayer
        {
            allowedTargets = 2;
            jip = 0;
        };
        class EPOCH_server_unpackBackpack
        {
            allowedTargets = 2;
            jip = 0;
        };
        class EPOCH_server_triggerAntagonist
        {
            allowedTargets = 2;
            jip = 0;
        };
        class EPOCH_server_deadPlayerDetonate
        {
            allowedTargets = 2;
            jip = 0;
        };
        class epoch_server_playersetvariable
        {
            allowedTargets = 2;
            jip = 0;
        };
        class EPOCH_spawn_vehicle
        {
            allowedTargets = 2;
            jip = 0;
        };
        class EPOCH_Server_missionComms
        {
            allowedTargets = 2;
            jip = 0;
        };
        class EPOCH_serverLootObject
        {
            allowedTargets = 2;
            jip = 0;
        };
        class EPOCH_server_makeMarker
        {
            allowedTargets = 2;
            jip = 0;
        };
        class EPOCH_server_removeMarker
        {
            allowedTargets = 2;
            jip = 0;
        };
        class EPOCH_server_makeSP
        {
            allowedTargets = 2;
            jip = 0;
        };
		class EPOCH_server_upgrade_vehicle
        {
            allowedTargets = 2;
            jip = 0;
        };
		class EPOCH_fnc_updatePlayerStats
        {
            allowedTargets = 2;
            jip = 0;
        };
		class EPOCH_client_updatePlayerStat
        {
            allowedTargets = 1;
            jip = 0;
        };
    };
    class Commands
    {
        mode = 0;
    };
};

/*[[[end]]]*/
