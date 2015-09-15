
class CfgMovesAnimal_Base_F
{
	access = 1;
	collisionVertexPattern[] = {};
	collisionGeomCompPattern[] = {1};
	class Default
	{
		access = 3;
		file = "";
		looped = 1;
		speed = 0.5;
		disableWeapons = 1;
		enableOptics = 1;
		disableWeaponsLong = 0;
		canreload = 1;
		showWeaponAim = 1;
		enableMissile = 0;
		enableBinocular = 0;
		showItemInHand = 0;
		showItemInRightHand = 0;
		showHandGun = 0;
		onLandBeg = 0;
		onLandEnd = 0;
		onLadder = 0;
		canPullTrigger = 1;
		duty = -0.51;
		predictSpeedCoef = 1;
		visibleSize = 1;
		aimPrecision = 1;
		relSpeedMin = 1.0;
		relSpeedMax = 1.0;
		soundEnabled = 1;
		soundOverride = "";
		soundEdge[] = {0.5,1};
		soundEdge1 = 0.5;
		soundEdge2 = 1;
		terminal = 0;
		limitGunMovement = 1;
		variantsPlayer[] = {};
		variantsAI[] = {};
		equivalentTo = "";
		connectAs = "";
		variantAfter[] = {5,10,20};
		connectFrom[] = {};
		connectTo[] = {};
		interpolateWith[] = {};
		interpolateTo[] = {};
		interpolateFrom[] = {};
		aiming = "aimingNo";
		leaning = "aimingNo";
		untiltWeapon = "aimingNo";
		aimingBody = "aimingUpDefault";
		legs = "legsNo";
		head = "headDefault";
		leaningFactorBeg = 0;
		leaningFactorEnd = 0;
		leaningFactorZeroPoint = -1;
		leaningCorrectionAngleBeg = 0;
		leaningCorrectionAngleEnd = 0;
		interpolationSpeed = 6;
		interpolationRestart = 0;
		hasCollShapeSafe = 0;
		collisionShapeSafe = "";
		boundingSphere = 1;
		enableDirectControl = 1;
		enableAutoActions = 0;
		leftHandIKBeg = 0;
		leftHandIKEnd = 0;
		leftHandIKCurve = 0;
		rightHandIKCurve = 0;
		rightHandIKBeg = 0;
		rightHandIKEnd = 0;
		weaponIK = 0;
		preload = 0;
		walkcycles = 1;
		forceAim = 0;
		showDisposableGun = 0;
		headBobStrength = 0.5;
		headBobMode = 1;
	};
	class StandBase: Default
	{
		duty = -1;
		head = "headDefault";
		speed = 1e+010;
		relSpeedMin = 0.7;
		relSpeedMax = 1.1;
		looped = 1;
		soundEnabled = 1;
		enableDirectControl = 0;
		disableWeapons = 1;
		disableWeaponsLong = 1;
	};
	class DefaultDie: Default
	{
		aiming = "aimingNo";
		legs = "legsNo";
		head = "headNo";
	};
	class ManActions
	{
		Stop = "";
		StopRelaxed = "";
		TurnL = "";
		TurnR = "";
		TurnLRelaxed = "";
		TurnRRelaxed = "";
		Default = "";
		JumpOff = "";
		ReloadMagazine = "";
		ReloadMGun = "";
		ReloadAT = "";
		ReloadMortar = "";
		ThrowGrenade = "";
		WalkF = "";
		WalkLF = "";
		WalkRF = "";
		WalkL = "";
		WalkR = "";
		WalkLB = "";
		WalkRB = "";
		WalkB = "";
		SlowF = "";
		SlowLF = "";
		SlowRF = "";
		SlowL = "";
		SlowR = "";
		SlowLB = "";
		SlowRB = "";
		SlowB = "";
		FastF = "";
		FastLF = "";
		FastRF = "";
		FastL = "";
		FastR = "";
		FastLB = "";
		FastRB = "";
		FastB = "";
		EvasiveForward = "";
		EvasiveLeft = "";
		EvasiveRight = "";
		EvasiveBack = "";
		StartSwim = "";
		StopSwim = "";
		Down = "";
		Up = "";
		PlayerStand = "";
		PlayerCrouch = "";
		PlayerProne = "";
		Lying = "";
		Stand = "";
		Combat = "";
		Crouch = "";
		CanNotMove = "";
		Civil = "";
		CivilLying = "";
		FireNotPossible = "";
		Die = "";
		WeaponOn = "";
		WeaponOff = "";
		StrokeFist = "";
		StrokeGun = "";
		SitDown = "";
		Salute = "";
		BinocOn = "";
		BinocOff = "";
		PutDown = "";
		PutDownEnd = "";
		Medic = "";
		Treated = "";
		LadderOnDown = "";
		LadderOnUp = "";
		LadderOff = "";
		LadderOffTop = "";
		LadderOffBottom = "";
		GetInLow = "";
		GetInMedium = "";
		GetInHigh = "";
		GetOutLow = "";
		GetOutMedium = "";
		GetOutHigh = "";
		TakeFlag = "";
		HandGunOn = "";
		LookAround = "";
		Eat = "";
		StopEat = "";
		Rest = "";
		StopRest = "";
	};
	class Actions
	{
		class NoActions: ManActions
		{
			turnSpeed = 8;
			limitFast = 5.5;
			useFastMove = 0;
			stance = "ManStanceUndefined";
			upDegree = 0;
		};
	};
	class Interpolations{};
	transitionsInterpolated[] = {};
	transitionsSimple[] = {};
	transitionsDisabled[] = {};
	class BlendAnims
	{
		aimingDefault[] = {"head",1};
		untiltWeaponDefault[] = {};
		legsDefault[] = {};
		headDefault[] = {"Head",1};
		aimingNo[] = {};
		legsNo[] = {};
		headNo[] = {};
		aimingUpDefault[] = {};
	};
};
class CfgMovesBear_F: CfgMovesAnimal_Base_F
{
	access = 1;
	skeletonName = "Bear";
	collisionVertexPattern[] = {"1a","2a","3a","4a","5a","6a","7a","8a","9a","10a","11a","12a","13a","14a","15a","16a","17a","18a","19a","20a","21a","22a","23a","24a","25a","26a","27a","28a","29a","30a","31a","32a","33a","34a"};
	collisionGeomCompPattern[] = {1};
	class Default: Default
	{
		actions = "BearActions";
		collisionShape = "A3\animals_f_beta\goat\goat_CollShape.p3d";
	};
	class StandBase: Default
	{
		aiming = "aimingDefault";
		disableWeapons = 1;
	};
	class DefaultDie: Default
	{
		enableDirectControl = 0;
		aiming = "aimingNo";
		legs = "legsNo";
		head = "headNo";
		disableWeapons = 1;
		interpolationRestart = 1;
	};
	class States
	{
		class Bear_Walk: StandBase
		{
			actions = "BearActions";
			duty = -0.7;
			enableDirectControl = 0;
			file = "\x\addons\a3_epoch_assets_3\CfgVehicles\Characters\bear_walk1_a.rtm";
			showWeaponAim = 0;
			disableWeapons = 1;
			disableWeaponsLong = 1;
			// variantsAI[] = {"Goat_Stop",0.2,"Goat_Walk",0.1};
			variantAfter[] = {3,10,20};
			speed = 0.5;
			relSpeedMin = 0.7;
			relSpeedMax = 1.1;
			looped = 1;
			soundEnabled = 0;
			//connectTo[] = {"Goat_Stop",0.02,"Goat_Walk",0.2,"Goat_Sprint",0.02};
			//connectFrom[] = {"Goat_Stop",0.02,"Goat_Walk",0.2,"Goat_Sprint",0.02};
			//interpolateTo[] = {"Goat_Stop",0.02,"Goat_Walk",0.2,"Goat_Sprint",0.02,"Goat_Die",0.01};
			enableBinocular = 1;
			preload = 1;
		};
	};
	class Actions: Actions
	{
		class NoActions: NoActions
		{
			turnSpeed = 3;
			limitFast = 5.5;
			useFastMove = 0;
			upDegree = 0;
		};
		class BearActions: NoActions
		{
			Stop = "";
			StopRelaxed = "";
			TurnL = "";
			TurnR = "";
			TurnLRelaxed = "";
			TurnRRelaxed = "";
			Default = "";
			JumpOff = "";
			WalkF = "Bear_Walk";
			SlowF = "Bear_Walk";
			FastF = "Bear_Walk";
			EvasiveForward = "";
			Down = "";
			Up = "";
			PlayerStand = "";
			PlayerCrouch = "";
			PlayerProne = "";
			Lying = "";
			Stand = "";
			Combat = "";
			Crouch = "";
			CanNotMove = "";
			Civil = "";
			CivilLying = "";
			FireNotPossible = "";
			Die = "";
			turnSpeed = 8;
			limitFast = 5.5;
			useFastMove = 0;
			upDegree = "ManPosNoWeapon";
		};
	};
	class Interpolations{};
	transitionsInterpolated[] = {};
	transitionsSimple[] = {};
	transitionsDisabled[] = {};
	class BlendAnims: BlendAnims
	{
		aimingDefault[] = {"Bear_Head",1,"Bear_Head",1,"Bear_Head",1};
		headDefault[] = {"Bear_Head",1,"Bear_Neck2",1,"Bear_Neck1",0.6,"Bear_Spine2",0.2};
		untiltWeaponDefault[] = {};
		legsDefault[] = {};
		aimingNo[] = {};
		legsNo[] = {};
		headNo[] = {};
		aimingUpDefault[] = {};
	};
};

