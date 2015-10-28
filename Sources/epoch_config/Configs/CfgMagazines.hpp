class CfgMagazines
{
	class Default;
	class CA_Magazine;

	class 1Rnd_Soda: CA_Magazine
	{
		picture = "";
		displayName = "Soda";
		scope = 2;
		descriptionShort = "Soda";
		count = 1;
		mass = 1;
		interactAction = 2;
		interactText = "DRINK";
		//Temp,Hunger,Thirst,Energy,Soiled,Immunity,Toxicity,Stamina,Crypto,BloodP
		interactAttributes[] = {0,0,500,0,0,0,0,0,0,0};
	};
	class 1Rnd_Food: CA_Magazine
	{
		picture = "";
		displayName = "Food";
		scope = 2;
		descriptionShort = "Food";
		count = 1;
		mass = 1;
		interactAction = 1;
		interactText = "EAT";
		//Temp,Hunger,Thirst,Energy,Soiled,Immunity,Toxicity,Stamina,Crypto,BloodP
		interactAttributes[] = {0,600,0,0,0,0,0,0,0,0};
	};

	class FAK : CA_Magazine
	{
		scope = 2;
		count = 1;
		type = "256";
		displayName = "$STR_A3_cfgWeapons_FirstAidKit0";
		picture = "\A3\Weapons_F\Items\data\UI\gear_FirstAidKit_CA.paa";
		model = "\A3\Weapons_F\Items\FirstAidkit";
		descriptionShort = "$STR_A3_cfgWeapons_FirstAidKit1";
		mass = 8;
		interactAction = 13;
		interactText = "USE";
	};

	class ItemLockbox: CA_Magazine
	{
		scope = 2;
		count = 1;
		type = 256;
		displayName = "Lockbox";
		model = "\x\addons\a3_epoch_assets_1\models\lockbox_mag.p3d";
		picture = "\x\addons\a3_epoch_assets_1\pictures\equip_lockbox_CA.paa";
		descriptionShort = "Semi secure lockbox";
		mass = 5;
		interactAction = 3;
		interactText = "BUILD";
		buildClass = "LockBox_SIM_EPOCH";
	};
	class ItemSafe : CA_Magazine
	{
		scope = 2;
		count = 1;
		type = 256;
		displayName = "Safe";
		model = "\x\addons\a3_epoch_assets_1\models\safe_onside.p3d";
		picture = "\x\addons\a3_epoch_assets_1\pictures\equip_safe_CA.paa";
		descriptionShort = "Secure Safe";
		mass = 50;
		interactAction = 3;
		interactText = "BUILD";
		buildClass = "Safe_SIM_EPOCH";
	};


	class PartPlankPack: CA_Magazine
	{
		scope = 2;
		count = 1;
		type = 256;
		displayName = "Lumber Pack";
		model = "\x\addons\a3_epoch_assets_1\models\plank_pack.p3d";
		picture = "\x\addons\a3_epoch_assets_1\pictures\equip_lumber_pack_CA.paa";
		descriptionShort = "Lumber in a stack";
		mass = 6;
	};
	class CinderBlocks: CA_Magazine
	{
		scope = 2;
		count = 1;
		type = 256;
		displayName = "Cinder Blocks";
		model = "\x\addons\a3_epoch_assets_1\models\cinder_stack.p3d";
		picture = "\x\addons\a3_epoch_assets_1\pictures\epuip_cinder_blocks_CA.paa";
		descriptionShort = "Stack of nine cinder blocks";
		mass = 75;
	};
	class MortarBucket: CA_Magazine
	{
		scope = 2;
		count = 1;
		type = 256;
		displayName = "Bucket of Mortar";
		model = "\x\addons\a3_epoch_assets_1\models\mortar.p3d";
		picture = "\x\addons\a3_epoch_assets_1\pictures\equip_mortar_CA.paa";
		descriptionShort = "Premixed mastic adhesive that will bond to concrete block.";
		mass = 15;
	};

	class ItemKiloHemp : CA_Magazine {
		scope = 2;
		count = 1;
		displayName = "Kilo of Hemp";
		descriptionShort = "Kilo of Hemp";
		model = "\x\addons\a3_epoch_assets_1\models\kilohemp.p3d";
		picture = "\x\addons\a3_epoch_assets_1\pictures\equip_kilohemp_CA.paa";
		type = 256;
		mass = 1;


	};

	class ItemSodaRbull : 1Rnd_Soda{
		displayName = "Red Gull";
		descriptionShort = "Red Gull Soda";
		model = "\x\addons\a3_epoch_assets_1\models\soda_redbull.p3d";
		picture = "\x\addons\a3_epoch_assets_1\pictures\equip_soda_rbull_CA.paa";
		mass = 1;
		//Temp,Hunger,Thirst,Energy,Soiled,Immunity,Toxicity,Stamina,Crypto,BloodP
		interactAttributes[] = {0,0,1000,0,0,0,0,100,0,0};
	};
	class ItemSodaOrangeSherbet : 1Rnd_Soda{
		displayName = "Orange Sherbet";
		descriptionShort = "Orange Sherbet Soda";
		model = "\x\addons\a3_epoch_assets_1\models\soda_sherbet.p3d";
		picture = "\x\addons\a3_epoch_assets_1\pictures\soda_orangesherbet_ca.paa";
		mass = 1;
		//Temp,Hunger,Thirst,Energy,Soiled,Immunity,Toxicity,Stamina,Crypto,BloodP
		interactAttributes[] = {0,0,800,0,0,0,0,75,0,0};
	};

	class ItemSodaPurple : 1Rnd_Soda{
		displayName = "Purple Nurple";
		descriptionShort = "Purple Nurple Soda";
		model = "\x\addons\a3_epoch_assets_1\models\soda_purple.p3d";
		picture = "\x\addons\a3_epoch_assets_1\pictures\soda_purple_equip_ca.paa";
		mass = 1;
		//Temp,Hunger,Thirst,Energy,Soiled,Immunity,Toxicity,Stamina,Crypto,BloodP
		interactAttributes[] = { 0, 0, 800, 0, 0, 0, 0, 75, 0, 0 };
	};
	class ItemSodaMocha : 1Rnd_Soda{
		displayName = "Mocha Cola";
		descriptionShort = "Mocha Cola Soda";
		model = "\x\addons\a3_epoch_assets_1\models\soda_mocha.p3d";
		picture = "\x\addons\a3_epoch_assets_1\pictures\soda_mocha_equip_ca.paa";
		mass = 1;
		//Temp,Hunger,Thirst,Energy,Soiled,Immunity,Toxicity,Stamina,Crypto,BloodP
		interactAttributes[] = { 0, 0, 650, 0, 0, 0, 0, 150, 0, 0 };
	};
	class ItemSodaBurst : 1Rnd_Soda{
		displayName = "Burst Koke";
		descriptionShort = "Burst Koke Soda";
		model = "\x\addons\a3_epoch_assets_1\models\soda_burst.p3d";
		picture = "\x\addons\a3_epoch_assets_1\pictures\soda_burst_equip_ca.paa";
		mass = 1;
		//Temp,Hunger,Thirst,Energy,Soiled,Immunity,Toxicity,Stamina,Crypto,BloodP
		interactAttributes[] = { 0, 0, 800, 0, 0, 0, 0, 75, 0, 0 };
	};


	class ItemTrout : 1Rnd_Food{
		scope = 2;
		displayName = "Rainbow Trout";
		descriptionShort = "Rainbow Trout: A small fish that can be fairly easy to catch.";
		model = "\x\addons\a3_epoch_assets_1\models\trout.p3d";
		picture = "\x\addons\a3_epoch_assets_1\pictures\equip_rainbowtrout_CA.paa";
		mass = 5;
		//Temp,Hunger,Thirst,Energy,Soiled,Immunity,Toxicity,Stamina,Crypto,BloodP
		interactAttributes[] = { 0, 300, 0, 0, 0, 0, 5, 0, 0, 0 };
	};
	class ItemSeaBass : 1Rnd_Food{
		scope = 2;
		displayName = "Sea Bass";
		descriptionShort = "Sea Bass: A medium sized fish that is fairly rare.";
		model = "\x\addons\a3_epoch_assets_1\models\seabass.p3d";
		picture = "\x\addons\a3_epoch_assets_1\pictures\equip_seabass_CA.paa";
		mass = 10;
		//Temp,Hunger,Thirst,Energy,Soiled,Immunity,Toxicity,Stamina,Crypto,BloodP
		interactAttributes[] = { 0, 500, 0, 0, 0, 0, 10, 0, 0, 0 };
	};
	class ItemTuna : 1Rnd_Food{
		scope = 2;
		displayName = "Blue Fin Tuna";
		descriptionShort = "Blue Fin Tuna: A very large and hard to catch fish. Sushi anyone?";
		model = "\x\addons\a3_epoch_assets_1\models\tuna.p3d";
		picture = "\x\addons\a3_epoch_assets_1\pictures\equip_tuna_CA.paa";
		mass = 50;
		//Temp,Hunger,Thirst,Energy,Soiled,Immunity,Toxicity,Stamina,Crypto,BloodP
		interactAttributes[] = { 0, 2500, 0, 0, 0, 0, 0, 0, 0, 0 };
	};
	class ItemTroutCooked : 1Rnd_Food{
		scope = 2;
		displayName = "Rainbow Trout (Cooked)";
		descriptionShort = "Rainbow Trout: A small fish that can be fairly easy to catch.";
		model = "\x\addons\a3_epoch_assets_1\models\trout_cooked.p3d";
		picture = "\x\addons\a3_epoch_assets_1\pictures\equip_trout_cooked_CA.paa";
		mass = 5;
		//Temp,Hunger,Thirst,Energy,Soiled,Immunity,Toxicity,Stamina,Crypto,BloodP
		interactAttributes[] = { 0, 600, 0, 0, 0, 0, 0, 0, 0, 0 };
	};
	class ItemSeaBassCooked : 1Rnd_Food{
		scope = 2;
		displayName = "Sea Bass (Cooked)";
		descriptionShort = "Sea Bass: A medium sized fish that is fairly rare.";
		model = "\x\addons\a3_epoch_assets_1\models\seabass_cooked.p3d";
		picture = "\x\addons\a3_epoch_assets_1\pictures\equip_seabass_cooked_CA.paa";
		mass = 10;
		//Temp,Hunger,Thirst,Energy,Soiled,Immunity,Toxicity,Stamina,Crypto,BloodP
		interactAttributes[] = { 0, 1200, 0, 0, 0, 0, 0, 0, 0, 0 };
	};
	class ItemTunaCooked : 1Rnd_Food{
		scope = 2;
		displayName = "Blue Fin Tuna (Cooked)";
		descriptionShort = "Blue Fin Tuna: A very large and hard to catch fish. Sushi anyone?";
		model = "\x\addons\a3_epoch_assets_1\models\tuna_cooked.p3d";
		picture = "\x\addons\a3_epoch_assets_1\pictures\equip_tuna_cooked_CA.paa";
		mass = 50;
		//Temp,Hunger,Thirst,Energy,Soiled,Immunity,Toxicity,Stamina,Crypto,BloodP
		interactAttributes[] = { 0, 5000, 0, 0, 0, 0, 0, 0, 0, 0 };
	};

	class FoodBioMeat : 1Rnd_Food{
		scope = 2;
		displayName = "Bio Meat";
		model = "\x\addons\a3_epoch_assets_1\models\biomeat_can.p3d";
		picture = "\x\addons\a3_epoch_assets_1\pictures\equip_biomeat_CA.paa";
		descriptionShort = "Bio Meat: A very good source of nutrition, and a very high chance of infection. Eat at own risk.";
		//Temp,Hunger,Thirst,Energy,Soiled,Immunity,Toxicity,Stamina,Crypto,BloodP
		interactAttributes[] = {0,1000,0,0,0,0,7,0,0,0};
	};

	class FoodMeeps : 1Rnd_Food{
		scope = 2;
		displayName = "Meeps Candy";
		model = "\x\addons\a3_epoch_assets\models\meeps.p3d";
		picture = "\x\addons\a3_epoch_assets\textures\candy\equip_meeps_ca.paa";
		descriptionShort = "Pumpkin marshmallow candy";
		//Temp,Hunger,Thirst,Energy,Soiled,Immunity,Toxicity,Stamina,Crypto,BloodP
		interactAttributes[] = {0,500,0,0,0,0,0,0,0,0};
	};
	class FoodSnooter : 1Rnd_Food{
		scope = 2;
		displayName = "Snooters Candy";
		model = "\x\addons\a3_epoch_assets\models\snooter.p3d";
		picture = "\x\addons\a3_epoch_assets\textures\candy\equip_snooters_ca.paa";
		descriptionShort = "Not hungry? grab a Snooters";
		//Temp,Hunger,Thirst,Energy,Soiled,Immunity,Toxicity,Stamina,Crypto,BloodP
		interactAttributes[] = {0,500,0,0,0,0,0,50,0,0};
	};
	class FoodWalkNSons : 1Rnd_Soda{
		scope = 2;
		displayName = "Walk N' Sons Soda";
		model = "\x\addons\a3_epoch_assets\models\walkinson.p3d";
		picture = "\x\addons\a3_epoch_assets\textures\candy\equip_walkinson_ca.paa";
		descriptionShort = "Stuck walkin' grab a Walk N' Sons Soda";
		//Temp,Hunger,Thirst,Energy,Soiled,Immunity,Toxicity,Stamina,Crypto,BloodP
		interactAttributes[] = {0,0,1200,0,0,0,0,150,0,0};
	};

	class ItemTopaz : CA_Magazine {
		scope = 2;
		displayName = "Topaz";
		model = "\x\addons\a3_epoch_assets_1\models\topaz.p3d";
		picture = "\x\addons\a3_epoch_assets_1\pictures\equip_topaz_CA.paa";
		count = 1;
		type = "256";
		descriptionShort = "Topaz";
		mass = 1;
	};
	class ItemOnyx : CA_Magazine {
		scope = 2;
		displayName = "Onyx";
		model = "\x\addons\a3_epoch_assets_1\models\obsidian.p3d";
		picture = "\x\addons\a3_epoch_assets_1\pictures\equip_obsidian_CA.paa";
		count = 1;
		type = "256";
		descriptionShort = "Onyx";
		mass = 1;
	};
	class ItemSapphire : CA_Magazine {
		scope = 2;
		displayName = "Sapphire";
		model = "\x\addons\a3_epoch_assets_1\models\sapphire.p3d";
		picture = "\x\addons\a3_epoch_assets_1\pictures\equip_sapphire_CA.paa";
		count = 1;
		type = "256";
		descriptionShort = "Sapphire";
		mass = 1;
	};
	class ItemAmethyst : CA_Magazine {
		scope = 2;
		displayName = "Amethyst";
		model = "\x\addons\a3_epoch_assets_1\models\amethyst.p3d";
		picture = "\x\addons\a3_epoch_assets_1\pictures\equip_amethyst_CA.paa";
		count = 1;
		type = "256";
		descriptionShort = "Amethyst";
		mass = 1;
	};
	class ItemEmerald : CA_Magazine {
		scope = 2;
		displayName = "Emerald";
		model = "\x\addons\a3_epoch_assets_1\models\emerald.p3d";
		picture = "\x\addons\a3_epoch_assets_1\pictures\equip_emerald_CA.paa";
		count = 1;
		type = "256";
		descriptionShort = "Emerald";
		mass = 1;
	};
	class ItemCitrine : CA_Magazine {
		scope = 2;
		displayName = "Citrine";
		model = "\x\addons\a3_epoch_assets_1\models\citrine.p3d";
		picture = "\x\addons\a3_epoch_assets_1\pictures\equip_citrine_CA.paa";
		count = 1;
		type = "256";
		descriptionShort = "Citrine";
		mass = 1;
	};
	class ItemRuby : CA_Magazine {
		scope = 2;
		displayName = "Ruby";
		model = "\x\addons\a3_epoch_assets_1\models\ruby.p3d";
		picture = "\x\addons\a3_epoch_assets_1\pictures\equip_ruby_CA.paa";
		count = 1;
		type = "256";
		descriptionShort = "Ruby";
		mass = 1;
	};
	class ItemQuartz : CA_Magazine {
		scope = 2;
		displayName = "Quartz";
		model = "\x\addons\a3_epoch_assets\models\quartz.p3d";
		picture = "\x\addons\a3_epoch_assets\textures\gem\equip_quartz_CA.paa";
		count = 1;
		type = "256";
		descriptionShort = "Quartz";
		mass = 1;
	};
	class ItemJade : CA_Magazine {
		scope = 2;
		displayName = "Jade";
		model = "\x\addons\a3_epoch_assets\models\jade.p3d";
		picture = "\x\addons\a3_epoch_assets\textures\gem\equip_jade_CA.paa";
		count = 1;
		type = "256";
		descriptionShort = "Jade";
		mass = 1;
	};
	class ItemGarnet : CA_Magazine {
		scope = 2;
		displayName = "Garnet";
		model = "\x\addons\a3_epoch_assets\models\garnet.p3d";
		picture = "\x\addons\a3_epoch_assets\textures\gem\equip_garnet_CA.paa";
		count = 1;
		type = "256";
		descriptionShort = "Garnet";
		mass = 1;
	};
	class JackKit : CA_Magazine
	{
		model = "\x\addons\a3_epoch_assets\models\jack.p3d";
		picture = "\x\addons\a3_epoch_assets\textures\kits\equip_jack_ca.paa";
		displayName = "Jack";
		scope = 2;
		descriptionShort = "Jack";
		count = 1;
		mass = 20;
		interactAction = 3; // 0 = examine, 1 = eat, 2 = drink, 3 = build
		interactText = "BUILD";
		buildClass = "Jack_SIM_EPOCH";
		isTemp = 1;
	};
	class TacticalBacon : CA_Magazine
	{
		author = "$STR_A3_Bohemia_Interactive";
		scope = 2;
		displayName = "$STR_A3_cfgVehicles_Land_TacticalBacon_F0";
		model = "\A3\Structures_F\Items\Food\TacticalBacon_F.p3d";
		picture = "\x\addons\a3_epoch_assets_3\CfgMagazines\Bacon\equip_TacticalBacon_ca.paa";
		count = 1;
		type = "256";
		descriptionShort = "Contains: mmm... Bacon!";
		mass = 1;
		interactAction = 1;
		interactText = "EAT";
		interactAttributes[] = { 0, 500, 0, 0, 0, 0, 0, 0, 0, 0 };
	};
	class ItemCoolerE : CA_Magazine {
		scope = 2;
		displayName = "Food Cooler (empty)";
		model = "\x\addons\a3_epoch_assets\models\cooler.p3d";
		picture = "\x\addons\a3_epoch_assets\textures\cooler\gear_cooler_ca.paa";
		count = 1;
		type = "256";
		descriptionShort = "Seal-a-Meal, its cold in here.";
		mass = 1;
	};
	class ItemCooler0 : CA_Magazine {
		scope = 2;
		displayName = "Food Cooler";
		model = "\x\addons\a3_epoch_assets\models\cooler.p3d";
		picture = "\x\addons\a3_epoch_assets\textures\cooler\gear_cooler_ca.paa";
		count = 1;
		type = "256";
		descriptionShort = "Contains: Cooked Snake Meat";
		mass = 1;
		interactReturnOnUse = "ItemCoolerE";
		interactAction = 1;
		interactText = "EAT";
		interactAttributes[] = { 0, 5000, 0, 0, 0, 0, 0, 0, 0, 0 };
	};
	class ItemCooler1 : CA_Magazine {
		scope = 2;
		displayName = "Food Cooler";
		model = "\x\addons\a3_epoch_assets\models\cooler.p3d";
		picture = "\x\addons\a3_epoch_assets\textures\cooler\gear_cooler_ca.paa";
		count = 1;
		type = "256";
		descriptionShort = "Contains: Cooked Rabbit Meat";
		mass = 1;
		interactReturnOnUse = "ItemCoolerE";
		interactAction = 1;
		interactText = "EAT";
		interactAttributes[] = { 0, 5000, 0, 0, 0, 0, 0, 0, 0, 0 };
	};
	class ItemCooler2 : CA_Magazine {
		scope = 2;
		displayName = "Food Cooler";
		model = "\x\addons\a3_epoch_assets\models\cooler.p3d";
		picture = "\x\addons\a3_epoch_assets\textures\cooler\gear_cooler_ca.paa";
		count = 1;
		type = "256";
		descriptionShort = "Contains: Cooked Chicken";
		mass = 1;
		interactReturnOnUse = "ItemCoolerE";
		interactAction = 1;
		interactText = "EAT";
		interactAttributes[] = { 0, 5000, 0, 0, 0, 0, 0, 0, 0, 0 };
	};
	class ItemCooler3 : CA_Magazine {
		scope = 2;
		displayName = "Food Cooler";
		model = "\x\addons\a3_epoch_assets\models\cooler.p3d";
		picture = "\x\addons\a3_epoch_assets\textures\cooler\gear_cooler_ca.paa";
		count = 1;
		type = "256";
		descriptionShort = "Contains: Cooked Goat Leg";
		mass = 1;
		interactReturnOnUse = "ItemCoolerE";
		interactAction = 1;
		interactText = "EAT";
		interactAttributes[] = { 0, 5000, 0, 0, 0, 0, 0, 0, 0, 0 };
	};
	class ItemCooler4 : CA_Magazine {
		scope = 2;
		displayName = "Food Cooler";
		model = "\x\addons\a3_epoch_assets\models\cooler.p3d";
		picture = "\x\addons\a3_epoch_assets\textures\cooler\gear_cooler_ca.paa";
		count = 1;
		type = "256";
		descriptionShort = "Contains: Cooked Sheep Leg";
		mass = 1;
		interactReturnOnUse = "ItemCoolerE";
		interactAction = 1;
		interactText = "EAT";
		//Temp,Hunger,Thirst,Energy,Soiled,Immunity,Toxicity,Stamina,Crypto,BloodP
		interactAttributes[] = { 0, 5000, 0, 0, 0, 0, 0, 0, 0, 0 };
	};


	class ItemMixOil : CA_Magazine {
		scope = 2;
		displayName = "2-Stroke Engine Oil";
		model = "\x\addons\a3_epoch_assets_1\models\oilmix.p3d";
		picture = "\x\addons\a3_epoch_assets_1\pictures\equip_oilmix_CA.paa";
		count = 1;
		type = "256";
		descriptionShort = "2-Stroke Engine Oil";
		mass = 1;
	};

	// Documents
	class ItemDocument: CA_Magazine {
		scope = 2;
		count = 1;
		type = 256;
		displayName = "Document";
		model = "\x\addons\a3_epoch_assets_1\models\doc_generic.p3d";
		picture = "\x\addons\a3_epoch_assets_1\pictures\equip_doc_generic_ca.paa";
		descriptionShort = "Unknown document";
		mass = 1;
	};

	class ItemDocumentMission: CA_Magazine
	{
		scope = 2;
		count = 1;
		type = 256;
		displayName = "Mission Document";
		model = "\x\addons\a3_epoch_assets_1\models\doc_generic.p3d";
		picture = "\x\addons\a3_epoch_assets_1\pictures\equip_doc_generic_ca.paa";
		descriptionShort = "A very important message, Eyes Only !";
		mass = 1;
	};

	class ItemSilverBar: CA_Magazine {
		scope = 2;
		count = 1;
		worth = 1;
		type = 256;
		displayName = "Silver";
		model = "\x\addons\a3_epoch_assets_1\models\ItemSilverBar1oz.p3d";
		picture = "\x\addons\a3_epoch_assets_1\pictures\equip_silver_bar_CA.paa";
		descriptionShort = "Silver Bar";
		mass = 1;
	};

	class ItemGoldBar: CA_Magazine {
		scope = 2;
		count = 1;
		worth = 100;
		type = 256;
		displayName = "Gold";
		model = "\x\addons\a3_epoch_assets_1\models\ItemGoldBar1oz.p3d";
		picture = "\x\addons\a3_epoch_assets_1\pictures\equip_gold_bar_CA.paa";
		descriptionShort = "Gold Bar";
		mass = 1;
	};
	class ItemGoldBar10oz: CA_Magazine {
		scope = 2;
		count = 1;
		worth = 1000;
		type = 256;
		displayName = "10oz Gold";
		model = "\x\addons\a3_epoch_assets_1\models\ItemGoldBar10oz.p3d";
		picture = "\x\addons\a3_epoch_assets_1\pictures\equip_gold_bar_10oz_CA.paa";
		descriptionShort = "10 x 1oz Gold Bar";
		mass = 10;
	};
	class ItemRock : CA_Magazine {
		scope = 2;
		count = 1;
		type = 256;
		displayName = "Rock";
		model = "\x\addons\a3_epoch_assets\models\rock.p3d";
		picture = "\x\addons\a3_epoch_assets\textures\improv_weapon\gear_rock_ca.paa";
		descriptionShort = "Used for crafting fireplaces and mortar. Can be mined from rocks using a sledgehammer.";
		mass = 1;
	};
	class ItemStick : CA_Magazine {
		scope = 2;
		count = 1;
		type = 256;
		displayName = "Stick";
		model = "\x\addons\a3_epoch_assets\models\stick.p3d";
		picture = "\x\addons\a3_epoch_assets\textures\improv_weapon\gear_stick_ca.paa";
		descriptionShort = "Used for crafting.";
		mass = 1;
	};
	class ItemRope : CA_Magazine {
		scope = 2;
		count = 1;
		type = 256;
		displayName = "Rope";
		model = "\x\addons\a3_epoch_assets\models\rope.p3d";
		picture = "\x\addons\a3_epoch_assets\textures\improv_weapon\gear_rope_ca.paa";
		descriptionShort = "Used for crafting.";
		mass = 1;
	};
	class PartOre: CA_Magazine {
		scope = 2;
		count = 1;
		type = 256;
		displayName = "Iron Ore";
		model = "\x\addons\a3_epoch_assets\models\ore.p3d";
		picture="\x\addons\a3_epoch_assets_1\pictures\equip_iron_ore_CA.paa";
		descriptionShort = "Used for crafting scrap metal. Can be mined from rocks using a sledgehammer.";
		mass = 1;
	};
	class PartOreSilver: CA_Magazine {
		scope = 2;
		count = 1;
		type = 256;
		displayName = "Silver Ore";
		model = "\x\addons\a3_epoch_assets\models\oreSilver.p3d";
		picture="\x\addons\a3_epoch_assets_1\pictures\equip_silver_ore_CA.paa";
		descriptionShort = "Can be mined from rocks using a sledgehammer.";
		mass = 1;
	};
	class PartOreGold: CA_Magazine {
		scope = 2;
		count = 1;
		type = 256;
		displayName = "Gold Ore";
		model = "\x\addons\a3_epoch_assets\models\oreGold.p3d";
		picture="\x\addons\a3_epoch_assets_1\pictures\equip_gold_ore_CA.paa";
		descriptionShort = "Can be mined from rocks using a sledgehammer.";
		mass = 1;
	};

	// TODO make use of this for backpacks
	class ItemPacked : CA_Magazine
	{
		scope = 2;
		count = 1;
		type = 256;
		displayName = "Packed Backpack";
		model = "\x\addons\a3_epoch_assets\models\PackedBag.p3d";
		picture = "\x\addons\a3_epoch_assets\textures\backpack\gear_packedBag_ca.paa";
		descriptionShort = "Brand new backpack still in the package";
		mass = 1.5;
	};

	class ItemSolar : CA_Magazine
	{
		scope = 2;
		count = 1;
		type = 256;
		displayName = "Solar Panels";
		model = "\x\addons\a3_epoch_assets_3\CfgVehicles\solar_gen_assets\Solar_panels\Solar_Panels.p3d";
		picture = "\x\addons\a3_epoch_assets_3\CfgVehicles\solar_gen_assets\Solar_panels\Solar_Panels_Icon_CA.paa";
		descriptionShort = "Next gen solar panels";
		mass = 10;
	};
	class ItemCables : CA_Magazine
	{
		scope = 2;
		count = 1;
		type = 256;
		displayName = "Wire Cables";
		model = "\x\addons\a3_epoch_assets_3\CfgVehicles\solar_gen_assets\Cables\Solar_cables.p3d";
		picture = "\x\addons\a3_epoch_assets_3\CfgVehicles\solar_gen_assets\Cables\Solar_Cable_Icon_CA.paa";
		descriptionShort = "Copper wire isulated with rubber.";
		mass = 10;
	};
	class ItemBattery : CA_Magazine
	{
		scope = 2;
		count = 1;
		type = 256;
		displayName = "Enclosed Battery";
		model = "\x\addons\a3_epoch_assets_3\CfgVehicles\solar_gen_assets\Battery\Battery.p3d";
		picture = "\x\addons\a3_epoch_assets_3\CfgVehicles\solar_gen_assets\Battery\Battery_box_Icon_CA.paa";
		descriptionShort = "Battery in a protective case.";
		mass = 10;
	};

	class ItemScraps : CA_Magazine
	{
		scope = 2;
		count = 1;
		type = 256;
		displayName = "Metal Scraps";
		model = "\x\addons\a3_epoch_assets\models\scraps.p3d";
		picture = "\x\addons\a3_epoch_assets\textures\scraps\gear_scraps_ca.paa";
		descriptionShort = "Piece of metal scrap";
		mass = 1.5;
	};

	class ItemCorrugated : CA_Magazine
	{
		scope = 2;
		count = 1;
		type = 256;
		displayName = "Salvage Metal (Small)";
		model = "\x\addons\a3_epoch_assets\models\salvage_small.p3d";
		picture = "\x\addons\a3_epoch_assets\textures\salvage\equip_salvage_small_ca.paa";
		descriptionShort = "Small pile of assorted metal parts";
		mass = 5;
	};
	class ItemCorrugatedLg : CA_Magazine
	{
		scope = 2;
		count = 1;
		type = 256;
		displayName = "Salvage Metal (Large)";
		model = "\x\addons\a3_epoch_assets\models\salvage_large.p3d";
		picture = "\x\addons\a3_epoch_assets\textures\salvage\equip_salvage_large_ca.paa";
		descriptionShort = "Large pile of assorted metal parts";
		mass = 12;
	};
	class 30Rnd_test_mag: CA_Magazine
	{
		scope = 2;
		displayName = "Test magazine";
		picture = "\A3\Weapons_F\Data\placeholder_co.paa";
		ammo = "B_Test_Caseless";
		count = 30;
		initSpeed = 795;
		tracersEvery = 0;
		lastRoundsTracer = 4;
		descriptionShort = "Used to shoot test bullets";
	};

	class 5Rnd_rollins_mag : CA_Magazine
	{
		scope = 2;
		displayName = "Rollins magazine";
		picture = "\x\addons\a3_epoch_assets\textures\rol_rounds\equip_Rol_rounds_ca.paa";
		model = "\x\addons\a3_epoch_assets\models\rol_rounds.p3d";
		ammo = "B_Test_Caseless";
		count = 5;
		initSpeed = 795;
		tracersEvery = 0;
		lastRoundsTracer = 4;
		descriptionShort = "Rollins 5Rnd Magazine";
		mass = 3;
	};

	class CSGAS: CA_Magazine
	{
		scope = 2;
		displayName = "Chainsaw Gas";
		picture = "\x\addons\a3_epoch_assets\textures\kits\gear_jerryMixed_ca.paa";
		ammo = "ChainSaw_Bullet";
		count = 1000;
		initSpeed = 100;
		tracersEvery = 0;
		lastRoundsTracer = 9999;
		descriptionShort = "Chainsaw Gas";
		mass = 5;
	};
	class sledge_swing: CA_Magazine
	{
		scope = 2;
		displayName = "Swing";
		picture = "\x\addons\a3_epoch_assets\textures\kits\equip_swing_ca.paa";
		ammo = "B_Swing";
		count = 1000;
		initSpeed = 275;
		tracersEvery = 0;
		lastRoundsTracer = 9999;
		descriptionShort = "Swing";
		mass = 0;
	};
	class stick_swing : CA_Magazine
	{
		scope = 2;
		displayName = "Swing";
		picture = "\x\addons\a3_epoch_assets\textures\kits\equip_swing_ca.paa";
		ammo = "B_Stick";
		count = 1000;
		initSpeed = 275;
		tracersEvery = 0;
		lastRoundsTracer = 9999;
		descriptionShort = "Swing";
		mass = 0;
	};
	class hatchet_swing : CA_Magazine
	{
		scope = 2;
		displayName = "Swing";
		picture = "\x\addons\a3_epoch_assets\textures\kits\equip_swing_ca.paa";
		ammo = "B_Hatchet";
		count = 1000;
		initSpeed = 100;
		tracersEvery = 0;
		lastRoundsTracer = 9999;
		descriptionShort = "Swing";
		mass = 0;
	};
	class 30Rnd_test_mag_Tracer: 30Rnd_test_mag
	{
		tracersEvery = 1;
		lastRoundsTracer = 30;
		displayName = "Test tracer magazine";
		descriptionShort = "Used to shoot test tracer bullets";
		displaynameshort = "Tracers";
	};
	class EnergyPack: CA_Magazine
	{
		picture = "\A3\Weapons_F\Data\UI\M_battery_CA.paa";
		displayName = "Small energy pack";
		scope = 2;
		ammo = "B_EnergyPack";
		sound[] = {"A3\sounds_f\dummysound",31.622776,1,1600};
		reloadMagazineSound[] = {"A3\sounds_f\dummysound",0.01,1,10};
		descriptionShort = "Two part container filled with enough energy and matter for one use";
		initSpeed = 420;
		count = 10;
		mass = 4;
		interactAction = 9;
		interactText = "USE";
		//Temp,Hunger,Thirst,Energy,Soiled,Immunity,Toxicity,Stamina,Crypto,BloodP
		interactAttributes[] = {0,0,0,100,0,0,0,0,0,0};
	};
	class EnergyPackLg : CA_Magazine
	{
		picture = "\A3\Weapons_F\Data\UI\M_battery_CA.paa";
		displayName = "Large energy pack";
		scope = 2;
		ammo = "B_EnergyPack";
		sound[] = { "A3\sounds_f\dummysound", 31.622776, 1, 1600 };
		reloadMagazineSound[] = { "A3\sounds_f\dummysound", 0.01, 1, 10 };
		descriptionShort = "Large two part container filled with enough energy and matter 10 uses";
		initSpeed = 420;
		count = 100;
		mass = 40;
		interactAction = 9;
		interactText = "USE";
		//Temp,Hunger,Thirst,Energy,Soiled,Immunity,Toxicity,Stamina,Crypto,BloodP
		interactAttributes[] = {0,0,0,1000,0,0,0,0,0,0};
	};

	class WoodLog_EPOCH: CA_Magazine
	{
		picture = "\x\addons\a3_epoch_assets\textures\kits\equip_woodenLog_ca.paa";
		model = "x\addons\a3_epoch_assets_3\cfgmagazines\log\SteamLogs.p3d";
		displayName = "$STR_A3_wooden_log";
		scope = 2;
		descriptionShort = "$STR_A3_wooden_log";
		count = 1;
		mass = 10;
	};
	class WhiskeyNoodle : CA_Magazine
	{
		displayName = "Whisky Noodle";
		picture = "\x\addons\a3_epoch_assets\textures\whiskeynoodle\equip_whiskeyNoodle_ca.paa";
		model = "\x\addons\a3_epoch_assets\models\whiskeynoodle.p3d";
		scope = 2;
		descriptionShort = "Say it slow, Drink it fast..";
		count = 1;
		mass = 1;
		interactAction = 2;
		interactText = "DRINK";
		//Temp,Hunger,Thirst,Energy,Soiled,Immunity,Toxicity,Stamina,Crypto,BloodP
		interactAttributes[] = {0,0,800,0,0,0,-5,50,0,20};
	};

	class CircuitParts : CA_Magazine
	{
		displayName = "Electronic components";
		picture = "\x\addons\a3_epoch_assets\textures\circuit\equip_circuit_ca.paa";
		model = "\x\addons\a3_epoch_assets\models\circuit.p3d";
		scope = 2;
		descriptionShort = "Electronic components";
		count = 1;
		mass = 5;
	};

	class VehicleRepair : CA_Magazine
	{
		displayName = "Vehicle Repair Parts";
		picture = "\x\addons\a3_epoch_assets\textures\vehiclerepair\equip_vehicleRepair_ca.paa";
		model = "\x\addons\a3_epoch_assets\models\vehicleRepair.p3d";
		scope = 2;
		descriptionShort = "Repairs the most damaged part";
		count = 1;
		mass = 20;
		interactAction = 10;
		interactText = "USE";
	};
	class VehicleRepairLg : CA_Magazine
	{
		displayName = "Vehicle Repair Kit";
		picture = "\x\addons\a3_epoch_assets\textures\vehiclerepair\equip_vehicleRepairLg_ca.paa";
		model = "\x\addons\a3_epoch_assets\models\vehicleRepairLg.p3d";
		scope = 2;
		descriptionShort = "Fully repairs any vehicle";
		count = 1;
		mass = 50;
		interactAction = 11;
		interactText = "USE";
	};
	class Pelt_EPOCH : CA_Magazine
	{
		picture = "\x\addons\a3_epoch_assets\textures\meat\equip_scrapHide_ca.paa";
		model = "\x\addons\a3_epoch_assets\models\scrapHide.p3d";
		displayName = "Scrap Pelt";
		scope = 2;
		descriptionShort = "Scrap Pelt";
		count = 1;
		mass = 5;
	};

	class Venom_EPOCH : CA_Magazine
	{
		picture = "\x\addons\a3_epoch_assets\textures\meat\equip_venomSac_ca.paa";
		model = "\x\addons\a3_epoch_assets\models\venomSac.p3d";
		displayName = "Venom Sack";
		scope = 2;
		descriptionShort = "Venom Sack";
		count = 1;
		mass = 1;
		interactAction = 1;
		interactText = "EAT";
		//Temp,Hunger,Thirst,Energy,Soiled,Immunity,Toxicity,Stamina,Crypto,BloodP
		interactAttributes[] = {0,0,0,0,0,0,20,0,0,0};
	};
	class SnakeCarcass_EPOCH : CA_Magazine
	{
		picture = "\x\addons\a3_epoch_assets\textures\meat\equip_snakeCorpse_ca.paa";
		model = "\x\addons\a3_epoch_assets\models\snakeCorpse.p3d";
		displayName = "Snake Carcass";
		scope = 2;
		descriptionShort = "Gutted and cleaned";
		count = 1;
		mass = 5;
		interactAction = 1;
		interactText = "EAT";
		//Temp,Hunger,Thirst,Energy,Soiled,Immunity,Toxicity,Stamina,Crypto,BloodP
		interactAttributes[] = { 0, 300, 0, 0, 0, 0, 10, 0, 0, 0 };
	};
	/*
	class SnakeMeatRaw_EPOCH : CA_Magazine
	{
		picture = "\x\addons\a3_epoch_assets\textures\meat\equip_snakeMeat_ca.paa";
		model = "\x\addons\a3_epoch_assets\models\snakeMeat.p3d";
		displayName = "Raw Snake Meat";
		scope = 2;
		descriptionShort = "Gutted and cleaned";
		count = 1;
		mass = 5;
	};
	*/
	class SnakeMeat_EPOCH : CA_Magazine
	{
		picture = "\x\addons\a3_epoch_assets\textures\meat\equip_snakemeatCooked_ca.paa";
		model = "\x\addons\a3_epoch_assets\models\snakeMeat_cooked.p3d";
		displayName = "Cooked Snake Meat";
		scope = 2;
		descriptionShort = "Tastes like chicken.";
		count = 1;
		mass = 5;
		interactAction = 1;
		interactText = "EAT";
		//Temp,Hunger,Thirst,Energy,Soiled,Immunity,Toxicity,Stamina,Crypto,BloodP
		interactAttributes[] = {0,1200,0,0,0,0,0,0,0,0};
	};
	class RabbitCarcass_EPOCH : CA_Magazine
	{
		picture = "\x\addons\a3_epoch_assets\textures\meat\equip_rabbitCorpse_ca.paa";
		model = "\x\addons\a3_epoch_assets\models\rabbit.p3d";
		displayName = "Rabbit Carcass";
		scope = 2;
		descriptionShort = "Gutted and cleaned";
		count = 1;
		mass = 5;
		interactAction = 1;
		interactText = "EAT";
		//Temp,Hunger,Thirst,Energy,Soiled,Immunity,Toxicity,Stamina,Crypto,BloodP
		interactAttributes[] = { 0, 300, 0, 0, 0, 0, 10, 0, 0, 0 };
	};
	class CookedRabbit_EPOCH : CA_Magazine
	{
		picture = "\x\addons\a3_epoch_assets\textures\meat\equip_rabbitCooked_ca.paa";
		model = "\x\addons\a3_epoch_assets\models\rabbit_cooked.p3d";
		displayName = "Cooked Rabbit";
		scope = 2;
		descriptionShort = "Mmm Tasty!";
		count = 1;
		mass = 5;
		interactAction = 1;
		interactText = "EAT";
		//Temp,Hunger,Thirst,Energy,Soiled,Immunity,Toxicity,Stamina,Crypto,BloodP
		interactAttributes[] = {0,1200,0,0,0,0,0,0,0,0};
	};
	class ChickenCarcass_EPOCH : CA_Magazine
	{
		picture = "\x\addons\a3_epoch_assets\textures\meat\equip_chickenRaw_ca.paa";
		model = "\x\addons\a3_epoch_assets\models\chickenRaw.p3d";
		displayName = "Chicken Carcass";
		scope = 2;
		descriptionShort = "Gutted and cleaned";
		count = 1;
		mass = 10;
		interactAction = 1;
		interactText = "EAT";
		//Temp,Hunger,Thirst,Energy,Soiled,Immunity,Toxicity,Stamina,Crypto,BloodP
		interactAttributes[] = { 0, 500, 0, 0, 0, 0, 25, 0, 0, 0 };
	};
	class CookedChicken_EPOCH : CA_Magazine
	{
		picture = "\x\addons\a3_epoch_assets\textures\meat\equip_chickenCooked_ca.paa";
		model = "\x\addons\a3_epoch_assets\models\chicken_cooked.p3d";
		displayName = "Cooked Chicken";
		scope = 2;
		descriptionShort = "Roasted to perfection!";
		count = 1;
		mass = 10;
		interactAction = 1;
		interactText = "EAT";
		//Temp,Hunger,Thirst,Energy,Soiled,Immunity,Toxicity,Stamina,Crypto,BloodP
		interactAttributes[] = {0,2000,0,0,0,0,0,0,0,0};
	};
	class GoatCarcass_EPOCH : CA_Magazine
	{
		picture = "\x\addons\a3_epoch_assets\textures\meat\equip_goatLeg_ca.paa";
		model = "\x\addons\a3_epoch_assets\models\goatLeg.p3d";
		displayName = "Raw Goat Leg";
		scope = 2;
		descriptionShort = "Raw Goat Leg";
		count = 1;
		mass = 20;
		interactAction = 1;
		interactText = "EAT";
		//Temp,Hunger,Thirst,Energy,Soiled,Immunity,Toxicity,Stamina,Crypto,BloodP
		interactAttributes[] = { 0, 500, 0, 0, 0, 0, 15, 0, 0, 0 };
	};
	class CookedGoat_EPOCH : CA_Magazine
	{
		picture = "\x\addons\a3_epoch_assets\textures\meat\equip_goatlegCooked_ca.paa";
		model = "\x\addons\a3_epoch_assets\models\goatLeg_cooked.p3d";
		displayName = "Cooked Goat Leg";
		scope = 2;
		descriptionShort = "Cooked Goat Leg";
		count = 1;
		mass = 20;
		interactAction = 1;
		interactText = "EAT";
		//Temp,Hunger,Thirst,Energy,Soiled,Immunity,Toxicity,Stamina,Crypto,BloodP
		interactAttributes[] = {0,3000,0,0,0,0,0,0,0,0};
	};
	class SheepCarcass_EPOCH : CA_Magazine
	{
		picture = "\x\addons\a3_epoch_assets\textures\meat\equip_goatLeg_ca.paa";
		model = "\x\addons\a3_epoch_assets\models\goatLeg.p3d";
		displayName = "Raw Sheep Leg";
		scope = 2;
		descriptionShort = "Raw Sheep Leg";
		count = 1;
		mass = 20;
		interactAction = 1;
		interactText = "EAT";
		//Temp,Hunger,Thirst,Energy,Soiled,Immunity,Toxicity,Stamina,Crypto,BloodP
		interactAttributes[] = { 0, 500, 0, 0, 0, 0, 15, 0, 0, 0 };
	};
	class CookedSheep_EPOCH : CA_Magazine
	{
		picture = "\x\addons\a3_epoch_assets\textures\meat\equip_goatlegCooked_ca.paa";
		model = "\x\addons\a3_epoch_assets\models\goatLeg_cooked.p3d";
		displayName = "Cooked Sheep Leg";
		scope = 2;
		descriptionShort = "Cooked Sheep Leg";
		count = 1;
		mass = 20;
		interactAction = 1;
		interactText = "EAT";
		//Temp,Hunger,Thirst,Energy,Soiled,Immunity,Toxicity,Stamina,Crypto,BloodP
		interactAttributes[] = {0,3000,0,0,0,0,0,0,0,0};
	};

	class KitSpikeTrap: CA_Magazine
	{
		model = "\x\addons\a3_epoch_assets_1\models\supply_crate.p3d";
		picture = "\x\addons\a3_epoch_assets_1\pictures\equip_wooden_crate_ca.paa";
		displayName = "Wooden Spike Trap";
		scope = 2;
		descriptionShort = "Wooden Spike Trap";
		count = 1;
		mass = 20;
		interactAction = 3; // 0 = examine, 1 = eat, 2 = drink, 3 = build
		interactText = "BUILD";
		buildClass = "Spike_TRAP_SIM_EPOCH";
	};
	class KitMetalTrap: CA_Magazine
	{
		model = "\x\addons\a3_epoch_assets_1\models\supply_crate.p3d";
		picture = "\x\addons\a3_epoch_assets_1\pictures\equip_wooden_crate_ca.paa";
		displayName = "Metal Spike Trap";
		scope = 2;
		descriptionShort = "Metal Spike Trap";
		count = 1;
		mass = 20;
		interactAction = 3; // 0 = examine, 1 = eat, 2 = drink, 3 = build
		interactText = "BUILD";
		buildClass = "Metal_TRAP_SIM_EPOCH";
	};

	class KitStudWall: CA_Magazine
	{
		model = "\x\addons\a3_epoch_assets_1\models\supply_crate.p3d";
		picture = "\x\addons\a3_epoch_assets\textures\kits\equip_woodenWall_ca.paa";
		displayName = "Wooden Stud Wall";
		scope = 2;
		descriptionShort = "Wooden Stud Wall";
		count = 1;
		mass = 20;
		interactAction = 3; // 0 = examine, 1 = eat, 2 = drink, 3 = build
		interactText = "BUILD";
		buildClass = "WoodLargeWall_EPOCH";
	};
	class KitWoodFloor : CA_Magazine
	{
		model = "\x\addons\a3_epoch_assets_1\models\supply_crate.p3d";
		picture = "\x\addons\a3_epoch_assets\textures\kits\equip_woodenFloor_ca.paa";
		displayName = "Wooden Floor";
		scope = 2;
		descriptionShort = "Wooden Floor";
		count = 1;
		mass = 20;
		interactAction = 3; // 0 = examine, 1 = eat, 2 = drink, 3 = build
		interactText = "BUILD";
		buildClass = "WoodFloor_EPOCH";
	};
	class KitWoodStairs : CA_Magazine
	{
		model = "\x\addons\a3_epoch_assets_1\models\supply_crate.p3d";
		picture = "\x\addons\a3_epoch_assets\textures\kits\equip_woodenStairs_ca.paa";
		displayName = "Wooden Stairs";
		scope = 2;
		descriptionShort = "Wooden Stairs";
		count = 1;
		mass = 20;
		interactAction = 3; // 0 = examine, 1 = eat, 2 = drink, 3 = build
		interactText = "BUILD";
		buildClass = "WoodStairs_EPOCH";
	};
	class KitWoodTower : CA_Magazine
	{
		model = "\x\addons\a3_epoch_assets_1\models\supply_crate.p3d";
		// TODO icon
		picture = "\x\addons\a3_epoch_assets_1\pictures\equip_wooden_crate_ca.paa";
		displayName = "Wooden Tower";
		scope = 2;
		descriptionShort = "Wooden Tower";
		count = 1;
		mass = 20;
		interactAction = 3; // 0 = examine, 1 = eat, 2 = drink, 3 = build
		interactText = "BUILD";
		buildClass = "WoodTower_EPOCH";
	};
	class KitWoodRamp : CA_Magazine
	{
		model = "\x\addons\a3_epoch_assets_1\models\supply_crate.p3d";
		picture = "\x\addons\a3_epoch_assets\textures\kits\equip_woodramp_ca.paa";
		displayName = "Wooden Ramp";
		scope = 2;
		descriptionShort = "Wooden Ramp";
		count = 1;
		mass = 20;
		interactAction = 3; // 0 = examine, 1 = eat, 2 = drink, 3 = build
		interactText = "BUILD";
		buildClass = "WoodRamp_EPOCH";
	};
	class KitTankTrap : CA_Magazine
	{
		model = "\x\addons\a3_epoch_assets_1\models\supply_crate.p3d";
		picture = "\x\addons\a3_epoch_assets_1\pictures\equip_wooden_crate_ca.paa";
		displayName = "Tank Trap";
		scope = 2;
		descriptionShort = "Tank Trap";
		count = 1;
		mass = 20;
		interactAction = 3; // 0 = examine, 1 = eat, 2 = drink, 3 = build
		interactText = "BUILD";
		buildClass = "TankTrap_SIM_EPOCH";
	};
	class KitWoodLadder : CA_Magazine
	{
		model = "\x\addons\a3_epoch_assets_1\models\supply_crate.p3d";
		// TODO: ladder icon
		picture = "\x\addons\a3_epoch_assets_1\pictures\equip_wooden_crate_ca.paa";
		displayName = "Wooden Ladder";
		scope = 2;
		descriptionShort = "Wooden Ladder";
		count = 1;
		mass = 20;
		interactAction = 3; // 0 = examine, 1 = eat, 2 = drink, 3 = build
		interactText = "BUILD";
		buildClass = "WoodLadder_EPOCH";
	};
	class KitFirePlace : CA_Magazine
	{
		model = "\x\addons\a3_epoch_assets_1\models\supply_crate.p3d";
		picture = "\x\addons\a3_epoch_assets_1\pictures\equip_wooden_crate_ca.paa";
		displayName = "Fireplace";
		scope = 2;
		descriptionShort = "Fireplace";
		count = 1;
		mass = 20;
		interactAction = 3; // 0 = examine, 1 = eat, 2 = drink, 3 = build
		interactText = "BUILD";
		buildClass = "FirePlace_SIM_EPOCH";
		isTemp = 1;
	};
	class KitTiPi : CA_Magazine
	{
		model = "\x\addons\a3_epoch_assets_1\models\supply_crate.p3d";
		picture = "\x\addons\a3_epoch_assets\textures\kits\equip_TP_ca.paa";
		displayName = "TiPi Kit";
		scope = 2;
		descriptionShort = "TeePee (TiPi)";
		count = 1;
		mass = 20;
		interactAction = 3; // 0 = examine, 1 = eat, 2 = drink, 3 = build
		interactText = "BUILD";
		buildClass = "Tipi_SIM_EPOCH";
		isStorage = 1;
	};
	/*
	class KitBase1 : CA_Magazine
	{
		model = "\x\addons\a3_epoch_assets_1\models\supply_crate.p3d";
		picture = "\x\addons\a3_epoch_assets\textures\kits\equip_TP_ca.paa";
		displayName = "Base Kit #1";
		scope = 2;
		descriptionShort = "Base Kit #1";
		count = 1;
		mass = 20;
		interactAction = 3; // 0 = examine, 1 = eat, 2 = drink, 3 = build
		interactText = "BUILD";
		buildClass = "BaseKit1_EPOCH";
	};
	*/
	class KitShelf : CA_Magazine
	{
		model = "\x\addons\a3_epoch_assets_1\models\supply_crate.p3d";
		picture = "\x\addons\a3_epoch_assets\textures\kits\equip_shelf_ca.paa";
		displayName = "Shelf Kit";
		scope = 2;
		descriptionShort = "Shelf";
		count = 1;
		mass = 20;
		interactAction = 3; // 0 = examine, 1 = eat, 2 = drink, 3 = build
		interactText = "BUILD";
		buildClass = "StorageShelf_SIM_EPOCH";
		isStorage = 1;
	};
	class KitWorkbench : CA_Magazine
	{
		model = "\x\addons\a3_epoch_assets_1\models\supply_crate.p3d";
		picture = "\x\addons\a3_epoch_assets_1\pictures\equip_wooden_crate_ca.paa";
		displayName = "Workbench Kit";
		scope = 2;
		descriptionShort = "Workbench";
		count = 1;
		mass = 20;
		interactAction = 3; // 0 = examine, 1 = eat, 2 = drink, 3 = build
		interactText = "BUILD";
		buildClass = "Workbench_SIM_EPOCH";
		isStorage = 1;
	};
	class KitFoundation : CA_Magazine
	{
		model = "\x\addons\a3_epoch_assets_1\models\supply_crate.p3d";
		picture = "\x\addons\a3_epoch_assets\textures\kits\equip_foundation_ca.paa";
		displayName = "Concrete Foundation";
		scope = 2;
		descriptionShort = "Concrete Foundation";
		count = 1;
		mass = 20;
		interactAction = 3; // 0 = examine, 1 = eat, 2 = drink, 3 = build
		interactText = "BUILD";
		buildClass = "Foundation_EPOCH";
	};
	class KitWoodFoundation : CA_Magazine
	{
		model = "\x\addons\a3_epoch_assets_1\models\supply_crate.p3d";
		picture = "\x\addons\a3_epoch_assets\textures\kits\equip_foundation_ca.paa";
		displayName = "Wood Foundation";
		scope = 2;
		descriptionShort = "Wood Foundation";
		count = 1;
		mass = 10;
		interactAction = 3; // 0 = examine, 1 = eat, 2 = drink, 3 = build
		interactText = "BUILD";
		buildClass = "WoodFoundation_EPOCH";
	};
	class KitSolarGen : CA_Magazine
	{
		model = "\x\addons\a3_epoch_assets_1\models\supply_crate.p3d";
		// TODO: solar gen icon
		picture = "\x\addons\a3_epoch_assets_1\pictures\equip_wooden_crate_ca.paa";
		displayName = "Solar Generator Kit";
		scope = 2;
		descriptionShort = "Solar Generator Kit";
		count = 1;
		mass = 20;
		interactAction = 3; // 0 = examine, 1 = eat, 2 = drink, 3 = build
		interactText = "BUILD";
		buildClass = "SolarGen_SIM_EPOCH";
	};
	class KitPlotPole : CA_Magazine
	{
		model = "\x\addons\a3_epoch_assets_1\models\supply_crate.p3d";
		picture = "\x\addons\a3_epoch_assets\textures\jammer\equip_jammer_ca.paa";
		displayName = "Frequency Jammer";
		scope = 2;
		descriptionShort = "Frequency Jammer";
		count = 1;
		mass = 20;
		interactAction = 3; // 0 = examine, 1 = eat, 2 = drink, 3 = build
		interactText = "BUILD";
		buildClass = "PlotPole_SIM_EPOCH";
	};
	class KitCinderWall : CA_Magazine
	{
		model = "\x\addons\a3_epoch_assets_1\models\supply_crate.p3d";
		picture = "\x\addons\a3_epoch_assets\textures\kits\equip_cinderHalf_ca.paa";
		displayName = "Cinder Wall";
		scope = 2;
		descriptionShort = "Cinder Wall";
		count = 1;
		mass = 20;
		interactAction = 3; // 0 = examine, 1 = eat, 2 = drink, 3 = build
		interactText = "BUILD";
		buildClass = "CinderWallHalf_EPOCH";
	};


	class PaintCanBase: CA_Magazine
	{
		model = "\x\addons\a3_epoch_assets\models\paintCan.p3d";
		picture = "\x\addons\a3_epoch_assets\textures\paint can\gear_paintCan_ca.paa";
		displayName = "Paint Can";
		scope = 0;
		descriptionShort = "Crust-O-Leum, Oil based protective enamel.";
		count = 1;
		mass = 1;
		interactAction = 12;
		interactText = "USE";
	};
	class PaintCanClear : PaintCanBase
	{
		scope = 2;
		displayName = "Paint Stripper";
		descriptionShort = "Removes paint and other finishes.";
		colorName = "None";
		textureIndex = 0;
	};
	class PaintCanBlk: PaintCanBase
	{
		scope = 2;
		displayName = "Paint Can (Black)";
		colorName = "Black";
		textureIndex = 1;
	};
	class PaintCanBlu: PaintCanBase
	{
		scope = 2;
		displayName = "Paint Can (Blue)";
		colorName = "Blue";
		textureIndex = 2;
	};
	class PaintCanBrn: PaintCanBase
	{
		scope = 2;
		displayName = "Paint Can (Brown)";
		colorName = "Brown";
		textureIndex = 3;
	};
	class PaintCanGrn: PaintCanBase
	{
		scope = 2;
		displayName = "Paint Can (Green)";
		colorName = "Green";
		textureIndex = 4;
	};
	class PaintCanOra: PaintCanBase
	{
		scope = 2;
		displayName = "Paint Can (Orange)";
		colorName = "Orange";
		textureIndex = 5;
	};
	class PaintCanPur: PaintCanBase
	{
		scope = 2;
		displayName = "Paint Can (Purple)";
		colorName = "Purple";
		textureIndex = 6;
	};
	class PaintCanRed: PaintCanBase
	{
		scope = 2;
		displayName = "Paint Can (Red)";
		colorName = "Red";
		textureIndex = 7;
	};
	class PaintCanTeal: PaintCanBase
	{
		scope = 2;
		displayName = "Paint Can (Teal)";
		colorName = "Teal";
		textureIndex = 8;
	};
	class PaintCanYel: PaintCanBase
	{
		scope = 2;
		displayName = "Paint Can (Yellow)";
		colorName = "Yellow";
		textureIndex = 9;
	};

	class Poppy : CA_Magazine
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\poppy.p3d";
		//TODO icon for poppy
		picture = "\x\addons\a3_epoch_assets\textures\moist\gear_moist_ca.paa";
		displayName = "Poppy";
		descriptionShort = "Pod off of a poppy plant.";
		count = 1;
		mass = 1;
		interactAction = 6;
		interactText = "USE";
		//Temp,Hunger,Thirst,Energy,Soiled,Immunity,Toxicity,Stamina,Crypto,BloodP
		interactAttributes[] = { 0, 0, 0, 0, 0, 10, 0, -100, 0, -10 };
	};

	class Goldenseal : CA_Magazine
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets_3\vegetation\models\goldenseal.p3d";
		picture = "\x\addons\a3_epoch_assets_3\vegetation\gear_goldenseal_ca.paa";
		displayName = "Goldenseal";
		descriptionShort = "Helps reduce toxicity";
		count = 1;
		mass = 1;
		interactAction = 6;
		interactText = "USE";
		//Temp,Hunger,Thirst,Energy,Soiled,Immunity,Toxicity,Stamina,Crypto,BloodP
		interactAttributes[] = { 0, 0, 0, 0, 0, 0, -50, 0, 0, 0 };
	};

	class Pumpkin : CA_Magazine
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets_3\vegetation\models\pumpkin.p3d";
		picture = "\x\addons\a3_epoch_assets_3\vegetation\gear_pumpkin_ca.paa";
		displayName = "Pumpkin";
		descriptionShort = "Pumpkin";
		count = 1;
		mass = 1;
		interactAction = 6;
		interactText = "USE";
		//Temp,Hunger,Thirst,Energy,Soiled,Immunity,Toxicity,Stamina,Crypto,BloodP
		interactAttributes[] = { 0, 500, 0, 0, 0, 0, 0, 50, 0, 0 };
	};

	class Towelette: CA_Magazine
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\moist.p3d";
		picture = "\x\addons\a3_epoch_assets\textures\moist\gear_moist_ca.paa";
		displayName = "Moist Towelette";
		descriptionShort = "Tear open packet, remove towelette and use.";
		count = 1;
		mass = 1;
		interactAction = 6;
		interactText = "USE";
		//Temp,Hunger,Thirst,Energy,Soiled,Immunity,Toxicity,Stamina,Crypto,BloodP
		interactAttributes[] = {0,0,0,0,-25,0,0,0,0,0};
	};
	class HeatPack: CA_Magazine
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\heatdough.p3d";
		picture = "\x\addons\a3_epoch_assets\textures\moist\gear_heat_ca.paa";
		displayName = "Heat Pack";
		descriptionShort = "Don't suffer in the cold... just open one of these and get toasty!";
		count = 1;
		mass = 1;
		interactAction = 7;
		interactText = "USE";
		//Temp,Hunger,Thirst,Energy,Soiled,Immunity,Toxicity,Stamina,Crypto,BloodP
		interactAttributes[] = {1,0,0,0,0,0,0,0,0,0};
	};
	class ColdPack : CA_Magazine
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\heatdough.p3d";
		picture = "\x\addons\a3_epoch_assets\textures\moist\gear_heat_ca.paa";
		displayName = "Cold Pack";
		descriptionShort = "Running Hot? cool it off!";
		count = 1;
		mass = 1;
		interactAction = 8;
		interactText = "USE";
		//Temp,Hunger,Thirst,Energy,Soiled,Immunity,Toxicity,Stamina,Crypto,BloodP
		interactAttributes[] = {-1,0,0,0,0,0,0,0,0,0};
	};
};
