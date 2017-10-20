/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Epoch Server side loot table configs for CUP Weapons

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server_settngs/configs/CfgLootTable_CUP.h
*/
class CfgLootTable_MADCUP
{
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

	class Pumpkin
	{
		items[] = {
				{ { "Pumpkin", "magazine" }, 1 }
		};
	};

	class Hemp
	{
		items[] = {
				{ { "ItemKiloHemp", "magazine" }, 1 }
		};
	};

	class Items
	{
		items[] = {
				{ { "ItemCompass", "item" }, 20 },
				{ { "ItemGeigerCounter_EPOCH", "item" }, 1 },
				{ { "ItemGPS", "item" }, 9 },
				{ { "EpochRadio0", "item" }, 3 },
				{ { "EpochRadio1", "item" }, 3 },
				{ { "EpochRadio2", "item" }, 3 },
				{ { "EpochRadio3", "item" }, 2 },
				{ { "EpochRadio4", "item" }, 2 },
				{ { "EpochRadio5", "item" }, 2 },
				{ { "EpochRadio6", "item" }, 2 },
				{ { "EpochRadio7", "item" }, 1 },
				{ { "EpochRadio8", "item" }, 1 },
				{ { "EpochRadio9", "item" }, 1 },
				{ { "ItemWatch", "item" }, 30 },
				{ { "FAK", "magazine" }, 20 }
		};
	};
	class Repairs
	{
		items[] = {
				{ { "VehicleRepair", "magazine" }, 30 },
				{ { "SpareTire", "magazine" }, 10 },
				{ { "EngineParts", "magazine" }, 10 },
				{ { "EngineBlock", "magazine" }, 10 },
				{ { "ItemGlass", "magazine" }, 15 },
				{ { "ItemDuctTape", "magazine" }, 20 },
				{ { "ItemRotor", "magazine" }, 5 }
		};
	};
	class VehicleDocs
	{
		items[] = {
				{ { "ItemVehDoc1", "magazine" }, 20 },
				{ { "ItemVehDoc2", "magazine" }, 15 },
				{ { "ItemVehDoc3", "magazine" }, 4 },
				{ { "ItemVehDoc4", "magazine" }, 2 }
		};
	};
	class Equipment
	{
		items[] = {
				{ { "Rangefinder", "weapon" }, 5 },
				{ { "Binocular", "item" }, 35 },
				{ { "NVG_EPOCH", "item" }, 10 },
				{ { "acc_flashlight", "item" }, 15 },
				{ { "acc_pointer_IR", "item" }, 15 },
				// Marksman DLC
				{ { "Bipods", "CfgLootTable" }, 5 },
				// CUP
				{ { "CUP_Equipment", "CfgLootTable" }, 10 },
				{ { "CUP_sniperCamo", "CfgLootTable" }, 5 }
		};
	};
	class CUP_Equipment
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
	class CUP_sniperCamo
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
	class SniperRifle
	{
		items[] = {
				{ { "SniperRiflem107", "CfgLootTable" }, 8 },

				// Marksman DLC
				{ { "SniperRifleMarkDLC", "CfgLootTable" }, 10 },

				{ { "srifle_LRR_F", "weapon" }, 6 },
                { { "srifle_LRR_camo_F", "weapon" }, 5 },
				{ { "srifle_GM6_F", "weapon" }, 14 },
				{ { "srifle_DMR_01_F", "weapon" }, 12 },
				{ { "SniperRifleM14", "CfgLootTable" }, 18 },
				{ { "srifle_EBR_F", "weapon" }, 15 },
				// CUP
				{ { "CUP_SniperRifles", "CfgLootTable" }, 12 }

		};
	};
	class CUP_SniperRifles
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
	// All Marksman DLC weapons without attachments
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
	class SniperRiflem107
	{
		items[] = {
				{ { "m107_EPOCH", "weapon" }, 1 },
				{ { "m107Tan_EPOCH", "weapon" }, 1 }
		};
	};
	class SniperRifleM14
	{
		items[] = {
				{ { "M14_EPOCH", "weapon" }, 1 },
				{ { "M14Grn_EPOCH", "weapon" }, 1 }
		};
	};

	class SniperRifleAmmo
	{
		items[] = {
				{ { "20Rnd_762x51_Mag", "magazine" }, 1 },
				{ { "SniperRifleAmmo_5Rnd_127x108_Mag", "CfgLootTable" }, 1 },
				{ { "7Rnd_408_Mag", "magazine" }, 1 },
				{ { "10Rnd_762x54_Mag", "magazine" }, 1 },
				{ { "10Rnd_338_Mag", "magazine" }, 1 },
				{ { "10Rnd_93x64_DMR_05_Mag", "magazine" }, 1 },
				{ { "10Rnd_127x54_Mag", "magazine" }, 1 },
				{ { "CUP_SniperRifleAmmo", "CfgLootTable" }, 14 }
		};
	};
	class CUP_SniperRifleAmmo
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

	class SniperRifleAmmo_5Rnd_127x108_Mag
	{
		items[] = {
				{ { "5Rnd_127x108_Mag", "magazine" }, 1 },
				{ { "5Rnd_127x108_APDS_Mag", "magazine" }, 1 }
		};
	};

