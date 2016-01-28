/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Epoch Server side loot table configs

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server_settngs/configs/loots.h
*/
class CfgMainTable
{
	class Default
	{
		chance = 1;
		lootMin = 1;
		LootMax = 1;
		tables[] = { "Food" };
		antagonists[] = {
				{ "UAV", 30 },
				{ "Cloak", 25 }, // Night = Epoch_Cloak_F, Day = Epoch_Sapper_F
				{ "Sapper", 25 },
				{ "SapperB", 15 },
				{ "PHANTOM", 5 }
		};
	};
	class Tree : Default
	{
		chance = 1;
		lootMin = 3;
		LootMax = 6;
		tables[] = { "Tree" };
	};
	class Bush : Default
	{
		chance = 1;
		lootMin = 1;
		LootMax = 2;
		tables[] = { "Bush" };
	};
	class Trash : Default
	{
		chance = 0.33;
		lootMin = 1;
		LootMax = 6;
		tables[] = {
				{ "Items", 5 },
				{ "Backpack", 5 },
				{ "Pistols", 3 },
				{ "Uniforms", 9 },
				{ "Vests", 7 },
				{ "Headgear", 9 },
				{ "Food", 9 },
				{ "Hand", 10 },
				{ "Equipment", 10 },
				{ "Generic", 15 },
				{ "GenericLarge", 18 }
		};
		antagonists[] = {
				{ "UAV", 30 }, // I_UAV_01_F
				{ "Cloak", 30 }, // Night = Epoch_Cloak_F, Day = Epoch_Sapper_F
				{ "Sapper", 25 }, // Epoch_Sapper_F
				{ "SapperB", 15 }  // Epoch_SapperB_F
		};
	};
	class TrashSmall : Default
	{
		chance = 0.33;
		lootMin = 1;
		LootMax = 4;
		tables[] = {
				{ "Items", 5 },
				{ "Equipment", 11 },
				{ "Pistols", 11 },
				{ "Uniforms", 11 },
				{ "Vests", 11 },
				{ "Headgear", 11 },
				{ "Food", 12 },
				{ "Hand", 11 },
				{ "Generic", 17 }
		};
	};
	class TrashVehicle : Default
	{
		chance = 0.33;
		lootMin = 3;
		LootMax = 6;
		tables[] = {
				{ "Items", 19 },
				{ "Equipment", 16 },
				{ "Uniforms", 18 },
				{ "Vests", 7 },
				{ "Headgear", 7 },
				{ "Hand", 8 },
				{ "Generic", 10 },
				{ "GenericAuto", 15 }
		};
	};
	class TrashFood : Default
	{
		chance = 0.33;
		lootMin = 3;
		LootMax = 6;
		tables[] = { "Food" };
	};

	class PumpkinPatch : Default
	{
		chance = 1;
		lootMin = 1;
		LootMax = 1;
		tables[] = { "Pumpkin" };
	};

	class VehicleBoat : Default
	{
		lootMin = 3;
		LootMax = 6;
		tables[] = {
				{ "Items", 6 },
				{ "Equipment", 6 },
				{ "Pistols", 5 },
				{ "PistolAmmo", 7 },
				{ "Scopes", 5 },
				{ "Muzzles", 5 },
				{ "Uniforms", 6 },
				{ "Vests", 5 },
				{ "Headgear", 5 },
				{ "Food", 7 },
				{ "Generic", 8 },
				{ "GenericAuto", 9 },
				{ "RifleBoat", 5 },
				{ "RifleAmmoBoat", 9 },
				{ "Hand", 5 },
				{ "Grenades", 2 },
				{ "Backpack", 5 }
		};
	};

