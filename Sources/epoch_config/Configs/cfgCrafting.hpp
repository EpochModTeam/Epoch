/*
	Author: Aaron Clark - EpochMod.com

    Contributors: Raimonds Virtoss (v2 Crafting)

	Description:
	Main Crafting configs

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_config/Configs/CfgCrafting.hpp

	USAGE:
	nearby[] =
	{
		{
			"Fire",			//Name of field, anything
			"",				//image folder path (ie "\x\addons\a3_epoch_code\Data\UI\crafting\"), empty for Epoch default
			"fire",			//image prefix, suffix will be added by code. 2 possible suffixes: [_true.paa, _false.paa]
			{1,{"ALL"}},	//ARRAY of p3D {0,{"filename.p3d","filename.p3d"}} or ARRAY of logic classes {1,{"AIR","LAND","className"}} or 2 WorldInteractions check {2,{"water"}} Integer to switch array mode
			3,				//distance to check in meters
			1,				//count
			1,				//BOOL: object has to be on fire
			0				//BOOL: object has to be alive (not destroyed)
		};
	};

	//Can be multiple requirements like this, example requires both fire and water (unlimited, but requires mouse scroll if more than 8 elements):
	nearby[] =
	{
		{"Fire", "", "fire", {1,{"ALL"}}, 3, 1, 1, 0},
		{"Water source","","water",{0,{"barrelwater_f.p3d", "water_source_f.p3d", "pumpa.p3d", "misc_wellpump.p3d"}},3,1,0,0},
		{{"Water source", "", "water", {2,{"water"}}, 3, 1, 0, 0}}

	};
*/

class CfgCrafting
{
	DeveloperMode = 0; //used for 3D preview position and scale, set to 0 for live server!

	//You can customize basic theme of crafting UI here:
	colorScheme[] =
	{
		"\x\addons\a3_epoch_code\Data\UI\crafting\cancel.paa",
		"\x\addons\a3_epoch_code\Data\UI\crafting\craft.paa",
		"\x\addons\a3_epoch_code\Data\UI\crafting\close.paa",

		{"Recipes", 			{0,0,0,0.8}},
		{"Ingredients",			{0,0,0,0.8}},
		{"Preview",				{0.76,0.5,0.07,0.8}},
		{"Resources",			{0,0,0,0.8}},
		{"Description",			{0,0,0,0.8}},
		{" -- Requires -- ",	{0.99,0.53,0.03,1}},
		{" -- Used in -- ",		{0.99,0.53,0.03,1}},

		{0,1,0,1},		//Recipe LB, item found
		{0,1,0,1},		//Ingredients LB, Has items on player
		{1,1,0,1},		//Ingredients LB, Has items nearby
		{1,0,0,1}, 		//Ingredients LB, Missing items
		{1,1,1,1},		//Ingredients LB, Items used in...
		{0,0,0,0.1},	//Background color
		{0,0,0,1},		//Frame color
		{0,0,0,0},		//description ST
		{0,0,0,0},		//Recipe LB
		{0,0,0,0},		//Ingredients LB

		{0.76,0.5,0.07,0.8},	//progress bar
		{0,0,0,0.3},			//progress background
		"#FFFFFF",				//progress text HTML color

		{1,0.6,0.01,1}		//QTY color
	};

	/** --------- Don't edit --------- **/
	class Default //className, any object or item
	{
		craftTime = 1; //time it takes to craft

		recipe[] = {}; //nested arrays, {{"item", 1}};
		nearby[] = {}; //nearby requirements - fire, water source, object
		usedIn[] = {}; //item is an ingredient

		previewPosition[] = {0.8125,1,0.285}; //XzY
		previewScale = 1;
		previewVector = 0; //vector rotation multiplier

		priority = 0; //Recipe list priority, items with 0 are on top followed by order in config file.
		type = 0; //After crafting, item is added: [0 - to inventory], [1 - in weapon holder], [2 - as vehicle]
		descriptionFull = ""; //Structured text, added on new line after descriptionShort

		/** --------- Config Overrides --------- **/
		//displayName = "";
		//picture = "";
		//descriptionShort = "";
		//model = "\x\addons\a3_epoch_assets\models\logo.p3d";
	};

	/** --------- Main templates --------- **/
	class WeaponHolder: Default //Placed inside weaponholder in front of player (?)
	{
		priority = 0;
		type = 1;
		offset[] = {0,1,0}; //local space
		craftTime = 10;
		descriptionFull = "Demo: Can be used if player's inventory space is an issue";
	};
	class Vehicle: Default //Spawned in front of player (?)
	{
		priority = 0;
		type = 2;
		offset[] = {0,5,0}; //local space
		craftTime = 10;
		descriptionFull = "Demo: Should be used for vehicles only";
	};
	class Kit: Default //base building kits gets higher priority on the list
	{
		priority = 1;
		descriptionFull = "Base building material";
		craftTime = 4;
	};
	class Item: Default //Goes into inventory
	{
		priority = 2;
		craftTime = 2;
	};
	class Part: Default //Looted part - an ingredient for other items, can't be crafted
	{
		priority = 3;
		descriptionFull = "<t color='#FD7F30'>This item has no recipe, but is a part used for other recipes</t>";
	};

