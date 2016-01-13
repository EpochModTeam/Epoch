/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Player Configs

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_config/Configs/CfgVehicles/Players.hpp
*/

class B_Soldier_base_F;
class Epoch_Female_base_F : B_Soldier_base_F
{
	identityTypes[] = { "Woman", "NoGlasses" };

	// minGunElev = -80;
	maxGunElev = 80; // test increased aim up angle

	faceType = "Man_A3";
	woman = 1;
	side = 1;
	engineer = 1;
	vehicleClass = "Women";
	scope = 0;

	// fix and normalize base classes
	cost = 40000;
	headgearProbability = 100;
	allowedHeadgear[] = {};
	class HitPoints
	{
		class HitFace
		{
			armor = 1;
			material = -1;
			name = "face_hub";
			passThrough = 0.1;
			radius = 0.08;
			explosionShielding = 0.1;
			minimalHit = 0.01;
		};
		class HitNeck: HitFace
		{
			armor = 1;
			material = -1;
			name = "neck";
			passThrough = 0.1;
			radius = 0.1;
			explosionShielding = 0.5;
			minimalHit = 0.01;
		};
		class HitHead: HitNeck
		{
			armor = 1;
			material = -1;
			name = "head";
			passThrough = 0.1;
			radius = 0.2;
			explosionShielding = 0.5;
			minimalHit = 0.01;
			depends = "HitFace max HitNeck";
		};
		class HitPelvis
		{
			armor = 1;
			material = -1;
			name = "pelvis";
			passThrough = 0.1;
			radius = 0.2;
			explosionShielding = 1;
			visual = "injury_body";
			minimalHit = 0.01;
		};
		class HitAbdomen: HitPelvis
		{
			armor = 1;
			material = -1;
			name = "spine1";
			passThrough = 0.1;
			radius = 0.15;
			explosionShielding = 1;
			visual = "injury_body";
			minimalHit = 0.01;
		};
		class HitDiaphragm: HitAbdomen
		{
			armor = 1;
			material = -1;
			name = "spine2";
			passThrough = 0.1;
			radius = 0.15;
			explosionShielding = 6;
			visual = "injury_body";
			minimalHit = 0.01;
		};
		class HitChest: HitDiaphragm
		{
			armor = 1;
			material = -1;
			name = "spine3";
			passThrough = 0.1;
			radius = 0.15;
			explosionShielding = 6;
			visual = "injury_body";
			minimalHit = 0.01;
		};
		class HitBody: HitChest
		{
			armor = 1000;
			material = -1;
			name = "body";
			passThrough = 0.1;
			radius = 0.16;
			explosionShielding = 6;
			visual = "injury_body";
			minimalHit = 0.01;
			depends = "HitPelvis max HitAbdomen max HitDiaphragm max HitChest";
		};
		class HitArms
		{
			armor = 1;
			material = -1;
			name = "arms";
			passThrough = 1;
			radius = 0.1;
			explosionShielding = 1;
			visual = "injury_hands";
			minimalHit = 0.01;
		};
		class HitHands: HitArms
		{
			armor = 1;
			material = -1;
			name = "hands";
			passThrough = 1;
			radius = 0.1;
			explosionShielding = 1;
			visual = "injury_hands";
			minimalHit = 0.01;
			depends = "HitArms";
		};
		class HitLegs
		{
			armor = 1;
			material = -1;
			name = "legs";
			passThrough = 1;
			radius = 0.12;
			explosionShielding = 1;
			visual = "injury_legs";
			minimalHit = 0.01;
		};
	};
	armor = 2;
	armorStructural = 0.5;
	explosionShielding = 0.05;

	class Wounds
	{
		tex[] = {};
		mat[] = { "x\addons\a3_epoch_assets\textures\camo\female_camoDark.rvmat", "x\addons\a3_epoch_assets\textures\camo\female_camoinjury.rvmat", "x\addons\a3_epoch_assets\textures\camo\female_camoinjury.rvmat" };
	};
	model = "\x\addons\a3_epoch_assets_3\CfgVehicles\Characters\Keesha_character.p3d";
	modelSides[] = {1};
	nakedUniform = "U_BasicBodyFemale";
	uniformClass = "U_Test_uniform";
	weapons[] = {"Throw","Put"};
	respawnWeapons[] = {"Throw","Put"};
	Items[] = {};
	RespawnItems[] = {};
	magazines[] = {};
	respawnMagazines[] = {};
	linkedItems[] = { "V_F41_EPOCH", "ItemMap"};
	respawnLinkedItems[] = { "V_F41_EPOCH", "ItemMap" };
};

