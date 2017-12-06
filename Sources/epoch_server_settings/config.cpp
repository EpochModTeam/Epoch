/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Epoch Server Settings Config

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server_settngs/config.cpp
*/

#define _ARMA_

class CfgPatches {
	class A3_server_settings {
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		epochVersion = "1.1.0";
		requiredAddons[] = {};
		#include "build.hpp"
	};
};

// inport loot tables
#include "configs\CfgMainTable.h"
#include "configs\CfgLootTable.h"
#include "configs\CfgLootTable_CUP.h"
#include "configs\CfgLootTable_MAD.h"
#include "configs\CfgLootTable_MADCUP.h"
// vehicle textures
#include "configs\CfgEpochVehicles.h"
// security checks
#include "configs\security\security_checks.h"
// props template
#include "configs\templates\CfgPropTemplate.h"

// import settings
class CfgEpochServer
{
	#include "\@epochhive\epochah.hpp"
	#include "\@epochhive\epochconfig.hpp"
};

// map config
class CfgEpoch
{
	class Default
	{
		worldSize = 12000;
		vehicleSpawnTypes[] = {
			{"FlatAreaCity",1},
			{"FlatAreaCitySmall",1},
			{"NameCity",2},
			{"NameVillage",1},
			{"NameCityCapital",4},
			{"Airport",5}
		};
		
		// Radiation System
		radioactiveLocations[] = {"NameCityCapital", "NameCity", "Airport"};
		radioactiveLocationsCount = 3;
		// Block radioactive locations spawn
		radioactiveLocBLObjects[] = {"PlotPole_EPOCH"};
		radioactiveLocBLDistance = 500;
		customRadioactiveLocations[] = { // position , intensity , object to spawn radiated
			// {{11650,11900,0}, 500, "Land_Device_assembled_F"},
			// {{0,0,0}, 0, ""} //any of these will throw an error in the rpt
			// leave this empty to spawn 0 custom locations
		};
		
		// Traders
		traderBlds[] = {"House", "Building"};
		traderHomes[] = {"House", "Building"};
		traderUniforms[] = {"U_OG_leader", "U_C_Poloshirt_stripped", "U_C_Poloshirt_blue", "U_C_Poloshirt_burgundy", "U_C_Poloshirt_tricolour", "U_C_Poloshirt_salmon", "U_C_Poloshirt_redwhite", "U_C_Poor_1", "U_C_WorkerCoveralls", "U_C_Journalist", "U_C_Scientist", "U_OrestesBody"};
		
		// Debug Box 
		telePos[] = {};
		lightPos[] = {
			{-16.623,-8.50195,-10.5417},
			{15.0352,-9.08594,-10.5417}
		};
		debugBoxClass = "Debug_static_F";
		cloneClasses[] = {"clone_empty_static_F", "clone_male_static_F", "clone_female_static_F"};
		
		// Settings for Events, Missions, etc
		spawnDistanceFromPlayers = 500;
		spawnDistanceFromJammers = 1000;
		spawnDistanceFromTraders = 2000;
		HeightenedPlayerVsPlayer = 1; // 0 = OFF

		// Shipwrecks Loot Box Spawner
		shipwreckLootEnabled = 1; // 0 = OFF
		debugShipwreckLoot = 0; // 1 = ON
		showBoatLootMarkers = 1;
		maxSpawnedShipwrecks = 12;
		distFromOtherShipwrecks = 750;
		shipwreckDecayMarkerColor = "ColorBrown"; // decay changes icon (_markers select 2)
		shipwreckCompromisedColor = "ColorRed"; // compromised changes active surround (_markers select 0)

		// Plant Spawner
		debugPlantSpawner = 0;
		showPlantMarkers = 1;
		maxPlantSpawns = 5;
		distFromOtherPlants = 2500;
		plantDecayTime = 1200; //Half this time results in decayMarkerColor marker
		plantDecayMarkerColor = "ColorBrown";
		plantCompromisedColor = "ColorRed";
		availablePlants[] = {"Goldenseal_EPOCH", "Goldenseal_EPOCH", "Goldenseal_EPOCH", "Poppy_EPOCH", "Pumpkin_EPOCH"};

		// Carnival and Loot Box Spawner
		debugCarnivalSpawner = 0;
		showCarnivalMarkers = 1;
		maxCarnivalSpawns = 2;
		distFromOtherCarnivals = 5000;
		carnivalDecayTime = 3600;
		carnivalDecayMarkerColor = "ColorBrown";
		carnivalCompromisedColor = "ColorRed";
		carnivalSpawnedObjects[] = {"Carnival_Tent", "Land_Slide_F", "Carnival_Tent", "Land_Carousel_01_F", "Carnival_Tent", "Carnival_Tent"};
		