	/** --------- RECIPES BELOW --------- **/

	// items
	class ItemCoolerE : Part
	{
		 usedIn[] = { "ItemCooler0", "ItemCooler1", "ItemCooler2", "ItemCooler3", "ItemCooler4" };
		previewPosition[] = {0.795709,1,0.415296};
		previewScale = 0.8;
		previewVector = 0;
	};
	class ItemCooler0 : Item
	{
		recipe[] = { "ItemCoolerE", { "SnakeMeat_EPOCH", 2 }, "sweetcorn_epoch" };
		previewPosition[] = {0.795709,1,0.415296};
		previewScale = 0.8;
		previewVector = 0;
	};
	class ItemCooler1 : Item
	{
		recipe[] = { "ItemCoolerE", { "CookedRabbit_EPOCH", 2 }, "sweetcorn_epoch" };
		previewPosition[] = {0.795709,1,0.415296};
		previewScale = 0.8;
		previewVector = 0;
	};
	class ItemCooler2 : Item
	{
		recipe[] = { "ItemCoolerE", "CookedChicken_EPOCH", "sweetcorn_epoch" };
		previewPosition[] = {0.795709,1,0.415296};
		previewScale = 0.8;
		previewVector = 0;
	};
	class ItemCooler3 : Item
	{
		recipe[] = { "ItemCoolerE", "CookedGoat_EPOCH", "sweetcorn_epoch" };
		previewPosition[] = {0.795709,1,0.415296};
		previewScale = 0.8;
		previewVector = 0;
	};
	class ItemCooler4 : Item
	{
		recipe[] = { "ItemCoolerE", "CookedSheep_EPOCH", "sweetcorn_epoch" };
		previewPosition[] = {0.795709,1,0.415296};
		previewScale = 0.8;
		previewVector = 0;
	};
	class sweetcorn_epoch : Part
	{
		usedIn[] = {"ItemCooler0","ItemCooler1","ItemCooler2","ItemCooler3","ItemCooler4"};
		previewPosition[] = {0.799332,1,0.26};
		previewScale = 2.7;
		previewVector = 0;
	};
	class CircuitParts : Part
	{
		usedIn[] = { "EnergyPack", "EnergyPackLg", "KitPlotPole" };
		previewPosition[] = {0.791044,1,0.256956};
		previewScale = 2;
		previewVector = 2.3;
	};
	class EnergyPack : Item
	{
		usedIn[] = { "EnergyPackLg" };
		nearby[] = {{"Fire", "", "fire", {1,{"ALL"}}, 3, 1, 1, 0},{"Workbench", "", "workbench", {1,{"WorkBench_EPOCH"}}, 3, 1, 0, 1}};
		recipe[] = {  { "CircuitParts", 1 }, { "ItemCopperBar", 1 }, { "clean_water_epoch", 1 } };
		previewPosition[] = {0.8,1,0.29};
		previewScale = 1.75;
		previewVector = 2.8;
	};
	class EnergyPackLg : Item
	{
		nearby[] = {{"Workbench", "", "workbench", {1,{"WorkBench_EPOCH"}}, 3, 1, 0, 1}};
		recipe[] = { { "EnergyPack", 3 }, { "ItemGoldBar", 1 }, { "CircuitParts", 1 } };
		previewPosition[] = {0.8,1,0.29};
		previewScale = 1.75;
		previewVector = 2.8;
	};


	class ItemSodaEmpty : Part
	{
		usedIn[] = { "ItemAluminumBar" };
		previewPosition[] = {0.799961,1,0.27};
		previewScale = 1.25;
	};
	class ItemAluminumBar : Item
	{
		usedIn[] = {};
		nearby[] = {{"Fire", "", "fire", {1,{"ALL"}}, 3, 1, 1, 0}};
		recipe[] = { { "ItemSodaEmpty", 6 }, {"water_epoch", 1}};
		previewPosition[] = {0.797144,1,0.309158};
		previewScale = 1;
		previewVector = 2.8;
	};

	class ItemEmptyTin : Part
	{
		usedIn[] = { "ItemTinBar" };
		previewPosition[] = {0.799961,1,0.27};
		previewScale = 1.25;
	};
	class ItemTinBar : Item
	{
		usedIn[] = {};
		nearby[] = {{"Fire", "", "fire", {1,{"ALL"}}, 3, 1, 1, 0}};
		recipe[] = { { "ItemEmptyTin", 6 }, {"water_epoch", 1}};
		previewPosition[] = {0.797144,1,0.309158};
		previewScale = 1;
		previewVector = 2.8;
	};



	class PartOre : Part
	{
		usedIn[] = { "ItemScraps" };
		previewPosition[] = {0.799961,1,0.27};
		previewScale = 1.25;
	};
	class PartOreSilver : Part
	{
		usedIn[] = { "ItemSilverBar" };
		previewPosition[] = {0.799961,1,0.27};
		previewScale = 1.25;
	};
	class PartOreGold : Part
	{
		usedIn[] = { "ItemGoldBar" };
		previewPosition[] = {0.799961,1,0.27};
		previewScale = 1.25;
	};

