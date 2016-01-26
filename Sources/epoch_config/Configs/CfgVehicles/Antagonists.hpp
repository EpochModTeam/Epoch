/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Antagonist Configs

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_config/Configs/CfgVehicles/Antagonists.hpp
*/


class Epoch_Char_base_F : Civilian
{
	faceType = "Man_A3";
	side = 4;
	faction = "CIV_F";
	genericNames = "GreekMen";
	vehicleClass = "Men";
	scope = 0;
	class Wounds
	{
		tex[] = {};
		mat[] = { "A3\Characters_F\Common\Data\basicbody.rvmat", "A3\Characters_F\Common\Data\basicbody_injury.rvmat", "A3\Characters_F\Common\Data\basicbody_injury.rvmat", "A3\Characters_F\Heads\Data\hl_white_bald_muscular.rvmat", "A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat", "A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat", "A3\Characters_F\Heads\Data\hl_black_bald_muscular.rvmat", "A3\Characters_F\Heads\Data\hl_black_bald_muscular_injury.rvmat", "A3\Characters_F\Heads\Data\hl_black_bald_muscular_injury.rvmat", "A3\Characters_F\Heads\Data\hl_white_hairy_muscular.rvmat", "A3\Characters_F\Heads\Data\hl_white_hairy_muscular_injury.rvmat", "A3\Characters_F\Heads\Data\hl_white_hairy_muscular_injury.rvmat", "A3\Characters_F\Heads\Data\hl_white_old.rvmat", "A3\Characters_F\Heads\Data\hl_white_old_injury.rvmat", "A3\Characters_F\Heads\Data\hl_white_old_injury.rvmat", "A3\Characters_F\Heads\Data\hl_asian_bald_muscular.rvmat", "A3\Characters_F\Heads\Data\hl_asian_bald_muscular_injury.rvmat", "A3\Characters_F\Heads\Data\hl_asian_bald_muscular_injury.rvmat" };
	};
	model = "\A3\Characters_F\Common\basicbody";
	modelSides[] = {4};
	//nakedUniform = "U_Char_uniform";
	//uniformClass = "U_Char_uniform";
	class UniformInfo
	{
		class SlotsInfo
		{
			class NVG : UniformSlotInfo
			{
				slotType = 602;
			};
			class Scuba : UniformSlotInfo
			{
				slotType = "SCUBA_SLOT";
			};
			class Googles : UniformSlotInfo
			{
				slotType = 603;
			};
			class Headgear : UniformSlotInfo
			{
				slotType = 605;
			};
		};
	};
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
	weapons[] = { "Throw", "Put" };
	respawnWeapons[] = { "Throw", "Put" };
	Items[] = {};
	RespawnItems[] = {};
	magazines[] = {};
	respawnMagazines[] = {};
	linkedItems[] = {};
	respawnLinkedItems[] = {};
};
class Epoch_Sapper_base_F: Civilian2
{
	moves = "CfgMovesMaleSdr2";
	gestures = "CfgGesturesSapper";
	faceType = "Default";
	side = 4;
	faction = "CIV_F";
	genericNames = "GreekMen";
	vehicleClass = "Men";
	scope = 0;
	class Wounds
	{
		tex[] = {};
		mat[] = {"A3\Characters_F\Common\Data\basicbody.rvmat","A3\Characters_F\Common\Data\basicbody_injury.rvmat","A3\Characters_F\Common\Data\basicbody_injury.rvmat","A3\Characters_F\Heads\Data\hl_white_bald_muscular.rvmat","A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat","A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat","A3\Characters_F\Heads\Data\hl_black_bald_muscular.rvmat","A3\Characters_F\Heads\Data\hl_black_bald_muscular_injury.rvmat","A3\Characters_F\Heads\Data\hl_black_bald_muscular_injury.rvmat","A3\Characters_F\Heads\Data\hl_white_hairy_muscular.rvmat","A3\Characters_F\Heads\Data\hl_white_hairy_muscular_injury.rvmat","A3\Characters_F\Heads\Data\hl_white_hairy_muscular_injury.rvmat","A3\Characters_F\Heads\Data\hl_white_old.rvmat","A3\Characters_F\Heads\Data\hl_white_old_injury.rvmat","A3\Characters_F\Heads\Data\hl_white_old_injury.rvmat","A3\Characters_F\Heads\Data\hl_asian_bald_muscular.rvmat","A3\Characters_F\Heads\Data\hl_asian_bald_muscular_injury.rvmat","A3\Characters_F\Heads\Data\hl_asian_bald_muscular_injury.rvmat"};
	};
	model = "\A3\Characters_F\Common\basicbody";
	modelSides[] = {4};
	//nakedUniform = "U_Sapper_uniform";
	//uniformClass = "U_Sapper_uniform";
	class UniformInfo
	{
		class SlotsInfo
		{
			class NVG: UniformSlotInfo
			{
				slotType = 602;
			};
			class Scuba: UniformSlotInfo
			{
				slotType = "SCUBA_SLOT";
			};
			class Googles: UniformSlotInfo
			{
				slotType = 603;
			};
			class Headgear: UniformSlotInfo
			{
				slotType = 605;
			};
		};
	};
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
	weapons[] = {"Throw","Put"};
	respawnWeapons[] = {"Throw","Put"};
	Items[] = {};
	RespawnItems[] = {};
	magazines[] = {};
	respawnMagazines[] = {};
	linkedItems[] = {};
	respawnLinkedItems[] = {};
};

