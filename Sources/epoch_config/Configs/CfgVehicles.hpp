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
	class CAManBase2: CAManBase
	{
		author = "$STR_A3_Bohemia_Interactive";
		_generalMacro = "CAManBase2";
		picture = "";
		Icon = "iconMan";
		fsmDanger = "A3\characters_f\scripts\danger.fsm";
		moves = "CfgMovesMaleSdr2";
		movesFatigue = "CfgMovesFatigue";
		gestures = "CfgGesturesSapper";
		bonePrimaryWeapon = "weapon";
		oxygenCapacity = 70;
		formationTimeDiving = 2;
		formationTimeSwimming = 3;
		triggerAnim = "A3\anims_f\data\Anim\sdr\trigger.rtm";
		woman = 0;
		faceType = "Man_A3";
		minGunElev = -80;
		maxGunElev = 60;
		minGunTurn = -1;
		maxGunTurn = 1;
		minGunTurnAI = -30;
		maxGunTurnAI = 30;
		extCameraPosition[] = {0.22,0.05,-2.2};
		class HeadLimits;
		boneHead = "head";
		boneHeadCutScene = "headcutscene";
		boneLEye = "eyeleft";
		boneREye = "eyeright";
		boneLEyelidUp = "face_eyelidupperleft";
		boneREyelidUp = "face_eyelidupperright";
		boneLEyelidDown = "face_eyelidlowerleft";
		boneREyelidDown = "face_eyelidlowerright";
		boneLPupil = "l_pupila";
		boneRPupil = "r_pupila";
		minHeadTurnAI = -60;
		maxHeadTurnAI = 60;
		class ViewPilot: ViewPilot
		{
			initFov = 0.75;
			minFov = 0.375;
			maxFov = 1.1;
			initAngleX = 8;
			minAngleX = -85;
			maxAngleX = 85;
			initAngleY = 0;
			minAngleY = -150;
			maxAngleY = 150;
		};
		ISangleMod[] = {0.1,0.03,0.1};
		ISrecoilMod[] = {0,0,0.2};
		ISspeedMod[] = {0.0001,0.0001,0};
		ISmaxTurn = 0.5;
		ISanimMod[] = {0.03,0.06,0.04};
		class HitPoints
		{
			class HitHead
			{
				armor = 1;
				material = -1;
				name = "head";
				passThrough = 1;
				radius = 0.1;
				explosionShielding = 0.5;
				minimalHit = 0;
			};
			class HitBody
			{
				armor = 1;
				material = -1;
				name = "body";
				passThrough = 1;
				radius = 0.15;
				explosionShielding = 6;
				visual = "injury_body";
				minimalHit = 0;
			};
			class HitHands
			{
				armor = 1;
				material = -1;
				name = "hands";
				passThrough = 1;
				radius = 0.08;
				explosionShielding = 1;
				visual = "injury_hands";
				minimalHit = 0;
			};
			class HitLegs
			{
				armor = 1;
				material = -1;
				name = "legs";
				passThrough = 1;
				radius = 0.1;
				explosionShielding = 1;
				visual = "injury_legs";
				minimalHit = 0;
			};
		};
		armor = 2;
		armorStructural = 5;
		selectionHeadWound = "head_injury";
		selectionBodyWound = "injury_body";
		selectionLArmWound = "injury_hands";
		selectionRArmWound = "injury_hands";
		selectionLLegWound = "injury_legs";
		selectionRLegWound = "injury_legs";
		selectionLArmWound1 = "injury_hands";
		selectionRArmWound1 = "injury_hands";
		selectionLLegWound1 = "injury_legs";
		selectionRLegWound1 = "injury_legs";
		selectionLArmWound2 = "hl";
		selectionRArmWound2 = "hl";
		selectionLLegWound2 = "hl";
		selectionRLegWound2 = "hl";
		selectionHeadHide = "";
		selectionNeckHide = "";
		memoryPointLStep = "footstepL";
		memoryPointRStep = "footstepR";
		memoryPointAim = "aimPoint";
		memoryPointCameraTarget = "camera";
		memoryPointCommonDamage = "l_femur_hit";
		memoryPointLeaningAxis = "leaning_axis";
		memoryPointAimingAxis = "aiming_axis";
		memoryPointHeadAxis = "head_axis";
		memoryPointWaterSurface = "water_surface";
		selectionLBrow = "lBrow";
		selectionMBrow = "mBrow";
		selectionRBrow = "rBrow";
		selectionLMouth = "lMouth";
		selectionMMouth = "mMouth";
		selectionRMouth = "rMouth";
		selectionEyelid = "Eyelids";
		selectionLip = "LLip";
		useInternalLODInVehicles = 1;
		accuracy = 0;
		vehicleClass = "Men";
		type = 0;
		threat[] = {1,0.05,0.05};
		vegetation0[] = {"A3\Sounds_F\characters\movements\bush_001",0.25118864,1,30};
		vegetation1[] = {"A3\Sounds_F\characters\movements\bush_002",0.31622776,1,30};
		vegetation2[] = {"A3\Sounds_F\characters\movements\bush_003",0.31622776,1,30};
		vegetation3[] = {"A3\Sounds_F\characters\movements\bush_004",0.2818383,1,30};
		vegetation4[] = {"A3\Sounds_F\characters\movements\bush_005",0.25118864,1,30};
		vegetation5[] = {"A3\Sounds_F\characters\movements\bush_006",0.2238721,1,30};
		vegetation6[] = {"A3\Sounds_F\characters\movements\bush_007",0.56234133,1,30};
		vegetation7[] = {"A3\Sounds_F\characters\movements\bush_008",0.56234133,1,30};
		vegetation8[] = {"A3\Sounds_F\characters\movements\bush_009",0.56234133,1,30};
		vegetation9[] = {"A3\Sounds_F\characters\movements\bush_010",0.56234133,1,30};
		vegetation10[] = {"A3\Sounds_F\characters\movements\bush_011",0.56234133,1,30};
		vegetation11[] = {"A3\Sounds_F\characters\movements\bush_012",0.56234133,1,30};
		vegetationSounds[] = {"vegetation0",0.08,"vegetation1",0.08,"vegetation2",0.08,"vegetation3",0.08,"vegetation4",0.08,"vegetation5",0.08,"vegetation6",0.08,"vegetation7",0.08,"vegetation8",0.09,"vegetation9",0.09,"vegetation10",0.09,"vegetation11",0.09};
		class PulsationSound
		{
			sample0[] = {{ { { "A3\sounds_f\characters\human-sfx\other\heart_3",0.056234132,1 },1.0 } }};
			sample1[] = {{ { { "A3\sounds_f\characters\human-sfx\other\heart_3",0.056234132,1 },1.0 } }};
			sample2[] = {{ { { "A3\sounds_f\characters\human-sfx\other\heart_3",0.056234132,1 },1.0 } }};
			sample3[] = {{ { { "A3\sounds_f\characters\human-sfx\other\heart_3",0.056234132,1 },1.0 } }};
		};
		class HealingSound
		{
			sound[] = {"A3\sounds_f\characters\human-sfx\other\fak1_loop",0.1,1,10};
		};
		class StabilizingSound
		{
			sound[] = {"A3\sounds_f\characters\human-sfx\other\fak1_loop",0.056234132,1,10};
		};
		class HealingSoundWithMedikit
		{
			sound[] = {"A3\sounds_f\characters\human-sfx\other\medikit1",0.056234132,1,10};
		};
		class FreefallSound
		{
			sound[] = {"A3\Sounds_F\characters\human-sfx\other\freefall1",0.5011872,1,40};
		};
		class SoundRecovered
		{
			Person1[] = {{ "Male08ENG" },{ { { "A3\sounds_f\characters\human-sfx\P01\SoundRecovered_01",0.35481337,1,20 },0.25 },{ { "A3\sounds_f\characters\human-sfx\P01\SoundRecovered_02",0.35481337,1,20 },0.25 },{ { "A3\sounds_f\characters\human-sfx\P01\SoundRecovered_03",0.35481337,1,20 },0.25 },{ { "A3\sounds_f\characters\human-sfx\P01\SoundRecovered_04",0.35481337,1,20 },0.25 } }};
			Person2[] = {{ { { "A3\sounds_f\characters\human-sfx\P02\SoundRecovered_01",0.35481337,1,20 },0.25 },{ { "A3\sounds_f\characters\human-sfx\P02\SoundRecovered_02",0.35481337,1,20 },0.25 },{ { "A3\sounds_f\characters\human-sfx\P02\SoundRecovered_03",0.35481337,1,20 },0.25 },{ { "A3\sounds_f\characters\human-sfx\P02\SoundRecovered_04",0.35481337,1,20 },0.25 } }};
			Person3[] = {{ { { "A3\sounds_f\characters\human-sfx\P03\SoundRecovered_01",0.35481337,1,20 },0.25 },{ { "A3\sounds_f\characters\human-sfx\P03\SoundRecovered_02",0.35481337,1,20 },0.25 },{ { "A3\sounds_f\characters\human-sfx\P03\SoundRecovered_03",0.35481337,1,20 },0.25 },{ { "A3\sounds_f\characters\human-sfx\P03\SoundRecovered_04",0.35481337,1,20 },0.25 } }};
			Person4[] = {{ { { "A3\sounds_f\characters\human-sfx\P04\SoundRecovered_01",0.35481337,1,20 },0.25 },{ { "A3\sounds_f\characters\human-sfx\P04\SoundRecovered_02",0.35481337,1,20 },0.25 },{ { "A3\sounds_f\characters\human-sfx\P04\SoundRecovered_03",0.35481337,1,20 },0.25 },{ { "A3\sounds_f\characters\human-sfx\P04\SoundRecovered_04",0.35481337,1,20 },0.25 } }};
		};
		class SoundChoke
		{
			breath0[] = {{ { { "A3\sounds_f\characters\human-sfx\P01\SoundRecovered_water_01",0.35481337,1,20 },0.3 },{ { "A3\sounds_f\characters\human-sfx\P01\SoundRecovered_water_02",0.35481337,1,20 },0.3 },{ { "A3\sounds_f\characters\human-sfx\P01\SoundRecovered_water_03",0.35481337,1,20 },0.4 } }};
			breath1[] = {{ { { "A3\sounds_f\characters\human-sfx\P02\SoundRecovered_water_01",0.35481337,1,20 },0.3 },{ { "A3\sounds_f\characters\human-sfx\P02\SoundRecovered_water_02",0.35481337,1,20 },0.3 },{ { "A3\sounds_f\characters\human-sfx\P02\SoundRecovered_water_03",0.35481337,1,20 },0.4 } }};
			breath2[] = {{ { { "A3\sounds_f\characters\human-sfx\P03\SoundRecovered_water_01",0.35481337,1,20 },0.3 },{ { "A3\sounds_f\characters\human-sfx\P03\SoundRecovered_water_02",0.35481337,1,20 },0.3 },{ { "A3\sounds_f\characters\human-sfx\P03\SoundRecovered_water_03",0.35481337,1,20 },0.4 } }};
			breath3[] = {{ { { "A3\sounds_f\characters\human-sfx\P04\SoundRecovered_water_01",0.35481337,1,20 },0.3 },{ { "A3\sounds_f\characters\human-sfx\P04\SoundRecovered_water_02",0.35481337,1,20 },0.3 },{ { "A3\sounds_f\characters\human-sfx\P04\SoundRecovered_water_03",0.35481337,1,20 },0.4 } }};
		};
		class SoundDrown
		{
			breath0[] = {{ { { "A3\sounds_f\characters\human-sfx\08_hum_inside_head1",0.31622776,1,20 },1.0 } }};
			breath1[] = {{ { { "A3\sounds_f\characters\human-sfx\08_hum_inside_head1",0.31622776,1,20 },1.0 } }};
			breath2[] = {{ { { "A3\sounds_f\characters\human-sfx\08_hum_inside_head1",0.31622776,1,20 },1.0 } }};
			breath3[] = {{ { { "A3\sounds_f\characters\human-sfx\08_hum_inside_head1",0.31622776,1,20 },1.0 } }};
		};
		class SoundDrowning
		{
			breath0[] = {{ { { "A3\sounds_f\characters\human-sfx\P01\drowning_01",0.5011872,1,20 },0.5 },{ { "A3\sounds_f\characters\human-sfx\P01\drowning_02",0.5011872,1,20 },0.5 } }};
			breath1[] = {{ { { "A3\sounds_f\characters\human-sfx\P01\drowning_01",0.5011872,1,20 },0.5 },{ { "A3\sounds_f\characters\human-sfx\P01\drowning_02",0.5011872,1,20 },0.5 } }};
			breath2[] = {{ { { "A3\sounds_f\characters\human-sfx\P01\drowning_01",0.5011872,1,20 },0.5 },{ { "A3\sounds_f\characters\human-sfx\P01\drowning_02",0.5011872,1,20 },0.5 } }};
			breath3[] = {{ { { "A3\sounds_f\characters\human-sfx\P01\drowning_01",0.5011872,1,20 },0.5 },{ { "A3\sounds_f\characters\human-sfx\P01\drowning_02",0.5011872,1,20 },0.5 } }};
		};
		class SoundBurning
		{
			Person1[] = {{ { { "A3\Sounds_F\characters\human-sfx\P01\Burning_01",0.56234133,1,20 },0.2 },{ { "A3\Sounds_F\characters\human-sfx\P01\Burning_02",0.56234133,1,25 },0.2 },{ { "A3\Sounds_F\characters\human-sfx\P01\Burning_03",0.56234133,1,25 },0.2 },{ { "A3\Sounds_F\characters\human-sfx\P01\Burning_04",0.56234133,1,25 },0.2 },{ { "A3\Sounds_F\characters\human-sfx\P01\Burning_05",0.56234133,1,25 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\P01\Burning_06",0.56234133,1,25 },0.1 } }};
			Person2[] = {{ { { "A3\Sounds_F\characters\human-sfx\Person1\Burning_01",0.56234133,1,20 },0.25 },{ { "A3\Sounds_F\characters\human-sfx\Person1\Burning_02",0.56234133,1,25 },0.25 },{ { "A3\Sounds_F\characters\human-sfx\Person1\Burning_03",0.56234133,1,25 },0.25 },{ { "A3\Sounds_F\characters\human-sfx\Person1\Burning_04",0.56234133,1,25 },0.25 } }};
			Person3[] = {{ { { "A3\Sounds_F\characters\human-sfx\Person2\P2_moan_01",0.56234133,1,20 },0.25 },{ { "A3\Sounds_F\characters\human-sfx\Person2\P2_moan_02",0.56234133,1,25 },0.25 },{ { "A3\Sounds_F\characters\human-sfx\Person2\P2_moan_03",0.56234133,1,25 },0.25 },{ { "A3\Sounds_F\characters\human-sfx\Person2\P2_moan_08",0.56234133,1,25 },0.25 } }};
			Person4[] = {{ { { "A3\Sounds_F\characters\human-sfx\Person3\P3_moan_01",0.56234133,1,20 },0.25 },{ { "A3\Sounds_F\characters\human-sfx\Person3\P3_moan_02",0.56234133,1,25 },0.25 },{ { "A3\Sounds_F\characters\human-sfx\Person3\P3_moan_03",0.56234133,1,25 },0.25 },{ { "A3\Sounds_F\characters\human-sfx\Person3\P3_moan_09",0.56234133,1,25 },0.25 } }};
		};
		class SoundBreathSwimming
		{
			breathSwimming0[] = {{ { { "A3\Sounds_F\characters\human-sfx\P01\Water_breath_01",0.56234133,1,25 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\P01\Water_breath_02",0.56234133,1,25 },0.2 },{ { "A3\Sounds_F\characters\human-sfx\P01\Water_breath_03",0.56234133,1,25 },0.2 },{ { "A3\Sounds_F\characters\human-sfx\P01\Water_breath_04",0.56234133,1,25 },0.2 },{ { "A3\Sounds_F\characters\human-sfx\P01\Water_breath_05",0.56234133,1,25 },0.2 },{ { "A3\Sounds_F\characters\human-sfx\P01\Water_breath_06",0.56234133,1,25 },0.1 } }};
			breathSwimming1[] = {{ { { "A3\Sounds_F\characters\human-sfx\P02\Water_Breath_01",0.56234133,1.1,25 },0.25 },{ { "A3\Sounds_F\characters\human-sfx\P02\Water_Breath_02",0.56234133,1.1,25 },0.25 },{ { "A3\Sounds_F\characters\human-sfx\P02\Water_Breath_03",0.56234133,1.1,25 },0.25 },{ { "A3\Sounds_F\characters\human-sfx\P02\Water_Breath_04",0.56234133,1.1,25 },0.25 } }};
			breathSwimming2[] = {{ { { "A3\Sounds_F\characters\human-sfx\water-breath-01",0.56234133,0.8,25 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\water-breath-02",0.56234133,0.8,25 },0.2 },{ { "A3\Sounds_F\characters\human-sfx\water-breath-03",0.56234133,0.8,25 },0.2 },{ { "A3\Sounds_F\characters\human-sfx\water-breath-04",0.56234133,0.8,25 },0.2 },{ { "A3\Sounds_F\characters\human-sfx\water-breath-05",0.56234133,0.8,25 },0.2 },{ { "A3\Sounds_F\characters\human-sfx\water-breath-06",0.56234133,0.8,25 },0.1 } }};
			breathSwimming3[] = {{ { { "A3\Sounds_F\characters\human-sfx\water-breath-01",0.56234133,1.2,25 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\water-breath-02",0.56234133,1.2,25 },0.2 },{ { "A3\Sounds_F\characters\human-sfx\water-breath-03",0.56234133,1.2,25 },0.2 },{ { "A3\Sounds_F\characters\human-sfx\water-breath-04",0.56234133,1.2,25 },0.2 },{ { "A3\Sounds_F\characters\human-sfx\water-breath-05",0.56234133,1.2,25 },0.2 },{ { "A3\Sounds_F\characters\human-sfx\water-breath-06",0.56234133,1.2,25 },0.1 } }};
		};
		class SoundHitScream
		{
			person0[] = {{ { { "A3\sounds_f\characters\human-sfx\P01\Low_hit_01",0.56234133,1,40 },0.2 },{ { "A3\sounds_f\characters\human-sfx\P01\Low_hit_02",0.56234133,1,40 },0.2 },{ { "A3\sounds_f\characters\human-sfx\P01\Low_hit_03",0.56234133,1,40 },0.2 },{ { "A3\sounds_f\characters\human-sfx\P01\Low_hit_04",0.56234133,1,40 },0.2 },{ { "A3\sounds_f\characters\human-sfx\P01\Low_hit_05",0.56234133,1,40 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P01\Low_hit_06",0.56234133,1,40 },0.1 } },{ { { "A3\sounds_f\characters\human-sfx\P01\Mid_hit_01",0.70794576,1,60 },0.25 },{ { "A3\sounds_f\characters\human-sfx\P01\Mid_hit_02",0.70794576,1,60 },0.25 },{ { "A3\sounds_f\characters\human-sfx\P01\Mid_hit_03",0.70794576,1,60 },0.25 },{ { "A3\sounds_f\characters\human-sfx\P01\Mid_hit_04",0.70794576,1,60 },0.25 } },{ { { "A3\sounds_f\characters\human-sfx\P01\Max_hit_01",0.8912509,1,80 },0.2 },{ { "A3\sounds_f\characters\human-sfx\P01\Max_hit_02",0.8912509,1,80 },0.2 },{ { "A3\sounds_f\characters\human-sfx\P01\Max_hit_03",0.8912509,1,80 },0.2 },{ { "A3\sounds_f\characters\human-sfx\P01\Max_hit_04",0.8912509,1,80 },0.2 },{ { "A3\sounds_f\characters\human-sfx\P01\Max_hit_05",0.8912509,1,80 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P01\Max_hit_06",0.8912509,1,80 },0.05 },{ { "A3\sounds_f\characters\human-sfx\P01\Max_hit_07",0.8912509,1,80 },0.05 } }};
			person1[] = {{ { { "A3\sounds_f\characters\human-sfx\P01\Low_hit_01",0.56234133,1,40 },0.2 },{ { "A3\sounds_f\characters\human-sfx\P01\Low_hit_02",0.56234133,1,40 },0.2 },{ { "A3\sounds_f\characters\human-sfx\P01\Low_hit_03",0.56234133,1,40 },0.2 },{ { "A3\sounds_f\characters\human-sfx\P01\Low_hit_04",0.56234133,1,40 },0.2 },{ { "A3\sounds_f\characters\human-sfx\P01\Low_hit_05",0.56234133,1,40 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P01\Low_hit_06",0.56234133,1,40 },0.1 } },{ { { "A3\sounds_f\characters\human-sfx\P01\Mid_hit_01",0.70794576,1,60 },0.25 },{ { "A3\sounds_f\characters\human-sfx\P01\Mid_hit_02",0.70794576,1,60 },0.25 },{ { "A3\sounds_f\characters\human-sfx\P01\Mid_hit_03",0.70794576,1,60 },0.25 },{ { "A3\sounds_f\characters\human-sfx\P01\Mid_hit_04",0.70794576,1,60 },0.25 } },{ { { "A3\sounds_f\characters\human-sfx\P01\Max_hit_01",0.8912509,1,80 },0.25 },{ { "A3\sounds_f\characters\human-sfx\P01\Max_hit_02",0.8912509,1,80 },0.25 },{ { "A3\sounds_f\characters\human-sfx\P01\Max_hit_03",0.8912509,1,80 },0.25 },{ { "A3\sounds_f\characters\human-sfx\P01\Max_hit_04",0.8912509,1,80 },0.25 } }};
			person2[] = {{ { { "A3\sounds_f\characters\human-sfx\person2\P2_hit_small_01",0.56234133,1,40 },0.25 },{ { "A3\sounds_f\characters\human-sfx\person2\P2_hit_small_02",0.56234133,1,40 },0.25 },{ { "A3\sounds_f\characters\human-sfx\person2\P2_hit_small_03",0.56234133,1,40 },0.25 },{ { "A3\sounds_f\characters\human-sfx\person2\P2_hit_small_04",0.56234133,1,40 },0.25 } },{ { { "A3\sounds_f\characters\human-sfx\person2\P2_hit_02",0.70794576,1,60 },0.25 },{ { "A3\sounds_f\characters\human-sfx\person2\P2_hit_03",0.70794576,1,60 },0.25 },{ { "A3\sounds_f\characters\human-sfx\person2\P2_hit_04",0.70794576,1,60 },0.25 },{ { "A3\sounds_f\characters\human-sfx\person2\P2_hit_05",0.70794576,1,60 },0.25 } },{ { { "A3\sounds_f\characters\human-sfx\person2\P2_hit_01",0.8912509,1,80 },0.25 },{ { "A3\sounds_f\characters\human-sfx\person2\P2_hit_07",0.8912509,1,80 },0.25 },{ { "A3\sounds_f\characters\human-sfx\person2\P2_hit_08",0.8912509,1,80 },0.25 },{ { "A3\sounds_f\characters\human-sfx\person2\P2_hit_09",0.8912509,1,80 },0.25 } }};
			person3[] = {{ { { "A3\sounds_f\characters\human-sfx\person3\P3_hit_01",0.56234133,1,30 },0.25 },{ { "A3\sounds_f\characters\human-sfx\person3\P3_hit_06",0.56234133,1,30 },0.25 },{ { "A3\sounds_f\characters\human-sfx\person3\P3_hit_07",0.56234133,1,30 },0.25 },{ { "A3\sounds_f\characters\human-sfx\person3\P3_hit_08",0.56234133,1,30 },0.25 } },{ { { "A3\sounds_f\characters\human-sfx\person3\P3_hit_02",0.70794576,1,60 },0.25 },{ { "A3\sounds_f\characters\human-sfx\person3\P3_hit_03",0.70794576,1,60 },0.25 },{ { "A3\sounds_f\characters\human-sfx\person3\P3_hit_04",0.70794576,1,60 },0.25 },{ { "A3\sounds_f\characters\human-sfx\person3\P3_hit_05",0.70794576,1,60 },0.25 } },{ { { "A3\sounds_f\characters\human-sfx\person3\P3_hit_10",0.8912509,1,80 },0.25 },{ { "A3\sounds_f\characters\human-sfx\person3\P3_hit_11",0.8912509,1,80 },0.25 },{ { "A3\sounds_f\characters\human-sfx\person3\P3_hit_12",0.8912509,1,80 },0.25 },{ { "A3\sounds_f\characters\human-sfx\person3\P3_hit_13",0.8912509,1,80 },0.25 } }};
		};
		class SoundBreath
		{
			breath0[] = {{ { { "A3\sounds_f\characters\human-sfx\P01\Breath_Low_01",0.056234132,1,7 },0.2 },{ { "A3\sounds_f\characters\human-sfx\P01\Breath_Low_02",0.056234132,1,7 },0.2 },{ { "A3\sounds_f\characters\human-sfx\P01\Breath_Low_03",0.056234132,1,7 },0.2 },{ { "A3\sounds_f\characters\human-sfx\P01\Breath_Low_04",0.056234132,1,7 },0.2 },{ { "A3\sounds_f\characters\human-sfx\P01\Breath_Low_05",0.056234132,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P01\Breath_Low_06",0.056234132,1,7 },0.1 } },{ { { "A3\sounds_f\characters\human-sfx\P01\Breath_Mid_01",0.1,1,7 },0.2 },{ { "A3\sounds_f\characters\human-sfx\P01\Breath_Mid_02",0.1,1,7 },0.2 },{ { "A3\sounds_f\characters\human-sfx\P01\Breath_Mid_03",0.1,1,7 },0.2 },{ { "A3\sounds_f\characters\human-sfx\P01\Breath_Mid_04",0.1,1,7 },0.2 },{ { "A3\sounds_f\characters\human-sfx\P01\Breath_Mid_05",0.1,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P01\Breath_Mid_06",0.1,1,7 },0.1 } },{ { { "A3\sounds_f\characters\human-sfx\P01\Breath_Max_01",0.11220185,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P01\Breath_Max_02",0.11220185,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P01\Breath_Max_03",0.11220185,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P01\Breath_Max_04",0.11220185,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P01\Breath_Max_05",0.11220185,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P01\Breath_Max_06",0.11220185,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P01\Breath_Max_07",0.11220185,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P01\Breath_Max_08",0.11220185,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\P01\Breath_Max_09",0.11220185,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\P01\Breath_Max_10",0.11220185,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\P01\Breath_Max_11",0.11220185,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\P01\Breath_Max_12",0.11220185,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\P01\Breath_Max_13z",0.11220185,1,7 },0.025 },{ { "A3\sounds_f\characters\human-sfx\P01\Breath_Max_14z",0.11220185,1,7 },0.025 } }};
			breath1[] = {{ { { "A3\sounds_f\characters\human-sfx\P02\Breath_Low_01",0.056234132,1,7 },0.2 },{ { "A3\sounds_f\characters\human-sfx\P02\Breath_Low_02",0.056234132,1,7 },0.2 },{ { "A3\sounds_f\characters\human-sfx\P02\Breath_Low_03",0.056234132,1,7 },0.2 },{ { "A3\sounds_f\characters\human-sfx\P02\Breath_Low_04",0.056234132,1,7 },0.2 },{ { "A3\sounds_f\characters\human-sfx\P02\Breath_Low_05",0.056234132,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P02\Breath_Low_06",0.056234132,1,7 },0.1 } },{ { { "A3\sounds_f\characters\human-sfx\P02\Breath_Mid_01",0.07943282,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P02\Breath_Mid_02",0.07943282,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P02\Breath_Mid_03",0.07943282,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P02\Breath_Mid_04",0.07943282,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P02\Breath_Mid_05",0.07943282,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P02\Breath_Mid_06",0.07943282,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P02\Breath_Mid_07",0.07943282,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P02\Breath_Mid_08",0.07943282,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P02\Breath_Mid_09",0.07943282,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\P02\Breath_Mid_10",0.07943282,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\P02\Breath_Mid_11",0.07943282,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\P02\Breath_Mid_12",0.07943282,1,7 },0.05 } },{ { { "A3\sounds_f\characters\human-sfx\P02\Breath_Max_01",0.11220185,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P02\Breath_Max_02",0.11220185,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P02\Breath_Max_03",0.11220185,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P02\Breath_Max_04",0.11220185,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P02\Breath_Max_05",0.11220185,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P02\Breath_Max_06",0.11220185,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P02\Breath_Max_07",0.11220185,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P02\Breath_Max_08",0.11220185,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P02\Breath_Max_09",0.11220185,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\P02\Breath_Max_10",0.11220185,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\P02\Breath_Max_11",0.11220185,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\P02\Breath_Max_12",0.11220185,1,7 },0.05 } }};
			breath2[] = {{ { { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_low_01",0.056234132,1,7 },0.15 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_low_02",0.056234132,1,7 },0.15 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_low_03",0.056234132,1,7 },0.15 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_low_04",0.056234132,1,7 },0.15 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_low_05",0.056234132,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_low_06",0.056234132,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_low_07",0.056234132,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_low_08",0.056234132,1,7 },0.1 } },{ { { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_mid_01",0.08912508,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_mid_02",0.08912508,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_mid_03",0.08912508,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_mid_04",0.08912508,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_mid_05",0.08912508,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_mid_06",0.08912508,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_mid_07",0.08912508,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_mid_08",0.08912508,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_mid_09",0.08912508,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_mid_10_z",0.08912508,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_mid_11_z",0.08912508,1,7 },0.05 } },{ { { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_high_01",0.11220185,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_high_02",0.11220185,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_high_03",0.11220185,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_high_04",0.11220185,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_high_05",0.11220185,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_high_06",0.11220185,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_high_07",0.11220185,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_high_08",0.11220185,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_high_09",0.11220185,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_high_10",0.11220185,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_high_11",0.11220185,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_high_12",0.11220185,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_high_13",0.11220185,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_high_14",0.11220185,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_high_15",0.11220185,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_high_16_z",0.11220185,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_high_17_z",0.11220185,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_high_18_z",0.11220185,1,7 },0.05 } }};
			breath3[] = {{ { { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_low_01",0.056234132,1,7 },0.2 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_low_02",0.056234132,1,7 },0.2 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_low_03",0.056234132,1,7 },0.15 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_low_04",0.056234132,1,7 },0.15 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_low_05",0.056234132,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_low_06",0.056234132,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_low_07",0.056234132,1,7 },0.1 } },{ { { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_mid_01",0.07943282,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_mid_02",0.07943282,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_mid_03",0.07943282,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_mid_04",0.07943282,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_mid_05",0.07943282,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_mid_06",0.07943282,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_mid_07",0.07943282,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_mid_08",0.07943282,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_mid_09",0.07943282,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_mid_10",0.07943282,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_mid_11",0.07943282,1,7 },0.05 } },{ { { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_high_01",0.11220185,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_high_02",0.11220185,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_high_03",0.11220185,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_high_04",0.11220185,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_high_05",0.11220185,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_high_06",0.11220185,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_high_07",0.11220185,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_high_08",0.11220185,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_high_09",0.11220185,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_high_10",0.11220185,1,7 },0.1 } }};
		};
		class SoundBreathInjured
		{
			Person0[] = {{ { { "A3\sounds_f\characters\human-sfx\P01\Soundbreathinjured_Low_01",0.056234132,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P01\Soundbreathinjured_Low_02",0.056234132,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P01\Soundbreathinjured_Low_03",0.056234132,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P01\Soundbreathinjured_Low_04",0.056234132,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P01\Soundbreathinjured_Low_05",0.056234132,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P01\Soundbreathinjured_Low_06",0.056234132,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P01\Soundbreathinjured_Low_07",0.056234132,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P01\Soundbreathinjured_Low_08",0.056234132,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P01\Soundbreathinjured_Low_09",0.056234132,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\P01\Soundbreathinjured_Low_10",0.056234132,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\P01\Soundbreathinjured_Low_11",0.056234132,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\P01\Soundbreathinjured_Low_12",0.056234132,1,7 },0.05 } },{ { { "A3\sounds_f\characters\human-sfx\P01\Soundbreathinjured_Mid_01",0.08912508,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P01\Soundbreathinjured_Mid_02",0.08912508,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P01\Soundbreathinjured_Mid_03",0.08912508,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P01\Soundbreathinjured_Mid_04",0.08912508,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P01\Soundbreathinjured_Mid_05",0.08912508,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P01\Soundbreathinjured_Mid_06",0.08912508,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P01\Soundbreathinjured_Mid_07",0.08912508,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\P01\Soundbreathinjured_Mid_08",0.08912508,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\P01\Soundbreathinjured_Mid_09",0.08912508,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\P01\Soundbreathinjured_Mid_10",0.08912508,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\P01\Soundbreathinjured_Mid_11",0.08912508,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\P01\Soundbreathinjured_Mid_12",0.08912508,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\P01\Soundbreathinjured_Mid_13",0.08912508,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\P01\Soundbreathinjured_Mid_14",0.08912508,1,7 },0.05 } },{ { { "A3\sounds_f\characters\human-sfx\P01\Soundbreathinjured_Max_01",0.12589253,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P01\Soundbreathinjured_Max_02",0.12589253,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P01\Soundbreathinjured_Max_03",0.12589253,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P01\Soundbreathinjured_Max_04",0.12589253,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P01\Soundbreathinjured_Max_05",0.12589253,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P01\Soundbreathinjured_Max_06",0.12589253,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P01\Soundbreathinjured_Max_07",0.12589253,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P01\Soundbreathinjured_Max_08",0.12589253,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P01\Soundbreathinjured_Max_09",0.12589253,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\P01\Soundbreathinjured_Max_10",0.12589253,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\P01\Soundbreathinjured_Max_11",0.12589253,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\P01\Soundbreathinjured_Max_12",0.12589253,1,7 },0.05 } }};
			person1[] = {{ { { "A3\sounds_f\characters\human-sfx\P02\Soundbreathinjured_Low_01",0.056234132,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P02\Soundbreathinjured_Low_02",0.056234132,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P02\Soundbreathinjured_Low_03",0.056234132,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P02\Soundbreathinjured_Low_04",0.056234132,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P02\Soundbreathinjured_Low_05",0.056234132,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\P02\Soundbreathinjured_Low_06",0.056234132,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\P02\Soundbreathinjured_Low_07",0.056234132,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\P02\Soundbreathinjured_Low_08",0.056234132,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\P02\Soundbreathinjured_Low_09",0.056234132,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\P02\Soundbreathinjured_Low_10",0.056234132,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\P02\Soundbreathinjured_Low_11",0.056234132,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\P02\Soundbreathinjured_Low_12",0.056234132,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\P02\Soundbreathinjured_Low_13",0.056234132,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\P02\Soundbreathinjured_Low_14",0.056234132,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\P02\Soundbreathinjured_Low_15",0.056234132,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\P02\Soundbreathinjured_Low_16",0.056234132,1,7 },0.05 } },{ { { "A3\sounds_f\characters\human-sfx\P02\Soundbreathinjured_Mid_01",0.1,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P02\Soundbreathinjured_Mid_02",0.1,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P02\Soundbreathinjured_Mid_03",0.1,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P02\Soundbreathinjured_Mid_04",0.1,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P02\Soundbreathinjured_Mid_05",0.1,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P02\Soundbreathinjured_Mid_06",0.1,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P02\Soundbreathinjured_Mid_07",0.1,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\P02\Soundbreathinjured_Mid_08",0.1,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\P02\Soundbreathinjured_Mid_09",0.1,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\P02\Soundbreathinjured_Mid_10",0.1,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\P02\Soundbreathinjured_Mid_11",0.1,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\P02\Soundbreathinjured_Mid_12",0.1,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\P02\Soundbreathinjured_Mid_13",0.1,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\P02\Soundbreathinjured_Mid_14",0.1,1,7 },0.05 } },{ { { "A3\sounds_f\characters\human-sfx\P02\Soundbreathinjured_Max_01",0.12589253,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P02\Soundbreathinjured_Max_02",0.12589253,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P02\Soundbreathinjured_Max_03",0.12589253,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P02\Soundbreathinjured_Max_04",0.12589253,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P02\Soundbreathinjured_Max_05",0.12589253,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P02\Soundbreathinjured_Max_06",0.12589253,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\P02\Soundbreathinjured_Max_07",0.12589253,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\P02\Soundbreathinjured_Max_08",0.12589253,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\P02\Soundbreathinjured_Max_09",0.12589253,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\P02\Soundbreathinjured_Max_10",0.12589253,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\P02\Soundbreathinjured_Max_11",0.12589253,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\P02\Soundbreathinjured_Max_12",0.12589253,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\P02\Soundbreathinjured_Max_13",0.12589253,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\P02\Soundbreathinjured_Max_14",0.12589253,1,7 },0.05 } }};
			person2[] = {{ { { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_low_01",0.056234132,1,7 },0.0625 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_low_02",0.056234132,1,7 },0.0625 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_low_03",0.056234132,1,7 },0.0625 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_low_04",0.056234132,1,7 },0.0625 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_low_05",0.056234132,1,7 },0.0625 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_low_06",0.056234132,1,7 },0.0625 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_low_07",0.056234132,1,7 },0.0625 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_low_08",0.056234132,1,7 },0.0625 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_damage_low_01",0.056234132,1,7 },0.0625 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_damage_low_02",0.056234132,1,7 },0.0625 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_damage_low_03",0.056234132,1,7 },0.0625 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_damage_low_04",0.056234132,1,7 },0.0625 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_damage_low_05",0.056234132,1,7 },0.0625 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_damage_low_06",0.056234132,1,7 },0.0625 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_damage_low_07",0.056234132,1,7 },0.0625 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_damage_low_08",0.056234132,1,7 },0.0625 } },{ { { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_mid_01",0.08912508,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_mid_02",0.08912508,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_mid_03",0.08912508,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_mid_04",0.08912508,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_mid_05",0.08912508,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_mid_06",0.08912508,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_mid_07",0.08912508,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_mid_08",0.08912508,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_mid_09",0.08912508,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_mid_10_z",0.08912508,1,7 },0.025 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_mid_11_z",0.08912508,1,7 },0.025 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_damage_mid_11",0.08912508,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_damage_mid_12",0.08912508,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_damage_mid_13",0.08912508,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_damage_mid_14",0.08912508,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_damage_mid_15",0.08912508,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_damage_mid_16",0.08912508,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_damage_mid_17",0.08912508,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_damage_mid_18",0.08912508,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_damage_mid_01",0.08912508,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_damage_mid_02",0.08912508,1,7 },0.05 } },{ { { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_high_01",0.12589253,1,7 },0.75 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_high_02",0.12589253,1,7 },0.5 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_high_03",0.12589253,1,7 },0.5 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_high_04",0.12589253,1,7 },0.5 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_high_05",0.12589253,1,7 },0.5 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_high_06",0.12589253,1,7 },0.5 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_high_07",0.12589253,1,7 },0.25 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_high_08",0.12589253,1,7 },0.25 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_high_09",0.12589253,1,7 },0.25 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_high_10",0.12589253,1,7 },0.25 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_high_11",0.12589253,1,7 },0.25 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_high_12",0.12589253,1,7 },0.25 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_high_13",0.12589253,1,7 },0.25 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_high_14",0.12589253,1,7 },0.25 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_high_15",0.12589253,1,7 },0.25 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_high_16_z",0.12589253,1,7 },0.25 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_high_17_z",0.12589253,1,7 },0.25 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_high_18_z",0.12589253,1,7 },0.25 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_damage_high_01",0.12589253,1,7 },0.25 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_damage_high_02",0.12589253,1,7 },0.25 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_damage_high_03",0.12589253,1,7 },0.25 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_damage_high_04",0.12589253,1,7 },0.25 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_damage_high_05",0.12589253,1,7 },0.25 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_damage_high_06",0.12589253,1,7 },0.25 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_damage_high_07",0.12589253,1,7 },0.25 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_damage_high_08",0.12589253,1,7 },0.25 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_damage_high_09",0.12589253,1,7 },0.25 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_damage_high_10",0.12589253,1,7 },0.25 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_damage_high_11",0.12589253,1,7 },0.25 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_damage_high_12",0.12589253,1,7 },0.25 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_damage_high_13",0.12589253,1,7 },0.25 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_damage_high_14",0.12589253,1,7 },0.25 },{ { "A3\sounds_f\characters\human-sfx\Person2\P2_breath_damage_high_15",0.12589253,1,7 },0.25 } }};
			person3[] = {{ { { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_low_01",0.056234132,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_low_02",0.056234132,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_low_03",0.056234132,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_low_04",0.056234132,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_low_05",0.056234132,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_low_06",0.056234132,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_low_07",0.056234132,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_damage_low_01",0.056234132,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_damage_low_02",0.056234132,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_damage_low_03",0.056234132,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_damage_low_04",0.056234132,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_damage_low_05",0.056234132,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_damage_low_06",0.056234132,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_damage_low_07",0.056234132,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_damage_low_08",0.056234132,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_damage_low_09",0.056234132,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_damage_low_10",0.056234132,1,7 },0.1 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_damage_low_11",0.056234132,1,7 },0.1 } },{ { { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_mid_01",0.08912508,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_mid_02",0.08912508,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_mid_03",0.08912508,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_mid_04",0.08912508,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_mid_05",0.08912508,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_mid_06",0.08912508,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_mid_07",0.08912508,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_mid_08",0.08912508,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_mid_09",0.08912508,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_mid_10",0.08912508,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_mid_11",0.08912508,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_damage_mid_01",0.08912508,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_damage_mid_02",0.08912508,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_damage_mid_03",0.08912508,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_damage_mid_04",0.08912508,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_damage_mid_05",0.08912508,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_damage_mid_06",0.08912508,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_damage_mid_07",0.08912508,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_damage_mid_08",0.08912508,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_damage_mid_09",0.08912508,1,7 },0.025 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_damage_mid_10",0.08912508,1,7 },0.025 } },{ { { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_high_01",0.12589253,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_high_02",0.12589253,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_high_03",0.12589253,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_high_04",0.12589253,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_high_05",0.12589253,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_high_06",0.12589253,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_high_07",0.12589253,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_high_08",0.12589253,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_high_09",0.12589253,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_high_10",0.12589253,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_damage_high_01",0.12589253,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_damage_high_02",0.12589253,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_damage_high_03",0.12589253,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_damage_high_04",0.12589253,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_damage_high_05",0.12589253,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_damage_high_06",0.12589253,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_damage_high_07",0.12589253,1,7 },0.05 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_damage_high_08",0.12589253,1,7 },0.075 },{ { "A3\sounds_f\characters\human-sfx\Person3\P3_breath_damage_high_09",0.12589253,1,7 },0.075 } }};
		};
		class SoundInjured
		{
			person_moan0[] = {{ { { "A3\Sounds_F\characters\human-sfx\P01\Soundinjured_Low_01",0.07943282,1,10 },0.2 },{ { "A3\Sounds_F\characters\human-sfx\P01\Soundinjured_Low_02",0.07943282,1,10 },0.2 },{ { "A3\Sounds_F\characters\human-sfx\P01\Soundinjured_Low_03",0.07943282,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\P01\Soundinjured_Low_04",0.07943282,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\P01\Soundinjured_Low_05",0.07943282,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\P01\Soundinjured_Low_06",0.07943282,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\P01\Soundinjured_Low_07",0.07943282,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\P01\Soundinjured_Low_08",0.07943282,1,10 },0.1 } },{ { { "A3\Sounds_F\characters\human-sfx\P01\Soundinjured_Mid_01",0.12589253,1,10 },0.2 },{ { "A3\Sounds_F\characters\human-sfx\P01\Soundinjured_Mid_02",0.12589253,1,10 },0.2 },{ { "A3\Sounds_F\characters\human-sfx\P01\Soundinjured_Mid_03",0.12589253,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\P01\Soundinjured_Mid_04",0.12589253,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\P01\Soundinjured_Mid_05",0.12589253,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\P01\Soundinjured_Mid_06",0.12589253,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\P01\Soundinjured_Mid_07",0.12589253,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\P01\Soundinjured_Mid_08",0.12589253,1,10 },0.1 } },{ { { "A3\Sounds_F\characters\human-sfx\P01\Soundinjured_Max_01",0.15848932,1,10 },0.2 },{ { "A3\Sounds_F\characters\human-sfx\P01\Soundinjured_Max_02",0.15848932,1,10 },0.2 },{ { "A3\Sounds_F\characters\human-sfx\P01\Soundinjured_Max_03",0.15848932,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\P01\Soundinjured_Max_04",0.15848932,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\P01\Soundinjured_Max_05",0.15848932,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\P01\Soundinjured_Max_06",0.15848932,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\P01\Soundinjured_Max_07",0.15848932,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\P01\Soundinjured_Max_08",0.15848932,1,10 },0.1 } }};
			person_moan1[] = {{ { { "A3\Sounds_F\characters\human-sfx\P02\Soundinjured_Low_01",0.07943282,1,10 },0.2 },{ { "A3\Sounds_F\characters\human-sfx\P02\Soundinjured_Low_02",0.07943282,1,10 },0.2 },{ { "A3\Sounds_F\characters\human-sfx\P02\Soundinjured_Low_03",0.07943282,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\P02\Soundinjured_Low_04",0.07943282,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\P02\Soundinjured_Low_05",0.07943282,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\P02\Soundinjured_Low_06",0.07943282,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\P02\Soundinjured_Low_07",0.07943282,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\P02\Soundinjured_Low_08",0.07943282,1,10 },0.1 } },{ { { "A3\Sounds_F\characters\human-sfx\P02\Soundinjured_Mid_01",0.12589253,1,10 },0.2 },{ { "A3\Sounds_F\characters\human-sfx\P02\Soundinjured_Mid_02",0.12589253,1,10 },0.2 },{ { "A3\Sounds_F\characters\human-sfx\P02\Soundinjured_Mid_03",0.12589253,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\P02\Soundinjured_Mid_04",0.12589253,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\P02\Soundinjured_Mid_05",0.12589253,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\P02\Soundinjured_Mid_06",0.12589253,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\P02\Soundinjured_Mid_07",0.12589253,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\P02\Soundinjured_Mid_08",0.12589253,1,10 },0.1 } },{ { { "A3\Sounds_F\characters\human-sfx\P02\Soundinjured_Max_01",0.15848932,1,10 },0.2 },{ { "A3\Sounds_F\characters\human-sfx\P02\Soundinjured_Max_02",0.15848932,1,10 },0.2 },{ { "A3\Sounds_F\characters\human-sfx\P02\Soundinjured_Max_03",0.15848932,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\P02\Soundinjured_Max_04",0.15848932,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\P02\Soundinjured_Max_05",0.15848932,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\P02\Soundinjured_Max_06",0.15848932,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\P02\Soundinjured_Max_07",0.15848932,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\P02\Soundinjured_Max_08",0.15848932,1,10 },0.1 } }};
			person_moan2[] = {{ { { "A3\Sounds_F\characters\human-sfx\Person2\P2_moan_01",0.07943282,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\Person2\P2_moan_02",0.07943282,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\Person2\P2_moan_03",0.07943282,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\Person2\P2_moan_04",0.07943282,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\Person2\P2_moan_05",0.07943282,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\Person2\P2_moan_06",0.07943282,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\Person2\P2_moan_07",0.07943282,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\Person2\P2_moan_08",0.07943282,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\Person2\P2_moan_09",0.07943282,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\Person2\P2_moan_10",0.07943282,1,10 },0.1 } },{ { { "A3\Sounds_F\characters\human-sfx\Person2\P2_moan_12",0.12589253,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\Person2\P2_moan_13",0.12589253,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\Person2\P2_moan_03",0.12589253,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\Person2\P2_moan_04",0.12589253,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\Person2\P2_moan_05",0.12589253,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\Person2\P2_moan_06",0.12589253,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\Person2\P2_moan_07",0.12589253,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\Person2\P2_moan_08",0.12589253,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\Person2\P2_moan_09",0.12589253,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\Person2\P2_moan_10",0.12589253,1,10 },0.05 },{ { "A3\Sounds_F\characters\human-sfx\Person2\P2_moan_11",0.12589253,1,10 },0.05 } },{ { { "A3\Sounds_F\characters\human-sfx\Person2\P2_moan_08",0.15848932,1,10 },0.2 },{ { "A3\Sounds_F\characters\human-sfx\Person2\P2_moan_09",0.15848932,1,10 },0.2 },{ { "A3\Sounds_F\characters\human-sfx\Person2\P2_moan_10",0.15848932,1,10 },0.2 },{ { "A3\Sounds_F\characters\human-sfx\Person2\P2_moan_11",0.15848932,1,10 },0.2 },{ { "A3\Sounds_F\characters\human-sfx\Person2\P2_moan_12",0.15848932,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\Person2\P2_moan_13",0.15848932,1,10 },0.1 } }};
			person_moan3[] = {{ { { "A3\Sounds_F\characters\human-sfx\Person3\P3_moan_01",0.07943282,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\Person3\P3_moan_02",0.07943282,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\Person3\P3_moan_03",0.07943282,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\Person3\P3_moan_04",0.07943282,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\Person3\P3_moan_05",0.07943282,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\Person3\P3_moan_06",0.07943282,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\Person3\P3_moan_07",0.07943282,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\Person3\P3_moan_08",0.07943282,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\Person3\P3_moan_09",0.07943282,1,10 },0.2 } },{ { { "A3\Sounds_F\characters\human-sfx\Person3\P3_moan_01",0.1,1,10 },0.2 },{ { "A3\Sounds_F\characters\human-sfx\Person3\P3_moan_02",0.1,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\Person3\P3_moan_03",0.1,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\Person3\P3_moan_04",0.1,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\Person3\P3_moan_05",0.1,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\Person3\P3_moan_06",0.1,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\Person3\P3_moan_07",0.1,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\Person3\P3_moan_08",0.1,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\Person3\P3_moan_09",0.1,1,10 },0.1 } },{ { { "A3\Sounds_F\characters\human-sfx\Person3\P3_moan_01",0.15848932,1,10 },0.2 },{ { "A3\Sounds_F\characters\human-sfx\Person3\P3_moan_02",0.15848932,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\Person3\P3_moan_03",0.15848932,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\Person3\P3_moan_04",0.15848932,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\Person3\P3_moan_05",0.15848932,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\Person3\P3_moan_06",0.15848932,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\Person3\P3_moan_07",0.15848932,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\Person3\P3_moan_08",0.15848932,1,10 },0.1 },{ { "A3\Sounds_F\characters\human-sfx\Person3\P3_moan_09",0.15848932,1,10 },0.1 } }};
		};
		class SoundBreathAutomatic
		{
			breath0[] = {{ { { "A3\Sounds_F\characters\human-sfx\other\diver-breath-1",0.56234133,1,20 },0.25 },{ { "A3\Sounds_F\characters\human-sfx\other\diver-breath-2",0.56234133,1,20 },0.25 },{ { "A3\Sounds_F\characters\human-sfx\other\diver-breath-3",0.56234133,1,20 },0.25 },{ { "A3\Sounds_F\characters\human-sfx\other\diver-breath-4",0.56234133,1,20 },0.25 } }};
		};
		class SoundGear
		{
			primary[] = {{ "walk",{ "A3\sounds_f\characters\movements\soldier_gear_walk_01",0.07943282,1,30 } },{ "walk",{ "A3\sounds_f\characters\movements\soldier_gear_walk_02",0.07943282,1,30 } },{ "walk",{ "A3\sounds_f\characters\movements\soldier_gear_walk_03",0.07943282,1,30 } },{ "walk",{ "A3\sounds_f\characters\movements\soldier_gear_walk_04",0.07943282,1,30 } },{ "walk",{ "A3\sounds_f\characters\movements\soldier_gear_walk_05",0.07943282,1,30 } },{ "walk",{ "A3\sounds_f\characters\movements\soldier_gear_walk_06",0.07943282,1,30 } },{ "walk",{ "A3\sounds_f\characters\movements\soldier_gear_walk_07",0.07943282,1,30 } },{ "walk",{ "A3\sounds_f\characters\movements\soldier_gear_walk_08",0.07943282,1,30 } },{ "run",{ "A3\sounds_f\characters\movements\soldier_gear_run_01",0.11220185,1,35 } },{ "run",{ "A3\sounds_f\characters\movements\soldier_gear_run_02",0.11220185,1,35 } },{ "run",{ "A3\sounds_f\characters\movements\soldier_gear_run_03",0.11220185,1,35 } },{ "run",{ "A3\sounds_f\characters\movements\soldier_gear_run_04",0.11220185,1,35 } },{ "run",{ "A3\sounds_f\characters\movements\soldier_gear_run_05",0.11220185,1,35 } },{ "run",{ "A3\sounds_f\characters\movements\soldier_gear_run_06",0.11220185,1,35 } },{ "run",{ "A3\sounds_f\characters\movements\soldier_gear_run_07",0.11220185,1,35 } },{ "run",{ "A3\sounds_f\characters\movements\soldier_gear_run_08",0.11220185,1,35 } },{ "sprint",{ "A3\sounds_f\characters\movements\soldier_gear_sprint_01",0.14125374,1,45 } },{ "sprint",{ "A3\sounds_f\characters\movements\soldier_gear_sprint_02",0.14125374,1,45 } },{ "sprint",{ "A3\sounds_f\characters\movements\soldier_gear_sprint_03",0.14125374,1,45 } },{ "sprint",{ "A3\sounds_f\characters\movements\soldier_gear_sprint_04",0.14125374,1,45 } },{ "sprint",{ "A3\sounds_f\characters\movements\soldier_gear_sprint_05",0.14125374,1,45 } },{ "sprint",{ "A3\sounds_f\characters\movements\soldier_gear_sprint_06",0.14125374,1,45 } },{ "sprint",{ "A3\sounds_f\characters\movements\soldier_gear_sprint_07",0.14125374,1,45 } },{ "sprint",{ "A3\sounds_f\characters\movements\soldier_gear_sprint_08",0.14125374,1,45 } }};
			secondary[] = {{ "run",{ "",1.0,1,10 } },{ "run",{ "",1.0,1,10 } },{ "sprint",{ "",1.0,1,10 } }};
		};
		class SoundEquipment
		{
			soldier[] = {{ "walk",{ "A3\sounds_f\characters\movements\suit_run_01",0.056234132,1,30 } },{ "walk",{ "A3\sounds_f\characters\movements\suit_run_02",0.056234132,1,30 } },{ "walk",{ "A3\sounds_f\characters\movements\suit_run_03",0.056234132,1,30 } },{ "walk",{ "A3\sounds_f\characters\movements\suit_run_04",0.056234132,1,30 } },{ "walk",{ "A3\sounds_f\characters\movements\suit_run_05",0.056234132,1,30 } },{ "walk",{ "A3\sounds_f\characters\movements\suit_run_06",0.056234132,1,30 } },{ "walk",{ "A3\sounds_f\characters\movements\suit_run_07",0.056234132,1,30 } },{ "walk",{ "A3\sounds_f\characters\movements\suit_run_08",0.056234132,1,30 } },{ "run",{ "A3\sounds_f\characters\movements\suit_run_01",0.063095726,1,32 } },{ "run",{ "A3\sounds_f\characters\movements\suit_run_02",0.063095726,1,32 } },{ "run",{ "A3\sounds_f\characters\movements\suit_run_03",0.063095726,1,32 } },{ "run",{ "A3\sounds_f\characters\movements\suit_run_04",0.063095726,1,32 } },{ "run",{ "A3\sounds_f\characters\movements\suit_run_05",0.063095726,1,32 } },{ "run",{ "A3\sounds_f\characters\movements\suit_run_06",0.063095726,1,32 } },{ "run",{ "A3\sounds_f\characters\movements\suit_run_07",0.063095726,1,32 } },{ "run",{ "A3\sounds_f\characters\movements\suit_run_08",0.063095726,1,32 } },{ "sprint",{ "A3\sounds_f\characters\movements\suit_sprint_01",0.1,1,35 } },{ "sprint",{ "A3\sounds_f\characters\movements\suit_sprint_02",0.1,1,35 } },{ "sprint",{ "A3\sounds_f\characters\movements\suit_sprint_03",0.1,1,35 } },{ "sprint",{ "A3\sounds_f\characters\movements\suit_sprint_04",0.1,1,35 } },{ "sprint",{ "A3\sounds_f\characters\movements\suit_sprint_05",0.1,1,35 } },{ "sprint",{ "A3\sounds_f\characters\movements\suit_sprint_06",0.1,1,35 } },{ "sprint",{ "A3\sounds_f\characters\movements\suit_sprint_07",0.1,1,35 } },{ "sprint",{ "A3\sounds_f\characters\movements\suit_sprint_08",0.1,1,35 } }};
			civilian[] = {{ "walk",{ "A3\sounds_f\characters\movements\suit_run_01",0.056234132,1,20 } },{ "walk",{ "A3\sounds_f\characters\movements\suit_run_02",0.056234132,1,20 } },{ "walk",{ "A3\sounds_f\characters\movements\suit_run_03",0.056234132,1,20 } },{ "walk",{ "A3\sounds_f\characters\movements\suit_run_04",0.056234132,1,20 } },{ "walk",{ "A3\sounds_f\characters\movements\suit_run_05",0.056234132,1,20 } },{ "walk",{ "A3\sounds_f\characters\movements\suit_run_06",0.056234132,1,20 } },{ "walk",{ "A3\sounds_f\characters\movements\suit_run_07",0.056234132,1,20 } },{ "walk",{ "A3\sounds_f\characters\movements\suit_run_08",0.056234132,1,20 } },{ "run",{ "A3\sounds_f\characters\movements\suit_run_01",0.07943282,1,30 } },{ "run",{ "A3\sounds_f\characters\movements\suit_run_02",0.07943282,1,30 } },{ "run",{ "A3\sounds_f\characters\movements\suit_run_03",0.07943282,1,30 } },{ "run",{ "A3\sounds_f\characters\movements\suit_run_04",0.07943282,1,30 } },{ "run",{ "A3\sounds_f\characters\movements\suit_run_05",0.07943282,1,30 } },{ "run",{ "A3\sounds_f\characters\movements\suit_run_06",0.07943282,1,30 } },{ "run",{ "A3\sounds_f\characters\movements\suit_run_07",0.07943282,1,30 } },{ "run",{ "A3\sounds_f\characters\movements\suit_run_08",0.07943282,1,30 } },{ "sprint",{ "A3\sounds_f\characters\movements\suit_sprint_01",0.1,1,40 } },{ "sprint",{ "A3\sounds_f\characters\movements\suit_sprint_02",0.1,1,40 } },{ "sprint",{ "A3\sounds_f\characters\movements\suit_sprint_03",0.1,1,40 } },{ "sprint",{ "A3\sounds_f\characters\movements\suit_sprint_04",0.1,1,40 } },{ "sprint",{ "A3\sounds_f\characters\movements\suit_sprint_05",0.1,1,40 } },{ "sprint",{ "A3\sounds_f\characters\movements\suit_sprint_06",0.1,1,40 } },{ "sprint",{ "A3\sounds_f\characters\movements\suit_sprint_07",0.1,1,40 } },{ "sprint",{ "A3\sounds_f\characters\movements\suit_sprint_08",0.1,1,40 } }};
		};

		class SoundEnvironExt
		{
			generic[] = {{ "healself",{ "\A3\Sounds_F\characters\ingame\AinvPknlMstpSlayWrflDnon_medic",0.8912509,1,70 } },{ "healselfprone",{ "\A3\Sounds_F\characters\ingame\AinvPpneMstpSlayWrflDnon_medic",0.8912509,1,70 } },{ "healselfpistolkneelin",{ "\A3\Sounds_F\characters\ingame\AinvPknlMstpSlayWpstDnon_medicIn",0.8912509,1,70 } },{ "healselfpistolkneel",{ "\A3\Sounds_F\characters\ingame\AinvPknlMstpSlayWpstDnon_medic",0.8912509,1,70 } },{ "healselfpistolkneelout",{ "\A3\Sounds_F\characters\ingame\AinvPknlMstpSlayWpstDnon_medicOut",0.8912509,1,70 } },{ "healselfpistolpromein",{ "\A3\Sounds_F\characters\ingame\AinvPpneMstpSlayWpstDnon_medicin",0.8912509,1,70 } },{ "healselfpistolprone",{ "\A3\Sounds_F\characters\ingame\AinvPpneMstpSlayWpstDnon_medic",0.8912509,1,70 } },{ "healselfpistolpromeout",{ "\A3\Sounds_F\characters\ingame\AinvPpneMstpSlayWpstDnon_medicOut",0.8912509,1,70 } },{ "adjust_short",{ "\A3\sounds_f\characters\stances\adjust_short1",0.15848932,1,70 } },{ "adjust_short",{ "\A3\sounds_f\characters\stances\adjust_short2",0.15848932,1,70 } },{ "adjust_short",{ "\A3\sounds_f\characters\stances\adjust_short3",0.15848932,1,70 } },{ "adjust_short",{ "\A3\sounds_f\characters\stances\adjust_short4",0.15848932,1,70 } },{ "adjust_short",{ "\A3\sounds_f\characters\stances\adjust_short5",0.15848932,1,70 } },{ "adjust_stand_to_left_prone",{ "\A3\sounds_f\characters\stances\adjust_short1",0.15848932,1,70 } },{ "adjust_stand_to_right_prone",{ "\A3\sounds_f\characters\stances\adjust_short5",0.15848932,1,70 } },{ "adjust_kneelhigh_to_standlow",{ "\A3\sounds_f\characters\stances\adjust_short3",0.15848932,1,70 } },{ "adjust_standlow_to_kneelhigh",{ "\A3\sounds_f\characters\stances\adjust_short1",0.15848932,1,70 } },{ "roll",{ "\A3\sounds_f\characters\stances\adjust_short4",0.35481337,1,70 } },{ "grenade_throw",{ "\A3\sounds_f\characters\stances\adjust_short1",0.35481337,1,70 } },{ "grenade_throw",{ "\A3\sounds_f\characters\stances\adjust_short2",0.35481337,1,70 } },{ "grenade_throw",{ "\A3\sounds_f\characters\stances\adjust_short3",0.35481337,1,70 } },{ "grenade_throw",{ "\A3\sounds_f\characters\stances\adjust_short4",0.35481337,1,70 } },{ "grenade_throw",{ "\A3\sounds_f\characters\stances\adjust_short5",0.35481337,1,70 } },{ "inventory_in",{ "\A3\sounds_f\characters\stances\adjust_short1",0.25118864,1,70 } },{ "inventory_out",{ "\A3\sounds_f\characters\stances\adjust_short2",0.25118864,1,70 } },{ "handgun_to_launcher",{ "\A3\sounds_f\characters\stances\change_handgun_to_launcher",0.25118864,1,70 } },{ "handgun_to_rifle",{ "\A3\sounds_f\characters\stances\change_handgun_to_rifle",0.25118864,1,70 } },{ "handgun_to_unarmed",{ "\A3\sounds_f\characters\stances\change_handgun_to_unarmed",0.25118864,1,70 } },{ "launcher_to_handgun",{ "\A3\sounds_f\characters\stances\change_launcher_to_handgun",0.25118864,1,70 } },{ "launcher_to_rifle",{ "\A3\sounds_f\characters\stances\change_launcher_to_rifle",0.25118864,1,70 } },{ "launcher_to_unarmed",{ "\A3\sounds_f\characters\stances\change_launcher_to_unarmed",0.25118864,1,70 } },{ "rifle_to_handgun",{ "\A3\sounds_f\characters\stances\change_rifle_to_handgun",0.25118864,1,70 } },{ "rifle_to_launcher",{ "\A3\sounds_f\characters\stances\change_rifle_to_launcher",0.25118864,1,70 } },{ "rifle_to_unarmed",{ "\A3\sounds_f\characters\stances\change_rifle_to_unarmed",0.25118864,1,70 } },{ "unarmed_to_handgun",{ "\A3\sounds_f\characters\stances\change_unarmed_to_handgun",0.25118864,1,70 } },{ "unarmed_to_launcher",{ "\A3\sounds_f\characters\stances\change_unarmed_to_launcher",0.25118864,1,70 } },{ "unarmed_to_rifle",{ "\A3\sounds_f\characters\stances\change_unarmed_to_rifle",0.25118864,1,70 } },{ "to_binoc",{ "\A3\sounds_f\characters\stances\change_rifle_to_binoculars",0.25118864,1,70 } },{ "to_binoc_lnr",{ "\A3\sounds_f\characters\stances\change_rifle_to_binoculars",0.25118864,1,70 } },{ "to_binoc_civil",{ "\A3\sounds_f\characters\stances\change_unarmed_to_binoculars",0.25118864,1,70 } },{ "from_binoc",{ "\A3\sounds_f\characters\stances\change_binoculars_to_rifle",0.25118864,1,70 } },{ "from_binoc_lnr",{ "\A3\sounds_f\characters\stances\change_handgun_to_launcher",0.25118864,1,70 } },{ "from_binoc_civil",{ "\A3\sounds_f\characters\stances\change_binoculars_to_unarmed",0.25118864,1,70 } },{ "ladder",{ "\A3\Sounds_F\characters\movements\ladder\ladder_01",0.5011872,1,70 } },{ "ladder",{ "\A3\Sounds_F\characters\movements\ladder\ladder_02",0.5011872,1,70 } },{ "ladder",{ "\A3\Sounds_F\characters\movements\ladder\ladder_03",0.5011872,1,70 } },{ "ladder",{ "\A3\Sounds_F\characters\movements\ladder\ladder_04",0.5011872,1,70 } },{ "ladder",{ "\A3\Sounds_F\characters\movements\ladder\ladder_05",0.5011872,1,70 } },{ "ladder",{ "\A3\Sounds_F\characters\movements\ladder\ladder_06",0.5011872,1,70 } },{ "Acts_CrouchGetLowGesture",{ "\A3\Sounds_F\characters\cutscenes\Acts_CrouchGetLowGesture",0.8912509,1,70 } },{ "Acts_listeningToRadio_Loop",{ "\A3\Sounds_F\characters\cutscenes\Acts_listeningToRadio_Loop",0.8912509,1,70 } },{ "Acts_listeningToRadio_Out",{ "\A3\Sounds_F\characters\cutscenes\Acts_listeningToRadio_Out",0.8912509,1,70 } },{ "Acts_LyingWounded_loop1",{ "\A3\Sounds_F\characters\cutscenes\Acts_LyingWounded_loop1",0.8912509,1,70 } },{ "Acts_LyingWounded_loop2",{ "\A3\Sounds_F\characters\cutscenes\Acts_LyingWounded_loop2",0.8912509,1,70 } },{ "Acts_LyingWounded_loop3",{ "\A3\Sounds_F\characters\cutscenes\Acts_LyingWounded_loop3",0.8912509,1,70 } },{ "Acts_NavigatingChopper_In",{ "\A3\Sounds_F\characters\cutscenes\Acts_NavigatingChopper_In",0.56234133,1,70 } },{ "Acts_NavigatingChopper_Loop",{ "\A3\Sounds_F\characters\cutscenes\Acts_NavigatingChopper_Loop",0.56234133,1,70 } },{ "Acts_NavigatingChopper_Out",{ "\A3\Sounds_F\characters\cutscenes\Acts_NavigatingChopper_Out",0.56234133,1,70 } },{ "Acts_PercMstpSlowWrflDnon_handup1",{ "\A3\Sounds_F\characters\cutscenes\Acts_PercMstpSlowWrflDnon_handup1",0.56234133,1,70 } },{ "Acts_PercMstpSlowWrflDnon_handup1b",{ "\A3\Sounds_F\characters\cutscenes\Acts_PercMstpSlowWrflDnon_handup1b",0.56234133,1,70 } },{ "Acts_PercMstpSlowWrflDnon_handup1c",{ "\A3\Sounds_F\characters\cutscenes\Acts_PercMstpSlowWrflDnon_handup1c",0.56234133,1,70 } },{ "Acts_PercMstpSlowWrflDnon_handup2",{ "\A3\Sounds_F\characters\cutscenes\Acts_PercMstpSlowWrflDnon_handup2",0.56234133,1,70 } },{ "Acts_PercMstpSlowWrflDnon_handup2b",{ "\A3\Sounds_F\characters\cutscenes\Acts_PercMstpSlowWrflDnon_handup2b",0.8912509,1,70 } },{ "Acts_PercMstpSlowWrflDnon_handup2c",{ "\A3\Sounds_F\characters\cutscenes\Acts_PercMstpSlowWrflDnon_handup2c",0.56234133,1,70 } },{ "Acts_SignalToCheck",{ "\A3\Sounds_F\characters\cutscenes\Acts_SignalToCheck",0.56234133,1,70 } },{ "Acts_ShowingTheRightWay_Loop",{ "\A3\Sounds_F\characters\cutscenes\Acts_ShowingTheRightWay_Loop",0.56234133,1,70 } },{ "Acts_ShowingTheRightWay_Out",{ "\A3\Sounds_F\characters\cutscenes\Acts_ShowingTheRightWay_Out",0.56234133,1,70 } },{ "Acts_ShieldFromSun_Loop",{ "\A3\Sounds_F\characters\cutscenes\Acts_ShieldFromSun_Loop",0.56234133,1,70 } },{ "Acts_ShieldFromSun_Out",{ "\A3\Sounds_F\characters\cutscenes\Acts_ShieldFromSun_Out",0.56234133,1,70 } },{ "Acts_TreatingWounded01",{ "\A3\Sounds_F\characters\cutscenes\Acts_TreatingWounded01",0.56234133,1,70 } },{ "Acts_TreatingWounded02",{ "\A3\Sounds_F\characters\cutscenes\Acts_TreatingWounded02",0.56234133,1,70 } },{ "Acts_TreatingWounded03",{ "\A3\Sounds_F\characters\cutscenes\Acts_TreatingWounded03",0.56234133,1,70 } },{ "Acts_TreatingWounded04",{ "\A3\Sounds_F\characters\cutscenes\Acts_TreatingWounded04",0.56234133,1,70 } },{ "Acts_TreatingWounded05",{ "\A3\Sounds_F\characters\cutscenes\Acts_TreatingWounded05",0.56234133,1,70 } },{ "Acts_TreatingWounded06",{ "\A3\Sounds_F\characters\cutscenes\Acts_TreatingWounded06",0.56234133,1,70 } },{ "Acts_AidlPercMstpSlowWrflDnon_pissing",{ "\A3\Sounds_F\characters\cutscenes\Acts_AidlPercMstpSlowWrflDnon_pissing",0.8912509,1,70 } },{ "Acts_BoatAttacked01",{ "\A3\Sounds_F\characters\cutscenes\Acts_BoatAttacked01",0.8912509,1,70 } },{ "Acts_BoatAttacked02",{ "\A3\Sounds_F\characters\cutscenes\Acts_BoatAttacked02",0.8912509,1,70 } },{ "Acts_BoatAttacked03",{ "\A3\Sounds_F\characters\cutscenes\Acts_BoatAttacked03",0.8912509,1,70 } },{ "Acts_BoatAttacked04",{ "\A3\Sounds_F\characters\cutscenes\Acts_BoatAttacked04",0.8912509,1,70 } },{ "Acts_BoatAttacked05",{ "\A3\Sounds_F\characters\cutscenes\Acts_BoatAttacked05",0.8912509,1,70 } },{ "Acts_CrouchingCoveringRifle01",{ "\A3\Sounds_F\characters\cutscenes\Acts_CrouchingCoveringRifle01",0.56234133,1,70 } },{ "Acts_CrouchingIdleRifle01",{ "\A3\Sounds_F\characters\cutscenes\Acts_CrouchingIdleRifle01",0.56234133,1,70 } },{ "Acts_CrouchingReloadingRifle01",{ "\A3\Sounds_F\characters\cutscenes\Acts_CrouchingReloadingRifle01",0.56234133,1,70 } },{ "Acts_CrouchingWatchingRifle01",{ "\A3\Sounds_F\characters\cutscenes\Acts_CrouchingWatchingRifle01",0.56234133,1,70 } },{ "Acts_InjuredAngryRifle01",{ "\A3\Sounds_F\characters\cutscenes\Acts_InjuredAngryRifle01",0.56234133,1,70 } },{ "Acts_InjuredCoughRifle02",{ "\A3\Sounds_F\characters\cutscenes\Acts_InjuredCoughRifle02",0.56234133,1,70 } },{ "Acts_InjuredLookingRifle01",{ "\A3\Sounds_F\characters\cutscenes\Acts_InjuredLookingRifle01",0.56234133,1,70 } },{ "Acts_InjuredLookingRifle02",{ "\A3\Sounds_F\characters\cutscenes\Acts_InjuredLookingRifle02",0.56234133,1,70 } },{ "Acts_InjuredLookingRifle03",{ "\A3\Sounds_F\characters\cutscenes\Acts_InjuredLookingRifle03",0.56234133,1,70 } },{ "Acts_InjuredLookingRifle04",{ "\A3\Sounds_F\characters\cutscenes\Acts_InjuredLookingRifle04",0.56234133,1,70 } },{ "Acts_InjuredLookingRifle05",{ "\A3\Sounds_F\characters\cutscenes\Acts_InjuredLookingRifle05",0.56234133,1,70 } },{ "Acts_InjuredLyingRifle01",{ "\A3\Sounds_F\characters\cutscenes\Acts_InjuredLyingRifle01",0.56234133,1,70 } },{ "Acts_InjuredSpeakingRIfle01",{ "\A3\Sounds_F\characters\cutscenes\Acts_InjuredSpeakingRIfle01",0.56234133,1,70 } },{ "Acts_PknlMstpSlowWrflDnon",{ "\A3\Sounds_F\characters\cutscenes\Acts_PknlMstpSlowWrflDnon",0.56234133,1,70 } },{ "Acts_SittingJumpingSaluting_loop1",{ "\A3\Sounds_F\characters\cutscenes\Acts_SittingJumpingSaluting_loop1",0.56234133,1,70 } },{ "Acts_SittingJumpingSaluting_loop2",{ "\A3\Sounds_F\characters\cutscenes\Acts_SittingJumpingSaluting_loop2",0.56234133,1,70 } },{ "Acts_SittingJumpingSaluting_loop3",{ "\A3\Sounds_F\characters\cutscenes\Acts_SittingJumpingSaluting_loop3",0.56234133,1,70 } }};
			rock[] = {{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.25118864,1,70 } },{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.25118864,1,70 } },{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.25118864,1,70 } },{ "adjust_stand_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel1",0.25118864,1,70 } },{ "adjust_stand_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel2",0.25118864,1,70 } },{ "adjust_kneel_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand1",0.25118864,1,70 } },{ "adjust_kneel_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand2",0.25118864,1,70 } },{ "adjust_stand_to_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_prone",0.25118864,1,70 } },{ "adjust_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_to_stand",0.25118864,1,70 } },{ "adjust_prone_up",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_up",0.25118864,1,70 } },{ "adjust_prone_up_back",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_up_back",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.25118864,1,70 } },{ "adjust_prone_left",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_left",0.25118864,1,70 } },{ "adjust_prone_right",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_right",0.25118864,1,70 } },{ "adjust_kneel_to_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_prone",0.25118864,1,70 } },{ "adjust_prone_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_to_kneel",0.25118864,1,70 } },{ "adjust_stand_to_left_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_left_prone",0.25118864,1,70 } },{ "adjust_stand_to_right_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_right_prone",0.25118864,1,70 } },{ "adjust_left_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_left_prone_to_stand",0.25118864,1,70 } },{ "adjust_right_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_right_prone_to_stand",0.25118864,1,70 } },{ "\A3\sounds_f\characters\footsteps\rock_walk_1",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\rock_walk_2",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\rock_walk_3",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\rock_walk_4",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\rock_walk_5",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\rock_walk_6",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\rock_walk_7",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\rock_walk_8",0.5011872,1,100 },{ "run",{ "\A3\sounds_f\characters\footsteps\rock_run_1",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\rock_run_2",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\rock_run_3",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\rock_run_4",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\rock_run_5",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\rock_run_6",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\rock_run_7",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\rock_run_8",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\rock_walk_1",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\rock_walk_2",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\rock_walk_3",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\rock_walk_4",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\rock_walk_5",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\rock_walk_6",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\rock_walk_7",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\rock_walk_8",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\rock_sprint_1",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\rock_sprint_2",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\rock_sprint_3",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\rock_sprint_4",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\rock_sprint_5",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\rock_sprint_6",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\rock_sprint_7",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\rock_sprint_8",0.5011872,1,100 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_1",0.2238721,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_2",0.2238721,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_3",0.2238721,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_4",0.2238721,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_5",0.2238721,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_6",0.2238721,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_7",0.2238721,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_8",0.2238721,1,50 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_concrete_1",0.5011872,1,70 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_concrete_2",0.5011872,1,70 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_concrete_3",0.5011872,1,70 } },{ "Acts_carFixingWheel",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_carFixingWheel",0.56234133,1,70 } },{ "Acts_PercMwlkSlowWrflDf",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_PercMwlkSlowWrflDf",0.56234133,1,70 } },{ "Acts_PercMwlkSlowWrflDf2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_PercMwlkSlowWrflDf2",0.56234133,1,70 } },{ "Acts_SittingJumpingSaluting_out",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_SittingJumpingSaluting_out",0.56234133,1,70 } },{ "Acts_WalkingChecking",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WalkingChecking",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle02",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle02",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle03",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle03",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle04",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle04",0.56234133,1,70 } },{ "Acts_HUBABriefing",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_HUBABriefing",0.56234133,1,70 } },{ "Acts_PointingLeftUnarmed",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_PointingLeftUnarmed",0.56234133,1,70 } },{ "Acts_SittingJumpingSaluting_in",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_SittingJumpingSaluting_in",0.56234133,1,70 } },{ "Acts_StandingSpeakingUnarmed",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_StandingSpeakingUnarmed",0.56234133,1,70 } },{ "Acts_TreatingWounded_in",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_TreatingWounded_in",0.56234133,1,70 } },{ "Acts_TreatingWounded_out",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_TreatingWounded_out",0.56234133,1,70 } },{ "Acts_UnconsciousStandUp_part1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_UnconsciousStandUp_part1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_1b",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_1b",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_3",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_4",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_5",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_6",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_3",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_4",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_5",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_6",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_3",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_4",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_5",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_6",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_3",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_3",0.56234133,1,70 } }};
			normal[] = {{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.25118864,1,70 } },{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.25118864,1,70 } },{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.25118864,1,70 } },{ "adjust_stand_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel1",0.25118864,1,70 } },{ "adjust_stand_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel2",0.25118864,1,70 } },{ "adjust_kneel_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand1",0.25118864,1,70 } },{ "adjust_kneel_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand2",0.25118864,1,70 } },{ "adjust_stand_to_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_prone",0.25118864,1,70 } },{ "adjust_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_to_stand",0.25118864,1,70 } },{ "adjust_prone_up",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_up",0.25118864,1,70 } },{ "adjust_prone_up_back",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_up_back",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.25118864,1,70 } },{ "adjust_prone_left",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_left",0.25118864,1,70 } },{ "adjust_prone_right",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_right",0.25118864,1,70 } },{ "adjust_kneel_to_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_prone",0.25118864,1,70 } },{ "adjust_prone_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_to_kneel",0.25118864,1,70 } },{ "adjust_stand_to_left_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_left_prone",0.25118864,1,70 } },{ "adjust_stand_to_right_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_right_prone",0.25118864,1,70 } },{ "adjust_left_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_left_prone_to_stand",0.25118864,1,70 } },{ "adjust_right_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_right_prone_to_stand",0.25118864,1,70 } },{ "\A3\sounds_f\characters\footsteps\concrete_walk_1",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\concrete_walk_2",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\concrete_walk_3",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\concrete_walk_4",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\concrete_walk_5",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\concrete_walk_6",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\concrete_walk_7",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\concrete_walk_8",0.5011872,1,100 },{ "run",{ "\A3\sounds_f\characters\footsteps\concrete_run_1",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\concrete_run_2",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\concrete_run_3",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\concrete_run_4",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\concrete_run_5",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\concrete_run_6",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\concrete_run_7",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\concrete_run_8",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\concrete_walk_1",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\concrete_walk_2",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\concrete_walk_3",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\concrete_walk_4",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\concrete_walk_5",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\concrete_walk_6",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\concrete_walk_7",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\concrete_walk_8",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\concrete_sprint_1",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\concrete_sprint_2",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\concrete_sprint_3",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\concrete_sprint_4",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\concrete_sprint_5",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\concrete_sprint_6",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\concrete_sprint_7",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\concrete_sprint_8",0.5011872,1,100 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_1",0.19952624,1,70 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_2",0.19952624,1,70 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_3",0.19952624,1,70 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_4",0.19952624,1,70 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_5",0.19952624,1,70 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_6",0.19952624,1,70 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_7",0.19952624,1,70 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_8",0.19952624,1,70 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_concrete_1",0.5011872,1,70 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_concrete_2",0.5011872,1,70 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_concrete_3",0.5011872,1,70 } },{ "Acts_carFixingWheel",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_carFixingWheel",0.56234133,1,70 } },{ "Acts_PercMwlkSlowWrflDf",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_PercMwlkSlowWrflDf",0.56234133,1,70 } },{ "Acts_PercMwlkSlowWrflDf2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_PercMwlkSlowWrflDf2",0.56234133,1,70 } },{ "Acts_SittingJumpingSaluting_out",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_SittingJumpingSaluting_out",0.56234133,1,70 } },{ "Acts_WalkingChecking",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WalkingChecking",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle02",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle02",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle03",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle03",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle04",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle04",0.56234133,1,70 } },{ "Acts_HUBABriefing",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_HUBABriefing",0.56234133,1,70 } },{ "Acts_PointingLeftUnarmed",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_PointingLeftUnarmed",0.56234133,1,70 } },{ "Acts_SittingJumpingSaluting_in",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_SittingJumpingSaluting_in",0.56234133,1,70 } },{ "Acts_StandingSpeakingUnarmed",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_StandingSpeakingUnarmed",0.56234133,1,70 } },{ "Acts_TreatingWounded_in",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_TreatingWounded_in",0.56234133,1,70 } },{ "Acts_TreatingWounded_out",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_TreatingWounded_out",0.56234133,1,70 } },{ "Acts_UnconsciousStandUp_part1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_UnconsciousStandUp_part1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_1b",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_1b",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_3",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_4",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_5",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_6",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_3",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_4",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_5",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_6",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_3",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_4",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_5",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_6",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_3",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_3",0.56234133,1,70 } }};
			tarmac[] = {{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.25118864,1,70 } },{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.25118864,1,70 } },{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.25118864,1,70 } },{ "adjust_stand_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel1",0.25118864,1,70 } },{ "adjust_stand_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel2",0.25118864,1,70 } },{ "adjust_kneel_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand1",0.25118864,1,70 } },{ "adjust_kneel_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand2",0.25118864,1,70 } },{ "adjust_stand_to_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_prone",0.25118864,1,70 } },{ "adjust_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_to_stand",0.25118864,1,70 } },{ "adjust_prone_up",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_up",0.25118864,1,70 } },{ "adjust_prone_up_back",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_up_back",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.25118864,1,70 } },{ "adjust_prone_left",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_left",0.25118864,1,70 } },{ "adjust_prone_right",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_right",0.25118864,1,70 } },{ "adjust_kneel_to_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_prone",0.25118864,1,70 } },{ "adjust_prone_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_to_kneel",0.25118864,1,70 } },{ "adjust_stand_to_left_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_left_prone",0.25118864,1,70 } },{ "adjust_stand_to_right_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_right_prone",0.25118864,1,70 } },{ "adjust_left_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_left_prone_to_stand",0.25118864,1,70 } },{ "adjust_right_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_right_prone_to_stand",0.25118864,1,70 } },{ "\A3\sounds_f\characters\footsteps\concrete_walk_1",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\concrete_walk_2",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\concrete_walk_3",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\concrete_walk_4",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\concrete_walk_5",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\concrete_walk_6",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\concrete_walk_7",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\concrete_walk_8",0.5011872,1,100 },{ "run",{ "\A3\sounds_f\characters\footsteps\concrete_run_1",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\concrete_run_2",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\concrete_run_3",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\concrete_run_4",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\concrete_run_5",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\concrete_run_6",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\concrete_run_7",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\concrete_run_8",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\concrete_walk_1",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\concrete_walk_2",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\concrete_walk_3",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\concrete_walk_4",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\concrete_walk_5",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\concrete_walk_6",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\concrete_walk_7",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\concrete_walk_8",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\concrete_sprint_1",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\concrete_sprint_2",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\concrete_sprint_3",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\concrete_sprint_4",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\concrete_sprint_5",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\concrete_sprint_6",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\concrete_sprint_7",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\concrete_sprint_8",0.5011872,1,100 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_1",0.2238721,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_2",0.2238721,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_3",0.2238721,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_4",0.2238721,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_5",0.2238721,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_6",0.2238721,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_7",0.2238721,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_8",0.2238721,1,50 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_concrete_1",0.5011872,1,70 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_concrete_2",0.5011872,1,70 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_concrete_3",0.5011872,1,70 } },{ "Acts_carFixingWheel",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_carFixingWheel",0.56234133,1,70 } },{ "Acts_PercMwlkSlowWrflDf",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_PercMwlkSlowWrflDf",0.56234133,1,70 } },{ "Acts_PercMwlkSlowWrflDf2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_PercMwlkSlowWrflDf2",0.56234133,1,70 } },{ "Acts_SittingJumpingSaluting_out",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_SittingJumpingSaluting_out",0.56234133,1,70 } },{ "Acts_WalkingChecking",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WalkingChecking",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle02",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle02",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle03",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle03",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle04",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle04",0.56234133,1,70 } },{ "Acts_HUBABriefing",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_HUBABriefing",0.56234133,1,70 } },{ "Acts_PointingLeftUnarmed",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_PointingLeftUnarmed",0.56234133,1,70 } },{ "Acts_SittingJumpingSaluting_in",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_SittingJumpingSaluting_in",0.56234133,1,70 } },{ "Acts_StandingSpeakingUnarmed",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_StandingSpeakingUnarmed",0.56234133,1,70 } },{ "Acts_TreatingWounded_in",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_TreatingWounded_in",0.56234133,1,70 } },{ "Acts_TreatingWounded_out",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_TreatingWounded_out",0.56234133,1,70 } },{ "Acts_UnconsciousStandUp_part1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_UnconsciousStandUp_part1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_1b",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_1b",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_3",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_4",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_5",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_6",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_3",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_4",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_5",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_6",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_3",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_4",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_5",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_6",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_3",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_3",0.56234133,1,70 } }};
			stony[] = {{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.25118864,1,70 } },{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.25118864,1,70 } },{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.25118864,1,70 } },{ "adjust_stand_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel1",0.25118864,1,70 } },{ "adjust_stand_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel2",0.25118864,1,70 } },{ "adjust_kneel_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand1",0.25118864,1,70 } },{ "adjust_kneel_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand2",0.25118864,1,70 } },{ "adjust_stand_to_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_prone",0.25118864,1,70 } },{ "adjust_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_to_stand",0.25118864,1,70 } },{ "adjust_prone_up",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_up",0.25118864,1,70 } },{ "adjust_prone_up_back",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_up_back",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.25118864,1,70 } },{ "adjust_prone_left",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_left",0.25118864,1,70 } },{ "adjust_prone_right",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_right",0.25118864,1,70 } },{ "adjust_kneel_to_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_prone",0.25118864,1,70 } },{ "adjust_prone_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_to_kneel",0.25118864,1,70 } },{ "adjust_stand_to_left_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_left_prone",0.25118864,1,70 } },{ "adjust_stand_to_right_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_right_prone",0.25118864,1,70 } },{ "adjust_left_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_left_prone_to_stand",0.25118864,1,70 } },{ "adjust_right_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_right_prone_to_stand",0.25118864,1,70 } },{ "\A3\sounds_f\characters\footsteps\stony_walk_1",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\stony_walk_2",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\stony_walk_3",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\stony_walk_4",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\stony_walk_5",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\stony_walk_6",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\stony_walk_7",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\stony_walk_8",0.5011872,1,100 },{ "run",{ "\A3\sounds_f\characters\footsteps\stony_run_1",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\stony_run_2",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\stony_run_3",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\stony_run_4",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\stony_run_5",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\stony_run_6",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\stony_run_7",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\stony_run_8",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\stony_walk_1",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\stony_walk_2",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\stony_walk_3",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\stony_walk_4",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\stony_walk_5",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\stony_walk_6",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\stony_walk_7",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\stony_walk_8",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\stony_sprint_1",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\stony_sprint_2",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\stony_sprint_3",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\stony_sprint_4",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\stony_sprint_5",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\stony_sprint_6",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\stony_sprint_7",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\stony_sprint_8",0.5011872,1,100 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_1",0.19952624,1,70 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_2",0.19952624,1,70 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_3",0.19952624,1,70 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_4",0.19952624,1,70 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_5",0.19952624,1,70 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_6",0.19952624,1,70 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_7",0.19952624,1,70 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_8",0.19952624,1,70 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_concrete_1",0.5011872,1,70 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_concrete_2",0.5011872,1,70 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_concrete_3",0.5011872,1,70 } },{ "swim",{ "A3\Sounds_F\characters\movements\plavani1",0.5011872,1,70 } },{ "swim",{ "A3\Sounds_F\characters\movements\plavani2",0.5011872,1,70 } },{ "swim",{ "A3\Sounds_F\characters\movements\plavani3",0.5011872,1,70 } },{ "Acts_carFixingWheel",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_carFixingWheel",0.56234133,1,70 } },{ "Acts_PercMwlkSlowWrflDf",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_PercMwlkSlowWrflDf",0.56234133,1,70 } },{ "Acts_PercMwlkSlowWrflDf2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_PercMwlkSlowWrflDf2",0.56234133,1,70 } },{ "Acts_SittingJumpingSaluting_out",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_SittingJumpingSaluting_out",0.56234133,1,70 } },{ "Acts_WalkingChecking",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WalkingChecking",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle02",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle02",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle03",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle03",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle04",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle04",0.56234133,1,70 } },{ "Acts_HUBABriefing",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_HUBABriefing",0.56234133,1,70 } },{ "Acts_PointingLeftUnarmed",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_PointingLeftUnarmed",0.56234133,1,70 } },{ "Acts_SittingJumpingSaluting_in",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_SittingJumpingSaluting_in",0.56234133,1,70 } },{ "Acts_StandingSpeakingUnarmed",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_StandingSpeakingUnarmed",0.56234133,1,70 } },{ "Acts_TreatingWounded_in",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_TreatingWounded_in",0.56234133,1,70 } },{ "Acts_TreatingWounded_out",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_TreatingWounded_out",0.56234133,1,70 } },{ "Acts_UnconsciousStandUp_part1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_UnconsciousStandUp_part1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_1b",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_1b",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_3",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_4",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_5",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_6",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_3",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_4",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_5",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_6",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_3",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_4",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_5",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_6",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_3",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_3",0.56234133,1,70 } }};
			water[] = {{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.25118864,1,70 } },{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.25118864,1,70 } },{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.25118864,1,70 } },{ "adjust_stand_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel1",0.25118864,1,70 } },{ "adjust_stand_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel2",0.25118864,1,70 } },{ "adjust_kneel_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand1",0.25118864,1,70 } },{ "adjust_kneel_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand2",0.25118864,1,70 } },{ "adjust_stand_to_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_prone",0.25118864,1,70 } },{ "adjust_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_to_stand",0.25118864,1,70 } },{ "adjust_prone_up",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_up",0.25118864,1,70 } },{ "adjust_prone_up_back",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_up_back",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.25118864,1,70 } },{ "adjust_prone_left",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_left",0.25118864,1,70 } },{ "adjust_prone_right",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_right",0.25118864,1,70 } },{ "adjust_kneel_to_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_prone",0.25118864,1,70 } },{ "adjust_prone_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_to_kneel",0.25118864,1,70 } },{ "adjust_stand_to_left_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_left_prone",0.25118864,1,70 } },{ "adjust_stand_to_right_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_right_prone",0.25118864,1,70 } },{ "adjust_left_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_left_prone_to_stand",0.25118864,1,70 } },{ "adjust_right_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_right_prone_to_stand",0.25118864,1,70 } },{ "\A3\sounds_f\characters\footsteps\water_walk_1",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\water_walk_2",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\water_walk_3",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\water_walk_4",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\water_walk_5",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\water_walk_6",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\water_walk_7",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\water_walk_8",0.5011872,1,100 },{ "run",{ "\A3\sounds_f\characters\footsteps\water_run_1",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\water_run_2",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\water_run_3",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\water_run_4",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\water_run_5",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\water_run_6",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\water_run_7",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\water_run_8",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\water_walk_1",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\water_walk_2",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\water_walk_3",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\water_walk_4",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\water_walk_5",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\water_walk_6",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\water_walk_7",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\water_walk_8",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\water_sprint_1",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\water_sprint_2",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\water_sprint_3",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\water_sprint_4",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\water_sprint_5",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\water_sprint_6",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\water_sprint_7",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\water_sprint_8",0.5011872,1,100 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_water_1",0.19952624,1,70 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_water_2",0.19952624,1,70 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_water_3",0.19952624,1,70 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_water_4",0.19952624,1,70 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_water_5",0.19952624,1,70 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_water_6",0.19952624,1,70 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_water_7",0.19952624,1,70 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_water_8",0.19952624,1,70 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_water_1",0.5011872,1,70 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_water_2",0.5011872,1,70 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_water_3",0.5011872,1,70 } },{ "swim",{ "A3\Sounds_F\characters\movements\plavani1",0.5011872,1,70 } },{ "swim",{ "A3\Sounds_F\characters\movements\plavani2",0.5011872,1,70 } },{ "swim",{ "A3\Sounds_F\characters\movements\plavani3",0.5011872,1,70 } },{ "swim",{ "A3\Sounds_F\characters\movements\plavani4",0.5011872,1,70 } },{ "dive",{ "A3\Sounds_F\characters\movements\diver-swim-1",0.5011872,1.0,70 } },{ "dive",{ "A3\Sounds_F\characters\movements\diver-swim-2",0.5011872,1.0,70 } },{ "dive",{ "A3\Sounds_F\characters\movements\diver-swim-3",0.5011872,1.0,70 } },{ "dive",{ "A3\Sounds_F\characters\movements\diver-swim-4",0.5011872,1.0,70 } },{ "dive",{ "A3\Sounds_F\characters\movements\diver-swim-5",0.5011872,1.0,70 } },{ "dive",{ "A3\Sounds_F\characters\movements\diver-swim-6",0.5011872,1.0,70 } },{ "dive_dry",{ "A3\Sounds_F\characters\movements\diver-dry-swim-1",0.5011872,1.0,70 } },{ "dive_dry",{ "A3\Sounds_F\characters\movements\diver-dry-swim-2",0.5011872,1.0,70 } },{ "dive_dry",{ "A3\Sounds_F\characters\movements\diver-dry-swim-3",0.5011872,1.0,70 } },{ "dive_dry",{ "A3\Sounds_F\characters\movements\diver-dry-swim-4",0.5011872,1.0,70 } },{ "dive_dry",{ "A3\Sounds_F\characters\movements\diver-dry-swim-5",0.5011872,1.0,70 } },{ "dive_dry",{ "A3\Sounds_F\characters\movements\diver-dry-swim-6",0.5011872,1.0,70 } },{ "Acts_carFixingWheel",{ "A3\Sounds_F\characters\cutscenes\water_Acts_carFixingWheel",0.56234133,1,70 } },{ "Acts_PercMwlkSlowWrflDf",{ "A3\Sounds_F\characters\cutscenes\water_Acts_PercMwlkSlowWrflDf",0.56234133,1,70 } },{ "Acts_PercMwlkSlowWrflDf2",{ "A3\Sounds_F\characters\cutscenes\water_Acts_PercMwlkSlowWrflDf2",0.56234133,1,70 } },{ "Acts_SittingJumpingSaluting_out",{ "A3\Sounds_F\characters\cutscenes\water_Acts_SittingJumpingSaluting_out",0.56234133,1,70 } },{ "Acts_WalkingChecking",{ "A3\Sounds_F\characters\cutscenes\water_Acts_WalkingChecking",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle02",{ "A3\Sounds_F\characters\cutscenes\water_Acts_CrouchingFiringLeftRifle02",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle03",{ "A3\Sounds_F\characters\cutscenes\water_Acts_CrouchingFiringLeftRifle03",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle04",{ "A3\Sounds_F\characters\cutscenes\water_Acts_CrouchingFiringLeftRifle04",0.56234133,1,70 } },{ "Acts_HUBABriefing",{ "A3\Sounds_F\characters\cutscenes\water_Acts_HUBABriefing",0.56234133,1,70 } },{ "Acts_PointingLeftUnarmed",{ "A3\Sounds_F\characters\cutscenes\water_Acts_PointingLeftUnarmed",0.56234133,1,70 } },{ "Acts_SittingJumpingSaluting_in",{ "A3\Sounds_F\characters\cutscenes\water_Acts_SittingJumpingSaluting_in",0.56234133,1,70 } },{ "Acts_StandingSpeakingUnarmed",{ "A3\Sounds_F\characters\cutscenes\water_Acts_StandingSpeakingUnarmed",0.56234133,1,70 } },{ "Acts_TreatingWounded_in",{ "A3\Sounds_F\characters\cutscenes\water_Acts_TreatingWounded_in",0.56234133,1,70 } },{ "Acts_TreatingWounded_out",{ "A3\Sounds_F\characters\cutscenes\water_Acts_TreatingWounded_out",0.56234133,1,70 } },{ "Acts_UnconsciousStandUp_part1",{ "A3\Sounds_F\characters\cutscenes\water_Acts_UnconsciousStandUp_part1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk",{ "A3\Sounds_F\characters\cutscenes\water_Acts_WelcomeOnHUB01_AIWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_1",{ "A3\Sounds_F\characters\cutscenes\water_Acts_WelcomeOnHUB01_AIWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_1b",{ "A3\Sounds_F\characters\cutscenes\water_Acts_WelcomeOnHUB01_AIWalk_1b",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_2",{ "A3\Sounds_F\characters\cutscenes\water_Acts_WelcomeOnHUB01_AIWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_3",{ "A3\Sounds_F\characters\cutscenes\water_Acts_WelcomeOnHUB01_AIWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_4",{ "A3\Sounds_F\characters\cutscenes\water_Acts_WelcomeOnHUB01_AIWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_5",{ "A3\Sounds_F\characters\cutscenes\water_Acts_WelcomeOnHUB01_AIWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_6",{ "A3\Sounds_F\characters\cutscenes\water_Acts_WelcomeOnHUB01_AIWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\water_Acts_WelcomeOnHUB01_PlayerWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\water_Acts_WelcomeOnHUB01_PlayerWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_2",{ "A3\Sounds_F\characters\cutscenes\water_Acts_WelcomeOnHUB01_PlayerWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_3",{ "A3\Sounds_F\characters\cutscenes\water_Acts_WelcomeOnHUB01_PlayerWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_4",{ "A3\Sounds_F\characters\cutscenes\water_Acts_WelcomeOnHUB01_PlayerWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_5",{ "A3\Sounds_F\characters\cutscenes\water_Acts_WelcomeOnHUB01_PlayerWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_6",{ "A3\Sounds_F\characters\cutscenes\water_Acts_WelcomeOnHUB01_PlayerWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk",{ "A3\Sounds_F\characters\cutscenes\water_Acts_WelcomeOnHUB02_AIWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_2",{ "A3\Sounds_F\characters\cutscenes\water_Acts_WelcomeOnHUB02_AIWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_3",{ "A3\Sounds_F\characters\cutscenes\water_Acts_WelcomeOnHUB02_AIWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_4",{ "A3\Sounds_F\characters\cutscenes\water_Acts_WelcomeOnHUB02_AIWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_5",{ "A3\Sounds_F\characters\cutscenes\water_Acts_WelcomeOnHUB02_AIWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_6",{ "A3\Sounds_F\characters\cutscenes\water_Acts_WelcomeOnHUB02_AIWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\water_Acts_WelcomeOnHUB02_PlayerWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\water_Acts_WelcomeOnHUB02_PlayerWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_2",{ "A3\Sounds_F\characters\cutscenes\water_Acts_WelcomeOnHUB02_PlayerWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_3",{ "A3\Sounds_F\characters\cutscenes\water_Acts_WelcomeOnHUB02_PlayerWalk_3",0.56234133,1,70 } }};
			gravel[] = {{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.25118864,1,70 } },{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.25118864,1,70 } },{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.25118864,1,70 } },{ "adjust_stand_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel1",0.25118864,1,70 } },{ "adjust_stand_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel2",0.25118864,1,70 } },{ "adjust_kneel_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand1",0.25118864,1,70 } },{ "adjust_kneel_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand2",0.25118864,1,70 } },{ "adjust_stand_to_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_prone",0.25118864,1,70 } },{ "adjust_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_to_stand",0.25118864,1,70 } },{ "adjust_prone_up",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_up",0.25118864,1,70 } },{ "adjust_prone_up_back",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_up_back",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.25118864,1,70 } },{ "adjust_prone_left",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_left",0.25118864,1,70 } },{ "adjust_prone_right",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_right",0.25118864,1,70 } },{ "adjust_kneel_to_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_prone",0.25118864,1,70 } },{ "adjust_prone_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_to_kneel",0.25118864,1,70 } },{ "adjust_stand_to_left_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_left_prone",0.25118864,1,70 } },{ "adjust_stand_to_right_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_right_prone",0.25118864,1,70 } },{ "adjust_left_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_left_prone_to_stand",0.25118864,1,70 } },{ "adjust_right_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_right_prone_to_stand",0.25118864,1,70 } },{ "\A3\sounds_f\characters\footsteps\gravel_walk_1",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\gravel_walk_2",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\gravel_walk_3",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\gravel_walk_4",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\gravel_walk_5",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\gravel_walk_6",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\gravel_walk_7",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\gravel_walk_8",0.5011872,1,100 },{ "run",{ "\A3\sounds_f\characters\footsteps\gravel_run_1",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\gravel_run_2",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\gravel_run_3",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\gravel_run_4",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\gravel_run_5",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\gravel_run_6",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\gravel_run_7",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\gravel_run_8",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\gravel_walk_1",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\gravel_walk_2",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\gravel_walk_3",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\gravel_walk_4",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\gravel_walk_5",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\gravel_walk_6",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\gravel_walk_7",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\gravel_walk_8",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\gravel_sprint_1",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\gravel_sprint_2",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\gravel_sprint_3",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\gravel_sprint_4",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\gravel_sprint_5",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\gravel_sprint_6",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\gravel_sprint_7",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\gravel_sprint_8",0.5011872,1,100 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_dirt_1",0.19952624,1,40 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_dirt_2",0.19952624,1,40 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_dirt_3",0.19952624,1,40 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_dirt_4",0.19952624,1,40 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_dirt_5",0.19952624,1,40 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_dirt_6",0.19952624,1,40 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_dirt_7",0.19952624,1,40 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_gravel_1",0.5011872,1,70 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_gravel_2",0.5011872,1,70 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_gravel_3",0.5011872,1,70 } },{ "swim",{ "A3\Sounds_F\characters\movements\plavani1",0.5011872,1,70 } },{ "swim",{ "A3\Sounds_F\characters\movements\plavani2",0.5011872,1,70 } },{ "swim",{ "A3\Sounds_F\characters\movements\plavani3",0.5011872,1,70 } },{ "Acts_carFixingWheel",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_carFixingWheel",0.56234133,1,70 } },{ "Acts_PercMwlkSlowWrflDf",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_PercMwlkSlowWrflDf",0.56234133,1,70 } },{ "Acts_PercMwlkSlowWrflDf2",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_PercMwlkSlowWrflDf2",0.56234133,1,70 } },{ "Acts_SittingJumpingSaluting_out",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_SittingJumpingSaluting_out",0.56234133,1,70 } },{ "Acts_WalkingChecking",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WalkingChecking",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle02",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_CrouchingFiringLeftRifle02",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle03",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_CrouchingFiringLeftRifle03",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle04",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_CrouchingFiringLeftRifle04",0.56234133,1,70 } },{ "Acts_HUBABriefing",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_HUBABriefing",0.56234133,1,70 } },{ "Acts_PointingLeftUnarmed",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_PointingLeftUnarmed",0.56234133,1,70 } },{ "Acts_SittingJumpingSaluting_in",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_SittingJumpingSaluting_in",0.56234133,1,70 } },{ "Acts_StandingSpeakingUnarmed",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_StandingSpeakingUnarmed",0.56234133,1,70 } },{ "Acts_TreatingWounded_in",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_TreatingWounded_in",0.56234133,1,70 } },{ "Acts_TreatingWounded_out",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_TreatingWounded_out",0.56234133,1,70 } },{ "Acts_UnconsciousStandUp_part1",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_UnconsciousStandUp_part1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_1",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_1b",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_1b",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_2",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_3",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_4",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_5",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_6",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_2",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_3",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_4",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_5",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_6",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_2",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_3",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_4",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_5",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_6",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_PlayerWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_PlayerWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_2",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_PlayerWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_3",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_PlayerWalk_3",0.56234133,1,70 } }};
			roof_tiles[] = {{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.25118864,1,70 } },{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.25118864,1,70 } },{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.25118864,1,70 } },{ "adjust_stand_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel1",0.25118864,1,70 } },{ "adjust_stand_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel2",0.25118864,1,70 } },{ "adjust_kneel_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand1",0.25118864,1,70 } },{ "adjust_kneel_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand2",0.25118864,1,70 } },{ "adjust_stand_to_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_prone",0.25118864,1,70 } },{ "adjust_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_to_stand",0.25118864,1,70 } },{ "adjust_prone_up",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_up",0.25118864,1,70 } },{ "adjust_prone_up_back",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_up_back",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.25118864,1,70 } },{ "adjust_prone_left",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_left",0.25118864,1,70 } },{ "adjust_prone_right",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_right",0.25118864,1,70 } },{ "adjust_kneel_to_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_prone",0.25118864,1,70 } },{ "adjust_prone_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_to_kneel",0.25118864,1,70 } },{ "adjust_stand_to_left_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_left_prone",0.25118864,1,70 } },{ "adjust_stand_to_right_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_right_prone",0.25118864,1,70 } },{ "adjust_left_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_left_prone_to_stand",0.25118864,1,70 } },{ "adjust_right_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_right_prone_to_stand",0.25118864,1,70 } },{ "\A3\sounds_f\characters\footsteps\roof_tiles_walk_1",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\roof_tiles_walk_2",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\roof_tiles_walk_3",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\roof_tiles_walk_4",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\roof_tiles_walk_5",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\roof_tiles_walk_6",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\roof_tiles_walk_7",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\roof_tiles_walk_8",0.5011872,1,100 },{ "run",{ "\A3\sounds_f\characters\footsteps\roof_tiles_run_1",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\roof_tiles_run_2",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\roof_tiles_run_3",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\roof_tiles_run_4",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\roof_tiles_run_5",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\roof_tiles_run_6",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\roof_tiles_run_7",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\roof_tiles_run_8",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\roof_tiles_walk_1",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\roof_tiles_walk_2",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\roof_tiles_walk_3",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\roof_tiles_walk_4",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\roof_tiles_walk_5",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\roof_tiles_walk_6",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\roof_tiles_walk_7",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\roof_tiles_walk_8",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\roof_tiles_sprint_1",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\roof_tiles_sprint_2",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\roof_tiles_sprint_3",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\roof_tiles_sprint_4",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\roof_tiles_sprint_5",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\roof_tiles_sprint_6",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\roof_tiles_sprint_7",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\roof_tiles_sprint_8",0.5011872,1,100 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_1",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_2",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_3",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_4",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_5",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_6",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_7",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_8",0.19952624,1,50 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_concrete_1",0.5011872,1,70 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_concrete_2",0.5011872,1,70 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_concrete_3",0.5011872,1,70 } },{ "swim",{ "A3\Sounds_F\characters\movements\plavani1",0.5011872,1,70 } },{ "swim",{ "A3\Sounds_F\characters\movements\plavani2",0.5011872,1,70 } },{ "swim",{ "A3\Sounds_F\characters\movements\plavani3",0.5011872,1,70 } },{ "Acts_carFixingWheel",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_carFixingWheel",0.56234133,1,70 } },{ "Acts_PercMwlkSlowWrflDf",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_PercMwlkSlowWrflDf",0.56234133,1,70 } },{ "Acts_PercMwlkSlowWrflDf2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_PercMwlkSlowWrflDf2",0.56234133,1,70 } },{ "Acts_SittingJumpingSaluting_out",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_SittingJumpingSaluting_out",0.56234133,1,70 } },{ "Acts_WalkingChecking",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WalkingChecking",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle02",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle02",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle03",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle03",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle04",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle04",0.56234133,1,70 } },{ "Acts_HUBABriefing",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_HUBABriefing",0.56234133,1,70 } },{ "Acts_PointingLeftUnarmed",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_PointingLeftUnarmed",0.56234133,1,70 } },{ "Acts_SittingJumpingSaluting_in",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_SittingJumpingSaluting_in",0.56234133,1,70 } },{ "Acts_StandingSpeakingUnarmed",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_StandingSpeakingUnarmed",0.56234133,1,70 } },{ "Acts_TreatingWounded_in",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_TreatingWounded_in",0.56234133,1,70 } },{ "Acts_TreatingWounded_out",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_TreatingWounded_out",0.56234133,1,70 } },{ "Acts_UnconsciousStandUp_part1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_UnconsciousStandUp_part1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_1b",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_1b",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_3",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_4",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_5",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_6",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_3",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_4",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_5",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_6",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_3",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_4",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_5",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_6",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_3",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_3",0.56234133,1,70 } }};
			sand[] = {{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.25118864,1,70 } },{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.25118864,1,70 } },{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.25118864,1,70 } },{ "adjust_stand_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel1",0.25118864,1,70 } },{ "adjust_stand_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel2",0.25118864,1,70 } },{ "adjust_kneel_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand1",0.25118864,1,70 } },{ "adjust_kneel_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand2",0.25118864,1,70 } },{ "adjust_stand_to_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_prone",0.25118864,1,70 } },{ "adjust_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_to_stand",0.25118864,1,70 } },{ "adjust_prone_up",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_up",0.25118864,1,70 } },{ "adjust_prone_up_back",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_up_back",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.25118864,1,70 } },{ "adjust_prone_left",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_left",0.25118864,1,70 } },{ "adjust_prone_right",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_right",0.25118864,1,70 } },{ "adjust_kneel_to_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_prone",0.25118864,1,70 } },{ "adjust_prone_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_to_kneel",0.25118864,1,70 } },{ "adjust_stand_to_left_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_left_prone",0.25118864,1,70 } },{ "adjust_stand_to_right_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_right_prone",0.25118864,1,70 } },{ "adjust_left_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_left_prone_to_stand",0.25118864,1,70 } },{ "adjust_right_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_right_prone_to_stand",0.25118864,1,70 } },{ "\A3\sounds_f\characters\footsteps\sand_walk_1",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\sand_walk_2",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\sand_walk_3",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\sand_walk_4",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\sand_walk_5",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\sand_walk_6",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\sand_walk_7",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\sand_walk_8",0.5011872,1,100 },{ "run",{ "\A3\sounds_f\characters\footsteps\sand_run_1",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\sand_run_2",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\sand_run_3",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\sand_run_4",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\sand_run_5",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\sand_run_6",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\sand_run_7",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\sand_run_8",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\sand_walk_1",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\sand_walk_2",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\sand_walk_3",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\sand_walk_4",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\sand_walk_5",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\sand_walk_6",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\sand_walk_7",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\sand_walk_8",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\sand_sprint_1",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\sand_sprint_2",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\sand_sprint_3",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\sand_sprint_4",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\sand_sprint_5",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\sand_sprint_6",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\sand_sprint_7",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\sand_sprint_8",0.5011872,1,100 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_sand_01",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_sand_02",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_sand_03",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_sand_04",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_sand_05",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_sand_06",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_sand_07",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_sand_08",0.19952624,1,50 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_sand_1",0.5011872,1,70 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_sand_2",0.5011872,1,70 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_sand_3",0.5011872,1,70 } },{ "swim",{ "A3\Sounds_F\characters\movements\plavani1",0.5011872,1,70 } },{ "swim",{ "A3\Sounds_F\characters\movements\plavani2",0.5011872,1,70 } },{ "swim",{ "A3\Sounds_F\characters\movements\plavani3",0.5011872,1,70 } },{ "Acts_carFixingWheel",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_carFixingWheel",0.56234133,1,70 } },{ "Acts_PercMwlkSlowWrflDf",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_PercMwlkSlowWrflDf",0.56234133,1,70 } },{ "Acts_PercMwlkSlowWrflDf2",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_PercMwlkSlowWrflDf2",0.56234133,1,70 } },{ "Acts_SittingJumpingSaluting_out",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_SittingJumpingSaluting_out",0.56234133,1,70 } },{ "Acts_WalkingChecking",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WalkingChecking",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle02",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_CrouchingFiringLeftRifle02",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle03",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_CrouchingFiringLeftRifle03",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle04",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_CrouchingFiringLeftRifle04",0.56234133,1,70 } },{ "Acts_HUBABriefing",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_HUBABriefing",0.56234133,1,70 } },{ "Acts_PointingLeftUnarmed",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_PointingLeftUnarmed",0.56234133,1,70 } },{ "Acts_SittingJumpingSaluting_in",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_SittingJumpingSaluting_in",0.56234133,1,70 } },{ "Acts_StandingSpeakingUnarmed",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_StandingSpeakingUnarmed",0.56234133,1,70 } },{ "Acts_TreatingWounded_in",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_TreatingWounded_in",0.56234133,1,70 } },{ "Acts_TreatingWounded_out",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_TreatingWounded_out",0.56234133,1,70 } },{ "Acts_UnconsciousStandUp_part1",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_UnconsciousStandUp_part1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_AIWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_1",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_AIWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_1b",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_AIWalk_1b",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_2",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_AIWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_3",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_AIWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_4",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_AIWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_5",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_AIWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_6",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_AIWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_PlayerWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_PlayerWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_2",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_PlayerWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_3",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_PlayerWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_4",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_PlayerWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_5",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_PlayerWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_6",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_PlayerWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_AIWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_2",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_AIWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_3",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_AIWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_4",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_AIWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_5",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_AIWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_6",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_AIWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_PlayerWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_PlayerWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_2",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_PlayerWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_3",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_PlayerWalk_3",0.56234133,1,70 } }};
			drygrass[] = {{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.25118864,1,70 } },{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.25118864,1,70 } },{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.25118864,1,70 } },{ "adjust_stand_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel1",0.25118864,1,70 } },{ "adjust_stand_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel2",0.25118864,1,70 } },{ "adjust_kneel_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand1",0.25118864,1,70 } },{ "adjust_kneel_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand2",0.25118864,1,70 } },{ "adjust_stand_to_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_prone",0.25118864,1,70 } },{ "adjust_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_to_stand",0.25118864,1,70 } },{ "adjust_prone_up",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_up",0.25118864,1,70 } },{ "adjust_prone_up_back",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_up_back",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.25118864,1,70 } },{ "adjust_prone_left",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_left",0.25118864,1,70 } },{ "adjust_prone_right",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_right",0.25118864,1,70 } },{ "adjust_kneel_to_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_prone",0.25118864,1,70 } },{ "adjust_prone_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_to_kneel",0.25118864,1,70 } },{ "adjust_stand_to_left_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_left_prone",0.25118864,1,70 } },{ "adjust_stand_to_right_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_right_prone",0.25118864,1,70 } },{ "adjust_left_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_left_prone_to_stand",0.25118864,1,70 } },{ "adjust_right_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_right_prone_to_stand",0.25118864,1,70 } },{ "\A3\sounds_f\characters\footsteps\new_dry_grass_walk_1",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\new_dry_grass_walk_2",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\new_dry_grass_walk_3",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\new_dry_grass_walk_4",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\new_dry_grass_walk_5",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\new_dry_grass_walk_6",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\new_dry_grass_walk_7",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\new_dry_grass_walk_8",0.5011872,1,100 },{ "run",{ "\A3\sounds_f\characters\footsteps\new_dry_grass_run_1",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\new_dry_grass_run_2",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\new_dry_grass_run_3",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\new_dry_grass_run_4",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\new_dry_grass_run_5",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\new_dry_grass_run_6",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\new_dry_grass_run_7",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\new_dry_grass_run_8",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\new_dry_grass_walk_1",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\new_dry_grass_walk_2",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\new_dry_grass_walk_3",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\new_dry_grass_walk_4",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\new_dry_grass_walk_5",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\new_dry_grass_walk_6",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\new_dry_grass_walk_7",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\new_dry_grass_walk_8",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\new_dry_grass_sprint_1",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\new_dry_grass_sprint_2",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\new_dry_grass_sprint_3",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\new_dry_grass_sprint_4",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\new_dry_grass_sprint_5",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\new_dry_grass_sprint_6",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\new_dry_grass_sprint_7",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\new_dry_grass_sprint_8",0.5011872,1,100 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_grass_01",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_grass_02",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_grass_03",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_grass_04",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_grass_05",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_grass_06",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_grass_07",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_grass_08",0.19952624,1,50 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_drygrass_1",0.5011872,1,70 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_drygrass_2",0.5011872,1,70 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_drygrass_3",0.5011872,1,70 } },{ "swim",{ "A3\Sounds_F\characters\movements\plavani1",0.5011872,1,70 } },{ "swim",{ "A3\Sounds_F\characters\movements\plavani2",0.5011872,1,70 } },{ "swim",{ "A3\Sounds_F\characters\movements\plavani3",0.5011872,1,70 } },{ "Acts_carFixingWheel",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_carFixingWheel",0.56234133,1,70 } },{ "Acts_PercMwlkSlowWrflDf",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_PercMwlkSlowWrflDf",0.56234133,1,70 } },{ "Acts_PercMwlkSlowWrflDf2",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_PercMwlkSlowWrflDf2",0.56234133,1,70 } },{ "Acts_SittingJumpingSaluting_out",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_SittingJumpingSaluting_out",0.56234133,1,70 } },{ "Acts_WalkingChecking",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WalkingChecking",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle02",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_CrouchingFiringLeftRifle02",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle03",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_CrouchingFiringLeftRifle03",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle04",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_CrouchingFiringLeftRifle04",0.56234133,1,70 } },{ "Acts_HUBABriefing",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_HUBABriefing",0.56234133,1,70 } },{ "Acts_PointingLeftUnarmed",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_PointingLeftUnarmed",0.56234133,1,70 } },{ "Acts_SittingJumpingSaluting_in",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_SittingJumpingSaluting_in",0.56234133,1,70 } },{ "Acts_StandingSpeakingUnarmed",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_StandingSpeakingUnarmed",0.56234133,1,70 } },{ "Acts_TreatingWounded_in",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_TreatingWounded_in",0.56234133,1,70 } },{ "Acts_TreatingWounded_out",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_TreatingWounded_out",0.56234133,1,70 } },{ "Acts_UnconsciousStandUp_part1",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_UnconsciousStandUp_part1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_AIWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_1",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_AIWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_1b",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_AIWalk_1b",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_2",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_AIWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_3",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_AIWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_4",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_AIWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_5",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_AIWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_6",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_AIWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_PlayerWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_PlayerWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_2",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_PlayerWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_3",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_PlayerWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_4",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_PlayerWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_5",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_PlayerWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_6",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_PlayerWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_AIWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_2",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_AIWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_3",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_AIWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_4",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_AIWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_5",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_AIWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_6",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_AIWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_PlayerWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_PlayerWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_2",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_PlayerWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_3",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_PlayerWalk_3",0.56234133,1,70 } }};
			grass[] = {{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.25118864,1,70 } },{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.25118864,1,70 } },{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.25118864,1,70 } },{ "adjust_stand_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel1",0.25118864,1,70 } },{ "adjust_stand_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel2",0.25118864,1,70 } },{ "adjust_kneel_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand1",0.25118864,1,70 } },{ "adjust_kneel_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand2",0.25118864,1,70 } },{ "adjust_stand_to_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_prone",0.25118864,1,70 } },{ "adjust_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_to_stand",0.25118864,1,70 } },{ "adjust_prone_up",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_up",0.25118864,1,70 } },{ "adjust_prone_up_back",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_up_back",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.25118864,1,70 } },{ "adjust_prone_left",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_left",0.25118864,1,70 } },{ "adjust_prone_right",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_right",0.25118864,1,70 } },{ "adjust_kneel_to_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_prone",0.25118864,1,70 } },{ "adjust_prone_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_to_kneel",0.25118864,1,70 } },{ "adjust_stand_to_left_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_left_prone",0.25118864,1,70 } },{ "adjust_stand_to_right_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_right_prone",0.25118864,1,70 } },{ "adjust_left_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_left_prone_to_stand",0.25118864,1,70 } },{ "adjust_right_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_right_prone_to_stand",0.25118864,1,70 } },{ "\A3\sounds_f\characters\footsteps\new_grass_walk_1",0.15848932,1,70 },{ "\A3\sounds_f\characters\footsteps\new_grass_walk_2",0.15848932,1,70 },{ "\A3\sounds_f\characters\footsteps\new_grass_walk_3",0.15848932,1,70 },{ "\A3\sounds_f\characters\footsteps\new_grass_walk_4",0.15848932,1,70 },{ "\A3\sounds_f\characters\footsteps\new_grass_walk_5",0.15848932,1,70 },{ "\A3\sounds_f\characters\footsteps\new_grass_walk_6",0.15848932,1,70 },{ "\A3\sounds_f\characters\footsteps\new_grass_walk_7",0.15848932,1,70 },{ "\A3\sounds_f\characters\footsteps\new_grass_walk_8",0.15848932,1,70 },{ "run",{ "\A3\sounds_f\characters\footsteps\new_grass_run_1",0.25118864,1,70 } },{ "run",{ "\A3\sounds_f\characters\footsteps\new_grass_run_2",0.25118864,1,70 } },{ "run",{ "\A3\sounds_f\characters\footsteps\new_grass_run_3",0.25118864,1,70 } },{ "run",{ "\A3\sounds_f\characters\footsteps\new_grass_run_4",0.25118864,1,70 } },{ "run",{ "\A3\sounds_f\characters\footsteps\new_grass_run_5",0.25118864,1,70 } },{ "run",{ "\A3\sounds_f\characters\footsteps\new_grass_run_6",0.25118864,1,70 } },{ "run",{ "\A3\sounds_f\characters\footsteps\new_grass_run_7",0.25118864,1,70 } },{ "run",{ "\A3\sounds_f\characters\footsteps\new_grass_run_8",0.25118864,1,70 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\new_grass_walk_1",0.15848932,1,70 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\new_grass_walk_2",0.15848932,1,70 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\new_grass_walk_3",0.15848932,1,70 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\new_grass_walk_4",0.15848932,1,70 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\new_grass_walk_5",0.15848932,1,70 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\new_grass_walk_6",0.15848932,1,70 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\new_grass_walk_7",0.15848932,1,70 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\new_grass_walk_8",0.15848932,1,70 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\new_grass_sprint_1",0.31622776,1,70 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\new_grass_sprint_2",0.31622776,1,70 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\new_grass_sprint_3",0.31622776,1,70 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\new_grass_sprint_4",0.31622776,1,70 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\new_grass_sprint_5",0.31622776,1,70 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\new_grass_sprint_6",0.31622776,1,70 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\new_grass_sprint_7",0.31622776,1,70 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\new_grass_sprint_8",0.31622776,1,70 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_grass_01",0.17782794,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_grass_02",0.17782794,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_grass_03",0.17782794,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_grass_04",0.17782794,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_grass_05",0.17782794,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_grass_06",0.17782794,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_grass_07",0.17782794,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_grass_08",0.17782794,1,50 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_grass_1",0.5011872,1,70 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_grass_2",0.5011872,1,70 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_grass_3",0.5011872,1,70 } },{ "swim",{ "A3\Sounds_F\characters\movements\plavani1",0.5011872,1,70 } },{ "swim",{ "A3\Sounds_F\characters\movements\plavani2",0.5011872,1,70 } },{ "swim",{ "A3\Sounds_F\characters\movements\plavani3",0.5011872,1,70 } },{ "Acts_carFixingWheel",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_carFixingWheel",0.56234133,1,70 } },{ "Acts_PercMwlkSlowWrflDf",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_PercMwlkSlowWrflDf",0.56234133,1,70 } },{ "Acts_PercMwlkSlowWrflDf2",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_PercMwlkSlowWrflDf2",0.56234133,1,70 } },{ "Acts_SittingJumpingSaluting_out",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_SittingJumpingSaluting_out",0.56234133,1,70 } },{ "Acts_WalkingChecking",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WalkingChecking",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle02",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_CrouchingFiringLeftRifle02",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle03",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_CrouchingFiringLeftRifle03",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle04",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_CrouchingFiringLeftRifle04",0.56234133,1,70 } },{ "Acts_HUBABriefing",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_HUBABriefing",0.56234133,1,70 } },{ "Acts_PointingLeftUnarmed",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_PointingLeftUnarmed",0.56234133,1,70 } },{ "Acts_SittingJumpingSaluting_in",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_SittingJumpingSaluting_in",0.56234133,1,70 } },{ "Acts_StandingSpeakingUnarmed",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_StandingSpeakingUnarmed",0.56234133,1,70 } },{ "Acts_TreatingWounded_in",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_TreatingWounded_in",0.56234133,1,70 } },{ "Acts_TreatingWounded_out",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_TreatingWounded_out",0.56234133,1,70 } },{ "Acts_UnconsciousStandUp_part1",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_UnconsciousStandUp_part1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_AIWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_1",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_AIWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_1b",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_AIWalk_1b",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_2",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_AIWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_3",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_AIWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_4",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_AIWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_5",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_AIWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_6",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_AIWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_PlayerWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_PlayerWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_2",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_PlayerWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_3",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_PlayerWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_4",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_PlayerWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_5",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_PlayerWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_6",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB01_PlayerWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_AIWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_2",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_AIWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_3",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_AIWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_4",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_AIWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_5",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_AIWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_6",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_AIWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_PlayerWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_PlayerWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_2",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_PlayerWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_3",{ "A3\Sounds_F\characters\cutscenes\grass_Acts_WelcomeOnHUB02_PlayerWalk_3",0.56234133,1,70 } }};
			debris[] = {{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.25118864,1,70 } },{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.25118864,1,70 } },{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.25118864,1,70 } },{ "adjust_stand_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel1",0.25118864,1,70 } },{ "adjust_stand_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel2",0.25118864,1,70 } },{ "adjust_kneel_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand1",0.25118864,1,70 } },{ "adjust_kneel_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand2",0.25118864,1,70 } },{ "adjust_stand_to_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_prone",0.25118864,1,70 } },{ "adjust_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_to_stand",0.25118864,1,70 } },{ "adjust_prone_up",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_up",0.25118864,1,70 } },{ "adjust_prone_up_back",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_up_back",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.25118864,1,70 } },{ "adjust_prone_left",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_left",0.25118864,1,70 } },{ "adjust_prone_right",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_right",0.25118864,1,70 } },{ "adjust_kneel_to_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_prone",0.25118864,1,70 } },{ "adjust_prone_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_to_kneel",0.25118864,1,70 } },{ "adjust_stand_to_left_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_left_prone",0.25118864,1,70 } },{ "adjust_stand_to_right_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_right_prone",0.25118864,1,70 } },{ "adjust_left_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_left_prone_to_stand",0.25118864,1,70 } },{ "adjust_right_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_right_prone_to_stand",0.25118864,1,70 } },{ "\A3\sounds_f\characters\footsteps\debris_walk_1",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\debris_walk_2",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\debris_walk_3",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\debris_walk_4",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\debris_walk_5",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\debris_walk_6",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\debris_walk_7",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\debris_walk_8",0.5011872,1,100 },{ "run",{ "\A3\sounds_f\characters\footsteps\debris_run_1",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\debris_run_2",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\debris_run_3",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\debris_run_4",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\debris_run_5",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\debris_run_6",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\debris_run_7",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\debris_run_8",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\debris_walk_1",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\debris_walk_2",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\debris_walk_3",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\debris_walk_4",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\debris_walk_5",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\debris_walk_6",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\debris_walk_7",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\debris_walk_8",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\debris_sprint_1",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\debris_sprint_2",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\debris_sprint_3",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\debris_sprint_4",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\debris_sprint_5",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\debris_sprint_6",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\debris_sprint_7",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\debris_sprint_8",0.5011872,1,100 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_dirt_1",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_dirt_2",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_dirt_3",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_dirt_4",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_dirt_5",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_dirt_6",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_dirt_7",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_dirt_8",0.19952624,1,50 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_gravel_1",0.5011872,1,70 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_gravel_2",0.5011872,1,70 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_gravel_3",0.5011872,1,70 } },{ "swim",{ "A3\Sounds_F\characters\movements\plavani1",0.5011872,1,70 } },{ "swim",{ "A3\Sounds_F\characters\movements\plavani2",0.5011872,1,70 } },{ "swim",{ "A3\Sounds_F\characters\movements\plavani3",0.5011872,1,70 } },{ "Acts_carFixingWheel",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_carFixingWheel",0.56234133,1,70 } },{ "Acts_PercMwlkSlowWrflDf",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_PercMwlkSlowWrflDf",0.56234133,1,70 } },{ "Acts_PercMwlkSlowWrflDf2",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_PercMwlkSlowWrflDf2",0.56234133,1,70 } },{ "Acts_SittingJumpingSaluting_out",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_SittingJumpingSaluting_out",0.56234133,1,70 } },{ "Acts_WalkingChecking",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WalkingChecking",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle02",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_CrouchingFiringLeftRifle02",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle03",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_CrouchingFiringLeftRifle03",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle04",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_CrouchingFiringLeftRifle04",0.56234133,1,70 } },{ "Acts_HUBABriefing",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_HUBABriefing",0.56234133,1,70 } },{ "Acts_PointingLeftUnarmed",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_PointingLeftUnarmed",0.56234133,1,70 } },{ "Acts_SittingJumpingSaluting_in",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_SittingJumpingSaluting_in",0.56234133,1,70 } },{ "Acts_StandingSpeakingUnarmed",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_StandingSpeakingUnarmed",0.56234133,1,70 } },{ "Acts_TreatingWounded_in",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_TreatingWounded_in",0.56234133,1,70 } },{ "Acts_TreatingWounded_out",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_TreatingWounded_out",0.56234133,1,70 } },{ "Acts_UnconsciousStandUp_part1",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_UnconsciousStandUp_part1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_1",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_1b",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_1b",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_2",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_3",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_4",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_5",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_6",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_2",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_3",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_4",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_5",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_6",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_2",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_3",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_4",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_5",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_6",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_PlayerWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_PlayerWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_2",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_PlayerWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_3",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_PlayerWalk_3",0.56234133,1,70 } }};
			wood[] = {{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.25118864,1,70 } },{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.25118864,1,70 } },{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.25118864,1,70 } },{ "adjust_stand_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel1",0.25118864,1,70 } },{ "adjust_stand_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel2",0.25118864,1,70 } },{ "adjust_kneel_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand1",0.25118864,1,70 } },{ "adjust_kneel_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand2",0.25118864,1,70 } },{ "adjust_stand_to_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_prone",0.25118864,1,70 } },{ "adjust_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_to_stand",0.25118864,1,70 } },{ "adjust_prone_up",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_up",0.25118864,1,70 } },{ "adjust_prone_up_back",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_up_back",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.25118864,1,70 } },{ "adjust_prone_left",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_left",0.25118864,1,70 } },{ "adjust_prone_right",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_right",0.25118864,1,70 } },{ "adjust_kneel_to_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_prone",0.25118864,1,70 } },{ "adjust_prone_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_to_kneel",0.25118864,1,70 } },{ "adjust_stand_to_left_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_left_prone",0.25118864,1,70 } },{ "adjust_stand_to_right_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_right_prone",0.25118864,1,70 } },{ "adjust_left_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_left_prone_to_stand",0.25118864,1,70 } },{ "adjust_right_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_right_prone_to_stand",0.25118864,1,70 } },{ "\A3\sounds_f\characters\footsteps\wood_walk_ext_1",0.5011872,0.7,100 },{ "\A3\sounds_f\characters\footsteps\wood_walk_ext_2",0.5011872,0.7,100 },{ "\A3\sounds_f\characters\footsteps\wood_walk_ext_3",0.5011872,0.7,100 },{ "\A3\sounds_f\characters\footsteps\wood_walk_ext_4",0.5011872,0.7,100 },{ "\A3\sounds_f\characters\footsteps\wood_walk_ext_5",0.5011872,0.7,100 },{ "\A3\sounds_f\characters\footsteps\wood_walk_ext_6",0.5011872,0.7,100 },{ "\A3\sounds_f\characters\footsteps\wood_walk_ext_7",0.5011872,0.7,100 },{ "\A3\sounds_f\characters\footsteps\wood_walk_ext_8",0.5011872,0.7,100 },{ "run",{ "\A3\sounds_f\characters\footsteps\wood_run_ext_1",0.5011872,0.7,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\wood_run_ext_2",0.5011872,0.7,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\wood_run_ext_3",0.5011872,0.7,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\wood_run_ext_4",0.5011872,0.7,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\wood_run_ext_5",0.5011872,0.7,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\wood_run_ext_6",0.5011872,0.7,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\wood_run_ext_7",0.5011872,0.7,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\wood_run_ext_8",0.5011872,0.7,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\wood_walk_ext_1",0.5011872,0.7,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\wood_walk_ext_2",0.5011872,0.7,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\wood_walk_ext_3",0.5011872,0.7,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\wood_walk_ext_4",0.5011872,0.7,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\wood_walk_ext_5",0.5011872,0.7,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\wood_walk_ext_6",0.5011872,0.7,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\wood_walk_ext_7",0.5011872,0.7,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\wood_walk_ext_8",0.5011872,0.7,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\wood_sprint_ext_1",0.5011872,0.7,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\wood_sprint_ext_2",0.5011872,0.7,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\wood_sprint_ext_3",0.5011872,0.7,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\wood_sprint_ext_4",0.5011872,0.7,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\wood_sprint_ext_5",0.5011872,0.7,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\wood_sprint_ext_6",0.5011872,0.7,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\wood_sprint_ext_7",0.5011872,0.7,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\wood_sprint_ext_8",0.5011872,0.7,100 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_1",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_2",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_3",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_4",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_5",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_6",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_7",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_8",0.19952624,1,50 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_wood_1",0.5011872,1,70 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_wood_2",0.5011872,1,70 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_wood_3",0.5011872,1,70 } },{ "swim",{ "A3\Sounds_F\characters\movements\plavani1",0.5011872,1,70 } },{ "swim",{ "A3\Sounds_F\characters\movements\plavani2",0.5011872,1,70 } },{ "swim",{ "A3\Sounds_F\characters\movements\plavani3",0.5011872,1,70 } },{ "Acts_carFixingWheel",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_carFixingWheel",0.56234133,1,70 } },{ "Acts_PercMwlkSlowWrflDf",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_PercMwlkSlowWrflDf",0.56234133,1,70 } },{ "Acts_PercMwlkSlowWrflDf2",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_PercMwlkSlowWrflDf2",0.56234133,1,70 } },{ "Acts_SittingJumpingSaluting_out",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_SittingJumpingSaluting_out",0.56234133,1,70 } },{ "Acts_WalkingChecking",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WalkingChecking",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle02",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_CrouchingFiringLeftRifle02",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle03",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_CrouchingFiringLeftRifle03",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle04",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_CrouchingFiringLeftRifle04",0.56234133,1,70 } },{ "Acts_HUBABriefing",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_HUBABriefing",0.56234133,1,70 } },{ "Acts_PointingLeftUnarmed",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_PointingLeftUnarmed",0.56234133,1,70 } },{ "Acts_SittingJumpingSaluting_in",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_SittingJumpingSaluting_in",0.56234133,1,70 } },{ "Acts_StandingSpeakingUnarmed",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_StandingSpeakingUnarmed",0.56234133,1,70 } },{ "Acts_TreatingWounded_in",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_TreatingWounded_in",0.56234133,1,70 } },{ "Acts_TreatingWounded_out",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_TreatingWounded_out",0.56234133,1,70 } },{ "Acts_UnconsciousStandUp_part1",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_UnconsciousStandUp_part1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_1",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_1b",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_1b",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_2",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_3",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_4",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_5",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_6",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_2",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_3",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_4",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_5",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_6",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_2",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_3",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_4",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_5",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_6",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_PlayerWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_PlayerWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_2",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_PlayerWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_3",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_PlayerWalk_3",0.56234133,1,70 } }};
			wood_int[] = {{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.25118864,1,70 } },{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.25118864,1,70 } },{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.25118864,1,70 } },{ "adjust_stand_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel1",0.25118864,1,70 } },{ "adjust_stand_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel2",0.25118864,1,70 } },{ "adjust_kneel_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand1",0.25118864,1,70 } },{ "adjust_kneel_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand2",0.25118864,1,70 } },{ "adjust_stand_to_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_prone",0.25118864,1,70 } },{ "adjust_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_to_stand",0.25118864,1,70 } },{ "adjust_prone_up",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_up",0.25118864,1,70 } },{ "adjust_prone_up_back",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_up_back",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.25118864,1,70 } },{ "adjust_prone_left",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_left",0.25118864,1,70 } },{ "adjust_prone_right",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_right",0.25118864,1,70 } },{ "adjust_kneel_to_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_prone",0.25118864,1,70 } },{ "adjust_prone_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_to_kneel",0.25118864,1,70 } },{ "adjust_stand_to_left_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_left_prone",0.25118864,1,70 } },{ "adjust_stand_to_right_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_right_prone",0.25118864,1,70 } },{ "adjust_left_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_left_prone_to_stand",0.25118864,1,70 } },{ "adjust_right_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_right_prone_to_stand",0.25118864,1,70 } },{ "\A3\sounds_f\characters\footsteps\wood_walk_int_1",0.5011872,0.7,70 },{ "\A3\sounds_f\characters\footsteps\wood_walk_int_2",0.5011872,0.7,70 },{ "\A3\sounds_f\characters\footsteps\wood_walk_int_3",0.5011872,0.7,70 },{ "\A3\sounds_f\characters\footsteps\wood_walk_int_4",0.5011872,0.7,70 },{ "\A3\sounds_f\characters\footsteps\wood_walk_int_5",0.5011872,0.7,70 },{ "\A3\sounds_f\characters\footsteps\wood_walk_int_6",0.5011872,0.7,70 },{ "\A3\sounds_f\characters\footsteps\wood_walk_int_7",0.5011872,0.7,70 },{ "\A3\sounds_f\characters\footsteps\wood_walk_int_8",0.5011872,0.7,70 },{ "run",{ "\A3\sounds_f\characters\footsteps\wood_run_int_1",0.5011872,0.7,70 } },{ "run",{ "\A3\sounds_f\characters\footsteps\wood_run_int_2",0.5011872,0.7,70 } },{ "run",{ "\A3\sounds_f\characters\footsteps\wood_run_int_3",0.5011872,0.7,70 } },{ "run",{ "\A3\sounds_f\characters\footsteps\wood_run_int_4",0.5011872,0.7,70 } },{ "run",{ "\A3\sounds_f\characters\footsteps\wood_run_int_5",0.5011872,0.7,70 } },{ "run",{ "\A3\sounds_f\characters\footsteps\wood_run_int_6",0.5011872,0.7,70 } },{ "run",{ "\A3\sounds_f\characters\footsteps\wood_run_int_7",0.5011872,0.7,70 } },{ "run",{ "\A3\sounds_f\characters\footsteps\wood_run_int_8",0.5011872,0.7,70 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\wood_walk_int_1",0.5011872,0.7,70 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\wood_walk_int_2",0.5011872,0.7,70 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\wood_walk_int_3",0.5011872,0.7,70 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\wood_walk_int_4",0.5011872,0.7,70 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\wood_walk_int_5",0.5011872,0.7,70 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\wood_walk_int_6",0.5011872,0.7,70 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\wood_walk_int_7",0.5011872,0.7,70 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\wood_walk_int_8",0.5011872,0.7,70 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\wood_sprint_int_1",0.5011872,0.7,70 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\wood_sprint_int_2",0.5011872,0.7,70 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\wood_sprint_int_3",0.5011872,0.7,70 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\wood_sprint_int_4",0.5011872,0.7,70 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\wood_sprint_int_5",0.5011872,0.7,70 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\wood_sprint_int_6",0.5011872,0.7,70 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\wood_sprint_int_7",0.5011872,0.7,70 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\wood_sprint_int_8",0.5011872,0.7,70 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_1",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_2",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_3",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_4",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_5",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_6",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_7",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_8",0.19952624,1,50 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_wood_1",0.5011872,1,70 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_wood_2",0.5011872,1,70 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_wood_3",0.5011872,1,70 } },{ "swim",{ "A3\Sounds_F\characters\movements\plavani1",0.5011872,1,70 } },{ "swim",{ "A3\Sounds_F\characters\movements\plavani2",0.5011872,1,70 } },{ "swim",{ "A3\Sounds_F\characters\movements\plavani3",0.5011872,1,70 } },{ "Acts_carFixingWheel",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_carFixingWheel",0.56234133,1,70 } },{ "Acts_PercMwlkSlowWrflDf",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_PercMwlkSlowWrflDf",0.56234133,1,70 } },{ "Acts_PercMwlkSlowWrflDf2",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_PercMwlkSlowWrflDf2",0.56234133,1,70 } },{ "Acts_SittingJumpingSaluting_out",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_SittingJumpingSaluting_out",0.56234133,1,70 } },{ "Acts_WalkingChecking",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WalkingChecking",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle02",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_CrouchingFiringLeftRifle02",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle03",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_CrouchingFiringLeftRifle03",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle04",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_CrouchingFiringLeftRifle04",0.56234133,1,70 } },{ "Acts_HUBABriefing",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_HUBABriefing",0.56234133,1,70 } },{ "Acts_PointingLeftUnarmed",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_PointingLeftUnarmed",0.56234133,1,70 } },{ "Acts_SittingJumpingSaluting_in",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_SittingJumpingSaluting_in",0.56234133,1,70 } },{ "Acts_StandingSpeakingUnarmed",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_StandingSpeakingUnarmed",0.56234133,1,70 } },{ "Acts_TreatingWounded_in",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_TreatingWounded_in",0.56234133,1,70 } },{ "Acts_TreatingWounded_out",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_TreatingWounded_out",0.56234133,1,70 } },{ "Acts_UnconsciousStandUp_part1",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_UnconsciousStandUp_part1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_1",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_1b",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_1b",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_2",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_3",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_4",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_5",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_6",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_2",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_3",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_4",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_5",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_6",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_2",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_3",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_4",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_5",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_6",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_PlayerWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_PlayerWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_2",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_PlayerWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_3",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_PlayerWalk_3",0.56234133,1,70 } }};
			concrete_int[] = {{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.25118864,1,70 } },{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.25118864,1,70 } },{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.25118864,1,70 } },{ "adjust_stand_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel1",0.25118864,1,70 } },{ "adjust_stand_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel2",0.25118864,1,70 } },{ "adjust_kneel_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand1",0.25118864,1,70 } },{ "adjust_kneel_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand2",0.25118864,1,70 } },{ "adjust_stand_to_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_prone",0.25118864,1,70 } },{ "adjust_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_to_stand",0.25118864,1,70 } },{ "adjust_prone_up",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_up",0.25118864,1,70 } },{ "adjust_prone_up_back",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_up_back",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.25118864,1,70 } },{ "adjust_prone_left",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_left",0.25118864,1,70 } },{ "adjust_prone_right",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_right",0.25118864,1,70 } },{ "adjust_kneel_to_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_prone",0.25118864,1,70 } },{ "adjust_prone_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_to_kneel",0.25118864,1,70 } },{ "adjust_stand_to_left_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_left_prone",0.25118864,1,70 } },{ "adjust_stand_to_right_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_right_prone",0.25118864,1,70 } },{ "adjust_left_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_left_prone_to_stand",0.25118864,1,70 } },{ "adjust_right_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_right_prone_to_stand",0.25118864,1,70 } },{ "\A3\sounds_f\characters\footsteps\concrete_int_walk_1",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\concrete_int_walk_2",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\concrete_int_walk_3",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\concrete_int_walk_4",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\concrete_int_walk_5",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\concrete_int_walk_6",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\concrete_int_walk_7",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\concrete_int_walk_8",0.5011872,1,100 },{ "run",{ "\A3\sounds_f\characters\footsteps\concrete_int_run_1",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\concrete_int_run_2",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\concrete_int_run_3",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\concrete_int_run_4",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\concrete_int_run_5",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\concrete_int_run_6",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\concrete_int_run_7",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\concrete_int_run_8",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\concrete_int_walk_1",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\concrete_int_walk_2",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\concrete_int_walk_3",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\concrete_int_walk_4",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\concrete_int_walk_5",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\concrete_int_walk_6",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\concrete_int_walk_7",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\concrete_int_walk_8",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\concrete_int_sprint_1",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\concrete_int_sprint_2",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\concrete_int_sprint_3",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\concrete_int_sprint_4",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\concrete_int_sprint_5",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\concrete_int_sprint_6",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\concrete_int_sprint_7",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\concrete_int_sprint_8",0.5011872,1,100 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_1",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_2",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_3",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_4",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_5",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_6",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_7",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_8",0.19952624,1,50 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_concrete_1",0.5011872,1,70 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_concrete_2",0.5011872,1,70 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_concrete_3",0.5011872,1,70 } },{ "swim",{ "A3\Sounds_F\characters\movements\plavani1",0.5011872,1,70 } },{ "swim",{ "A3\Sounds_F\characters\movements\plavani2",0.5011872,1,70 } },{ "swim",{ "A3\Sounds_F\characters\movements\plavani3",0.5011872,1,70 } },{ "Acts_carFixingWheel",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_carFixingWheel",0.56234133,1,70 } },{ "Acts_PercMwlkSlowWrflDf",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_PercMwlkSlowWrflDf",0.56234133,1,70 } },{ "Acts_PercMwlkSlowWrflDf2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_PercMwlkSlowWrflDf2",0.56234133,1,70 } },{ "Acts_SittingJumpingSaluting_out",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_SittingJumpingSaluting_out",0.56234133,1,70 } },{ "Acts_WalkingChecking",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WalkingChecking",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle02",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle02",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle03",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle03",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle04",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle04",0.56234133,1,70 } },{ "Acts_HUBABriefing",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_HUBABriefing",0.56234133,1,70 } },{ "Acts_PointingLeftUnarmed",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_PointingLeftUnarmed",0.56234133,1,70 } },{ "Acts_SittingJumpingSaluting_in",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_SittingJumpingSaluting_in",0.56234133,1,70 } },{ "Acts_StandingSpeakingUnarmed",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_StandingSpeakingUnarmed",0.56234133,1,70 } },{ "Acts_TreatingWounded_in",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_TreatingWounded_in",0.56234133,1,70 } },{ "Acts_TreatingWounded_out",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_TreatingWounded_out",0.56234133,1,70 } },{ "Acts_UnconsciousStandUp_part1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_UnconsciousStandUp_part1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_1b",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_1b",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_3",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_4",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_5",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_6",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_3",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_4",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_5",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_6",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_3",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_4",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_5",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_6",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_3",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_3",0.56234133,1,70 } }};
			concrete[] = {{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.25118864,1,70 } },{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.25118864,1,70 } },{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.25118864,1,70 } },{ "adjust_stand_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel1",0.25118864,1,70 } },{ "adjust_stand_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel2",0.25118864,1,70 } },{ "adjust_kneel_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand1",0.25118864,1,70 } },{ "adjust_kneel_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand2",0.25118864,1,70 } },{ "adjust_stand_to_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_prone",0.25118864,1,70 } },{ "adjust_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_to_stand",0.25118864,1,70 } },{ "adjust_prone_up",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_up",0.25118864,1,70 } },{ "adjust_prone_up_back",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_up_back",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.25118864,1,70 } },{ "adjust_prone_left",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_left",0.25118864,1,70 } },{ "adjust_prone_right",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_right",0.25118864,1,70 } },{ "adjust_kneel_to_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_prone",0.25118864,1,70 } },{ "adjust_prone_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_to_kneel",0.25118864,1,70 } },{ "adjust_stand_to_left_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_left_prone",0.25118864,1,70 } },{ "adjust_stand_to_right_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_right_prone",0.25118864,1,70 } },{ "adjust_left_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_left_prone_to_stand",0.25118864,1,70 } },{ "adjust_right_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_right_prone_to_stand",0.25118864,1,70 } },{ "\A3\sounds_f\characters\footsteps\concrete_walk_1",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\concrete_walk_2",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\concrete_walk_3",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\concrete_walk_4",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\concrete_walk_5",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\concrete_walk_6",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\concrete_walk_7",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\concrete_walk_8",0.5011872,1,100 },{ "run",{ "\A3\sounds_f\characters\footsteps\concrete_run_1",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\concrete_run_2",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\concrete_run_3",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\concrete_run_4",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\concrete_run_5",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\concrete_run_6",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\concrete_run_7",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\concrete_run_8",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\concrete_walk_1",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\concrete_walk_2",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\concrete_walk_3",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\concrete_walk_4",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\concrete_walk_5",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\concrete_walk_6",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\concrete_walk_7",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\concrete_walk_8",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\concrete_sprint_1",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\concrete_sprint_2",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\concrete_sprint_3",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\concrete_sprint_4",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\concrete_sprint_5",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\concrete_sprint_6",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\concrete_sprint_7",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\concrete_sprint_8",0.5011872,1,100 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_1",0.19952624,1,40 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_2",0.19952624,1,40 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_3",0.19952624,1,40 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_4",0.19952624,1,40 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_5",0.19952624,1,40 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_6",0.19952624,1,40 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_7",0.19952624,1,40 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_8",0.19952624,1,40 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_concrete_1",0.5011872,1,70 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_concrete_2",0.5011872,1,70 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_concrete_3",0.5011872,1,70 } },{ "swim",{ "A3\Sounds_F\characters\movements\plavani1",0.5011872,1,70 } },{ "swim",{ "A3\Sounds_F\characters\movements\plavani2",0.5011872,1,70 } },{ "swim",{ "A3\Sounds_F\characters\movements\plavani3",0.5011872,1,70 } },{ "Acts_carFixingWheel",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_carFixingWheel",0.56234133,1,70 } },{ "Acts_PercMwlkSlowWrflDf",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_PercMwlkSlowWrflDf",0.56234133,1,70 } },{ "Acts_PercMwlkSlowWrflDf2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_PercMwlkSlowWrflDf2",0.56234133,1,70 } },{ "Acts_SittingJumpingSaluting_out",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_SittingJumpingSaluting_out",0.56234133,1,70 } },{ "Acts_WalkingChecking",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WalkingChecking",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle02",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle02",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle03",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle03",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle04",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle04",0.56234133,1,70 } },{ "Acts_HUBABriefing",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_HUBABriefing",0.56234133,1,70 } },{ "Acts_PointingLeftUnarmed",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_PointingLeftUnarmed",0.56234133,1,70 } },{ "Acts_SittingJumpingSaluting_in",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_SittingJumpingSaluting_in",0.56234133,1,70 } },{ "Acts_StandingSpeakingUnarmed",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_StandingSpeakingUnarmed",0.56234133,1,70 } },{ "Acts_TreatingWounded_in",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_TreatingWounded_in",0.56234133,1,70 } },{ "Acts_TreatingWounded_out",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_TreatingWounded_out",0.56234133,1,70 } },{ "Acts_UnconsciousStandUp_part1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_UnconsciousStandUp_part1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_1b",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_1b",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_3",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_4",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_5",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_6",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_3",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_4",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_5",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_6",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_3",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_4",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_5",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_6",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_3",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_3",0.56234133,1,70 } }};
			metal[] = {{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.25118864,1,70 } },{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.25118864,1,70 } },{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.25118864,1,70 } },{ "adjust_stand_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel1",0.25118864,1,70 } },{ "adjust_stand_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel2",0.25118864,1,70 } },{ "adjust_kneel_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand1",0.25118864,1,70 } },{ "adjust_kneel_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand2",0.25118864,1,70 } },{ "adjust_stand_to_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_prone",0.25118864,1,70 } },{ "adjust_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_to_stand",0.25118864,1,70 } },{ "adjust_prone_up",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_up",0.25118864,1,70 } },{ "adjust_prone_up_back",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_up_back",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.25118864,1,70 } },{ "adjust_prone_left",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_left",0.25118864,1,70 } },{ "adjust_prone_right",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_right",0.25118864,1,70 } },{ "adjust_kneel_to_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_prone",0.25118864,1,70 } },{ "adjust_prone_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_to_kneel",0.25118864,1,70 } },{ "adjust_stand_to_left_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_left_prone",0.25118864,1,70 } },{ "adjust_stand_to_right_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_right_prone",0.25118864,1,70 } },{ "adjust_left_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_left_prone_to_stand",0.25118864,1,70 } },{ "adjust_right_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_right_prone_to_stand",0.25118864,1,70 } },{ "\A3\sounds_f\characters\footsteps\metal_walk_1",0.5011872,1,120 },{ "\A3\sounds_f\characters\footsteps\metal_walk_2",0.5011872,1,120 },{ "\A3\sounds_f\characters\footsteps\metal_walk_3",0.5011872,1,120 },{ "\A3\sounds_f\characters\footsteps\metal_walk_4",0.5011872,1,120 },{ "\A3\sounds_f\characters\footsteps\metal_walk_5",0.5011872,1,120 },{ "\A3\sounds_f\characters\footsteps\metal_walk_6",0.5011872,1,120 },{ "\A3\sounds_f\characters\footsteps\metal_walk_7",0.5011872,1,120 },{ "\A3\sounds_f\characters\footsteps\metal_walk_8",0.5011872,1,120 },{ "run",{ "\A3\sounds_f\characters\footsteps\metal_run_1",0.5011872,1,120 } },{ "run",{ "\A3\sounds_f\characters\footsteps\metal_run_2",0.5011872,1,120 } },{ "run",{ "\A3\sounds_f\characters\footsteps\metal_run_3",0.5011872,1,120 } },{ "run",{ "\A3\sounds_f\characters\footsteps\metal_run_4",0.5011872,1,120 } },{ "run",{ "\A3\sounds_f\characters\footsteps\metal_run_5",0.5011872,1,120 } },{ "run",{ "\A3\sounds_f\characters\footsteps\metal_run_6",0.5011872,1,120 } },{ "run",{ "\A3\sounds_f\characters\footsteps\metal_run_7",0.5011872,1,120 } },{ "run",{ "\A3\sounds_f\characters\footsteps\metal_run_8",0.5011872,1,120 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\metal_walk_1",0.5011872,1,120 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\metal_walk_2",0.5011872,1,120 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\metal_walk_3",0.5011872,1,120 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\metal_walk_4",0.5011872,1,120 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\metal_walk_5",0.5011872,1,120 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\metal_walk_6",0.5011872,1,120 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\metal_walk_7",0.5011872,1,120 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\metal_walk_8",0.5011872,1,120 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\metal_sprint_1",0.5011872,1,120 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\metal_sprint_2",0.5011872,1,120 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\metal_sprint_3",0.5011872,1,120 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\metal_sprint_4",0.5011872,1,120 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\metal_sprint_5",0.5011872,1,120 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\metal_sprint_6",0.5011872,1,120 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\metal_sprint_7",0.5011872,1,120 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\metal_sprint_8",0.5011872,1,120 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_1",0.19952624,1,40 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_2",0.19952624,1,40 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_3",0.19952624,1,40 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_4",0.19952624,1,40 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_5",0.19952624,1,40 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_6",0.19952624,1,40 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_7",0.19952624,1,40 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_8",0.19952624,1,40 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_metal_1",0.5011872,1,70 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_metal_2",0.5011872,1,70 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_metal_3",0.5011872,1,70 } },{ "swim",{ "A3\Sounds_F\characters\movements\plavani1",0.5011872,1,70 } },{ "swim",{ "A3\Sounds_F\characters\movements\plavani2",0.5011872,1,70 } },{ "swim",{ "A3\Sounds_F\characters\movements\plavani3",0.5011872,1,70 } },{ "Acts_carFixingWheel",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_carFixingWheel",0.56234133,1,70 } },{ "Acts_PercMwlkSlowWrflDf",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_PercMwlkSlowWrflDf",0.56234133,1,70 } },{ "Acts_PercMwlkSlowWrflDf2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_PercMwlkSlowWrflDf2",0.56234133,1,70 } },{ "Acts_SittingJumpingSaluting_out",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_SittingJumpingSaluting_out",0.56234133,1,70 } },{ "Acts_WalkingChecking",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WalkingChecking",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle02",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle02",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle03",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle03",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle04",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle04",0.56234133,1,70 } },{ "Acts_HUBABriefing",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_HUBABriefing",0.56234133,1,70 } },{ "Acts_PointingLeftUnarmed",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_PointingLeftUnarmed",0.56234133,1,70 } },{ "Acts_SittingJumpingSaluting_in",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_SittingJumpingSaluting_in",0.56234133,1,70 } },{ "Acts_StandingSpeakingUnarmed",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_StandingSpeakingUnarmed",0.56234133,1,70 } },{ "Acts_TreatingWounded_in",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_TreatingWounded_in",0.56234133,1,70 } },{ "Acts_TreatingWounded_out",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_TreatingWounded_out",0.56234133,1,70 } },{ "Acts_UnconsciousStandUp_part1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_UnconsciousStandUp_part1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_1b",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_1b",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_3",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_4",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_5",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_6",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_3",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_4",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_5",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_6",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_3",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_4",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_5",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_6",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_3",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_3",0.56234133,1,70 } }};
			metal_int[] = {{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.25118864,1,70 } },{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.25118864,1,70 } },{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.25118864,1,70 } },{ "adjust_stand_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel1",0.25118864,1,70 } },{ "adjust_stand_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel2",0.25118864,1,70 } },{ "adjust_kneel_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand1",0.25118864,1,70 } },{ "adjust_kneel_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand2",0.25118864,1,70 } },{ "adjust_stand_to_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_prone",0.25118864,1,70 } },{ "adjust_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_to_stand",0.25118864,1,70 } },{ "adjust_prone_up",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_up",0.25118864,1,70 } },{ "adjust_prone_up_back",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_up_back",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.25118864,1,70 } },{ "adjust_prone_left",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_left",0.25118864,1,70 } },{ "adjust_prone_right",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_right",0.25118864,1,70 } },{ "adjust_kneel_to_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_prone",0.25118864,1,70 } },{ "adjust_prone_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_to_kneel",0.25118864,1,70 } },{ "adjust_stand_to_left_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_left_prone",0.25118864,1,70 } },{ "adjust_stand_to_right_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_right_prone",0.25118864,1,70 } },{ "adjust_left_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_left_prone_to_stand",0.25118864,1,70 } },{ "adjust_right_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_right_prone_to_stand",0.25118864,1,70 } },{ "\A3\sounds_f\characters\footsteps\metal_int_walk_1",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\metal_int_walk_2",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\metal_int_walk_3",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\metal_int_walk_4",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\metal_int_walk_5",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\metal_int_walk_6",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\metal_int_walk_7",0.5011872,1,100 },{ "\A3\sounds_f\characters\footsteps\metal_int_walk_8",0.5011872,1,100 },{ "run",{ "\A3\sounds_f\characters\footsteps\metal_int_run_1",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\metal_int_run_2",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\metal_int_run_3",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\metal_int_run_4",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\metal_int_run_5",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\metal_int_run_6",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\metal_int_run_7",0.5011872,1,100 } },{ "run",{ "\A3\sounds_f\characters\footsteps\metal_int_run_8",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\metal_int_walk_1",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\metal_int_walk_2",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\metal_int_walk_3",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\metal_int_walk_4",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\metal_int_walk_5",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\metal_int_walk_6",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\metal_int_walk_7",0.5011872,1,100 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\metal_int_walk_8",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\metal_int_sprint_1",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\metal_int_sprint_2",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\metal_int_sprint_3",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\metal_int_sprint_4",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\metal_int_sprint_5",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\metal_int_sprint_6",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\metal_int_sprint_7",0.5011872,1,100 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\metal_int_sprint_8",0.5011872,1,100 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_1",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_2",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_3",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_4",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_5",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_6",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_7",0.19952624,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_8",0.19952624,1,50 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_metal_1",0.5011872,1,70 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_metal_2",0.5011872,1,70 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_metal_3",0.5011872,1,70 } },{ "swim",{ "A3\Sounds_F\characters\movements\plavani1",0.5011872,1,70 } },{ "swim",{ "A3\Sounds_F\characters\movements\plavani2",0.5011872,1,70 } },{ "swim",{ "A3\Sounds_F\characters\movements\plavani3",0.5011872,1,70 } },{ "Acts_carFixingWheel",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_carFixingWheel",0.56234133,1,70 } },{ "Acts_PercMwlkSlowWrflDf",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_PercMwlkSlowWrflDf",0.56234133,1,70 } },{ "Acts_PercMwlkSlowWrflDf2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_PercMwlkSlowWrflDf2",0.56234133,1,70 } },{ "Acts_SittingJumpingSaluting_out",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_SittingJumpingSaluting_out",0.56234133,1,70 } },{ "Acts_WalkingChecking",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WalkingChecking",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle02",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle02",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle03",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle03",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle04",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle04",0.56234133,1,70 } },{ "Acts_HUBABriefing",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_HUBABriefing",0.56234133,1,70 } },{ "Acts_PointingLeftUnarmed",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_PointingLeftUnarmed",0.56234133,1,70 } },{ "Acts_SittingJumpingSaluting_in",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_SittingJumpingSaluting_in",0.56234133,1,70 } },{ "Acts_StandingSpeakingUnarmed",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_StandingSpeakingUnarmed",0.56234133,1,70 } },{ "Acts_TreatingWounded_in",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_TreatingWounded_in",0.56234133,1,70 } },{ "Acts_TreatingWounded_out",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_TreatingWounded_out",0.56234133,1,70 } },{ "Acts_UnconsciousStandUp_part1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_UnconsciousStandUp_part1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_1b",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_1b",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_3",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_4",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_5",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_6",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_3",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_4",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_5",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_6",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_3",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_4",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_5",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_6",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_3",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_3",0.56234133,1,70 } }};
			tiles_int[] = {{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.25118864,1,70 } },{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.25118864,1,70 } },{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.25118864,1,70 } },{ "adjust_stand_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel1",0.25118864,1,70 } },{ "adjust_stand_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel2",0.25118864,1,70 } },{ "adjust_kneel_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand1",0.25118864,1,70 } },{ "adjust_kneel_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand2",0.25118864,1,70 } },{ "adjust_stand_to_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_prone",0.25118864,1,70 } },{ "adjust_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_to_stand",0.25118864,1,70 } },{ "adjust_prone_up",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_up",0.25118864,1,70 } },{ "adjust_prone_up_back",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_up_back",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.25118864,1,70 } },{ "adjust_prone_left",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_left",0.25118864,1,70 } },{ "adjust_prone_right",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_right",0.25118864,1,70 } },{ "adjust_kneel_to_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_prone",0.25118864,1,70 } },{ "adjust_prone_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_to_kneel",0.25118864,1,70 } },{ "adjust_stand_to_left_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_left_prone",0.25118864,1,70 } },{ "adjust_stand_to_right_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_right_prone",0.25118864,1,70 } },{ "adjust_left_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_left_prone_to_stand",0.25118864,1,70 } },{ "adjust_right_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_right_prone_to_stand",0.25118864,1,70 } },{ "\A3\sounds_f\characters\footsteps\tiles_int_walk_1",0.5011872,1,70 },{ "\A3\sounds_f\characters\footsteps\tiles_int_walk_2",0.5011872,1,70 },{ "\A3\sounds_f\characters\footsteps\tiles_int_walk_3",0.5011872,1,70 },{ "\A3\sounds_f\characters\footsteps\tiles_int_walk_4",0.5011872,1,70 },{ "\A3\sounds_f\characters\footsteps\tiles_int_walk_5",0.5011872,1,70 },{ "\A3\sounds_f\characters\footsteps\tiles_int_walk_6",0.5011872,1,70 },{ "\A3\sounds_f\characters\footsteps\tiles_int_walk_7",0.5011872,1,70 },{ "\A3\sounds_f\characters\footsteps\tiles_int_walk_8",0.5011872,1,70 },{ "run",{ "\A3\sounds_f\characters\footsteps\tiles_int_run_1",0.5011872,1,70 } },{ "run",{ "\A3\sounds_f\characters\footsteps\tiles_int_run_2",0.5011872,1,70 } },{ "run",{ "\A3\sounds_f\characters\footsteps\tiles_int_run_3",0.5011872,1,70 } },{ "run",{ "\A3\sounds_f\characters\footsteps\tiles_int_run_4",0.5011872,1,70 } },{ "run",{ "\A3\sounds_f\characters\footsteps\tiles_int_run_5",0.5011872,1,70 } },{ "run",{ "\A3\sounds_f\characters\footsteps\tiles_int_run_6",0.5011872,1,70 } },{ "run",{ "\A3\sounds_f\characters\footsteps\tiles_int_run_7",0.5011872,1,70 } },{ "run",{ "\A3\sounds_f\characters\footsteps\tiles_int_run_8",0.5011872,1,70 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\tiles_int_walk_1",0.5011872,1,70 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\tiles_int_walk_2",0.5011872,1,70 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\tiles_int_walk_3",0.5011872,1,70 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\tiles_int_walk_4",0.5011872,1,70 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\tiles_int_walk_5",0.5011872,1,70 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\tiles_int_walk_6",0.5011872,1,70 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\tiles_int_walk_7",0.5011872,1,70 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\tiles_int_walk_8",0.5011872,1,70 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\tiles_int_sprint_1",0.5011872,1,70 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\tiles_int_sprint_2",0.5011872,1,70 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\tiles_int_sprint_3",0.5011872,1,70 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\tiles_int_sprint_4",0.5011872,1,70 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\tiles_int_sprint_5",0.5011872,1,70 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\tiles_int_sprint_6",0.5011872,1,70 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\tiles_int_sprint_7",0.5011872,1,70 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\tiles_int_sprint_8",0.5011872,1,70 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_1",0.17782794,1,40 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_2",0.17782794,1,40 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_3",0.17782794,1,40 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_4",0.17782794,1,40 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_5",0.17782794,1,40 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_6",0.17782794,1,40 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_7",0.17782794,1,40 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_8",0.17782794,1,40 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_concrete_1",0.5011872,1,70 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_concrete_2",0.5011872,1,70 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_concrete_3",0.5011872,1,70 } },{ "swim",{ "A3\Sounds_F\characters\movements\plavani1",0.5011872,1,70 } },{ "swim",{ "A3\Sounds_F\characters\movements\plavani2",0.5011872,1,70 } },{ "swim",{ "A3\Sounds_F\characters\movements\plavani3",0.5011872,1,70 } },{ "Acts_carFixingWheel",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_carFixingWheel",0.56234133,1,70 } },{ "Acts_PercMwlkSlowWrflDf",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_PercMwlkSlowWrflDf",0.56234133,1,70 } },{ "Acts_PercMwlkSlowWrflDf2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_PercMwlkSlowWrflDf2",0.56234133,1,70 } },{ "Acts_SittingJumpingSaluting_out",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_SittingJumpingSaluting_out",0.56234133,1,70 } },{ "Acts_WalkingChecking",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WalkingChecking",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle02",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle02",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle03",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle03",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle04",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle04",0.56234133,1,70 } },{ "Acts_HUBABriefing",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_HUBABriefing",0.56234133,1,70 } },{ "Acts_PointingLeftUnarmed",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_PointingLeftUnarmed",0.56234133,1,70 } },{ "Acts_SittingJumpingSaluting_in",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_SittingJumpingSaluting_in",0.56234133,1,70 } },{ "Acts_StandingSpeakingUnarmed",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_StandingSpeakingUnarmed",0.56234133,1,70 } },{ "Acts_TreatingWounded_in",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_TreatingWounded_in",0.56234133,1,70 } },{ "Acts_TreatingWounded_out",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_TreatingWounded_out",0.56234133,1,70 } },{ "Acts_UnconsciousStandUp_part1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_UnconsciousStandUp_part1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_1b",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_1b",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_3",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_4",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_5",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_6",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_3",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_4",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_5",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_6",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_3",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_4",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_5",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_6",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_3",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_3",0.56234133,1,70 } }};
			dirt[] = {{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.25118864,1,70 } },{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.25118864,1,70 } },{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.25118864,1,70 } },{ "adjust_stand_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel1",0.25118864,1,70 } },{ "adjust_stand_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel2",0.25118864,1,70 } },{ "adjust_kneel_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand1",0.25118864,1,70 } },{ "adjust_kneel_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand2",0.25118864,1,70 } },{ "adjust_stand_to_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_prone",0.25118864,1,70 } },{ "adjust_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_to_stand",0.25118864,1,70 } },{ "adjust_prone_up",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_up",0.25118864,1,70 } },{ "adjust_prone_up_back",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_up_back",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.25118864,1,70 } },{ "adjust_prone_left",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_left",0.25118864,1,70 } },{ "adjust_prone_right",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_right",0.25118864,1,70 } },{ "adjust_kneel_to_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_prone",0.25118864,1,70 } },{ "adjust_prone_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_to_kneel",0.25118864,1,70 } },{ "adjust_stand_to_left_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_left_prone",0.25118864,1,70 } },{ "adjust_stand_to_right_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_right_prone",0.25118864,1,70 } },{ "adjust_left_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_left_prone_to_stand",0.25118864,1,70 } },{ "adjust_right_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_right_prone_to_stand",0.25118864,1,70 } },{ "\A3\sounds_f\characters\footsteps\dirt_walk_new_1",0.5011872,1,70 },{ "\A3\sounds_f\characters\footsteps\dirt_walk_new_2",0.5011872,1,70 },{ "\A3\sounds_f\characters\footsteps\dirt_walk_new_3",0.5011872,1,70 },{ "\A3\sounds_f\characters\footsteps\dirt_walk_new_4",0.5011872,1,70 },{ "\A3\sounds_f\characters\footsteps\dirt_walk_new_5",0.5011872,1,70 },{ "\A3\sounds_f\characters\footsteps\dirt_walk_new_6",0.5011872,1,70 },{ "\A3\sounds_f\characters\footsteps\dirt_walk_new_7",0.5011872,1,70 },{ "\A3\sounds_f\characters\footsteps\dirt_walk_new_8",0.5011872,1,70 },{ "run",{ "\A3\sounds_f\characters\footsteps\dirt_run_new_1",0.5011872,1,70 } },{ "run",{ "\A3\sounds_f\characters\footsteps\dirt_run_new_2",0.5011872,1,70 } },{ "run",{ "\A3\sounds_f\characters\footsteps\dirt_run_new_3",0.5011872,1,70 } },{ "run",{ "\A3\sounds_f\characters\footsteps\dirt_run_new_4",0.5011872,1,70 } },{ "run",{ "\A3\sounds_f\characters\footsteps\dirt_run_new_5",0.5011872,1,70 } },{ "run",{ "\A3\sounds_f\characters\footsteps\dirt_run_new_6",0.5011872,1,70 } },{ "run",{ "\A3\sounds_f\characters\footsteps\dirt_run_new_7",0.5011872,1,70 } },{ "run",{ "\A3\sounds_f\characters\footsteps\dirt_run_new_8",0.5011872,1,70 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\dirt_walk_new_1",0.5011872,1,70 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\dirt_walk_new_2",0.5011872,1,70 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\dirt_walk_new_3",0.5011872,1,70 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\dirt_walk_new_4",0.5011872,1,70 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\dirt_walk_new_5",0.5011872,1,70 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\dirt_walk_new_6",0.5011872,1,70 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\dirt_walk_new_7",0.5011872,1,70 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\dirt_walk_new_8",0.5011872,1,70 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\dirt_sprint_new_1",0.5011872,1,70 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\dirt_sprint_new_2",0.5011872,1,70 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\dirt_sprint_new_3",0.5011872,1,70 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\dirt_sprint_new_4",0.5011872,1,70 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\dirt_sprint_new_5",0.5011872,1,70 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\dirt_sprint_new_6",0.5011872,1,70 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\dirt_sprint_new_7",0.5011872,1,70 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\dirt_sprint_new_8",0.5011872,1,70 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_dirt_1",0.17782794,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_dirt_2",0.17782794,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_dirt_3",0.17782794,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_dirt_4",0.17782794,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_dirt_5",0.17782794,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_dirt_6",0.17782794,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_dirt_7",0.17782794,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_dirt_8",0.17782794,1,50 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_dirt_1",0.5011872,1,70 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_dirt_2",0.5011872,1,70 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_dirt_3",0.5011872,1,70 } },{ "swim",{ "A3\Sounds_F\characters\movements\plavani1",0.5011872,1,70 } },{ "swim",{ "A3\Sounds_F\characters\movements\plavani2",0.5011872,1,70 } },{ "swim",{ "A3\Sounds_F\characters\movements\plavani3",0.5011872,1,70 } },{ "Acts_carFixingWheel",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_carFixingWheel",0.56234133,1,70 } },{ "Acts_PercMwlkSlowWrflDf",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_PercMwlkSlowWrflDf",0.56234133,1,70 } },{ "Acts_PercMwlkSlowWrflDf2",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_PercMwlkSlowWrflDf2",0.56234133,1,70 } },{ "Acts_SittingJumpingSaluting_out",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_SittingJumpingSaluting_out",0.56234133,1,70 } },{ "Acts_WalkingChecking",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WalkingChecking",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle02",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_CrouchingFiringLeftRifle02",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle03",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_CrouchingFiringLeftRifle03",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle04",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_CrouchingFiringLeftRifle04",0.56234133,1,70 } },{ "Acts_HUBABriefing",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_HUBABriefing",0.56234133,1,70 } },{ "Acts_PointingLeftUnarmed",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_PointingLeftUnarmed",0.56234133,1,70 } },{ "Acts_SittingJumpingSaluting_in",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_SittingJumpingSaluting_in",0.56234133,1,70 } },{ "Acts_StandingSpeakingUnarmed",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_StandingSpeakingUnarmed",0.56234133,1,70 } },{ "Acts_TreatingWounded_in",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_TreatingWounded_in",0.56234133,1,70 } },{ "Acts_TreatingWounded_out",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_TreatingWounded_out",0.56234133,1,70 } },{ "Acts_UnconsciousStandUp_part1",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_UnconsciousStandUp_part1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_1",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_1b",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_1b",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_2",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_3",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_4",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_5",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_6",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_AIWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_2",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_3",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_4",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_5",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_6",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB01_PlayerWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_2",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_3",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_4",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_5",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_6",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_AIWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_PlayerWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_PlayerWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_2",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_PlayerWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_3",{ "A3\Sounds_F\characters\cutscenes\dirt_Acts_WelcomeOnHUB02_PlayerWalk_3",0.56234133,1,70 } }};
			roof_tin[] = {{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.25118864,1,70 } },{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.25118864,1,70 } },{ "adjust_stand_side",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.25118864,1,70 } },{ "adjust_stand_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel1",0.25118864,1,70 } },{ "adjust_stand_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_kneel2",0.25118864,1,70 } },{ "adjust_kneel_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand1",0.25118864,1,70 } },{ "adjust_kneel_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_stand2",0.25118864,1,70 } },{ "adjust_stand_to_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_prone",0.25118864,1,70 } },{ "adjust_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_to_stand",0.25118864,1,70 } },{ "adjust_prone_up",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_up",0.25118864,1,70 } },{ "adjust_prone_up_back",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_up_back",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side1",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side2",0.25118864,1,70 } },{ "adjust_prone_down",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_side3",0.25118864,1,70 } },{ "adjust_prone_left",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_left",0.25118864,1,70 } },{ "adjust_prone_right",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_right",0.25118864,1,70 } },{ "adjust_kneel_to_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_kneel_to_prone",0.25118864,1,70 } },{ "adjust_prone_to_kneel",{ "\A3\sounds_f\characters\stances\concrete_adjust_prone_to_kneel",0.25118864,1,70 } },{ "adjust_stand_to_left_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_left_prone",0.25118864,1,70 } },{ "adjust_stand_to_right_prone",{ "\A3\sounds_f\characters\stances\concrete_adjust_stand_to_right_prone",0.25118864,1,70 } },{ "adjust_left_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_left_prone_to_stand",0.25118864,1,70 } },{ "adjust_right_prone_to_stand",{ "\A3\sounds_f\characters\stances\concrete_adjust_right_prone_to_stand",0.25118864,1,70 } },{ "\A3\sounds_f\characters\footsteps\roof_tin_walk_1",0.5011872,1,70 },{ "\A3\sounds_f\characters\footsteps\roof_tin_walk_2",0.5011872,1,70 },{ "\A3\sounds_f\characters\footsteps\roof_tin_walk_3",0.5011872,1,70 },{ "\A3\sounds_f\characters\footsteps\roof_tin_walk_4",0.5011872,1,70 },{ "\A3\sounds_f\characters\footsteps\roof_tin_walk_5",0.5011872,1,70 },{ "\A3\sounds_f\characters\footsteps\roof_tin_walk_6",0.5011872,1,70 },{ "\A3\sounds_f\characters\footsteps\roof_tin_walk_7",0.5011872,1,70 },{ "\A3\sounds_f\characters\footsteps\roof_tin_walk_8",0.5011872,1,70 },{ "run",{ "\A3\sounds_f\characters\footsteps\roof_tin_run_1",0.5011872,1,70 } },{ "run",{ "\A3\sounds_f\characters\footsteps\roof_tin_run_2",0.5011872,1,70 } },{ "run",{ "\A3\sounds_f\characters\footsteps\roof_tin_run_3",0.5011872,1,70 } },{ "run",{ "\A3\sounds_f\characters\footsteps\roof_tin_run_4",0.5011872,1,70 } },{ "run",{ "\A3\sounds_f\characters\footsteps\roof_tin_run_5",0.5011872,1,70 } },{ "run",{ "\A3\sounds_f\characters\footsteps\roof_tin_run_6",0.5011872,1,70 } },{ "run",{ "\A3\sounds_f\characters\footsteps\roof_tin_run_7",0.5011872,1,70 } },{ "run",{ "\A3\sounds_f\characters\footsteps\roof_tin_run_8",0.5011872,1,70 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\roof_tin_walk_1",0.0056234132,1,70 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\roof_tin_walk_2",0.0056234132,1,70 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\roof_tin_walk_3",0.0056234132,1,70 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\roof_tin_walk_4",0.0056234132,1,70 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\roof_tin_walk_5",0.0056234132,1,70 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\roof_tin_walk_6",0.0056234132,1,70 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\roof_tin_walk_7",0.0056234132,1,70 } },{ "walk",{ "\A3\sounds_f\characters\footsteps\roof_tin_walk_8",0.0056234132,1,70 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\roof_tin_sprint_1",0.5011872,1,70 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\roof_tin_sprint_2",0.5011872,1,70 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\roof_tin_sprint_3",0.5011872,1,70 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\roof_tin_sprint_4",0.5011872,1,70 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\roof_tin_sprint_5",0.5011872,1,70 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\roof_tin_sprint_6",0.5011872,1,70 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\roof_tin_sprint_7",0.5011872,1,70 } },{ "sprint",{ "\A3\sounds_f\characters\footsteps\roof_tin_sprint_8",0.5011872,1,70 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_1",0.17782794,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_2",0.17782794,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_3",0.17782794,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_4",0.17782794,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_5",0.17782794,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_6",0.17782794,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_7",0.17782794,1,50 } },{ "crawl",{ "\A3\sounds_f\characters\crawl\crawl_concrete_8",0.17782794,1,50 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_concrete_1",0.5011872,1,70 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_concrete_2",0.5011872,1,70 } },{ "bodyfall",{ "\A3\sounds_f\characters\movements\bodyfalls\bodyfall_concrete_3",0.5011872,1,70 } },{ "swim",{ "A3\Sounds_F\characters\movements\plavani1",0.5011872,1,70 } },{ "swim",{ "A3\Sounds_F\characters\movements\plavani2",0.5011872,1,70 } },{ "swim",{ "A3\Sounds_F\characters\movements\plavani3",0.5011872,1,70 } },{ "Acts_carFixingWheel",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_carFixingWheel",0.56234133,1,70 } },{ "Acts_PercMwlkSlowWrflDf",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_PercMwlkSlowWrflDf",0.56234133,1,70 } },{ "Acts_PercMwlkSlowWrflDf2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_PercMwlkSlowWrflDf2",0.56234133,1,70 } },{ "Acts_SittingJumpingSaluting_out",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_SittingJumpingSaluting_out",0.56234133,1,70 } },{ "Acts_WalkingChecking",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WalkingChecking",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle02",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle02",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle03",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle03",0.56234133,1,70 } },{ "Acts_CrouchingFiringLeftRifle04",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_CrouchingFiringLeftRifle04",0.56234133,1,70 } },{ "Acts_HUBABriefing",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_HUBABriefing",0.56234133,1,70 } },{ "Acts_PointingLeftUnarmed",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_PointingLeftUnarmed",0.56234133,1,70 } },{ "Acts_SittingJumpingSaluting_in",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_SittingJumpingSaluting_in",0.56234133,1,70 } },{ "Acts_StandingSpeakingUnarmed",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_StandingSpeakingUnarmed",0.56234133,1,70 } },{ "Acts_TreatingWounded_in",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_TreatingWounded_in",0.56234133,1,70 } },{ "Acts_TreatingWounded_out",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_TreatingWounded_out",0.56234133,1,70 } },{ "Acts_UnconsciousStandUp_part1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_UnconsciousStandUp_part1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_1b",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_1b",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_3",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_4",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_5",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_AIWalk_6",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_AIWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_3",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_4",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_5",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB01_PlayerWalk_6",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB01_PlayerWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_3",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_3",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_4",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_4",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_5",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_5",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_AIWalk_6",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_AIWalk_6",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_1",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_1",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_2",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_2",0.56234133,1,70 } },{ "Acts_WelcomeOnHUB02_PlayerWalk_3",{ "A3\Sounds_F\characters\cutscenes\concrete_Acts_WelcomeOnHUB02_PlayerWalk_3",0.56234133,1,70 } }};
		};

		weaponSlots = "1  +  4  + 12*  256  +  4096  +  2  + 8* 16  + 12*131072";
		fsmFormation = "Formation";
		leftArmToElbow[] = {"LeftArm",0.5,"LeftArmRoll",0};
		leftArmFromElbow[] = {"LeftForeArm",0,"LeftForeArmRoll",0.5};
		leftWrist = "LeftHand";
		leftShoulder = "LeftShoulder";
		leftHand[] = {"LeftHandThumb3","LeftHandThumb2","LeftHandThumb1","LeftHandIndex3","LeftHandIndex2","LeftHandIndex1","LeftHandMiddle3","LeftHandMiddle2","LeftHandMiddle1","LeftHandRing3","LeftHandRing2","LeftHandRing1","LeftHandRing","LeftHandPinky3","LeftHandPinky2","LeftHandPinky1"};
		leftArmPoints[] = {"LeftShoulder","lelbow","lelbow_axis","lwrist"};
		rightArmToElbow[] = {"rightArm",0.5,"rightArmRoll",0};
		rightArmFromElbow[] = {"rightForeArm",0,"rightForeArmRoll",0.5};
		rightWrist = "rightHand";
		rightShoulder = "rightShoulder";
		rightHand[] = {"rightHandThumb3","rightHandThumb2","rightHandThumb1","rightHandIndex3","rightHandIndex2","rightHandIndex1","rightHandMiddle3","rightHandMiddle2","rightHandMiddle1","rightHandRing3","rightHandRing2","rightHandRing1","rightHandRing","rightHandPinky3","rightHandPinky2","rightHandPinky1"};
		rightArmPoints[] = {"rightShoulder","relbow","relbow_axis","rwrist"};
		leftLegToKnee[] = {"LeftUpLeg",0.5,"LeftUpLegRoll",0};
		leftLegFromKnee[] = {"LeftLeg",0,"LeftLegRoll",0.5};
		leftHeel = "leftFoot";
		leftHip = "pelvis";
		leftFoot[] = {"LeftToeBase"};
		leftLegPoints[] = {"lfemur","lknee","lknee_axis","lankle"};
		rightLegToKnee[] = {"rightUpLeg",0.5,"rightUpLegRoll",0};
		rightLegFromKnee[] = {"rightLeg",0,"rightLegRoll",0.5};
		rightHeel = "rightFoot";
		rightHip = "pelvis";
		rightFoot[] = {"RightToeBase"};
		rightLegPoints[] = {"rfemur","rknee","rknee_axis","rankle"};
		launcherBone = "launcher";
		handGunBone = "RightHand";
		weaponBone = "weapon";
		impactEffectsSea = "ImpactEffectsSeaMen";
		AnimEffectShortExhaust = 0.12;
		AnimEffectShortRest = 0.04;
		canCarryBackPack = 1;
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
					slotType = 604;
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
		grenadeThrowDir[] = {0,0.2,1};
	};
	class Civilian2: CAManBase2
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
		class HitPoints: HitPoints
		{
			class HitHead: HitHead
			{
				armor = 1;
			};
			class HitBody: HitBody
			{
				armor = 2;
			};
			class HitHands: HitHands
			{
				armor = 2;
			};
			class HitLegs: HitLegs
			{
				armor = 2;
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

	class B_Soldier_base_F;
	class Epoch_Female_base_F : B_Soldier_base_F
	{
		identityTypes[] = { "Woman", "NoGlasses" };

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
			class HitHead
			{
				armor = 1;
				material = -1;
				name = "head";
				passThrough = 1;
				radius = 0.1;
				explosionShielding = 0.5;
				minimalHit = 0;
			};
			class HitBody
			{
				armor = 1;
				material = -1;
				name = "body";
				passThrough = 1;
				radius = 0.15;
				explosionShielding = 10;
				visual = "injury_body";
				minimalHit = 0;
			};
			class HitHands
			{
				armor = 1;
				material = -1;
				name = "hands";
				passThrough = 1;
				radius = 0.08;
				explosionShielding = 1;
				visual = "injury_hands";
				minimalHit = 0;
			};
			class HitLegs
			{
				armor = 1;
				material = -1;
				name = "legs";
				passThrough = 1;
				radius = 0.1;
				explosionShielding = 1;
				visual = "injury_legs";
				minimalHit = 0;
			};
		};
		armor = 2;
		armorStructural = 5;

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
		class HitPoints: HitPoints
		{
			class HitHead: HitHead
			{
				armor = 2;
			};
			class HitBody: HitBody
			{
				armor = 2;
			};
			class HitHands: HitHands
			{
				armor = 2;
			};
			class HitLegs: HitLegs
			{
				armor = 2;
			};
		};
		armor = 2;
		armorStructural = 5;

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
		class HitPoints: HitPoints
		{
			class HitHead: HitHead
			{
				armor = 1;
				passThrough = 1;
				explosionShielding = 0.5;
			};
			class HitBody: HitBody
			{
				armor = 6;
				passThrough = 0.5;
				explosionShielding = 1.5;
			};
			class HitHands: HitHands
			{
				armor = 8;
				passThrough = 0.5;
				explosionShielding = 0.8;
			};
			class HitLegs: HitLegs
			{
				armor = 8;
				passThrough = 0.5;
				explosionShielding = 0.8;
			};
		};
		armor = 2;
		armorStructural = 5;

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

	class O_Soldier_base_F;
	class Epoch_Man_base_F : O_Soldier_base_F
	{
		identityTypes[] = { "Kerry", "NoGlasses" };

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
			class HitHead
			{
				armor = 1;
				material = -1;
				name = "head";
				passThrough = 1;
				radius = 0.1;
				explosionShielding = 0.5;
				minimalHit = 0;
			};
			class HitBody
			{
				armor = 1;
				material = -1;
				name = "body";
				passThrough = 1;
				radius = 0.15;
				explosionShielding = 10;
				visual = "injury_body";
				minimalHit = 0;
			};
			class HitHands
			{
				armor = 1;
				material = -1;
				name = "hands";
				passThrough = 1;
				radius = 0.08;
				explosionShielding = 1;
				visual = "injury_hands";
				minimalHit = 0;
			};
			class HitLegs
			{
				armor = 1;
				material = -1;
				name = "legs";
				passThrough = 1;
				radius = 0.1;
				explosionShielding = 1;
				visual = "injury_legs";
				minimalHit = 0;
			};
		};
		armor = 2;
		armorStructural = 5;


	};
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
	class Epoch_Female_F: Epoch_Female_base_F
	{
		woman = 1;
		scope = 2;
		displayName = "Female";
		interactMode = 2;
	};
	class Epoch_Male_F: Epoch_Man_base_F
	{
		scope = 2;
		displayName = "Male";
		interactMode = 2;
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
	class House;
	class House_F: House
	{
		class DestructionEffects;
	};
	class House_Small_F;
	class Ruins_F;

	class PowerLines_base_F : House_F
	{
		mapSize = 2.35;
		author = "$STR_A3_Bohemia_Interactive";
		_generalMacro = "PowerLines_base_F";
		scope = 0;
		scopeCurator = 0;
		displayName = "";
		model = "\A3\Weapons_F\empty.p3d";
		vehicleClass = "Structures_Infrastructure";
		cost = 100;
		compatibleWires[] = {};
		class EventHandlers
		{
			killed = "if (isServer) then {this call compile preprocessFileLineNumbers ""\A3\Structures_F\Ind\PowerLines\Scripts\column_ruins.sqf""};";
		};
	};

	class PowerLines_Small_base_F : House_Small_F
	{
		mapSize = 2.79;
		author = "$STR_A3_Bohemia_Interactive";
		_generalMacro = "PowerLines_Small_base_F";
		scope = 0;
		scopeCurator = 0;
		displayName = "";
		model = "\A3\Weapons_F\empty.p3d";
		vehicleClass = "Structures_Infrastructure";
		compatibleWires[] = {};
		cost = 100;
		class EventHandlers
		{
			killed = "if (isServer) then {this call compile preprocessFileLineNumbers ""\A3\Structures_F\Ind\PowerLines\Scripts\column_ruins.sqf""};";
		};
	};

	class Land_Communication_anchor_F : House_F
	{
		mapSize = 9.73;
		author = "$STR_A3_Bohemia_Interactive";
		_generalMacro = "Land_Communication_anchor_F";
		scope = 1;
		scopeCurator = 2;
		displayName = "$STR_A3_CfgVehicles_Land_Communication_anchor_F0";
		model = "\A3\Structures_F\Ind\Transmitter_Tower\Communication_anchor_F.p3d";
		vehicleClass = "Structures_Infrastructure";
		class DestructionEffects
		{
			class DestroyPhase1
			{
				simulation = "destroy";
				type = "DelayedDestruction";
				lifeTime = 1;
				position = "";
				intensity = 1;
				interval = 1;
			};
		};
		class EventHandlers
		{
			killed = "if (isServer) then {this call compile preprocessFileLineNumbers ""\A3\Structures_F\Ind\Transmitter_Tower\Scripts\anchor_ruins.sqf""};";
		};
	};
	class Land_Communication_F : House_F
	{
		mapSize = 4.53;
		author = "$STR_A3_Bohemia_Interactive";
		_generalMacro = "Land_Communication_F";
		scope = 1;
		scopeCurator = 2;
		displayName = "$STR_A3_CfgVehicles_Land_Communication_F0";
		model = "\A3\Structures_F\Ind\Transmitter_Tower\Communication_F.p3d";
		vehicleClass = "Structures_Infrastructure";
		cost = 40000;
		class EventHandlers
		{
			killed = "if (isServer) then {this call compile preprocessFileLineNumbers ""\A3\Structures_F\Ind\Transmitter_Tower\Scripts\tower_ruins.sqf""};";
		};
	};

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
	/*
	class Sword_SIM_EPOCH: Constructions_modular_F
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets\models\sword.p3d";
		displayName = "Sword";
	};
	*/
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
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 3;
				condition = "(this animationPhase ""open_left"" < 0.5) && (this animationPhase ""lock_cGarage"" < 0.5)";
				statement = "this animate [""lock_cGarage"", 1]";
			};
			class Unlock_cGarage : Lock_cGarage
			{
				displayName = "Unlock";
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
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 3;
				condition = "!(call EPOCH_lockCheck) && (this animationPhase ""Open_Door"" == 0) && (this animationPhase ""lock_Door"" == 0)";
				statement = "this animate [""lock_Door"", 1]";
			};
			class Unlock_Door : Lock_Door
			{
				displayName = "Unlock";
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
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 3;
				condition = "!(call EPOCH_lockCheck) && (this animationPhase ""Open_Door"" == 0) && (this animationPhase ""lock_Door"" == 0)";
				statement = "this animate [""lock_Door"", 1]";
			};
			class Unlock_Door : Lock_Door
			{
				displayName = "Unlock";
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
		class UserActions
		{
			class MaintainIT
			{
				displayName = "Maintain";
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 10;
				condition = "damage this < 1";
				statement = "this call EPOCH_maintainIT";
			};
		};
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

	class Constructions_lockedstatic_F : NonStrategic
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
		bypassJammer = 1;
		limitNearby = 2;
		isSecureStorage = 1;
		returnOnPack[] = { { "ItemLockbox", 1 } };
		class UserActions
		{
			class Unlock
			{
				displayName = "Unlock";
				displayNameDefault = "<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 3;
				condition = "this getVariable [""EPOCH_Locked"",true]";
				statement = "EPOCH_lockStorage_PVS = [this,false,player,Epoch_personalToken]; publicVariableServer ""EPOCH_lockStorage_PVS""; [getpos this, 5, 5] call Epoch_gui3DCooldown;";
			};
			class Pack
			{
				displayName = "Pack";
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 3;
				condition = "this getVariable [""EPOCH_Locked"",true]";
				statement = "EPOCH_packStorage_PVS = [this,player,Epoch_personalToken]; publicVariableServer ""EPOCH_packStorage_PVS""; [getpos this, 5, 5] call Epoch_gui3DCooldown;";
			};
		};
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
		bypassJammer = 1;
		limitNearby = 2;
		isSecureStorage = 1;
		returnOnPack[] = { { "ItemSafe", 1 } };
		class UserActions
		{
			class Unlock
			{
				displayName = "Unlock";
				displayNameDefault = "<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 3;
				condition = "(this getVariable[""EPOCH_secStorParent"", objNull]) getVariable [""EPOCH_Locked"",true]";
				statement = "EPOCH_lockStorage_PVS = [this,false,player,Epoch_personalToken]; publicVariableServer ""EPOCH_lockStorage_PVS""; [getpos this, 5, 5] call Epoch_gui3DCooldown;";
			};
			class Pack
			{
				displayName = "Pack";
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 3;
				condition = "(this getVariable[""EPOCH_secStorParent"", objNull]) getVariable [""EPOCH_Locked"",true]";
				statement = "EPOCH_packStorage_PVS = [this,player,Epoch_personalToken]; publicVariableServer ""EPOCH_packStorage_PVS""; [getpos this, 5, 5] call Epoch_gui3DCooldown;";
			};
		};
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
		upgradeBuilding[] = { "CinderWallGarage_EPOCH", { { "ItemCorrugatedLg", 1 }, { "CircuitParts", 1 }  } };
		simulClass = "CinderWall_SIM_EPOCH";
		staticClass = "CinderWall_EPOCH";
		GhostPreview = "CinderWall_EPOCH";
		snapType = "snapPointsPara";
		snapPointsPara[] = { "N", "E", "W" };
		allowedSnapPoints[] = { "N", "S", "E", "W" };
		energyCost = 0.4;
		armor = 10000;
		removeParts[] = { { "CinderBlocks", 4 }, { "ItemRock", 2 } };
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
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 3;
				condition = "!(call EPOCH_lockCheck) && (this animationPhase ""open_left"" < 0.5) && (this animationPhase ""lock_cGarage"" < 0.5)";
				statement = "this animate [""lock_cGarage"", 1]";
			};
			class Unlock_cGarage : Lock_cGarage
			{
				displayName = "Unlock";
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
		removeParts[] = { { "PartPlankPack", 2 } };
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
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 3;
				condition = "!(call EPOCH_lockCheck) && (this animationPhase ""Open_Door"" == 0) && (this animationPhase ""lock_Door"" == 0)";
				statement = "this animate [""lock_Door"", 1]";
			};
			class Unlock_Door : Lock_Door
			{
				displayName = "Unlock";
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
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 3;
				condition = "!(call EPOCH_lockCheck) && (this animationPhase ""Open_Door"" == 0) && (this animationPhase ""lock_Door"" == 0)";
				statement = "this animate [""lock_Door"", 1]";
			};
			class Unlock_Door : Lock_Door
			{
				displayName = "Unlock";
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
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 3;
				condition = "damage this < 1";
				statement = "this call EPOCH_LootIT;";
			};
		};
	};

	class Secure_Storage_Proxy : WeaponHolder {};
	class LockBoxProxy_EPOCH : Secure_Storage_Proxy
	{
		scope = 2;
		model = "\A3\Weapons_f\dummyweapon.p3d";
		displayName = "Lockbox WH";
		isGround = 0;
		showWeaponCargo = 0;
		forceSupply = 0;
		maximumLoad = 600;
		isSecureStorage = 1;
		parentClass = "LockBox_EPOCH";

		class UserActions
		{
			class Lock
			{
				displayName = "Lock";
				displayNameDefault = "<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 3;
				condition = "this == this";
				statement = "EPOCH_lockStorage_PVS = [this,true,player,Epoch_personalToken]; publicVariableServer ""EPOCH_lockStorage_PVS""; [getpos this, 5, 5] call Epoch_gui3DCooldown;";
			};
		};
	};

	class SafeProxy_EPOCH : Secure_Storage_Proxy
	{
		scope = 2;
		model = "\x\addons\a3_epoch_assets_1\models\safe_proxy.p3d";
		displayName = "Safe WH";
		isGround = 0;
		showWeaponCargo = 0;
		forceSupply = 0;
		maximumLoad = 3600;
		isSecureStorage = 1;
		parentClass = "Safe_EPOCH";

		class UserActions
		{
			class Lock
			{
				displayName = "Lock";
				displayNameDefault = "<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
				onlyforplayer = 1;
				position = "Door_knopf";
				radius = 3;
				condition = "this == this";
				statement = "EPOCH_lockStorage_PVS = [this,true,player,Epoch_personalToken]; publicVariableServer ""EPOCH_lockStorage_PVS""; [getpos this, 5, 5] call Epoch_gui3DCooldown;";
			};
		};
	};

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