	class Pelt_EPOCH : Part
	{
		usedIn[] = { "KitTiPi" };
		previewPosition[] = {0.793741,1,0.274824};
		previewScale = 0.7;
		previewVector = 2.2;
	};
	class ItemRock : Part
	{
		usedIn[] = { "KitFirePlace" , "MeleeMaul", "CrudeHatchet" };
		previewPosition[] = {0.796998,1,0.35};
		previewScale = 1.3;
	};
	class ItemStick : Item
	{
		usedIn[] = { "WoodClub", "MeleeMaul", "CrudeHatchet", "KitFirePlace" , "KitSpikeTrap" , "KitMetalTrap" };
		recipe[] = { { "WoodLog_EPOCH", 1 } };
		previewPosition[] = {0.8,1,0.25};
		previewScale = 0.4;
		previewVector = 1;
	};
	class JackKit : Part
	{
		usedIn[] = { "KitSpikeTrap" , "KitMetalTrap"  };
		previewPosition[] = {0.796267,1,0.322762};
		previewScale = 0.9;
		previewVector = 1.4;
	};
	class ItemKiloHemp : Part
	{
		usedIn[] = { "ItemRope", "ItemBurlap" };
		previewPosition[] = {0.796267,1,0.322762};
		previewScale = 0.9;
		previewVector = 1.4;
	};
	class ItemRope : Item
	{
		usedIn[] = { "WoodClub", "MeleeMaul", "CrudeHatchet" };
		nearby[] = {{"Workbench", "", "workbench", {1,{"WorkBench_EPOCH"}}, 3, 1, 0, 1}};
		recipe[] = { { "ItemKiloHemp", 1 } };
		previewPosition[] = {0.8,1,0.35};
		previewScale = 4;
	};
	class ItemBurlap : Item
	{
		usedIn[] = { "KitHesco3" };
		nearby[] = {{"Workbench", "", "workbench", {1,{"WorkBench_EPOCH"}}, 3, 1, 0, 1}};
		recipe[] = { { "ItemKiloHemp", 2 } };
		previewPosition[] = {0.8,1,0.35};
		previewScale = 4;
	};
	class MeleeMaul : Item
	{
		recipe[] = { { "ItemRock", 1 }, { "ItemStick", 2 }, { "ItemRope", 1 } };
		previewPosition[] = {0.798975,1,0.300388};
		previewScale = 0.3;
		previewVector = -1.8;
	};
	class CrudeHatchet : Item
	{
		recipe[] = { { "ItemRock", 1 }, { "ItemStick", 1 }, { "ItemRope", 1 } };
		previewPosition[] = {0.786139,1,0.328525};
		previewScale = 0.6;
	};
	class WoodClub : Item
	{
		recipe[] = { { "ItemStick", 2 } };
		previewPosition[] = {0.799633,1,0.237804};
		previewScale = 0.35;
		previewVector = 2.4;
	};

	class WoodLog_EPOCH : Part
	{
		usedIn[] = { "PartPlankPack", "ItemStick", "ItemPlywoodPack" };
		previewPosition[] = {0.800064,1,0.25};
		previewScale = 0.3;
	};
	class MortarBucket : Part
	{
		usedIn[] = {"KitFoundation","KitCinderWall", "KitHesco3"};
		previewPosition[] = {0.799442,1,0.426761};
		previewScale = 0.6;
		previewVector = 0;
	};
	class ItemScraps : Item
	{
		usedIn[] = { "ItemCorrugated", "KitMetalTrap"};
		nearby[] = {{"Fire", "", "fire", {1,{"ALL"}}, 3, 1, 1, 0}};
		recipe[] = { { "PartOre", 2 } };
		previewPosition[] = {0.797144,1,0.309158};
		previewScale = 1;
		previewVector = 2.8;
	};
	class ItemCorrugated : Item
	{
		usedIn[] = {"KitShelf","ItemCorrugatedLg"};
		nearby[] = {{"Fire", "", "fire", {1,{"ALL"}}, 3, 1, 1, 0}};
		recipe[] = { { "ItemScraps", 2 } };
		previewPosition[] = {0.791088,1,0.300004};
		previewScale = 0.2;
		previewVector = 1;
	};
	class CinderBlocks : Part
	{
		usedIn[] = { "KitCinderWall" };
		previewPosition[] = {0.801866,1,0.35};
		previewScale = 0.2;
	};
	class ItemMixOil : Part
	{
		usedIn[] = { "CSGAS" };
		previewPosition[] = {0.802419,1,0.433119};
		previewScale = 1.5;
	};
	class jerrycan_epoch : Part
	{
		usedIn[] = { "CSGAS" };
		previewPosition[] = {0.802443,1,0.254301};
		previewScale = 0.6;
		previewVector = 4.9;
	};