class Epoch_Cloak_F : Epoch_Char_base_F
{
	scope = 2;
	faceType = "Default";
	displayName = "Cloak";
	model = "\x\addons\a3_epoch_assets_3\CfgVehicles\Characters\Cloak_Character.p3d";
	glassesEnabled = 0;
	modelSides[] = {6};
	armor = 10;
	armorStructural = 20;
	class HitPoints
	{
		class HitFace
		{
			armor = 1000;
			material = -1;
			name = "face_hub";
			passThrough = 0.1;
			radius = 0.08;
			explosionShielding = 0.1;
			minimalHit = 0.01;
		};
		class HitNeck: HitFace
		{
			armor = 10;
			material = -1;
			name = "neck";
			passThrough = 0.1;
			radius = 0.1;
			explosionShielding = 0.5;
			minimalHit = 0.01;
		};
		class HitHead: HitNeck
		{
			armor = 10;
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
			armor = 10;
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
			armor = 10;
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
			armor = 10;
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
			armor = 10;
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
			armor = 10;
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
			armor = 10;
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
			armor = 10;
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
			armor = 10;
			material = -1;
			name = "legs";
			passThrough = 1;
			radius = 0.12;
			explosionShielding = 1;
			visual = "injury_legs";
			minimalHit = 0.01;
		};
	};
};
class Epoch_Sapper_F: Epoch_Sapper_base_F
{
	scope = 2;
	faceType = "Default";
	displayName = "Sapper";
	model = "\x\addons\a3_epoch_assets_3\CfgVehicles\Characters\Sapper_Character.p3d";
	hiddenSelections[] = {"sapper","remains"};
	hiddenSelectionsTextures[] = {"x\addons\a3_epoch_assets\textures\sapper\sapper_eco.paa",""};
	glassesEnabled = 0;
	modelSides[] = {6};
	armor = 6;
	armorStructural = 13;

	magazines[] = {};
	respawnMagazines[] = {};

