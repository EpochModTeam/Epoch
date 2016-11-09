/*
	Author: Aaron Clark - EpochMod.com
    Contributors: Andrew Gregory

	Description:
	Main Client side configs for the Epoch gamemode

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_config/Configs/CfgEpochClient.hpp
*/
/*[[[cog from arma_config_tools import *; json_to_arma()]]]*/
class CfgEpochClient
{
    epochVersion = "0.4.0.0";
    sapperRngChance = 100;
    droneRngChance = 100;
    buildingNearbyMilitary = 0;
    buildingNearbyMilitaryRange = 300;
    buildingNearbyMilitaryClasses[] = {"Cargo_Tower_base_F","Cargo_HQ_base_F","Cargo_Patrol_base_F","Cargo_House_base_F"};
    restrictedLocations[] = {"NameCityCapital"};
    restrictedLocationsRange = 300;
    buildingRequireJammer = 0;
    buildingCountLimit = 200;
    buildingJammerRange = 75;
    JammerPerGroup = 1;
    minJammerDistance = 650;
    maxBuildingHeigh = 33;
    buildingCountLeader = 125;
    buildingCountPerMember = 5;
    storagecountLeader = 10;
    storagecountPerMember = 5;
    maxdoors = 8;
    maxgates = 5;
    disableRemoteSensors = True;
    EPOCH_news[] = {"Word is that Sappers have a new boss.","Dogs will often lure them monsters away.","My dog was blown up. I miss him.."};
    deathMorphClass[] = {"Epoch_Sapper_F","Epoch_SapperB_F","I_UAV_01_F","Epoch_Cloak_F"};
    niteLight[] = {1,1.88,22};
    ryanZombiesEnabled = True;
    antagonistSpawnIndex[] = {{"Epoch_Cloak_F",1},{"GreatWhite_F",2},{"Epoch_Sapper_F",2},{"Epoch_SapperB_F",1},{"I_UAV_01_F",2},{"PHANTOM",1},{"B_Heli_Transport_01_F",1},{"EPOCH_RyanZombie_1",12}};
    customVarsDefaults[] = {{"Temp",98.6,{106.7,95,102,105,96,95}},{"Hunger",1500,{5000,0,5001,5001,1250,0}},{"Thirst",750,{2500,0,2501,2501,625,0}},{"AliveTime",0,{-2,0}},{"Energy",0,{2500,0}},{"Wet",0,{100,0,35,55,-1,-1}},{"Soiled",0,{100,0,35,55,-1,-1}},{"Immunity",0,{100,0}},{"Toxicity",0,{100,0,35,55,-1,-1}},{"Stamina",100,{"EPOCH_playerStaminaMax",0}},{"Crypto",0,{250000,0}},{"HitPoints",{0,0,0,0},{1,0,0.5,1,-1,-1}},{"BloodP",100,{190,0,120,140,70,50}},{"SpawnArray",{},{}},{"Karma",0,{50000,-50000}},{"Alcohol",0,{100,0,35,55,-1,-1}},{"Radiation",0,{100,0,35,55,-1,-1}},{"Nuisance",0,{100,0}},{"MissionArray",{},{}}};
    hudConfigs[] = {{{"BloodP","","",{"getPlayerDamage",">=",0.7}},"topRight","x\addons\a3_epoch_code\Data\UI\bleeding_ca.paa",{"forceUpdate"}},{{"Oxygen","getPlayerOxygenRemaining","",{},{1,0,2,2,1,0.55}},"topRight","x\addons\a3_epoch_code\Data\UI\oxygen_ca.paa"},{"Hunger","topRight","x\addons\a3_epoch_code\Data\UI\hunger_ca.paa",{"forceBloodRise"}},{"Thirst","topRight","x\addons\a3_epoch_code\Data\UI\thirst_ca.paa",{"forceBloodRise"}},{"Temp","topRight",{"x\addons\a3_epoch_code\Data\UI\hot_ca.paa","x\addons\a3_epoch_code\Data\UI\cold_ca.paa"},{"forceFatigue"}},{"Toxicity","topRight","x\addons\a3_epoch_code\Data\UI\hazzard_ca.paa"},{"Alcohol","topRight","x\addons\a3_epoch_code\Data\UI\drunk_ca.paa"},{"Soiled","topRight","x\addons\a3_epoch_code\Data\UI\soiled_ca.paa"},{"Radiation","topRight","x\addons\a3_epoch_code\Data\UI\rads_ca.paa"},{{"HitPoints","getPlayerHitPointDamage","HitLegs"},"topRight","x\addons\a3_epoch_code\Data\UI\broken_ca.paa"}};
    group_upgrade_lvl[] = {4,"1000",6,"1500",8,"2000",10,"2500",12,"3000",14,"3500",16,"4000",32,"8000",64,"16000"};
    displayAddEventHandler[] = {"keyDown","keyUp"};
    keyDown = "(_this call EPOCH_KeyDown)";
    keyUp = "(_this call EPOCH_KeyUp)";
    addEventHandler[] = {"Respawn","Put","Take","InventoryClosed","InventoryOpened","Fired","Killed","HandleRating","GetInMan","GetOutMan"};
    Respawn = "(_this select 0) call EPOCH_clientRespawn";
    Put = "(_this select 1) call EPOCH_interact;_this call EPOCH_PutHandler";
    Take = "(_this select 1) call EPOCH_interact;_this call EPOCH_UnisexCheck";
    Fired = "_this call EPOCH_fnc_playerFired;";
    InventoryClosed = "if !(EPOCH_arr_interactedObjs isEqualTo[]) then {[EPOCH_arr_interactedObjs] remoteExec['EPOCH_server_save_vehicles', 2]; EPOCH_arr_interactedObjs = [];};";
    InventoryOpened = "setMousePosition[0.5, 0.5]; call EPOCH_showStats;_this spawn EPOCH_initUI;_container = _this select 1;_lockedNear = false;if (_container isKindOf 'GroundWeaponHolder' || _container isKindOf 'WeaponHolderSimulated') then {{if (locked _x in [2, 3] ||_x getVariable['EPOCH_Locked', false]) exitWith {_lockedNear = true}} forEach (player nearSupplies 10);};if (locked _container in [2, 3] || _container getVariable['EPOCH_Locked', false] || _lockedNear) then {[] spawn {disableSerialization;waitUntil {!isNull findDisplay 602};_display = findDisplay 602;_ctrl_cargo = _display displayCtrl 6401;_ctrl_ground = _display displayCtrl 6321;_ctrl_cargo ctrlEnable  false;ctrlSetFocus _ctrl_ground;ctrlActivate _ctrl_ground;};};";
    Killed = "_this call EPOCH_fnc_playerDeath;";
    HandleRating = "EPOCH_playerKarma = EPOCH_playerKarma + (_this select 1);0";
    HandleDamage = "";
    HandleHeal = "";
    Dammaged = "";
    Hit = "";
    HitPart = "";
    GetInMan = "_this call EPOCH_getInMan";
    GetOutMan = "_this call EPOCH_getOutMan;";
    nonJammerAI[] = {"B_Heli_Transport_01_F","PHANTOM","EPOCH_Sapper_F","Epoch_SapperB_F","I_UAV_01_F","EPOCH_RyanZombie_1"};
    nonTraderAI[] = {"B_Heli_Transport_01_F","PHANTOM","EPOCH_Sapper_F","Epoch_SapperB_F","I_UAV_01_F","Epoch_Cloak_F","GreatWhite_F","EPOCH_RyanZombie_1"};
    nonTraderAIRange = 50;
    fishLoots[] = {"ItemTuna","ItemSeaBass","ItemSeaBass","ItemSeaBass","ItemTrout","ItemTrout","ItemTrout","ItemTrout","ItemTrout","ItemTrout"};
    animalAiTables[] = {"Sheep_random_EPOCH","Sheep_random_EPOCH","Goat_random_EPOCH","Goat_random_EPOCH","Goat_random_EPOCH",{"Cock_random_EPOCH","Hen_random_EPOCH"},{"Cock_random_EPOCH","Hen_random_EPOCH"},"Rabbit_EPOCH","Rabbit_EPOCH","Rabbit_EPOCH","Snake_random_EPOCH","Snake2_random_EPOCH",{"Fin_random_EPOCH","Alsatian_Random_EPOCH"}};
    playerDeathScreen = "TapOut";
    playerKilledScreen = "TapOut2";
    playerDisableRevenge = 0;
    playerRevengeMinAliveTime = 900;
    bankTransferTime[] = {0.0006,1.2,0.06};
    #include "CfgEpochClient\Altis.hpp"
    #include "CfgEpochClient\australia.hpp"
    #include "CfgEpochClient\Bornholm.hpp"
    #include "CfgEpochClient\Chernarus_Summer.hpp"
    #include "CfgEpochClient\Chernarus.hpp"
    #include "CfgEpochClient\Esseker.hpp"
    #include "CfgEpochClient\ProvingGrounds_PMC.hpp"
    #include "CfgEpochClient\Sara_dbe1.hpp"
    #include "CfgEpochClient\Sara.hpp"
    #include "CfgEpochClient\SaraLite.hpp"
    #include "CfgEpochClient\Stratis.hpp"
    #include "CfgEpochClient\takistan.hpp"
    #include "CfgEpochClient\utes.hpp"
    #include "CfgEpochClient\vr.hpp"
    #include "CfgEpochClient\Zargabad.hpp"
    #include "CfgEpochClient\Tanoa.hpp"
    #include "CfgEpochClient\WorldInteractions.hpp"
};
class CfgEpochSapper
{
    detonateDistMax = 8;
    groanTrig = 16;
    sRange = 300;
    smellDist = 24;
    reflexSpeed = 0.25;
    nestChance = 2;
    hideLevel = 72;
    chargeLevel = 62;
};
class CfgEpochUAV
{
    UAVMinDist = 48;
    UAVMaxDist = 180;
    UAVHeight = 100;
};
class CfgEpochUAVSupport
{
    unitTypes[] = {"I_Soldier_EPOCH","I_Soldier2_EPOCH","I_Soldier3_EPOCH"};
    maxUnitNum = 2;
    minAISkill = 0.2;
    maxAimingAccuracy = 0.7;
    maxAimingShake = 0.9;
    maxAimingSpeed = 0.6;
    maxEndurance = 0.4;
    maxSpotDistance = 0.4;
    maxSpotTime = 0.3;
    maxCourage = 0.3;
    maxReloadSpeed = 0.5;
    maxCommanding = 0.4;
    maxGeneral = 0.4;
};
class CfgEpochAirDrop
{
    AirDropFreq = 1200;
    AirDropChance = 6;
};
class CfgEpochCloak
{
    cRange = 300;
    cAggression = 75;
    attackFrequency = 120;
    attackDistance = 38;
    targetChangeFrequency = 42;
    teleportChance = 66;
    hoverFrequency = 1280;
};
class CfgEpochRyanZombie
{
    zeds[] = {"EPOCH_RyanZombie_1","EPOCH_RyanZombie_2","EPOCH_RyanZombie_3","EPOCH_RyanZombie_4","EPOCH_RyanZombie_5"};
    attackDist = 1.6;
    range = 45;
    disposeRange = 800;
    smell[] = {38,0.42};
    sight[] = {28,0.72};
    hearing[] = {108,0.68};
    memory[] = {480,0.8};
    reflexSpeed = 0.25;
    moans[] = {"ryanzombiesmoan1","ryanzombiesmoan2","ryanzombiesmoan3","ryanzombiesmoan4"};
    screams[] = {"ryanzombiesscream1","ryanzombiesscream2","ryanzombiesscream3","ryanzombiesscream4","ryanzombiesscream5","ryanzombiesscream6","ryanzombiesscream7","ryanzombiesscream8","ryanzombiesscream9"};
};

/*[[[end]]]*/
