/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Main CfgVehicles config file

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_config/Configs/CfgVehicles.hpp
*/

class UniformSlotInfo;
class CfgVehicles
{
	class Static;
	class Const_Ghost_EPOCH : Static {};
	class Animated_Loot : Static {};
	class NonStrategic;
	class WeaponHolder;

	class Man;
	class CAManBase: Man
	{
		class ViewPilot;
		class HitPoints
		{
			class HitHead;
			class HitBody;
			class HitHands;
			class HitLegs;
		};
	};


	class EPOCH_CAManBase: CAManBase
	{
		class HitPoints: HitPoints
		{
			class HitFace: HitHead
			{
				armor               = 1; // Keep constant so that the hit point armor remains on the same scale
				material            = -1;
				name                = "face_hub"; // Selection name
				passThrough         = 0.1; // Damage resistance
				radius              = 0.08;
				explosionShielding  = 0.1; // Protection against explosive damage
				minimalHit          = 0.01; // Minimal damage value that can be applied
			}
			class HitNeck: HitFace
			{
				armor               = 1;
				material            = -1;
				name                = "neck";
				passThrough         = 0.1;
				radius              = 0.1;
				explosionShielding  = 0.5;
				minimalHit          = 0.01;
			}
			class HitHead: HitNeck
			{
				armor               = 1;
				material            = -1;
				name                = "head";
				passThrough         = 0.1;
				radius              = 0.2;
				explosionShielding  = 0.5;
				minimalHit          = 0.01;
				depends             = "HitFace max HitNeck"; // Returns the greater of HitFace and HitNeck.
			};
			class HitPelvis: HitBody
			{
				armor               = 1;
				material            = -1;
				name                = "pelvis";
				passThrough         = 0.1;
				radius              = 0.2;
				explosionShielding  = 1;
				visual              = "injury_body";
				minimalHit          = 0.01;
			};
			class HitAbdomen: HitPelvis
			{
				armor               = 1;
				material            = -1;
				name                = "spine1";
				passThrough         = 0.1;
				radius              = 0.15;
				explosionShielding  = 1;
				visual              = "injury_body";
				minimalHit          = 0.01;
			};
			class HitDiaphragm: HitAbdomen
			{
				armor               = 1;
				material            = -1;
				name                = "spine2";
				passThrough         = 0.1;
				radius              = 0.15;
				explosionShielding  = 6;
				visual              = "injury_body";
				minimalHit          = 0.01;
			}
			class HitChest: HitDiaphragm
			{
				armor               = 1;
				material            = -1;
				name                = "spine3";
				passThrough         = 0.1;
				radius              = 0.15;
				explosionShielding  = 6;
				visual              = "injury_body";
				minimalHit          = 0.01;
			};
			class HitBody: HitChest
			{
				armor               = 1000; //not supposed to take damage directly
				material            = -1;
				name                = "body";
				passThrough         = 0.1;
				radius              = 0.16;
				explosionShielding  = 6;
				visual              = "injury_body";
				minimalHit          = 0.01;
				depends             = "HitPelvis max HitAbdomen max HitDiaphragm max HitChest";
			};
			class HitArms: HitHands
			{
				armor               = 1;
				material            = -1;
				name                = "arms";
				passThrough         = 1;
				radius              = 0.1;
				explosionShielding  = 1;
				visual              = "injury_hands";
				minimalHit          = 0.01;
			};
			class HitHands: HitArms
			{
				armor               = 1;
				material            = -1;
				name                = "hands";
				passThrough         = 1;
				radius              = 0.1;
				explosionShielding  = 1;
				visual              = "injury_hands";
				minimalHit          = 0.01;
				depends             = "HitArms";
			};
			class HitLegs: HitLegs
			{
				armor               = 1;
				material            = -1;
				name                = "legs";
				passThrough         = 1;
				radius              = 0.12;
				explosionShielding  = 1;
				visual              = "injury_legs";
				minimalHit          = 0.01;
			};
		};

		armor= 2;//keep constant so that the hit point armor remains on the same scale
		armorStructural= 0.4;// [*] must be adjusted for each model to achieve consistent total damage results
		explosionShielding = 0.04;// [*] for consistent explosive damage after adjusting = ( armorStructural / 10 )
		minTotalDamageThreshold = 0.001;//minimalHit for total damage
		impactDamageMultiplier= 0.5;//multiplier for falling damage
		// * adjusted for each model
	};

	class Civilian2: EPOCH_CAManBase
	{
		class SpeechVariants
		{
			class Default
			{
				speechSingular[] = {"veh_infantry_civilian_s"};
				speechPlural[] = {"veh_infantry_civilian_p"};
			};
		};
		textSingular = "$STR_A3_nameSound_veh_infantry_civilian_s";
		textPlural = "$STR_A3_nameSound_veh_infantry_civilian_p";
		nameSound = "veh_infantry_civilian_s";
		author = "$STR_A3_Bohemia_Interactive";
		_generalMacro = "Civilian";
		side = 3;
		scope = 0;
		displayName = "$STR_DN_CIVILIAN";
		class HitPoints : HitPoints
		{
			class HitHead : HitHead
			{
				armor = 1;
			};
			class HitBody : HitBody
			{
				armor = 2;
			};
			class HitHands : HitHands
			{
				armor = 2;
			};
			class HitLegs : HitLegs
			{
				armor = 2;
			};
			class HitFace : HitFace {};
			class HitNeck : HitNeck {};
			class HitPelvis : HitPelvis {};
			class HitAbdomen : HitAbdomen {};
			class HitDiaphragm : HitDiaphragm {};
			class HitChest : HitChest {};
			class HitArms : HitArms {};

		};
		accuracy = 1.6;
		camouflage = 1.2;
		threat[] = {0,0,0};
		magazines[] = {};
		cost = 100000;
		minHeadTurnAI = -50;
		maxHeadTurnAI = 50;
		formationX = 2;
		formationZ = 5;
		class Wounds
		{
			tex[] = {};
			mat[] = {};
		};
		class EventHandlers;
		primaryAmmoCoef = 0.0;
		secondaryAmmoCoef = 0.0;
		handgunAmmoCoef = 0.0;
	};


	class Civilian: CAManBase
	{
		class SpeechVariants
		{
			class Default
			{
				speechSingular[] = {"veh_infantry_civilian_s"};
				speechPlural[] = {"veh_infantry_civilian_p"};
			};
		};
		textSingular = "$STR_A3_nameSound_veh_infantry_civilian_s";
		textPlural = "$STR_A3_nameSound_veh_infantry_civilian_p";
		nameSound = "veh_infantry_civilian_s";
		author = "$STR_A3_Bohemia_Interactive";
		_generalMacro = "Civilian";
		side = 3;
		scope = 0;
		displayName = "$STR_DN_CIVILIAN";
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
		accuracy = 1.6;
		camouflage = 1.2;
		threat[] = {0,0,0};
		magazines[] = {};
		cost = 100000;
		minHeadTurnAI = -50;
		maxHeadTurnAI = 50;
		formationX = 2;
		formationZ = 5;
		class Wounds
		{
			tex[] = {};
			mat[] = {};
		};
		class EventHandlers;
		primaryAmmoCoef = 0.0;
		secondaryAmmoCoef = 0.0;
		handgunAmmoCoef = 0.0;
	};

	// allow males to wear CIV clothes Females=1
	class Civilian_F: Civilian
	{
		modelsides[] = {3,2,0}; // U_C_Commoner1_1
	};

	class C_man_1: Civilian_F
	{
		modelsides[] = {3,2,0};
		// U_C_Poloshirt_stripped, U_C_Poloshirt_blue, U_C_Poloshirt_burgundy, U_C_Poloshirt_tricolour, U_C_Poloshirt_salmon, U_C_Poloshirt_redwhite
	};

	class C_man_1_1_F: C_man_1
	{
		modelsides[] = {3,2,0}; // U_C_Commoner1_1
	};

	class C_Driver_1_F: C_man_1
	{
		modelsides[] = {3,2,0}; // karts DLC
	};

	class C_man_p_fugitive_F: C_man_1
	{
		modelsides[] = {3,2,0}; // U_C_Poor_1
	};

	class C_man_w_worker_F: C_man_1
	{
		modelsides[] = {3,2,0}; // U_C_WorkerCoveralls
	};

	class C_man_hunter_1_F: C_man_1
	{
		modelsides[] = {3,2,0}; // U_C_HunterBody_grn
	};

	class C_journalist_F: C_man_1
	{
		modelsides[] = {3,2,0}; // U_C_Journalist
	};

	class C_scientist_F: C_man_w_worker_F
	{
		modelsides[] = {3,2,0}; // U_C_Scientist
	};
	class VirtualMan_F;
	class VirtualMan_EPOCH : VirtualMan_F
	{
		displayName = "Epoch Player Slot";
		weapons[] = {};
		class Eventhandlers
		{
			init = "_this call EPOCH_localCleanup;";
		};
	};
	class I_Soldier_base_F;
	class I_Soldier_EPOCH : I_Soldier_base_F
	{
		author = "$STR_A3_Bohemia_Interactive";
		_generalMacro = "I_Soldier_EPOCH";
		scope = 2;
		displayName = "Epoch Militia Soldier";
		cost = 90000;
		camouflage = 1.2;
		uniformClass = "U_I_CombatUniform_shortsleeve";
		weapons[] = { "hgun_PDW2000_F", "hgun_ACPC2_F", "Throw", "Put" };
		respawnWeapons[] = { "hgun_PDW2000_F", "hgun_ACPC2_F", "Throw", "Put" };
		Items[] = { "FAK" };
		RespawnItems[] = { "FAK" };
		magazines[] = { "30Rnd_9x21_Mag", "30Rnd_9x21_Mag", "9Rnd_45ACP_Mag", "9Rnd_45ACP_Mag" };
		respawnMagazines[] = { "30Rnd_9x21_Mag", "30Rnd_9x21_Mag", "9Rnd_45ACP_Mag", "9Rnd_45ACP_Mag" };
		linkedItems[] = { "V_24_EPOCH", "H_89_EPOCH", "ItemMap", "ItemCompass", "ItemWatch", "EpochRadio0" };
		respawnLinkedItems[] = { "V_24_EPOCH", "H_89_EPOCH", "ItemMap", "ItemCompass", "ItemWatch", "EpochRadio0" };
	};
	class I_Soldier2_EPOCH : I_Soldier_base_F
	{
		author = "$STR_A3_Bohemia_Interactive";
		_generalMacro = "I_Soldier2_EPOCH";
		scope = 2;
		displayName = "Epoch Militia Guerilla";
		cost = 90000;
		camouflage = 1.2;
		uniformClass = "U_IG_Guerilla2_1";
		weapons[] = { "AKM_EPOCH", "hgun_ACPC2_F", "Throw", "Put" };
		respawnWeapons[] = { "AKM_EPOCH", "hgun_ACPC2_F", "Throw", "Put" };
		Items[] = { "FAK" };
		RespawnItems[] = { "FAK" };
		magazines[] = { "30Rnd_762x39_Mag", "30Rnd_762x39_Mag", "9Rnd_45ACP_Mag", "9Rnd_45ACP_Mag" };
		respawnMagazines[] = { "30Rnd_762x39_Mag", "30Rnd_762x39_Mag", "9Rnd_45ACP_Mag", "9Rnd_45ACP_Mag" };
		linkedItems[] = { "V_24_EPOCH", "H_89_EPOCH", "ItemMap", "ItemCompass", "ItemWatch", "EpochRadio0" };
		respawnLinkedItems[] = { "V_24_EPOCH", "H_89_EPOCH", "ItemMap", "ItemCompass", "ItemWatch", "EpochRadio0" };
	};
	class I_Soldier3_EPOCH : I_Soldier_base_F
	{
		author = "$STR_A3_Bohemia_Interactive";
		_generalMacro = "I_Soldier3_EPOCH";
		scope = 2;
		displayName = "Epoch Militia Ghillie";
		cost = 90000;
		camouflage = 1.4;
		uniformClass = "U_I_GhillieSuit";
		weapons[] = { "srifle_DMR_01_F", "hgun_ACPC2_F", "Throw", "Put" };
		respawnWeapons[] = { "srifle_DMR_01_F", "hgun_ACPC2_F", "Throw", "Put" };
		Items[] = { "FAK" };
		RespawnItems[] = { "FAK" };
		magazines[] = { "10Rnd_762x54_Mag", "10Rnd_762x54_Mag", "9Rnd_45ACP_Mag", "9Rnd_45ACP_Mag" };
		respawnMagazines[] = { "10Rnd_762x54_Mag", "10Rnd_762x54_Mag", "9Rnd_45ACP_Mag", "9Rnd_45ACP_Mag" };
		linkedItems[] = { "V_24_EPOCH", "H_89_EPOCH", "ItemMap", "ItemCompass", "ItemWatch", "EpochRadio0" };
		respawnLinkedItems[] = { "V_24_EPOCH", "H_89_EPOCH", "ItemMap", "ItemCompass", "ItemWatch", "EpochRadio0" };
	};

	#include "CfgVehicles\Players.hpp"
	#include "CfgVehicles\Antagonists.hpp"

	#include "CfgVehicles\Fixes.hpp"


	class Car;
	class Car_F: Car
	{
		class HitPoints
		{
			class HitLFWheel;
			class HitLF2Wheel;
			class HitRFWheel;
			class HitRF2Wheel;
			class HitBody;
			class HitGlass1;
			class HitGlass2;
			class HitGlass3;
			class HitGlass4;
		};
	};

	class C_Hatchback_01_F;
	class C_Hatchback_01_EPOCH: C_Hatchback_01_F
	{
		_generalMacro = "C_Hatchback_01_EPOCH";
		scope = 2;
		crew = "";
		side = 3;

		armor = 40;
		fuelCapacity = 45;
		fuelConsumptionRate = 0.02;
		transportMaxWeapons = 12;
		transportMaxMagazines = 64;
		transportMaxBackpacks = 12;
		maximumLoad = 1500;
		faction = "CIV_F";
		typicalCargo[] = {};
		class TransportItems{};
		textureSelectionIndex[] = {0};
		availableColors[] = {{ "\A3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_CO.paa","\A3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_BASE01_CO.paa","\A3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_BASE02_CO.paa","\A3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_BASE03_CO.paa","\A3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_BASE04_CO.paa","\A3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_BASE05_CO.paa","\A3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_BASE06_CO.paa","\A3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_BASE07_CO.paa","\A3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_BASE08_CO.paa","\A3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_BASE09_CO.paa" }};
		class Eventhandlers{};
	};

	class C_Hatchback_01_sport_F;
	class C_Hatchback_02_EPOCH: C_Hatchback_01_sport_F
	{
		_generalMacro = "C_Hatchback_02_EPOCH";
		scope = 2;
		crew = "";
		side = 3;

		armor = 40;
		fuelCapacity = 45;
		fuelConsumptionRate = 0.03;
		transportMaxWeapons = 12;
		transportMaxMagazines = 64;
		transportMaxBackpacks = 12;
		maximumLoad = 1500;
		faction = "CIV_F";
		typicalCargo[] = {};
		class TransportItems{};
		textureSelectionIndex[] = {0};
		availableColors[] = {{ "\A3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_SPORT01_CO.paa","\A3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_SPORT02_CO.paa","\A3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_SPORT03_CO.paa","\A3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_SPORT04_CO.paa","\A3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_SPORT05_CO.paa","\A3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_SPORT06_CO.paa" }};
		class Eventhandlers{};
	};
	class C_Offroad_01_F;
	class C_Offroad_01_EPOCH: C_Offroad_01_F
	{
		_generalMacro = "C_Offroad_01_EPOCH";
		scope = 2;
		crew = "";
		side = 3;

		armor = 50;
		fuelCapacity = 75;
		fuelConsumptionRate = 0.03;
		maximumLoad = 3500;
		faction = "CIV_F";
		typicalCargo[] = {};
		class TransportItems{};
		textureSelectionIndex[] = {0,1};
		availableColors[] = {{ "\A3\soft_F\Offroad_01\Data\Offroad_01_ext_co.paa","\A3\soft_F\Offroad_01\Data\Offroad_01_ext_BASE01_CO.paa","\A3\soft_F\Offroad_01\Data\Offroad_01_ext_BASE02_CO.paa","\A3\soft_F\Offroad_01\Data\Offroad_01_ext_BASE03_CO.paa","\A3\soft_F\Offroad_01\Data\Offroad_01_ext_BASE04_CO.paa","\A3\soft_F\Offroad_01\Data\Offroad_01_ext_BASE05_CO.paa" }};
		class Eventhandlers{};
	};
	class C_Quadbike_01_F;
	class C_Quadbike_01_EPOCH: C_Quadbike_01_F
	{
		_generalMacro = "C_Quadbike_01_EPOCH";
		scope = 2;
		crew = "";
		side = 3;

		armor = 30;
		fuelCapacity = 30;
		fuelConsumptionRate = 0.01;
		maximumLoad = 600;
		faction = "CIV_F";
		typicalCargo[] = {};
		class TransportItems{};
		textureSelectionIndex[] = {0,1};
		availableColors[] = {{ "\A3\Soft_F_Beta\Quadbike_01\Data\Quadbike_01_CIV_BLACK_CO.paa","\A3\Soft_F_Beta\Quadbike_01\Data\Quadbike_01_CIV_BLUE_CO.paa","\A3\Soft_F_Beta\Quadbike_01\Data\Quadbike_01_CIV_RED_CO.paa","\A3\Soft_F_Beta\Quadbike_01\Data\Quadbike_01_CIV_WHITE_CO.paa" },{ "\A3\Soft_F_Beta\Quadbike_01\Data\Quadbike_01_wheel_CIVBLACK_CO.paa","\A3\Soft_F_Beta\Quadbike_01\Data\Quadbike_01_wheel_CIVBLUE_CO.paa","\A3\Soft_F_Beta\Quadbike_01\Data\Quadbike_01_wheel_CIVRED_CO.paa","\A3\Soft_F_Beta\Quadbike_01\Data\Quadbike_01_wheel_CIVWHITE_CO.paa" }};
		class Eventhandlers{};
		class UserActions
		{
			class PressXToFlipTheThing
			{
				displayNameDefault = "Flip ATV";
				displayName = "Flip ATV";
				position = "";
				radius = 2.7;
				onlyForPlayer = 1;
				condition = "alive this && not canmove this && crew this isEqualTo []";
				statement = "this setvectorup [0,0,1]";
			};
		};
	};
	class C_SUV_01_F;
	class C_SUV_01_EPOCH: C_SUV_01_F
	{
		_generalMacro = "C_SUV_01_EPOCH";
		scope = 2;
		crew = "";
		side = 3;

		armor = 45;
		fuelCapacity = 45;
		fuelConsumptionRate = 0.02;
		transportMaxWeapons = 12;
		transportMaxMagazines = 64;
		transportMaxBackpacks = 12;
		maximumLoad = 2000;
		faction = "CIV_F";
		typicalCargo[] = {};
		class TransportItems{};
		textureSelectionIndex[] = {0};
		availableColors[] = {{ "\A3\Soft_F_Gamma\SUV_01\Data\SUV_01_ext_CO.paa","\A3\Soft_F_Gamma\SUV_01\Data\SUV_01_ext_02_CO.paa","\A3\Soft_F_Gamma\SUV_01\Data\SUV_01_ext_03_CO.paa","\A3\Soft_F_Gamma\SUV_01\Data\SUV_01_ext_04_CO.paa" }};
		class Eventhandlers{};
	};
	class C_Rubberboat;
	class C_Rubberboat_EPOCH: C_Rubberboat
	{
		_generalMacro = "C_Rubberboat_EPOCH";
		scope = 2;
		crew = "";
		side = 3;
		faction = "CIV_F";
		maximumLoad = 500;
		typicalCargo[] = {};
		class TransportItems{};
		hiddenSelectionsTextures[] = {"\A3\boat_F\Boat_Transport_01\data\Boat_Transport_01_civilian_CO.paa"};
		class Eventhandlers{};

		class UserActions
		{
			class PushTheThing
			{
				displayNameDefault = "Push";
				displayName = "Push";
				position = "";
				radius = 5;
				onlyForPlayer = 1;
				condition = "alive this && crew this isEqualTo [] && local this && isTouchingGround player";
				statement = "_vel = velocity this; _dir = getDir player; this setVelocity[(_vel select 0)+(sin _dir * 2),(_vel select 1)+(cos _dir * 2),(_vel select 2)]; ";
			};
		};
	};
	class O_Boat_Transport_01_F;
	class C_Rubberboat_02_EPOCH: O_Boat_Transport_01_F
	{
		_generalMacro = "C_Rubberboat_02_EPOCH";
		scope = 2;
		crew = "";
		side = 3;
		faction = "CIV_F";
		maximumLoad = 500;
		typicalCargo[] = {};
		class TransportItems{};
		hiddenSelectionsTextures[] = {"\A3\boat_F\Boat_Transport_01\data\Boat_Transport_01_OPFOR_CO.paa"};
		class Eventhandlers{};

		class UserActions
		{
			class PushTheThing
			{
				displayNameDefault = "Push";
				displayName = "Push";
				position = "";
				radius = 5;
				onlyForPlayer = 1;
				condition = "alive this && crew this isEqualTo [] && local this && isTouchingGround player";
				statement = "_vel = velocity this; _dir = getDir player; this setVelocity[(_vel select 0)+(sin _dir * 2),(_vel select 1)+(cos _dir * 2),(_vel select 2)]; ";
			};
		};
	};
	class O_Lifeboat;
	class C_Rubberboat_03_EPOCH: O_Lifeboat
	{
		_generalMacro = "C_Rubberboat_03_EPOCH";
		scope = 2;
		crew = "";
		side = 3;
		faction = "CIV_F";
		maximumLoad = 500;
		typicalCargo[] = {};
		class TransportItems{};
		hiddenSelectionsTextures[] = {"\A3\boat_F\Boat_Transport_01\data\Boat_Transport_01_rescue_CO.paa"};
		class Eventhandlers{};