	class HitPoints
	{
		class HitFace
		{
			armor = 3;
			material = -1;
			name = "face_hub";
			passThrough = 0.1;
			radius = 0.08;
			explosionShielding = 0.1;
			minimalHit = 0.01;
		};
		class HitNeck: HitFace
		{
			armor = 3;
			material = -1;
			name = "neck";
			passThrough = 0.1;
			radius = 0.1;
			explosionShielding = 0.5;
			minimalHit = 0.01;
		};
		class HitHead: HitNeck
		{
			armor = 3;
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
			armor = 3;
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
			armor = 3;
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
			armor = 3;
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
			armor = 3;
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
			armor = 1000;
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
			armor = 1000;
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
			armor = 8;
			material = -1;
			name = "legs";
			passThrough = 1;
			radius = 0.12;
			explosionShielding = 1;
			visual = "injury_legs";
			minimalHit = 0.01;
		};
	};
};
class Epoch_SapperG_F : Epoch_Sapper_F {
	scope = 2;
	displayName = "Sapper (Toxic)";
	moves = "CfgMovesMaleSdr3";
	hiddenSelections[] = {"camo","remains"};
	hiddenSelectionsTextures[] = {"x\addons\a3_epoch_assets\textures\sapper\sapper_green_eco.paa",""};
};
class Epoch_SapperB_F : Epoch_Sapper_base_F
{
	scope = 2;
	faceType = "Default";
	displayName = "Sapper (Bloated)";
	model = "\x\addons\a3_epoch_assets_3\CfgVehicles\Characters\Sapper_Bloated.p3d";
	//hiddenSelections[] = { "sapper", "remains" };
	//hiddenSelectionsTextures[] = { "x\addons\a3_epoch_assets\textures\sapper\sapper_eco.paa", "" };
	glassesEnabled = 0;
	modelSides[] = { 6 };
	armor = 9;
	armorStructural = 13;

	magazines[] = {};
	respawnMagazines[] = {};


	class HitPoints
	{
		class HitFace
		{
			armor = 3;
			material = -1;
			name = "face_hub";
			passThrough = 0.1;
			radius = 0.08;
			explosionShielding = 0.1;
			minimalHit = 0.01;
		};
		class HitNeck: HitFace
		{
			armor = 3;
			material = -1;
			name = "neck";
			passThrough = 0.1;
			radius = 0.1;
			explosionShielding = 0.5;
			minimalHit = 0.01;
		};
		class HitHead: HitNeck
		{
			armor = 3;
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
			armor = 3;
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
			armor = 3;
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
			armor = 3;
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
			armor = 9;
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
			armor = 1000;
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
			armor = 1000;
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
			armor = 8;
			material = -1;
			name = "legs";
			passThrough = 1;
			radius = 0.12;
			explosionShielding = 1;
			visual = "injury_legs";
			minimalHit = 0.01;
		};
	};
};

/*
class Epoch_Ent_Small_F : Epoch_Char_base_F
{
	scope = 2;
	faceType = "Default";
	model = "\x\addons\a3_epoch_assets_3\CfgVehicles\Characters\Elemental_Small.p3d";
	displayName = "Ent (small)";
	glassesEnabled = 0;
	modelSides[] = {6};
	class HitPoints: HitPoints
	{
		class HitHead: HitHead
		{
			armor = 100;
		};
		class HitBody: HitBody
		{
			armor = 200;
		};
		class HitHands: HitHands
		{
			armor = 200;
		};
		class HitLegs: HitLegs
		{
			armor = 200;
		};
	};
};
class Epoch_Ent_Med_F : Epoch_Char_base_F
{
	scope = 2;
	faceType = "Default";
	model = "\x\addons\a3_epoch_assets_3\CfgVehicles\Characters\Elemental_Med.p3d";
	displayName = "Ent (medium)";
	extCameraPosition[] = {0,1.5,-9};
	glassesEnabled = 0;
	modelSides[] = {6};
	class HitPoints: HitPoints
	{
		class HitHead: HitHead
		{
			armor = 200;
		};
		class HitBody: HitBody
		{
			armor = 300;
		};
		class HitHands: HitHands
		{
			armor = 300;
		};
		class HitLegs: HitLegs
		{
			armor = 300;
		};
	};
};
class Epoch_Ent_Large_F : Epoch_Char_base_F
{
	scope = 2;
	faceType = "Default";
	model = "\x\addons\a3_epoch_assets_3\CfgVehicles\Characters\Elemental_Large.p3d";
	displayName = "Ent (large)";
	extCameraPosition[] = {0,1.5,-18};
	glassesEnabled = 0;
	modelSides[] = {6};
	class HitPoints: HitPoints
	{
		class HitHead: HitHead
		{
			armor = 250;
		};
		class HitBody: HitBody
		{
			armor = 500;
		};
		class HitHands: HitHands
		{
			armor = 500;
		};
		class HitLegs: HitLegs
		{
			armor = 500;
		};
	};
};
*/