	class Generic
	{
		items[] = {
				{ { "ItemDocument", "magazine" }, 5 },
				{ { "ItemMixOil", "magazine" }, 4 },
				{ { "ItemCoolerE", "magazine" }, 6 },
				{ { "CircuitParts", "magazine" }, 8 },
				{ { "Repairs", "CfgLootTable" }, 7 },
				{ { "Towelette", "magazine" }, 14 },
				{ { "HotColdPacks", "CfgLootTable" }, 9 },
				{ { "PaintCans", "CfgLootTable" }, 9 },
				{ { "Sodas", "CfgLootTable" }, 8 },
				{ { "CanFood", "CfgLootTable" }, 8 },
				{ { "Primitive", "CfgLootTable" }, 21 },
				{ { "lighter_epoch", "magazine" }, 1 },
				{ { "Seeds", "CfgLootTable" }, 1 },
				{ { "ItemAluminumBar", "magazine" }, 2 },
				{ { "ItemCopperBar", "magazine" }, 2 },
				{ { "ItemTinBar", "magazine" }, 1 }
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
	class Sodas
	{
		items[] = {
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
	class CanFood
	{
		items[] = {
				{ { "ItemPowderMilk", "magazine" }, 3 },
				{ { "ItemRicebox", "magazine" }, 3 },
				{ { "ItemCereals", "magazine" }, 3 },
				{ { "ItemVitamins", "magazine" }, 3 },
				{ { "honey_epoch", "magazine" }, 5 },
				{ { "emptyjar_epoch", "magazine" }, 13 },
				{ { "FoodBioMeat", "magazine" }, 11 },
				{ { "sardines_epoch", "magazine" }, 11 },
				{ { "meatballs_epoch", "magazine" }, 13 },
				{ { "scam_epoch", "magazine" }, 14 },
				{ { "sweetcorn_epoch", "magazine" }, 14 },
				{ { "FoodSnooter", "magazine" }, 9 },
				{ { "TacticalBacon", "magazine" }, 5 },
				{ { "FoodMeeps", "magazine" }, 1 },
				{ { "ItemEmptyTin", "magazine" }, 5 }
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

	class GenericBed
	{
		items[] = {
				{ { "VehicleDocs", "CfgLootTable" }, 3 },
				{ { "ItemLockbox", "magazine" }, 5 },
				{ { "ItemMixOil", "magazine" }, 4 },
				{ { "ItemCoolerE", "magazine" }, 6 },
				{ { "CircuitParts", "magazine" }, 8 },
				{ { "Repairs", "CfgLootTable" }, 7 },
				{ { "Towelette", "magazine" }, 14 },
				{ { "HotColdPacks", "CfgLootTable" }, 8 },
				{ { "PaintCans", "CfgLootTable" }, 9 },
				{ { "Sodas", "CfgLootTable" }, 8 },
				{ { "CanFood", "CfgLootTable" }, 8 },
				{ { "Primitive", "CfgLootTable" }, 23 }
		};
	};

	class GenericLarge
	{
		items[] = {
				{ { "VehicleDocs", "CfgLootTable" }, 4 },
				{ { "MortarBucket", "magazine" }, 16 },
				{ { "CinderBlocks", "magazine" }, 17 },
				{ { "Repairs", "CfgLootTable" }, 16 },
				{ { "CircuitParts", "magazine" }, 17 },
				{ { "ItemCorrugated", "magazine" }, 17 },
				{ { "ItemSolar", "magazine" }, 5 },
				{ { "ItemBattery", "magazine" }, 5 },
				{ { "ItemCables", "magazine" }, 5 },
				{ { "ItemSafe", "magazine" }, 1 },
				{ { "ItemBarrelE", "magazine" }, 1 }
		};
	};

	class GenericAuto
	{
		items[] = {
				{ { "VehicleDocs", "CfgLootTable" }, 4 },
				{ { "ItemSafe", "magazine" }, 1 },
				{ { "ItemLockbox", "magazine" }, 4 },
				{ { "jerrycan_epoch", "magazine" }, 5 },
				{ { "CircuitParts", "magazine" }, 6 },
				{ { "MortarBucket", "magazine" }, 9 },
				{ { "Repairs", "CfgLootTable" }, 10 },
				{ { "ItemCorrugated", "magazine" }, 11 },
				{ { "CinderBlocks", "magazine" }, 12 },
				{ { "JackKit", "magazine" }, 8 },
				{ { "ItemCoolerE", "magazine" }, 13 },
				{ { "ItemScraps", "magazine" }, 13 },
				{ { "lighter_epoch", "magazine" }, 1 },
				{ { "ItemSolar", "magazine" }, 3 },
				{ { "ItemBattery", "magazine" }, 3 },
				{ { "ItemCables", "magazine" }, 3 },
				{ { "ItemBarrelE", "magazine" }, 1 }
		};
	};

	class Rifle
	{
		items[] = {
				{ { "AKM_EPOCH", "weapon" }, 3 },
				{ { "sr25_epoch", "weapon" }, 4 },
				{ { "Rifle_arifle_Katiba_F", "CfgLootTable" }, 5 },
				{ { "Rifle_arifle_MX_GL_F", "CfgLootTable" }, 6 },
				{ { "Rifle_l85a2_epoch", "CfgLootTable" }, 6 },
				{ { "m4a3_EPOCH", "weapon" }, 7 },
				{ { "Rifle_m16_EPOCH", "CfgLootTable" }, 7 },
				{ { "Rifle_arifle_Mk20_F", "CfgLootTable" }, 8 },
				{ { "Rifle_arifle_TRG21_F", "CfgLootTable" }, 8 },
				{ { "arifle_SDAR_F", "weapon" }, 9 },
				{ { "Rollins_F", "weapon" }, 9 },
				{ { "SMG_01_F", "weapon" }, 9 },
				{ { "SMG_02_F", "weapon" }, 9 },
				{ { "hgun_PDW2000_F", "weapon" }, 10 },
				// CUP custom
				{ { "CUP_arifles", "CfgLootTable" }, 5 },
				{ { "CUP_shotguns", "CfgLootTable" }, 5 },
				{ { "CUP_smg", "CfgLootTable" }, 5 }


		};
	};
	class CUP_arifles
	{
		items[] = {
			{ { "CUP_arifle_AK107_GL", "weapon" }, 1 },
			{ { "CUP_arifle_AK47", "weapon" }, 1 },
			{ { "CUP_arifle_AK74", "weapon" }, 1 },
			{ { "CUP_arifle_AK74_GL", "weapon" }, 1 },
			{ { "CUP_arifle_AK74M", "weapon" }, 1 },
			{ { "CUP_arifle_AK74M_GL", "weapon" }, 1 },
			{ { "CUP_arifle_AKM", "weapon" }, 1 },
			{ { "CUP_arifle_AKS", "weapon" }, 1 },
			{ { "CUP_arifle_AKS_Gold", "weapon" }, 1 },
			{ { "CUP_arifle_AKS74", "weapon" }, 1 },
			{ { "CUP_arifle_RPK74", "weapon" }, 1 },
			{ { "CUP_arifle_L85A2_GL", "weapon" }, 1 },
			{ { "CUP_arifle_M16A4_Base", "weapon" }, 1 },
			{ { "CUP_arifle_M4A1_black", "weapon" }, 1 },
			{ { "CUP_arifle_M4A1_BUIS_GL", "weapon" }, 1 },
			{ { "CUP_arifle_M4A1_BUIS_camo_GL", "weapon" }, 1 },
			{ { "CUP_arifle_M4A1_BUIS_desert_GL", "weapon" }, 1 },
			{ { "CUP_arifle_M16A2", "weapon" }, 1 },
			{ { "CUP_arifle_M16A2_GL", "weapon" }, 1 },
			{ { "CUP_arifle_M16A4_GL", "weapon" }, 1 },
			{ { "CUP_arifle_M4A3_desert", "weapon" }, 1 },
			{ { "CUP_arifle_M4A1", "weapon" }, 1 },
			{ { "CUP_arifle_CZ805_A1", "weapon" }, 1 },
			{ { "CUP_arifle_CZ805_GL", "weapon" }, 1 },
			{ { "CUP_arifle_CZ805_B_GL", "weapon" }, 1 },
			{ { "CUP_arifle_FNFAL", "weapon" }, 1 },
			{ { "CUP_arifle_FNFAL_railed", "weapon" }, 1 },
			{ { "CUP_arifle_FNFAL5061", "weapon" }, 1 },
			{ { "CUP_arifle_G36A", "weapon" }, 1 },
			{ { "CUP_arifle_G36K", "weapon" }, 1 },
			{ { "CUP_arifle_G36C", "weapon" }, 1 },
			{ { "CUP_arifle_MG36", "weapon" }, 1 },
			{ { "CUP_arifle_Mk16_CQC", "weapon" }, 1 },
			{ { "CUP_arifle_Mk16_CQC_FG", "weapon" }, 1 },
			{ { "CUP_arifle_Mk16_CQC_SFG", "weapon" }, 1 },
			{ { "CUP_arifle_Mk16_CQC_EGLM", "weapon" }, 1 },
			{ { "CUP_arifle_Mk16_STD", "weapon" }, 1 },
			{ { "CUP_arifle_Mk16_STD_FG", "weapon" }, 1 },
			{ { "CUP_arifle_Mk16_STD_SFG", "weapon" }, 1 },
			{ { "CUP_arifle_Mk16_STD_EGLM", "weapon" }, 1 },
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
			{ { "CUP_arifle_Sa58RIS1", "weapon" }, 1 },
			{ { "CUP_arifle_Sa58RIS2_gl", "weapon" }, 1 },
			{ { "CUP_arifle_XM8_Carbine_FG", "weapon" }, 1 },
			{ { "CUP_arifle_XM8_Carbine", "weapon" }, 1 },
			{ { "CUP_arifle_XM8_Carbine_GL", "weapon" }, 1 },
			{ { "CUP_arifle_xm8_sharpshooter", "weapon" }, 1 },
			{ { "CUP_arifle_xm8_SAW", "weapon" }, 1 },
			{ { "CUP_arifle_XM8_Compact", "weapon" }, 1 },
			{ { "CUP_arifle_XM8_Compact_Rail", "weapon" }, 1 },
			{ { "CUP_arifle_CZ805_A2", "weapon" }, 1 },
			{ { "CUP_arifle_CZ805_B", "weapon" }, 1 },
			{ { "CUP_arifle_Sa58P", "weapon" }, 1 },
			{ { "CUP_arifle_Sa58P_des", "weapon" }, 1 },
			{ { "CUP_arifle_Sa58V", "weapon" }, 1 },
			{ { "CUP_arifle_Sa58V_camo", "weapon" }, 1 },
			{ { "CUP_arifle_Sa58RIS1_des", "weapon" }, 1 },
			{ { "CUP_arifle_Sa58RIS2", "weapon" }, 1 },
			{ { "CUP_arifle_Sa58RIS2_camo", "weapon" }, 1 },
			{ { "CUP_arifle_AK107", "weapon" }, 1 },
			{ { "CUP_arifle_AKS74U", "weapon" }, 1 },
			{ { "CUP_arifle_RPK74_45", "weapon" }, 1 },
			{ { "CUP_arifle_RPK74M", "weapon" }, 1 },
			{ { "CUP_arifle_FNFAL5062", "weapon" }, 1 },
			{ { "CUP_arifle_FNFAL_OSW", "weapon" }, 1 },
			{ { "CUP_arifle_G36A_camo", "weapon" }, 1 },
			{ { "CUP_arifle_G36K_camo", "weapon" }, 1 },
			{ { "CUP_arifle_G36C_camo", "weapon" }, 1 },
			{ { "CUP_arifle_MG36_camo", "weapon" }, 1 },
			{ { "CUP_arifle_L85A2", "weapon" }, 1 },
			{ { "CUP_arifle_L86A2", "weapon" }, 1 },
			{ { "CUP_arifle_M4A1_camo", "weapon" }, 1 },
			{ { "CUP_arifle_M4A1_desert", "weapon" }, 1 },
			{ { "CUP_arifle_XM8_Railed", "weapon" }, 1 }
		};
	};
	class CUP_smg
	{
		items[] = {
				{ { "CUP_smg_bizon", "weapon" }, 1 },
				{ { "CUP_smg_EVO", "weapon" }, 1 },
				{ { "CUP_smg_MP5SD6", "weapon" }, 1 },
				{ { "CUP_smg_MP5A5", "weapon" }, 1 }
		};
	};


	class CUP_shotguns
	{
		items[] = {
				{ { "VG_sawed_off_01", "weapon" }, 3 },
                { { "Devastator_01", "weapon" }, 3 },
                { { "CUP_sgun_AA12", "weapon" }, 1 },
				{ { "CUP_sgun_M1014", "weapon" }, 1 },
				{ { "CUP_sgun_Saiga12K", "weapon" }, 1 }

		};
	};
	class Rifle_CUP_arifle_AK
	{
		items[] = {
				{ { "CUP_arifle_AK74", "weapon" }, 1 },
				{ { "CUP_arifle_AK74M", "weapon" }, 1 },
				{ { "CUP_arifle_AK74_GL", "weapon" }, 1 },
				{ { "CUP_arifle_AK74_GL_kobra", "weapon" }, 1 },
				{ { "CUP_arifle_AKS", "weapon" }, 1 },
				{ { "CUP_arifle_AKS_Gold", "weapon" }, 1 },
				{ { "CUP_arifle_AKS74", "weapon" }, 1 },
				{ { "CUP_arifle_AKS74U", "weapon" }, 1 },
				{ { "CUP_arifle_AK107", "weapon" }, 1 },
				{ { "CUP_arifle_AK107_GL", "weapon" }, 1 },
				{ { "CUP_arifle_AKM", "weapon" }, 1 }
		};
	};
	class Rifle_CUP_arifle_CZ
	{
		items[] = {
				{ { "CUP_arifle_CZ805_A1", "weapon" }, 1 },
				{ { "CUP_arifle_CZ805_GL", "weapon" }, 1 },
				{ { "CUP_arifle_CZ805_A2", "weapon" }, 1 },
				{ { "CUP_arifle_CZ805_B", "weapon" }, 1 },
				{ { "CUP_arifle_CZ805_B_GL", "weapon" }, 1 }
		};
	};
	class Rifle_CUP_arifle_FNFAL
	{
		items[] = {
				{ { "CUP_arifle_FNFAL", "weapon" }, 1 },
				{ { "CUP_arifle_FNFAL_railed", "weapon" }, 1 }
		};
	};
	class Rifle_CUP_arifle_G36
	{
		items[] = {
				{ { "CUP_arifle_G36A", "weapon" }, 1 },
				{ { "CUP_arifle_G36A_camo", "weapon" }, 1 },
				{ { "CUP_arifle_G36K", "weapon" }, 1 },
				{ { "CUP_arifle_G36K_camo", "weapon" }, 1 },
				{ { "CUP_arifle_G36C", "weapon" }, 1 },
				{ { "CUP_arifle_G36C_camo", "weapon" }, 1 }
		};
	};
	class Rifle_CUP_arifle_L85A2
	{
		items[] = {
				{ { "CUP_arifle_L85A2", "weapon" }, 1 },
				{ { "CUP_arifle_L85A2_GL", "weapon" }, 1 }
		};
	};
	class Rifle_CUP_arifle_M16
	{
		items[] = {
				{ { "CUP_arifle_M16A2", "weapon" }, 1 },
				{ { "CUP_arifle_M16A2_GL", "weapon" }, 1 },
				{ { "CUP_arifle_M16A4_Base", "weapon" }, 1 },
				{ { "CUP_arifle_M16A4_GL", "weapon" }, 1 }
		};
	};
	class Rifle_CUP_arifle_M4
	{
		items[] = {
				{ { "CUP_arifle_M4A1_BUIS_GL", "weapon" }, 1 },
				{ { "CUP_arifle_M4A1_BUIS_camo_GL", "weapon" }, 1 },
				{ { "CUP_arifle_M4A1_BUIS_desert_GL", "weapon" }, 1 },
				{ { "CUP_arifle_M4A1", "weapon" }, 1 },
				{ { "CUP_arifle_M4A1_camo", "weapon" }, 1 },
				{ { "CUP_arifle_M4A1_black", "weapon" }, 1 },
				{ { "CUP_arifle_M4A1_desert", "weapon" }, 1 },
				{ { "CUP_arifle_M4A3_desert", "weapon" }, 1 }
		};
	};
	class Rifle_CUP_arifle_Sa58
	{
		items[] = {
				{ { "CUP_arifle_Sa58P", "weapon" }, 1 },
				{ { "CUP_arifle_Sa58V", "weapon" }, 1 },
				{ { "CUP_arifle_Sa58RIS1", "weapon" }, 1 },
				{ { "CUP_arifle_Sa58RIS2", "weapon" }, 1 },
				{ { "CUP_arifle_Sa58RIS2_gl", "weapon" }, 1 },
				{ { "CUP_arifle_Sa58P_des", "weapon" }, 1 },
				{ { "CUP_arifle_Sa58V_camo", "weapon" }, 1 },
				{ { "CUP_arifle_Sa58RIS1_des", "weapon" }, 1 },
				{ { "CUP_arifle_Sa58RIS2_camo", "weapon" }, 1 }
		};
	};
	class Rifle_CUP_arifle_Mk16
	{
		items[] = {
				{ { "CUP_arifle_Mk16_STD", "weapon" }, 1 },
				{ { "CUP_arifle_Mk16_STD_FG", "weapon" }, 1 },
				{ { "CUP_arifle_Mk16_STD_SFG", "weapon" }, 1 },
				{ { "CUP_arifle_Mk16_STD_EGLM", "weapon" }, 1 },
				{ { "CUP_arifle_Mk16_CQC", "weapon" }, 1 },
				{ { "CUP_arifle_Mk16_CQC_FG", "weapon" }, 1 },
				{ { "CUP_arifle_Mk16_CQC_SFG", "weapon" }, 1 },
				{ { "CUP_arifle_Mk16_CQC_EGLM", "weapon" }, 1 },
				{ { "CUP_arifle_Mk16_SV", "weapon" }, 1 }
		};
	};
	class Rifle_CUP_arifle_Mk17
	{
		items[] = {
				{ { "CUP_arifle_Mk17_CQC", "weapon" }, 1 },
				{ { "CUP_arifle_Mk17_CQC_FG", "weapon" }, 1 },
				{ { "CUP_arifle_Mk17_CQC_SFG", "weapon" }, 1 },
				{ { "CUP_arifle_Mk17_CQC_EGLM", "weapon" }, 1 },
				{ { "CUP_arifle_Mk17_STD", "weapon" }, 1 },
				{ { "CUP_arifle_Mk17_STD_FG", "weapon" }, 1 },
				{ { "CUP_arifle_Mk17_STD_SFG", "weapon" }, 1 },
				{ { "CUP_arifle_Mk17_STD_EGLM", "weapon" }, 1 }
		};
	};
	class Rifle_CUP_arifle_Mk20
	{
		items[] = {
				{ { "CUP_arifle_Mk20", "weapon" }, 1 }
		};
	};
	class Rifle_CUP_arifle_XM8
	{
		items[] = {
				{ { "CUP_arifle_XM8_Carbine", "weapon" }, 1 },
				{ { "CUP_arifle_XM8_Carbine_GL", "weapon" }, 1 },
				{ { "CUP_arifle_xm8_sharpshooter", "weapon" }, 1 },
				{ { "CUP_arifle_XM8_Compact", "weapon" }, 1 },
				{ { "CUP_arifle_XM8_Compact_Rail", "weapon" }, 1 },
				{ { "CUP_arifle_XM8_Railed", "weapon" }, 1 },
				{ { "CUP_arifle_XM8_Carbine_FG", "weapon" }, 1 }
		};
	};

	class Rifle_l85a2_epoch
	{
		items[] = {
				{ { "l85a2_epoch", "weapon" }, 1 },
				{ { "l85a2_pink_epoch", "weapon" }, 1 },
				{ { "l85a2_ugl_epoch", "weapon" }, 1 }
		};
	};

	class Rifle_arifle_TRG21_F
	{
		items[] = {
				{ { "arifle_TRG21_GL_F", "weapon" }, 2 },
				{ { "arifle_TRG21_F", "weapon" }, 3 },
				{ { "arifle_TRG20_F", "weapon" }, 5 }
		};
	};

	class Rifle_arifle_Katiba_F
	{
		items[] = {
				{ { "arifle_Katiba_GL_F", "weapon" }, 2 },
				{ { "arifle_Katiba_C_F", "weapon" }, 3 },
				{ { "arifle_Katiba_F", "weapon" }, 5 }
		};
	};

	class Rifle_arifle_Mk20_F
	{
		items[] = {
				{ { "arifle_Mk20_GL_F", "weapon" }, 12 },
				{ { "arifle_Mk20_GL_plain_F", "weapon" }, 12 },
				{ { "arifle_Mk20C_F", "weapon" }, 16 },
				{ { "arifle_Mk20C_plain_F", "weapon" }, 18 },
				{ { "arifle_Mk20_F", "weapon" }, 20 },
				{ { "arifle_Mk20_plain_F", "weapon" }, 22 }
		};
	};

	class Rifle_m16_EPOCH
	{
		items[] = {
				{ { "m16_EPOCH", "weapon" }, 2 },
				{ { "m16Red_EPOCH", "weapon" }, 1 }
		};
	};

	class Rifle_arifle_MX_GL_F
	{
		items[] = {
				{ { "arifle_MX_GL_F", "weapon" }, 3 },
				{ { "arifle_MX_GL_Black_F", "weapon" }, 2 },
				{ { "arifle_MXM_Black_F", "weapon" }, 2 },
				{ { "arifle_MXC_Black_F", "weapon" }, 3 },
				{ { "arifle_MX_Black_F", "weapon" }, 2 },
				{ { "arifle_MXM_F", "weapon" }, 3 },
				{ { "arifle_MXC_F", "weapon" }, 3 },
				{ { "arifle_MX_F", "weapon" }, 3 }
		};
	};
	class RifleBoat
	{
		items[] = {
				{ { "Rollins_F", "weapon" }, 10 },
				{ { "SMG_02_F", "weapon" }, 12 },
				{ { "SMG_01_F", "weapon" }, 16 },
				{ { "hgun_PDW2000_F", "weapon" }, 18 },
				{ { "arifle_SDAR_F", "weapon" }, 20 },
				{ { "speargun_epoch", "weapon" }, 22 }
		};
	};
	class RifleAmmoBoat
	{
		items[] = {
				{ { "30Rnd_9x21_Mag", "magazine" }, 10 },
				{ { "16Rnd_9x21_Mag", "magazine" }, 15 },
				{ { "spear_magazine", "magazine" }, 20 },
				{ { "20Rnd_556x45_UW_mag", "magazine" }, 25 },
				{ { "5Rnd_rollins_mag", "magazine" }, 30 }
		};
	};
	class RifleAmmo
	{
		items[] = {
				{ { "30Rnd_762x39_Mag", "magazine" }, 8 },
				{ { "RifleAmmo_30Rnd_65x39_caseless_mag", "CfgLootTable" }, 11 },
				{ { "20Rnd_556x45_UW_mag", "magazine" }, 7 },
				{ { "RifleAmmo_30Rnd_556x45_Stanag", "CfgLootTable" }, 10 },
				{ { "RifleAmmo_30Rnd_45ACP_Mag_SMG_01", "CfgLootTable" }, 11 },
				{ { "30Rnd_9x21_Mag", "magazine" }, 12 },
				{ { "5Rnd_rollins_mag", "magazine" }, 15 },
				{ { "CUP_RifleAmmo", "CfgLootTable" }, 26 }
		};
	};
	class CUP_RifleAmmo
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
				{ { "CUP_30Rnd_Sa58_M", "magazine" }, 1 }
		};
	};


	class RifleAmmo_30Rnd_556x45_Stanag
	{
		items[] = {
				{ { "30Rnd_556x45_Stanag", "magazine" }, 4 },
				{ { "30Rnd_556x45_Stanag_Tracer_Red", "magazine" }, 2 },
				{ { "30Rnd_556x45_Stanag_Tracer_Green", "magazine" }, 2 },
				{ { "30Rnd_556x45_Stanag_Tracer_Yellow", "magazine" }, 2 }
		};
	};

	class RifleAmmo_30Rnd_65x39_caseless_mag
	{
		items[] = {
				{ { "30Rnd_65x39_caseless_mag", "magazine" }, 3 },
				{ { "30Rnd_65x39_caseless_mag_Tracer", "magazine" }, 2 },
				{ { "30Rnd_65x39_caseless_green", "magazine" }, 3 },
				{ { "30Rnd_65x39_caseless_green_mag_Tracer", "magazine" }, 2 }
		};
	};

	class RifleAmmo_30Rnd_45ACP_Mag_SMG_01
	{
		items[] = {
				{ { "30Rnd_45ACP_Mag_SMG_01", "magazine" }, 2 },
				{ { "30Rnd_45ACP_Mag_SMG_01_Tracer_Green", "magazine" }, 1 }
		};
	};

	class Grenades
	{
		items[] = {
				{ { "SmokeGrenades3Rnd", "CfgLootTable" }, 2 },
				{ { "Flares", "CfgLootTable" }, 3 },
				{ { "SmokeGrenades1Rnd", "CfgLootTable" }, 5 }
		};
	};

	class Flares
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

	class SmokeGrenades1Rnd
	{
		items[] = {
				{ { "1Rnd_Smoke_Grenade_shell", "magazine" }, 1 },
				{ { "1Rnd_SmokeRed_Grenade_shell", "magazine" }, 1 },
				{ { "1Rnd_SmokeGreen_Grenade_shell", "magazine" }, 1 },
				{ { "1Rnd_SmokeYellow_Grenade_shell", "magazine" }, 1 },
				{ { "1Rnd_SmokePurple_Grenade_shell", "magazine" }, 1 },
				{ { "1Rnd_SmokeBlue_Grenade_shell", "magazine" }, 1 },
				{ { "1Rnd_SmokeOrange_Grenade_shell", "magazine" }, 1 }
		};
	};

	class SmokeGrenades3Rnd
	{
		items[] = {
				{ { "3Rnd_Smoke_Grenade_shell", "magazine" }, 1 },
				{ { "3Rnd_SmokeRed_Grenade_shell", "magazine" }, 1 },
				{ { "3Rnd_SmokeGreen_Grenade_shell", "magazine" }, 1 },
				{ { "3Rnd_SmokeYellow_Grenade_shell", "magazine" }, 1 },
				{ { "3Rnd_SmokePurple_Grenade_shell", "magazine" }, 1 },
				{ { "3Rnd_SmokeBlue_Grenade_shell", "magazine" }, 1 },
				{ { "3Rnd_SmokeOrange_Grenade_shell", "magazine" }, 1 }
		};
	};

	class Machinegun
	{
		items[] = {
				{ { "LMG_Zafir_F", "weapon" }, 1 },
				{ { "Machinegun_arifle_MX_SW_F", "CfgLootTable" }, 2 },
				{ { "LMG_Mk200_F", "weapon" }, 3 },
				{ { "Machinegun_m249_EPOCH", "CfgLootTable" }, 3 },
				{ { "MMG_MarkDLC_EPOCH", "CfgLootTable" }, 1 },
				// CUP
				{ { "CUP_lmgs", "CfgLootTable" }, 1 }

		};
	};
	class CUP_lmgs
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


	class MMG_MarkDLC_EPOCH
	{
		items[] = {
				{ { "MMG_01_hex_F", "weapon" }, 1 },
				{ { "MMG_01_tan_F", "weapon" }, 1 },
				{ { "MMG_02_camo_F", "weapon" }, 1 },
				{ { "MMG_02_black_F", "weapon" }, 1 },
				{ { "MMG_02_sand_F", "weapon" }, 1 }
		};
	};

	class Machinegun_m249_EPOCH
	{
		items[] = {
				{ { "m249_EPOCH", "weapon" }, 1 },
				{ { "m249Tan_EPOCH", "weapon" }, 1 }
		};
	};
	class Machinegun_arifle_MX_SW_F
	{
		items[] = {
				{ { "arifle_MX_SW_F", "weapon" }, 2 },
				{ { "arifle_MX_SW_Black_F", "weapon" }, 1 }
		};
	};

	class MachinegunAmmo
	{
		items[] = {
				{ { "MachinegunAmmo_200Rnd_65x39_cased_Box", "CfgLootTable" }, 8 },
				{ { "130Rnd_338_Mag", "magazine" }, 6 },
				{ { "MachinegunAmmo_150Rnd_762x54_Box", "CfgLootTable" }, 10 },
				{ { "MachinegunAmmo_100Rnd_65x39_caseless_mag", "CfgLootTable" }, 13 },
				{ { "200Rnd_556x45_M249", "magazine" }, 10 },
				{ { "150Rnd_93x64_Mag", "magazine" }, 10 },
				{ { "MachinegunAmmo_30Rnd_65x39_caseless_mag", "CfgLootTable" }, 20 },
				{ { "CUP_MachinegunAmmo", "CfgLootTable" }, 23 }
		};
	};
	class CUP_MachinegunAmmo
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
				{ { "CUP_50Rnd_UK59_762x54R_Tracer", "magazine" }, 1 }
		};
	};
	class CUP_SubMachinegunAmmo
	{
		items[] = {
				{ { "CUP_64Rnd_9x19_Bizon_M", "magazine" }, 1 },
				{ { "CUP_64Rnd_Green_Tracer_9x19_Bizon_M", "magazine" }, 1 },
				{ { "CUP_64Rnd_Red_Tracer_9x19_Bizon_M", "magazine" }, 1 },
				{ { "CUP_64Rnd_White_Tracer_9x19_Bizon_M", "magazine" }, 1 },
				{ { "CUP_64Rnd_Yellow_Tracer_9x19_Bizon_M", "magazine" }, 1 },
				{ { "CUP_30Rnd_9x19_EVO", "magazine" }, 1 },
				{ { "CUP_30Rnd_9x19_MP5", "magazine" }, 1 }
		};
	};
	class MachinegunAmmo_30Rnd_65x39_caseless_mag
	{
		items[] = {
				{ { "30Rnd_65x39_caseless_mag", "magazine" }, 2 },
				{ { "30Rnd_65x39_caseless_mag_Tracer", "magazine" }, 1 }
		};
	};
	class MachinegunAmmo_200Rnd_65x39_cased_Box
	{
		items[] = {
				{ { "200Rnd_65x39_cased_Box", "magazine" }, 2 },
				{ { "200Rnd_65x39_cased_Box_Tracer", "magazine" }, 1 }
		};
	};
	class MachinegunAmmo_150Rnd_762x54_Box
	{
		items[] = {
				{ { "150Rnd_762x54_Box", "magazine" }, 2 },
				{ { "150Rnd_762x54_Box_Tracer", "magazine" }, 1 }
		};
	};
	class MachinegunAmmo_100Rnd_65x39_caseless_mag
	{
		items[] = {
				{ { "100Rnd_65x39_caseless_mag", "magazine" }, 2 },
				{ { "100Rnd_65x39_caseless_mag_Tracer", "magazine" }, 1 }
		};
	};

	class Tools
	{
		items[] = {
				{ { "Hatchet", "weapon" }, 62 },
				{ { "MeleeSledge", "weapon" }, 20 },
				{ { "ChainSaw", "weapon" }, 10 },
				{ { "Plunger", "weapon" }, 4 },
				{ { "MeleeSword", "weapon" }, 1 },
				{ { "MeleeRod", "weapon" }, 2 },
				{ { "lighter_epoch", "magazine" }, 1 }
		};
	};

	class Pistols
	{
		items[] = {
				{ { "revolver01", "weapon" }, 17 },
				{ { "Hgun_Pistol_Signal_F", "weapon" }, 4 },
				{ { "MultiGun", "weapon" }, 5 },
				{ { "hgun_Pistol_heavy_01_F", "weapon" }, 9 },
				{ { "hgun_P07_F", "weapon" }, 10 },
				{ { "hgun_Rook40_F", "weapon" }, 11 },
				{ { "hgun_Pistol_heavy_02_F", "weapon" }, 13 },
				{ { "1911_pistol_epoch", "weapon" }, 11 },
				{ { "hgun_ACPC2_F", "weapon" }, 10 },
				{ { "ruger_pistol_epoch", "weapon" }, 10 },
				// CUP
				{ { "CUP_pistols", "CfgLootTable" }, 15 }
		};
	};
	class CUP_pistols
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

	class PistolAmmo
	{
		items[] = {
				{ { "EnergyPack", "magazine" }, 4 },
				{ { "6Rnd_RedSignal_F", "magazine" }, 2 },
				{ { "6Rnd_GreenSignal_F", "magazine" }, 2 },
				{ { "30Rnd_9x21_Mag", "magazine" }, 8 },
				{ { "6Rnd_45ACP_Cylinder", "magazine" }, 9 },
				{ { "16Rnd_9x21_Mag", "magazine" }, 9 },
				{ { "11Rnd_45ACP_Mag", "magazine" }, 10 },
				{ { "9Rnd_45ACP_Mag", "magazine" }, 11 },
				{ { "9rnd_45X88_magazine", "magazine" }, 12 },
				{ { "10rnd_22X44_magazine", "magazine" }, 13 },
				// CUP
				{ { "CUP_PistolAmmo", "CfgLootTable" }, 10 },
				{ { "CUP_ShotgunAmmo", "CfgLootTable" }, 5 },
				{ { "CUP_SubMachinegunAmmo", "CfgLootTable" }, 5 }

		};
	};
	class CUP_PistolAmmo
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
	class CUP_ShotgunAmmo
	{
		items[] = {
			{ { "in005_1Rnd_12Gauge_Pellets", "magazine" }, 8 },
            { { "in005_1Rnd_12Gauge_Slug", "magazine" }, 8 },
			{ { "CUP_20Rnd_B_AA12_Pellets", "magazine" }, 3 },
			{ { "CUP_20Rnd_B_AA12_74Slug", "magazine" }, 2 },
			{ { "CUP_20Rnd_B_AA12_HE", "magazine" }, 1 },
			{ { "CUP_8Rnd_B_Beneli_74Slug", "magazine" }, 2 },
			{ { "CUP_8Rnd_B_Beneli_74Pellets", "magazine" }, 3 },
			{ { "CUP_8Rnd_B_Saiga12_74Slug_M", "magazine" }, 2 },
			{ { "CUP_8Rnd_B_Saiga12_74Pellets_M", "magazine" }, 3 }
		};
	};
	class Scopes
	{
		items[] = {
				// Marksman DLC
				{ { "ScopeAMSMarkDLC", "CfgLootTable" }, 1 },
				{ { "ScopeKHSMarkDLC", "CfgLootTable" }, 1 },
				{ { "A3_Scopes", "CfgLootTable" }, 2 },
				// CUP
				{ { "CUP_Scopes", "CfgLootTable" }, 2 }
		};
	};
	class A3_Scopes
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
	class CUP_Scopes
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
	class ScopeAMSMarkDLC
	{
		items[] = {
				{ { "optic_AMS", "item" }, 2 },
				{ { "optic_AMS_khk", "item" }, 1 },
				{ { "optic_AMS_snd", "item" }, 1 }
		};
	};
	class ScopeKHSMarkDLC
	{
		items[] = {
				{ { "optic_KHS_blk", "item" }, 1 },
				{ { "optic_KHS_hex", "item" }, 1 },
				{ { "optic_KHS_old", "item" }, 2 },
				{ { "optic_KHS_tan", "item" }, 1 }
		};
	};

	class Bipods
	{
		items[] = {
				{ { "bipod_01_F_snd", "item" }, 1 },
				{ { "bipod_01_F_blk", "item" }, 1 },
				{ { "bipod_01_F_mtp", "item" }, 1 },
				{ { "bipod_02_F_blk", "item" }, 1 },
				{ { "bipod_02_F_tan", "item" }, 1 },
				{ { "bipod_02_F_hex", "item" }, 1 },
				{ { "bipod_03_F_blk", "item" }, 1 },
				{ { "bipod_03_F_oli", "item" }, 1 },
				{ { "CUP_Bipods", "CfgLootTable" }, 2 }
		};
	};
	class CUP_Bipods
	{
		items[] = {
				{ { "CUP_bipod_Harris_1A2_L", "item" }, 1 },
				{ { "CUP_bipod_VLTOR_Modpod", "item" }, 1 }
		};
	};

	class Muzzles
	{
		items[] = {
				{ { "muzzle_sr25S_epoch", "item" }, 1 },
				{ { "muzzle_snds_H", "item" }, 1 },
				{ { "muzzle_snds_M", "item" }, 1 },
				{ { "muzzle_snds_L", "item" }, 1 },
				{ { "muzzle_snds_B", "item" }, 1 },
				{ { "muzzle_snds_H_MG", "item" }, 1 },
				{ { "muzzle_snds_acp", "item" }, 1 },
				{ { "Muzzles_MultiGun", "CfgLootTable" }, 1 },
				// Marksman DLC
				{ { "Muzzles_338MarkDLC", "CfgLootTable" }, 1 },
				{ { "Muzzles_93mmgMarkDLC", "CfgLootTable" }, 1 },
				{ { "CUP_Muzzles", "CfgLootTable" }, 8 }
		};
	};
	class CUP_Muzzles
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

	class Muzzles_338MarkDLC
	{
		items[] = {
				{ { "muzzle_snds_338_black", "item" }, 1 },
				{ { "muzzle_snds_338_green", "item" }, 1 },
				{ { "muzzle_snds_338_sand", "item" }, 1 }

		};
	};
	class Muzzles_93mmgMarkDLC
	{
		items[] = {
				{ { "muzzle_snds_93mmg", "item" }, 1 },
				{ { "muzzle_snds_93mmg_tan", "item" }, 1 }

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

	class Shipwreck
	{
		items[] = {
				{ { "Gems", "CfgLootTable" }, 5 },
				{ { "MetalBars", "CfgLootTable" }, 26 },
				{ { "PartOreGold", "magazine" }, 10 },
				{ { "PartOreSilver", "magazine" }, 13 },
				{ { "ItemKiloHemp", "magazine" }, 12 },
				{ { "ItemScraps", "magazine" }, 16 },
				{ { "PartOre", "magazine" }, 18 }
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
	class Mine
	{
		items[] = {
				{ { "Gems", "CfgLootTable" }, 15 },
				{ { "PartOreGold", "magazine" }, 20 },
				{ { "PartOreSilver", "magazine" }, 30 },
				{ { "PartOre", "magazine" }, 35 }
		};
	};
	class CopperMine
	{
		items[] = {
				{ { "Gems", "CfgLootTable" }, 15 },
				{ { "PartOreGold", "magazine" }, 20 },
				{ { "PartOreSilver", "magazine" }, 30 },
				{ { "PartOre", "magazine" }, 35 }
		};
	};
	class SilverMine
	{
		items[] = {
				{ { "Gems", "CfgLootTable" }, 15 },
				{ { "PartOreGold", "magazine" }, 20 },
				{ { "PartOreSilver", "magazine" }, 35 },
				{ { "PartOre", "magazine" }, 30 }
		};
	};
	class GoldMine
	{
		items[] = {
				{ { "Gems", "CfgLootTable" }, 20 },
				{ { "PartOreGold", "magazine" }, 35 },
				{ { "PartOreSilver", "magazine" }, 20 },
				{ { "PartOre", "magazine" }, 25 }
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
	class Food
	{
		items[] = {
				{ { "ItemCoolerE", "magazine" }, 4 },
				{ { "Sodas", "CfgLootTable" }, 47 },
				{ { "CanFood", "CfgLootTable" }, 49 }
		};
	};
	class Medical
	{
		items[] = {
				{ { "FAK", "magazine" }, 97 },
				{ { "Heal_EPOCH", "item" }, 2 },
				{ { "Defib_EPOCH", "item" }, 1 },
				{ { "EnergyPack", "magazine" }, 1 }
		};
	};
	class BaseBuilding
	{
		items[] = {
				{ { "KitPlotPole", "magazine" }, 5 },
				{ { "KitSolarGen", "magazine" }, 2 },
				{ { "KitStudWall", "magazine" }, 13 },
				{ { "KitShelf", "magazine" }, 9 },
				{ { "KitWorkbench", "magazine" }, 2 },
				{ { "KitWoodFloor", "magazine" }, 10 },
				{ { "KitWoodStairs", "magazine" }, 9 },
				{ { "KitWoodTower", "magazine" }, 5 },
				{ { "KitWoodRamp", "magazine" }, 5 },
				{ { "KitTankTrap", "magazine" }, 2 },
				{ { "KitHesco3", "magazine" }, 1 },
				{ { "KitWoodLadder", "magazine" }, 5 },
				{ { "KitFirePlace", "magazine" }, 8 },
				{ { "KitCinderWall", "magazine" }, 5 },
				{ { "KitFoundation", "magazine" }, 5 },
				{ { "KitWoodFoundation", "magazine" }, 14 },
				{ { "ItemSafe", "magazine" }, 1 }
		};
	};

	class Mission_Payout1
	{
		items[] = {
				{ { "Gems", "CfgLootTable" }, 8 },
				{ { "Sodas", "CfgLootTable" }, 6 },
				{ { "CanFood", "CfgLootTable" }, 8 },
				{ { "BaseBuilding", "CfgLootTable" }, 20 },
				{ { "GenericLarge", "CfgLootTable" }, 24 },
				{ { "ItemLockbox", "magazine" }, 4 },
				{ { "ItemSafe", "magazine" }, 1 },
				{ { "Generic", "CfgLootTable" }, 10 },
				{ { "Tools", "CfgLootTable" }, 19 }
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
				{ { "GoatCarcass_EPOCH", "magazine" }, 1 },
				{ { "Pelt_EPOCH", "magazine" }, 1 }
		};
	};
	class Alsatian_Random_EPOCH
	{
		items[] = {
				{ { "GoatCarcass_EPOCH", "magazine" }, 1 },
				{ { "Pelt_EPOCH", "magazine" }, 1 }
		};
	};
	class Cock_random_EPOCH
	{
		items[] = {
				{ { "ChickenCarcass_EPOCH", "magazine" }, 1 }
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
			{ { "Hand", "CfgLootTable" }, 20 },
			{ { "HotColdPacks", "CfgLootTable" }, 20 },
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
				{ { "HotColdPacks", "CfgLootTable" }, 18 },
				{ { "Pelt_EPOCH", "magazine" }, 31 }
		};
	};

	class HotColdPacks
	{
		items[] = {
				{ { "HeatPack", "magazine" }, 1 },
				{ { "ColdPack", "magazine" }, 1 }
		};
	};

	class Epoch_SapperB_F
	{
		items[] = {
				{ { "ItemGoldBar", "magazine" }, 9 },
				{ { "WhiskeyNoodle", "magazine" }, 13 },
				{ { "ItemKiloHemp", "magazine" }, 15 },
				{ { "ItemSilverBar", "magazine" }, 17 },
				{ { "HotColdPacks", "CfgLootTable" }, 17 },
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
                { { "HotColdPacks", "CfgLootTable" }, 17 },
                { { "Pelt_EPOCH", "magazine" }, 29 }
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
				{ { "Hand", "CfgLootTable" }, 11 },
				{ { "HandGrenade", "magazine" }, 12 },
				{ { "MiniGrenade", "magazine" }, 20 },
				{ { "HotColdPacks", "CfgLootTable" }, 21 },
				{ { "Venom_EPOCH", "magazine" }, 26 }
		};
	};

	class Snake_random_EPOCH
	{
		items[] = {
				{ { "SnakeCarcass_EPOCH", "magazine" }, 1 },
				{ { "Venom_EPOCH", "magazine" }, 1 }
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

	class Hand
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

	class Explosives
	{
		items[] = {
				{ { "HandGrenade", "magazine" }, 25 },
				{ { "MiniGrenade", "magazine" }, 25 },
				{ { "3Rnd_HE_Grenade_shell", "magazine" }, 15 },
				{ { "HighExplosives", "CfgLootTable" }, 35 }
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

	class Backpack
	{
		items[] = {
				{ { "B_AssaultPack_cbr", "backpack" }, 5 },
				{ { "B_AssaultPack_dgtl", "backpack" }, 5 },
				{ { "B_AssaultPack_khk", "backpack" }, 5 },
				{ { "B_AssaultPack_mcamo", "backpack" }, 5 },
				{ { "B_AssaultPack_ocamo", "backpack" }, 5 },
				{ { "B_AssaultPack_rgr", "backpack" }, 5 },
				{ { "B_AssaultPack_sgg", "backpack" }, 5 },
				{ { "B_AssaultPack_blk", "backpack" }, 5 },


				{ { "B_Carryall_cbr", "backpack" }, 1 },
				{ { "B_Carryall_khk", "backpack" }, 1 },
				{ { "B_Carryall_mcamo", "backpack" }, 1 },
				{ { "B_Carryall_ocamo", "backpack" }, 1 },
				{ { "B_Carryall_oli", "backpack" }, 1 },
				{ { "B_Carryall_oucamo", "backpack" }, 1 },

				{ { "B_FieldPack_blk", "backpack" }, 4 },
				{ { "B_FieldPack_cbr", "backpack" }, 4 },
				{ { "B_FieldPack_khk", "backpack" }, 4 },
				{ { "B_FieldPack_ocamo", "backpack" }, 4 },
				{ { "B_FieldPack_oli", "backpack" }, 4 },
				{ { "B_FieldPack_oucamo", "backpack" }, 4 },

				{ { "B_Kitbag_cbr", "backpack" }, 2 },
				{ { "B_Kitbag_mcamo", "backpack" }, 2 },
				{ { "B_Kitbag_rgr", "backpack" }, 2 },
				{ { "B_Kitbag_sgg", "backpack" }, 2 },

				{ { "B_Parachute", "backpack" }, 1 },

				{ { "B_TacticalPack_blk", "backpack" }, 2 },
				{ { "B_TacticalPack_mcamo", "backpack" }, 2 },
				{ { "B_TacticalPack_ocamo", "backpack" }, 2 },
				{ { "B_TacticalPack_oli", "backpack" }, 2 },
				{ { "B_TacticalPack_rgr", "backpack" }, 2 },

				{ { "smallbackpack_red_epoch", "backpack" }, 4 },
				{ { "smallbackpack_green_epoch", "backpack" }, 4 },
				{ { "smallbackpack_teal_epoch", "backpack" }, 4 },
				{ { "smallbackpack_pink_epoch", "backpack" }, 4 }
		};
	};

	class Uniforms
	{
		items[] = {
				{ { "MaleUniforms", "CfgLootTable" }, 1 },
				{ { "FemaleUniforms", "CfgLootTable" }, 1 }
		};
	};

	class MaleUniforms
	{
		items[] = {
				{ { "U_O_CombatUniform_ocamo", "item" }, 1 },
				{ { "U_O_GhillieSuit", "item" }, 1 },
				{ { "U_O_PilotCoveralls", "item" }, 1 },
				{ { "U_O_Wetsuit", "item" }, 1 },
				{ { "MaleUniforms_OG_Guerilla", "CfgLootTable" }, 1 },
				{ { "MaleUniforms_Poloshirt", "CfgLootTable" }, 1 },
				{ { "U_C_Poor_1", "item" }, 1 },
				{ { "U_C_WorkerCoveralls", "item" }, 1 },
				{ { "U_C_Journalist", "item" }, 1 },
				{ { "U_C_Scientist", "item" }, 1 },
				{ { "U_OrestesBody", "item" }, 1 },
				{ { "DLCUniforms", "CfgLootTable" }, 1 },
				{ { "MaleUniforms_FullGhillieMarkDLC", "CfgLootTable" }, 1 },

				// new uniforms
				{ { "U_C_Commoner1_1", "item" }, 1 },
				{ { "U_C_Poor_2", "item" }, 1 },
				{ { "U_C_HunterBody_grn", "item" }, 1 },
				{ { "U_C_Poor_shorts_1", "item" }, 1 },
				{ { "U_C_Commoner_shorts", "item" }, 1 },
				{ { "U_C_ShirtSurfer_shorts", "item" }, 1 },
				{ { "U_C_TeeSurfer_shorts_1", "item" }, 1 },
				{ { "U_C_TeeSurfer_shorts_2", "item" }, 1 },
				{ { "U_NikosBody", "item" }, 1 },
				{ { "U_NikosAgedBody", "item" }, 1 },
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
				{ { "U_I_Wetsuit", "item" }, 1 },
				{ { "U_I_GhillieSuit", "item" }, 1 },
				{ { "U_I_CombatUniform_tshirt", "item" }, 1 },
				{ { "U_O_OfficerUniform_ocamo", "item" }, 1 },
				{ { "U_O_SpecopsUniform_ocamo", "item" }, 1 },
				{ { "U_O_CombatUniform_oucamo", "item" }, 1 },
				{ { "U_Marshal", "item" }, 1 },
				{ { "U_B_Protagonist_VR", "item" }, 1 },
				{ { "U_O_Protagonist_VR", "item" }, 1 },
				{ { "U_I_Protagonist_VR", "item" }, 1 },
				{ { "U_I_FullGhillie_lsh", "item" }, 1 },
				{ { "U_I_FullGhillie_sard", "item" }, 1 },
				{ { "U_I_FullGhillie_ard", "item" }, 1 },
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
				{ { "U_O_T_FullGhillie_tna_F", "item" }, 1 },
				{ { "U_O_V_Soldier_Viper_F", "item" }, 1 },
				{ { "U_O_V_Soldier_Viper_hex_F", "item" }, 1 },
				{ { "U_C_man_sport_1_F", "item" }, 1 },
				{ { "U_C_man_sport_2_F", "item" }, 1 },
				{ { "U_C_man_sport_3_F", "item" }, 1 },
				{ { "U_C_Man_casual_1_F", "item" }, 1 },
				{ { "U_C_Man_casual_2_F", "item" }, 1 },
				{ { "U_C_Man_casual_3_F", "item" }, 1 },
				{ { "U_C_Man_casual_4_F", "item" }, 1 },
				{ { "U_C_Man_casual_5_F", "item" }, 1 },
				{ { "U_C_Man_casual_6_F", "item" }, 1 },
				{ { "U_C_IDAP_Man_cargo_F", "item" }, 1 },
				{ { "U_C_IDAP_Man_jeans_F", "item" }, 1 },
				{ { "U_C_IDAP_Man_TeeShorts_F", "item" }, 1 },
				{ { "U_C_IDAP_Man_Tee_F", "item" }, 1 },
				{ { "U_C_IDAP_Man_casual_F", "item" }, 1 },
				{ { "U_C_IDAP_Man_shorts_F", "item" }, 1 },
				{ { "U_C_ConstructionCoverall_Red_F", "item" }, 1 },
				{ { "U_C_ConstructionCoverall_vrana_F", "item" }, 1 },
				{ { "U_C_ConstructionCoverall_Black_F", "item" }, 1 },
				{ { "U_C_ConstructionCoverall_Blue_F", "item" }, 1 },
				{ { "U_C_Paramedic_01_F", "item" }, 1 },
				{ { "U_C_IDAP_Man_Casual_F", "item" }, 1 },
				{ { "U_C_Mechanic_01_F", "item" }, 1 }
		};
	};

	class MaleUniforms_FullGhillieMarkDLC
	{
		items[] = {
				{ { "U_O_FullGhillie_lsh", "item" }, 1 },
				{ { "U_O_FullGhillie_sard", "item" }, 1 },
				{ { "U_O_FullGhillie_ard", "item" }, 1 }
		};
	};

	class MaleUniforms_Poloshirt
	{
		items[] = {
				{ { "U_C_Poloshirt_stripped", "item" }, 1 },
				{ { "U_C_Poloshirt_blue", "item" }, 1 },
				{ { "U_C_Poloshirt_burgundy", "item" }, 1 },
				{ { "U_C_Poloshirt_tricolour", "item" }, 1 },
				{ { "U_C_Poloshirt_salmon", "item" }, 1 },
				{ { "U_C_Poloshirt_redwhite", "item" }, 1 }
		};
	};

	class MaleUniforms_OG_Guerilla
	{
		items[] = {
				{ { "U_OG_Guerilla1_1", "item" }, 1 },
				{ { "U_OG_Guerilla2_1", "item" }, 1 },
				{ { "U_OG_Guerilla2_2", "item" }, 1 },
				{ { "U_OG_Guerilla2_3", "item" }, 1 },
				{ { "U_OG_Guerilla3_1", "item" }, 1 },
				{ { "U_OG_Guerilla3_2", "item" }, 1 },
				{ { "U_OG_leader", "item" }, 1 }
		};
	};

	class DLCUniforms
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

	class FemaleUniforms
	{
		items[] = {
				{ { "FemaleWetsuits", "CfgLootTable" }, 1 },
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
				{ { "U_JeansPatched21_uniform", "item" }, 1 },
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
				{ { "U_JeansBlack21_uniform", "item" }, 1 }
		};
	};

	class FemaleWetsuits
	{
		items[] = {
				{ { "U_Wetsuit_uniform", "item" }, 1 },
				{ { "U_Wetsuit_White", "item" }, 1 },
				{ { "U_Wetsuit_Blue", "item" }, 1 },
				{ { "U_Wetsuit_Purp", "item" }, 1 },
				{ { "U_Wetsuit_Camo", "item" }, 1 }
		};
	};

	class Vests
	{
		items[] = {
                { { "V_MM_Vest_01", "item" }, 5 },
				{ { "V_1_EPOCH", "item" }, 5 },
				{ { "V_2_EPOCH", "item" }, 5 },
				{ { "V_3_EPOCH", "item" }, 5 },
				{ { "V_4_EPOCH", "item" }, 5 },
				{ { "V_5_EPOCH", "item" }, 5 },
				{ { "V_6_EPOCH", "item" }, 1 },
				{ { "V_7_EPOCH", "item" }, 1 },
				{ { "V_8_EPOCH", "item" }, 1 },
				{ { "V_9_EPOCH", "item" }, 1 },
				{ { "V_10_EPOCH", "item" }, 2 },
				{ { "V_11_EPOCH", "item" }, 2 },
				{ { "V_12_EPOCH", "item" }, 2 },
				{ { "V_13_EPOCH", "item" }, 3 },
				{ { "V_14_EPOCH", "item" }, 3 },
				{ { "V_15_EPOCH", "item" }, 3 },
				{ { "V_16_EPOCH", "item" }, 2 },
				{ { "V_17_EPOCH", "item" }, 3 },
				{ { "V_18_EPOCH", "item" }, 3 },
				{ { "V_19_EPOCH", "item" }, 2 },
				{ { "V_20_EPOCH", "item" }, 2 },
				{ { "V_21_EPOCH", "item" }, 4 },
				{ { "V_22_EPOCH", "item" }, 2 },
				{ { "V_23_EPOCH", "item" }, 2 },
				{ { "V_24_EPOCH", "item" }, 3 },
				{ { "V_25_EPOCH", "item" }, 2 },
				{ { "V_26_EPOCH", "item" }, 2 },
				{ { "V_27_EPOCH", "item" }, 2 },
				{ { "V_28_EPOCH", "item" }, 3 },
				{ { "V_29_EPOCH", "item" }, 3 },
				{ { "V_30_EPOCH", "item" }, 3 },
				{ { "V_31_EPOCH", "item" }, 1 },
				{ { "V_32_EPOCH", "item" }, 1 },
				{ { "V_33_EPOCH", "item" }, 2 },
				{ { "V_34_EPOCH", "item" }, 2 },
				{ { "V_35_EPOCH", "item" }, 2 },
				{ { "V_36_EPOCH", "item" }, 2 },
				{ { "V_37_EPOCH", "item" }, 2 },
				{ { "V_38_EPOCH", "item" }, 2 },
				{ { "V_39_EPOCH", "item" }, 2 },
				{ { "V_40_EPOCH", "item" }, 2 }
		};
	};
	class Headgear
	{
		items[] = {
				{ { "HeadgearArmored", "CfgLootTable" }, 1 },
				{ { "HeadgearNoArmor", "CfgLootTable" }, 9 }
		};
	};

	class HeadgearArmored
	{
		items[] = {
                { { "H_MM_Helmet_01", "item" }, 1 },
				{ { "H_1_EPOCH", "item" }, 1 },
				{ { "H_2_EPOCH", "item" }, 1 },
				{ { "H_3_EPOCH", "item" }, 1 },
				{ { "H_4_EPOCH", "item" }, 1 },
				{ { "H_5_EPOCH", "item" }, 1 },
				{ { "H_6_EPOCH", "item" }, 1 },
				{ { "H_7_EPOCH", "item" }, 1 },
				{ { "H_8_EPOCH", "item" }, 1 },
				{ { "H_9_EPOCH", "item" }, 1 },
				{ { "H_10_EPOCH", "item" }, 1 },
				{ { "H_12_EPOCH", "item" }, 1 },
				{ { "H_13_EPOCH", "item" }, 1 },
				{ { "H_14_EPOCH", "item" }, 1 },
				{ { "H_15_EPOCH", "item" }, 1 },
				{ { "H_16_EPOCH", "item" }, 1 },
				{ { "H_17_EPOCH", "item" }, 1 },
				{ { "H_18_EPOCH", "item" }, 1 },
				{ { "H_19_EPOCH", "item" }, 1 },
				{ { "H_20_EPOCH", "item" }, 1 },
				{ { "H_21_EPOCH", "item" }, 1 },
				{ { "H_22_EPOCH", "item" }, 1 },
				{ { "H_23_EPOCH", "item" }, 1 },
				{ { "H_24_EPOCH", "item" }, 1 },
				{ { "H_25_EPOCH", "item" }, 1 },
				{ { "H_26_EPOCH", "item" }, 1 },
				{ { "H_27_EPOCH", "item" }, 1 },
				{ { "H_29_EPOCH", "item" }, 1 },
				{ { "H_30_EPOCH", "item" }, 1 },
				{ { "H_31_EPOCH", "item" }, 1 },
				{ { "H_32_EPOCH", "item" }, 1 },
				{ { "H_33_EPOCH", "item" }, 1 },
				{ { "H_35_EPOCH", "item" }, 1 },
				{ { "H_36_EPOCH", "item" }, 1 },
				{ { "H_37_EPOCH", "item" }, 1 },
				{ { "H_38_EPOCH", "item" }, 1 },
				{ { "H_93_EPOCH", "item" }, 1 },
				{ { "H_94_EPOCH", "item" }, 1 },
				{ { "H_95_EPOCH", "item" }, 1 },
				{ { "H_96_EPOCH", "item" }, 1 },
				{ { "H_97_EPOCH", "item" }, 1 },
				{ { "H_98_EPOCH", "item" }, 1 },
				{ { "H_99_EPOCH", "item" }, 1 },
				{ { "H_100_EPOCH", "item" }, 1 },
				{ { "H_101_EPOCH", "item" }, 1 },
				{ { "H_102_EPOCH", "item" }, 1 },
				{ { "H_103_EPOCH", "item" }, 1 }
		};
	};

	class HeadgearNoArmor
	{
		items[] = {
                { { "H_MM_Buzzard_Gasmask_01", "item" }, 1 },
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
};