	class VehicleRepair : Part
	{
		usedIn[] = { "VehicleRepairLg" };
		previewPosition[] = {0.787659,1,0.30098};
		previewScale = 0.45;
		previewVector = 1.5;
	};
	class VehicleRepairLg : Item
	{
		recipe[] = { "VehicleRepair", "ItemCorrugated" };
		previewPosition[] = {0.798742,1,0.317871};
		previewScale = 0.25;
		previewVector = 0.7;
	};

	// radios

	class EpochRadio0 : Part // Quartz
	{
		usedIn[] = { "EpochRadio1" };
		model = "\a3\ui_f\objects\Radio.p3d";
		previewPosition[] = {0.800569,1,0.272473};
		previewScale = 0.45;
		previewVector = -3.9;
	};
	class EpochRadio1 : Item // Garnet
	{
		usedIn[] = { "EpochRadio2" };
		recipe[] = { "EpochRadio0", "ItemGarnet" };
		model = "\a3\ui_f\objects\Radio.p3d";
		previewPosition[] = {0.800569,1,0.272473};
		previewScale = 0.45;
		previewVector = -3.9;
	};
	class EpochRadio2 : Item // Citrine
	{
		usedIn[] = { "EpochRadio3" };
		recipe[] = { "EpochRadio1", "ItemCitrine" };
		model = "\a3\ui_f\objects\Radio.p3d";
		previewPosition[] = {0.800569,1,0.272473};
		previewScale = 0.45;
		previewVector = -3.9;
	};
	class EpochRadio3 : Item // Amethyst
	{
		usedIn[] = { "EpochRadio4" };
		recipe[] = { "EpochRadio2", "ItemAmethyst" };
		model = "\a3\ui_f\objects\Radio.p3d";
		previewPosition[] = {0.800569,1,0.272473};
		previewScale = 0.45;
		previewVector = -3.9;
	};
	class EpochRadio4 : Item // Topaz
	{
		usedIn[] = { "EpochRadio5" };
		recipe[] = { "EpochRadio3", "ItemTopaz" };
		model = "\a3\ui_f\objects\Radio.p3d";
		previewPosition[] = {0.800569,1,0.272473};
		previewScale = 0.45;
		previewVector = -3.9;
	};
	class EpochRadio5 : Item // Sapphire
	{
		usedIn[] = { "EpochRadio6" };
		recipe[] = { "EpochRadio4", "ItemSapphire" };
		model = "\a3\ui_f\objects\Radio.p3d";
		previewPosition[] = {0.800569,1,0.272473};
		previewScale = 0.45;
		previewVector = -3.9;
	};
	class EpochRadio6 : Item // Onyx
	{
		usedIn[] = { "EpochRadio7" };
		recipe[] = { "EpochRadio5", "ItemOnyx" };
		model = "\a3\ui_f\objects\Radio.p3d";
		previewPosition[] = {0.800569,1,0.272473};
		previewScale = 0.45;
		previewVector = -3.9;
	};
	class EpochRadio7 : Item // Emerald
	{
		usedIn[] = { "EpochRadio8" };
		recipe[] = { "EpochRadio6", "ItemEmerald" };
		model = "\a3\ui_f\objects\Radio.p3d";
		previewPosition[] = {0.800569,1,0.272473};
		previewScale = 0.45;
		previewVector = -3.9;
	};
	class EpochRadio8 : Item // Ruby
	{
		usedIn[] = { "EpochRadio9" };
		recipe[] = { "EpochRadio7", "ItemRuby" };
		model = "\a3\ui_f\objects\Radio.p3d";
		previewPosition[] = {0.800569,1,0.272473};
		previewScale = 0.45;
		previewVector = -3.9;
	};
	class EpochRadio9 : Item // Jade
	{
		recipe[] = { "EpochRadio8", "ItemJade" };
		model = "\a3\ui_f\objects\Radio.p3d";
		previewPosition[] = {0.800569,1,0.272473};
		previewScale = 0.45;
		previewVector = -3.9;
	};

	//Gems
	class ItemGarnet : Part
	{
		usedIn[] = {"EpochRadio1"};
		previewPosition[] = {0.801697,1,0.379502};
		previewScale = 3;
	};
	class ItemCitrine : Part
	{
		usedIn[] = {"EpochRadio2"};
		previewPosition[] = {0.796925,1,0.285847};
		previewScale = 3.5;
		previewVector = 2.7;
	};
	class ItemAmethyst : Part
	{
		usedIn[] = {"EpochRadio3"};
		previewPosition[] = {0.798082,1,0.277137};
		previewScale = 3;
		previewVector = 2.9;
	};
	class ItemTopaz : Part
	{
		usedIn[] = {"EpochRadio4"};
		previewPosition[] = {0.79555,1,0.393739};
		previewScale = 3;
	};
	class ItemSapphire : Part
	{
		usedIn[] = {"EpochRadio5"};
		previewPosition[] = {0.804014,1,0.283865};
		previewScale = 3;
		previewVector = 3.3;
	};
	class ItemOnyx : Part
	{
		usedIn[] = {"EpochRadio6"};
		previewPosition[] = {0.799376,1,0.283337};
		previewScale = 3;
		previewVector = 3.1;
	};
	class ItemEmerald : Part
	{
		usedIn[] = {"EpochRadio7"};
		previewPosition[] = {0.805568,1,0.293134};
		previewScale = 3;
		previewVector = 2.5;
	};
	class ItemRuby : Part
	{
		usedIn[] = {"EpochRadio8"};
		previewPosition[] = {0.79555,1,0.393739};
		previewScale = 3;
	};
	class ItemJade : Part
	{
		usedIn[] = {"EpochRadio9"};
		previewPosition[] = {0.796903,1,0.369781};
		previewScale = 3;
	};