class Underwear_F;
class FemaleUnderwear_F: Underwear_F
{
	author = "Epoch";
	_generalMacro = "FemaleUnderwear_F";
	scope = 1;
	scopeCurator = 0;
	displayName = "TEST: Underwear";
	model = "\x\addons\a3_epoch_assets_3\CfgVehicles\Characters\Keesha_character.p3d";
	uniformClass = "U_BasicBodyFemale";
	weapons[] = {};
	magazines[] = {};
	respawnWeapons[] = {};
	respawnMagazines[] = {};
};


class Epoch_Female_wetsuit_F : Epoch_Female_base_F
{
	faceType = "Man_A3";
	woman = 1;
	side = 1;
	engineer = 1;
	vehicleClass = "Women";
	displayName = "Female Wetsuit";
	scope = 2;

	hiddenSelections[] = { "Camo" };
	hiddenSelectionsTextures[] = { "\x\addons\a3_epoch_assets\textures\wetsuit\wetsuit_co.paa" };

	class Wounds
	{
		tex[] = {};
		mat[] = { "x\addons\a3_epoch_assets\textures\wetsuit\wetsuit.rvmat", "x\addons\a3_epoch_assets\textures\wetsuit\wetsuit_Injury.rvmat", "x\addons\a3_epoch_assets\textures\wetsuit\wetsuit_Injury.rvmat" };
	};
	model = "\x\addons\a3_epoch_assets_3\CfgVehicles\Characters\Female_WetSuit.p3d";

	hiddenUnderwaterSelections[] = { "hide" };
	shownUnderwaterSelections[] = { "unhide", "unhide2" };

	hiddenUnderwaterSelectionsTextures[] = { "\x\addons\a3_epoch_assets\textures\wetsuit\wetsuit_co.paa", "\x\addons\a3_epoch_assets\textures\wetsuit\wetsuit_co.paa", "\A3\characters_f\data\visors_ca.paa" };

	modelSides[] = {1};
	nakedUniform = "U_BasicBodyFemale";
	uniformClass = "U_Wetsuit_uniform";
	weapons[] = {"Throw","Put"};
	respawnWeapons[] = {"Throw","Put"};
	Items[] = {};
	RespawnItems[] = {};
	magazines[] = {};
	respawnMagazines[] = {};

	primaryAmmoCoef = 0.4;
	secondaryAmmoCoef = 0.1;
	handgunAmmoCoef = 0.2;