		class UserActions
		{
			class PushTheThing
			{
				displayNameDefault = "Push";
				displayName = "Push";
				position = "";
				radius = 5;
				onlyForPlayer = 1;
				condition = "alive this && crew this isEqualTo [] && local this && isTouchingGround player";
				statement = "_vel = velocity this; _dir = getDir player; this setVelocity[(_vel select 0)+(sin _dir * 2),(_vel select 1)+(cos _dir * 2),(_vel select 2)]; ";
			};
		};
	};
	class I_Boat_Transport_01_F;
	class C_Rubberboat_04_EPOCH: I_Boat_Transport_01_F
	{
		_generalMacro = "C_Rubberboat_04_EPOCH";
		scope = 2;
		crew = "";
		side = 3;
		faction = "CIV_F";
		maximumLoad = 500;
		typicalCargo[] = {};
		class TransportItems{};
		hiddenSelectionsTextures[] = {"\A3\boat_F\Boat_Transport_01\data\Boat_Transport_01_INDP_CO.paa"};
		class Eventhandlers{};

		class UserActions
		{
			class PushTheThing
			{
				displayNameDefault = "Push";
				displayName = "Push";
				position = "";
				radius = 5;
				onlyForPlayer = 1;
				condition = "alive this && crew this isEqualTo [] && local this && isTouchingGround player";
				statement = "_vel = velocity this; _dir = getDir player; this setVelocity[(_vel select 0)+(sin _dir * 2),(_vel select 1)+(cos _dir * 2),(_vel select 2)]; ";
			};
		};
	};
	class C_Van_01_box_F;
	class C_Van_01_box_EPOCH: C_Van_01_box_F
	{
		_generalMacro = "C_Van_01_box_EPOCH";
		scope = 2;
		crew = "";
		side = 3;

		armor = 80;
		fuelCapacity = 55;
		fuelConsumptionRate = 0.02;
		maximumLoad = 4000;
		faction = "CIV_F";
		typicalCargo[] = {};
		class TransportItems{};
		textureSelectionIndex[] = {0};
		availableColors[] = {{ "\A3\soft_f_gamma\van_01\Data\van_01_ext_CO.paa","\A3\soft_f_gamma\van_01\Data\van_01_ext_red_CO.paa" }};
		class Eventhandlers{};
	};
	class C_Van_01_transport_F;
	class C_Van_01_transport_EPOCH: C_Van_01_transport_F
	{
		scope = 2;
		crew = "";
		side = 3;

		armor = 80;
		fuelCapacity = 55;
		fuelConsumptionRate = 0.02;
		maximumLoad = 4000;
		faction = "CIV_F";
		typicalCargo[] = {};
		class TransportItems{};
		textureSelectionIndex[] = {0};
		availableColors[] = {{ "\A3\soft_f_gamma\van_01\Data\van_01_ext_CO.paa","\A3\soft_f_gamma\van_01\Data\van_01_ext_red_CO.paa" }};
		class Eventhandlers{};
	};
	class C_Boat_Civil_01_F;
	class C_Boat_Civil_01_EPOCH: C_Boat_Civil_01_F
	{
		scope = 2;
		crew = "";
		side = 3;
		faction = "CIV_F";
		maximumLoad = 800;
		typicalCargo[] = {};
		class TransportItems{};
		class Eventhandlers{};

		class UserActions
		{
			class PushTheThing
			{
				displayNameDefault = "Push";
				displayName = "Push";
				position = "";
				radius = 5;
				onlyForPlayer = 1;
				condition = "alive this && crew this isEqualTo [] && local this && isTouchingGround player";
				statement = "_vel = velocity this; _dir = getDir player; this setVelocity[(_vel select 0)+(sin _dir * 2),(_vel select 1)+(cos _dir * 2),(_vel select 2)]; ";
			};
		};
	};
	class C_Boat_Civil_01_police_F;
	class C_Boat_Civil_01_police_EPOCH: C_Boat_Civil_01_police_F
	{
		scope = 2;
		crew = "";
		side = 3;
		faction = "CIV_F";
		maximumLoad = 800;
		typicalCargo[] = {};
		class TransportItems{};
		class Eventhandlers{};

		class UserActions
		{
			class PushTheThing
			{
				displayNameDefault = "Push";
				displayName = "Push";
				position = "";
				radius = 5;
				onlyForPlayer = 1;
				condition = "alive this && crew this isEqualTo [] && local this && isTouchingGround player";
				statement = "_vel = velocity this; _dir = getDir player; this setVelocity[(_vel select 0)+(sin _dir * 2),(_vel select 1)+(cos _dir * 2),(_vel select 2)]; ";
			};
		};
	};
	class C_Boat_Civil_01_rescue_F;
	class C_Boat_Civil_01_rescue_EPOCH: C_Boat_Civil_01_rescue_F
	{
		scope = 2;
		crew = "";
		side = 3;
		faction = "CIV_F";
		maximumLoad = 600;
		typicalCargo[] = {};
		class TransportItems{};
		class Eventhandlers{};

		class UserActions
		{
			class PushTheThing
			{
				displayNameDefault = "Push";
				displayName = "Push";
				position = "";
				radius = 5;
				onlyForPlayer = 1;
				condition = "alive this && crew this isEqualTo [] && local this && isTouchingGround player";
				statement = "_vel = velocity this; _dir = getDir player; this setVelocity[(_vel select 0)+(sin _dir * 2),(_vel select 1)+(cos _dir * 2),(_vel select 2)]; ";
			};
		};
	};
	class B_Heli_Light_01_F;
	class B_Heli_Light_01_EPOCH: B_Heli_Light_01_F
	{
		scope = 2;
		crew = "";
		side = 3;

		armor = 35;

		faction = "CIV_F";
		maximumLoad = 1000;
		commanderCanSee = 2 + 16 + 32;
		gunnerCanSee = 2 + 16 + 32;
		driverCanSee = 2 + 16 + 32;
		typicalCargo[] = {};
		class TransportItems{};
		class Eventhandlers{};
	};
	class B_Heli_Transport_01_F;
	class B_Heli_Transport_01_EPOCH: B_Heli_Transport_01_F
	{
		scope = 2;
		crew = "";
		side = 3;
		armor = 60;
		faction = "CIV_F";
		maximumLoad = 3000;
		commanderCanSee = 2 + 16 + 32;
		gunnerCanSee = 2 + 16 + 32;
		driverCanSee = 2 + 16 + 32;
		typicalCargo[] = {};
		class TransportItems{};
		class Eventhandlers{};
	};
	class B_Heli_Transport_01_camo_F;
	class B_Heli_Transport_01_camo_EPOCH: B_Heli_Transport_01_camo_F
	{
		scope = 2;
		crew = "";
		side = 3;

		armor = 60;

		faction = "CIV_F";
		maximumLoad = 3000;
		commanderCanSee = 2 + 16 + 32;
		gunnerCanSee = 2 + 16 + 32;
		driverCanSee = 2 + 16 + 32;
		typicalCargo[] = {};
		class TransportItems{};
		class Eventhandlers{};
	};
	class B_SDV_01_F;
	class B_SDV_01_EPOCH: B_SDV_01_F
	{
		scope = 2;
		crew = "";
		side = 3;
		faction = "CIV_F";
		maximumLoad = 500;
		typicalCargo[] = {};
		class TransportItems{};
		class Eventhandlers{};
		class UserActions
		{
			class PushTheThing
			{
				displayNameDefault = "Push";
				displayName = "Push";
				position = "";
				radius = 5;
				onlyForPlayer = 1;
				condition = "alive this && crew this isEqualTo [] && local this && isTouchingGround player";
				statement = "_vel = velocity this; _dir = getDir player; this setVelocity[(_vel select 0)+(sin _dir * 2),(_vel select 1)+(cos _dir * 2),(_vel select 2)]; ";
			};
		};
	};

	class B_MRAP_01_F;
	class B_MRAP_01_EPOCH : B_MRAP_01_F
	{
		scope = 2;
		crew = "";
		side = 3;
		armor = 75;
		faction = "CIV_F";
		maximumLoad = 3500;
		typicalCargo[] = {};
		class TransportItems{};
		class Eventhandlers{};
	};

	class I_MRAP_03_F;
	class I_MRAP_03_EPOCH : I_MRAP_03_F
	{
		author = "$STR_A3_Bohemia_Interactive";
		_generalMacro = "I_MRAP_03_EPOCH";
		scope = 2;
		crew = "";
		side = 3;
		armor = 75;
		faction = "CIV_F";
		maximumLoad = 3500;
		typicalCargo[] = {};
		class TransportItems{};
		class Eventhandlers{};

		class RenderTargets
		{
			class commander_display
			{
				renderTarget = "rendertarget0";
				class CameraView1
				{
					pointPosition = "PIP0_pos";
					pointDirection = "PIP0_dir";
					renderVisionMode = 0;
					renderQuality = 2;
					fov = 0.5;
				};
			};
			class driver_display
			{
				renderTarget = "rendertarget2";
				class CameraView1
				{
					pointPosition = "PIP2_pos";
					pointDirection = "PIP2_dir";
					renderVisionMode = 0;
					renderQuality = 2;
					fov = 0.6;
				};
			};
			class mirrorL
			{
				renderTarget = "rendertarget4";
				class CameraView1
				{
					pointPosition = "PIP4_pos";
					pointDirection = "PIP4_dir";
					renderVisionMode = 4;
					renderQuality = 2;
					fov = 0.35;
				};
			};
			class mirrorR
			{
				renderTarget = "rendertarget5";
				class CameraView1
				{
					pointPosition = "PIP5_pos";
					pointDirection = "PIP5_dir";
					renderVisionMode = 4;
					renderQuality = 2;
					fov = 0.35;
				};
			};
		};

	};

	class B_Truck_01_transport_F;
	class B_Truck_01_transport_EPOCH: B_Truck_01_transport_F
	{
		scope = 2;
		crew = "";
		side = 3;

		armor = 80;
		fuelCapacity = 350;
		fuelConsumptionRate = 26;
		maximumLoad = 6000;
		transportMaxBackpacks = 64;
		transportMaxMagazines = 256;
		transportMaxWeapons = 64;
		faction = "CIV_F";
		typicalCargo[] = {};
		class TransportItems{};
		class Eventhandlers{};
	};
	class B_G_Offroad_01_armed_F;
	class B_G_Offroad_01_armed_EPOCH: B_G_Offroad_01_armed_F
	{
		scope = 2;
		crew = "";
		side = 3;

		armor = 80;
		fuelCapacity = 350;
		fuelConsumptionRate = 26;
		maximumLoad = 3500;
		faction = "CIV_F";
		typicalCargo[] = {};
		class TransportItems{};
		class Eventhandlers{};
	};
	class B_Truck_01_covered_F;
	class B_Truck_01_covered_EPOCH: B_Truck_01_covered_F
	{
		scope = 2;
		crew = "";
		side = 3;

		armor = 80;
		fuelCapacity = 350;
		fuelConsumptionRate = 26;
		maximumLoad = 6000;
		faction = "CIV_F";
		typicalCargo[] = {};
		class TransportItems{};
		class Eventhandlers{};
	};
	class B_Truck_01_mover_F;
	class B_Truck_01_mover_EPOCH: B_Truck_01_mover_F
	{
		scope = 2;
		crew = "";
		side = 3;

		armor = 80;
		fuelCapacity = 350;
		fuelConsumptionRate = 26;
		maximumLoad = 4000;
		faction = "CIV_F";
		typicalCargo[] = {};
		class TransportItems{};
		class Eventhandlers{};
	};
	class B_Truck_01_box_F;
	class B_Truck_01_box_EPOCH: B_Truck_01_box_F
	{
		scope = 2;
		crew = "";
		side = 3;
		faction = "CIV_F";

		armor = 80;
		fuelCapacity = 350;
		fuelConsumptionRate = 26;
		maximumLoad = 6000;
		transportMaxBackpacks = 64;
		transportMaxMagazines = 256;
		transportMaxWeapons = 64;
		typicalCargo[] = {};
		class TransportItems{};
		class Eventhandlers{};
	};
	class O_Truck_02_covered_F;
	class O_Truck_02_covered_EPOCH: O_Truck_02_covered_F
	{
		scope = 2;
		crew = "";
		side = 3;

		armor = 45;
		fuelCapacity = 350;
		fuelConsumptionRate = 26;
		maximumLoad = 5000;
		faction = "CIV_F";
		typicalCargo[] = {};
		class TransportItems{};
		class Eventhandlers{};
	};
	class O_Truck_02_transport_F;
	class O_Truck_02_transport_EPOCH: O_Truck_02_transport_F
	{
		scope = 2;
		crew = "";
		side = 3;

		armor = 45;
		fuelCapacity = 350;
		fuelConsumptionRate = 26;
		maximumLoad = 5000;
		faction = "CIV_F";
		typicalCargo[] = {};
		class TransportItems{};
		class Eventhandlers{};
	};
	class O_Truck_03_covered_F;
	class O_Truck_03_covered_EPOCH: O_Truck_03_covered_F
	{
		scope = 2;
		crew = "";
		side = 3;

		armor = 64;
		fuelCapacity = 250;
		fuelConsumptionRate = 36;
		maximumLoad = 5000;
		faction = "CIV_F";
		typicalCargo[] = {};
		class TransportItems{};
		class Eventhandlers{};
	};
	class O_Truck_02_box_F;
	class O_Truck_02_box_EPOCH: O_Truck_02_box_F
	{
		scope = 2;
		crew = "";
		side = 3;

		transportRepair = 0;
		armor = 45;
		fuelCapacity = 350;
		fuelConsumptionRate = 26;
		maximumLoad = 5000;
		transportMaxBackpacks = 64;
		transportMaxMagazines = 256;
		transportMaxWeapons = 64;
		faction = "CIV_F";
		typicalCargo[] = {};
		class TransportItems{};
		class Eventhandlers{};
	};
	class O_Heli_Light_02_unarmed_F;
	class O_Heli_Light_02_unarmed_EPOCH: O_Heli_Light_02_unarmed_F
	{
		scope = 2;
		crew = "";
		side = 3;

		armor = 30;
		maximumLoad = 3000;
		faction = "CIV_F";
		commanderCanSee = 2 + 16 + 32;
		gunnerCanSee = 2 + 16 + 32;
		driverCanSee = 2 + 16 + 32;
		typicalCargo[] = {};
		class TransportItems{};
		class Eventhandlers{};
	};
	class I_Heli_Transport_02_F;
	class I_Heli_Transport_02_EPOCH: I_Heli_Transport_02_F
	{
		scope = 2;
		crew = "";
		side = 3;

		armor = 50;
		maximumLoad = 5000;
		faction = "CIV_F";
		commanderCanSee = 2 + 16 + 32;
		gunnerCanSee = 2 + 16 + 32;
		driverCanSee = 2 + 16 + 32;
		typicalCargo[] = {};
		class TransportItems{};
		class Eventhandlers{};
	};
	class I_Heli_light_03_unarmed_F;
	class I_Heli_light_03_unarmed_EPOCH: I_Heli_light_03_unarmed_F
	{
		scope = 2;
		crew = "";
		side = 3;

		armor = 50;
		maximumLoad = 2000;
		faction = "CIV_F";
		commanderCanSee = 2 + 16 + 32;
		gunnerCanSee = 2 + 16 + 32;
		driverCanSee = 2 + 16 + 32;
		typicalCargo[] = {};
		class TransportItems{};
		class Eventhandlers{};
		class RenderTargets{};
	};
	class O_Heli_Transport_04_F;
	class O_Heli_Transport_04_EPOCH : O_Heli_Transport_04_F
	{
		scope = 2;
		crew = "";
		side = 3;
		faction = "CIV_F";
		maximumLoad = 4000;
		commanderCanSee = 2 + 16 + 32;
		gunnerCanSee = 2 + 16 + 32;
		driverCanSee = 2 + 16 + 32;
		typicalCargo[] = {};
		class TransportItems{};
		class Eventhandlers{};
		class RenderTargets{};
	};
	class O_Heli_Transport_04_bench_F;
	class O_Heli_Transport_04_bench_EPOCH : O_Heli_Transport_04_bench_F
	{
		scope = 2;
		crew = "";
		side = 3;
		faction = "CIV_F";
		maximumLoad = 4000;
		commanderCanSee = 2 + 16 + 32;
		gunnerCanSee = 2 + 16 + 32;
		driverCanSee = 2 + 16 + 32;
		typicalCargo[] = {};
		class TransportItems{};
		class Eventhandlers{};
		class RenderTargets{};
	};
	class O_Heli_Transport_04_box_F;
	class O_Heli_Transport_04_box_EPOCH : O_Heli_Transport_04_box_F
	{
		scope = 2;
		crew = "";
		side = 3;
		faction = "CIV_F";
		maximumLoad = 4000;
		commanderCanSee = 2 + 16 + 32;
		gunnerCanSee = 2 + 16 + 32;
		driverCanSee = 2 + 16 + 32;
		typicalCargo[] = {};
		class TransportItems{};
		class Eventhandlers{};
		class RenderTargets{};
	};
	class O_Heli_Transport_04_covered_F;
	class O_Heli_Transport_04_covered_EPOCH : O_Heli_Transport_04_covered_F
	{
		scope = 2;
		crew = "";
		side = 3;
		faction = "CIV_F";
		maximumLoad = 4000;
		commanderCanSee = 2 + 16 + 32;
		gunnerCanSee = 2 + 16 + 32;
		driverCanSee = 2 + 16 + 32;
		typicalCargo[] = {};
		class TransportItems{};
		class Eventhandlers{};
		class RenderTargets{};
	};
	class B_Heli_Transport_03_unarmed_F;
	class B_Heli_Transport_03_unarmed_EPOCH : B_Heli_Transport_03_unarmed_F
	{
		scope = 2;
		crew = "";
		side = 3;
		faction = "CIV_F";
		maximumLoad = 6000;
		commanderCanSee = 2 + 16 + 32;
		gunnerCanSee = 2 + 16 + 32;
		driverCanSee = 2 + 16 + 32;
		typicalCargo[] = {};
		class TransportItems{};
		class Eventhandlers{};
		class RenderTargets{};
	};

	class C_Heli_Light_01_civil_F;
	class C_Heli_Light_01_civil_EPOCH : C_Heli_Light_01_civil_F
	{
		scope = 2;
		crew = "";
		side = 3;
		faction = "CIV_F";
		maximumLoad = 1000;
		commanderCanSee = 2 + 16 + 32;
		gunnerCanSee = 2 + 16 + 32;
		driverCanSee = 2 + 16 + 32;
		typicalCargo[] = {};
		class TransportItems{};
		class Eventhandlers{};
		class RenderTargets{};
		textureSelectionIndex[] = { 0 };
		availableColors[] = { { "A3\Air_f\Heli_Light_01\Data\Heli_Light_01_ext_co.paa", "\a3\air_f\Heli_Light_01\Data\heli_light_01_ext_blue_co.paa", "\a3\air_f\Heli_Light_01\Data\heli_light_01_ext_co.paa", "\a3\air_f\Heli_Light_01\Data\heli_light_01_ext_ion_co.paa", "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_blueLine_co.paa", "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_digital_co.paa", "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_elliptical_co.paa", "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_furious_co.paa", "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_graywatcher_co.paa", "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_jeans_co.paa", "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_light_co.paa", "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_shadow_co.paa", "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_sheriff_co.paa", "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_speedy_co.paa", "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_sunset_co.paa", "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_vrana_co.paa", "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_wasp_co.paa", "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_wave_co.paa" } };
	};




	class LandVehicle;
	class Tank: LandVehicle
	{
		class NewTurret;
		class Sounds;
		class HitPoints;
	};
	class Tank_F: Tank
	{
		class Turrets
		{
			class MainTurret: NewTurret
			{
				class Turrets
				{
					class CommanderOptics;
				};
			};
		};
		class AnimationSources;
		class ViewPilot;
		class ViewOptics;
		class ViewCargo;
		class HeadLimits;
		class HitPoints: HitPoints
		{
			class HitHull;
			class HitEngine;
			class HitLTrack;
			class HitRTrack;
		};
		class Sounds: Sounds
		{
			class Engine;
			class Movement;
		};
	};

	class ThingX;
	class FloatingStructure_F;
	class Bobber_EPOCH : FloatingStructure_F
	{
		author = "Axle - EpochMod";
		_generalMacro = "Bobber_EPOCH";
		scope = 2;
		displayName = "Bobber";
		model = "\x\addons\a3_epoch_assets_3\fishing\bobber.p3d";

		canFloat = 1;
		waterLeakiness = 0;
		waterResistanceCoef = 0.8;
		waterAngularDampingCoef = 10;
		destrType = "DestructNo";

		mapSize = 0.14;
		icon = "iconObject_2x3";
		cost = 1000;
	};

	class Land_MPS_EPOCH : ThingX
	{
		mapSize = 0.14;
		author = "$STR_A3_Bohemia_Interactive";
		_generalMacro = "Land_MPS_EPOCH";
		scope = 2;
		displayName = "$STR_A3_cfgVehicles_Land_MobilePhone_smart_F0";
		model = "\A3\Structures_F\Items\Electronics\MobilePhone_smart_F.p3d";
		destrType = "DestructNo";
		icon = "iconObject_2x3";
		cost = 1000;
		hiddenSelections[] = { "camo" };
		hiddenSelectionsTextures[] = { "\A3\Structures_F\Items\Electronics\Data\Electronics_screens_mobilePhone_smart_CO.paa" };
		hiddenSelectionsMaterials[] = { "\A3\Structures_F\Items\Electronics\Data\electronics_screens.rvmat" };
		class UserActions
		{
			class open_door_l
			{
				displayName = "Take Krypto";
				position = "left";
				radius = 9;
				onlyForPlayer = 0;
				condition = "(this getVariable [""Crypto"",0]) > 0";
				statement = "this call EPOCH_takeCrypto;";
			};
		};
	};

	class Constructions_modular_F: ThingX
	{
		mapSize = 1.27;
		author = "Epoch";
		_generalMacro = "Constructions_base_F";
		scope = 0;
		displayName = "";
		model = "\A3\Weapons_F\empty.p3d";
		icon = "iconObject_5x4";
		armor = 1000;
		vehicleclass = "Epoch_objects";
		destrType = "DestructNo";
		cost = 1000;
		interactMode = 1;
	};