	class Vehicle : Default
	{
		lootMin = 3;
		LootMax = 6;
		tables[] = {
				{ "Items", 6 },
				{ "Equipment", 6 },
				{ "Pistols", 6 },
				{ "PistolAmmo", 6 },
				{ "Scopes", 4 },
				{ "Muzzles", 4 },
				{ "Uniforms", 6 },
				{ "Vests", 6 },
				{ "Headgear", 6 },
				{ "Food", 4 },
				{ "Generic", 6 },
				{ "GenericAuto", 6 },
				{ "Machinegun", 4 },
				{ "MachinegunAmmo", 4 },
				{ "Rifle", 5 },
				{ "RifleAmmo", 4 },
				{ "SniperRifle", 3 },
				{ "SniperRifleAmmo", 4 },
				{ "Hand", 4 },
				{ "Grenades", 2 },
				{ "Backpack", 4 }
		};
	};

	class Food : Default
	{
		lootMin = 3;
		LootMax = 6;
		tables[] = { "Food" };
	};

	class Tarp_EPOCH : Default
	{
		lootMin = 3;
		LootMax = 6;
		tables[] = { "GenericLarge" };
	};
	class wardrobe_epoch : Default
	{
		lootMin = 3;
		LootMax = 6;
		tables[] = {
				{ "Items", 9 },
				{ "Equipment", 9 },
				{ "Pistols", 4 },
				{ "PistolAmmo", 8 },
				{ "Uniforms", 14 },
				{ "Vests", 12 },
				{ "Headgear", 12 },
				{ "Hand", 6 },
				{ "Generic", 6 },
				{ "GenericBed", 10 },
				{ "Backpack", 10 }
		};
	};
	class locker_epoch : Default
	{
		lootMin = 3;
		LootMax = 6;
		tables[] = {
				{ "Items", 8 },
				{ "Equipment", 8 },
				{ "Pistols", 4 },
				{ "PistolAmmo", 5 },
				{ "Rifle", 1 },
				{ "MachinegunAmmo", 6 },
				{ "RifleAmmo", 6 },
				{ "Grenades", 5 },
				{ "Uniforms", 7 },
				{ "Vests", 6 },
				{ "Headgear", 6 },
				{ "Hand", 9 },
				{ "Generic", 11 },
				{ "GenericBed", 6 },
				{ "Backpack", 7 },
				{ "HighExplosives", 5 }
		};
	};
	class cooker_epoch : Default
	{
		lootMin = 3;
		LootMax = 6;
		tables[] = { "Food" };
	};
	class container_epoch : Default
	{
		lootMin = 3;
		LootMax = 6;
		tables[] = { "Shipwreak" };
		antagonists[] = {
				{ "GreatWhite", 1 }
		};
	};
	class MineralDepositCopper_EPOCH : Default
	{
		lootMin = 5;
		LootMax = 10;
		tables[] = { "Mine" };
	};
	class MineralDepositGold_EPOCH : Default
	{
		lootMin = 5;
		LootMax = 10;
		tables[] = { "Mine" };
	};
	class MineralDepositSilver_EPOCH : Default
	{
		lootMin = 5;
		LootMax = 10;
		tables[] = { "Mine" };
	};
	class Shelf_EPOCH : Default
	{
		lootMin = 3;
		LootMax = 6;
		tables[] = {
				{ "Items", 7 },
				{ "Equipment", 5 },
				{ "Pistols", 6 },
				{ "PistolAmmo", 8 },
				{ "MachinegunAmmo", 5 },
				{ "RifleAmmo", 8 },
				{ "SniperRifleAmmo", 5 },
				{ "Scopes", 4 },
				{ "Muzzles", 5 },
				{ "Uniforms", 4 },
				{ "Vests", 5 },
				{ "Headgear", 5 },
				{ "Rifle", 1 },
				{ "Hand", 4 },
				{ "Explosives", 11 },
				{ "Generic", 10 },
				{ "Food", 7 }
		};
	};
	class Fridge_EPOCH : Default
	{
		lootMin = 3;
		LootMax = 6;
		tables[] = { "Food" };
	};
	class Cabinet_EPOCH : Default
	{
		lootMin = 2;
		LootMax = 4;
		tables[] = { "Medical" };
	};
	class Freezer_EPOCH : Default
	{
		lootMin = 3;
		LootMax = 6;
		tables[] = { "Food" };
	};
	class Pelican_EPOCH : Default
	{
		lootMin = 2;
		LootMax = 4;
		tables[] = {
				{ "Pistols", 12 },
				{ "Scopes", 10 },
				{ "Muzzles", 10 },
				{ "Machinegun", 10 },
				{ "Rifle", 21 },
				{ "SniperRifle", 15 },
				{ "Explosives", 22 }
		};
	};
	class Bed_EPOCH : Default
	{
		lootMin = 3;
		LootMax = 6;
		tables[] = {
				{ "Items", 5 },
				{ "Equipment", 8},
				{ "Pistols", 3 },
				{ "PistolAmmo", 5 },
				{ "Scopes", 5 },
				{ "Muzzles", 5 },
				{ "Uniforms", 6 },
				{ "Vests", 6 },
				{ "Headgear", 8 },
				{ "Food", 9 },
				{ "RifleAmmo", 7 },
				{ "MachinegunAmmo", 3 },
				{ "SniperRifleAmmo", 2 },
				{ "Hand", 5 },
				{ "Generic", 5 },
				{ "GenericBed", 8 },
				{ "Backpack", 8 },
				{ "Explosives", 2 }
		};
	};
	class Bunk_EPOCH : Default
	{
		lootMin = 3;
		LootMax = 6;
		tables[] = {
				{ "Items", 5 },
				{ "Equipment", 6 },
				{ "Pistols", 5 },
				{ "PistolAmmo", 6 },
				{ "Scopes", 5 },
				{ "Muzzles", 5 },
				{ "Uniforms", 5 },
				{ "Vests", 5 },
				{ "Headgear", 5 },
				{ "Food", 8 },
				{ "Rifle", 2 },
				{ "RifleAmmo", 4 },
				{ "Machinegun", 1 },
				{ "MachinegunAmmo", 4 },
				{ "SniperRifle", 1 },
				{ "SniperRifleAmmo", 3 },
				{ "Hand", 6 },
				{ "Generic", 7 },
				{ "GenericBed", 9 },
				{ "Backpack", 6 },
				{ "HighExplosives", 2 }
		};
	};
	class Couch_EPOCH : Default
	{
		lootMin = 3;
		LootMax = 6;
		tables[] = {
				{ "Items", 6 },
				{ "Equipment", 6 },
				{ "Pistols", 5 },
				{ "PistolAmmo", 5 },
				{ "Scopes", 5 },
				{ "Muzzles", 5 },
				{ "Uniforms", 7 },
				{ "Vests", 5 },
				{ "Headgear", 13 },
				{ "Food", 11 },
				{ "RifleAmmo", 8 },
				{ "MachinegunAmmo", 6 },
				{ "Hand", 8 },
				{ "Generic", 10 }
		};
	};
	class Table_EPOCH : Default
	{
		lootMin = 2;
		LootMax = 5;
		tables[] = {
				{ "PistolAmmo", 16 },
				{ "Food", 20 },
				{ "RifleAmmo", 16 },
				{ "MachinegunAmmo", 16 },
				{ "SniperRifleAmmo", 16 },
				{ "Hand", 16 }
		};
	};
	class Chair_EPOCH : Default
	{
		lootMin = 2;
		LootMax = 4;
		tables[] = {
				{ "Items", 7 },
				{ "Equipment", 7 },
				{ "Pistols", 4 },
				{ "PistolAmmo", 10 },
				{ "Scopes", 6 },
				{ "Muzzles", 6 },
				{ "Vests", 6 },
				{ "Headgear", 8 },
				{ "Food", 8 },
				{ "RifleAmmo", 7 },
				{ "SniperRifleAmmo", 6 },
				{ "MachinegunAmmo", 7 },
				{ "Hand", 8 },
				{ "Generic", 10 }
		};
	};
	class ChairRed_EPOCH : Default
	{
		lootMin = 2;
		LootMax = 4;
		tables[] = {
				{ "Items", 7 },
				{ "Equipment", 7 },
				{ "Pistols", 4 },
				{ "PistolAmmo", 10 },
				{ "Scopes", 6 },
				{ "Muzzles", 6 },
				{ "Vests", 6 },
				{ "Headgear", 8 },
				{ "Food", 8 },
				{ "RifleAmmo", 7 },
				{ "SniperRifleAmmo", 6 },
				{ "MachinegunAmmo", 7 },
				{ "Hand", 8 },
				{ "Generic", 10 }
		};
	};
	class ToolRack_EPOCH : Default
	{
		lootMin = 2;
		LootMax = 6;
		tables[] = {
				{ "Items", 7 },
				{ "Equipment", 7 },
				{ "Pistols", 5 },
				{ "PistolAmmo", 9 },
				{ "Scopes", 6 },
				{ "Muzzles", 6 },
				{ "Vests", 6 },
				{ "Headgear", 6 },
				{ "RifleAmmo", 7 },
				{ "SniperRifleAmmo", 3 },
				{ "MachinegunAmmo", 4 },
				{ "Hand", 9 },
				{ "Generic", 10 },
				{ "Tools", 15 }
		};
	};
	class Shoebox_EPOCH : Default
	{
		lootMin = 1;
		LootMax = 3;
		tables[] = {
				{ "Food", 5 },
				{ "Items", 7 },
				{ "Equipment", 9 },
				{ "PistolAmmo", 10 },
				{ "Scopes", 8 },
				{ "Muzzles", 8 },
				{ "Explosives", 11 },
				{ "RifleAmmo", 8 },
				{ "SniperRifleAmmo", 6 },
				{ "MachinegunAmmo", 3 },
				{ "Hand", 10 },
				{ "Generic", 10 },
				{ "Grenades", 5 }
		};
	};
	class Filing_EPOCH : Default
	{
		lootMin = 3;
		LootMax = 6;
		tables[] = {
				{ "Items", 6 },
				{ "Equipment", 6 },
				{ "Pistols", 7 },
				{ "PistolAmmo", 10 },
				{ "Scopes", 5 },
				{ "Muzzles", 5 },
				{ "Uniforms", 10 },
				{ "Vests", 6 },
				{ "Headgear", 5 },
				{ "Food", 9 },
				{ "RifleAmmo", 5 },
				{ "MachinegunAmmo", 3 },
				{ "SniperRifleAmmo", 2 },
				{ "Hand", 10 },
				{ "Generic", 10 },
				{ "Grenades", 2 }
		};
	};
	class Cargo_Container : Default
	{
		lootMin = 10;
		LootMax = 12;
		tables[] = {
				{ "GenericLarge", 60 },
				{ "GenericAuto", 30 },
				{ "Machinegun", 3 },
				{ "Rifle", 5 },
				{ "SniperRifle", 2 }
		};
	};
	class AirDrop_Payout1
	{
		lootMin = 7;
		LootMax = 14;
		tables[] = {
				{ "Equipment", 6 },
				{ "Pistols", 8 },
				{ "PistolAmmo", 10 },
				{ "Scopes", 4 },
				{ "Muzzles", 4 },
				{ "Uniforms", 12 },
				{ "Vests", 5 },
				{ "Headgear", 4 },
				{ "Food", 11 },
				{ "RifleAmmo", 5 },
				{ "MachinegunAmmo", 3 },
				{ "SniperRifleAmmo", 2 },
				{ "Hand", 2 },
				{ "Tools", 8 },
				{ "Generic", 3 },
				{ "GenericLarge", 5 },
				{ "BaseBuilding", 6 },
				{ "Grenades", 2 }
		};
	};
	class Mission_Payout1
	{
		lootMin = 4;
		LootMax = 10;
		tables[] = { "Mission_Payout1" };
	};
	class Sheep_random_EPOCH
	{
		lootMin = 2;
		LootMax = 4;
		tables[] = { "Sheep_random_EPOCH" };
	};
	class Goat_random_EPOCH
	{
		lootMin = 2;
		LootMax = 4;
		tables[] = { "Goat_random_EPOCH" };
	};
	class Cock_random_EPOCH
	{
		lootMin = 1;
		LootMax = 1;
		tables[] = { "Cock_random_EPOCH" };
	};
	class Hen_random_EPOCH
	{
		lootMin = 1;
		LootMax = 1;
		tables[] = { "Hen_random_EPOCH" };
	};
	class Rabbit_EPOCH
	{
		lootMin = 1;
		LootMax = 1;
		tables[] = { "Rabbit_EPOCH" };
	};
	class Epoch_Sapper_F
	{
		lootMin = 5;
		LootMax = 10;
		tables[] = { "Epoch_Sapper_F" };
	};
	class Epoch_SapperB_F
	{
		lootMin = 5;
		LootMax = 10;
		tables[] = { "Epoch_SapperB_F" };
	};
	class Epoch_Cloak_F
	{
		lootMin = 5;
		LootMax = 10;
		tables[] = { "Epoch_Cloak_F" };
	};
	class I_UAV_01_F
	{
		lootMin = 1;
		LootMax = 1;
		tables[] = { "I_UAV_01_F" };
	};
	class Snake_random_EPOCH
	{
		lootMin = 1;
		LootMax = 1;
		tables[] = { "Snake_random_EPOCH" };
	};
	class Snake2_random_EPOCH
	{
		lootMin = 1;
		LootMax = 1;
		tables[] = { "Snake_random_EPOCH" };
	};
	class SeaFood
	{
		lootMin = 1;
		LootMax = 1;
		tables[] = { "SeaFood" };
	};
};


