/*
	Author: Aaron Clark - EpochMod.com

    Contributors: Raimonds Virtoss

	Description:
	Epoch Config

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_config/config.cpp
*/

#define _ARMA_

enum {
	StabilizedInAxesNone = 0,
	StabilizedInAxisX = 1,
	StabilizedInAxisY = 2,
	StabilizedInAxesBoth = 3,
	StabilizedInAxesXYZ = 4
};

class CfgPatches
{
	class A3_epoch_config
	{
		units[] = { "Epoch_Female_F", "Epoch_Male_F", "Epoch_Cloak_F", "Epoch_Sapper_F", "Epoch_Ent_Small_F", "Epoch_Ent_Med_F", "Epoch_Ent_Large_F", "Land_Test_House_01_F", "Land_Test_House_01_dam_F", "Land_Test_House_01_ruins_F", "Epoch_Test", "C_Test_Car_01_F", "C_Hatchback_01_EPOCH", "C_Hatchback_02_EPOCH", "C_Offroad_01_EPOCH", "C_Quadbike_01_EPOCH", "C_SUV_01_EPOCH", "C_Rubberboat_EPOCH", "C_Rubberboat_02_EPOCH", "C_Rubberboat_03_EPOCH", "C_Rubberboat_04_EPOCH", "C_Van_01_box_EPOCH", "C_Van_01_transport_EPOCH", "C_Boat_Civil_01_EPOCH", "C_Boat_Civil_01_police_EPOCH", "C_Boat_Civil_01_rescue_EPOCH", "B_Heli_Light_01_EPOCH", "B_Heli_Transport_01_EPOCH", "B_Heli_Transport_01_camo_EPOCH", "B_SDV_01_EPOCH", "B_MRAP_01_EPOCH", "B_Truck_01_transport_EPOCH", "B_Truck_01_covered_EPOCH", "B_Truck_01_mover_EPOCH", "B_Truck_01_box_EPOCH", "O_Truck_02_covered_EPOCH", "O_Truck_02_transport_EPOCH", "O_Truck_03_covered_EPOCH", "O_Truck_02_box_EPOCH", "O_Heli_Light_02_unarmed_EPOCH", "I_Heli_Transport_02_EPOCH", "I_Heli_light_03_unarmed_EPOCH", "O_Test_Tank_01", "Sword_SIM_EPOCH", "SapperHead_SIM_EPOCH", "SapperCorpse_SIM_EPOCH", "MetalFloor_SIM_EPOCH", "WoodRamp_SIM_EPOCH", "CinderWallHalf_SIM_EPOCH", "CinderWall_SIM_EPOCH", "CinderWallDoorway_SIM_EPOCH", "CinderWallSmallDoorway_SIM_EPOCH", "WoodFloor_SIM_EPOCH", "WoodFloorHalf_SIM_EPOCH", "WoodFloorQuarter_SIM_EPOCH", "WoodLargeWall_SIM_EPOCH", "WoodLargeWallCor_SIM_EPOCH", "WoodLargeWallDoorway_SIM_EPOCH", "WoodLargeWallDoor_SIM_EPOCH", "WoodLargeWallWin_SIM_EPOCH", "WoodSmallWallThird_SIM_EPOCH", "WoodStairs_SIM_EPOCH", "WoodLadder_SIM_EPOCH", "WoodStairsSans_SIM_EPOCH", "Shelf_SIM_EPOCH", "Chair_SIM_EPOCH", "ChairRed_SIM_EPOCH", "Filing_SIM_EPOCH", "Fridge_SIM_EPOCH", "Bed_SIM_EPOCH", "Couch_SIM_EPOCH", "Wardrobe_SIM_EPOCH", "Locker_SIM_EPOCH", "Cooker_SIM_EPOCH", "Pelican_SIM_EPOCH", "Land_SIM_EPOCH_WoodDoor_Base", "Land_SIM_EPOCH_WoodDoorLocked_Base", "CinderWallDoor_SIM_EPOCH_Base", "CinderWallDoorLocked_SIM_EPOCH_Base", "Land_SIM_EPOCH_WoodDoor", "Land_SIM_EPOCH_WoodDoorLocked", "Land_SIM_EPOCH_LargeWoodDoor", "Land_SIM_EPOCH_LargeWoodDoorLocked", "Land_SIM_EPOCH_GarageWoodDoor", "Land_SIM_EPOCH_GarageWoodDoorLocked", "CinderWallDoorLocked_SIM_EPOCH", "CinderWallDoor_SIM_EPOCH", "CinderWallDoorSmallLocked_SIM_EPOCH", "CinderWallDoorSmall_SIM_EPOCH", "Foundation_EPOCH", "Foundation_Ghost_EPOCH", "Sword_EPOCH", "MetalFloor_EPOCH", "WoodRamp_EPOCH", "CinderWallHalf_EPOCH", "CinderWall_EPOCH", "CinderWallDoorway_EPOCH", "CinderWallSmallDoorway_EPOCH", "WoodFloor_EPOCH", "WoodFloorHalf_EPOCH", "WoodFloorQuarter_EPOCH", "WoodLargeWall_EPOCH", "WoodLargeWallCor_EPOCH", "WoodLargeWallDoorway_EPOCH", "WoodLargeWallDoor_EPOCH", "WoodLargeWallWin_EPOCH", "WoodSmallWallThird_EPOCH", "WoodStairs_EPOCH", "WoodLadder_EPOCH", "WoodStairsSans_EPOCH", "Shelf_EPOCH", "Fridge_EPOCH", "Pelican_EPOCH", "BedProxy_EPOCH", "Bed_EPOCH", "CouchProxy_EPOCH", "Couch_EPOCH", "ChairProxy_EPOCH", "Chair_EPOCH", "ChairRed_EPOCH", "FilingProxy_EPOCH", "Filing_EPOCH", "Land_EPOCH_WoodDoor_Base", "Land_EPOCH_WoodDoorLocked_Base", "CinderWallDoor_EPOCH_Base", "CinderWallDoorLocked_EPOCH_Base", "Land_EPOCH_WoodDoor", "Land_EPOCH_WoodDoorLocked", "Land_EPOCH_LargeWoodDoor", "Land_EPOCH_LargeWoodDoorLocked", "Land_EPOCH_GarageWoodDoor", "Land_EPOCH_GarageWoodDoorLocked", "CinderWallDoorLocked_EPOCH", "CinderWallDoor_EPOCH", "CinderWallDoorSmallLocked_EPOCH", "CinderWallDoorSmall_EPOCH", "Poppy_EPOCH", "Land_WoodenBox_C_EPOCH", "Land_PaperBox_C_EPOCH", "centerplane_ui" };
		weapons[] = { "U_Test_uniform", "U_Test1_uniform", "V_F0_EPOCH", "V_F1_EPOCH", "V_F2_EPOCH", "V_F3_EPOCH", "V_F4_EPOCH", "V_F5_EPOCH", "V_F6_EPOCH", "V_F7_EPOCH", "V_1_EPOCH", "V_2_EPOCH", "V_3_EPOCH", "V_4_EPOCH", "V_5_EPOCH", "V_6_EPOCH", "V_7_EPOCH", "V_8_EPOCH", "V_9_EPOCH", "V_10_EPOCH", "V_11_EPOCH", "V_12_EPOCH", "V_13_EPOCH", "V_14_EPOCH", "V_15_EPOCH", "V_16_EPOCH", "V_17_EPOCH", "V_18_EPOCH", "V_19_EPOCH", "V_20_EPOCH", "V_21_EPOCH", "V_22_EPOCH", "V_23_EPOCH", "V_24_EPOCH", "V_25_EPOCH", "V_26_EPOCH", "V_27_EPOCH", "V_28_EPOCH", "V_29_EPOCH", "V_30_EPOCH", "V_31_EPOCH", "V_32_EPOCH", "V_33_EPOCH", "V_34_EPOCH", "V_35_EPOCH", "V_36_EPOCH", "V_37_EPOCH", "V_38_EPOCH", "V_39_EPOCH", "V_40_EPOCH", "H_F0_EPOCH", "H_F1_EPOCH", "H_F2_EPOCH", "H_F3_EPOCH", "H_F4_EPOCH", "H_F5_EPOCH", "H_11_EPOCH", "H_28_EPOCH", "Rollins_F", "ChainSaw", "ChainSawB", "ChainSawG", "ChainSawP", "ChainSawR", "MultiGun", "Drink", "MeleeSledge", "test_suppressor", "Defib_EPOCH", "Heal_EPOCH", "Repair_EPOCH", , "sr25_epoch", "sr25_ec_epoch", "muzzle_sr25S_epoch", "l85a2_base_epoch", "l85a2_epoch", "l85a2_ris_epoch", "l85a2_ris_ng_epoch", "l85a2_pink_epoch", "l85a2_ugl_epoch" };
		requiredVersion = 0.1;
		requiredAddons[] = { "a3_map_altis", "a3_map_stratis", "A3_epoch_assets_3", "a3_epoch_weapons", "epoch_objects", "A3_epoch_vehicles", "A3_epoch_assets_1", "A3_epoch_assets", "A3_Soft_F", "A3_Characters_F", "A3_Characters_F_Beta", "A3_Characters_F_EPA", "A3_Characters_F_EPB", "A3_Structures_F", "A3_Armor_F_Beta", "A3_Data_F", "A3_Weapons_F", "A3_Characters_F_Kart", "A3_Soft_F_Kart_Kart_01", "a2_epoch_weapons", "A3_Air_F_Gamma_UAV_01", "A3_Soft_F_Car", "A3_Soft_F_Heli_Car", "A3_Soft_F_Offroad_01", "A3_Soft_F_Quadbike", "A3_Soft_F_Heli_Quadbike", "A3_Soft_F_SUV", "A3_Soft_F_Heli_SUV", "A3_Boat_F_Boat_Transport_01", "A3_Soft_F_Truck", "A3_Soft_F_Heli_Truck", "A3_Soft_F_Bootcamp_Truck", "A3_Boat_F_Civilian_Boat", "A3_Air_F_Heli_Light_01", "A3_Air_F_Heli_Heli_Light_01", "A3_Air_F_Beta_Heli_Transport_01", "A3_Boat_F_SDV_01", "A3_Boat_F_Heli_SDV_01", "A3_Soft_F_MRAP_01", "A3_Soft_F_Heli_MRAP_01", "A3_Soft_F_HEMTT", "A3_Soft_F_Gamma_HEMTT", "A3_Soft_F_TruckHeavy", "A3_Soft_F_Gamma_TruckHeavy", "A3_Soft_F_EPC_Truck_03", "A3_Air_F_Heli_Light_02", "A3_Air_F_Beta_Heli_Transport_02", "A3_Air_F_EPB_Heli_Light_03", "A3_Air_F_Heli_Heli_Transport_04", "A3_Air_F_Heli_Heli_Transport_03", "A3_Animals_F_Dog", "A3_Animals_F_Rabbit", "A3_Animals_F_Chicken", "A3_Characters_F_Common", "A3_Structures_F_Ind_Transmitter_Tower", "a3_epoch_structures" };
		magazines[] = { "30Rnd_test_mag", "5Rnd_rollins_mag", "CSGAS", "sledge_swing", "30Rnd_test_mag_Tracer", "EnergyPack", "1Rnd_Soda", "1Rnd_Food", "WoodLog_EPOCH", "PaintCanBlk", "PaintCanBlu", "PaintCanBrn", "PaintCanGrn", "PaintCanOra", "PaintCanPur", "PaintCanRed", "PaintCanTeal", "PaintCanYel" };
		ammo[] = { "B_EnergyPack", "B_Swing", "Sapper_Charge_Ammo", "SapperB_Charge_Ammo", "B_Soda", "B_Food", "B_Test_Caseless", "ChainSaw_Bullet", "SmokeShellCustom" };
		epochVersion = "0.3.6.0";
	};
};