	// O_Soldier_diver_base_F
	class HitPoints
	{
		class HitFace
		{
			armor = 1;
			material = -1;
			name = "face_hub";
			passThrough = 0.1;
			radius = 0.08;
			explosionShielding = 0.1;
			minimalHit = 0.01;
		};
		class HitNeck: HitFace
		{
			armor = 1;
			material = -1;
			name = "neck";
			passThrough = 0.1;
			radius = 0.1;
			explosionShielding = 0.5;
			minimalHit = 0.01;
		};
		class HitHead: HitNeck
		{
			armor = 1;
			material = -1;
			name = "head";
			passThrough = 0.1;
			radius = 0.2;
			explosionShielding = 0.5;
			minimalHit = 0.01;
			depends = "HitFace max HitNeck";
		};
		class HitPelvis
		{
			armor = 1;
			material = -1;
			name = "pelvis";
			passThrough = 0.1;
			radius = 0.2;
			explosionShielding = 1;
			visual = "injury_body";
			minimalHit = 0.01;
		};
		class HitAbdomen: HitPelvis
		{
			armor = 1;
			material = -1;
			name = "spine1";
			passThrough = 0.1;
			radius = 0.15;
			explosionShielding = 1;
			visual = "injury_body";
			minimalHit = 0.01;
		};
		class HitDiaphragm: HitAbdomen
		{
			armor = 1;
			material = -1;
			name = "spine2";
			passThrough = 0.1;
			radius = 0.15;
			explosionShielding = 6;
			visual = "injury_body";
			minimalHit = 0.01;
		};
		class HitChest: HitDiaphragm
		{
			armor = 1;
			material = -1;
			name = "spine3";
			passThrough = 0.1;
			radius = 0.15;
			explosionShielding = 6;
			visual = "injury_body";
			minimalHit = 0.01;
		};
		class HitBody: HitChest
		{
			armor = 1000;
			material = -1;
			name = "body";
			passThrough = 0.1;
			radius = 0.2;
			explosionShielding = 6;
			visual = "injury_body";
			minimalHit = 0.01;
			depends = "HitPelvis max HitAbdomen max HitDiaphragm max HitChest";
		};
		class HitArms
		{
			armor = 1;
			material = -1;
			name = "arms";
			passThrough = 1;
			radius = 0.1;
			explosionShielding = 1;
			visual = "injury_hands";
			minimalHit = 0.01;
		};
		class HitHands: HitArms
		{
			armor = 1;
			material = -1;
			name = "hands";
			passThrough = 1;
			radius = 0.1;
			explosionShielding = 1;
			visual = "injury_hands";
			minimalHit = 0.01;
			depends = "HitArms";
		};
		class HitLegs
		{
			armor = 1;
			material = -1;
			name = "legs";
			passThrough = 1;
			radius = 0.12;
			explosionShielding = 1;
			visual = "injury_legs";
			minimalHit = 0.01;
		};
	};
	armor = 2;
	armorStructural = 0.5;
	explosionShielding = 0.05;

	// O_Soldier_base_F
	sensitivity = 3;
	threat[] = {1,0.1,0.1};
	camouflage = 1.4;

};
class Epoch_Female_wetsuitW_F : Epoch_Female_wetsuit_F
{
	displayName = "Female Wetsuit (white)";
	scope = 2;
	hiddenSelections[] = { "Camo" };
	hiddenSelectionsTextures[] = { "\x\addons\a3_epoch_assets\textures\wetsuit\wetsuitWhite_co.paa" };
	hiddenSelectionsMaterials[] = { "\x\addons\a3_epoch_assets\textures\wetsuit\wetsuitWhite.rvmat" };

	class Wounds
	{
		tex[] = {};
		mat[] = { "x\addons\a3_epoch_assets\textures\wetsuit\wetsuitWhite.rvmat", "x\addons\a3_epoch_assets\textures\wetsuit\wetsuit_Injury.rvmat", "x\addons\a3_epoch_assets\textures\wetsuit\wetsuit_Injury.rvmat" };
	};