		// EarthQuake and Mineral Deposit Spawner
		debugEarthquakeSpawner = 0;
		showEarthquakeMarkers = 1;
		maxEarthquakeSpawns = 3;
		distFromOtherEarthquakes = 1500;
		earthquakeDecayTime = 2400;
		earthquakeDecayMarkerColor = "ColorBrown";
		earthquakeCompromisedColor = "ColorRed";
		availableMinerals[] = {"MineralDepositCopper_EPOCH", "MineralDepositGold_EPOCH", "MineralDepositSilver_EPOCH"};
		
		// Container Spawner
		debugContainerSpawner = 0;
		showContainerMarkers = 1;
		maxContainerSpawns = 5;
		distFromOtherContainers = 3500;
		containerDecayTime = 1200;
		containerDecayMarkerColor = "ColorBrown";
		containerCompromisedColor = "ColorRed";
		
		// Satellite Crash Spawner
		debugSatelliteSpawner = 0;
		showSatelliteMarkers = 1;
		maxSatelliteSpawns = 5;
		distFromOtherSatellites = 2500;
		satelliteDecayTime = 2700;
		satelliteDecayMarkerColor = "ColorBrown";
		satelliteCompromisedColor = "ColorRed";
		availableSatellites[] = {"Land_Wreck_Satellite_EPOCH"};
		
