class CfgGesturesMale
{
	skeletonName = "OFP2_ManSkeleton";
	class ManActions{};
	class Actions
	{
		class NoActions
		{
			turnSpeed = 0;
			upDegree = 0;
			limitFast = 1;
			useFastMove = 0;
			stance = "ManStanceUndefined";
		};
	};
	class Default
	{
		actions = "NoActions";
		file = "";
		looped = 1;
		speed = 0.5;
		relSpeedMin = 0.5;
		relSpeedMax = 1;
		soundEnabled = 0;
		soundOverride = "";
		soundEdge[] = {0.5,1};
		terminal = 0;
		ragdoll = 0;
		equivalentTo = "";
		connectAs = "";
		connectFrom[] = {};
		connectTo[] = {};
		interpolateWith[] = {};
		interpolateTo[] = {};
		interpolateFrom[] = {};
		mask = "empty";
		interpolationSpeed = 6;
		interpolationRestart = 0;
		preload = 0;
		disableWeapons = 1;
		enableOptics = 0;
		showWeaponAim = 1;
		enableMissile = 1;
		enableBinocular = 1;
		showItemInHand = 0;
		showItemInRightHand = 0;
		showHandGun = 0;
		canPullTrigger = 1;
		Walkcycles = 1;
		headBobMode = 0;
		headBobStrength = 0;
		leftHandIKBeg = 0;
		leftHandIKEnd = 0;
		rightHandIKBeg = 0;
		rightHandIKEnd = 0;
		leftHandIKCurve[] = {1};
		rightHandIKCurve[] = {1};
		forceAim = 0;
	};
	class States
	{
		class GestureSwing0: Default
		{
			file = "\x\addons\a3_epoch_assets_3\CfgVehicles\Characters\hatch_swing1.rtm";
			looped = 0;
			speed = -0.6;
			mask = "handsWeapon_pst";
			headBobStrength = 0.2;
			headBobMode = 2;
			rightHandIKBeg = 1;
			rightHandIKEnd = 1;
			leftHandIKBeg = 1;
			leftHandIKEnd = 1;
		};
		class GestureSwing1 : Default
		{
			file = "\x\addons\a3_epoch_assets_3\CfgVehicles\Characters\hatch_swing2.rtm";
			looped = 0;
			speed = -0.6;
			mask = "handsWeapon_pst";
			headBobStrength = 0.2;
			headBobMode = 2;
			rightHandIKBeg = 1;
			rightHandIKEnd = 1;
			leftHandIKBeg = 1;
			leftHandIKEnd = 1;
		};
		class GestureSwing2 : Default
		{
			file = "\x\addons\a3_epoch_assets_3\CfgVehicles\Characters\hatch_swing3.rtm";
			looped = 0;
			speed = -0.6;
			mask = "handsWeapon_pst";
			headBobStrength = 0.2;
			headBobMode = 2;
			rightHandIKBeg = 1;
			rightHandIKEnd = 1;
			leftHandIKBeg = 1;
			leftHandIKEnd = 1;
		};
		class GestureFinger: Default
		{
			file = "\x\addons\a3_epoch_assets_3\CfgVehicles\Characters\dat_bird.rtm";
			looped = 0;
			speed = 0.62051;
			mask = "handsWeapon_pst";
			headBobStrength = 0.4;
			headBobMode = 2;
			rightHandIKBeg = 1;
			rightHandIKEnd = 1;
			leftHandIKBeg = 1;
			leftHandIKEnd = 1;
		};
		class SledgeSwing : Default
		{
			file = "\x\addons\a3_epoch_assets_3\CfgVehicles\Characters\Sledge_swing.rtm";
			looped = 0;
			speed = -0.6;
			mask = "handsLauncher";
			headBobStrength = 0.2;
			headBobMode = 2;
			rightHandIKBeg = 0;
			rightHandIKEnd = 0;
			leftHandIKBeg = 0;
			leftHandIKEnd = 0;
		};
		
	};
	class BlendAnims
	{
		handsLauncher[] = { "head", 1, "neck1", 1, "neck", 1, "launcher", 1, "LeftShoulder", 1, "LeftArm", 1, "LeftArmRoll", 1, "LeftForeArm", 1, "LeftForeArmRoll", 1, "LeftHand", 1, "LeftHandRing", 1, "LeftHandPinky1", 1, "LeftHandPinky2", 1, "LeftHandPinky3", 1, "LeftHandRing1", 1, "LeftHandRing2", 1, "LeftHandRing3", 1, "LeftHandMiddle1", 1, "LeftHandMiddle2", 1, "LeftHandMiddle3", 1, "LeftHandIndex1", 1, "LeftHandIndex2", 1, "LeftHandIndex3", 1, "LeftHandThumb1", 1, "LeftHandThumb2", 1, "LeftHandThumb3", 1, "RightShoulder", 1, "RightArm", 1, "RightArmRoll", 1, "RightForeArm", 1, "RightForeArmRoll", 1, "RightHand", 1, "RightHandRing", 1, "RightHandPinky1", 1, "RightHandPinky2", 1, "RightHandPinky3", 1, "RightHandRing1", 1, "RightHandRing2", 1, "RightHandRing3", 1, "RightHandMiddle1", 1, "RightHandMiddle2", 1, "RightHandMiddle3", 1, "RightHandIndex1", 1, "RightHandIndex2", 1, "RightHandIndex3", 1, "RightHandThumb1", 1, "RightHandThumb2", 1, "RightHandThumb3", 1, "Spine", 1, "Spine1", 1, "Spine2", 1, "Spine3", 1, "pelvis", "MaskStart" };
	};
};

class CfgGesturesSapper : CfgGesturesMale 
{
	skeletonName = "SapperSkeleton";
};