	// raw meats
	class SnakeCarcass_EPOCH : Part
	{
		usedIn[] = { "SnakeMeat_EPOCH" };
		previewPosition[] = {0.808621,1,0.238853};
		previewScale = 0.55;
		previewVector = 1.8;
	};
	class SnakeMeat_EPOCH : Item
	{
		usedIn[] = { "ItemCooler0" };
		nearby[] = {{"Fire", "", "fire", {1,{"ALL"}}, 3, 1, 1, 0}};
		recipe[] = { "SnakeCarcass_EPOCH" };
		previewPosition[] = {0.803189,1,0.408752};
		previewScale = 6;
	};
	class RabbitCarcass_EPOCH : Part
	{
		usedIn[] = { "CookedRabbit_EPOCH" };
		previewPosition[] = {0.796141,1,0.340971};
		previewScale = 1.5;
	};
	class CookedRabbit_EPOCH : Item
	{
		usedIn[] = { "ItemCooler1" };
		nearby[] = {{"Fire", "", "fire", {1,{"ALL"}}, 3, 1, 1, 0}};
		recipe[] = { "RabbitCarcass_EPOCH" };
		previewPosition[] = {0.796141,1,0.340971};
		previewScale = 1.5;
	};
	class ChickenCarcass_EPOCH : Part
	{
		usedIn[] = { "CookedChicken_EPOCH" };
		previewPosition[] = {0.796141,1,0.340971};
		previewScale = 0.9;
	};
	class CookedChicken_EPOCH : Item
	{
		usedIn[] = { "ItemCooler2" };
		nearby[] = {{"Fire", "", "fire", {1,{"ALL"}}, 3, 1, 1, 0}};
		recipe[] = { "ChickenCarcass_EPOCH" };
		previewPosition[] = {0.796141,1,0.340971};
		previewScale = 0.9;
	};

	class ItemTuna : Part
	{
		usedIn[] = { "ItemTunaCooked" };
		previewPosition[] = {0.796141,1,0.27};
		previewScale = 0.2;
		previewVector = 2.1;
	};
	class ItemSeaBass : Part
	{
		usedIn[] = { "ItemSeaBassCooked" };
		previewPosition[] = {0.796141,1,0.27};
		previewScale = 0.4;
		previewVector = 2.1;
	};
	class ItemTrout : Part
	{
		usedIn[] = { "ItemTroutCooked" };
		previewPosition[] = {0.796141,1,0.27};
		previewScale = 0.4;
		previewVector = 2.1;
	};
	class ItemTunaCooked : Item
	{
		usedIn[] = {};
		nearby[] = {{"Fire", "", "fire", {1,{"ALL"}}, 3, 1, 1, 0}};
		recipe[] = { "ItemTuna" };
		previewPosition[] = {0.796141,1,0.27};
		previewScale = 0.2;
		previewVector = 2;
	};
	class ItemSeaBassCooked : Item
	{
		usedIn[] = {};
		nearby[] = {{"Fire", "", "fire", {1,{"ALL"}}, 3, 1, 1, 0}};
		recipe[] = { "ItemSeaBass" };
		previewPosition[] = {0.796141,1,0.27};
		previewScale = 0.4;
		previewVector = 2;
	};
	class ItemTroutCooked : Item
	{
		usedIn[] = {};
		nearby[] = {{"Fire", "", "fire", {1,{"ALL"}}, 3, 1, 1, 0}};
		recipe[] = { "ItemTrout" };
		previewPosition[] = {0.796141,1,0.27};
		previewScale = 0.4;
		previewVector = 2;
	};

	class GoatCarcass_EPOCH : Part
	{
		usedIn[] = { "CookedGoat_EPOCH" };
		previewPosition[] = {0.796141,1,0.27};
		previewScale = 0.4;
		previewVector = 2.1;
	};
	class CookedGoat_EPOCH : Item
	{
		usedIn[] = { "ItemCooler3" };
		nearby[] = {{"Fire", "", "fire", {1,{"ALL"}}, 3, 1, 1, 0}};
		recipe[] = { "GoatCarcass_EPOCH" };
		previewPosition[] = {0.796141,1,0.27};
		previewScale = 0.4;
		previewVector = 2;
	};
	class SheepCarcass_EPOCH : Part
	{
		usedIn[] = { "CookedSheep_EPOCH" };
		previewPosition[] = {0.796141,1,0.27};
		previewScale = 0.4;
		previewVector = 2.1;
	};
	class CookedSheep_EPOCH : Item
	{
		usedIn[] = { "ItemCooler4" };
		nearby[] = {{"Fire", "", "fire", {1,{"ALL"}}, 3, 1, 1, 0}};
		recipe[] = { "SheepCarcass_EPOCH" };
		previewPosition[] = {0.796141,1,0.27};
		previewScale = 0.4;
		previewVector = 2.1;
	};