class CfgAddons
{
	class PreloadBanks{};
	class PreloadAddons
	{
		class A3_EPOCH
		{
			list[] = { "A3_epoch_assets_3", "a3_epoch_weapons", "A3_epoch_vehicles", "A3_epoch_vehicles_1", "epoch_objects", "A3_epoch_assets_1", "A3_epoch_assets" };
		};
	};
};

#include "\x\addons\a3_epoch_config\Configs\CfgMissions.hpp"
#include "\x\addons\a3_epoch_config\Configs\CfgWorlds.hpp"
#include "\x\addons\a3_epoch_config\Configs\CfgTraderMissions.hpp"
#include "\x\addons\a3_epoch_config\Configs\cfgCrafting.hpp"
#include "\x\addons\a3_epoch_config\Configs\cfgPricing.hpp"
#include "\x\addons\a3_epoch_config\Configs\CfgEpochClient.hpp"
#include "\x\addons\a3_epoch_config\Configs\CfgMasterLoop.hpp"
#include "\x\addons\a3_epoch_config\Configs\CfgBaseBuilding.hpp"
#include "\x\addons\a3_epoch_config\Configs\CfgSnapChecks.hpp"
#include "\x\addons\a3_epoch_config\Configs\CfgBuildingLootPos.hpp"
#include "\x\addons\a3_epoch_config\Configs\CfgActionMenu\CfgActionMenu_core.hpp"
#include "\x\addons\a3_epoch_config\Configs\CfgEpochConfiguration.hpp"

