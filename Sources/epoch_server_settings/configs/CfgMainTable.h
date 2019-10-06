/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Epoch Server side loot table configs

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server_settngs/configs/CfgMainTable.h
*/
class CfgMainTable
{
	class Default	// Will be used if no LootTable is found
	{
		chance = 1;
		lootMin = 2;
		LootMax = 3;
		tables[] = {
				{ "Food", 1 },
				{ "Drink", 1 },
				{ "Primitive", 1 }
		};
	};
/*
	class Example	// All Available Loot Classes
	{
		chance = 1;
		lootMin = 3;
		LootMax = 6;
		tables[] = {
				{ "Scopes", 1 },
				{ "Bipods", 1 },
				{ "Muzzles", 1 },
				{ "WpnFlashLights", 1 },
				{ "Pistols", 1 },
				{ "PistolAmmo", 1 },
				{ "Rifle", 1 },
				{ "RifleAmmo", 1 },
				{ "SniperRifle", 1 },
				{ "SniperRifleAmmo", 1 },
				{ "Machinegun", 1 },
				{ "MachinegunAmmo", 1 },
				{ "Uniforms_Male_Civ", 1 },
				{ "Uniforms_Male_Mil", 1 },
				{ "Uniforms_Female_Civ", 1 },
				{ "Uniforms_Female_Mil", 1 },
				{ "Vests_Low", 1 },
				{ "Vests_High", 1 },
				{ "BackPacks_Low", 1 },
				{ "BackPacks_High", 1 },
				{ "HeadgearNoArmor", 1 },
				{ "HeadgearArmored", 1 },
				{ "Primitive", 1 },
				{ "BuildingItems", 5 },
				{ "BuildingKits", 1 },
				{ "Storages", 1 },
				{ "Equipment", 1 },
				{ "Tools", 1 },
				{ "Repairs", 1 },
				{ "VehicleDocs", 1 },
				{ "Seeds", 1 },
				{ "Drink", 1 },
				{ "Food", 1 },
				{ "Medical", 1 },
				{ "PaintCans", 1 },
				{ "MetalBars", 1 },
				{ "Gems", 1 },
				{ "Ore", 1 },
				{ "Throw", 1 },
				{ "ThrowExplosive", 1 },
				{ "HighExplosives", 1 },
				{ "ShellFlares", 1 },
				{ "ShellSmokes", 1 },
				{ "ShellExplosives", 1 }
		};
	};

*/
// ########################################################################### Main Tables ###########################################################################
	class loots_civ : Default
	{
		chance = 1;
		lootMin = 1;
		LootMax = 2;
		tables[] = {
				{ "Scopes", 4 },
				{ "Bipods", 4 },
				{ "Muzzles", 4 },
				{ "WpnFlashLights", 4 },
				{ "Pistols", 5 },
				{ "PistolAmmo", 10 },
				{ "Rifle", 1 },
				{ "RifleAmmo", 3 },
				{ "SniperRifle", 0 },
				{ "SniperRifleAmmo", 1 },
				{ "Machinegun", 0 },
				{ "MachinegunAmmo", 1 },
				{ "Uniforms_Male_Civ", 5 },
				{ "Uniforms_Male_Mil", 1 },
				{ "Uniforms_Female_Civ", 5 },
				{ "Uniforms_Female_Mil", 1 },
				{ "Vests_Low", 5 },
				{ "Vests_High", 1 },
				{ "BackPacks_Low", 5 },
				{ "BackPacks_High", 1 },
				{ "HeadgearNoArmor", 10 },
				{ "HeadgearArmored", 1 },
				{ "Primitive", 20 },
				{ "BuildingItems", 10 },
				{ "BuildingKits", 1 },
				{ "Storages", 1 },
				{ "Equipment", 6 },
				{ "Tools", 6 },
				{ "Repairs", 10 },
				{ "VehicleDocs", 2 },
				{ "Seeds", 5 },
				{ "Drink", 20 },
				{ "Food", 20 },
				{ "Medical", 5 },
				{ "PaintCans", 10 },
				{ "MetalBars", 6 },
				{ "Gems", 1 },
				{ "Ore", 2 },
				{ "Throw", 5 },
				{ "ThrowExplosive", 3 },
				{ "HighExplosives", 1 },
				{ "ShellFlares", 3 },
				{ "ShellSmokes", 3 },
				{ "ShellExplosives", 1 }
		};
	};
	class loots_mil : Default
	{
		chance = 1;
		lootMin = 1;
		LootMax = 2;
		tables[] = {
				{ "Scopes", 10 },
				{ "Bipods", 10 },
				{ "Muzzles", 10 },
				{ "WpnFlashLights", 10 },
				{ "Pistols", 4 },
				{ "PistolAmmo", 6 },
				{ "Rifle", 6 },
				{ "RifleAmmo", 9 },
				{ "SniperRifle", 3 },
				{ "SniperRifleAmmo", 5 },
				{ "Machinegun", 2 },
				{ "MachinegunAmmo", 3 },
				{ "Uniforms_Male_Civ", 1 },
				{ "Uniforms_Male_Mil", 3 },
				{ "Uniforms_Female_Civ", 1 },
				{ "Uniforms_Female_Mil", 3 },
				{ "Vests_Low", 1 },
				{ "Vests_High", 5 },
				{ "BackPacks_Low", 1 },
				{ "BackPacks_High", 5 },
				{ "HeadgearNoArmor", 1 },
				{ "HeadgearArmored", 8 },
				{ "Primitive", 10 },
				{ "BuildingItems", 10 },
				{ "BuildingKits", 2 },
				{ "Storages", 1 },
				{ "Equipment", 10 },
				{ "Tools", 10 },
				{ "Repairs", 5 },
				{ "VehicleDocs", 4 },
				{ "Seeds", 1 },
				{ "Drink", 10 },
				{ "Food", 10 },
				{ "Medical", 8 },
				{ "PaintCans", 5 },
				{ "MetalBars", 4 },
				{ "Gems", 1 },
				{ "Ore", 2 },
				{ "Throw", 21},
				{ "ThrowExplosive", 6 },
				{ "HighExplosives", 2 },
				{ "ShellFlares", 3 },
				{ "ShellSmokes", 3 },
				{ "ShellExplosives", 3 }
		};
	};
	class loots_church : Default
	{
		chance = 1;
		lootMin = 1;
		LootMax = 2;
		tables[] = {
				{ "Pistols", 2 },
				{ "PistolAmmo", 2 },
				{ "Rifle", 6 },
				{ "RifleAmmo", 6 },
				{ "SniperRifle", 9 },
				{ "SniperRifleAmmo", 6 },
				{ "Machinegun", 9 },
				{ "MachinegunAmmo", 9 },
				{ "BackPacks_High", 5 },
				{ "HeadgearArmored", 3 },
				{ "Equipment", 2 },
				{ "Tools", 2 },
				{ "Medical", 2 },
				{ "ThrowExplosive", 7 },
				{ "HighExplosives", 3 }
		};
	};
	class loots_medical : Default
	{
		chance = 1;
		lootMin = 1;
		LootMax = 2;
		tables[] = {
				{ "Uniforms_Male_Civ", 2 },
				{ "Uniforms_Female_Civ", 2 },
				{ "BackPacks_Low", 2 },
				{ "BackPacks_High", 1 },
				{ "HeadgearNoArmor", 5 },
				{ "HeadgearArmored", 1 },
				{ "Primitive", 3 },
				{ "Equipment", 2 },
				{ "Tools", 2 },
				{ "Seeds", 2 },
				{ "Drink", 7 },
				{ "Food", 7 },
				{ "Medical", 20 },
				{ "MetalBars", 1 },
				{ "Gems", 1 },
				{ "Ore", 1 }
		};
	};
	class loots_workshop : Default
	{
		chance = 1;
		lootMin = 1;
		LootMax = 2;
		tables[] = {
				{ "Scopes", 3 },
				{ "Bipods", 3 },
				{ "Muzzles", 3 },
				{ "WpnFlashLights", 3 },
				{ "Pistols", 3 },
				{ "PistolAmmo", 5 },
				{ "Rifle", 1 },
				{ "RifleAmmo", 3 },
				{ "SniperRifle", 0 },
				{ "SniperRifleAmmo", 1 },
				{ "Machinegun", 0 },
				{ "MachinegunAmmo", 1 },
				{ "Uniforms_Male_Civ", 4 },
				{ "Uniforms_Male_Mil", 1 },
				{ "Uniforms_Female_Civ", 4 },
				{ "Uniforms_Female_Mil", 1 },
				{ "Vests_Low", 4 },
				{ "Vests_High", 1 },
				{ "BackPacks_Low", 5 },
				{ "BackPacks_High", 1 },
				{ "HeadgearNoArmor", 8 },
				{ "HeadgearArmored", 1 },
				{ "Primitive", 10 },
				{ "BuildingItems", 10 },
				{ "BuildingKits", 5 },
				{ "Storages", 2 },
				{ "Equipment", 6 },
				{ "Tools", 8 },
				{ "Repairs", 20 },
				{ "VehicleDocs", 5 },
				{ "Seeds", 2 },
				{ "Drink", 10 },
				{ "Food", 10 },
				{ "Medical", 6 },
				{ "PaintCans", 10 },
				{ "MetalBars", 4 },
				{ "Gems", 1 },
				{ "Ore", 2 },
				{ "Throw", 5 },
				{ "ThrowExplosive", 2 },
				{ "HighExplosives", 1 },
				{ "ShellFlares", 2 },
				{ "ShellSmokes", 2 },
				{ "ShellExplosives", 1 }
		};
	};
	class loots_industrial : Default
	{
		chance = 1;
		lootMin = 1;
		LootMax = 2;
		tables[] = {
				{ "Scopes", 1 },
				{ "Bipods", 1 },
				{ "Muzzles", 1 },
				{ "WpnFlashLights", 1 },
				{ "Pistols", 1 },
				{ "PistolAmmo", 2 },
				{ "Rifle", 1 },
				{ "RifleAmmo", 2 },
				{ "SniperRifle", 0 },
				{ "SniperRifleAmmo", 1 },
				{ "Machinegun", 0 },
				{ "MachinegunAmmo", 1 },
				{ "Uniforms_Male_Civ", 2 },
				{ "Uniforms_Male_Mil", 1 },
				{ "Uniforms_Female_Civ", 2 },
				{ "Uniforms_Female_Mil", 1 },
				{ "Vests_Low", 2 },
				{ "Vests_High", 1 },
				{ "BackPacks_Low", 3 },
				{ "BackPacks_High", 1 },
				{ "HeadgearNoArmor", 3 },
				{ "HeadgearArmored", 1 },
				{ "Primitive", 5 },
				{ "BuildingItems", 20 },
				{ "BuildingKits", 10 },
				{ "Storages", 3 },
				{ "Equipment", 2 },
				{ "Tools", 5 },
				{ "Repairs", 10 },
				{ "VehicleDocs", 3 },
				{ "Seeds", 1 },
				{ "Drink", 7 },
				{ "Food", 7 },
				{ "Medical", 3 },
				{ "PaintCans", 5 },
				{ "MetalBars", 3 },
				{ "Gems", 1 },
				{ "Ore", 1 },
				{ "Throw", 2 },
				{ "ThrowExplosive", 2 },
				{ "HighExplosives", 1 },
				{ "ShellFlares", 1 },
				{ "ShellSmokes", 1 },
				{ "ShellExplosives", 1 }
		};
	};
	class loots_market : Default
	{
		chance = 1;
		lootMin = 1;
		LootMax = 2;
		tables[] = {
				{ "Scopes", 3 },
				{ "Bipods", 3 },
				{ "Muzzles", 3 },
				{ "WpnFlashLights", 3 },
				{ "Pistols", 3 },
				{ "PistolAmmo", 5 },
				{ "Rifle", 1 },
				{ "RifleAmmo", 3 },
				{ "SniperRifle", 0 },
				{ "SniperRifleAmmo", 1 },
				{ "Machinegun", 0 },
				{ "MachinegunAmmo", 1 },
				{ "Uniforms_Male_Civ", 2 },
				{ "Uniforms_Male_Mil", 1 },
				{ "Uniforms_Female_Civ", 2 },
				{ "Uniforms_Female_Mil", 1 },
				{ "Vests_Low", 3 },
				{ "Vests_High", 1 },
				{ "BackPacks_Low", 3 },
				{ "BackPacks_High", 1 },
				{ "HeadgearNoArmor", 5 },
				{ "HeadgearArmored", 1 },
				{ "Primitive", 15 },
				{ "BuildingItems", 6 },
				{ "BuildingKits", 2 },
				{ "Storages", 1 },
				{ "Equipment", 5 },
				{ "Tools", 3 },
				{ "Repairs", 8 },
				{ "VehicleDocs", 1 },
				{ "Seeds", 3 },
				{ "Drink", 15 },
				{ "Food", 15 },
				{ "Medical", 6 },
				{ "PaintCans", 2 },
				{ "MetalBars", 2 },
				{ "Gems", 1 },
				{ "Ore", 2 },
				{ "Throw", 5 },
				{ "ThrowExplosive", 3 },
				{ "HighExplosives", 1 },
				{ "ShellFlares", 2 },
				{ "ShellSmokes", 2 },
				{ "ShellExplosives", 1 }
		};
	};
	class loots_construction : Default
	{
		chance = 1;
		lootMin = 1;
		LootMax = 2;
		tables[] = {
				{ "Scopes", 1 },
				{ "Bipods", 1 },
				{ "Muzzles", 1 },
				{ "WpnFlashLights", 1 },
				{ "Pistols", 1 },
				{ "PistolAmmo", 2 },
				{ "Rifle", 1 },
				{ "RifleAmmo", 2 },
				{ "SniperRifle", 0 },
				{ "SniperRifleAmmo", 1 },
				{ "Machinegun", 0 },
				{ "MachinegunAmmo", 1 },
				{ "Uniforms_Male_Civ", 1 },
				{ "Uniforms_Male_Mil", 1 },
				{ "Uniforms_Female_Civ", 1 },
				{ "Uniforms_Female_Mil", 1 },
				{ "Vests_Low", 1 },
				{ "Vests_High", 1 },
				{ "BackPacks_Low", 3 },
				{ "BackPacks_High", 2 },
				{ "HeadgearNoArmor", 1 },
				{ "HeadgearArmored", 1 },
				{ "Primitive", 5 },
				{ "BuildingItems", 35 },
				{ "BuildingKits", 5 },
				{ "Storages", 2 },
				{ "Equipment", 2 },
				{ "Tools", 2 },
				{ "Repairs", 5 },
				{ "VehicleDocs", 2 },
				{ "Seeds", 1 },
				{ "Drink", 3 },
				{ "Food", 3 },
				{ "Medical", 2 },
				{ "PaintCans", 3 },
				{ "MetalBars", 1 },
				{ "Gems", 1 },
				{ "Ore", 1 },
				{ "Throw", 2 },
				{ "ThrowExplosive", 2 },
				{ "HighExplosives", 1 },
				{ "ShellFlares", 1 },
				{ "ShellSmokes", 1 },
				{ "ShellExplosives", 1 }
		};
	};
	
	
// ########################################################################### Vehicles ###########################################################################
	class VehicleBoat : Default
	{
		lootMin = 2;
		LootMax = 4;
		tables[] = {
				{ "Scopes", 10 },
				{ "Bipods", 10 },
				{ "Muzzles", 10 },
				{ "WpnFlashLights", 10 },
				{ "Pistols", 20 },
				{ "PistolAmmo", 25 },
				{ "Rifle", 15 },
				{ "RifleAmmo", 20 },
				{ "SniperRifle", 10 },
				{ "SniperRifleAmmo", 15 },
				{ "Machinegun", 5 },
				{ "MachinegunAmmo", 10 },
				{ "Uniforms_Male_Civ", 10 },
				{ "Uniforms_Male_Mil", 10 },
				{ "Uniforms_Female_Civ", 10 },
				{ "Uniforms_Female_Mil", 10 },
				{ "Vests_Low", 10 },
				{ "Vests_High", 5 },
				{ "BackPacks_Low", 10 },
				{ "BackPacks_High", 5 },
				{ "HeadgearNoArmor", 10 },
				{ "HeadgearArmored", 10 },
				{ "Primitive", 10 },
				{ "BuildingItems", 10 },
				{ "BuildingKits", 5 },
				{ "Storages", 3 },
				{ "Equipment", 10 },
				{ "Tools", 10 },
				{ "Repairs", 15 },
				{ "VehicleDocs", 10 },
				{ "Seeds", 5 },
				{ "Drink", 10 },
				{ "Food", 10 },
				{ "Medical", 10 },
				{ "Throw", 10 },
				{ "ThrowExplosive", 5 },
				{ "HighExplosives", 3 },
				{ "ShellFlares", 2 },
				{ "ShellSmokes", 2 },
				{ "ShellExplosives", 2 }
		};
	};
	class Vehicle : VehicleBoat	{};
	
// ########################################################################### World Objects ###########################################################################
	class Trash : Default
	{
		chance = 0.33;
		lootMin = 1;
		LootMax = 4;
		tables[] = {
				{ "Scopes", 4 },
				{ "Bipods", 4 },
				{ "Muzzles", 4 },
				{ "WpnFlashLights", 4 },
				{ "Pistols", 6 },
				{ "PistolAmmo", 10 },
				{ "Uniforms_Male_Civ", 4 },
				{ "Uniforms_Male_Mil", 2 },
				{ "Uniforms_Female_Civ", 4 },
				{ "Uniforms_Female_Mil", 2 },
				{ "Vests_Low", 4 },
				{ "Vests_High", 2 },
				{ "BackPacks_Low", 4 },
				{ "BackPacks_High", 2 },
				{ "HeadgearNoArmor", 10 },
				{ "HeadgearArmored", 2 },
				{ "Primitive", 20 },
				{ "BuildingItems", 2 },
				{ "Equipment", 2 },
				{ "Tools", 2 },
				{ "Repairs", 6 },
				{ "VehicleDocs", 2 },
				{ "Seeds", 4 },
				{ "Drink", 20 },
				{ "Food", 20 },
				{ "Medical", 4 },
				{ "PaintCans", 8 },
				{ "Throw", 10 },
				{ "ThrowExplosive", 2 }
		};
	};
	class TrashSmall : Trash
	{
		lootMin = 1;
		LootMax = 2;
	};
	class Tree : Default
	{
		chance = 1;
		lootMin = 2;
		LootMax = 4;
		tables[] = { "Tree" };
	};
	class Rock : Default
	{
		chance = 1;
		lootMin = 1;
		LootMax = 3;
		tables[] = { "Rock" };
	};
	class Ore : Default
	{
		chance = 1;
		lootMin = 1;
		LootMax = 3;
		tables[] = {
				{ "Gems", 15 },
				{ "Ore", 85 }
		};
	};
	class Cinder : Default
	{
		chance = 1;
		lootMin = 1;
		LootMax = 3;
		tables[] = { "Cinder" };
	};
	class Wreck : Default
	{
		chance = 1;
		lootMin = 1;
		LootMax = 3;
		tables[] = { "Wreck" };
	};
	class Bush : Default
	{
		chance = 1;
		lootMin = 1;
		LootMax = 3;
		tables[] = { "Bush" };
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
		LootMax = 2;
		tables[] = { "Hemp" };
	};

// ########################################################################### Furnitures ###########################################################################
	class Tarp_EPOCH : Default
	{
		lootMin = 2;
		LootMax = 4;
		tables[] = {
				{ "BackPacks_Low", 5 },
				{ "BackPacks_High", 1 },
				{ "HeadgearNoArmor", 10 },
				{ "HeadgearArmored", 2 },
				{ "Primitive", 20 },
				{ "BuildingItems", 20 },
				{ "BuildingKits", 6 },
				{ "Storages", 2},
				{ "Equipment", 6 },
				{ "Tools", 6 },
				{ "Repairs", 15 },
				{ "VehicleDocs", 1 },
				{ "Seeds", 5 },
				{ "Drink", 3 },
				{ "Food", 3 },
				{ "Medical", 2 },
				{ "PaintCans", 10 },
				{ "MetalBars", 1 }
		};
	};
	class wardrobe_epoch : Default
	{
		lootMin = 2;
		LootMax = 4;
		tables[] = {
				{ "Pistols", 10 },
				{ "PistolAmmo", 15 },
				{ "Rifle", 5 },
				{ "RifleAmmo", 10 },
				{ "SniperRifle", 2 },
				{ "SniperRifleAmmo", 5 },
				{ "Machinegun", 1 },
				{ "MachinegunAmmo", 3 },
				{ "Uniforms_Male_Civ", 10 },
				{ "Uniforms_Male_Mil", 1 },
				{ "Uniforms_Female_Civ", 10 },
				{ "Uniforms_Female_Mil", 1 },
				{ "Vests_Low", 10 },
				{ "Vests_High", 1 },
				{ "BackPacks_Low", 8 },
				{ "BackPacks_High", 2 },
				{ "HeadgearNoArmor", 15 },
				{ "HeadgearArmored", 3 },
				{ "Equipment", 5 },
				{ "Tools", 5 },
				{ "MetalBars", 3 },
				{ "Gems", 1 },
				{ "Ore", 2 },
				{ "Throw", 3 }
		};
	};
	class locker_epoch : Default
	{
		lootMin = 2;
		LootMax = 4;
		tables[] = {
				{ "Scopes", 10 },
				{ "Bipods", 10 },
				{ "Muzzles", 10 },
				{ "WpnFlashLights", 10 },
				{ "Pistols", 15 },
				{ "PistolAmmo", 20 },
				{ "Rifle", 10 },
				{ "RifleAmmo", 15 },
				{ "SniperRifle", 5 },
				{ "SniperRifleAmmo", 10 },
				{ "Machinegun", 2 },
				{ "MachinegunAmmo", 5 },
				{ "Uniforms_Male_Civ", 5 },
				{ "Uniforms_Male_Mil", 5 },
				{ "Uniforms_Female_Civ", 5 },
				{ "Uniforms_Female_Mil", 5 },
				{ "Vests_Low", 10 },
				{ "Vests_High", 10 },
				{ "BackPacks_Low", 10 },
				{ "BackPacks_High", 5 },
				{ "HeadgearNoArmor", 15 },
				{ "HeadgearArmored", 10 },
				{ "Primitive", 15 },
				{ "Equipment", 10 },
				{ "Tools", 10 },
				{ "Repairs", 5 },
				{ "VehicleDocs", 2 },
				{ "Throw", 3 },
				{ "ThrowExplosive", 3 },
				{ "HighExplosives", 1 },
				{ "ShellFlares", 1 },
				{ "ShellSmokes", 1 },
				{ "ShellExplosives", 1 }
		};
	};
	class cooker_epoch : Default
	{
		lootMin = 2;
		LootMax = 4;
		tables[] = {
				{ "Drink", 1 },
				{ "Food", 1 }
		};
	};
	class Shelf_EPOCH : Default
	{
		lootMin = 2;
		LootMax = 4;
		tables[] = {
				{ "Equipment", 10 },
				{ "Pistols", 6 },
				{ "PistolAmmo", 8 },
				{ "MachinegunAmmo", 5 },
				{ "RifleAmmo", 8 },
				{ "SniperRifleAmmo", 5 },
				{ "Scopes", 4 },
				{ "Muzzles", 5 },
				{ "Uniforms_Male_Civ", 2 },
				{ "Uniforms_Male_Mil", 1 },
				{ "Uniforms_Female_Civ", 2 },
				{ "Uniforms_Female_Mil", 1 },
				{ "Vests_Low", 3 },
				{ "Vests_High", 2 },
				{ "HeadgearNoArmor", 3 },
				{ "HeadgearArmored", 2 },
				{ "Rifle", 3 },
				{ "Throw", 5 },
				{ "ThrowExplosive", 3 },
				{ "HighExplosives", 2 },
				{ "BuildingItems", 7 },
				{ "Drink", 3 },
				{ "Food", 3 },
				{ "BackPacks_Low", 1 },
				{ "BackPacks_High", 1 }
		};
	};
	class Fridge_EPOCH : Default
	{
		lootMin = 2;
		LootMax = 4;
		tables[] = {
				{ "Drink", 1 },
				{ "Food", 1 }
		};
	};
	class Cabinet_EPOCH : Default
	{
		lootMin = 1;
		LootMax = 3;
		tables[] = {
				{ "Medical", 1 }
		};
	};
	class Freezer_EPOCH : Default
	{
		lootMin = 2;
		LootMax = 4;
		tables[] = {
				{ "Drink", 1 },
				{ "Food", 1 }
		};
	};
	class Pelican_EPOCH : Default
	{
		lootMin = 1;
		LootMax = 3;
		tables[] = {
				{ "Pistols", 10 },
				{ "Scopes", 10 },
				{ "Muzzles", 10 },
				{ "Machinegun", 10 },
				{ "Rifle", 21 },
				{ "SniperRifle", 15 },
				{ "ThrowExplosive", 13 },
				{ "HighExplosives", 13 }
		};
	};
	class Bed_EPOCH : Default
	{
		lootMin = 2;
		LootMax = 4;
		tables[] = {
				{ "Rifle", 3 },
				{ "SniperRifle", 2 },
				{ "Equipment", 10},
				{ "Pistols", 4 },
				{ "PistolAmmo", 5 },
				{ "Scopes", 3 },
				{ "Muzzles", 3 },
				{ "Uniforms_Male_Civ", 2 },
				{ "Uniforms_Male_Mil", 1 },
				{ "Uniforms_Female_Civ", 2 },
				{ "Uniforms_Female_Mil", 1 },
				{ "Vests_Low", 3 },
				{ "Vests_High", 2 },
				{ "BackPacks_Low", 2 },
				{ "HeadgearNoArmor", 4 },
				{ "HeadgearArmored", 2 },
				{ "Drink", 4 },
				{ "Food", 4 },
				{ "RifleAmmo", 7 },
				{ "MachinegunAmmo", 3 },
				{ "SniperRifleAmmo", 2 },
				{ "Throw", 4 },
				{ "ThrowExplosive", 1 },
				{ "BuildingItems", 7 },
				{ "Repairs", 3 },
				{ "BackPacks_Low", 4 },
				{ "BackPacks_High", 2 }
		};
	};
	class Bunk_EPOCH : Default
	{
		lootMin = 2;
		LootMax = 4;
		tables[] = {
				{ "Equipment", 10 },
				{ "Pistols", 5 },
				{ "PistolAmmo", 6 },
				{ "Scopes", 4 },
				{ "Muzzles", 3 },
				{ "Uniforms_Male_Civ", 2 },
				{ "Uniforms_Male_Mil", 1 },
				{ "Uniforms_Female_Civ", 2 },
				{ "Uniforms_Female_Mil", 1 },
				{ "Vests_Low", 2 },
				{ "Vests_High", 2 },
				{ "BackPacks_Low", 2 },
				{ "HeadgearNoArmor", 3 },
				{ "HeadgearArmored", 3 },
				{ "Drink", 3 },
				{ "Food", 3 },
				{ "Medical", 1 },
				{ "Rifle", 3 },
				{ "RifleAmmo", 4 },
				{ "Machinegun", 1 },
				{ "MachinegunAmmo", 4 },
				{ "SniperRifle", 1 },
				{ "SniperRifleAmmo", 3 },
				{ "Throw", 4 },
				{ "ThrowExplosive", 1 },
				{ "BuildingItems", 7 },
				{ "Repairs", 3 },
				{ "BackPacks_Low", 4 },
				{ "BackPacks_High", 2 },
				{ "HighExplosives", 2 }
		};
	};
	class Couch_EPOCH : Default
	{
		lootMin = 2;
		LootMax = 4;
		tables[] = {
				{ "Rifle", 3 },
				{ "SniperRifle", 1 },
				{ "Equipment", 10 },
				{ "Pistols", 5 },
				{ "PistolAmmo", 5 },
				{ "Scopes", 5 },
				{ "Muzzles", 5 },
				{ "Uniforms_Male_Civ", 3 },
				{ "Uniforms_Male_Mil", 1 },
				{ "Uniforms_Female_Civ", 3 },
				{ "Uniforms_Female_Mil", 1 },
				{ "Vests_Low", 4 },
				{ "Vests_High", 1 },
				{ "BackPacks_Low", 2 },
				{ "HeadgearNoArmor", 4 },
				{ "HeadgearArmored", 2 },
				{ "Drink", 5 },
				{ "Food", 5 },
				{ "Medical", 1 },
				{ "RifleAmmo", 8 },
				{ "MachinegunAmmo", 6 },
				{ "Throw", 6 },
				{ "BuildingItems", 6 }
		};
	};
	class Table_EPOCH : Default
	{
		lootMin = 2;
		LootMax = 4;
		tables[] = {
				{ "PistolAmmo", 16 },
				{ "Drink", 9 },
				{ "Food", 9 },
				{ "Medical", 2 },
				{ "RifleAmmo", 16 },
				{ "MachinegunAmmo", 16 },
				{ "SniperRifleAmmo", 16 },
				{ "Throw", 15 },
				{ "ThrowExplosive", 1 }
		};
	};
	class Chair_EPOCH : Default
	{
		lootMin = 2;
		LootMax = 4;
		tables[] = {
				{ "Equipment", 12 },
				{ "Pistols", 4 },
				{ "PistolAmmo", 10 },
				{ "Scopes", 6 },
				{ "Muzzles", 6 },
				{ "Vests_Low", 3 },
				{ "Vests_High", 1 },
				{ "BackPacks_Low", 2 },
				{ "HeadgearNoArmor", 4 },
				{ "HeadgearArmored", 2 },
				{ "Drink", 3 },
				{ "Food", 3 },
				{ "Medical", 1 },
				{ "RifleAmmo", 7 },
				{ "SniperRifleAmmo", 6 },
				{ "MachinegunAmmo", 7 },
				{ "Throw", 8 },
				{ "BuildingItems", 3 },
				{ "Primitive", 5 },
				{ "Tools", 2 }
		};
	};
	class ChairRed_EPOCH : Chair_EPOCH {};
	class ToolRack_EPOCH : Default
	{
		lootMin = 2;
		LootMax = 4;
		tables[] = {
				{ "Tools", 25 },
				{ "Equipment", 20 },
				{ "Pistols", 6 },
				{ "Rifle", 4 },
				{ "SniperRifle", 2 },
				{ "VehicleDocs", 2 },
				{ "Scopes", 5 },
				{ "Bipods", 5 },
				{ "Muzzles", 5 }
		};
	};
	class Shoebox_EPOCH : Default
	{
		lootMin = 1;
		LootMax = 2;
		tables[] = {
				{ "Drink", 3 },
				{ "Food", 3 },
				{ "Medical", 2 },
				{ "Equipment", 15 },
				{ "PistolAmmo", 10 },
				{ "Scopes", 8 },
				{ "Muzzles", 8 },
				{ "ThrowExplosive", 11 },
				{ "RifleAmmo", 8 },
				{ "SniperRifleAmmo", 6 },
				{ "MachinegunAmmo", 3 },
				{ "Throw", 10 }
		};
	};
	class Filing_EPOCH : Default
	{
		lootMin = 2;
		LootMax = 4;
		tables[] = {
				{ "Equipment", 11 },
				{ "Pistols", 7 },
				{ "PistolAmmo", 10 },
				{ "Scopes", 5 },
				{ "Muzzles", 5 },
				{ "Uniforms_Male_Civ", 1 },
				{ "Uniforms_Male_Mil", 4 },
				{ "Uniforms_Female_Civ", 1 },
				{ "Uniforms_Female_Mil", 4 },
				{ "Vests_Low", 3 },
				{ "Vests_High", 3 },
				{ "BackPacks_Low", 1 },
				{ "HeadgearNoArmor", 3 },
				{ "HeadgearArmored", 3 },
				{ "Drink", 5 },
				{ "Food", 5 },
				{ "Medical", 2 },
				{ "RifleAmmo", 5 },
				{ "MachinegunAmmo", 3 },
				{ "SniperRifleAmmo", 2 },
				{ "Throw", 10 },
				{ "Generic", 10 },
				{ "ThrowExplosive", 2 }
		};
	};
	class Toilet_EPOCH : Default
	{
		lootMin = 1;
		LootMax = 3;
		tables[] = {
				{ "Primitive", 4 },
				{ "Drink", 3 },
				{ "Food", 3 },
				{ "Medical", 1 }
		};
	};
	
// ########################################################################### Epoch Map Missions ###########################################################################
	class container_epoch : Default
	{
		lootMin = 2;
		LootMax = 4;
		tables[] = {
				{ "Gems", 5 },
				{ "MetalBars", 26 },
				{ "Ore", 20 }
		};
	};
	class container_helicrash_epoch : Default
	{
		lootMin = 5;
		LootMax = 10;
		tables[] = {
				{ "Scopes", 10 },
				{ "Bipods", 10 },
				{ "Muzzles", 10 },
				{ "WpnFlashLights", 10 },
				{ "Pistols", 10 },
				{ "PistolAmmo", 10 },
				{ "Rifle", 8 },
				{ "RifleAmmo", 10 },
				{ "SniperRifle", 5 },
				{ "SniperRifleAmmo", 8 },
				{ "Machinegun", 5 },
				{ "MachinegunAmmo", 8 },
				{ "Uniforms_Male_Civ", 1 },
				{ "Uniforms_Male_Mil", 5 },
				{ "Uniforms_Female_Civ", 1 },
				{ "Uniforms_Female_Mil", 5 },
				{ "Vests_Low", 1 },
				{ "Vests_High", 5 },
				{ "BackPacks_Low", 1 },
				{ "BackPacks_High", 5 },
				{ "HeadgearNoArmor", 1 },
				{ "HeadgearArmored", 5 },
				{ "Primitive", 5 },
				{ "BuildingItems", 5 },
				{ "BuildingKits", 5 },
				{ "Storages", 3 },
				{ "Equipment", 5 },
				{ "Tools", 5 },
				{ "Repairs", 5 },
				{ "VehicleDocs", 2 },
				{ "Seeds", 1 },
				{ "Drink", 3 },
				{ "Food", 3 },
				{ "Medical", 3 },
				{ "PaintCans", 1 },
				{ "MetalBars", 2 },
				{ "Gems", 2 },
				{ "Ore", 2 },
				{ "Throw", 1 },
				{ "ThrowExplosive", 3 },
				{ "HighExplosives", 2 },
				{ "ShellFlares", 1 },
				{ "ShellSmokes", 1 },
				{ "ShellExplosives", 1 }
		};
	};
	class HeliCrash : container_helicrash_epoch
	{
		lootMin = 10;
		LootMax = 15;
	};
	class Cargo_Container : container_helicrash_epoch
	{
		lootMin = 5;
		LootMax = 8;
	};
	class MineralDepositCopper_EPOCH : Default
	{
		lootMin = 3;
		LootMax = 6;
		tables[] = {
				{ "Gems", 15 },
				{ "Ore", 85 }
		};
	};
	class MineralDepositSilver_EPOCH : Default
	{
		lootMin = 3;
		LootMax = 6;
		tables[] = {
				{ "Gems", 20 },
				{ "Ore", 75 }
		};
	};
	class MineralDepositGold_EPOCH : Default
	{
		lootMin = 3;
		LootMax = 6;
		tables[] = {
				{ "Gems", 25 },
				{ "Ore", 75 }
		};
	};
	class Land_Wreck_Satellite_EPOCH : Default
	{
		lootMin = 8;
		LootMax = 14;
		tables[] = { "Satellite" };
	};
	class satellite_p3d : Land_Wreck_Satellite_EPOCH {};
	class AirDrop_Payout1
	{
		lootMin = 5;
		LootMax = 10;
		tables[] = {
				{ "MetalBars", 5 },
				{ "BuildingItems", 1 },
				{ "Gems", 3 },
				{ "Primitive", 3 }
		};
	};
	
// ########################################################################### Epoch Trader Missions ###########################################################################
	class Mission_Payout1
	{
		lootMin = 2;
		LootMax = 5;
		tables[] = {
				{ "Primitive", 8 },
				{ "BuildingItems", 25 },
				{ "BuildingKits", 15 },
				{ "Storages", 3 },
				{ "Equipment", 5 },
				{ "Tools", 5 },
				{ "Repairs", 5 },
				{ "VehicleDocs", 2 },
				{ "Seeds", 5 },
				{ "Drink", 6 },
				{ "Food", 6 },
				{ "Medical", 4 },
				{ "MetalBars", 3 },
				{ "Gems", 3 }
		};
	};
	class Mission_Monster_Payout : Mission_Payout1
	{
		lootMin = 5;
		LootMax = 10;
	};
	class Mission_Fishing_Payout : Mission_Payout1
	{
		lootMin = 4;
		LootMax = 8;
	};

// ########################################################################### Epoch Animals / AIs ###########################################################################
	class Sheep_random_EPOCH
	{
		lootMin = 1;
		LootMax = 2;
		tables[] = { "Sheep_random_EPOCH" };
	};
	class Goat_random_EPOCH
	{
		lootMin = 1;
		LootMax = 2;
		tables[] = { "Goat_random_EPOCH" };
	};
	class Fin_random_EPOCH
	{
		lootMin = 1;
		LootMax = 2;
		tables[] = { "Fin_random_EPOCH" };
	};
	class Alsatian_Random_EPOCH
	{
		lootMin = 1;
		LootMax = 2;
		tables[] = { "Alsatian_Random_EPOCH" };
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
	class Epoch_RyanZombie_1
	{
		lootMin = 2;
		LootMax = 5;
		tables[] = { "EPOCH_RyanZombie_1" };
	};
	class GreatWhite_F
	{
		lootMin = 2;
		LootMax = 5;
		tables[] = { "GreatWhite_F" };
	};
	class Epoch_Sapper_F
	{
		lootMin = 2;
		LootMax = 5;
		tables[] = { "Epoch_Sapper_F" };
	};
	class Epoch_SapperB_F
	{
		lootMin = 2;
		LootMax = 5;
		tables[] = { "Epoch_SapperB_F" };
	};
    class Epoch_SapperG_F
	{
		lootMin = 2;
		LootMax = 5;
		tables[] = { "Epoch_SapperG_F" };
	};
	class Epoch_Cloak_F
	{
		lootMin = 2;
		LootMax = 5;
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
	class SeaFood
	{
		lootMin = 1;
		LootMax = 1;
		tables[] = { "SeaFood" };
	};
};