	class emptyjar_epoch : Part
	{
		usedIn[] = { "water_epoch" };
		previewPosition[] = {0.807346,1,0.43035};
		previewScale = 2.5;
	};
	class water_epoch : Item
	{
		usedIn[] = { "clean_water_epoch" };
		nearby[] = {{"Water source", "", "water", {2,{"water"}}, 3, 1, 0, 0}};
		recipe[] = { "emptyjar_epoch" };
		previewPosition[] = {0.807346,1,0.43035};
		previewScale = 2.5;
	};
	class clean_water_epoch : Item
	{
		usedIn[] = { "EnergyPack" };
		nearby[] = {{"Fire", "", "fire", {1,{"ALL"}}, 3, 1, 1, 0}};
		recipe[] = { "water_epoch" };
		previewPosition[] = {0.807346,1,0.43035};
		previewScale = 2.5;
		displayName = "Clean Water";
	};

	// recipes
	class CSGAS : Item
	{
		recipe[] = { "ItemMixOil", "jerrycan_epoch" };
		model = "\x\addons\a3_epoch_assets_2\jerrycan.p3d";
		previewPosition[] = {0.802443,1,0.254301};
		previewScale = 0.6;
		previewVector = 4.9;
	};
	class ItemCorrugatedLg : Item
	{
		usedIn[] = { "VehicleRepairLg", "KitPlotPole", "KitTankTrap", "KitHesco3" };
		recipe[] = { { "ItemCorrugated", 3 } };
		nearby[] = {{"Workbench", "", "workbench", {1,{"WorkBench_EPOCH"}}, 3, 1, 0, 1}};
		previewPosition[] = {0.797491,1,0.32899};
		previewScale = 0.25;
		previewVector = 0.5;
	};

	class PartPlankPack : Item
	{
		usedIn[] = {"KitStudWall","KitWoodFloor","KitWoodFoundation","KitWoodStairs","KitWoodRamp","KitWoodLadder","KitWoodTower","KitTiPi","KitWorkbench","KitSpikeTrap","KitMetalTrap"};
		recipe[] = {{"WoodLog_EPOCH",2}};
		previewPosition[] = {0.797837,1,0.288258};
		previewScale = 0.2;
		previewVector = 1;
		craftTime = 2;
	};
	class ItemPlywoodPack : Item
	{
		usedIn[] = {};
		recipe[] = {{"WoodLog_EPOCH",3}};
		previewPosition[] = {0.797837,1,0.288258};
		previewScale = 0.2;
		previewVector = 1;
		craftTime = 2;
	};


	class KitFirePlace : Kit
	{
		recipe[] = {{"ItemRock",2},{"ItemStick",1}};
		model = "\x\addons\a3_epoch_assets_2\fireplace.p3d";
		previewPosition[] = {0.791523,1,0.244987};
		previewScale = 0.2;
		previewVector = 1.5;
	};




	class KitSpikeTrap : Kit
	{
		recipe[] = {{"PartPlankPack",4},{"ItemStick",1},{"JackKit",1}};
		model = "\x\addons\a3_epoch_assets_1\models\supply_crate.p3d";
		nearby[] = {{"Workbench", "", "workbench", {1,{"WorkBench_EPOCH"}}, 3, 1, 0, 1}};
		previewPosition[] = {0.797675,1,0.398882};
		previewScale = 0.07;
		previewVector = 0;
	};
	class KitMetalTrap : Kit
	{
		recipe[] = {{"PartPlankPack",4},{"ItemStick",1},{"ItemScraps",2},{"JackKit",1}};
		model = "\x\addons\a3_epoch_assets_1\models\supply_crate.p3d";
		nearby[] = {{"Workbench", "", "workbench", {1,{"WorkBench_EPOCH"}}, 3, 1, 0, 1}};
		previewPosition[] = {0.797675,1,0.398882};
		previewScale = 0.07;
		previewVector = 0;
	};