class DefaultEventhandlers;
class WeaponFireGun;
class WeaponCloudsGun;
class WeaponFireMGun;
class WeaponCloudsMGun;

#include "\x\addons\a3_epoch_config\Configs\CfgMovesBasic.hpp"
#include "\x\addons\a3_epoch_config\Configs\CfgMovesMaleSdr.hpp"
#include "\x\addons\a3_epoch_config\Configs\CfgMovesMaleSdr2.hpp"
#include "\x\addons\a3_epoch_config\Configs\CfgGesturesMale.hpp"
#include "\x\addons\a3_epoch_config\Configs\CfgMovesAnimal.hpp"

#include "\x\addons\a3_epoch_config\Configs\CfgSounds.hpp"

#include "\x\addons\a3_epoch_config\Configs\CfgCloudlets.hpp"

#include "\x\addons\a3_epoch_config\Configs\CfgVehicles.hpp"

#include "\x\addons\a3_epoch_config\Configs\CfgActions.hpp"

//#include "\x\addons\a3_epoch_config\Configs\CfgInGameUI.hpp"

class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class SlotInfo;
class CowsSlot;
class PointerSlot;

#include "\x\addons\a3_epoch_config\Configs\cfgRecoils.hpp"

#include "\x\addons\a3_epoch_config\Configs\CfgMagazines.hpp"