	propsPos[] = {
			// Will accept several variations of this entry to place objects on the map
			// _className - STRING - Class name of the object to spawn
			// _position - ARRAY - posATL of the object placement
			// _direction - NUMBER or ARRAY - Accepts direction 0-360 or accepts Vector Direction and UP array
			// _deSimulate - BOOLEAN - Turns simulation off at spawn to save on performance
			// _dynamicSimulation(OPTIONAL) - BOOLEAN - Add the object to arma3 dynamic sim system
			// _destruction(OPTIONAL) - BOOLEAN - Setting this to true will allow damage to the object
			// _damage(OPTIONAL) - NUMBER - Preset damage limited to maximum 0.75 (75% damaged)
			
			// EXAMPLES:
			// {_classname, _position, _direction, _deSimulate, _dynamicSimulation, _destruction, _damage},
			// 1 {"Land_MarketShelter_F", { 13315.3, 14512.4, 0.0361125 }, 119.966, true},
			// 2 {"Land_MarketShelter_F", { 13315.3, 14512.4, 0.0361125 }, {{0,0,0},{0,0,1}}, true},
			// 3 {"Land_MarketShelter_F", { 13315.3, 14512.4, 0.0361125 }, {{0,0,0},{0,0,1}}, true, true, false, 0},
		};
		staticNpcPos[] = {};
        forcedVehicleSpawnTable = "";
        forcedLootSpawnTable = "";
		allowedVehiclesList[] = {
		    {"C_Offroad_01_EPOCH",8},
		    {"C_Quadbike_01_EPOCH",8},
		    {"C_Hatchback_01_EPOCH",10},
		    {"C_Hatchback_02_EPOCH",10},
		    {"C_SUV_01_EPOCH",10},
		    {"C_Rubberboat_EPOCH",5},
		    {"C_Rubberboat_02_EPOCH",5},
		    {"C_Rubberboat_03_EPOCH",5},
		    {"C_Rubberboat_04_EPOCH",5},
		    {"C_Van_01_box_EPOCH",8},
		    {"C_Van_01_transport_EPOCH",9},
		    {"C_Boat_Civil_01_EPOCH",5},
		    {"C_Boat_Civil_01_police_EPOCH",5},
		    {"C_Boat_Civil_01_rescue_EPOCH",5},
		    {"B_Heli_Light_01_EPOCH",2},
		    {"B_SDV_01_EPOCH",2},
		    {"B_MRAP_01_EPOCH",3},
			{"I_MRAP_03_EPOCH", 3},
		    {"B_Truck_01_transport_EPOCH",1},
		    {"B_Truck_01_covered_EPOCH",2},
		    {"B_Truck_01_mover_EPOCH",1},
		    {"B_Truck_01_box_EPOCH",1},
		    {"O_Truck_02_covered_EPOCH",2},
		    {"O_Truck_02_transport_EPOCH",1},
		    {"O_Truck_03_covered_EPOCH",1},
		    {"O_Truck_02_box_EPOCH",1},
		    {"I_Heli_light_03_unarmed_EPOCH",1},
		    {"O_Heli_Light_02_unarmed_EPOCH",1},
		    {"I_Heli_Transport_02_EPOCH",1},
		    {"O_Heli_Transport_04_EPOCH",1},
		    {"O_Heli_Transport_04_bench_EPOCH",1},
		    {"O_Heli_Transport_04_box_EPOCH",1},
		    {"O_Heli_Transport_04_covered_EPOCH",1},
		    {"B_Heli_Transport_03_unarmed_EPOCH",1},
		    {"jetski_epoch",7},
		    {"K01",2},
		    {"K02",2},
		    {"K03",2},
		    {"K04",2},
		    {"ebike_epoch",7},
		    {"mosquito_epoch",5},
			{"C_Heli_Light_01_civil_EPOCH",5}
		};
		allowedVehiclesList_CUP[] = {
			{"C_Offroad_01_EPOCH",4},
		    {"C_Quadbike_01_EPOCH",4},
		    {"C_Hatchback_01_EPOCH",5},
		    {"C_Hatchback_02_EPOCH",5},
		    {"C_SUV_01_EPOCH",5},
		    {"C_Rubberboat_EPOCH",2},
		    {"C_Rubberboat_02_EPOCH",2},
		    {"C_Rubberboat_03_EPOCH",2},
		    {"C_Rubberboat_04_EPOCH",2},
		    {"C_Van_01_box_EPOCH",4},
		    {"C_Van_01_transport_EPOCH",4},
		    {"C_Boat_Civil_01_EPOCH",5},
		    {"C_Boat_Civil_01_police_EPOCH",2},
		    {"C_Boat_Civil_01_rescue_EPOCH",2},
		    {"B_Heli_Light_01_EPOCH",2},
		    {"B_SDV_01_EPOCH",2},
		    {"B_MRAP_01_EPOCH",2},
			{"I_MRAP_03_EPOCH", 2},
		    {"B_Truck_01_transport_EPOCH",1},
		    {"B_Truck_01_covered_EPOCH",2},
		    {"B_Truck_01_mover_EPOCH",1},
		    {"B_Truck_01_box_EPOCH",1},
		    {"O_Truck_02_covered_EPOCH",2},
		    {"O_Truck_02_transport_EPOCH",1},
		    {"O_Truck_03_covered_EPOCH",1},
		    {"O_Truck_02_box_EPOCH",1},
		    {"I_Heli_light_03_unarmed_EPOCH",1},
		    {"O_Heli_Light_02_unarmed_EPOCH",1},
		    {"I_Heli_Transport_02_EPOCH",1},
		    {"O_Heli_Transport_04_EPOCH",1},
		    {"O_Heli_Transport_04_bench_EPOCH",1},
		    {"O_Heli_Transport_04_box_EPOCH",1},
		    {"O_Heli_Transport_04_covered_EPOCH",1},
		    {"B_Heli_Transport_03_unarmed_EPOCH",1},
		    {"jetski_epoch",3},
		    {"K01",1},
		    {"K02",1},
		    {"K03",1},
		    {"K04",1},
		    {"ebike_epoch",3},
		    {"mosquito_epoch",3},
			{"C_Heli_Light_01_civil_EPOCH",2},
			{"CUP_C_Fishing_Boat_Chernarus",2},
			{"CUP_C_LR_Transport_CTK",2},
			{"CUP_B_Zodiac_USMC",2},
			{"CUP_C_Skoda_Red_CIV",2},
			{"CUP_C_Skoda_White_CIV",2},
			{"CUP_C_Skoda_Blue_CIV",2},
			{"CUP_C_Skoda_Green_CIV",2},
			{"CUP_C_SUV_CIV",2},
			{"CUP_B_HMMWV_Transport_USA",2},
			{"CUP_B_HMMWV_Unarmed_USA",2},
			{"CUP_C_SUV_TK",2},
			{"CUP_B_LR_Transport_CZ_D",2},
			{"CUP_C_Datsun_Covered",2},
			{"CUP_C_Datsun_Plain",2},
			{"CUP_C_Datsun_Tubeframe",2},
			{"CUP_C_Datsun_4seat",2},
			{"CUP_C_Datsun",2},
			{"CUP_C_Golf4_green_Civ",2},
			{"CUP_C_Golf4_red_Civ",2},
			{"CUP_C_Golf4_blue_Civ",2},
			{"CUP_C_Golf4_black_Civ",2},
			{"CUP_C_Golf4_kitty_Civ",2},
			{"CUP_C_Golf4_reptile_Civ",2},
			{"CUP_C_Golf4_camodigital_Civ",2},
			{"CUP_C_Golf4_camodark_Civ",2},
			{"CUP_C_Golf4_camo_Civ",2},
			{"CUP_B_M1030",2},
			{"CUP_C_Ural_Civ_03",2},
			{"CUP_C_Ural_Open_Civ_03",2},
			{"CUP_C_Ural_Civ_02",2},
			{"CUP_B_TowingTractor_USMC",2},
			{"CUP_C_C47_CIV",2},
			{"CUP_B_LR_Transport_CZ_W",2},
			{"CUP_C_Golf4_white_Civ",2},
			{"CUP_C_Golf4_whiteblood_Civ",2},
			{"CUP_C_Golf4_yellow_Civ",2},
			{"CUP_C_Octavia_CIV",2},
			{"CUP_C_Ural_Civ_01",2},
			{"CUP_C_Ural_Open_Civ_01",2},
			{"CUP_B_Ural_CDF",2},
			{"CUP_B_Ural_Open_CDF",2},
			{"CUP_C_Ural_Open_Civ_02",2},
			{"CUP_B_HMMWV_Ambulance_USA",2},
			{"CUP_C_UAZ_Unarmed_TK_CIV",2},
			{"CUP_C_UAZ_Open_TK_CIV",2},
			{"CUP_B_UAZ_Unarmed_CDF",2},
			{"CUP_B_Ural_Empty_CDF",2},
			{"CUP_C_DC3_CIV",2}
		};
        allowedVehiclesList_MAD[] = {
			{"jetski_epoch",5},
            {"ebike_epoch",5},
		    {"mosquito_epoch",5},
            {"chums_buggy_1",10},
            {"plymouth_rock_1",5},
            {"warrig_black",5},
            {"nux_car_1",10},
            {"interceptor_1",5},
		};
        allowedVehiclesList_MADCUP[] = {
            {"jetski_epoch",3},
            {"ebike_epoch",1},
		    {"mosquito_epoch",3},
            {"chums_buggy_1",7},
            {"plymouth_rock_1",4},
            {"warrig_black",4},
            {"nux_car_1",7},
            {"interceptor_1",4},
			{"CUP_C_Fishing_Boat_Chernarus",2},
			{"CUP_C_Skoda_Red_CIV",1},
			{"CUP_C_Skoda_White_CIV",1},
			{"CUP_C_Skoda_Blue_CIV",1},
			{"CUP_C_Skoda_Green_CIV",1},
			{"CUP_C_Datsun_Covered",1},
			{"CUP_C_Datsun_Plain",1},
			{"CUP_C_Datsun_Tubeframe",1},
			{"CUP_C_Datsun_4seat",1},
			{"CUP_C_Datsun",1},
			{"CUP_C_Golf4_green_Civ",1},
			{"CUP_C_Golf4_red_Civ",1},
			{"CUP_C_Golf4_blue_Civ",1},
			{"CUP_C_Golf4_black_Civ",1},
			{"CUP_C_Golf4_kitty_Civ",1},
			{"CUP_C_Golf4_reptile_Civ",1},
			{"CUP_C_Golf4_camodigital_Civ",1},
			{"CUP_C_Golf4_camodark_Civ",1},
			{"CUP_C_Golf4_camo_Civ",1},
			{"CUP_B_M1030",2},
			{"CUP_C_Golf4_white_Civ",1},
			{"CUP_C_Golf4_whiteblood_Civ",1},
			{"CUP_C_Golf4_yellow_Civ",1},
			{"CUP_C_Octavia_CIV",1},
		};
	};
	#include "configs\maps\bornholm.h"
	#include "configs\maps\stratis.h"
	#include "configs\maps\altis.h"
	#include "configs\maps\chernarus.h"
	#include "configs\maps\chernarusredux.h"
	#include "configs\maps\chernarus_summer.h"
	#include "configs\maps\australia.h"
	#include "configs\maps\takistan.h"
	#include "configs\maps\Zargabad.h"
	#include "configs\maps\esseker.h"
	#include "configs\maps\Sara.h"
	#include "configs\maps\SaraLite.h"
	#include "configs\maps\Sara_dbe1.h"
	#include "configs\maps\Bootcamp_ACR.h"
	#include "configs\maps\Desert_E.h"
	#include "configs\maps\Mountains_ACR.h"
	#include "configs\maps\Porto.h"
	#include "configs\maps\ProvingGrounds_PMC.h"
	#include "configs\maps\Shapur_BAF.h"
	#include "configs\maps\Utes.h"
	#include "configs\maps\Woodland_ACR.h"
	#include "configs\maps\Napf.h"
	#include "configs\maps\tanoa.h"
    #include "configs\maps\Malden.h"
    #include "configs\maps\abramia.h"
    #include "configs\maps\dingor.h"
    #include "configs\maps\IslaDuala3.h"
    #include "configs\maps\Kapaulio.h"
    #include "configs\maps\lingor3.h"
    #include "configs\maps\Panthera3.h"
    #include "configs\maps\Winthera3.h"
    
};