	class KitStudWall : Kit
	{
		recipe[] = {{"PartPlankPack",4}};
		model = "\x\addons\a3_epoch_assets\models\Wooden_Wall_SIM.p3d";
		nearby[] = {{"Workbench", "", "workbench", {1,{"WorkBench_EPOCH"}}, 3, 1, 0, 1}};
		previewPosition[] = {0.797675,1,0.398882};
		previewScale = 0.07;
		previewVector = 0;
	};
	class KitWoodFloor : Kit
	{
		usedIn[] = { "KitWoodTower" };
		recipe[] = {{"PartPlankPack",4}};
		nearby[] = {{"Workbench", "", "workbench", {1,{"WorkBench_EPOCH"}}, 3, 1, 0, 1}};
		model = "\x\addons\a3_epoch_assets\models\Wooden_Floor.p3d";
		previewPosition[] = {0.800198,1,0.262418};
		previewScale = 0.055;
		previewVector = 3.6;
	};
	class KitWoodLadder : Kit
	{
		recipe[] = { { "PartPlankPack", 4 } };
		nearby[] = {{"Workbench", "", "workbench", {1,{"WorkBench_EPOCH"}}, 3, 1, 0, 1}};
		model = "\x\addons\a3_epoch_assets_3\CfgVehicles\Ladder\wood_ladder.p3d";
		previewPosition[] = {0.798736,1,0.441696};
		previewScale = 0.08;
		previewVector = 0;
	};
	class KitWoodRamp : Kit
	{
		recipe[] = { { "PartPlankPack", 6 } };
		nearby[] = {{"Workbench", "", "workbench", {1,{"WorkBench_EPOCH"}}, 3, 1, 0, 1}};
		model = "\x\addons\a3_epoch_assets\models\Wood_Ramp.p3d";
		previewPosition[] = {0.799137,1,0.350575};
		previewScale = 0.05;
		previewVector = 0;
	};
	class KitTankTrap : Kit
	{
		recipe[] = { { "ItemCorrugatedLg", 1 } };
		nearby[] = {{"Workbench", "", "workbench", {1,{"WorkBench_EPOCH"}}, 3, 1, 0, 1}};
		model = "\x\addons\a3_epoch_assets_3\CfgVehicles\Defense\tank_trap.p3d";
		previewPosition[] = { 0.803749, 1, 0.448515 };
		previewScale = 0.17;
		previewVector = 0;
	};
	class KitHesco3 : Kit
	{
		recipe[] = {  { "ItemBurlap", 3 }, { "MortarBucket", 2 }, { "ItemCorrugatedLg", 2 } };
		nearby[] = { { "Workbench", "", "workbench", { 1, { "WorkBench_EPOCH" } }, 3, 1, 0, 1 } };
		model = "\x\addons\a3_epoch_assets_3\CfgVehicles\Defense\hesco.p3d";
		previewPosition[] = { 0.803749, 1, 0.448515 };
		previewScale = 0.02;
		previewVector = 0;
	};
	class KitWoodStairs : Kit
	{
		recipe[] = {{"PartPlankPack",4}};
		nearby[] = {{"Workbench", "", "workbench", {1,{"WorkBench_EPOCH"}}, 3, 1, 0, 1}};
		model = "\x\addons\a3_epoch_assets\models\Wood_stairs.p3d";
		previewPosition[] = {0.795037,1,0.377922};
		previewScale = 0.054;
		previewVector = 0;
	};
	class KitWoodTower : Kit
	{
		recipe[] = { {"KitWoodFloor", 1}, { "PartPlankPack", 4 } };
		nearby[] = {{"Workbench", "", "workbench", {1,{"WorkBench_EPOCH"}}, 3, 1, 0, 1}};
		model = "\x\addons\a3_epoch_assets_3\CfgVehicles\Tower\Tower\Base_Tower_Frame.p3d";
		previewPosition[] = {0.800653,1,0.378749};
		previewScale = 0.05;
		previewVector = 0;
	};
	class KitTiPi : Kit
	{
		recipe[] = { { "Pelt_EPOCH", 4 }, { "PartPlankPack", 2 } };
		nearby[] = {{"Workbench", "", "workbench", {1,{"WorkBench_EPOCH"}}, 3, 1, 0, 1}};
		model = "\x\addons\a3_epoch_assets\models\tp.p3d";
		previewPosition[] = {0.801503,1,0.433758};
		previewScale = 0.06;
		previewVector = 0;
	};
	class KitShelf : Kit
	{
		recipe[] = {{"ItemCorrugated",3}};
		nearby[] = {{"Workbench", "", "workbench", {1,{"WorkBench_EPOCH"}}, 3, 1, 0, 1}};
		model = "\x\addons\a3_epoch_assets\models\shelf.p3d";
		previewPosition[] = {0.803749,1,0.448515};
		previewScale = 0.17;
		previewVector = 0;
	};
	class KitWorkbench : Kit
	{
		recipe[] = { { "PartPlankPack", 2 } };
		model = "\x\addons\a3_epoch_assets_1\models\workbench.p3d";
		previewPosition[] = { 0.803749, 1, 0.448515 };
		previewScale = 0.17;
		previewVector = 0;
	};
	class KitFoundation : Kit
	{
		recipe[] = {{"MortarBucket",4}};
		nearby[] = {{"Workbench", "", "workbench", {1,{"WorkBench_EPOCH"}}, 3, 1, 0, 1}};
		model = "\x\addons\a3_epoch_assets\models\Concrete_Col.p3d";
		previewPosition[] = {0.796787,1,0.211457};
		previewScale = 0.047;
		previewVector = 0;
	};
	class KitWoodFoundation : Kit
	{
		recipe[] = {{"PartPlankPack",8}};
		nearby[] = {{"Workbench", "", "workbench", {1,{"WorkBench_EPOCH"}}, 3, 1, 0, 1}};
		model = "\x\addons\a3_epoch_assets\models\Wood_Col.p3d";
		previewPosition[] = {0.796787,1,0.211457};
		previewScale = 0.047;
		previewVector = 0;
	};