#include "\x\addons\a3_epoch_config\Configs\CfgAmmo.hpp"

#include "\x\addons\a3_epoch_config\Configs\CfgWeapons.hpp"



class CfgAnimationSourceSounds
{
	class jack_pump
	{
		class pumpJack
		{
			loop = 0;
			terminate = 0;
			trigger = "direction * (phase factor[0.01,0.02])";
			sound0[] = { "\x\addons\a3_epoch_assets\sounds\tools\jack", 1, 1, 20 };
			sound[] = { "sound0", 1 };
		};

	};
};

class CfgCommands
{
	// allowedHTMLLoadURIs[] += // think this adds to an existing array
	allowedHTMLLoadURIs[] =
	{
		"https://raw.githubusercontent.com/epochmodteam/epoch/test/changelog.html" //there are some issues with capitalization used in github links
	};
};

class CfgFontFamilies
{
	class VT323
	{
		fonts[] = {"x\addons\a3_epoch_config\Data\Fonts\VT323\VT3236","x\addons\a3_epoch_config\Data\Fonts\VT323\VT3237","x\addons\a3_epoch_config\Data\Fonts\VT323\VT3238","x\addons\a3_epoch_config\Data\Fonts\VT323\VT3239","x\addons\a3_epoch_config\Data\Fonts\VT323\VT32310","x\addons\a3_epoch_config\Data\Fonts\VT323\VT32311","x\addons\a3_epoch_config\Data\Fonts\VT323\VT32312","x\addons\a3_epoch_config\Data\Fonts\VT323\VT32313","x\addons\a3_epoch_config\Data\Fonts\VT323\VT32314","x\addons\a3_epoch_config\Data\Fonts\VT323\VT32315","x\addons\a3_epoch_config\Data\Fonts\VT323\VT32316","x\addons\a3_epoch_config\Data\Fonts\VT323\VT32317","x\addons\a3_epoch_config\Data\Fonts\VT323\VT32318","x\addons\a3_epoch_config\Data\Fonts\VT323\VT32319","x\addons\a3_epoch_config\Data\Fonts\VT323\VT32320","x\addons\a3_epoch_config\Data\Fonts\VT323\VT32321","x\addons\a3_epoch_config\Data\Fonts\VT323\VT32322","x\addons\a3_epoch_config\Data\Fonts\VT323\VT32323","x\addons\a3_epoch_config\Data\Fonts\VT323\VT32324","x\addons\a3_epoch_config\Data\Fonts\VT323\VT32325","x\addons\a3_epoch_config\Data\Fonts\VT323\VT32326","x\addons\a3_epoch_config\Data\Fonts\VT323\VT32327","x\addons\a3_epoch_config\Data\Fonts\VT323\VT32328","x\addons\a3_epoch_config\Data\Fonts\VT323\VT32329","x\addons\a3_epoch_config\Data\Fonts\VT323\VT32330","x\addons\a3_epoch_config\Data\Fonts\VT323\VT32331","x\addons\a3_epoch_config\Data\Fonts\VT323\VT32334","x\addons\a3_epoch_config\Data\Fonts\VT323\VT32335","x\addons\a3_epoch_config\Data\Fonts\VT323\VT32337","x\addons\a3_epoch_config\Data\Fonts\VT323\VT32346"};
		spaceWidth = 0.7;
		spacing = 0.2;
	};
};
