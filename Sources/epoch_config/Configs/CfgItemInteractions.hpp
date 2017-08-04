/*
Legend:
interactAction: 0 = examine, 1 = eat, 2 = drink, 3 = build
interactAttributes[] = {
	{"Temp",0},
	{"Hunger",0},
	{"Thirst",0},
	{"Energy",0},
	{"Soiled",0},
	{"Immunity",0},
	{"Toxicity",0},
	{"Stamina",0},
	{"Wet",0},
	{"BloodP",0},
	{"Karma",0},
	{"Alcohol",0},
	{"Radiation",0}
};
*/
/*[[[cog from arma_config_tools import *; json_to_arma()]]]*/
/*
    @author = "Aaron Clark - https://EpochMod.com";
    @contributors[] = {"Andrew Gregory"};
    @description = "Item interaction configs";
    @licence = "Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike";
    @github = "https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_config/Configs/CfgItemInteractions.hpp";
*/
class CfgItemInteractions
{
    class Default
    {
        interactAction = 0;
    };
    class Food_base : Default
    {
        interactAction = 1;
        interactText = "EAT";
        interactAttributes[] = {{"Hunger",600}};
    };
    class Food_TinCan_base : Food_base
    {
        interactReturnOnUse = "ItemEmptyTin";
    };
    class Food_Jar_base : Food_base
    {
        interactReturnOnUse = "emptyjar_epoch";
    };
    class Food_Cooler_base : Food_base
    {
        interactReturnOnUse = "ItemCoolerE";
    };
    class Drink_base : Default
    {
        interactAction = 2;
        interactText = "DRINK";
        interactAttributes[] = {{"Thirst",500}};
    };
    class Drink_Jar_base : Drink_base
    {
        interactReturnOnUse = "emptyjar_epoch";
    };
    class Soda_base : Drink_base
    {
        interactReturnOnUse = "ItemSodaEmpty";
    };
    class Item_Build_base : Default
    {
        interactAction = 3;
        interactText = "BUILD";
    };
    class Item_Packed_base : Default
    {
        interactAction = 14;
        interactText = "UNPACK";
    };
    class honey_epoch : Food_Jar_base
    {
        interactText = "EAT";
        interactAttributes[] = {{"Immunity",1},{"Stamina",30},{"BloodP",10}};
        interactActions[] = {{"EMPTY","[1,[],'emptyjar_epoch'] call EPOCH_consumeItem;"}};
    };
    class sardines_epoch : Food_TinCan_base
    {
        interactAttributes[] = {{"Hunger",1000},{"Toxicity",7}};
    };
    class meatballs_epoch : Food_TinCan_base
    {
        interactAttributes[] = {{"Hunger",1200}};
    };
    class scam_epoch : Food_TinCan_base
    {
        interactAttributes[] = {{"Hunger",1000}};
    };
    class sweetcorn_epoch : Food_TinCan_base
    {
        interactAttributes[] = {{"Hunger",600}};
    };
    class FoodBioMeat : Food_TinCan_base
    {
        interactAttributes[] = {{"Hunger",1000},{"Toxicity",7}};
    };
    class TacticalBacon : Food_TinCan_base
    {
        interactAttributes[] = {{"Hunger",500}};
    };
    class ItemTrout : Food_base
    {
        interactAttributes[] = {{"Hunger",300},{"Toxicity",5}};
    };
    class ItemSeaBass : Food_base
    {
        interactAttributes[] = {{"Hunger",500},{"Toxicity",10}};
    };
    class ItemTuna : Food_base
    {
        interactAttributes[] = {{"Hunger",2500}};
    };
    class ItemTroutCooked : Food_base
    {
        interactAttributes[] = {{"Hunger",600}};
    };
    class ItemSeaBassCooked : Food_base
    {
        interactAttributes[] = {{"Hunger",1200}};
    };
    class ItemTunaCooked : Food_base
    {
        interactAttributes[] = {{"Hunger",5000}};
    };
    class FoodMeeps : Food_base
    {
        interactAttributes[] = {{"Hunger",500}};
    };
    class FoodSnooter : Food_base
    {
        interactAttributes[] = {{"Hunger",500},{"Stamina",50}};
    };
    class ItemCooler0 : Food_Cooler_base
    {
        interactAttributes[] = {{"Hunger",3000}};
    };
    class ItemCooler1 : Food_Cooler_base
    {
        interactAttributes[] = {{"Hunger",3500}};
    };
    class ItemCooler2 : Food_Cooler_base
    {
        interactAttributes[] = {{"Hunger",4000}};
    };
    class ItemCooler3 : Food_Cooler_base
    {
        interactAttributes[] = {{"Hunger",5000}};
    };
    class ItemCooler4 : Food_Cooler_base
    {
        interactAttributes[] = {{"Hunger",5000}};
    };
    class WhiskeyNoodle : Drink_base
    {
        interactAttributes[] = {{"Thirst",800},{"Toxicity",-1},{"Stamina",50},{"Alcohol",10}};
    };
    class water_epoch : Drink_Jar_base
    {
        interactAttributes[] = {{"Thirst",500},{"Toxicity",5,1},{"Stamina",50}};
    };
    class clean_water_epoch : Drink_Jar_base
    {
        interactAttributes[] = {{"Thirst",500},{"Stamina",50}};
    };
    class ItemSodaRbull : Soda_base
    {
        interactAttributes[] = {{"Thirst",1000},{"Stamina",100}};
    };
    class ItemSodaOrangeSherbet : Soda_base
    {
        interactAttributes[] = {{"Thirst",800},{"Stamina",75}};
    };
    class ItemSodaPurple : Soda_base
    {
        interactAttributes[] = {{"Thirst",800},{"Stamina",75}};
    };
    class ItemSodaMocha : Soda_base
    {
        interactAttributes[] = {{"Thirst",650},{"Stamina",150}};
    };
    class ItemSodaBurst : Soda_base
    {
        interactAttributes[] = {{"Thirst",800},{"Stamina",75}};
    };
    class FoodWalkNSons : Soda_base
    {
        interactAttributes[] = {{"Thirst",1200},{"Stamina",150}};
    };
    class ItemSodaAlpineDude : Soda_base
    {
        interactAttributes[] = {{"Thirst",800},{"Stamina",800}};
    };
    class jerrycan_epoch : Default
    {
        interactAction = 4;
        interactText = "FILL";
        interactReturnOnUse = "jerrycanE_epoch";
        interactAttributes[] = {10};
        interactActions[] = {{"DRINK","[2,[['Toxicity',100],['Alcohol',50]],'jerrycanE_epoch'] call EPOCH_consumeItem;"},{"EMPTY","[2,[],'jerrycanE_epoch'] call EPOCH_consumeItem;"}};
    };
    class jerrycanE_epoch : Default
    {
        interactAction = 5;
        interactText = "SIPHON";
        interactReturnOnUse = "jerrycan_epoch";
        interactAttributes[] = {10};
    };
    class FAK : Default
    {
        interactAction = 13;
        interactText = "USE";
    };
    class ItemLockbox : Item_Build_base
    {
        buildClass = "LockBox_SIM_EPOCH";
    };
    class ItemSafe : Item_Build_base
    {
        buildClass = "Safe_SIM_EPOCH";
    };
    class JackKit : Item_Build_base
    {
        buildClass = "Jack_SIM_EPOCH";
    };
    class EnergyPack : Default
    {
        interactAction = 9;
        interactText = "USE";
        interactAttributes[] = {{"Energy",100}};
    };
    class EnergyPackLg : Default
    {
        interactAction = 9;
        interactText = "USE";
        interactAttributes[] = {{"Energy",1000}};
    };
    class VehicleRepair : Default
    {
        interactAction = 10;
        interactText = "USE";
    };
    class VehicleRepairLg : Default
    {
        interactAction = 11;
        interactText = "USE";
    };
    class Venom_EPOCH : Default
    {
        interactAction = 1;
        interactText = "EAT";
        interactAttributes[] = {{"Toxicity",20,1}};
    };
    class SnakeCarcass_EPOCH : Default
    {
        interactAction = 1;
        interactText = "EAT";
        interactAttributes[] = {{"Hunger",300},{"Soiled",1},{"Toxicity",10,1}};
    };
    class SnakeMeat_EPOCH : Default
    {
        interactAction = 1;
        interactText = "EAT";
        interactAttributes[] = {{"Hunger",1200}};
    };
    class RabbitCarcass_EPOCH : Default
    {
        interactAction = 1;
        interactText = "EAT";
        interactAttributes[] = {{"Hunger",300},{"Soiled",1},{"Toxicity",10,1}};
    };
    class CookedRabbit_EPOCH : Default
    {
        interactAction = 1;
        interactText = "EAT";
        interactAttributes[] = {{"Hunger",1200}};
    };
    class ChickenCarcass_EPOCH : Default
    {
        interactAction = 1;
        interactText = "EAT";
        interactAttributes[] = {{"Hunger",500},{"Soiled",1},{"Toxicity",25,1}};
    };
    class CookedChicken_EPOCH : Default
    {
        interactAction = 1;
        interactText = "EAT";
        interactAttributes[] = {{"Hunger",2000}};
    };
    class GoatCarcass_EPOCH : Default
    {
        interactAction = 1;
        interactText = "EAT";
        interactAttributes[] = {{"Hunger",500},{"Soiled",1},{"Toxicity",15,1}};
    };
    class DogCarcass_EPOCH : Default
    {
        interactAction = 1;
        interactText = "EAT";
        interactAttributes[] = {{"Hunger",500},{"Soiled",1},{"Toxicity",15,1},{"Karma",-10}};
    };
    class CookedDog_EPOCH : Default
    {
        interactAction = 1;
        interactText = "EAT";
        interactAttributes[] = {{"Hunger",3000},{"Karma",-10}};
    };
    class CookedGoat_EPOCH : Default
    {
        interactAction = 1;
        interactText = "EAT";
        interactAttributes[] = {{"Hunger",3000}};
    };
    class SheepCarcass_EPOCH : Default
    {
        interactAction = 1;
        interactText = "EAT";
        interactAttributes[] = {{"Hunger",500},{"Soiled",1},{"Toxicity",15,1}};
    };
    class CookedSheep_EPOCH : Default
    {
        interactAction = 1;
        interactText = "EAT";
        interactAttributes[] = {{"Hunger",3000}};
    };
	class ItemPowderMilk : Food_base
    {
        interactAttributes[] = {{"Thirst",-350},{"Hunger",300}};
    };
	class ItemRicebox : Food_base
    {
        interactAttributes[] = {{"Thirst",-1000},{"Hunger",1200}};
    };
	class ItemCereals : Food_base
    {
        interactAttributes[] = {{"Thirst",-1000},{"Hunger",1200}};
    };
	class ItemVitamins : Food_base
    {
		interactText = "Take Pills";
        interactAttributes[] = {{"Immunity",20},{"Stamina",50},{"BloodP",-10},{"Toxicity",-5},{"Thirst",-150}};
    };
    class KitSpikeTrap : Item_Build_base
    {
        buildClass = "Spike_TRAP_SIM_EPOCH";
    };
    class KitMetalTrap : Item_Build_base
    {
        buildClass = "Metal_TRAP_SIM_EPOCH";
    };
    class KitStudWall : Item_Build_base
    {
        buildClass = "WoodLargeWall_EPOCH";
    };
    class KitWoodFloor : Item_Build_base
    {
        buildClass = "WoodFloor_EPOCH";
    };
    class KitWoodHalfFloor : Item_Build_base
    {
        buildClass = "WoodHalfFloor_EPOCH";
    };
	class KitWoodQuarterFloor : Item_Build_base
    {
        buildClass = "WoodQuarterFloor_EPOCH";
    };
	class KitWoodStairs : Item_Build_base
    {
        buildClass = "WoodStairs_EPOCH";
    };
    class KitWoodTower : Item_Build_base
    {
        buildClass = "WoodTower_EPOCH";
    };
    class KitWoodRamp : Item_Build_base
    {
        buildClass = "WoodRamp_EPOCH";
    };
    class KitTankTrap : Item_Build_base
    {
        buildClass = "TankTrap_SIM_EPOCH";
    };
    class KitHesco3 : Item_Build_base
    {
        buildClass = "Hesco3_EPOCH";
    };
    class KitWoodLadder : Item_Build_base
    {
        buildClass = "WoodLadder_EPOCH";
    };
    class KitFirePlace : Item_Build_base
    {
        buildClass = "FirePlace_SIM_EPOCH";
    };
    class KitTiPi : Item_Build_base
    {
        buildClass = "Tipi_SIM_EPOCH";
        isStorage = 1;
    };
    class KitShelf : Item_Build_base
    {
        buildClass = "StorageShelf_SIM_EPOCH";
        isStorage = 1;
    };
    class KitWorkbench : Item_Build_base
    {
        buildClass = "Workbench_SIM_EPOCH";
        isStorage = 1;
    };
    class KitFoundation : Item_Build_base
    {
        buildClass = "Foundation_EPOCH";
    };
    class KitWoodFoundation : Item_Build_base
    {
        buildClass = "WoodFoundation_EPOCH";
    };
    class KitSolarGen : Item_Build_base
    {
        buildClass = "SolarGen_SIM_EPOCH";
    };
    class KitPlotPole : Item_Build_base
    {
        buildClass = "PlotPole_SIM_EPOCH";
    };
    class KitCinderWall : Item_Build_base
    {
        buildClass = "CinderWallHalf_EPOCH";
    };
    class PaintCanBase : Default
    {
        interactAction = 12;
        interactText = "USE";
    };
    class PaintCanClear : PaintCanBase
    {
        colorName = "None";
        textureIndex = 0;
    };
    class PaintCanBlk : PaintCanBase
    {
        colorName = "Black";
        textureIndex = 1;
    };
    class PaintCanBlu : PaintCanBase
    {
        colorName = "Blue";
        textureIndex = 2;
    };
    class PaintCanBrn : PaintCanBase
    {
        colorName = "Brown";
        textureIndex = 3;
    };
    class PaintCanGrn : PaintCanBase
    {
        colorName = "Green";
        textureIndex = 4;
    };
    class PaintCanOra : PaintCanBase
    {
        colorName = "Orange";
        textureIndex = 5;
    };
    class PaintCanPur : PaintCanBase
    {
        colorName = "Purple";
        textureIndex = 6;
    };
    class PaintCanRed : PaintCanBase
    {
        colorName = "Red";
        textureIndex = 7;
    };
    class PaintCanTeal : PaintCanBase
    {
        colorName = "Teal";
        textureIndex = 8;
    };
    class PaintCanYel : PaintCanBase
    {
        colorName = "Yellow";
        textureIndex = 9;
    };
    class Poppy : Default
    {
        interactAction = 6;
        interactText = "USE";
        interactAttributes[] = {{"Immunity",10},{"Stamina",-100},{"BloodP",-10}};
    };
    class Goldenseal : Default
    {
        interactAction = 6;
        interactText = "USE";
        interactAttributes[] = {{"Toxicity",-50}};
    };
    class Pumpkin : Default
    {
        interactAction = 6;
        interactText = "USE";
        interactAttributes[] = {{"Hunger",500},{"Stamina",50}};
    };
    class Towelette : Default
    {
        interactAction = 6;
        interactText = "USE";
        interactAttributes[] = {{"Soiled",-25}};
    };
    class HeatPack : Default
    {
        interactAction = 7;
        interactText = "USE";
        interactAttributes[] = {{"Temp",1}};
    };
    class ColdPack : Default
    {
        interactAction = 8;
        interactText = "USE";
        interactAttributes[] = {{"Temp",-1}};
    };
    class ItemHotwire : Default
    {
        interactAction = 2;
        interactText = "USE";
    };
    class ItemKeyKit : Default
    {
        interactAction = 2;
        interactText = "USE";
    };
    class ItemBarrelF : Default
    {
        interactAction = 4;
        interactText = "FILL";
        interactAttributes[] = {210};
        interactReturnOnUse = "ItemBarrelE";
    };
    class ItemBarrelE : Default
    {
        interactAction = 5;
        interactText = "SIPHON";
        interactAttributes[] = {210};
        interactReturnOnUse = "ItemBarrelF";
    };
    class ItemKey : Default
    {
        interactAction = 2;
        interactText = "USE";
    };
    class ItemKeyBlue : ItemKey {};
    class ItemKeyGreen : ItemKey {};
    class ItemKeyRed : ItemKey {};
    class ItemKeyYellow : ItemKey {};
    class ItemDoc1 : Default
    {
        interactAction = 15;
        interactText = "READ";
    };
    class ItemDoc2 : ItemDoc1 {};
    class ItemDoc3 : ItemDoc1 {};
    class ItemDoc4 : ItemDoc1 {};
    class ItemDoc5 : ItemDoc1 {};
    class ItemDoc6 : ItemDoc1 {};
    class ItemDoc7 : ItemDoc1 {};
    class ItemDoc8 : ItemDoc1 {};
    class ItemVehDoc1 : ItemDoc1 {};
    class ItemVehDoc2 : ItemDoc1 {};
    class ItemVehDoc3 : ItemDoc1 {};
    class ItemVehDoc4 : ItemDoc1 {};
	class KitVehicleUpgradeI_100_EPOCH : ItemDoc1 {};
	class KitVehicleUpgradeI_200_EPOCH : ItemDoc1 {};
	class KitVehicleUpgradeI_300_EPOCH : ItemDoc1 {};
	class KitVehicleUpgradeII_100_EPOCH : ItemDoc1 {};
	class KitVehicleUpgradeII_200_EPOCH : ItemDoc1 {};
	class KitVehicleUpgradeII_300_EPOCH : ItemDoc1 {};
	class KitVehicleUpgradeIII_100_EPOCH : ItemDoc1 {};
	class KitVehicleUpgradeIII_200_EPOCH : ItemDoc1 {};
	class KitVehicleUpgradeIII_300_EPOCH : ItemDoc1 {};
	class KitVehicleUpgradeIV_100_EPOCH : ItemDoc1 {};
	class KitVehicleUpgradeIV_200_EPOCH : ItemDoc1 {};
	class KitVehicleUpgradeIV_300_EPOCH : ItemDoc1 {};
    class ItemBulb : Default {};
    class ItemBurlap : Default {};
    class ItemBriefcaseE : Default {};
    class ItemBriefcaseGold100oz : Default {};
	class ItemBriefcaseSilver100oz : Default {};
    class ItemAluminumBar : Default {};
	class ItemAluminumBar10oz : Default {};
    class ItemCopperBar : Default {};
	class ItemCopperBar10oz : Default {};
    class ItemTinBar : Default {};
	class ItemTinBar10oz : Default {};
    class ItemPlywoodPack : Default {};
    class ItemComboLock : Default {};
    class CircuitParts : Default {};
    class Pelt_EPOCH : Default {};
    class ItemPipe : Default {};
    class ItemEmptyTin : Default {};
    class ItemSodaEmpty : Default {};
    class emptyjar_epoch : Default {};
    class PartPlankPack : Default {};
    class CinderBlocks : Default {};
    class MortarBucket : Default {};
    class ItemKiloHemp : Default {};
    class ItemTopaz : Default {};
    class ItemOnyx : Default {};
    class ItemSapphire : Default {};
    class ItemAmethyst : Default {};
    class ItemEmerald : Default {};
    class ItemCitrine : Default {};
    class ItemRuby : Default {};
    class ItemQuartz : Default {};
    class ItemJade : Default {};
    class ItemGarnet : Default {};
    class ItemMixOil : Default {};
    class ItemDocument : Default {};
    class ItemDocumentMission : Default {};
    class ItemSilverBar : Default {};
	class ItemSilverBar10oz : Default {};
    class ItemGoldBar : Default {};
    class ItemGoldBar10oz : Default {};
    class ItemRock : Default {};
    class ItemStick : Default {};
    class ItemRope : Default {};
    class PartOre : Default {};
    class PartOreSilver : Default {};
    class PartOreGold : Default {};
    class ItemPacked : Default {};
    class ItemSolar : Default {};
    class ItemCables : Default {};
    class ItemBattery : Default {};
    class ItemScraps : Default {};
    class ItemCorrugated : Default {};
    class ItemCorrugatedLg : Default {};
    class 5Rnd_rollins_mag : Default {};
    class CSGAS : Default {};
    class sledge_swing : Default {};
    class stick_swing : Default {};
    class hatchet_swing : Default {};
    class WoodLog_EPOCH : Default {};
    class ItemCoolerE : Default {};
    class lighter_epoch : Default {};
    class Item_AssaultPack_cbr : Item_Packed_base
    {
        interactReturnOnUse = "B_AssaultPack_cbr";
    };
    class Item_AssaultPack_dgtl : Item_Packed_base
    {
        interactReturnOnUse = "B_AssaultPack_dgtl";
    };
    class Item_AssaultPack_khk : Item_Packed_base
    {
        interactReturnOnUse = "B_AssaultPack_khk";
    };
    class Item_AssaultPack_mcamo : Item_Packed_base
    {
        interactReturnOnUse = "B_AssaultPack_mcamo";
    };
    class Item_AssaultPack_ocamo : Item_Packed_base
    {
        interactReturnOnUse = "B_AssaultPack_ocamo";
    };
    class Item_AssaultPack_rgr : Item_Packed_base
    {
        interactReturnOnUse = "B_AssaultPack_rgr";
    };
    class Item_AssaultPack_sgg : Item_Packed_base
    {
        interactReturnOnUse = "B_AssaultPack_sgg";
    };
    class Item_AssaultPack_blk : Item_Packed_base
    {
        interactReturnOnUse = "B_AssaultPack_blk";
    };
    class Item_Carryall_cbr : Item_Packed_base
    {
        interactReturnOnUse = "B_Carryall_cbr";
    };
    class Item_Carryall_khk : Item_Packed_base
    {
        interactReturnOnUse = "B_Carryall_khk";
    };
    class Item_Carryall_mcamo : Item_Packed_base
    {
        interactReturnOnUse = "B_Carryall_mcamo";
    };
    class Item_Carryall_ocamo : Item_Packed_base
    {
        interactReturnOnUse = "B_Carryall_ocamo";
    };
    class Item_Carryall_oli : Item_Packed_base
    {
        interactReturnOnUse = "B_Carryall_oli";
    };
    class Item_Carryall_oucamo : Item_Packed_base
    {
        interactReturnOnUse = "B_Carryall_oucamo";
    };
    class Item_FieldPack_blk : Item_Packed_base
    {
        interactReturnOnUse = "B_FieldPack_blk";
    };
    class Item_FieldPack_cbr : Item_Packed_base
    {
        interactReturnOnUse = "B_FieldPack_cbr";
    };
    class Item_FieldPack_khk : Item_Packed_base
    {
        interactReturnOnUse = "B_FieldPack_khk";
    };
    class Item_FieldPack_ocamo : Item_Packed_base
    {
        interactReturnOnUse = "B_FieldPack_ocamo";
    };
    class Item_FieldPack_oli : Item_Packed_base
    {
        interactReturnOnUse = "B_FieldPack_oli";
    };
    class Item_FieldPack_oucamo : Item_Packed_base
    {
        interactReturnOnUse = "B_FieldPack_oucamo";
    };
    class Item_Kitbag_cbr : Item_Packed_base
    {
        interactReturnOnUse = "B_Kitbag_cbr";
    };
    class Item_Kitbag_mcamo : Item_Packed_base
    {
        interactReturnOnUse = "B_Kitbag_mcamo";
    };
    class Item_Kitbag_rgr : Item_Packed_base
    {
        interactReturnOnUse = "B_Kitbag_rgr";
    };
    class Item_Kitbag_sgg : Item_Packed_base
    {
        interactReturnOnUse = "B_Kitbag_sgg";
    };
    class Item_TacticalPack_blk : Item_Packed_base
    {
        interactReturnOnUse = "B_TacticalPack_blk";
    };
    class Item_TacticalPack_mcamo : Item_Packed_base
    {
        interactReturnOnUse = "B_TacticalPack_mcamo";
    };
    class Item_TacticalPack_ocamo : Item_Packed_base
    {
        interactReturnOnUse = "B_TacticalPack_ocamo";
    };
    class Item_TacticalPack_oli : Item_Packed_base
    {
        interactReturnOnUse = "B_TacticalPack_oli";
    };
    class Item_TacticalPack_rgr : Item_Packed_base
    {
        interactReturnOnUse = "B_TacticalPack_rgr";
    };
    class Item_smallbackpack_red : Item_Packed_base
    {
        interactReturnOnUse = "smallbackpack_red_epoch";
    };
    class Item_smallbackpack_green : Item_Packed_base
    {
        interactReturnOnUse = "smallbackpack_green_epoch";
    };
    class Item_smallbackpack_teal : Item_Packed_base
    {
        interactReturnOnUse = "smallbackpack_teal_epoch";
    };
    class Item_smallbackpack_pink : Item_Packed_base
    {
        interactReturnOnUse = "smallbackpack_pink_epoch";
    };
};

/*[[[end]]]*/
