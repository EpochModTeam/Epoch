/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Epoch Server side loot table configs

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server_settngs/configs/CfgLootTable.h
*/
class CfgLootTable
{
// DLC/Mod Related from here
	class Scopes
	{
		items[] = {
				{ { "Scopes_Vanilla", "CfgLootTable" }, 5 },
				{ { "Scopes_MarkDLC", "CfgLootTable" }, 1 },
				{ { "Scopes_CUP", "CfgLootTable" }, 0 }
		};
	};
	class Bipods
	{
		items[] = {
				{ { "Bipods_Vanilla", "CfgLootTable" }, 5 },
				{ { "Bipods_CUP", "CfgLootTable" }, 0 }
		};
	};
	class Muzzles
	{
		items[] = {
				{ { "Muzzles_Vanilla", "CfgLootTable" }, 15 },
				{ { "Muzzles_MarkDLC", "CfgLootTable" }, 8 },
				{ { "Muzzles_CUP", "CfgLootTable" }, 0 },
				{ { "Muzzles_MultiGun", "CfgLootTable" }, 1 }
		};
	};
	class WpnFlashLights
	{
		items[] = {
				{ { "WpnFlashLights_Vanilla", "CfgLootTable" }, 5 },
				{ { "WpnFlashLights_CUP", "CfgLootTable" }, 0 },
				{ { "SniperCamo_CUP", "CfgLootTable" }, 0 }
		};
	};
	class Pistols
	{
		items[] = {
				{ { "Pistols_Vanilla", "CfgLootTable" }, 20 },
				{ { "NL_Pistols", "CfgLootTable" }, 2 },
				{ { "Pistols_CUP", "CfgLootTable" }, 0 },
				{ { "Pistols_MAD", "CfgLootTable" }, 0 }
		};
	};
	class PistolAmmo
	{
		items[] = {
				{ { "PistolAmmo_Vanilla", "CfgLootTable" }, 15 },
				{ { "NL_PistolAmmo", "CfgLootTable" }, 3 },
				{ { "PistolAmmo_CUP", "CfgLootTable" }, 0 }
		};
	};
	class Rifle
	{
		items[] = {
				{ { "Rifle_Vanilla", "CfgLootTable" }, 10 },
				{ { "A2_Rifle", "CfgLootTable" }, 10 },
				{ { "NL_Rifle", "CfgLootTable" }, 2 },
				{ { "Rifle_CUP", "CfgLootTable" }, 0 },
				{ { "Rifle_MAD", "CfgLootTable" }, 0 }
		};
	};
	class RifleAmmo
	{
		items[] = {
				{ { "RifleAmmo_Vanilla", "CfgLootTable" }, 20 },
				{ { "NL_RifleAmmo", "CfgLootTable" }, 6 },
				{ { "A2_RifleAmmo", "CfgLootTable" }, 20 },
				{ { "RifleAmmo_CUP", "CfgLootTable" }, 0 },
				{ { "RifleAmmo_MAD", "CfgLootTable" }, 0 }
		};
	};
	class SniperRifle
	{
		items[] = {
				{ { "SniperRifle_Vanilla", "CfgLootTable" }, 5 },
				{ { "SniperRifleMarkDLC", "CfgLootTable" }, 1 },
				{ { "SniperRifle_CUP", "CfgLootTable" }, 0 }
		};
	};
	class SniperRifleAmmo
	{
		items[] = {
				{ { "SniperRifleAmmo_Vanilla", "CfgLootTable" }, 5 },
				{ { "SniperRifleAmmoMarkDLC", "CfgLootTable" }, 1 },
				{ { "SniperRifleAmmo_CUP", "CfgLootTable" }, 0 }
		};
	};
	class Machinegun
	{
		items[] = {
				{ { "Machinegun_Vanilla", "CfgLootTable" }, 5 },
				{ { "MachinegunMarkDLC", "CfgLootTable" }, 1 },
				{ { "Machinegun_CUP", "CfgLootTable" }, 0 }
		};
	};
	class MachinegunAmmo
	{
		items[] = {
				{ { "MachinegunAmmo_Vanilla", "CfgLootTable" }, 5 },
				{ { "MachinegunAmmoMarkDLC", "CfgLootTable" }, 1 },
				{ { "MachinegunAmmo_CUP", "CfgLootTable" }, 0 }
		};
	};
	class Uniforms_Male_Civ
	{
		items[] = {
				{ { "Uniforms_Male_Civ_Vanilla", "CfgLootTable" }, 8 },
				{ { "Uniforms_Male_KartDLC", "CfgLootTable" }, 1 },
				{ { "Uniforms_Male_IdapDLC", "CfgLootTable" }, 1 }
		};
	};
	class Uniforms_Male_Mil
	{
		items[] = {
				{ { "Uniforms_Male_Mil_Vanilla", "CfgLootTable" }, 8 },
				{ { "Uniforms_Male_WetSuit", "CfgLootTable" }, 1 },
				{ { "Uniforms_Male_MarksDLC", "CfgLootTable" }, 1 },
				{ { "Uniforms_Male_ApexDLC", "CfgLootTable" }, 1 }
		};
	};
	class Uniforms_Female_Civ
	{
		items[] = {
				{ { "Uniforms_Female_Civ_Epoch", "CfgLootTable" }, 1 }
		};
	};
	class Uniforms_Female_Mil
	{
		items[] = {
				{ { "Uniforms_Female_Mil_Epoch", "CfgLootTable" }, 8 },
				{ { "Uniforms_Female_WetSuit_Epoch", "CfgLootTable" }, 1 }
		};
	};
	class Vests_Low
	{
		items[] = {
				{ { "Vests_Low_Vanilla", "CfgLootTable" }, 1 }
		};
	};
	class Vests_High
	{
		items[] = {
				{ { "Vests_High_Vanilla", "CfgLootTable" }, 8 },
				{ { "Vests_Rebreather_Epoch", "CfgLootTable" }, 1 },
				{ { "Vests_ApexDLC", "CfgLootTable" }, 1 }
		};
	};
	class BackPacks_Low
	{
		items[] = {
				{ { "Backpacks_Low_Base", "CfgLootTable" }, 1 }
		};
	};
	class BackPacks_High
	{
		items[] = {
				{ { "Backpacks_High_Base", "CfgLootTable" }, 10 },
				{ { "Backpacks_UAV", "CfgLootTable" }, 1 }
		};
	};
// DLC/Mod Related end