	modelSides[] = { 1 };
	uniformClass = "U_Wetsuit_White";
	hiddenUnderwaterSelectionsTextures[] = { "\x\addons\a3_epoch_assets\textures\wetsuit\wetsuitWhite_co.paa", "\x\addons\a3_epoch_assets\textures\wetsuit\wetsuitWhite_co.paa", "\A3\characters_f\data\visors_ca.paa" };

};
class Epoch_Female_wetsuitB_F : Epoch_Female_wetsuit_F
{
	displayName = "Female Wetsuit (blue)";
	scope = 2;
	hiddenSelections[] = { "Camo" };
	hiddenSelectionsTextures[] = { "\x\addons\a3_epoch_assets\textures\wetsuit\wetsuitBlue_co.paa" };
	modelSides[] = { 1 };
	uniformClass = "U_Wetsuit_Blue";
	hiddenUnderwaterSelectionsTextures[] = { "\x\addons\a3_epoch_assets\textures\wetsuit\wetsuitBlue_co.paa", "\x\addons\a3_epoch_assets\textures\wetsuit\wetsuitBlue_co.paa", "\A3\characters_f\data\visors_ca.paa" };
};
class Epoch_Female_wetsuitP_F : Epoch_Female_wetsuit_F
{
	displayName = "Female Wetsuit (purple)";
	scope = 2;
	hiddenSelections[] = { "Camo" };
	hiddenSelectionsTextures[] = { "\x\addons\a3_epoch_assets\textures\wetsuit\wetsuitPurp_co.paa" };
	modelSides[] = { 1 };
	uniformClass = "U_Wetsuit_Purp";
	hiddenUnderwaterSelectionsTextures[] = { "\x\addons\a3_epoch_assets\textures\wetsuit\wetsuitPurp_co.paa", "\x\addons\a3_epoch_assets\textures\wetsuit\wetsuitPurp_co.paa", "\A3\characters_f\data\visors_ca.paa" };
};
class Epoch_Female_wetsuitC_F : Epoch_Female_wetsuit_F
{
	displayName = "Female Wetsuit (camo)";
	scope = 2;
	hiddenSelections[] = { "Camo" };
	hiddenSelectionsTextures[] = { "\x\addons\a3_epoch_assets\textures\wetsuit\wetsuitCamo_co.paa" };
	modelSides[] = { 1 };
	uniformClass = "U_Wetsuit_Camo";
	hiddenUnderwaterSelectionsTextures[] = { "\x\addons\a3_epoch_assets\textures\wetsuit\wetsuitCamo_co.paa", "\x\addons\a3_epoch_assets\textures\wetsuit\wetsuitCamo_co.paa", "\A3\characters_f\data\visors_ca.paa" };

	camouflage = 1.0;
};

class Epoch_Female_Ghillie1_F : Epoch_Female_base_F
{
	displayName = "Female Ghillie (tan)";
	scope = 2;
	model = "\x\addons\a3_epoch_assets_3\CfgVehicles\Characters\female_ghillie.p3d";

	hiddenSelections[] = { "Camo" };
	hiddenSelectionsTextures[] = { "\a3\characters_f\common\data\ghillie_3_ca.paa" };
	// hiddenSelectionsMaterials[] = { "\x\addons\a3_epoch_assets\textures\camo\female_camoDark.rvmat" };

	modelSides[] = { 1 };
	uniformClass = "U_ghillie1_uniform";

	// O_Soldier_sniper_base_F
	primaryAmmoCoef = 0.2;
	secondaryAmmoCoef = 0.05;
	handgunAmmoCoef = 0.1;

	// O_Soldier_base_F
	class HitPoints
	{
		class HitFace
		{
			armor = 1;
			material = -1;
			name = "face_hub";
			passThrough = 0.1;
			radius = 0.08;
			explosionShielding = 0.1;
			minimalHit = 0.01;
		};
		class HitNeck: HitFace
		{
			armor = 4;
			material = -1;
			name = "neck";
			passThrough = 0.1;
			radius = 0.1;
			explosionShielding = 0.5;
			minimalHit = 0.01;
		};
		class HitHead: HitNeck
		{
			armor = 1;
			material = -1;
			name = "head";
			passThrough = 0.1;
			radius = 0.2;
			explosionShielding = 0.5;
			minimalHit = 0.01;
			depends = "HitFace max HitNeck";
		};
		class HitPelvis
		{
			armor = 6;
			material = -1;
			name = "pelvis";
			passThrough = 0.04;
			radius = 0.2;
			explosionShielding = 1;
			visual = "injury_body";
			minimalHit = 0.01;
		};
		class HitAbdomen: HitPelvis
		{
			armor = 6;
			material = -1;
			name = "spine1";
			passThrough = 0.04;
			radius = 0.15;
			explosionShielding = 1;
			visual = "injury_body";
			minimalHit = 0.01;
		};
		class HitDiaphragm: HitAbdomen
		{
			armor = 6;
			material = -1;
			name = "spine2";
			passThrough = 0.04;
			radius = 0.15;
			explosionShielding = 1.5;
			visual = "injury_body";
			minimalHit = 0.01;
		};
		class HitChest: HitDiaphragm
		{
			armor = 6;
			material = -1;
			name = "spine3";
			passThrough = 0.04;
			radius = 0.15;
			explosionShielding = 1.5;
			visual = "injury_body";
			minimalHit = 0.01;
		};
		class HitBody: HitChest
		{
			armor = 1000;
			material = -1;
			name = "body";
			passThrough = 0.04;
			radius = 0.16;
			explosionShielding = 1.5;
			visual = "injury_body";
			minimalHit = 0.01;
			depends = "HitPelvis max HitAbdomen max HitDiaphragm max HitChest";
		};
		class HitArms
		{
			armor = 8;
			material = -1;
			name = "arms";
			passThrough = 0.6;
			radius = 0.1;
			explosionShielding = 0.8;
			visual = "injury_hands";
			minimalHit = 0.01;
		};
		class HitHands: HitArms
		{
			armor = 8;
			material = -1;
			name = "hands";
			passThrough = 0.6;
			radius = 0.1;
			explosionShielding = 0.8;
			visual = "injury_hands";
			minimalHit = 0.01;
			depends = "HitArms";
		};
		class HitLegs
		{
			armor = 8;
			material = -1;
			name = "legs";
			passThrough = 0.6;
			radius = 0.12;
			explosionShielding = 0.8;
			visual = "injury_legs";
			minimalHit = 0.01;
		};
	};
	armor = 2;
	armorStructural = 0.5;
	explosionShielding = 0.05;

