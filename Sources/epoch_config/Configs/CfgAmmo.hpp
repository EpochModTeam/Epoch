class CfgAmmo
{
	class BulletBase;
	class B_Test_45ACP_Ball: BulletBase
	{
		hit = 0;
		indirectHit = 0;
		indirectHitRange = 0;
		cartridge = "FxCartridge_9mm";
		caliber = 2.6;
		deflecting = 45;
		visibleFire = 5;
		audibleFire = 9;
		cost = 100;
		typicalSpeed = 280;
		airFriction = -0.0018;
	};
	class B_Hatchet : BulletBase
	{
		hit = 3;
		indirectHit = 0;
		indirectHitRange = 0;
		cartridge = "FxCartridge_9mm";
		caliber = 2.6;
		deflecting = 45;
		visibleFire = 5;
		audibleFire = 9;
		cost = 100;
		typicalSpeed = 10;
		airFriction = -0.0018;
		muzzleEffect = "";
		minRange = 1;
		minRangeProbab = 0.8;
		midRange = 2;
		midRangeProbab = 1.5;
		maxRange = 3;
		maxRangeProbab = 2.5;
		explosive = 0;
		simulationStep = 0.001;
		timeToLive = 0.03;
		soundHit[] = { "", "db-90", 1 };
		soundEngine[] = { "", "db-80", 4 };
	};
	class B_Swing: BulletBase
	{
		hit = 8;
		indirectHit = 0;
		indirectHitRange = 0;
		cartridge = "FxCartridge_9mm";
		simulation = "shotRocket";
		effectsMissileInit = "";
		effectsMissile = "EmptyEffect";
		model = "\x\addons\a3_epoch_assets_3\CfgVehicles\swing_box.p3d";
		caliber = 0.26;
		deflecting = 0;
		visibleFire = 0.1;
		audibleFire = 1;
		cost = 100;
		typicalSpeed = 275;
		airFriction = -0.0018;
		minRange = 1;
		minRangeProbab = 0.8;
		midRange = 2;
		midRangeProbab = 1.5;
		maxRange = 3;
		maxRangeProbab = 2.5;
		explosive = 0;
		simulationStep = 0.001;
		timeToLive = 0.004;
		soundHit[] = {"","db-90",1};
		soundEngine[] = {"","db-80",4};
	};
	class B_Stick : BulletBase
	{
		hit = 2;
		indirectHit = 0;
		indirectHitRange = 0;
		cartridge = "FxCartridge_9mm";
		simulation = "shotRocket";
		effectsMissileInit = "";
		effectsMissile = "EmptyEffect";
		model = "\x\addons\a3_epoch_assets_3\CfgVehicles\swing_box.p3d";
		caliber = 0.26;
		deflecting = 0;
		visibleFire = 0.1;
		audibleFire = 1;
		cost = 100;
		typicalSpeed = 275;
		airFriction = -0.0018;
		minRange = 1;
		minRangeProbab = 0.8;
		midRange = 2;
		midRangeProbab = 1.5;
		maxRange = 3;
		maxRangeProbab = 2.5;
		explosive = 0;
		simulationStep = 0.001;
		timeToLive = 0.004;
		soundHit[] = { "", "db-90", 1 };
		soundEngine[] = { "", "db-80", 4 };
	};
	class PipeBombBase;
	class Sapper_Charge_Ammo: PipeBombBase
	{
		hit = 50;
		indirectHit = 10;
		indirectHitRange = 5;
		model = "\x\addons\a3_epoch_assets_3\CfgVehicles\swing_box.p3d";
		mineModelDisabled = "";
		defaultMagazine = "IEDLandSmall_Remote_Mag";
		soundHit[] = {"A3\sounds_f\weapons\Mines\mine_debris_6",2.5118864,1,1500};
		soundTrigger[] = {"A3\Sounds_F\weapons\mines\mech_trigger_1",0.56234133,1,40};
		soundActivation[] = {"A3\Sounds_F\weapons\mines\mech_activate_mine_1",0.56234133,1,40};
		CraterEffects = "IEDMineSmallLandCrater";
		explosionEffects = "IEDMineSmallExplosion";
		whistleDist = 6;
		cost = 200;
		mineInconspicuousness = 50;
		mineTrigger = "RemoteTrigger";
	};
	class SapperB_Charge_Ammo : PipeBombBase
	{
		hit = 1500;
		indirectHit = 1500;
		indirectHitRange = 5;
		model = "\x\addons\a3_epoch_assets_3\CfgVehicles\swing_box.p3d";
		mineModelDisabled = "";
		defaultMagazine = "SatchelCharge_Remote_Mag";
		soundHit[] = { "A3\Sounds_F\weapons\Mines\mine_debris_2", 3.1622777, 1, 1500 };
		ExplosionEffects = "MineNondirectionalExplosion";
		CraterEffects = "MineNondirectionalCrater";
		whistleDist = 10;
		cost = 200;
		mineInconspicuousness = 50;
		mineTrigger = "RemoteTrigger";
	};
	class GrenadeHand;
	class SmokeShellCustom : GrenadeHand
	{
		model = "\x\addons\a3_epoch_assets_3\CfgVehicles\swing_box.p3d";
		hit = 0;
		indirectHit = 0;
		indirectHitRange = 0;
		typicalspeed = 22;
		cost = 100;
		simulation = "shotSmokeX";
		explosive = 0;
		deflecting = 60;
		explosionTime = 2;
		timeToLive = 60;
		fuseDistance = 0;
		soundHit[] = { "", 0, 1 };
		
		SmokeShellSoundLoop1[] = { "A3\Sounds_F\weapons\smokeshell\smoke_loop1", 0.12589253, 1, 70 };
		SmokeShellSoundLoop2[] = { "A3\Sounds_F\weapons\smokeshell\smoke_loop2", 0.12589253, 1, 70 };

		grenadeFireSound[] = {};
		grenadeBurningSound[] = { "SmokeShellSoundLoop1", 0.5, "SmokeShellSoundLoop2", 0.5 };
		
		impactGroundSoft[] = {};
		impactGroundHard[] = {};
		impactIron[] = {};
		impactArmor[] = {};
		impactBuilding[] = {};
		impactFoliage[] = {};
		impactWood[] = {};
		impactGlass[] = {};
		impactGlassArmored[] = {};
		impactConcrete[] = {};
		impactRubber[] = {};
		impactPlastic[] = {};
		impactDefault[] = {};
		impactMetal[] = {};
		impactMetalplate[] = {};
		impactWater[] = {};
		
		effectsSmoke = "SmokeShellWhiteEffect";
		whistleDist = 0;
		smokeColor[] = { 0.039, 0.278, 0, 0.5 };
	};
	
	class B_Test_Caseless: BulletBase
	{
		hit = 10;
		indirectHit = 0;
		indirectHitRange = 0;
		cartridge = "FxCartridge_65_caseless";
		visibleFire = 5;
		audibleFire = 8;
		cost = 1.2;
		airLock = 1;
		typicalSpeed = 820;
		caliber = 1.0;
		model = "\A3\Weapons_f\Data\bullettracer\tracer_red";
		tracerScale = 1.0;
		tracerStartTime = 0.05;
		tracerEndTime = 1;
		airFriction = -0.00096;
		class CamShakeFire
		{
			power = 0;
			duration = 0;
			frequency = 0;
			distance = 0;
		};
		class CamShakePlayerFire
		{
			power = 0;
			duration = 0;
			frequency = 0;
			distance = 0;
		};
	};
	class ChainSaw_Bullet: BulletBase
	{
		hit = 5;
		indirectHit = 0;
		indirectHitRange = 0;
		cartridge = "FxCartridge_65_caseless";
		visibleFire = 5;
		audibleFire = 8;
		cost = 1.2;
		airLock = 0;
		typicalSpeed = 100;
		caliber = 1.0;
		model = "\A3\Weapons_f\Data\bullettracer\tracer_red";
		tracerScale = 1.0;
		tracerStartTime = 0.05;
		tracerEndTime = 1;
		airFriction = -0.00096;
		class CamShakeFire
		{
			power = 0;
			duration = 0;
			frequency = 0;
			distance = 0;
		};
		class CamShakePlayerFire
		{
			power = 0;
			duration = 0;
			frequency = 0;
			distance = 0;
		};
		minRange = 1;
		minRangeProbab = 0.8;
		midRange = 2;
		midRangeProbab = 1.5;
		maxRange = 2.5;
		maxRangeProbab = 2;
		explosive = 0;
		simulationStep = 0.001;
		timeToLive = 0.03;
		soundHit[] = {"","db-90",1};
		soundEngine[] = {"","db-80",4};
	};
};