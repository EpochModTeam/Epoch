/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Epoch Server side loot table configs

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server_settngs/configs/CfgMainTable.h
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

	class HempFiber : Default
	{
		chance = 1;
		lootMin = 1;
		LootMax = 3;
		tables[] = { "Hemp" };
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