	// O_sniper_F
	threat[] = {1,0.6,0.6};
	camouflage = 0.4;
	sensitivity = 3.3;
};
class Epoch_Female_Ghillie2_F : Epoch_Female_Ghillie1_F
{
	displayName = "Female Ghillie (light green)";
	scope = 2;
	model = "\x\addons\a3_epoch_assets_3\CfgVehicles\Characters\female_ghillie.p3d";

	hiddenSelections[] = { "Camo" };
	hiddenSelectionsTextures[] = { "\a3\characters_f\common\data\ghillie_2_ca.paa" };
	// hiddenSelectionsMaterials[] = { "\x\addons\a3_epoch_assets\textures\camo\female_camoDark.rvmat" };

	modelSides[] = { 1 };
	uniformClass = "U_ghillie2_uniform";
};
class Epoch_Female_Ghillie3_F : Epoch_Female_Ghillie1_F
{
	displayName = "Female Ghillie (green)";
	scope = 2;
	model = "\x\addons\a3_epoch_assets_3\CfgVehicles\Characters\female_ghillie.p3d";

	hiddenSelections[] = { "Camo" };
	hiddenSelectionsTextures[] = { "\a3\characters_f\common\data\ghillie_1_ca.paa" };
	// hiddenSelectionsMaterials[] = { "\x\addons\a3_epoch_assets\textures\camo\female_camoDark.rvmat" };

	modelSides[] = { 1 };
	uniformClass = "U_ghillie3_uniform";
};

class Epoch_Female_Camo_F : Epoch_Female_base_F
{
	displayName = "Female Camo";
	scope = 2;
	model = "\x\addons\a3_epoch_assets_3\CfgVehicles\Characters\female_camo.p3d";
	hiddenSelections[] = { "Camo" };
	hiddenSelectionsTextures[] = { "\x\addons\a3_epoch_assets\textures\camo\camoDark_co.paa" };
	hiddenSelectionsMaterials[] = { "\x\addons\a3_epoch_assets\textures\camo\female_camoDark.rvmat" };

	class Wounds
	{
		tex[] = {};
		mat[] = { "x\addons\a3_epoch_assets\textures\camo\female_camoDark.rvmat", "x\addons\a3_epoch_assets\textures\camo\female_camoinjury.rvmat", "x\addons\a3_epoch_assets\textures\camo\female_camoinjury.rvmat" };
	};

	modelSides[] = { 1 };
	uniformClass = "U_Camo_uniform";

};
class Epoch_Female_CamoBlue_F : Epoch_Female_Camo_F
{
	displayName = "Female Camo (Blue)";
	scope = 2;
	model = "\x\addons\a3_epoch_assets_3\CfgVehicles\Characters\female_camo.p3d";
	hiddenSelections[] = { "Camo" };
	hiddenSelectionsTextures[] = { "\x\addons\a3_epoch_assets\textures\camo\camoBlue_co.paa" };
	hiddenSelectionsMaterials[] = { "\x\addons\a3_epoch_assets\textures\camo\female_camoBlue.rvmat" };