	class Spike_TRAP_SIM_EPOCH: Constructions_modular_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\sticks.p3d";
		displayName = "Spike Trap (SIM)";
		simulClass = "Spike_TRAP_SIM_EPOCH";
		staticClass = "Spike_TRAP_EPOCH";
		GhostPreview = "Spike_TRAP_EPOCH";
		limitNearby = 1;
		bypassJammer = 1;
	};

	class Metal_TRAP_SIM_EPOCH: Constructions_modular_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\sticks.p3d";
		displayName = "Metal Trap (SIM)";
		simulClass = "Metal_TRAP_SIM_EPOCH";
		staticClass = "Metal_TRAP_EPOCH";
		GhostPreview = "Metal_TRAP_EPOCH";
		limitNearby = 1;
		bypassJammer = 1;
	};

	class TankTrap_SIM_EPOCH: Constructions_modular_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets_3\CfgVehicles\Defense\tank_trap.p3d";
		displayName = "Tank Trap (SIM)";
		simulClass = "TankTrap_SIM_EPOCH";
		staticClass = "TankTrap_EPOCH";
		GhostPreview = "TankTrap_EPOCH";
		limitNearby = 4;
		bypassJammer = 1;
	};

	class Hesco3_SIM_EPOCH : Constructions_modular_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets_3\CfgVehicles\Defense\hesco.p3d";
		displayName = "Hesco Wide (SIM)";
		simulClass = "Hesco3_SIM_EPOCH";
		staticClass = "Hesco3_EPOCH";
		GhostPreview = "Hesco3_Ghost_EPOCH";
		snapType = "snapPointsPara";
		snapPointsPara[] = { "C", "E", "W" };
		allowedSnapPoints[] = { "C", "E", "W" };
		allowedSnapObjects[] = { "Hesco3_EPOCH" };
		energyCost = 0.4;
		slingLoadCargoMemoryPoints[] = {};
		limitNearby = 4;
		bypassJammer = 1;

		/*
		hiddenSelections[] = { "Camo" };
		hiddenSelectionsTextures[] = { "\x\addons\a3_epoch_assets\textures\hesco\hesco_co.paa" };
		hiddenSelectionsMaterials[] = { "\x\addons\a3_epoch_assets\textures\hesco\hesco.rvmat" };
		*/
	};

	class SapperHead_SIM_EPOCH: Constructions_modular_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets_3\CfgVehicles\Characters\sapper_head.p3d";
		displayName = "Sapper Head";
	};
	class SapperCorpse_SIM_EPOCH: Constructions_modular_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets_3\CfgVehicles\Characters\Sapper_corpse.p3d";
		displayName = "Sapper Corpse";
	};
	class Secure_Storage_Temp : Constructions_modular_F {};
	class LockBox_SIM_EPOCH : Secure_Storage_Temp
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets_1\models\lockbox.p3d";
		displayName = "Lockbox";
		simulClass = "LockBox_SIM_EPOCH";
		staticClass = "LockBox_EPOCH";
		GhostPreview = "LockBox_EPOCH";
		limitNearby = 2;
		bypassJammer = 1;
	};
	class Safe_SIM_EPOCH : Secure_Storage_Temp
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets_1\models\safe.p3d";
		displayName = "Safe";
		simulClass = "Safe_SIM_EPOCH";
		staticClass = "Safe_EPOCH";
		GhostPreview = "Safe_EPOCH";
		limitNearby = 2;
		bypassJammer = 1;
	};
	class Fireplace_SIM_EPOCH : Constructions_modular_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets_2\fireplace.p3d";
		displayName = "Empty Fireplace (SIM)";
		simulClass = "Fireplace_SIM_EPOCH";
		staticClass = "Fireplace_EPOCH";
		GhostPreview = "Fireplace_EPOCH";
		isTemporary = 1;
	};
	class Jack_SIM_EPOCH : Constructions_modular_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\jack.p3d";
		displayName = "Jack";
		simulClass = "Jack_SIM_EPOCH";
		staticClass = "Jack_EPOCH";
		GhostPreview = "Jack_EPOCH";

		class AnimationSources
		{
			class raise
			{
				source = "user";
				animPeriod = 2;
				initPhase = 0;
			};
			class pump
			{
				source = "user";
				animPeriod = 2;
				initPhase = 0;
				sound = "jack_pump";
			};

		};
		class UserActions
		{
			class Open_left
			{
				displayName = "Raise";
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 3;
				condition = "this animationPhase ""raise"" < 0.5";
				statement = "this animate [""raise"", ((this animationPhase ""raise"")+0.1)]; this animate [""pump"", ((this animationPhase ""pump"")+0.1)];";
			};
			class Close_left : Open_left
			{
				displayName = "Lower";
				condition = "this animationPhase ""raise"" >= 0.1";
				statement = "this animate [""raise"", ((this animationPhase ""raise"")-0.1)]; this animate [""pump"", ((this animationPhase ""pump"")-0.1)];";
			};
			class Pack
			{
				displayName = "Pickup";
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 3;
				condition = "this animationPhase ""raise"" == 0";
				statement = "EPOCH_packJack_PVS = [this,player,Epoch_personalToken]; publicVariableServer ""EPOCH_packJack_PVS"";";
			};
		};

	};
	class WoodRamp_SIM_EPOCH : Constructions_modular_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\Wood_Ramp.p3d";
		displayName = "Wood Ramp";
		simulClass = "WoodRamp_SIM_EPOCH";
		staticClass = "WoodRamp_EPOCH";
		GhostPreview = "WoodRamp_Ghost_EPOCH";
		snapPointsPara[] = {};
		snapPointsPerp[] = {};
		allowedSnapPoints[] = { "NF", "SF", "EF", "WF", "CB" };
		allowedSnapObjects[] = { "Const_floors_static_F", "Constructions_foundation_F" };
		energyCost = 0.2;
		slingLoadCargoMemoryPoints[] = { "N", "S", "E", "W" };
	};


	class CinderWallHalf_SIM_EPOCH: Constructions_modular_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\cinder_half_SIM.p3d";
		displayName = "Half Cinder Block Wall";
		upgradeBuilding[] = {"CinderWall_EPOCH",{ { "CinderBlocks",4 },{ "MortarBucket",1 } }};
		simulClass = "CinderWallHalf_SIM_EPOCH";
		staticClass = "CinderWallHalf_EPOCH";
		GhostPreview = "CinderWallHalf_Ghost_EPOCH";
		snapType = "snapPointsPara";
		snapPointsPara[] = { "N", "E", "W" };
		allowedSnapPoints[] = { "N", "S", "E", "W" };
		allowedSnapObjects[] = { "Const_Cinder_static_F", "Const_floors_static_F" };
		energyCost = 0.2;
		slingLoadCargoMemoryPoints[] = { "N", "S", "E", "W" };
	};
	class CinderWall_SIM_EPOCH: Constructions_modular_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\cinder_SIM.p3d";
		displayName = "Cinder Block Wall";
		simulClass = "CinderWall_SIM_EPOCH";
		staticClass = "CinderWall_EPOCH";
		GhostPreview = "CinderWall_EPOCH";
		snapType = "snapPointsPara";
		snapPointsPara[] = { "N", "E", "W" };
		allowedSnapPoints[] = { "N", "S", "E", "W" };
		allowedSnapObjects[] = {"Const_Cinder_static_F","Const_floors_static_F"};
		energyCost = 0.4;
		slingLoadCargoMemoryPoints[] = { "N", "S", "E", "W" };
	};
	class CinderWallGarage_SIM_EPOCH : Constructions_modular_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\cGarage_SIM.p3d";
		displayName = "Cinder Block Garage";
		simulClass = "CinderWallGarage_SIM_EPOCH";
		staticClass = "CinderWallGarage_EPOCH";
		GhostPreview = "CinderWallGarage_EPOCH";
		snapType = "snapPointsPara";
		snapPointsPara[] = { "N", "E", "W" };
		allowedSnapPoints[] = { "N", "S", "E", "W" };
		allowedSnapObjects[] = { "Const_Cinder_static_F", "Const_floors_static_F" };
		energyCost = 0.5;
		slingLoadCargoMemoryPoints[] = { "N", "S", "E", "W" };
		class AnimationSources
		{
			class open_left
			{
				source = "user";
				animPeriod = 2;
				initPhase = 0;
				sound = "MetalBigDoorsSound";
			};
			class open_right
			{
				source = "user";
				animPeriod = 2;
				initPhase = 0;
				sound = "MetalOldBigDoorsSound";
			};
			class lock_cGarage
			{
				source = "user";
				animPeriod = 2;
				initPhase = 1;
				sound = "ServoDoorsSound";
			};

		};
		class UserActions
		{
			class Open_left
			{
				displayName = "Open";
				displayNameDefault = "<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 3;
				condition = "(this animationPhase ""open_left"" < 0.5) && (this animationPhase ""lock_cGarage"" < 0.5)";
				statement = "this animate [""open_left"", 1]; this animate [""open_right"", 1]";
			};
			class Close_left : Open_left
			{
				displayName = "Close";
				condition = "this animationPhase ""open_left"" >= 0.5";
				statement = "this animate [""open_left"", 0]; this animate [""open_right"", 0]";
			};

			class Lock_cGarage
			{
				displayName = "Lock";
				displayNameDefault = "<img image='\A3\modules_f\data\iconlock_ca.paa' size='2.5' />";
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 3;
				condition = "(this animationPhase ""open_left"" < 0.5) && (this animationPhase ""lock_cGarage"" < 0.5)";
				statement = "this animate [""lock_cGarage"", 1]";
			};
			class Unlock_cGarage : Lock_cGarage
			{
				displayName = "Unlock";
				displayNameDefault = "<img image='\A3\modules_f\data\iconunlock_ca.paa' size='2.5' />";
				condition = "(this animationPhase ""open_left"" < 0.5) && (this animationPhase ""lock_cGarage"" >= 0.5)";
				statement = "this animate [""lock_cGarage"", 0];";
			};
		};
	};

	class WoodFloor_SIM_EPOCH: Constructions_modular_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\Wooden_Floor.p3d";
		displayName = "Wood Floor";
		simulClass = "WoodFloor_SIM_EPOCH";
		staticClass = "WoodFloor_EPOCH";
		GhostPreview = "WoodFloor_Ghost_EPOCH";
		snapPointsPara[] = {"NF","SF","EF","WF","C","CB"};
		snapPointsPerp[] = {"N","S","E","W","CinN","CinS","CinE","CinW"};
		allowedSnapPoints[] = {"NF","SF","EF","WF","C"};
		allowedSnapObjects[] = {"Const_floors_static_F","Constructions_foundation_F"};
		energyCost = 0.2;
		slingLoadCargoMemoryPoints[] = { "N", "S", "E", "W" };
	};
	class MetalFloor_SIM_EPOCH : Constructions_modular_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets_1\models\metal_floor.p3d";
		displayName = "Metal Floor";
		simulClass = "MetalFloor_SIM_EPOCH";
		staticClass = "MetalFloor_EPOCH";
		GhostPreview = "MetalFloor_Ghost_EPOCH";
		snapPointsPara[] = { "NF", "SF", "EF", "WF", "C", "CB" };
		snapPointsPerp[] = { "N", "S", "E", "W", "CinN", "CinS", "CinE", "CinW" };
		allowedSnapPoints[] = { "NF", "SF", "EF", "WF", "C" };
		allowedSnapObjects[] = { "Const_floors_static_F", "Constructions_foundation_F" };
		energyCost = 0.5;
		slingLoadCargoMemoryPoints[] = { "N", "S", "E", "W" };
	};

	class WoodLargeWall_SIM_EPOCH: Constructions_modular_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\Wooden_Wall_SIM.p3d";
		displayName = "Large Wall";
		upgradeBuilding[] = {"WoodLargeWallCor_EPOCH",{ { "PartGlass",1 } }};
		simulClass = "WoodLargeWall_SIM_EPOCH";
		staticClass = "WoodLargeWall_EPOCH";
		GhostPreview = "WoodLargeWall_Ghost_EPOCH";
		snapPointsPara[] = {"N","E","W"};
		allowedSnapPoints[] = {"N","S","E","W"};
		allowedSnapObjects[] = {"Const_floors_static_F","Const_WoodWalls_static_F"};
		slingLoadCargoMemoryPoints[] = { "N", "S", "E", "W" };
	};

	// lvl 1
	class WoodWall1_SIM_EPOCH : Constructions_modular_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets_3\CfgVehicles\Plywood_Upgrades\plywood_wall\Wooden_Wall_ply.p3d";
		displayName = "Plywood Wall (SIM)";
		simulClass = "WoodWall1_SIM_EPOCH";
		staticClass = "WoodWall1_EPOCH";
		GhostPreview = "WoodWall1_EPOCH";
		snapPointsPara[] = { "N", "E", "W" };
		allowedSnapPoints[] = { "N", "S", "E", "W" };
		allowedSnapObjects[] = { "Const_floors_static_F", "Const_WoodWalls_static_F" };
		energyCost = 0.2;
	};

	// lvl 2
	class WoodLargeWallCor_SIM_EPOCH: Constructions_modular_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\Wooden_Wall_Cor_SIM.p3d";
		displayName = "Wall";
		upgradeBuilding[] = {"WoodLargeWallDoor_EPOCH",{ { "PartGlass",1 } }};
		simulClass = "WoodLargeWallCor_SIM_EPOCH";
		staticClass = "WoodLargeWallCor_EPOCH";
		GhostPreview = "WoodLargeWallCor_EPOCH";
		snapPointsPara[] = {"N","E","W"};
		allowedSnapPoints[] = {"N","S","E","W"};
		allowedSnapObjects[] = {"Const_floors_static_F","Const_WoodWalls_static_F"};
		sections[] = { "camo_cor", "camo" };
		hiddenSelections[] = { "camo_cor", "camo" };
		hiddenSelectionsTextures[] = { "x\addons\a3_epoch_assets\textures\cor\corrugated_co.paa", "x\addons\a3_epoch_assets\textures\plyplank_eco.paa" };
		availableTextures[] = { "\x\addons\a3_epoch_assets\textures\cor\corrugated_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_black_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_blue_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_brown_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_green_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_orange_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_purple_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_red_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_teal_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_yellow_co.paa" };
		energyCost = 0.2;
	};

	// lvl 1
	class WoodWall2_SIM_EPOCH : Constructions_modular_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets_3\CfgVehicles\Plywood_Upgrades\plywood_doorway\Wooden_Wall_Doorway.p3d";
		displayName = "Plywood Wall Doorway (SIM)";
		simulClass = "WoodWall2_SIM_EPOCH";
		staticClass = "WoodWall2_EPOCH";
		snapPointsPara[] = { "N", "E", "W" };
		allowedSnapPoints[] = { "N", "S", "E", "W" };
		allowedSnapObjects[] = { "Const_floors_static_F", "Const_WoodWalls_static_F" };
		energyCost = 0.2;
		slingLoadCargoMemoryPoints[] = { "N", "S", "E", "W" };
	};
	// lvl 2
	class WoodLargeWallDoorway_SIM_EPOCH: Constructions_modular_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\Wooden_Wall_Doorway.p3d";
		displayName = "Wall Doorway";
		upgradeBuilding[] = {"WoodLargeWallDoor_EPOCH",{ { "PartWoodPlywood",1 },{ "PartWoodLumber",1 } }};
		simulClass = "WoodLargeWallDoorway_SIM_EPOCH";
		staticClass = "WoodLargeWallDoorway_EPOCH";
		snapPointsPara[] = {"N","E","W"};
		allowedSnapPoints[] = {"N","S","E","W"};
		allowedSnapObjects[] = {"Const_floors_static_F","Const_WoodWalls_static_F"};
		sections[] = { "camo_cor", "camo" };
		hiddenSelections[] = { "camo_cor", "camo" };
		hiddenSelectionsTextures[] = { "x\addons\a3_epoch_assets\textures\cor\corrugated_co.paa", "x\addons\a3_epoch_assets\textures\plyplank_eco.paa" };
		availableTextures[] = { "\x\addons\a3_epoch_assets\textures\cor\corrugated_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_black_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_blue_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_brown_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_green_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_orange_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_purple_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_red_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_teal_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_yellow_co.paa" };
		energyCost = 0.2;
		slingLoadCargoMemoryPoints[] = { "N", "S", "E", "W" };
	};

	// lvl 1
	class WoodWall3_SIM_EPOCH : Constructions_modular_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets_3\CfgVehicles\Plywood_Upgrades\plywood_door\Wooden_Wall_Door.p3d";
		displayName = "Plywood Wall Doorway w/ Door (SIM)";
		simulClass = "WoodWall3_SIM_EPOCH";
		staticClass = "WoodWall3_EPOCH";
		snapPointsPara[] = { "N", "E", "W" };
		allowedSnapPoints[] = { "N", "S", "E", "W" };
		allowedSnapObjects[] = { "Const_floors_static_F", "Const_WoodWalls_static_F" };

		/*
		sections[] = { "camo_cor", "camo" };
		hiddenSelections[] = { "camo_cor", "camo" };
		hiddenSelectionsTextures[] = { "x\addons\a3_epoch_assets\textures\cor\corrugated_co.paa", "x\addons\a3_epoch_assets\textures\plyplank_eco.paa" };
		*/

		energyCost = 0.2;
		slingLoadCargoMemoryPoints[] = { "N", "S", "E", "W" };
		class AnimationSources
		{
			class Open_Door
			{
				source = "user";
				animPeriod = 2;
				initPhase = 0;
			};
		};
		class UserActions
		{
			class Open_door
			{
				displayName = "Open";
				displayNameDefault = "<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 3;
				condition = "this animationPhase ""Open_Door"" < 0.5";
				statement = "this animate [""Open_Door"", 1]";
			};
			class Close_door : Open_door
			{
				displayName = "Close";
				condition = "this animationPhase ""Open_Door"" >= 0.5";
				statement = "this animate [""Open_Door"", 0];";
			};
		};
	};

	// lvl 2
	class WoodLargeWallDoor_SIM_EPOCH: Constructions_modular_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\Wooden_Wall_Door_SIM.p3d";
		displayName = "Wall Doorway w/ Door";
		simulClass = "WoodLargeWallDoor_SIM_EPOCH";
		staticClass = "WoodLargeWallDoor_EPOCH";
		snapPointsPara[] = {"N","E","W"};
		allowedSnapPoints[] = {"N","S","E","W"};
		allowedSnapObjects[] = {"Const_floors_static_F","Const_WoodWalls_static_F"};

		sections[] = { "camo_cor", "camo" };
		hiddenSelections[] = { "camo_cor", "camo" };
		hiddenSelectionsTextures[] = { "x\addons\a3_epoch_assets\textures\cor\corrugated_co.paa", "x\addons\a3_epoch_assets\textures\plyplank_eco.paa" };
		availableTextures[] = { "\x\addons\a3_epoch_assets\textures\cor\corrugated_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_black_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_blue_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_brown_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_green_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_orange_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_purple_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_red_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_teal_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_yellow_co.paa" };

		energyCost = 0.2;
		slingLoadCargoMemoryPoints[] = { "N", "S", "E", "W" };
		class AnimationSources
		{
			class Open_Door
			{
				source = "user";
				animPeriod = 2;
				initPhase = 0;
			};
		};
		class UserActions
		{
			class Open_door
			{
				displayName = "Open";
				displayNameDefault = "<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 3;
				condition = "this animationPhase ""Open_Door"" < 0.5";
				statement = "this animate [""Open_Door"", 1]";
			};
			class Close_door: Open_door
			{
				displayName = "Close";
				condition = "this animationPhase ""Open_Door"" >= 0.5";
				statement = "this animate [""Open_Door"", 0];";
			};
		};
	};
	// lvl 1
	class WoodWall4_SIM_EPOCH : Constructions_modular_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets_3\CfgVehicles\Plywood_Upgrades\Plywood_DoorW_L\Plywood_DoorL.p3d";
		displayName = "Wall Doorway w/ Locking Door";
		simulClass = "WoodWall4_SIM_EPOCH";
		staticClass = "WoodWall4_EPOCH";
		snapPointsPara[] = { "N", "E", "W" };
		allowedSnapPoints[] = { "N", "S", "E", "W" };

		allowedSnapObjects[] = { "Const_floors_static_F", "Const_WoodWalls_static_F" };

		/*
		sections[] = { "camo_cor", "camo" };
		hiddenSelections[] = { "camo_cor", "camo" };
		hiddenSelectionsTextures[] = { "x\addons\a3_epoch_assets\textures\cor\corrugated_co.paa", "x\addons\a3_epoch_assets\textures\plyplank_eco.paa" };
		*/

		energyCost = 0.2;
		slingLoadCargoMemoryPoints[] = { "N", "S", "E", "W" };
		class AnimationSources
		{
			class Open_Door
			{
				source = "user";
				animPeriod = 2;
				initPhase = 0;
			};
			class lock_Door
			{
				source = "user";
				animPeriod = 2;
				initPhase = 1;
				sound = "ServoDoorsSound";
			};
		};
		class UserActions
		{
			class Open_door
			{
				displayName = "Open";
				displayNameDefault = "<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 3;
				condition = "(this animationPhase ""Open_Door"" < 0.5) && (this animationPhase ""lock_Door"" == 0)";
				statement = "this animate [""Open_Door"", 1]";
			};
			class Close_door : Open_door
			{
				displayName = "Close";
				condition = "(this animationPhase ""Open_Door"" >= 0.5) && (this animationPhase ""lock_Door"" == 0)";
				statement = "this animate [""Open_Door"", 0];";
			};

			class Lock_Door
			{
				displayName = "Lock";
				displayNameDefault = "<img image='\A3\modules_f\data\iconlock_ca.paa' size='2.5' />";
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 3;
				condition = "!(call EPOCH_lockCheck) && (this animationPhase ""Open_Door"" == 0) && (this animationPhase ""lock_Door"" == 0)";
				statement = "this animate [""lock_Door"", 1]";
			};
			class Unlock_Door : Lock_Door
			{
				displayName = "Unlock";
				displayNameDefault = "<img image='\A3\modules_f\data\iconunlock_ca.paa' size='2.5' />";
				condition = "!(call EPOCH_lockCheck) && (this animationPhase ""Open_Door"" == 0) && (this animationPhase ""lock_Door"" == 1)";
				statement = "this animate [""lock_Door"", 0];";
			};
		};
	};
	// lvl 2
	class WoodLargeWallDoorL_SIM_EPOCH : Constructions_modular_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\Wooden_Wall_DoorL_SIM.p3d";
		displayName = "Wall Doorway w/ Locking Door";
		simulClass = "WoodLargeWallDoorL_SIM_EPOCH";
		staticClass = "WoodLargeWallDoorL_EPOCH";
		snapPointsPara[] = { "N", "E", "W" };
		allowedSnapPoints[] = { "N", "S", "E", "W" };
		allowedSnapObjects[] = { "Const_floors_static_F", "Const_WoodWalls_static_F" };

		sections[] = { "camo_cor", "camo" };
		hiddenSelections[] = { "camo_cor", "camo" };
		hiddenSelectionsTextures[] = { "x\addons\a3_epoch_assets\textures\cor\corrugated_co.paa", "x\addons\a3_epoch_assets\textures\plyplank_eco.paa" };
		availableTextures[] = { "\x\addons\a3_epoch_assets\textures\cor\corrugated_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_black_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_blue_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_brown_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_green_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_orange_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_purple_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_red_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_teal_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_yellow_co.paa" };

		energyCost = 0.2;
		slingLoadCargoMemoryPoints[] = { "N", "S", "E", "W" };
		class AnimationSources
		{
			class Open_Door
			{
				source = "user";
				animPeriod = 2;
				initPhase = 0;
			};
			class lock_Door
			{
				source = "user";
				animPeriod = 2;
				initPhase = 1;
				sound = "ServoDoorsSound";
			};
		};
		class UserActions
		{
			class Open_door
			{
				displayName = "Open";
				displayNameDefault = "<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 3;
				condition = "(this animationPhase ""Open_Door"" < 0.5) && (this animationPhase ""lock_Door"" == 0)";
				statement = "this animate [""Open_Door"", 1]";
			};
			class Close_door : Open_door
			{
				displayName = "Close";
				condition = "(this animationPhase ""Open_Door"" >= 0.5) && (this animationPhase ""lock_Door"" == 0)";
				statement = "this animate [""Open_Door"", 0];";
			};

			class Lock_Door
			{
				displayName = "Lock";
				displayNameDefault = "<img image='\A3\modules_f\data\iconlock_ca.paa' size='2.5' />";
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 3;
				condition = "!(call EPOCH_lockCheck) && (this animationPhase ""Open_Door"" == 0) && (this animationPhase ""lock_Door"" == 0)";
				statement = "this animate [""lock_Door"", 1]";
			};
			class Unlock_Door : Lock_Door
			{
				displayName = "Unlock";
				displayNameDefault = "<img image='\A3\modules_f\data\iconunlock_ca.paa' size='2.5' />";
				condition = "!(call EPOCH_lockCheck) && (this animationPhase ""Open_Door"" == 0) && (this animationPhase ""lock_Door"" == 1)";
				statement = "this animate [""lock_Door"", 0];";
			};
		};
	};



	class WoodStairs_SIM_EPOCH: Constructions_modular_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\Wood_stairs.p3d";
		displayName = "Wood Stairs";
		simulClass = "WoodStairs_SIM_EPOCH";
		staticClass = "WoodStairs_EPOCH";
		GhostPreview = "WoodStairs_Ghost_EPOCH";
		snapPointsPara[] = {};
		snapPointsPerp[] = {};
		allowedSnapPoints[] = {"NF","SF","EF","WF","CB"};
		allowedSnapObjects[] = {"Const_floors_static_F","Constructions_foundation_F"};
		energyCost = 0.2;
		slingLoadCargoMemoryPoints[] = { "N", "S", "E", "W" };
	};

	// Wood_stairs_upgrade
	class WoodStairs2_SIM_EPOCH : Constructions_modular_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\Wood_stairs_upgrade.p3d";
		displayName = "Wood Stairs";
		simulClass = "WoodStairs2_SIM_EPOCH";
		staticClass = "WoodStairs2_EPOCH";
		GhostPreview = "WoodStairs2_EPOCH";
		snapPointsPara[] = { "NF", "SF", "EF", "WF", "C", "CB" };
		snapPointsPerp[] = { "N", "S", "E", "W", "CinN", "CinS", "CinE", "CinW" };
		allowedSnapPoints[] = { "NF", "SF", "EF", "WF", "CB" };
		allowedSnapObjects[] = { "Const_floors_static_F", "Constructions_foundation_F" };
		energyCost = 0.3;
		slingLoadCargoMemoryPoints[] = { "N", "S", "E", "W" };
	};

	class WoodTower_SIM_EPOCH : Constructions_modular_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets_3\CfgVehicles\Tower\Tower\Base_Tower_Frame.p3d";
		displayName = "Wood Tower";
		simulClass = "WoodTower_SIM_EPOCH";
		staticClass = "WoodTower_EPOCH";
		GhostPreview = "WoodTower_Ghost_EPOCH";
		snapPointsPara[] = { "NF2", "SF2", "EF2", "WF2","NF", "SF", "EF", "WF", "C", "CB" };
		snapPointsPerp[] = { "N", "S", "E", "W", "CinN", "CinS", "CinE", "CinW" };
		allowedSnapPoints[] = { "NF2", "SF2", "EF2", "WF2", "CB" };
		allowedSnapObjects[] = { "WoodTower_EPOCH", "Const_floors_static_F", "Constructions_foundation_F" };
		energyCost = 0.3;
		slingLoadCargoMemoryPoints[] = { "N", "S", "E", "W" };

		class AnimationSources
		{
			class NWall
			{
				source = "user";
				animPeriod = 1;
				initPhase = 0;
			};
			class EWall
			{
				source = "user";
				animPeriod = 1;
				initPhase = 0;
			};
			class SWall
			{
				source = "user";
				animPeriod = 1;
				initPhase = 0;
			};
			class WWall
			{
				source = "user";
				animPeriod = 1;
				initPhase = 0;
			};
		};
	};

	class WoodLadder_SIM_EPOCH: Constructions_modular_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets_3\CfgVehicles\Ladder\wood_ladder.p3d";
		displayName = "Wood Ladder";
		ladders[] = {};
		simulClass = "WoodLadder_SIM_EPOCH";
		staticClass = "WoodLadder_EPOCH";
		GhostPreview = "WoodLadder_Ghost_EPOCH";
	};

	// LOOT
	class Tipi_SIM_EPOCH : Constructions_modular_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\tp.p3d";
		displayName = "Tipi Sim";
		simulClass = "Tipi_SIM_EPOCH";
		staticClass = "Tipi_EPOCH";
		limitNearby = 2;
		bypassJammer = 1;
	};

	class Shelf_SIM_EPOCH: Constructions_modular_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\metalStorage.p3d";
		displayName = "Metal Shelf Sim";
		simulClass = "Shelf_SIM_EPOCH";
		staticClass = "Shelf_EPOCH";
	};

	class StorageShelf_SIM_EPOCH : Constructions_modular_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\shelf.p3d";
		displayName = "Metal Shelf Sim";
		simulClass = "StorageShelf_SIM_EPOCH";
		staticClass = "StorageShelf_EPOCH";
		limitNearby = 5;
		bypassJammer = 1;
	};

	class WorkBench_SIM_EPOCH : Constructions_modular_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets_1\models\workbench.p3d";
		displayName = "WorkBench (SIM)";
		staticClass = "WorkBench_EPOCH";
		simulClass = "WorkBench_SIM_EPOCH";
		limitNearby = 5;
		bypassJammer = 1;
	};

	class Tarp_SIM_EPOCH : Constructions_modular_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\tarp.p3d";
		displayName = "Tarp Covered Pallet";
		simulClass = "Tarp_SIM_EPOCH";
		staticClass = "Tarp_EPOCH";
	};
	class Freezer_SIM_EPOCH : Constructions_modular_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\freezer.p3d";
		displayName = "Chest Freezer";
		simulClass = "Freezer_SIM_EPOCH";
		staticClass = "Freezer_EPOCH";
	};

	class PlotPole_SIM_EPOCH : Constructions_modular_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\jammer.p3d";
		displayName = "Frequency Jammer Sim";
		staticClass = "PlotPole_EPOCH";
		simulClass = "PlotPole_SIM_EPOCH";
		bypassJammer = 1;
	};

	class SolarGen_SIM_EPOCH : Constructions_modular_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets_3\CfgVehicles\Solar_Generator_Complete\Solar_generator.p3d";
		displayName = "Solar Power Generator";
		staticClass = "SolarGen_EPOCH";
		simulClass = "SolarGen_SIM_EPOCH";
	};

	class ToolRack_SIM_EPOCH : Constructions_modular_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\toolRack.p3d";
		displayName = "Tool Rack";
		simulClass = "ToolRack_SIM_EPOCH";
		staticClass = "ToolRack_EPOCH";
	};

	class Chair_SIM_EPOCH: Constructions_modular_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\chair_adult.p3d";
		displayName = "Chair";
		simulClass = "Chair_SIM_EPOCH";
		staticClass = "Chair_EPOCH";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\x\addons\a3_epoch_assets\textures\chair\chair_ECO.paa"};
		hiddenSelectionsMaterials[] = {"\x\addons\a3_epoch_assets\textures\chair\chair.rvmat"};
	};
	class ChairRed_SIM_EPOCH: Constructions_modular_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\chair_adult.p3d";
		displayName = "Chair (Red)";
		simulClass = "ChairRed_SIM_EPOCH";
		staticClass = "ChairRed_EPOCH";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\x\addons\a3_epoch_assets\textures\chair\chair_kid_ECO.paa"};
		hiddenSelectionsMaterials[] = {"\x\addons\a3_epoch_assets\textures\chair\chair_kid.rvmat"};
	};
	class Filing_SIM_EPOCH: Constructions_modular_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\filing.p3d";
		displayName = "Filing Cabinet";
		simulClass = "Filing_SIM_EPOCH";
		staticClass = "Filing_EPOCH";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\x\addons\a3_epoch_assets\textures\filing\filing_co.paa"};
	};
	class Shoebox_SIM_EPOCH : Constructions_modular_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\shoebox.p3d";
		displayName = "Shoebox";
		simulClass = "Shoebox_SIM_EPOCH";
		staticClass = "Shoebox_EPOCH";
		// hiddenSelections[] = { "Camo" };
		// hiddenSelectionsTextures[] = { "\x\addons\a3_epoch_assets\textures\filing\filing_co.paa" };
	};
	class Fridge_SIM_EPOCH: Constructions_modular_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\fridge_door_anim.p3d";
		displayName = "Fridge";
		simulClass = "Fridge_SIM_EPOCH";
		staticClass = "Fridge_EPOCH";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\x\addons\a3_epoch_assets\textures\fridge\fridge_CO.paa"};
		availableTextures[] = {"\x\addons\a3_epoch_assets\textures\fridge\fridge_CO.paa","\x\addons\a3_epoch_assets\textures\fridge\fridgeBlack_CO.paa","\x\addons\a3_epoch_assets\textures\fridge\fridgeSteel_co.paa","\x\addons\a3_epoch_assets\textures\fridge\fridgeWhite_co.paa"};
		class AnimationSources
		{
			class Open_bot
			{
				source = "user";
				animPeriod = 2;
				initPhase = 0;
			};
			class Open_top
			{
				source = "user";
				animPeriod = 2;
				initPhase = 0;
			};
		};
		class UserActions
		{
			class Open_bot
			{
				displayName = "Open Bottom";
				displayNameDefault = "<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 3;
				condition = "this animationPhase ""Open_bot"" < 0.5";
				statement = "this animate [""Open_bot"", 1]";
			};
			class Close_bot: Open_bot
			{
				displayName = "Close Bottom";
				condition = "this animationPhase ""Open_bot"" >= 0.5";
				statement = "this animate [""Open_bot"", 0];";
			};
			class Open_top
			{
				displayName = "Open Top";
				displayNameDefault = "<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 3;
				condition = "this animationPhase ""Open_top"" < 0.5";
				statement = "this animate [""Open_top"", 1]";
			};
			class Close_top: Open_top
			{
				displayName = "Close Top";
				condition = "this animationPhase ""Open_top"" >= 0.5";
				statement = "this animate [""Open_top"", 0];";
			};
		};
	};
	class Bed_SIM_EPOCH: Constructions_modular_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\bed_dummy.p3d";
		displayName = "Mattress";
		simulClass = "Bed_SIM_EPOCH";
		staticClass = "Bed_EPOCH";
		forceSupply = 0;
	};
	class Bunk_SIM_EPOCH : Constructions_modular_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\bunk.p3d";
		displayName = "Bunk";
		simulClass = "Bunk_SIM_EPOCH";
		staticClass = "Bunk_EPOCH";
		forceSupply = 0;
	};

	class Couch_SIM_EPOCH: Constructions_modular_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\couch_dummy.p3d";
		displayName = "Couch";
		simulClass = "Couch_SIM_EPOCH";
		staticClass = "Couch_EPOCH";
	};
	class Table_SIM_EPOCH : Constructions_modular_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\coffee_table.p3d";
		displayName = "Coffee Table";
		simulClass = "Table_SIM_EPOCH";
		staticClass = "Table_EPOCH";
	};
	class Wardrobe_SIM_EPOCH: Constructions_modular_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets_2\wardrobe.p3d";
		author = "Kiory";
		displayName = "Wardrobe";
		simulClass = "Wardrobe_SIM_EPOCH";
		staticClass = "wardrobe_epoch";
	};
	class Locker_SIM_EPOCH: Constructions_modular_F
	{
		scope = 2;
		author = "Kiory";
		model = "\x\addons\a3_epoch_assets_2\lockers.p3d";
		displayName = "Wardrobe";
		simulClass = "Locker_SIM_EPOCH";
		staticClass = "locker_epoch";
	};
	class Cooker_SIM_EPOCH: Constructions_modular_F
	{
		scope = 2;
		author = "Kiory";
		model = "\x\addons\a3_epoch_assets_2\cooker.p3d";
		displayName = "Cooker";
		simulClass = "Cooker_SIM_EPOCH";
		staticClass = "cooker_epoch";
	};
	class Pelican_SIM_EPOCH: Constructions_modular_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\pelican.p3d";
		displayName = "Pelican";
		simulClass = "Pelican_SIM_EPOCH";
		staticClass = "Pelican_EPOCH";
		forceSupply = 0;
		class AnimationSources
		{
			class Open_top
			{
				source = "user";
				animPeriod = 2;
				initPhase = 0;
			};
		};
		class UserActions
		{
			class Open_top
			{
				displayName = "Search";
				displayNameDefault = "<img image='\A3\ui_f\data\map\VehicleIcons\iconvehicle_ca.paa' size='2.5' />";
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 3;
				condition = "this animationPhase ""Open_top"" < 0.5";
				statement = "this animate [""Open_top"", 1]; this call EPOCH_LootIT;";
			};
			/*
			class Close_top: Open_top
			{
				displayName = "Close";
				condition = "this animationPhase ""Open_top"" >= 0.5";
				statement = "this animate [""Open_top"", 0];";
			};
			*/
		};
	};

	class Debug_static_F : NonStrategic
	{
		mapSize = 2.27;
		author = "Epoch";
		_generalMacro = "Debug_static_F";
		scope = 2;
		displayName = "DEBUG BOX";
		model = "\x\addons\a3_epoch_assets\models\debug.p3d";
		icon = "iconObject_5x4";
		armor = 1000;
		vehicleclass = "Epoch_objects";
		destrType = "DestructNo";
		cost = 1000;
	};
	class clone_female_static_F : NonStrategic
	{
		mapSize = 1.27;
		author = "Epoch";
		_generalMacro = "clone_female_static_F";
		scope = 2;
		displayName = "Female Clone Vat";
		model = "\x\addons\a3_epoch_assets\models\clone_female.p3d";
		icon = "iconObject_1x1";
		armor = 1000;
		vehicleclass = "Epoch_objects";
		destrType = "DestructNo";
		cost = 1000;
		class AnimationSources
		{
			class raise
			{
				source = "user";
				animPeriod = 20;
				initPhase = 1;
			};
		};
	};
	class clone_male_static_F : NonStrategic
	{
		mapSize = 1.27;
		author = "Epoch";
		_generalMacro = "clone_female_static_F";
		scope = 2;
		displayName = "Male Clone Vat";
		model = "\x\addons\a3_epoch_assets\models\clone_male.p3d";
		icon = "iconObject_1x1";
		armor = 1000;
		vehicleclass = "Epoch_objects";
		destrType = "DestructNo";
		cost = 1000;
		class AnimationSources
		{
			class raise
			{
				source = "user";
				animPeriod = 20;
				initPhase = 1;
			};
		};
	};

	class clone_empty_static_F : NonStrategic
	{
		mapSize = 1.27;
		author = "Epoch";
		_generalMacro = "clone_empty_static_F";
		scope = 2;
		displayName = "Empty Clone Vat";
		model = "\x\addons\a3_epoch_assets\models\clone_male.p3d";
		icon = "iconObject_1x1";
		armor = 1000;
		vehicleclass = "Epoch_objects";
		destrType = "DestructNo";
		cost = 1000;
		hiddenSelections[] = { "clone" };
		hiddenSelectionsTextures[] = { "" };
	};

	class Constructions_static_F: NonStrategic
	{
		mapSize = 1.27;
		author = "Epoch";
		_generalMacro = "Constructions_base_F";
		scope = 0;
		displayName = "";
		model = "\A3\Weapons_F\empty.p3d";
		icon = "iconObject_5x4";
		armor = 5000;
		vehicleclass = "Epoch_objects";
		destrType = "DestructBuilding";
		cost = 1000;
		interactMode = 1;
	};
	class Constructions_foundation_F: NonStrategic
	{
		mapSize = 1.27;
		author = "Epoch";
		_generalMacro = "Constructions_foundation_F";
		scope = 0;
		displayName = "";
		model = "\A3\Weapons_F\empty.p3d";
		icon = "iconObject_5x4";
		armor = 5000;
		vehicleclass = "Epoch_objects";
		destrType = "DestructBuilding";
		cost = 1000;
		interactMode = 1;
	};
	class Foundation_EPOCH: Constructions_foundation_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\Concrete_Col.p3d";
		// upgradeBuilding[] = { "Foundation2_EPOCH", { { "MortarBucket", 4 } } };
		displayName = "Concrete Foundation";
		placement = "vertical";
		GhostPreview = "Foundation_Ghost_EPOCH";
		staticClass = "Foundation_EPOCH";
		snapPointsPara[] = {"N","S","E","W","C"};
		snapPointsPerp[] = {};
		allowedSnapPoints[] = {"N","S","E","W"};
		allowedSnapObjects[] = { "Constructions_foundation_F" };
		armor = 15000;
		removeParts[] = { {"ItemRock", 4} };
		maxHeight = 2.5;
	};
	class WoodFoundation_EPOCH : Constructions_foundation_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\Wood_Col.p3d";
		displayName = "Wood Foundation";
		placement = "vertical";
		GhostPreview = "WoodFoundation_Ghost_EPOCH";
		staticClass = "WoodFoundation_EPOCH";
		snapPointsPara[] = { "N", "S", "E", "W", "C" };
		snapPointsPerp[] = {};
		allowedSnapPoints[] = { "N", "S", "E", "W" };
		allowedSnapObjects[] = { "Constructions_foundation_F" };
		armor = 5000;
		removeParts[] = { { "PartPlankPack", 4 } };
		maxHeight = 2.5;
	};
	class Foundation_Ghost_EPOCH : Const_Ghost_EPOCH
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\Concrete_Col_Ghost.p3d";
		displayName = "Concrete Foundation (Ghost)";
		placement = "vertical";
		staticClass = "Foundation_EPOCH";
		snapPointsPara[] = { "N", "S", "E", "W", "C"};
		snapPointsPerp[] = {};
		allowedSnapPoints[] = { "N", "S", "E", "W"};
		allowedSnapObjects[] = { "Constructions_foundation_F" };
		ladders[] = {};
	};
	class WoodFoundation_Ghost_EPOCH : Const_Ghost_EPOCH
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\Concrete_Col_Ghost.p3d";
		displayName = "Wood Foundation (Ghost)";
		placement = "vertical";
		staticClass = "WoodFoundation_EPOCH";
		snapPointsPara[] = { "N", "S", "E", "W", "C" };
		snapPointsPerp[] = {};
		allowedSnapPoints[] = { "N", "S", "E", "W" };
		allowedSnapObjects[] = { "Constructions_foundation_F" };
		ladders[] = {};
	};

	class SolarGen_EPOCH : Constructions_static_F
	{
		mapSize = 1.27;
		author = "Epoch: SteamPunkGears";
		_generalMacro = "SolarGen_EPOCH";
		icon = "iconObject_5x4";
		armor = 5000;
		vehicleclass = "Epoch_objects";
		destrType = "DestructBuilding";
		cost = 1000;

		powerCapacity = 10;
		powerType = 1;

		scope = 2;
		placement = "vertical";

		model = "\x\addons\a3_epoch_assets_3\CfgVehicles\Solar_Generator_Complete\Solar_generator.p3d";
		displayName = "Solar Power Generator";

		GhostPreview = "SolarGen_EPOCH";
		staticClass = "SolarGen_EPOCH";
		simulClass = "SolarGen_SIM_EPOCH";

		removeParts[] = { { "KitSolarGen", 1 } };

		interactMode = 1;
	};

	class PlotPole_EPOCH : NonStrategic
	{
		mapSize = 1.27;
		author = "Epoch";
		_generalMacro = "PlotPole_EPOCH";
		icon = "iconObject_5x4";
		armor = 15000;
		vehicleclass = "Epoch_objects";
		destrType = "DestructBuilding";
		cost = 1000;

		scope = 2;
		displayName = "Frequency Jammer";
		placement = "vertical";
		GhostPreview = "PlotPole_EPOCH";
		staticClass = "PlotPole_EPOCH";
		simulClass = "PlotPole_SIM_EPOCH";

		model = "\x\addons\a3_epoch_assets\models\jammer.p3d";
		/*
		class UserActions
		{
			class MaintainIT
			{
				displayName = "Maintain";
				displayNameDefault = "<img image='\A3\ui_f\data\gui\Rsc\RscDisplayArcadeMap\icon_saveas_ca.paa' size='2.5' />";
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 10;
				condition = "damage this < 1";
				statement = "this call EPOCH_maintainIT";
			};
		};
		*/
		removeParts[] = { { "KitPlotPole", 1 } };
		bypassJammer = 1;
		interactMode = 1;
	};


	class Const_floors_static_F: Constructions_static_F{
		selectionDamage = "zbytek";
		class Damage
		{
			tex[] = {};
			mat[] = { "x\addons\a3_epoch_assets\textures\plyplank.rvmat", "x\addons\a3_epoch_assets\textures\PlyPlank_destruct50.rvmat", "x\addons\a3_epoch_assets\textures\PlyPlank_destruct50.rvmat" };
		};
	};
	class Const_All_Walls_F: Constructions_static_F{};
	class Const_Cinder_static_F: Const_All_Walls_F{
		selectionDamage = "zbytek";
		class Damage
		{
			tex[] = {};
			mat[] = { "x\addons\a3_epoch_assets\textures\cinder\cinder.rvmat", "x\addons\a3_epoch_assets\textures\cinder\cinder_destruct50.rvmat", "x\addons\a3_epoch_assets\textures\cinder\cinder_destruct50.rvmat" };
		};
	};
	class Const_WoodWalls_static_F: Const_All_Walls_F{
		selectionDamage = "camo_cor";
		class Damage
		{
			tex[] = {};
			mat[] = { "x\addons\a3_epoch_assets\textures\cor\corrugated.rvmat", "x\addons\a3_epoch_assets\textures\cor\corrugated_destruct50.rvmat", "x\addons\a3_epoch_assets\textures\cor\corrugated_destruct50.rvmat" };
		};
	};
	class WallHolder: WeaponHolder
	{
		scopeCurator = 0;
		class TransportMagazines{};
		forceSupply = 0;
		showWeaponCargo = 1;
		isGround = 0;
	};
	/*
	class Land_FirePlace_F;
	class FirePlace_EPOCH : Land_FirePlace_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets_2\fireplace_full.p3d";
		displayName = "FirePlace EPOCH";
		staticClass = "fireplace_e_epoch";
		GhostPreview = "fireplace_e_epoch";
	};


	class Sword_EPOCH: Constructions_static_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\sword.p3d";
		displayName = "Sword";
	};
	*/

	class Constructions_lockedstatic_F : WeaponHolder
	{
		mapSize = 1.27;
		author = "Epoch";
		_generalMacro = "Constructions_lockedstatic_F";
		scope = 0;
		displayName = "";
		model = "\A3\Weapons_F\empty.p3d";
		icon = "iconObject_5x4";
		armor = 5000;
		vehicleclass = "Epoch_objects";
		destrType = "DestructBuilding";
		cost = 1000;
		// storage defaults
		isGround = 0;
		showWeaponCargo = 0;
		forceSupply = 0;
		maximumLoad = 600;
		isSecureStorage = 1;
	};

	class LockBox_EPOCH : Constructions_lockedstatic_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets_1\models\lockbox.p3d";
		displayName = "Lockbox";
		simulClass = "LockBox_SIM_EPOCH";
		staticClass = "LockBox_EPOCH";
		weaponHolderProxy = "LockBoxProxy_EPOCH";
		GhostPreview = "LockBox_EPOCH";
		armor = 5000;
		maximumLoad = 600;
		bypassJammer = 1;
		limitNearby = 2;
		isSecureStorage = 1;
		returnOnPack[] = { { "ItemLockbox", 1 } };
		/*
		class UserActions
		{
			class Unlock
			{
				displayName = "Unlock";
				displayNameDefault = "<img image='\A3\modules_f\data\iconunlock_ca.paa' size='2.5' />";
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 3;
				condition = "this getVariable [""EPOCH_Locked"",true]";
				statement = "EPOCH_lockStorage_PVS = [this,false,player,Epoch_personalToken]; publicVariableServer ""EPOCH_lockStorage_PVS"";";
			};
			class Pack
			{
				displayName = "Pack";
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 3;
				condition = "this getVariable [""EPOCH_Locked"",true]";
				statement = "EPOCH_packStorage_PVS = [this,player,Epoch_personalToken]; publicVariableServer ""EPOCH_packStorage_PVS"";";
			};
		};
		*/
	};


	class Safe_EPOCH : Constructions_lockedstatic_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets_1\models\safe.p3d";
		displayName = "Lockbox";
		simulClass = "Safe_SIM_EPOCH";
		staticClass = "Safe_EPOCH";
		weaponHolderProxy = "SafeProxy_EPOCH";
		GhostPreview = "Safe_EPOCH";
		armor = 15000;
		maximumLoad = 3600;
		bypassJammer = 1;
		limitNearby = 2;
		isSecureStorage = 1;
		returnOnPack[] = { { "ItemSafe", 1 } };
		/*
		class UserActions
		{

			class Unlock
			{
				displayName = "Unlock";
				displayNameDefault = "<img image='\A3\modules_f\data\iconunlock_ca.paa' size='2.5' />";
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 3;
				condition = "(this getVariable[""EPOCH_secStorParent"", objNull]) getVariable [""EPOCH_Locked"",true]";
				statement = "EPOCH_lockStorage_PVS = [this,false,player,Epoch_personalToken]; publicVariableServer ""EPOCH_lockStorage_PVS"";";
			};

			class Pack
			{
				displayName = "Pack";
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 3;
				condition = "(this getVariable[""EPOCH_secStorParent"", objNull]) getVariable [""EPOCH_Locked"",true]";
				statement = "EPOCH_packStorage_PVS = [this,player,Epoch_personalToken]; publicVariableServer ""EPOCH_packStorage_PVS"";";
			};

		};
		*/

	};


	class TankTrap_EPOCH: Constructions_static_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets_3\CfgVehicles\Defense\tank_trap.p3d";
		displayName = "Tank Trap";
		simulClass = "TankTrap_SIM_EPOCH";
		staticClass = "TankTrap_EPOCH";
		GhostPreview = "TankTrap_EPOCH";
		energyCost = 0.2;
		limitNearby = 4;
		bypassJammer = 1;
	};

	class TRAP_EPOCH : Constructions_static_F {};
	class Spike_TRAP_EPOCH: Constructions_static_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\sticks.p3d";
		displayName = "Spike Trap (SIM)";
		simulClass = "Spike_TRAP_SIM_EPOCH";
		staticClass = "Spike_TRAP_EPOCH";
		GhostPreview = "Spike_TRAP_EPOCH";
		ammoClass = "Spike_TRAP_AMMO_EPOCH";
		energyCost = 0.2;
		limitNearby = 2;
		bypassJammer = 1;
		armor = 0.1;
	};

	class Metal_TRAP_EPOCH: Constructions_static_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\sticks.p3d";
		displayName = "Metal Trap (SIM)";
		simulClass = "Metal_TRAP_SIM_EPOCH";
		staticClass = "Metal_TRAP_EPOCH";
		GhostPreview = "Metal_TRAP_EPOCH";
		ammoClass = "Metal_TRAP_AMMO_EPOCH";
		energyCost = 0.4;
		limitNearby = 2;
		bypassJammer = 1;
		armor = 0.1;
	};

	class Hesco3_EPOCH: Const_All_Walls_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets_3\CfgVehicles\Defense\hesco.p3d";
		displayName = "Hesco Wide";
		simulClass = "Hesco3_SIM_EPOCH";
		staticClass = "Hesco3_EPOCH";
		GhostPreview = "Hesco3_Ghost_EPOCH";
		snapType = "snapPointsPara";
		snapPointsPara[] = { "C", "E", "W" };
		allowedSnapPoints[] = { "C", "E", "W" };
		energyCost = 0.2;
		limitNearby = 4;
		bypassJammer = 1;

		/*
		hiddenSelections[] = { "Camo" };
		hiddenSelectionsTextures[] = { "\x\addons\a3_epoch_assets\textures\hesco\hesco_co.paa" };
		hiddenSelectionsMaterials[] = { "\x\addons\a3_epoch_assets\textures\hesco\hesco.rvmat" };
		*/

		/*
		selectionDamage = "zbytek";
		class Damage
		{
			tex[] = {};
			mat[] = { "x\addons\a3_epoch_assets\textures\cinder\cinder.rvmat", "x\addons\a3_epoch_assets\textures\cinder\cinder_destruct50.rvmat", "x\addons\a3_epoch_assets\textures\cinder\cinder_destruct50.rvmat" };
		};
		*/
	};

	class WoodRamp_EPOCH : Constructions_static_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\Wood_Ramp.p3d";
		displayName = "Wood Ramp";
		simulClass = "WoodRamp_SIM_EPOCH";
		staticClass = "WoodRamp_EPOCH";
		GhostPreview = "WoodRamp_Ghost_EPOCH";
		snapPointsPara[] = {};
		snapPointsPerp[] = {};
		allowedSnapPoints[] = { "NF", "SF", "EF", "WF", "CB" };
		energyCost = 0.2;
		removeParts[] = { { "PartPlankPack", 3 } };
		selectionDamage = "zbytek";
		class Damage
		{
			tex[] = {};
			mat[] = { "x\addons\a3_epoch_assets\textures\plyplank.rvmat", "x\addons\a3_epoch_assets\textures\PlyPlank_destruct50.rvmat", "x\addons\a3_epoch_assets\textures\PlyPlank_destruct50.rvmat" };
		};
	};

	class CinderWallHalf_EPOCH: Const_Cinder_static_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\cinder_half.p3d";
		displayName = "Half Cinder Block Wall";
		upgradeBuilding[] = {"CinderWall_EPOCH",{ { "CinderBlocks",2 },{ "MortarBucket",1 } }};
		simulClass = "CinderWallHalf_SIM_EPOCH";
		staticClass = "CinderWallHalf_EPOCH";
		GhostPreview = "CinderWallHalf_Ghost_EPOCH";
		snapType = "snapPointsPara";
		snapPointsPara[] = { "N", "E", "W" };
		allowedSnapPoints[] = { "N", "S", "E", "W" };
		armor = 10000;
		removeParts[] = { { "CinderBlocks", 2 }, { "ItemRock", 1 } };
	};
	class CinderWall_EPOCH: Const_Cinder_static_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\cinder.p3d";
		displayName = "Cinder Block Wall";
		// upgradeBuilding[] = { "CinderWallGarage_EPOCH", { { "ItemCorrugatedLg", 1 }, { "CircuitParts", 1 }  } };
		simulClass = "CinderWall_SIM_EPOCH";
		staticClass = "CinderWall_EPOCH";
		GhostPreview = "CinderWall_EPOCH";
		snapType = "snapPointsPara";
		snapPointsPara[] = { "N", "E", "W" };
		allowedSnapPoints[] = { "N", "S", "E", "W" };
		energyCost = 0.4;
		armor = 10000;

	};
	class CinderWallGarage_EPOCH : Const_Cinder_static_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\cGarage.p3d";
		displayName = "Cinder Block Garage";
		simulClass = "CinderWallGarage_SIM_EPOCH";
		staticClass = "CinderWallGarage_EPOCH";
		GhostPreview = "CinderWallGarage_EPOCH";
		snapType = "snapPointsPara";
		snapPointsPara[] = { "N", "E", "W" };
		allowedSnapPoints[] = { "N", "S", "E", "W" };
		energyCost = 0.5;
		armor = 15000;
		removeParts[] = { { "CinderBlocks", 4 }, { "ItemCorrugatedLg", 1 }, { "CircuitParts", 1 } };

		class AnimationSources
		{
			class open_left
			{
				source = "user";
				animPeriod = 2;
				initPhase = 0;
				sound = "MetalBigDoorsSound";
			};
			class open_right
			{
				source = "user";
				animPeriod = 2;
				initPhase = 0;
				sound = "MetalOldBigDoorsSound";
			};
			class lock_cGarage
			{
				source = "user";
				animPeriod = 2;
				initPhase = 1;
				sound = "ServoDoorsSound";
			};

		};
		class UserActions
		{
			class Open_left
			{
				displayName = "Open";
				displayNameDefault = "<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 3;
				condition = "(this animationPhase ""open_left"" < 0.5) && (this animationPhase ""lock_cGarage"" < 0.5)";
				statement = "this animate [""open_left"", 1]; this animate [""open_right"", 1]";
			};
			class Close_left : Open_left
			{
				displayName = "Close";
				condition = "this animationPhase ""open_left"" >= 0.5";
				statement = "this animate [""open_left"", 0]; this animate [""open_right"", 0]";
			};

			class Lock_cGarage
			{
				displayName = "Lock";
				displayNameDefault = "<img image='\A3\modules_f\data\iconlock_ca.paa' size='2.5' />";
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 3;
				condition = "!(call EPOCH_lockCheck) && (this animationPhase ""open_left"" < 0.5) && (this animationPhase ""lock_cGarage"" < 0.5)";
				statement = "this animate [""lock_cGarage"", 1]";
			};
			class Unlock_cGarage : Lock_cGarage
			{
				displayName = "Unlock";
				displayNameDefault = "<img image='\A3\modules_f\data\iconunlock_ca.paa' size='2.5' />";
				condition = "!(call EPOCH_lockCheck) && (this animationPhase ""open_left"" < 0.5) && (this animationPhase ""lock_cGarage"" >= 0.5)";
				statement = "this animate [""lock_cGarage"", 0];";
			};
		};

	};

	class Jack_EPOCH : Constructions_static_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\jack.p3d";
		displayName = "Jack";

		simulClass = "Jack_SIM_EPOCH";
		staticClass = "Jack_EPOCH";
		GhostPreview = "Jack_EPOCH";

		limitNearby = 2;
		bypassJammer = 1;

		energyCost = 0.1;

		class AnimationSources
		{
			class raise
			{
				source = "user";
				animPeriod = 2;
				initPhase = 0;
			};
			class pump
			{
				source = "user";
				animPeriod = 2;
				initPhase = 0;
			};

		};
		class UserActions
		{
			class Open_left
			{
				displayName = "Raise";
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 3;
				condition = "this animationPhase ""raise"" < 0.5";
				statement = "this animate [""raise"", 1]; this animate [""pump"", 1]";
			};
			class Close_left : Open_left
			{
				displayName = "Lower";
				condition = "this animationPhase ""raise"" >= 0.5";
				statement = "this animate [""raise"", 0]; this animate [""pump"", 0]";
			};

		};

	};

	class WoodFloor_EPOCH: Const_floors_static_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\Wooden_Floor.p3d";
		displayName = "Wood Floor";
		simulClass = "WoodFloor_SIM_EPOCH";
		staticClass = "WoodFloor_EPOCH";
		GhostPreview = "WoodFloor_Ghost_EPOCH";
		snapPointsPara[] = {"NF","SF","EF","WF","C","CB"};
		snapPointsPerp[] = {"N","S","E","W","CinN","CinS","CinE","CinW"};
		allowedSnapPoints[] = {"NF","SF","EF","WF","C"};
		energyCost = 0.2;
	};
	class MetalFloor_EPOCH : Const_floors_static_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets_1\models\metal_floor.p3d";
		displayName = "Metal Floor";
		simulClass = "MetalFloor_SIM_EPOCH";
		staticClass = "MetalFloor_EPOCH";
		GhostPreview = "MetalFloor_Ghost_EPOCH";
		snapPointsPara[] = { "NF", "SF", "EF", "WF", "C", "CB" };
		snapPointsPerp[] = { "N", "S", "E", "W", "CinN", "CinS", "CinE", "CinW" };
		allowedSnapPoints[] = { "NF", "SF", "EF", "WF", "C" };
		energyCost = 0.5;
		armor = 15000;

		selectionDamage = "zbytek";
		class Damage
		{
			tex[] = {};
			// TODO: make seperate rvmat for destruction check for issues due to camo zbytek applying to all mats
			mat[] = { "x\addons\a3_epoch_assets_1\textures\metal_floor.rvmat", "x\addons\a3_epoch_assets\textures\PlyPlank_destruct50.rvmat", "x\addons\a3_epoch_assets\textures\PlyPlank_destruct50.rvmat" };
		};
	};

	// Wood wall seed item lvl 0
	class WoodLargeWall_EPOCH: Const_WoodWalls_static_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\Wooden_Wall.p3d";
		displayName = "Large Wall";

		simulClass = "WoodLargeWall_SIM_EPOCH";
		staticClass = "WoodLargeWall_EPOCH";
		GhostPreview = "WoodLargeWall_Ghost_EPOCH";
		snapType = "snapPointsPara";
		snapPointsPara[] = {"N","E","W"};
		allowedSnapPoints[] = {"N","S","E","W"};
		removeParts[] = { { "PartPlankPack", 2 } };
		selectionDamage = "zbytek";
		class Damage
		{
			tex[] = {};
			mat[] = { "x\addons\a3_epoch_assets\textures\plyplank.rvmat", "x\addons\a3_epoch_assets\textures\PlyPlank_destruct50.rvmat", "x\addons\a3_epoch_assets\textures\PlyPlank_destruct50.rvmat" };
		};
	};
	class Tipi_Ghost_EPOCH : Const_Ghost_EPOCH
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\tp_ghost.p3d";
		displayName = "TiPi Ghost";
		staticClass = "Tipi_EPOCH";
		ladders[] = {};
	};
	class StorageShelf_Ghost_EPOCH : Const_Ghost_EPOCH
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\shelf_ghost.p3d";
		displayName = "Shelf Ghost";
		staticClass = "StorageShelf_EPOCH";
		ladders[] = {};
	};
	class WorkBench_Ghost_EPOCH : Const_Ghost_EPOCH
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets_1\models\workbench.p3d";
		displayName = "WorkBench Ghost";
		staticClass = "WorkBench_EPOCH";
		ladders[] = {};
	};

	class WoodLargeWall_Ghost_EPOCH : Const_Ghost_EPOCH
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\Wooden_Wall_Ghost.p3d";
		displayName = "Wood Wall Ghost";
		staticClass = "WoodLargeWall_EPOCH";

		snapPointsPara[] = { "N", "E", "W" };
		allowedSnapPoints[] = { "N", "S", "E", "W" };
		allowedSnapObjects[] = { "Const_floors_static_F", "Const_WoodWalls_static_F" };

		ladders[] = {};
	};
	class WoodFloor_Ghost_EPOCH : Const_Ghost_EPOCH
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\Wooden_Floor_Ghost.p3d";
		displayName = "Wood Floor Ghost";
		staticClass = "WoodFloor_EPOCH";

		snapPointsPara[] = { "NF", "SF", "EF", "WF", "C", "CB" };
		snapPointsPerp[] = { "N", "S", "E", "W", "CinN", "CinS", "CinE", "CinW" };
		allowedSnapPoints[] = { "NF", "SF", "EF", "WF", "C" };
		allowedSnapObjects[] = { "Const_floors_static_F", "Constructions_foundation_F" };

		ladders[] = {};
	};
	class MetalFloor_Ghost_EPOCH : Const_Ghost_EPOCH
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets_1\models\metal_floor_ghost.p3d";
		displayName = "Metal Floor Ghost";
		staticClass = "MetalFloor_EPOCH";

		snapPointsPara[] = { "NF", "SF", "EF", "WF", "C", "CB" };
		snapPointsPerp[] = { "N", "S", "E", "W", "CinN", "CinS", "CinE", "CinW" };
		allowedSnapPoints[] = { "NF", "SF", "EF", "WF", "C" };
		allowedSnapObjects[] = { "Const_floors_static_F", "Constructions_foundation_F" };

		ladders[] = {};
	};

	class WoodLadder_Ghost_EPOCH : Const_Ghost_EPOCH
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets_3\CfgVehicles\Ladder\wood_ladder_ghost.p3d";
		displayName = "Wood Ladder Ghost";
		ladders[] = {};
		simulClass = "WoodLadder_SIM_EPOCH";
		staticClass = "WoodLadder_EPOCH";
		GhostPreview = "WoodLadder_Ghost_EPOCH";
	};

	class WoodStairs_Ghost_EPOCH : Const_Ghost_EPOCH
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\Wood_stairs90_Ghost.p3d";
		displayName = "Wood Stairs Ghost";
		staticClass = "WoodStairs_EPOCH";

		snapPointsPara[] = {};
		snapPointsPerp[] = {};
		allowedSnapPoints[] = { "NF2", "SF2", "EF2", "WF2", "NF", "SF", "EF", "WF", "CB" };
		allowedSnapObjects[] = { "Const_floors_static_F", "Constructions_foundation_F" };

		ladders[] = {};
	};

	class WoodTower_Ghost_EPOCH : Const_Ghost_EPOCH
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets_3\CfgVehicles\Tower\Tower\Base_Tower_Frame_Ghost.p3d";
		displayName = "Wood Tower Ghost";
		staticClass = "WoodTower_EPOCH";
		snapPointsPara[] = {};
		snapPointsPerp[] = {};
		allowedSnapPoints[] = { "NF2", "SF2", "EF2", "WF2", "CB" };
		allowedSnapObjects[] = { "Const_floors_static_F", "Constructions_foundation_F" };
		ladders[] = {};
	};



	class WoodRamp_Ghost_EPOCH : Const_Ghost_EPOCH
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\Wood_Ramp_Ghost.p3d";
		displayName = "Wood Ramp Ghost";
		staticClass = "WoodRamp_EPOCH";

		snapPointsPara[] = {};
		snapPointsPerp[] = {};
		allowedSnapPoints[] = { "NF", "SF", "EF", "WF", "CB" };
		allowedSnapObjects[] = { "Const_floors_static_F", "Constructions_foundation_F" };

		ladders[] = {};
	};


	class Hesco3_Ghost_EPOCH : Const_Ghost_EPOCH
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets_3\CfgVehicles\Defense\hesco_ghost.p3d";
		displayName = "Hesco Wide (Ghost)";
		staticClass = "Hesco3_EPOCH";

		snapPointsPara[] = {};
		snapPointsPerp[] = {};
		allowedSnapPoints[] = { "C", "E", "W" };
		allowedSnapObjects[] = { "Hesco3_EPOCH" };

		ladders[] = {};
	};

	class CinderWallHalf_Ghost_EPOCH : Const_Ghost_EPOCH
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\cinder_half_Ghost.p3d";
		displayName = "Cinder Half Wall Ghost";
		staticClass = "CinderWallHalf_EPOCH";
		simulClass = "CinderWallHalf_SIM_EPOCH";
		GhostPreview = "CinderWallHalf_Ghost_EPOCH";
		snapType = "snapPointsPara";
		snapPointsPara[] = { "N", "E", "W" };
		allowedSnapPoints[] = { "N", "S", "E", "W" };
		allowedSnapObjects[] = { "Const_Cinder_static_F", "Const_floors_static_F"};
		ladders[] = {};
	};

	// Wood only Lvl 1
	class WoodWall1_EPOCH : Const_WoodWalls_static_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets_3\CfgVehicles\Plywood_Upgrades\plywood_wall\Wooden_Wall_ply.p3d";
		displayName = "Large Plywood Wall";

		simulClass = "WoodWall1_SIM_EPOCH";
		staticClass = "WoodWall1_EPOCH";
		GhostPreview = "WoodWall1_EPOCH";

		snapType = "snapPointsPara";
		snapPointsPara[] = { "N", "E", "W" };
		allowedSnapPoints[] = { "N", "S", "E", "W" };
		energyCost = 0.2;

		// TODO: selection for just plywood  > camo_ply
		// TODO: needs colors
		// sections[] = { "camo_ply", "camo" };
		// hiddenSelections[] = { "camo_cor", "camo" };
		// hiddenSelectionsTextures[] = { "x\addons\a3_epoch_assets\textures\cor\corrugated_co.paa", "x\addons\a3_epoch_assets\textures\plyplank_eco.paa" };
		// availableTextures[] = { "\x\addons\a3_epoch_assets\textures\cor\corrugated_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_black_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_blue_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_brown_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_green_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_orange_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_purple_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_red_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_teal_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_yellow_co.paa" };

		armor = 1500;
		removeParts[] = { { "PartPlankPack", 2 } };
	};
	// Wood + Metal Lvl 2
	class WoodLargeWallCor_EPOCH: Const_WoodWalls_static_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\Wooden_Wall_Cor.p3d";
		displayName = "Large Corrugated Wall";
		upgradeBuilding[] = {"WoodLargeWallDoorway_EPOCH",{ { "PartPlankPack",1 } }};
		simulClass = "WoodLargeWallCor_SIM_EPOCH";
		staticClass = "WoodLargeWallCor_EPOCH";
		GhostPreview = "WoodLargeWallCor_EPOCH";
		snapType = "snapPointsPara";
		snapPointsPara[] = {"N","E","W"};
		allowedSnapPoints[] = {"N","S","E","W"};
		energyCost = 0.2;
		sections[] = { "camo_cor", "camo" };
		hiddenSelections[] = { "camo_cor", "camo" };
		hiddenSelectionsTextures[] = {"x\addons\a3_epoch_assets\textures\cor\corrugated_co.paa","x\addons\a3_epoch_assets\textures\plyplank_eco.paa"};
		availableTextures[] = { "\x\addons\a3_epoch_assets\textures\cor\corrugated_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_black_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_blue_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_brown_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_green_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_orange_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_purple_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_red_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_teal_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_yellow_co.paa" };
		armor = 7500;
		removeParts[] = { { "PartPlankPack", 2 }, { "ItemCorrugated", 1 } };
	};

	// Wood only lvl 1
	class WoodWall2_EPOCH : Const_WoodWalls_static_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets_3\CfgVehicles\Plywood_Upgrades\plywood_doorway\Wooden_Wall_Doorway.p3d";
		displayName = "Plywood Wall Doorway";

		simulClass = "WoodWall2_SIM_EPOCH";
		staticClass = "WoodWall2_EPOCH";
		GhostPreview = "WoodWall2_EPOCH";
		snapPointsPara[] = { "N", "E", "W" };
		allowedSnapPoints[] = { "N", "S", "E", "W" };
		energyCost = 0.2;
		armor = 1500;

		/* TODO
		sections[] = { "camo_cor", "camo" };
		hiddenSelections[] = { "camo_cor", "camo" };
		hiddenSelectionsTextures[] = { "x\addons\a3_epoch_assets\textures\cor\corrugated_co.paa", "x\addons\a3_epoch_assets\textures\plyplank_eco.paa" };
		availableTextures[] = { "\x\addons\a3_epoch_assets\textures\cor\corrugated_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_black_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_blue_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_brown_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_green_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_orange_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_purple_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_red_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_teal_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_yellow_co.paa" };
		*/

		removeParts[] = { { "PartPlankPack", 2 } };
	};

	// Wood + metal lvl 2
	class WoodLargeWallDoorway_EPOCH: Const_WoodWalls_static_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\Wooden_Wall_Doorway.p3d";
		displayName = "Wall Doorway";
		upgradeBuilding[] = {"WoodLargeWallDoor_EPOCH",{ { "ItemCorrugated",1 },{ "PartPlankPack",1 } }};
		simulClass = "WoodLargeWallDoorway_SIM_EPOCH";
		staticClass = "WoodLargeWallDoorway_EPOCH";
		GhostPreview = "WoodLargeWallDoorway_EPOCH";
		snapPointsPara[] = {"N","E","W"};
		allowedSnapPoints[] = {"N","S","E","W"};
		energyCost = 0.2;
		sections[] = { "camo_cor", "camo" };
		hiddenSelections[] = { "camo_cor", "camo" };
		hiddenSelectionsTextures[] = {"x\addons\a3_epoch_assets\textures\cor\corrugated_co.paa","x\addons\a3_epoch_assets\textures\plyplank_eco.paa"};
		availableTextures[] = { "\x\addons\a3_epoch_assets\textures\cor\corrugated_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_black_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_blue_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_brown_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_green_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_orange_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_purple_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_red_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_teal_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_yellow_co.paa" };
		removeParts[] = { { "PartPlankPack", 2 }, { "ItemCorrugated", 1 } };
	};

	// Wood only lvl 1
	class WoodWall3_EPOCH : Const_WoodWalls_static_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets_3\CfgVehicles\Plywood_Upgrades\plywood_door\Wooden_Wall_Door.p3d";

		displayName = "Plywood Wall Doorway w/ Door";
		simulClass = "WoodWall3_SIM_EPOCH";
		staticClass = "WoodWall3_EPOCH";
		GhostPreview = "WoodWall3_EPOCH";
		snapPointsPara[] = { "N", "E", "W" };
		allowedSnapPoints[] = { "N", "S", "E", "W" };
		allowedSnapObjects[] = { "Const_floors_static_F", "Const_WoodWalls_static_F" };

		/*
		sections[] = { "camo_cor", "camo" };
		hiddenSelections[] = { "camo_cor", "camo" };
		hiddenSelectionsTextures[] = { "x\addons\a3_epoch_assets\textures\cor\corrugated_co.paa", "x\addons\a3_epoch_assets\textures\plyplank_eco.paa" };
		availableTextures[] = { "\x\addons\a3_epoch_assets\textures\cor\corrugated_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_black_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_blue_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_brown_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_green_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_orange_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_purple_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_red_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_teal_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_yellow_co.paa" };
		*/

		energyCost = 0.2;
		armor = 1500;

		removeParts[] = { { "PartPlankPack", 2 } };

		class AnimationSources
		{
			class Open_Door
			{
				source = "user";
				animPeriod = 2;
				initPhase = 0;
			};
		};
		class UserActions
		{
			class Open_door
			{
				displayName = "Open";
				displayNameDefault = "<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 3;
				condition = "this animationPhase ""Open_Door"" < 0.5";
				statement = "this animate [""Open_Door"", 1]";
			};
			class Close_door : Open_door
			{
				displayName = "Close";
				condition = "this animationPhase ""Open_Door"" >= 0.5";
				statement = "this animate [""Open_Door"", 0];";
			};
		};
	};

	// Wood + meta lvl 2
	class WoodLargeWallDoor_EPOCH: Const_WoodWalls_static_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\Wooden_Wall_Door.p3d";
		upgradeBuilding[] = { "WoodLargeWallDoorL_EPOCH", { { "ItemCorrugated", 1 }, { "CircuitParts", 1 } } };
		displayName = "Wall Doorway w/ Door";
		simulClass = "WoodLargeWallDoor_SIM_EPOCH";
		staticClass = "WoodLargeWallDoor_EPOCH";
		GhostPreview = "WoodLargeWallDoor_EPOCH";
		snapPointsPara[] = {"N","E","W"};
		allowedSnapPoints[] = {"N","S","E","W"};
		allowedSnapObjects[] = {"Const_floors_static_F","Const_WoodWalls_static_F"};
		sections[] = { "camo_cor", "camo" };
		hiddenSelections[] = { "camo_cor", "camo" };
		hiddenSelectionsTextures[] = {"x\addons\a3_epoch_assets\textures\cor\corrugated_co.paa","x\addons\a3_epoch_assets\textures\plyplank_eco.paa"};
		availableTextures[] = { "\x\addons\a3_epoch_assets\textures\cor\corrugated_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_black_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_blue_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_brown_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_green_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_orange_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_purple_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_red_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_teal_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_yellow_co.paa" };
		energyCost = 0.2;
		armor = 7500;
		removeParts[] = { { "PartPlankPack", 2 }, { "ItemCorrugated", 1 } };
		class AnimationSources
		{
			class Open_Door
			{
				source = "user";
				animPeriod = 2;
				initPhase = 0;
			};
		};
		class UserActions
		{
			class Open_door
			{
				displayName = "Open";
				displayNameDefault = "<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 3;
				condition = "this animationPhase ""Open_Door"" < 0.5";
				statement = "this animate [""Open_Door"", 1]";
			};
			class Close_door: Open_door
			{
				displayName = "Close";
				condition = "this animationPhase ""Open_Door"" >= 0.5";
				statement = "this animate [""Open_Door"", 0];";
			};
		};
	};

	// Wood only lvl 1
	class WoodWall4_EPOCH : Const_WoodWalls_static_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets_3\CfgVehicles\Plywood_Upgrades\Plywood_DoorW_L\Plywood_DoorL.p3d";
		displayName = "Plywood Wall Doorway w/ Locking Door";
		simulClass = "WoodWall4_SIM_EPOCH";
		staticClass = "WoodWall4_EPOCH";
		GhostPreview = "WoodWall4_EPOCH";
		snapPointsPara[] = { "N", "E", "W" };
		allowedSnapPoints[] = { "N", "S", "E", "W" };
		allowedSnapObjects[] = { "Const_floors_static_F", "Const_WoodWalls_static_F" };

		/*
		sections[] = { "camo_cor", "camo" };
		hiddenSelections[] = { "camo_cor", "camo" };
		hiddenSelectionsTextures[] = { "x\addons\a3_epoch_assets\textures\cor\corrugated_co.paa", "x\addons\a3_epoch_assets\textures\plyplank_eco.paa" };
		availableTextures[] = { "\x\addons\a3_epoch_assets\textures\cor\corrugated_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_black_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_blue_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_brown_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_green_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_orange_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_purple_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_red_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_teal_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_yellow_co.paa" };
		*/

		energyCost = 0.2;
		armor = 1500;

		removeParts[] = { { "PartPlankPack", 2 }, { "CircuitParts", 1 } };

		class AnimationSources
		{
			class Open_Door
			{
				source = "user";
				animPeriod = 2;
				initPhase = 0;
			};
			class lock_Door
			{
				source = "user";
				animPeriod = 2;
				initPhase = 1;
				sound = "ServoDoorsSound";
			};
		};
		class UserActions
		{
			class Open_door
			{
				displayName = "Open";
				displayNameDefault = "<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 3;
				condition = "(this animationPhase ""Open_Door"" < 0.5) && (this animationPhase ""lock_Door"" == 0)";
				statement = "this animate [""Open_Door"", 1]";
			};
			class Close_door : Open_door
			{
				displayName = "Close";
				condition = "(this animationPhase ""Open_Door"" >= 0.5) && (this animationPhase ""lock_Door"" == 0)";
				statement = "this animate [""Open_Door"", 0];";
			};

			class Lock_Door
			{
				displayName = "Lock";
				displayNameDefault = "<img image='\A3\modules_f\data\iconlock_ca.paa' size='2.5' />";
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 3;
				condition = "!(call EPOCH_lockCheck) && (this animationPhase ""Open_Door"" == 0) && (this animationPhase ""lock_Door"" == 0)";
				statement = "this animate [""lock_Door"", 1]";
			};
			class Unlock_Door : Lock_Door
			{
				displayName = "Unlock";
				displayNameDefault = "<img image='\A3\modules_f\data\iconunlock_ca.paa' size='2.5' />";
				condition = "!(call EPOCH_lockCheck) && (this animationPhase ""Open_Door"" == 0) && (this animationPhase ""lock_Door"" == 1)";
				statement = "this animate [""lock_Door"", 0];";
			};
		};
	};


	// Wood + metal lvl 2
	class WoodLargeWallDoorL_EPOCH : Const_WoodWalls_static_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\Wooden_Wall_DoorL.p3d";
		displayName = "Wall Doorway w/ Locking Door";
		simulClass = "WoodLargeWallDoorL_SIM_EPOCH";
		staticClass = "WoodLargeWallDoorL_EPOCH";
		GhostPreview = "WoodLargeWallDoorL_EPOCH";
		snapPointsPara[] = { "N", "E", "W" };
		allowedSnapPoints[] = { "N", "S", "E", "W" };
		allowedSnapObjects[] = { "Const_floors_static_F", "Const_WoodWalls_static_F" };
		sections[] = { "camo_cor", "camo" };
		hiddenSelections[] = { "camo_cor", "camo" };
		hiddenSelectionsTextures[] = {"x\addons\a3_epoch_assets\textures\cor\corrugated_co.paa","x\addons\a3_epoch_assets\textures\plyplank_eco.paa"};
		availableTextures[] = { "\x\addons\a3_epoch_assets\textures\cor\corrugated_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_black_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_blue_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_brown_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_green_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_orange_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_purple_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_red_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_teal_co.paa", "\x\addons\a3_epoch_assets\textures\cor\corrugated_yellow_co.paa" };
		energyCost = 0.2;
		armor = 7500;
		removeParts[] = { { "PartPlankPack", 2 }, { "ItemCorrugated", 1 }, { "CircuitParts", 1 } };
		class AnimationSources
		{
			class Open_Door
			{
				source = "user";
				animPeriod = 2;
				initPhase = 0;
			};
			class lock_Door
			{
				source = "user";
				animPeriod = 2;
				initPhase = 1;
				sound = "ServoDoorsSound";
			};
		};
		class UserActions
		{
			class Open_door
			{
				displayName = "Open";
				displayNameDefault = "<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 3;
				condition = "(this animationPhase ""Open_Door"" < 0.5) && (this animationPhase ""lock_Door"" == 0)";
				statement = "this animate [""Open_Door"", 1]";
			};
			class Close_door : Open_door
			{
				displayName = "Close";
				condition = "(this animationPhase ""Open_Door"" >= 0.5) && (this animationPhase ""lock_Door"" == 0)";
				statement = "this animate [""Open_Door"", 0];";
			};

			class Lock_Door
			{
				displayName = "Lock";
				displayNameDefault = "<img image='\A3\modules_f\data\iconlock_ca.paa' size='2.5' />";
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 3;
				condition = "!(call EPOCH_lockCheck) && (this animationPhase ""Open_Door"" == 0) && (this animationPhase ""lock_Door"" == 0)";
				statement = "this animate [""lock_Door"", 1]";
			};
			class Unlock_Door : Lock_Door
			{
				displayName = "Unlock";
				displayNameDefault = "<img image='\A3\modules_f\data\iconunlock_ca.paa' size='2.5' />";
				condition = "!(call EPOCH_lockCheck) && (this animationPhase ""Open_Door"" == 0) && (this animationPhase ""lock_Door"" == 1)";
				statement = "this animate [""lock_Door"", 0];";
			};
		};
	};

	class WoodStairs_EPOCH: Constructions_static_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\Wood_stairs.p3d";
		upgradeBuilding[] = { "WoodStairs2_EPOCH", { { "PartPlankPack", 4 } } };
		displayName = "Wood Stairs";
		simulClass = "WoodStairs_SIM_EPOCH";
		staticClass = "WoodStairs_EPOCH";
		GhostPreview = "WoodStairs_Ghost_EPOCH";
		snapPointsPara[] = {};
		snapPointsPerp[] = {};
		allowedSnapPoints[] = { "NF2", "SF2", "EF2", "WF2", "NF", "SF", "EF", "WF", "CB" };
		allowedSnapObjects[] = { "Const_floors_static_F", "Constructions_foundation_F" };
		energyCost = 0.2;
		removeParts[] = { { "PartPlankPack", 4 } };
		selectionDamage = "zbytek";
		class Damage
		{
			tex[] = {};
			mat[] = { "x\addons\a3_epoch_assets\textures\plyplank.rvmat", "x\addons\a3_epoch_assets\textures\PlyPlank_destruct50.rvmat", "x\addons\a3_epoch_assets\textures\PlyPlank_destruct50.rvmat" };
		};
	};
	class WoodStairs2_EPOCH : Const_floors_static_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\Wood_stairs_upgrade.p3d";
		displayName = "Wood Stairs lvl 2";
		simulClass = "WoodStairs2_SIM_EPOCH";
		staticClass = "WoodStairs2_EPOCH";
		GhostPreview = "WoodStairs2_EPOCH";
		snapPointsPara[] = { "NF2", "SF2", "EF2", "WF2", "NF", "SF", "EF", "WF", "C", "CB" };
		snapPointsPerp[] = { "N", "S", "E", "W", "CinN", "CinS", "CinE", "CinW" };
		allowedSnapPoints[] = { "NF2", "SF2", "EF2", "WF2", "NF", "SF", "EF", "WF", "CB" };
		energyCost = 0.3;
		armor = 7500;
		removeParts[] = { { "PartPlankPack", 4 } };
	};

	class WoodTower_EPOCH : Const_floors_static_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets_3\CfgVehicles\Tower\Tower\Base_Tower_Frame.p3d";
		displayName = "Wood Tower";
		simulClass = "WoodTower_SIM_EPOCH";
		staticClass = "WoodTower_EPOCH";
		GhostPreview = "WoodTower_Ghost_EPOCH";
		snapPointsPara[] = { "NF2", "SF2", "EF2", "WF2","NF", "SF", "EF", "WF", "C", "CB" };
		snapPointsPerp[] = { "N", "S", "E", "W", "CinN", "CinS", "CinE", "CinW" };
		allowedSnapPoints[] = { "NF2", "SF2", "EF2", "WF2", "CB" };
		allowedSnapObjects[] = { "WoodTower_EPOCH", "Const_floors_static_F", "Constructions_foundation_F" };
		persistAnimations[] = { "NWall", "EWall", "SWall", "WWall" };

		energyCost = 0.3;
		armor = 7500;
		removeParts[] = { { "PartPlankPack", 4 } };


		class AnimationSources
		{
			class NWall
			{
				source = "user";
				animPeriod = 1;
				initPhase = 0;
			};
			class EWall
			{
				source = "user";
				animPeriod = 1;
				initPhase = 0;
			};
			class SWall
			{
				source = "user";
				animPeriod = 1;
				initPhase = 0;
			};
			class WWall
			{
				source = "user";
				animPeriod = 1;
				initPhase = 0;
			};
		};
		class UserActions
		{
			class add_nwall
			{
				displayName = "Add Wall";
				onlyforplayer = 1;
				position = "NWall_trigger";
				radius = 2.5;
				condition = "!(call EPOCH_lockCheck) && (this animationPhase ""NWall"" < 0.5)";
				statement = "[this,""NWall"",1] call EPOCH_changeWallState";
			};
			class remove_nwall : add_nwall
			{
				displayName = "Remove Wall";
				position = "NWall_trigger";
				condition = "!(call EPOCH_lockCheck) && (this animationPhase ""NWall"" >= 0.5)";
				statement = "[this,""NWall"",0] call EPOCH_changeWallState";
			};

			class add_ewall : add_nwall
			{
				displayName = "Add Wall";
				position = "EWall_trigger";
				condition = "!(call EPOCH_lockCheck) && (this animationPhase ""EWall"" < 0.5)";
				statement = "[this,""EWall"",1] call EPOCH_changeWallState";
			};
			class remove_ewall : add_nwall
			{
				displayName = "Remove Wall";
				position = "EWall_trigger";
				condition = "!(call EPOCH_lockCheck) && (this animationPhase ""EWall"" >= 0.5)";
				statement = "[this,""EWall"",0] call EPOCH_changeWallState";
			};

			class add_swall : add_nwall
			{
				displayName = "Add Wall";
				position = "SWall_trigger";
				condition = "!(call EPOCH_lockCheck) && (this animationPhase ""SWall"" < 0.5)";
				statement = "[this,""SWall"",1] call EPOCH_changeWallState";
			};
			class remove_swall : add_nwall
			{
				displayName = "Remove Wall";
				position = "SWall_trigger";
				condition = "!(call EPOCH_lockCheck) && (this animationPhase ""SWall"" >= 0.5)";
				statement = "[this,""SWall"",0] call EPOCH_changeWallState";
			};

			class add_wwall : add_nwall
			{
				displayName = "Add Wall";
				position = "WWall_trigger";
				condition = "!(call EPOCH_lockCheck) && (this animationPhase ""WWall"" < 0.5)";
				statement = "[this,""WWall"",1] call EPOCH_changeWallState";
			};
			class remove_wwall : add_nwall
			{
				displayName = "Remove Wall";
				position = "WWall_trigger";
				condition = "!(call EPOCH_lockCheck) && (this animationPhase ""WWall"" >= 0.5)";
				statement = "[this,""WWall"",0] call EPOCH_changeWallState";
			};
		};
	};

	class WoodLadder_EPOCH: Constructions_static_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets_3\CfgVehicles\Ladder\wood_ladder.p3d";
		displayName = "Wood Ladder";
		ladders[] = {{ "start1","end1" }};
		simulClass = "WoodLadder_SIM_EPOCH";
		staticClass = "WoodLadder_EPOCH";
		GhostPreview = "WoodLadder_Ghost_EPOCH";
		energyCost = 0.1;
		armor = 500;
		removeParts[] = { { "PartPlankPack", 2 } };
	};

	class Buildable_Storage : WeaponHolder
	{
		scope = 0;
		forceSupply = 0;
		isGround = 0;
		author = "Epoch Mod";
		destrType = "DestructBuilding";
		armor = 8000;
		maximumLoad = 1000;
	};

	class Tipi_EPOCH : Buildable_Storage
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\tp.p3d";
		GhostPreview = "Tipi_Ghost_EPOCH";
		displayName = "Tipi";
		maximumLoad = 1200;
		staticClass = "Tipi_EPOCH";
		simulClass = "Tipi_SIM_EPOCH";
		limitNearby = 2;
		bypassJammer = 1;
		interactMode = 4;
	};
	class StorageShelf_EPOCH : Buildable_Storage
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\shelf.p3d";
		displayName = "Metal Shelf";
		GhostPreview = "StorageShelf_Ghost_EPOCH";
		maximumLoad = 800;
		staticClass = "StorageShelf_EPOCH";
		simulClass = "StorageShelf_SIM_EPOCH";
		limitNearby = 5;
		bypassJammer = 1;
		interactMode = 4;
	};
	class WorkBench_EPOCH : Buildable_Storage
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets_1\models\workbench.p3d";
		displayName = "WorkBench";
		GhostPreview = "WorkBench_Ghost_EPOCH";
		maximumLoad = 800;
		staticClass = "WorkBench_EPOCH";
		simulClass = "WorkBench_SIM_EPOCH";
		limitNearby = 5;
		bypassJammer = 1;
		interactMode = 4;
	};
	class ShelfProxy_EPOCH : WeaponHolder
	{
		scope = 2;
		author = "Epoch Mod";
		model = "\x\addons\a3_epoch_assets\models\metalStorage_proxy.p3d";
		displayName = "Shelf Proxy";
		isGround = 0;
	};
	class TarpProxy_EPOCH : WeaponHolder
	{
		scope = 2;
		author = "Epoch Mod";
		model = "\x\addons\a3_epoch_assets\models\tarp_proxy.p3d";
		displayName = "Pallet Proxy";
		isGround = 0;
	};
	class MineralProxy_EPOCH : WeaponHolder
	{
		scope = 2;
		author = "Epoch Mod";
		model = "\x\addons\a3_epoch_assets\models\mineral_proxy.p3d";
		displayName = "Mineral Proxy";
		isGround = 0;
	};
	class MineralDepositCopper_EPOCH : Animated_Loot
	{
		scope = 2;
		author = "Epoch Mod";
		model = "\x\addons\a3_epoch_assets\models\mineral.p3d";
		displayName = "Mineral Deposit (Copper)";
		hiddenSelections[] = { "Camo" };
		hiddenSelectionsTextures[] = { "\x\addons\a3_epoch_assets\textures\minerals\mineralBrown_co.paa" };
		hiddenSelectionsMaterials[] = { "\x\addons\a3_epoch_assets\textures\minerals\mineralCopper.rvmat" };
		weaponHolderProxy = "MineralProxy_EPOCH";
		destrType = "DestructEngine";
		class DestructionEffects{
			class Smoke1
			{
				simulation = "particles";
				type = "HouseDestructionSmoke3";
				position = "destructionEffect1";
				qualityLevel = 2;
				intensity = 0.15;
				interval = 1;
				lifeTime = 0.07;
			};
			class Smoke1Med
			{
				simulation = "particles";
				type = "HouseDestructionSmoke3Med";
				position = "destructionEffect1";
				qualityLevel = 1;
				intensity = 0.15;
				interval = 1;
				lifeTime = 0.05;
			};
			class Smoke1Low
			{
				simulation = "particles";
				type = "HouseDestructionSmoke3Low";
				position = "destructionEffect1";
				qualityLevel = 0;
				intensity = 0.15;
				interval = 1;
				lifeTime = 0.05;
			};
		};
		class Destruction
		{
			animations[] = { { "x\addons\a3_epoch_assets\models\mineral_move.rtm", 0.5, 2 } };
		};
		class UserActions
		{
			class LootIT
			{
				displayName = "Search";
				displayNameDefault = "<img image='\A3\ui_f\data\map\VehicleIcons\iconvehicle_ca.paa' size='2.5' />";
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 3;
				condition = "damage this > 0.5";
				statement = "this call EPOCH_LootIT;";
			};
		};
	};
	class MineralDepositGold_EPOCH : MineralDepositCopper_EPOCH
	{
		displayName = "Mineral Deposit (Gold)";
		hiddenSelections[] = { "Camo" };
		hiddenSelectionsTextures[] = { "\x\addons\a3_epoch_assets\textures\minerals\mineralBrown_co.paa" };
		hiddenSelectionsMaterials[] = { "\x\addons\a3_epoch_assets\textures\minerals\mineralGold.rvmat" };
	};
	class MineralDepositSilver_EPOCH : MineralDepositCopper_EPOCH
	{
		displayName = "Mineral Deposit (Silver)";
		hiddenSelections[] = { "Camo" };
		hiddenSelectionsTextures[] = { "\x\addons\a3_epoch_assets\textures\minerals\mineralBrown_co.paa" };
		hiddenSelectionsMaterials[] = { "\x\addons\a3_epoch_assets\textures\minerals\mineralSilver.rvmat" };
	};
	class Tarp_EPOCH : Animated_Loot
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\tarp.p3d";
		displayName = "Tarp Covered Pallet";
		simulClass = "Tarp_SIM_EPOCH";
		staticClass = "Tarp_EPOCH";
		weaponHolderProxy = "TarpProxy_EPOCH";
		destrType = "DestructEngine";
		class DestructionEffects{};
		class Destruction
		{
			animations[] = { { "x\addons\a3_epoch_assets\models\tarp_move.rtm", 0.5, 1 } };
		};
		class UserActions
		{
			class LootIT
			{
				displayName = "Search";
				displayNameDefault = "<img image='\A3\ui_f\data\map\VehicleIcons\iconvehicle_ca.paa' size='2.5' />";
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 3;
				condition = "damage this < 1";
				statement = "this call EPOCH_LootIT;";
			};
		};
	};
	class Shelf_EPOCH : Animated_Loot
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\metalStorage.p3d";
		displayName = "Metal Shelf";
		simulClass = "Shelf_SIM_EPOCH";
		staticClass = "Shelf_EPOCH";
		hiddenSelections[] = { "Camo" };
		hiddenSelectionsTextures[] = { "\x\addons\a3_epoch_assets\textures\metalstorage\metalStorage_co.paa" };
		availableTextures[] = { "\x\addons\a3_epoch_assets\textures\metalstorage\metalStorage_co.paa", "\x\addons\a3_epoch_assets\textures\metalstorage\metalStorageBlk_CO.paa", "\x\addons\a3_epoch_assets\textures\metalstorage\metalStorageYel_CO.paa", "\x\addons\a3_epoch_assets\textures\metalstorage\metalStorageSil_CO.paa", "\x\addons\a3_epoch_assets\textures\metalstorage\metalStorageBlue_CO.paa" };
		weaponHolderProxy = "ShelfProxy_EPOCH";
		destrType = "DestructEngine";
		class DestructionEffects{};
		class Destruction
		{
			animations[] = { { "x\addons\a3_epoch_assets\models\metalStorage_move.rtm", 0.5, 2 } };
		};
		class UserActions
		{
			class LootIT
			{
				displayName = "Search";
				displayNameDefault = "<img image='\A3\ui_f\data\map\VehicleIcons\iconvehicle_ca.paa' size='2.5' />";
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 3;
				condition = "damage this < 1";
				statement = "this call EPOCH_LootIT;";
			};
		};
	};

	class WH_Loot : WeaponHolder {};

	class Freezer_EPOCH : WH_Loot
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\freezer.p3d";
		displayName = "Chest Freezer";
		simulClass = "Freezer_SIM_EPOCH";
		staticClass = "Freezer_EPOCH";
		forceSupply = 0;
		isGround = 0;
		class AnimationSources
		{
			class Open_top
			{
				source = "user";
				animPeriod = 2;
				initPhase = 0;
			};
		};
		class UserActions
		{
			class Open_top
			{
				displayName = "Search";
				displayNameDefault = "<img image='\A3\ui_f\data\map\VehicleIcons\iconvehicle_ca.paa' size='2.5' />";
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 3;
				condition = "this animationPhase ""Open_top"" < 0.5";
				statement = "this animate [""Open_top"", 1]; this call EPOCH_LootIT;";
			};
			/*
			class Close_top: Open_top
			{
			displayName = "Close";
			condition = "this animationPhase ""Open_top"" >= 0.5";
			statement = "this animate [""Open_top"", 0];";
			};
			*/
		};
	};


	class Cabinet_EPOCH : WH_Loot
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets_3\CfgVehicles\Furniture\medicine_cabinet\mc_door_anim.p3d";
		displayName = "Medicine Cabinet";
		simulClass = "Cabinet_EPOCH";
		staticClass = "Cabinet_EPOCH";
		forceSupply = 0;
		isGround = 0;
		// hiddenSelections[] = { "Camo" };
		// hiddenSelectionsTextures[] = { "\x\addons\a3_epoch_assets\textures\fridge\fridge_CO.paa" };
		// availableTextures[] = { "\x\addons\a3_epoch_assets\textures\fridge\fridge_CO.paa", "\x\addons\a3_epoch_assets\textures\fridge\fridgeBlack_CO.paa", "\x\addons\a3_epoch_assets\textures\fridge\fridgeSteel_co.paa", "\x\addons\a3_epoch_assets\textures\fridge\fridgeWhite_co.paa" };
		class AnimationSources
		{
			class Open_bot
			{
				source = "user";
				animPeriod = 2;
				initPhase = 0;
			};
		};
		class UserActions
		{
			class Open_bot
			{
				displayName = "Search";
				displayNameDefault = "<img image='\A3\ui_f\data\map\VehicleIcons\iconvehicle_ca.paa' size='2.5' />";
				onlyforplayer = 1;
				position = "actionPoint";
				radius = 3;
				condition = "this animationPhase ""Open_bot"" < 0.5";
				statement = "this animate [""Open_bot"", 1]; this animate [""Open_top"", 1]; this call EPOCH_LootIT;";
			};

		};
	};
	class Fridge_EPOCH : WH_Loot
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\fridge_door_anim.p3d";
		displayName = "Fridge";
		simulClass = "Fridge_SIM_EPOCH";
		staticClass = "Fridge_EPOCH";
		forceSupply = 0;
		isGround = 0;
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\x\addons\a3_epoch_assets\textures\fridge\fridge_CO.paa"};
		availableTextures[] = {"\x\addons\a3_epoch_assets\textures\fridge\fridge_CO.paa","\x\addons\a3_epoch_assets\textures\fridge\fridgeBlack_CO.paa","\x\addons\a3_epoch_assets\textures\fridge\fridgeSteel_co.paa","\x\addons\a3_epoch_assets\textures\fridge\fridgeWhite_co.paa"};
		class AnimationSources
		{
			class Open_bot
			{
				source = "user";
				animPeriod = 2;
				initPhase = 0;
			};
			class Open_top
			{
				source = "user";
				animPeriod = 2;
				initPhase = 0;
			};
		};
		class UserActions
		{
			class Open_bot
			{
				displayName = "Search";
				displayNameDefault = "<img image='\A3\ui_f\data\map\VehicleIcons\iconvehicle_ca.paa' size='2.5' />";
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 3;
				condition = "this animationPhase ""Open_bot"" < 0.5";
				statement = "this animate [""Open_bot"", 1]; this animate [""Open_top"", 1]; this call EPOCH_LootIT;";
			};
			/*
			class Close_bot: Open_bot
			{
				displayName = "Close Bottom";
				condition = "this animationPhase ""Open_bot"" >= 0.5";
				statement = "this animate [""Open_bot"", 0];";
			};
			class Open_top
			{
				displayName = "Open Top";
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 3;
				condition = "this animationPhase ""Open_top"" < 0.5";
				statement = "this animate [""Open_top"", 1]; this call EPOCH_LootIT;";
			};
			class Close_top: Open_top
			{
				displayName = "Close Top";
				condition = "this animationPhase ""Open_top"" >= 0.5";
				statement = "this animate [""Open_top"", 0];";
			};
			*/
		};
	};
	class Pelican_EPOCH : WH_Loot
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\pelican.p3d";
		displayName = "Pelican";
		simulClass = "Pelican_SIM_EPOCH";
		staticClass = "Pelican_EPOCH";
		forceSupply = 0;
		isGround = 0;
		class AnimationSources
		{
			class Open_top
			{
				source = "user";
				animPeriod = 2;
				initPhase = 0;
			};
		};
		class UserActions
		{
			class Open_top
			{
				displayName = "Search";
				displayNameDefault = "<img image='\A3\ui_f\data\map\VehicleIcons\iconvehicle_ca.paa' size='2.5' />";
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 3;
				condition = "this animationPhase ""Open_top"" < 0.5";
				statement = "this animate [""Open_top"", 1]; this call EPOCH_LootIT;";
			};
			/*
			class Close_top: Open_top
			{
				displayName = "Close";
				condition = "this animationPhase ""Open_top"" >= 0.5";
				statement = "this animate [""Open_top"", 0];";
			};
			*/
		};
	};

	class BedProxy_EPOCH: WeaponHolder
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\Bed_proxy.p3d";
		displayName = "Mattress";
		isGround = 0;
	};
	class Bed_EPOCH : Animated_Loot
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\bed.p3d";
		displayName = "Mattress";
		simulClass = "Bed_SIM_EPOCH";
		staticClass = "Bed_EPOCH";
		weaponHolderProxy = "BedProxy_EPOCH";
		destrType = "DestructEngine";
		class DestructionEffects{};
		class Destruction
		{
			animations[] = {{ "x\addons\a3_epoch_assets\models\bed_move.rtm",0.5,3 }};
		};
		class UserActions
		{
			class FlipMattress
			{
				displayName = "Search";
				displayNameDefault = "<img image='\A3\ui_f\data\map\VehicleIcons\iconvehicle_ca.paa' size='2.5' />";
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 3;
				condition = "damage this < 1";
				statement = "this call EPOCH_LootIT;";
			};
		};
	};

	class Bunk_EPOCH : Animated_Loot
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\bunk.p3d";
		displayName = "Bunk";
		simulClass = "Bunk_SIM_EPOCH";
		staticClass = "Bunk_EPOCH";
		weaponHolderProxy = "BedProxy_EPOCH";
		destrType = "DestructEngine";
		class DestructionEffects{};
		class Destruction
		{
			animations[] = { { "x\addons\a3_epoch_assets\models\bunk_move.rtm", 0.5, 3 } };
		};
		class UserActions
		{
			class FlipMattress
			{
				displayName = "Search";
				displayNameDefault = "<img image='\A3\ui_f\data\map\VehicleIcons\iconvehicle_ca.paa' size='2.5' />";
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 3;
				condition = "damage this < 1";
				statement = "this call EPOCH_LootIT;";
			};
		};
	};

	// class Secure_Storage_Proxy : WeaponHolder {};
	class LockBoxProxy_EPOCH : LockBox_EPOCH {};
	class SafeProxy_EPOCH : Safe_EPOCH {};

	class CouchProxy_EPOCH: WeaponHolder
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\couch_proxy.p3d";
		displayName = "Couch";
		isGround = 0;
	};
	class Couch_EPOCH : Animated_Loot
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\couch.p3d";
		displayName = "Couch";
		simulClass = "Couch_SIM_EPOCH";
		staticClass = "Couch_EPOCH";
		weaponHolderProxy = "CouchProxy_EPOCH";
		destrType = "DestructEngine";
		class DestructionEffects{};
		class Destruction
		{
			animations[] = {{ "x\addons\a3_epoch_assets\models\couch_move.rtm",0.5,3 }};
		};
		class UserActions
		{
			class SearchCouch
			{
				displayName = "Search";
				displayNameDefault = "<img image='\A3\ui_f\data\map\VehicleIcons\iconvehicle_ca.paa' size='2.5' />";
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 3;
				condition = "damage this < 1";
				statement = "this call EPOCH_LootIT;";
			};
		};
	};
	class Table_EPOCH : Animated_Loot
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\coffee_table.p3d";
		displayName = "Coffee Table";
		simulClass = "Table_SIM_EPOCH";
		staticClass = "Table_EPOCH";
		weaponHolderProxy = "TableProxy_EPOCH";
		destrType = "DestructEngine";
		class DestructionEffects{};
		class Destruction
		{
			animations[] = { { "x\addons\a3_epoch_assets\models\coffeeTable_Move.rtm", 0.5, 3 } };
		};
		class UserActions
		{
			class SearchCouch
			{
				displayName = "Search";
				displayNameDefault = "<img image='\A3\ui_f\data\map\VehicleIcons\iconvehicle_ca.paa' size='2.5' />";
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 3;
				condition = "damage this < 1";
				statement = "this call EPOCH_LootIT;";
			};
		};
	};
	class TableProxy_EPOCH : WeaponHolder
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\coffee_table_proxy.p3d";
		displayName = "Coffee Table Proxy";
		isGround = 0;
	};
	class ChairProxy_EPOCH: WeaponHolder
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\chair_proxy.p3d";
		displayName = "Chair";
		isGround = 0;
	};
	class Chair_EPOCH : Animated_Loot
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\chair_adult.p3d";
		displayName = "Chair";
		simulClass = "Chair_SIM_EPOCH";
		staticClass = "Chair_EPOCH";
		weaponHolderProxy = "ChairProxy_EPOCH";
		availableTextures[] = {"\x\addons\a3_epoch_assets\textures\chair\chair_ECO.paa","\x\addons\a3_epoch_assets\textures\chair\chair_kid_ECO.paa"};
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\x\addons\a3_epoch_assets\textures\chair\chair_ECO.paa"};
		hiddenSelectionsMaterials[] = {"\x\addons\a3_epoch_assets\textures\chair\chair.rvmat"};
		destrType = "DestructEngine";
		class DestructionEffects{};
		class Destruction
		{
			animations[] = {{ "x\addons\a3_epoch_assets\models\chair_move.rtm",0.5,3 }};
		};
		class UserActions
		{
			class FlipMattress
			{
				displayName = "Search";
				displayNameDefault = "<img image='\A3\ui_f\data\map\VehicleIcons\iconvehicle_ca.paa' size='2.5' />";
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 3;
				condition = "damage this < 1";
				statement = "this call EPOCH_LootIT;";
			};
		};
	};


	class ToolRackProxy_EPOCH : WeaponHolder
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\toolRack_proxy.p3d";
		displayName = "Tool Rack";
		isGround = 0;
	};
	class ToolRack_EPOCH : Animated_Loot
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\toolRack.p3d";
		displayName = "Tool Rack";
		simulClass = "ToolRack_SIM_EPOCH";
		staticClass = "ToolRack_EPOCH";
		weaponHolderProxy = "ToolRackProxy_EPOCH";
		destrType = "DestructEngine";
		class DestructionEffects{};
		class Destruction
		{
			animations[] = { { "x\addons\a3_epoch_assets\models\toolRack_move.rtm", 0.5, 1 } };
		};
		class UserActions
		{
			class LootIT
			{
				displayName = "Search";
				displayNameDefault = "<img image='\A3\ui_f\data\map\VehicleIcons\iconvehicle_ca.paa' size='2.5' />";
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 3;
				condition = "damage this < 1";
				statement = "this call EPOCH_LootIT;";
			};
		};
	};

	class ChairRed_EPOCH: Chair_EPOCH
	{
		scope = 2;
		displayName = "Chair (Red)";
		simulClass = "ChairRed_SIM_EPOCH";
		staticClass = "ChairRed_EPOCH";
		hiddenSelectionsTextures[] = {"\x\addons\a3_epoch_assets\textures\chair\chair_kid_ECO.paa"};
		hiddenSelectionsMaterials[] = {"\x\addons\a3_epoch_assets\textures\chair\chair_kid.rvmat"};
		availableTextures[] = {"\x\addons\a3_epoch_assets\textures\chair\chair_kid_ECO.paa","\x\addons\a3_epoch_assets\textures\chair\chair_ECO.paa"};
	};

	class ShoeboxProxy_EPOCH : WeaponHolder
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\shoebox_proxy.p3d";
		displayName = "Shoebox proxy";
		isGround = 0;
	};
	class Shoebox_EPOCH : Animated_Loot
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\shoebox.p3d";
		displayName = "Shoebox";
		simulClass = "Shoebox_SIM_EPOCH";
		staticClass = "Shoebox_EPOCH";
		weaponHolderProxy = "ShoeboxProxy_EPOCH";
		destrType = "DestructEngine";
		class DestructionEffects{};
		class Destruction
		{
			animations[] = { { "x\addons\a3_epoch_assets\models\shoebox_move.rtm", 0.5, 3 } };
		};
		class UserActions
		{
			class OpenCabinet
			{
				displayName = "Search";
				displayNameDefault = "<img image='\A3\ui_f\data\map\VehicleIcons\iconvehicle_ca.paa' size='2.5' />";
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 3;
				condition = "damage this < 1";
				statement = "this call EPOCH_LootIT;";
			};
		};
	};

	class FilingProxy_EPOCH: WeaponHolder
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\filing_proxy.p3d";
		displayName = "Filing Cabinet";
		isGround = 0;
	};
	class Filing_EPOCH : Animated_Loot
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\filing.p3d";
		displayName = "Filing Cabinet";
		simulClass = "Filing_SIM_EPOCH";
		staticClass = "Filing_EPOCH";
		weaponHolderProxy = "FilingProxy_EPOCH";
		availableTextures[] = {"\x\addons\a3_epoch_assets\textures\filing\filing_co.paa","\x\addons\a3_epoch_assets\textures\filing\filing_blue_co.paa","\x\addons\a3_epoch_assets\textures\filing\filing_green_co.paa"};
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\x\addons\a3_epoch_assets\textures\filing\filing_co.paa"};
		destrType = "DestructEngine";
		class DestructionEffects{};
		class Destruction
		{
			animations[] = {{ "x\addons\a3_epoch_assets\models\filing_move.rtm",0.5,3 }};
		};
		class UserActions
		{
			class OpenCabinet
			{
				displayName = "Search";
				displayNameDefault = "<img image='\A3\ui_f\data\map\VehicleIcons\iconvehicle_ca.paa' size='2.5' />";
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 3;
				condition = "damage this < 1";
				statement = "this call EPOCH_LootIT;";
			};
		};
	};
	class CargoProxy_EPOCH: WeaponHolder
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\filing_proxy.p3d";
		displayName = "Filing Cabinet";
		isGround = 0;
	};

	class Carnival_Tent : Static
	{
		mapSize = 6.19;
		author = "Epoch";
		_generalMacro = "Carnival_Tent";
		scope = 2;
		displayName = "Carnival Tent";
		model = "\x\addons\a3_epoch_assets_3\carnival\models\carnyTent.p3d";

		ladders[] = { { "start1", "end1" } };

		icon = "iconObject_5x2";
		vehicleclass = "Epoch_objects";
		destrType = "DestructNo";
		cost = 5000;
	};


	class Cargo_Container: Static
	{
		mapSize = 6.19;
		author = "$STR_A3_Bohemia_Interactive";
		_generalMacro = "Cargo_Container";
		scope = 2;
		displayName = "$STR_A3_CfgVehicles_Land_Cargo20_orange_F0";
		model = "\A3\Structures_F\Ind\Cargo\Cargo20_orange_F.p3d";
		ladders[] = { { "start1", "end1" } };
		weaponHolderProxy = "Land_PaperBox_C_EPOCH";
		maxloot = 8;
		icon = "iconObject_5x2";
		vehicleClass = "Container";
		destrType = "DestructNo";
		cost = 5000;
		numberOfDoors = 2;
		selectionDamage = "DamT_1";
		class AnimationSources
		{
			class LockedDoor_source
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.1;
			};
			class Door_1_source
			{
				source = "user";
				initPhase = 0;
				animPeriod = 1;
			};
			class Door_2_source
			{
				source = "user";
				initPhase = 0;
				animPeriod = 1;
			};
		};
		class UserActions
		{
			class OpenDoor_1
			{
				displayNameDefault = "<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
				displayName = "Search";
				position = "Door_1_trigger";
				priority = 0.4;
				radius = 1.5;
				onlyForPlayer = 0;
				condition = "(this animationPhase 'Door_1_rot') < 0.5";
				statement = "[this, 'Door_1_rot', 'Door_Handle_1_rot_1', 'Door_Handle_1_rot_2'] call BIS_fnc_DoorOpen; this call EPOCH_LootIT;";
			};
			/*
			class CloseDoor_1: OpenDoor_1
			{
				displayNameDefault = "<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
				displayName = "$STR_DN_OUT_C_DOOR";
				priority = 0.2;
				condition = "((this animationPhase 'Door_1_rot') >= 0.5) && ((this getVariable ['bis_disabled_Door_1',0]) != 1)";
				statement = "([this, 'Door_1_rot', 'Door_Handle_1_rot_1', 'Door_Handle_1_rot_2'] execVM ""\A3\Structures_F\scripts\Door_close.sqf"")";
			};
			class OpenLockedDoor_1: OpenDoor_1
			{
				displayNameDefault = "<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
				condition = "((this animationPhase 'Door_1_rot') < 0.1) && ((this getVariable ['bis_disabled_Door_1',0]) == 1)";
				statement = "([this, 'Door_Handle_1_rot_1', 'Door_Locked_1_rot'] execVM ""\A3\Structures_F\scripts\LockedDoor_open.sqf"")";
			};
			class OpenDoor_2
			{
				displayNameDefault = "<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
				displayName = "$STR_DN_OUT_O_DOOR";
				position = "Door_2_trigger";
				priority = 0.4;
				radius = 1.5;
				onlyForPlayer = 0;
				condition = "((this animationPhase 'Door_2_rot') < 0.5) && ((this getVariable ['bis_disabled_Door_2',0]) != 1)";
				statement = "([this, 'Door_2_rot', 'Door_Handle_2_rot_1', 'Door_Handle_2_rot_2'] execVM ""\A3\Structures_F\scripts\Door_open.sqf"")";
			};
			class CloseDoor_2: OpenDoor_2
			{
				displayNameDefault = "<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
				displayName = "$STR_DN_OUT_C_DOOR";
				priority = 0.2;
				condition = "((this animationPhase 'Door_2_rot') >= 0.5) && ((this getVariable ['bis_disabled_Door_2',0]) != 1)";
				statement = "([this, 'Door_2_rot', 'Door_Handle_2_rot_1', 'Door_Handle_2_rot_2'] execVM ""\A3\Structures_F\scripts\Door_close.sqf"")";
			};
			class OpenLockedDoor_2: OpenDoor_2
			{
				displayNameDefault = "<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
				condition = "((this animationPhase 'Door_2_rot') < 0.1) && ((this getVariable ['bis_disabled_Door_2',0]) == 1)";
				statement = "([this, 'Door_Handle_2_rot_1', 'Door_Locked_2_rot'] execVM ""\A3\Structures_F\scripts\LockedDoor_open.sqf"")";
			};
			*/
		};
		actionBegin1 = "OpenDoor_1";
		actionEnd1 = "OpenDoor_1";
		actionBegin2 = "OpenDoor_2";
		actionEnd2 = "OpenDoor_2";
	};

	class WeaponHolder_Single_F;
	class Grown_Plants_F: WeaponHolder_Single_F
	{
		author = "Epoch";
	};
	// TODO make use of plants 0.2+
	class Poppy_EPOCH: Grown_Plants_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\poppy.p3d";
		displayName = "Poppy";
		transportMaxItems = 0;
		transportMaxMagazines = 1;
		transportMaxWeapons = 0;
		class TransportMagazines
		{
			class _xx_Poppy
			{
				magazine = "Poppy";
				count = 1;
			};
		};
	};
	class Goldenseal_EPOCH : Grown_Plants_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets_3\vegetation\models\goldenseal.p3d";
		displayName = "Goldenseal";
		transportMaxItems = 0;
		transportMaxMagazines = 1;
		transportMaxWeapons = 0;
		class TransportMagazines
		{
			class _xx_Goldenseal
			{
				magazine = "Goldenseal";
				count = 1;
			};
		};
	};
	class Pumpkin_EPOCH : Grown_Plants_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets_3\vegetation\models\pumpkin.p3d";
		displayName = "Pumpkin";
		transportMaxItems = 0;
		transportMaxMagazines = 1;
		transportMaxWeapons = 0;
		class TransportMagazines
		{
			class _xx_Pumpkin
			{
				magazine = "Pumpkin";
				count = 1;
			};
		};
	};

	class ContainerSupply;
	class Land_WoodenBox_C_EPOCH: ContainerSupply
	{
		mapSize = 2.03;
		author = "$STR_A3_Bohemia_Interactive";
		_generalMacro = "Land_WoodenBox_F";
		scope = 2;
		displayName = "$STR_A3_CfgVehicles_Land_WoodenBox_F0";
		model = "\A3\Structures_F\Civ\Constructions\WoodenBox_F.p3d";
		icon = "iconObject_4x1";
	};
	class Land_PaperBox_C_EPOCH: ContainerSupply
	{
		mapSize = 1.459;
		author = "$STR_A3_Bohemia_Interactive";
		_generalMacro = "Land_PaperBox_closed_F";
		scope = 2;
		displayName = "$STR_A3_CfgVehicles_Land_PaperBox_closed_F0";
		model = "\A3\Structures_F_EPA\Mil\Scrapyard\PaperBox_closed_F.p3d";
		icon = "iconObject_1x1";
	};
	class Transport_EPOCH: NonStrategic
	{
		model = "\x\addons\a3_epoch_assets\models\tele.p3d";
		mapSize = 2;
		accuracy = 1000;
		destrType = "DestructNo";
		class UserActions
		{
			class EnterBuilding
			{
				displayNameDefault = "<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
				displayName = "Teleport";
				position = "Epoch_Action_Point";
				priority = 1;
				radius = 3;
				onlyForPlayer = 0;
				condition = "this == this";
				statement = "this call EPOCH_EnterBuilding";
			};
		};
	};
	class Transport_E_EPOCH : Transport_EPOCH
	{
		model = "\x\addons\a3_epoch_assets\models\tele_east.p3d";
	};
	class Transport_W_EPOCH : Transport_EPOCH
	{
		model = "\x\addons\a3_epoch_assets\models\tele_west.p3d";
	};
	class Transport_N_EPOCH : Transport_EPOCH
	{
		model = "\x\addons\a3_epoch_assets\models\tele_north.p3d";
	};
	class Transport_C_EPOCH : Transport_EPOCH
	{
		model = "\x\addons\a3_epoch_assets\models\tele_central.p3d";
	};
	class BloodSplat: NonStrategic
	{
		model = "\A3\characters_F\blood_splash.p3d";
		mapSize = 2;
		accuracy = 1000;
		destrType = "DestructNo";
		armor = 20;
	};
	/*
	class test_EmptyObjectForFireBig;
	class Generic_EmitterG_EPOCH: test_EmptyObjectForFireBig
	{
		displayName = "Generic Emitter (Green)";
		class Eventhandlers
		{
			init = "(_this select 0) execVM ""\x\addons\a3_epoch_config\scripts\fireG.sqf"";";
		};
	};
	class Generic_EmitterB_EPOCH: test_EmptyObjectForFireBig
	{
		displayName = "Generic Emitter (Blue)";
		class Eventhandlers
		{
			init = "(_this select 0) execVM ""\x\addons\a3_epoch_config\scripts\fireB.sqf"";";
		};
	};
	class Generic_EmitterR_EPOCH: test_EmptyObjectForFireBig
	{
		displayName = "Generic Emitter (Red)";
		class Eventhandlers
		{
			init = "(_this select 0) execVM ""\x\addons\a3_epoch_config\scripts\fireR.sqf"";";
		};
	};

	class Generic_BloodE_EPOCH : test_EmptyObjectForFireBig
	{
		displayName = "Generic Emitter (Blood)";
		class Eventhandlers
		{
			init = "(_this select 0) execVM ""\x\addons\a3_epoch_config\scripts\Bite.sqf"";";
		};
	};
	*/

	class centerplane_ui: NonStrategic
	{
		mapSize = 1;
		author = "Kiory";
		_generalMacro = "centerplane_ui";
		scope = 2;
		displayName = "centerplane";
		vehicleClass = "Helpers";
		model = "\x\addons\a3_epoch_assets_3\CfgVehicles\center_plane.p3d";
		hiddenSelections[] = {"usertexture","usertextureL","usertextureR"};
		hiddenSelectionsTextures[] = {""};
	};
	class logo_plane_EPOCH: NonStrategic
	{
		mapSize = 1;
		author = "Epoch";
		_generalMacro = "logo_plane_EPOCH";
		scope = 2;
		displayName = "Epoch Logo";
		vehicleClass = "Helpers";
		model = "\x\addons\a3_epoch_assets\models\logo.p3d";
	};



	class Animal;
	class Animal_Base_F : Animal
	{
		class EventHandlers;
	};
	/*
	class Bear_Base_F: Animal_Base_F
	{
		scope = 2;
		displayName = "Bear";
		model = "\x\addons\a3_epoch_assets_3\CfgVehicles\Characters\bear.p3d";
		hasGeometry = 1;
		moves = "CfgMovesBear_F";
		class VariablesScalar
		{
			_threatMaxRadius = 30;
			_runDistanceMax = 70;
			_movePrefer = 0.25;
			_formationPrefer = 0.8;
			_scareLimit = 0.2;
			_dangerLimit = 5.0;
			_walkSpeed = 1.2;
		};
		class VariablesString
		{
			_expSafe = "(0.5 * meadow) * (0.5 *  trees) * (1 - forest) * (1 - houses) * (1 - sea) * hills";
			_expDanger = "(1 - sea) * hills";
		};
		class Wounds
		{
			tex[] = {};
			mat[] = {"A3\animals_f_beta\Goat\data\goat.rvmat","A3\animals_f_beta\Goat\data\W1_goat.rvmat","A3\animals_f_beta\Goat\data\W2_goat.rvmat"};
		};
		class EventHandlers;
		hiddenSelections[] = {"camo"};
	};
	*/
	class Construct_F : Animal_Base_F
	{
		scope = 2;
		displayName = "Constuct";
		model = "\x\addons\a3_epoch_assets_3\CfgVehicles\Characters\construct.p3d";
		hasGeometry = 1;
		moves = "CfgMovesConstruct_F";
		class VariablesScalar
		{
			_threatMaxRadius = 30;
			_runDistanceMax = 70;
			_movePrefer = 0.25;
			_formationPrefer = 0.8;
			_scareLimit = 0.2;
			_dangerLimit = 5.0;
			_walkSpeed = 1.2;
		};
		class VariablesString
		{
			_expSafe = "(0.5 * meadow) * (0.5 *  trees) * (1 - forest) * (1 - houses) * (1 - sea) * hills";
			_expDanger = "(1 - sea) * hills";
		};
		class Wounds
		{
			tex[] = {};
			mat[] = { "A3\animals_f_beta\Goat\data\goat.rvmat", "A3\animals_f_beta\Goat\data\W1_goat.rvmat", "A3\animals_f_beta\Goat\data\W2_goat.rvmat" };
		};
		class EventHandlers;
		hiddenSelections[] = { "camo" };
	};




	class Shark_Base_F : Animal_Base_F
	{
		moves = "CfgMovesGreatWhite_F";
		memoryPointAim = "pilot";
		memoryPointCameraTarget = "camera";
		minHeight = "(-1 * waterDepth)";
		avgHeight = "(-1 * waterDepth)/4";
		maxHeight = -1.5;
		straightDistance = 2;
		turning = 5;
		class VariablesScalar
		{
			_threatMaxRadius = 5;
			_runDistanceMax = 25;
			_movePrefer = 1;
			_formationPrefer = 0.7;
			_scareLimit = 0.2;
			_dangerLimit = 1.0;
			_walkSpeed = -1;
		};
		class VariablesString
		{
			_expSafe = "waterDepth interpolate [2,3,0,1]";
			_expDanger = "waterDepth interpolate [2,3,0,1]";
		};
	};
	class GreatWhite_F : Shark_Base_F
	{
		scope = 1;
		displayName = "Great White";
		model = "\x\addons\a3_epoch_assets\models\shark_epoch.p3d";
		moves = "CfgMovesGreatWhite_F";
		hasGeometry = 1;
		agentTasks[] = {};
		interactMode = 3;
	};

	class Goat_random_EPOCH : Animal_Base_F
	{
		scope = 1;
		displayName = "$STR_A3_CfgVehicles_Goat_Base_F0";
		model = "\A3\animals_f_beta\Goat\Goat_F.p3d";
		hasGeometry = 1;
		agentTasks[] = {};
		moves = "CfgMovesGoat_F";
		class Wounds
		{
			tex[] = {};
			mat[] = { "A3\animals_f_beta\Goat\data\goat.rvmat", "A3\animals_f_beta\Goat\data\W1_goat.rvmat", "A3\animals_f_beta\Goat\data\W2_goat.rvmat" };
		};
		interactMode = 3;
	};

	class Sheep_random_EPOCH : Animal_Base_F
	{
		scope = 1;
		displayName = "$STR_A3_CfgVehicles_Sheep_random_F0";
		model = "\A3\animals_f_beta\Sheep\Sheep_F.p3d";
		hasGeometry = 1;
		moves = "CfgMovesSheep_F";
		class Wounds
		{
			tex[] = {};
			mat[] = { "A3\animals_f_beta\sheep\data\sheep.rvmat", "A3\animals_f_beta\sheep\data\W1_sheep.rvmat", "A3\animals_f_beta\sheep\data\W2_sheep.rvmat" };
		};
		interactMode = 3;
	};

	class Cock_random_F;
	class Cock_random_EPOCH: Cock_random_F {
		agentTasks[] = {};
		interactMode = 3;
	};
	class Hen_random_F;
	class Hen_random_EPOCH: Hen_random_F {
		agentTasks[] = {};
		interactMode = 3;
	};

	class Rabbit_F : Animal_Base_F
	{
		author = "$STR_A3_Bohemia_Interactive";
		_generalMacro = "Rabbit_F";
		scope = 2;
		displayName = "$STR_A3_CfgVehicles_Rabbit_F0";
		model = "\A3\Animals_F\rabbit\rabbit_F.p3d";
		side = 3;
		moves = "CfgMovesRabbit_F";
		fsmFormation = "";
		fsmDanger = "";
		maxTurnAngularVelocity = 30;
		costTurnCoef = 1e-005;
		boneHead = "head";
		bonePrimaryWeapon = "head";
		weaponBone = "head";
		triggerAnim = "";
		class VariablesScalar
		{
			_threatMaxRadius = 20;
			_runDistanceMax = 50;
			_movePrefer = 0.7;
			_formationPrefer = 0.2;
			_scareLimit = 0.2;
			_dangerLimit = 1.0;
			_walkSpeed = 0.9;
		};
		class VariablesString
		{
			_expSafe = "(0.5 * meadow) * (0.5 *  trees) * (1 - forest) * (1 - houses) * (1 - sea)";
			_expDanger = "(trees) * (forest) * (1 - meadow) * (1 - houses) * (1 - sea)";
		};
		class Wounds
		{
			tex[] = {};
			mat[] = { "A3\Animals_F\Rabbit\data\Rabbit.rvmat", "A3\Animals_F\Rabbit\data\W1_Rabbit.rvmat", "A3\Animals_F\Rabbit\data\W2_Rabbit.rvmat" };
		};
		class EventHandlers : EventHandlers
		{
			init = "deleteVehicle (_this select 0)";
		};
	};

	class Rabbit_EPOCH : Animal_Base_F {

		author = "$STR_A3_Bohemia_Interactive";
		_generalMacro = "Rabbit_F";
		scope = 2;
		displayName = "$STR_A3_CfgVehicles_Rabbit_F0";
		model = "\A3\Animals_F\rabbit\rabbit_F.p3d";
		side = 3;
		moves = "CfgMovesRabbit_F";
		fsmFormation = "";
		fsmDanger = "";
		maxTurnAngularVelocity = 30;
		costTurnCoef = 1e-005;
		boneHead = "head";
		bonePrimaryWeapon = "head";
		weaponBone = "head";
		triggerAnim = "";
		class VariablesScalar
		{
			_threatMaxRadius = 20;
			_runDistanceMax = 50;
			_movePrefer = 0.7;
			_formationPrefer = 0.2;
			_scareLimit = 0.2;
			_dangerLimit = 1.0;
			_walkSpeed = 0.9;
		};
		class VariablesString
		{
			_expSafe = "(0.5 * meadow) * (0.5 *  trees) * (1 - forest) * (1 - houses) * (1 - sea)";
			_expDanger = "(trees) * (forest) * (1 - meadow) * (1 - houses) * (1 - sea)";
		};
		class Wounds
		{
			tex[] = {};
			mat[] = { "A3\Animals_F\Rabbit\data\Rabbit.rvmat", "A3\Animals_F\Rabbit\data\W1_Rabbit.rvmat", "A3\Animals_F\Rabbit\data\W2_Rabbit.rvmat" };
		};

		agentTasks[] = {};
		hasGeometry = 1;
		interactMode = 3;
	};

	class Snake_random_EPOCH : Animal_Base_F
	{
		scope = 1;
		agentTasks[] = {};
		displayName = "Dice Snake";
		model = "\A3\Animals_F\Snakes\snake_F.p3d";
		side = 3;
		moves = "CfgMovesSnakes_F";
		fsmFormation = "";
		fsmDanger = "";
		maxTurnAngularVelocity = 30;
		costTurnCoef = 1e-005;
		boneHead = "head";
		bonePrimaryWeapon = "head";
		weaponBone = "head";
		triggerAnim = "";
		hiddenSelections[] = { "camo" };
		hiddenSelectionsTextures[] = { "\A3\Animals_F\Snakes\data\Snake_Dice_CO.paa" };
		interactMode = 3;
	};
	class Snake2_random_EPOCH : Snake_random_EPOCH
	{
		displayName = "Leopard Snake";
		hiddenSelectionsTextures[] = { "\A3\Animals_F\Snakes\data\Snake_Leopard_CO.paa" };
	};

	class Snake_random_F : Animal_Base_F
	{
		scope = 1;
		displayName = "$STR_A3_CfgVehicles_Snake_random_F0";
		model = "\A3\Animals_F\Snakes\snake_F.p3d";
		side = 3;
		moves = "CfgMovesSnakes_F";
		fsmFormation = "";
		fsmDanger = "";
		maxTurnAngularVelocity = 30;
		costTurnCoef = 1e-005;
		boneHead = "head";
		bonePrimaryWeapon = "head";
		weaponBone = "head";
		triggerAnim = "";

		class EventHandlers : EventHandlers
		{
			init = "deleteVehicle (_this select 0)";
		};
	};

	class Fin_blackwhite_F;
	class Fin_random_EPOCH : Fin_blackwhite_F {
		agentTasks[] = {};
		hasGeometry = 1;
		interactMode = -1;
	};
	class Alsatian_Black_F;
	class Alsatian_Random_EPOCH : Alsatian_Black_F {
		agentTasks[] = {};
		hasGeometry = 1;
		interactMode = -1;
	};

	class C_Kart_01_Fuel_F;
	class K01 : C_Kart_01_Fuel_F
	{
		class UserActions
		{
			class PressXToFlipTheThing
			{
				displayNameDefault = "Flip Kart";
				displayName = "Flip Kart";
				position = "";
				radius = 2.7;
				onlyForPlayer = 1;
				condition = "alive this && not canmove this && crew this isEqualTo []";
				statement = "this setvectorup [0,0,1]";
			};
		};
	};
	class C_Kart_01_Blu_F;
	class K02 : C_Kart_01_Blu_F
	{
		class UserActions
		{
			class PressXToFlipTheThing
			{
				displayNameDefault = "Flip Kart";
				displayName = "Flip Kart";
				position = "";
				radius = 2.7;
				onlyForPlayer = 1;
				condition = "alive this && not canmove this && crew this isEqualTo []";
				statement = "this setvectorup [0,0,1]";
			};
		};
	};
	class C_Kart_01_Red_F;
	class K03 : C_Kart_01_Red_F
	{
		class UserActions
		{
			class PressXToFlipTheThing
			{
				displayNameDefault = "Flip Kart";
				displayName = "Flip Kart";
				position = "";
				radius = 2.7;
				onlyForPlayer = 1;
				condition = "alive this && not canmove this && crew this isEqualTo []";
				statement = "this setvectorup [0,0,1]";
			};
		};
	};
	class C_Kart_01_Vrana_F;
	class K04 : C_Kart_01_Vrana_F
	{
		class UserActions
		{
			class PressXToFlipTheThing
			{
				displayNameDefault = "Flip Kart";
				displayName = "Flip Kart";
				position = "";
				radius = 2.7;
				onlyForPlayer = 1;
				condition = "alive this && not canmove this && crew this isEqualTo []";
				statement = "this setvectorup [0,0,1]";
			};
		};
	};
	class UAV_01_base_F;
	class I_UAV_01_F: UAV_01_base_F
	{
		fuelCapacity = 50000;
	};
};