class CfgMovesConstruct_F : CfgMovesAnimal_Base_F
{
	access = 1;
	skeletonName = "construct_skeleton";
	collisionVertexPattern[] = { "1a", "2a", "3a", "4a", "5a", "6a", "7a", "8a", "9a", "10a", "11a", "12a", "13a", "14a", "15a", "16a", "17a", "18a", "19a", "20a", "21a", "22a", "23a", "24a", "25a", "26a", "27a", "28a", "29a", "30a", "31a", "32a", "33a", "34a" };
	collisionGeomCompPattern[] = { 1 };
	class Default : Default
	{
		actions = "ConstructActions";
		collisionShape = "x\addons\a3_epoch_assets_3\CfgVehicles\Characters\construct_CollShape.p3d";
	};
	class StandBase : Default
	{
		aiming = "aimingDefault";
		disableWeapons = 1;
	};
	class DefaultDie : Default
	{
		enableDirectControl = 0;
		aiming = "aimingNo";
		legs = "legsNo";
		head = "headNo";
		disableWeapons = 1;
		interpolationRestart = 1;
	};
	class States
	{
		class Construct_Stop : StandBase
		{
			legs = "legsDefault";
			actions = "ConstructActions";
			duty = -1;
			enableDirectControl = 0;
			file = "\x\addons\a3_epoch_assets_3\CfgVehicles\Characters\Construct_stop.rtm";
			showWeaponAim = 0;
			disableWeapons = 1;
			disableWeaponsLong = 1;
			variantsAI[] = { "Construct_Stop", 0.2, "Construct_Walk", 0.1 };
			variantAfter[] = { 0, 2, 3 };
			speed = 1e+010;
			relSpeedMin = 0.7;
			relSpeedMax = 1.1;
			looped = 1;
			soundEnabled = 0;
			connectTo[] = { "Construct_Stop", 0.02, "Construct_Walk", 0.2, "Construct_Sprint", 0.02 };
			connectFrom[] = { "Construct_Stop", 0.02, "Construct_Walk", 0.2, "Construct_Sprint", 0.02 };
			interpolateTo[] = { "Construct_Stop", 0.02, "Construct_Walk", 0.2, "Construct_Sprint", 0.02, "Construct_Die", 0.01 };
			enableBinocular = 1;
			preload = 1;
		};
		class Construct_TurnL : Construct_Stop
		{
			file = "\x\addons\a3_epoch_assets_3\CfgVehicles\Characters\construct_rotateL.rtm";
			connectTo[] = { "Construct_Stop", 0.25 };
			connectFrom[] = { "Construct_Stop", 0.25 };
			interpolateTo[] = { "Construct_Stop", 0.25, "Construct_Die", 0.01 };
			interpolateFrom[] = { "Construct_Stop", 0.25 };
			speed = 0.1;
		};
		class Construct_TurnR : Construct_TurnL
		{
			file = "\x\addons\a3_epoch_assets_3\CfgVehicles\Characters\construct_rotateR.rtm";
		};
		class Construct_Init : Construct_Stop{};
		class Construct_Walk : Construct_Stop
		{
			duty = -0.7;
			file = "\x\addons\a3_epoch_assets_3\CfgVehicles\Characters\construct_walk.rtm";
			speed = 0.2;
			variantAfter[] = { 3, 10, 20 };
		};
		class Construct_Sprint : Construct_Walk
		{
			file = "\x\addons\a3_epoch_assets_3\CfgVehicles\Characters\construct_leap.rtm";
			speed = 0.2;
		};
		class Construct_Eat : StandBase
		{
			speed = -6.0;
			file = "\x\addons\a3_epoch_assets_3\CfgVehicles\Characters\construct_slam.rtm";
			connectTo[] = { "Construct_Stop", 0.1 };
			connectFrom[] = { "Construct_Walk", 0.1 };
			interpolateTo[] = { "Construct_Die", 0.1 };
		};
		class Construct_Die : DefaultDie
		{
			actions = "NoActions";
			file = "\x\addons\a3_epoch_assets_3\CfgVehicles\Characters\construct_death.rtm";
			speed = 0.3;
			looped = 0;
			variantsPlayer[] = {};
			variantsAI[] = {};
			variantAfter[] = { 0, 0, 0 };
			terminal = 1;
		};
	};
	class Actions : Actions
	{
		class NoActions : NoActions
		{
			turnSpeed = 3;
			limitFast = 5.5;
			useFastMove = 0;
			upDegree = 0;
		};
		class ConstructActions : NoActions
		{
			Stop = "Construct_Stop";
			StopRelaxed = "Construct_Eat";
			TurnL = "Construct_TurnL";
			TurnR = "Construct_TurnR";
			TurnLRelaxed = "Construct_TurnL";
			TurnRRelaxed = "Construct_TurnR";
			Default = "Construct_Eat";
			JumpOff = "Construct_Stop";
			WalkF = "Construct_Walk";
			SlowF = "Construct_Walk";
			FastF = "Construct_Sprint";
			EvasiveForward = "Construct_Sprint";
			Down = "Construct_Stop";
			Up = "Construct_Stop";
			PlayerStand = "Construct_Stop";
			PlayerCrouch = "Construct_Stop";
			PlayerProne = "Construct_Stop";
			Lying = "Construct_Stop";
			Stand = "Construct_Stop";
			Combat = "Construct_Stop";
			Crouch = "Construct_Stop";
			CanNotMove = "Construct_Stop";
			Civil = "Construct_Eat";
			CivilLying = "Construct_Stop";
			FireNotPossible = "Construct_Stop";
			Die = "Construct_Die";
			turnSpeed = 3;
			limitFast = 5.5;
			useFastMove = 0;
			upDegree = "ManPosNoWeapon";
		};
	};
	class Interpolations{};
	transitionsInterpolated[] = {};
	transitionsSimple[] = {};
	transitionsDisabled[] = {};
	class BlendAnims : BlendAnims
	{
		aimingDefault[] = { "head", 1, "head", 1, "head", 1 };
		headDefault[] = { "head", 1, "neck", 1, "Spine3", 0.2 };
		untiltWeaponDefault[] = {};
		legsDefault[] = {};
		aimingNo[] = {};
		legsNo[] = {};
		headNo[] = {};
		aimingUpDefault[] = {};
	};
};