	class Wounds
	{
		tex[] = {};
		mat[] = { "x\addons\a3_epoch_assets\textures\camo\female_camoBlue.rvmat", "x\addons\a3_epoch_assets\textures\camo\female_camoinjury.rvmat", "x\addons\a3_epoch_assets\textures\camo\female_camoinjury.rvmat" };
	};

	modelSides[] = { 1 };
	uniformClass = "U_CamoBlue_uniform";
};
class Epoch_Female_CamoBrn_F : Epoch_Female_Camo_F
{
	displayName = "Female Camo (Brown)";
	scope = 2;
	model = "\x\addons\a3_epoch_assets_3\CfgVehicles\Characters\female_camo.p3d";
	hiddenSelections[] = { "Camo" };
	hiddenSelectionsTextures[] = { "\x\addons\a3_epoch_assets\textures\camo\camoBrown_co.paa" };
	hiddenSelectionsMaterials[] = { "\x\addons\a3_epoch_assets\textures\camo\female_camoBrown.rvmat" };

	class Wounds
	{
		tex[] = {};
		mat[] = { "x\addons\a3_epoch_assets\textures\camo\female_camoBrown.rvmat", "x\addons\a3_epoch_assets\textures\camo\female_camoinjury.rvmat", "x\addons\a3_epoch_assets\textures\camo\female_camoinjury.rvmat" };
	};

	modelSides[] = { 1 };
	uniformClass = "U_CamoBrn_uniform";
};
class Epoch_Female_CamoRed_F : Epoch_Female_Camo_F
{
	displayName = "Female Camo (Red)";
	scope = 2;
	model = "\x\addons\a3_epoch_assets_3\CfgVehicles\Characters\female_camo.p3d";
	hiddenSelections[] = { "Camo" };
	hiddenSelectionsTextures[] = { "\x\addons\a3_epoch_assets\textures\camo\camoRed_co.paa" };
	hiddenSelectionsMaterials[] = { "\x\addons\a3_epoch_assets\textures\camo\female_camoRed.rvmat" };

	class Wounds
	{
		tex[] = {};
		mat[] = { "x\addons\a3_epoch_assets\textures\camo\female_camoRed.rvmat", "x\addons\a3_epoch_assets\textures\camo\female_camoinjury.rvmat", "x\addons\a3_epoch_assets\textures\camo\female_camoinjury.rvmat" };
	};

	modelSides[] = { 1 };
	uniformClass = "U_CamoRed_uniform";
};

class Epoch_Female_F: Epoch_Female_base_F
{
    woman = 1;
    scope = 2;
    displayName = "Female";
    interactMode = 2;
};














class O_Soldier_base_F;
class Epoch_Man_base_F : O_Soldier_base_F
{
	identityTypes[] = { "Kerry", "NoGlasses" };

	maxGunElev = 80; // test increased aim up angle

	faceType = "Man_A3";
	side = 0;
	vehicleClass = "Men";
	engineer = 1;
	scope = 0;
	class Wounds
	{
		tex[] = {};
		mat[] = {"A3\Characters_F\Common\Data\basicbody.rvmat","A3\Characters_F\Common\Data\basicbody_injury.rvmat","A3\Characters_F\Common\Data\basicbody_injury.rvmat","A3\Characters_F\Heads\Data\hl_white_bald_muscular.rvmat","A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat","A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat","A3\Characters_F\Heads\Data\hl_black_bald_muscular.rvmat","A3\Characters_F\Heads\Data\hl_black_bald_muscular_injury.rvmat","A3\Characters_F\Heads\Data\hl_black_bald_muscular_injury.rvmat","A3\Characters_F\Heads\Data\hl_white_hairy_muscular.rvmat","A3\Characters_F\Heads\Data\hl_white_hairy_muscular_injury.rvmat","A3\Characters_F\Heads\Data\hl_white_hairy_muscular_injury.rvmat","A3\Characters_F\Heads\Data\hl_white_old.rvmat","A3\Characters_F\Heads\Data\hl_white_old_injury.rvmat","A3\Characters_F\Heads\Data\hl_white_old_injury.rvmat","A3\Characters_F\Heads\Data\hl_asian_bald_muscular.rvmat","A3\Characters_F\Heads\Data\hl_asian_bald_muscular_injury.rvmat","A3\Characters_F\Heads\Data\hl_asian_bald_muscular_injury.rvmat"};
	};
	model = "\A3\Characters_F\Common\basicbody";
	modelSides[] = {0};
	nakedUniform = "U_BasicBody";
	uniformClass = "U_Test1_uniform";
	weapons[] = {"Throw","Put"};
	respawnWeapons[] = {"Throw","Put"};
	Items[] = {};
	RespawnItems[] = {};
	magazines[] = {};
	respawnMagazines[] = {};
	linkedItems[] = { "V_41_EPOCH", "ItemMap" };
	respawnLinkedItems[] = { "V_41_EPOCH", "ItemMap" };

