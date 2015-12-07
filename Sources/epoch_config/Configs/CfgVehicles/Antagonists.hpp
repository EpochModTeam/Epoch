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
	class HitPoints : HitPoints
	{
		class HitHead : HitHead
		{
			armor = "0.3*2.5";
		};
		class HitBody : HitBody
		{
			armor = "0.5*10";
		};
		class HitHands : HitHands
		{
			armor = "0.8*5";
		};
		class HitLegs : HitLegs
		{
			armor = "0.8*5";
		};
		class HitFace : HitFace {};
		class HitNeck : HitNeck {};
		class HitPelvis : HitPelvis {};
		class HitAbdomen : HitAbdomen {};
		class HitDiaphragm : HitDiaphragm {};
		class HitChest : HitChest {};
		class HitArms : HitArms {};

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
	class HitPoints: HitPoints
	{
		class HitHead: HitHead
		{
			armor = "0.3*2.5";
		};
		class HitBody: HitBody
		{
			armor = "0.5*10";
		};
		class HitHands: HitHands
		{
			armor = "0.8*5";
		};
		class HitLegs: HitLegs
		{
			armor = "0.8*5";
		};
		class HitFace : HitFace {};
		class HitNeck : HitNeck {};
		class HitPelvis : HitPelvis {};
		class HitAbdomen : HitAbdomen {};
		class HitDiaphragm : HitDiaphragm {};
		class HitChest : HitChest {};
		class HitArms : HitArms {};

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
	class HitPoints : HitPoints
	{
		class HitHead : HitHead
		{
			armor = 10;
		};
		class HitBody : HitBody
		{
			armor = 10;
		};
		class HitHands : HitHands
		{
			armor = 10;
		};
		class HitLegs : HitLegs
		{
			armor = 10;
		};
		class HitFace : HitFace {};
		class HitNeck : HitNeck {};
		class HitPelvis : HitPelvis {};
		class HitAbdomen : HitAbdomen {};
		class HitDiaphragm : HitDiaphragm {};
		class HitChest : HitChest {};
		class HitArms : HitArms {};

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

	class HitPoints : HitPoints
	{
		class HitHead : HitHead
		{
			armor = 4;
		};
		class HitBody : HitBody
		{
			armor = 7;
		};
		class HitHands : HitHands
		{
			armor = 1000;
		};
		class HitLegs : HitLegs
		{
			armor = 9;
		};
		class HitFace : HitFace {};
		class HitNeck : HitNeck {};
		class HitPelvis : HitPelvis {};
		class HitAbdomen : HitAbdomen {};
		class HitDiaphragm : HitDiaphragm {};
		class HitChest : HitChest {};
		class HitArms : HitArms {};

	};
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

	class HitPoints : HitPoints
	{
		class HitHead : HitHead
		{
			armor = 4;
		};
		class HitBody : HitBody
		{
			armor = 7;
		};
		class HitHands : HitHands
		{
			armor = 1000;
		};
		class HitLegs : HitLegs
		{
			armor = 9;
		};
		class HitFace : HitFace {};
		class HitNeck : HitNeck {};
		class HitPelvis : HitPelvis {};
		class HitAbdomen : HitAbdomen {};
		class HitDiaphragm : HitDiaphragm {};
		class HitChest : HitChest {};
		class HitArms : HitArms {};

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