class CfgMovesGreatWhite_F : CfgMovesAnimal_Base_F
{
	skeletonName = "SharkSkeleton";
	class Default : Default
	{
		actions = "SharksActions";
		collisionShape = "A3\Animals_F\empty_CollShape.p3d";
	};
	class DefaultDie : Default{};
	class StandBase : Default
	{
		file = "\x\addons\a3_epoch_assets\models\shark_move.rtm";
	};
	class States
	{
		class Sharks_Swim : StandBase
		{
			file = "\x\addons\a3_epoch_assets\models\shark_move.rtm";
			looped = 1;
			speed = -1.0;
			interpolateTo[] = { "Sharks_Die", 1, "Sharks_Die2", 1 };
			connectTo[] = { "Sharks_Stop", 1, "Sharks_Swim", 1, "Sharks_Swim_S1", 1, "Sharks_Swim_S2", 1, "Sharks_Swim_S3", 1 };
			equivalentTo = "Sharks_Swim";
			variantsAI[] = { "Sharks_Swim", 0.01, "Sharks_Swim_S1", 0.33, "Sharks_Swim_S2", 0.33, "Sharks_Swim_S3", 0.33 };
			variantAfter[] = { 0.83, 0.83, 0.83 };
		};
		class Sharks_Swim_S1 : StandBase
		{
			file = "\x\addons\a3_epoch_assets\models\shark_moveLong.rtm";
			connectTo[] = { "Sharks_Swim", 0.1 };
			speed = -1.5;
			variantAfter[] = { 0.83, 0.83, 0.83 };
		};
		class Sharks_Swim_S2 : StandBase
		{
			file = "\x\addons\a3_epoch_assets\models\shark_move.rtm";
			connectTo[] = { "Sharks_Swim", 0.1 };
			speed = -1.0;
			variantAfter[] = { 0.83, 0.83, 0.83 };
		};
		class Sharks_Swim_S3 : StandBase
		{
			file = "\x\addons\a3_epoch_assets\models\shark_moveLong.rtm";
			connectTo[] = { "Sharks_Swim", 0.1 };
			speed = -1.4;
			variantAfter[] = { 0.83, 0.83, 0.83 };
		};
		class Sharks_Stop : StandBase
		{
			file = "\x\addons\a3_epoch_assets\models\shark_attack.rtm";
			looped = 1;
			speed = -1.5;
			connectFrom[] = { "Sharks_Swim", 1 };
			connectTo[] = { "Sharks_Swim", 1 };
		};
		class Sharks_Die : DefaultDie
		{
			file = "\x\addons\a3_epoch_assets\models\shark_death.rtm";
			speed = -1.4;
			actions = "NoActions";
			looped = "False";
			variantsPlayer[] = { "Sharks_Die", 0.5, "Sharks_Die2", 0.5 };
			variantsAI[] = {};
			variantAfter[] = { 0, 0, 0 };
			interpolateFrom[] = { "Sharks_Swim", 0.02, "Sharks_Stop", 0.2 };
			interpolateTo[] = { "Sharks_Die", 1, "Sharks_Die2", 1 };
			terminal = 1;
		};
		class Sharks_Die2 : Sharks_Die
		{
			file = "\x\addons\a3_epoch_assets\models\shark_death.rtm";
			speed = -2;
			looped = 0;
			variantAfter[] = { 0, 0, 0 };
		};
	};
	class Actions : Actions
	{
		class NoActions : NoActions
		{
			Stop = "Sharks_Stop";
			StopRelaxed = "Sharks_Stop";
			TurnL = "Sharks_Stop";
			TurnR = "Sharks_Stop";
			TurnLRelaxed = "Sharks_Stop";
			TurnRRelaxed = "Sharks_Stop";
			Default = "Sharks_Swim";
			JumpOff = "Sharks_Swim";
			StartSwim = "Sharks_swim";
			StopSwim = "Sharks_Swim";
			WalkF = "Sharks_swim";
			SlowF = "Sharks_swim";
			FastF = "Sharks_swim";
			EvasiveForward = "Sharks_swim";
			Down = "Sharks_Swim";
			Up = "Sharks_Swim";
			PlayerStand = "Sharks_Swim";
			PlayerCrouch = "Sharks_Swim";
			PlayerProne = "Sharks_Swim";
			Lying = "Sharks_Swim";
			Stand = "Sharks_Swim";
			Combat = "Sharks_Swim";
			Crouch = "Sharks_Swim";
			CanNotMove = "Sharks_Stop";
			Civil = "Sharks_Swim";
			CivilLying = "Sharks_Swim";
			FireNotPossible = "Sharks_Swim";
			Die = "Sharks_Die";
			Eat = "Sharks_Swim";
			Rest = "Sharks_Swim";
		};
		class SharksActions : NoActions
		{
			Stop = "Sharks_Stop";
			StopRelaxed = "Sharks_Stop";
			TurnL = "Sharks_Stop";
			TurnR = "Sharks_Stop";
			TurnLRelaxed = "Sharks_Stop";
			TurnRRelaxed = "Sharks_Stop";
			Default = "Sharks_Swim";
			JumpOff = "Sharks_Swim";
			StartSwim = "Sharks_swim";
			StopSwim = "Sharks_Swim";
			WalkF = "Sharks_swim";
			SlowF = "Sharks_swim";
			FastF = "Sharks_swim";
			EvasiveForward = "Sharks_swim";
			Down = "Sharks_Swim";
			Up = "Sharks_Swim";
			PlayerStand = "Sharks_Swim";
			PlayerCrouch = "Sharks_Swim";
			PlayerProne = "Sharks_Swim";
			Lying = "Sharks_Swim";
			Stand = "Sharks_Swim";
			Combat = "Sharks_Swim";
			Crouch = "Sharks_Swim";
			CanNotMove = "Sharks_Stop";
			Civil = "Sharks_Swim";
			CivilLying = "Sharks_Swim";
			FireNotPossible = "Sharks_Swim";
			Die = "Sharks_Die";
			Eat = "Sharks_Swim";
			Rest = "Sharks_Swim";
			turnSpeed = 1;
			limitFast = 5.5;
			useFastMove = 0;
			upDegree = "ManPosNoWeapon";
		};
	};
	class BlendAnims : BlendAnims
	{
		aimingDefault[] = { "fish_head", 1 };
		headDefault[] = { "fish_head", 1 };
	};
};