	class HeadgearNoArmor
	{
		items[] = {
				{ { "H_11_EPOCH", "item" }, 1 },
				{ { "H_28_EPOCH", "item" }, 1 },
				{ { "H_34_EPOCH", "item" }, 1 },
				{ { "H_39_EPOCH", "item" }, 1 },
				{ { "H_40_EPOCH", "item" }, 1 },
				{ { "H_41_EPOCH", "item" }, 1 },
				{ { "H_42_EPOCH", "item" }, 1 },
				{ { "H_43_EPOCH", "item" }, 1 },
				{ { "H_44_EPOCH", "item" }, 1 },
				{ { "H_45_EPOCH", "item" }, 1 },
				{ { "H_46_EPOCH", "item" }, 1 },
				{ { "H_47_EPOCH", "item" }, 1 },
				{ { "H_48_EPOCH", "item" }, 1 },
				{ { "H_49_EPOCH", "item" }, 1 },
				{ { "H_50_EPOCH", "item" }, 1 },
				{ { "H_51_EPOCH", "item" }, 1 },
				{ { "H_52_EPOCH", "item" }, 1 },
				{ { "H_53_EPOCH", "item" }, 1 },
				{ { "H_54_EPOCH", "item" }, 1 },
				{ { "H_55_EPOCH", "item" }, 1 },
				{ { "H_56_EPOCH", "item" }, 1 },
				{ { "H_57_EPOCH", "item" }, 1 },
				{ { "H_58_EPOCH", "item" }, 1 },
				{ { "H_59_EPOCH", "item" }, 1 },
				{ { "H_60_EPOCH", "item" }, 1 },
				{ { "H_61_EPOCH", "item" }, 1 },
				{ { "H_62_EPOCH", "item" }, 1 },
				{ { "H_63_EPOCH", "item" }, 1 },
				{ { "H_64_EPOCH", "item" }, 1 },
				{ { "H_65_EPOCH", "item" }, 1 },
				{ { "H_66_EPOCH", "item" }, 1 },
				{ { "H_67_EPOCH", "item" }, 1 },
				{ { "H_68_EPOCH", "item" }, 1 },
				{ { "H_69_EPOCH", "item" }, 1 },
				{ { "H_70_EPOCH", "item" }, 1 },
				{ { "H_71_EPOCH", "item" }, 1 },
				{ { "H_72_EPOCH", "item" }, 1 },
				{ { "H_73_EPOCH", "item" }, 1 },
				{ { "H_74_EPOCH", "item" }, 1 },
				{ { "H_75_EPOCH", "item" }, 1 },
				{ { "H_76_EPOCH", "item" }, 1 },
				{ { "H_77_EPOCH", "item" }, 1 },
				{ { "H_78_EPOCH", "item" }, 1 },
				{ { "H_79_EPOCH", "item" }, 1 },
				{ { "H_80_EPOCH", "item" }, 1 },
				{ { "H_81_EPOCH", "item" }, 1 },
				{ { "H_82_EPOCH", "item" }, 1 },
				{ { "H_83_EPOCH", "item" }, 1 },
				{ { "H_84_EPOCH", "item" }, 1 },
				{ { "H_85_EPOCH", "item" }, 1 },
				{ { "H_86_EPOCH", "item" }, 1 },
				{ { "H_87_EPOCH", "item" }, 1 },
				{ { "H_88_EPOCH", "item" }, 1 },
				{ { "H_89_EPOCH", "item" }, 1 },
				{ { "H_90_EPOCH", "item" }, 1 },
				{ { "H_91_EPOCH", "item" }, 1 },
				{ { "H_92_EPOCH", "item" }, 1 },
				{ { "H_104_EPOCH", "item" }, 1 },
                { { "H_105_EPOCH", "item" }, 1 },
				{ { "thor_mask_epoch", "item" }, 1, },
				{ { "iron_mask_epoch", "item" }, 1, },
				{ { "wolf_mask_epoch", "item" }, 1, {"getDate", 1, "==", 10} }, // only available in october
				{ { "pkin_mask_epoch", "item" }, 1, {"getDate", 1, "==", 10} }, // only available in october
				{ { "clown_mask_epoch", "item" }, 1, {"getDate", 1, "==", 10} }, // only available in october
				{ { "hockey_mask_epoch", "item" }, 1, {"getDate", 1, "==", 10} }, // only available in october
				{ { "plague_mask_epoch", "item" }, 1, {"getDate", 1, "==", 10} }, // only available in october
				{ { "ghostface_mask_epoch", "item" }, 1, {"getDate", 1, "==", 10} }, // only available in october
				{ { "skull_mask_epoch", "item" }, 1, {"getDate", 1, "==", 10} }, // only available in october
				{ { "witch_mask_epoch", "item" }, 1, {"getDate", 1, "==", 10} }, // only available in october
				{ { "radiation_mask_epoch", "item" }, 1 }
		};
	};
	class HeadgearArmored
	{
		items[] = {
				{ { "H_1_EPOCH", "item" }, 2 },
				{ { "H_2_EPOCH", "item" }, 2 },
				{ { "H_3_EPOCH", "item" }, 2 },
				{ { "H_4_EPOCH", "item" }, 2 },
				{ { "H_5_EPOCH", "item" }, 2 },
				{ { "H_6_EPOCH", "item" }, 2 },
				{ { "H_7_EPOCH", "item" }, 2 },
				{ { "H_8_EPOCH", "item" }, 2 },
				{ { "H_9_EPOCH", "item" }, 2 },
				{ { "H_10_EPOCH", "item" }, 2 },
				{ { "H_12_EPOCH", "item" }, 2 },
				{ { "H_13_EPOCH", "item" }, 2 },
				{ { "H_14_EPOCH", "item" }, 2 },
				{ { "H_15_EPOCH", "item" }, 2 },
				{ { "H_16_EPOCH", "item" }, 2 },
				{ { "H_17_EPOCH", "item" }, 2 },
				{ { "H_18_EPOCH", "item" }, 2 },
				{ { "H_19_EPOCH", "item" }, 2 },
				{ { "H_20_EPOCH", "item" }, 2 },
				{ { "H_21_EPOCH", "item" }, 2 },
				{ { "H_22_EPOCH", "item" }, 2 },
				{ { "H_23_EPOCH", "item" }, 2 },
				{ { "H_24_EPOCH", "item" }, 2 },
				{ { "H_25_EPOCH", "item" }, 2 },
				{ { "H_26_EPOCH", "item" }, 2 },
				{ { "H_27_EPOCH", "item" }, 2 },
				{ { "H_29_EPOCH", "item" }, 2 },
				{ { "H_30_EPOCH", "item" }, 2 },
				{ { "H_31_EPOCH", "item" }, 2 },
				{ { "H_32_EPOCH", "item" }, 2 },
				{ { "H_33_EPOCH", "item" }, 2 },
				{ { "H_35_EPOCH", "item" }, 2 },
				{ { "H_36_EPOCH", "item" }, 2 },
				{ { "H_37_EPOCH", "item" }, 2 },
				{ { "H_38_EPOCH", "item" }, 2 },
				{ { "H_93_EPOCH", "item" }, 1 },		// Race Hemlet
				{ { "H_94_EPOCH", "item" }, 1 },		// Race Hemlet
				{ { "H_95_EPOCH", "item" }, 1 },		// Race Hemlet
				{ { "H_96_EPOCH", "item" }, 1 },		// Race Hemlet
				{ { "H_97_EPOCH", "item" }, 1 },		// Race Hemlet
				{ { "H_98_EPOCH", "item" }, 1 },		// Race Hemlet
				{ { "H_99_EPOCH", "item" }, 1 },		// Race Hemlet
				{ { "H_100_EPOCH", "item" }, 1 },		// Race Hemlet
				{ { "H_101_EPOCH", "item" }, 1 },		// Race Hemlet
				{ { "H_102_EPOCH", "item" }, 1 },		// Race Hemlet
				{ { "H_103_EPOCH", "item" }, 1 }		// Race Hemlet
		};
	};
	class Primitive
	{
		items[] = {
				{ { "ItemRock", "magazine" }, 5 },
				{ { "ItemRope", "magazine" }, 2 },
				{ { "ItemStick", "magazine" }, 5 },
				{ { "ItemScraps", "magazine" }, 1 },
				{ { "ItemCanvas", "magazine" }, 1 },
				{ { "ItemBurlap", "magazine" }, 1 }
		};
	};
	class BuildingItems
	{
		items[] = {
				{ { "ItemMixOil", "magazine" }, 4 },
				{ { "CircuitParts", "magazine" }, 5 },
				{ { "CinderBlocks", "magazine" }, 5 },
				{ { "MortarBucket", "magazine" }, 15 },
				{ { "ItemCorrugated", "magazine" }, 10 },
				{ { "ItemCorrugatedLg", "magazine" }, 2 },
				{ { "ItemBulb", "magazine" }, 2 },
				{ { "ItemSolar", "magazine" }, 2 },
				{ { "ItemBattery", "magazine" }, 3 },
				{ { "ItemCables", "magazine" }, 3 },
				{ { "ItemPipe", "magazine" }, 2 },
				{ { "ItemBarrelE", "magazine" }, 1 },
				{ { "jerrycan_epoch", "magazine" }, 1 },
				{ { "jerrycanE_epoch", "magazine" }, 1 },
				{ { "JackKit", "magazine" }, 0 }
		};
	};
	class BuildingKits
	{
		items[] = {
				{ { "KitPlotPole", "magazine" }, 5 },
				{ { "KitSolarGen", "magazine" }, 2 },
				
				{ { "KitStudWall", "magazine" }, 13 },
				{ { "KitCinderWall", "magazine" }, 5 },
				
				{ { "KitWoodQuarterFloor", "magazine" }, 2 },
				{ { "KitWoodHalfFloor", "magazine" }, 2 },
				{ { "KitWoodFloor", "magazine" }, 8 },
				
				{ { "KitWoodStairs", "magazine" }, 9 },
				{ { "KitWoodTower", "magazine" }, 5 },
				{ { "KitWoodRamp", "magazine" }, 5 },
				{ { "KitTankTrap", "magazine" }, 2 },
				{ { "KitHesco3", "magazine" }, 1 },
				{ { "KitWoodLadder", "magazine" }, 5 },
				{ { "KitFirePlace", "magazine" }, 8 },
				{ { "KitFoundation", "magazine" }, 5 },
				{ { "KitWoodFoundation", "magazine" }, 14 }
		};
	};
	class Storages
	{
		items[] = {
				{ { "KitWorkbench", "magazine" }, 25 },
				{ { "KitShelf", "magazine" }, 20 },
				{ { "KitTiPi", "magazine" }, 15 },
				{ { "KitTentA", "magazine" }, 10 },
				{ { "KitTentDome", "magazine" }, 10 },
				{ { "ItemLockbox", "magazine" }, 10 },
				{ { "ItemSafe", "magazine" }, 6 },
//				{ { "ItemSafe_s", "magazine" }, 4 },	// Variant with less Load than the normal Safe
				{ { "ItemGunSafe", "magazine" }, 4 }
		};
	};
	class Equipment
	{
		items[] = {
				{ { "ItemWatch", "item" }, 30 },
				{ { "ItemCompass", "item" }, 20 },
				{ { "Binocular", "item" }, 10 },
				{ { "ItemGPS", "item" }, 9 },
				{ { "B_UavTerminal", "item" }, 5 },
				{ { "NVG_EPOCH", "item" }, 5 },
				{ { "Rangefinder", "weapon" }, 2 },
				{ { "EpochRadio0", "item" }, 2 },
				{ { "EpochRadio1", "item" }, 2 },
				{ { "EpochRadio2", "item" }, 2 },
				{ { "EpochRadio3", "item" }, 2 },
				{ { "EpochRadio4", "item" }, 2 },
				{ { "EpochRadio5", "item" }, 1 },
				{ { "EpochRadio6", "item" }, 1 },
				{ { "EpochRadio7", "item" }, 1 },
				{ { "EpochRadio8", "item" }, 1 },
				{ { "EpochRadio9", "item" }, 1 },
				{ { "ItemGeigerCounter_EPOCH", "item" }, 1 }
		};
	};
	class Tools
	{
		items[] = {
				{ { "Hatchet", "weapon" }, 40 },
				{ { "MeleeSledge", "weapon" }, 20 },
				{ { "ChainSaw", "weapon" }, 10 },
				{ { "Plunger", "weapon" }, 4 },
				{ { "MeleeSword", "weapon" }, 2 },
				{ { "Power_Sword", "weapon" }, 1 },
				{ { "MeleeRod", "weapon" }, 2 },
				{ { "lighter_epoch", "magazine" }, 1 },
				{ { "SmeltingTools_EPOCH", "magazine" }, 10 },
				{ { "ItemFireExtinguisher", "magazine" }, 1 }
		};
	};
	class Repairs
	{
		items[] = {
				{ { "VehicleRepair", "magazine" }, 30 },
				{ { "SpareTire", "magazine" }, 10 },
				{ { "EngineParts", "magazine" }, 7 },
				{ { "EngineBlock", "magazine" }, 3 },
				{ { "ItemGlass", "magazine" }, 3 },
				{ { "ItemDuctTape", "magazine" }, 10 },
				{ { "FuelTank", "magazine" }, 3 },
				{ { "ItemRotor", "magazine" }, 3 }
		};
	};
	class VehicleDocs
	{
		items[] = {
				{ { "ItemDocument", "magazine" }, 20 },
				{ { "ItemVehDoc1", "magazine" }, 20 },
				{ { "ItemVehDoc2", "magazine" }, 15 },
				{ { "ItemVehDoc3", "magazine" }, 5 },
				{ { "ItemVehDoc4", "magazine" }, 2 }
		};
	};
	class Seeds
	{
		items[] = {
				{ { "ItemSeedBag", "magazine" }, 10 },
				{ { "SeedPacket_Hemp", "magazine" }, 1 },
				{ { "SeedPacket_GoldenSeal", "magazine" }, 1 },
				{ { "SeedPacket_Poppy", "magazine" }, 1 },
				{ { "SeedPacket_Pumpkin", "magazine" }, 2 },
				{ { "SeedPacket_Sunflower", "magazine" }, 2 }
		};
	};
	class Drink
	{
		items[] = {
				{ { "ItemCanteen_Empty", "magazine" }, 5 },
				{ { "ItemCanteen_Dirty", "magazine" }, 5 },
				{ { "ItemCanteen_Clean", "magazine" }, 1 },
				{ { "ItemBottlePlastic_Empty", "magazine" }, 5 },
				{ { "ItemBottlePlastic_Dirty", "magazine" }, 5 },
				{ { "ItemBottlePlastic_Clean", "magazine" }, 1 },
				{ { "WhiskeyNoodle", "magazine" }, 5 },
				{ { "ItemSodaOrangeSherbet", "magazine" }, 13 },
				{ { "ItemSodaAlpineDude", "magazine" }, 6 },
				{ { "ItemSodaPurple", "magazine" }, 13 },
				{ { "ItemSodaMocha", "magazine" }, 12 },
				{ { "ItemSodaBurst", "magazine" }, 15 },
				{ { "ItemSodaRbull", "magazine" }, 13 },
				{ { "FoodWalkNSons", "magazine" }, 13 },
				{ { "ItemSodaEmpty", "magazine" }, 11 }
		};
	};
	class Food
	{
		items[] = {
				{ { "ItemCoolerE", "magazine" }, 3 },
				{ { "bluburger_epoch", "magazine" }, 4 },
				{ { "redburger_epoch", "magazine" }, 4 },
				{ { "gyro_wrap_epoch", "magazine" }, 4 },
				{ { "icecream_epoch", "magazine" }, 3 },
				{ { "ItemPowderMilk", "magazine" }, 3 },
				{ { "ItemRicebox", "magazine" }, 3 },
				{ { "ItemCereals", "magazine" }, 3 },
				{ { "ItemVitamins", "magazine" }, 3 },
				{ { "honey_epoch", "magazine" }, 5 },
				{ { "emptyjar_epoch", "magazine" }, 13 },
				{ { "water_epoch", "magazine" }, 3 },
				{ { "clean_water_epoch", "magazine" }, 1 },
				{ { "FoodBioMeat", "magazine" }, 11 },
				{ { "sardines_epoch", "magazine" }, 11 },
				{ { "meatballs_epoch", "magazine" }, 13 },
				{ { "scam_epoch", "magazine" }, 14 },
				{ { "sweetcorn_epoch", "magazine" }, 14 },
				{ { "FoodSnooter", "magazine" }, 5 },
				{ { "krypto_candy_epoch", "magazine" }, 4 },
				{ { "TacticalBacon", "magazine" }, 5 },
				{ { "FoodMeeps", "magazine" }, 1 },
				{ { "ItemEmptyTin", "magazine" }, 5 },
				{ { "ItemBakedBeans", "magazine" }, 3 },
				{ { "HotAxeSauce_epoch", "magazine" }, 1 }
		};
	};
	class Medical
	{
		items[] = {
				{ { "ItemDefibrillator", "magazine" }, 1 },
				{ { "FAK", "magazine" }, 50 },
				{ { "Soap_Epoch", "magazine" }, 3 },
				{ { "atropine_epoch", "magazine" }, 6 },
				{ { "adrenaline_epoch", "magazine" }, 5 },
				{ { "morphine_epoch", "magazine" }, 3 },
				{ { "caffeinepills_epoch", "magazine" }, 10 },
				{ { "orlistat_epoch", "magazine" }, 5 },
				{ { "nanite_cream_epoch", "magazine" }, 3 },
				{ { "nanite_gun_epoch", "magazine" }, 1 },
				{ { "nanite_pills_epoch", "magazine" }, 5 },
				{ { "iodide_pills_epoch", "magazine" }, 5 },
				{ { "ItemWaterPurificationTablets", "magazine" }, 5 },
				{ { "HeatPack", "magazine" }, 1 },
				{ { "ColdPack", "magazine" }, 1 },
				{ { "Towelette", "magazine" }, 8 }
		};
	};
	class PaintCans
	{
		items[] = {
				{ { "PaintCanClear", "magazine" }, 1 },
				{ { "PaintCanBlk", "magazine" }, 1 },
				{ { "PaintCanBlu", "magazine" }, 1 },
				{ { "PaintCanBrn", "magazine" }, 1 },
				{ { "PaintCanGrn", "magazine" }, 1 },
				{ { "PaintCanOra", "magazine" }, 1 },
				{ { "PaintCanPur", "magazine" }, 1 },
				{ { "PaintCanRed", "magazine" }, 1 },
				{ { "PaintCanTeal", "magazine" }, 1 },
				{ { "PaintCanYel", "magazine" }, 1 }
		};
	};
	class MetalBars
	{
		items[] = {
				{ { "ItemGoldBar10oz", "magazine" }, 1 },
				{ { "ItemGoldBar", "magazine" }, 9 },
				{ { "ItemSilverBar", "magazine" }, 20 },
				{ { "ItemCopperBar", "magazine" }, 20 },
				{ { "ItemAluminumBar", "magazine" }, 20 },
				{ { "ItemTinBar", "magazine" }, 30 }
		};
	};
	class Gems
	{
		items[] = {
				{ { "ItemJade", "magazine" }, 5 },
				{ { "ItemRuby", "magazine" }, 8 },
				{ { "ItemSapphire", "magazine" }, 9 },
				{ { "ItemTopaz", "magazine" }, 10 },
				{ { "ItemOnyx", "magazine" }, 10 },
				{ { "ItemAmethyst", "magazine" }, 10 },
				{ { "ItemEmerald", "magazine" }, 10 },
				{ { "ItemCitrine", "magazine" }, 10 },
				{ { "ItemGarnet", "magazine" }, 13 },
				{ { "ItemQuartz", "magazine" }, 15 }
		};
	};
	class Ore
	{
		items[] = {
				{ { "PartOreGold", "magazine" }, 20 },
				{ { "PartOreSilver", "magazine" }, 30 },
				{ { "PartOre", "magazine" }, 35 }
		};
	};
	class Throw
	{
		items[] = {
				{ { "SmokeShell", "magazine" }, 1 },
				{ { "SmokeShellYellow", "magazine" }, 1 },
				{ { "SmokeShellGreen", "magazine" }, 1 },
                { { "SmokeShellToxic", "magazine" }, 1 },
				{ { "SmokeShellRed", "magazine" }, 1 },
				{ { "SmokeShellPurple", "magazine" }, 1 },
				{ { "SmokeShellOrange", "magazine" }, 1 },
				{ { "SmokeShellBlue", "magazine" }, 1 },
				{ { "Chemlight_green", "magazine" }, 1 },
				{ { "Chemlight_red", "magazine" }, 1 },
				{ { "Chemlight_yellow", "magazine" }, 1 },
				{ { "Chemlight_blue", "magazine" }, 1 }
		};
	};
	class ThrowExplosive
	{
		items[] = {
				{ { "HandGrenade", "magazine" }, 25 },
				{ { "MiniGrenade", "magazine" }, 25 }
		};
	};
	class HighExplosives
	{
		items[] = {
				{ { "SatchelCharge_Remote_Mag", "magazine" }, 15 },
				{ { "ATMine_Range_Mag", "magazine" }, 5 },
				{ { "SLAMDirectionalMine_Wire_Mag", "magazine" }, 3 },
				{ { "DemoCharge_Remote_Mag", "magazine" }, 6 },
				{ { "ClaymoreDirectionalMine_Remote_Mag", "magazine" }, 10 },
				{ { "APERSBoundingMine_Range_Mag", "magazine" }, 21 },
				{ { "APERSTripMine_Wire_Mag", "magazine" }, 20 },
				{ { "APERSMine_Range_Mag", "magazine" }, 20 }
		};
	};
	class ShellFlares
	{
		items[] = {
				{ { "3Rnd_UGL_FlareWhite_F", "magazine" }, 1 },
				{ { "3Rnd_UGL_FlareGreen_F", "magazine" }, 1 },
				{ { "3Rnd_UGL_FlareRed_F", "magazine" }, 1 },
				{ { "3Rnd_UGL_FlareYellow_F", "magazine" }, 1 },
				{ { "3Rnd_UGL_FlareCIR_F", "magazine" }, 1 },
				{ { "UGL_FlareWhite_F", "magazine" }, 1 },
				{ { "UGL_FlareGreen_F", "magazine" }, 1 },
				{ { "UGL_FlareRed_F", "magazine" }, 1 },
				{ { "UGL_FlareYellow_F", "magazine" }, 1 },
				{ { "UGL_FlareCIR_F", "magazine" }, 1 }
		};
	};
	class ShellSmokes
	{
		items[] = {
				{ { "1Rnd_Smoke_Grenade_shell", "magazine" }, 1 },
				{ { "1Rnd_SmokeRed_Grenade_shell", "magazine" }, 1 },
				{ { "1Rnd_SmokeGreen_Grenade_shell", "magazine" }, 1 },
				{ { "1Rnd_SmokeYellow_Grenade_shell", "magazine" }, 1 },
				{ { "1Rnd_SmokePurple_Grenade_shell", "magazine" }, 1 },
				{ { "1Rnd_SmokeBlue_Grenade_shell", "magazine" }, 1 },
				{ { "1Rnd_SmokeOrange_Grenade_shell", "magazine" }, 1 },
				{ { "3Rnd_Smoke_Grenade_shell", "magazine" }, 1 },
				{ { "3Rnd_SmokeRed_Grenade_shell", "magazine" }, 1 },
				{ { "3Rnd_SmokeGreen_Grenade_shell", "magazine" }, 1 },
				{ { "3Rnd_SmokeYellow_Grenade_shell", "magazine" }, 1 },
				{ { "3Rnd_SmokePurple_Grenade_shell", "magazine" }, 1 },
				{ { "3Rnd_SmokeBlue_Grenade_shell", "magazine" }, 1 },
				{ { "3Rnd_SmokeOrange_Grenade_shell", "magazine" }, 1 }
		};
	};
	class ShellExplosives
	{
		items[] = {
				{ { "1Rnd_HE_Grenade_shell", "magazine" }, 1 },
				{ { "3Rnd_HE_Grenade_shell", "magazine" }, 1 }
		};
	};

// ########################################################################### Base Classes ###########################################################################