	// fix and normalize base classes
	cost = 40000;
	headgearProbability = 100;
	allowedHeadgear[] = {};
	class HitPoints
	{
		class HitFace
		{
			armor = 1;
			material = -1;
			name = "face_hub";
			passThrough = 0.1;
			radius = 0.08;
			explosionShielding = 0.1;
			minimalHit = 0.01;
		};
		class HitNeck: HitFace
		{
			armor = 1;
			material = -1;
			name = "neck";
			passThrough = 0.1;
			radius = 0.1;
			explosionShielding = 0.5;
			minimalHit = 0.01;
		};
		class HitHead: HitNeck
		{
			armor = 1;
			material = -1;
			name = "head";
			passThrough = 0.1;
			radius = 0.2;
			explosionShielding = 0.5;
			minimalHit = 0.01;
			depends = "HitFace max HitNeck";
		};
		class HitPelvis
		{
			armor = 1;
			material = -1;
			name = "pelvis";
			passThrough = 0.1;
			radius = 0.2;
			explosionShielding = 1;
			visual = "injury_body";
			minimalHit = 0.01;
		};
		class HitAbdomen: HitPelvis
		{
			armor = 1;
			material = -1;
			name = "spine1";
			passThrough = 0.1;
			radius = 0.15;
			explosionShielding = 1;
			visual = "injury_body";
			minimalHit = 0.01;
		};
		class HitDiaphragm: HitAbdomen
		{
			armor = 1;
			material = -1;
			name = "spine2";
			passThrough = 0.1;
			radius = 0.15;
			explosionShielding = 6;
			visual = "injury_body";
			minimalHit = 0.01;
		};
		class HitChest: HitDiaphragm
		{
			armor = 1;
			material = -1;
			name = "spine3";
			passThrough = 0.1;
			radius = 0.15;
			explosionShielding = 6;
			visual = "injury_body";
			minimalHit = 0.01;
		};
		class HitBody: HitChest
		{
			armor = 1000;
			material = -1;
			name = "body";
			passThrough = 0.1;
			radius = 0.16;
			explosionShielding = 6;
			visual = "injury_body";
			minimalHit = 0.01;
			depends = "HitPelvis max HitAbdomen max HitDiaphragm max HitChest";
		};
		class HitArms
		{
			armor = 1;
			material = -1;
			name = "arms";
			passThrough = 1;
			radius = 0.1;
			explosionShielding = 1;
			visual = "injury_hands";
			minimalHit = 0.01;
		};
		class HitHands: HitArms
		{
			armor = 1;
			material = -1;
			name = "hands";
			passThrough = 1;
			radius = 0.1;
			explosionShielding = 1;
			visual = "injury_hands";
			minimalHit = 0.01;
			depends = "HitArms";
		};
		class HitLegs
		{
			armor = 1;
			material = -1;
			name = "legs";
			passThrough = 1;
			radius = 0.12;
			explosionShielding = 1;
			visual = "injury_legs";
			minimalHit = 0.01;
		};
	};
	armor = 2;
	armorStructural = 0.5;
	explosionShielding = 0.05;


};
class Epoch_Male_F: Epoch_Man_base_F
{
    scope = 2;
    displayName = "Male";
    interactMode = 2;
};