class CfgLootTable
{
	class Tree
	{
		items[] = {
				{ { "WoodLog_EPOCH", "magazine" }, 1 }
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

	class Items
	{
		items[] = {
				{ { "ItemCompass", "item" }, 20 },
				{ { "ItemGPS", "item" }, 10 },
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
				{ { "FAK", "item" }, 20 }
		};
	};
	class Equipment
	{
		items[] = {
				{ { "Rangefinder", "weapon" }, 5 },
				{ { "Binocular", "item" }, 40 },
				{ { "NVG_EPOCH", "item" }, 10 },
				{ { "acc_flashlight", "item" }, 20 },
				{ { "acc_pointer_IR", "item" }, 20 },
				// Marksman DLC
				{ { "Bipods", "CfgLootTable" }, 5 }

		};
	};

	class SniperRifle
	{
		items[] = {
				{ { "SniperRiflem107", "CfgLootTable" }, 8 },

				// Marksman DLC
				{ { "SniperRifleMarkDLC", "CfgLootTable" }, 10 },

				{ { "srifle_LRR_F", "weapon" }, 11 },
				{ { "srifle_GM6_F", "weapon" }, 16 },
				{ { "srifle_DMR_01_F", "weapon" }, 17 },
				{ { "SniperRifleM14", "CfgLootTable" }, 18 },
				{ { "srifle_EBR_F", "weapon" }, 20 }
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
				{ { "10Rnd_127x54_Mag", "magazine" }, 1 }

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
				{ { "VehicleRepair", "magazine" }, 7 },
				{ { "Towelette", "magazine" }, 14 },
				{ { "HotColdPacks", "CfgLootTable" }, 9 },
				{ { "PaintCans", "CfgLootTable" }, 9 },
				{ { "Sodas", "CfgLootTable" }, 8 },
				{ { "CanFood", "CfgLootTable" }, 8 },
				{ { "Primitive", "CfgLootTable" }, 21 },
				{ { "lighter_epoch", "magazine" }, 1 },

				{ { "ItemAluminumBar", "magazine" }, 2 },
				{ { "ItemCopperBar", "magazine" }, 2 },
				{ { "ItemTinBar", "magazine" }, 1 },
		};
	};

	class Primitive
	{
		items[] = {
				{ { "ItemRock", "magazine" }, 1 },
				{ { "ItemRope", "magazine" }, 1 },
				{ { "ItemStick", "magazine" }, 1 },
				{ { "ItemScraps", "magazine" }, 1 }
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
				{ { "ItemLockbox", "magazine" }, 5 },
				{ { "ItemMixOil", "magazine" }, 4 },
				{ { "ItemCoolerE", "magazine" }, 6 },
				{ { "CircuitParts", "magazine" }, 8 },
				{ { "VehicleRepair", "magazine" }, 7 },
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
				{ { "MortarBucket", "magazine" }, 16 },
				{ { "CinderBlocks", "magazine" }, 17 },
				{ { "VehicleRepair", "magazine" }, 16 },
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
				{ { "ItemSafe", "magazine" }, 1 },
				{ { "ItemLockbox", "magazine" }, 4 },
				{ { "jerrycan_epoch", "magazine" }, 5 },
				{ { "CircuitParts", "magazine" }, 6 },
				{ { "MortarBucket", "magazine" }, 9 },
				{ { "VehicleRepair", "magazine" }, 10 },
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
				{ { "hgun_PDW2000_F", "weapon" }, 10 }
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
				{ { "RifleAmmo_30Rnd_65x39_caseless_mag", "CfgLootTable" }, 14 },
				{ { "20Rnd_556x45_UW_mag", "magazine" }, 12 },
				{ { "RifleAmmo_30Rnd_556x45_Stanag", "CfgLootTable" }, 13 },
				{ { "RifleAmmo_30Rnd_45ACP_Mag_SMG_01", "CfgLootTable" }, 16 },
				{ { "30Rnd_9x21_Mag", "magazine" }, 17 },
				{ { "5Rnd_rollins_mag", "magazine" }, 20 }
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
				{ { "MMG_MarkDLC_EPOCH", "CfgLootTable" }, 1 }
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
				{ { "MachinegunAmmo_100Rnd_65x39_caseless_mag", "CfgLootTable" }, 22 },
				{ { "200Rnd_556x45_M249", "magazine" }, 19 },
				{ { "150Rnd_93x64_Mag", "magazine" }, 10 },
				{ { "MachinegunAmmo_30Rnd_65x39_caseless_mag", "CfgLootTable" }, 29 }
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
	/*
	class MachinegunAmmo_150Rnd_762x51_Box
	{
		items[] = {
				{ { "150Rnd_762x51_Box", "magazine" }, 2 },
				{ { "150Rnd_762x51_Box_Tracer", "magazine" }, 1 }
		};
	};
	*/
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
				{ { "Hgun_Pistol_Signal_F", "weapon" }, 4 },
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
	class PistolAmmo
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
	class Scopes
	{
		items[] = {
				{ { "optic_NVS", "item" }, 1 },
				{ { "optic_tws", "item" }, 1 },
				{ { "optic_tws_mg", "item" }, 1 },
				{ { "optic_SOS", "item" }, 2 },
				{ { "optic_LRPS", "item" }, 2 },

				// Marksman DLC
				{ { "ScopeAMSMarkDLC", "CfgLootTable" }, 2 },
				{ { "ScopeKHSMarkDLC", "CfgLootTable" }, 2 },

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
				{ { "bipod_03_F_oli", "item" }, 1 }
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
				{ { "Muzzles_93mmgMarkDLC", "CfgLootTable" }, 1 }
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

	class Shipwreak
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
				{ { "ItemTinBar", "magazine" }, 30 },
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
				{ { "FAK", "item" }, 97 },
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
				{ { "MaleUniforms_FullGhillieMarkDLC", "CfgLootTable" }, 1 }
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
				{ { "U_CamoBrn_uniform", "item" }, 1 },
				{ { "U_CamoBlue_uniform", "item" }, 1 },
				{ { "U_Camo_uniform", "item" }, 1 },
				{ { "U_ghillie1_uniform", "item" }, 1 },
				{ { "U_ghillie2_uniform", "item" }, 1 },
				{ { "U_ghillie3_uniform", "item" }, 1 }
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
				//{ { "wolf_mask_epoch", "item" }, 1 },
				//{ { "pkin_mask_epoch", "item" }, 1 },
				//{ { "clown_mask_epoch", "item" }, 1 }

		};
	};
};