	class Scopes_Vanilla
	{
		items[] = {
				{ { "optic_NVS", "item" }, 1 },
				{ { "optic_tws", "item" }, 1 },
				{ { "optic_tws_mg", "item" }, 1 },
				{ { "optic_SOS", "item" }, 2 },
				{ { "optic_LRPS", "item" }, 2 },
				{ { "optic_DMS", "item" }, 3 },
				{ { "optic_Arco", "item" }, 4 },
				{ { "optic_Hamr", "item" }, 5 },
				{ { "Elcan_epoch", "item" }, 5 },
				{ { "Elcan_reflex_epoch", "item" }, 5 },
				{ { "optic_MRCO", "item" }, 6 },
				{ { "optic_Holosight", "item" }, 6 },
				{ { "optic_Holosight_smg", "item" }, 6 },
				{ { "optic_Aco", "item" }, 7 },
				{ { "optic_ACO_grn", "item" }, 7 },
				{ { "optic_Aco_smg", "item" }, 7 },
				{ { "optic_ACO_grn_smg", "item" }, 8 },
				{ { "optic_Yorris", "item" }, 10 },
				{ { "optic_MRD", "item" }, 10 }
		};
	};
	class Scopes_MarkDLC
	{
		items[] = {
				{ { "optic_AMS", "item" }, 2 },
				{ { "optic_AMS_khk", "item" }, 1 },
				{ { "optic_AMS_snd", "item" }, 1 },
				{ { "optic_KHS_blk", "item" }, 1 },
				{ { "optic_KHS_hex", "item" }, 1 },
				{ { "optic_KHS_old", "item" }, 2 },
				{ { "optic_KHS_tan", "item" }, 1 }
		};
	};
	class Scopes_CUP
	{
		items[] = {
				{ { "CUP_optic_PSO_1", "item" }, 1 },
				{ { "CUP_optic_PSO_3", "item" }, 1 },
				{ { "CUP_optic_Kobra", "item" }, 1 },
				{ { "CUP_optic_GOSHAWK", "item" }, 1 },
				{ { "CUP_optic_NSPU", "item" }, 1 },
				{ { "CUP_optic_PechenegScope", "item" }, 1 },
				{ { "CUP_optic_SB_3_12x50_PMII", "item" }, 1 },
				{ { "CUP_optic_AN_PAS_13c2", "item" }, 1 },
				{ { "CUP_optic_LeupoldMk4", "item" }, 1 },
				{ { "CUP_optic_HoloBlack", "item" }, 1 },
				{ { "CUP_optic_HoloWdl", "item" }, 1 },
				{ { "CUP_optic_HoloDesert", "item" }, 1 },
				{ { "CUP_optic_Eotech533", "item" }, 1 },
				{ { "CUP_optic_Eotech533Grey", "item" }, 1 },
				{ { "CUP_optic_CompM4", "item" }, 1 },
				{ { "CUP_optic_SUSAT", "item" }, 1 },
				{ { "CUP_optic_ACOG", "item" }, 1 },
				{ { "CUP_optic_CWS", "item" }, 1 },
				{ { "CUP_optic_Leupold_VX3", "item" }, 1 },
				{ { "CUP_optic_AN_PVS_10", "item" }, 1 },
				{ { "CUP_optic_CompM2_Black", "item" }, 1 },
				{ { "CUP_optic_CompM2_Woodland", "item" }, 1 },
				{ { "CUP_optic_CompM2_Woodland2", "item" }, 1 },
				{ { "CUP_optic_CompM2_Desert", "item" }, 1 },
				{ { "CUP_optic_RCO", "item" }, 1 },
				{ { "CUP_optic_RCO_desert", "item" }, 1 },
				{ { "CUP_optic_LeupoldM3LR", "item" }, 1 },
				{ { "CUP_optic_LeupoldMk4_10x40_LRT_Desert", "item" }, 1 },
				{ { "CUP_optic_LeupoldMk4_10x40_LRT_Woodland", "item" }, 1 },
				{ { "CUP_optic_ElcanM145", "item" }, 1 },
				{ { "CUP_optic_AN_PAS_13c1", "item" }, 1 },
				{ { "CUP_optic_LeupoldMk4_CQ_T", "item" }, 1 },
				{ { "CUP_optic_ELCAN_SpecterDR", "item" }, 1 },
				{ { "CUP_optic_LeupoldMk4_MRT_tan", "item" }, 1 },
				{ { "CUP_optic_SB_11_4x20_PM", "item" }, 1 },
				{ { "CUP_optic_ZDDot", "item" }, 1 },
				{ { "CUP_optic_MRad", "item" }, 1 },
				{ { "CUP_optic_TrijiconRx01_desert", "item" }, 1 },
				{ { "CUP_optic_TrijiconRx01_black", "item" }, 1 },
				{ { "CUP_optic_AN_PVS_4", "item" }, 1 }
		};
	};
	class Bipods_Vanilla
	{
		items[] = {
				{ { "bipod_01_F_snd", "item" }, 1 },
				{ { "bipod_01_F_blk", "item" }, 1 },
				{ { "bipod_01_F_mtp", "item" }, 1 },
				{ { "bipod_02_F_blk", "item" }, 1 },
				{ { "bipod_02_F_tan", "item" }, 1 },
				{ { "bipod_02_F_hex", "item" }, 1 },
				{ { "bipod_03_F_blk", "item" }, 1 },
				{ { "bipod_03_F_oli", "item" }, 1 }
		};
	};
	class Bipods_CUP
	{
		items[] = {
				{ { "CUP_bipod_Harris_1A2_L", "item" }, 1 },
				{ { "CUP_bipod_VLTOR_Modpod", "item" }, 1 }
		};
	};
	class Muzzles_Vanilla
	{
		items[] = {
				{ { "muzzle_sr25S_epoch", "item" }, 1 },
				{ { "muzzle_snds_H", "item" }, 1 },
				{ { "muzzle_snds_M", "item" }, 1 },
				{ { "muzzle_snds_L", "item" }, 1 },
				{ { "muzzle_snds_B", "item" }, 1 },
				{ { "muzzle_snds_H_MG", "item" }, 1 },
				{ { "muzzle_snds_acp", "item" }, 1 },
				{ { "Muzzles_MultiGun", "CfgLootTable" }, 1 }
		};
	};
	class Muzzles_MarkDLC
	{
		items[] = {
				{ { "muzzle_snds_570", "item" }, 1 },
				{ { "muzzle_snds_338_black", "item" }, 1 },
				{ { "muzzle_snds_338_green", "item" }, 1 },
				{ { "muzzle_snds_338_sand", "item" }, 1 },
				{ { "muzzle_snds_93mmg", "item" }, 1 },
				{ { "muzzle_snds_93mmg_tan", "item" }, 1 }
		};
	};
	class Muzzles_CUP
	{
		items[] = {
				{ { "CUP_muzzle_snds_M110", "item" }, 1 },
				{ { "CUP_muzzle_snds_M14", "item" }, 1 },
				{ { "CUP_muzzle_PBS4", "item" }, 1 },
				{ { "CUP_muzzle_PB6P9", "item" }, 1 },
				{ { "CUP_muzzle_Bizon", "item" }, 1 },
				{ { "CUP_muzzle_snds_M9", "item" }, 1 },
				{ { "CUP_muzzle_snds_MicroUzi", "item" }, 1 },
				{ { "CUP_muzzle_snds_AWM", "item" }, 1 },
				{ { "CUP_muzzle_snds_G36_black", "item" }, 1 },
				{ { "CUP_muzzle_snds_G36_desert", "item" }, 1 },
				{ { "CUP_muzzle_snds_L85", "item" }, 1 },
				{ { "CUP_muzzle_snds_M16_camo", "item" }, 1 },
				{ { "CUP_muzzle_snds_M16", "item" }, 1 },
				{ { "CUP_muzzle_snds_SCAR_L", "item" }, 1 },
				{ { "CUP_muzzle_mfsup_SCAR_L", "item" }, 1 },
				{ { "CUP_muzzle_snds_SCAR_H", "item" }, 1 },
				{ { "CUP_muzzle_mfsup_SCAR_H", "item" }, 1 },
				{ { "CUP_muzzle_snds_XM8", "item" }, 1 }
		};
	};
	class Muzzles_MultiGun
	{
		items[] = {
				{ { "Heal_EPOCH", "item" }, 1 },
				{ { "Defib_EPOCH", "item" }, 1 },
				{ { "Repair_EPOCH", "item" }, 1 }
		};
	};
	class WpnFlashLights_Vanilla
	{
		items[] = {
				{ { "acc_flashlight", "item" }, 1 },
				{ { "acc_flashlight_pistol", "item" }, 1 },
				{ { "acc_pointer_IR", "item" }, 1 }
		};
	};
	class WpnFlashLights_CUP
	{
		items[] = {
				{ { "CUP_acc_Glock17_Flashlight", "item" }, 1 },
				{ { "CUP_acc_ANPEQ_15", "item" }, 1 },
				{ { "CUP_acc_ANPEQ_2", "item" }, 1 },
				{ { "CUP_acc_Flashlight", "item" }, 1 },
				{ { "CUP_acc_Flashlight_wdl", "item" }, 1 },
				{ { "CUP_acc_Flashlight_desert", "item" }, 1 },
				{ { "CUP_acc_XM8_light_module", "item" }, 1 },
				{ { "CUP_acc_ANPEQ_2_camo", "item" }, 1 },
				{ { "CUP_acc_ANPEQ_2_desert", "item" }, 1 },
				{ { "CUP_acc_ANPEQ_2_grey", "item" }, 1 },
				{ { "CUP_acc_CZ_M3X", "item" }, 1 }
		};
	};
	class SniperCamo_CUP
	{
		items[] = {
				{ { "CUP_Mxx_camo", "item" }, 1 },
				{ { "CUP_Mxx_camo_half", "item" }, 1 },
				{ { "CUP_SVD_camo_g", "item" }, 1 },
				{ { "CUP_SVD_camo_g_half", "item" }, 1 },
				{ { "CUP_SVD_camo_d", "item" }, 1 },
				{ { "CUP_SVD_camo_d_half", "item" }, 1 }

		};
	};
	class Pistols_Vanilla
	{
		items[] = {
				{ { "hgun_Pistol_Signal_F", "weapon" }, 4 },
				{ { "MultiGun", "weapon" }, 5 },
				{ { "hgun_Pistol_heavy_01_F", "weapon" }, 9 },
				{ { "hgun_P07_F", "weapon" }, 10 },
				{ { "hgun_Rook40_F", "weapon" }, 11 },
				{ { "hgun_Pistol_heavy_02_F", "weapon" }, 13 },
				{ { "1911_pistol_epoch", "weapon" }, 14 },
				{ { "hgun_ACPC2_F", "weapon" }, 16 },
				{ { "ruger_pistol_epoch", "weapon" }, 18 }
		};
	};
	class NL_Pistols
	{
		items[] = {
				{ { "hgun_Pistol_tranq_01", "weapon" }, 1 }
		};
	};
	class PistolAmmo_Vanilla
	{
		items[] = {
				{ { "EnergyPack", "magazine" }, 4 },
				{ { "6Rnd_RedSignal_F", "magazine" }, 2 },
				{ { "6Rnd_GreenSignal_F", "magazine" }, 2 },
				{ { "30Rnd_9x21_Mag", "magazine" }, 10 },
				{ { "6Rnd_45ACP_Cylinder", "magazine" }, 11 },
				{ { "16Rnd_9x21_Mag", "magazine" }, 11 },
				{ { "11Rnd_45ACP_Mag", "magazine" }, 12 },
				{ { "9Rnd_45ACP_Mag", "magazine" }, 16 },
				{ { "9rnd_45X88_magazine", "magazine" }, 16 },
				{ { "10rnd_22X44_magazine", "magazine" }, 16 }
		};
	};
	class NL_PistolAmmo
	{
		items[] = {
				{ { "tranq_dart_mag", "magazine" }, 1 }
		};
	};
	class Pistols_CUP
	{
		items[] = {
				{ { "CUP_hgun_Compact", "weapon" }, 1 },
				{ { "CUP_hgun_Duty", "weapon" }, 1 },
				{ { "CUP_hgun_Phantom", "weapon" }, 1 },
				{ { "CUP_hgun_Glock17", "weapon" }, 1 },
				{ { "CUP_hgun_Makarov", "weapon" }, 1 },
				{ { "CUP_hgun_MicroUzi", "weapon" }, 1 },
				{ { "CUP_hgun_TaurusTracker455", "weapon" }, 1 },
				{ { "CUP_hgun_PB6P9", "weapon" }, 1 },
				{ { "CUP_hgun_SA61", "weapon" }, 1 },
				{ { "CUP_hgun_M9", "weapon" }, 1 },
				{ { "CUP_hgun_TaurusTracker455_gold", "weapon" }, 1 },
				{ { "CUP_hgun_Colt1911", "weapon" }, 1 }
		};
	};
	class PistolAmmo_CUP
	{
		items[] = {
				{ { "CUP_10Rnd_9x19_Compact", "magazine" }, 2 },
				{ { "CUP_18Rnd_9x19_Phantom", "magazine" }, 1 },
				{ { "CUP_17Rnd_9x19_glock17", "magazine" }, 1 },
				{ { "CUP_8Rnd_9x18_Makarov_M", "magazine" }, 2 },
				{ { "CUP_8Rnd_9x18_MakarovSD_M", "magazine" }, 2 },
				{ { "CUP_30Rnd_9x19_UZI", "magazine" }, 1 },
				{ { "CUP_6Rnd_45ACP_M", "magazine" }, 3 },
				{ { "CUP_20Rnd_B_765x17_Ball_M", "magazine" }, 1 },
				{ { "CUP_15Rnd_9x19_M9", "magazine" }, 1 },
				{ { "CUP_7Rnd_45ACP_1911", "magazine" }, 2 }
		};
	};
	class Pistols_MAD
	{
		items[] = {
                { { "revolver01", "weapon" }, 17 }
		};
	};
	class Rifle_Vanilla
	{
		items[] = {
				{ { "AKM_EPOCH", "weapon" }, 3 },
				{ { "sr25_epoch", "weapon" }, 4 },

				{ { "arifle_Katiba_GL_F", "weapon" }, 2 },
				{ { "arifle_Katiba_C_F", "weapon" }, 3 },
				{ { "arifle_Katiba_F", "weapon" }, 5 },

				{ { "arifle_MX_GL_F", "weapon" }, 3 },
				{ { "arifle_MX_GL_Black_F", "weapon" }, 2 },
				{ { "arifle_MXM_Black_F", "weapon" }, 2 },
				{ { "arifle_MXC_Black_F", "weapon" }, 3 },
				{ { "arifle_MX_Black_F", "weapon" }, 2 },
				{ { "arifle_MXM_F", "weapon" }, 3 },
				{ { "arifle_MXC_F", "weapon" }, 3 },
				{ { "arifle_MX_F", "weapon" }, 3 },

				{ { "l85a2_epoch", "weapon" }, 1 },
				{ { "l85a2_pink_epoch", "weapon" }, 1 },
				{ { "l85a2_ugl_epoch", "weapon" }, 1 },

				{ { "m4a3_EPOCH", "weapon" }, 7 },

				{ { "m16_EPOCH", "weapon" }, 2 },
				{ { "m16Red_EPOCH", "weapon" }, 1 },

				{ { "arifle_Mk20_GL_F", "weapon" }, 12 },
				{ { "arifle_Mk20_GL_plain_F", "weapon" }, 12 },
				{ { "arifle_Mk20C_F", "weapon" }, 16 },
				{ { "arifle_Mk20C_plain_F", "weapon" }, 18 },
				{ { "arifle_Mk20_F", "weapon" }, 20 },
				{ { "arifle_Mk20_plain_F", "weapon" }, 22 },

				{ { "arifle_TRG21_GL_F", "weapon" }, 2 },
				{ { "arifle_TRG21_F", "weapon" }, 3 },
				{ { "arifle_TRG20_F", "weapon" }, 5 },

				{ { "arifle_SDAR_F", "weapon" }, 9 },
				{ { "Rollins_F", "weapon" }, 9 },
				{ { "SMG_01_F", "weapon" }, 9 },
				{ { "SMG_02_F", "weapon" }, 9 },

				{ { "SMG_03_TR_black", "weapon" }, 1 },
				{ { "SMG_03_TR_camo", "weapon" }, 1 },
				{ { "SMG_03_TR_khaki", "weapon" }, 1 },
				{ { "SMG_03_TR_hex", "weapon" }, 1 },
				{ { "SMG_03C_TR_black", "weapon" }, 1 },
				{ { "SMG_03C_TR_camo", "weapon" }, 1 },
				{ { "SMG_03C_TR_khaki", "weapon" }, 1 },
				{ { "SMG_03C_TR_hex", "weapon" }, 1 },
				{ { "SMG_03_black", "weapon" }, 1 },
				{ { "SMG_03_camo", "weapon" }, 1 },
				{ { "SMG_03_khaki", "weapon" }, 1 },
				{ { "SMG_03_hex", "weapon" }, 1 },
				{ { "SMG_03C_black", "weapon" }, 1 },
				{ { "SMG_03C_camo", "weapon" }, 1 },
				{ { "SMG_03C_khaki", "weapon" }, 1 },
				{ { "SMG_03C_hex", "weapon" }, 1 },

				{ { "hgun_PDW2000_F", "weapon" }, 10 },
				{ { "speargun_epoch", "weapon" }, 5 }
		};
	};
	class RifleAmmo_Vanilla
	{
		items[] = {
				{ { "30Rnd_762x39_Mag", "magazine" }, 8 },
				
				{ { "30Rnd_65x39_caseless_mag", "magazine" }, 3 },
				{ { "30Rnd_65x39_caseless_mag_Tracer", "magazine" }, 2 },
				{ { "30Rnd_65x39_caseless_green", "magazine" }, 3 },
				{ { "30Rnd_65x39_caseless_green_mag_Tracer", "magazine" }, 2 },
				
				{ { "20Rnd_556x45_UW_mag", "magazine" }, 12 },
				
				{ { "30Rnd_556x45_Stanag", "magazine" }, 4 },
				{ { "30Rnd_556x45_Stanag_Tracer_Red", "magazine" }, 2 },
				{ { "30Rnd_556x45_Stanag_Tracer_Green", "magazine" }, 2 },
				{ { "30Rnd_556x45_Stanag_Tracer_Yellow", "magazine" }, 2 },
				
				{ { "30Rnd_45ACP_Mag_SMG_01", "magazine" }, 5 },
				{ { "30Rnd_45ACP_Mag_SMG_01_Tracer_Green", "magazine" }, 5 },

				{ { "30Rnd_9x21_Mag", "magazine" }, 10 },
				{ { "5Rnd_rollins_mag", "magazine" }, 10 },
				{ { "50Rnd_570x28_SMG_03", "magazine" }, 10 },
				
				{ { "spear_magazine", "magazine" }, 2 }
		};
	};
	class NL_RifleAmmo
	{
		items[] = {
				{ { "NL_pvc_bb_mag", "magazine" }, 5 },
				{ { "NL_shot_bb_mag", "magazine" }, 5 },
				{ { "xbow_mag_bolt", "magazine" }, 5 },
				{ { "xbow_mag_tranq", "magazine" }, 5 },
				{ { "xbow_mag_exp", "magazine" }, 2 }
		};
	};
	class A2_Rifle
	{
		items[] = {
				{ { "a2_ak47s_gold_EPOCH", "weapon" }, 1 },
				{ { "a2_AK107_EPOCH", "weapon" }, 1 },
				{ { "a2_bizon_epoch", "weapon" }, 1 },
				{ { "a2_dmr_epoch", "weapon" }, 1 },
				{ { "a2_dmr_epoch_scoped", "weapon" }, 1 },
				{ { "a2_fnfal_epoch", "weapon" }, 1 },
				{ { "a2_G36_C_epoch", "weapon" }, 1 },
				{ { "a2_Mg36_epoch", "weapon" }, 1 },
				{ { "a2_leeenfield_epoch", "weapon" }, 1 },
				{ { "a2_m110_epoch", "weapon" }, 1 },
				{ { "a2_mk16_epoch", "weapon" }, 1 },
				{ { "a2_mk17_epoch", "weapon" }, 1 },
				{ { "a2_svd_epoch", "weapon" }, 1 },
				{ { "a2_VSS_vintorez_epoch", "weapon" }, 1 },
				{ { "a2_aks74un_EPOCH", "weapon" }, 1 }
		};
	};
	class NL_Rifle
	{
		items[] = {
				{ { "pvcrifle_01_F", "weapon" }, 1 },
				{ { "nl_Shotgun", "weapon" }, 1 },
				{ { "nl_auto_xbow", "weapon" }, 1 }
		};
	};
	class A2_RifleAmmo
	{
		items[] = {
				{ { "Bizon_64Rnd_9x18", "magazine" }, 2 },
				{ { "20Rnd_762x51_DMR", "magazine" }, 2 },
				{ { "20Rnd_762x51_FNFAL", "magazine" }, 2 },
				{ { "30Rnd_556x45_G36", "magazine" }, 2 },
				{ { "10Rnd_303", "magazine" }, 2 },
				{ { "100Rnd_556x45_BetaCMag", "magazine" }, 2 },
				{ { "10Rnd_762x54_SVD", "magazine" }, 2 },
				{ { "10Rnd_9x39_SP5_VSS", "magazine" }, 2 }
		};
	};
	class Rifle_CUP
	{
		items[] = {
			{ { "CUP_smg_bizon", "weapon" }, 1 },
			{ { "CUP_smg_EVO", "weapon" }, 1 },
			{ { "CUP_smg_MP5SD6", "weapon" }, 1 },
			{ { "CUP_smg_MP5A5", "weapon" }, 1 },

			{ { "CUP_sgun_AA12", "weapon" }, 1 },
			{ { "CUP_sgun_M1014", "weapon" }, 1 },
			{ { "CUP_sgun_Saiga12K", "weapon" }, 1 },

			{ { "CUP_arifle_AK74", "weapon" }, 1 },
			{ { "CUP_arifle_AK74M", "weapon" }, 1 },
			{ { "CUP_arifle_AK74M_GL", "weapon" }, 1 },
			{ { "CUP_arifle_AK74_GL", "weapon" }, 1 },
			{ { "CUP_arifle_AK74_GL_kobra", "weapon" }, 1 },
			{ { "CUP_arifle_AKS", "weapon" }, 1 },
			{ { "CUP_arifle_AKS_Gold", "weapon" }, 1 },
			{ { "CUP_arifle_AKS74", "weapon" }, 1 },
			{ { "CUP_arifle_AKS74U", "weapon" }, 1 },
			{ { "CUP_arifle_AK107", "weapon" }, 1 },
			{ { "CUP_arifle_AK107_GL", "weapon" }, 1 },
			{ { "CUP_arifle_AKM", "weapon" }, 1 },

			{ { "CUP_arifle_CZ805_A1", "weapon" }, 1 },
			{ { "CUP_arifle_CZ805_GL", "weapon" }, 1 },
			{ { "CUP_arifle_CZ805_A2", "weapon" }, 1 },
			{ { "CUP_arifle_CZ805_B", "weapon" }, 1 },
			{ { "CUP_arifle_CZ805_B_GL", "weapon" }, 1 },
			
			{ { "CUP_arifle_FNFAL", "weapon" }, 1 },
			{ { "CUP_arifle_FNFAL_railed", "weapon" }, 1 },
			{ { "CUP_arifle_FNFAL5061", "weapon" }, 1 },
			{ { "CUP_arifle_FNFAL5062", "weapon" }, 1 },
			{ { "CUP_arifle_FNFAL_OSW", "weapon" }, 1 },
			
			{ { "CUP_arifle_G36A", "weapon" }, 1 },
			{ { "CUP_arifle_G36A_camo", "weapon" }, 1 },
			{ { "CUP_arifle_G36K", "weapon" }, 1 },
			{ { "CUP_arifle_G36K_camo", "weapon" }, 1 },
			{ { "CUP_arifle_G36C", "weapon" }, 1 },
			{ { "CUP_arifle_G36C_camo", "weapon" }, 1 },
			
			{ { "CUP_arifle_L85A2", "weapon" }, 1 },
			{ { "CUP_arifle_L85A2_GL", "weapon" }, 1 },
			
			{ { "CUP_arifle_M16A2", "weapon" }, 1 },
			{ { "CUP_arifle_M16A2_GL", "weapon" }, 1 },
			{ { "CUP_arifle_M16A4_Base", "weapon" }, 1 },
			{ { "CUP_arifle_M16A4_GL", "weapon" }, 1 },
			
			{ { "CUP_arifle_M4A1_BUIS_GL", "weapon" }, 1 },
			{ { "CUP_arifle_M4A1_BUIS_camo_GL", "weapon" }, 1 },
			{ { "CUP_arifle_M4A1_BUIS_desert_GL", "weapon" }, 1 },
			{ { "CUP_arifle_M4A1", "weapon" }, 1 },
			{ { "CUP_arifle_M4A1_camo", "weapon" }, 1 },
			{ { "CUP_arifle_M4A1_black", "weapon" }, 1 },
			{ { "CUP_arifle_M4A1_desert", "weapon" }, 1 },
			{ { "CUP_arifle_M4A3_desert", "weapon" }, 1 },
			
			{ { "CUP_arifle_Sa58P", "weapon" }, 1 },
			{ { "CUP_arifle_Sa58V", "weapon" }, 1 },
			{ { "CUP_arifle_Sa58RIS1", "weapon" }, 1 },
			{ { "CUP_arifle_Sa58RIS2", "weapon" }, 1 },
			{ { "CUP_arifle_Sa58RIS2_gl", "weapon" }, 1 },
			{ { "CUP_arifle_Sa58P_des", "weapon" }, 1 },
			{ { "CUP_arifle_Sa58V_camo", "weapon" }, 1 },
			{ { "CUP_arifle_Sa58RIS1_des", "weapon" }, 1 },
			{ { "CUP_arifle_Sa58RIS2_camo", "weapon" }, 1 },
			
			{ { "CUP_arifle_Mk16_STD", "weapon" }, 1 },
			{ { "CUP_arifle_Mk16_STD_FG", "weapon" }, 1 },
			{ { "CUP_arifle_Mk16_STD_SFG", "weapon" }, 1 },
			{ { "CUP_arifle_Mk16_STD_EGLM", "weapon" }, 1 },
			{ { "CUP_arifle_Mk16_CQC", "weapon" }, 1 },
			{ { "CUP_arifle_Mk16_CQC_FG", "weapon" }, 1 },
			{ { "CUP_arifle_Mk16_CQC_SFG", "weapon" }, 1 },
			{ { "CUP_arifle_Mk16_CQC_EGLM", "weapon" }, 1 },
			{ { "CUP_arifle_Mk16_SV", "weapon" }, 1 },
			
			{ { "CUP_arifle_Mk17_CQC", "weapon" }, 1 },
			{ { "CUP_arifle_Mk17_CQC_FG", "weapon" }, 1 },
			{ { "CUP_arifle_Mk17_CQC_SFG", "weapon" }, 1 },
			{ { "CUP_arifle_Mk17_CQC_EGLM", "weapon" }, 1 },
			{ { "CUP_arifle_Mk17_STD", "weapon" }, 1 },
			{ { "CUP_arifle_Mk17_STD_FG", "weapon" }, 1 },
			{ { "CUP_arifle_Mk17_STD_SFG", "weapon" }, 1 },
			{ { "CUP_arifle_Mk17_STD_EGLM", "weapon" }, 1 },
			
			{ { "CUP_arifle_Mk20", "weapon" }, 1 },
			
			{ { "CUP_arifle_XM8_Carbine", "weapon" }, 1 },
			{ { "CUP_arifle_XM8_Carbine_GL", "weapon" }, 1 },
			{ { "CUP_arifle_xm8_sharpshooter", "weapon" }, 1 },
			{ { "CUP_arifle_XM8_Compact", "weapon" }, 1 },
			{ { "CUP_arifle_XM8_Compact_Rail", "weapon" }, 1 },
			{ { "CUP_arifle_XM8_Railed", "weapon" }, 1 },
			{ { "CUP_arifle_XM8_Carbine_FG", "weapon" }, 1 },
			{ { "CUP_arifle_xm8_SAW", "weapon" }, 1 },

			{ { "CUP_arifle_AK47", "weapon" }, 1 },
			{ { "CUP_arifle_RPK74", "weapon" }, 1 },
			{ { "CUP_arifle_MG36", "weapon" }, 1 },
			{ { "CUP_arifle_RPK74_45", "weapon" }, 1 },
			{ { "CUP_arifle_RPK74M", "weapon" }, 1 },
			{ { "CUP_arifle_MG36_camo", "weapon" }, 1 },
			{ { "CUP_arifle_L86A2", "weapon" }, 1 }
		};
	};
	class RifleAmmo_CUP
	{
		items[] = {
				{ { "CUP_30Rnd_545x39_AK_M", "magazine" }, 1 },
				{ { "CUP_30Rnd_TE1_Green_Tracer_545x39_AK_M", "magazine" }, 1 },
				{ { "CUP_30Rnd_TE1_Red_Tracer_545x39_AK_M", "magazine" }, 1 },
				{ { "CUP_30Rnd_TE1_White_Tracer_545x39_AK_M", "magazine" }, 1 },
				{ { "CUP_30Rnd_TE1_Yellow_Tracer_545x39_AK_M", "magazine" }, 1 },
				{ { "CUP_45Rnd_TE4_LRT4_Green_Tracer_545x39_RPK_M", "magazine" }, 1 },
				{ { "CUP_30Rnd_762x39_AK47_M", "magazine" }, 1 },
				{ { "CUP_75Rnd_TE4_LRT4_Green_Tracer_545x39_RPK_M", "magazine" }, 1 },
				{ { "CUP_30Rnd_556x45_Stanag", "magazine" }, 1 },
				{ { "CUP_30Rnd_556x45_G36", "magazine" }, 1 },
				{ { "CUP_30Rnd_TE1_Red_Tracer_556x45_G36", "magazine" }, 1 },
				{ { "CUP_30Rnd_TE1_Green_Tracer_556x45_G36", "magazine" }, 1 },
				{ { "CUP_30Rnd_TE1_Yellow_Tracer_556x45_G36", "magazine" }, 1 },
				{ { "CUP_100Rnd_556x45_BetaCMag", "magazine" }, 1 },
				{ { "CUP_100Rnd_TE1_Red_Tracer_556x45_BetaCMag", "magazine" }, 1 },
				{ { "CUP_100Rnd_TE1_Green_Tracer_556x45_BetaCMag", "magazine" }, 1 },
				{ { "CUP_100Rnd_TE1_Yellow_Tracer_556x45_BetaCMag", "magazine" }, 1 },
				{ { "CUP_20Rnd_556x45_Stanag", "magazine" }, 1 },
				{ { "CUP_20Rnd_762x51_CZ805B", "magazine" }, 1 },
				{ { "CUP_20Rnd_TE1_Yellow_Tracer_762x51_CZ805B", "magazine" }, 1 },
				{ { "CUP_20Rnd_TE1_Red_Tracer_762x51_CZ805B", "magazine" }, 1 },
				{ { "CUP_20Rnd_TE1_Green_Tracer_762x51_CZ805B", "magazine" }, 1 },
				{ { "CUP_20Rnd_TE1_White_Tracer_762x51_CZ805B", "magazine" }, 1 },
				{ { "CUP_20Rnd_762x51_FNFAL_M", "magazine" }, 1 },
				{ { "CUP_20Rnd_762x51_B_SCAR", "magazine" }, 1 },
				{ { "CUP_20Rnd_TE1_Yellow_Tracer_762x51_SCAR", "magazine" }, 1 },
				{ { "CUP_20Rnd_TE1_Red_Tracer_762x51_SCAR", "magazine" }, 1 },
				{ { "CUP_20Rnd_TE1_Green_Tracer_762x51_SCAR", "magazine" }, 1 },
				{ { "CUP_20Rnd_TE1_White_Tracer_762x51_SCAR", "magazine" }, 1 },
				{ { "CUP_30Rnd_Sa58_M_TracerG", "magazine" }, 1 },
				{ { "CUP_30Rnd_Sa58_M_TracerR", "magazine" }, 1 },
				{ { "CUP_30Rnd_Sa58_M_TracerY", "magazine" }, 1 },
				{ { "CUP_30Rnd_Sa58_M", "magazine" }, 1 },
				
				{ { "CUP_20Rnd_B_AA12_Pellets", "magazine" }, 3 },
				{ { "CUP_20Rnd_B_AA12_74Slug", "magazine" }, 2 },
				{ { "CUP_20Rnd_B_AA12_HE", "magazine" }, 1 },
				{ { "CUP_8Rnd_B_Beneli_74Slug", "magazine" }, 2 },
				{ { "CUP_8Rnd_B_Beneli_74Pellets", "magazine" }, 3 },
				{ { "CUP_8Rnd_B_Saiga12_74Slug_M", "magazine" }, 2 },
				{ { "CUP_8Rnd_B_Saiga12_74Pellets_M", "magazine" }, 3 }
		};
	};
	class Rifle_MAD
	{
		items[] = {
                { { "VG_sawed_off_01", "weapon" }, 1 },
                { { "Devastator_01", "weapon" }, 1 }
		};
	};
	class RifleAmmo_MAD
	{
		items[] = {
                { { "in005_1Rnd_12Gauge_Pellets", "magazine" }, 1 },
                { { "in005_1Rnd_12Gauge_Slug", "magazine" }, 1 }
		};
	};
	class SniperRifle_Vanilla
	{
		items[] = {
				{ { "m107_EPOCH", "weapon" }, 1 },
				{ { "m107Tan_EPOCH", "weapon" }, 1 },

				{ { "srifle_LRR_F", "weapon" }, 11 },
				{ { "srifle_GM6_F", "weapon" }, 16 },

				{ { "M14_EPOCH", "weapon" }, 1 },
				{ { "M14Grn_EPOCH", "weapon" }, 1 },

				{ { "srifle_EBR_F", "weapon" }, 20 },
				
				{ { "srifle_DMR_01_F", "weapon" }, 17 }
		};
	};
	class SniperRifleAmmo_Vanilla
	{
		items[] = {
				{ { "5Rnd_127x108_Mag", "magazine" }, 1 },
				{ { "5Rnd_127x108_APDS_Mag", "magazine" }, 1 },
				{ { "7Rnd_408_Mag", "magazine" }, 1 },
				{ { "20Rnd_762x51_Mag", "magazine" }, 1 },
				{ { "10Rnd_762x54_Mag", "magazine" }, 1 }
		};
	};
	class SniperRifleMarkDLC
	{
		items[] = {
				{ { "srifle_DMR_02_F", "weapon" }, 1 },
				{ { "srifle_DMR_02_camo_F", "weapon" }, 1 },
				{ { "srifle_DMR_02_sniper_F", "weapon" }, 1 },
				{ { "srifle_DMR_03_F", "weapon" }, 1 },
				{ { "srifle_DMR_03_khaki_F", "weapon" }, 1 },
				{ { "srifle_DMR_03_tan_F", "weapon" }, 1 },
				{ { "srifle_DMR_03_multicam_F", "weapon" }, 1 },
				{ { "srifle_DMR_03_woodland_F", "weapon" }, 1 },
				{ { "srifle_DMR_04_F", "weapon" }, 1 },
				{ { "srifle_DMR_04_Tan_F", "weapon" }, 1 },
				{ { "srifle_DMR_05_blk_F", "weapon" }, 1 },
				{ { "srifle_DMR_05_hex_F", "weapon" }, 1 },
				{ { "srifle_DMR_05_tan_f", "weapon" }, 1 },
				{ { "srifle_DMR_06_camo_F", "weapon" }, 1 },
				{ { "srifle_DMR_06_olive_F", "weapon" }, 1 }
		};
	};
	class SniperRifleAmmoMarkDLC
	{
		items[] = {
				{ { "10Rnd_338_Mag", "magazine" }, 1 },				// DMR_02
				{ { "10Rnd_127x54_Mag", "magazine" }, 1 },			// DMR_04
				{ { "10Rnd_93x64_DMR_05_Mag", "magazine" }, 1 }		// DMR_05
				
		};
	};
	class SniperRifle_CUP
	{
		items[] = {
				{ { "CUP_srifle_AS50", "weapon" }, 1 },
				{ { "CUP_srifle_LeeEnfield", "weapon" }, 1 },
				{ { "CUP_srifle_LeeEnfield_rail", "weapon" }, 1 },
				{ { "CUP_srifle_M107_Base", "weapon" }, 1 },
				{ { "CUP_srifle_M110", "weapon" }, 1 },
				{ { "CUP_srifle_M14", "weapon" }, 1 },
				{ { "CUP_srifle_M14_DMR", "weapon" }, 1 },
				{ { "CUP_srifle_Mk12SPR", "weapon" }, 1 },
				{ { "CUP_srifle_M24_des", "weapon" }, 1 },
				{ { "CUP_srifle_M40A3", "weapon" }, 1 },
				{ { "CUP_srifle_ksvk", "weapon" }, 1 },
				{ { "CUP_srifle_SVD", "weapon" }, 1 },
				{ { "CUP_srifle_VSSVintorez", "weapon" }, 1 },
				{ { "CUP_srifle_CZ750", "weapon" }, 1 },
				{ { "CUP_srifle_CZ550", "weapon" }, 1 },
				{ { "CUP_srifle_CZ550_rail", "weapon" }, 1 },
				{ { "CUP_srifle_M24_wdl", "weapon" }, 1 },
				{ { "CUP_srifle_SVD_des", "weapon" }, 1 },
				{ { "CUP_srifle_AWM_des", "weapon" }, 1 },
				{ { "CUP_srifle_AWM_wdl", "weapon" }, 1 },
				{ { "CUP_srifle_G22_des", "weapon" }, 1 }
		};
	};
	class SniperRifleAmmo_CUP
	{
		items[] = {
				{ { "CUP_5Rnd_127x99_as50_M", "magazine" }, 1 },
				{ { "CUP_10x_303_M", "magazine" }, 1 },
				{ { "CUP_10Rnd_127x99_m107", "magazine" }, 1 },
				{ { "CUP_20Rnd_762x51_B_M110", "magazine" }, 1 },
				{ { "CUP_20Rnd_TE1_Yellow_Tracer_762x51_M110", "magazine" }, 1 },
				{ { "CUP_20Rnd_TE1_Red_Tracer_762x51_M110", "magazine" }, 1 },
				{ { "CUP_20Rnd_TE1_Green_Tracer_762x51_M110", "magazine" }, 1 },
				{ { "CUP_20Rnd_TE1_White_Tracer_762x51_M110", "magazine" }, 1 },
				{ { "CUP_20Rnd_762x51_DMR", "magazine" }, 1 },
				{ { "CUP_20Rnd_TE1_Yellow_Tracer_762x51_DMR", "magazine" }, 1 },
				{ { "CUP_20Rnd_TE1_Red_Tracer_762x51_DMR", "magazine" }, 1 },
				{ { "CUP_20Rnd_TE1_Green_Tracer_762x51_DMR", "magazine" }, 1 },
				{ { "CUP_20Rnd_TE1_White_Tracer_762x51_DMR", "magazine" }, 1 },
				{ { "CUP_20Rnd_556x45_Stanag", "magazine" }, 1 },
				{ { "CUP_30Rnd_556x45_Stanag", "magazine" }, 1 },
				{ { "CUP_30Rnd_556x45_G36", "magazine" }, 1 },
				{ { "CUP_30Rnd_TE1_Red_Tracer_556x45_G36", "magazine" }, 1 },
				{ { "CUP_30Rnd_TE1_Green_Tracer_556x45_G36", "magazine" }, 1 },
				{ { "CUP_30Rnd_TE1_Yellow_Tracer_556x45_G36", "magazine" }, 1 },
				{ { "CUP_100Rnd_556x45_BetaCMag", "magazine" }, 1 },
				{ { "CUP_100Rnd_TE1_Red_Tracer_556x45_BetaCMag", "magazine" }, 1 },
				{ { "CUP_100Rnd_TE1_Green_Tracer_556x45_BetaCMag", "magazine" }, 1 },
				{ { "CUP_100Rnd_TE1_Yellow_Tracer_556x45_BetaCMag", "magazine" }, 1 },
				{ { "CUP_5Rnd_762x51_M24", "magazine" }, 1 },
				{ { "CUP_5Rnd_127x108_KSVK_M", "magazine" }, 1 },
				{ { "CUP_10Rnd_762x54_SVD_M", "magazine" }, 1 },
				{ { "CUP_10Rnd_9x39_SP5_VSS_M", "magazine" }, 1 },
				{ { "CUP_20Rnd_9x39_SP5_VSS_M", "magazine" }, 1 },
				{ { "CUP_10Rnd_762x51_CZ750_Tracer", "magazine" }, 1 },
				{ { "CUP_10Rnd_762x51_CZ750", "magazine" }, 1 },
				{ { "CUP_5x_22_LR_17_HMR_M", "magazine" }, 1 },
				{ { "CUP_5Rnd_86x70_L115A1", "magazine" }, 1 },
				{ { "CUP_5Rnd_762x67_G22", "magazine" }, 1 }
		};
	};
	class Machinegun_Vanilla
	{
		items[] = {
				{ { "LMG_Zafir_F", "weapon" }, 2 },

				{ { "arifle_MX_SW_F", "weapon" }, 4 },
				{ { "arifle_MX_SW_Black_F", "weapon" }, 2 },

				{ { "LMG_Mk200_F", "weapon" }, 6 },

				{ { "m249_EPOCH", "weapon" }, 1 },
				{ { "m249Tan_EPOCH", "weapon" }, 1 }
		};
	};
	class MachinegunAmmo_Vanilla
	{
		items[] = {
				{ { "100Rnd_65x39_caseless_mag", "magazine" }, 2 },
				{ { "100Rnd_65x39_caseless_mag_Tracer", "magazine" }, 1 },

				{ { "150Rnd_762x54_Box", "magazine" }, 2 },
				{ { "150Rnd_762x54_Box_Tracer", "magazine" }, 1 },

				{ { "200Rnd_556x45_M249", "magazine" }, 19 },

				{ { "200Rnd_65x39_cased_Box", "magazine" }, 2 },
				{ { "200Rnd_65x39_cased_Box_Tracer", "magazine" }, 1 }
		};
	};
	class MachinegunMarkDLC
	{
		items[] = {
				{ { "MMG_01_hex_F", "weapon" }, 1 },
				{ { "MMG_01_tan_F", "weapon" }, 1 },
				{ { "MMG_02_camo_F", "weapon" }, 1 },
				{ { "MMG_02_black_F", "weapon" }, 1 },
				{ { "MMG_02_sand_F", "weapon" }, 1 }
		};
	};
	class MachinegunAmmoMarkDLC
	{
		items[] = {
				{ { "150Rnd_93x64_Mag", "magazine" }, 1 },
				{ { "130Rnd_338_Mag", "magazine" }, 1 }
		};
	};
	class Machinegun_CUP
	{
		items[] = {
				{ { "CUP_lmg_L110A1", "weapon" }, 1 },
				{ { "CUP_lmg_M240", "weapon" }, 1 },
				{ { "CUP_lmg_minimipara", "weapon" }, 1 },
				{ { "CUP_lmg_minimi", "weapon" }, 1 },
				{ { "CUP_lmg_m249_para", "weapon" }, 1 },
				{ { "CUP_lmg_M249_E2", "weapon" }, 1 },
				{ { "CUP_lmg_minimi_railed", "weapon" }, 1 },
				{ { "CUP_lmg_m249_pip1", "weapon" }, 1 },
				{ { "CUP_lmg_m249_pip4", "weapon" }, 1 },
				{ { "CUP_lmg_L7A2", "weapon" }, 1 },
				{ { "CUP_lmg_PKM", "weapon" }, 1 },
				{ { "CUP_lmg_Pecheneg", "weapon" }, 1 },
				{ { "CUP_lmg_UK59", "weapon" }, 1 },
				{ { "CUP_lmg_m249_pip2", "weapon" }, 1 },
				{ { "CUP_lmg_m249_pip3", "weapon" }, 1 },
				{ { "CUP_lmg_m249_SQuantoon", "weapon" }, 1 },
				{ { "CUP_lmg_M60E4", "weapon" }, 1 },
				{ { "CUP_lmg_Mk48_des", "weapon" }, 1 },
				{ { "CUP_lmg_Mk48_wdl", "weapon" }, 1 }
		};
	};
	class MachinegunAmmo_CUP
	{
		items[] = {
				{ { "CUP_200Rnd_TE4_Red_Tracer_556x45_M249", "magazine" }, 1 },
				{ { "CUP_200Rnd_TE4_Yellow_Tracer_556x45_M249", "magazine" }, 1 },
				{ { "CUP_200Rnd_TE1_Red_Tracer_556x45_M249", "magazine" }, 1 },
				{ { "CUP_100Rnd_TE4_Green_Tracer_556x45_M249", "magazine" }, 1 },
				{ { "CUP_100Rnd_TE4_Red_Tracer_556x45_M249", "magazine" }, 1 },
				{ { "CUP_100Rnd_TE4_Yellow_Tracer_556x45_M249", "magazine" }, 1 },
				{ { "CUP_200Rnd_TE4_Green_Tracer_556x45_L110A1", "magazine" }, 1 },
				{ { "CUP_200Rnd_TE4_Red_Tracer_556x45_L110A1", "magazine" }, 1 },
				{ { "CUP_200Rnd_TE4_Yellow_Tracer_556x45_L110A1", "magazine" }, 1 },
				{ { "CUP_30Rnd_556x45_Stanag", "magazine" }, 1 },
				{ { "CUP_30Rnd_556x45_G36", "magazine" }, 1 },
				{ { "CUP_100Rnd_TE4_LRT4_White_Tracer_762x51_Belt_M", "magazine" }, 1 },
				{ { "CUP_100Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M", "magazine" }, 1 },
				{ { "CUP_200Rnd_TE4_Green_Tracer_556x45_M249", "magazine" }, 1 },
				{ { "CUP_100Rnd_TE4_LRT4_762x54_PK_Tracer_Green_M", "magazine" }, 1 },
				{ { "CUP_50Rnd_UK59_762x54R_Tracer", "magazine" }, 1 },
				
				{ { "CUP_64Rnd_9x19_Bizon_M", "magazine" }, 1 },
				{ { "CUP_64Rnd_Green_Tracer_9x19_Bizon_M", "magazine" }, 1 },
				{ { "CUP_64Rnd_Red_Tracer_9x19_Bizon_M", "magazine" }, 1 },
				{ { "CUP_64Rnd_White_Tracer_9x19_Bizon_M", "magazine" }, 1 },
				{ { "CUP_64Rnd_Yellow_Tracer_9x19_Bizon_M", "magazine" }, 1 },
				{ { "CUP_30Rnd_9x19_EVO", "magazine" }, 1 },
				{ { "CUP_30Rnd_9x19_MP5", "magazine" }, 1 }
		};
	};
	class Uniforms_Male_Civ_Vanilla
	{
		items[] = {
				{ { "U_C_Poloshirt_stripped", "item" }, 1 },
				{ { "U_C_Poloshirt_blue", "item" }, 1 },
				{ { "U_C_Poloshirt_burgundy", "item" }, 1 },
				{ { "U_C_Poloshirt_tricolour", "item" }, 1 },
				{ { "U_C_Poloshirt_salmon", "item" }, 1 },
				{ { "U_C_Poloshirt_redwhite", "item" }, 1 },
				{ { "U_C_Commoner1_1", "item" }, 1 },
				{ { "U_C_Poor_2", "item" }, 1 },
				{ { "U_C_HunterBody_grn", "item" }, 1 },
				{ { "U_C_Poor_shorts_1", "item" }, 1 },
				{ { "U_NikosBody", "item" }, 1 },
				{ { "U_NikosAgedBody", "item" }, 1 },
				{ { "U_Marshal", "item" }, 1 },
				{ { "U_C_man_sport_1_F", "item" }, 1 },
				{ { "U_C_man_sport_2_F", "item" }, 1 },
				{ { "U_C_man_sport_3_F", "item" }, 1 },
				{ { "U_C_Man_casual_1_F", "item" }, 1 },
				{ { "U_C_Man_casual_2_F", "item" }, 1 },
				{ { "U_C_Man_casual_3_F", "item" }, 1 },
				{ { "U_C_Man_casual_4_F", "item" }, 1 },
				{ { "U_C_Man_casual_5_F", "item" }, 1 },
				{ { "U_C_Man_casual_6_F", "item" }, 1 },
				{ { "U_C_Poor_1", "item" }, 1 },
				{ { "U_C_WorkerCoveralls", "item" }, 1 },
				{ { "U_C_Journalist", "item" }, 1 },
				{ { "U_C_Scientist", "item" }, 1 },
				{ { "U_OrestesBody", "item" }, 1 },
				{ { "U_C_Commoner_shorts", "item" }, 1 },
				{ { "U_C_ShirtSurfer_shorts", "item" }, 1 },
				{ { "U_C_TeeSurfer_shorts_1", "item" }, 1 },
				{ { "U_C_TeeSurfer_shorts_2", "item" }, 1 }
				
		};
	};
	class Uniforms_Male_Mil_Vanilla
	{
		items[] = {
				{ { "U_OG_Guerilla1_1", "item" }, 1 },
				{ { "U_OG_Guerilla2_1", "item" }, 1 },
				{ { "U_OG_Guerilla2_2", "item" }, 1 },
				{ { "U_OG_Guerilla2_3", "item" }, 1 },
				{ { "U_OG_Guerilla3_1", "item" }, 1 },
				{ { "U_OG_Guerilla3_2", "item" }, 1 },
				{ { "U_OG_leader", "item" }, 1 },
				{ { "U_O_CombatUniform_ocamo", "item" }, 1 },
				{ { "U_O_GhillieSuit", "item" }, 1 },
				{ { "U_O_PilotCoveralls", "item" }, 1 },
				{ { "U_IG_Guerilla1_1", "item" }, 1 },
				{ { "U_IG_leader", "item" }, 1 },
				{ { "U_IG_Guerilla2_1", "item" }, 1 },
				{ { "U_IG_Guerilla2_3", "item" }, 1 },
				{ { "U_IG_Guerilla2_2", "item" }, 1 },
				{ { "U_IG_Guerilla3_1", "item" }, 1 },
				{ { "U_IG_Guerrilla_6_1", "item" }, 1 },
				{ { "U_OG_Guerrilla_6_1", "item" }, 1 },
				{ { "U_I_CombatUniform", "item" }, 1 },
				{ { "U_I_CombatUniform_shortsleeve", "item" }, 1 },
				{ { "U_I_HeliPilotCoveralls", "item" }, 1 },
				{ { "U_I_pilotCoveralls", "item" }, 1 },
				{ { "U_I_OfficerUniform", "item" }, 1 },
				{ { "U_I_GhillieSuit", "item" }, 1 },
				{ { "U_I_CombatUniform_tshirt", "item" }, 1 },
				{ { "U_O_OfficerUniform_ocamo", "item" }, 1 },
				{ { "U_O_SpecopsUniform_ocamo", "item" }, 1 },
				{ { "U_O_CombatUniform_oucamo", "item" }, 1 },
				{ { "U_I_C_Soldier_Para_1_F", "item" }, 1 },
				{ { "U_I_C_Soldier_Para_2_F", "item" }, 1 },
				{ { "U_I_C_Soldier_Para_3_F", "item" }, 1 },
				{ { "U_I_C_Soldier_Para_4_F", "item" }, 1 },
				{ { "U_I_C_Soldier_Para_5_F", "item" }, 1 },
				{ { "U_I_C_Soldier_Bandit_1_F", "item" }, 1 },
				{ { "U_I_C_Soldier_Bandit_2_F", "item" }, 1 },
				{ { "U_I_C_Soldier_Bandit_3_F", "item" }, 1 },
				{ { "U_I_C_Soldier_Bandit_4_F", "item" }, 1 },
				{ { "U_I_C_Soldier_Bandit_5_F", "item" }, 1 },
				{ { "U_I_C_Soldier_Camo_F", "item" }, 1 },
				{ { "U_O_T_Soldier_F", "item" }, 1 },
				{ { "U_O_T_Officer_F", "item" }, 1 },
				{ { "U_O_T_Sniper_F", "item" }, 1 },
				{ { "U_RadiationSuit_M_uniform", "item" }, 1 }				
		};
	};
	class Uniforms_Male_WetSuit
	{
		items[] = {
				{ { "U_O_Wetsuit", "item" }, 1 },
				{ { "U_I_Wetsuit", "item" }, 1 }
		};
	};
	class Uniforms_Male_MarksDLC
	{
		items[] = {
				{ { "U_O_T_FullGhillie_tna_F", "item" }, 1 },
				{ { "U_O_FullGhillie_lsh", "item" }, 1 },
				{ { "U_O_FullGhillie_sard", "item" }, 1 },
				{ { "U_O_FullGhillie_ard", "item" }, 1 },
				{ { "U_I_FullGhillie_lsh", "item" }, 1 },
				{ { "U_I_FullGhillie_sard", "item" }, 1 },
				{ { "U_I_FullGhillie_ard", "item" }, 1 }
		};
	};
	class Uniforms_Male_KartDLC
	{
		items[] = {
				{ { "U_C_Driver_1", "item" }, 1 },
				{ { "U_C_Driver_2", "item" }, 1 },
				{ { "U_C_Driver_3", "item" }, 1 },
				{ { "U_C_Driver_4", "item" }, 1 },
				{ { "U_C_Driver_1_black", "item" }, 1 },
				{ { "U_C_Driver_1_blue", "item" }, 1 },
				{ { "U_C_Driver_1_green", "item" }, 1 },
				{ { "U_C_Driver_1_red", "item" }, 1 },
				{ { "U_C_Driver_1_white", "item" }, 1 },
				{ { "U_C_Driver_1_yellow", "item" }, 1 },
				{ { "U_C_Driver_1_orange", "item" }, 1 },
				{ { "U_C_Driver_1_red", "item" }, 1 }
		};
	};
	class Uniforms_Male_IdapDLC
	{
		items[] = {
				{ { "U_C_ConstructionCoverall_Red_F", "item" }, 1 },
				{ { "U_C_ConstructionCoverall_vrana_F", "item" }, 1 },
				{ { "U_C_ConstructionCoverall_Black_F", "item" }, 1 },
				{ { "U_C_ConstructionCoverall_Blue_F", "item" }, 1 },
				{ { "U_C_Paramedic_01_F", "item" }, 1 },
				{ { "U_C_Mechanic_01_F", "item" }, 1 }
		};
	};
	class Uniforms_Male_ApexDLC
	{
		items[] = {
				{ { "U_O_V_Soldier_Viper_hex_F", "item" }, 1 },
				{ { "U_O_V_Soldier_Viper_F", "item" }, 1 }
		};
	};
	class Uniforms_Female_Civ_Epoch
	{
		items[] = {
				{ { "U_JeansBlack1_uniform", "item" }, 1 },
				{ { "U_JeansBlack2_uniform", "item" }, 1 },
				{ { "U_JeansBlack3_uniform", "item" }, 1 },
				{ { "U_JeansBlack4_uniform", "item" }, 1 },
				{ { "U_JeansBlack5_uniform", "item" }, 1 },
				{ { "U_JeansBlack6_uniform", "item" }, 1 },
				{ { "U_JeansBlack7_uniform", "item" }, 1 },
				{ { "U_JeansBlack8_uniform", "item" }, 1 },
				{ { "U_JeansBlack9_uniform", "item" }, 1 },
				{ { "U_JeansBlack10_uniform", "item" }, 1 },
				{ { "U_JeansBlack11_uniform", "item" }, 1 },
				{ { "U_JeansBlack12_uniform", "item" }, 1 },
				{ { "U_JeansBlack13_uniform", "item" }, 1 },
				{ { "U_JeansBlack14_uniform", "item" }, 1 },
				{ { "U_JeansBlack15_uniform", "item" }, 1 },
				{ { "U_JeansBlack16_uniform", "item" }, 1 },
				{ { "U_JeansBlack17_uniform", "item" }, 1 },
				{ { "U_JeansBlack18_uniform", "item" }, 1 },
				{ { "U_JeansBlack19_uniform", "item" }, 1 },
				{ { "U_JeansBlack20_uniform", "item" }, 1 },
				{ { "U_JeansBlack21_uniform", "item" }, 1 },
				{ { "U_JeansArBrn1_uniform", "item" }, 1 },
				{ { "U_JeansArBrn2_uniform", "item" }, 1 },
				{ { "U_JeansArBrn3_uniform", "item" }, 1 },
				{ { "U_JeansArBrn4_uniform", "item" }, 1 },
				{ { "U_JeansArBrn5_uniform", "item" }, 1 },
				{ { "U_JeansArBrn6_uniform", "item" }, 1 },
				{ { "U_JeansArBrn7_uniform", "item" }, 1 },
				{ { "U_JeansArBrn8_uniform", "item" }, 1 },
				{ { "U_JeansArBrn9_uniform", "item" }, 1 },
				{ { "U_JeansArBrn10_uniform", "item" }, 1 },
				{ { "U_JeansArBrn11_uniform", "item" }, 1 },
				{ { "U_JeansArBrn12_uniform", "item" }, 1 },
				{ { "U_JeansArBrn13_uniform", "item" }, 1 },
				{ { "U_JeansArBrn14_uniform", "item" }, 1 },
				{ { "U_JeansArBrn15_uniform", "item" }, 1 },
				{ { "U_JeansArBrn16_uniform", "item" }, 1 },
				{ { "U_JeansArBrn17_uniform", "item" }, 1 },
				{ { "U_JeansArBrn18_uniform", "item" }, 1 },
				{ { "U_JeansArBrn19_uniform", "item" }, 1 },
				{ { "U_JeansArBrn20_uniform", "item" }, 1 },
				{ { "U_JeansArBrn21_uniform", "item" }, 1 },
				{ { "U_JeansBlkBrn1_uniform", "item" }, 1 },
				{ { "U_JeansBlkBrn2_uniform", "item" }, 1 },
				{ { "U_JeansBlkBrn3_uniform", "item" }, 1 },
				{ { "U_JeansBlkBrn4_uniform", "item" }, 1 },
				{ { "U_JeansBlkBrn5_uniform", "item" }, 1 },
				{ { "U_JeansBlkBrn6_uniform", "item" }, 1 },
				{ { "U_JeansBlkBrn7_uniform", "item" }, 1 },
				{ { "U_JeansBlkBrn8_uniform", "item" }, 1 },
				{ { "U_JeansBlkBrn9_uniform", "item" }, 1 },
				{ { "U_JeansBlkBrn10_uniform", "item" }, 1 },
				{ { "U_JeansBlkBrn11_uniform", "item" }, 1 },
				{ { "U_JeansBlkBrn12_uniform", "item" }, 1 },
				{ { "U_JeansBlkBrn13_uniform", "item" }, 1 },
				{ { "U_JeansBlkBrn14_uniform", "item" }, 1 },
				{ { "U_JeansBlkBrn15_uniform", "item" }, 1 },
				{ { "U_JeansBlkBrn16_uniform", "item" }, 1 },
				{ { "U_JeansBlkBrn17_uniform", "item" }, 1 },
				{ { "U_JeansBlkBrn18_uniform", "item" }, 1 },
				{ { "U_JeansBlkBrn19_uniform", "item" }, 1 },
				{ { "U_JeansBlkBrn20_uniform", "item" }, 1 },
				{ { "U_JeansBlkBrn21_uniform", "item" }, 1 },
				{ { "U_JeansPatched1_uniform", "item" }, 1 },
				{ { "U_JeansPatched2_uniform", "item" }, 1 },
				{ { "U_JeansPatched3_uniform", "item" }, 1 },
				{ { "U_JeansPatched4_uniform", "item" }, 1 },
				{ { "U_JeansPatched5_uniform", "item" }, 1 },
				{ { "U_JeansPatched6_uniform", "item" }, 1 },
				{ { "U_JeansPatched7_uniform", "item" }, 1 },
				{ { "U_JeansPatched8_uniform", "item" }, 1 },
				{ { "U_JeansPatched9_uniform", "item" }, 1 },
				{ { "U_JeansPatched10_uniform", "item" }, 1 },
				{ { "U_JeansPatched11_uniform", "item" }, 1 },
				{ { "U_JeansPatched12_uniform", "item" }, 1 },
				{ { "U_JeansPatched13_uniform", "item" }, 1 },
				{ { "U_JeansPatched14_uniform", "item" }, 1 },
				{ { "U_JeansPatched15_uniform", "item" }, 1 },
				{ { "U_JeansPatched16_uniform", "item" }, 1 },
				{ { "U_JeansPatched17_uniform", "item" }, 1 },
				{ { "U_JeansPatched18_uniform", "item" }, 1 },
				{ { "U_JeansPatched19_uniform", "item" }, 1 },
				{ { "U_JeansPatched20_uniform", "item" }, 1 },
				{ { "U_JeansPatched21_uniform", "item" }, 1 }
		};
	};
	class Uniforms_Female_WetSuit_Epoch
	{
		items[] = {
				{ { "U_Wetsuit_uniform", "item" }, 1 },
				{ { "U_Wetsuit_White", "item" }, 1 },
				{ { "U_Wetsuit_Blue", "item" }, 1 },
				{ { "U_Wetsuit_Purp", "item" }, 1 },
				{ { "U_Wetsuit_Camo", "item" }, 1 }
		};
	};
	class Uniforms_Female_Mil_Epoch
	{
		items[] = {
				{ { "U_CamoRed_uniform", "item" }, 1 },
                { { "U_CamoAloha_uniform", "item" }, 1 },
                { { "U_CamoBiker_uniform", "item" }, 1 },
                { { "U_CamoBubblegum_uniform", "item" }, 1 },
                { { "U_CamoLumberjack_uniform", "item" }, 1 },
                { { "U_CamoOutback_uniform", "item" }, 1 },
                { { "U_CamoPink_uniform", "item" }, 1 },
                { { "U_CamoPinkPolka_uniform", "item" }, 1 },
				{ { "U_CamoBrn_uniform", "item" }, 1 },
				{ { "U_CamoBlue_uniform", "item" }, 1 },
				{ { "U_Camo_uniform", "item" }, 1 },
				{ { "U_ghillie1_uniform", "item" }, 1 },
				{ { "U_ghillie2_uniform", "item" }, 1 },
				{ { "U_ghillie3_uniform", "item" }, 1 },
				{ { "U_RadiationSuit_F_uniform", "item" }, 1 }
		};
	};
	class Vests_Low_Vanilla
	{
		items[] = {
				{ { "V_Press_F", "item" }, 1 },

				{ { "V_1_EPOCH", "item" }, 1 },
				{ { "V_2_EPOCH", "item" }, 1 },
				{ { "V_3_EPOCH", "item" }, 1 },
				{ { "V_4_EPOCH", "item" }, 1 },
				{ { "V_5_EPOCH", "item" }, 1 },
				{ { "V_6_EPOCH", "item" }, 1 },
				{ { "V_7_EPOCH", "item" }, 1 },
				{ { "V_8_EPOCH", "item" }, 1 },
				{ { "V_9_EPOCH", "item" }, 1 },
				{ { "V_10_EPOCH", "item" }, 1 },
				{ { "V_11_EPOCH", "item" }, 1 },
				{ { "V_12_EPOCH", "item" }, 1 },
				{ { "V_13_EPOCH", "item" }, 1 },
				{ { "V_14_EPOCH", "item" }, 1 },
				{ { "V_15_EPOCH", "item" }, 1 },
				{ { "V_16_EPOCH", "item" }, 1 },
				{ { "V_17_EPOCH", "item" }, 1 },
				{ { "V_18_EPOCH", "item" }, 1 },
				{ { "V_21_EPOCH", "item" }, 1 },
				{ { "V_22_EPOCH", "item" }, 1 },
				{ { "V_23_EPOCH", "item" }, 1 },
				{ { "V_24_EPOCH", "item" }, 1 },
				{ { "V_25_EPOCH", "item" }, 1 },
				{ { "V_26_EPOCH", "item" }, 1 },
				{ { "V_27_EPOCH", "item" }, 1 },
				{ { "V_28_EPOCH", "item" }, 1 },
				{ { "V_29_EPOCH", "item" }, 1 },
				{ { "V_30_EPOCH", "item" }, 1 },
				{ { "V_31_EPOCH", "item" }, 1 },
				{ { "V_32_EPOCH", "item" }, 1 },
				{ { "V_33_EPOCH", "item" }, 1 },
				{ { "V_34_EPOCH", "item" }, 1 },
				{ { "V_35_EPOCH", "item" }, 1 },
				{ { "V_37_EPOCH", "item" }, 1 },
				{ { "V_38_EPOCH", "item" }, 1 },
				{ { "V_39_EPOCH", "item" }, 1 },
				{ { "V_40_EPOCH", "item" }, 1 }
		};
	};
	class Vests_High_Vanilla
	{
		items[] = {
				{ { "V_PlateCarrier1_tna_F", "item" }, 1 },
				{ { "V_PlateCarrierSpec_tna_F", "item" }, 1 },
				{ { "V_PlateCarrierSpec_blk", "item" }, 1 },
				{ { "V_HarnessO_ghex_F", "item" }, 1 },
				{ { "V_HarnessOGL_ghex_F", "item" }, 1 },
				{ { "V_PlateCarrier2_tna_F", "item" }, 1 },
				{ { "V_PlateCarrierGL_tna_F", "item" }, 1 }
		};
	};
	class Vests_Rebreather_Epoch
	{
		items[] = {
				{ { "V_19_EPOCH", "item" }, 1 },
				{ { "V_20_EPOCH", "item" }, 1 },
				{ { "V_36_EPOCH", "item" }, 1 }
		};
	};
	class Vests_ApexDLC
	{
		items[] = {
				{ { "V_TacChestrig_grn_F", "item" }, 1 },
				{ { "V_TacChestrig_oli_F", "item" }, 1 },
				{ { "V_TacChestrig_cbr_F", "item" }, 1 }
		};
	};
	class Backpacks_Low_Base
	{
		items[] = {
				{ { "B_ViperLightHarness_blk_F", "backpack" }, 2 },		// 260
				{ { "B_ViperLightHarness_ghex_F", "backpack" }, 2 },	// 260
				{ { "B_ViperLightHarness_hex_F", "backpack" }, 2 },		// 260
				{ { "B_ViperLightHarness_khk_F", "backpack" }, 2 },		// 260
				{ { "B_ViperLightHarness_oli_F", "backpack" }, 2 },		// 260

				{ { "Assault_Pack_Epoch", "backpack" }, 1 },			// 300
				{ { "B_ViperHarness_blk_F", "backpack" }, 1 },			// 300
				{ { "B_ViperHarness_ghex_F", "backpack" }, 1 },			// 300
				{ { "B_ViperHarness_hex_F", "backpack" }, 1 },			// 300
				{ { "B_ViperHarness_khk_F", "backpack" }, 1 },			// 300
				{ { "B_ViperHarness_oli_F", "backpack" }, 1 },			// 300
				{ { "Patrol_Pack_Epoch", "backpack" }, 1 },				// 300
				{ { "TK_RPG_Backpack_Epoch", "backpack" }, 1 },			// 300

				{ { "CZ_VestPouch_Epoch", "backpack" }, 3 }				// 340
		};
	};
	class Backpacks_High_Base
	{
		items[] = {
				{ { "B_AssaultPack_cbr", "backpack" }, 5 },				// 360
				{ { "B_AssaultPack_dgtl", "backpack" }, 5 },			// 360
				{ { "B_AssaultPack_khk", "backpack" }, 5 },				// 360
				{ { "B_AssaultPack_mcamo", "backpack" }, 5 },			// 360
				{ { "B_AssaultPack_ocamo", "backpack" }, 5 },			// 360
				{ { "B_AssaultPack_rgr", "backpack" }, 5 },				// 360
				{ { "B_AssaultPack_sgg", "backpack" }, 5 },				// 360
				{ { "B_AssaultPack_blk", "backpack" }, 5 },				// 360
				{ { "B_AssaultPack_tna_F", "backpack" }, 5 },			// 360

				{ { "B_FieldPack_blk", "backpack" }, 4 },				// 400
				{ { "B_FieldPack_cbr", "backpack" }, 4 },				// 400
				{ { "B_FieldPack_khk", "backpack" }, 4 },				// 400
				{ { "B_FieldPack_ocamo", "backpack" }, 4 },				// 400
				{ { "B_FieldPack_oli", "backpack" }, 4 },				// 400
				{ { "B_FieldPack_oucamo", "backpack" }, 4 },			// 400
				{ { "civil_assault_pack_Epoch", "backpack" }, 4 },		// 400

				{ { "S_Gunbag_Epoch", "backpack" }, 4 },				// 420

				{ { "smallbackpack_red_epoch", "backpack" }, 4 },		// 460
				{ { "smallbackpack_green_epoch", "backpack" }, 4 },		// 460
				{ { "smallbackpack_teal_epoch", "backpack" }, 4 },		// 460
				{ { "smallbackpack_pink_epoch", "backpack" }, 4 },		// 460

				{ { "B_TacticalPack_blk", "backpack" }, 2 },			// 480
				{ { "B_TacticalPack_mcamo", "backpack" }, 2 },			// 480
				{ { "B_TacticalPack_ocamo", "backpack" }, 2 },			// 480
				{ { "B_TacticalPack_oli", "backpack" }, 2 },			// 480
				{ { "B_TacticalPack_rgr", "backpack" }, 2 },			// 480
				{ { "ALICE_Pack_Epoch", "backpack" }, 2 },				// 480

				{ { "US_Backpack_Epoch", "backpack" }, 2 },				// 500

				{ { "B_Kitbag_cbr", "backpack" }, 2 },					// 520
				{ { "B_Kitbag_mcamo", "backpack" }, 2 },				// 520
				{ { "B_Kitbag_rgr", "backpack" }, 2 },					// 520
				{ { "B_Kitbag_sgg", "backpack" }, 2 },					// 520
				{ { "CZ_Backpack_Epoch", "backpack" }, 1 },				// 520

				{ { "B_Carryall_cbr", "backpack" }, 1 },				// 550
				{ { "B_Carryall_khk", "backpack" }, 1 },				// 550
				{ { "B_Carryall_mcamo", "backpack" }, 1 },				// 550
				{ { "B_Carryall_ocamo", "backpack" }, 1 },				// 550
				{ { "B_Carryall_oli", "backpack" }, 1 },				// 550
				{ { "B_Carryall_oucamo", "backpack" }, 1 },				// 550
				
				{ { "L_Gunbag_Epoch", "backpack" }, 3 },				// 580
				
				{ { "B_Parachute", "backpack" }, 1 }
		};
	};
	class Backpacks_UAV
	{
		items[] = {
				{ { "I_UAV_01_backpack_F", "backpack" }, 1 },
				{ { "C_IDAP_UAV_06_backpack_F", "backpack" }, 1 },
				{ { "C_IDAP_UAV_06_antimine_backpack_F", "backpack" }, 1 },
				{ { "B_UAV_06_medical_backpack_F", "backpack" }, 1 }
		};
	};

// ########################################################################### Special Loot ###########################################################################
	class Tree
	{
		items[] = {
				{ { "WoodLog_EPOCH", "magazine" }, 1 }
		};
	};
	class Rock
	{
		items[] = {
				{ { "PartOre", "magazine" }, 1 },
				{ { "ItemRock", "magazine" }, 2 }
		};
	};
	class Cinder
	{
		items[] = {
				{ { "CinderBlocks", "magazine" }, 1 }
		};
	};
	class Wreck
	{
		items[] = {
				{ { "ItemScraps", "magazine" }, 1 }
		};
	};
	class Bush
	{
		items[] = {
				{ { "ItemStick", "magazine" }, 1 }
		};
	};
	class Sheep_random_EPOCH
	{
		items[] = {
				{ { "SheepCarcass_EPOCH", "magazine" }, 1 },
				{ { "Pelt_EPOCH", "magazine" }, 1 }
		};
	};
	class Goat_random_EPOCH
	{
		items[] = {
				{ { "GoatCarcass_EPOCH", "magazine" }, 1 },
				{ { "Pelt_EPOCH", "magazine" }, 1 }
		};
	};
	class Fin_random_EPOCH
	{
		items[] = {
				{ { "DogCarcass_EPOCH", "magazine" }, 1 },
				{ { "Pelt_EPOCH", "magazine" }, 1 }
		};
	};
	class Alsatian_Random_EPOCH
	{
		items[] = {
				{ { "DogCarcass_EPOCH", "magazine" }, 1 },
				{ { "Pelt_EPOCH", "magazine" }, 1 }
		};
	};
	class Hen_random_EPOCH
	{
		items[] = {
				{ { "ChickenCarcass_EPOCH", "magazine" }, 1 }
		};
	};
	class Rabbit_EPOCH
	{
		items[] = {
				{ { "RabbitCarcass_EPOCH", "magazine" }, 1 },
				{ { "Pelt_EPOCH", "magazine" }, 1 }
		};
	};
	class EPOCH_RyanZombie_1
	{
		items[] = {
			{ { "MetalBars", "CfgLootTable" }, 5 },
			{ { "WhiskeyNoodle", "magazine" }, 5 },
			{ { "Throw", "CfgLootTable" }, 10 },
			{ { "ThrowExplosive", "CfgLootTable" }, 10 },
			{ { "Medical", "CfgLootTable" }, 20 },
			{ { "PistolAmmo", "CfgLootTable" }, 20 },
			{ { "Pelt_EPOCH", "magazine" }, 10 }
		};
	};
	class GreatWhite_F
	{
		items[] = {
				{ { "MetalBars", "CfgLootTable" }, 9 },
				{ { "ItemBriefcaseGold100oz", "magazine" }, 1 }
		};
	};
	class Epoch_Sapper_F
	{
		items[] = {
				{ { "MetalBars", "CfgLootTable" }, 6 },
				{ { "WhiskeyNoodle", "magazine" }, 11 },
				{ { "ItemKiloHemp", "magazine" }, 16 },
				{ { "ItemSilverBar", "magazine" }, 18 },
				{ { "Medical", "CfgLootTable" }, 18 },
				{ { "Pelt_EPOCH", "magazine" }, 31 }
		};
	};
	class Cock_random_EPOCH
	{
		items[] = {
				{ { "ChickenCarcass_EPOCH", "magazine" }, 1 }
		};
	};
	class Epoch_SapperB_F
	{
		items[] = {
				{ { "ItemGoldBar", "magazine" }, 9 },
				{ { "WhiskeyNoodle", "magazine" }, 13 },
				{ { "ItemKiloHemp", "magazine" }, 15 },
				{ { "ItemSilverBar", "magazine" }, 17 },
				{ { "Medical", "CfgLootTable" }, 17 },
				{ { "Pelt_EPOCH", "magazine" }, 29 }
		};
	};
    class Epoch_SapperG_F
    {
        items[] = {
                { { "SmokeShellToxic", "magazine" }, 9 },
                { { "WhiskeyNoodle", "magazine" }, 13 },
                { { "ItemKiloHemp", "magazine" }, 15 },
                { { "ItemSilverBar", "magazine" }, 17 },
                { { "Medical", "CfgLootTable" }, 17 },
                { { "Pelt_EPOCH", "magazine" }, 29 }
        };
    };
	class Snake_random_EPOCH
	{
		items[] = {
				{ { "SnakeCarcass_EPOCH", "magazine" }, 1 },
				{ { "Venom_EPOCH", "magazine" }, 1 }
		};
	};
	class I_UAV_01_F
	{
		items[] = {
				{ { "CircuitParts", "magazine" }, 1 }
		};
	};
	class Epoch_Cloak_F
	{
		items[] = {
				{ { "Gems", "CfgLootTable" }, 10 },
				{ { "Throw", "CfgLootTable" }, 11 },
				{ { "ThrowExplosive", "magazine" }, 12 },
				{ { "MiniGrenade", "magazine" }, 20 },
				{ { "Medical", "CfgLootTable" }, 21 },
				{ { "Venom_EPOCH", "magazine" }, 26 }
		};
	};
	class SeaFood
	{
		items[] = {
				{ { "ItemTrout", "magazine" }, 3 },
				{ { "ItemSeaBass", "magazine" }, 2 },
				{ { "ItemTuna", "magazine" }, 1 }
		};
	};
	class Satellite
	{
		items[] = {
				{ { "MetalBars", "CfgLootTable" }, 5 },
				{ { "CircuitParts", "magazine" }, 1 },
				{ { "Gems", "CfgLootTable" }, 3 },
				{ { "ItemScraps", "magazine" }, 1 },
				{ { "ItemCorrugated", "magazine" }, 2 },
				{ { "ItemSolar", "magazine" }, 1 },
				{ { "ItemBattery", "magazine" }, 1 },
				{ { "ItemCables", "magazine" }, 1 }
		};
	};
};