	class KitCinderWall : Kit
	{
		recipe[] = {{"CinderBlocks",2},{"MortarBucket",2}};
		nearby[] = {{"Workbench", "", "workbench", {1,{"WorkBench_EPOCH"}}, 3, 1, 0, 1}};
		model = "\x\addons\a3_epoch_assets\models\cinder_half.p3d";
		previewPosition[] = {0.797638,1,0.341915};
		previewScale = 0.07;
		previewVector = 0;
	};
	class KitPlotPole : Kit
	{
		recipe[] = {{ "ItemCables", 1 }, { "ItemBattery", 1 }, {"ItemCorrugatedLg",2}, {"CircuitParts",2} };
		nearby[] = {{"Workbench", "", "workbench", {1,{"WorkBench_EPOCH"}}, 3, 1, 0, 1}};
		model = "\x\addons\a3_epoch_assets\models\jammer.p3d";
		previewPosition[] = {0.801378,1,0.464834};
		previewScale = 0.055;
		previewVector = 0;
	};

	class ItemSolar : Part
	{
		usedIn[] = { "KitSolarGen" };
		previewPosition[] = {0.802374,1,0.26};
		previewScale = 0.19;
		previewVector = 3.3;

	};
	class ItemCables : Item
	{
		usedIn[] = { "KitSolarGen", "KitPlotPole", "ItemCopperBar" };
		nearby[] = {{"Workbench", "", "workbench", {1,{"WorkBench_EPOCH"}}, 3, 1, 0, 1}};
		// TODO add rubber/plasic
		recipe[] = { { "ItemCopperBar", 1 } };
		previewPosition[] = {0.802374,1,0.26};
		previewScale = 0.3;
		previewVector = 2.8;
	};

	class ItemCopperBar : Item
	{
		usedIn[] = {"ItemCables"};
		nearby[] = {{"Fire", "", "fire", {1,{"ALL"}}, 3, 1, 1, 0}};
		recipe[] = { { "ItemCables", 1 }, {"water_epoch", 1}};
		previewPosition[] = {0.797144,1,0.309158};
		previewScale = 1;
		previewVector = 2.8;
	};

	class ItemGoldBar : Item
	{
		usedIn[] = { "ItemGoldBar10oz" };
		nearby[] = {{"Fire", "", "fire", {1,{"ALL"}}, 3, 1, 1, 0}};
		recipe[] = { { "PartOreGold", 2 }, {"water_epoch", 1} };
		previewPosition[] = {0.797144,1,0.309158};
		previewScale = 1;
		previewVector = 2.8;
	};
	class ItemSilverBar : Item
	{
		usedIn[] = {};
		nearby[] = {{"Fire", "", "fire", {1,{"ALL"}}, 3, 1, 1, 0}};
		recipe[] = { { "PartOreSilver", 2 }, {"water_epoch", 1} };
		previewPosition[] = {0.797144,1,0.309158};
		previewScale = 1;
		previewVector = 2.8;
	};

	class ItemGoldBar10oz : Item
	{
		usedIn[] = {"ItemBriefcaseGold100oz"};
		nearby[] = {{"Fire", "", "fire", {1,{"ALL"}}, 3, 1, 1, 0}};
		recipe[] = { { "ItemGoldBar", 10 }, {"water_epoch", 1}};
		previewPosition[] = {0.797144,1,0.309158};
		previewScale = 1;
		previewVector = 2.8;
	};

	class ItemBriefcaseGold100oz : Item
	{
		usedIn[] = {};
		nearby[] = {};
		recipe[] = { { "ItemGoldBar10oz", 10 }, {"ItemBriefcaseE", 1}};
		previewPosition[] = {0.797144,1,0.309158};
		previewScale = 1;
		previewVector = 2.8;
	};




	class ItemBattery : Item
	{
		usedIn[] = { "KitSolarGen", "KitPlotPole" };
		nearby[] = {{"Workbench", "", "workbench", {1,{"WorkBench_EPOCH"}}, 3, 1, 0, 1}};
		recipe[] = { { "EnergyPackLg", 3 }, { "CircuitParts", 1 } };
		previewPosition[] = {0.802374,1,0.276733};
		previewScale = 0.4;
	};
	class KitSolarGen : Kit
	{
		// TODO recipe
		recipe[] = { { "ItemSolar", 1 }, { "ItemCables", 1 }, { "ItemBattery", 1 }, { "ItemCorrugatedLg", 2 }, { "CircuitParts", 2 } };
		nearby[] = {{"Workbench", "", "workbench", {1,{"WorkBench_EPOCH"}}, 3, 1, 0, 1}};
		model = "\x\addons\a3_epoch_assets_3\CfgVehicles\Solar_Generator_Complete\Solar_generator.p3d";
		previewPosition[] = {0.804979,1,0.39189};
		previewScale = 0.11;
		previewVector = 0;
	};

};
