/*
	Author: BI

    Contributors:

	Description:
	Stock CfgMovesBasic from 1.54

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_config/Configs/CfgMovesBasic.hpp
*/

class CfgMovesBasic
{
	access = 0;
	skeletonName = "";
	collisionVertexPattern[] = {"1a","2a","3a","4a","5a","6a","7a","8a","9a","10a","11a","12a","13a","14a","15a","16a","17a","18a","19a","20a","21a","22a","23a","24a","25a","26a","27a","28a","29a","30a","31a","32a","33a","34a","1c","2c","3c","4c","5c","6c","7c","8c"};
	collisionGeomCompPattern[] = {1,3};
	class Default
	{
		GetOutPara = "";
		weaponLowered = 0;
		weaponObstructed = 0;
		canBlendStep = 0;
		idle = "idleDefault";
		access = 3;
		actions = "NoActions";
		file = "";
		looped = 1;
		speed = 0.5;
		disableWeapons = 0;
		enableOptics = 0;
		disableWeaponsLong = 0;
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
		canReload = 1;
		duty = -0.5;
		visibleSize = 0.75012;
		aimPrecision = 1;
		camShakeFire = 1;
		static = 0;
		relSpeedMin = 1;
		relSpeedMax = 1;
		soundEnabled = 1;
		soundOverride = "";
		soundEdge[] = {0.5,1};
		terminal = 0;
		ragdoll = 0;
		limitGunMovement = 1;
		variantsPlayer[] = {};
		variantsAI[] = {""};
		equivalentTo = "";
		connectAs = "";
		variantAfter[] = {5,10,20};
		connectFrom[] = {};
		connectTo[] = {};
		interpolateWith[] = {};
		interpolateTo[] = {};
		interpolateFrom[] = {};
		ignoreMinPlayTime[] = {"Unconscious"};
		aiming = "aimingDefault";
		aimingBody = "aimingUpDefault";
		leaning = "leaningDefault";
		legs = "legsDefault";
		head = "headDefault";
		leaningFactorBeg = 0;
		leaningFactorEnd = 0;
		leaningFactorZeroPoint = -1;
		interpolationSpeed = 6;
		interpolationRestart = 0;
		enableDirectControl = 1;
		headBobMode = 0;
		headBobStrength = 0;
		collisionShape = "A3\anims_f\Data\Geom\Sdr\Perc_Wrfl.p3d";
		hasCollShapeSafe = 0;
		collisionShapeSafe = "";
		boundingSphere = 1;
		enableAutoActions = 0;
		leftHandIKEnd = 0;
		leftHandIKBeg = 0;
		rightHandIKBeg = 0;
		rightHandIKEnd = 0;
		leftHandIKCurve[] = {};
		rightHandIKCurve[] = {};
		weaponIK = 0;
		preload = 0;
		Walkcycles = 1;
		forceAim = 0;
		adjstance = "m";
	};
	class HealBase: Default
	{
		disableWeapons = 1;
		disableWeaponsLong = 1;
		showWeaponAim = 0;
		canPullTrigger = 0;
		duty = 0.2;
		limitGunMovement = 0;
		aiming = "empty";
		aimingBody = "empty";
		actions = "HealActionBase";
		looped = 0;
	};
	class HealBaseRfl: HealBase{};
	class StandBase: Default
	{
		disableWeapons = 1;
		leaningFactorBeg = 1;
		leaningFactorEnd = 1;
		headBobMode = 2;
		headBobStrength = 0.20398;
	};
	class DefaultDie: Default
	{
		aiming = "aimingNo";
		aimingBody = "aimingNo";
		legs = "legsNo";
		head = "headNo";
		disableWeapons = 1;
		interpolationRestart = 1;
		soundEdge[] = {0.45};
		boundingSphere = 1.5;
		enableDirectControl = 0;
		showWeaponAim = 0;
		canPullTrigger = 0;
		headBobMode = 1;
		headBobStrength = -1;
	};
	class ManActions
	{
		AdjustF = "";
		AdjustB = "";
		AdjustL = "";
		AdjustR = "";
		AdjustLF = "";
		AdjustLB = "";
		AdjustRB = "";
		AdjustRF = "";
		dooraction = "AmovPercMwlkSnonWnonDf";
		GestureLegPush = "";
		agonyStart = "AinjPpneMstpSnonWnonDnon";
		agonyStop = "AmovPpneMstpSnonWnonDnon";
		medicStop = "AinvPknlMstpSnonWnonDnon_medicEnd";
		medicStart = "AinvPknlMstpSnonWnonDnon_medic0S";
		medicStartUp = "AinvPknlMstpSnonWrflDnon_medicUp0S";
		medicStartRightSide = "AinvPknlMstpSnonWnonDr_medic0S";
		GestureAgonyCargo = "";
		grabCarry = "Helper_SwitchToCarryRfl";
		grabCarried = "AinjPfalMstpSnonWnonDnon_carried_still";
		grabDrag = "AmovPercMstpSlowWrflDnon_AcinPknlMwlkSlowWrflDb_2";
		grabDragged = "AcinPknlMwlkSlowWrflDb_still";
		carriedStill = "AinjPfalMstpSnonWrflDnon_carried_still";
		released = "";
		releasedBad = "";
		Stop = "";
		StopRelaxed = "";
		TurnL = "";
		TurnR = "";
		TurnLRelaxed = "";
		TurnRRelaxed = "";
		ReloadMagazine = "";
		reloadGM6 = "";
		ReloadMGun = "";
		ReloadRPG = "ReloadRPG";
		ReloadMortar = "";
		ThrowPrepare = "";
		ThrowGrenade = "";
		WalkF = "";
		WalkLF = "";
		WalkRF = "";
		WalkL = "";
		WalkR = "";
		WalkLB = "";
		WalkRB = "";
		WalkB = "";
		PlayerWalkF = "";
		PlayerWalkLF = "";
		PlayerWalkRF = "";
		PlayerWalkL = "";
		PlayerWalkR = "";
		PlayerWalkLB = "";
		PlayerWalkRB = "";
		PlayerWalkB = "";
		SlowF = "";
		SlowLF = "";
		SlowRF = "";
		SlowL = "";
		SlowR = "";
		SlowLB = "";
		SlowRB = "";
		SlowB = "";
		PlayerSlowF = "";
		PlayerSlowLF = "";
		PlayerSlowRF = "";
		PlayerSlowL = "";
		PlayerSlowR = "";
		PlayerSlowLB = "";
		PlayerSlowRB = "";
		PlayerSlowB = "";
		FastF = "";
		FastLF = "";
		FastRF = "";
		FastL = "";
		FastR = "";
		FastLB = "";
		FastRB = "";
		FastB = "";
		TactF = "";
		TactLF = "";
		TactRF = "";
		TactL = "";
		TactR = "";
		TactLB = "";
		TactRB = "";
		TactB = "";
		PlayerTactF = "";
		PlayerTactLF = "";
		PlayerTactRF = "";
		PlayerTactL = "";
		PlayerTactR = "";
		PlayerTactLB = "";
		PlayerTactRB = "";
		PlayerTactB = "";
		EvasiveLeft = "";
		EvasiveRight = "";
		startSwim = "";
		surfaceSwim = "";
		bottomSwim = "";
		StopSwim = "";
		startDive = "AdvePercMrunSnonWnonDf";
		SurfaceDive = "AsdvPercMrunSnonWnonDf";
		BottomDive = "AbdvPercMrunSnonWnonDf";
		StopDive = "";
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
		Die = "Unconscious";
		Unconscious = "Unconscious";
		WeaponOn = "";
		WeaponOff = "";
		Default = "";
		JumpOff = "";
		StrokeFist = "";
		StrokeGun = "";
		SitDown = "";
		Salute = "";
		saluteOff = "";
		GetOver = "";
		Diary = "";
		Surrender = "";
		Gear = "";
		BinocOn = "";
		BinocOff = "";
		PutDown = "";
		PutDownEnd = "";
		Medic = "";
		MedicOther = "";
		Treated = "";
		LadderOnDown = "";
		LadderOnUp = "";
		LadderOff = "";
		LadderOffTop = "";
		LadderOffBottom = "";
		GetInLow = "";
		GetInMedium = "";
		GetInHigh = "";
		GetInVertical = "";
		GetInSDV = "";
		GetInHeli_Attack_01Pilot = "";
		GetInHeli_Attack_01Gunner = "";
		GetInHelicopterCargo = "";
		GetInMRAP_01 = "";
		GetInMRAP_01_cargo = "";
		GetOutMRAP_01 = "";
		GetOutMRAP_01_cargo = "";
		GetOutHelicopterCargo = "";
		GetOutLow = "";
		GetOutMedium = "";
		GetOutHigh = "";
		GetOutHighZamak = "";
		GetOutHighHemtt = "";
		GetOutSDV = "";
		GetOutHeli_Attack_01Pilot = "";
		GetOutHeli_Attack_01Gunner = "";
		GetInBoat = "";
		GetOutBoat = "";
		TakeFlag = "";
		HandGunOn = "";
		gestureAttack = "";
		gestureGo = "";
		gestureGoB = "";
		gestureFreeze = "";
		gesturePoint = "";
		gestureCeaseFire = "";
		gestureCover = "";
		gestureUp = "";
		gestureNo = "";
		gestureYes = "";
		gestureFollow = "";
		gestureAdvance = "";
		gestureHi = "";
		gestureHiB = "";
		gestureHiC = "";
		gestureNod = "";
		GestureSpasm0 = "";
		GestureSpasm1 = "";
		GestureSpasm2 = "";
		GestureSpasm3 = "";
		GestureSpasm4 = "";
		GestureSpasm5 = "";
		GestureSpasm6 = "";
		GestureSpasm0weak = "";
		GestureSpasm1weak = "";
		GestureSpasm2weak = "";
		GestureSpasm3weak = "";
		GestureSpasm4weak = "";
		GestureSpasm5weak = "";
		GestureSpasm6weak = "";
		GestureReloadMX = "";
		GestureReloadMXCompact = "";
		GestureReloadMXSniper = "";
		GestureReloadMk20 = "";
		GestureReloadMk20UGL = "";
		GestureReloadMXUGL = "";
		GestureReloadTRG = "";
		GestureReloadTRGUGL = "";
		GestureReloadKatiba = "";
		GestureReloadKatibaUGL = "";
		GestureReloadM200 = "";
		GestureReloadLRR = "";
		GestureReloadEBR = "";
		GestureReloadM4SSAS = "";
		GestureReloadSMG_02 = "";
		GestureReloadSMG_03 = "";
		GestureReloadPistol = "";
		GestureReloadPistolHeavy02 = "";
		GestureReloadFlaregun = "";
		GestureReloadSMG_01 = "";
		GestureReloadSDAR = "";
		GestureReloadDMR = "";
		GestureReloadDMR02 = "";
		GestureReloadDMR03 = "";
		GestureReloadDMR04 = "";
		GestureReloadDMR05 = "";
		GestureReloadDMR06 = "";
		GestureReloadMMG01 = "";
		GestureReloadMMG02 = "";
		MountOptic = "";
		DismountOptic = "";
		MountSide = "";
		DismountSide = "";
		GestureMountMuzzle = "";
		GestureDismountMuzzle = "";
		healedStart = "";
		healedStop = "";
		TestDriver = "BasicDriver";
		TestDriverOut = "BasicDriverOut";
		TestGunner = "BasicSittingGunner";
		Relax = "";
		swimUp = "";
		swimDown = "";
		StartFreefall = "";
		PrimaryWeapon = "";
		SecondaryWeapon = "";
		Binoculars = "";
		FDStart = "";
		Obstructed = "";
		// Custom Start
		GestureSwing0 = "";
		GestureSwing1 = "";
		GestureSwing2 = "";
		GestureFinger = "";
		SledgeSwing = "";
		// Custom End
	};
	class Actions
	{
		class NoActions: ManActions
		{
			// Custom Start
			GestureSwing0[] = {"GestureSwing0","Gesture"};
			GestureSwing1[] = {"GestureSwing1","Gesture"};
			GestureSwing2[] = {"GestureSwing2","Gesture"};
			GestureFinger[] = {"GestureFinger","Gesture"};
			SledgeSwing[] = {"SledgeSwing","Gesture"};
			// Custom End

			GestureLegPush[] = {"GestureLegPush","Gesture"};
			GestureNod[] = {"GestureNod","Gesture"};
			GestureAgonyCargo[] = {"GestureAgonyCargo","Gesture"};
			access = 3;
			ladderOnDown = "LadderCivilOn_Top";
			ladderOnUp = "LadderCivilOn_Top";
			turnSpeed = 1;
			upDegree = -1;
			stance = "ManStanceUndefined";
			limitFast = 5;
			leanRRot = 0;
			leanRShift = 0;
			leanLRot = 0;
			leanLShift = 0;
			useFastMove = 0;
			GestureSpasm0[] = {"GestureSpasm0","Gesture"};
			GestureSpasm1[] = {"GestureSpasm1","Gesture"};
			GestureSpasm2[] = {"GestureSpasm2","Gesture"};
			GestureSpasm3[] = {"GestureSpasm3","Gesture"};
			GestureSpasm4[] = {"GestureSpasm4","Gesture"};
			GestureSpasm5[] = {"GestureSpasm5","Gesture"};
			GestureSpasm6[] = {"GestureSpasm6","Gesture"};
			GestureSpasm0weak[] = {"GestureSpasm0weak","Gesture"};
			GestureSpasm1weak[] = {"GestureSpasm1weak","Gesture"};
			GestureSpasm2weak[] = {"GestureSpasm2weak","Gesture"};
			GestureSpasm3weak[] = {"GestureSpasm3weak","Gesture"};
			GestureSpasm4weak[] = {"GestureSpasm4weak","Gesture"};
			GestureSpasm5weak[] = {"GestureSpasm5weak","Gesture"};
			GestureSpasm6weak[] = {"GestureSpasm6weak","Gesture"};
			GestureReloadMk20[] = {"GestureReloadMk20","Gesture"};
			GestureReloadMk20UGL[] = {"GestureReloadMk20UGL","Gesture"};
			GestureReloadMXUGL[] = {"GestureReloadMXUGL","Gesture"};
			GestureReloadMX[] = {"GestureReloadMX","Gesture"};
			GestureReloadMXCompact[] = {"GestureReloadMXCompact","Gesture"};
			GestureReloadMXSniper[] = {"GestureReloadMXSniper","Gesture"};
			GestureReloadTRG[] = {"GestureReloadTRG","Gesture"};
			GestureReloadTRGUGL[] = {"GestureReloadTRGUGL","Gesture"};
			GestureReloadKatibaUGL[] = {"GestureReloadKatibaUGL","Gesture"};
			GestureReloadKatiba[] = {"GestureReloadKatiba","Gesture"};
			GestureReloadM200[] = {"GestureReloadM200","Gesture"};
			GestureReloadLRR[] = {"GestureReloadLRR","Gesture"};
			GestureReloadEBR[] = {"GestureReloadEBR","Gesture"};
			GestureReloadSMG_02[] = {"GestureReloadSMG_02","Gesture"};
			GestureReloadSMG_03[] = {"GestureReloadSMG_03","Gesture"};
			GestureReloadPistol[] = {"GestureReloadPistol","Gesture"};
			GestureReloadPistolHeavy02[] = {"GestureReloadPistolHeavy02","Gesture"};
			GestureReloadFlaregun[] = {"GestureReloadFlaregun","Gesture"};
			GestureReloadSMG_01[] = {"GestureReloadSMG_01","Gesture"};
			GestureReloadSDAR[] = {"GestureReloadSDAR","Gesture"};
			GestureReloadDMR[] = {"GestureReloadDMR","Gesture"};
			GestureReloadDMR02[] = {"GestureReloadDMR02","Gesture"};
			GestureReloadDMR03[] = {"GestureReloadDMR03","Gesture"};
			GestureReloadDMR04[] = {"GestureReloadDMR04","Gesture"};
			GestureReloadDMR05[] = {"GestureReloadDMR05","Gesture"};
			GestureReloadDMR06[] = {"GestureReloadDMR06","Gesture"};
			GestureReloadMMG01[] = {"GestureReloadMMG01","Gesture"};
			GestureReloadMMG02[] = {"GestureReloadMMG02","Gesture"};
			GestureReloadM4SSAS[] = {"GestureReloadM4SSAS","Gesture"};
			GestureMountMuzzle[] = {"GestureMountMuzzle","Gesture"};
			GestureDismountMuzzle[] = {"GestureDismountMuzzle","Gesture"};
			grabCarried = "AinjPfalMstpSnonWrflDnon_carried_Up";
		};
		class DeadActions: NoActions
		{
			upDegree = "ManPosDead";
			stance = "ManStanceProne";
			LadderOnDown = "";
			LadderOnUp = "";
			TestDriver = "";
			TestDriverOut = "";
			TestGunner = "";
			Die = "DeadState";
		};
		class CutsceneLoop: NoActions
		{
			upDegree = "ManPosStand";
			stance = "ManStanceStand";
			LadderOnDown = "";
			LadderOnUp = "";
			TestDriver = "";
			TestDriverOut = "";
			TestGunner = "";
			Die = "DeadState";
			stop = "Acts_PercMwlkSlowWrflDf";
		};
		class StaticCutsceneLoop: NoActions
		{
			upDegree = "ManPosStand";
			stance = "ManStanceStand";
			LadderOnDown = "";
			LadderOnUp = "";
			TestDriver = "";
			TestDriverOut = "";
			TestGunner = "";
			Die = "DeadState";
		};
		class StaticCutsceneLoopPlayerWalk: NoActions
		{
			upDegree = "ManPosStand";
			stance = "ManStanceStand";
			LadderOnDown = "";
			LadderOnUp = "";
			TestDriver = "";
			TestDriverOut = "";
			TestGunner = "";
			Die = "DeadState";
			stop = "AmovPercMstpSlowWrflDnon";
			stopRelaxed = "AmovPercMstpSlowWrflDnon";
			default = "AmovPercMstpSlowWrflDnon";
		};
		class ToIncapacitatedAction: NoActions
		{
			upDegree = "ManPosDead";
			stance = "ManStanceProne";
			Die = "DeadState";
			turnSpeed = 2.5;
			limitFast = 5.5;
		};
		class IncapacitatedAction: ToIncapacitatedAction{};
		class ToIncapacitatedRifleAction: ToIncapacitatedAction
		{
			AgonyStop = "AmovPpneMstpSrasWrflDnon";
		};
		class IncapacitatedRifleAction: ToIncapacitatedRifleAction{};
		class ToIncapacitatedPistolAction: ToIncapacitatedAction
		{
			AgonyStop = "AmovPpneMstpSrasWpstDnon";
		};
		class IncapacitatedPistolAction: ToIncapacitatedPistolAction{};
		class CargoActions: NoActions{};
		class RifleBaseLowStandActions: NoActions
		{
			stop = "AmovPercMstpSlowWrflDnon";
			default = "AmovPercMstpSlowWrflDnon";
			StopRelaxed = "AidlPercMstpSlowWrflDnon_AI";
			turnL = "AmovPercMstpSlowWrflDnon_turnL";
			turnR = "AmovPercMstpSlowWrflDnon_turnR";
			turnLRelaxed = "AmovPercMstpSlowWrflDnon_turnL";
			turnRRelaxed = "AmovPercMstpSlowWrflDnon_turnR";
			reloadMagazine[] = {"WeaponMagazineReloadStand_g","Gesture"};
			gestureGo[] = {"GestureGoStand","Gesture"};
			gestureGoB[] = {"GestureGoBStand","Gesture"};
			gestureFreeze[] = {"GestureFreezeStand","Gesture"};
			gesturePoint[] = {"GestureAttackStand","Gesture"};
			gestureCeaseFire[] = {"GestureCeaseFire","Gesture"};
			gestureCover[] = {"GestureCover","Gesture"};
			gestureUp[] = {"GestureUp","Gesture"};
			gestureNo[] = {"GestureNo","Gesture"};
			gestureYes[] = {"GestureYes","Gesture"};
			gestureFollow[] = {"GestureFollow","Gesture"};
			gestureAdvance[] = {"GestureAttackStand","Gesture"};
			gestureHi[] = {"GestureHi","Gesture"};
			gestureHiB[] = {"GestureHiB","Gesture"};
			gestureHiC[] = {"GestureHiC","Gesture"};
			reloadGM6[] = {"GestureReloadGM6","Gesture"};
			MountOptic = "MountOptic";
			DismountOptic = "DismountOptic";
			MountSide = "MountSide";
			DismountSide = "DismountSide";
			reloadMGun = "AmovPercMstpSlowWrflDnon";
			reloadMortar = "AmovPercMstpSlowWrflDnon";
			throwPrepare = "AwopPercMstpSgthWrflDnon_Start1";
			throwGrenade[] = {"GestureThrowGrenade","Gesture"};
			WalkF = "AmovPercMwlkSlowWrflDf";
			WalkLF = "AmovPercMwlkSlowWrflDfl";
			WalkRF = "AmovPercMwlkSlowWrflDfr";
			WalkL = "AmovPercMwlkSlowWrflDl";
			WalkR = "AmovPercMwlkSlowWrflDr";
			WalkLB = "AmovPercMwlkSlowWrflDbl";
			WalkRB = "AmovPercMwlkSlowWrflDbr";
			WalkB = "AmovPercMwlkSlowWrflDb";
			PlayerWalkF = "AmovPercMwlkSlowWrflDf";
			PlayerWalkLF = "AmovPercMwlkSlowWrflDfl";
			PlayerWalkRF = "AmovPercMwlkSlowWrflDfr";
			PlayerWalkL = "AmovPercMwlkSlowWrflDl";
			PlayerWalkR = "AmovPercMwlkSlowWrflDr";
			PlayerWalkLB = "AmovPercMwlkSlowWrflDbl";
			PlayerWalkRB = "AmovPercMwlkSlowWrflDbr";
			PlayerWalkB = "AmovPercMwlkSlowWrflDb";
			SlowF = "AmovPercMrunSlowWrflDf";
			SlowLF = "AmovPercMrunSlowWrflDfl";
			SlowRF = "AmovPercMrunSlowWrflDfr";
			SlowL = "AmovPercMrunSlowWrflDl";
			SlowR = "AmovPercMrunSlowWrflDr";
			SlowLB = "AmovPercMrunSlowWrflDbl";
			SlowRB = "AmovPercMrunSlowWrflDbr";
			SlowB = "AmovPercMrunSlowWrflDb";
			PlayerSlowF = "AmovPercMrunSlowWrflDf";
			PlayerSlowLF = "AmovPercMrunSlowWrflDfl";
			PlayerSlowRF = "AmovPercMrunSlowWrflDfr";
			PlayerSlowL = "AmovPercMrunSlowWrflDl";
			PlayerSlowR = "AmovPercMrunSlowWrflDr";
			PlayerSlowLB = "AmovPercMrunSlowWrflDbl";
			PlayerSlowRB = "AmovPercMrunSlowWrflDbr";
			PlayerSlowB = "AmovPercMrunSlowWrflDb";
			FastF = "AmovPercMevaSlowWrflDf";
			FastLF = "AmovPercMevaSlowWrflDfl";
			FastRF = "AmovPercMevaSlowWrflDfr";
			FastL = "AmovPercMrunSlowWrflDl";
			FastR = "AmovPercMrunSlowWrflDr";
			FastLB = "AmovPercMrunSlowWrflDbl";
			FastRB = "AmovPercMrunSlowWrflDbr";
			FastB = "AmovPercMrunSlowWrflDb";
			TactF = "AmovPercMtacSlowWrflDf";
			TactLF = "AmovPercMtacSlowWrflDfl";
			TactRF = "AmovPercMtacSlowWrflDfr";
			TactL = "AmovPercMtacSlowWrflDl";
			TactR = "AmovPercMtacSlowWrflDr";
			TactLB = "AmovPercMtacSlowWrflDbl";
			TactRB = "AmovPercMtacSlowWrflDbr";
			TactB = "AmovPercMtacSlowWrflDb";
			PlayerTactF = "AmovPercMtacSlowWrflDf";
			PlayerTactLF = "AmovPercMtacSlowWrflDfl";
			PlayerTactRF = "AmovPercMtacSlowWrflDfr";
			PlayerTactL = "AmovPercMtacSlowWrflDl";
			PlayerTactR = "AmovPercMtacSlowWrflDr";
			PlayerTactLB = "AmovPercMtacSlowWrflDbl";
			PlayerTactRB = "AmovPercMtacSlowWrflDbr";
			PlayerTactB = "AmovPercMtacSlowWrflDb";
			EvasiveLeft = "";
			EvasiveRight = "";
			down = "AmovPpneMstpSrasWrflDnon";
			up = "AmovPknlMstpSlowWrflDnon";
			weaponOn = "AmovPknlMstpSrasWlnrDnon";
			weaponOff = "AmovPercMstpSrasWrflDnon";
			binocOn = "AwopPercMstpSoptWbinDnon_rfl";
			binocOff = "AmovPercMstpSrasWrflDnon";
			handGunOn = "AmovPercMstpSrasWpstDnon";
			takeFlag = "AinvPknlMstpSlayWrflDnon";
			putDown = "AmovPknlMstpSrasWrflDnon_explo";
			medic = "AinvPknlMstpSlayWrflDnon_medic";
			medicOther = "AinvPknlMstpSlayWrflDnon_medicOther";
			medicUp = "AinvPknlMstpSlayWrflDnon_medicUp";
			treated = "AinvPknlMstpSlayWrflDnon_healed";
			PlayerStand = "AmovPercMstpSlowWrflDnon";
			PlayerCrouch = "AmovPknlMstpSlowWrflDnon";
			PlayerProne = "AmovPpneMstpSrasWrflDnon";
			Combat = "AmovPercMstpSrasWrflDnon";
			Lying = "AmovPpneMstpSrasWrflDnon";
			Stand = "AmovPercMstpSrasWrflDnon";
			Crouch = "AmovPknlMstpSlowWrflDnon";
			CanNotMove = "AmovPercMstpSrasWrflDnon";
			Civil = "AmovPercMstpSnonWnonDnon";
			CivilLying = "AmovPpneMstpSnonWnonDnon";
			FireNotPossible = "AmovPercMstpSrasWrflDnon";
			ladderOnDown = "LadderRifleOn";
			ladderOnUp = "LadderRifleOn";
			strokeGun = "AmovPercMstpSrasWrflDnon";
			GetInLow = "AmovPercMstpSnonWnonDnon_AcrgPknlMstpSnonWnonDnon_getInLow";
			GetInMedium = "AmovPercMstpSnonWnonDnon_AcrgPknlMstpSnonWnonDnon_getInMedium";
			GetInHigh = "AmovPercMstpSnonWnonDnon_AcrgPknlMstpSnonWnonDnon_getInHigh";
			GetInVertical = "GetIn_Vertical_Rifle";
			GetInSDV = "AmovPercMstpSnonWnonDnon_AcrgPknlMstpSnonWnonDnon_getInHigh";
			GetOutPara = "AparPercMstpSnonWnonDnon_AmovPpneMstpSnonWnonDnon";
			GetOutLow = "AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWrflDnon_getOutLow";
			GetOutMedium = "AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWrflDnon_getOutMedium";
			GetOutHigh = "AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWrflDnon_getOutHigh";
			GetOutHighZamak = "AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWrflDnon_getOutHighZamak";
			GetOutHighHemtt = "AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWrflDnon_getOutHighHemtt";
			GetOutSDV = "AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWrflDnon_getOutHigh";
			GetOutHeli_Attack_01Pilot = "Heli_Attack_01Pilot_AmovPercMstpSlowWrflDnon";
			GetOutHeli_Attack_01Gunner = "Heli_Attack_01Gunner_AmovPercMstpSlowWrflDnon";
			GetInHelicopterCargo = "GetInHelicopterCargoRfl";
			GetInMRAP_01 = "GetInMRAP_01Rfl";
			GetInMRAP_01_cargo = "GetInMRAP_01_cargoRfl";
			GetOutMRAP_01 = "GetOutMRAP_01Rfl";
			GetOutMRAP_01_cargo = "GetOutMRAP_01_cargoRfl";
			GetOutHelicopterCargo = "GetOutHelicopterCargoRfl";
			sitDown = "AmovPsitMstpSlowWrflDnon";
			getOver = "AovrPercMstpSlowWrflDf";
			salute = "AmovPercMstpSlowWrflDnon_salute";
			turnSpeed = 8;
			limitFast = 5.5;
			leanRRot = 0.5;
			leanRShift = 0.01;
			leanLRot = 0.5;
			leanLShift = 0.01;
			startSwim = "AswmPercMrunSnonWnonDf";
			surfaceSwim = "AsswPercMrunSnonWnonDf";
			bottomSwim = "AbswPercMrunSnonWnonDf";
			startDive = "AdvePercMrunSnonWrflDf";
			SurfaceDive = "AsdvPercMrunSnonWrflDf";
			BottomDive = "AbdvPercMrunSnonWrflDf";
			upDegree = "ManPosStand";
			stance = "ManStanceStand";
			medicStop = "AinvPknlMstpSnonWrflDnon_medicEnd";
			medicStart = "AinvPknlMstpSnonWrflDnon_medic0S";
			medicStartRightSide = "AinvPknlMstpSnonWrflDr_medic0S";
			healedStop = "AinjPpneMstpSnonWrflDnon";
			healedStart = "AinjPpneMstpSnonWrflDnon_injuredHealed";
			agonyStart = "AinjPpneMstpSnonWrflDnon";
			agonyStop = "AmovPpneMstpSrasWrflDnon";
			Diary = "";
			Surrender = "AmovPercMstpSsurWnonDnon";
			Gear = "AmovPercMstpSlowWrflDnon_gear";
			saluteOff = "AmovPercMstpSlowWrflDnon";
			Relax = "AmovPknlMstpSlowWrflDnon_relax";
			StartFreefall = "AfalPercMstpSrasWrflDnon";
			PrimaryWeapon = "AmovPercMstpSrasWrflDnon";
			SecondaryWeapon = "AmovPercMstpSrasWlnrDnon";
			Binoculars = "AmovPercMstpSoptWbinDnon";
		};
		class RifleLowStandActions: RifleBaseLowStandActions
		{
			PlayerStand = "";
			Diary = "";
			Gear = "AinvPercMstpSrasWrflDnon";
			StopRelaxed = "AmovPercMstpSlowWrflDnon";
			putDown = "AmovPercMstpSrasWrflDnon_AinvPercMstpSrasWrflDnon_Putdown";
			GetInBoat = "GetInHeli_Transport_01Cargo";
			GetOutBoat = "AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWrflDnon_getOutLow";
		};
		class RifleLowStandActionsNoAdjust: RifleLowStandActions
		{
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
			AdjustLF = "";
			AdjustLB = "";
			AdjustRB = "";
			AdjustRF = "";
		};
		class RifleLowStandActions_gear: RifleLowStandActions
		{
			Stop = "AmovPercMstpSlowWrflDnon_gear";
			StopRelaxed = "AmovPercMstpSlowWrflDnon_gear";
			Default = "AmovPercMstpSlowWrflDnon_gear";
			PlayerStand = "AmovPercMstpSlowWrflDnon";
			Civil = "AmovPercMstpSnonWnonDnon_gear";
			HandGunOn = "AmovPercMstpSrasWpstDnon_gear";
		};
		class RifleLowStandActions_diary: RifleLowStandActions_gear
		{
			Stop = "AmovPercMstpSlowWrflDnon_diary";
			StopRelaxed = "AmovPercMstpSlowWrflDnon_diary";
			Default = "AmovPercMstpSlowWrflDnon_diary";
		};
		class RifleLowStandActionsWlkF: RifleLowStandActionsNoAdjust
		{
			PlayerCrouch = "AmovPknlMwlkSlowWrflDf";
			Up = "AmovPknlMwlkSlowWrflDf";
			ThrowPrepare = "AmovPercMwlkSlowWrflDf";
			Combat = "AmovPercMwlkSrasWrflDf";
		};
		class RifleLowStandActionsRunF: RifleLowStandActionsNoAdjust
		{
			turnSpeed = 4.5;
			PlayerCrouch = "AmovPknlMrunSlowWrflDf";
			Up = "AmovPknlMrunSlowWrflDf";
			ThrowPrepare = "AmovPercMrunSlowWrflDf";
			Combat = "AmovPercMtacSrasWrflDf";
			FireNotPossible = "AmovPercMtacSrasWrflDf";
		};
		class RifleLowStandActionsWlkFL: RifleLowStandActionsNoAdjust
		{
			PlayerCrouch = "AmovPknlMwlkSlowWrflDfl";
			Up = "AmovPknlMwlkSlowWrflDfl";
			ThrowPrepare = "AmovPercMwlkSlowWrflDfl";
			Combat = "AmovPercMwlkSrasWrflDfl";
			FireNotPossible = "AmovPercMwlkSrasWrflDfl";
		};
		class RifleLowStandActionsRunFL: RifleLowStandActionsNoAdjust
		{
			turnSpeed = 4.5;
			PlayerCrouch = "AmovPknlMrunSlowWrflDfl";
			Up = "AmovPknlMrunSlowWrflDfl";
			ThrowPrepare = "AmovPercMrunSlowWrflDfl";
			Combat = "AmovPercMtacSrasWrflDfl";
			FireNotPossible = "AmovPercMtacSrasWrflDfl";
		};
		class RifleLowStandActionsWlkL: RifleLowStandActionsNoAdjust
		{
			PlayerCrouch = "AmovPknlMwlkSlowWrflDl";
			Up = "AmovPknlMwlkSlowWrflDl";
			Combat = "AmovPercMwlkSrasWrflDl";
			FireNotPossible = "AmovPercMwlkSrasWrflDl";
		};
		class RifleLowStandActionsRunL: RifleLowStandActionsNoAdjust
		{
			turnSpeed = 4.5;
			PlayerCrouch = "AmovPknlMrunSlowWrflDl";
			Up = "AmovPknlMrunSlowWrflDl";
			Combat = "AmovPercMtacSrasWrflDl";
			FireNotPossible = "AmovPercMtacSrasWrflDl";
		};
		class RifleLowStandActionsWlkBL: RifleLowStandActionsNoAdjust
		{
			PlayerCrouch = "AmovPknlMwlkSlowWrflDbl";
			Up = "AmovPknlMwlkSlowWrflDbl";
			Combat = "AmovPercMwlkSrasWrflDbl";
			FireNotPossible = "AmovPercMwlkSrasWrflDbl";
		};
		class RifleLowStandActionsRunBL: RifleLowStandActionsNoAdjust
		{
			turnSpeed = 4.5;
			PlayerCrouch = "AmovPknlMrunSlowWrflDbl";
			Up = "AmovPknlMrunSlowWrflDbl";
			Combat = "AmovPercMtacSrasWrflDbl";
			FireNotPossible = "AmovPercMtacSrasWrflDbl";
		};
		class RifleLowStandActionsWlkB: RifleLowStandActionsNoAdjust
		{
			PlayerCrouch = "AmovPknlMwlkSlowWrflDb";
			Up = "AmovPknlMwlkSlowWrflDb";
			Combat = "AmovPercMwlkSrasWrflDb";
			FireNotPossible = "AmovPercMwlkSrasWrflDb";
		};
		class RifleLowStandActionsRunB: RifleLowStandActionsNoAdjust
		{
			turnSpeed = 4.5;
			PlayerCrouch = "AmovPknlMrunSlowWrflDb";
			Up = "AmovPknlMrunSlowWrflDb";
			Combat = "AmovPercMtacSrasWrflDb";
			FireNotPossible = "AmovPercMtacSrasWrflDb";
		};
		class RifleLowStandActionsWlkBR: RifleLowStandActionsNoAdjust
		{
			PlayerCrouch = "AmovPknlMwlkSlowWrflDbr";
			Up = "AmovPknlMwlkSlowWrflDbr";
			Combat = "AmovPercMwlkSrasWrflDbr";
			FireNotPossible = "AmovPercMwlkSrasWrflDbr";
		};
		class RifleLowStandActionsRunBR: RifleLowStandActionsNoAdjust
		{
			turnSpeed = 4.5;
			PlayerCrouch = "AmovPknlMrunSlowWrflDbr";
			Up = "AmovPknlMrunSlowWrflDbr";
			Combat = "AmovPercMtacSrasWrflDbr";
			FireNotPossible = "AmovPercMtacSrasWrflDbr";
		};
		class RifleLowStandActionsWlkR: RifleLowStandActionsNoAdjust
		{
			PlayerCrouch = "AmovPknlMwlkSlowWrflDr";
			Up = "AmovPknlMwlkSlowWrflDr";
			Combat = "AmovPercMwlkSrasWrflDr";
			FireNotPossible = "AmovPercMwlkSrasWrflDr";
		};
		class RifleLowStandActionsRunR: RifleLowStandActionsNoAdjust
		{
			turnSpeed = 4.5;
			PlayerCrouch = "AmovPknlMrunSlowWrflDr";
			Up = "AmovPknlMrunSlowWrflDr";
			Combat = "AmovPercMtacSrasWrflDr";
			FireNotPossible = "AmovPercMtacSrasWrflDr";
		};
		class RifleLowStandActionsWlkFR: RifleLowStandActionsNoAdjust
		{
			PlayerCrouch = "AmovPknlMwlkSlowWrflDr";
			up = "AmovPknlMwlkSlowWrflDr";
			Combat = "AmovPercMwlkSrasWrflDfr";
			FireNotPossible = "AmovPercMwlkSrasWrflDfr";
		};
		class RifleLowStandActionsRunFR: RifleLowStandActionsNoAdjust
		{
			turnSpeed = 4.5;
			PlayerCrouch = "AmovPknlMrunSlowWrflDfr";
			Up = "AmovPknlMrunSlowWrflDfr";
			ThrowPrepare = "AmovPercMrunSlowWrflDfr";
			Combat = "AmovPercMtacSrasWrflDfr";
			FireNotPossible = "AmovPercMtacSrasWrflDfr";
		};
		class RifleLowStandActionsTacF: RifleLowStandActionsNoAdjust
		{
			PlayerCrouch = "AmovPknlMtacSlowWrflDf";
			Up = "AmovPknlMtacSlowWrflDf";
			ThrowPrepare = "AmovPercMTacSlowWrflDf";
			Combat = "AmovPercMTacSrasWrflDf";
		};
		class RifleLowStandActionsTacFL: RifleLowStandActionsNoAdjust
		{
			PlayerCrouch = "AmovPknlMtacSlowWrflDfl";
			Up = "AmovPknlMtacSlowWrflDfl";
			ThrowPrepare = "AmovPercMTacSlowWrflDfl";
			Combat = "AmovPercMTacSrasWrflDfl";
		};
		class RifleLowStandActionsTacL: RifleLowStandActionsNoAdjust
		{
			PlayerCrouch = "AmovPknlMtacSlowWrflDl";
			Up = "AmovPknlMtacSlowWrflDl";
			Combat = "AmovPercMTacSrasWrflDl";
		};
		class RifleLowStandActionsTacBL: RifleLowStandActionsNoAdjust
		{
			PlayerCrouch = "AmovPknlMtacSlowWrflDbl";
			Up = "AmovPknlMtacSlowWrflDbl";
			Combat = "AmovPercMTacSrasWrflDbl";
		};
		class RifleLowStandActionsTacB: RifleLowStandActionsNoAdjust
		{
			PlayerCrouch = "AmovPknlMtacSlowWrflDb";
			Up = "AmovPknlMtacSlowWrflDb";
			Combat = "AmovPercMTacSrasWrflDb";
		};
		class RifleLowStandActionsTacBR: RifleLowStandActionsNoAdjust
		{
			PlayerCrouch = "";
			Up = "AmovPknlMtacSlowWrflDbr";
			Combat = "AmovPercMTacSrasWrflDbr";
		};
		class RifleLowStandActionsTacR: RifleLowStandActionsNoAdjust
		{
			PlayerCrouch = "AmovPknlMtacSlowWrflDr";
			Up = "AmovPknlMtacSlowWrflDr";
			Combat = "AmovPercMTacSrasWrflDr";
		};
		class RifleLowStandActionsTacFR: RifleLowStandActionsNoAdjust
		{
			PlayerCrouch = "AmovPknlMtacSlowWrflDfr";
			Up = "AmovPknlMtacSlowWrflDfr";
			ThrowPrepare = "AmovPercMTacSlowWrflDfr";
			Combat = "AmovPercMTacSrasWrflDfr";
		};
		class RifleStandLowEvasiveActionsF: RifleLowStandActionsNoAdjust
		{
			turnSpeed = 4;
			ThrowPrepare = "AmovPercMevaSlowWrflDf";
			salute = "";
			sitDown = "";
			Up = "AmovPknlMevaSlowWrflDf";
			PlayerCrouch = "AmovPknlMevaSlowWrflDf";
			AdjustF = "AmovPercMrunSrasWrflDf";
		};
		class RifleStandLowEvasiveActionsFR: RifleLowStandActionsNoAdjust
		{
			turnSpeed = 4;
			ThrowPrepare = "AmovPercMevaSlowWrflDfr";
			salute = "";
			sitDown = "";
			Up = "AmovPknlMevaSlowWrflDfr";
			PlayerCrouch = "AmovPknlMevaSlowWrflDfr";
			AdjustLF = "AmovPercMrunSrasWrflDfl";
		};
		class RifleStandLowEvasiveActionsFL: RifleLowStandActionsNoAdjust
		{
			turnSpeed = 4;
			ThrowPrepare = "AmovPercMevaSlowWrflDfl";
			salute = "";
			sitDown = "";
			Up = "AmovPknlMevaSlowWrflDfl";
			PlayerCrouch = "AmovPknlMevaSlowWrflDfl";
			AdjustLF = "AmovPercMrunSrasWrflDfl";
		};
		class RifleLowStandActions_talkCalm: RifleLowStandActions
		{
			Default = "AidlPercSlowWrflDnon_talkCalm";
		};
		class RifleLowStandActions_evasiveActions: RifleLowStandActions{};
		class RifleBaseStandActions: RifleBaseLowStandActions
		{
			stop = "AmovPercMstpSrasWrflDnon";
			default = "AmovPercMstpSrasWrflDnon";
			StopRelaxed = "AidlPercMstpSrasWrflDnon_AI";
			turnL = "AmovPercMstpSrasWrflDnon_turnL";
			turnR = "AmovPercMstpSrasWrflDnon_turnR";
			turnLRelaxed = "AmovPercMstpSrasWrflDnon_turnL";
			turnRRelaxed = "AmovPercMstpSrasWrflDnon_turnR";
			reloadMGun = "AmovPercMstpSrasWrflDnon";
			reloadMortar = "AmovPercMstpSrasWrflDnon";
			throwPrepare = "AwopPercMstpSgthWrflDnon_Start2";
			WalkF = "AmovPercMwlkSrasWrflDf";
			WalkLF = "AmovPercMwlkSrasWrflDfl";
			WalkRF = "AmovPercMwlkSrasWrflDfr";
			WalkL = "AmovPercMwlkSrasWrflDl";
			WalkR = "AmovPercMwlkSrasWrflDr";
			WalkLB = "AmovPercMwlkSrasWrflDbl";
			WalkRB = "AmovPercMwlkSrasWrflDbr";
			WalkB = "AmovPercMwlkSrasWrflDb";
			PlayerWalkF = "AmovPercMwlkSrasWrflDf";
			PlayerWalkLF = "AmovPercMwlkSrasWrflDfl";
			PlayerWalkRF = "AmovPercMwlkSrasWrflDfr";
			PlayerWalkL = "AmovPercMwlkSrasWrflDl";
			PlayerWalkR = "AmovPercMwlkSrasWrflDr";
			PlayerWalkLB = "AmovPercMwlkSrasWrflDbl";
			PlayerWalkRB = "AmovPercMwlkSrasWrflDbr";
			PlayerWalkB = "AmovPercMwlkSrasWrflDb";
			SlowF = "AmovPercMrunSrasWrflDf_ldst";
			SlowLF = "AmovPercMrunSrasWrflDfl_ldst";
			SlowRF = "AmovPercMrunSrasWrflDfr_ldst";
			SlowL = "AmovPercMrunSrasWrflDl_ldst";
			SlowR = "AmovPercMrunSrasWrflDr_ldst";
			SlowLB = "AmovPercMrunSrasWrflDbl_ldst";
			SlowRB = "AmovPercMrunSrasWrflDbr_ldst";
			SlowB = "AmovPercMrunSrasWrflDb_ldst";
			PlayerSlowF = "AmovPercMrunSrasWrflDf";
			PlayerSlowLF = "AmovPercMrunSrasWrflDfl";
			PlayerSlowRF = "AmovPercMrunSrasWrflDfr";
			PlayerSlowL = "AmovPercMrunSrasWrflDl";
			PlayerSlowR = "AmovPercMrunSrasWrflDr";
			PlayerSlowLB = "AmovPercMrunSrasWrflDbl";
			PlayerSlowRB = "AmovPercMrunSrasWrflDbr";
			PlayerSlowB = "AmovPercMrunSrasWrflDb";
			FastF = "AmovPercMevaSrasWrflDf";
			FastLF = "AmovPercMevaSrasWrflDfl";
			FastRF = "AmovPercMevaSrasWrflDfr";
			FastL = "AmovPercMevaSrasWrflDl";
			FastR = "AmovPercMevaSrasWrflDr";
			FastLB = "AmovPercMrunSrasWrflDbl";
			FastRB = "AmovPercMrunSrasWrflDbr";
			FastB = "AmovPercMrunSrasWrflDb";
			TactF = "AmovPercMtacSrasWrflDf";
			TactLF = "AmovPercMtacSrasWrflDfl";
			TactRF = "AmovPercMtacSrasWrflDfr";
			TactL = "AmovPercMtacSrasWrflDl";
			TactR = "AmovPercMtacSrasWrflDr";
			TactLB = "AmovPercMtacSrasWrflDbl";
			TactRB = "AmovPercMtacSrasWrflDbr";
			TactB = "AmovPercMtacSrasWrflDb";
			PlayerTactF = "AmovPercMtacSrasWrflDf";
			PlayerTactLF = "AmovPercMtacSrasWrflDfl";
			PlayerTactRF = "AmovPercMtacSrasWrflDfr";
			PlayerTactL = "AmovPercMtacSrasWrflDl";
			PlayerTactR = "AmovPercMtacSrasWrflDr";
			PlayerTactLB = "AmovPercMtacSrasWrflDbl";
			PlayerTactRB = "AmovPercMtacSrasWrflDbr";
			PlayerTactB = "AmovPercMtacSrasWrflDb";
			EvasiveLeft = "";
			EvasiveRight = "";
			up = "AmovPknlMstpSrasWrflDnon";
			getOver = "AovrPercMstpSrasWrflDf";
			salute = "AmovPercMstpSrasWrflDnon_salute";
			PlayerStand = "AmovPercMstpSrasWrflDnon";
			upDegree = "ManPosCombat";
			PlayerCrouch = "AmovPknlMstpSrasWrflDnon";
			Stand = "AmovPercMstpSlowWrflDnon";
			WeaponOn = "AmovPercMstpSrasWlnrDnon";
			Crouch = "AmovPknlMstpSrasWrflDnon";
			CanNotMove = "AmovPercMstpSlowWrflDnon";
			saluteOff = "AmovPercMstpSrasWrflDnon";
			GetInBoat = "GetInHeli_Transport_01Cargo";
			GetOutBoat = "AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWrflDnon_getOutLow";
		};
		class RifleStandActions: RifleBaseStandActions
		{
			PlayerStand = "";
			Diary = "";
			Gear = "AinvPercMstpSrasWrflDnon";
			AdjustF = "AadjPercMstpSrasWrflDup";
			AdjustLF = "AadjPercMstpSrasWrflDup";
			AdjustRF = "AadjPercMstpSrasWrflDup";
			AdjustB = "AadjPercMstpSrasWrflDdown";
			AdjustLB = "AadjPercMstpSrasWrflDdown";
			AdjustRB = "AadjPercMstpSrasWrflDdown";
			AdjustL = "AadjPercMstpSrasWrflDleft";
			AdjustR = "AadjPercMstpSrasWrflDright";
			startDive = "AdvePercMstpSnonWrflDnon";
			SurfaceDive = "AsdvPercMstpSnonWrflDnon";
			BottomDive = "AbdvPercMstpSnonWrflDnon";
			putDown = "AmovPercMstpSrasWrflDnon_AinvPercMstpSrasWrflDnon_Putdown";
		};
		class RifleStandActionsNoAdjust: RifleStandActions
		{
			AdjustF = "";
			AdjustLF = "";
			AdjustRF = "";
			AdjustB = "";
			AdjustLB = "";
			AdjustRB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleStandActions_gear: RifleLowStandActions
		{
			Stop = "AmovPercMstpSrasWrflDnon_gear";
			StopRelaxed = "AmovPercMstpSrasWrflDnon_gear";
			Default = "AmovPercMstpSrasWrflDnon_gear";
			PlayerStand = "AmovPercMstpSrasWrflDnon";
			Civil = "AmovPercMstpSnonWnonDnon_gear";
			HandGunOn = "AmovPercMstpSrasWpstDnon_gear";
		};
		class RifleStandActions_diary: RifleStandActions_gear
		{
			Stop = "AmovPercMstpSrasWrflDnon_diary";
			StopRelaxed = "AmovPercMstpSrasWrflDnon_diary";
			Default = "AmovPercMstpSrasWrflDnon_diary";
		};
		class RifleStandActions_Idle: RifleStandActions{};
		class RifleStandEvasiveActionsF_Idle: RifleStandActions_Idle{};
		class RifleStandSaluteActions_Idle: RifleStandActions_Idle
		{
			StopRelaxed = "AidlPercMstpSrasWrflDnon_Salute";
			Stop = "AidlPercMstpSrasWrflDnon_Salute";
			Default = "AidlPercMstpSrasWrflDnon_Salute";
			Salute = "AmovPercMstpSrasWrflDnon";
			SitDown = "";
		};
		class RifleStandActionsRunF: RifleStandActionsNoAdjust
		{
			PlayerStand = "AmovPercMtacSrasWrflDf";
			turnSpeed = 4.5;
			PlayerCrouch = "AmovPknlMrunSrasWrflDf";
			Up = "AmovPknlMrunSrasWrflDf";
			ThrowPrepare = "AmovPercMrunSrasWrflDf";
			AdjustF = "";
			Combat = "AmovPercMtacSrasWrflDf";
			Stand = "AmovPercMrunSlowWrflDf";
		};
		class RifleStandActionsWlkF: RifleStandActionsNoAdjust
		{
			PlayerCrouch = "AmovPknlMwlkSrasWrflDf";
			Up = "AmovPknlMwlkSrasWrflDf";
			ThrowPrepare = "AmovPercMwlkSrasWrflDf";
			AdjustF = "";
			Combat = "AmovPercMwlkSrasWrflDf";
			Stand = "AmovPercMwlkSlowWrflDf";
		};
		class RifleStandActionsRunFL: RifleStandActionsNoAdjust
		{
			PlayerStand = "AmovPercMtacSrasWrflDfl";
			turnSpeed = 4.5;
			PlayerCrouch = "AmovPknlMrunSrasWrflDfl";
			Up = "AmovPknlMrunSrasWrflDfl";
			ThrowPrepare = "AmovPercMrunSrasWrflDfl";
			Stand = "AmovPercMrunSlowWrflDfl";
		};
		class RifleStandActionsWlkFL: RifleStandActionsNoAdjust
		{
			PlayerCrouch = "AmovPknlMwlkSrasWrflDfl";
			Up = "AmovPknlMwlkSrasWrflDfl";
			ThrowPrepare = "AmovPercMwlkSrasWrflDfl";
			Stand = "AmovPercMwlkSlowWrflDfl";
		};
		class RifleStandActionsRunL: RifleStandActionsNoAdjust
		{
			PlayerStand = "AmovPercMtacSrasWrflDl";
			turnSpeed = 4.5;
			PlayerCrouch = "AmovPknlMrunSrasWrflDl";
			Up = "AmovPknlMrunSrasWrflDl";
			AdjustL = "";
			Stand = "AmovPercMrunSlowWrflDl";
		};
		class RifleStandActionsWlkL: RifleStandActionsNoAdjust
		{
			PlayerCrouch = "AmovPknlMwlkSrasWrflDl";
			Up = "AmovPknlMwlkSrasWrflDl";
			AdjustL = "";
			Stand = "AmovPercMwlkSlowWrflDl";
		};
		class RifleStandActionsRunBL: RifleStandActionsNoAdjust
		{
			PlayerStand = "AmovPercMtacSrasWrflDbl";
			turnSpeed = 4.5;
			PlayerCrouch = "AmovPknlMrunSrasWrflDbl";
			Up = "AmovPknlMrunSrasWrflDbl";
			Stand = "AmovPercMrunSlowWrflDbl";
		};
		class RifleStandActionsWlkBL: RifleStandActionsNoAdjust
		{
			PlayerCrouch = "AmovPknlMwlkSrasWrflDbl";
			Up = "AmovPknlMwlkSrasWrflDbl";
			Stand = "AmovPercMwlkSlowWrflDbl";
		};
		class RifleStandActionsRunB: RifleStandActionsNoAdjust
		{
			PlayerStand = "AmovPercMtacSrasWrflDb";
			turnSpeed = 4.5;
			PlayerCrouch = "AmovPknlMrunSrasWrflDb";
			Up = "AmovPknlMrunSrasWrflDb";
			AdjustB = "";
			Stand = "AmovPercMrunSlowWrflDb";
		};
		class RifleStandActionsWlkB: RifleStandActionsNoAdjust
		{
			PlayerCrouch = "AmovPknlMwlkSrasWrflDb";
			Up = "AmovPknlMwlkSrasWrflDb";
			AdjustB = "";
			Stand = "AmovPercMwlkSlowWrflDb";
		};
		class RifleStandActionsRunBR: RifleStandActionsNoAdjust
		{
			PlayerStand = "AmovPercMtacSrasWrflDbr";
			turnSpeed = 4.5;
			PlayerCrouch = "AmovPknlMrunSrasWrflDbr";
			Up = "AmovPknlMrunSrasWrflDbr";
			Stand = "AmovPercMrunSlowWrflDbr";
		};
		class RifleStandActionsWlkBR: RifleStandActionsNoAdjust
		{
			PlayerCrouch = "";
			Up = "AmovPknlMwlkSrasWrflDbr";
			Stand = "AmovPercMwlkSlowWrflDbr";
		};
		class RifleStandActionsRunR: RifleStandActionsNoAdjust
		{
			PlayerStand = "AmovPercMtacSrasWrflDr";
			turnSpeed = 4.5;
			PlayerCrouch = "AmovPknlMrunSrasWrflDr";
			Up = "AmovPknlMrunSrasWrflDr";
			AdjustR = "";
			Stand = "AmovPercMrunSlowWrflDr";
		};
		class RifleStandActionsWlkR: RifleStandActionsNoAdjust
		{
			PlayerCrouch = "AmovPknlMwlkSrasWrflDr";
			Up = "AmovPknlMwlkSrasWrflDr";
			AdjustR = "";
			Stand = "AmovPercMwlkSlowWrflDr";
		};
		class RifleStandActionsRunFR: RifleStandActionsNoAdjust
		{
			PlayerStand = "AmovPercMtacSrasWrflDfr";
			turnSpeed = 4.5;
			PlayerCrouch = "AmovPknlMrunSrasWrflDfr";
			Up = "AmovPknlMrunSrasWrflDfr";
			ThrowPrepare = "AmovPercMrunSrasWrflDfr";
			Stand = "AmovPercMrunSlowWrflDfr";
		};
		class RifleStandActionsWlkFR: RifleStandActionsNoAdjust
		{
			PlayerCrouch = "AmovPknlMwlkSrasWrflDfr";
			Up = "AmovPknlMwlkSrasWrflDfr";
			ThrowPrepare = "AmovPercMwlkSrasWrflDfr";
			Stand = "AmovPercMwlkSlowWrflDfr";
		};
		class RifleStandActionsTacF: RifleStandActionsNoAdjust
		{
			PlayerCrouch = "AmovPknlMtacSrasWrflDf";
			Up = "AmovPknlMtacSrasWrflDf";
			ThrowPrepare = "AmovPercMTacSrasWrflDf";
			AdjustF = "";
			Combat = "AmovPercMTacSrasWrflDf";
			Stand = "AmovPercMtacSlowWrflDf";
		};
		class RifleStandActionsTacFL: RifleStandActionsNoAdjust
		{
			PlayerCrouch = "AmovPknlMtacSrasWrflDfl";
			Up = "AmovPknlMtacSrasWrflDfl";
			ThrowPrepare = "AmovPercMTacSrasWrflDfl";
			Stand = "AmovPercMTacSlowWrflDfl";
		};
		class RifleStandActionsTacL: RifleStandActionsNoAdjust
		{
			PlayerCrouch = "AmovPknlMtacSrasWrflDl";
			Up = "AmovPknlMtacSrasWrflDl";
			AdjustL = "";
			Stand = "AmovPercMtacSlowWrflDl";
		};
		class RifleStandActionsTacBL: RifleStandActionsNoAdjust
		{
			PlayerCrouch = "AmovPknlMtacSrasWrflDbl";
			Up = "AmovPknlMtacSrasWrflDbl";
			Stand = "AmovPercMtacSlowWrflDbl";
		};
		class RifleStandActionsTacB: RifleStandActionsNoAdjust
		{
			PlayerCrouch = "AmovPknlMtacSrasWrflDb";
			Up = "AmovPknlMtacSrasWrflDb";
			Stand = "AmovPercMTacSlowWrflDb";
			AdjustB = "";
		};
		class RifleStandActionsTacBR: RifleStandActionsNoAdjust
		{
			PlayerCrouch = "AmovPknlMtacSrasWrflDbr";
			Up = "AmovPknlMtacSrasWrflDbr";
			Stand = "AmovPercMtacSlowWrflDbr";
		};
		class RifleStandActionsTacR: RifleStandActionsNoAdjust
		{
			PlayerCrouch = "AmovPknlMtacSrasWrflDr";
			Up = "AmovPknlMtacSrasWrflDr";
			AdjustR = "";
			Stand = "AmovPercMtacSlowWrflDr";
		};
		class RifleStandActionsTacFR: RifleStandActionsNoAdjust
		{
			PlayerCrouch = "AmovPknlMtacSrasWrflDfr";
			Up = "AmovPknlMtacSrasWrflDfr";
			ThrowPrepare = "AmovPercMTacSrasWrflDfr";
			Stand = "AmovPercMtacSlowWrflDfr";
		};
		class RifleStandActionsTacLnr: RifleStandActionsTacF
		{
			upDegree = "ManPosWeapon";
			PlayerWalkF = "AmovPercMtacSrasWlnrDf";
			PlayerWalkLF = "AmovPercMtacSrasWlnrDfl";
			PlayerWalkRF = "AmovPercMtacSrasWlnrDfr";
			PlayerTactF = "AmovPercMtacSrasWlnrDf";
			PlayerTactLF = "AmovPercMtacSrasWlnrDfl";
			PlayerTactRF = "AmovPercMtacSrasWlnrDfr";
			PlayerSlowF = "AmovPercMtacSrasWlnrDf";
			PlayerSlowLF = "AmovPercMtacSrasWlnrDfl";
			PlayerSlowRF = "AmovPercMtacSrasWlnrDfr";
			WalkF = "AmovPercMtacSrasWlnrDf";
			WalkLF = "AmovPercMtacSrasWlnrDfl";
			WalkRF = "AmovPercMtacSrasWlnrDfr";
			TactF = "AmovPercMtacSrasWlnrDf";
			TactLF = "AmovPercMtacSrasWlnrDfl";
			TactLR = "AmovPercMtacSrasWlnrDfr";
			SlowF = "AmovPercMtacSrasWlnrDf";
			SlowLF = "AmovPercMtacSrasWlnrDfl";
			SlowLR = "AmovPercMtacSrasWlnrDfr";
		};
		class RifleStandEvasiveActionsF: RifleStandActionsNoAdjust
		{
			turnSpeed = 4;
			salute = "";
			Up = "AmovPknlMevaSrasWrflDf";
			PlayerCrouch = "AmovPknlMevaSrasWrflDf";
			sitDown = "";
			AdjustF = "AmovPercMrunSrasWrflDf";
		};
		class RifleStandEvasiveActionsFL: RifleStandActionsNoAdjust
		{
			turnSpeed = 4;
			salute = "";
			sitDown = "";
			Up = "AmovPknlMevaSrasWrflDfl";
			PlayerCrouch = "AmovPknlMevaSrasWrflDfl";
			AdjustLF = "AmovPercMrunSrasWrflDfl";
		};
		class RifleStandEvasiveActionsFR: RifleStandActionsNoAdjust
		{
			turnSpeed = 4;
			salute = "";
			sitDown = "";
			Up = "AmovPknlMevaSrasWrflDfr";
			PlayerCrouch = "AmovPknlMevaSrasWrflDfr";
			AdjustRF = "AmovPercMrunSrasWrflDfr";
		};
		class RifleStandEvasiveActionsR: RifleStandActionsRunR
		{
			turnSpeed = 4;
			PlayerProne = "AadjPpneMstpSrasWrflDright";
			Down = "AadjPpneMstpSrasWrflDright";
			Up = "AmovPknlMevaSrasWrflDr";
			PlayerCrouch = "AmovPknlMevaSrasWrflDr";
		};
		class RifleStandEvasiveActionsL: RifleStandActionsRunL
		{
			turnSpeed = 4;
			PlayerProne = "AadjPpneMstpSrasWrflDleft";
			Down = "AadjPpneMstpSrasWrflDleft";
			Up = "AmovPknlMevaSrasWrflDl";
			PlayerCrouch = "AmovPknlMevaSrasWrflDl";
		};
		class RifleLowStandSaluteActions: RifleBaseLowStandActions
		{
			stop = "AmovPercMstpSlowWrflDnon_Salute";
			StopRelaxed = "AmovPercMstpSlowWrflDnon_Salute";
			default = "AmovPercMstpSlowWrflDnon_Salute";
			salute = "AmovPercMstpSlowWrflDnon";
			sitDown = "";
		};
		class RifleStandSaluteActions: RifleBaseStandActions
		{
			stop = "AmovPercMstpSrasWrflDnon_Salute";
			StopRelaxed = "AmovPercMstpSrasWrflDnon_Salute";
			default = "AmovPercMstpSrasWrflDnon_Salute";
			salute = "AmovPercMstpSrasWrflDnon";
			sitDown = "";
		};
		class RifleLowSitActions: RifleBaseLowStandActions
		{
			turnL = "";
			turnR = "";
			stop = "AmovPsitMstpSlowWrflDnon";
			StopRelaxed = "AmovPsitMstpSlowWrflDnon";
			default = "AmovPsitMstpSlowWrflDnon";
			sitDown = "AmovPercMstpSlowWrflDnon";
			Gear = "";
			Diary = "";
			GetOver = "";
			stance = "ManStanceCrouch";
		};
		class RifleSitActions: RifleBaseStandActions
		{
			turnSpeed = 0;
			turnL = "";
			turnR = "";
			stop = "AmovPsitMstpSrasWrflDnon";
			StopRelaxed = "AmovPsitMstpSrasWrflDnon";
			default = "AmovPsitMstpSrasWrflDnon";
			sitDown = "AmovPercMstpSrasWrflDnon";
			Gear = "";
			Diary = "";
			GetOver = "";
			stance = "ManStanceCrouch";
		};
		class RifleSitactionTest: RifleSitActions
		{
			Stop = "sitRfl_R_BidleLoopTest";
			StopRelaxed = "sitRfl_R_BidleLoopTest";
			Default = "sitRfl_R_BidleLoopTest";
		};
		class RifleStandTakeActions: RifleBaseLowStandActions
		{
			stop = "AmovPercMstpSrasWrflDnon_gear";
			StopRelaxed = "AmovPercMstpSrasWrflDnon_gear";
			default = "";
			salute = "";
			sitDown = "";
			PutDown = "AmovPercMstpSrasWrflDnon";
		};
		class RifleKneelActions: RifleBaseStandActions
		{
			AdjustF = "AadjPknlMstpSrasWrflDup";
			AdjustLF = "AadjPknlMstpSrasWrflDup";
			AdjustRF = "AadjPknlMstpSrasWrflDup";
			AdjustB = "AadjPknlMstpSrasWrflDdown";
			AdjustLB = "AadjPknlMstpSrasWrflDdown";
			AdjustRB = "AadjPknlMstpSrasWrflDdown";
			AdjustL = "AadjPknlMstpSrasWrflDleft";
			AdjustR = "AadjPknlMstpSrasWrflDright";
			stop = "AmovPknlMstpSrasWrflDnon";
			default = "AmovPknlMstpSrasWrflDnon";
			stopRelaxed = "AidlPknlMstpSrasWrflDnon_AI";
			turnL = "AmovPknlMstpSrasWrflDnon_turnL";
			turnR = "AmovPknlMstpSrasWrflDnon_turnR";
			turnLRelaxed = "AmovPknlMstpSrasWrflDnon_turnL";
			turnRRelaxed = "AmovPknlMstpSrasWrflDnon_turnR";
			putDown = "AmovPknlMstpSrasWrflDnon_AinvPknlMstpSrasWrflDnon_Putdown";
			reloadMGun = "AmovPknlMstpSrasWrflDnon";
			reloadMortar = "AmovPknlMstpSrasWrflDnon";
			throwPrepare = "AwopPknlMstpSgthWrflDnon_Start";
			WalkF = "AmovPknlMwlkSrasWrflDf";
			WalkLF = "AmovPknlMwlkSrasWrflDfl";
			WalkRF = "AmovPknlMwlkSrasWrflDfr";
			WalkL = "AmovPknlMwlkSrasWrflDl";
			WalkR = "AmovPknlMwlkSrasWrflDr";
			WalkLB = "AmovPknlMwlkSrasWrflDbl";
			WalkRB = "AmovPknlMwlkSrasWrflDbr";
			WalkB = "AmovPknlMwlkSrasWrflDb";
			PlayerWalkF = "AmovPknlMwlkSrasWrflDf";
			PlayerWalkLF = "AmovPknlMwlkSrasWrflDfl";
			PlayerWalkRF = "AmovPknlMwlkSrasWrflDfr";
			PlayerWalkL = "AmovPknlMwlkSrasWrflDl";
			PlayerWalkR = "AmovPknlMwlkSrasWrflDr";
			PlayerWalkLB = "AmovPknlMwlkSrasWrflDbl";
			PlayerWalkRB = "AmovPknlMwlkSrasWrflDbr";
			PlayerWalkB = "AmovPknlMwlkSrasWrflDb";
			SlowF = "AmovPknlMrunSrasWrflDf";
			SlowLF = "AmovPknlMrunSrasWrflDfl";
			SlowRF = "AmovPknlMrunSrasWrflDfr";
			SlowL = "AmovPknlMrunSrasWrflDl";
			SlowR = "AmovPknlMrunSrasWrflDr";
			SlowLB = "AmovPknlMrunSrasWrflDbl";
			SlowRB = "AmovPknlMrunSrasWrflDbr";
			SlowB = "AmovPknlMrunSrasWrflDb";
			PlayerSlowF = "AmovPknlMrunSrasWrflDf";
			PlayerSlowLF = "AmovPknlMrunSrasWrflDfl";
			PlayerSlowRF = "AmovPknlMrunSrasWrflDfr";
			PlayerSlowL = "AmovPknlMrunSrasWrflDl";
			PlayerSlowR = "AmovPknlMrunSrasWrflDr";
			PlayerSlowLB = "AmovPknlMrunSrasWrflDbl";
			PlayerSlowRB = "AmovPknlMrunSrasWrflDbr";
			PlayerSlowB = "AmovPknlMrunSrasWrflDb";
			FastF = "AmovPknlMevaSrasWrflDf";
			FastLF = "AmovPknlMevaSrasWrflDfl";
			FastRF = "AmovPknlMevaSrasWrflDfr";
			FastL = "AmovPknlMevaSrasWrflDl";
			FastR = "AmovPknlMevaSrasWrflDr";
			FastLB = "AmovPknlMrunSrasWrflDbl";
			FastRB = "AmovPknlMrunSrasWrflDbr";
			FastB = "AmovPknlMrunSrasWrflDb";
			TactF = "AmovPknlMtacSrasWrflDf";
			TactLF = "AmovPknlMtacSrasWrflDfl";
			TactRF = "AmovPknlMtacSrasWrflDfr";
			TactL = "AmovPknlMtacSrasWrflDl";
			TactR = "AmovPknlMtacSrasWrflDr";
			TactLB = "AmovPknlMtacSrasWrflDbl";
			TactRB = "AmovPknlMtacSrasWrflDbr";
			TactB = "AmovPknlMtacSrasWrflDb";
			PlayerTactF = "AmovPknlMtacSrasWrflDf";
			PlayerTactLF = "AmovPknlMtacSrasWrflDfl";
			PlayerTactRF = "AmovPknlMtacSrasWrflDfr";
			PlayerTactL = "AmovPknlMtacSrasWrflDl";
			PlayerTactR = "AmovPknlMtacSrasWrflDr";
			PlayerTactLB = "AmovPknlMtacSrasWrflDbl";
			PlayerTactRB = "AmovPknlMtacSrasWrflDbr";
			PlayerTactB = "AmovPknlMtacSrasWrflDb";
			EvasiveLeft = "AmovPknlMevaSrasWrflDfl";
			EvasiveRight = "AmovPknlMevaSrasWrflDfr";
			up = "AmovPercMstpSrasWrflDnon";
			weaponOn = "AmovPknlMstpSrasWlnrDnon";
			weaponOff = "AmovPknlMstpSrasWrflDnon";
			binocOn = "AwopPknlMstpSoptWbinDnon_rfl";
			binocOff = "AmovPknlMstpSrasWrflDnon";
			handGunOn = "AmovPknlMstpSrasWpstDnon";
			takeFlag = "AinvPknlMstpSlayWrflDnon_1";
			Stand = "AmovPknlMstpSlowWrflDnon";
			CanNotMove = "AmovPknlMstpSrasWrflDnon";
			FireNotPossible = "AmovPknlMstpSrasWrflDnon";
			strokeGun = "AmovPknlMstpSrasWrflDnon";
			salute = "";
			turnSpeed = 4.5;
			upDegree = "ManPosCrouch";
			stance = "ManStanceCrouch";
			PlayerCrouch = "";
			Diary = "";
			Gear = "AinvPknlMstpSrasWrflDnon";
			medicStop = "AmovPknlMstpSrasWrflDnon";
			StartFreefall = "AfalPknlMstpSrasWrflDnon";
			PrimaryWeapon = "AmovPknlMstpSrasWrflDnon";
			SecondaryWeapon = "AmovPknlMstpSrasWlnrDnon";
			Binoculars = "AmovPknlMstpSoptWbinDnon";
		};
		class RifleKneelActionsNoAdjust: RifleKneelActions
		{
			AdjustF = "";
			AdjustLF = "";
			AdjustRF = "";
			AdjustB = "";
			AdjustLB = "";
			AdjustRB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleCrouchActions: RifleKneelActions
		{
			Stop = "AmovPcrhMstpSrasWrflDnon";
			Crouch = "AmovPcrhMstpSrasWrflDnon";
			PlayerCrouch = "AmovPknlMstpSrasWrflDnon";
			AdjustF = "AadjPcrhMstpSrasWrflDup";
			AdjustLF = "AadjPcrhMstpSrasWrflDup";
			AdjustRF = "AadjPcrhMstpSrasWrflDup";
			AdjustB = "AadjPcrhMstpSrasWrflDdown";
			AdjustLB = "AadjPcrhMstpSrasWrflDdown";
			AdjustRB = "AadjPcrhMstpSrasWrflDdown";
			AdjustL = "AadjPcrhMstpSrasWrflDleft";
			AdjustR = "AadjPcrhMstpSrasWrflDright";
		};
		class RifleKneelActions_gear: RifleKneelActions
		{
			Stop = "AmovPknlMstpSrasWrflDnon_gear";
			StopRelaxed = "AmovPknlMstpSrasWrflDnon_gear";
			Default = "AmovPknlMstpSrasWrflDnon_gear";
			PlayerCrouch = "AmovPknlMstpSrasWrflDnon";
			Civil = "AmovPknlMstpSnonWnonDnon_gear";
			HandGunOn = "AmovPknlMstpSrasWpstDnon_gear";
		};
		class RifleKneelActions_explo: RifleKneelActions_gear
		{
			Stop = "AmovPknlMstpSrasWrflDnon";
			StopRelaxed = "AmovPknlMstpSrasWrflDnon";
		};
		class RifleKneelActions_diary: RifleKneelActions_gear
		{
			Stop = "AmovPknlMstpSrasWrflDnon_diary";
			StopRelaxed = "AmovPknlMstpSrasWrflDnon_diary";
			Default = "AmovPknlMstpSrasWrflDnon_diary";
		};
		class RifleKneelActionsRunF: RifleKneelActions
		{
			PlayerStand = "AmovPercMrunSrasWrflDf";
			PlayerCrouch = "AmovPknlMtacSrasWrflDf";
			Up = "AmovPercMrunSrasWrflDf";
			AdjustF = "";
			Stand = "AmovPknlMrunSlowWrflDf";
		};
		class RifleKneelActionsWlkF: RifleKneelActionsNoAdjust
		{
			PlayerStand = "AmovPercMwlkSrasWrflDf";
			Up = "AmovPercMwlkSrasWrflDf";
			AdjustF = "";
			Stand = "AmovPknlMwlkSlowWrflDf";
		};
		class RifleKneelActionsRunFL: RifleKneelActionsNoAdjust
		{
			PlayerStand = "AmovPercMrunSrasWrflDfl";
			PlayerCrouch = "AmovPknlMtacSrasWrflDfl";
			Up = "AmovPercMrunSrasWrflDfl";
			Stand = "AmovPknlMrunSlowWrflDfl";
		};
		class RifleKneelActionsWlkFL: RifleKneelActionsNoAdjust
		{
			PlayerStand = "AmovPercMwlkSrasWrflDfl";
			Up = "AmovPercMwlkSrasWrflDfl";
			Stand = "AmovPknlMwlkSlowWrflDfl";
		};
		class RifleKneelActionsRunL: RifleKneelActionsNoAdjust
		{
			PlayerStand = "AmovPercMrunSrasWrflDl";
			PlayerCrouch = "AmovPknlMtacSrasWrflDl";
			Up = "AmovPercMrunSrasWrflDl";
			AdjustL = "";
			Stand = "AmovPknlMrunSlowWrflDl";
		};
		class RifleKneelActionsWlkL: RifleKneelActionsNoAdjust
		{
			PlayerStand = "AmovPercMwlkSrasWrflDl";
			Up = "AmovPercMwlkSrasWrflDl";
			AdjustL = "";
			Stand = "AmovPknlMwlkSlowWrflDl";
		};
		class RifleKneelActionsRunBL: RifleKneelActionsNoAdjust
		{
			PlayerStand = "AmovPercMrunSrasWrfldbl";
			PlayerCrouch = "AmovPknlMtacSrasWrflDbl";
			Up = "AmovPercMrunSrasWrfldbl";
			Stand = "AmovPknlMrunSlowWrflDbl";
		};
		class RifleKneelActionsWlkBL: RifleKneelActionsNoAdjust
		{
			PlayerStand = "AmovPercMwlkSrasWrfldbl";
			Up = "AmovPercMwlkSrasWrfldbl";
			Stand = "AmovPknlMwlkSlowWrflDbl";
		};
		class RifleKneelActionsRunB: RifleKneelActionsNoAdjust
		{
			PlayerStand = "AmovPercMrunSrasWrflDb";
			PlayerCrouch = "AmovPknlMtacSrasWrflDb";
			Up = "AmovPercMrunSrasWrflDb";
			AdjustB = "";
			Stand = "AmovPknlMrunSlowWrflDb";
		};
		class RifleKneelActionsWlkB: RifleKneelActionsNoAdjust
		{
			PlayerStand = "AmovPercMwlkSrasWrflDb";
			Up = "AmovPercMwlkSrasWrflDb";
			AdjustB = "";
			Stand = "AmovPknlMwlkSlowWrflDb";
		};
		class RifleKneelActionsRunBR: RifleKneelActionsNoAdjust
		{
			PlayerStand = "AmovPercMrunSrasWrflDbr";
			PlayerCrouch = "AmovPknlMtacSrasWrflDbr";
			Up = "AmovPercMrunSrasWrflDbr";
			Stand = "AmovPknlMrunSlowWrflDbr";
		};
		class RifleKneelActionsWlkBR: RifleKneelActionsNoAdjust
		{
			PlayerStand = "AmovPercMwlkSrasWrflDbr";
			Up = "AmovPercMwlkSrasWrflDbr";
			Stand = "AmovPknlMwlkSlowWrflDbr";
		};
		class RifleKneelActionsRunR: RifleKneelActionsNoAdjust
		{
			PlayerStand = "AmovPercMrunSrasWrflDr";
			PlayerCrouch = "AmovPknlMtacSrasWrflDr";
			Up = "AmovPercMrunSrasWrflDr";
			AdjustR = "";
			Stand = "AmovPknlMrunSlowWrflDr";
		};
		class RifleKneelActionsWlkR: RifleKneelActionsNoAdjust
		{
			PlayerStand = "AmovPercMwlkSrasWrflDr";
			Up = "AmovPercMwlkSrasWrflDr";
			AdjustR = "";
			Stand = "AmovPknlMwlkSlowWrflDr";
		};
		class RifleKneelActionsRunFR: RifleKneelActionsNoAdjust
		{
			PlayerStand = "AmovPercMrunSrasWrflDfr";
			PlayerCrouch = "AmovPknlMtacSrasWrflDfr";
			Up = "AmovPercMrunSrasWrflDfr";
			Stand = "AmovPknlMrunSlowWrflDfr";
		};
		class RifleKneelActionsWlkFR: RifleKneelActionsNoAdjust
		{
			PlayerStand = "AmovPercMwlkSrasWrflDfr";
			Up = "AmovPercMwlkSrasWrflDfr";
			Stand = "AmovPknlMwlkSlowWrflDfr";
		};
		class RifleKneelActionsTacF: RifleKneelActionsNoAdjust
		{
			PlayerStand = "AmovPercMTacSrasWrflDf";
			Up = "AmovPercMTacSrasWrflDf";
			AdjustF = "";
			Stand = "AmovPknlMtacSlowWrflDf";
		};
		class RifleKneelActionsTacFL: RifleKneelActionsNoAdjust
		{
			PlayerStand = "AmovPercMTacSrasWrflDfl";
			Up = "AmovPercMTacSrasWrflDfl";
			Stand = "AmovPknlMtacSlowWrflDfl";
		};
		class RifleKneelActionsTacL: RifleKneelActionsNoAdjust
		{
			PlayerStand = "AmovPercMTacSrasWrflDl";
			Up = "AmovPercMTacSrasWrflDl";
			AdjustL = "";
			Stand = "AmovPknlMtacSlowWrflDl";
		};
		class RifleKneelActionsTacBL: RifleKneelActionsNoAdjust
		{
			PlayerStand = "AmovPercMTacSrasWrfldbl";
			Up = "AmovPercMTacSrasWrfldbl";
			Stand = "AmovPknlMtacSlowWrflDbl";
		};
		class RifleKneelActionsTacB: RifleKneelActionsNoAdjust
		{
			PlayerStand = "AmovPercMTacSrasWrflDb";
			Up = "AmovPercMTacSrasWrflDb";
			AdjustB = "";
			Stand = "AmovPknlMtacSlowWrflDb";
		};
		class RifleKneelActionsTacBR: RifleKneelActionsNoAdjust
		{
			PlayerStand = "AmovPercMTacSrasWrflDbr";
			Up = "AmovPercMTacSrasWrflDbr";
			Stand = "AmovPknlMtacSlowWrflDbr";
		};
		class RifleKneelActionsTacR: RifleKneelActionsNoAdjust
		{
			PlayerStand = "AmovPercMTacSrasWrflDr";
			Up = "AmovPercMTacSrasWrflDr";
			AdjustR = "";
			Stand = "AmovPknlMtacSlowWrflDr";
		};
		class RifleKneelActionsTacFR: RifleKneelActionsNoAdjust
		{
			PlayerStand = "AmovPercMTacSrasWrflDfr";
			Up = "AmovPercMTacSrasWrflDfr";
			Stand = "AmovPknlMtacSlowWrflDfr";
		};
		class RifleKneelEvasiveActionsF: RifleKneelActionsNoAdjust
		{
			Up = "AmovPercMevaSrasWrflDf";
			PlayerStand = "AmovPercMevaSrasWrflDf";
			AdjustF = "AmovPknlMrunSrasWrflDf";
		};
		class RifleKneelEvasiveActionsFR: RifleKneelEvasiveActionsF
		{
			Up = "AmovPercMevaSrasWrflDfr";
			PlayerStand = "AmovPercMevaSrasWrflDfr";
			AdjustRF = "AmovPknlMrunSrasWrflDfr";
		};
		class RifleKneelEvasiveActionsFL: RifleKneelEvasiveActionsF
		{
			Up = "AmovPercMevaSrasWrflDfl";
			PlayerStand = "AmovPercMevaSrasWrflDfl";
			AdjustLF = "AmovPknlMrunSrasWrflDfl";
		};
		class RifleKneelEvasiveActionsR: RifleKneelActionsRunR
		{
			turnSpeed = 4;
			PlayerProne = "AadjPpneMstpSrasWrflDright";
			Down = "AadjPpneMstpSrasWrflDright";
			Up = "AmovPercMevaSrasWrflDr";
			PlayerStand = "AmovPercMevaSrasWrflDr";
		};
		class RifleKneelEvasiveActionsL: RifleKneelActionsRunL
		{
			turnSpeed = 4;
			PlayerProne = "AadjPpneMstpSrasWrflDleft";
			Down = "AadjPpneMstpSrasWrflDleft";
			Up = "AmovPercMevaSrasWrflDr";
			PlayerStand = "AmovPercMevaSrasWrflDr";
		};
		class RifleKneelLowActions: RifleKneelActions
		{
			Stop = "AmovPknlMstpSlowWrflDnon";
			StopRelaxed = "AidlPknlMstpSlowWrflDnon_AI";
			Default = "AmovPknlMstpSlowWrflDnon";
			TurnL = "AmovPknlMstpSlowWrflDnon_turnL";
			TurnR = "AmovPknlMstpSlowWrflDnon_turnR";
			TurnLRelaxed = "AmovPknlMstpSlowWrflDnon_turnL";
			TurnRRelaxed = "AmovPknlMstpSlowWrflDnon_turnR";
			WalkF = "AmovPknlMwlkSlowWrflDf";
			WalkLF = "AmovPknlMwlkSlowWrflDfl";
			WalkRF = "AmovPknlMwlkSlowWrflDfr";
			WalkL = "AmovPknlMwlkSlowWrflDl";
			WalkR = "AmovPknlMwlkSlowWrflDr";
			WalkLB = "AmovPknlMwlkSlowWrflDbl";
			WalkRB = "AmovPknlMwlkSlowWrflDbr";
			WalkB = "AmovPknlMwlkSlowWrflDb";
			PlayerWalkF = "AmovPknlMwlkSlowWrflDf";
			PlayerWalkLF = "AmovPknlMwlkSlowWrflDfl";
			PlayerWalkRF = "AmovPknlMwlkSlowWrflDfr";
			PlayerWalkL = "AmovPknlMwlkSlowWrflDl";
			PlayerWalkR = "AmovPknlMwlkSlowWrflDr";
			PlayerWalkLB = "AmovPknlMwlkSlowWrflDbl";
			PlayerWalkRB = "AmovPknlMwlkSlowWrflDbr";
			PlayerWalkB = "AmovPknlMwlkSlowWrflDb";
			Up = "AmovPercMstpSlowWrflDnon";
			PlayerStand = "AmovPercMstpSlowWrflDnon";
			Combat = "AmovPknlMstpSrasWrflDnon";
			Stand = "AmovPknlMstpSrasWrflDnon";
			CanNotMove = "AmovPknlMstpSlowWrflDnon";
			WeaponOff = "AmovPknlMstpSlowWrflDnon";
			SlowF = "AmovPknlMrunSlowWrflDf";
			SlowLF = "AmovPknlMrunSlowWrflDfl";
			SlowRF = "AmovPknlMrunSlowWrflDfr";
			SlowL = "AmovPknlMrunSlowWrflDl";
			SlowR = "AmovPknlMrunSlowWrflDr";
			SlowLB = "AmovPknlMrunSlowWrflDbl";
			SlowRB = "AmovPknlMrunSlowWrflDbr";
			SlowB = "AmovPknlMrunSlowWrflDb";
			PlayerSlowF = "AmovPknlMrunSlowWrflDf";
			PlayerSlowLF = "AmovPknlMrunSlowWrflDfl";
			PlayerSlowRF = "AmovPknlMrunSlowWrflDfr";
			PlayerSlowL = "AmovPknlMrunSlowWrflDl";
			PlayerSlowR = "AmovPknlMrunSlowWrflDr";
			PlayerSlowLB = "AmovPknlMrunSlowWrflDbl";
			PlayerSlowRB = "AmovPknlMrunSlowWrflDbr";
			PlayerSlowB = "AmovPknlMrunSlowWrflDb";
			FastL = "AmovPknlMrunSlowWrflDl";
			FastR = "AmovPknlMrunSlowWrflDr";
			FastLB = "AmovPknlMrunSlowWrflDbl";
			FastRB = "AmovPknlMrunSlowWrflDbr";
			FastB = "AmovPknlMrunSlowWrflDb";
			FastF = "AmovPknlMevaSlowWrflDf";
			FastLF = "AmovPknlMevaSlowWrflDfl";
			FastRF = "AmovPknlMevaSlowWrflDfr";
			TactF = "AmovPknlMtacSlowWrflDf";
			TactLF = "AmovPknlMtacSlowWrflDfl";
			TactRF = "AmovPknlMtacSlowWrflDfr";
			TactL = "AmovPknlMtacSlowWrflDl";
			TactR = "AmovPknlMtacSlowWrflDr";
			TactLB = "AmovPknlMtacSlowWrflDbl";
			TactRB = "AmovPknlMtacSlowWrflDbr";
			TactB = "AmovPknlMtacSlowWrflDb";
			PlayerTactF = "AmovPknlMtacSlowWrflDf";
			PlayerTactLF = "AmovPknlMtacSlowWrflDfl";
			PlayerTactRF = "AmovPknlMtacSlowWrflDfr";
			PlayerTactL = "AmovPknlMtacSlowWrflDl";
			PlayerTactR = "AmovPknlMtacSlowWrflDr";
			PlayerTactLB = "AmovPknlMtacSlowWrflDbl";
			PlayerTactRB = "AmovPknlMtacSlowWrflDbr";
			PlayerTactB = "AmovPknlMtacSlowWrflDb";
			Diary = "";
			GetOver = "AovrPercMstpSlowWrflDf";
		};
		class RifleKneelLowActionsNoAdjust: RifleKneelLowActions
		{
			AdjustF = "";
			AdjustLF = "";
			AdjustRF = "";
			AdjustB = "";
			AdjustLB = "";
			AdjustRB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleKneelLowEvasiveActionsF: RifleKneelLowActionsNoAdjust
		{
			PlayerStand = "AmovPercMevaSlowWrflDf";
			AdjustF = "AmovPknlMrunSrasWrflDf";
			Up = "AmovPercMevaSlowWrflDf";
		};
		class RifleKneelLowEvasiveActionsFR: RifleKneelLowActionsNoAdjust
		{
			PlayerStand = "AmovPercMevaSlowWrflDfr";
			AdjustRF = "AmovPknlMrunSrasWrflDfr";
			Up = "AmovPercMevaSlowWrflDfr";
		};
		class RifleKneelLowEvasiveActionsFL: RifleKneelLowActionsNoAdjust
		{
			PlayerStand = "AmovPercMevaSlowWrflDfl";
			AdjustLF = "AmovPknlMrunSrasWrflDfl";
			Up = "AmovPercMevaSlowWrflDfl";
		};
		class RifleKneelLowActions_relax: RifleKneelLowActionsNoAdjust
		{
			SlowF = "AmovPercMrunSlowWrflDf";
		};
		class RifleKneelLowActions_gear: RifleKneelLowActionsNoAdjust
		{
			Stop = "AmovPknlMstpSlowWrflDnon_gear";
			StopRelaxed = "AmovPknlMstpSlowWrflDnon_gear";
			Default = "AmovPknlMstpSlowWrflDnon_gear";
			PlayerCrouch = "AmovPknlMstpSlowWrflDnon";
			Civil = "AmovPknlMstpSnonWnonDnon_gear";
			HandGunOn = "AmovPknlMstpSrasWpstDnon_gear";
		};
		class RifleKneelLowActions_explo: RifleKneelLowActions_gear
		{
			Stop = "AmovPknlMstpSlowWrflDnon";
			StopRelaxed = "AmovPknlMstpSlowWrflDnon";
		};
		class RifleKneelLowActions_diary: RifleKneelLowActions_gear
		{
			Stop = "AmovPknlMstpSlowWrflDnon_diary";
			StopRelaxed = "AmovPknlMstpSlowWrflDnon_diary";
			Default = "AmovPknlMstpSlowWrflDnon_diary";
		};
		class RifleKneelLowActionsRunF: RifleKneelLowActionsNoAdjust
		{
			PlayerStand = "AmovPercMrunSlowWrflDf";
			Up = "AmovPercMrunSlowWrflDf";
			fireNotPossible = "AmovPknlMtacSrasWrflDf";
			AdjustF = "";
			Stand = "AmovPknlMrunSrasWrflDf";
		};
		class RifleKneelLowActionsWlkF: RifleKneelLowActionsNoAdjust
		{
			PlayerStand = "AmovPercMwlkSlowWrflDf";
			Up = "AmovPercMwlkSlowWrflDf";
			fireNotPossible = "AmovPknlMwlkSrasWrflDf";
			AdjustF = "";
			Stand = "AmovPknlMwlkSrasWrflDf";
		};
		class RifleKneelLowActionsRunFL: RifleKneelLowActionsNoAdjust
		{
			PlayerStand = "AmovPercMrunSlowWrflDfl";
			Up = "AmovPercMrunSlowWrflDfl";
			fireNotPossible = "AmovPknlMtacSrasWrflDfl";
			Stand = "AmovPknlMrunSrasWrflDfl";
		};
		class RifleKneelLowActionsWlkFL: RifleKneelLowActionsNoAdjust
		{
			PlayerStand = "AmovPercMwlkSlowWrflDfl";
			Up = "AmovPercMwlkSlowWrflDfl";
			fireNotPossible = "AmovPknlMwlkSrasWrflDfl";
			Stand = "AmovPknlMwlkSrasWrflDfl";
		};
		class RifleKneelLowActionsRunL: RifleKneelLowActionsNoAdjust
		{
			PlayerStand = "AmovPercMrunSlowWrflDl";
			Up = "AmovPercMrunSlowWrflDl";
			fireNotPossible = "AmovPknlMtacSrasWrflDl";
			AdjustL = "";
			Stand = "AmovPknlMrunSrasWrflDl";
		};
		class RifleKneelLowActionsWlkL: RifleKneelLowActionsNoAdjust
		{
			PlayerStand = "AmovPercMwlkSlowWrflDl";
			Up = "AmovPercMwlkSlowWrflDl";
			fireNotPossible = "AmovPknlMwlkSrasWrflDl";
			AdjustL = "";
			Stand = "AmovPknlMwlkSrasWrflDl";
		};
		class RifleKneelLowActionsRunBL: RifleKneelLowActionsNoAdjust
		{
			PlayerStand = "AmovPercMrunSlowWrflDbl";
			Up = "AmovPercMrunSlowWrflDbl";
			fireNotPossible = "AmovPknlMtacSrasWrflDbl";
			Stand = "AmovPknlMrunSrasWrflDbl";
		};
		class RifleKneelLowActionsWlkBL: RifleKneelLowActionsNoAdjust
		{
			PlayerStand = "AmovPercMwlkSlowWrflDbl";
			Up = "AmovPercMwlkSlowWrflDbl";
			fireNotPossible = "AmovPknlMwlkSrasWrflDbl";
			Stand = "AmovPknlMwlkSrasWrflDbl";
		};
		class RifleKneelLowActionsRunB: RifleKneelLowActionsNoAdjust
		{
			PlayerStand = "AmovPercMrunSlowWrflDb";
			Up = "AmovPercMrunSlowWrflDb";
			fireNotPossible = "AmovPknlMtacSrasWrflDb";
			AdjustB = "";
			Stand = "AmovPknlMrunSrasWrflDb";
		};
		class RifleKneelLowActionsWlkB: RifleKneelLowActionsNoAdjust
		{
			PlayerStand = "AmovPercMwlkSlowWrflDb";
			Up = "AmovPercMwlkSlowWrflDb";
			fireNotPossible = "AmovPknlMwlkSrasWrflDb";
			AdjustB = "";
			Stand = "AmovPknlMwlkSrasWrflDb";
		};
		class RifleKneelLowActionsRunBR: RifleKneelLowActionsNoAdjust
		{
			PlayerStand = "AmovPercMrunSlowWrflDbr";
			Up = "AmovPercMrunSlowWrflDbr";
			fireNotPossible = "AmovPknlMtacSrasWrflDbr";
			Stand = "AmovPknlMrunSrasWrflDbr";
		};
		class RifleKneelLowActionsWlkBR: RifleKneelLowActionsNoAdjust
		{
			PlayerStand = "AmovPercMwlkSlowWrflDbr";
			Up = "AmovPercMwlkSlowWrflDbr";
			fireNotPossible = "AmovPknlMwlkSrasWrflDbr";
			Stand = "AmovPknlMwlkSrasWrflDbr";
		};
		class RifleKneelLowActionsRunR: RifleKneelLowActionsNoAdjust
		{
			PlayerStand = "AmovPercMrunSlowWrflDr";
			Up = "AmovPercMrunSlowWrflDr";
			fireNotPossible = "AmovPknlMtacSrasWrflDr";
			AdjustR = "";
			Stand = "AmovPknlMrunSrasWrflDr";
		};
		class RifleKneelLowActionsWlkR: RifleKneelLowActionsNoAdjust
		{
			PlayerStand = "AmovPercMwlkSlowWrflDr";
			Up = "AmovPercMwlkSlowWrflDr";
			fireNotPossible = "AmovPknlMwlkSrasWrflDr";
			AdjustR = "";
			Stand = "AmovPknlMwlkSrasWrflDr";
		};
		class RifleKneelLowActionsRunFR: RifleKneelLowActionsNoAdjust
		{
			PlayerStand = "AmovPercMrunSlowWrflDfr";
			Up = "AmovPercMrunSlowWrflDfr";
			fireNotPossible = "AmovPknlMtacSrasWrflDfr";
			Stand = "AmovPknlMrunSrasWrflDfr";
		};
		class RifleKneelLowActionsWlkFR: RifleKneelLowActionsNoAdjust
		{
			PlayerStand = "AmovPercMwlkSlowWrflDfr";
			Up = "AmovPercMwlkSlowWrflDfr";
			fireNotPossible = "AmovPknlMwlkSrasWrflDfr";
			Stand = "AmovPknlMwlkSrasWrflDfr";
		};
		class RifleKneelLowActionsTacF: RifleKneelLowActionsNoAdjust
		{
			PlayerStand = "AmovPercMTacSlowWrflDf";
			Up = "AmovPercMTacSlowWrflDf";
			AdjustF = "";
			Stand = "AmovPknlMtacSrasWrflDf";
		};
		class RifleKneelLowActionsTacFL: RifleKneelLowActionsNoAdjust
		{
			PlayerStand = "AmovPercMTacSlowWrflDfl";
			Up = "AmovPercMTacSlowWrflDfl";
			Stand = "AmovPknlMtacSrasWrflDfl";
		};
		class RifleKneelLowActionsTacL: RifleKneelLowActionsNoAdjust
		{
			PlayerStand = "AmovPercMTacSlowWrflDl";
			Up = "AmovPercMTacSlowWrflDl";
			AdjustL = "";
			Stand = "AmovPknlMtacSrasWrflDl";
		};
		class RifleKneelLowActionsTacBL: RifleKneelLowActionsNoAdjust
		{
			PlayerStand = "AmovPercMTacSlowWrfldbl";
			Up = "AmovPercMTacSlowWrfldbl";
			Stand = "AmovPknlMtacSrasWrflDbl";
		};
		class RifleKneelLowActionsTacB: RifleKneelLowActionsNoAdjust
		{
			PlayerStand = "AmovPercMTacSlowWrflDb";
			Up = "AmovPercMTacSlowWrflDb";
			AdjustB = "";
			Stand = "AmovPknlMtacSrasWrflDb";
		};
		class RifleKneelLowActionsTacBR: RifleKneelLowActionsNoAdjust
		{
			PlayerStand = "AmovPercMTacSlowWrflDbr";
			Up = "AmovPercMTacSlowWrflDbr";
			Stand = "AmovPknlMtacSrasWrflDbr";
		};
		class RifleKneelLowActionsTacR: RifleKneelLowActionsNoAdjust
		{
			PlayerStand = "AmovPercMTacSlowWrflDr";
			Up = "AmovPercMTacSlowWrflDr";
			AdjustR = "";
			Stand = "AmovPknlMtacSrasWrflDr";
		};
		class RifleKneelLowActionsTacFR: RifleKneelLowActionsNoAdjust
		{
			PlayerStand = "AmovPercMTacSlowWrflDfr";
			Up = "AmovPercMTacSlowWrflDfr";
			Stand = "AmovPknlMtacSrasWrflDfr";
		};
		class RifleKneelTakeActions: RifleKneelActions
		{
			stop = "AinvPknlMstpSlayWrflDnon_1";
			StopRelaxed = "AinvPknlMstpSlayWrflDnon_1";
			default = "AinvPknlMstpSlayWrflDnon_1";
			sitDown = "";
			PlayerCrouch = "AmovPknlMstpSrasWrflDnon";
		};
		class RifleAdjustStandBaseActions: RifleBaseStandActions
		{
			Lying = "";
			Crouch = "";
		};
		class RifleAdjustLStandActions: RifleAdjustStandBaseActions
		{
			stop = "AadjPercMstpSrasWrflDleft";
			default = "AadjPercMstpSrasWrflDleft";
			StopRelaxed = "AadjPercMstpSrasWrflDleft";
			turnL = "AadjPercMstpSrasWrflDleft";
			turnR = "AadjPercMstpSrasWrflDleft";
			turnLRelaxed = "AadjPercMstpSrasWrflDleft";
			turnRRelaxed = "AadjPercMstpSrasWrflDleft";
			WalkF = "AadjPercMwlkSrasWrflDf_left";
			WalkLF = "AadjPercMwlkSrasWrflDfl_left";
			WalkRF = "AadjPercMwlkSrasWrflDfr_left";
			WalkL = "AadjPercMwlkSrasWrflDl_left";
			WalkR = "AadjPercMwlkSrasWrflDr_left";
			WalkLB = "AadjPercMwlkSrasWrflDbl_left";
			WalkRB = "AadjPercMwlkSrasWrflDbr_left";
			WalkB = "AadjPercMwlkSrasWrflDb_left";
			PlayerWalkF = "AadjPercMwlkSrasWrflDf_left";
			PlayerWalkLF = "AadjPercMwlkSrasWrflDfl_left";
			PlayerWalkRF = "AadjPercMwlkSrasWrflDfr_left";
			PlayerWalkL = "AadjPercMwlkSrasWrflDl_left";
			PlayerWalkR = "AadjPercMwlkSrasWrflDr_left";
			PlayerWalkLB = "AadjPercMwlkSrasWrflDbl_left";
			PlayerWalkRB = "AadjPercMwlkSrasWrflDbr_left";
			PlayerWalkB = "AadjPercMwlkSrasWrflDb_left";
			SlowF = "AadjPercMrunSrasWrflDf_left";
			SlowLF = "AadjPercMrunSrasWrflDfl_left";
			SlowRF = "AadjPercMrunSrasWrflDfr_left";
			SlowL = "AadjPercMrunSrasWrflDl_left";
			SlowR = "AadjPercMrunSrasWrflDr_left";
			SlowLB = "AadjPercMrunSrasWrflDbl_left";
			SlowRB = "AadjPercMrunSrasWrflDbr_left";
			SlowB = "AadjPercMrunSrasWrflDb_left";
			PlayerSlowF = "AadjPercMrunSrasWrflDf_left";
			PlayerSlowLF = "AadjPercMrunSrasWrflDfl_left";
			PlayerSlowRF = "AadjPercMrunSrasWrflDfr_left";
			PlayerSlowL = "AadjPercMrunSrasWrflDl_left";
			PlayerSlowR = "AadjPercMrunSrasWrflDr_left";
			PlayerSlowLB = "AadjPercMrunSrasWrflDbl_left";
			PlayerSlowRB = "AadjPercMrunSrasWrflDbr_left";
			PlayerSlowB = "AadjPercMrunSrasWrflDb_left";
			FastF = "AadjPercMevaSrasWrflDf_left";
			FastLF = "AadjPercMevaSrasWrflDfl_left";
			FastRF = "AadjPercMevaSrasWrflDfr_left";
			FastL = "AadjPercMrunSrasWrflDl_left";
			FastR = "AadjPercMrunSrasWrflDr_left";
			FastLB = "AadjPercMrunSrasWrflDbl_left";
			FastRB = "AadjPercMrunSrasWrflDbr_left";
			FastB = "AadjPercMrunSrasWrflDb_left";
			TactF = "AadjPercMtacSrasWrflDf_left";
			TactLF = "AadjPercMtacSrasWrflDfl_left";
			TactRF = "AadjPercMtacSrasWrflDfr_left";
			TactL = "AadjPercMtacSrasWrflDl_left";
			TactR = "AadjPercMtacSrasWrflDr_left";
			TactLB = "AadjPercMtacSrasWrflDbl_left";
			TactRB = "AadjPercMtacSrasWrflDbr_left";
			TactB = "AadjPercMtacSrasWrflDb_left";
			PlayerTactF = "AadjPercMtacSrasWrflDf_left";
			PlayerTactLF = "AadjPercMtacSrasWrflDfl_left";
			PlayerTactRF = "AadjPercMtacSrasWrflDfr_left";
			PlayerTactL = "AadjPercMtacSrasWrflDl_left";
			PlayerTactR = "AadjPercMtacSrasWrflDr_left";
			PlayerTactLB = "AadjPercMtacSrasWrflDbl_left";
			PlayerTactRB = "AadjPercMtacSrasWrflDbr_left";
			PlayerTactB = "AadjPercMtacSrasWrflDb_left";
			up = "AadjPknlMstpSrasWrflDleft";
			down = "AadjPpneMstpSrasWrflDleft";
			PlayerProne = "AadjPpneMstpSrasWrflDleft";
			PlayerCrouch = "AadjPknlMstpSrasWrflDleft";
			Combat = "AadjPercMstpSrasWrflDleft";
			FireNotPossible = "AadjPercMstpSrasWrflDleft";
			Crouch = "AadjPknlMstpSrasWrflDleft";
			AdjustF = "AadjPercMstpSrasWrflDup";
			AdjustLF = "AadjPercMstpSrasWrflDup";
			AdjustRF = "AadjPercMstpSrasWrflDup";
			AdjustB = "AadjPercMstpSrasWrflDdown";
			AdjustLB = "AadjPercMstpSrasWrflDdown";
			AdjustRB = "AadjPercMstpSrasWrflDdown";
			AdjustL = "AadjPercMstpSrasWrflDleft";
			AdjustR = "AmovPercMstpSrasWrflDnon";
		};
		class RifleAdjustRStandActions: RifleAdjustStandBaseActions
		{
			stop = "AadjPercMstpSrasWrflDright";
			default = "AadjPercMstpSrasWrflDright";
			StopRelaxed = "AadjPercMstpSrasWrflDright";
			turnL = "AadjPercMstpSrasWrflDright";
			turnR = "AadjPercMstpSrasWrflDright";
			turnLRelaxed = "AadjPercMstpSrasWrflDright";
			turnRRelaxed = "AadjPercMstpSrasWrflDright";
			WalkF = "AadjPercMwlkSrasWrflDf_right";
			WalkLF = "AadjPercMwlkSrasWrflDfl_right";
			WalkRF = "AadjPercMwlkSrasWrflDfr_right";
			WalkL = "AadjPercMwlkSrasWrflDl_right";
			WalkR = "AadjPercMwlkSrasWrflDr_right";
			WalkLB = "AadjPercMwlkSrasWrflDbl_right";
			WalkRB = "AadjPercMwlkSrasWrflDbr_right";
			WalkB = "AadjPercMwlkSrasWrflDb_right";
			PlayerWalkF = "AadjPercMwlkSrasWrflDf_right";
			PlayerWalkLF = "AadjPercMwlkSrasWrflDfl_right";
			PlayerWalkRF = "AadjPercMwlkSrasWrflDfr_right";
			PlayerWalkL = "AadjPercMwlkSrasWrflDl_right";
			PlayerWalkR = "AadjPercMwlkSrasWrflDr_right";
			PlayerWalkLB = "AadjPercMwlkSrasWrflDbl_right";
			PlayerWalkRB = "AadjPercMwlkSrasWrflDbr_right";
			PlayerWalkB = "AadjPercMwlkSrasWrflDb_right";
			SlowF = "AadjPercMrunSrasWrflDf_right";
			SlowLF = "AadjPercMrunSrasWrflDfl_right";
			SlowRF = "AadjPercMrunSrasWrflDfr_right";
			SlowL = "AadjPercMrunSrasWrflDl_right";
			SlowR = "AadjPercMrunSrasWrflDr_right";
			SlowLB = "AadjPercMrunSrasWrflDbl_right";
			SlowRB = "AadjPercMrunSrasWrflDbr_right";
			SlowB = "AadjPercMrunSrasWrflDb_right";
			PlayerSlowF = "AadjPercMrunSrasWrflDf_right";
			PlayerSlowLF = "AadjPercMrunSrasWrflDfl_right";
			PlayerSlowRF = "AadjPercMrunSrasWrflDfr_right";
			PlayerSlowL = "AadjPercMrunSrasWrflDl_right";
			PlayerSlowR = "AadjPercMrunSrasWrflDr_right";
			PlayerSlowLB = "AadjPercMrunSrasWrflDbl_right";
			PlayerSlowRB = "AadjPercMrunSrasWrflDbr_right";
			PlayerSlowB = "AadjPercMrunSrasWrflDb_right";
			FastF = "AadjPercMevaSrasWrflDf_right";
			FastLF = "AadjPercMevaSrasWrflDfl_right";
			FastRF = "AadjPercMevaSrasWrflDfr_right";
			FastL = "AadjPercMrunSrasWrflDl_right";
			FastR = "AadjPercMrunSrasWrflDr_right";
			FastLB = "AadjPercMrunSrasWrflDbl_right";
			FastRB = "AadjPercMrunSrasWrflDbr_right";
			FastB = "AadjPercMrunSrasWrflDb_right";
			TactF = "AadjPercMtacSrasWrflDf_right";
			TactLF = "AadjPercMtacSrasWrflDfl_right";
			TactRF = "AadjPercMtacSrasWrflDfr_right";
			TactL = "AadjPercMtacSrasWrflDl_right";
			TactR = "AadjPercMtacSrasWrflDr_right";
			TactLB = "AadjPercMtacSrasWrflDbl_right";
			TactRB = "AadjPercMtacSrasWrflDbr_right";
			TactB = "AadjPercMtacSrasWrflDb_right";
			PlayerTactF = "AadjPercMtacSrasWrflDf_right";
			PlayerTactLF = "AadjPercMtacSrasWrflDfl_right";
			PlayerTactRF = "AadjPercMtacSrasWrflDfr_right";
			PlayerTactL = "AadjPercMtacSrasWrflDl_right";
			PlayerTactR = "AadjPercMtacSrasWrflDr_right";
			PlayerTactLB = "AadjPercMtacSrasWrflDbl_right";
			PlayerTactRB = "AadjPercMtacSrasWrflDbr_right";
			PlayerTactB = "AadjPercMtacSrasWrflDb_right";
			up = "AadjPknlMstpSrasWrflDright";
			down = "AadjPpneMstpSrasWrflDright";
			PlayerProne = "AadjPpneMstpSrasWrflDright";
			PlayerCrouch = "AadjPknlMstpSrasWrflDright";
			Combat = "AadjPercMstpSrasWrflDright";
			FireNotPossible = "AadjPercMstpSrasWrflDright";
			Crouch = "AadjPknlMstpSrasWrflDright";
			AdjustF = "AadjPercMstpSrasWrflDup";
			AdjustLF = "AadjPercMstpSrasWrflDup";
			AdjustRF = "AadjPercMstpSrasWrflDup";
			AdjustB = "AadjPercMstpSrasWrflDdown";
			AdjustLB = "AadjPercMstpSrasWrflDdown";
			AdjustRB = "AadjPercMstpSrasWrflDdown";
			AdjustL = "AmovPercMstpSrasWrflDnon";
			AdjustR = "AadjPercMstpSrasWrflDright";
		};
		class RifleAdjustFStandActions: RifleAdjustStandBaseActions
		{
			stop = "AadjPercMstpSrasWrflDup";
			default = "AadjPercMstpSrasWrflDup";
			StopRelaxed = "AadjPercMstpSrasWrflDup";
			turnL = "AadjPercMstpSrasWrflDup";
			turnR = "AadjPercMstpSrasWrflDup";
			turnLRelaxed = "AadjPercMstpSrasWrflDup";
			turnRRelaxed = "AadjPercMstpSrasWrflDup";
			WalkF = "AadjPercMwlkSrasWrflDf_up";
			WalkLF = "AadjPercMwlkSrasWrflDfl_up";
			WalkRF = "AadjPercMwlkSrasWrflDfr_up";
			WalkL = "AadjPercMwlkSrasWrflDl_up";
			WalkR = "AadjPercMwlkSrasWrflDr_up";
			WalkLB = "AadjPercMwlkSrasWrflDbl_up";
			WalkRB = "AadjPercMwlkSrasWrflDbr_up";
			WalkB = "AadjPercMwlkSrasWrflDb_up";
			PlayerWalkF = "AadjPercMwlkSrasWrflDf_up";
			PlayerWalkLF = "AadjPercMwlkSrasWrflDfl_up";
			PlayerWalkRF = "AadjPercMwlkSrasWrflDfr_up";
			PlayerWalkL = "AadjPercMwlkSrasWrflDl_up";
			PlayerWalkR = "AadjPercMwlkSrasWrflDr_up";
			PlayerWalkLB = "AadjPercMwlkSrasWrflDbl_up";
			PlayerWalkRB = "AadjPercMwlkSrasWrflDbr_up";
			PlayerWalkB = "AadjPercMwlkSrasWrflDb_up";
			SlowF = "AadjPercMrunSrasWrflDf_up";
			SlowLF = "AadjPercMrunSrasWrflDfl_up";
			SlowRF = "AadjPercMrunSrasWrflDfr_up";
			SlowL = "AadjPercMrunSrasWrflDl_up";
			SlowR = "AadjPercMrunSrasWrflDr_up";
			SlowLB = "AadjPercMrunSrasWrflDbl_up";
			SlowRB = "AadjPercMrunSrasWrflDbr_up";
			SlowB = "AadjPercMrunSrasWrflDb_up";
			PlayerSlowF = "AadjPercMrunSrasWrflDf_up";
			PlayerSlowLF = "AadjPercMrunSrasWrflDfl_up";
			PlayerSlowRF = "AadjPercMrunSrasWrflDfr_up";
			PlayerSlowL = "AadjPercMrunSrasWrflDl_up";
			PlayerSlowR = "AadjPercMrunSrasWrflDr_up";
			PlayerSlowLB = "AadjPercMrunSrasWrflDbl_up";
			PlayerSlowRB = "AadjPercMrunSrasWrflDbr_up";
			PlayerSlowB = "AadjPercMrunSrasWrflDb_up";
			FastF = "AadjPercMevaSrasWrflDf_up";
			FastLF = "AadjPercMevaSrasWrflDfl_up";
			FastRF = "AadjPercMevaSrasWrflDfr_up";
			FastL = "AadjPercMrunSrasWrflDl_up";
			FastR = "AadjPercMrunSrasWrflDr_up";
			FastLB = "AadjPercMrunSrasWrflDbl_up";
			FastRB = "AadjPercMrunSrasWrflDbr_up";
			FastB = "AadjPercMrunSrasWrflDb_up";
			TactF = "AadjPercMtacSrasWrflDf_up";
			TactLF = "AadjPercMtacSrasWrflDfl_up";
			TactRF = "AadjPercMtacSrasWrflDfr_up";
			TactL = "AadjPercMtacSrasWrflDl_up";
			TactR = "AadjPercMtacSrasWrflDr_up";
			TactLB = "AadjPercMtacSrasWrflDbl_up";
			TactRB = "AadjPercMtacSrasWrflDbr_up";
			TactB = "AadjPercMtacSrasWrflDb_up";
			PlayerTactF = "AadjPercMtacSrasWrflDf_up";
			PlayerTactLF = "AadjPercMtacSrasWrflDfl_up";
			PlayerTactRF = "AadjPercMtacSrasWrflDfr_up";
			PlayerTactL = "AadjPercMtacSrasWrflDl_up";
			PlayerTactR = "AadjPercMtacSrasWrflDr_up";
			PlayerTactLB = "AadjPercMtacSrasWrflDbl_up";
			PlayerTactRB = "AadjPercMtacSrasWrflDbr_up";
			PlayerTactB = "AadjPercMtacSrasWrflDb_up";
			up = "AadjPknlMstpSrasWrflDup";
			PlayerCrouch = "AadjPknlMstpSrasWrflDup";
			Combat = "AadjPercMstpSrasWrflDup";
			FireNotPossible = "AadjPercMstpSrasWrflDup";
			Crouch = "AadjPknlMstpSrasWrflDup";
			AdjustF = "AadjPercMstpSrasWrflDup";
			AdjustLF = "AadjPercMstpSrasWrflDup";
			AdjustRF = "AadjPercMstpSrasWrflDup";
			AdjustB = "AmovPercMstpSrasWrflDnon";
			AdjustL = "AadjPercMstpSrasWrflDleft";
			AdjustR = "AadjPercMstpSrasWrflDright";
		};
		class RifleAdjustBStandActions: RifleAdjustStandBaseActions
		{
			stop = "AadjPercMstpSrasWrflDdown";
			default = "AadjPercMstpSrasWrflDdown";
			StopRelaxed = "AadjPercMstpSrasWrflDdown";
			turnL = "AadjPercMstpSrasWrflDdown";
			turnR = "AadjPercMstpSrasWrflDdown";
			turnLRelaxed = "AadjPercMstpSrasWrflDdown";
			turnRRelaxed = "AadjPercMstpSrasWrflDdown";
			WalkF = "AadjPercMwlkSrasWrflDf_down";
			WalkLF = "AadjPercMwlkSrasWrflDfl_down";
			WalkRF = "AadjPercMwlkSrasWrflDfr_down";
			WalkL = "AadjPercMwlkSrasWrflDl_down";
			WalkR = "AadjPercMwlkSrasWrflDr_down";
			WalkLB = "AadjPercMwlkSrasWrflDbl_down";
			WalkRB = "AadjPercMwlkSrasWrflDbr_down";
			WalkB = "AadjPercMwlkSrasWrflDb_down";
			PlayerWalkF = "AadjPercMwlkSrasWrflDf_down";
			PlayerWalkLF = "AadjPercMwlkSrasWrflDfl_down";
			PlayerWalkRF = "AadjPercMwlkSrasWrflDfr_down";
			PlayerWalkL = "AadjPercMwlkSrasWrflDl_down";
			PlayerWalkR = "AadjPercMwlkSrasWrflDr_down";
			PlayerWalkLB = "AadjPercMwlkSrasWrflDbl_down";
			PlayerWalkRB = "AadjPercMwlkSrasWrflDbr_down";
			PlayerWalkB = "AadjPercMwlkSrasWrflDb_down";
			SlowF = "AadjPercMrunSrasWrflDf_down";
			SlowLF = "AadjPercMrunSrasWrflDfl_down";
			SlowRF = "AadjPercMrunSrasWrflDfr_down";
			SlowL = "AadjPercMrunSrasWrflDl_down";
			SlowR = "AadjPercMrunSrasWrflDr_down";
			SlowLB = "AadjPercMrunSrasWrflDbl_down";
			SlowRB = "AadjPercMrunSrasWrflDbr_down";
			SlowB = "AadjPercMrunSrasWrflDb_down";
			PlayerSlowF = "AadjPercMrunSrasWrflDf_down";
			PlayerSlowLF = "AadjPercMrunSrasWrflDfl_down";
			PlayerSlowRF = "AadjPercMrunSrasWrflDfr_down";
			PlayerSlowL = "AadjPercMrunSrasWrflDl_down";
			PlayerSlowR = "AadjPercMrunSrasWrflDr_down";
			PlayerSlowLB = "AadjPercMrunSrasWrflDbl_down";
			PlayerSlowRB = "AadjPercMrunSrasWrflDbr_down";
			PlayerSlowB = "AadjPercMrunSrasWrflDb_down";
			FastF = "AadjPercMevaSrasWrflDf_down";
			FastLF = "AadjPercMevaSrasWrflDfl_down";
			FastRF = "AadjPercMevaSrasWrflDfr_down";
			FastL = "AadjPercMrunSrasWrflDl_down";
			FastR = "AadjPercMrunSrasWrflDr_down";
			FastLB = "AadjPercMrunSrasWrflDbl_down";
			FastRB = "AadjPercMrunSrasWrflDbr_down";
			FastB = "AadjPercMrunSrasWrflDb_down";
			TactF = "AadjPercMtacSrasWrflDf_down";
			TactLF = "AadjPercMtacSrasWrflDfl_down";
			TactRF = "AadjPercMtacSrasWrflDfr_down";
			TactL = "AadjPercMtacSrasWrflDl_down";
			TactR = "AadjPercMtacSrasWrflDr_down";
			TactLB = "AadjPercMtacSrasWrflDbl_down";
			TactRB = "AadjPercMtacSrasWrflDbr_down";
			TactB = "AadjPercMtacSrasWrflDb_down";
			PlayerTactF = "AadjPercMtacSrasWrflDf_down";
			PlayerTactLF = "AadjPercMtacSrasWrflDfl_down";
			PlayerTactRF = "AadjPercMtacSrasWrflDfr_down";
			PlayerTactL = "AadjPercMtacSrasWrflDl_down";
			PlayerTactR = "AadjPercMtacSrasWrflDr_down";
			PlayerTactLB = "AadjPercMtacSrasWrflDbl_down";
			PlayerTactRB = "AadjPercMtacSrasWrflDbr_down";
			PlayerTactB = "AadjPercMtacSrasWrflDb_down";
			up = "AadjPknlMstpSrasWrflDdown";
			downDegree = "ManPosCombat";
			PlayerCrouch = "AadjPknlMstpSrasWrflDdown";
			Combat = "AadjPercMstpSrasWrflDdown";
			FireNotPossible = "AadjPercMstpSrasWrflDdown";
			Crouch = "AadjPknlMstpSrasWrflDdown";
			AdjustF = "AmovPercMstpSrasWrflDnon";
			AdjustB = "AadjPknlMstpSrasWrflDup";
			AdjustL = "AadjPercMstpSrasWrflDleft";
			AdjustR = "AadjPercMstpSrasWrflDright";
		};
		class RifleAdjustKneelBaseActions: RifleKneelActions
		{
			Lying = "";
			Crouch = "";
			AdjustF = "AadjPknlMstpSrasWrflDup";
			AdjustLF = "AadjPknlMstpSrasWrflDup";
			AdjustRF = "AadjPknlMstpSrasWrflDup";
			AdjustB = "AadjPknlMstpSrasWrflDdown";
			AdjustLB = "AadjPknlMstpSrasWrflDdown";
			AdjustRB = "AadjPknlMstpSrasWrflDdown";
			AdjustL = "AadjPknlMstpSrasWrflDleft";
			AdjustR = "AadjPknlMstpSrasWrflDright";
		};
		class RifleAdjustLKneelActions: RifleAdjustKneelBaseActions
		{
			stop = "AadjPknlMstpSrasWrflDleft";
			default = "AadjPknlMstpSrasWrflDleft";
			StopRelaxed = "AadjPknlMstpSrasWrflDleft";
			turnL = "AadjPknlMstpSrasWrflDleft";
			turnR = "AadjPknlMstpSrasWrflDleft";
			turnLRelaxed = "AadjPknlMstpSrasWrflDleft";
			turnRRelaxed = "AadjPknlMstpSrasWrflDleft";
			WalkF = "AadjPknlMwlkSrasWrflDf_left";
			WalkLF = "AadjPknlMwlkSrasWrflDfl_left";
			WalkRF = "AadjPknlMwlkSrasWrflDfr_left";
			WalkL = "AadjPknlMwlkSrasWrflDl_left";
			WalkR = "AadjPknlMwlkSrasWrflDr_left";
			WalkLB = "AadjPknlMwlkSrasWrflDbl_left";
			WalkRB = "AadjPknlMwlkSrasWrflDbr_left";
			WalkB = "AadjPknlMwlkSrasWrflDb_left";
			PlayerWalkF = "AadjPknlMwlkSrasWrflDf_left";
			PlayerWalkLF = "AadjPknlMwlkSrasWrflDfl_left";
			PlayerWalkRF = "AadjPknlMwlkSrasWrflDfr_left";
			PlayerWalkL = "AadjPknlMwlkSrasWrflDl_left";
			PlayerWalkR = "AadjPknlMwlkSrasWrflDr_left";
			PlayerWalkLB = "AadjPknlMwlkSrasWrflDbl_left";
			PlayerWalkRB = "AadjPknlMwlkSrasWrflDbr_left";
			PlayerWalkB = "AadjPknlMwlkSrasWrflDb_left";
			SlowF = "AadjPknlMrunSrasWrflDf_left";
			SlowLF = "AadjPknlMrunSrasWrflDfl_left";
			SlowRF = "AadjPknlMrunSrasWrflDfr_left";
			SlowL = "AadjPknlMrunSrasWrflDl_left";
			SlowR = "AadjPknlMrunSrasWrflDr_left";
			SlowLB = "AadjPknlMrunSrasWrflDbl_left";
			SlowRB = "AadjPknlMrunSrasWrflDbr_left";
			SlowB = "AadjPknlMrunSrasWrflDb_left";
			PlayerSlowF = "AadjPknlMrunSrasWrflDf_left";
			PlayerSlowLF = "AadjPknlMrunSrasWrflDfl_left";
			PlayerSlowRF = "AadjPknlMrunSrasWrflDfr_left";
			PlayerSlowL = "AadjPknlMrunSrasWrflDl_left";
			PlayerSlowR = "AadjPknlMrunSrasWrflDr_left";
			PlayerSlowLB = "AadjPknlMrunSrasWrflDbl_left";
			PlayerSlowRB = "AadjPknlMrunSrasWrflDbr_left";
			PlayerSlowB = "AadjPknlMrunSrasWrflDb_left";
			FastF = "AadjPknlMevaSrasWrflDf_left";
			FastLF = "AadjPknlMevaSrasWrflDfl_left";
			FastRF = "AadjPknlMevaSrasWrflDfr_left";
			FastL = "AadjPknlMrunSrasWrflDl_left";
			FastR = "AadjPknlMrunSrasWrflDr_left";
			FastLB = "AadjPknlMrunSrasWrflDbl_left";
			FastRB = "AadjPknlMrunSrasWrflDbr_left";
			FastB = "AadjPknlMrunSrasWrflDb_left";
			TactF = "AadjPknlMtacSrasWrflDf_left";
			TactLF = "AadjPknlMtacSrasWrflDfl_left";
			TactRF = "AadjPknlMtacSrasWrflDfr_left";
			TactL = "AadjPknlMtacSrasWrflDl_left";
			TactR = "AadjPknlMtacSrasWrflDr_left";
			TactLB = "AadjPknlMtacSrasWrflDbl_left";
			TactRB = "AadjPknlMtacSrasWrflDbr_left";
			TactB = "AadjPknlMtacSrasWrflDb_left";
			PlayerTactF = "AadjPknlMtacSrasWrflDf_left";
			PlayerTactLF = "AadjPknlMtacSrasWrflDfl_left";
			PlayerTactRF = "AadjPknlMtacSrasWrflDfr_left";
			PlayerTactL = "AadjPknlMtacSrasWrflDl_left";
			PlayerTactR = "AadjPknlMtacSrasWrflDr_left";
			PlayerTactLB = "AadjPknlMtacSrasWrflDbl_left";
			PlayerTactRB = "AadjPknlMtacSrasWrflDbr_left";
			PlayerTactB = "AadjPknlMtacSrasWrflDb_left";
			up = "AadjPercMstpSrasWrflDleft";
			upDegree = "ManPosCombat";
			PlayerStand = "AadjPercMstpSrasWrflDleft";
			PlayerCrouch = "AmovPknlMstpSrasWrflDnon";
			Combat = "AadjPknlMstpSrasWrflDleft";
			FireNotPossible = "AadjPknlMstpSrasWrflDleft";
			Stand = "AmovPknlMstpSlowWrflDnon";
			AdjustR = "AmovPknlMstpSrasWrflDnon";
			down = "AadjPpneMstpSrasWrflDleft";
			PlayerProne = "AadjPpneMstpSrasWrflDleft";
		};
		class RifleAdjustRKneelActions: RifleAdjustKneelBaseActions
		{
			stop = "AadjPknlMstpSrasWrflDright";
			default = "AadjPknlMstpSrasWrflDright";
			StopRelaxed = "AadjPknlMstpSrasWrflDright";
			turnL = "AadjPknlMstpSrasWrflDright";
			turnR = "AadjPknlMstpSrasWrflDright";
			turnLRelaxed = "AadjPknlMstpSrasWrflDright";
			turnRRelaxed = "AadjPknlMstpSrasWrflDright";
			WalkF = "AadjPknlMwlkSrasWrflDf_right";
			WalkLF = "AadjPknlMwlkSrasWrflDfl_right";
			WalkRF = "AadjPknlMwlkSrasWrflDfr_right";
			WalkL = "AadjPknlMwlkSrasWrflDl_right";
			WalkR = "AadjPknlMwlkSrasWrflDr_right";
			WalkLB = "AadjPknlMwlkSrasWrflDbl_right";
			WalkRB = "AadjPknlMwlkSrasWrflDbr_right";
			WalkB = "AadjPknlMwlkSrasWrflDb_right";
			PlayerWalkF = "AadjPknlMwlkSrasWrflDf_right";
			PlayerWalkLF = "AadjPknlMwlkSrasWrflDfl_right";
			PlayerWalkRF = "AadjPknlMwlkSrasWrflDfr_right";
			PlayerWalkL = "AadjPknlMwlkSrasWrflDl_right";
			PlayerWalkR = "AadjPknlMwlkSrasWrflDr_right";
			PlayerWalkLB = "AadjPknlMwlkSrasWrflDbl_right";
			PlayerWalkRB = "AadjPknlMwlkSrasWrflDbr_right";
			PlayerWalkB = "AadjPknlMwlkSrasWrflDb_right";
			SlowF = "AadjPknlMrunSrasWrflDf_right";
			SlowLF = "AadjPknlMrunSrasWrflDfl_right";
			SlowRF = "AadjPknlMrunSrasWrflDfr_right";
			SlowL = "AadjPknlMrunSrasWrflDl_right";
			SlowR = "AadjPknlMrunSrasWrflDr_right";
			SlowLB = "AadjPknlMrunSrasWrflDbl_right";
			SlowRB = "AadjPknlMrunSrasWrflDbr_right";
			SlowB = "AadjPknlMrunSrasWrflDb_right";
			PlayerSlowF = "AadjPknlMrunSrasWrflDf_right";
			PlayerSlowLF = "AadjPknlMrunSrasWrflDfl_right";
			PlayerSlowRF = "AadjPknlMrunSrasWrflDfr_right";
			PlayerSlowL = "AadjPknlMrunSrasWrflDl_right";
			PlayerSlowR = "AadjPknlMrunSrasWrflDr_right";
			PlayerSlowLB = "AadjPknlMrunSrasWrflDbl_right";
			PlayerSlowRB = "AadjPknlMrunSrasWrflDbr_right";
			PlayerSlowB = "AadjPknlMrunSrasWrflDb_right";
			FastF = "AadjPknlMevaSrasWrflDf_right";
			FastLF = "AadjPknlMevaSrasWrflDfl_right";
			FastRF = "AadjPknlMevaSrasWrflDfr_right";
			FastL = "AadjPknlMrunSrasWrflDl_right";
			FastR = "AadjPknlMrunSrasWrflDr_right";
			FastLB = "AadjPknlMrunSrasWrflDbl_right";
			FastRB = "AadjPknlMrunSrasWrflDbr_right";
			FastB = "AadjPknlMrunSrasWrflDb_right";
			TactF = "AadjPknlMtacSrasWrflDf_right";
			TactLF = "AadjPknlMtacSrasWrflDfl_right";
			TactRF = "AadjPknlMtacSrasWrflDfr_right";
			TactL = "AadjPknlMtacSrasWrflDl_right";
			TactR = "AadjPknlMtacSrasWrflDr_right";
			TactLB = "AadjPknlMtacSrasWrflDbl_right";
			TactRB = "AadjPknlMtacSrasWrflDbr_right";
			TactB = "AadjPknlMtacSrasWrflDb_right";
			PlayerTactF = "AadjPknlMtacSrasWrflDf_right";
			PlayerTactLF = "AadjPknlMtacSrasWrflDfl_right";
			PlayerTactRF = "AadjPknlMtacSrasWrflDfr_right";
			PlayerTactL = "AadjPknlMtacSrasWrflDl_right";
			PlayerTactR = "AadjPknlMtacSrasWrflDr_right";
			PlayerTactLB = "AadjPknlMtacSrasWrflDbl_right";
			PlayerTactRB = "AadjPknlMtacSrasWrflDbr_right";
			PlayerTactB = "AadjPknlMtacSrasWrflDb_right";
			up = "AadjPercMstpSrasWrflDright";
			upDegree = "ManPosCombat";
			PlayerStand = "AadjPercMstpSrasWrflDright";
			PlayerCrouch = "AmovPknlMstpSrasWrflDnon";
			Combat = "AadjPknlMstpSrasWrflDright";
			FireNotPossible = "AadjPknlMstpSrasWrflDright";
			Stand = "AmovPknlMstpSlowWrflDnon";
			AdjustL = "AmovPknlMstpSrasWrflDnon";
			down = "AadjPpneMstpSrasWrflDright";
			PlayerProne = "AadjPpneMstpSrasWrflDright";
		};
		class RifleAdjustFKneelActions: RifleAdjustKneelBaseActions
		{
			stop = "AadjPknlMstpSrasWrflDup";
			default = "AadjPknlMstpSrasWrflDup";
			StopRelaxed = "AadjPknlMstpSrasWrflDup";
			turnL = "AadjPknlMstpSrasWrflDup";
			turnR = "AadjPknlMstpSrasWrflDup";
			turnLRelaxed = "AadjPknlMstpSrasWrflDup";
			turnRRelaxed = "AadjPknlMstpSrasWrflDup";
			WalkF = "AadjPknlMwlkSrasWrflDf_up";
			WalkLF = "AadjPknlMwlkSrasWrflDfl_up";
			WalkRF = "AadjPknlMwlkSrasWrflDfr_up";
			WalkL = "AadjPknlMwlkSrasWrflDl_up";
			WalkR = "AadjPknlMwlkSrasWrflDr_up";
			WalkLB = "AadjPknlMwlkSrasWrflDbl_up";
			WalkRB = "AadjPknlMwlkSrasWrflDbr_up";
			WalkB = "AadjPknlMwlkSrasWrflDb_up";
			PlayerWalkF = "AadjPknlMwlkSrasWrflDf_up";
			PlayerWalkLF = "AadjPknlMwlkSrasWrflDfl_up";
			PlayerWalkRF = "AadjPknlMwlkSrasWrflDfr_up";
			PlayerWalkL = "AadjPknlMwlkSrasWrflDl_up";
			PlayerWalkR = "AadjPknlMwlkSrasWrflDr_up";
			PlayerWalkLB = "AadjPknlMwlkSrasWrflDbl_up";
			PlayerWalkRB = "AadjPknlMwlkSrasWrflDbr_up";
			PlayerWalkB = "AadjPknlMwlkSrasWrflDb_up";
			SlowF = "AadjPknlMrunSrasWrflDf_up";
			SlowLF = "AadjPknlMrunSrasWrflDfl_up";
			SlowRF = "AadjPknlMrunSrasWrflDfr_up";
			SlowL = "AadjPknlMrunSrasWrflDl_up";
			SlowR = "AadjPknlMrunSrasWrflDr_up";
			SlowLB = "AadjPknlMrunSrasWrflDbl_up";
			SlowRB = "AadjPknlMrunSrasWrflDbr_up";
			SlowB = "AadjPknlMrunSrasWrflDb_up";
			PlayerSlowF = "AadjPknlMrunSrasWrflDf_up";
			PlayerSlowLF = "AadjPknlMrunSrasWrflDfl_up";
			PlayerSlowRF = "AadjPknlMrunSrasWrflDfr_up";
			PlayerSlowL = "AadjPknlMrunSrasWrflDl_up";
			PlayerSlowR = "AadjPknlMrunSrasWrflDr_up";
			PlayerSlowLB = "AadjPknlMrunSrasWrflDbl_up";
			PlayerSlowRB = "AadjPknlMrunSrasWrflDbr_up";
			PlayerSlowB = "AadjPknlMrunSrasWrflDb_up";
			FastF = "AadjPknlMevaSrasWrflDf_up";
			FastLF = "AadjPknlMevaSrasWrflDfl_up";
			FastRF = "AadjPknlMevaSrasWrflDfr_up";
			FastL = "AadjPknlMrunSrasWrflDl_up";
			FastR = "AadjPknlMrunSrasWrflDr_up";
			FastLB = "AadjPknlMrunSrasWrflDbl_up";
			FastRB = "AadjPknlMrunSrasWrflDbr_up";
			FastB = "AadjPknlMrunSrasWrflDb_up";
			TactF = "AadjPknlMtacSrasWrflDf_up";
			TactLF = "AadjPknlMtacSrasWrflDfl_up";
			TactRF = "AadjPknlMtacSrasWrflDfr_up";
			TactL = "AadjPknlMtacSrasWrflDl_up";
			TactR = "AadjPknlMtacSrasWrflDr_up";
			TactLB = "AadjPknlMtacSrasWrflDbl_up";
			TactRB = "AadjPknlMtacSrasWrflDbr_up";
			TactB = "AadjPknlMtacSrasWrflDb_up";
			PlayerTactF = "AadjPknlMtacSrasWrflDf_up";
			PlayerTactLF = "AadjPknlMtacSrasWrflDfl_up";
			PlayerTactRF = "AadjPknlMtacSrasWrflDfr_up";
			PlayerTactL = "AadjPknlMtacSrasWrflDl_up";
			PlayerTactR = "AadjPknlMtacSrasWrflDr_up";
			PlayerTactLB = "AadjPknlMtacSrasWrflDbl_up";
			PlayerTactRB = "AadjPknlMtacSrasWrflDbr_up";
			PlayerTactB = "AadjPknlMtacSrasWrflDb_up";
			up = "AadjPercMstpSrasWrflDup";
			upDegree = "ManPosCombat";
			PlayerStand = "AadjPercMstpSrasWrflDup";
			PlayerCrouch = "AmovPknlMstpSrasWrflDnon";
			Combat = "AadjPknlMstpSrasWrflDup";
			FireNotPossible = "AadjPknlMstpSrasWrflDup";
			Stand = "AmovPknlMstpSlowWrflDnon";
			AdjustF = "AadjPercMstpSrasWrflDdown";
			AdjustB = "AmovPknlMstpSrasWrflDnon";
		};
		class RifleAdjustBKneelActions: RifleAdjustKneelBaseActions
		{
			stop = "AadjPknlMstpSrasWrflDdown";
			default = "AadjPknlMstpSrasWrflDdown";
			StopRelaxed = "AadjPknlMstpSrasWrflDdown";
			turnL = "AadjPknlMstpSrasWrflDdown";
			turnR = "AadjPknlMstpSrasWrflDdown";
			turnLRelaxed = "AadjPknlMstpSrasWrflDdown";
			turnRRelaxed = "AadjPknlMstpSrasWrflDdown";
			WalkF = "AadjPknlMwlkSrasWrflDf_down";
			WalkLF = "AadjPknlMwlkSrasWrflDfl_down";
			WalkRF = "AadjPknlMwlkSrasWrflDfr_down";
			WalkL = "AadjPknlMwlkSrasWrflDl_down";
			WalkR = "AadjPknlMwlkSrasWrflDr_down";
			WalkLB = "AadjPknlMwlkSrasWrflDbl_down";
			WalkRB = "AadjPknlMwlkSrasWrflDbr_down";
			WalkB = "AadjPknlMwlkSrasWrflDb_down";
			PlayerWalkF = "AadjPknlMwlkSrasWrflDf_down";
			PlayerWalkLF = "AadjPknlMwlkSrasWrflDfl_down";
			PlayerWalkRF = "AadjPknlMwlkSrasWrflDfr_down";
			PlayerWalkL = "AadjPknlMwlkSrasWrflDl_down";
			PlayerWalkR = "AadjPknlMwlkSrasWrflDr_down";
			PlayerWalkLB = "AadjPknlMwlkSrasWrflDbl_down";
			PlayerWalkRB = "AadjPknlMwlkSrasWrflDbr_down";
			PlayerWalkB = "AadjPknlMwlkSrasWrflDb_down";
			SlowF = "AadjPknlMrunSrasWrflDf_down";
			SlowLF = "AadjPknlMrunSrasWrflDfl_down";
			SlowRF = "AadjPknlMrunSrasWrflDfr_down";
			SlowL = "AadjPknlMrunSrasWrflDl_down";
			SlowR = "AadjPknlMrunSrasWrflDr_down";
			SlowLB = "AadjPknlMrunSrasWrflDbl_down";
			SlowRB = "AadjPknlMrunSrasWrflDbr_down";
			SlowB = "AadjPknlMrunSrasWrflDb_down";
			PlayerSlowF = "AadjPknlMrunSrasWrflDf_down";
			PlayerSlowLF = "AadjPknlMrunSrasWrflDfl_down";
			PlayerSlowRF = "AadjPknlMrunSrasWrflDfr_down";
			PlayerSlowL = "AadjPknlMrunSrasWrflDl_down";
			PlayerSlowR = "AadjPknlMrunSrasWrflDr_down";
			PlayerSlowLB = "AadjPknlMrunSrasWrflDbl_down";
			PlayerSlowRB = "AadjPknlMrunSrasWrflDbr_down";
			PlayerSlowB = "AadjPknlMrunSrasWrflDb_down";
			FastF = "AadjPknlMevaSrasWrflDf_down";
			FastLF = "AadjPknlMevaSrasWrflDfl_down";
			FastRF = "AadjPknlMevaSrasWrflDfr_down";
			FastL = "AadjPknlMrunSrasWrflDl_down";
			FastR = "AadjPknlMrunSrasWrflDr_down";
			FastLB = "AadjPknlMrunSrasWrflDbl_down";
			FastRB = "AadjPknlMrunSrasWrflDbr_down";
			FastB = "AadjPknlMrunSrasWrflDb_down";
			TactF = "AadjPknlMtacSrasWrflDf_down";
			TactLF = "AadjPknlMtacSrasWrflDfl_down";
			TactRF = "AadjPknlMtacSrasWrflDfr_down";
			TactL = "AadjPknlMtacSrasWrflDl_down";
			TactR = "AadjPknlMtacSrasWrflDr_down";
			TactLB = "AadjPknlMtacSrasWrflDbl_down";
			TactRB = "AadjPknlMtacSrasWrflDbr_down";
			TactB = "AadjPknlMtacSrasWrflDb_down";
			PlayerTactF = "AadjPknlMtacSrasWrflDf_down";
			PlayerTactLF = "AadjPknlMtacSrasWrflDfl_down";
			PlayerTactRF = "AadjPknlMtacSrasWrflDfr_down";
			PlayerTactL = "AadjPknlMtacSrasWrflDl_down";
			PlayerTactR = "AadjPknlMtacSrasWrflDr_down";
			PlayerTactLB = "AadjPknlMtacSrasWrflDbl_down";
			PlayerTactRB = "AadjPknlMtacSrasWrflDbr_down";
			PlayerTactB = "AadjPknlMtacSrasWrflDb_down";
			up = "AadjPercMstpSrasWrflDdown";
			downDegree = "ManPosCombat";
			PlayerStand = "AadjPercMstpSrasWrflDdown";
			PlayerCrouch = "AmovPknlMstpSrasWrflDnon";
			Combat = "AadjPknlMstpSrasWrflDdown";
			FireNotPossible = "AadjPknlMstpSrasWrflDdown";
			Stand = "AmovPknlMstpSlowWrflDnon";
			AdjustF = "AmovPknlMstpSrasWrflDnon";
			AdjustB = "AadjPpneMstpSrasWrflDup";
		};
		class RifleAdjustLStandActionsRunF: RifleAdjustLStandActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDf_left";
			PlayerCrouch = "AadjPknlMrunSrasWrflDf_left";
			Up = "AadjPknlMrunSrasWrflDf_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustLStandActionsWlkF: RifleAdjustLStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWrflDf_left";
			Up = "AadjPknlMwlkSrasWrflDf_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustLStandActionsRunFL: RifleAdjustLStandActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDfl_left";
			PlayerCrouch = "AadjPknlMrunSrasWrflDfl_left";
			Up = "AadjPknlMrunSrasWrflDfl_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustLStandActionsWlkFL: RifleAdjustLStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWrflDfl_left";
			Up = "AadjPknlMwlkSrasWrflDfl_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustLStandActionsRunL: RifleAdjustLStandActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDl_left";
			PlayerCrouch = "AadjPknlMrunSrasWrflDl_left";
			Up = "AadjPknlMrunSrasWrflDl_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustLStandActionsWlkL: RifleAdjustLStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWrflDl_left";
			Up = "AadjPknlMwlkSrasWrflDl_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustLStandActionsRunBL: RifleAdjustLStandActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDbl_left";
			PlayerCrouch = "AadjPknlMrunSrasWrflDbl_left";
			Up = "AadjPknlMrunSrasWrflDbl_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustLStandActionsWlkBL: RifleAdjustLStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWrflDbl_left";
			Up = "AadjPknlMwlkSrasWrflDbl_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustLStandActionsRunB: RifleAdjustLStandActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDb_left";
			PlayerCrouch = "AadjPknlMrunSrasWrflDb_left";
			Up = "AadjPknlMrunSrasWrflDb_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustLStandActionsWlkB: RifleAdjustLStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWrflDb_left";
			Up = "AadjPknlMwlkSrasWrflDb_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustLStandActionsRunBR: RifleAdjustLStandActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDbr_left";
			PlayerCrouch = "AadjPknlMrunSrasWrflDbr_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustLStandActionsWlkBR: RifleAdjustLStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWrflDbr_left";
			Up = "AadjPknlMwlkSrasWrflDbr_left";
			Stand = "AadjPercMwlkSrasWrflDbr_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustLStandActionsRunR: RifleAdjustLStandActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDr_left";
			PlayerCrouch = "AadjPknlMrunSrasWrflDr_left";
			Up = "AadjPknlMrunSrasWrflDr_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustLStandActionsWlkR: RifleAdjustLStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWrflDr_left";
			Up = "AadjPknlMwlkSrasWrflDr_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustLStandActionsRunFR: RifleAdjustLStandActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDfr_left";
			PlayerCrouch = "AadjPknlMrunSrasWrflDfr_left";
			Up = "AadjPknlMrunSrasWrflDfr_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustLStandActionsWlkFR: RifleAdjustLStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWrflDfr_left";
			Up = "AadjPknlMwlkSrasWrflDfr_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustLStandEvasiveActionsF: RifleAdjustLStandActions
		{
			PlayerCrouch = "AadjPknlMevaSrasWrflDf_left";
			Up = "AadjPknlMevaSrasWrflDf_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustLStandEvasiveActionsFR: RifleAdjustLStandActions
		{
			PlayerCrouch = "AadjPknlMevaSrasWrflDfr_left";
			Up = "AadjPknlMevaSrasWrflDfr_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustLStandEvasiveActionsFL: RifleAdjustLStandActions
		{
			PlayerCrouch = "AadjPknlMevaSrasWrflDfl_left";
			Up = "AadjPknlMevaSrasWrflDfl_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustRStandActionsRunF: RifleAdjustRStandActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDf_right";
			PlayerCrouch = "AadjPknlMrunSrasWrflDf_right";
			Up = "AadjPknlMrunSrasWrflDf_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustRStandActionsWlkF: RifleAdjustRStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWrflDf_right";
			Up = "AadjPknlMwlkSrasWrflDf_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustRStandActionsRunFL: RifleAdjustRStandActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDfl_right";
			PlayerCrouch = "AadjPknlMrunSrasWrflDfl_right";
			Up = "AadjPknlMrunSrasWrflDfl_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustRStandActionsWlkFL: RifleAdjustRStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWrflDfl_right";
			Up = "AadjPknlMwlkSrasWrflDfl_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustRStandActionsRunL: RifleAdjustRStandActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDl_right";
			PlayerCrouch = "AadjPknlMrunSrasWrflDl_right";
			Up = "AadjPknlMrunSrasWrflDl_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustRStandActionsWlkL: RifleAdjustRStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWrflDl_right";
			Up = "AadjPknlMwlkSrasWrflDl_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustRStandActionsRunBL: RifleAdjustRStandActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDbl_right";
			PlayerCrouch = "AadjPknlMrunSrasWrflDbl_right";
			Up = "AadjPknlMrunSrasWrflDbl_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustRStandActionsWlkBL: RifleAdjustRStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWrflDbl_right";
			Up = "AadjPknlMwlkSrasWrflDbl_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustRStandActionsRunB: RifleAdjustRStandActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDb_right";
			PlayerCrouch = "AadjPknlMrunSrasWrflDb_right";
			Up = "AadjPknlMrunSrasWrflDb_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustRStandActionsWlkB: RifleAdjustRStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWrflDb_right";
			Up = "AadjPknlMwlkSrasWrflDb_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustRStandActionsRunBR: RifleAdjustRStandActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDbr_right";
			PlayerCrouch = "AadjPknlMrunSrasWrflDbr_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustRStandActionsWlkBR: RifleAdjustRStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWrflDbr_right";
			Up = "AadjPknlMwlkSrasWrflDbr_right";
			Stand = "AadjPercMwlkSrasWrflDbr_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustRStandActionsRunR: RifleAdjustRStandActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDr_right";
			PlayerCrouch = "AadjPknlMrunSrasWrflDr_right";
			Up = "AadjPknlMrunSrasWrflDr_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustRStandActionsWlkR: RifleAdjustRStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWrflDr_right";
			Up = "AadjPknlMwlkSrasWrflDr_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustRStandActionsRunFR: RifleAdjustRStandActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDfr_right";
			PlayerCrouch = "AadjPknlMrunSrasWrflDfr_right";
			Up = "AadjPknlMrunSrasWrflDfr_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustRStandActionsWlkFR: RifleAdjustRStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWrflDfr_right";
			Up = "AadjPknlMwlkSrasWrflDfr_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustRStandEvasiveActionsF: RifleAdjustRStandActions
		{
			PlayerCrouch = "AadjPknlMevaSrasWrflDf_right";
			Up = "AadjPknlMevaSrasWrflDf_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustRStandEvasiveActionsFR: RifleAdjustRStandActions
		{
			PlayerCrouch = "AadjPknlMevaSrasWrflDfr_right";
			Up = "AadjPknlMevaSrasWrflDfr_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustRStandEvasiveActionsFL: RifleAdjustRStandActions
		{
			PlayerCrouch = "AadjPknlMevaSrasWrflDfl_right";
			Up = "AadjPknlMevaSrasWrflDfl_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustFStandActionsRunF: RifleAdjustFStandActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDf_up";
			PlayerCrouch = "AadjPknlMrunSrasWrflDf_up";
			Up = "AadjPknlMrunSrasWrflDf_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustFStandActionsWlkF: RifleAdjustFStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWrflDf_up";
			Up = "AadjPknlMwlkSrasWrflDf_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustFStandActionsRunFL: RifleAdjustFStandActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDfl_up";
			PlayerCrouch = "AadjPknlMrunSrasWrflDfl_up";
			Up = "AadjPknlMrunSrasWrflDfl_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustFStandActionsWlkFL: RifleAdjustFStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWrflDfl_up";
			Up = "AadjPknlMwlkSrasWrflDfl_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustFStandActionsRunL: RifleAdjustFStandActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDl_up";
			PlayerCrouch = "AadjPknlMrunSrasWrflDl_up";
			Up = "AadjPknlMrunSrasWrflDl_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustFStandActionsWlkL: RifleAdjustFStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWrflDl_up";
			Up = "AadjPknlMwlkSrasWrflDl_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustFStandActionsRunBL: RifleAdjustFStandActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDbl_up";
			PlayerCrouch = "AadjPknlMrunSrasWrflDbl_up";
			Up = "AadjPknlMrunSrasWrflDbl_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustFStandActionsWlkBL: RifleAdjustFStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWrflDbl_up";
			Up = "AadjPknlMwlkSrasWrflDbl_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustFStandActionsRunB: RifleAdjustFStandActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDb_up";
			PlayerCrouch = "AadjPknlMrunSrasWrflDb_up";
			Up = "AadjPknlMrunSrasWrflDb_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustFStandActionsWlkB: RifleAdjustFStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWrflDb_up";
			Up = "AadjPknlMwlkSrasWrflDb_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustFStandActionsRunBR: RifleAdjustFStandActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDbr_up";
			PlayerCrouch = "AadjPknlMrunSrasWrflDbr_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustFStandActionsWlkBR: RifleAdjustFStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWrflDbr_up";
			Up = "AadjPknlMwlkSrasWrflDbr_up";
			Stand = "AadjPercMwlkSrasWrflDbr_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustFStandActionsRunR: RifleAdjustFStandActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDr_up";
			PlayerCrouch = "AadjPknlMrunSrasWrflDr_up";
			Up = "AadjPknlMrunSrasWrflDr_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustFStandActionsWlkR: RifleAdjustFStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWrflDr_up";
			Up = "AadjPknlMwlkSrasWrflDr_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustFStandActionsRunFR: RifleAdjustFStandActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDfr_up";
			PlayerCrouch = "AadjPknlMrunSrasWrflDfr_up";
			Up = "AadjPknlMrunSrasWrflDfr_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustFStandActionsWlkFR: RifleAdjustFStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWrflDfr_up";
			Up = "AadjPknlMwlkSrasWrflDfr_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustFStandEvasiveActionsF: RifleAdjustFStandActions
		{
			PlayerCrouch = "AadjPknlMevaSrasWrflDf_up";
			Up = "AadjPknlMevaSrasWrflDf_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustFStandEvasiveActionsFR: RifleAdjustFStandActions
		{
			PlayerCrouch = "AadjPknlMevaSrasWrflDfr_up";
			Up = "AadjPknlMevaSrasWrflDfr_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustFStandEvasiveActionsFL: RifleAdjustFStandActions
		{
			PlayerCrouch = "AadjPknlMevaSrasWrflDfl_up";
			Up = "AadjPknlMevaSrasWrflDfl_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustBStandActionsRunF: RifleAdjustBStandActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDf_down";
			PlayerCrouch = "AadjPknlMrunSrasWrflDf_down";
			Up = "AadjPknlMrunSrasWrflDf_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustBStandActionsWlkF: RifleAdjustBStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWrflDf_down";
			Up = "AadjPknlMwlkSrasWrflDf_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustBStandActionsRunFL: RifleAdjustBStandActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDfl_down";
			PlayerCrouch = "AadjPknlMrunSrasWrflDfl_down";
			Up = "AadjPknlMrunSrasWrflDfl_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustBStandActionsWlkFL: RifleAdjustBStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWrflDfl_down";
			Up = "AadjPknlMwlkSrasWrflDfl_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustBStandActionsRunL: RifleAdjustBStandActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDl_down";
			PlayerCrouch = "AadjPknlMrunSrasWrflDl_down";
			Up = "AadjPknlMrunSrasWrflDl_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustBStandActionsWlkL: RifleAdjustBStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWrflDl_down";
			Up = "AadjPknlMwlkSrasWrflDl_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustBStandActionsRunBL: RifleAdjustBStandActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDbl_down";
			PlayerCrouch = "AadjPknlMrunSrasWrflDbl_down";
			Up = "AadjPknlMrunSrasWrflDbl_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustBStandActionsWlkBL: RifleAdjustBStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWrflDbl_down";
			Up = "AadjPknlMwlkSrasWrflDbl_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustBStandActionsRunB: RifleAdjustBStandActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDb_down";
			PlayerCrouch = "AadjPknlMrunSrasWrflDb_down";
			Up = "AadjPknlMrunSrasWrflDb_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustBStandActionsWlkB: RifleAdjustBStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWrflDb_down";
			Up = "AadjPknlMwlkSrasWrflDb_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustBStandActionsRunBR: RifleAdjustBStandActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDbr_down";
			PlayerCrouch = "AadjPknlMrunSrasWrflDbr_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustBStandActionsWlkBR: RifleAdjustBStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWrflDbr_down";
			Up = "AadjPknlMwlkSrasWrflDbr_down";
			Stand = "AadjPercMwlkSrasWrflDbr_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustBStandActionsRunR: RifleAdjustBStandActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDr_down";
			PlayerCrouch = "AadjPknlMrunSrasWrflDr_down";
			Up = "AadjPknlMrunSrasWrflDr_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustBStandActionsWlkR: RifleAdjustBStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWrflDr_down";
			Up = "AadjPknlMwlkSrasWrflDr_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustBStandActionsRunFR: RifleAdjustBStandActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDfr_down";
			PlayerCrouch = "AadjPknlMrunSrasWrflDfr_down";
			Up = "AadjPknlMrunSrasWrflDfr_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustBStandActionsWlkFR: RifleAdjustBStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWrflDfr_down";
			Up = "AadjPknlMwlkSrasWrflDfr_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustBStandEvasiveActionsF: RifleAdjustBStandActions
		{
			PlayerCrouch = "AadjPknlMevaSrasWrflDf_down";
			Up = "AadjPknlMevaSrasWrflDf_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustBStandEvasiveActionsFR: RifleAdjustBStandActions
		{
			PlayerCrouch = "AadjPknlMevaSrasWrflDfr_down";
			Up = "AadjPknlMevaSrasWrflDfr_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustBStandEvasiveActionsFL: RifleAdjustBStandActions
		{
			PlayerCrouch = "AadjPknlMevaSrasWrflDfl_down";
			Up = "AadjPknlMevaSrasWrflDfl_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustLStandActionsTacF: RifleAdjustLStandActions
		{
			PlayerStand = "AadjPercMrunSrasWrflDf_left";
			PlayerCrouch = "AadjPknlMtacSrasWrflDf_left";
			Up = "AadjPknlMtacSrasWrflDf_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustLStandActionsTacFL: RifleAdjustLStandActions
		{
			PlayerStand = "AadjPercMrunSrasWrflDfl_left";
			PlayerCrouch = "AadjPknlMtacSrasWrflDfl_left";
			Up = "AadjPknlMtacSrasWrflDfl_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustLStandActionsTacL: RifleAdjustLStandActions
		{
			PlayerStand = "AadjPercMrunSrasWrflDl_left";
			PlayerCrouch = "AadjPknlMtacSrasWrflDl_left";
			Up = "AadjPknlMtacSrasWrflDl_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustLStandActionsTacBL: RifleAdjustLStandActions
		{
			PlayerStand = "AadjPercMrunSrasWrflDbl_left";
			PlayerCrouch = "AadjPknlMtacSrasWrflDbl_left";
			Up = "AadjPknlMtacSrasWrflDbl_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustLStandActionsTacB: RifleAdjustLStandActions
		{
			PlayerStand = "AadjPercMrunSrasWrflDb_left";
			PlayerCrouch = "AadjPknlMtacSrasWrflDb_left";
			Up = "AadjPknlMtacSrasWrflDb_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustLStandActionsTacBR: RifleAdjustLStandActions
		{
			PlayerStand = "AadjPercMrunSrasWrflDbr_left";
			PlayerCrouch = "AadjPknlMtacSrasWrflDbr_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustLStandActionsTacR: RifleAdjustLStandActions
		{
			PlayerStand = "AadjPercMrunSrasWrflDr_left";
			PlayerCrouch = "AadjPknlMtacSrasWrflDr_left";
			Up = "AadjPknlMtacSrasWrflDr_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustLStandActionsTacFR: RifleAdjustLStandActions
		{
			PlayerStand = "AadjPercMrunSrasWrflDfr_left";
			PlayerCrouch = "AadjPknlMtacSrasWrflDfr_left";
			Up = "AadjPknlMtacSrasWrflDfr_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustRStandActionsTacF: RifleAdjustRStandActions
		{
			PlayerStand = "AadjPercMrunSrasWrflDf_right";
			PlayerCrouch = "AadjPknlMtacSrasWrflDf_right";
			Up = "AadjPknlMtacSrasWrflDf_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustRStandActionsTacFL: RifleAdjustRStandActions
		{
			PlayerStand = "AadjPercMrunSrasWrflDfl_right";
			PlayerCrouch = "AadjPknlMtacSrasWrflDfl_right";
			Up = "AadjPknlMtacSrasWrflDfl_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustRStandActionsTacL: RifleAdjustRStandActions
		{
			PlayerStand = "AadjPercMrunSrasWrflDl_right";
			PlayerCrouch = "AadjPknlMtacSrasWrflDl_right";
			Up = "AadjPknlMtacSrasWrflDl_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustRStandActionsTacBL: RifleAdjustRStandActions
		{
			PlayerStand = "AadjPercMrunSrasWrflDbl_right";
			PlayerCrouch = "AadjPknlMtacSrasWrflDbl_right";
			Up = "AadjPknlMtacSrasWrflDbl_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustRStandActionsTacB: RifleAdjustRStandActions
		{
			PlayerStand = "AadjPercMrunSrasWrflDb_right";
			PlayerCrouch = "AadjPknlMtacSrasWrflDb_right";
			Up = "AadjPknlMtacSrasWrflDb_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustRStandActionsTacBR: RifleAdjustRStandActions
		{
			PlayerStand = "AadjPercMrunSrasWrflDbr_right";
			PlayerCrouch = "AadjPknlMtacSrasWrflDbr_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustRStandActionsTacR: RifleAdjustRStandActions
		{
			PlayerStand = "AadjPercMrunSrasWrflDr_right";
			PlayerCrouch = "AadjPknlMtacSrasWrflDr_right";
			Up = "AadjPknlMtacSrasWrflDr_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustRStandActionsTacFR: RifleAdjustRStandActions
		{
			PlayerStand = "AadjPercMrunSrasWrflDfr_right";
			PlayerCrouch = "AadjPknlMtacSrasWrflDfr_right";
			Up = "AadjPknlMtacSrasWrflDfr_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustFStandActionsTacF: RifleAdjustFStandActions
		{
			PlayerStand = "AadjPercMrunSrasWrflDf_up";
			PlayerCrouch = "AadjPknlMtacSrasWrflDf_up";
			Up = "AadjPknlMtacSrasWrflDf_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustFStandActionsTacFL: RifleAdjustFStandActions
		{
			PlayerStand = "AadjPercMrunSrasWrflDfl_up";
			PlayerCrouch = "AadjPknlMtacSrasWrflDfl_up";
			Up = "AadjPknlMtacSrasWrflDfl_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustFStandActionsTacL: RifleAdjustFStandActions
		{
			PlayerStand = "AadjPercMrunSrasWrflDl_up";
			PlayerCrouch = "AadjPknlMtacSrasWrflDl_up";
			Up = "AadjPknlMtacSrasWrflDl_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustFStandActionsTacBL: RifleAdjustFStandActions
		{
			PlayerStand = "AadjPercMrunSrasWrflDbl_up";
			PlayerCrouch = "AadjPknlMtacSrasWrflDbl_up";
			Up = "AadjPknlMtacSrasWrflDbl_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustFStandActionsTacB: RifleAdjustFStandActions
		{
			PlayerStand = "AadjPercMrunSrasWrflDb_up";
			PlayerCrouch = "AadjPknlMtacSrasWrflDb_up";
			Up = "AadjPknlMtacSrasWrflDb_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustFStandActionsTacBR: RifleAdjustFStandActions
		{
			PlayerStand = "AadjPercMrunSrasWrflDbr_up";
			PlayerCrouch = "AadjPknlMtacSrasWrflDbr_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustFStandActionsTacR: RifleAdjustFStandActions
		{
			PlayerStand = "AadjPercMrunSrasWrflDr_up";
			PlayerCrouch = "AadjPknlMtacSrasWrflDr_up";
			Up = "AadjPknlMtacSrasWrflDr_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustFStandActionsTacFR: RifleAdjustFStandActions
		{
			PlayerStand = "AadjPercMrunSrasWrflDfr_up";
			PlayerCrouch = "AadjPknlMtacSrasWrflDfr_up";
			Up = "AadjPknlMtacSrasWrflDfr_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustBStandActionsTacF: RifleAdjustBStandActions
		{
			PlayerStand = "AadjPercMrunSrasWrflDf_down";
			PlayerCrouch = "AadjPknlMtacSrasWrflDf_down";
			Up = "AadjPknlMtacSrasWrflDf_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustBStandActionsTacFL: RifleAdjustBStandActions
		{
			PlayerStand = "AadjPercMrunSrasWrflDfl_down";
			PlayerCrouch = "AadjPknlMtacSrasWrflDfl_down";
			Up = "AadjPknlMtacSrasWrflDfl_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustBStandActionsTacL: RifleAdjustBStandActions
		{
			PlayerStand = "AadjPercMrunSrasWrflDl_down";
			PlayerCrouch = "AadjPknlMtacSrasWrflDl_down";
			Up = "AadjPknlMtacSrasWrflDl_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustBStandActionsTacBL: RifleAdjustBStandActions
		{
			PlayerStand = "AadjPercMrunSrasWrflDbl_down";
			PlayerCrouch = "AadjPknlMtacSrasWrflDbl_down";
			Up = "AadjPknlMtacSrasWrflDbl_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustBStandActionsTacB: RifleAdjustBStandActions
		{
			PlayerStand = "AadjPercMrunSrasWrflDb_down";
			PlayerCrouch = "AadjPknlMtacSrasWrflDb_down";
			Up = "AadjPknlMtacSrasWrflDb_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustBStandActionsTacBR: RifleAdjustBStandActions
		{
			PlayerStand = "AadjPercMrunSrasWrflDbr_down";
			PlayerCrouch = "AadjPknlMtacSrasWrflDbr_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustBStandActionsTacR: RifleAdjustBStandActions
		{
			PlayerStand = "AadjPercMrunSrasWrflDr_down";
			PlayerCrouch = "AadjPknlMtacSrasWrflDr_down";
			Up = "AadjPknlMtacSrasWrflDr_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustBStandActionsTacFR: RifleAdjustBStandActions
		{
			PlayerStand = "AadjPercMrunSrasWrflDfr_down";
			PlayerCrouch = "AadjPknlMtacSrasWrflDfr_down";
			Up = "AadjPknlMtacSrasWrflDfr_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustLKneelActionsRunF: RifleAdjustLKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWrflDf_left";
			PlayerStand = "AadjPercMrunSrasWrflDf_left";
			Up = "AadjPercMrunSrasWrflDf_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustLKneelActionsWlkF: RifleAdjustLKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWrflDf_left";
			Up = "AadjPercMwlkSrasWrflDf_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustLKneelActionsRunFL: RifleAdjustLKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWrflDfl_left";
			PlayerStand = "AadjPercMrunSrasWrflDfl_left";
			Up = "AadjPercMrunSrasWrflDfl_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustLKneelActionsWlkFL: RifleAdjustLKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWrflDfl_left";
			Up = "AadjPercMwlkSrasWrflDfl_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustLKneelActionsRunL: RifleAdjustLKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWrflDl_left";
			PlayerStand = "AadjPercMrunSrasWrflDl_left";
			Up = "AadjPercMrunSrasWrflDl_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustLKneelActionsWlkL: RifleAdjustLKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWrflDl_left";
			Up = "AadjPercMwlkSrasWrflDl_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustLKneelActionsRunBL: RifleAdjustLKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWrflDbl_left";
			PlayerStand = "AadjPercMrunSrasWrflDbl_left";
			Up = "AadjPercMrunSrasWrflDbl_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustLKneelActionsWlkBL: RifleAdjustLKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWrflDbl_left";
			Up = "AadjPercMwlkSrasWrflDbl_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustLKneelActionsRunB: RifleAdjustLKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWrflDb_left";
			PlayerStand = "AadjPercMrunSrasWrflDb_left";
			Up = "AadjPercMrunSrasWrflDb_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustLKneelActionsWlkB: RifleAdjustLKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWrflDb_left";
			Up = "AadjPercMwlkSrasWrflDb_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustLKneelActionsRunBR: RifleAdjustLKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWrflDbr_left";
			PlayerStand = "AadjPercMrunSrasWrflDbr_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustLKneelActionsWlkBR: RifleAdjustLKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWrflDbr_left";
			Up = "AadjPercMwlkSrasWrflDbr_left";
			Stand = "AadjPknlMwlkSrasWrflDbr_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustLKneelActionsRunR: RifleAdjustLKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWrflDr_left";
			PlayerStand = "AadjPercMrunSrasWrflDr_left";
			Up = "AadjPercMrunSrasWrflDr_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustLKneelActionsWlkR: RifleAdjustLKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWrflDr_left";
			Up = "AadjPercMwlkSrasWrflDr_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustLKneelActionsRunFR: RifleAdjustLKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWrflDfr_left";
			PlayerStand = "AadjPercMrunSrasWrflDfr_left";
			Up = "AadjPercMrunSrasWrflDfr_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustLKneelActionsWlkFR: RifleAdjustLKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWrflDfr_left";
			Up = "AadjPercMwlkSrasWrflDfr_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustLKneelEvasiveActionsF: RifleAdjustLKneelActions
		{
			PlayerStand = "AadjPercMevaSrasWrflDf_left";
			Up = "AadjPercMevaSrasWrflDf_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustLKneelEvasiveActionsFR: RifleAdjustLKneelActions
		{
			PlayerStand = "AadjPercMevaSrasWrflDfr_left";
			Up = "AadjPercMevaSrasWrflDfr_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustLKneelEvasiveActionsFL: RifleAdjustLKneelActions
		{
			PlayerStand = "AadjPercMevaSrasWrflDfl_left";
			Up = "AadjPercMevaSrasWrflDfl_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustRKneelActionsRunF: RifleAdjustRKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWrflDf_right";
			PlayerStand = "AadjPercMrunSrasWrflDf_right";
			Up = "AadjPercMrunSrasWrflDf_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustRKneelActionsWlkF: RifleAdjustRKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWrflDf_right";
			Up = "AadjPercMwlkSrasWrflDf_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustRKneelActionsRunFL: RifleAdjustRKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWrflDfl_right";
			PlayerStand = "AadjPercMrunSrasWrflDfl_right";
			Up = "AadjPercMrunSrasWrflDfl_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustRKneelActionsWlkFL: RifleAdjustRKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWrflDfl_right";
			Up = "AadjPercMwlkSrasWrflDfl_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustRKneelActionsRunL: RifleAdjustRKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWrflDl_right";
			PlayerStand = "AadjPercMrunSrasWrflDl_right";
			Up = "AadjPercMrunSrasWrflDl_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustRKneelActionsWlkL: RifleAdjustRKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWrflDl_right";
			Up = "AadjPercMwlkSrasWrflDl_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustRKneelActionsRunBL: RifleAdjustRKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWrflDbl_right";
			PlayerStand = "AadjPercMrunSrasWrflDbl_right";
			Up = "AadjPercMrunSrasWrflDbl_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustRKneelActionsWlkBL: RifleAdjustRKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWrflDbl_right";
			Up = "AadjPercMwlkSrasWrflDbl_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustRKneelActionsRunB: RifleAdjustRKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWrflDb_right";
			PlayerStand = "AadjPercMrunSrasWrflDb_right";
			Up = "AadjPercMrunSrasWrflDb_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustRKneelActionsWlkB: RifleAdjustRKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWrflDb_right";
			Up = "AadjPercMwlkSrasWrflDb_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustRKneelActionsRunBR: RifleAdjustRKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWrflDbr_right";
			PlayerStand = "AadjPercMrunSrasWrflDbr_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustRKneelActionsWlkBR: RifleAdjustRKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWrflDbr_right";
			Up = "AadjPercMwlkSrasWrflDbr_right";
			Stand = "AadjPknlMwlkSrasWrflDbr_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustRKneelActionsRunR: RifleAdjustRKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWrflDr_right";
			PlayerStand = "AadjPercMrunSrasWrflDr_right";
			Up = "AadjPercMrunSrasWrflDr_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustRKneelActionsWlkR: RifleAdjustRKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWrflDr_right";
			Up = "AadjPercMwlkSrasWrflDr_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustRKneelActionsRunFR: RifleAdjustRKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWrflDfr_right";
			PlayerStand = "AadjPercMrunSrasWrflDfr_right";
			Up = "AadjPercMrunSrasWrflDfr_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustRKneelActionsWlkFR: RifleAdjustRKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWrflDfr_right";
			Up = "AadjPercMwlkSrasWrflDfr_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustRKneelEvasiveActionsF: RifleAdjustRKneelActions
		{
			PlayerStand = "AadjPercMevaSrasWrflDf_left";
			Up = "AadjPercMevaSrasWrflDf_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustRKneelEvasiveActionsFR: RifleAdjustRKneelActions
		{
			PlayerStand = "AadjPercMevaSrasWrflDfr_left";
			Up = "AadjPercMevaSrasWrflDfr_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustRKneelEvasiveActionsFL: RifleAdjustRKneelActions
		{
			PlayerStand = "AadjPercMevaSrasWrflDfl_left";
			Up = "AadjPercMevaSrasWrflDfl_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustFKneelActionsRunF: RifleAdjustFKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWrflDf_up";
			PlayerStand = "AadjPercMrunSrasWrflDf_up";
			Up = "AadjPercMrunSrasWrflDf_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustFKneelActionsWlkF: RifleAdjustFKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWrflDf_up";
			Up = "AadjPercMwlkSrasWrflDf_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustFKneelActionsRunFL: RifleAdjustFKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWrflDfl_up";
			PlayerStand = "AadjPercMrunSrasWrflDfl_up";
			Up = "AadjPercMrunSrasWrflDfl_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustFKneelActionsWlkFL: RifleAdjustFKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWrflDfl_up";
			Up = "AadjPercMwlkSrasWrflDfl_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustFKneelActionsRunL: RifleAdjustFKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWrflDl_up";
			PlayerStand = "AadjPercMrunSrasWrflDl_up";
			Up = "AadjPercMrunSrasWrflDl_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustFKneelActionsWlkL: RifleAdjustFKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWrflDl_up";
			Up = "AadjPercMwlkSrasWrflDl_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustFKneelActionsRunBL: RifleAdjustFKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWrflDbl_up";
			PlayerStand = "AadjPercMrunSrasWrflDbl_up";
			Up = "AadjPercMrunSrasWrflDbl_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustFKneelActionsWlkBL: RifleAdjustFKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWrflDbl_up";
			Up = "AadjPercMwlkSrasWrflDbl_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustFKneelActionsRunB: RifleAdjustFKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWrflDb_up";
			PlayerStand = "AadjPercMrunSrasWrflDb_up";
			Up = "AadjPercMrunSrasWrflDb_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustFKneelActionsWlkB: RifleAdjustFKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWrflDb_up";
			Up = "AadjPercMwlkSrasWrflDb_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustFKneelActionsRunBR: RifleAdjustFKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWrflDbr_up";
			PlayerStand = "AadjPercMrunSrasWrflDbr_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustFKneelActionsWlkBR: RifleAdjustFKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWrflDbr_up";
			Up = "AadjPercMwlkSrasWrflDbr_up";
			Stand = "AadjPknlMwlkSrasWrflDbr_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustFKneelActionsRunR: RifleAdjustFKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWrflDr_up";
			PlayerStand = "AadjPercMrunSrasWrflDr_up";
			Up = "AadjPercMrunSrasWrflDr_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustFKneelActionsWlkR: RifleAdjustFKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWrflDr_up";
			Up = "AadjPercMwlkSrasWrflDr_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustFKneelActionsRunFR: RifleAdjustFKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWrflDfr_up";
			PlayerStand = "AadjPercMrunSrasWrflDfr_up";
			Up = "AadjPercMrunSrasWrflDfr_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustFKneelActionsWlkFR: RifleAdjustFKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWrflDfr_up";
			Up = "AadjPercMwlkSrasWrflDfr_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustFKneelEvasiveActionsF: RifleAdjustFKneelActions
		{
			PlayerStand = "AadjPercMevaSrasWrflDf_left";
			Up = "AadjPercMevaSrasWrflDf_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustFKneelEvasiveActionsFR: RifleAdjustFKneelActions
		{
			PlayerStand = "AadjPercMevaSrasWrflDfr_left";
			Up = "AadjPercMevaSrasWrflDfr_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustFKneelEvasiveActionsFL: RifleAdjustFKneelActions
		{
			PlayerStand = "AadjPercMevaSrasWrflDfl_left";
			Up = "AadjPercMevaSrasWrflDfl_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustBKneelActionsRunF: RifleAdjustBKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWrflDf_down";
			PlayerStand = "AadjPercMrunSrasWrflDf_down";
			Up = "AadjPercMrunSrasWrflDf_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustBKneelActionsWlkF: RifleAdjustBKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWrflDf_down";
			Up = "AadjPercMwlkSrasWrflDf_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustBKneelActionsRunFL: RifleAdjustBKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWrflDfl_down";
			PlayerStand = "AadjPercMrunSrasWrflDfl_down";
			Up = "AadjPercMrunSrasWrflDfl_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustBKneelActionsWlkFL: RifleAdjustBKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWrflDfl_down";
			Up = "AadjPercMwlkSrasWrflDfl_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustBKneelActionsRunL: RifleAdjustBKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWrflDl_down";
			PlayerStand = "AadjPercMrunSrasWrflDl_down";
			Up = "AadjPercMrunSrasWrflDl_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustBKneelActionsWlkL: RifleAdjustBKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWrflDl_down";
			Up = "AadjPercMwlkSrasWrflDl_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustBKneelActionsRunBL: RifleAdjustBKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWrflDbl_down";
			PlayerStand = "AadjPercMrunSrasWrflDbl_down";
			Up = "AadjPercMrunSrasWrflDbl_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustBKneelActionsWlkBL: RifleAdjustBKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWrflDbl_down";
			Up = "AadjPercMwlkSrasWrflDbl_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustBKneelActionsRunB: RifleAdjustBKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWrflDb_down";
			PlayerStand = "AadjPercMrunSrasWrflDb_down";
			Up = "AadjPercMrunSrasWrflDb_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustBKneelActionsWlkB: RifleAdjustBKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWrflDb_down";
			Up = "AadjPercMwlkSrasWrflDb_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustBKneelActionsRunBR: RifleAdjustBKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWrflDbr_down";
			PlayerStand = "AadjPercMrunSrasWrflDbr_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustBKneelActionsWlkBR: RifleAdjustBKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWrflDbr_down";
			Up = "AadjPercMwlkSrasWrflDbr_down";
			Stand = "AadjPknlMwlkSrasWrflDbr_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustBKneelActionsRunR: RifleAdjustBKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWrflDr_down";
			PlayerStand = "AadjPercMrunSrasWrflDr_down";
			Up = "AadjPercMrunSrasWrflDr_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustBKneelActionsWlkR: RifleAdjustBKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWrflDr_down";
			Up = "AadjPercMwlkSrasWrflDr_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustBKneelActionsRunFR: RifleAdjustBKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWrflDfr_down";
			PlayerStand = "AadjPercMrunSrasWrflDfr_down";
			Up = "AadjPercMrunSrasWrflDfr_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustBKneelActionsWlkFR: RifleAdjustBKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWrflDfr_down";
			Up = "AadjPercMwlkSrasWrflDfr_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustBKneelEvasiveActionsF: RifleAdjustBKneelActions
		{
			PlayerStand = "AadjPercMevaSrasWrflDf_down";
			Up = "AadjPercMevaSrasWrflDf_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustBKneelEvasiveActionsFR: RifleAdjustBKneelActions
		{
			PlayerStand = "AadjPercMevaSrasWrflDfr_down";
			Up = "AadjPercMevaSrasWrflDfr_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustBKneelEvasiveActionsFL: RifleAdjustBKneelActions
		{
			PlayerStand = "AadjPercMevaSrasWrflDfl_down";
			Up = "AadjPercMevaSrasWrflDfl_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustLKneelActionsTacF: RifleAdjustLKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDf_left";
			PlayerCrouch = "AadjPknlMrunSrasWrflDf_left";
			Up = "AadjPercMtacSrasWrflDf_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustLKneelActionsTacFL: RifleAdjustLKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDfl_left";
			PlayerCrouch = "AadjPknlMrunSrasWrflDfl_left";
			Up = "AadjPercMtacSrasWrflDfl_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustLKneelActionsTacL: RifleAdjustLKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDl_left";
			PlayerCrouch = "AadjPknlMrunSrasWrflDl_left";
			Up = "AadjPercMtacSrasWrflDl_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustLKneelActionsTacBL: RifleAdjustLKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDbl_left";
			PlayerCrouch = "AadjPknlMrunSrasWrflDbl_left";
			Up = "AadjPercMtacSrasWrflDbl_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustLKneelActionsTacB: RifleAdjustLKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDb_left";
			PlayerCrouch = "AadjPknlMrunSrasWrflDb_left";
			Up = "AadjPercMtacSrasWrflDb_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustLKneelActionsTacBR: RifleAdjustLKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDbr_left";
			PlayerCrouch = "AadjPknlMrunSrasWrflDbr_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustLKneelActionsTacR: RifleAdjustLKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDr_left";
			PlayerCrouch = "AadjPknlMrunSrasWrflDr_left";
			Up = "AadjPercMtacSrasWrflDr_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustLKneelActionsTacFR: RifleAdjustLKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDfr_left";
			PlayerCrouch = "AadjPknlMrunSrasWrflDfr_left";
			Up = "AadjPercMtacSrasWrflDfr_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustRKneelActionsTacF: RifleAdjustRKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDf_right";
			PlayerCrouch = "AadjPknlMrunSrasWrflDf_right";
			Up = "AadjPercMtacSrasWrflDf_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustRKneelActionsTacFL: RifleAdjustRKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDfl_right";
			PlayerCrouch = "AadjPknlMrunSrasWrflDfl_right";
			Up = "AadjPercMtacSrasWrflDfl_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustRKneelActionsTacL: RifleAdjustRKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDl_right";
			PlayerCrouch = "AadjPknlMrunSrasWrflDl_right";
			Up = "AadjPercMtacSrasWrflDl_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustRKneelActionsTacBL: RifleAdjustRKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDbl_right";
			PlayerCrouch = "AadjPknlMrunSrasWrflDbl_right";
			Up = "AadjPercMtacSrasWrflDbl_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustRKneelActionsTacB: RifleAdjustRKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDb_right";
			PlayerCrouch = "AadjPknlMrunSrasWrflDb_right";
			Up = "AadjPercMtacSrasWrflDb_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustRKneelActionsTacBR: RifleAdjustRKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDbr_right";
			PlayerCrouch = "AadjPknlMrunSrasWrflDbr_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustRKneelActionsTacR: RifleAdjustRKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDr_right";
			PlayerCrouch = "AadjPknlMrunSrasWrflDr_right";
			Up = "AadjPercMtacSrasWrflDr_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustRKneelActionsTacFR: RifleAdjustRKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDfr_right";
			PlayerCrouch = "AadjPknlMrunSrasWrflDfr_right";
			Up = "AadjPercMtacSrasWrflDfr_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustFKneelActionsTacF: RifleAdjustFKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDf_up";
			PlayerCrouch = "AadjPknlMrunSrasWrflDf_up";
			Up = "AadjPercMtacSrasWrflDf_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustFKneelActionsTacFL: RifleAdjustFKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDfl_up";
			PlayerCrouch = "AadjPknlMrunSrasWrflDfl_up";
			Up = "AadjPercMtacSrasWrflDfl_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustFKneelActionsTacL: RifleAdjustFKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDl_up";
			PlayerCrouch = "AadjPknlMrunSrasWrflDl_up";
			Up = "AadjPercMtacSrasWrflDl_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustFKneelActionsTacBL: RifleAdjustFKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDbl_up";
			PlayerCrouch = "AadjPknlMrunSrasWrflDbl_up";
			Up = "AadjPercMtacSrasWrflDbl_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustFKneelActionsTacB: RifleAdjustFKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDb_up";
			PlayerCrouch = "AadjPknlMrunSrasWrflDb_up";
			Up = "AadjPercMtacSrasWrflDb_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustFKneelActionsTacBR: RifleAdjustFKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDbr_up";
			PlayerCrouch = "AadjPknlMrunSrasWrflDbr_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustFKneelActionsTacR: RifleAdjustFKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDr_up";
			PlayerCrouch = "AadjPknlMrunSrasWrflDr_up";
			Up = "AadjPercMtacSrasWrflDr_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustFKneelActionsTacFR: RifleAdjustFKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDfr_up";
			PlayerCrouch = "AadjPknlMrunSrasWrflDfr_up";
			Up = "AadjPercMtacSrasWrflDfr_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustBKneelActionsTacF: RifleAdjustBKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDf_down";
			PlayerCrouch = "AadjPknlMrunSrasWrflDf_down";
			Up = "AadjPercMtacSrasWrflDf_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustBKneelActionsTacFL: RifleAdjustBKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDfl_down";
			PlayerCrouch = "AadjPknlMrunSrasWrflDfl_down";
			Up = "AadjPercMtacSrasWrflDfl_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustBKneelActionsTacL: RifleAdjustBKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDl_down";
			PlayerCrouch = "AadjPknlMrunSrasWrflDl_down";
			Up = "AadjPercMtacSrasWrflDl_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustBKneelActionsTacBL: RifleAdjustBKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDbl_down";
			PlayerCrouch = "AadjPknlMrunSrasWrflDbl_down";
			Up = "AadjPercMtacSrasWrflDbl_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustBKneelActionsTacB: RifleAdjustBKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDb_down";
			PlayerCrouch = "AadjPknlMrunSrasWrflDb_down";
			Up = "AadjPercMtacSrasWrflDb_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustBKneelActionsTacBR: RifleAdjustBKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDbr_down";
			PlayerCrouch = "AadjPknlMrunSrasWrflDbr_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustBKneelActionsTacR: RifleAdjustBKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDr_down";
			PlayerCrouch = "AadjPknlMrunSrasWrflDr_down";
			Up = "AadjPercMtacSrasWrflDr_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleAdjustBKneelActionsTacFR: RifleAdjustBKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWrflDfr_down";
			PlayerCrouch = "AadjPknlMrunSrasWrflDfr_down";
			Up = "AadjPercMtacSrasWrflDfr_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class RifleProneActions: RifleBaseStandActions
		{
			gestureGo[] = {"GestureGoBProne","Gesture"};
			gestureGoB[] = {"GestureGoBProne","Gesture"};
			gestureFreeze[] = {"GestureFreezeProne","Gesture"};
			gesturePoint[] = {"","Gesture"};
			gestureCeaseFire[] = {"","Gesture"};
			gestureCover[] = {"","Gesture"};
			gestureUp[] = {"GestureGoBProne","Gesture"};
			gestureNo[] = {"","Gesture"};
			gestureYes[] = {"","Gesture"};
			gestureFollow[] = {"","Gesture"};
			gestureAdvance[] = {"GestureAdvanceProne","Gesture"};
			GestureReloadM200 = "RifleReloadProneM200";
			GestureReloadMk20 = "RifleReloadProneMk20";
			GestureReloadMk20UGL = "RifleReloadProneMk20UGL";
			GestureReloadMXUGL = "RifleReloadProneMXUGL";
			GestureReloadMX = "RifleReloadProneMX";
			GestureReloadMXCompact = "RifleReloadProneMXCompact";
			GestureReloadMXSniper = "RifleReloadProneMXSniper";
			GestureReloadTRG = "RifleReloadProneTRG";
			GestureReloadKatiba = "RifleReloadProneKatiba";
			GestureReloadKatibaUGL = "RifleReloadProneKatibaUGL";
			GestureReloadTRGUGL = "RifleReloadProneTRGUGL";
			GestureReloadLRR = "RifleReloadProneLRR";
			GestureReloadEBR = "RifleReloadProneEBR";
			GestureReloadSMG_03 = "RifleReloadProneSMG_03";
			GestureReloadSMG_02 = "RifleReloadProneSMG_02";
			GestureReloadSMG_01 = "RifleReloadProneSMG_01";
			GestureReloadSDAR = "RifleReloadProneSDAR";
			GestureReloadDMR = "RifleReloadProneDMR";
			GestureReloadDMR02 = "RifleReloadProneDMR02";
			GestureReloadDMR03 = "RifleReloadProneDMR03";
			GestureReloadDMR04 = "RifleReloadProneDMR04";
			GestureReloadDMR05 = "RifleReloadProneDMR05";
			GestureReloadDMR06 = "RifleReloadProneDMR06";
			GestureReloadMMG01 = "RifleReloadProneMMG01";
			GestureReloadMMG02 = "RifleReloadProneMMG02";
			GestureReloadM4SSAS = "RifleReloadProneM4SSAS";
			ReloadGM6 = "RifleReloadProneGM6";
			GestureReloadPistol = "PistolReloadProne";
			GestureReloadPistolHeavy02 = "PistolHeavy02ReloadProne";
			GestureReloadFlaregun = "PistolReloadProneFlaregun";
			GestureMountMuzzle[] = {"GestureMountMuzzleProne","Gesture"};
			GestureDismountMuzzle[] = {"GestureDismountMuzzleProne","Gesture"};
			MountOptic = "MountOpticProne";
			DismountOptic = "DismountOpticProne";
			MountSide = "";
			DismountSide = "";
			AdjustF = "AadjPpneMstpSrasWrflDup";
			AdjustLF = "AadjPpneMstpSrasWrflDup";
			AdjustRF = "AadjPpneMstpSrasWrflDup";
			AdjustB = "AadjPpneMstpSrasWrflDdown";
			AdjustLB = "AadjPpneMstpSrasWrflDdown";
			AdjustRB = "AadjPpneMstpSrasWrflDdown";
			AdjustR = "AadjPpneMstpSrasWrflDright";
			AdjustL = "AadjPpneMstpSrasWrflDleft";
			stop = "AmovPpneMstpSrasWrflDnon";
			default = "AmovPpneMstpSrasWrflDnon";
			stopRelaxed = "AidlPpneMstpSrasWrflDnon_AI";
			turnL = "AmovPpneMstpSrasWrflDnon_turnL";
			turnR = "AmovPpneMstpSrasWrflDnon_turnR";
			turnLRelaxed = "AmovPpneMstpSrasWrflDnon_turnL";
			turnRRelaxed = "AmovPpneMstpSrasWrflDnon_turnR";
			reloadMagazine = "WeaponMagazineReloadProne";
			reloadMGun = "AmovPpneMstpSrasWrflDnon";
			reloadMortar = "AmovPpneMstpSrasWrflDnon";
			throwPrepare = "AwopPpneMstpSgthWrflDnon_Start";
			throwGrenade = "AwopPpneMstpSgthWrflDnon_Fast_Start";
			WalkF = "AmovPpneMrunSlowWrflDf";
			WalkLF = "AmovPpneMrunSlowWrflDfl";
			WalkRF = "AmovPpneMrunSlowWrflDfr";
			WalkL = "AmovPpneMrunSlowWrflDl";
			WalkR = "AmovPpneMrunSlowWrflDr";
			WalkLB = "AmovPpneMrunSlowWrflDbl";
			WalkRB = "AmovPpneMrunSlowWrflDbr";
			WalkB = "AmovPpneMrunSlowWrflDb";
			PlayerWalkF = "AmovPpneMrunSlowWrflDf";
			PlayerWalkLF = "AmovPpneMrunSlowWrflDfl";
			PlayerWalkRF = "AmovPpneMrunSlowWrflDfr";
			PlayerWalkL = "AmovPpneMrunSlowWrflDl";
			PlayerWalkR = "AmovPpneMrunSlowWrflDr";
			PlayerWalkLB = "AmovPpneMrunSlowWrflDbl";
			PlayerWalkRB = "AmovPpneMrunSlowWrflDbr";
			PlayerWalkB = "AmovPpneMrunSlowWrflDb";
			SlowF = "AmovPpneMsprSlowWrflDf";
			SlowLF = "AmovPpneMsprSlowWrflDfl";
			SlowRF = "AmovPpneMsprSlowWrflDfr";
			SlowL = "AmovPpneMsprSlowWrflDl";
			SlowR = "AmovPpneMsprSlowWrflDr";
			SlowLB = "AmovPpneMsprSlowWrflDbl";
			SlowRB = "AmovPpneMsprSlowWrflDbr";
			SlowB = "AmovPpneMsprSlowWrflDb";
			PlayerSlowF = "AmovPpneMsprSlowWrflDf";
			PlayerSlowLF = "AmovPpneMsprSlowWrflDfl";
			PlayerSlowRF = "AmovPpneMsprSlowWrflDfr";
			PlayerSlowL = "AmovPpneMsprSlowWrflDl";
			PlayerSlowR = "AmovPpneMsprSlowWrflDr";
			PlayerSlowLB = "AmovPpneMsprSlowWrflDbl";
			PlayerSlowRB = "AmovPpneMsprSlowWrflDbr";
			PlayerSlowB = "AmovPpneMsprSlowWrflDb";
			FastF = "AmovPpneMevaSlowWrflDf";
			FastLF = "AmovPpneMsprSlowWrflDfl";
			FastRF = "AmovPpneMsprSlowWrflDfr";
			FastL = "AmovPpneMsprSlowWrflDl";
			FastR = "AmovPpneMsprSlowWrflDr";
			FastLB = "AmovPpneMsprSlowWrflDbl";
			FastRB = "AmovPpneMsprSlowWrflDbr";
			FastB = "AmovPpneMsprSlowWrflDb";
			TactF = "AmovPpneMrunSlowWrflDf";
			TactLF = "AmovPpneMrunSlowWrflDfl";
			TactRF = "AmovPpneMrunSlowWrflDfr";
			TactL = "AmovPpneMrunSlowWrflDl";
			TactR = "AmovPpneMrunSlowWrflDr";
			TactLB = "AmovPpneMrunSlowWrflDbl";
			TactRB = "AmovPpneMrunSlowWrflDbr";
			TactB = "AmovPpneMrunSlowWrflDb";
			PlayerTactF = "AmovPpneMrunSlowWrflDf";
			PlayerTactLF = "AmovPpneMrunSlowWrflDfl";
			PlayerTactRF = "AmovPpneMrunSlowWrflDfr";
			PlayerTactL = "AmovPpneMrunSlowWrflDl";
			PlayerTactR = "AmovPpneMrunSlowWrflDr";
			PlayerTactLB = "AmovPpneMrunSlowWrflDbl";
			PlayerTactRB = "AmovPpneMrunSlowWrflDbr";
			PlayerTactB = "AmovPpneMrunSlowWrflDb";
			EvasiveLeft = "AmovPpneMstpSrasWrflDnon_AmovPpneMevaSlowWrflDl";
			EvasiveRight = "AmovPpneMstpSrasWrflDnon_AmovPpneMevaSlowWrflDr";
			down = "AmovPercMstpSrasWrflDnon";
			weaponOn = "AmovPknlMstpSrasWlnrDnon";
			weaponOff = "AmovPpneMstpSrasWrflDnon";
			binocOn = "AwopPpneMstpSoptWbinDnon_rfl";
			binocOff = "AmovPpneMstpSrasWrflDnon";
			handGunOn = "AmovPpneMstpSrasWpstDnon";
			takeFlag = "AmovPpneMstpSrasWrflDnon";
			putDown = "AmovPpneMstpSrasWrflDnon_AinvPpneMstpSrasWrflDnon_Putdown";
			treated = "AmovPpneMstpSrasWrflDnon_healed";
			CanNotMove = "AmovPpneMstpSrasWrflDnon";
			FireNotPossible = "AmovPpneMstpSrasWrflDnon";
			strokeGun = "AmovPpneMstpSrasWrflDnon";
			sitDown = "";
			salute = "";
			medic = "AinvPpneMstpSlayWrflDnon_medic";
			medicOther = "AinvPpneMstpSlayWrflDnon_medicOther";
			turnSpeed = 2.5;
			leanRRot = 0;
			leanRShift = 0;
			leanLRot = 0;
			leanLShift = 0;
			upDegree = "ManPosLying";
			stance = "ManStanceProne";
			Stand = "AmovPercMstpSrasWrflDnon";
			Diary = "";
			PlayerProne = "";
			Gear = "AinvPpneMstpSrasWrflDnon";
			GetOver = "";
			Relax = "AmovPpneMstpSrasWrflDnon_relax";
			StartFreefall = "AfalPpneMstpSrasWrflDnon";
			PrimaryWeapon = "AmovPpneMstpSrasWrflDnon";
			SecondaryWeapon = "AmovPknlMstpSrasWlnrDnon";
			Binoculars = "AmovPpneMstpSoptWbinDnon";
		};
		class RifleProneActionsEvasiveF: RifleProneActions
		{
			PlayerStand = "AmovPercMevaSrasWrflDf";
			down = "AmovPercMevaSrasWrflDf";
		};
		class RifleAdjustProneBaseActions: RifleProneActions
		{
			Lying = "";
			Crouch = "";
		};
		class RifleAdjustBProneActions: RifleAdjustProneBaseActions
		{
			AdjustF = "AmovPpneMstpSrasWrflDnon";
			stop = "AadjPpneMstpSrasWrflDdown";
			default = "AadjPpneMstpSrasWrflDdown";
			stopRelaxed = "AadjPpneMstpSrasWrflDdown";
			turnL = "AadjPpneMstpSrasWrflDdown_turnL";
			turnR = "AadjPpneMstpSrasWrflDdown_turnR";
			turnLRelaxed = "AadjPpneMstpSrasWrflDdown_turnL";
			turnRRelaxed = "AadjPpneMstpSrasWrflDdown_turnR";
			ReloadGM6[] = {"GestureReloadGM6","Gesture"};
			reloadMGun = "";
			reloadMortar = "";
			throwPrepare = "";
			throwGrenade[] = {"GestureThrowGrenade","Gesture"};
			WalkF = "AadjPpneMstpSrasWrflDdown";
			WalkLF = "AadjPpneMstpSrasWrflDdown";
			WalkRF = "AadjPpneMstpSrasWrflDdown";
			WalkL = "AadjPpneMstpSrasWrflDdown";
			WalkR = "AadjPpneMstpSrasWrflDdown";
			WalkLB = "AadjPpneMstpSrasWrflDdown";
			WalkRB = "AadjPpneMstpSrasWrflDdown";
			WalkB = "AadjPpneMstpSrasWrflDdown";
			PlayerWalkF = "AadjPpneMstpSrasWrflDdown";
			PlayerWalkLF = "AadjPpneMstpSrasWrflDdown";
			PlayerWalkRF = "AadjPpneMstpSrasWrflDdown";
			PlayerWalkL = "AadjPpneMstpSrasWrflDdown";
			PlayerWalkR = "AadjPpneMstpSrasWrflDdown";
			PlayerWalkLB = "AadjPpneMstpSrasWrflDdown";
			PlayerWalkRB = "AadjPpneMstpSrasWrflDdown";
			PlayerWalkB = "AadjPpneMstpSrasWrflDdown";
			SlowF = "AadjPpneMstpSrasWrflDdown";
			SlowLF = "AadjPpneMstpSrasWrflDdown";
			SlowRF = "AadjPpneMstpSrasWrflDdown";
			SlowL = "AadjPpneMstpSrasWrflDdown";
			SlowR = "AadjPpneMstpSrasWrflDdown";
			SlowLB = "AadjPpneMstpSrasWrflDdown";
			SlowRB = "AadjPpneMstpSrasWrflDdown";
			SlowB = "AadjPpneMstpSrasWrflDdown";
			PlayerSlowF = "AadjPpneMstpSrasWrflDdown";
			PlayerSlowLF = "AadjPpneMstpSrasWrflDdown";
			PlayerSlowRF = "AadjPpneMstpSrasWrflDdown";
			PlayerSlowL = "AadjPpneMstpSrasWrflDdown";
			PlayerSlowR = "AadjPpneMstpSrasWrflDdown";
			PlayerSlowLB = "AadjPpneMstpSrasWrflDdown";
			PlayerSlowRB = "AadjPpneMstpSrasWrflDdown";
			PlayerSlowB = "AadjPpneMstpSrasWrflDdown";
			FastF = "AadjPpneMstpSrasWrflDdown";
			FastLF = "AadjPpneMstpSrasWrflDdown";
			FastRF = "AadjPpneMstpSrasWrflDdown";
			FastL = "AadjPpneMstpSrasWrflDdown";
			FastR = "AadjPpneMstpSrasWrflDdown";
			FastLB = "AadjPpneMstpSrasWrflDdown";
			FastRB = "AadjPpneMstpSrasWrflDdown";
			FastB = "AadjPpneMstpSrasWrflDdown";
			TactF = "AadjPpneMstpSrasWrflDdown";
			TactLF = "AadjPpneMstpSrasWrflDdown";
			TactRF = "AadjPpneMstpSrasWrflDdown";
			TactL = "AadjPpneMstpSrasWrflDdown";
			TactR = "AadjPpneMstpSrasWrflDdown";
			TactLB = "AadjPpneMstpSrasWrflDdown";
			TactRB = "AadjPpneMstpSrasWrflDdown";
			TactB = "AadjPpneMstpSrasWrflDdown";
			PlayerTactF = "AadjPpneMstpSrasWrflDdown";
			PlayerTactLF = "AadjPpneMstpSrasWrflDdown";
			PlayerTactRF = "AadjPpneMstpSrasWrflDdown";
			PlayerTactL = "AadjPpneMstpSrasWrflDdown";
			PlayerTactR = "AadjPpneMstpSrasWrflDdown";
			PlayerTactLB = "AadjPpneMstpSrasWrflDdown";
			PlayerTactRB = "AadjPpneMstpSrasWrflDdown";
			PlayerTactB = "AadjPpneMstpSrasWrflDdown";
			EvasiveLeft = "AadjPpneMstpSrasWrflDdown";
			EvasiveRight = "AadjPpneMstpSrasWrflDdown";
			putDown = "AmovPpneMstpSrasWrflDnon";
			Combat = "AadjPpneMstpSrasWrflDdown";
			strokeGun = "";
			limitFast = 3.5;
			leanRRot = 0.1;
			leanRShift = 0.1;
			leanLRot = 0.1;
			leanLShift = 0.1;
			PlayerProne = "AmovPpneMstpSrasWrflDnon";
			Gear = "";
		};
		class RifleAdjustFProneActions: RifleAdjustProneBaseActions
		{
			gestureGo = "";
			gestureGoB = "";
			gestureFreeze = "";
			gestureUp = "";
			gestureAdvance[] = {"GestureAdvance","Gesture"};
			GestureReloadMk20[] = {"GestureReloadMk20Context","Gesture"};
			GestureReloadMk20UGL[] = {"GestureReloadMk20UGLContext","Gesture"};
			GestureReloadMXUGL[] = {"GestureReloadMXUGLContext","Gesture"};
			GestureReloadMX[] = {"GestureReloadMXContext","Gesture"};
			GestureReloadMXCompact[] = {"GestureReloadMXCompactContext","Gesture"};
			GestureReloadMXSniper[] = {"GestureReloadMXSniperContext","Gesture"};
			GestureReloadTRG[] = {"GestureReloadTRGContext","Gesture"};
			GestureReloadTRGUGL[] = {"GestureReloadTRGUGLContext","Gesture"};
			GestureReloadKatibaUGL[] = {"GestureReloadKatibaUGLContext","Gesture"};
			GestureReloadKatiba[] = {"GestureReloadKatibaContext","Gesture"};
			GestureReloadLRR[] = {"GestureReloadLRRContext","Gesture"};
			GestureReloadEBR[] = {"GestureReloadEBRContext","Gesture"};
			GestureReloadSMG_02[] = {"GestureReloadSMG_02Context","Gesture"};
			GestureReloadSMG_03[] = {"GestureReloadSMG_03Context","Gesture"};
			GestureReloadPistol[] = {"GestureReloadPistolContext","Gesture"};
			GestureReloadPistolHeavy02[] = {"GestureReloadPistolHeavy02Context","Gesture"};
			GestureReloadFlaregun[] = {"GestureReloadFlaregunContext","Gesture"};
			GestureReloadSMG_01[] = {"GestureReloadSMG_01Context","Gesture"};
			GestureReloadSDAR[] = {"GestureReloadSDARContext","Gesture"};
			GestureReloadDMR[] = {"GestureReloadDMRContext","Gesture"};
			GestureReloadDMR02[] = {"GestureReloadDMR02Context","Gesture"};
			GestureReloadDMR03[] = {"GestureReloadDMR03Context","Gesture"};
			GestureReloadDMR04[] = {"GestureReloadDMR04Context","Gesture"};
			GestureReloadDMR05[] = {"GestureReloadDMR05Context","Gesture"};
			GestureReloadDMR06[] = {"GestureReloadDMR06Context","Gesture"};
			GestureReloadMMG01[] = {"GestureReloadMMG01Context","Gesture"};
			GestureReloadMMG02[] = {"GestureReloadMMG02Context","Gesture"};
			GestureReloadM4SSAS[] = {"GestureReloadM4SSASContext","Gesture"};
			GestureMountMuzzle[] = {"GestureMountMuzzle","Gesture"};
			GestureDismountMuzzle[] = {"GestureDismountMuzzle","Gesture"};
			throwGrenade[] = {"GestureThrowGrenadeContext","Gesture"};
			MountOptic = "";
			DismountOptic = "";
			AdjustF = "AadjPknlMstpSrasWrflDdown";
			AdjustB = "AmovPpneMstpSrasWrflDnon";
			stop = "AadjPpneMstpSrasWrflDup";
			default = "AadjPpneMstpSrasWrflDup";
			stopRelaxed = "AadjPpneMstpSrasWrflDup";
			turnL = "AadjPpneMstpSrasWrflDup_turnL";
			turnR = "AadjPpneMstpSrasWrflDup_turnR";
			turnLRelaxed = "AadjPpneMstpSrasWrflDup_turnL";
			turnRRelaxed = "AadjPpneMstpSrasWrflDup_turnR";
			ReloadGM6[] = {"GestureReloadGM6Context","Gesture"};
			reloadMGun = "";
			reloadMortar = "";
			throwPrepare = "";
			WalkF = "AadjPpneMwlkSrasWrflDup_f";
			WalkLF = "AadjPpneMwlkSrasWrflDup_fl";
			WalkRF = "AadjPpneMwlkSrasWrflDup_fr";
			WalkL = "AadjPpneMwlkSrasWrflDup_l";
			WalkR = "AadjPpneMwlkSrasWrflDup_r";
			WalkLB = "AadjPpneMwlkSrasWrflDup_bl";
			WalkRB = "AadjPpneMwlkSrasWrflDup_br";
			WalkB = "AadjPpneMwlkSrasWrflDup_b";
			PlayerWalkF = "AadjPpneMwlkSrasWrflDup_f";
			PlayerWalkLF = "AadjPpneMwlkSrasWrflDup_fl";
			PlayerWalkRF = "AadjPpneMwlkSrasWrflDup_fr";
			PlayerWalkL = "AadjPpneMwlkSrasWrflDup_l";
			PlayerWalkR = "AadjPpneMwlkSrasWrflDup_r";
			PlayerWalkLB = "AadjPpneMwlkSrasWrflDup_bl";
			PlayerWalkRB = "AadjPpneMwlkSrasWrflDup_br";
			PlayerWalkB = "AadjPpneMwlkSrasWrflDup_b";
			SlowF = "AadjPpneMwlkSrasWrflDup_f";
			SlowLF = "AadjPpneMwlkSrasWrflDup_fl";
			SlowRF = "AadjPpneMwlkSrasWrflDup_fr";
			SlowL = "AadjPpneMwlkSrasWrflDup_l";
			SlowR = "AadjPpneMwlkSrasWrflDup_r";
			SlowLB = "AadjPpneMwlkSrasWrflDup_bl";
			SlowRB = "AadjPpneMwlkSrasWrflDup_br";
			SlowB = "AadjPpneMwlkSrasWrflDup_b";
			PlayerSlowF = "AadjPpneMwlkSrasWrflDup_f";
			PlayerSlowLF = "AadjPpneMwlkSrasWrflDup_fl";
			PlayerSlowRF = "AadjPpneMwlkSrasWrflDup_fr";
			PlayerSlowL = "AadjPpneMwlkSrasWrflDup_l";
			PlayerSlowR = "AadjPpneMwlkSrasWrflDup_r";
			PlayerSlowLB = "AadjPpneMwlkSrasWrflDup_bl";
			PlayerSlowRB = "AadjPpneMwlkSrasWrflDup_br";
			PlayerSlowB = "AadjPpneMwlkSrasWrflDup_b";
			FastF = "AadjPpneMwlkSrasWrflDup_f";
			FastLF = "AadjPpneMwlkSrasWrflDup_fl";
			FastRF = "AadjPpneMwlkSrasWrflDup_fr";
			FastL = "AadjPpneMwlkSrasWrflDup_l";
			FastR = "AadjPpneMwlkSrasWrflDup_r";
			FastLB = "AadjPpneMwlkSrasWrflDup_bl";
			FastRB = "AadjPpneMwlkSrasWrflDup_br";
			FastB = "AadjPpneMwlkSrasWrflDup_b";
			TactF = "AadjPpneMwlkSrasWrflDup_f";
			TactLF = "AadjPpneMwlkSrasWrflDup_fl";
			TactRF = "AadjPpneMwlkSrasWrflDup_fr";
			TactL = "AadjPpneMwlkSrasWrflDup_l";
			TactR = "AadjPpneMwlkSrasWrflDup_r";
			TactLB = "AadjPpneMwlkSrasWrflDup_bl";
			TactRB = "AadjPpneMwlkSrasWrflDup_br";
			TactB = "AadjPpneMwlkSrasWrflDup_b";
			PlayerTactF = "AadjPpneMwlkSrasWrflDup_f";
			PlayerTactLF = "AadjPpneMwlkSrasWrflDup_fl";
			PlayerTactRF = "AadjPpneMwlkSrasWrflDup_fr";
			PlayerTactL = "AadjPpneMwlkSrasWrflDup_l";
			PlayerTactR = "AadjPpneMwlkSrasWrflDup_r";
			PlayerTactLB = "AadjPpneMwlkSrasWrflDup_bl";
			PlayerTactRB = "AadjPpneMwlkSrasWrflDup_br";
			PlayerTactB = "AadjPpneMwlkSrasWrflDup_b";
			EvasiveLeft = "";
			EvasiveRight = "";
			Down = "AmovPpneMstpSrasWrflDnon";
			putDown = "AmovPpneMstpSrasWrflDnon";
			Combat = "AadjPpneMstpSrasWrflDup";
			strokeGun = "";
			limitFast = 3.5;
			leanRRot = 0.1;
			leanRShift = 0.1;
			leanLRot = 0.1;
			leanLShift = 0.1;
			PlayerProne = "AmovPpneMstpSrasWrflDnon";
			Gear = "";
		};
		class RifleAdjustLProneActions: RifleAdjustProneBaseActions
		{
			gestureGo = "";
			gestureGoB = "";
			gestureFreeze = "";
			gestureUp = "";
			gestureAdvance[] = {"GestureAdvance","Gesture"};
			GestureReloadMk20[] = {"GestureReloadMk20Context","Gesture"};
			GestureReloadMk20UGL[] = {"GestureReloadMk20UGLContext","Gesture"};
			GestureReloadMXUGL[] = {"GestureReloadMXUGLContext","Gesture"};
			GestureReloadMX[] = {"GestureReloadMXContext","Gesture"};
			GestureReloadMXCompact[] = {"GestureReloadMXCompactContext","Gesture"};
			GestureReloadMXSniper[] = {"GestureReloadMXSniperContext","Gesture"};
			GestureReloadTRG[] = {"GestureReloadTRGContext","Gesture"};
			GestureReloadTRGUGL[] = {"GestureReloadTRGUGLContext","Gesture"};
			GestureReloadKatibaUGL[] = {"GestureReloadKatibaUGLContext","Gesture"};
			GestureReloadKatiba[] = {"GestureReloadKatibaContext","Gesture"};
			GestureReloadLRR[] = {"GestureReloadLRRContext","Gesture"};
			GestureReloadEBR[] = {"GestureReloadEBRContext","Gesture"};
			GestureReloadSMG_02[] = {"GestureReloadSMG_02Context","Gesture"};
			GestureReloadSMG_03[] = {"GestureReloadSMG_03Context","Gesture"};
			GestureReloadPistol[] = {"GestureReloadPistolContext","Gesture"};
			GestureReloadPistolHeavy02[] = {"GestureReloadPistolHeavy02Context","Gesture"};
			GestureReloadFlaregun[] = {"GestureReloadFlaregunContext","Gesture"};
			GestureReloadSMG_01[] = {"GestureReloadSMG_01Context","Gesture"};
			GestureReloadSDAR[] = {"GestureReloadSDARContext","Gesture"};
			GestureReloadDMR[] = {"GestureReloadDMRContext","Gesture"};
			GestureReloadDMR02[] = {"GestureReloadDMR02Context","Gesture"};
			GestureReloadDMR03[] = {"GestureReloadDMR03Context","Gesture"};
			GestureReloadDMR04[] = {"GestureReloadDMR04Context","Gesture"};
			GestureReloadDMR05[] = {"GestureReloadDMR05Context","Gesture"};
			GestureReloadDMR06[] = {"GestureReloadDMR06Context","Gesture"};
			GestureReloadMMG01[] = {"GestureReloadMMG01Context","Gesture"};
			GestureReloadMMG02[] = {"GestureReloadMMG02Context","Gesture"};
			GestureReloadM4SSAS[] = {"GestureReloadM4SSASContext","Gesture"};
			GestureMountMuzzle[] = {"GestureMountMuzzle","Gesture"};
			GestureDismountMuzzle[] = {"GestureDismountMuzzle","Gesture"};
			throwGrenade[] = {"GestureThrowGrenadeContext","Gesture"};
			MountOptic = "";
			DismountOptic = "";
			AdjustR = "AmovPpneMstpSrasWrflDnon";
			stop = "AadjPpneMstpSrasWrflDleft";
			default = "AadjPpneMstpSrasWrflDleft";
			stopRelaxed = "AadjPpneMstpSrasWrflDleft";
			turnL = "AadjPpneMstpSrasWrflDleft";
			turnR = "AadjPpneMstpSrasWrflDleft";
			turnLRelaxed = "AadjPpneMstpSrasWrflDleft";
			turnRRelaxed = "AadjPpneMstpSrasWrflDleft";
			ReloadGM6[] = {"GestureReloadGM6Context","Gesture"};
			reloadMGun = "";
			reloadMortar = "";
			throwPrepare = "";
			WalkF = "";
			WalkLF = "";
			WalkRF = "";
			WalkL = "";
			WalkR = "";
			WalkLB = "";
			WalkRB = "";
			WalkB = "";
			PlayerWalkF = "";
			PlayerWalkLF = "";
			PlayerWalkRF = "";
			PlayerWalkL = "AadjPpneMwlkSrasWrflDleft_l";
			PlayerWalkR = "AadjPpneMwlkSrasWrflDleft_r";
			PlayerWalkLB = "";
			PlayerWalkRB = "";
			PlayerWalkB = "";
			SlowF = "";
			SlowLF = "";
			SlowRF = "";
			SlowL = "AadjPpneMwlkSrasWrflDleft_l";
			SlowR = "AadjPpneMwlkSrasWrflDleft_r";
			SlowLB = "";
			SlowRB = "";
			SlowB = "";
			PlayerSlowF = "";
			PlayerSlowLF = "";
			PlayerSlowRF = "";
			PlayerSlowL = "AadjPpneMwlkSrasWrflDleft_l";
			PlayerSlowR = "AadjPpneMwlkSrasWrflDleft_r";
			PlayerSlowLB = "";
			PlayerSlowRB = "";
			PlayerSlowB = "";
			FastF = "";
			FastLF = "";
			FastRF = "";
			FastL = "AadjPpneMwlkSrasWrflDleft_l";
			FastR = "AadjPpneMwlkSrasWrflDleft_r";
			FastLB = "";
			FastRB = "";
			FastB = "";
			TactF = "";
			TactLF = "";
			TactRF = "";
			TactL = "AadjPpneMwlkSrasWrflDleft_l";
			TactR = "AadjPpneMwlkSrasWrflDleft_r";
			TactLB = "";
			TactRB = "";
			TactB = "";
			PlayerTactF = "";
			PlayerTactLF = "";
			PlayerTactRF = "";
			PlayerTactL = "AadjPpneMwlkSrasWrflDleft_l";
			PlayerTactR = "AadjPpneMwlkSrasWrflDleft_r";
			PlayerTactLB = "";
			PlayerTactRB = "";
			PlayerTactB = "";
			EvasiveLeft = "AadjPpneMstpSrasWrflDleft";
			EvasiveRight = "AadjPpneMstpSrasWrflDleft";
			putDown = "AmovPpneMstpSrasWrflDnon";
			Combat = "AadjPpneMstpSrasWrflDleft";
			strokeGun = "";
			limitFast = 3.5;
			leanRRot = 0.1;
			leanRShift = 0.1;
			leanLRot = 0.1;
			leanLShift = 0.1;
			PlayerProne = "AmovPpneMstpSrasWrflDnon";
			Gear = "";
		};
		class RifleAdjustRProneActions: RifleAdjustProneBaseActions
		{
			gestureGo = "";
			gestureGoB = "";
			gestureFreeze = "";
			gestureUp = "";
			gestureAdvance[] = {"GestureAdvance","Gesture"};
			GestureReloadMk20[] = {"GestureReloadMk20ContextAnimDrive","Gesture"};
			GestureReloadMk20UGL[] = {"GestureReloadMk20UGLContextAnimDrive","Gesture"};
			GestureReloadMXUGL[] = {"GestureReloadMXUGLContextAnimDrive","Gesture"};
			GestureReloadMX[] = {"GestureReloadMXContextAnimDrive","Gesture"};
			GestureReloadMXCompact[] = {"GestureReloadMXCompactContextAnimDrive","Gesture"};
			GestureReloadMXSniper[] = {"GestureReloadMXSniperContextAnimDrive","Gesture"};
			GestureReloadTRG[] = {"GestureReloadTRGContextAnimDrive","Gesture"};
			GestureReloadTRGUGL[] = {"GestureReloadTRGUGLContextAnimDrive","Gesture"};
			GestureReloadKatibaUGL[] = {"GestureReloadKatibaUGLContextAnimDrive","Gesture"};
			GestureReloadKatiba[] = {"GestureReloadKatibaContextAnimDrive","Gesture"};
			GestureReloadLRR[] = {"GestureReloadLRRContextAnimDrive","Gesture"};
			GestureReloadEBR[] = {"GestureReloadEBRContextAnimDrive","Gesture"};
			GestureReloadSMG_02[] = {"GestureReloadSMG_02ContextAnimDrive","Gesture"};
			GestureReloadSMG_03[] = {"GestureReloadSMG_03ContextAnimDrive","Gesture"};
			GestureReloadPistol[] = {"GestureReloadPistolContextAnimDrive","Gesture"};
			GestureReloadPistolHeavy02[] = {"GestureReloadPistolHeavy02ContextAnimDrive","Gesture"};
			GestureReloadFlaregun[] = {"GestureReloadFlaregunContextAnimDrive","Gesture"};
			GestureReloadSMG_01[] = {"GestureReloadSMG_01ContextAnimDrive","Gesture"};
			GestureReloadSDAR[] = {"GestureReloadSDARContextAnimDrive","Gesture"};
			GestureReloadDMR[] = {"GestureReloadDMRContextAnimDrive","Gesture"};
			GestureReloadDMR02[] = {"GestureReloadDMR02ContextAnimDrive","Gesture"};
			GestureReloadDMR03[] = {"GestureReloadDMR03ContextAnimDrive","Gesture"};
			GestureReloadDMR04[] = {"GestureReloadDMR04ContextAnimDrive","Gesture"};
			GestureReloadDMR05[] = {"GestureReloadDMR05ContextAnimDrive","Gesture"};
			GestureReloadDMR06[] = {"GestureReloadDMR06ContextAnimDrive","Gesture"};
			GestureReloadMMG01[] = {"GestureReloadMMG01ContextAnimDrive","Gesture"};
			GestureReloadMMG02[] = {"GestureReloadMMG02ContextAnimDrive","Gesture"};
			GestureReloadM4SSAS[] = {"GestureReloadM4SSASContextAnimDrive","Gesture"};
			GestureMountMuzzle[] = {"GestureMountMuzzle","Gesture"};
			GestureDismountMuzzle[] = {"GestureDismountMuzzle","Gesture"};
			MountOptic = "";
			DismountOptic = "";
			stop = "AadjPpneMstpSrasWrflDright";
			default = "AadjPpneMstpSrasWrflDright";
			stopRelaxed = "AadjPpneMstpSrasWrflDright";
			turnL = "AadjPpneMstpSrasWrflDright";
			turnR = "AadjPpneMstpSrasWrflDright";
			turnLRelaxed = "AadjPpneMstpSrasWrflDright";
			turnRRelaxed = "AadjPpneMstpSrasWrflDright";
			ReloadGM6[] = {"GestureReloadGM6Context","Gesture"};
			reloadMGun = "";
			reloadMortar = "";
			throwPrepare = "";
			throwGrenade[] = {"GestureThrowGrenadeContext","Gesture"};
			WalkF = "";
			WalkLF = "";
			WalkRF = "";
			WalkL = "";
			WalkR = "";
			WalkLB = "";
			WalkRB = "";
			WalkB = "";
			PlayerWalkF = "";
			PlayerWalkLF = "";
			PlayerWalkRF = "";
			PlayerWalkL = "AadjPpneMwlkSrasWrflDright_l";
			PlayerWalkR = "AadjPpneMwlkSrasWrflDright_r";
			PlayerWalkLB = "";
			PlayerWalkRB = "";
			PlayerWalkB = "";
			SlowF = "";
			SlowLF = "";
			SlowRF = "";
			SlowL = "AadjPpneMwlkSrasWrflDright_l";
			SlowR = "AadjPpneMwlkSrasWrflDright_r";
			SlowLB = "";
			SlowRB = "";
			SlowB = "";
			PlayerSlowF = "";
			PlayerSlowLF = "";
			PlayerSlowRF = "";
			PlayerSlowL = "AadjPpneMwlkSrasWrflDright_l";
			PlayerSlowR = "AadjPpneMwlkSrasWrflDright_r";
			PlayerSlowLB = "";
			PlayerSlowRB = "";
			PlayerSlowB = "";
			FastF = "";
			FastLF = "";
			FastRF = "";
			FastL = "AadjPpneMwlkSrasWrflDright_l";
			FastR = "AadjPpneMwlkSrasWrflDright_r";
			FastLB = "";
			FastRB = "";
			FastB = "";
			TactF = "";
			TactLF = "";
			TactRF = "";
			TactL = "AadjPpneMwlkSrasWrflDright_l";
			TactR = "AadjPpneMwlkSrasWrflDright_r";
			TactLB = "";
			TactRB = "";
			TactB = "";
			PlayerTactF = "";
			PlayerTactLF = "";
			PlayerTactRF = "";
			PlayerTactL = "AadjPpneMwlkSrasWrflDright_l";
			PlayerTactR = "AadjPpneMwlkSrasWrflDright_r";
			PlayerTactLB = "";
			PlayerTactRB = "";
			PlayerTactB = "";
			EvasiveLeft = "AadjPpneMstpSrasWrflDright";
			EvasiveRight = "AadjPpneMstpSrasWrflDright";
			putDown = "AmovPpneMstpSrasWrflDnon";
			Combat = "AadjPpneMstpSrasWrflDright";
			strokeGun = "";
			limitFast = 3.5;
			leanRRot = 0.1;
			leanRShift = 0.1;
			leanLRot = 0.1;
			leanLShift = 0.1;
			PlayerProne = "AmovPpneMstpSrasWrflDnon";
			Gear = "";
		};
		class RifleProneActionsRunF: RifleProneActions
		{
			PlayerStand = "AmovPpneMstpSrasWrflDnon_AmovPercMsprSlowWrflDf";
		};
		class RifleProneActionsRunB: RifleProneActions{};
		class PistolStandActions: NoActions
		{
			gestureGo[] = {"GestureGoStandPistol","Gesture"};
			gestureGoB[] = {"GestureGoBStand","Gesture"};
			gestureFreeze[] = {"GestureFreezeStandPistol","Gesture"};
			gesturePoint[] = {"GesturePointStand","Gesture"};
			gestureCeaseFire[] = {"GestureCeaseFire","Gesture"};
			gestureCover[] = {"GestureCover","Gesture"};
			gestureUp[] = {"GestureUp","Gesture"};
			gestureNo[] = {"GestureNo","Gesture"};
			gestureYes[] = {"GestureYes","Gesture"};
			gestureFollow[] = {"GestureFollow","Gesture"};
			gestureAdvance[] = {"GestureAdvance","Gesture"};
			gestureHi[] = {"GestureHi","Gesture"};
			gestureHiB[] = {"GestureHiB","Gesture"};
			gestureHiC[] = {"GestureHiC","Gesture"};
			stop = "AmovPercMstpSrasWpstDnon";
			default = "AmovPercMstpSrasWpstDnon";
			stopRelaxed = "AmovPercMstpSrasWpstDnon";
			turnL = "AmovPercMstpSrasWpstDnon_turnL";
			turnR = "AmovPercMstpSrasWpstDnon_turnR";
			turnLRelaxed = "AmovPercMstpSrasWpstDnon_turnL";
			turnRRelaxed = "AmovPercMstpSrasWpstDnon_turnR";
			reloadMagazine[] = {"PistolMagazineReloadStand_g","Gesture"};
			throwPrepare = "AwopPercMstpSgthWpstDnon_Part2";
			throwGrenade[] = {"GestureThrowGrenadePistol","Gesture"};
			WalkF = "AmovPercMwlkSrasWpstDf";
			WalkLF = "AmovPercMwlkSrasWpstDfl";
			WalkRF = "AmovPercMwlkSrasWpstDfr";
			WalkL = "AmovPercMwlkSrasWpstDl";
			WalkR = "AmovPercMwlkSrasWpstDr";
			WalkLB = "AmovPercMwlkSrasWpstDbl";
			WalkRB = "AmovPercMwlkSrasWpstDbr";
			WalkB = "AmovPercMwlkSrasWpstDb";
			PlayerWalkF = "AmovPercMwlkSrasWpstDf";
			PlayerWalkLF = "AmovPercMwlkSrasWpstDfl";
			PlayerWalkRF = "AmovPercMwlkSrasWpstDfr";
			PlayerWalkL = "AmovPercMwlkSrasWpstDl";
			PlayerWalkR = "AmovPercMwlkSrasWpstDr";
			PlayerWalkLB = "AmovPercMwlkSrasWpstDbl";
			PlayerWalkRB = "AmovPercMwlkSrasWpstDbr";
			PlayerWalkB = "AmovPercMwlkSrasWpstDb";
			SlowF = "AmovPercMrunSlowWpstDf";
			SlowLF = "AmovPercMrunSlowWpstDfl";
			SlowRF = "AmovPercMrunSlowWpstDr";
			SlowL = "AmovPercMrunSlowWpstDl";
			SlowR = "AmovPercMrunSlowWpstDr";
			SlowLB = "AmovPercMrunSlowWpstDbl";
			SlowRB = "AmovPercMrunSlowWpstDbr";
			SlowB = "AmovPercMrunSlowWpstDb";
			PlayerSlowF = "AmovPercMrunSrasWpstDf";
			PlayerSlowLF = "AmovPercMrunSrasWpstDfl";
			PlayerSlowRF = "AmovPercMrunSrasWpstDfr";
			PlayerSlowL = "AmovPercMrunSrasWpstDl";
			PlayerSlowR = "AmovPercMrunSrasWpstDr";
			PlayerSlowLB = "AmovPercMrunSrasWpstDbl";
			PlayerSlowRB = "AmovPercMrunSrasWpstDbr";
			PlayerSlowB = "AmovPercMrunSrasWpstDb";
			FastF = "AmovPercMevaSrasWpstDf";
			FastLF = "AmovPercMevaSrasWpstDfl";
			FastRF = "AmovPercMevaSrasWpstDfr";
			FastL = "AmovPercMevaSrasWpstDl";
			FastR = "AmovPercMevaSrasWpstDr";
			FastLB = "AmovPercMrunSrasWpstDbl";
			FastRB = "AmovPercMrunSrasWpstDbr";
			FastB = "AmovPercMrunSrasWpstDb";
			TactF = "AmovPercMrunSlowWpstDf";
			TactLF = "AmovPercMrunSlowWpstDfl";
			TactRF = "AmovPercMrunSlowWpstDfr";
			TactL = "AmovPercMrunSlowWpstDl";
			TactR = "AmovPercMrunSlowWpstDr";
			TactLB = "AmovPercMrunSlowWpstDbl";
			TactRB = "AmovPercMrunSlowWpstDbr";
			TactB = "AmovPercMrunSlowWpstDb";
			PlayerTactF = "AmovPercMtacSrasWpstDf";
			PlayerTactLF = "AmovPercMtacSrasWpstDfl";
			PlayerTactRF = "AmovPercMtacSrasWpstDfr";
			PlayerTactL = "AmovPercMtacSrasWpstDl";
			PlayerTactR = "AmovPercMtacSrasWpstDr";
			PlayerTactLB = "AmovPercMtacSrasWpstDbl";
			PlayerTactRB = "AmovPercMtacSrasWpstDbr";
			PlayerTactB = "AmovPercMtacSrasWpstDb";
			down = "AmovPpneMstpSrasWpstDnon";
			up = "AmovPknlMstpSrasWpstDnon";
			PlayerStand = "AmovPercMstpSlowWpstDnon";
			PlayerCrouch = "AmovPknlMstpSrasWpstDnon";
			PlayerProne = "AmovPpneMstpSrasWpstDnon";
			weaponOn = "AmovPercMstpSrasWlnrDnon";
			weaponOff = "AmovPercMstpSrasWpstDnon";
			binocOn = "AwopPercMstpSoptWbinDnon_pst";
			binocOff = "AmovPercMstpSrasWpstDnon";
			handGunOn = "AmovPercMstpSrasWrflDnon";
			takeFlag = "AinvPknlMstpSnonWnonDnon_1";
			putDown = "AmovPercMstpSrasWpstDnon_AinvPercMstpSrasWpstDnon_Putdown";
			medic = "AinvPknlMstpSlayWpstDnon_medic";
			medicOther = "AinvPknlMstpSlayWpstDnon_medicOther";
			treated = "AinvPknlMstpSnonWnonDnon_healed_1";
			Combat = "AmovPercMstpSrasWrflDnon";
			Lying = "AmovPpneMstpSrasWpstDnon";
			Stand = "AmovPercMstpSlowWpstDnon";
			Crouch = "AmovPknlMstpSrasWpstDnon";
			CanNotMove = "AmovPercMstpSrasWpstDnon";
			Civil = "AmovPercMstpSnonWnonDnon";
			CivilLying = "AmovPpneMstpSnonWnonDnon";
			FireNotPossible = "AmovPercMstpSrasWpstDnon";
			strokeGun = "AmovPercMstpSrasWpstDnon";
			GetInLow = "AmovPercMstpSnonWnonDnon_AcrgPknlMstpSnonWnonDnon_getInLow";
			GetInMedium = "AmovPercMstpSnonWnonDnon_AcrgPknlMstpSnonWnonDnon_getInMedium";
			GetInHigh = "AmovPercMstpSnonWnonDnon_AcrgPknlMstpSnonWnonDnon_getInHigh";
			GetInVertical = "GetIn_Vertical_Pistol";
			GetInSDV = "AmovPercMstpSnonWnonDnon_AcrgPknlMstpSnonWnonDnon_getInHigh";
			GetOutLow = "AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWpstDnon_getOutLow";
			GetOutMedium = "AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWpstDnon_getOutMedium";
			GetOutHigh = "AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWpstDnon_getOutHigh";
			GetOutHighZamak = "AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWpstDnon_getOutHighZamak";
			GetOutHighHemtt = "AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWpstDnon_getOutHighHemtt";
			GetOutSDV = "AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWpstDnon_getOutHigh";
			GetInHelicopterCargo = "GetInHelicopterCargoPst";
			GetInMRAP_01 = "GetInMRAP_01Pst";
			GetInMRAP_01_cargo = "GetInMRAP_01_cargoPst";
			GetOutMRAP_01 = "GetOutMRAP_01Pst";
			GetOutMRAP_01_cargo = "GetOutMRAP_01_cargoPst";
			GetOutHelicopterCargo = "GetOutHelicopterCargoPst";
			startSwim = "AswmPercMrunSnonWnonDf";
			surfaceSwim = "AsswPercMrunSnonWnonDf";
			bottomSwim = "AbswPercMrunSnonWnonDf";
			startDive = "AdvePercMstpSnonWnonDnon";
			SurfaceDive = "AsdvPercMstpSnonWnonDnon";
			BottomDive = "AbdvPercMstpSnonWnonDnon";
			sitDown = "AmovPsitMstpSnonWpstDnon_ground";
			getOver = "AovrPercMstpSrasWpstDf";
			salute = "AmovPercMstpSrasWpstDnon_salute";
			leanRRot = 0.5;
			leanRShift = 0.01;
			leanLRot = 0.5;
			leanLShift = 0.01;
			turnSpeed = 8;
			limitFast = 5.5;
			upDegree = "ManPosHandGunStand";
			stance = "ManStanceStand";
			EvasiveLeft = "AmovPercMevaSrasWpstDfl";
			EvasiveRight = "AmovPercMevaSrasWpstDfr";
			grabCarry = "Helper_SwitchToCarrynon_pst";
			grabDragged = "AinjPpneMrunSnonWnonDb_grab";
			grabDrag = "AmovPercMstpSrasWpstDnon_AcinPknlMwlkSnonWpstDb_2";
			Diary = "";
			Surrender = "AmovPercMstpSsurWnonDnon";
			saluteOff = "AmovPercMstpSrasWpstDnon";
			Gear = "AinvPercMstpSrasWpstDnon";
			AdjustF = "AadjPercMstpSrasWpstDup";
			AdjustLF = "AadjPercMstpSrasWpstDup";
			AdjustRF = "AadjPercMstpSrasWpstDup";
			AdjustB = "AadjPercMstpSrasWpstDdown";
			AdjustLB = "AadjPercMstpSrasWpstDdown";
			AdjustRB = "AadjPercMstpSrasWpstDdown";
			AdjustL = "AadjPercMstpSrasWpstDleft";
			AdjustR = "AadjPercMstpSrasWpstDright";
			Relax = "AmovPknlMstpSrasWpstDnon_relax";
			StartFreefall = "AfalPercMstpSrasWpstDnon";
			PrimaryWeapon = "AmovPercMstpSrasWrflDnon";
			SecondaryWeapon = "AmovPercMstpSrasWlnrDnon";
			Binoculars = "AmovPercMstpSoptWbinDnon";
			GetInBoat = "GetInHeli_Transport_01Cargo";
			GetOutBoat = "AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWrflDnon_getOutLow";
		};
		class PistolStandActionsNoAdjust: PistolStandActions
		{
			AdjustF = "";
			AdjustLF = "";
			AdjustRF = "";
			AdjustB = "";
			AdjustLB = "";
			AdjustRB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolStandActions_gear: PistolStandActions
		{
			Stop = "AmovPercMstpSrasWpstDnon_gear";
			StopRelaxed = "AmovPercMstpSrasWpstDnon_gear";
			Default = "AmovPercMstpSrasWpstDnon_gear";
			PlayerStand = "AmovPercMstpSrasWpstDnon";
			Civil = "AmovPercMstpSnonWnonDnon_gear";
			HandGunOn = "AinvPercMstpSrasWrflDnon";
		};
		class PistolStandActionsRunF: PistolStandActionsNoAdjust
		{
			turnSpeed = 4.5;
			PlayerCrouch = "AmovPknlMrunSrasWpstDf";
			Up = "AmovPknlMrunSrasWpstDf";
			Crouch = "AmovPknlMrunSrasWpstDf";
			Stand = "AmovPercMrunSlowWpstDf";
		};
		class PistolStandActionsRunFL: PistolStandActionsNoAdjust
		{
			turnSpeed = 4.5;
			PlayerCrouch = "AmovPknlMrunSrasWpstDfl";
			Up = "AmovPknlMrunSrasWpstDfl";
			Crouch = "AmovPknlMrunSrasWpstDfl";
			Stand = "AmovPercMrunSlowWpstDfl";
		};
		class PistolStandActionsRunL: PistolStandActionsNoAdjust
		{
			turnSpeed = 4.5;
			PlayerCrouch = "AmovPknlMrunSrasWpstDl";
			Up = "AmovPknlMrunSrasWpstDl";
			Crouch = "AmovPknlMrunSrasWpstDl";
			AdjustL = "";
			Stand = "AmovPercMrunSlowWpstDl";
		};
		class PistolStandActionsRunBL: PistolStandActionsNoAdjust
		{
			turnSpeed = 4.5;
			PlayerCrouch = "AmovPknlMrunSrasWpstDbl";
			Up = "AmovPknlMrunSrasWpstDbl";
			Crouch = "AmovPknlMrunSrasWpstDbl";
			Stand = "AmovPercMrunSlowWpstDbl";
		};
		class PistolStandActionsRunB: PistolStandActionsNoAdjust
		{
			turnSpeed = 4.5;
			PlayerCrouch = "AmovPknlMrunSrasWpstDb";
			Up = "AmovPknlMrunSrasWpstDb";
			Crouch = "AmovPknlMrunSrasWpstDb";
			AdjustB = "";
			Stand = "AmovPercMrunSlowWpstDb";
		};
		class PistolStandActionsRunBR: PistolStandActionsNoAdjust
		{
			turnSpeed = 4.5;
			PlayerCrouch = "AmovPknlMrunSrasWpstDbr";
			Up = "AmovPknlMrunSrasWpstDbr";
			Crouch = "AmovPknlMrunSrasWpstDbr";
			Stand = "AmovPercMrunSlowWpstDbr";
		};
		class PistolStandActionsRunR: PistolStandActionsNoAdjust
		{
			turnSpeed = 4.5;
			PlayerCrouch = "AmovPknlMrunSrasWpstDr";
			Up = "AmovPknlMrunSrasWpstDr";
			Crouch = "AmovPknlMrunSrasWpstDr";
			AdjustR = "";
			Stand = "AmovPercMrunSlowWpstDr";
		};
		class PistolStandActionsRunFR: PistolStandActionsNoAdjust
		{
			turnSpeed = 4.5;
			PlayerCrouch = "AmovPknlMrunSrasWpstDfr";
			Up = "AmovPknlMrunSrasWpstDfr";
			Crouch = "AmovPknlMrunSrasWpstDfr";
			Stand = "AmovPercMrunSlowWpstDfr";
		};
		class PistolStandActionsTacF: PistolStandActionsNoAdjust
		{
			turnSpeed = 4.5;
			PlayerCrouch = "AmovPknlMtacSrasWpstDf";
			Up = "AmovPknlMtacSrasWpstDf";
			Crouch = "AmovPknlMtacSrasWpstDf";
			AdjustF = "";
			Stand = "AmovPercMtacSlowWpstDf";
		};
		class PistolStandActionsTacFL: PistolStandActionsNoAdjust
		{
			turnSpeed = 4.5;
			PlayerCrouch = "AmovPknlMtacSrasWpstDfl";
			Up = "AmovPknlMtacSrasWpstDfl";
			Crouch = "AmovPknlMtacSrasWpstDfl";
			Stand = "AmovPercMtacSlowWpstDfl";
		};
		class PistolStandActionsTacL: PistolStandActionsNoAdjust
		{
			turnSpeed = 4.5;
			PlayerCrouch = "AmovPknlMtacSrasWpstDl";
			Up = "AmovPknlMtacSrasWpstDl";
			Crouch = "AmovPknlMtacSrasWpstDl";
			AdjustL = "";
			Stand = "AmovPercMtacSlowWpstDl";
		};
		class PistolStandActionsTacBL: PistolStandActionsNoAdjust
		{
			turnSpeed = 4.5;
			PlayerCrouch = "AmovPknlMtacSrasWpstDbl";
			Up = "AmovPknlMtacSrasWpstDbl";
			Crouch = "AmovPknlMtacSrasWpstDbl";
			Stand = "AmovPercMtacSlowWpstDbl";
		};
		class PistolStandActionsTacB: PistolStandActionsNoAdjust
		{
			turnSpeed = 4.5;
			PlayerCrouch = "AmovPknlMtacSrasWpstDb";
			Up = "AmovPknlMtacSrasWpstDb";
			Crouch = "AmovPknlMtacSrasWpstDb";
			AdjustB = "";
			Stand = "AmovPercMtacSlowWpstDb";
		};
		class PistolStandActionsTacBR: PistolStandActionsNoAdjust
		{
			turnSpeed = 4.5;
			PlayerCrouch = "AmovPknlMtacSrasWpstDbr";
			Up = "AmovPknlMtacSrasWpstDbr";
			Crouch = "AmovPknlMtacSrasWpstDbr";
			Stand = "AmovPercMtacSlowWpstDbr";
		};
		class PistolStandActionsTacR: PistolStandActionsNoAdjust
		{
			turnSpeed = 4.5;
			PlayerCrouch = "AmovPknlMtacSrasWpstDr";
			Up = "AmovPknlMtacSrasWpstDr";
			Crouch = "AmovPknlMtacSrasWpstDr";
			AdjustR = "";
			Stand = "AmovPercMtacSlowWpstDr";
		};
		class PistolStandActionsTacFR: PistolStandActionsNoAdjust
		{
			turnSpeed = 4.5;
			PlayerCrouch = "AmovPknlMtacSrasWpstDfr";
			Up = "AmovPknlMtacSrasWpstDfr";
			Crouch = "AmovPknlMtacSrasWpstDfr";
			Stand = "AmovPercMtacSlowWpstDfr";
		};
		class PistolStandActionsWlkF: PistolStandActionsRunF
		{
			turnSpeed = 8;
			PlayerCrouch = "AmovPknlMwlkSrasWpstDf";
			Up = "AmovPknlMwlkSrasWpstDf";
			Crouch = "AmovPknlMwlkSrasWpstDf";
			Stand = "AmovPercMwlkSlowWpstDf";
		};
		class PistolStandActionsWlkFL: PistolStandActionsRunF
		{
			turnSpeed = 8;
			PlayerCrouch = "AmovPknlMwlkSrasWpstDfl";
			Up = "AmovPknlMwlkSrasWpstDfl";
			Crouch = "AmovPknlMwlkSrasWpstDfl";
			Stand = "AmovPercMwlkSlowWpstDfl";
		};
		class PistolStandActionsWlkL: PistolStandActionsRunF
		{
			turnSpeed = 8;
			PlayerCrouch = "AmovPknlMwlkSrasWpstDl";
			Up = "AmovPknlMwlkSrasWpstDl";
			Crouch = "AmovPknlMwlkSrasWpstDl";
			AdjustL = "";
			Stand = "AmovPercMwlkSlowWpstDl";
		};
		class PistolStandActionsWlkBL: PistolStandActionsRunF
		{
			turnSpeed = 8;
			PlayerCrouch = "AmovPknlMwlkSrasWpstDbl";
			Up = "AmovPknlMwlkSrasWpstDbl";
			Crouch = "AmovPknlMwlkSrasWpstDbl";
			Stand = "AmovPercMwlkSlowWpstDbl";
		};
		class PistolStandActionsWlkB: PistolStandActionsRunF
		{
			turnSpeed = 8;
			PlayerCrouch = "AmovPknlMwlkSrasWpstDb";
			Up = "AmovPknlMwlkSrasWpstDb";
			Crouch = "AmovPknlMwlkSrasWpstDb";
			AdjustB = "";
			Stand = "AmovPercMwlkSlowWpstDb";
		};
		class PistolStandActionsWlkBR: PistolStandActionsRunF
		{
			turnSpeed = 8;
			PlayerCrouch = "AmovPknlMwlkSrasWpstDbr";
			Up = "AmovPknlMwlkSrasWpstDbr";
			Crouch = "AmovPknlMwlkSrasWpstDbr";
			Stand = "AmovPercMwlkSlowWpstDbr";
		};
		class PistolStandActionsWlkR: PistolStandActionsRunF
		{
			turnSpeed = 8;
			PlayerCrouch = "AmovPknlMwlkSrasWpstDr";
			Up = "AmovPknlMwlkSrasWpstDr";
			Crouch = "AmovPknlMwlkSrasWpstDr";
			AdjustR = "";
			Stand = "AmovPercMwlkSlowWpstDr";
		};
		class PistolStandActionsWlkFR: PistolStandActionsRunF
		{
			turnSpeed = 8;
			PlayerCrouch = "AmovPknlMwlkSrasWpstDfr";
			Up = "AmovPknlMwlkSrasWpstDfr";
			Crouch = "AmovPknlMwlkSrasWpstDfr";
			Stand = "AmovPercMwlkSlowWpstDfr";
		};
		class PistolLowStandActions: PistolStandActions
		{
			stopRelaxed = "AidlPercMstpSlowWpstDnon_AI";
			Stop = "AmovPercMstpSlowWpstDnon";
			Combat = "AmovPercMstpSrasWpstDnon";
			Stand = "AmovPercMstpSrasWpstDnon";
			PlayerCrouch = "AmovPknlMstpSlowWpstDnon";
			Default = "AmovPercMstpSlowWpstDnon";
			PlayerWalkF = "AmovPercMwlkSlowWpstDf";
			PlayerWalkLF = "AmovPercMwlkSlowWpstDfl";
			PlayerWalkRF = "AmovPercMwlkSlowWpstDfr";
			PlayerWalkL = "AmovPercMwlkSlowWpstDl";
			PlayerWalkR = "AmovPercMwlkSlowWpstDr";
			PlayerWalkLB = "AmovPercMwlkSlowWpstDbl";
			PlayerWalkRB = "AmovPercMwlkSlowWpstDbr";
			PlayerWalkB = "AmovPercMwlkSlowWpstDb";
			TactF = "AmovPercMtacSlowWpstDf";
			TactLF = "AmovPercMtacSlowWpstDfl";
			TactRF = "AmovPercMtacSlowWpstDfr";
			TactL = "AmovPercMtacSlowWpstDl";
			TactR = "AmovPercMtacSlowWpstDr";
			TactLB = "AmovPercMtacSlowWpstDbl";
			TactRB = "AmovPercMtacSlowWpstDbr";
			TactB = "AmovPercMtacSlowWpstDb";
			PlayerTactF = "AmovPercMtacSlowWpstDf";
			PlayerTactLF = "AmovPercMtacSlowWpstDfl";
			PlayerTactRF = "AmovPercMtacSlowWpstDfr";
			PlayerTactL = "AmovPercMtacSlowWpstDl";
			PlayerTactR = "AmovPercMtacSlowWpstDr";
			PlayerTactLB = "AmovPercMtacSlowWpstDbl";
			PlayerTactRB = "AmovPercMtacSlowWpstDbr";
			PlayerTactB = "AmovPercMtacSlowWpstDb";
			SlowRF = "AmovPercMrunSlowWpstDfr";
			PlayerSlowF = "AmovPercMrunSlowWpstDf";
			PlayerSlowLF = "AmovPercMrunSlowWpstDfl";
			PlayerSlowRF = "AmovPercMrunSlowWpstDfr";
			PlayerSlowL = "AmovPercMrunSlowWpstDl";
			PlayerSlowR = "AmovPercMrunSlowWpstDr";
			PlayerSlowLB = "AmovPercMrunSlowWpstDbl";
			PlayerSlowRB = "AmovPercMrunSlowWpstDbr";
			PlayerSlowB = "AmovPercMrunSlowWpstDb";
			FastF = "AmovPercMevaSlowWpstDf";
			FastLF = "AmovPercMevaSlowWpstDfl";
			FastRF = "AmovPercMevaSlowWpstDfr";
			FastL = "AmovPercMrunSlowWpstDl";
			FastR = "AmovPercMrunSlowWpstDr";
			FastLB = "AmovPercMrunSlowWpstDbl";
			FastRB = "AmovPercMrunSlowWpstDbr";
			FastB = "AmovPercMrunSlowWpstDb";
			EvasiveLeft = "AmovPercMevaSlowWpstDfl";
			EvasiveRight = "AmovPercMevaSlowWpstDfr";
			GetOver = "AovrPercMstpSlowWpstDf";
			turnL = "AmovPercMstpSlowWpstDnon_turnL";
			turnR = "AmovPercMstpSlowWpstDnon_turnR";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
			HandGunOn = "AmovPercMstpSrasWpstDnon";
		};
		class PistolLowStandActionsNoAdjust: PistolLowStandActions
		{
			AdjustF = "";
			AdjustLF = "";
			AdjustRF = "";
			AdjustB = "";
			AdjustLB = "";
			AdjustRB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolLowStandActionsRunF: PistolLowStandActionsNoAdjust
		{
			turnSpeed = 4.5;
			PlayerCrouch = "AmovPknlMrunSlowWpstDf";
			Up = "AmovPknlMrunSlowWpstDf";
			Crouch = "AmovPknlMrunSlowWpstDf";
			fireNotPossible = "AmovPercMtacSrasWpstDf";
			Stand = "AmovPercMrunSrasWpstDf";
		};
		class PistolLowStandActionsRunFL: PistolLowStandActionsNoAdjust
		{
			turnSpeed = 4.5;
			PlayerCrouch = "AmovPknlMrunSlowWpstDfl";
			Up = "AmovPknlMrunSlowWpstDfl";
			Crouch = "AmovPknlMrunSlowWpstDfl";
			fireNotPossible = "AmovPercMtacSrasWpstDfl";
			Stand = "AmovPercMrunSrasWpstDfl";
		};
		class PistolLowStandActionsRunL: PistolLowStandActionsNoAdjust
		{
			turnSpeed = 4.5;
			PlayerCrouch = "AmovPknlMrunSlowWpstDl";
			Up = "AmovPknlMrunSlowWpstDl";
			Crouch = "AmovPknlMrunSlowWpstDl";
			fireNotPossible = "AmovPercMtacSrasWpstDl";
			Stand = "AmovPercMrunSrasWpstDl";
		};
		class PistolLowStandActionsRunBL: PistolLowStandActionsNoAdjust
		{
			turnSpeed = 4.5;
			PlayerCrouch = "AmovPknlMrunSlowWpstDbl";
			Up = "AmovPknlMrunSlowWpstDbl";
			Crouch = "AmovPknlMrunSlowWpstDbl";
			fireNotPossible = "AmovPercMtacSrasWpstDbl";
			Stand = "AmovPercMrunSrasWpstDbl";
		};
		class PistolLowStandActionsRunB: PistolLowStandActionsNoAdjust
		{
			turnSpeed = 4.5;
			PlayerCrouch = "AmovPknlMrunSlowWpstDb";
			Up = "AmovPknlMrunSlowWpstDb";
			Crouch = "AmovPknlMrunSlowWpstDb";
			fireNotPossible = "AmovPercMtacSrasWpstDb";
			Stand = "AmovPercMrunSrasWpstDb";
		};
		class PistolLowStandActionsRunBR: PistolLowStandActionsNoAdjust
		{
			turnSpeed = 4.5;
			PlayerCrouch = "AmovPknlMrunSlowWpstDbr";
			Up = "AmovPknlMrunSlowWpstDbr";
			Crouch = "AmovPknlMrunSlowWpstDbr";
			fireNotPossible = "AmovPercMtacSrasWpstDbr";
			Stand = "AmovPercMrunSrasWpstDbr";
		};
		class PistolLowStandActionsRunR: PistolLowStandActionsNoAdjust
		{
			turnSpeed = 4.5;
			PlayerCrouch = "AmovPknlMrunSlowWpstDr";
			Up = "AmovPknlMrunSlowWpstDr";
			Crouch = "AmovPknlMrunSlowWpstDr";
			fireNotPossible = "AmovPercMtacSrasWpstDr";
			Stand = "AmovPercMrunSrasWpstDr";
		};
		class PistolLowStandActionsRunFR: PistolLowStandActionsNoAdjust
		{
			turnSpeed = 4.5;
			PlayerCrouch = "AmovPknlMrunSlowWpstDfr";
			Up = "AmovPknlMrunSlowWpstDfr";
			Crouch = "AmovPknlMrunSlowWpstDfr";
			fireNotPossible = "AmovPercMtacSrasWpstDfr";
			Stand = "AmovPercMrunSrasWpstDfr";
		};
		class PistolLowStandActionsWlkF: PistolLowStandActionsRunF
		{
			turnSpeed = 8;
			PlayerCrouch = "AmovPknlMwlkSlowWpstDf";
			Up = "AmovPknlMwlkSlowWpstDf";
			Crouch = "AmovPknlMwlkSlowWpstDf";
			fireNotPossible = "AmovPercMwlkSrasWpstDf";
			Stand = "AmovPercMwlkSrasWpstDf";
		};
		class PistolLowStandActionsWlkFL: PistolLowStandActionsRunF
		{
			turnSpeed = 8;
			PlayerCrouch = "AmovPknlMwlkSlowWpstDfl";
			Up = "AmovPknlMwlkSlowWpstDfl";
			Crouch = "AmovPknlMwlkSlowWpstDfl";
			fireNotPossible = "AmovPercMwlkSrasWpstDfl";
			Stand = "AmovPercMwlkSrasWpstDfl";
		};
		class PistolLowStandActionsWlkL: PistolLowStandActionsRunF
		{
			turnSpeed = 8;
			PlayerCrouch = "AmovPknlMwlkSlowWpstDl";
			Up = "AmovPknlMwlkSlowWpstDl";
			Crouch = "AmovPknlMwlkSlowWpstDl";
			fireNotPossible = "AmovPercMwlkSrasWpstDl";
			Stand = "AmovPercMwlkSrasWpstDl";
		};
		class PistolLowStandActionsWlkBL: PistolLowStandActionsRunF
		{
			turnSpeed = 8;
			PlayerCrouch = "AmovPknlMwlkSlowWpstDbl";
			Up = "AmovPknlMwlkSlowWpstDbl";
			Crouch = "AmovPknlMwlkSlowWpstDbl";
			fireNotPossible = "AmovPercMwlkSrasWpstDbl";
			Stand = "AmovPercMwlkSrasWpstDbl";
		};
		class PistolLowStandActionsWlkB: PistolLowStandActionsRunF
		{
			turnSpeed = 8;
			PlayerCrouch = "AmovPknlMwlkSlowWpstDb";
			Up = "AmovPknlMwlkSlowWpstDb";
			Crouch = "AmovPknlMwlkSlowWpstDb";
			fireNotPossible = "AmovPercMwlkSrasWpstDb";
			Stand = "AmovPercMwlkSrasWpstDb";
		};
		class PistolLowStandActionsWlkBR: PistolLowStandActionsRunF
		{
			turnSpeed = 8;
			PlayerCrouch = "AmovPknlMwlkSlowWpstDbr";
			Up = "AmovPknlMwlkSlowWpstDbr";
			Crouch = "AmovPknlMwlkSlowWpstDbr";
			fireNotPossible = "AmovPercMwlkSrasWpstDbr";
			Stand = "AmovPercMwlkSrasWpstDbr";
		};
		class PistolLowStandActionsWlkR: PistolLowStandActionsRunF
		{
			turnSpeed = 8;
			PlayerCrouch = "AmovPknlMwlkSlowWpstDr";
			Up = "AmovPknlMwlkSlowWpstDr";
			Crouch = "AmovPknlMwlkSlowWpstDr";
			fireNotPossible = "AmovPercMwlkSrasWpstDr";
			Stand = "AmovPercMwlkSrasWpstDr";
		};
		class PistolLowStandActionsWlkFR: PistolLowStandActionsRunF
		{
			turnSpeed = 8;
			PlayerCrouch = "AmovPknlMwlkSlowWpstDfr";
			Up = "AmovPknlMwlkSlowWpstDfr";
			Crouch = "AmovPknlMwlkSlowWpstDfr";
			fireNotPossible = "AmovPercMwlkSrasWpstDfr";
			Stand = "AmovPercMwlkSrasWpstDfr";
		};
		class PistolLowStandActionsTacF: PistolLowStandActionsRunF
		{
			turnSpeed = 8;
			PlayerCrouch = "AmovPknlMtacSlowWpstDf";
			Up = "AmovPknlMtacSlowWpstDf";
			Crouch = "AmovPknlMtacSlowWpstDf";
			Stand = "AmovPercMtacSrasWpstDf";
		};
		class PistolLowStandActionsTacFL: PistolLowStandActionsRunF
		{
			turnSpeed = 8;
			PlayerCrouch = "AmovPknlMtacSlowWpstDfl";
			Up = "AmovPknlMtacSlowWpstDfl";
			Crouch = "AmovPknlMtacSlowWpstDfl";
			fireNotPossible = "AmovPercMtacSrasWpstDfl";
			Stand = "AmovPercMtacSrasWpstDfl";
		};
		class PistolLowStandActionsTacL: PistolLowStandActionsRunF
		{
			turnSpeed = 8;
			PlayerCrouch = "AmovPknlMtacSlowWpstDl";
			Up = "AmovPknlMtacSlowWpstDl";
			Crouch = "AmovPknlMtacSlowWpstDl";
			fireNotPossible = "AmovPercMtacSrasWpstDl";
			Stand = "AmovPercMtacSrasWpstDl";
		};
		class PistolLowStandActionsTacBL: PistolLowStandActionsRunF
		{
			turnSpeed = 8;
			PlayerCrouch = "AmovPknlMtacSlowWpstDbl";
			Up = "AmovPknlMtacSlowWpstDbl";
			Crouch = "AmovPknlMtacSlowWpstDbl";
			fireNotPossible = "AmovPercMtacSrasWpstDbl";
			Stand = "AmovPercMtacSrasWpstDbl";
		};
		class PistolLowStandActionsTacB: PistolLowStandActionsRunF
		{
			turnSpeed = 8;
			PlayerCrouch = "AmovPknlMtacSlowWpstDb";
			Up = "AmovPknlMtacSlowWpstDb";
			Crouch = "AmovPknlMtacSlowWpstDb";
			fireNotPossible = "AmovPercMtacSrasWpstDb";
			Stand = "AmovPercMtacSrasWpstDb";
		};
		class PistolLowStandActionsTacBR: PistolLowStandActionsRunF
		{
			turnSpeed = 8;
			PlayerCrouch = "AmovPknlMtacSlowWpstDbr";
			Up = "AmovPknlMtacSlowWpstDbr";
			Crouch = "AmovPknlMtacSlowWpstDbr";
			fireNotPossible = "AmovPercMtacSrasWpstDbr";
			Stand = "AmovPercMtacSrasWpstDbr";
		};
		class PistolLowStandActionsTacR: PistolLowStandActionsRunF
		{
			turnSpeed = 8;
			PlayerCrouch = "AmovPknlMtacSlowWpstDr";
			Up = "AmovPknlMtacSlowWpstDr";
			Crouch = "AmovPknlMtacSlowWpstDr";
			fireNotPossible = "AmovPercMtacSrasWpstDr";
			Stand = "AmovPercMtacSrasWpstDr";
		};
		class PistolLowStandActionsTacFR: PistolLowStandActionsRunF
		{
			turnSpeed = 8;
			PlayerCrouch = "AmovPknlMtacSlowWpstDfr";
			Up = "AmovPknlMtacSlowWpstDfr";
			Crouch = "AmovPknlMtacSlowWpstDfr";
			fireNotPossible = "AmovPercMtacSrasWpstDfr";
			Stand = "AmovPercMtacSrasWpstDfr";
		};
		class PistolLowStandEvasiveActionsF: PistolLowStandActionsNoAdjust
		{
			turnSpeed = 4;
			salute = "";
			Stand = "AmovPercMstpSrasWpstDnon";
			Up = "AmovPknlMevaSrasWpstDf";
			PlayerCrouch = "AmovPknlMevaSrasWpstDf";
			AdjustF = "AmovPercMrunSrasWpstDf";
		};
		class PistolLowStandEvasiveActionsFL: PistolLowStandActionsNoAdjust
		{
			turnSpeed = 4;
			salute = "";
			Stand = "AmovPercMstpSrasWpstDnon";
			Up = "AmovPknlMevaSrasWpstDfl";
			PlayerCrouch = "AmovPknlMevaSrasWpstDfl";
			AdjustLF = "AmovPercMrunSrasWpstDfl";
		};
		class PistolLowStandEvasiveActionsFR: PistolLowStandActionsNoAdjust
		{
			turnSpeed = 4;
			salute = "";
			Stand = "AmovPercMstpSrasWpstDnon";
			Up = "AmovPknlMevaSrasWpstDfr";
			PlayerCrouch = "AmovPknlMevaSrasWpstDfr";
			AdjustRF = "AmovPercMrunSrasWpstDfr";
		};
		class PistolStandEvasiveActionsF: PistolStandActions
		{
			turnSpeed = 4;
			salute = "";
			Stand = "AmovPercMstpSrasWpstDnon";
			Up = "AmovPknlMevaSrasWpstDf";
			PlayerCrouch = "AmovPknlMevaSrasWpstDf";
			AdjustF = "AmovPercMrunSrasWpstDf";
		};
		class PistolStandEvasiveActionsFL: PistolStandActions
		{
			turnSpeed = 4;
			salute = "";
			Stand = "AmovPercMstpSrasWpstDnon";
			Up = "AmovPknlMevaSrasWpstDfl";
			PlayerCrouch = "AmovPknlMevaSrasWpstDfl";
			AdjustLF = "AmovPercMrunSrasWpstDfl";
		};
		class PistolStandEvasiveActionsFR: PistolStandActions
		{
			turnSpeed = 4;
			salute = "";
			Stand = "AmovPercMstpSrasWpstDnon";
			Up = "AmovPknlMevaSrasWpstDfr";
			PlayerCrouch = "AmovPknlMevaSrasWpstDfr";
			AdjustRF = "AmovPercMrunSrasWpstDfr";
		};
		class PistolStandEvasiveActionsR: PistolStandActionsRunR
		{
			turnSpeed = 4;
			PlayerProne = "AadjPpneMstpSrasWpstDright";
			Down = "AadjPpneMstpSrasWpstDright";
			Up = "AmovPknlMevaSrasWpstDr";
			PlayerCrouch = "AmovPknlMevaSrasWpstDr";
		};
		class PistolStandEvasiveActionsL: PistolStandActionsRunL
		{
			turnSpeed = 4;
			PlayerProne = "AadjPpneMstpSrasWpstDleft";
			Down = "AadjPpneMstpSrasWpstDleft";
			Up = "AmovPknlMevaSrasWpstDl";
			PlayerCrouch = "AmovPknlMevaSrasWpstDl";
		};
		class PistolRunFActions: PistolStandActions
		{
			throwPrepare = "AmovPercMrunSrasWpstDf";
		};
		class PistolWalkFActions: PistolStandActions
		{
			throwPrepare = "AmovPercMwlkSrasWpstDf";
		};
		class PistolStandSaluteActions: PistolStandActions
		{
			stop = "AmovPercMstpSrasWpstDnon_Salute";
			stopRelaxed = "AmovPercMstpSrasWpstDnon_Salute";
			default = "AmovPercMstpSrasWpstDnon_Salute";
			salute = "AmovPercMstpSrasWpstDnon";
		};
		class PistolStandTakeActions: PistolStandActions
		{
			stop = "AinvPknlMstpSnonWnonDnon_1";
			StopRelaxed = "AinvPknlMstpSnonWnonDnon_1";
			default = "AinvPknlMstpSnonWnonDnon_1";
			salute = "";
			sitDown = "";
		};
		class PistolSitActions: PistolStandActions
		{
			turnL = "";
			turnR = "";
			stop = "AmovPsitMstpSnonWpstDnon_ground";
			StopRelaxed = "AmovPsitMstpSnonWpstDnon_ground";
			default = "AmovPsitMstpSnonWpstDnon_ground";
			sitDown = "AmovPercMstpSrasWpstDnon";
			Diary = "";
			GetOver = "";
			stance = "ManStanceCrouch";
		};
		class PistolKneelActions: PistolStandActions
		{
			stop = "AmovPknlMstpSrasWpstDnon";
			default = "AmovPknlMstpSrasWpstDnon";
			stopRelaxed = "AidlPknlMstpSrasWpstDnon_AI";
			turnL = "AmovPknlMstpSrasWpstDnon_turnL";
			turnR = "AmovPknlMstpSrasWpstDnon_turnR";
			turnLRelaxed = "AmovPknlMstpSrasWpstDnon_turnL";
			turnRRelaxed = "AmovPknlMstpSrasWpstDnon_turnR";
			reloadMagazine[] = {"PistolMagazineReloadKneel_g","Gesture"};
			throwPrepare = "AwopPknlMstpSgthWpstDnon_Part2";
			WalkF = "AmovPknlMwlkSrasWpstDf";
			WalkLF = "AmovPknlMwlkSrasWpstDfl";
			WalkRF = "AmovPknlMwlkSrasWpstDfr";
			WalkL = "AmovPknlMwlkSrasWpstDl";
			WalkR = "AmovPknlMwlkSrasWpstDr";
			WalkLB = "AmovPknlMwlkSrasWpstDbl";
			WalkRB = "AmovPknlMwlkSrasWpstDbr";
			WalkB = "AmovPknlMwlkSrasWpstDb";
			PlayerWalkF = "AmovPknlMwlkSrasWpstDf";
			PlayerWalkLF = "AmovPknlMwlkSrasWpstDfl";
			PlayerWalkRF = "AmovPknlMwlkSrasWpstDfr";
			PlayerWalkL = "AmovPknlMwlkSrasWpstDl";
			PlayerWalkR = "AmovPknlMwlkSrasWpstDr";
			PlayerWalkLB = "AmovPknlMwlkSrasWpstDbl";
			PlayerWalkRB = "AmovPknlMwlkSrasWpstDbr";
			PlayerWalkB = "AmovPknlMwlkSrasWpstDb";
			SlowF = "AmovPknlMrunSlowWpstDf";
			SlowLF = "AmovPknlMrunSlowWpstDfl";
			SlowRF = "AmovPknlMrunSlowWpstDfr";
			SlowL = "AmovPknlMrunSlowWpstDl";
			SlowR = "AmovPknlMrunSlowWpstDr";
			SlowLB = "AmovPknlMrunSlowWpstDbl";
			SlowRB = "AmovPknlMrunSlowWpstDbr";
			SlowB = "AmovPknlMrunSlowWpstDb";
			PlayerSlowF = "AmovPknlMrunSrasWpstDf";
			PlayerSlowLF = "AmovPknlMrunSrasWpstDfl";
			PlayerSlowRF = "AmovPknlMrunSrasWpstDfr";
			PlayerSlowL = "AmovPknlMrunSrasWpstDl";
			PlayerSlowR = "AmovPknlMrunSrasWpstDr";
			PlayerSlowLB = "AmovPknlMrunSrasWpstDbl";
			PlayerSlowRB = "AmovPknlMrunSrasWpstDbr";
			PlayerSlowB = "AmovPknlMrunSrasWpstDb";
			FastF = "AmovPknlMevaSrasWpstDf";
			FastLF = "AmovPknlMevaSrasWpstDfl";
			FastRF = "AmovPknlMevaSrasWpstDfr";
			FastL = "AmovPknlMevaSrasWpstDl";
			FastR = "AmovPknlMevaSrasWpstDr";
			FastLB = "AmovPknlMrunSrasWpstDbl";
			FastRB = "AmovPknlMrunSrasWpstDbr";
			FastB = "AmovPknlMrunSrasWpstDb";
			TactF = "AmovPknlMtacSrasWpstDf";
			TactLF = "AmovPknlMtacSrasWpstDfl";
			TactRF = "AmovPknlMtacSrasWpstDfr";
			TactL = "AmovPknlMtacSrasWpstDl";
			TactR = "AmovPknlMtacSrasWpstDr";
			TactLB = "AmovPknlMtacSrasWpstDbl";
			TactRB = "AmovPknlMtacSrasWpstDbr";
			TactB = "AmovPknlMtacSrasWpstDb";
			PlayerTactF = "AmovPknlMtacSrasWpstDf";
			PlayerTactLF = "AmovPknlMtacSrasWpstDfl";
			PlayerTactRF = "AmovPknlMtacSrasWpstDfr";
			PlayerTactL = "AmovPknlMtacSrasWpstDl";
			PlayerTactR = "AmovPknlMtacSrasWpstDr";
			PlayerTactLB = "AmovPknlMtacSrasWpstDbl";
			PlayerTactRB = "AmovPknlMtacSrasWpstDbr";
			PlayerTactB = "AmovPknlMtacSrasWpstDb";
			up = "AmovPercMstpSrasWpstDnon";
			PlayerStand = "AmovPercMstpSrasWpstDnon";
			weaponOn = "AmovPknlMstpSrasWlnrDnon";
			weaponOff = "AmovPknlMstpSrasWpstDnon";
			binocOn = "AwopPknlMstpSoptWbinDnon_pst";
			binocOff = "AmovPknlMstpSrasWpstDnon";
			handGunOn = "AmovPknlMstpSrasWrflDnon";
			takeFlag = "AinvPknlMstpSnonWnonDnon_2";
			Stand = "AmovPknlMstpSlowWpstDnon";
			Civil = "AmovPknlMstpSnonWnonDnon";
			CanNotMove = "AmovPknlMstpSrasWpstDnon";
			FireNotPossible = "AmovPknlMstpSrasWpstDnon";
			strokeGun = "AmovPknlMstpSrasWpstDnon";
			sitDown = "";
			salute = "";
			turnSpeed = 4.5;
			upDegree = "ManPosHandGunCrouch";
			stance = "ManStanceCrouch";
			Gear = "AinvPknlMstpSrasWpstDnon";
			AdjustF = "AadjPknlMstpSrasWpstDup";
			AdjustLF = "AadjPknlMstpSrasWpstDup";
			AdjustRF = "AadjPknlMstpSrasWpstDup";
			AdjustB = "AadjPknlMstpSrasWpstDdown";
			AdjustLB = "AadjPknlMstpSrasWpstDdown";
			AdjustRB = "AadjPknlMstpSrasWpstDdown";
			AdjustL = "AadjPknlMstpSrasWpstDleft";
			AdjustR = "AadjPknlMstpSrasWpstDright";
			medicStop = "AmovPknlMstpSrasWpstDnon";
			putDown = "AmovPknlMstpSrasWpstDnon_AinvPknlMstpSrasWpstDnon_Putdown";
			StartFreefall = "AfalPknlMstpSrasWpstDnon";
			Combat = "AmovPknlMstpSrasWrflDnon";
			PrimaryWeapon = "AmovPknlMstpSrasWrflDnon";
			SecondaryWeapon = "AmovPknlMstpSrasWlnrDnon";
			Binoculars = "AmovPknlMstpSoptWbinDnon";
		};
		class PistolKneelActionsNoAdjust: PistolKneelActions
		{
			AdjustF = "";
			AdjustLF = "";
			AdjustRF = "";
			AdjustB = "";
			AdjustLB = "";
			AdjustRB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolKneelActions_gear: PistolKneelActions
		{
			Stop = "AmovPknlMstpSrasWpstDnon_gear";
			StopRelaxed = "AmovPknlMstpSrasWpstDnon_gear";
			Default = "AmovPknlMstpSrasWpstDnon_gear";
			HandGunOn = "AinvPknlMstpSrasWrflDnon";
			Civil = "AmovPknlMstpSnonWnonDnon_gear";
		};
		class PistolKneelActions_explo: PistolKneelActions_gear
		{
			Stop = "AmovPknlMstpSrasWpstDnon";
			StopRelaxed = "AmovPknlMstpSrasWpstDnon";
		};
		class PistolKneelActionsRunF: PistolKneelActionsNoAdjust
		{
			PlayerStand = "AmovPercMrunSrasWpstDf";
			Up = "AmovPercMrunSrasWpstDf";
			AdjustF = "";
			Stand = "AmovPknlMrunSlowWpstDf";
		};
		class PistolKneelActionsRunFL: PistolKneelActionsNoAdjust
		{
			PlayerStand = "AmovPercMrunSrasWpstDfl";
			Up = "AmovPercMrunSrasWpstDfl";
			Stand = "AmovPknlMrunSlowWpstDfl";
		};
		class PistolKneelActionsRunL: PistolKneelActionsNoAdjust
		{
			PlayerStand = "AmovPercMrunSrasWpstDl";
			Up = "AmovPercMrunSrasWpstDl";
			AdjustL = "";
			Stand = "AmovPknlMrunSlowWpstDl";
		};
		class PistolKneelActionsRunBL: PistolKneelActionsNoAdjust
		{
			PlayerStand = "AmovPercMrunSrasWpstDbl";
			Up = "AmovPercMrunSrasWpstDbl";
			Stand = "AmovPknlMrunSlowWpstDbl";
		};
		class PistolKneelActionsRunB: PistolKneelActionsNoAdjust
		{
			PlayerStand = "AmovPercMrunSrasWpstDb";
			Up = "AmovPercMrunSrasWpstDb";
			AdjustB = "";
			Stand = "AmovPknlMrunSlowWpstDb";
		};
		class PistolKneelActionsRunBR: PistolKneelActionsNoAdjust
		{
			PlayerStand = "AmovPercMrunSrasWpstDbr";
			Up = "AmovPercMrunSrasWpstDbr";
			Stand = "AmovPknlMrunSlowWpstDbr";
		};
		class PistolKneelActionsRunR: PistolKneelActionsNoAdjust
		{
			PlayerStand = "AmovPercMrunSrasWpstDr";
			Up = "AmovPercMrunSrasWpstDr";
			AdjustR = "";
			Stand = "AmovPknlMrunSlowWpstDr";
		};
		class PistolKneelActionsRunFr: PistolKneelActionsNoAdjust
		{
			PlayerStand = "AmovPercMrunSrasWpstDfr";
			Up = "AmovPercMrunSrasWpstDfr";
			Stand = "AmovPknlMrunSlowWpstDfr";
		};
		class PistolKneelActionsTacF: PistolKneelActionsNoAdjust
		{
			PlayerStand = "AmovPercMTacSrasWpstDf";
			Up = "AmovPercMTacSrasWpstDf";
			AdjustF = "";
			Stand = "AmovPknlMtacSlowWpstDf";
		};
		class PistolKneelActionsTacFL: PistolKneelActionsNoAdjust
		{
			PlayerStand = "AmovPercMTacSrasWpstDfl";
			Up = "AmovPercMTacSrasWpstDfl";
			Stand = "AmovPknlMtacSlowWpstDfl";
		};
		class PistolKneelActionsTacL: PistolKneelActionsNoAdjust
		{
			PlayerStand = "AmovPercMTacSrasWpstDl";
			Up = "AmovPercMTacSrasWpstDl";
			AdjustL = "";
			Stand = "AmovPknlMtacSlowWpstDl";
		};
		class PistolKneelActionsTacBL: PistolKneelActionsNoAdjust
		{
			PlayerStand = "AmovPercMTacSrasWpstDbl";
			Up = "AmovPercMTacSrasWpstDbl";
			Stand = "AmovPknlMtacSlowWpstDbl";
		};
		class PistolKneelActionsTacB: PistolKneelActionsNoAdjust
		{
			PlayerStand = "AmovPercMTacSrasWpstDb";
			Up = "AmovPercMTacSrasWpstDb";
			AdjustB = "";
			Stand = "AmovPknlMtacSlowWpstDb";
		};
		class PistolKneelActionsTacBR: PistolKneelActionsNoAdjust
		{
			PlayerStand = "AmovPercMTacSrasWpstDbr";
			Up = "AmovPercMTacSrasWpstDbr";
			Stand = "AmovPknlMtacSlowWpstDbr";
		};
		class PistolKneelActionsTacR: PistolKneelActionsNoAdjust
		{
			PlayerStand = "AmovPercMTacSrasWpstDr";
			Up = "AmovPercMTacSrasWpstDr";
			AdjustR = "";
			Stand = "AmovPknlMtacSlowWpstDr";
		};
		class PistolKneelActionsTacFr: PistolKneelActionsNoAdjust
		{
			PlayerStand = "AmovPercMTacSrasWpstDfr";
			Up = "AmovPercMTacSrasWpstDfr";
			Stand = "AmovPknlMtacSlowWpstDfr";
		};
		class PistolKneelActionsWlkF: PistolKneelActionsRunF
		{
			PlayerStand = "AmovPercMwlkSrasWpstDf";
			Up = "AmovPercMwlkSrasWpstDf";
			Stand = "AmovPknlMwlkSlowWpstDf";
		};
		class PistolKneelActionsWlkFL: PistolKneelActionsRunF
		{
			PlayerStand = "AmovPercMwlkSrasWpstDfl";
			Up = "AmovPercMwlkSrasWpstDfl";
			Stand = "AmovPknlMwlkSlowWpstDfl";
		};
		class PistolKneelActionsWlkL: PistolKneelActionsRunF
		{
			PlayerStand = "AmovPercMwlkSrasWpstDl";
			Up = "AmovPercMwlkSrasWpstDl";
			AdjustL = "";
			Stand = "AmovPknlMwlkSlowWpstDl";
		};
		class PistolKneelActionsWlkBL: PistolKneelActionsRunF
		{
			PlayerStand = "AmovPercMwlkSrasWpstDbl";
			Up = "AmovPercMwlkSrasWpstDbl";
			Stand = "AmovPknlMwlkSlowWpstDbl";
		};
		class PistolKneelActionsWlkB: PistolKneelActionsRunF
		{
			PlayerStand = "AmovPercMwlkSrasWpstDb";
			Up = "AmovPercMwlkSrasWpstDb";
			AdjustB = "";
			Stand = "AmovPknlMwlkSlowWpstDb";
		};
		class PistolKneelActionsWlkBR: PistolKneelActionsRunF
		{
			PlayerStand = "AmovPercMwlkSrasWpstDbr";
			Up = "AmovPercMwlkSrasWpstDbr";
			Stand = "AmovPknlMwlkSlowWpstDbr";
		};
		class PistolKneelActionsWlkR: PistolKneelActionsRunF
		{
			PlayerStand = "AmovPercMwlkSrasWpstDr";
			Up = "AmovPercMwlkSrasWpstDr";
			AdjustR = "";
			Stand = "AmovPknlMwlkSlowWpstDr";
		};
		class PistolKneelActionsWlkFR: PistolKneelActionsRunF
		{
			PlayerStand = "AmovPercMwlkSrasWpstDfr";
			Up = "AmovPercMwlkSrasWpstDfr";
			Stand = "AmovPknlMwlkSlowWpstDfr";
		};
		class PistolLowKneelActions: PistolKneelActions
		{
			default = "AmovPknlMstpSlowWpstDnon";
			turnL = "AmovPknlMstpSlowWpstDnon_turnL";
			turnR = "AmovPknlMstpSlowWpstDnon_turnR";
			stopRelaxed = "AidlPknlMstpSlowWpstDnon_AI";
			Stop = "AmovPknlMstpSlowWpstDnon";
			Stand = "AmovPknlMstpSrasWpstDnon";
			PlayerWalkF = "AmovPknlMwlkSlowWpstDf";
			PlayerWalkLF = "AmovPknlMwlkSlowWpstDfl";
			PlayerWalkRF = "AmovPknlMwlkSlowWpstDfr";
			PlayerWalkL = "AmovPknlMwlkSlowWpstDl";
			PlayerWalkR = "AmovPknlMwlkSlowWpstDr";
			PlayerWalkLB = "AmovPknlMwlkSlowWpstDbl";
			PlayerWalkRB = "AmovPknlMwlkSlowWpstDbr";
			PlayerWalkB = "AmovPknlMwlkSlowWpstDb";
			TactF = "AmovPknlMtacSlowWpstDf";
			TactLF = "AmovPknlMtacSlowWpstDfl";
			TactRF = "AmovPknlMtacSlowWpstDfr";
			TactL = "AmovPknlMtacSlowWpstDl";
			TactR = "AmovPknlMtacSlowWpstDr";
			TactLB = "AmovPknlMtacSlowWpstDbl";
			TactRB = "AmovPknlMtacSlowWpstDbr";
			TactB = "AmovPknlMtacSlowWpstDb";
			PlayerTactF = "AmovPknlMtacSlowWpstDf";
			PlayerTactLF = "AmovPknlMtacSlowWpstDfl";
			PlayerTactRF = "AmovPknlMtacSlowWpstDfr";
			PlayerTactL = "AmovPknlMtacSlowWpstDl";
			PlayerTactR = "AmovPknlMtacSlowWpstDr";
			PlayerTactLB = "AmovPknlMtacSlowWpstDbl";
			PlayerTactRB = "AmovPknlMtacSlowWpstDbr";
			PlayerTactB = "AmovPknlMtacSlowWpstDb";
			PlayerSlowF = "AmovPknlMrunSlowWpstDf";
			PlayerSlowLF = "AmovPknlMrunSlowWpstDfl";
			PlayerSlowRF = "AmovPknlMrunSlowWpstDfr";
			PlayerSlowL = "AmovPknlMrunSlowWpstDl";
			PlayerSlowR = "AmovPknlMrunSlowWpstDr";
			PlayerSlowLB = "AmovPknlMrunSlowWpstDbl";
			PlayerSlowRB = "AmovPknlMrunSlowWpstDbr";
			PlayerSlowB = "AmovPknlMrunSlowWpstDb";
			FastL = "AmovPknlMrunSlowWpstDl";
			FastR = "AmovPknlMrunSlowWpstDr";
			FastLB = "AmovPknlMrunSlowWpstDbl";
			FastRB = "AmovPknlMrunSlowWpstDbr";
			FastB = "AmovPknlMrunSlowWpstDb";
			Crouch = "AmovPknlMstpSlowWpstDnon";
			PlayerStand = "AmovPercMstpSlowWpstDnon";
			PlayerCrouch = "AmovPknlMstpSlowWpstDnon";
			Combat = "AmovPknlMstpSrasWpstDnon";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
			handGunOn = "AmovPknlMstpSrasWpstDnon";
		};
		class PistolLowKneelActionsNoAdjust: PistolLowKneelActions
		{
			AdjustF = "";
			AdjustLF = "";
			AdjustRF = "";
			AdjustB = "";
			AdjustLB = "";
			AdjustRB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolLowKneelActionsRunF: PistolLowKneelActionsNoAdjust
		{
			PlayerStand = "AmovPercMrunSlowWpstDf";
			Up = "AmovPercMrunSlowWpstDf";
			fireNotPossible = "AmovPknlMtacSrasWpstDf";
			Stand = "AmovPknlMrunSrasWpstDf";
		};
		class PistolLowKneelActionsRunFL: PistolLowKneelActionsNoAdjust
		{
			PlayerStand = "AmovPercMrunSlowWpstDfl";
			Up = "AmovPercMrunSlowWpstDfl";
			fireNotPossible = "AmovPknlMtacSrasWpstDfl";
			Stand = "AmovPknlMrunSrasWpstDfl";
		};
		class PistolLowKneelActionsRunL: PistolLowKneelActionsNoAdjust
		{
			PlayerStand = "AmovPercMrunSlowWpstDl";
			Up = "AmovPercMrunSlowWpstDl";
			fireNotPossible = "AmovPknlMtacSrasWpstDl";
			Stand = "AmovPknlMrunSrasWpstDl";
		};
		class PistolLowKneelActionsRunBL: PistolLowKneelActionsNoAdjust
		{
			PlayerStand = "AmovPercMrunSlowWpstDbl";
			Up = "AmovPercMrunSlowWpstDbl";
			fireNotPossible = "AmovPknlMtacSrasWpstDbl";
			Stand = "AmovPknlMrunSrasWpstDbl";
		};
		class PistolLowKneelActionsRunB: PistolLowKneelActionsNoAdjust
		{
			PlayerStand = "AmovPercMrunSlowWpstDb";
			Up = "AmovPercMrunSlowWpstDb";
			fireNotPossible = "AmovPknlMtacSrasWpstDb";
			Stand = "AmovPknlMrunSrasWpstDb";
		};
		class PistolLowKneelActionsRunBR: PistolLowKneelActionsNoAdjust
		{
			PlayerStand = "AmovPercMrunSlowWpstDbr";
			Up = "AmovPercMrunSlowWpstDbr";
			fireNotPossible = "AmovPknlMtacSrasWpstDbr";
			Stand = "AmovPknlMrunSrasWpstDbr";
		};
		class PistolLowKneelActionsRunR: PistolLowKneelActionsNoAdjust
		{
			PlayerStand = "AmovPercMrunSlowWpstDr";
			Up = "AmovPercMrunSlowWpstDr";
			fireNotPossible = "AmovPknlMtacSrasWpstDr";
			Stand = "AmovPknlMrunSrasWpstDr";
		};
		class PistolLowKneelActionsRunFr: PistolLowKneelActionsNoAdjust
		{
			PlayerStand = "AmovPercMrunSlowWpstDfr";
			Up = "AmovPercMrunSlowWpstDfr";
			fireNotPossible = "AmovPknlMtacSrasWpstDfr";
			Stand = "AmovPknlMrunSrasWpstDfr";
		};
		class PistolLowKneelActionsWlkF: PistolLowKneelActionsRunF
		{
			PlayerStand = "AmovPercMwlkSlowWpstDf";
			Up = "AmovPercMwlkSlowWpstDf";
			fireNotPossible = "AmovPknlMwlkSrasWpstDf";
			Stand = "AmovPknlMwlkSrasWpstDf";
		};
		class PistolLowKneelActionsWlkFL: PistolLowKneelActionsRunF
		{
			PlayerStand = "AmovPercMwlkSlowWpstDfl";
			Up = "AmovPercMwlkSlowWpstDfl";
			fireNotPossible = "AmovPknlMwlkSrasWpstDfl";
			Stand = "AmovPknlMwlkSrasWpstDfl";
		};
		class PistolLowKneelActionsWlkL: PistolLowKneelActionsRunF
		{
			PlayerStand = "AmovPercMwlkSlowWpstDl";
			Up = "AmovPercMwlkSlowWpstDl";
			fireNotPossible = "AmovPknlMwlkSrasWpstDl";
			Stand = "AmovPknlMwlkSrasWpstDl";
		};
		class PistolLowKneelActionsWlkBL: PistolLowKneelActionsRunF
		{
			PlayerStand = "AmovPercMwlkSlowWpstDbl";
			Up = "AmovPercMwlkSlowWpstDbl";
			fireNotPossible = "AmovPknlMwlkSrasWpstDbl";
			Stand = "AmovPknlMwlkSrasWpstDbl";
		};
		class PistolLowKneelActionsWlkB: PistolLowKneelActionsRunF
		{
			PlayerStand = "AmovPercMwlkSlowWpstDb";
			Up = "AmovPercMwlkSlowWpstDb";
			fireNotPossible = "AmovPknlMwlkSrasWpstDb";
			Stand = "AmovPknlMwlkSrasWpstDb";
		};
		class PistolLowKneelActionsWlkBR: PistolLowKneelActionsRunF
		{
			PlayerStand = "AmovPercMwlkSlowWpstDbr";
			Up = "AmovPercMwlkSlowWpstDbr";
			fireNotPossible = "AmovPknlMwlkSrasWpstDbr";
			Stand = "AmovPknlMwlkSrasWpstDbr";
		};
		class PistolLowKneelActionsWlkR: PistolLowKneelActionsRunF
		{
			PlayerStand = "AmovPercMwlkSlowWpstDr";
			Up = "AmovPercMwlkSlowWpstDr";
			fireNotPossible = "AmovPknlMwlkSrasWpstDr";
			Stand = "AmovPknlMwlkSrasWpstDr";
		};
		class PistolLowKneelActionsWlkFR: PistolLowKneelActionsRunF
		{
			PlayerStand = "AmovPercMwlkSlowWpstDfr";
			Up = "AmovPercMwlkSlowWpstDfr";
			fireNotPossible = "AmovPknlMwlkSrasWpstDfr";
			Stand = "AmovPknlMwlkSrasWpstDfr";
		};
		class PistolLowKneelActionsTacF: PistolLowKneelActionsRunF
		{
			PlayerStand = "AmovPercMtacSlowWpstDf";
			Up = "AmovPercMtacSlowWpstDf";
			fireNotPossible = "AmovPknlMtacSrasWpstDf";
			Stand = "AmovPknlMtacSrasWpstDf";
		};
		class PistolLowKneelActionsTacFL: PistolLowKneelActionsRunF
		{
			PlayerStand = "AmovPercMtacSlowWpstDfl";
			Up = "AmovPercMtacSlowWpstDfl";
			fireNotPossible = "AmovPknlMtacSrasWpstDfl";
			Stand = "AmovPknlMtacSrasWpstDfl";
		};
		class PistolLowKneelActionsTacL: PistolLowKneelActionsRunF
		{
			PlayerStand = "AmovPercMtacSlowWpstDl";
			Up = "AmovPercMtacSlowWpstDl";
			fireNotPossible = "AmovPknlMtacSrasWpstDl";
			Stand = "AmovPknlMtacSrasWpstDl";
		};
		class PistolLowKneelActionsTacBL: PistolLowKneelActionsRunF
		{
			PlayerStand = "AmovPercMtacSlowWpstDbl";
			Up = "AmovPercMtacSlowWpstDbl";
			fireNotPossible = "AmovPknlMtacSrasWpstDbl";
			Stand = "AmovPknlMtacSrasWpstDbl";
		};
		class PistolLowKneelActionsTacB: PistolLowKneelActionsRunF
		{
			PlayerStand = "AmovPercMtacSlowWpstDb";
			Up = "AmovPercMtacSlowWpstDb";
			fireNotPossible = "AmovPknlMtacSrasWpstDb";
			Stand = "AmovPknlMtacSrasWpstDb";
		};
		class PistolLowKneelActionsTacBR: PistolLowKneelActionsRunF
		{
			PlayerStand = "AmovPercMtacSlowWpstDbr";
			Up = "AmovPercMtacSlowWpstDbr";
			fireNotPossible = "AmovPknlMtacSrasWpstDbr";
			Stand = "AmovPknlMtacSrasWpstDbr";
		};
		class PistolLowKneelActionsTacR: PistolLowKneelActionsRunF
		{
			PlayerStand = "AmovPercMtacSlowWpstDr";
			Up = "AmovPercMtacSlowWpstDr";
			fireNotPossible = "AmovPknlMtacSrasWpstDr";
			Stand = "AmovPknlMtacSrasWpstDr";
		};
		class PistolLowKneelActionsTacFR: PistolLowKneelActionsRunF
		{
			PlayerStand = "AmovPercMtacSlowWpstDfr";
			Up = "AmovPercMtacSlowWpstDfr";
			fireNotPossible = "AmovPknlMtacSrasWpstDfr";
			Stand = "AmovPknlMtacSrasWpstDfr";
		};
		class PistolKneelTakeActions: PistolKneelActions
		{
			stop = "AinvPknlMstpSnonWnonDnon_2";
			StopRelaxed = "AinvPknlMstpSnonWnonDnon_2";
			default = "AinvPknlMstpSnonWnonDnon_2";
		};
		class PistolKneelEvasiveActionsF: PistolKneelActions
		{
			Up = "AmovPercMevaSrasWpstDf";
			PlayerCrouch = "";
			PlayerStand = "AmovPercMevaSrasWpstDf";
			Crouch = "AmovPknlMevaSrasWpstDf";
			turnSpeed = 4;
			AdjustF = "AmovPknlMrunSrasWpstDf";
		};
		class PistolKneelEvasiveActionsFL: PistolKneelActions
		{
			Up = "AmovPercMevaSrasWpstDfl";
			PlayerCrouch = "";
			PlayerStand = "AmovPercMevaSrasWpstDfl";
			Crouch = "AmovPknlMevaSrasWpstDfl";
			turnSpeed = 4;
			AdjustLF = "AmovPknlMrunSrasWpstDfl";
		};
		class PistolKneelEvasiveActionsFR: PistolKneelActions
		{
			Up = "AmovPercMevaSrasWpstDfr";
			PlayerCrouch = "";
			PlayerStand = "AmovPercMevaSrasWpstDfr";
			Crouch = "AmovPknlMevaSrasWpstDfr";
			turnSpeed = 4;
			AdjustRF = "AmovPknlMrunSrasWpstDfr";
		};
		class PistolKneelEvasiveActionsR: PistolKneelActions
		{
			Up = "AmovPercMevaSrasWpstDr";
			PlayerCrouch = "";
			PlayerStand = "AmovPercMevaSrasWpstDr";
			PlayerProne = "AadjPpneMstpSrasWpstDright";
			down = "AadjPpneMstpSrasWpstDright";
			turnSpeed = 4;
			AdjustR = "AmovPknlMrunSrasWpstDr";
		};
		class PistolKneelEvasiveActionsL: PistolKneelActions
		{
			Up = "AmovPercMevaSrasWpstDl";
			PlayerCrouch = "";
			PlayerStand = "AmovPercMevaSrasWpstDl";
			PlayerProne = "AadjPpneMstpSrasWpstDleft";
			down = "AadjPpneMstpSrasWpstDleft";
			turnSpeed = 4;
			AdjustL = "AmovPknlMrunSrasWpstDl";
		};
		class PistolLowKneelEvasiveActionsF: PistolLowKneelActions
		{
			turnSpeed = 4;
			salute = "";
			Crouch = "AmovPknlMevaSrasWpstDf";
			Up = "AmovPercMevaSlowWpstDf";
			PlayerStand = "AmovPercMevaSlowWpstDf";
			AdjustF = "AmovPknlMrunSrasWpstDf";
		};
		class PistolLowKneelEvasiveActionsFL: PistolLowKneelActions
		{
			turnSpeed = 4;
			salute = "";
			Crouch = "AmovPknlMevaSrasWpstDfl";
			Up = "AmovPercMevaSlowWpstDfl";
			PlayerStand = "AmovPercMevaSlowWpstDfl";
			AdjustLF = "AmovPknlMrunSrasWpstDfl";
		};
		class PistolLowKneelEvasiveActionsFR: PistolLowKneelActions
		{
			turnSpeed = 4;
			salute = "";
			Crouch = "AmovPknlMevaSrasWpstDfr";
			Up = "AmovPercMevaSlowWpstDfr";
			PlayerStand = "AmovPercMevaSlowWpstDfr";
			AdjustRF = "AmovPknlMrunSrasWpstDfr";
		};
		class PistolProneActions: PistolStandActions
		{
			gestureGo[] = {"GestureGoBProne","Gesture"};
			gestureGoB[] = {"GestureGoBProne","Gesture"};
			gestureFreeze[] = {"GestureFreezeProne","Gesture"};
			gesturePoint[] = {"","Gesture"};
			gestureCeaseFire[] = {"","Gesture"};
			gestureCover[] = {"","Gesture"};
			gestureUp[] = {"GestureGoBProne","Gesture"};
			gestureNo[] = {"","Gesture"};
			gestureYes[] = {"","Gesture"};
			gestureFollow[] = {"","Gesture"};
			gestureAdvance[] = {"GestureAdvanceProne","Gesture"};
			GestureReloadMk20 = "RifleReloadProneMk20";
			GestureReloadMk20UGL = "RifleReloadProneMk20UGL";
			GestureReloadMXUGL = "RifleReloadProneMXUGL";
			GestureReloadMX = "RifleReloadProneMX";
			GestureReloadMXCompact = "RifleReloadProneMXCompact";
			GestureReloadMXSniper = "RifleReloadProneMXSniper";
			GestureReloadTRG = "RifleReloadProneTRG";
			GestureReloadTRGUGL = "RifleReloadProneTRGUGL";
			GestureReloadKatiba = "RifleReloadProneKatiba";
			GestureReloadKatibaUGL = "RifleReloadProneKatibaUGL";
			GestureReloadLRR = "RifleReloadProneLRR";
			GestureReloadEBR = "RifleReloadProneEBR";
			GestureReloadSMG_03 = "RifleReloadProneSMG_03";
			GestureReloadSMG_02 = "RifleReloadProneSMG_02";
			GestureReloadSMG_01 = "RifleReloadProneSMG_01";
			GestureReloadSDAR = "RifleReloadProneSDAR";
			GestureReloadDMR = "RifleReloadProneDMR";
			GestureReloadDMR02 = "RifleReloadProneDMR02";
			GestureReloadDMR03 = "RifleReloadProneDMR03";
			GestureReloadDMR04 = "RifleReloadProneDMR04";
			GestureReloadDMR05 = "RifleReloadProneDMR05";
			GestureReloadDMR06 = "RifleReloadProneDMR06";
			GestureReloadMMG01 = "RifleReloadProneMMG01";
			GestureReloadMMG02 = "RifleReloadProneMMG02";
			GestureReloadM4SSAS = "RifleReloadProneM4SSAS";
			GestureReloadPistol = "PistolReloadProne";
			GestureReloadPistolHeavy02 = "PistolHeavy02ReloadProne";
			GestureReloadFlaregun = "PistolReloadProneFlaregun";
			stop = "AmovPpneMstpSrasWpstDnon";
			default = "AmovPpneMstpSrasWpstDnon";
			stopRelaxed = "AidlPpneMstpSrasWpstDnon_AI";
			turnL = "AmovPpneMstpSrasWpstDnon_turnL";
			turnR = "AmovPpneMstpSrasWpstDnon_turnR";
			turnLRelaxed = "AmovPpneMstpSrasWpstDnon_turnL";
			turnRRelaxed = "AmovPpneMstpSrasWpstDnon_turnR";
			reloadMagazine = "PistolMagazineReloadProne";
			reloadGM6 = "reloadGM6";
			reloadMGun = "AmovPpneMstpSrasWpstDnon";
			reloadMortar = "AmovPpneMstpSrasWpstDnon";
			throwPrepare = "AwopPpneMstpSgthWpstDnon_Part2";
			WalkF = "AmovPpneMrunSlowWpstDf";
			WalkLF = "AmovPpneMrunSlowWpstDfl";
			WalkRF = "AmovPpneMrunSlowWpstDfr";
			WalkL = "AmovPpneMrunSlowWpstDl";
			WalkR = "AmovPpneMrunSlowWpstDr";
			WalkLB = "AmovPpneMrunSlowWpstDbl";
			WalkRB = "AmovPpneMrunSlowWpstDbr";
			WalkB = "AmovPpneMrunSlowWpstDb";
			PlayerWalkF = "AmovPpneMrunSlowWpstDf";
			PlayerWalkLF = "AmovPpneMrunSlowWpstDfl";
			PlayerWalkRF = "AmovPpneMrunSlowWpstDfr";
			PlayerWalkL = "AmovPpneMrunSlowWpstDl";
			PlayerWalkR = "AmovPpneMrunSlowWpstDr";
			PlayerWalkLB = "AmovPpneMrunSlowWpstDbl";
			PlayerWalkRB = "AmovPpneMrunSlowWpstDbr";
			PlayerWalkB = "AmovPpneMrunSlowWpstDb";
			SlowF = "AmovPpneMrunSlowWpstDf";
			SlowLF = "AmovPpneMrunSlowWpstDfl";
			SlowRF = "AmovPpneMrunSlowWpstDfr";
			SlowL = "AmovPpneMrunSlowWpstDl";
			SlowR = "AmovPpneMrunSlowWpstDr";
			SlowLB = "AmovPpneMrunSlowWpstDbl";
			SlowRB = "AmovPpneMrunSlowWpstDbr";
			SlowB = "AmovPpneMrunSlowWpstDb";
			PlayerSlowF = "AmovPpneMrunSlowWpstDf";
			PlayerSlowLF = "AmovPpneMrunSlowWpstDfl";
			PlayerSlowRF = "AmovPpneMrunSlowWpstDfr";
			PlayerSlowL = "AmovPpneMrunSlowWpstDl";
			PlayerSlowR = "AmovPpneMrunSlowWpstDr";
			PlayerSlowLB = "AmovPpneMrunSlowWpstDbl";
			PlayerSlowRB = "AmovPpneMrunSlowWpstDbr";
			PlayerSlowB = "AmovPpneMrunSlowWpstDb";
			FastF = "AmovPpneMsprSlowWpstDf";
			FastLF = "AmovPpneMrunSlowWpstDfl";
			FastRF = "AmovPpneMrunSlowWpstDfr";
			FastL = "AmovPpneMrunSlowWpstDl";
			FastR = "AmovPpneMrunSlowWpstDr";
			FastLB = "AmovPpneMrunSlowWpstDbl";
			FastRB = "AmovPpneMrunSlowWpstDbr";
			FastB = "AmovPpneMrunSlowWpstDb";
			TactF = "AmovPpneMrunSlowWpstDf";
			TactLF = "AmovPpneMrunSlowWpstDfl";
			TactRF = "AmovPpneMrunSlowWpstDfr";
			TactL = "AmovPpneMrunSlowWpstDl";
			TactR = "AmovPpneMrunSlowWpstDr";
			TactLB = "AmovPpneMrunSlowWpstDbl";
			TactRB = "AmovPpneMrunSlowWpstDbr";
			TactB = "AmovPpneMrunSlowWpstDb";
			PlayerTactF = "AmovPpneMrunSlowWpstDf";
			PlayerTactLF = "AmovPpneMrunSlowWpstDfl";
			PlayerTactRF = "AmovPpneMrunSlowWpstDfr";
			PlayerTactL = "AmovPpneMrunSlowWpstDl";
			PlayerTactR = "AmovPpneMrunSlowWpstDr";
			PlayerTactLB = "AmovPpneMrunSlowWpstDbl";
			PlayerTactRB = "AmovPpneMrunSlowWpstDbr";
			PlayerTactB = "AmovPpneMrunSlowWpstDb";
			EvasiveLeft = "AmovPpneMstpSrasWpstDnon_AmovPpneMevaSlowWpstDl";
			EvasiveRight = "AmovPpneMstpSrasWpstDnon_AmovPpneMevaSlowWpstDr";
			down = "AmovPercMstpSrasWpstDnon";
			Gear = "AinvPpneMstpSrasWpstDnon";
			PlayerStand = "AmovPercMstpSrasWpstDnon";
			weaponOn = "AmovPknlMstpSrasWlnrDnon";
			weaponOff = "AmovPpneMstpSrasWpstDnon";
			binocOn = "AwopPpneMstpSoptWbinDnon_pst";
			binocOff = "AmovPpneMstpSrasWpstDnon";
			handGunOn = "AmovPpneMstpSrasWrflDnon";
			takeFlag = "AmovPpneMstpSrasWpstDnon";
			putDown = "AmovPpneMstpSrasWpstDnon_AinvPpneMstpSrasWpstDnon_Putdown";
			treated = "AmovPpneMstpSrasWpstDnon_healed";
			CanNotMove = "AmovPpneMstpSrasWpstDnon";
			FireNotPossible = "AmovPpneMstpSrasWpstDnon";
			strokeGun = "AmovPpneMstpSrasWpstDnon";
			sitDown = "";
			salute = "";
			throwGrenade = "AwopPpneMstpSgthWpstDnon_Fast_Start_1";
			turnSpeed = 2.5;
			leanRRot = 0;
			leanRShift = 0;
			leanLRot = 0;
			leanLShift = 0;
			upDegree = "ManPosHandGunLying";
			stance = "ManStanceProne";
			Civil = "AmovPpneMstpSnonWnonDnon";
			medic = "AinvPpneMstpSlayWpstDnon_medic";
			medicOther = "AinvPpneMstpSlayWpstDnon_medicOther";
			GetOver = "";
			Stand = "";
			AdjustL = "AadjPpneMstpSrasWpstDleft";
			AdjustR = "AadjPpneMstpSrasWpstDright";
			AdjustF = "AadjPpneMstpSrasWpstDup";
			AdjustLF = "AadjPpneMstpSrasWpstDup";
			AdjustRF = "AadjPpneMstpSrasWpstDup";
			AdjustB = "AadjPpneMstpSrasWpstDdown";
			AdjustLB = "AadjPpneMstpSrasWpstDdown";
			AdjustRB = "AadjPpneMstpSrasWpstDdown";
			Relax = "AmovPpneMstpSrasWpstDnon_relax";
			Combat = "AmovPpneMstpSrasWrflDnon";
			StartFreefall = "AfalPpneMstpSrasWpstDnon";
			PrimaryWeapon = "AmovPpneMstpSrasWrflDnon";
			SecondaryWeapon = "AmovPknlMstpSrasWlnrDnon";
			Binoculars = "AmovPpneMstpSoptWbinDnon";
		};
		class PistolAdjustProneBaseActions: PistolProneActions
		{
			Lying = "";
			Crouch = "";
		};
		class PistolAdjustFProneActions: PistolAdjustProneBaseActions
		{
			gestureGo = "";
			gestureGoB = "";
			gestureFreeze = "";
			gestureUp = "";
			gestureAdvance[] = {"GestureAdvance","Gesture"};
			GestureReloadPistol[] = {"GestureReloadPistolContext","Gesture"};
			GestureReloadPistolHeavy02[] = {"GestureReloadPistolHeavy02Context","Gesture"};
			GestureReloadFlaregun[] = {"GestureReloadFlaregunContext","Gesture"};
			throwGrenade[] = {"GestureThrowGrenadePistolContext","Gesture"};
			stop = "AadjPpneMstpSrasWpstDup";
			default = "AadjPpneMstpSrasWpstDup";
			stopRelaxed = "AadjPpneMstpSrasWpstDup";
			turnL = "AadjPpneMstpSrasWpstDup_turnL";
			turnR = "AadjPpneMstpSrasWpstDup_turnR";
			turnLRelaxed = "AadjPpneMstpSrasWpstDup_turnL";
			turnRRelaxed = "AadjPpneMstpSrasWpstDup_turnR";
			reloadMGun = "AadjPpneMstpSrasWpstDup";
			reloadMortar = "AadjPpneMstpSrasWpstDup";
			WalkF = "AadjPpneMwlkSrasWpstDup_f";
			WalkLF = "";
			WalkRF = "";
			WalkL = "AadjPpneMwlkSrasWpstDup_l";
			WalkR = "AadjPpneMwlkSrasWpstDup_r";
			WalkLB = "";
			WalkRB = "";
			WalkB = "AadjPpneMwlkSrasWpstDup_b";
			PlayerWalkF = "AadjPpneMwlkSrasWpstDup_f";
			PlayerWalkLF = "";
			PlayerWalkRF = "";
			PlayerWalkL = "AadjPpneMwlkSrasWpstDup_l";
			PlayerWalkR = "AadjPpneMwlkSrasWpstDup_r";
			PlayerWalkLB = "";
			PlayerWalkRB = "";
			PlayerWalkB = "AadjPpneMwlkSrasWpstDup_b";
			SlowF = "AadjPpneMwlkSrasWpstDup_f";
			SlowLF = "";
			SlowRF = "";
			SlowL = "AadjPpneMwlkSrasWpstDup_l";
			SlowR = "AadjPpneMwlkSrasWpstDup_r";
			SlowLB = "";
			SlowRB = "";
			SlowB = "AadjPpneMwlkSrasWpstDup_b";
			PlayerSlowF = "AadjPpneMwlkSrasWpstDup_f";
			PlayerSlowLF = "";
			PlayerSlowRF = "";
			PlayerSlowL = "AadjPpneMwlkSrasWpstDup_l";
			PlayerSlowR = "AadjPpneMwlkSrasWpstDup_r";
			PlayerSlowLB = "";
			PlayerSlowRB = "";
			PlayerSlowB = "AadjPpneMwlkSrasWpstDup_b";
			FastF = "AadjPpneMwlkSrasWpstDup_f";
			FastLF = "";
			FastRF = "";
			FastL = "AadjPpneMwlkSrasWpstDup_l";
			FastR = "AadjPpneMwlkSrasWpstDup_r";
			FastLB = "";
			FastRB = "";
			FastB = "";
			TactF = "AadjPpneMwlkSrasWpstDup_f";
			TactLF = "";
			TactRF = "";
			TactL = "AadjPpneMwlkSrasWpstDup_l";
			TactR = "AadjPpneMwlkSrasWpstDup_r";
			TactLB = "";
			TactRB = "";
			TactB = "AadjPpneMwlkSrasWpstDup_b";
			PlayerTactF = "AadjPpneMwlkSrasWpstDup_f";
			PlayerTactLF = "";
			PlayerTactRF = "";
			PlayerTactL = "AadjPpneMwlkSrasWpstDup_l";
			PlayerTactR = "AadjPpneMwlkSrasWpstDup_r";
			PlayerTactLB = "";
			PlayerTactRB = "";
			PlayerTactB = "AadjPpneMwlkSrasWpstDup_b";
			EvasiveLeft = "";
			EvasiveRight = "";
			weaponOff = "AadjPpneMstpSrasWpstDup";
			Combat = "AadjPpneMstpSrasWpstDup";
			Lying = "AadjPpneMstpSrasWpstDup";
			CanNotMove = "AadjPpneMstpSrasWpstDup";
			FireNotPossible = "AadjPpneMstpSrasWpstDup";
			turnSpeed = 1.5;
			AdjustF = "AadjPknlMstpSrasWpstDdown";
			AdjustB = "AmovPpneMstpSrasWpstDnon";
			Relax = "AadjPpneMstpSrasWpstDup";
		};
		class PistolAdjustBProneActions: PistolAdjustProneBaseActions
		{
			stop = "AadjPpneMstpSrasWpstDdown";
			default = "AadjPpneMstpSrasWpstDdown";
			stopRelaxed = "AadjPpneMstpSrasWpstDdown";
			turnL = "AadjPpneMstpSrasWpstDdown_turnL";
			turnR = "AadjPpneMstpSrasWpstDdown_turnR";
			turnLRelaxed = "AadjPpneMstpSrasWpstDdown_turnL";
			turnRRelaxed = "AadjPpneMstpSrasWpstDdown_turnR";
			reloadMGun = "AadjPpneMstpSrasWpstDdown";
			reloadMortar = "AadjPpneMstpSrasWpstDdown";
			WalkF = "AadjPpneMstpSrasWpstDdown";
			WalkLF = "AadjPpneMstpSrasWpstDdown";
			WalkRF = "AadjPpneMstpSrasWpstDdown";
			WalkL = "AadjPpneMstpSrasWpstDdown";
			WalkR = "AadjPpneMstpSrasWpstDdown";
			WalkLB = "AadjPpneMstpSrasWpstDdown";
			WalkRB = "AadjPpneMstpSrasWpstDdown";
			WalkB = "AadjPpneMstpSrasWpstDdown";
			PlayerWalkF = "AadjPpneMstpSrasWpstDdown";
			PlayerWalkLF = "AadjPpneMstpSrasWpstDdown";
			PlayerWalkRF = "AadjPpneMstpSrasWpstDdown";
			PlayerWalkL = "AadjPpneMstpSrasWpstDdown";
			PlayerWalkR = "AadjPpneMstpSrasWpstDdown";
			PlayerWalkLB = "AadjPpneMstpSrasWpstDdown";
			PlayerWalkRB = "AadjPpneMstpSrasWpstDdown";
			PlayerWalkB = "AadjPpneMstpSrasWpstDdown";
			SlowF = "AadjPpneMstpSrasWpstDdown";
			SlowLF = "AadjPpneMstpSrasWpstDdown";
			SlowRF = "AadjPpneMstpSrasWpstDdown";
			SlowL = "AadjPpneMstpSrasWpstDdown";
			SlowR = "AadjPpneMstpSrasWpstDdown";
			SlowLB = "AadjPpneMstpSrasWpstDdown";
			SlowRB = "AadjPpneMstpSrasWpstDdown";
			SlowB = "AadjPpneMstpSrasWpstDdown";
			PlayerSlowF = "AadjPpneMstpSrasWpstDdown";
			PlayerSlowLF = "AadjPpneMstpSrasWpstDdown";
			PlayerSlowRF = "AadjPpneMstpSrasWpstDdown";
			PlayerSlowL = "AadjPpneMstpSrasWpstDdown";
			PlayerSlowR = "AadjPpneMstpSrasWpstDdown";
			PlayerSlowLB = "AadjPpneMstpSrasWpstDdown";
			PlayerSlowRB = "AadjPpneMstpSrasWpstDdown";
			PlayerSlowB = "AadjPpneMstpSrasWpstDdown";
			FastF = "AadjPpneMstpSrasWpstDdown";
			FastLF = "AadjPpneMstpSrasWpstDdown";
			FastRF = "AadjPpneMstpSrasWpstDdown";
			FastL = "AadjPpneMstpSrasWpstDdown";
			FastR = "AadjPpneMstpSrasWpstDdown";
			FastLB = "AadjPpneMstpSrasWpstDdown";
			FastRB = "AadjPpneMstpSrasWpstDdown";
			FastB = "AadjPpneMstpSrasWpstDdown";
			TactF = "AadjPpneMstpSrasWpstDdown";
			TactLF = "AadjPpneMstpSrasWpstDdown";
			TactRF = "AadjPpneMstpSrasWpstDdown";
			TactL = "AadjPpneMstpSrasWpstDdown";
			TactR = "AadjPpneMstpSrasWpstDdown";
			TactLB = "AadjPpneMstpSrasWpstDdown";
			TactRB = "AadjPpneMstpSrasWpstDdown";
			TactB = "AadjPpneMstpSrasWpstDdown";
			PlayerTactF = "AadjPpneMstpSrasWpstDdown";
			PlayerTactLF = "AadjPpneMstpSrasWpstDdown";
			PlayerTactRF = "AadjPpneMstpSrasWpstDdown";
			PlayerTactL = "AadjPpneMstpSrasWpstDdown";
			PlayerTactR = "AadjPpneMstpSrasWpstDdown";
			PlayerTactLB = "AadjPpneMstpSrasWpstDdown";
			PlayerTactRB = "AadjPpneMstpSrasWpstDdown";
			PlayerTactB = "AadjPpneMstpSrasWpstDdown";
			weaponOff = "AadjPpneMstpSrasWpstDdown";
			Combat = "AadjPpneMstpSrasWpstDdown";
			Lying = "AadjPpneMstpSrasWpstDdown";
			CanNotMove = "AadjPpneMstpSrasWpstDdown";
			FireNotPossible = "AadjPpneMstpSrasWpstDdown";
			strokeGun = "";
			turnSpeed = 1.5;
			AdjustF = "AmovPpneMstpSrasWpstDnon";
			Relax = "AadjPpneMstpSrasWpstDdown";
		};
		class PistolAdjustLProneActions: PistolAdjustProneBaseActions
		{
			gestureGo = "";
			gestureGoB = "";
			gestureFreeze = "";
			gestureUp = "";
			gestureAdvance[] = {"GestureAdvance","Gesture"};
			GestureReloadPistol[] = {"GestureReloadPistolContext","Gesture"};
			GestureReloadPistolHeavy02[] = {"GestureReloadPistolHeavy02Context","Gesture"};
			GestureReloadFlaregun[] = {"GestureReloadFlaregunContext","Gesture"};
			throwGrenade[] = {"GestureThrowGrenadePistolContext","Gesture"};
			stop = "AadjPpneMstpSrasWpstDleft";
			default = "AadjPpneMstpSrasWpstDleft";
			stopRelaxed = "AadjPpneMstpSrasWpstDleft";
			turnL = "AadjPpneMstpSrasWpstDleft";
			turnR = "AadjPpneMstpSrasWpstDleft";
			turnLRelaxed = "AadjPpneMstpSrasWpstDleft";
			turnRRelaxed = "AadjPpneMstpSrasWpstDleft";
			reloadMGun = "AadjPpneMstpSrasWpstDleft";
			reloadMortar = "AadjPpneMstpSrasWpstDleft";
			WalkF = "";
			WalkLF = "";
			WalkRF = "";
			WalkL = "";
			WalkR = "";
			WalkLB = "";
			WalkRB = "";
			WalkB = "";
			PlayerWalkF = "";
			PlayerWalkLF = "";
			PlayerWalkRF = "";
			PlayerWalkL = "AadjPpneMwlkSrasWpstDleft_l";
			PlayerWalkR = "AadjPpneMwlkSrasWpstDleft_r";
			PlayerWalkLB = "";
			PlayerWalkRB = "";
			PlayerWalkB = "";
			SlowF = "";
			SlowLF = "";
			SlowRF = "";
			SlowL = "AadjPpneMwlkSrasWpstDleft_l";
			SlowR = "AadjPpneMwlkSrasWpstDleft_r";
			SlowLB = "";
			SlowRB = "";
			SlowB = "";
			PlayerSlowF = "";
			PlayerSlowLF = "";
			PlayerSlowRF = "";
			PlayerSlowL = "AadjPpneMwlkSrasWpstDleft_l";
			PlayerSlowR = "AadjPpneMwlkSrasWpstDleft_r";
			PlayerSlowLB = "";
			PlayerSlowRB = "";
			PlayerSlowB = "";
			FastF = "";
			FastLF = "";
			FastRF = "";
			FastL = "AadjPpneMwlkSrasWpstDleft_l";
			FastR = "AadjPpneMwlkSrasWpstDleft_r";
			FastLB = "";
			FastRB = "";
			FastB = "";
			TactF = "";
			TactLF = "";
			TactRF = "";
			TactL = "AadjPpneMwlkSrasWpstDleft_l";
			TactR = "AadjPpneMwlkSrasWpstDleft_r";
			TactLB = "";
			TactRB = "";
			TactB = "";
			PlayerTactF = "";
			PlayerTactLF = "";
			PlayerTactRF = "";
			PlayerTactL = "AadjPpneMwlkSrasWpstDleft_l";
			PlayerTactR = "AadjPpneMwlkSrasWpstDleft_r";
			PlayerTactLB = "";
			PlayerTactRB = "";
			PlayerTactB = "";
			EvasiveLeft = "AadjPpneMstpSrasWpstDleft";
			EvasiveRight = "AadjPpneMstpSrasWpstDleft";
			weaponOff = "AadjPpneMstpSrasWpstDleft";
			Combat = "AadjPpneMstpSrasWpstDleft";
			Lying = "AadjPpneMstpSrasWpstDleft";
			CanNotMove = "AadjPpneMstpSrasWpstDleft";
			FireNotPossible = "AadjPpneMstpSrasWpstDleft";
			turnSpeed = 1.5;
			Relax = "AadjPpneMstpSrasWpstDleft";
		};
		class PistolAdjustRProneActions: PistolAdjustProneBaseActions
		{
			gestureGo = "";
			gestureGoB = "";
			gestureFreeze = "";
			gestureUp = "";
			gestureAdvance[] = {"GestureAdvance","Gesture"};
			GestureReloadPistol[] = {"GestureReloadPistolContext","Gesture"};
			GestureReloadPistolHeavy02[] = {"GestureReloadPistolHeavy02Context","Gesture"};
			GestureReloadFlaregun[] = {"GestureReloadFlaregunContext","Gesture"};
			throwGrenade[] = {"GestureThrowGrenadePistolContext","Gesture"};
			stop = "AadjPpneMstpSrasWpstDright";
			default = "AadjPpneMstpSrasWpstDright";
			stopRelaxed = "AadjPpneMstpSrasWpstDright";
			turnL = "AadjPpneMstpSrasWpstDright";
			turnR = "AadjPpneMstpSrasWpstDright";
			turnLRelaxed = "AadjPpneMstpSrasWpstDright";
			turnRRelaxed = "AadjPpneMstpSrasWpstDright";
			reloadMGun = "AadjPpneMstpSrasWpstDright";
			reloadMortar = "AadjPpneMstpSrasWpstDright";
			WalkF = "";
			WalkLF = "";
			WalkRF = "";
			WalkL = "";
			WalkR = "";
			WalkLB = "";
			WalkRB = "";
			WalkB = "";
			PlayerWalkF = "";
			PlayerWalkLF = "";
			PlayerWalkRF = "";
			PlayerWalkL = "AadjPpneMwlkSrasWpstDright_l";
			PlayerWalkR = "AadjPpneMwlkSrasWpstDright_r";
			PlayerWalkLB = "";
			PlayerWalkRB = "";
			PlayerWalkB = "";
			SlowF = "";
			SlowLF = "";
			SlowRF = "";
			SlowL = "AadjPpneMwlkSrasWpstDright_l";
			SlowR = "AadjPpneMwlkSrasWpstDright_r";
			SlowLB = "";
			SlowRB = "";
			SlowB = "";
			PlayerSlowF = "";
			PlayerSlowLF = "";
			PlayerSlowRF = "";
			PlayerSlowL = "AadjPpneMwlkSrasWpstDright_l";
			PlayerSlowR = "AadjPpneMwlkSrasWpstDright_r";
			PlayerSlowLB = "";
			PlayerSlowRB = "";
			PlayerSlowB = "";
			FastF = "";
			FastLF = "";
			FastRF = "";
			FastL = "AadjPpneMwlkSrasWpstDright_l";
			FastR = "AadjPpneMwlkSrasWpstDright_r";
			FastLB = "";
			FastRB = "";
			FastB = "";
			TactF = "";
			TactLF = "";
			TactRF = "";
			TactL = "AadjPpneMwlkSrasWpstDright_l";
			TactR = "AadjPpneMwlkSrasWpstDright_r";
			TactLB = "";
			TactRB = "";
			TactB = "";
			PlayerTactF = "";
			PlayerTactLF = "";
			PlayerTactRF = "";
			PlayerTactL = "AadjPpneMwlkSrasWpstDright_l";
			PlayerTactR = "AadjPpneMwlkSrasWpstDright_r";
			PlayerTactLB = "";
			PlayerTactRB = "";
			PlayerTactB = "";
			EvasiveLeft = "AadjPpneMstpSrasWpstDright";
			EvasiveRight = "AadjPpneMstpSrasWpstDright";
			weaponOff = "AadjPpneMstpSrasWpstDright";
			Combat = "AadjPpneMstpSrasWpstDright";
			Lying = "AadjPpneMstpSrasWpstDright";
			CanNotMove = "AadjPpneMstpSrasWpstDright";
			FireNotPossible = "AadjPpneMstpSrasWpstDright";
			turnSpeed = 1.5;
			Relax = "AadjPpneMstpSrasWpstDright";
		};
		class CivilStandActions: NoActions
		{
			gestureHi[] = {"GestureHi","Gesture"};
			gestureHiB[] = {"GestureHiB","Gesture"};
			gestureHiC[] = {"GestureHiC","Gesture"};
			stop = "AmovPercMstpSnonWnonDnon";
			default = "AmovPercMstpSnonWnonDnon";
			stopRelaxed = "AmovPercMstpSnonWnonDnon";
			turnL = "AmovPercMstpSnonWnonDnon_turnL";
			turnR = "AmovPercMstpSnonWnonDnon_turnR";
			turnLRelaxed = "AmovPercMstpSnonWnonDnon_turnL";
			turnRRelaxed = "AmovPercMstpSnonWnonDnon_turnR";
			reloadMagazine = "AmovPercMstpSnonWnonDnon";
			reloadGM6 = "reloadGM6";
			reloadMGun = "AmovPercMstpSnonWnonDnon";
			reloadMortar = "AmovPercMstpSnonWnonDnon";
			throwPrepare = "AwopPercMstpSgthWnonDnon_start";
			throwGrenade[] = {"GestureThrowGrenadeUna","Gesture"};
			WalkF = "AmovPercMwlkSnonWnonDf";
			WalkLF = "AmovPercMwlkSnonWnonDfl";
			WalkRF = "AmovPercMwlkSnonWnonDfr";
			WalkL = "AmovPercMwlkSnonWnonDl";
			WalkR = "AmovPercMwlkSnonWnonDr";
			WalkLB = "AmovPercMwlkSnonWnonDbl";
			WalkRB = "AmovPercMwlkSnonWnonDbr";
			WalkB = "AmovPercMwlkSnonWnonDb";
			PlayerWalkF = "AmovPercMwlkSnonWnonDf";
			PlayerWalkLF = "AmovPercMwlkSnonWnonDfl";
			PlayerWalkRF = "AmovPercMwlkSnonWnonDfr";
			PlayerWalkL = "AmovPercMwlkSnonWnonDl";
			PlayerWalkR = "AmovPercMwlkSnonWnonDr";
			PlayerWalkLB = "AmovPercMwlkSnonWnonDbl";
			PlayerWalkRB = "AmovPercMwlkSnonWnonDbr";
			PlayerWalkB = "AmovPercMwlkSnonWnonDb";
			SlowF = "AmovPercMrunSnonWnonDf";
			SlowLF = "AmovPercMrunSnonWnonDfl";
			SlowRF = "AmovPercMrunSnonWnonDfr";
			SlowL = "AmovPercMrunSnonWnonDl";
			SlowR = "AmovPercMrunSnonWnonDr";
			SlowLB = "AmovPercMrunSnonWnonDbl";
			SlowRB = "AmovPercMrunSnonWnonDbr";
			SlowB = "AmovPercMrunSnonWnonDb";
			PlayerSlowF = "AmovPercMrunSnonWnonDf";
			PlayerSlowLF = "AmovPercMrunSnonWnonDfl";
			PlayerSlowRF = "AmovPercMrunSnonWnonDfr";
			PlayerSlowL = "AmovPercMrunSnonWnonDl";
			PlayerSlowR = "AmovPercMrunSnonWnonDr";
			PlayerSlowLB = "AmovPercMrunSnonWnonDbl";
			PlayerSlowRB = "AmovPercMrunSnonWnonDbr";
			PlayerSlowB = "AmovPercMrunSnonWnonDb";
			FastF = "AmovPercMevaSnonWnonDf";
			FastLF = "AmovPercMevaSnonWnonDfl";
			FastRF = "AmovPercMevaSnonWnonDfr";
			FastL = "AmovPercMrunSnonWnonDl";
			FastR = "AmovPercMrunSnonWnonDr";
			FastLB = "AmovPercMrunSnonWnonDbl";
			FastRB = "AmovPercMrunSnonWnonDbr";
			FastB = "AmovPercMrunSnonWnonDb";
			TactF = "AmovPercMwlkSnonWnonDf";
			TactLF = "AmovPercMwlkSnonWnonDfl";
			TactRF = "AmovPercMwlkSnonWnonDfr";
			TactL = "AmovPercMwlkSnonWnonDl";
			TactR = "AmovPercMwlkSnonWnonDr";
			TactLB = "AmovPercMwlkSnonWnonDbl";
			TactRB = "AmovPercMwlkSnonWnonDbr";
			TactB = "AmovPercMwlkSnonWnonDb";
			PlayerTactF = "AmovPercMwlkSnonWnonDf";
			PlayerTactLF = "AmovPercMwlkSnonWnonDfl";
			PlayerTactRF = "AmovPercMwlkSnonWnonDfr";
			PlayerTactL = "AmovPercMwlkSnonWnonDl";
			PlayerTactR = "AmovPercMwlkSnonWnonDr";
			PlayerTactLB = "AmovPercMwlkSnonWnonDbl";
			PlayerTactRB = "AmovPercMwlkSnonWnonDbr";
			PlayerTactB = "AmovPercMwlkSnonWnonDb";
			down = "AmovPpneMstpSnonWnonDnon";
			up = "AmovPknlMstpSnonWnonDnon";
			weaponOn = "AmovPercMstpSrasWlnrDnon";
			weaponOff = "AmovPercMstpSnonWnonDnon";
			binocOn = "AwopPercMstpSoptWbinDnon_non";
			binocOff = "AmovPercMstpSnonWnonDnon";
			handGunOn = "AmovPercMstpSrasWpstDnon";
			Gear = "AinvPercMstpSnonWnonDnon";
			takeFlag = "AinvPknlMstpSnonWnonDnon_3";
			putDown = "AmovPercMstpSnonWnonDnon_AinvPercMstpSnonWnonDnon_Putdown";
			medic = "AinvPknlMstpSlayWnonDnon_medic";
			medicOther = "AinvPknlMstpSlayWnonDnon_medicOther";
			treated = "AinvPknlMstpSnonWnonDnon_healed_2";
			PlayerCrouch = "AmovPknlMstpSnonWnonDnon";
			PlayerProne = "AmovPpneMstpSnonWnonDnon";
			Combat = "AmovPercMstpSrasWrflDnon";
			Lying = "AmovPpneMstpSnonWnonDnon";
			Stand = "AmovPercMstpSnonWnonDnon";
			Crouch = "AmovPknlMstpSnonWnonDnon";
			CanNotMove = "AmovPercMstpSnonWnonDnon";
			Civil = "AmovPercMstpSnonWnonDnon";
			CivilLying = "AmovPpneMstpSnonWnonDnon";
			FireNotPossible = "AmovPercMstpSnonWnonDnon";
			strokeGun = "AmovPercMstpSnonWnonDnon";
			GetInLow = "AmovPercMstpSnonWnonDnon_AcrgPknlMstpSnonWnonDnon_getInLow";
			GetInMedium = "AmovPercMstpSnonWnonDnon_AcrgPknlMstpSnonWnonDnon_getInMedium";
			GetInHigh = "AmovPercMstpSnonWnonDnon_AcrgPknlMstpSnonWnonDnon_getInHigh";
			GetInVertical = "GetIn_Vertical_Unarmed";
			GetInSDV = "AmovPercMstpSnonWnonDnon_AcrgPknlMstpSnonWnonDnon_getInHigh";
			GetOutLow = "AcrgPknlMstpSnonWnonDnon_AmovPercMstpSnonWnonDnon_getOutLow";
			GetOutMedium = "AcrgPknlMstpSnonWnonDnon_AmovPercMstpSnonWnonDnon_getOutMedium";
			GetOutHigh = "AcrgPknlMstpSnonWnonDnon_AmovPercMstpSnonWnonDnon_getOutHigh";
			GetOutHighZamak = "AcrgPknlMstpSnonWnonDnon_AmovPercMstpSnonWnonDnon_getOutHighZamak";
			GetOutHighHemtt = "AcrgPknlMstpSnonWnonDnon_AmovPercMstpSnonWnonDnon_getOutHighHemtt";
			GetOutSDV = "AcrgPknlMstpSnonWnonDnon_AmovPercMstpSnonWnonDnon_getOutHigh";
			GetInHelicopterCargo = "GetInHelicopterCargo";
			GetInMRAP_01 = "GetInMRAP_01";
			GetInMRAP_01_cargo = "GetInMRAP_01_cargo";
			GetOutMRAP_01 = "GetOutMRAP_01";
			GetOutMRAP_01_cargo = "GetOutMRAP_01_cargo";
			GetOutHelicopterCargo = "GetOutHelicopterCargo";
			startSwim = "AswmPercMrunSnonWnonDf";
			surfaceSwim = "AsswPercMrunSnonWnonDf";
			bottomSwim = "AbswPercMrunSnonWnonDf";
			startDive = "AdvePercMstpSnonWnonDnon";
			SurfaceDive = "AsdvPercMstpSnonWnonDnon";
			BottomDive = "AbdvPercMstpSnonWnonDnon";
			sitDown = "AmovPsitMstpSnonWnonDnon_ground";
			getOver = "AovrPercMstpSnonWnonDf";
			salute = "AmovPercMstpSnonWnonDnon_salute";
			turnSpeed = 8;
			limitFast = 4;
			leanRRot = 0.57;
			leanRShift = 0.1;
			leanLRot = 0.57;
			leanLShift = 0.07;
			upDegree = "ManPosNoWeapon";
			stance = "ManStanceStand";
			EvasiveLeft = "AmovPercMevaSnonWnonDfl";
			EvasiveRight = "AmovPercMevaSnonWnonDfr";
			grabCarry = "Helper_SwitchToCarryNon";
			grabDragged = "AinjPpneMrunSnonWnonDb_grab";
			grabDrag = "AmovPercMstpSnonWnonDnon_AcinPknlMwlkSnonWnonDb_2";
			Diary = "";
			Surrender = "AmovPercMstpSsurWnonDnon";
			saluteOff = "AmovPercMstpSnonWnonDnon";
			Relax = "AmovPknlMstpSnonWnonDnon_relax";
			medicStartUp = "AinvPknlMstpSnonWnonDnon_medicUp0S";
			StartFreefall = "AfalPercMstpSnonWnonDnon";
			PrimaryWeapon = "AmovPercMstpSrasWrflDnon";
			SecondaryWeapon = "AmovPercMstpSrasWlnrDnon";
			Binoculars = "AmovPercMstpSoptWbinDnon";
			GetInBoat = "GetInHeli_Transport_01Cargo";
			GetOutBoat = "AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWrflDnon_getOutLow";
			AdjustF = "AmovPercMstpSnonWnonDnon";
			AdjustB = "AmovPercMstpSnonWnonDnon";
			AdjustL = "AmovPercMstpSnonWnonDnon";
			AdjustR = "AmovPercMstpSnonWnonDnon";
			AdjustLF = "AmovPercMstpSnonWnonDnon";
			AdjustLB = "AmovPercMstpSnonWnonDnon";
			AdjustRB = "AmovPercMstpSnonWnonDnon";
			AdjustRF = "AmovPercMstpSnonWnonDnon";
		};
		class CivilStandActions_noSalute: CivilStandActions
		{
			Salute = "";
		};
		class CivilExerciseActions: CivilStandActions
		{
			GetOver = "";
		};
		class CivilRunActions: CivilStandActions
		{
			turnSpeed = 4.5;
			throwPrepare = "AmovPercMrunSnonWnonDf";
			salute = "";
		};
		class CivilRunActionsF: CivilRunActions
		{
			Crouch = "AmovPknlMrunSnonWnonDf";
			PlayerCrouch = "AmovPknlMrunSnonWnonDf";
			Up = "AmovPknlMrunSnonWnonDf";
		};
		class CivilRunActionsFL: CivilRunActions
		{
			Crouch = "AmovPknlMrunSnonWnonDfl";
			PlayerCrouch = "AmovPknlMrunSnonWnonDfl";
			Up = "AmovPknlMrunSnonWnonDfl";
		};
		class CivilRunActionsL: CivilRunActions
		{
			Crouch = "AmovPknlMrunSnonWnonDl";
			PlayerCrouch = "AmovPknlMrunSnonWnonDl";
			Up = "AmovPknlMrunSnonWnonDl";
		};
		class CivilRunActionsBL: CivilRunActions
		{
			Crouch = "AmovPknlMrunSnonWnonDbl";
			PlayerCrouch = "AmovPknlMrunSnonWnonDbl";
			Up = "AmovPknlMrunSnonWnonDbl";
		};
		class CivilRunActionsB: CivilRunActions
		{
			Crouch = "AmovPknlMrunSnonWnonDb";
			PlayerCrouch = "AmovPknlMrunSnonWnonDb";
			Up = "AmovPknlMrunSnonWnonDb";
		};
		class CivilRunActionsBR: CivilRunActions
		{
			Crouch = "AmovPknlMrunSnonWnonDbr";
			PlayerCrouch = "AmovPknlMrunSnonWnonDbr";
			Up = "AmovPknlMrunSnonWnonDbr";
		};
		class CivilRunActionsR: CivilRunActions
		{
			Crouch = "AmovPknlMrunSnonWnonDr";
			PlayerCrouch = "AmovPknlMrunSnonWnonDr";
			Up = "AmovPknlMrunSnonWnonDr";
		};
		class CivilRunActionsFR: CivilRunActions
		{
			Crouch = "AmovPknlMrunSnonWnonDfr";
			PlayerCrouch = "AmovPknlMrunSnonWnonDfr";
			Up = "AmovPknlMrunSnonWnonDfr";
		};
		class CivilWlkActionsF: CivilRunActionsF
		{
			turnSpeed = 8;
			PlayerCrouch = "AmovPknlMwlkSnonWnonDf";
			Crouch = "AmovPknlMwlkSnonWnonDf";
			Up = "AmovPknlMwlkSnonWnonDf";
		};
		class CivilWlkActionsFL: CivilWlkActionsF
		{
			PlayerCrouch = "AmovPknlMwlkSnonWnonDfl";
			Crouch = "AmovPknlMwlkSnonWnonDfl";
			Up = "AmovPknlMwlkSnonWnonDfl";
		};
		class CivilWlkActionsL: CivilWlkActionsF
		{
			Crouch = "AmovPknlMwlkSnonWnonDl";
			PlayerCrouch = "AmovPknlMwlkSnonWnonDl";
			Up = "AmovPknlMwlkSnonWnonDl";
		};
		class CivilWlkActionsBL: CivilWlkActionsF
		{
			Crouch = "AmovPknlMwlkSnonWnonDbl";
			PlayerCrouch = "AmovPknlMwlkSnonWnonDbl";
			Up = "AmovPknlMwlkSnonWnonDbl";
		};
		class CivilWlkActionsB: CivilWlkActionsF
		{
			Crouch = "AmovPknlMwlkSnonWnonDb";
			PlayerCrouch = "AmovPknlMwlkSnonWnonDb";
			Up = "AmovPknlMwlkSnonWnonDb";
		};
		class CivilWlkActionsBR: CivilWlkActionsF
		{
			Crouch = "AmovPknlMwlkSnonWnonDbr";
			PlayerCrouch = "AmovPknlMwlkSnonWnonDbr";
			Up = "AmovPknlMwlkSnonWnonDbr";
		};
		class CivilWlkActionsR: CivilWlkActionsF
		{
			Crouch = "AmovPknlMwlkSnonWnonDr";
			PlayerCrouch = "AmovPknlMwlkSnonWnonDr";
			Up = "AmovPknlMwlkSnonWnonDr";
		};
		class CivilWlkActionsFR: CivilWlkActionsF
		{
			Crouch = "AmovPknlMwlkSnonWnonDfr";
			PlayerCrouch = "AmovPknlMwlkSnonWnonDfr";
			Up = "AmovPknlMwlkSnonWnonDfr";
		};
		class CivilEvasiveActions: CivilStandActions
		{
			turnSpeed = 4;
			throwPrepare = "AmovPercMrunSnonWnonDf";
			salute = "";
			limitFast = 5.5;
		};
		class CivilStandSaluteActions: CivilStandActions
		{
			stop = "AmovPercMstpSnonWnonDnon_Salute";
			stopRelaxed = "AmovPercMstpSnonWnonDnon_Salute";
			default = "AmovPercMstpSnonWnonDnon_Salute";
			salute = "AmovPercMstpSnonWnonDnon";
		};
		class CivilStandTakeActions: CivilStandActions
		{
			stop = "AinvPknlMstpSnonWnonDnon_3";
			StopRelaxed = "AinvPknlMstpSnonWnonDnon_3";
			default = "AinvPknlMstpSnonWnonDnon_3";
			salute = "";
			sitDown = "";
		};
		class CivilSitActions: CivilStandActions
		{
			turnL = "";
			turnR = "";
			stop = "AmovPsitMstpSnonWnonDnon_ground";
			StopRelaxed = "AmovPsitMstpSnonWnonDnon_ground";
			default = "AmovPsitMstpSnonWnonDnon_ground";
			sitDown = "AmovPercMstpSnonWnonDnon";
			Diary = "";
			GetOver = "";
		};
		class CivilStandSurrenderActions: CivilStandActions
		{
			turnL = "";
			turnR = "";
			stop = "AmovPercMstpSsurWnonDnon";
			StopRelaxed = "AmovPercMstpSsurWnonDnon";
			default = "AmovPercMstpSsurWnonDnon";
		};
		class CivilKneelActions: CivilStandActions
		{
			stop = "AmovPknlMstpSnonWnonDnon";
			default = "AmovPknlMstpSnonWnonDnon";
			stopRelaxed = "AmovPknlMstpSnonWnonDnon";
			turnL = "AmovPknlMstpSnonWnonDnon_turnL";
			turnR = "AmovPknlMstpSnonWnonDnon_turnR";
			turnLRelaxed = "AmovPknlMstpSnonWnonDnon_turnL";
			turnRRelaxed = "AmovPknlMstpSnonWnonDnon_turnR";
			reloadMagazine = "AmovPknlMstpSnonWnonDnon";
			reloadMGun = "AmovPknlMstpSnonWnonDnon";
			WalkF = "AmovPknlMwlkSnonWnonDf";
			WalkLF = "AmovPknlMwlkSnonWnonDfl";
			WalkRF = "AmovPknlMwlkSnonWnonDfr";
			WalkL = "AmovPknlMwlkSnonWnonDl";
			WalkR = "AmovPknlMwlkSnonWnonDr";
			WalkLB = "AmovPknlMwlkSnonWnonDbl";
			WalkRB = "AmovPknlMwlkSnonWnonDbr";
			WalkB = "AmovPknlMwlkSnonWnonDb";
			PlayerWalkF = "AmovPknlMwlkSnonWnonDf";
			PlayerWalkLF = "AmovPknlMwlkSnonWnonDfl";
			PlayerWalkRF = "AmovPknlMwlkSnonWnonDfr";
			PlayerWalkL = "AmovPknlMwlkSnonWnonDl";
			PlayerWalkR = "AmovPknlMwlkSnonWnonDr";
			PlayerWalkLB = "AmovPknlMwlkSnonWnonDbl";
			PlayerWalkRB = "AmovPknlMwlkSnonWnonDbr";
			PlayerWalkB = "AmovPknlMwlkSnonWnonDb";
			SlowF = "AmovPknlMrunSnonWnonDf";
			SlowLF = "AmovPknlMrunSnonWnonDfl";
			SlowRF = "AmovPknlMrunSnonWnonDfr";
			SlowL = "AmovPknlMrunSnonWnonDl";
			SlowR = "AmovPknlMrunSnonWnonDr";
			SlowLB = "AmovPknlMrunSnonWnonDbl";
			SlowRB = "AmovPknlMrunSnonWnonDbr";
			SlowB = "AmovPknlMrunSnonWnonDb";
			PlayerSlowF = "AmovPknlMrunSnonWnonDf";
			PlayerSlowLF = "AmovPknlMrunSnonWnonDfl";
			PlayerSlowRF = "AmovPknlMrunSnonWnonDfr";
			PlayerSlowL = "AmovPknlMrunSnonWnonDl";
			PlayerSlowR = "AmovPknlMrunSnonWnonDr";
			PlayerSlowLB = "AmovPknlMrunSnonWnonDbl";
			PlayerSlowRB = "AmovPknlMrunSnonWnonDbr";
			PlayerSlowB = "AmovPknlMrunSnonWnonDb";
			FastL = "AmovPknlMrunSnonWnonDl";
			FastR = "AmovPknlMrunSnonWnonDr";
			FastLB = "AmovPknlMrunSnonWnonDbl";
			FastRB = "AmovPknlMrunSnonWnonDbr";
			FastB = "AmovPknlMrunSnonWnonDb";
			FastF = "AmovPknlMevaSnonWnonDf";
			FastLF = "AmovPknlMevaSnonWnonDfl";
			FastRF = "AmovPknlMevaSnonWnonDfr";
			TactF = "AmovPknlMwlkSnonWnonDf";
			TactLF = "AmovPknlMwlkSnonWnonDfl";
			TactRF = "AmovPknlMwlkSnonWnonDfr";
			TactL = "AmovPknlMwlkSnonWnonDl";
			TactR = "AmovPknlMwlkSnonWnonDr";
			TactLB = "AmovPknlMwlkSnonWnonDbl";
			TactRB = "AmovPknlMwlkSnonWnonDbr";
			TactB = "AmovPknlMwlkSnonWnonDb";
			PlayerTactF = "AmovPknlMwlkSnonWnonDf";
			PlayerTactLF = "AmovPknlMwlkSnonWnonDfl";
			PlayerTactRF = "AmovPknlMwlkSnonWnonDfr";
			PlayerTactL = "AmovPknlMwlkSnonWnonDl";
			PlayerTactR = "AmovPknlMwlkSnonWnonDr";
			PlayerTactLB = "AmovPknlMwlkSnonWnonDbl";
			PlayerTactRB = "AmovPknlMwlkSnonWnonDbr";
			PlayerTactB = "AmovPknlMwlkSnonWnonDb";
			up = "AmovPercMstpSnonWnonDnon";
			weaponOn = "AmovPknlMstpSrasWlnrDnon";
			weaponOff = "AmovPknlMstpSnonWnonDnon";
			binocOff = "AmovPknlMstpSnonWnonDnon";
			binocOn = "AwopPknlMstpSoptWbinDnon_non";
			handGunOn = "AmovPknlMstpSrasWpstDnon";
			takeFlag = "AinvPknlMstpSnonWnonDnon_4";
			Gear = "AinvPknlMstpSnonWnonDnon";
			putDown = "AmovPknlMstpSnonWnonDnon_AinvPknlMstpSnonWnonDnon_Putdown";
			Combat = "AmovPknlMstpSrasWrflDnon";
			Stand = "AmovPercMstpSlowWrflDnon";
			CanNotMove = "AmovPknlMstpSnonWnonDnon";
			FireNotPossible = "AmovPknlMstpSnonWnonDnon";
			strokeGun = "AmovPknlMstpSnonWnonDnon";
			sitDown = "";
			salute = "";
			turnSpeed = 4.5;
			limitFast = 5.5;
			PlayerCrouch = "";
			PlayerStand = "AmovPercMstpSnonWnonDnon";
			ReloadRPG = "AmovPknlMstpSnonWnonDnon";
			ReloadMortar = "AmovPknlMstpSnonWnonDnon";
			stance = "ManStanceCrouch";
			medicStop = "AmovPknlMstpSnonWnonDnon";
			StartFreefall = "AfalPknlMstpSnonWnonDnon";
			PrimaryWeapon = "AmovPknlMstpSrasWrflDnon";
			SecondaryWeapon = "AmovPknlMstpSrasWlnrDnon";
			Binoculars = "AmovPknlMstpSoptWbinDnon";
		};
		class CivilKneelActions_gear: CivilKneelActions
		{
			Stop = "AmovPknlMstpSnonWnonDnon_gear";
			StopRelaxed = "AmovPknlMstpSnonWnonDnon_gear";
			Default = "AmovPknlMstpSnonWnonDnon_gear";
			PlayerCrouch = "AmovPknlMstpSnonWnonDnon";
			Civil = "AmovPknlMstpSnonWnonDnon_gear";
		};
		class CivilKneelActions_explo: CivilKneelActions_gear
		{
			Stop = "AmovPknlMstpSnonWnonDnon";
			StopRelaxed = "AmovPknlMstpSnonWnonDnon";
		};
		class CivilKneelActionsRunF: CivilKneelActions
		{
			PlayerStand = "AmovPercMrunSnonWnonDf";
			Stand = "AmovPercMrunSnonWnonDf";
			Up = "AmovPercMrunSnonWnonDf";
		};
		class CivilKneelActionsRunFl: CivilKneelActions
		{
			PlayerStand = "AmovPercMrunSnonWnonDfl";
			Stand = "AmovPercMrunSnonWnonDfl";
			Up = "AmovPercMrunSnonWnonDfl";
		};
		class CivilKneelActionsRunL: CivilKneelActions
		{
			PlayerStand = "AmovPercMrunSnonWnonDl";
			Stand = "AmovPercMrunSnonWnonDl";
			Up = "AmovPercMrunSnonWnonDl";
		};
		class CivilKneelActionsRunBL: CivilKneelActions
		{
			PlayerStand = "AmovPercMrunSnonWnonDbl";
			Stand = "AmovPercMrunSnonWnonDbl";
			Up = "AmovPercMrunSnonWnonDbl";
		};
		class CivilKneelActionsRunB: CivilKneelActions
		{
			PlayerStand = "AmovPercMrunSnonWnonDb";
			Stand = "AmovPercMrunSnonWnonDb";
			Up = "AmovPercMrunSnonWnonDb";
		};
		class CivilKneelActionsRunBR: CivilKneelActions
		{
			PlayerStand = "AmovPercMrunSnonWnonDbr";
			Stand = "AmovPercMrunSnonWnonDbr";
			Up = "AmovPercMrunSnonWnonDbr";
		};
		class CivilKneelActionsRunR: CivilKneelActions
		{
			PlayerStand = "AmovPercMrunSnonWnonDr";
			Stand = "AmovPercMrunSnonWnonDr";
			Up = "AmovPercMrunSnonWnonDr";
		};
		class CivilKneelActionsRunFR: CivilKneelActions
		{
			PlayerStand = "AmovPercMrunSnonWnonDfr";
			Stand = "AmovPercMrunSnonWnonDfr";
			Up = "AmovPercMrunSnonWnonDfr";
		};
		class CivilKneelActionsWlkF: CivilKneelActionsRunF
		{
			PlayerStand = "AmovPercMwlkSnonWnonDf";
			Stand = "AmovPercMwlkSnonWnonDf";
			Up = "AmovPercMwlkSnonWnonDf";
		};
		class CivilKneelActionsWlkFL: CivilKneelActionsRunF
		{
			PlayerStand = "AmovPercMwlkSnonWnonDfl";
			Stand = "AmovPercMwlkSnonWnonDfl";
			Up = "AmovPercMwlkSnonWnonDfl";
		};
		class CivilKneelActionsWlkL: CivilKneelActionsRunF
		{
			PlayerStand = "AmovPercMwlkSnonWnonDl";
			Stand = "AmovPercMwlkSnonWnonDl";
			Up = "AmovPercMwlkSnonWnonDl";
		};
		class CivilKneelActionsWlkBL: CivilKneelActionsRunF
		{
			PlayerStand = "AmovPercMwlkSnonWnonDbl";
			Stand = "AmovPercMwlkSnonWnonDbl";
			Up = "AmovPercMwlkSnonWnonDbl";
		};
		class CivilKneelActionsWlkB: CivilKneelActionsRunF
		{
			PlayerStand = "AmovPercMwlkSnonWnonDb";
			Stand = "AmovPercMwlkSnonWnonDb";
			Up = "AmovPercMwlkSnonWnonDb";
		};
		class CivilKneelActionsWlkBR: CivilKneelActionsRunF
		{
			PlayerStand = "AmovPercMwlkSnonWnonDbr";
			Stand = "AmovPercMwlkSnonWnonDbr";
			Up = "AmovPercMwlkSnonWnonDbr";
		};
		class CivilKneelActionsWlkR: CivilKneelActionsRunF
		{
			PlayerStand = "AmovPercMwlkSnonWnonDr";
			Stand = "AmovPercMwlkSnonWnonDr";
			Up = "AmovPercMwlkSnonWnonDr";
		};
		class CivilKneelActionsWlkFR: CivilKneelActionsRunF
		{
			PlayerStand = "AmovPercMwlkSnonWnonDfr";
			Stand = "AmovPercMwlkSnonWnonDfr";
			Up = "AmovPercMwlkSnonWnonDfr";
		};
		class CivilKneelActions_fixing: CivilKneelActions
		{
			Stop = "ActsPercSnonWnonDnon_carFixing2";
			StopRelaxed = "ActsPercSnonWnonDnon_carFixing2";
			Default = "ActsPercSnonWnonDnon_carFixing2";
		};
		class CivilKneelTakeActions: CivilKneelActions
		{
			stop = "AinvPknlMstpSnonWnonDnon_4";
			StopRelaxed = "AinvPknlMstpSnonWnonDnon_4";
			default = "AinvPknlMstpSnonWnonDnon_4";
		};
		class CivilEvasiveKneelActions: CivilKneelActions
		{
			limitFast = 5.5;
		};
		class CivilProneActions: CivilStandActions
		{
			stop = "AmovPpneMstpSnonWnonDnon";
			default = "AmovPpneMstpSnonWnonDnon";
			stopRelaxed = "AmovPpneMstpSnonWnonDnon";
			turnL = "AmovPpneMstpSnonWnonDnon_turnL";
			turnR = "AmovPpneMstpSnonWnonDnon_turnR";
			turnLRelaxed = "AmovPpneMstpSnonWnonDnon_turnL";
			turnRRelaxed = "AmovPpneMstpSnonWnonDnon_turnR";
			reloadMagazine = "AmovPpneMstpSnonWnonDnon";
			reloadMGun = "AmovPpneMstpSnonWnonDnon";
			reloadMortar = "AmovPpneMstpSnonWnonDnon";
			throwPrepare = "AwopPpneMstpSgthWnonDnon_start";
			WalkF = "AmovPpneMrunSnonWnonDf";
			WalkLF = "AmovPpneMrunSnonWnonDfl";
			WalkRF = "AmovPpneMrunSnonWnonDfr";
			WalkL = "AmovPpneMrunSnonWnonDl";
			WalkR = "AmovPpneMrunSnonWnonDr";
			WalkLB = "AmovPpneMrunSnonWnonDbl";
			WalkRB = "AmovPpneMrunSnonWnonDbr";
			WalkB = "AmovPpneMrunSnonWnonDb";
			PlayerWalkF = "AmovPpneMrunSnonWnonDf";
			PlayerWalkLF = "AmovPpneMrunSnonWnonDfl";
			PlayerWalkRF = "AmovPpneMrunSnonWnonDfr";
			PlayerWalkL = "AmovPpneMrunSnonWnonDl";
			PlayerWalkR = "AmovPpneMrunSnonWnonDr";
			PlayerWalkLB = "AmovPpneMrunSnonWnonDbl";
			PlayerWalkRB = "AmovPpneMrunSnonWnonDbr";
			PlayerWalkB = "AmovPpneMrunSnonWnonDb";
			SlowF = "AmovPpneMrunSnonWnonDf";
			SlowLF = "AmovPpneMrunSnonWnonDfl";
			SlowRF = "AmovPpneMrunSnonWnonDfr";
			SlowL = "AmovPpneMrunSnonWnonDl";
			SlowR = "AmovPpneMrunSnonWnonDr";
			SlowLB = "AmovPpneMrunSnonWnonDbl";
			SlowRB = "AmovPpneMrunSnonWnonDbr";
			SlowB = "AmovPpneMrunSnonWnonDb";
			PlayerSlowF = "AmovPpneMrunSnonWnonDf";
			PlayerSlowLF = "AmovPpneMrunSnonWnonDfl";
			PlayerSlowRF = "AmovPpneMrunSnonWnonDfr";
			PlayerSlowL = "AmovPpneMrunSnonWnonDl";
			PlayerSlowR = "AmovPpneMrunSnonWnonDr";
			PlayerSlowLB = "AmovPpneMrunSnonWnonDbl";
			PlayerSlowRB = "AmovPpneMrunSnonWnonDbr";
			PlayerSlowB = "AmovPpneMrunSnonWnonDb";
			FastF = "AmovPpneMsprSnonWnonDf";
			FastLF = "AmovPpneMrunSnonWnonDfl";
			FastRF = "AmovPpneMrunSnonWnonDfr";
			FastL = "AmovPpneMrunSnonWnonDl";
			FastR = "AmovPpneMrunSnonWnonDr";
			FastLB = "AmovPpneMrunSnonWnonDbl";
			FastRB = "AmovPpneMrunSnonWnonDbr";
			FastB = "AmovPpneMrunSnonWnonDb";
			TactF = "AmovPpneMrunSnonWnonDf";
			TactLF = "AmovPpneMrunSnonWnonDfl";
			TactRF = "AmovPpneMrunSnonWnonDfr";
			TactL = "AmovPpneMrunSnonWnonDl";
			TactR = "AmovPpneMrunSnonWnonDr";
			TactLB = "AmovPpneMrunSnonWnonDbl";
			TactRB = "AmovPpneMrunSnonWnonDbr";
			TactB = "AmovPpneMrunSnonWnonDb";
			PlayerTactF = "AmovPpneMrunSnonWnonDf";
			PlayerTactLF = "AmovPpneMrunSnonWnonDfl";
			PlayerTactRF = "AmovPpneMrunSnonWnonDfr";
			PlayerTactL = "AmovPpneMrunSnonWnonDl";
			PlayerTactR = "AmovPpneMrunSnonWnonDr";
			PlayerTactLB = "AmovPpneMrunSnonWnonDbl";
			PlayerTactRB = "AmovPpneMrunSnonWnonDbr";
			PlayerTactB = "AmovPpneMrunSnonWnonDb";
			EvasiveLeft = "AmovPpneMstpSnonWnonDnon_AmovPpneMevaSnonWnonDl";
			EvasiveRight = "AmovPpneMstpSnonWnonDnon_AmovPpneMevaSnonWnonDr";
			down = "AmovPercMstpSnonWnonDnon";
			weaponOn = "AmovPknlMstpSrasWlnrDnon";
			weaponOff = "AmovPpneMstpSnonWnonDnon";
			binocOn = "AwopPpneMstpSoptWbinDnon_non";
			binocOff = "AmovPpneMstpSnonWnonDnon";
			handGunOn = "AmovPpneMstpSrasWpstDnon";
			takeFlag = "AmovPpneMstpSnonWnonDnon";
			Gear = "AinvPpneMstpSnonWnonDnon";
			putDown = "AmovPpneMstpSnonWnonDnon_AinvPpneMstpSnonWnonDnon_Putdown";
			treated = "AmovPpneMstpSnonWnonDnon_healed";
			Lying = "AmovPpneMstpSrasWrflDnon";
			Crouch = "AmovPpneMstpSnonWnonDnon";
			CanNotMove = "AmovPpneMstpSnonWnonDnon";
			FireNotPossible = "AmovPpneMstpSnonWnonDnon";
			strokeGun = "AmovPpneMstpSnonWnonDnon";
			sitDown = "";
			salute = "";
			turnSpeed = 2.5;
			limitFast = 5.5;
			leanRRot = 0;
			leanRShift = 0;
			leanLRot = 0;
			leanLShift = 0;
			upDegree = "ManPosLyingNoWeapon";
			stance = "ManStanceProne";
			Diary = "";
			GetOver = "";
			throwGrenade = "AwopPpneMstpSgthWnonDnon_Fast_Start";
			PlayerStand = "AmovPercMstpSnonWnonDnon";
			Relax = "AmovPpneMstpSnonWnonDnon_relax";
			medic = "AinvPpneMstpSlayWnonDnon_medic";
			medicOther = "AinvPpneMstpSlayWnonDnon_medicOther";
			StartFreefall = "AfalPpneMstpSnonWnonDnon";
			PrimaryWeapon = "AmovPpneMstpSrasWrflDnon";
			SecondaryWeapon = "AmovPpneMstpSrasWlnrDnon";
			Binoculars = "AmovPpneMstpSoptWbinDnon";
		};
		class LauncherKneelActions: NoActions
		{
			leanRRot = 0.5;
			leanRShift = 0.01;
			leanLRot = 0.5;
			leanLShift = 0.01;
			stop = "AmovPknlMstpSrasWlnrDnon";
			default = "AmovPknlMstpSrasWlnrDnon";
			weaponOn = "AmovPknlMstpSrasWlnrDnon";
			weaponOff = "AmovPknlMstpSrasWrflDnon";
			binocOn = "AwopPknlMstpSoptWbinDnon_lnr";
			binocOff = "AmovPknlMstpSrasWlnrDnon";
			handGunOn = "AmovPknlMstpSrasWpstDnon";
			reloadMagazine[] = {"LauncherMagazineReloadStand","gesture"};
			throwGrenade[] = {"GestureThrowGrenadeLauncher","Gesture"};
			Up = "AmovPercMstpSrasWlnrDnon";
			PlayerStand = "AmovPercMstpSrasWlnrDnon";
			Combat = "AmovPercMstpSrasWlnrDnon";
			Lying = "AmovPknlMstpSrasWrflDnon";
			Stand = "AmovPercMstpSrasWlnrDnon";
			Crouch = "AmovPknlMstpSrasWlnrDnon";
			ReloadRPG = "ReloadRPGKneel";
			Civil = "AmovPknlMstpSnonWnonDnon";
			CivilLying = "AmovPpneMstpSnonWnonDnon";
			WalkF = "AmovPknlMwlkSrasWlnrDf";
			WalkLF = "AmovPknlMwlkSrasWlnrDfl";
			WalkRF = "AmovPknlMwlkSrasWlnrDfr";
			WalkL = "AmovPknlMwlkSrasWlnrDl";
			WalkR = "AmovPknlMwlkSrasWlnrDr";
			WalkLB = "AmovPknlMwlkSrasWlnrDbl";
			WalkRB = "AmovPknlMwlkSrasWlnrDbr";
			WalkB = "AmovPknlMwlkSrasWlnrDb";
			PlayerWalkF = "AmovPknlMwlkSrasWlnrDf";
			PlayerWalkLF = "AmovPknlMwlkSrasWlnrDfl";
			PlayerWalkRF = "AmovPknlMwlkSrasWlnrDfr";
			PlayerWalkL = "AmovPknlMwlkSrasWlnrDl";
			PlayerWalkR = "AmovPknlMwlkSrasWlnrDr";
			PlayerWalkLB = "AmovPknlMwlkSrasWlnrDbl";
			PlayerWalkRB = "AmovPknlMwlkSrasWlnrDbr";
			PlayerWalkB = "AmovPknlMwlkSrasWlnrDb";
			SlowF = "AmovPknlMrunSrasWlnrDf";
			SlowLF = "AmovPknlMrunSrasWlnrDfl";
			SlowRF = "AmovPknlMrunSrasWlnrDfr";
			SlowL = "AmovPknlMrunSrasWlnrDl";
			SlowR = "AmovPknlMrunSrasWlnrDr";
			SlowLB = "AmovPknlMrunSrasWlnrDbl";
			SlowRB = "AmovPknlMrunSrasWlnrDbr";
			SlowB = "AmovPknlMrunSrasWlnrDb";
			PlayerSlowF = "AmovPknlMrunSrasWlnrDf";
			PlayerSlowLF = "AmovPknlMrunSrasWlnrDfl";
			PlayerSlowRF = "AmovPknlMrunSrasWlnrDfr";
			PlayerSlowL = "AmovPknlMrunSrasWlnrDl";
			PlayerSlowR = "AmovPknlMrunSrasWlnrDr";
			PlayerSlowLB = "AmovPknlMrunSrasWlnrDbl";
			PlayerSlowRB = "AmovPknlMrunSrasWlnrDbr";
			PlayerSlowB = "AmovPknlMrunSrasWlnrDb";
			FastF = "AmovPknlMevaSlowWlnrDf";
			FastLF = "AmovPknlMevaSlowWlnrDfl";
			FastRF = "AmovPknlMevaSlowWlnrDfr";
			FastL = "AmovPknlMrunSrasWlnrDl";
			FastR = "AmovPknlMrunSrasWlnrDr";
			FastLB = "AmovPknlMrunSrasWlnrDbl";
			FastRB = "AmovPknlMrunSrasWlnrDbr";
			FastB = "AmovPknlMrunSrasWlnrDb";
			TactF = "AmovPknlMtacSrasWlnrDf";
			TactLF = "AmovPknlMtacSrasWlnrDfl";
			TactRF = "AmovPknlMtacSrasWlnrDfr";
			TactL = "AmovPknlMtacSrasWlnrDl";
			TactR = "AmovPknlMtacSrasWlnrDr";
			TactLB = "AmovPknlMtacSrasWlnrDbl";
			TactRB = "AmovPknlMtacSrasWlnrDbr";
			TactB = "AmovPknlMtacSrasWlnrDb";
			PlayerTactF = "AmovPknlMtacSrasWlnrDf";
			PlayerTactLF = "AmovPknlMtacSrasWlnrDfl";
			PlayerTactRF = "AmovPknlMtacSrasWlnrDfr";
			PlayerTactL = "AmovPknlMtacSrasWlnrDl";
			PlayerTactR = "AmovPknlMtacSrasWlnrDr";
			PlayerTactLB = "AmovPknlMtacSrasWlnrDbl";
			PlayerTactRB = "AmovPknlMtacSrasWlnrDbr";
			PlayerTactB = "AmovPknlMtacSrasWlnrDb";
			turnL = "AmovPknlMstpSrasWlnrDnon_turnL";
			turnR = "AmovPknlMstpSrasWlnrDnon_turnR";
			turnLRelaxed = "AmovPknlMstpSrasWlnrDnon_turnL";
			turnRRelaxed = "AmovPknlMstpSrasWlnrDnon_turnR";
			getInCar = "AmovPknlMstpSrasWrflDnon";
			getOutCar = "AmovPknlMstpSrasWrflDnon";
			getInTank = "AmovPknlMstpSrasWrflDnon";
			getOutTank = "AmovPknlMstpSrasWrflDnon";
			upDegree = "ManPosWeapon";
			stance = "ManStanceCrouch";
			treated = "AinvPknlMstpSnonWnonDnon_healed_2";
			turnSpeed = 4.5;
			startSwim = "AswmPercMrunSnonWnonDf";
			surfaceSwim = "AsswPercMrunSnonWnonDf";
			bottomSwim = "AbswPercMrunSnonWnonDf";
			startDive = "AdvePercMstpSnonWnonDnon";
			SurfaceDive = "AsdvPercMstpSnonWnonDnon";
			BottomDive = "AbdvPercMstpSnonWnonDnon";
			EvasiveLeft = "AmovPercMevaSlowWlnrDfl";
			EvasiveRight = "AmovPercMevaSlowWlnrDfr";
			Diary = "";
			Surrender = "AmovPercMstpSsurWnonDnon";
			medic = "AinvPknlMstpSlayWnonDnon_medic";
			medicOther = "AinvPknlMstpSlayWlnrDnon_medicOther";
			Relax = "AmovPknlMstpSrasWlnrDnon_relax";
			Gear = "AinvPknlMstpSrasWlnrDnon";
			putDown = "AmovPknlMstpSrasWlnrDnon_AinvPknlMstpSrasWlnrDnon_Putdown";
			StartFreefall = "AfalPknlMstpSrasWlnrDnon";
			PlayerProne = "AmovPpneMstpSnonWnonDnon";
			Down = "AmovPpneMstpSnonWnonDnon";
			PrimaryWeapon = "AmovPknlMstpSrasWrflDnon";
			SecondaryWeapon = "AmovPknlMstpSrasWlnrDnon";
			Binoculars = "AmovPknlMstpSoptWbinDnon";
			GetInBoat = "GetInHeli_Transport_01Cargo";
			GetOutBoat = "AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWrflDnon_getOutLow";
		};
		class LauncherKneelActionsRunF: LauncherKneelActions
		{
			PlayerStand = "AmovPercMrunSrasWlnrDf";
			Stand = "AmovPercMrunSrasWlnrDf";
			Up = "AmovPercMrunSrasWlnrDf";
		};
		class LauncherKneelActionsRunFL: LauncherKneelActionsRunF
		{
			Up = "AmovPercMrunSrasWlnrDfl";
			PlayerStand = "AmovPercMrunSrasWlnrDfl";
			Stand = "AmovPercMrunSrasWlnrDfl";
		};
		class LauncherKneelActionsRunL: LauncherKneelActionsRunF
		{
			Up = "AmovPercMrunSrasWlnrDl";
			PlayerStand = "AmovPercMrunSrasWlnrDl";
			Stand = "AmovPercMrunSrasWlnrDl";
		};
		class LauncherKneelActionsRunBL: LauncherKneelActionsRunF
		{
			PlayerStand = "AmovPercMrunSrasWlnrDbl";
			Up = "AmovPercMrunSrasWlnrDbl";
			Stand = "AmovPercMrunSrasWlnrDbl";
		};
		class LauncherKneelActionsRunB: LauncherKneelActionsRunF
		{
			PlayerStand = "AmovPercMrunSrasWlnrDb";
			Up = "AmovPercMrunSrasWlnrDb";
			Stand = "AmovPercMrunSrasWlnrDb";
		};
		class LauncherKneelActionsRunBR: LauncherKneelActionsRunF
		{
			Stand = "AmovPercMrunSrasWlnrDbr";
			PlayerStand = "AmovPercMrunSrasWlnrDbr";
			Up = "AmovPercMrunSrasWlnrDbr";
		};
		class LauncherKneelActionsRunR: LauncherKneelActionsRunF
		{
			Up = "AmovPercMrunSrasWlnrDr";
			PlayerStand = "AmovPercMrunSrasWlnrDr";
			Stand = "AmovPercMrunSrasWlnrDr";
		};
		class LauncherKneelActionsRunFR: LauncherKneelActionsRunF
		{
			PlayerStand = "AmovPercMrunSrasWlnrDfr";
			Up = "AmovPercMrunSrasWlnrDfr";
			Stand = "AmovPercMrunSrasWlnrDfr";
		};
		class LauncherKneelActionsTacF: LauncherKneelActions
		{
			PlayerStand = "AmovPercMtacSrasWlnrDf";
			Stand = "AmovPercMtacSrasWlnrDf";
			Up = "AmovPercMtacSrasWlnrDf";
		};
		class LauncherKneelActionsTacFL: LauncherKneelActionsTacF
		{
			PlayerStand = "AmovPercMtacSrasWlnrDfl";
			Up = "AmovPercMtacSrasWlnrDfl";
			Stand = "AmovPercMtacSrasWlnrDfl";
		};
		class LauncherKneelActionsTacL: LauncherKneelActionsTacF
		{
			Stand = "AmovPercMtacSrasWlnrDl";
			PlayerStand = "AmovPercMtacSrasWlnrDl";
			Up = "AmovPercMtacSrasWlnrDl";
		};
		class LauncherKneelActionsTacBL: LauncherKneelActionsTacF
		{
			PlayerStand = "AmovPercMtacSrasWlnrDbl";
			Up = "AmovPercMtacSrasWlnrDbl";
			Stand = "AmovPercMtacSrasWlnrDbl";
		};
		class LauncherKneelActionsTacB: LauncherKneelActionsTacF
		{
			PlayerStand = "AmovPercMtacSrasWlnrDb";
			Up = "AmovPercMtacSrasWlnrDb";
			Stand = "AmovPercMtacSrasWlnrDb";
		};
		class LauncherKneelActionsTacBR: LauncherKneelActionsTacF
		{
			Stand = "AmovPercMtacSrasWlnrDbr";
			PlayerStand = "AmovPercMtacSrasWlnrDbr";
			Up = "AmovPercMtacSrasWlnrDbr";
		};
		class LauncherKneelActionsTacR: LauncherKneelActionsTacF
		{
			Stand = "AmovPercMtacSrasWlnrDr";
			PlayerStand = "AmovPercMtacSrasWlnrDr";
			Up = "AmovPercMtacSrasWlnrDr";
		};
		class LauncherKneelActionsTacFR: LauncherKneelActionsTacF
		{
			PlayerStand = "AmovPercMtacSrasWlnrDfr";
			Up = "AmovPercMtacSrasWlnrDfr";
			Stand = "AmovPercMtacSrasWlnrDfr";
		};
		class LauncherKneelActionsWlkF: LauncherKneelActions
		{
			PlayerStand = "AmovPercMwlkSrasWlnrDf";
			Stand = "AmovPercMwlkSrasWlnrDf";
			Up = "AmovPercMwlkSrasWlnrDf";
		};
		class LauncherKneelActionsWlkFL: LauncherKneelActionsWlkF
		{
			PlayerStand = "AmovPercMwlkSrasWlnrDfl";
			Up = "AmovPercMwlkSrasWlnrDfl";
			Stand = "AmovPercMwlkSrasWlnrDfl";
		};
		class LauncherKneelActionsWlkL: LauncherKneelActionsWlkF
		{
			Stand = "AmovPercMwlkSrasWlnrDl";
			PlayerStand = "AmovPercMwlkSrasWlnrDl";
			Up = "AmovPercMwlkSrasWlnrDl";
		};
		class LauncherKneelActionsWlkBL: LauncherKneelActionsWlkF
		{
			PlayerStand = "AmovPercMwlkSrasWlnrDbl";
			Up = "AmovPercMwlkSrasWlnrDbl";
			Stand = "AmovPercMwlkSrasWlnrDbl";
		};
		class LauncherKneelActionsWlkB: LauncherKneelActionsWlkF
		{
			PlayerStand = "AmovPercMwlkSrasWlnrDb";
			Up = "AmovPercMwlkSrasWlnrDb";
			Stand = "AmovPercMwlkSrasWlnrDb";
		};
		class LauncherKneelActionsWlkBR: LauncherKneelActionsWlkF
		{
			Stand = "AmovPercMwlkSrasWlnrDbr";
			PlayerStand = "AmovPercMwlkSrasWlnrDbr";
			Up = "AmovPercMwlkSrasWlnrDbr";
		};
		class LauncherKneelActionsWlkR: LauncherKneelActionsWlkF
		{
			Stand = "AmovPercMwlkSrasWlnrDr";
			PlayerStand = "AmovPercMwlkSrasWlnrDr";
			Up = "AmovPercMwlkSrasWlnrDr";
		};
		class LauncherKneelActionsWlkFR: LauncherKneelActionsWlkF
		{
			PlayerStand = "AmovPercMwlkSrasWlnrDfr";
			Up = "AmovPercMwlkSrasWlnrDfr";
			Stand = "AmovPercMwlkSrasWlnrDfr";
		};
		class LauncherKneelRunFActions: LauncherKneelActions{};
		class LauncherKneelRunBActions: LauncherKneelRunFActions{};
		class LauncherStandActions: LauncherKneelActions
		{
			PlayerStand = "";
			ReloadRPG = "ReloadRPG";
			StopRelaxed = "AidlPercMstpSrasWlnrDnon_AI";
			Default = "AmovPercMstpSrasWlnrDnon";
			Up = "AmovPknlMstpSrasWlnrDnon";
			PlayerCrouch = "AmovPknlMstpSrasWlnrDnon";
			PlayerProne = "AmovPpneMstpSnonWnonDnon";
			Down = "AmovPpneMstpSnonWnonDnon";
			TurnL = "AmovPercMstpSrasWlnrDnon_turnL";
			TurnLRelaxed = "AmovPercMstpSrasWlnrDnon_turnL";
			TurnR = "AmovPercMstpSrasWlnrDnon_turnR";
			TurnRRelaxed = "AmovPercMstpSrasWlnrDnon_turnR";
			Stop = "AmovPercMstpSrasWlnrDnon";
			WalkB = "AmovPercMwlkSrasWlnrDb";
			WalkRB = "AmovPercMwlkSrasWlnrDbr";
			WalkLB = "AmovPercMwlkSrasWlnrDbl";
			WalkR = "AmovPercMwlkSrasWlnrDr";
			WalkL = "AmovPercMwlkSrasWlnrDl";
			WalkRF = "AmovPercMwlkSrasWlnrDfr";
			WalkLF = "AmovPercMwlkSrasWlnrDfl";
			WalkF = "AmovPercMwlkSrasWlnrDf";
			PlayerWalkB = "AmovPercMwlkSrasWlnrDb";
			PlayerWalkRB = "AmovPercMwlkSrasWlnrDbr";
			PlayerWalkLB = "AmovPercMwlkSrasWlnrDbl";
			PlayerWalkR = "AmovPercMwlkSrasWlnrDr";
			PlayerWalkL = "AmovPercMwlkSrasWlnrDl";
			PlayerWalkRF = "AmovPercMwlkSrasWlnrDfr";
			PlayerWalkLF = "AmovPercMwlkSrasWlnrDfl";
			PlayerWalkF = "AmovPercMwlkSrasWlnrDf";
			WeaponOff = "AmovPercMstpSrasWrflDnon";
			WeaponOn = "AmovPercMstpSrasWlnrDnon";
			BinocOff = "AmovPercMstpSrasWlnrDnon";
			EvasiveLeft = "AmovPercMrunSrasWlnrDfl";
			EvasiveRight = "AmovPercMrunSrasWlnrDfr";
			BinocOn = "AwopPercMstpSoptWbinDnon_lnr";
			HandGunOn = "AmovPercMstpSrasWpstDnon";
			SlowF = "AmovPercMrunSrasWlnrDf";
			SlowLF = "AmovPercMrunSrasWlnrDfl";
			SlowRF = "AmovPercMrunSrasWlnrDfr";
			SlowL = "AmovPercMrunSrasWlnrDl";
			SlowR = "AmovPercMrunSrasWlnrDr";
			SlowLB = "AmovPercMrunSrasWlnrDbl";
			SlowRB = "AmovPercMrunSrasWlnrDbr";
			SlowB = "AmovPercMrunSrasWlnrDb";
			PlayerSlowF = "AmovPercMrunSrasWlnrDf";
			PlayerSlowLF = "AmovPercMrunSrasWlnrDfl";
			PlayerSlowRF = "AmovPercMrunSrasWlnrDfr";
			PlayerSlowL = "AmovPercMrunSrasWlnrDl";
			PlayerSlowR = "AmovPercMrunSrasWlnrDr";
			PlayerSlowLB = "AmovPercMrunSrasWlnrDbl";
			PlayerSlowRB = "AmovPercMrunSrasWlnrDbr";
			PlayerSlowB = "AmovPercMrunSrasWlnrDb";
			FastF = "AmovPercMevaSlowWlnrDf";
			FastLF = "AmovPercMevaSlowWlnrDfl";
			FastRF = "AmovPercMevaSlowWlnrDfr";
			FastL = "AmovPercMrunSrasWlnrDl";
			FastR = "AmovPercMrunSrasWlnrDr";
			FastLB = "AmovPercMrunSrasWlnrDbl";
			FastRB = "AmovPercMrunSrasWlnrDr";
			FastB = "AmovPercMrunSrasWlnrDb";
			TactB = "AmovPercMtacSrasWlnrDb";
			TactRB = "AmovPercMtacSrasWlnrDbr";
			TactLB = "AmovPercMtacSrasWlnrDbl";
			TactR = "AmovPercMtacSrasWlnrDr";
			TactL = "AmovPercMtacSrasWlnrDl";
			TactRF = "AmovPercMtacSrasWlnrDfr";
			TactLF = "AmovPercMtacSrasWlnrDfl";
			TactF = "AmovPercMtacSrasWlnrDf";
			PlayerTactB = "AmovPercMtacSrasWlnrDb";
			PlayerTactRB = "AmovPercMtacSrasWlnrDbr";
			PlayerTactLB = "AmovPercMtacSrasWlnrDbl";
			PlayerTactR = "AmovPercMtacSrasWlnrDr";
			PlayerTactL = "AmovPercMtacSrasWlnrDl";
			PlayerTactRF = "AmovPercMtacSrasWlnrDfr";
			PlayerTactLF = "AmovPercMtacSrasWlnrDfl";
			PlayerTactF = "AmovPercMtacSrasWlnrDf";
			GetOver = "AovrPercMstpSrasWlnrDf";
			Gear = "AinvPercMstpSrasWlnrDnon";
			putDown = "AmovPercMstpSrasWlnrDnon_AinvPercMstpSrasWlnrDnon_Putdown";
			stance = "ManStanceStand";
			StartFreefall = "AfalPercMstpSrasWlnrDnon";
			PrimaryWeapon = "AmovPercMstpSrasWrflDnon";
			SecondaryWeapon = "AmovPercMstpSrasWlnrDnon";
			Binoculars = "AmovPercMstpSoptWbinDnon";
		};
		class LauncherStandActionsRunF: LauncherStandActions
		{
			Crouch = "AmovPknlMrunSrasWlnrDf";
			PlayerCrouch = "AmovPknlMrunSrasWlnrDf";
			Up = "AmovPknlMrunSrasWlnrDf";
		};
		class LauncherStandActionsRunFL: LauncherStandActionsRunF
		{
			PlayerCrouch = "AmovPknlMrunSrasWlnrDfl";
			Up = "AmovPknlMrunSrasWlnrDfl";
			Crouch = "AmovPknlMrunSrasWlnrDfl";
		};
		class LauncherStandActionsRunL: LauncherStandActionsRunF
		{
			PlayerCrouch = "AmovPknlMrunSrasWlnrDl";
			Up = "AmovPknlMrunSrasWlnrDl";
			Crouch = "AmovPknlMrunSrasWlnrDl";
		};
		class LauncherStandActionsRunBL: LauncherStandActionsRunF
		{
			PlayerCrouch = "AmovPknlMrunSrasWlnrDbl";
			Up = "AmovPknlMrunSrasWlnrDbl";
			Crouch = "AmovPknlMrunSrasWlnrDbl";
		};
		class LauncherStandActionsRunB: LauncherStandActionsRunF
		{
			Up = "AmovPknlMrunSrasWlnrDb";
			PlayerCrouch = "AmovPknlMrunSrasWlnrDb";
			Crouch = "AmovPknlMrunSrasWlnrDb";
		};
		class LauncherStandActionsRunBR: LauncherStandActionsRunF
		{
			Up = "AmovPknlMrunSrasWlnrDbr";
			PlayerCrouch = "AmovPknlMrunSrasWlnrDbr";
			Crouch = "AmovPknlMrunSrasWlnrDbr";
		};
		class LauncherStandActionsRunR: LauncherStandActionsRunF
		{
			Crouch = "AmovPknlMrunSrasWlnrDr";
			PlayerCrouch = "AmovPknlMrunSrasWlnrDr";
			Up = "AmovPknlMrunSrasWlnrDr";
		};
		class LauncherStandActionsRunFR: LauncherStandActionsRunF
		{
			PlayerCrouch = "AmovPknlMrunSrasWlnrDfr";
			Up = "AmovPknlMrunSrasWlnrDfr";
			Crouch = "AmovPknlMrunSrasWlnrDfr";
		};
		class LauncherStandActionsWlkF: LauncherStandActions
		{
			PlayerCrouch = "AmovPknlMwlkSrasWlnrDf";
			Crouch = "AmovPknlMwlkSrasWlnrDf";
			Up = "AmovPknlMwlkSrasWlnrDf";
		};
		class LauncherStandActionsWlkFL: LauncherStandActionsWlkF
		{
			Up = "AmovPknlMwlkSrasWlnrDfl";
			PlayerCrouch = "AmovPknlMwlkSrasWlnrDfl";
			Crouch = "AmovPknlMwlkSrasWlnrDfl";
		};
		class LauncherStandActionsWlkL: LauncherStandActionsWlkF
		{
			Up = "AmovPknlMwlkSrasWlnrDl";
			PlayerCrouch = "AmovPknlMwlkSrasWlnrDl";
			Crouch = "AmovPknlMwlkSrasWlnrDl";
		};
		class LauncherStandActionsWlkBL: LauncherStandActionsWlkF
		{
			Crouch = "AmovPknlMwlkSrasWlnrDbl";
			PlayerCrouch = "AmovPknlMwlkSrasWlnrDbl";
			Up = "AmovPknlMwlkSrasWlnrDbl";
		};
		class LauncherStandActionsWlkB: LauncherStandActionsWlkF
		{
			Crouch = "AmovPknlMwlkSrasWlnrDb";
			PlayerCrouch = "AmovPknlMwlkSrasWlnrDb";
			Up = "AmovPknlMwlkSrasWlnrDb";
		};
		class LauncherStandActionsWlkBR: LauncherStandActionsWlkF
		{
			Crouch = "AmovPknlMwlkSrasWlnrDbr";
			PlayerCrouch = "AmovPknlMwlkSrasWlnrDbr";
			Up = "AmovPknlMwlkSrasWlnrDbr";
		};
		class LauncherStandActionsWlkR: LauncherStandActionsWlkF
		{
			PlayerCrouch = "AmovPknlMwlkSrasWlnrDr";
			Up = "AmovPknlMwlkSrasWlnrDr";
			Crouch = "AmovPknlMwlkSrasWlnrDr";
		};
		class LauncherStandActionsWlkFR: LauncherStandActionsWlkF
		{
			Crouch = "AmovPknlMwlkSrasWlnrDfr";
			PlayerCrouch = "AmovPknlMwlkSrasWlnrDfr";
			Up = "AmovPknlMwlkSrasWlnrDfr";
		};
		class LauncherStandActionsTacF: LauncherStandActions
		{
			PlayerCrouch = "AmovPknlMTacSrasWlnrDf";
			Crouch = "AmovPknlMTacSrasWlnrDf";
			Up = "AmovPknlMTacSrasWlnrDf";
		};
		class LauncherStandActionsTacFL: LauncherStandActionsTacF
		{
			Up = "AmovPknlMTacSrasWlnrDfl";
			PlayerCrouch = "AmovPknlMTacSrasWlnrDfl";
			Crouch = "AmovPknlMTacSrasWlnrDfl";
		};
		class LauncherStandActionsTacL: LauncherStandActionsTacF
		{
			Up = "AmovPknlMTacSrasWlnrDl";
			PlayerCrouch = "AmovPknlMTacSrasWlnrDl";
			Crouch = "AmovPknlMTacSrasWlnrDl";
		};
		class LauncherStandActionsTacBL: LauncherStandActionsTacF
		{
			Crouch = "AmovPknlMTacSrasWlnrDbl";
			PlayerCrouch = "AmovPknlMTacSrasWlnrDbl";
			Up = "AmovPknlMTacSrasWlnrDbl";
		};
		class LauncherStandActionsTacB: LauncherStandActionsTacF
		{
			Crouch = "AmovPknlMTacSrasWlnrDb";
			PlayerCrouch = "AmovPknlMTacSrasWlnrDb";
			Up = "AmovPknlMTacSrasWlnrDb";
		};
		class LauncherStandActionsTacBR: LauncherStandActionsTacF
		{
			Crouch = "AmovPknlMTacSrasWlnrDbr";
			PlayerCrouch = "AmovPknlMTacSrasWlnrDbr";
			Up = "AmovPknlMTacSrasWlnrDbr";
		};
		class LauncherStandActionsTacR: LauncherStandActionsTacF
		{
			PlayerCrouch = "AmovPknlMTacSrasWlnrDr";
			Up = "AmovPknlMTacSrasWlnrDr";
			Crouch = "AmovPknlMTacSrasWlnrDr";
		};
		class LauncherStandActionsTacFR: LauncherStandActionsTacF
		{
			Crouch = "AmovPknlMTacSrasWlnrDfr";
			PlayerCrouch = "AmovPknlMTacSrasWlnrDfr";
			Up = "AmovPknlMTacSrasWlnrDfr";
		};
		class LauncherProneActions: LauncherKneelActions
		{
			StopRelaxed = "AmovPpneMstpSrasWlnrDnon";
			Default = "AmovPpneMstpSrasWlnrDnon";
			Combat = "AmovPpneMstpSrasWlnrDnon";
			Stand = "AmovPercMstpSrasWrflDnon";
			Up = "AmovPknlMstpSrasWlnrDnon";
			TurnL = "AmovPercMstpSrasWlnrDnon_turnL";
			TurnLRelaxed = "AmovPercMstpSrasWlnrDnon_turnL";
			TurnR = "AmovPercMstpSrasWlnrDnon_turnR";
			TurnRRelaxed = "AmovPercMstpSrasWlnrDnon_turnR";
			Stop = "AmovPpneMstpSrasWlnrDnon";
			WalkB = "AmovPpneMrunSrasWlnrDb";
			WalkRB = "AmovPpneMrunSrasWlnrDbr";
			WalkLB = "AmovPpneMrunSrasWlnrDbl";
			WalkR = "AmovPpneMrunSrasWlnrDr";
			WalkL = "AmovPpneMrunSrasWlnrDl";
			WalkRF = "AmovPpneMrunSrasWlnrDfr";
			WalkLF = "AmovPpneMrunSrasWlnrDfl";
			WalkF = "AmovPpneMrunSrasWlnrDf";
			PlayerWalkB = "AmovPpneMrunSrasWlnrDb";
			PlayerWalkRB = "AmovPpneMrunSrasWlnrDbr";
			PlayerWalkLB = "AmovPpneMrunSrasWlnrDbl";
			PlayerWalkR = "AmovPpneMrunSrasWlnrDr";
			PlayerWalkL = "AmovPpneMrunSrasWlnrDl";
			PlayerWalkRF = "AmovPpneMrunSrasWlnrDfr";
			PlayerWalkLF = "AmovPpneMrunSrasWlnrDfl";
			PlayerWalkF = "AmovPpneMrunSrasWlnrDf";
			WeaponOff = "AmovPpneMstpSrasWrflDnon";
			WeaponOn = "AmovPpneMstpSrasWlnrDnon";
			BinocOff = "AmovPercMstpSrasWlnrDnon";
			EvasiveLeft = "";
			EvasiveRight = "";
			BinocOn = "AwopPercMstpSoptWbinDnon_lnr";
			HandGunOn = "AmovPpneMstpSrasWpstDnon";
			SlowF = "AmovPpneMrunSrasWlnrDf";
			SlowLF = "AmovPpneMrunSrasWlnrDfl";
			SlowRF = "AmovPpneMrunSrasWlnrDfr";
			SlowL = "AmovPpneMrunSrasWlnrDl";
			SlowR = "AmovPpneMrunSrasWlnrDr";
			SlowLB = "AmovPpneMrunSrasWlnrDbl";
			SlowRB = "AmovPpneMrunSrasWlnrDbr";
			SlowB = "AmovPpneMrunSrasWlnrDb";
			PlayerSlowF = "AmovPpneMrunSrasWlnrDf";
			PlayerSlowLF = "AmovPpneMrunSrasWlnrDfl";
			PlayerSlowRF = "AmovPpneMrunSrasWlnrDfr";
			PlayerSlowL = "AmovPpneMrunSrasWlnrDl";
			PlayerSlowR = "AmovPpneMrunSrasWlnrDr";
			PlayerSlowLB = "AmovPpneMrunSrasWlnrDbl";
			PlayerSlowRB = "AmovPpneMrunSrasWlnrDbr";
			PlayerSlowB = "AmovPpneMrunSrasWlnrDb";
			FastF = "AmovPpneMrunSrasWlnrDf";
			FastLF = "AmovPpneMrunSrasWlnrDfl";
			FastRF = "AmovPpneMrunSrasWlnrDfr";
			FastL = "AmovPpneMrunSrasWlnrDl";
			FastR = "AmovPpneMrunSrasWlnrDr";
			FastLB = "AmovPpneMrunSrasWlnrDbl";
			FastRB = "AmovPpneMrunSrasWlnrDr";
			FastB = "AmovPpneMrunSrasWlnrDb";
			TactB = "AmovPpneMrunSrasWlnrDb";
			TactRB = "AmovPpneMrunSrasWlnrDbr";
			TactLB = "AmovPpneMrunSrasWlnrDbl";
			TactR = "AmovPpneMrunSrasWlnrDr";
			TactL = "AmovPpneMrunSrasWlnrDl";
			TactRF = "AmovPpneMrunSrasWlnrDfr";
			TactLF = "AmovPpneMrunSrasWlnrDfl";
			TactF = "AmovPpneMrunSrasWlnrDf";
			PlayerTactB = "AmovPpneMrunSrasWlnrDb";
			PlayerTactRB = "AmovPpneMrunSrasWlnrDbr";
			PlayerTactLB = "AmovPpneMrunSrasWlnrDbl";
			PlayerTactR = "AmovPpneMrunSrasWlnrDr";
			PlayerTactL = "AmovPpneMrunSrasWlnrDl";
			PlayerTactRF = "AmovPpneMrunSrasWlnrDfr";
			PlayerTactLF = "AmovPpneMrunSrasWlnrDfl";
			PlayerTactF = "AmovPpneMrunSrasWlnrDf";
			stance = "ManStanceProne";
		};
		class LauncherStandLowStpActions: LauncherStandActions
		{
			Stop = "AmovPercMstpSlowWlnrDnon";
			TurnL = "AmovPercMstpSlowWlnrDnon_turnL";
			TurnR = "AmovPercMstpSlowWlnrDnon_turnR";
			TurnLRelaxed = "AmovPercMstpSlowWlnrDnon_turnL";
			TurnRRelaxed = "AmovPercMstpSlowWlnrDnon_turnR";
			WalkF = "AmovPercMwlkSlowWlnrDf";
			WalkLF = "AmovPercMwlkSlowWlnrDfl";
			WalkRF = "AmovPercMwlkSlowWlnrDfr";
			WalkL = "AmovPercMwlkSlowWlnrDl";
			WalkR = "AmovPercMwlkSlowWlnrDr";
			WalkLB = "AmovPercMwlkSlowWlnrDbl";
			WalkRB = "AmovPercMwlkSlowWlnrDbr";
			WalkB = "AmovPercMwlkSlowWlnrDb";
			PlayerWalkF = "AmovPercMwlkSlowWlnrDf";
			PlayerWalkLF = "AmovPercMwlkSlowWlnrDfl";
			PlayerWalkRF = "AmovPercMwlkSlowWlnrDfr";
			PlayerWalkL = "AmovPercMwlkSlowWlnrDl";
			PlayerWalkR = "AmovPercMwlkSlowWlnrDr";
			PlayerWalkLB = "AmovPercMwlkSlowWlnrDbl";
			PlayerWalkRB = "AmovPercMwlkSlowWlnrDbr";
			PlayerWalkB = "AmovPercMwlkSlowWlnrDb";
			PlayerStand = "AmovPercMstpSrasWlnrDnon";
			FireNotPossible = "AmovPercMstpSrasWlnrDnon";
			SlowF = "AmovPercMwlkSlowWlnrDf";
			SlowLF = "AmovPercMwlkSlowWlnrDfl";
			SlowRF = "AmovPercMwlkSlowWlnrDfr";
			SlowL = "AmovPercMwlkSlowWlnrDl";
			SlowR = "AmovPercMwlkSlowWlnrDr";
			SlowLB = "AmovPercMwlkSlowWlnrDbl";
			SlowRB = "AmovPercMwlkSlowWlnrDbr";
			SlowB = "AmovPercMwlkSlowWlnrDb";
			PlayerSlowF = "AmovPercMwlkSlowWlnrDf";
			PlayerSlowLF = "AmovPercMwlkSlowWlnrDfl";
			PlayerSlowRF = "AmovPercMwlkSlowWlnrDfr";
			PlayerSlowL = "AmovPercMwlkSlowWlnrDl";
			PlayerSlowR = "AmovPercMwlkSlowWlnrDr";
			PlayerSlowLB = "AmovPercMwlkSlowWlnrDbl";
			PlayerSlowRB = "AmovPercMwlkSlowWlnrDbr";
			PlayerSlowB = "AmovPercMwlkSlowWlnrDb";
			FastL = "AmovPercMwlkSlowWlnrDl";
			FastR = "AmovPercMwlkSlowWlnrDr";
			FastLB = "AmovPercMwlkSlowWlnrDbl";
			FastRB = "AmovPercMwlkSlowWlnrDbr";
			FastB = "AmovPercMwlkSlowWlnrDb";
			TactF = "AmovPercMwlkSlowWlnrDf";
			TactLF = "AmovPercMwlkSlowWlnrDfl";
			TactRF = "AmovPercMwlkSlowWlnrDfr";
			TactL = "AmovPercMwlkSlowWlnrDl";
			TactR = "AmovPercMwlkSlowWlnrDr";
			TactLB = "AmovPercMwlkSlowWlnrDbl";
			TactRB = "AmovPercMwlkSlowWlnrDbr";
			TactB = "AmovPercMwlkSlowWlnrDb";
			PlayerTactF = "AmovPercMwlkSlowWlnrDf";
			PlayerTactLF = "AmovPercMwlkSlowWlnrDfl";
			PlayerTactRF = "AmovPercMwlkSlowWlnrDfr";
			PlayerTactL = "AmovPercMwlkSlowWlnrDl";
			PlayerTactR = "AmovPercMwlkSlowWlnrDr";
			PlayerTactLB = "AmovPercMwlkSlowWlnrDbl";
			PlayerTactRB = "AmovPercMwlkSlowWlnrDbr";
			PlayerTactB = "AmovPercMwlkSlowWlnrDb";
			EvasiveLeft = "AmovPercMwlkSlowWlnrDfl";
			EvasiveRight = "AmovPercMwlkSlowWlnrDfr";
			GetOver = "AovrPercMstpSlowWlnrDf";
			FastF = "AmovPercMrunSlowWlnrDf";
			FastLF = "AmovPercMrunSlowWlnrDfl";
			FastRF = "AmovPercMrunSlowWlnrDfr";
		};
		class LauncherStandRunFActions: LauncherStandActions{};
		class LauncherStandRunBActions: LauncherStandActions{};
		class LauncherKneelEvasiveFActions: LauncherStandRunFActions
		{
			turnSpeed = 4;
			WalkF = "AmovPercMevaSlowWlnrDf";
			PlayerWalkF = "AmovPercMevaSlowWlnrDf";
			SlowF = "AmovPercMevaSlowWlnrDf";
			PlayerSlowF = "AmovPercMevaSlowWlnrDf";
			SlowLF = "AmovPercMevaSlowWlnrDfl";
			SlowRF = "AmovPercMevaSlowWlnrDfr";
			PlayerSlowLF = "AmovPercMevaSlowWlnrDfl";
			PlayerSlowRF = "AmovPercMevaSlowWlnrDfr";
			WalkLF = "AmovPercMevaSlowWlnrDfl";
			WalkRF = "AmovPercMevaSlowWlnrDfr";
			PlayerWalkLF = "AmovPercMevaSlowWlnrDfl";
			PlayerWalkRF = "AmovPercMevaSlowWlnrDfr";
			stance = "ManStanceCrouch";
		};
		class LadderCivilActions: NoActions
		{
			stop = "LadderCivilStatic";
			default = "LadderCivilStatic";
			ladderOff = "AmovPercMstpSnonWnonDnon";
			ladderOffTop = "LadderCivilTopOff";
			ladderOffBottom = "LadderCivilDownOff";
			down = "LadderCivilDownLoop";
			up = "LadderCivilUpLoop";
			turnSpeed = 0.1;
		};
		class LadderRifleActions: LadderCivilActions
		{
			stop = "LadderRifleStatic";
			default = "LadderRifleStatic";
			ladderOff = "AmovPercMstpSlowWrflDnon";
			ladderOffTop = "LadderRifleTopOff";
			ladderOffBottom = "LadderRifleDownOff";
			ladderOnDown = "LadderRifleOn";
			ladderOnUp = "LadderRifleOn";
			down = "LadderRifleDownLoop";
			up = "LadderRifleUpLoop";
		};
		class SwimmingActions: NoActions
		{
			relax = "AswmPercMstpSnonWnonDnon_relax";
			stop = "AswmPercMstpSnonWnonDnon";
			startSwim = "AswmPercMstpSnonWnonDnon";
			surfaceSwim = "AsswPercMstpSnonWnonDnon";
			bottomSwim = "AbswPercMstpSnonWnonDnon";
			default = "AswmPercMstpSnonWnonDnon";
			stopRelaxed = "AswmPercMstpSnonWnonDnon";
			turnL = "AswmPercMstpSnonWnonDnon";
			turnR = "AswmPercMstpSnonWnonDnon";
			putDown = "AswmPercMstpSnonWnonDnon_AswmPercMstpSnonWnonDnon_putDown";
			medic = "AswmPercMstpSnonWnonDnon_AswmPercMstpSnonWnonDnon_putDown";
			WalkF = "AswmPercMwlkSnonWnonDf";
			WalkLF = "AswmPercMwlkSnonWnonDfl";
			WalkRF = "AswmPercMwlkSnonWnonDfr";
			WalkL = "AswmPercMwlkSnonWnonDl";
			WalkR = "AswmPercMwlkSnonWnonDr";
			WalkLB = "AswmPercMstpSnonWnonDnon";
			WalkRB = "AswmPercMstpSnonWnonDnon";
			WalkB = "AswmPercMwlkSnonWnonDb";
			PlayerWalkF = "AswmPercMwlkSnonWnonDf";
			PlayerWalkLF = "AswmPercMwlkSnonWnonDfl";
			PlayerWalkRF = "AswmPercMwlkSnonWnonDfr";
			PlayerWalkL = "AswmPercMwlkSnonWnonDl";
			PlayerWalkR = "AswmPercMwlkSnonWnonDr";
			PlayerWalkLB = "AswmPercMstpSnonWnonDnon";
			PlayerWalkRB = "AswmPercMstpSnonWnonDnon";
			PlayerWalkB = "AswmPercMwlkSnonWnonDb";
			SlowF = "AswmPercMrunSnonWnonDf";
			SlowLF = "AswmPercMrunSnonWnonDfl";
			SlowRF = "AswmPercMrunSnonWnonDfr";
			SlowL = "AswmPercMrunSnonWnonDl";
			SlowR = "AswmPercMrunSnonWnonDr";
			SlowLB = "AswmPercMstpSnonWnonDnon";
			SlowRB = "AswmPercMstpSnonWnonDnon";
			SlowB = "AswmPercMrunSnonWnonDb";
			PlayerSlowF = "AswmPercMrunSnonWnonDf";
			PlayerSlowLF = "AswmPercMrunSnonWnonDfl";
			PlayerSlowRF = "AswmPercMrunSnonWnonDfr";
			PlayerSlowL = "AswmPercMrunSnonWnonDl";
			PlayerSlowR = "AswmPercMrunSnonWnonDr";
			PlayerSlowLB = "AswmPercMstpSnonWnonDnon";
			PlayerSlowRB = "AswmPercMstpSnonWnonDnon";
			PlayerSlowB = "AswmPercMrunSnonWnonDb";
			FastF = "AswmPercMsprSnonWnonDf";
			FastLF = "AswmPercMsprSnonWnonDf";
			FastRF = "AswmPercMsprSnonWnonDf";
			FastL = "AswmPercMstpSnonWnonDnon";
			FastR = "AswmPercMstpSnonWnonDnon";
			FastLB = "AswmPercMstpSnonWnonDnon";
			FastRB = "AswmPercMstpSnonWnonDnon";
			FastB = "AswmPercMrunSnonWnonDb";
			TactF = "AswmPercMwlkSnonWnonDf";
			TactLF = "AswmPercMwlkSnonWnonDfl";
			TactRF = "AswmPercMwlkSnonWnonDfr";
			TactL = "AswmPercMwlkSnonWnonDl";
			TactR = "AswmPercMwlkSnonWnonDr";
			TactLB = "AswmPercMstpSnonWnonDnon";
			TactRB = "AswmPercMstpSnonWnonDnon";
			TactB = "AswmPercMwlkSnonWnonDb";
			PlayerTactF = "AswmPercMwlkSnonWnonDf";
			PlayerTactLF = "AswmPercMwlkSnonWnonDfl";
			PlayerTactRF = "AswmPercMwlkSnonWnonDfr";
			PlayerTactL = "AswmPercMwlkSnonWnonDl";
			PlayerTactR = "AswmPercMwlkSnonWnonDr";
			PlayerTactLB = "AswmPercMstpSnonWnonDnon";
			PlayerTactRB = "AswmPercMstpSnonWnonDnon";
			PlayerTactB = "AswmPercMwlkSnonWnonDb";
			stopSwim = "AmovPercMstpSnonWnonDnon";
			swimUp = "AswmPercMstpSnonWnonDnon_goup";
			swimDown = "AswmPercMstpSnonWnonDnon_goDown";
			GetOutPara = "AswmPercMstpSnonWnonDnon";
			upDegree = "ManPosSwimming";
			limitFast = 2;
			GetInBoat = "AmovPercMstpSnonWnonDnon_AcrgPknlMstpSnonWnonDnon_getInHigh";
			GetOutBoat = "AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWrflDnon_getOutHigh";
		};
		class SwimmingActionsRunF: SwimmingActions
		{
			startSwim = "AswmPercMrunSnonWnonDf";
			surfaceSwim = "AsswPercMrunSnonWnonDf";
			bottomSwim = "AbswPercMrunSnonWnonDf";
		};
		class SwimmingActionsRunFL: SwimmingActions
		{
			startSwim = "AswmPercMrunSnonWnonDfl";
			surfaceSwim = "AsswPercMrunSnonWnonDfl";
			bottomSwim = "AbswPercMrunSnonWnonDfl";
		};
		class SwimmingActionsRunL: SwimmingActions
		{
			startSwim = "AswmPercMrunSnonWnonDl";
			surfaceSwim = "AsswPercMrunSnonWnonDl";
			bottomSwim = "AbswPercMrunSnonWnonDl";
		};
		class SwimmingActionsRunBL: SwimmingActions
		{
			startSwim = "AswmPercMrunSnonWnonDbl";
			surfaceSwim = "AsswPercMrunSnonWnonDbl";
			bottomSwim = "AbswPercMrunSnonWnonDbl";
		};
		class SwimmingActionsRunB: SwimmingActions
		{
			startSwim = "AswmPercMrunSnonWnonDb";
			surfaceSwim = "AsswPercMrunSnonWnonDb";
			bottomSwim = "AbswPercMrunSnonWnonDb";
		};
		class SwimmingActionsRunBR: SwimmingActions
		{
			startSwim = "AswmPercMrunSnonWnonDbr";
			surfaceSwim = "AsswPercMrunSnonWnonDbr";
			bottomSwim = "AbswPercMrunSnonWnonDbr";
		};
		class SwimmingActionsRunR: SwimmingActions
		{
			startSwim = "AswmPercMrunSnonWnonDr";
			surfaceSwim = "AsswPercMrunSnonWnonDr";
			bottomSwim = "AbswPercMrunSnonWnonDr";
		};
		class SwimmingActionsRunFR: SwimmingActions
		{
			startSwim = "AswmPercMrunSnonWnonDfr";
			surfaceSwim = "AsswPercMrunSnonWnonDfr";
			bottomSwim = "AbswPercMrunSnonWnonDfr";
		};
		class SwimmingActionsFastF: SwimmingActionsRunF
		{
			limitFast = 4;
		};
		class SwimmingActionsFastFR: SwimmingActionsRunF
		{
			limitFast = 4;
		};
		class SwimmingActionsFastFL: SwimmingActionsRunF
		{
			limitFast = 4;
		};
		class SurfaceSwimmingActions: SwimmingActions
		{
			relax = "AsswPercMstpSnonWnonDnon_relax";
			stop = "AsswPercMstpSnonWnonDnon";
			default = "AsswPercMstpSnonWnonDnon";
			stopRelaxed = "AsswPercMstpSnonWnonDnon";
			turnL = "AsswPercMstpSnonWnonDnon";
			turnR = "AsswPercMstpSnonWnonDnon";
			WalkF = "AsswPercMwlkSnonWnonDf";
			WalkLF = "AsswPercMwlkSnonWnonDfl";
			WalkRF = "AsswPercMwlkSnonWnonDfr";
			WalkL = "AsswPercMwlkSnonWnonDl";
			WalkR = "AsswPercMwlkSnonWnonDr";
			WalkLB = "AsswPercMstpSnonWnonDnon";
			WalkRB = "AsswPercMstpSnonWnonDnon";
			WalkB = "AsswPercMwlkSnonWnonDb";
			PlayerWalkF = "AsswPercMwlkSnonWnonDf";
			PlayerWalkLF = "AsswPercMwlkSnonWnonDfl";
			PlayerWalkRF = "AsswPercMwlkSnonWnonDfr";
			PlayerWalkL = "AsswPercMwlkSnonWnonDl";
			PlayerWalkR = "AsswPercMwlkSnonWnonDr";
			PlayerWalkLB = "AsswPercMstpSnonWnonDnon";
			PlayerWalkRB = "AsswPercMstpSnonWnonDnon";
			PlayerWalkB = "AsswPercMwlkSnonWnonDb";
			SlowF = "AsswPercMrunSnonWnonDf";
			SlowLF = "AsswPercMrunSnonWnonDfl";
			SlowRF = "AsswPercMrunSnonWnonDfr";
			SlowL = "AsswPercMrunSnonWnonDl";
			SlowR = "AsswPercMrunSnonWnonDr";
			SlowLB = "AsswPercMstpSnonWnonDnon";
			SlowRB = "AsswPercMstpSnonWnonDnon";
			SlowB = "AsswPercMrunSnonWnonDb";
			PlayerSlowF = "AsswPercMrunSnonWnonDf";
			PlayerSlowLF = "AsswPercMrunSnonWnonDfl";
			PlayerSlowRF = "AsswPercMrunSnonWnonDfr";
			PlayerSlowL = "AsswPercMrunSnonWnonDl";
			PlayerSlowR = "AsswPercMrunSnonWnonDr";
			PlayerSlowLB = "AsswPercMstpSnonWnonDnon";
			PlayerSlowRB = "AsswPercMstpSnonWnonDnon";
			PlayerSlowB = "AsswPercMrunSnonWnonDb";
			FastF = "AsswPercMsprSnonWnonDf";
			FastLF = "AsswPercMsprSnonWnonDf";
			FastRF = "AsswPercMsprSnonWnonDf";
			FastL = "AsswPercMstpSnonWnonDnon";
			FastR = "AsswPercMstpSnonWnonDnon";
			FastLB = "AsswPercMstpSnonWnonDnon";
			FastRB = "AsswPercMstpSnonWnonDnon";
			FastB = "AsswPercMrunSnonWnonDb";
			TactF = "AsswPercMwlkSnonWnonDf";
			TactLF = "AsswPercMwlkSnonWnonDfl";
			TactRF = "AsswPercMwlkSnonWnonDfr";
			TactL = "AsswPercMwlkSnonWnonDl";
			TactR = "AsswPercMwlkSnonWnonDr";
			TactLB = "AsswPercMstpSnonWnonDnon";
			TactRB = "AsswPercMstpSnonWnonDnon";
			TactB = "AsswPercMwlkSnonWnonDb";
			PlayerTactF = "AsswPercMwlkSnonWnonDf";
			PlayerTactLF = "AsswPercMwlkSnonWnonDfl";
			PlayerTactRF = "AsswPercMwlkSnonWnonDfr";
			PlayerTactL = "AsswPercMwlkSnonWnonDl";
			PlayerTactR = "AsswPercMwlkSnonWnonDr";
			PlayerTactLB = "AsswPercMstpSnonWnonDnon";
			PlayerTactRB = "AsswPercMstpSnonWnonDnon";
			PlayerTactB = "AsswPercMwlkSnonWnonDb";
			swimUp = "AsswPercMstpSnonWnonDnon_goup";
			swimDown = "AsswPercMstpSnonWnonDnon_goDown";
			upDegree = "ManPosSurfaceSwimming";
		};
		class SurfaceSwimmingActionsRunF: SurfaceSwimmingActions
		{
			startSwim = "AswmPercMrunSnonWnonDf";
			surfaceSwim = "AsswPercMrunSnonWnonDf";
			bottomSwim = "AbswPercMrunSnonWnonDf";
		};
		class SurfaceSwimmingActionsRunFL: SurfaceSwimmingActions
		{
			startSwim = "AswmPercMrunSnonWnonDfl";
			surfaceSwim = "AsswPercMrunSnonWnonDfl";
			bottomSwim = "AbswPercMrunSnonWnonDfl";
		};
		class SurfaceSwimmingActionsRunL: SurfaceSwimmingActions
		{
			startSwim = "AswmPercMrunSnonWnonDl";
			surfaceSwim = "AsswPercMrunSnonWnonDl";
			bottomSwim = "AbswPercMrunSnonWnonDl";
		};
		class SurfaceSwimmingActionsRunBL: SurfaceSwimmingActions
		{
			startSwim = "AswmPercMrunSnonWnonDbl";
			surfaceSwim = "AsswPercMrunSnonWnonDbl";
			bottomSwim = "AbswPercMrunSnonWnonDbl";
		};
		class SurfaceSwimmingActionsRunB: SurfaceSwimmingActions
		{
			startSwim = "AswmPercMrunSnonWnonDb";
			surfaceSwim = "AsswPercMrunSnonWnonDb";
			bottomSwim = "AbswPercMrunSnonWnonDb";
		};
		class SurfaceSwimmingActionsRunBR: SurfaceSwimmingActions
		{
			startSwim = "AswmPercMrunSnonWnonDbr";
			surfaceSwim = "AsswPercMrunSnonWnonDbr";
			bottomSwim = "AbswPercMrunSnonWnonDbr";
		};
		class SurfaceSwimmingActionsRunR: SurfaceSwimmingActions
		{
			startSwim = "AswmPercMrunSnonWnonDr";
			surfaceSwim = "AsswPercMrunSnonWnonDr";
			bottomSwim = "AbswPercMrunSnonWnonDr";
		};
		class SurfaceSwimmingActionsRunFR: SurfaceSwimmingActions
		{
			startSwim = "AswmPercMrunSnonWnonDfr";
			surfaceSwim = "AsswPercMrunSnonWnonDfr";
			bottomSwim = "AbswPercMrunSnonWnonDfr";
		};
		class SurfaceSwimmingActionsFastF: SurfaceSwimmingActionsRunF
		{
			limitFast = 4;
		};
		class SurfaceSwimmingActionsFastFR: SurfaceSwimmingActionsRunF
		{
			limitFast = 4;
		};
		class SurfaceSwimmingActionsFastFL: SurfaceSwimmingActionsRunF
		{
			limitFast = 4;
		};
		class BottomSwimmingActions: SwimmingActions
		{
			relax = "AbswPercMstpSnonWnonDnon_relax";
			stop = "AbswPercMstpSnonWnonDnon";
			default = "AbswPercMstpSnonWnonDnon";
			stopRelaxed = "AbswPercMstpSnonWnonDnon";
			turnL = "AbswPercMstpSnonWnonDnon";
			turnR = "AbswPercMstpSnonWnonDnon";
			WalkF = "AbswPercMwlkSnonWnonDf";
			WalkLF = "AbswPercMwlkSnonWnonDfl";
			WalkRF = "AbswPercMwlkSnonWnonDfr";
			WalkL = "AbswPercMwlkSnonWnonDl";
			WalkR = "AbswPercMwlkSnonWnonDr";
			WalkLB = "AbswPercMstpSnonWnonDnon";
			WalkRB = "AbswPercMstpSnonWnonDnon";
			WalkB = "AbswPercMwlkSnonWnonDb";
			PlayerWalkF = "AbswPercMwlkSnonWnonDf";
			PlayerWalkLF = "AbswPercMwlkSnonWnonDfl";
			PlayerWalkRF = "AbswPercMwlkSnonWnonDfr";
			PlayerWalkL = "AbswPercMwlkSnonWnonDl";
			PlayerWalkR = "AbswPercMwlkSnonWnonDr";
			PlayerWalkLB = "AbswPercMstpSnonWnonDnon";
			PlayerWalkRB = "AbswPercMstpSnonWnonDnon";
			PlayerWalkB = "AbswPercMwlkSnonWnonDb";
			SlowF = "AbswPercMrunSnonWnonDf";
			SlowLF = "AbswPercMrunSnonWnonDfl";
			SlowRF = "AbswPercMrunSnonWnonDfr";
			SlowL = "AbswPercMrunSnonWnonDl";
			SlowR = "AbswPercMrunSnonWnonDr";
			SlowLB = "AbswPercMstpSnonWnonDnon";
			SlowRB = "AbswPercMstpSnonWnonDnon";
			SlowB = "AbswPercMrunSnonWnonDb";
			PlayerSlowF = "AbswPercMrunSnonWnonDf";
			PlayerSlowLF = "AbswPercMrunSnonWnonDfl";
			PlayerSlowRF = "AbswPercMrunSnonWnonDfr";
			PlayerSlowL = "AbswPercMrunSnonWnonDl";
			PlayerSlowR = "AbswPercMrunSnonWnonDr";
			PlayerSlowLB = "AbswPercMstpSnonWnonDnon";
			PlayerSlowRB = "AbswPercMstpSnonWnonDnon";
			PlayerSlowB = "AbswPercMrunSnonWnonDb";
			FastF = "AbswPercMsprSnonWnonDf";
			FastLF = "AbswPercMsprSnonWnonDf";
			FastRF = "AbswPercMsprSnonWnonDf";
			FastL = "AbswPercMstpSnonWnonDnon";
			FastR = "AbswPercMstpSnonWnonDnon";
			FastLB = "AbswPercMstpSnonWnonDnon";
			FastRB = "AbswPercMstpSnonWnonDnon";
			FastB = "AbswPercMrunSnonWnonDb";
			TactF = "AbswPercMwlkSnonWnonDf";
			TactLF = "AbswPercMwlkSnonWnonDfl";
			TactRF = "AbswPercMwlkSnonWnonDfr";
			TactL = "AbswPercMwlkSnonWnonDl";
			TactR = "AbswPercMwlkSnonWnonDr";
			TactLB = "AbswPercMstpSnonWnonDnon";
			TactRB = "AbswPercMstpSnonWnonDnon";
			TactB = "AbswPercMwlkSnonWnonDb";
			PlayerTactF = "AbswPercMwlkSnonWnonDf";
			PlayerTactLF = "AbswPercMwlkSnonWnonDfl";
			PlayerTactRF = "AbswPercMwlkSnonWnonDfr";
			PlayerTactL = "AbswPercMwlkSnonWnonDl";
			PlayerTactR = "AbswPercMwlkSnonWnonDr";
			PlayerTactLB = "AbswPercMstpSnonWnonDnon";
			PlayerTactRB = "AbswPercMstpSnonWnonDnon";
			PlayerTactB = "AbswPercMwlkSnonWnonDb";
			swimUp = "AbswPercMstpSnonWnonDnon_goup";
			swimDown = "AbswPercMstpSnonWnonDnon_goDown";
			upDegree = "ManPosBottomSwimming";
		};
		class BottomSwimmingActionsRunF: BottomSwimmingActions
		{
			startSwim = "AswmPercMrunSnonWnonDf";
			surfaceSwim = "AsswPercMrunSnonWnonDf";
			bottomSwim = "AbswPercMrunSnonWnonDf";
		};
		class BottomSwimmingActionsRunFL: BottomSwimmingActions
		{
			startSwim = "AswmPercMrunSnonWnonDfl";
			surfaceSwim = "AsswPercMrunSnonWnonDfl";
			bottomSwim = "AbswPercMrunSnonWnonDfl";
		};
		class BottomSwimmingActionsRunL: BottomSwimmingActions
		{
			startSwim = "AswmPercMrunSnonWnonDl";
			surfaceSwim = "AsswPercMrunSnonWnonDl";
			bottomSwim = "AbswPercMrunSnonWnonDl";
		};
		class BottomSwimmingActionsRunBL: BottomSwimmingActions
		{
			startSwim = "AswmPercMrunSnonWnonDbl";
			surfaceSwim = "AsswPercMrunSnonWnonDbl";
			bottomSwim = "AbswPercMrunSnonWnonDbl";
		};
		class BottomSwimmingActionsRunB: BottomSwimmingActions
		{
			startSwim = "AswmPercMrunSnonWnonDb";
			surfaceSwim = "AsswPercMrunSnonWnonDb";
			bottomSwim = "AbswPercMrunSnonWnonDb";
		};
		class BottomSwimmingActionsRunBR: BottomSwimmingActions
		{
			startSwim = "AswmPercMrunSnonWnonDbr";
			surfaceSwim = "AsswPercMrunSnonWnonDbr";
			bottomSwim = "AbswPercMrunSnonWnonDbr";
		};
		class BottomSwimmingActionsRunR: BottomSwimmingActions
		{
			startSwim = "AswmPercMrunSnonWnonDr";
			surfaceSwim = "AsswPercMrunSnonWnonDr";
			bottomSwim = "AbswPercMrunSnonWnonDr";
		};
		class BottomSwimmingActionsRunFR: BottomSwimmingActions
		{
			startSwim = "AswmPercMrunSnonWnonDfr";
			surfaceSwim = "AsswPercMrunSnonWnonDfr";
			bottomSwim = "AbswPercMrunSnonWnonDfr";
		};
		class BottomSwimmingActionsFastF: BottomSwimmingActionsRunF
		{
			limitFast = 4;
		};
		class BottomSwimmingActionsFastFR: BottomSwimmingActionsRunF
		{
			limitFast = 4;
		};
		class BottomSwimmingActionsFastFL: BottomSwimmingActionsRunF
		{
			limitFast = 4;
		};
		class DivingActions: NoActions
		{
			relax = "AdvePercMstpSnonWnonDnon_relax";
			stop = "AdvePercMstpSnonWnonDnon";
			PrimaryWeapon = "AdvePercMstpSnonWrflDnon";
			default = "AdvePercMstpSnonWnonDnon";
			stopRelaxed = "AdvePercMstpSnonWnonDnon";
			turnL = "AdvePercMstpSnonWnonDnon_turnL";
			turnR = "AdvePercMstpSnonWnonDnon_turnR";
			putDown = "AdvePercMstpSnonWnonDnon_AdvePercMstpSnonWnonDnon_putDown";
			medic = "AdvePercMstpSnonWnonDnon_AdvePercMstpSnonWnonDnon_putDown";
			WalkF = "AdvePercMwlkSnonWnonDf";
			WalkLF = "AdvePercMwlkSnonWnonDfl";
			WalkRF = "AdvePercMwlkSnonWnonDfr";
			WalkL = "AdvePercMwlkSnonWnonDl";
			WalkR = "AdvePercMwlkSnonWnonDr";
			WalkLB = "AdvePercMwlkSnonWnonDbl";
			WalkRB = "AdvePercMwlkSnonWnonDbr";
			WalkB = "AdvePercMwlkSnonWnonDb";
			PlayerWalkF = "AdvePercMwlkSnonWnonDf";
			PlayerWalkLF = "AdvePercMwlkSnonWnonDfl";
			PlayerWalkRF = "AdvePercMwlkSnonWnonDfr";
			PlayerWalkL = "AdvePercMwlkSnonWnonDl";
			PlayerWalkR = "AdvePercMwlkSnonWnonDr";
			PlayerWalkLB = "AdvePercMwlkSnonWnonDbl";
			PlayerWalkRB = "AdvePercMwlkSnonWnonDbr";
			PlayerWalkB = "AdvePercMwlkSnonWnonDb";
			SlowF = "AdvePercMrunSnonWnonDf";
			SlowLF = "AdvePercMrunSnonWnonDfl";
			SlowRF = "AdvePercMrunSnonWnonDfr";
			SlowL = "AdvePercMrunSnonWnonDl";
			SlowR = "AdvePercMrunSnonWnonDr";
			SlowLB = "AdvePercMrunSnonWnonDbl";
			SlowRB = "AdvePercMrunSnonWnonDbr";
			SlowB = "AdvePercMrunSnonWnonDb";
			PlayerSlowF = "AdvePercMrunSnonWnonDf";
			PlayerSlowLF = "AdvePercMrunSnonWnonDfl";
			PlayerSlowRF = "AdvePercMrunSnonWnonDfr";
			PlayerSlowL = "AdvePercMrunSnonWnonDl";
			PlayerSlowR = "AdvePercMrunSnonWnonDr";
			PlayerSlowLB = "AdvePercMrunSnonWnonDbl";
			PlayerSlowRB = "AdvePercMrunSnonWnonDbr";
			PlayerSlowB = "AdvePercMrunSnonWnonDb";
			FastF = "AdvePercMsprSnonWnonDf";
			FastLF = "AdvePercMrunSnonWnonDfl";
			FastRF = "AdvePercMrunSnonWnonDfr";
			FastL = "AdvePercMrunSnonWnonDl";
			FastR = "AdvePercMrunSnonWnonDr";
			FastLB = "AdvePercMrunSnonWnonDbl";
			FastRB = "AdvePercMrunSnonWnonDbr";
			FastB = "AdvePercMrunSnonWnonDb";
			TactF = "AdvePercMtacSnonWnonDf";
			TactLF = "AdvePercMtacSnonWnonDfl";
			TactRF = "AdvePercMtacSnonWnonDfr";
			TactL = "AdvePercMtacSnonWnonDl";
			TactR = "AdvePercMtacSnonWnonDr";
			TactLB = "AdvePercMtacSnonWnonDbl";
			TactRB = "AdvePercMtacSnonWnonDbr";
			TactB = "AdvePercMtacSnonWnonDb";
			PlayerTactF = "AdvePercMtacSnonWnonDf";
			PlayerTactLF = "AdvePercMtacSnonWnonDfl";
			PlayerTactRF = "AdvePercMtacSnonWnonDfr";
			PlayerTactL = "AdvePercMtacSnonWnonDl";
			PlayerTactR = "AdvePercMtacSnonWnonDr";
			PlayerTactLB = "AdvePercMtacSnonWnonDbl";
			PlayerTactRB = "AdvePercMtacSnonWnonDbr";
			PlayerTactB = "AdvePercMtacSnonWnonDb";
			stopDive = "AmovPercMstpSnonWnonDnon";
			SurfaceDive = "AsdvPercMstpSnonWnonDnon";
			BottomDive = "AbdvPercMstpSnonWnonDnon";
			SurfaceSwim = "AsswPercMstpSnonWnonDnon";
			BottomSwim = "AbswPercMstpSnonWnonDnon";
			swimUp = "AdvePercMstpSnonWnonDnon_goup";
			swimDown = "AdvePercMstpSnonWnonDnon_goDown";
			GetInSDV = "AdvePercMstpSnonWnonDnon_GetInSDV";
			GetOutSDV = "AdvePercMstpSnonWnonDnon_GetOutSDV";
			GetOutPara = "AdvePercMstpSnonWnonDnon";
			upDegree = "ManPosDiving";
			limitFast = 3.2;
			GetInBoat = "AmovPercMstpSnonWnonDnon_AcrgPknlMstpSnonWnonDnon_getInHigh";
			GetOutBoat = "AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWrflDnon_getOutHigh";
		};
		class DivingActionsGoingOut: DivingActions
		{
			upDegree = "ManPosGoingFromWater";
			Civil = "AmovPercMstpSnonWnonDnon";
			Default = "AmovPercMstpSnonWnonDnon";
			Stop = "AmovPercMstpSrasWrflDnon";
			Combat = "AmovPercMstpSrasWrflDnon";
		};
		class DivingActionsFastF: DivingActions
		{
			StartDive = "AdvePercMsprSnonWnonDf";
			SurfaceDive = "AsdvPercMsprSnonWnonDf";
			BottomDive = "AbdvPercMsprSnonWnonDf";
		};
		class DivingActionsRunF: DivingActions
		{
			SurfaceDive = "AsdvPercMrunSnonWnonDf";
			BottomDive = "AbdvPercMrunSnonWnonDf";
		};
		class DivingActionsRunFL: DivingActions
		{
			StartDive = "AdvePercMrunSnonWnonDfl";
			SurfaceDive = "AsdvPercMrunSnonWnonDfl";
			BottomDive = "AbdvPercMrunSnonWnonDfl";
		};
		class DivingActionsRunFR: DivingActions
		{
			StartDive = "AdvePercMrunSnonWnonDfr";
			SurfaceDive = "AsdvPercMrunSnonWnonDfr";
			BottomDive = "AbdvPercMrunSnonWnonDfr";
		};
		class DivingActionsRunB: DivingActions
		{
			StartDive = "AdvePercMrunSnonWnonDb";
			SurfaceDive = "AsdvPercMrunSnonWnonDb";
			BottomDive = "AbdvPercMrunSnonWnonDb";
		};
		class DivingActionsRunBR: DivingActions
		{
			StartDive = "AdvePercMrunSnonWnonDbr";
			SurfaceDive = "AsdvPercMrunSnonWnonDbr";
			BottomDive = "AbdvPercMrunSnonWnonDbr";
		};
		class DivingActionsRunBL: DivingActions
		{
			StartDive = "AdvePercMrunSnonWnonDbl";
			SurfaceDive = "AsdvPercMrunSnonWnonDbl";
			BottomDive = "AbdvPercMrunSnonWnonDbl";
		};
		class DivingActionsRunL: DivingActions
		{
			StartDive = "AdvePercMrunSnonWnonDl";
			SurfaceDive = "AsdvPercMrunSnonWnonDl";
			BottomDive = "AbdvPercMrunSnonWnonDl";
		};
		class DivingActionsRunR: DivingActions
		{
			StartDive = "AdvePercMrunSnonWnonDr";
			SurfaceDive = "AsdvPercMrunSnonWnonDr";
			BottomDive = "AbdvPercMrunSnonWnonDr";
		};
		class DivingActionsWlkF: DivingActions
		{
			StartDive = "AdvePercMwlkSnonWnonDf";
			SurfaceDive = "AsdvPercMwlkSnonWnonDf";
			BottomDive = "AbdvPercMwlkSnonWnonDf";
		};
		class DivingActionsWlkFL: DivingActions
		{
			StartDive = "AdvePercMwlkSnonWnonDfl";
			SurfaceDive = "AsdvPercMwlkSnonWnonDfl";
			BottomDive = "AbdvPercMwlkSnonWnonDfl";
		};
		class DivingActionsWlkFR: DivingActions
		{
			StartDive = "AdvePercMwlkSnonWnonDfr";
			SurfaceDive = "AsdvPercMwlkSnonWnonDfr";
			BottomDive = "AbdvPercMwlkSnonWnonDfr";
		};
		class DivingActionsWlkB: DivingActions
		{
			StartDive = "AdvePercMwlkSnonWnonDb";
			SurfaceDive = "AsdvPercMwlkSnonWnonDb";
			BottomDive = "AbdvPercMwlkSnonWnonDb";
		};
		class DivingActionsWlkBR: DivingActions
		{
			StartDive = "AdvePercMwlkSnonWnonDbr";
			SurfaceDive = "AsdvPercMwlkSnonWnonDbr";
			BottomDive = "AbdvPercMwlkSnonWnonDbr";
		};
		class DivingActionsWlkBL: DivingActions
		{
			StartDive = "AdvePercMwlkSnonWnonDbl";
			SurfaceDive = "AsdvPercMwlkSnonWnonDbl";
			BottomDive = "AbdvPercMwlkSnonWnonDbl";
		};
		class DivingActionsWlkL: DivingActions
		{
			StartDive = "AdvePercMwlkSnonWnonDl";
			SurfaceDive = "AsdvPercMwlkSnonWnonDl";
			BottomDive = "AbdvPercMwlkSnonWnonDl";
		};
		class DivingActionsWlkR: DivingActions
		{
			StartDive = "AdvePercMwlkSnonWnonDr";
			SurfaceDive = "AsdvPercMwlkSnonWnonDr";
			BottomDive = "AbdvPercMwlkSnonWnonDr";
		};
		class DivingActionsTacF: DivingActions
		{
			StartDive = "AdvePercMtacSnonWnonDf";
			SurfaceDive = "AsdvPercMtacSnonWnonDf";
			BottomDive = "AbdvPercMtacSnonWnonDf";
		};
		class DivingActionsTacFL: DivingActions
		{
			StartDive = "AdvePercMtacSnonWnonDfl";
			SurfaceDive = "AsdvPercMtacSnonWnonDfl";
			BottomDive = "AbdvPercMtacSnonWnonDfl";
		};
		class DivingActionsTacFR: DivingActions
		{
			StartDive = "AdvePercMtacSnonWnonDfr";
			SurfaceDive = "AsdvPercMtacSnonWnonDfr";
			BottomDive = "AbdvPercMtacSnonWnonDfr";
		};
		class DivingActionsTacB: DivingActions
		{
			StartDive = "AdvePercMtacSnonWnonDb";
			SurfaceDive = "AsdvPercMtacSnonWnonDb";
			BottomDive = "AbdvPercMtacSnonWnonDb";
		};
		class DivingActionsTacBR: DivingActions
		{
			StartDive = "AdvePercMtacSnonWnonDbr";
			SurfaceDive = "AsdvPercMtacSnonWnonDbr";
			BottomDive = "AbdvPercMtacSnonWnonDbr";
		};
		class DivingActionsTacBL: DivingActions
		{
			StartDive = "AdvePercMtacSnonWnonDbl";
			SurfaceDive = "AsdvPercMtacSnonWnonDbl";
			BottomDive = "AbdvPercMtacSnonWnonDbl";
		};
		class DivingActionsTacL: DivingActions
		{
			StartDive = "AdvePercMtacSnonWnonDl";
			SurfaceDive = "AsdvPercMtacSnonWnonDl";
			BottomDive = "AbdvPercMtacSnonWnonDl";
		};
		class DivingActionsTacR: DivingActions
		{
			StartDive = "AdvePercMtacSnonWnonDr";
			SurfaceDive = "AsdvPercMtacSnonWnonDr";
			BottomDive = "AbdvPercMtacSnonWnonDr";
		};
		class DivingRifleActions: DivingActions
		{
			relax = "AdvePercMstpSnonWrflDnon_relax";
			stop = "AdvePercMstpSnonWrflDnon";
			default = "AdvePercMstpSnonWrflDnon";
			stopRelaxed = "AdvePercMstpSnonWrflDnon";
			turnL = "AdvePercMstpSnonWrflDnon_turnL";
			turnR = "AdvePercMstpSnonWrflDnon_turnR";
			putDown = "AdvePercMstpSnonWrflDnon_AdvePercMstpSnonWrflDnon_putDown";
			WalkF = "AdvePercMwlkSnonWrflDf";
			WalkLF = "AdvePercMwlkSnonWrflDfl";
			WalkRF = "AdvePercMwlkSnonWrflDfr";
			WalkL = "AdvePercMwlkSnonWrflDl";
			WalkR = "AdvePercMwlkSnonWrflDr";
			WalkLB = "AdvePercMwlkSnonWrflDbl";
			WalkRB = "AdvePercMwlkSnonWrflDbr";
			WalkB = "AdvePercMwlkSnonWrflDb";
			PlayerWalkF = "AdvePercMwlkSnonWrflDf";
			PlayerWalkLF = "AdvePercMwlkSnonWrflDfl";
			PlayerWalkRF = "AdvePercMwlkSnonWrflDfr";
			PlayerWalkL = "AdvePercMwlkSnonWrflDl";
			PlayerWalkR = "AdvePercMwlkSnonWrflDr";
			PlayerWalkLB = "AdvePercMwlkSnonWrflDbl";
			PlayerWalkRB = "AdvePercMwlkSnonWrflDbr";
			PlayerWalkB = "AdvePercMwlkSnonWrflDb";
			SlowF = "AdvePercMrunSnonWrflDf";
			SlowLF = "AdvePercMrunSnonWrflDfl";
			SlowRF = "AdvePercMrunSnonWrflDfr";
			SlowL = "AdvePercMrunSnonWrflDl";
			SlowR = "AdvePercMrunSnonWrflDr";
			SlowLB = "AdvePercMrunSnonWrflDbl";
			SlowRB = "AdvePercMrunSnonWrflDbr";
			SlowB = "AdvePercMrunSnonWrflDb";
			PlayerSlowF = "AdvePercMrunSnonWrflDf";
			PlayerSlowLF = "AdvePercMrunSnonWrflDfl";
			PlayerSlowRF = "AdvePercMrunSnonWrflDfr";
			PlayerSlowL = "AdvePercMrunSnonWrflDl";
			PlayerSlowR = "AdvePercMrunSnonWrflDr";
			PlayerSlowLB = "AdvePercMrunSnonWrflDbl";
			PlayerSlowRB = "AdvePercMrunSnonWrflDbr";
			PlayerSlowB = "AdvePercMrunSnonWrflDb";
			FastF = "AdvePercMsprSnonWrflDf";
			FastLF = "AdvePercMrunSnonWrflDfl";
			FastRF = "AdvePercMrunSnonWrflDfr";
			FastL = "AdvePercMrunSnonWrflDl";
			FastR = "AdvePercMrunSnonWrflDr";
			FastLB = "AdvePercMrunSnonWrflDbl";
			FastRB = "AdvePercMrunSnonWrflDbr";
			FastB = "AdvePercMrunSnonWrflDb";
			TactF = "AdvePercMtacSnonWrflDf";
			TactLF = "AdvePercMtacSnonWrflDfl";
			TactRF = "AdvePercMtacSnonWrflDfr";
			TactL = "AdvePercMtacSnonWrflDl";
			TactR = "AdvePercMtacSnonWrflDr";
			TactLB = "AdvePercMtacSnonWrflDbl";
			TactRB = "AdvePercMtacSnonWrflDbr";
			TactB = "AdvePercMtacSnonWrflDb";
			PlayerTactF = "AdvePercMtacSnonWrflDf";
			PlayerTactLF = "AdvePercMtacSnonWrflDfl";
			PlayerTactRF = "AdvePercMtacSnonWrflDfr";
			PlayerTactL = "AdvePercMtacSnonWrflDl";
			PlayerTactR = "AdvePercMtacSnonWrflDr";
			PlayerTactLB = "AdvePercMtacSnonWrflDbl";
			PlayerTactRB = "AdvePercMtacSnonWrflDbr";
			PlayerTactB = "AdvePercMtacSnonWrflDb";
			stopDive = "AmovPercMstpSrasWrflDnon";
			StartDive = "AdvePercMstpSnonWrflDnon";
			SurfaceDive = "AsdvPercMstpSnonWrflDnon";
			BottomDive = "AbdvPercMstpSnonWrflDnon";
			swimUp = "AdvePercMstpSnonWrflDnon_goup";
			swimDown = "AdvePercMstpSnonWrflDnon_goDown";
			GetInSDV = "AdvePercMstpSnonWrflDnon_GetInSDV";
			GetOutSDV = "AdvePercMstpSnonWrflDnon_GetOutSDV";
		};
		class DivingRifleActionsGoingOut: DivingRifleActions
		{
			upDegree = "ManPosGoingFromWater";
			Stop = "AmovPercMstpSrasWrflDnon";
			Combat = "AmovPercMstpSrasWrflDnon";
			Default = "AmovPercMstpSrasWrflDnon";
		};
		class DivingRifleActionsFastF: DivingRifleActions
		{
			StartDive = "AdvePercMsprSnonWrflDf";
			SurfaceDive = "AsdvPercMsprSnonWrflDf";
			BottomDive = "AbdvPercMsprSnonWrflDf";
		};
		class DivingRifleActionsRunF: DivingRifleActions
		{
			StartDive = "AdvePercMrunSnonWrflDf";
			SurfaceDive = "AsdvPercMrunSnonWrflDf";
			BottomDive = "AbdvPercMrunSnonWrflDf";
		};
		class DivingRifleActionsRunFL: DivingRifleActions
		{
			StartDive = "AdvePercMrunSnonWrflDfl";
			SurfaceDive = "AsdvPercMrunSnonWrflDfl";
			BottomDive = "AbdvPercMrunSnonWrflDfl";
		};
		class DivingRifleActionsRunFR: DivingRifleActions
		{
			StartDive = "AdvePercMrunSnonWrflDfr";
			SurfaceDive = "AsdvPercMrunSnonWrflDfr";
			BottomDive = "AbdvPercMrunSnonWrflDfr";
		};
		class DivingRifleActionsRunB: DivingRifleActions
		{
			StartDive = "AdvePercMrunSnonWrflDb";
			SurfaceDive = "AsdvPercMrunSnonWrflDb";
			BottomDive = "AbdvPercMrunSnonWrflDb";
		};
		class DivingRifleActionsRunBR: DivingRifleActions
		{
			StartDive = "AdvePercMrunSnonWrflDbr";
			SurfaceDive = "AsdvPercMrunSnonWrflDbr";
			BottomDive = "AbdvPercMrunSnonWrflDbr";
		};
		class DivingRifleActionsRunBL: DivingRifleActions
		{
			StartDive = "AdvePercMrunSnonWrflDbl";
			SurfaceDive = "AsdvPercMrunSnonWrflDbl";
			BottomDive = "AbdvPercMrunSnonWrflDbl";
		};
		class DivingRifleActionsRunL: DivingRifleActions
		{
			StartDive = "AdvePercMrunSnonWrflDl";
			SurfaceDive = "AsdvPercMrunSnonWrflDl";
			BottomDive = "AbdvPercMrunSnonWrflDl";
		};
		class DivingRifleActionsRunR: DivingRifleActions
		{
			StartDive = "AdvePercMrunSnonWrflDr";
			SurfaceDive = "AsdvPercMrunSnonWrflDr";
			BottomDive = "AbdvPercMrunSnonWrflDr";
		};
		class DivingRifleActionsWlkF: DivingRifleActions
		{
			StartDive = "AdvePercMwlkSnonWrflDf";
			SurfaceDive = "AsdvPercMwlkSnonWrflDf";
			BottomDive = "AbdvPercMwlkSnonWrflDf";
		};
		class DivingRifleActionsWlkFL: DivingRifleActions
		{
			StartDive = "AdvePercMwlkSnonWrflDfl";
			SurfaceDive = "AsdvPercMwlkSnonWrflDfl";
			BottomDive = "AbdvPercMwlkSnonWrflDfl";
		};
		class DivingRifleActionsWlkFR: DivingRifleActions
		{
			StartDive = "AdvePercMwlkSnonWrflDfr";
			SurfaceDive = "AsdvPercMwlkSnonWrflDfr";
			BottomDive = "AbdvPercMwlkSnonWrflDfr";
		};
		class DivingRifleActionsWlkB: DivingRifleActions
		{
			StartDive = "AdvePercMwlkSnonWrflDb";
			SurfaceDive = "AsdvPercMwlkSnonWrflDb";
			BottomDive = "AbdvPercMwlkSnonWrflDb";
		};
		class DivingRifleActionsWlkBR: DivingRifleActions
		{
			StartDive = "AdvePercMwlkSnonWrflDbr";
			SurfaceDive = "AsdvPercMwlkSnonWrflDbr";
			BottomDive = "AbdvPercMwlkSnonWrflDbr";
		};
		class DivingRifleActionsWlkBL: DivingRifleActions
		{
			StartDive = "AdvePercMwlkSnonWrflDbl";
			SurfaceDive = "AsdvPercMwlkSnonWrflDbl";
			BottomDive = "AbdvPercMwlkSnonWrflDbl";
		};
		class DivingRifleActionsWlkL: DivingRifleActions
		{
			StartDive = "AdvePercMwlkSnonWrflDl";
			SurfaceDive = "AsdvPercMwlkSnonWrflDl";
			BottomDive = "AbdvPercMwlkSnonWrflDl";
		};
		class DivingRifleActionsWlkR: DivingRifleActions
		{
			StartDive = "AdvePercMwlkSnonWrflDr";
			SurfaceDive = "AsdvPercMwlkSnonWrflDr";
			BottomDive = "AbdvPercMwlkSnonWrflDr";
		};
		class DivingRifleActionsTacF: DivingRifleActions
		{
			StartDive = "AdvePercMtacSnonWrflDf";
			SurfaceDive = "AsdvPercMtacSnonWrflDf";
			BottomDive = "AbdvPercMtacSnonWrflDf";
		};
		class DivingRifleActionsTacFL: DivingRifleActions
		{
			StartDive = "AdvePercMtacSnonWrflDfl";
			SurfaceDive = "AsdvPercMtacSnonWrflDfl";
			BottomDive = "AbdvPercMtacSnonWrflDfl";
		};
		class DivingRifleActionsTacFR: DivingRifleActions
		{
			StartDive = "AdvePercMtacSnonWrflDfr";
			SurfaceDive = "AsdvPercMtacSnonWrflDfr";
			BottomDive = "AbdvPercMtacSnonWrflDfr";
		};
		class DivingRifleActionsTacB: DivingRifleActions
		{
			StartDive = "AdvePercMtacSnonWrflDb";
			SurfaceDive = "AsdvPercMtacSnonWrflDb";
			BottomDive = "AbdvPercMtacSnonWrflDb";
		};
		class DivingRifleActionsTacBR: DivingRifleActions
		{
			StartDive = "AdvePercMtacSnonWrflDbr";
			SurfaceDive = "AsdvPercMtacSnonWrflDbr";
			BottomDive = "AbdvPercMtacSnonWrflDbr";
		};
		class DivingRifleActionsTacBL: DivingRifleActions
		{
			StartDive = "AdvePercMtacSnonWrflDbl";
			SurfaceDive = "AsdvPercMtacSnonWrflDbl";
			BottomDive = "AbdvPercMtacSnonWrflDbl";
		};
		class DivingRifleActionsTacL: DivingRifleActions
		{
			StartDive = "AdvePercMtacSnonWrflDl";
			SurfaceDive = "AsdvPercMtacSnonWrflDl";
			BottomDive = "AbdvPercMtacSnonWrflDl";
		};
		class DivingRifleActionsTacR: DivingRifleActions
		{
			StartDive = "AdvePercMtacSnonWrflDr";
			SurfaceDive = "AsdvPercMtacSnonWrflDr";
			BottomDive = "AbdvPercMtacSnonWrflDr";
		};
		class SurfaceDivingActions: NoActions
		{
			relax = "AsdvPercMstpSnonWnonDnon_relax";
			stop = "AsdvPercMstpSnonWnonDnon";
			PrimaryWeapon = "AsdvPercMstpSnonWrflDnon";
			default = "AsdvPercMstpSnonWnonDnon";
			stopRelaxed = "AsdvPercMstpSnonWnonDnon";
			turnL = "AsdvPercMstpSnonWnonDnon_turnL";
			turnR = "AsdvPercMstpSnonWnonDnon_turnR";
			putDown = "AsdvPercMstpSnonWnonDnon_AsdvPercMstpSnonWnonDnon_putDown";
			WalkF = "AsdvPercMwlkSnonWnonDf";
			WalkLF = "AsdvPercMwlkSnonWnonDfl";
			WalkRF = "AsdvPercMwlkSnonWnonDfr";
			WalkL = "AsdvPercMwlkSnonWnonDl";
			WalkR = "AsdvPercMwlkSnonWnonDr";
			WalkLB = "AsdvPercMwlkSnonWnonDbl";
			WalkRB = "AsdvPercMwlkSnonWnonDbr";
			WalkB = "AsdvPercMwlkSnonWnonDb";
			PlayerWalkF = "AsdvPercMwlkSnonWnonDf";
			PlayerWalkLF = "AsdvPercMwlkSnonWnonDfl";
			PlayerWalkRF = "AsdvPercMwlkSnonWnonDfr";
			PlayerWalkL = "AsdvPercMwlkSnonWnonDl";
			PlayerWalkR = "AsdvPercMwlkSnonWnonDr";
			PlayerWalkLB = "AsdvPercMwlkSnonWnonDbl";
			PlayerWalkRB = "AsdvPercMwlkSnonWnonDbr";
			PlayerWalkB = "AsdvPercMwlkSnonWnonDb";
			SlowF = "AsdvPercMrunSnonWnonDf";
			SlowLF = "AsdvPercMrunSnonWnonDfl";
			SlowRF = "AsdvPercMrunSnonWnonDfr";
			SlowL = "AsdvPercMrunSnonWnonDl";
			SlowR = "AsdvPercMrunSnonWnonDr";
			SlowLB = "AsdvPercMrunSnonWnonDbl";
			SlowRB = "AsdvPercMrunSnonWnonDbr";
			SlowB = "AsdvPercMrunSnonWnonDb";
			PlayerSlowF = "AsdvPercMrunSnonWnonDf";
			PlayerSlowLF = "AsdvPercMrunSnonWnonDfl";
			PlayerSlowRF = "AsdvPercMrunSnonWnonDfr";
			PlayerSlowL = "AsdvPercMrunSnonWnonDl";
			PlayerSlowR = "AsdvPercMrunSnonWnonDr";
			PlayerSlowLB = "AsdvPercMrunSnonWnonDbl";
			PlayerSlowRB = "AsdvPercMrunSnonWnonDbr";
			PlayerSlowB = "AsdvPercMrunSnonWnonDb";
			FastF = "AsdvPercMsprSnonWnonDf";
			FastLF = "AsdvPercMrunSnonWnonDfl";
			FastRF = "AsdvPercMrunSnonWnonDfr";
			FastL = "AsdvPercMrunSnonWnonDl";
			FastR = "AsdvPercMrunSnonWnonDr";
			FastLB = "AsdvPercMrunSnonWnonDbl";
			FastRB = "AsdvPercMrunSnonWnonDbr";
			FastB = "AsdvPercMrunSnonWnonDb";
			TactF = "AsdvPercMtacSnonWnonDf";
			TactLF = "AsdvPercMtacSnonWnonDfl";
			TactRF = "AsdvPercMtacSnonWnonDfr";
			TactL = "AsdvPercMtacSnonWnonDl";
			TactR = "AsdvPercMtacSnonWnonDr";
			TactLB = "AsdvPercMtacSnonWnonDbl";
			TactRB = "AsdvPercMtacSnonWnonDbr";
			TactB = "AsdvPercMtacSnonWnonDb";
			PlayerTactF = "AsdvPercMtacSnonWnonDf";
			PlayerTactLF = "AsdvPercMtacSnonWnonDfl";
			PlayerTactRF = "AsdvPercMtacSnonWnonDfr";
			PlayerTactL = "AsdvPercMtacSnonWnonDl";
			PlayerTactR = "AsdvPercMtacSnonWnonDr";
			PlayerTactLB = "AsdvPercMtacSnonWnonDbl";
			PlayerTactRB = "AsdvPercMtacSnonWnonDbr";
			PlayerTactB = "AsdvPercMtacSnonWnonDb";
			stopDive = "AmovPercMstpSnonWnonDnon";
			SurfaceDive = "AsdvPercMstpSnonWnonDnon";
			BottomDive = "AbdvPercMstpSnonWnonDnon";
			swimUp = "AsdvPercMstpSnonWnonDnon_goup";
			swimDown = "AsdvPercMstpSnonWnonDnon_goDown";
			GetInSDV = "AsdvPercMstpSnonWnonDnon_GetInSDV";
			GetOutSDV = "AsdvPercMstpSnonWnonDnon_GetOutSDV";
			upDegree = "ManPosSurfaceDiving";
			limitFast = 3.2;
			GetInBoat = "AmovPercMstpSnonWnonDnon_AcrgPknlMstpSnonWnonDnon_getInHigh";
			GetOutBoat = "AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWrflDnon_getOutHigh";
		};
		class SurfaceDivingActionsGoingOut: SurfaceDivingActions
		{
			upDegree = "ManPosGoingFromWater";
			Civil = "AmovPercMstpSnonWnonDnon";
			Default = "AmovPercMstpSnonWnonDnon";
			Stop = "AmovPercMstpSrasWrflDnon";
			Combat = "AmovPercMstpSrasWrflDnon";
		};
		class SurfaceDivingActionsFastF: SurfaceDivingActions
		{
			StartDive = "AdvePercMsprSnonWnonDf";
			SurfaceDive = "AsdvPercMsprSnonWnonDf";
			BottomDive = "AbdvPercMsprSnonWnonDf";
		};
		class SurfaceDivingActionsRunF: SurfaceDivingActions
		{
			SurfaceDive = "AsdvPercMrunSnonWnonDf";
			BottomDive = "AbdvPercMrunSnonWnonDf";
		};
		class SurfaceDivingActionsRunFL: SurfaceDivingActions
		{
			StartDive = "AdvePercMrunSnonWnonDfl";
			SurfaceDive = "AsdvPercMrunSnonWnonDfl";
			BottomDive = "AbdvPercMrunSnonWnonDfl";
		};
		class SurfaceDivingActionsRunFR: SurfaceDivingActions
		{
			StartDive = "AdvePercMrunSnonWnonDfr";
			SurfaceDive = "AsdvPercMrunSnonWnonDfr";
			BottomDive = "AbdvPercMrunSnonWnonDfr";
		};
		class SurfaceDivingActionsRunB: SurfaceDivingActions
		{
			StartDive = "AdvePercMrunSnonWnonDb";
			SurfaceDive = "AsdvPercMrunSnonWnonDb";
			BottomDive = "AbdvPercMrunSnonWnonDb";
		};
		class SurfaceDivingActionsRunBR: SurfaceDivingActions
		{
			StartDive = "AdvePercMrunSnonWnonDbr";
			SurfaceDive = "AsdvPercMrunSnonWnonDbr";
			BottomDive = "AbdvPercMrunSnonWnonDbr";
		};
		class SurfaceDivingActionsRunBL: SurfaceDivingActions
		{
			StartDive = "AdvePercMrunSnonWnonDbl";
			SurfaceDive = "AsdvPercMrunSnonWnonDbl";
			BottomDive = "AbdvPercMrunSnonWnonDbl";
		};
		class SurfaceDivingActionsRunL: SurfaceDivingActions
		{
			StartDive = "AdvePercMrunSnonWnonDl";
			SurfaceDive = "AsdvPercMrunSnonWnonDl";
			BottomDive = "AbdvPercMrunSnonWnonDl";
		};
		class SurfaceDivingActionsRunR: SurfaceDivingActions
		{
			StartDive = "AdvePercMrunSnonWnonDr";
			SurfaceDive = "AsdvPercMrunSnonWnonDr";
			BottomDive = "AbdvPercMrunSnonWnonDr";
		};
		class SurfaceDivingActionsWlkF: SurfaceDivingActions
		{
			StartDive = "AdvePercMwlkSnonWnonDf";
			SurfaceDive = "AsdvPercMwlkSnonWnonDf";
			BottomDive = "AbdvPercMwlkSnonWnonDf";
		};
		class SurfaceDivingActionsWlkFL: SurfaceDivingActions
		{
			StartDive = "AdvePercMwlkSnonWnonDfl";
			SurfaceDive = "AsdvPercMwlkSnonWnonDfl";
			BottomDive = "AbdvPercMwlkSnonWnonDfl";
		};
		class SurfaceDivingActionsWlkFR: SurfaceDivingActions
		{
			StartDive = "AdvePercMwlkSnonWnonDfr";
			SurfaceDive = "AsdvPercMwlkSnonWnonDfr";
			BottomDive = "AbdvPercMwlkSnonWnonDfr";
		};
		class SurfaceDivingActionsWlkB: SurfaceDivingActions
		{
			StartDive = "AdvePercMwlkSnonWnonDb";
			SurfaceDive = "AsdvPercMwlkSnonWnonDb";
			BottomDive = "AbdvPercMwlkSnonWnonDb";
		};
		class SurfaceDivingActionsWlkBR: SurfaceDivingActions
		{
			StartDive = "AdvePercMwlkSnonWnonDbr";
			SurfaceDive = "AsdvPercMwlkSnonWnonDbr";
			BottomDive = "AbdvPercMwlkSnonWnonDbr";
		};
		class SurfaceDivingActionsWlkBL: SurfaceDivingActions
		{
			StartDive = "AdvePercMwlkSnonWnonDbl";
			SurfaceDive = "AsdvPercMwlkSnonWnonDbl";
			BottomDive = "AbdvPercMwlkSnonWnonDbl";
		};
		class SurfaceDivingActionsWlkL: SurfaceDivingActions
		{
			StartDive = "AdvePercMwlkSnonWnonDl";
			SurfaceDive = "AsdvPercMwlkSnonWnonDl";
			BottomDive = "AbdvPercMwlkSnonWnonDl";
		};
		class SurfaceDivingActionsWlkR: SurfaceDivingActions
		{
			StartDive = "AdvePercMwlkSnonWnonDr";
			SurfaceDive = "AsdvPercMwlkSnonWnonDr";
			BottomDive = "AbdvPercMwlkSnonWnonDr";
		};
		class SurfaceDivingActionsTacF: SurfaceDivingActions
		{
			StartDive = "AdvePercMtacSnonWnonDf";
			SurfaceDive = "AsdvPercMtacSnonWnonDf";
			BottomDive = "AbdvPercMtacSnonWnonDf";
		};
		class SurfaceDivingActionsTacFL: SurfaceDivingActions
		{
			StartDive = "AdvePercMtacSnonWnonDfl";
			SurfaceDive = "AsdvPercMtacSnonWnonDfl";
			BottomDive = "AbdvPercMtacSnonWnonDfl";
		};
		class SurfaceDivingActionsTacFR: SurfaceDivingActions
		{
			StartDive = "AdvePercMtacSnonWnonDfr";
			SurfaceDive = "AsdvPercMtacSnonWnonDfr";
			BottomDive = "AbdvPercMtacSnonWnonDfr";
		};
		class SurfaceDivingActionsTacB: SurfaceDivingActions
		{
			StartDive = "AdvePercMtacSnonWnonDb";
			SurfaceDive = "AsdvPercMtacSnonWnonDb";
			BottomDive = "AbdvPercMtacSnonWnonDb";
		};
		class SurfaceDivingActionsTacBR: SurfaceDivingActions
		{
			StartDive = "AdvePercMtacSnonWnonDbr";
			SurfaceDive = "AsdvPercMtacSnonWnonDbr";
			BottomDive = "AbdvPercMtacSnonWnonDbr";
		};
		class SurfaceDivingActionsTacBL: SurfaceDivingActions
		{
			StartDive = "AdvePercMtacSnonWnonDbl";
			SurfaceDive = "AsdvPercMtacSnonWnonDbl";
			BottomDive = "AbdvPercMtacSnonWnonDbl";
		};
		class SurfaceDivingActionsTacL: SurfaceDivingActions
		{
			StartDive = "AdvePercMtacSnonWnonDl";
			SurfaceDive = "AsdvPercMtacSnonWnonDl";
			BottomDive = "AbdvPercMtacSnonWnonDl";
		};
		class SurfaceDivingActionsTacR: SurfaceDivingActions
		{
			StartDive = "AdvePercMtacSnonWnonDr";
			SurfaceDive = "AsdvPercMtacSnonWnonDr";
			BottomDive = "AbdvPercMtacSnonWnonDr";
		};
		class SurfaceDivingRifleActions: SurfaceDivingActions
		{
			relax = "AsdvPercMstpSnonWrflDnon_relax";
			stop = "AsdvPercMstpSnonWrflDnon";
			default = "AsdvPercMstpSnonWrflDnon";
			stopRelaxed = "AsdvPercMstpSnonWrflDnon";
			turnL = "AsdvPercMstpSnonWrflDnon_turnL";
			turnR = "AsdvPercMstpSnonWrflDnon_turnR";
			putDown = "AsdvPercMstpSnonWrflDnon_AsdvPercMstpSnonWrflDnon_putDown";
			WalkF = "AsdvPercMwlkSnonWrflDf";
			WalkLF = "AsdvPercMwlkSnonWrflDfl";
			WalkRF = "AsdvPercMwlkSnonWrflDfr";
			WalkL = "AsdvPercMwlkSnonWrflDl";
			WalkR = "AsdvPercMwlkSnonWrflDr";
			WalkLB = "AsdvPercMwlkSnonWrflDbl";
			WalkRB = "AsdvPercMwlkSnonWrflDbr";
			WalkB = "AsdvPercMwlkSnonWrflDb";
			PlayerWalkF = "AsdvPercMwlkSnonWrflDf";
			PlayerWalkLF = "AsdvPercMwlkSnonWrflDfl";
			PlayerWalkRF = "AsdvPercMwlkSnonWrflDfr";
			PlayerWalkL = "AsdvPercMwlkSnonWrflDl";
			PlayerWalkR = "AsdvPercMwlkSnonWrflDr";
			PlayerWalkLB = "AsdvPercMwlkSnonWrflDbl";
			PlayerWalkRB = "AsdvPercMwlkSnonWrflDbr";
			PlayerWalkB = "AsdvPercMwlkSnonWrflDb";
			SlowF = "AsdvPercMrunSnonWrflDf";
			SlowLF = "AsdvPercMrunSnonWrflDfl";
			SlowRF = "AsdvPercMrunSnonWrflDfr";
			SlowL = "AsdvPercMrunSnonWrflDl";
			SlowR = "AsdvPercMrunSnonWrflDr";
			SlowLB = "AsdvPercMrunSnonWrflDbl";
			SlowRB = "AsdvPercMrunSnonWrflDbr";
			SlowB = "AsdvPercMrunSnonWrflDb";
			PlayerSlowF = "AsdvPercMrunSnonWrflDf";
			PlayerSlowLF = "AsdvPercMrunSnonWrflDfl";
			PlayerSlowRF = "AsdvPercMrunSnonWrflDfr";
			PlayerSlowL = "AsdvPercMrunSnonWrflDl";
			PlayerSlowR = "AsdvPercMrunSnonWrflDr";
			PlayerSlowLB = "AsdvPercMrunSnonWrflDbl";
			PlayerSlowRB = "AsdvPercMrunSnonWrflDbr";
			PlayerSlowB = "AsdvPercMrunSnonWrflDb";
			FastF = "AsdvPercMsprSnonWrflDf";
			FastLF = "AsdvPercMrunSnonWrflDfl";
			FastRF = "AsdvPercMrunSnonWrflDfr";
			FastL = "AsdvPercMrunSnonWrflDl";
			FastR = "AsdvPercMrunSnonWrflDr";
			FastLB = "AsdvPercMrunSnonWrflDbl";
			FastRB = "AsdvPercMrunSnonWrflDbr";
			FastB = "AsdvPercMrunSnonWrflDb";
			TactF = "AsdvPercMtacSnonWrflDf";
			TactLF = "AsdvPercMtacSnonWrflDfl";
			TactRF = "AsdvPercMtacSnonWrflDfr";
			TactL = "AsdvPercMtacSnonWrflDl";
			TactR = "AsdvPercMtacSnonWrflDr";
			TactLB = "AsdvPercMtacSnonWrflDbl";
			TactRB = "AsdvPercMtacSnonWrflDbr";
			TactB = "AsdvPercMtacSnonWrflDb";
			PlayerTactF = "AsdvPercMtacSnonWrflDf";
			PlayerTactLF = "AsdvPercMtacSnonWrflDfl";
			PlayerTactRF = "AsdvPercMtacSnonWrflDfr";
			PlayerTactL = "AsdvPercMtacSnonWrflDl";
			PlayerTactR = "AsdvPercMtacSnonWrflDr";
			PlayerTactLB = "AsdvPercMtacSnonWrflDbl";
			PlayerTactRB = "AsdvPercMtacSnonWrflDbr";
			PlayerTactB = "AsdvPercMtacSnonWrflDb";
			stopDive = "AmovPercMstpSrasWrflDnon";
			SurfaceDive = "AsdvPercMstpSnonWrflDnon";
			StartDive = "AdvePercMstpSnonWrflDnon";
			BottomDive = "AbdvPercMstpSnonWrflDnon";
			swimUp = "AsdvPercMstpSnonWrflDnon_goup";
			swimDown = "AsdvPercMstpSnonWrflDnon_goDown";
			GetInSDV = "AsdvPercMstpSnonWrflDnon_GetInSDV";
			GetOutSDV = "AsdvPercMstpSnonWrflDnon_GetOutSDV";
		};
		class SurfaceDivingRifleActionsGoingOut: SurfaceDivingRifleActions
		{
			upDegree = "ManPosGoingFromWater";
			Stop = "AmovPercMstpSrasWrflDnon";
			Combat = "AmovPercMstpSrasWrflDnon";
			Default = "AmovPercMstpSrasWrflDnon";
		};
		class SurfaceDivingRifleActionsFastF: SurfaceDivingRifleActions
		{
			StartDive = "AdvePercMsprSnonWrflDf";
			SurfaceDive = "AsdvPercMsprSnonWrflDf";
			BottomDive = "AbdvPercMsprSnonWrflDf";
		};
		class SurfaceDivingRifleActionsRunF: SurfaceDivingRifleActions
		{
			StartDive = "AdvePercMrunSnonWrflDf";
			SurfaceDive = "AsdvPercMrunSnonWrflDf";
			BottomDive = "AbdvPercMrunSnonWrflDf";
		};
		class SurfaceDivingRifleActionsRunFL: SurfaceDivingRifleActions
		{
			StartDive = "AdvePercMrunSnonWrflDfl";
			SurfaceDive = "AsdvPercMrunSnonWrflDfl";
			BottomDive = "AbdvPercMrunSnonWrflDfl";
		};
		class SurfaceDivingRifleActionsRunFR: SurfaceDivingRifleActions
		{
			StartDive = "AdvePercMrunSnonWrflDfr";
			SurfaceDive = "AsdvPercMrunSnonWrflDfr";
			BottomDive = "AbdvPercMrunSnonWrflDfr";
		};
		class SurfaceDivingRifleActionsRunB: SurfaceDivingRifleActions
		{
			StartDive = "AdvePercMrunSnonWrflDb";
			SurfaceDive = "AsdvPercMrunSnonWrflDb";
			BottomDive = "AbdvPercMrunSnonWrflDb";
		};
		class SurfaceDivingRifleActionsRunBR: SurfaceDivingRifleActions
		{
			StartDive = "AdvePercMrunSnonWrflDbr";
			SurfaceDive = "AsdvPercMrunSnonWrflDbr";
			BottomDive = "AbdvPercMrunSnonWrflDbr";
		};
		class SurfaceDivingRifleActionsRunBL: SurfaceDivingRifleActions
		{
			StartDive = "AdvePercMrunSnonWrflDbl";
			SurfaceDive = "AsdvPercMrunSnonWrflDbl";
			BottomDive = "AbdvPercMrunSnonWrflDbl";
		};
		class SurfaceDivingRifleActionsRunL: SurfaceDivingRifleActions
		{
			StartDive = "AdvePercMrunSnonWrflDl";
			SurfaceDive = "AsdvPercMrunSnonWrflDl";
			BottomDive = "AbdvPercMrunSnonWrflDl";
		};
		class SurfaceDivingRifleActionsRunR: SurfaceDivingRifleActions
		{
			StartDive = "AdvePercMrunSnonWrflDr";
			SurfaceDive = "AsdvPercMrunSnonWrflDr";
			BottomDive = "AbdvPercMrunSnonWrflDr";
		};
		class SurfaceDivingRifleActionsWlkF: SurfaceDivingRifleActions
		{
			StartDive = "AdvePercMwlkSnonWrflDf";
			SurfaceDive = "AsdvPercMwlkSnonWrflDf";
			BottomDive = "AbdvPercMwlkSnonWrflDf";
		};
		class SurfaceDivingRifleActionsWlkFL: SurfaceDivingRifleActions
		{
			StartDive = "AdvePercMwlkSnonWrflDfl";
			SurfaceDive = "AsdvPercMwlkSnonWrflDfl";
			BottomDive = "AbdvPercMwlkSnonWrflDfl";
		};
		class SurfaceDivingRifleActionsWlkFR: SurfaceDivingRifleActions
		{
			StartDive = "AdvePercMwlkSnonWrflDfr";
			SurfaceDive = "AsdvPercMwlkSnonWrflDfr";
			BottomDive = "AbdvPercMwlkSnonWrflDfr";
		};
		class SurfaceDivingRifleActionsWlkB: SurfaceDivingRifleActions
		{
			StartDive = "AdvePercMwlkSnonWrflDb";
			SurfaceDive = "AsdvPercMwlkSnonWrflDb";
			BottomDive = "AbdvPercMwlkSnonWrflDb";
		};
		class SurfaceDivingRifleActionsWlkBR: SurfaceDivingRifleActions
		{
			StartDive = "AdvePercMwlkSnonWrflDbr";
			SurfaceDive = "AsdvPercMwlkSnonWrflDbr";
			BottomDive = "AbdvPercMwlkSnonWrflDbr";
		};
		class SurfaceDivingRifleActionsWlkBL: SurfaceDivingRifleActions
		{
			StartDive = "AdvePercMwlkSnonWrflDbl";
			SurfaceDive = "AsdvPercMwlkSnonWrflDbl";
			BottomDive = "AbdvPercMwlkSnonWrflDbl";
		};
		class SurfaceDivingRifleActionsWlkL: SurfaceDivingRifleActions
		{
			StartDive = "AdvePercMwlkSnonWrflDl";
			SurfaceDive = "AsdvPercMwlkSnonWrflDl";
			BottomDive = "AbdvPercMwlkSnonWrflDl";
		};
		class SurfaceDivingRifleActionsWlkR: SurfaceDivingRifleActions
		{
			StartDive = "AdvePercMwlkSnonWrflDr";
			SurfaceDive = "AsdvPercMwlkSnonWrflDr";
			BottomDive = "AbdvPercMwlkSnonWrflDr";
		};
		class SurfaceDivingRifleActionsTacF: SurfaceDivingRifleActions
		{
			StartDive = "AdvePercMtacSnonWrflDf";
			SurfaceDive = "AsdvPercMtacSnonWrflDf";
			BottomDive = "AbdvPercMtacSnonWrflDf";
		};
		class SurfaceDivingRifleActionsTacFL: SurfaceDivingRifleActions
		{
			StartDive = "AdvePercMtacSnonWrflDfl";
			SurfaceDive = "AsdvPercMtacSnonWrflDfl";
			BottomDive = "AbdvPercMtacSnonWrflDfl";
		};
		class SurfaceDivingRifleActionsTacFR: SurfaceDivingRifleActions
		{
			StartDive = "AdvePercMtacSnonWrflDfr";
			SurfaceDive = "AsdvPercMtacSnonWrflDfr";
			BottomDive = "AbdvPercMtacSnonWrflDfr";
		};
		class SurfaceDivingRifleActionsTacB: SurfaceDivingRifleActions
		{
			StartDive = "AdvePercMtacSnonWrflDb";
			SurfaceDive = "AsdvPercMtacSnonWrflDb";
			BottomDive = "AbdvPercMtacSnonWrflDb";
		};
		class SurfaceDivingRifleActionsTacBR: SurfaceDivingRifleActions
		{
			StartDive = "AdvePercMtacSnonWrflDbr";
			SurfaceDive = "AsdvPercMtacSnonWrflDbr";
			BottomDive = "AbdvPercMtacSnonWrflDbr";
		};
		class SurfaceDivingRifleActionsTacBL: SurfaceDivingRifleActions
		{
			StartDive = "AdvePercMtacSnonWrflDbl";
			SurfaceDive = "AsdvPercMtacSnonWrflDbl";
			BottomDive = "AbdvPercMtacSnonWrflDbl";
		};
		class SurfaceDivingRifleActionsTacL: SurfaceDivingRifleActions
		{
			StartDive = "AdvePercMtacSnonWrflDl";
			SurfaceDive = "AsdvPercMtacSnonWrflDl";
			BottomDive = "AbdvPercMtacSnonWrflDl";
		};
		class SurfaceDivingRifleActionsTacR: SurfaceDivingRifleActions
		{
			StartDive = "AdvePercMtacSnonWrflDr";
			SurfaceDive = "AsdvPercMtacSnonWrflDr";
			BottomDive = "AbdvPercMtacSnonWrflDr";
		};
		class BottomDivingActions: NoActions
		{
			relax = "AbdvPercMstpSnonWnonDnon_relax";
			stop = "AbdvPercMstpSnonWnonDnon";
			PrimaryWeapon = "AbdvPercMstpSnonWrflDnon";
			default = "AbdvPercMstpSnonWnonDnon";
			stopRelaxed = "AbdvPercMstpSnonWnonDnon";
			turnL = "AbdvPercMstpSnonWnonDnon_turnL";
			turnR = "AbdvPercMstpSnonWnonDnon_turnR";
			putDown = "AbdvPercMstpSnonWnonDnon_AbdvPercMstpSnonWnonDnon_putDown";
			WalkF = "AbdvPercMwlkSnonWnonDf";
			WalkLF = "AbdvPercMwlkSnonWnonDfl";
			WalkRF = "AbdvPercMwlkSnonWnonDfr";
			WalkL = "AbdvPercMwlkSnonWnonDl";
			WalkR = "AbdvPercMwlkSnonWnonDr";
			WalkLB = "AbdvPercMwlkSnonWnonDbl";
			WalkRB = "AbdvPercMwlkSnonWnonDbr";
			WalkB = "AbdvPercMwlkSnonWnonDb";
			PlayerWalkF = "AbdvPercMwlkSnonWnonDf";
			PlayerWalkLF = "AbdvPercMwlkSnonWnonDfl";
			PlayerWalkRF = "AbdvPercMwlkSnonWnonDfr";
			PlayerWalkL = "AbdvPercMwlkSnonWnonDl";
			PlayerWalkR = "AbdvPercMwlkSnonWnonDr";
			PlayerWalkLB = "AbdvPercMwlkSnonWnonDbl";
			PlayerWalkRB = "AbdvPercMwlkSnonWnonDbr";
			PlayerWalkB = "AbdvPercMwlkSnonWnonDb";
			SlowF = "AbdvPercMrunSnonWnonDf";
			SlowLF = "AbdvPercMrunSnonWnonDfl";
			SlowRF = "AbdvPercMrunSnonWnonDfr";
			SlowL = "AbdvPercMrunSnonWnonDl";
			SlowR = "AbdvPercMrunSnonWnonDr";
			SlowLB = "AbdvPercMrunSnonWnonDbl";
			SlowRB = "AbdvPercMrunSnonWnonDbr";
			SlowB = "AbdvPercMrunSnonWnonDb";
			PlayerSlowF = "AbdvPercMrunSnonWnonDf";
			PlayerSlowLF = "AbdvPercMrunSnonWnonDfl";
			PlayerSlowRF = "AbdvPercMrunSnonWnonDfr";
			PlayerSlowL = "AbdvPercMrunSnonWnonDl";
			PlayerSlowR = "AbdvPercMrunSnonWnonDr";
			PlayerSlowLB = "AbdvPercMrunSnonWnonDbl";
			PlayerSlowRB = "AbdvPercMrunSnonWnonDbr";
			PlayerSlowB = "AbdvPercMrunSnonWnonDb";
			FastF = "AbdvPercMsprSnonWnonDf";
			FastLF = "AbdvPercMrunSnonWnonDfl";
			FastRF = "AbdvPercMrunSnonWnonDfr";
			FastL = "AbdvPercMrunSnonWnonDl";
			FastR = "AbdvPercMrunSnonWnonDr";
			FastLB = "AbdvPercMrunSnonWnonDbl";
			FastRB = "AbdvPercMrunSnonWnonDbr";
			FastB = "AbdvPercMrunSnonWnonDb";
			TactF = "AbdvPercMtacSnonWnonDf";
			TactLF = "AbdvPercMtacSnonWnonDfl";
			TactRF = "AbdvPercMtacSnonWnonDfr";
			TactL = "AbdvPercMtacSnonWnonDl";
			TactR = "AbdvPercMtacSnonWnonDr";
			TactLB = "AbdvPercMtacSnonWnonDbl";
			TactRB = "AbdvPercMtacSnonWnonDbr";
			TactB = "AbdvPercMtacSnonWnonDb";
			PlayerTactF = "AbdvPercMtacSnonWnonDf";
			PlayerTactLF = "AbdvPercMtacSnonWnonDfl";
			PlayerTactRF = "AbdvPercMtacSnonWnonDfr";
			PlayerTactL = "AbdvPercMtacSnonWnonDl";
			PlayerTactR = "AbdvPercMtacSnonWnonDr";
			PlayerTactLB = "AbdvPercMtacSnonWnonDbl";
			PlayerTactRB = "AbdvPercMtacSnonWnonDbr";
			PlayerTactB = "AbdvPercMtacSnonWnonDb";
			stopDive = "AmovPercMstpSnonWnonDnon";
			SurfaceDive = "AsdvPercMstpSnonWnonDnon";
			BottomDive = "AbdvPercMstpSnonWnonDnon";
			swimUp = "AbdvPercMstpSnonWnonDnon_goup";
			swimDown = "AbdvPercMstpSnonWnonDnon_goDown";
			GetInSDV = "AbdvPercMstpSnonWnonDnon_GetInSDV";
			GetOutSDV = "AbdvPercMstpSnonWnonDnon_GetOutSDV";
			upDegree = "ManPosBottomDiving";
			limitFast = 3.2;
			GetInBoat = "AmovPercMstpSnonWnonDnon_AcrgPknlMstpSnonWnonDnon_getInHigh";
			GetOutBoat = "AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWrflDnon_getOutHigh";
		};
		class BottomDivingActionsGoingOut: BottomDivingActions
		{
			upDegree = "ManPosGoingFromWater";
			Civil = "AmovPercMstpSnonWnonDnon";
			Default = "AmovPercMstpSnonWnonDnon";
			Stop = "AmovPercMstpSrasWrflDnon";
			Combat = "AmovPercMstpSrasWrflDnon";
		};
		class BottomDivingActionsFastF: BottomDivingActions
		{
			StartDive = "AdvePercMsprSnonWnonDf";
			SurfaceDive = "AsdvPercMsprSnonWnonDf";
			BottomDive = "AbdvPercMsprSnonWnonDf";
		};
		class BottomDivingActionsRunF: BottomDivingActions
		{
			SurfaceDive = "AsdvPercMrunSnonWnonDf";
			BottomDive = "AbdvPercMrunSnonWnonDf";
		};
		class BottomDivingActionsRunFL: BottomDivingActions
		{
			StartDive = "AdvePercMrunSnonWnonDfl";
			SurfaceDive = "AsdvPercMrunSnonWnonDfl";
			BottomDive = "AbdvPercMrunSnonWnonDfl";
		};
		class BottomDivingActionsRunFR: BottomDivingActions
		{
			StartDive = "AdvePercMrunSnonWnonDfr";
			SurfaceDive = "AsdvPercMrunSnonWnonDfr";
			BottomDive = "AbdvPercMrunSnonWnonDfr";
		};
		class BottomDivingActionsRunB: BottomDivingActions
		{
			StartDive = "AdvePercMrunSnonWnonDb";
			SurfaceDive = "AsdvPercMrunSnonWnonDb";
			BottomDive = "AbdvPercMrunSnonWnonDb";
		};
		class BottomDivingActionsRunBR: BottomDivingActions
		{
			StartDive = "AdvePercMrunSnonWnonDbr";
			SurfaceDive = "AsdvPercMrunSnonWnonDbr";
			BottomDive = "AbdvPercMrunSnonWnonDbr";
		};
		class BottomDivingActionsRunBL: BottomDivingActions
		{
			StartDive = "AdvePercMrunSnonWnonDbl";
			SurfaceDive = "AsdvPercMrunSnonWnonDbl";
			BottomDive = "AbdvPercMrunSnonWnonDbl";
		};
		class BottomDivingActionsRunL: BottomDivingActions
		{
			StartDive = "AdvePercMrunSnonWnonDl";
			SurfaceDive = "AsdvPercMrunSnonWnonDl";
			BottomDive = "AbdvPercMrunSnonWnonDl";
		};
		class BottomDivingActionsRunR: BottomDivingActions
		{
			StartDive = "AdvePercMrunSnonWnonDr";
			SurfaceDive = "AsdvPercMrunSnonWnonDr";
			BottomDive = "AbdvPercMrunSnonWnonDr";
		};
		class BottomDivingActionsWlkF: BottomDivingActions
		{
			StartDive = "AdvePercMwlkSnonWnonDf";
			SurfaceDive = "AsdvPercMwlkSnonWnonDf";
			BottomDive = "AbdvPercMwlkSnonWnonDf";
		};
		class BottomDivingActionsWlkFL: BottomDivingActions
		{
			StartDive = "AdvePercMwlkSnonWnonDfl";
			SurfaceDive = "AsdvPercMwlkSnonWnonDfl";
			BottomDive = "AbdvPercMwlkSnonWnonDfl";
		};
		class BottomDivingActionsWlkFR: BottomDivingActions
		{
			StartDive = "AdvePercMwlkSnonWnonDfr";
			SurfaceDive = "AsdvPercMwlkSnonWnonDfr";
			BottomDive = "AbdvPercMwlkSnonWnonDfr";
		};
		class BottomDivingActionsWlkB: BottomDivingActions
		{
			StartDive = "AdvePercMwlkSnonWnonDb";
			SurfaceDive = "AsdvPercMwlkSnonWnonDb";
			BottomDive = "AbdvPercMwlkSnonWnonDb";
		};
		class BottomDivingActionsWlkBR: BottomDivingActions
		{
			StartDive = "AdvePercMwlkSnonWnonDbr";
			SurfaceDive = "AsdvPercMwlkSnonWnonDbr";
			BottomDive = "AbdvPercMwlkSnonWnonDbr";
		};
		class BottomDivingActionsWlkBL: BottomDivingActions
		{
			StartDive = "AdvePercMwlkSnonWnonDbl";
			SurfaceDive = "AsdvPercMwlkSnonWnonDbl";
			BottomDive = "AbdvPercMwlkSnonWnonDbl";
		};
		class BottomDivingActionsWlkL: BottomDivingActions
		{
			StartDive = "AdvePercMwlkSnonWnonDl";
			SurfaceDive = "AsdvPercMwlkSnonWnonDl";
			BottomDive = "AbdvPercMwlkSnonWnonDl";
		};
		class BottomDivingActionsWlkR: BottomDivingActions
		{
			StartDive = "AdvePercMwlkSnonWnonDr";
			SurfaceDive = "AsdvPercMwlkSnonWnonDr";
			BottomDive = "AbdvPercMwlkSnonWnonDr";
		};
		class BottomDivingActionsTacF: BottomDivingActions
		{
			StartDive = "AdvePercMtacSnonWnonDf";
			SurfaceDive = "AsdvPercMtacSnonWnonDf";
			BottomDive = "AbdvPercMtacSnonWnonDf";
		};
		class BottomDivingActionsTacFL: BottomDivingActions
		{
			StartDive = "AdvePercMtacSnonWnonDfl";
			SurfaceDive = "AsdvPercMtacSnonWnonDfl";
			BottomDive = "AbdvPercMtacSnonWnonDfl";
		};
		class BottomDivingActionsTacFR: BottomDivingActions
		{
			StartDive = "AdvePercMtacSnonWnonDfr";
			SurfaceDive = "AsdvPercMtacSnonWnonDfr";
			BottomDive = "AbdvPercMtacSnonWnonDfr";
		};
		class BottomDivingActionsTacB: BottomDivingActions
		{
			StartDive = "AdvePercMtacSnonWnonDb";
			SurfaceDive = "AsdvPercMtacSnonWnonDb";
			BottomDive = "AbdvPercMtacSnonWnonDb";
		};
		class BottomDivingActionsTacBR: BottomDivingActions
		{
			StartDive = "AdvePercMtacSnonWnonDbr";
			SurfaceDive = "AsdvPercMtacSnonWnonDbr";
			BottomDive = "AbdvPercMtacSnonWnonDbr";
		};
		class BottomDivingActionsTacBL: BottomDivingActions
		{
			StartDive = "AdvePercMtacSnonWnonDbl";
			SurfaceDive = "AsdvPercMtacSnonWnonDbl";
			BottomDive = "AbdvPercMtacSnonWnonDbl";
		};
		class BottomDivingActionsTacL: BottomDivingActions
		{
			StartDive = "AdvePercMtacSnonWnonDl";
			SurfaceDive = "AsdvPercMtacSnonWnonDl";
			BottomDive = "AbdvPercMtacSnonWnonDl";
		};
		class BottomDivingActionsTacR: BottomDivingActions
		{
			StartDive = "AdvePercMtacSnonWnonDr";
			SurfaceDive = "AsdvPercMtacSnonWnonDr";
			BottomDive = "AbdvPercMtacSnonWnonDr";
		};
		class BottomDivingRifleActions: BottomDivingActions
		{
			relax = "AbdvPercMstpSnonWrflDnon_relax";
			stop = "AbdvPercMstpSnonWrflDnon";
			default = "AbdvPercMstpSnonWrflDnon";
			stopRelaxed = "AbdvPercMstpSnonWrflDnon";
			turnL = "AbdvPercMstpSnonWrflDnon_turnL";
			turnR = "AbdvPercMstpSnonWrflDnon_turnR";
			putDown = "AbdvPercMstpSnonWrflDnon_AbdvPercMstpSnonWrflDnon_putDown";
			WalkF = "AbdvPercMwlkSnonWrflDf";
			WalkLF = "AbdvPercMwlkSnonWrflDfl";
			WalkRF = "AbdvPercMwlkSnonWrflDfr";
			WalkL = "AbdvPercMwlkSnonWrflDl";
			WalkR = "AbdvPercMwlkSnonWrflDr";
			WalkLB = "AbdvPercMwlkSnonWrflDbl";
			WalkRB = "AbdvPercMwlkSnonWrflDbr";
			WalkB = "AbdvPercMwlkSnonWrflDb";
			PlayerWalkF = "AbdvPercMwlkSnonWrflDf";
			PlayerWalkLF = "AbdvPercMwlkSnonWrflDfl";
			PlayerWalkRF = "AbdvPercMwlkSnonWrflDfr";
			PlayerWalkL = "AbdvPercMwlkSnonWrflDl";
			PlayerWalkR = "AbdvPercMwlkSnonWrflDr";
			PlayerWalkLB = "AbdvPercMwlkSnonWrflDbl";
			PlayerWalkRB = "AbdvPercMwlkSnonWrflDbr";
			PlayerWalkB = "AbdvPercMwlkSnonWrflDb";
			SlowF = "AbdvPercMrunSnonWrflDf";
			SlowLF = "AbdvPercMrunSnonWrflDfl";
			SlowRF = "AbdvPercMrunSnonWrflDfr";
			SlowL = "AbdvPercMrunSnonWrflDl";
			SlowR = "AbdvPercMrunSnonWrflDr";
			SlowLB = "AbdvPercMrunSnonWrflDbl";
			SlowRB = "AbdvPercMrunSnonWrflDbr";
			SlowB = "AbdvPercMrunSnonWrflDb";
			PlayerSlowF = "AbdvPercMrunSnonWrflDf";
			PlayerSlowLF = "AbdvPercMrunSnonWrflDfl";
			PlayerSlowRF = "AbdvPercMrunSnonWrflDfr";
			PlayerSlowL = "AbdvPercMrunSnonWrflDl";
			PlayerSlowR = "AbdvPercMrunSnonWrflDr";
			PlayerSlowLB = "AbdvPercMrunSnonWrflDbl";
			PlayerSlowRB = "AbdvPercMrunSnonWrflDbr";
			PlayerSlowB = "AbdvPercMrunSnonWrflDb";
			FastF = "AbdvPercMsprSnonWrflDf";
			FastLF = "AbdvPercMrunSnonWrflDfl";
			FastRF = "AbdvPercMrunSnonWrflDfr";
			FastL = "AbdvPercMrunSnonWrflDl";
			FastR = "AbdvPercMrunSnonWrflDr";
			FastLB = "AbdvPercMrunSnonWrflDbl";
			FastRB = "AbdvPercMrunSnonWrflDbr";
			FastB = "AbdvPercMrunSnonWrflDb";
			TactF = "AbdvPercMtacSnonWrflDf";
			TactLF = "AbdvPercMtacSnonWrflDfl";
			TactRF = "AbdvPercMtacSnonWrflDfr";
			TactL = "AbdvPercMtacSnonWrflDl";
			TactR = "AbdvPercMtacSnonWrflDr";
			TactLB = "AbdvPercMtacSnonWrflDbl";
			TactRB = "AbdvPercMtacSnonWrflDbr";
			TactB = "AbdvPercMtacSnonWrflDb";
			PlayerTactF = "AbdvPercMtacSnonWrflDf";
			PlayerTactLF = "AbdvPercMtacSnonWrflDfl";
			PlayerTactRF = "AbdvPercMtacSnonWrflDfr";
			PlayerTactL = "AbdvPercMtacSnonWrflDl";
			PlayerTactR = "AbdvPercMtacSnonWrflDr";
			PlayerTactLB = "AbdvPercMtacSnonWrflDbl";
			PlayerTactRB = "AbdvPercMtacSnonWrflDbr";
			PlayerTactB = "AbdvPercMtacSnonWrflDb";
			stopDive = "AmovPercMstpSrasWrflDnon";
			StartDive = "AdvePercMstpSnonWrflDnon";
			SurfaceDive = "AsdvPercMstpSnonWrflDnon";
			BottomDive = "AbdvPercMstpSnonWrflDnon";
			swimUp = "AbdvPercMstpSnonWrflDnon_goup";
			swimDown = "AbdvPercMstpSnonWrflDnon_goDown";
			GetInSDV = "AbdvPercMstpSnonWrflDnon_GetInSDV";
			GetOutSDV = "AbdvPercMstpSnonWrflDnon_GetOutSDV";
		};
		class BottomDivingRifleActionsGoingOut: BottomDivingRifleActions
		{
			upDegree = "ManPosGoingFromWater";
			Stop = "AmovPercMstpSrasWrflDnon";
			Combat = "AmovPercMstpSrasWrflDnon";
			Default = "AmovPercMstpSrasWrflDnon";
		};
		class BottomDivingRifleActionsFastF: BottomDivingRifleActions
		{
			StartDive = "AdvePercMsprSnonWrflDf";
			SurfaceDive = "AsdvPercMsprSnonWrflDf";
			BottomDive = "AbdvPercMsprSnonWrflDf";
		};
		class BottomDivingRifleActionsRunF: BottomDivingRifleActions
		{
			StartDive = "AdvePercMrunSnonWrflDf";
			SurfaceDive = "AsdvPercMrunSnonWrflDf";
			BottomDive = "AbdvPercMrunSnonWrflDf";
		};
		class BottomDivingRifleActionsRunFL: BottomDivingRifleActions
		{
			StartDive = "AdvePercMrunSnonWrflDfl";
			SurfaceDive = "AsdvPercMrunSnonWrflDfl";
			BottomDive = "AbdvPercMrunSnonWrflDfl";
		};
		class BottomDivingRifleActionsRunFR: BottomDivingRifleActions
		{
			StartDive = "AdvePercMrunSnonWrflDfr";
			SurfaceDive = "AsdvPercMrunSnonWrflDfr";
			BottomDive = "AbdvPercMrunSnonWrflDfr";
		};
		class BottomDivingRifleActionsRunB: BottomDivingRifleActions
		{
			StartDive = "AdvePercMrunSnonWrflDb";
			SurfaceDive = "AsdvPercMrunSnonWrflDb";
			BottomDive = "AbdvPercMrunSnonWrflDb";
		};
		class BottomDivingRifleActionsRunBR: BottomDivingRifleActions
		{
			StartDive = "AdvePercMrunSnonWrflDbr";
			SurfaceDive = "AsdvPercMrunSnonWrflDbr";
			BottomDive = "AbdvPercMrunSnonWrflDbr";
		};
		class BottomDivingRifleActionsRunBL: BottomDivingRifleActions
		{
			StartDive = "AdvePercMrunSnonWrflDbl";
			SurfaceDive = "AsdvPercMrunSnonWrflDbl";
			BottomDive = "AbdvPercMrunSnonWrflDbl";
		};
		class BottomDivingRifleActionsRunL: BottomDivingRifleActions
		{
			StartDive = "AdvePercMrunSnonWrflDl";
			SurfaceDive = "AsdvPercMrunSnonWrflDl";
			BottomDive = "AbdvPercMrunSnonWrflDl";
		};
		class BottomDivingRifleActionsRunR: BottomDivingRifleActions
		{
			StartDive = "AdvePercMrunSnonWrflDr";
			SurfaceDive = "AsdvPercMrunSnonWrflDr";
			BottomDive = "AbdvPercMrunSnonWrflDr";
		};
		class BottomDivingRifleActionsWlkF: BottomDivingRifleActions
		{
			StartDive = "AdvePercMwlkSnonWrflDf";
			SurfaceDive = "AsdvPercMwlkSnonWrflDf";
			BottomDive = "AbdvPercMwlkSnonWrflDf";
		};
		class BottomDivingRifleActionsWlkFL: BottomDivingRifleActions
		{
			StartDive = "AdvePercMwlkSnonWrflDfl";
			SurfaceDive = "AsdvPercMwlkSnonWrflDfl";
			BottomDive = "AbdvPercMwlkSnonWrflDfl";
		};
		class BottomDivingRifleActionsWlkFR: BottomDivingRifleActions
		{
			StartDive = "AdvePercMwlkSnonWrflDfr";
			SurfaceDive = "AsdvPercMwlkSnonWrflDfr";
			BottomDive = "AbdvPercMwlkSnonWrflDfr";
		};
		class BottomDivingRifleActionsWlkB: BottomDivingRifleActions
		{
			StartDive = "AdvePercMwlkSnonWrflDb";
			SurfaceDive = "AsdvPercMwlkSnonWrflDb";
			BottomDive = "AbdvPercMwlkSnonWrflDb";
		};
		class BottomDivingRifleActionsWlkBR: BottomDivingRifleActions
		{
			StartDive = "AdvePercMwlkSnonWrflDbr";
			SurfaceDive = "AsdvPercMwlkSnonWrflDbr";
			BottomDive = "AbdvPercMwlkSnonWrflDbr";
		};
		class BottomDivingRifleActionsWlkBL: BottomDivingRifleActions
		{
			StartDive = "AdvePercMwlkSnonWrflDbl";
			SurfaceDive = "AsdvPercMwlkSnonWrflDbl";
			BottomDive = "AbdvPercMwlkSnonWrflDbl";
		};
		class BottomDivingRifleActionsWlkL: BottomDivingRifleActions
		{
			StartDive = "AdvePercMwlkSnonWrflDl";
			SurfaceDive = "AsdvPercMwlkSnonWrflDl";
			BottomDive = "AbdvPercMwlkSnonWrflDl";
		};
		class BottomDivingRifleActionsWlkR: BottomDivingRifleActions
		{
			StartDive = "AdvePercMwlkSnonWrflDr";
			SurfaceDive = "AsdvPercMwlkSnonWrflDr";
			BottomDive = "AbdvPercMwlkSnonWrflDr";
		};
		class BottomDivingRifleActionsTacF: BottomDivingRifleActions
		{
			StartDive = "AdvePercMtacSnonWrflDf";
			SurfaceDive = "AsdvPercMtacSnonWrflDf";
			BottomDive = "AbdvPercMtacSnonWrflDf";
		};
		class BottomDivingRifleActionsTacFL: BottomDivingRifleActions
		{
			StartDive = "AdvePercMtacSnonWrflDfl";
			SurfaceDive = "AsdvPercMtacSnonWrflDfl";
			BottomDive = "AbdvPercMtacSnonWrflDfl";
		};
		class BottomDivingRifleActionsTacFR: BottomDivingRifleActions
		{
			StartDive = "AdvePercMtacSnonWrflDfr";
			SurfaceDive = "AsdvPercMtacSnonWrflDfr";
			BottomDive = "AbdvPercMtacSnonWrflDfr";
		};
		class BottomDivingRifleActionsTacB: BottomDivingRifleActions
		{
			StartDive = "AdvePercMtacSnonWrflDb";
			SurfaceDive = "AsdvPercMtacSnonWrflDb";
			BottomDive = "AbdvPercMtacSnonWrflDb";
		};
		class BottomDivingRifleActionsTacBR: BottomDivingRifleActions
		{
			StartDive = "AdvePercMtacSnonWrflDbr";
			SurfaceDive = "AsdvPercMtacSnonWrflDbr";
			BottomDive = "AbdvPercMtacSnonWrflDbr";
		};
		class BottomDivingRifleActionsTacBL: BottomDivingRifleActions
		{
			StartDive = "AdvePercMtacSnonWrflDbl";
			SurfaceDive = "AsdvPercMtacSnonWrflDbl";
			BottomDive = "AbdvPercMtacSnonWrflDbl";
		};
		class BottomDivingRifleActionsTacL: BottomDivingRifleActions
		{
			StartDive = "AdvePercMtacSnonWrflDl";
			SurfaceDive = "AsdvPercMtacSnonWrflDl";
			BottomDive = "AbdvPercMtacSnonWrflDl";
		};
		class BottomDivingRifleActionsTacR: BottomDivingRifleActions
		{
			StartDive = "AdvePercMtacSnonWrflDr";
			SurfaceDive = "AsdvPercMtacSnonWrflDr";
			BottomDive = "AbdvPercMtacSnonWrflDr";
		};
		class BinocStandActions: RifleStandActions
		{
			gestureGo[] = {"GestureGoBStand","Gesture"};
			binocOn = "";
			putDown = "AmovPercMstpSoptWbinDnon_AinvPercMstpSoptWbinDnon_Putdown";
			down = "AmovPpneMstpSoptWbinDnon";
			up = "AmovPknlMstpSoptWbinDnon";
			stop = "AmovPercMstpSoptWbinDnon";
			stopRelaxed = "AmovPercMstpSoptWbinDnon";
			default = "AmovPercMstpSoptWbinDnon";
			PlayerStand = "AmovPercMstpSoptWbinDnon";
			PlayerCrouch = "AmovPknlMstpSoptWbinDnon";
			PlayerProne = "AmovPpneMstpSoptWbinDnon";
			upDegree = "ManPosBinocStand";
			TurnL = "AmovPercMstpSoptWbinDnon_turnL";
			TurnR = "AmovPercMstpSoptWbinDnon_turnR";
			TurnLRelaxed = "AmovPercMstpSoptWbinDnon_turnL";
			TurnRRelaxed = "AmovPercMstpSoptWbinDnon_turnR";
			WalkF = "AmovPercMwlkSoptWbinDf";
			WalkLF = "AmovPercMwlkSoptWbinDfl";
			WalkRF = "AmovPercMwlkSoptWbinDfr";
			WalkL = "AmovPercMwlkSoptWbinDl";
			WalkR = "AmovPercMwlkSoptWbinDr";
			WalkLB = "AmovPercMwlkSoptWbinDbl";
			WalkRB = "AmovPercMwlkSoptWbinDbr";
			WalkB = "AmovPercMwlkSoptWbinDb";
			PlayerWalkF = "AmovPercMwlkSoptWbinDf";
			PlayerWalkLF = "AmovPercMwlkSoptWbinDfl";
			PlayerWalkRF = "AmovPercMwlkSoptWbinDfr";
			PlayerWalkL = "AmovPercMwlkSoptWbinDl";
			PlayerWalkR = "AmovPercMwlkSoptWbinDr";
			PlayerWalkLB = "AmovPercMwlkSoptWbinDbl";
			PlayerWalkRB = "AmovPercMwlkSoptWbinDbr";
			PlayerWalkB = "AmovPercMwlkSoptWbinDb";
			SlowF = "AmovPercMrunSnonWbinDf";
			SlowLF = "AmovPercMrunSnonWbinDfl";
			SlowRF = "AmovPercMrunSnonWbinDfr";
			SlowL = "AmovPercMrunSnonWbinDl";
			SlowR = "AmovPercMrunSnonWbinDr";
			SlowLB = "AmovPercMrunSnonWbinDbl";
			SlowRB = "AmovPercMrunSnonWbinDbr";
			SlowB = "AmovPercMrunSnonWbinDb";
			PlayerSlowF = "AmovPercMrunSnonWbinDf";
			PlayerSlowLF = "AmovPercMrunSnonWbinDfl";
			PlayerSlowRF = "AmovPercMrunSnonWbinDfr";
			PlayerSlowL = "AmovPercMrunSnonWbinDl";
			PlayerSlowR = "AmovPercMrunSnonWbinDr";
			PlayerSlowLB = "AmovPercMrunSnonWbinDbl";
			PlayerSlowRB = "AmovPercMrunSnonWbinDbr";
			PlayerSlowB = "AmovPercMrunSnonWbinDb";
			FastF = "AmovPercMevaSnonWbinDf";
			FastLF = "AmovPercMevaSnonWbinDfl";
			FastRF = "AmovPercMevaSnonWbinDfr";
			FastL = "AmovPercMrunSnonWbinDl";
			FastR = "AmovPercMrunSnonWbinDr";
			FastLB = "AmovPercMrunSnonWbinDbl";
			FastRB = "AmovPercMrunSnonWbinDbr";
			FastB = "AmovPercMrunSnonWbinDb";
			TactF = "AmovPercMwlkSoptWbinDf";
			TactLF = "AmovPercMwlkSoptWbinDfl";
			TactRF = "AmovPercMwlkSoptWbinDfr";
			TactL = "AmovPercMwlkSoptWbinDl";
			TactR = "AmovPercMwlkSoptWbinDr";
			TactLB = "AmovPercMwlkSoptWbinDbl";
			TactRB = "AmovPercMwlkSoptWbinDbr";
			TactB = "AmovPercMwlkSoptWbinDb";
			PlayerTactF = "AmovPercMwlkSoptWbinDf";
			PlayerTactLF = "AmovPercMwlkSoptWbinDfl";
			PlayerTactRF = "AmovPercMwlkSoptWbinDfr";
			PlayerTactL = "AmovPercMwlkSoptWbinDl";
			PlayerTactR = "AmovPercMwlkSoptWbinDr";
			PlayerTactLB = "AmovPercMwlkSoptWbinDbl";
			PlayerTactRB = "AmovPercMwlkSoptWbinDbr";
			PlayerTactB = "AmovPercMwlkSoptWbinDb";
			EvasiveRight = "";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
			Diary = "";
			Gear = "";
			GetOver = "AovrPercMstpSoptWbinDf";
		};
		class BinocStandActionsWlkF: BinocStandActions
		{
			PlayerCrouch = "AmovPknlMwlkSoptWbinDf";
			up = "AmovPknlMwlkSoptWbinDf";
		};
		class BinocStandActionsWlkFL: BinocStandActions
		{
			PlayerCrouch = "AmovPknlMwlkSoptWbinDfl";
			up = "AmovPknlMwlkSoptWbinDfl";
		};
		class BinocStandActionsWlkFR: BinocStandActions
		{
			PlayerCrouch = "AmovPknlMwlkSoptWbinDfr";
			up = "AmovPknlMwlkSoptWbinDfr";
		};
		class BinocStandActionsWlkR: BinocStandActions
		{
			PlayerCrouch = "AmovPknlMwlkSoptWbinDr";
			up = "AmovPknlMwlkSoptWbinDr";
		};
		class BinocStandActionsWlkL: BinocStandActions
		{
			PlayerCrouch = "AmovPknlMwlkSoptWbinDl";
			up = "AmovPknlMwlkSoptWbinDl";
		};
		class BinocStandActionsWlkB: BinocStandActions
		{
			PlayerCrouch = "AmovPknlMwlkSoptWbinDb";
			up = "AmovPknlMwlkSoptWbinDB";
		};
		class BinocStandActionsWlkBL: BinocStandActions
		{
			PlayerCrouch = "AmovPknlMwlkSoptWbinDbl";
			up = "AmovPknlMwlkSoptWbinDbl";
		};
		class BinocStandActionsWlkBR: BinocStandActions
		{
			PlayerCrouch = "AmovPknlMwlkSoptWbinDbr";
			up = "AmovPknlMwlkSoptWbinDbr";
		};
		class BinocStandActionsRunF: BinocStandActions
		{
			PlayerCrouch = "AmovPknlMRunSnonWbinDf";
			up = "AmovPknlMRunSnonWbinDf";
		};
		class BinocStandActionsRunFL: BinocStandActions
		{
			PlayerCrouch = "AmovPknlMRunSnonWbinDfl";
			up = "AmovPknlMRunSnonWbinDfl";
		};
		class BinocStandActionsRunFR: BinocStandActions
		{
			PlayerCrouch = "AmovPknlMRunSnonWbinDfr";
			up = "AmovPknlMRunSnonWbinDfr";
		};
		class BinocStandActionsRunR: BinocStandActions
		{
			PlayerCrouch = "AmovPknlMRunSnonWbinDr";
			up = "AmovPknlMRunSnonWbinDr";
		};
		class BinocStandActionsRunL: BinocStandActions
		{
			PlayerCrouch = "AmovPknlMRunSnonWbinDl";
			up = "AmovPknlMRunSnonWbinDl";
		};
		class BinocStandActionsRunB: BinocStandActions
		{
			PlayerCrouch = "AmovPknlMRunSnonWbinDb";
			up = "AmovPknlMRunSnonWbinDB";
		};
		class BinocStandActionsRunBL: BinocStandActions
		{
			PlayerCrouch = "AmovPknlMRunSnonWbinDbl";
			up = "AmovPknlMRunSnonWbinDbl";
		};
		class BinocStandActionsRunBR: BinocStandActions
		{
			PlayerCrouch = "AmovPknlMRunSnonWbinDbr";
			up = "AmovPknlMRunSnonWbinDbr";
		};
		class BinocStandActionsEvasiveF: BinocStandActions
		{
			PlayerCrouch = "AmovPknlMevaSnonWbinDf";
			up = "AmovPknlMevaSnonWbinDf";
		};
		class BinocStandActionsEvasiveFL: BinocStandActions
		{
			PlayerCrouch = "AmovPknlMevaSnonWbinDfl";
			up = "AmovPknlMevaSnonWbinDfl";
		};
		class BinocStandActionsEvasiveFR: BinocStandActions
		{
			PlayerCrouch = "AmovPknlMevaSnonWbinDfr";
			up = "AmovPknlMevaSnonWbinDfr";
		};
		class BinocKneelActions: RifleKneelActions
		{
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
			binocOn = "";
			down = "AmovPpneMstpSoptWbinDnon";
			up = "AmovPercMstpSoptWbinDnon";
			putDown = "AmovPknlMstpSoptWbinDnon_AinvPknlMstpSoptWbinDnon_Putdown";
			stop = "AmovPknlMstpSoptWbinDnon";
			stopRelaxed = "AmovPknlMstpSoptWbinDnon";
			default = "AmovPknlMstpSoptWbinDnon";
			PlayerStand = "AmovPercMstpSoptWbinDnon";
			PlayerCrouch = "AmovPknlMstpSoptWbinDnon";
			PlayerProne = "AmovPpneMstpSoptWbinDnon";
			upDegree = "ManPosBinoc";
			TurnL = "AmovPknlMstpSoptWbinDnon_turnL";
			TurnR = "AmovPknlMstpSoptWbinDnon_turnR";
			TurnLRelaxed = "AmovPknlMstpSoptWbinDnon_turnL";
			TurnRRelaxed = "AmovPknlMstpSoptWbinDnon_turnR";
			WalkF = "AmovPknlMwlkSoptWbinDf";
			WalkLF = "AmovPknlMwlkSoptWbinDfl";
			WalkRF = "AmovPknlMwlkSoptWbinDfr";
			WalkL = "AmovPknlMwlkSoptWbinDl";
			WalkR = "AmovPknlMwlkSoptWbinDr";
			WalkLB = "AmovPknlMwlkSoptWbinDbl";
			WalkRB = "AmovPknlMwlkSoptWbinDbr";
			WalkB = "AmovPknlMwlkSoptWbinDb";
			PlayerWalkF = "AmovPknlMwlkSoptWbinDf";
			PlayerWalkLF = "AmovPknlMwlkSoptWbinDfl";
			PlayerWalkRF = "AmovPknlMwlkSoptWbinDfr";
			PlayerWalkL = "AmovPknlMwlkSoptWbinDl";
			PlayerWalkR = "AmovPknlMwlkSoptWbinDr";
			PlayerWalkLB = "AmovPknlMwlkSoptWbinDbl";
			PlayerWalkRB = "AmovPknlMwlkSoptWbinDbr";
			PlayerWalkB = "AmovPknlMwlkSoptWbinDb";
			SlowF = "AmovPknlMrunSnonWbinDf";
			SlowLF = "AmovPknlMrunSnonWbinDfl";
			SlowRF = "AmovPknlMrunSnonWbinDfr";
			SlowL = "AmovPknlMrunSnonWbinDl";
			SlowR = "AmovPknlMrunSnonWbinDr";
			SlowLB = "AmovPknlMrunSnonWbinDbl";
			SlowRB = "AmovPknlMrunSnonWbinDbr";
			SlowB = "AmovPknlMrunSnonWbinDb";
			PlayerSlowF = "AmovPknlMrunSnonWbinDf";
			PlayerSlowLF = "AmovPknlMrunSnonWbinDfl";
			PlayerSlowRF = "AmovPknlMrunSnonWbinDfr";
			PlayerSlowL = "AmovPknlMrunSnonWbinDl";
			PlayerSlowR = "AmovPknlMrunSnonWbinDr";
			PlayerSlowLB = "AmovPknlMrunSnonWbinDbl";
			PlayerSlowRB = "AmovPknlMrunSnonWbinDbr";
			PlayerSlowB = "AmovPknlMrunSnonWbinDb";
			FastF = "AmovPknlMevaSnonWbinDf";
			FastLF = "AmovPknlMevaSnonWbinDfl";
			FastRF = "AmovPknlMevaSnonWbinDfr";
			FastL = "AmovPknlMrunSnonWbinDl";
			FastR = "AmovPknlMrunSnonWbinDr";
			FastLB = "AmovPknlMrunSnonWbinDbl";
			FastRB = "AmovPknlMrunSnonWbinDbr";
			FastB = "AmovPknlMrunSnonWbinDb";
			TactF = "AmovPknlMwlkSoptWbinDf";
			TactLF = "AmovPknlMwlkSoptWbinDfl";
			TactRF = "AmovPknlMwlkSoptWbinDfr";
			TactL = "AmovPknlMwlkSoptWbinDl";
			TactR = "AmovPknlMwlkSoptWbinDr";
			TactLB = "AmovPknlMwlkSoptWbinDbl";
			TactRB = "AmovPknlMwlkSoptWbinDbr";
			TactB = "AmovPknlMwlkSoptWbinDb";
			PlayerTactF = "AmovPknlMwlkSoptWbinDf";
			PlayerTactLF = "AmovPknlMwlkSoptWbinDfl";
			PlayerTactRF = "AmovPknlMwlkSoptWbinDfr";
			PlayerTactL = "AmovPknlMwlkSoptWbinDl";
			PlayerTactR = "AmovPknlMwlkSoptWbinDr";
			PlayerTactLB = "AmovPknlMwlkSoptWbinDbl";
			PlayerTactRB = "AmovPknlMwlkSoptWbinDbr";
			PlayerTactB = "AmovPknlMwlkSoptWbinDb";
			EvasiveRight = "";
			EvasiveLeft = "";
			Diary = "";
			Gear = "";
		};
		class BinocKneelActionsWlkF: BinocKneelActions
		{
			PlayerCrouch = "AmovPercMwlkSoptWbinDf";
			up = "AmovPercMwlkSoptWbinDf";
		};
		class BinocKneelActionsWlkFL: BinocKneelActions
		{
			PlayerCrouch = "AmovPercMwlkSoptWbinDfl";
			up = "AmovPercMwlkSoptWbinDfl";
		};
		class BinocKneelActionsWlkFR: BinocKneelActions
		{
			PlayerCrouch = "AmovPercMwlkSoptWbinDfr";
			up = "AmovPercMwlkSoptWbinDfr";
		};
		class BinocKneelActionsWlkR: BinocKneelActions
		{
			PlayerCrouch = "AmovPercMwlkSoptWbinDr";
			up = "AmovPercMwlkSoptWbinDr";
		};
		class BinocKneelActionsWlkL: BinocKneelActions
		{
			PlayerCrouch = "AmovPercMwlkSoptWbinDl";
			up = "AmovPercMwlkSoptWbinDl";
		};
		class BinocKneelActionsWlkB: BinocKneelActions
		{
			PlayerCrouch = "AmovPercMwlkSoptWbinDb";
			up = "AmovPercMwlkSoptWbinDB";
		};
		class BinocKneelActionsWlkBL: BinocKneelActions
		{
			PlayerCrouch = "AmovPercMwlkSoptWbinDbl";
			up = "AmovPercMwlkSoptWbinDbl";
		};
		class BinocKneelActionsWlkBR: BinocKneelActions
		{
			PlayerCrouch = "AmovPercMwlkSoptWbinDbr";
			up = "AmovPercMwlkSoptWbinDbr";
		};
		class BinocKneelActionsRunF: BinocKneelActions
		{
			PlayerCrouch = "AmovPercMRunSnonWbinDf";
			up = "AmovPercMRunSnonWbinDf";
		};
		class BinocKneelActionsRunFL: BinocKneelActions
		{
			PlayerCrouch = "AmovPercMRunSnonWbinDfl";
			up = "AmovPercMRunSnonWbinDfl";
		};
		class BinocKneelActionsRunFR: BinocKneelActions
		{
			PlayerCrouch = "AmovPercMRunSnonWbinDfr";
			up = "AmovPercMRunSnonWbinDfr";
		};
		class BinocKneelActionsRunR: BinocKneelActions
		{
			PlayerCrouch = "AmovPercMRunSnonWbinDr";
			up = "AmovPercMRunSnonWbinDr";
		};
		class BinocKneelActionsRunL: BinocKneelActions
		{
			PlayerCrouch = "AmovPercMRunSnonWbinDl";
			up = "AmovPercMRunSnonWbinDl";
		};
		class BinocKneelActionsRunB: BinocKneelActions
		{
			PlayerCrouch = "AmovPercMRunSnonWbinDb";
			up = "AmovPercMRunSnonWbinDB";
		};
		class BinocKneelActionsRunBL: BinocKneelActions
		{
			PlayerCrouch = "AmovPercMRunSnonWbinDbl";
			up = "AmovPercMRunSnonWbinDbl";
		};
		class BinocKneelActionsRunBR: BinocKneelActions
		{
			PlayerCrouch = "AmovPercMRunSnonWbinDbr";
			up = "AmovPercMRunSnonWbinDbr";
		};
		class BinocKneelActionsEvasiveF: BinocKneelActions
		{
			PlayerCrouch = "AmovPercMevaSnonWbinDf";
			up = "AmovPercMevaSnonWbinDf";
		};
		class BinocKneelActionsEvasiveFL: BinocKneelActions
		{
			PlayerCrouch = "AmovPercMevaSnonWbinDfl";
			up = "AmovPercMevaSnonWbinDfl";
		};
		class BinocKneelActionsEvasiveFR: BinocKneelActions
		{
			PlayerCrouch = "AmovPercMevaSnonWbinDfr";
			up = "AmovPercMevaSnonWbinDfr";
		};
		class BinocProneActions: RifleProneActions
		{
			AdjustF = "";
			AdjustB = "";
			AdjustLF = "";
			AdjustLB = "";
			AdjustRF = "";
			AdjustRB = "";
			AdjustR = "";
			AdjustL = "";
			binocOn = "";
			stop = "AmovPpneMstpSoptWbinDnon";
			stopRelaxed = "AmovPpneMstpSoptWbinDnon";
			default = "AmovPpneMstpSoptWbinDnon";
			PlayerStand = "AmovPercMstpSoptWbinDnon";
			PlayerCrouch = "AmovPknlMstpSoptWbinDnon";
			PlayerProne = "AmovPpneMstpSoptWbinDnon";
			upDegree = "ManPosBinocLying";
			putDown = "AmovPpneMstpSoptWbinDnon_AinvPpneMstpSoptWbinDnon_Putdown";
			down = "AmovPercMstpSoptWbinDnon";
			up = "AmovPknlMstpSoptWbinDnon";
			TurnL = "AmovPpneMstpSoptWbinDnon_turnL";
			TurnR = "AmovPpneMstpSoptWbinDnon_turnR";
			TurnLRelaxed = "AmovPpneMstpSoptWbinDnon_turnL";
			TurnRRelaxed = "AmovPpneMstpSoptWbinDnon_turnR";
			WalkF = "AmovPpneMwlkSoptWbinDf";
			WalkLF = "AmovPpneMwlkSoptWbinDfl";
			WalkRF = "AmovPpneMwlkSoptWbinDfr";
			WalkL = "AmovPpneMwlkSoptWbinDl";
			WalkR = "AmovPpneMwlkSoptWbinDr";
			WalkLB = "AmovPpneMwlkSoptWbinDbl";
			WalkRB = "AmovPpneMwlkSoptWbinDbr";
			WalkB = "AmovPpneMwlkSoptWbinDb";
			PlayerWalkF = "AmovPpneMwlkSoptWbinDf";
			PlayerWalkLF = "AmovPpneMwlkSoptWbinDfl";
			PlayerWalkRF = "AmovPpneMwlkSoptWbinDfr";
			PlayerWalkL = "AmovPpneMwlkSoptWbinDl";
			PlayerWalkR = "AmovPpneMwlkSoptWbinDr";
			PlayerWalkLB = "AmovPpneMwlkSoptWbinDbl";
			PlayerWalkRB = "AmovPpneMwlkSoptWbinDbr";
			PlayerWalkB = "AmovPpneMwlkSoptWbinDb";
			SlowF = "AmovPpneMrunSnonWbinDf";
			SlowLF = "AmovPpneMrunSnonWbinDfl";
			SlowRF = "AmovPpneMrunSnonWbinDfr";
			SlowL = "AmovPpneMrunSnonWbinDl";
			SlowR = "AmovPpneMrunSnonWbinDr";
			SlowLB = "AmovPpneMrunSnonWbinDbl";
			SlowRB = "AmovPpneMrunSnonWbinDbr";
			SlowB = "AmovPpneMrunSnonWbinDb";
			PlayerSlowF = "AmovPpneMrunSnonWbinDf";
			PlayerSlowLF = "AmovPpneMrunSnonWbinDfl";
			PlayerSlowRF = "AmovPpneMrunSnonWbinDfr";
			PlayerSlowL = "AmovPpneMrunSnonWbinDl";
			PlayerSlowR = "AmovPpneMrunSnonWbinDr";
			PlayerSlowLB = "AmovPpneMrunSnonWbinDbl";
			PlayerSlowRB = "AmovPpneMrunSnonWbinDbr";
			PlayerSlowB = "AmovPpneMrunSnonWbinDb";
			FastF = "AmovPpneMevaSnonWbinDf";
			FastLF = "AmovPpneMrunSnonWbinDfl";
			FastRF = "AmovPpneMrunSnonWbinDfr";
			FastL = "AmovPpneMrunSnonWbinDl";
			FastR = "AmovPpneMrunSnonWbinDr";
			FastLB = "AmovPpneMrunSnonWbinDbl";
			FastRB = "AmovPpneMrunSnonWbinDbr";
			FastB = "AmovPpneMrunSnonWbinDb";
			TactF = "AmovPpneMwlkSoptWbinDf";
			TactLF = "AmovPpneMwlkSoptWbinDfl";
			TactRF = "AmovPpneMwlkSoptWbinDfr";
			TactL = "AmovPpneMwlkSoptWbinDl";
			TactR = "AmovPpneMwlkSoptWbinDr";
			TactLB = "AmovPpneMwlkSoptWbinDbl";
			TactRB = "AmovPpneMwlkSoptWbinDbr";
			TactB = "AmovPpneMwlkSoptWbinDb";
			PlayerTactF = "AmovPpneMwlkSoptWbinDf";
			PlayerTactLF = "AmovPpneMwlkSoptWbinDfl";
			PlayerTactRF = "AmovPpneMwlkSoptWbinDfr";
			PlayerTactL = "AmovPpneMwlkSoptWbinDl";
			PlayerTactR = "AmovPpneMwlkSoptWbinDr";
			PlayerTactLB = "AmovPpneMwlkSoptWbinDbl";
			PlayerTactRB = "AmovPpneMwlkSoptWbinDbr";
			PlayerTactB = "AmovPpneMwlkSoptWbinDb";
			EvasiveRight = "AmovPpneMstpSoptWbinDnon_AmovPpneMevaSoptWbinDr";
			EvasiveLeft = "AmovPpneMstpSoptWbinDnon_AmovPpneMevaSoptWbinDl";
		};
		class BinocProneActionsWlkF: BinocProneActions{};
		class BinocProneActionsWlkFL: BinocProneActions{};
		class BinocProneActionsWlkFR: BinocProneActions{};
		class BinocProneActionsWlkR: BinocProneActions{};
		class BinocProneActionsWlkL: BinocProneActions{};
		class BinocProneActionsWlkB: BinocProneActions{};
		class BinocProneActionsWlkBL: BinocProneActions{};
		class BinocProneActionsWlkBR: BinocProneActions{};
		class BinocProneActionsRunF: BinocProneActions{};
		class BinocProneActionsRunFL: BinocProneActions{};
		class BinocProneActionsRunFR: BinocProneActions{};
		class BinocProneActionsRunR: BinocProneActions{};
		class BinocProneActionsRunL: BinocProneActions{};
		class BinocProneActionsRunB: BinocProneActions{};
		class BinocProneActionsRunBL: BinocProneActions{};
		class BinocProneActionsRunBR: BinocProneActions{};
		class BinocProneActionsEvasiveF: BinocProneActions{};
		class BinocStandRflActions: RifleStandActions
		{
			gestureGo[] = {"GestureGoBStand","Gesture"};
			binocOn = "";
			down = "AwopPpneMstpSoptWbinDnon_rfl";
			up = "AwopPknlMstpSoptWbinDnon_rfl";
			stop = "AwopPercMstpSoptWbinDnon_rfl";
			stopRelaxed = "AwopPercMstpSoptWbinDnon_rfl";
			default = "AwopPercMstpSoptWbinDnon_rfl";
			PlayerStand = "AwopPercMstpSoptWbinDnon_rfl";
			PlayerCrouch = "AwopPknlMstpSoptWbinDnon_rfl";
			PlayerProne = "AwopPpneMstpSoptWbinDnon_rfl";
			upDegree = "ManPosBinocStand";
			TurnL = "AwopPercMstpSoptWbinDnon_rfl_turnL";
			TurnR = "AwopPercMstpSoptWbinDnon_rfl_turnR";
			TurnLRelaxed = "AwopPercMstpSoptWbinDnon_rfl_turnL";
			TurnRRelaxed = "AwopPercMstpSoptWbinDnon_rfl_turnR";
			WalkF = "AmovPercMwlkSoptWbinDf_rfl";
			WalkLF = "AmovPercMwlkSoptWbinDfl_rfl";
			WalkRF = "AmovPercMwlkSoptWbinDfr_rfl";
			WalkL = "AmovPercMwlkSoptWbinDl_rfl";
			WalkR = "AmovPercMwlkSoptWbinDr_rfl";
			WalkLB = "AmovPercMwlkSoptWbinDbl_rfl";
			WalkRB = "AmovPercMwlkSoptWbinDbr_rfl";
			WalkB = "AmovPercMwlkSoptWbinDb_rfl";
			PlayerWalkF = "AmovPercMwlkSoptWbinDf_rfl";
			PlayerWalkLF = "AmovPercMwlkSoptWbinDfl_rfl";
			PlayerWalkRF = "AmovPercMwlkSoptWbinDfr_rfl";
			PlayerWalkL = "AmovPercMwlkSoptWbinDl_rfl";
			PlayerWalkR = "AmovPercMwlkSoptWbinDr_rfl";
			PlayerWalkLB = "AmovPercMwlkSoptWbinDbl_rfl";
			PlayerWalkRB = "AmovPercMwlkSoptWbinDbr_rfl";
			PlayerWalkB = "AmovPercMwlkSoptWbinDb_rfl";
			SlowF = "AmovPercMrunSnonWbinDf_rfl";
			SlowLF = "AmovPercMrunSnonWbinDfl_rfl";
			SlowRF = "AmovPercMrunSnonWbinDfr_rfl";
			SlowL = "AmovPercMrunSnonWbinDl_rfl";
			SlowR = "AmovPercMrunSnonWbinDr_rfl";
			SlowLB = "AmovPercMrunSnonWbinDbl_rfl";
			SlowRB = "AmovPercMrunSnonWbinDbr_rfl";
			SlowB = "AmovPercMrunSnonWbinDb_rfl";
			PlayerSlowF = "AmovPercMrunSnonWbinDf_rfl";
			PlayerSlowLF = "AmovPercMrunSnonWbinDfl_rfl";
			PlayerSlowRF = "AmovPercMrunSnonWbinDfr_rfl";
			PlayerSlowL = "AmovPercMrunSnonWbinDl_rfl";
			PlayerSlowR = "AmovPercMrunSnonWbinDr_rfl";
			PlayerSlowLB = "AmovPercMrunSnonWbinDbl_rfl";
			PlayerSlowRB = "AmovPercMrunSnonWbinDbr_rfl";
			PlayerSlowB = "AmovPercMrunSnonWbinDb_rfl";
			FastF = "AmovPercMevaSnonWbinDf_rfl";
			FastLF = "AmovPercMevaSnonWbinDfl_rfl";
			FastRF = "AmovPercMevaSnonWbinDfr_rfl";
			FastL = "AmovPercMrunSnonWbinDl_rfl";
			FastR = "AmovPercMrunSnonWbinDr_rfl";
			FastLB = "AmovPercMrunSnonWbinDbl_rfl";
			FastRB = "AmovPercMrunSnonWbinDbr_rfl";
			FastB = "AmovPercMrunSnonWbinDb_rfl";
			TactF = "AmovPercMwlkSoptWbinDf_rfl";
			TactLF = "AmovPercMwlkSoptWbinDfl_rfl";
			TactRF = "AmovPercMwlkSoptWbinDfr_rfl";
			TactL = "AmovPercMwlkSoptWbinDl_rfl";
			TactR = "AmovPercMwlkSoptWbinDr_rfl";
			TactLB = "AmovPercMwlkSoptWbinDbl_rfl";
			TactRB = "AmovPercMwlkSoptWbinDbr_rfl";
			TactB = "AmovPercMwlkSoptWbinDb_rfl";
			PlayerTactF = "AmovPercMwlkSoptWbinDf_rfl";
			PlayerTactLF = "AmovPercMwlkSoptWbinDfl_rfl";
			PlayerTactRF = "AmovPercMwlkSoptWbinDfr_rfl";
			PlayerTactL = "AmovPercMwlkSoptWbinDl_rfl";
			PlayerTactR = "AmovPercMwlkSoptWbinDr_rfl";
			PlayerTactLB = "AmovPercMwlkSoptWbinDbl_rfl";
			PlayerTactRB = "AmovPercMwlkSoptWbinDbr_rfl";
			PlayerTactB = "AmovPercMwlkSoptWbinDb_rfl";
			EvasiveRight = "";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
			Diary = "";
			Gear = "";
			GetOver = "";
		};
		class BinocStandRflActionsWlkF: BinocStandRflActions
		{
			PlayerCrouch = "AmovPknlMwlkSoptWbinDf_rfl";
			up = "AmovPknlMwlkSoptWbinDf_rfl";
		};
		class BinocStandRflActionsWlkFL: BinocStandRflActions
		{
			PlayerCrouch = "AmovPknlMwlkSoptWbinDfl_rfl";
			up = "AmovPknlMwlkSoptWbinDfl_rfl";
		};
		class BinocStandRflActionsWlkFR: BinocStandRflActions
		{
			PlayerCrouch = "AmovPknlMwlkSoptWbinDfr_rfl";
			up = "AmovPknlMwlkSoptWbinDfr_rfl";
		};
		class BinocStandRflActionsWlkR: BinocStandRflActions
		{
			PlayerCrouch = "AmovPknlMwlkSoptWbinDr_rfl";
			up = "AmovPknlMwlkSoptWbinDr_rfl";
		};
		class BinocStandRflActionsWlkL: BinocStandRflActions
		{
			PlayerCrouch = "AmovPknlMwlkSoptWbinDl_rfl";
			up = "AmovPknlMwlkSoptWbinDl_rfl";
		};
		class BinocStandRflActionsWlkB: BinocStandRflActions
		{
			PlayerCrouch = "AmovPknlMwlkSoptWbinDb_rfl";
			up = "AmovPknlMwlkSoptWbinDB_rfl";
		};
		class BinocStandRflActionsWlkBL: BinocStandRflActions
		{
			PlayerCrouch = "AmovPknlMwlkSoptWbinDbl_rfl";
			up = "AmovPknlMwlkSoptWbinDbl_rfl";
		};
		class BinocStandRflActionsWlkBR: BinocStandRflActions
		{
			PlayerCrouch = "AmovPknlMwlkSoptWbinDbr_rfl";
			up = "AmovPknlMwlkSoptWbinDbr_rfl";
		};
		class BinocStandRflActionsRunF: BinocStandRflActions
		{
			PlayerCrouch = "AmovPknlMRunSnonWbinDf_rfl";
			up = "AmovPknlMRunSnonWbinDf_rfl";
		};
		class BinocStandRflActionsRunFL: BinocStandRflActions
		{
			PlayerCrouch = "AmovPknlMRunSnonWbinDfl_rfl";
			up = "AmovPknlMRunSnonWbinDfl_rfl";
		};
		class BinocStandRflActionsRunFR: BinocStandRflActions
		{
			PlayerCrouch = "AmovPknlMRunSnonWbinDfr_rfl";
			up = "AmovPknlMRunSnonWbinDfr_rfl";
		};
		class BinocStandRflActionsRunR: BinocStandRflActions
		{
			PlayerCrouch = "AmovPknlMRunSnonWbinDr_rfl";
			up = "AmovPknlMRunSnonWbinDr_rfl";
		};
		class BinocStandRflActionsRunL: BinocStandRflActions
		{
			PlayerCrouch = "AmovPknlMRunSnonWbinDl_rfl";
			up = "AmovPknlMRunSnonWbinDl_rfl";
		};
		class BinocStandRflActionsRunB: BinocStandRflActions
		{
			PlayerCrouch = "AmovPknlMRunSnonWbinDb_rfl";
			up = "AmovPknlMRunSnonWbinDB_rfl";
		};
		class BinocStandRflActionsRunBL: BinocStandRflActions
		{
			PlayerCrouch = "AmovPknlMRunSnonWbinDbl_rfl";
			up = "AmovPknlMRunSnonWbinDbl_rfl";
		};
		class BinocStandRflActionsRunBR: BinocStandRflActions
		{
			PlayerCrouch = "AmovPknlMRunSnonWbinDbr_rfl";
			up = "AmovPknlMRunSnonWbinDbr_rfl";
		};
		class BinocStandRflActionsEvasiveF: BinocStandRflActions
		{
			PlayerCrouch = "AmovPknlMevaSnonWbinDf_rfl";
			up = "AmovPknlMevaSnonWbinDf_rfl";
		};
		class BinocStandRflActionsEvasiveFL: BinocStandRflActions
		{
			PlayerCrouch = "AmovPknlMevaSnonWbinDfl_rfl";
			up = "AmovPknlMevaSnonWbinDfl_rfl";
		};
		class BinocStandRflActionsEvasiveFR: BinocStandRflActions
		{
			PlayerCrouch = "AmovPknlMevaSnonWbinDfr_rfl";
			up = "AmovPknlMevaSnonWbinDfr_rfl";
		};
		class BinocKneelRflActions: RifleKneelActions
		{
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
			binocOn = "";
			down = "AwopPpneMstpSoptWbinDnon_rfl";
			up = "AwopPercMstpSoptWbinDnon_rfl";
			stop = "AwopPknlMstpSoptWbinDnon_rfl";
			stopRelaxed = "AwopPknlMstpSoptWbinDnon_rfl";
			default = "AwopPknlMstpSoptWbinDnon_rfl";
			PlayerStand = "AwopPercMstpSoptWbinDnon_rfl";
			PlayerCrouch = "AwopPknlMstpSoptWbinDnon_rfl";
			PlayerProne = "AwopPpneMstpSoptWbinDnon_rfl";
			upDegree = "ManPosBinoc";
			TurnL = "AwopPknlMstpSoptWbinDnon_rfl_turnL";
			TurnR = "AwopPknlMstpSoptWbinDnon_rfl_turnR";
			TurnLRelaxed = "AwopPknlMstpSoptWbinDnon_rfl_turnL";
			TurnRRelaxed = "AwopPknlMstpSoptWbinDnon_rfl_turnR";
			WalkF = "AmovPknlMwlkSoptWbinDf_rfl";
			WalkLF = "AmovPknlMwlkSoptWbinDfl_rfl";
			WalkRF = "AmovPknlMwlkSoptWbinDfr_rfl";
			WalkL = "AmovPknlMwlkSoptWbinDl_rfl";
			WalkR = "AmovPknlMwlkSoptWbinDr_rfl";
			WalkLB = "AmovPknlMwlkSoptWbinDbl_rfl";
			WalkRB = "AmovPknlMwlkSoptWbinDbr_rfl";
			WalkB = "AmovPknlMwlkSoptWbinDb_rfl";
			PlayerWalkF = "AmovPknlMwlkSoptWbinDf_rfl";
			PlayerWalkLF = "AmovPknlMwlkSoptWbinDfl_rfl";
			PlayerWalkRF = "AmovPknlMwlkSoptWbinDfr_rfl";
			PlayerWalkL = "AmovPknlMwlkSoptWbinDl_rfl";
			PlayerWalkR = "AmovPknlMwlkSoptWbinDr_rfl";
			PlayerWalkLB = "AmovPknlMwlkSoptWbinDbl_rfl";
			PlayerWalkRB = "AmovPknlMwlkSoptWbinDbr_rfl";
			PlayerWalkB = "AmovPknlMwlkSoptWbinDb_rfl";
			SlowF = "AmovPknlMrunSnonWbinDf_rfl";
			SlowLF = "AmovPknlMrunSnonWbinDfl_rfl";
			SlowRF = "AmovPknlMrunSnonWbinDfr_rfl";
			SlowL = "AmovPknlMrunSnonWbinDl_rfl";
			SlowR = "AmovPknlMrunSnonWbinDr_rfl";
			SlowLB = "AmovPknlMrunSnonWbinDbl_rfl";
			SlowRB = "AmovPknlMrunSnonWbinDbr_rfl";
			SlowB = "AmovPknlMrunSnonWbinDb_rfl";
			PlayerSlowF = "AmovPknlMrunSnonWbinDf_rfl";
			PlayerSlowLF = "AmovPknlMrunSnonWbinDfl_rfl";
			PlayerSlowRF = "AmovPknlMrunSnonWbinDfr_rfl";
			PlayerSlowL = "AmovPknlMrunSnonWbinDl_rfl";
			PlayerSlowR = "AmovPknlMrunSnonWbinDr_rfl";
			PlayerSlowLB = "AmovPknlMrunSnonWbinDbl_rfl";
			PlayerSlowRB = "AmovPknlMrunSnonWbinDbr_rfl";
			PlayerSlowB = "AmovPknlMrunSnonWbinDb_rfl";
			FastF = "AmovPknlMevaSnonWbinDf_rfl";
			FastLF = "AmovPknlMevaSnonWbinDfl_rfl";
			FastRF = "AmovPknlMevaSnonWbinDfr_rfl";
			FastL = "AmovPknlMrunSnonWbinDl_rfl";
			FastR = "AmovPknlMrunSnonWbinDr_rfl";
			FastLB = "AmovPknlMrunSnonWbinDbl_rfl";
			FastRB = "AmovPknlMrunSnonWbinDbr_rfl";
			FastB = "AmovPknlMrunSnonWbinDb_rfl";
			TactF = "AmovPknlMwlkSoptWbinDf_rfl";
			TactLF = "AmovPknlMwlkSoptWbinDfl_rfl";
			TactRF = "AmovPknlMwlkSoptWbinDfr_rfl";
			TactL = "AmovPknlMwlkSoptWbinDl_rfl";
			TactR = "AmovPknlMwlkSoptWbinDr_rfl";
			TactLB = "AmovPknlMwlkSoptWbinDbl_rfl";
			TactRB = "AmovPknlMwlkSoptWbinDbr_rfl";
			TactB = "AmovPknlMwlkSoptWbinDb_rfl";
			PlayerTactF = "AmovPknlMwlkSoptWbinDf_rfl";
			PlayerTactLF = "AmovPknlMwlkSoptWbinDfl_rfl";
			PlayerTactRF = "AmovPknlMwlkSoptWbinDfr_rfl";
			PlayerTactL = "AmovPknlMwlkSoptWbinDl_rfl";
			PlayerTactR = "AmovPknlMwlkSoptWbinDr_rfl";
			PlayerTactLB = "AmovPknlMwlkSoptWbinDbl_rfl";
			PlayerTactRB = "AmovPknlMwlkSoptWbinDbr_rfl";
			PlayerTactB = "AmovPknlMwlkSoptWbinDb_rfl";
			EvasiveRight = "";
			EvasiveLeft = "";
			Diary = "";
			Gear = "";
		};
		class BinocKneelRflActionsWlkF: BinocKneelRflActions
		{
			PlayerCrouch = "AmovPercMwlkSoptWbinDf_rfl";
			up = "AmovPercMwlkSoptWbinDf_rfl";
		};
		class BinocKneelRflActionsWlkFL: BinocKneelRflActions
		{
			PlayerCrouch = "AmovPercMwlkSoptWbinDfl_rfl";
			up = "AmovPercMwlkSoptWbinDfl_rfl";
		};
		class BinocKneelRflActionsWlkFR: BinocKneelRflActions
		{
			PlayerCrouch = "AmovPercMwlkSoptWbinDfr_rfl";
			up = "AmovPercMwlkSoptWbinDfr_rfl";
		};
		class BinocKneelRflActionsWlkR: BinocKneelRflActions
		{
			PlayerCrouch = "AmovPercMwlkSoptWbinDr_rfl";
			up = "AmovPercMwlkSoptWbinDr_rfl";
		};
		class BinocKneelRflActionsWlkL: BinocKneelRflActions
		{
			PlayerCrouch = "AmovPercMwlkSoptWbinDl_rfl";
			up = "AmovPercMwlkSoptWbinDl_rfl";
		};
		class BinocKneelRflActionsWlkB: BinocKneelRflActions
		{
			PlayerCrouch = "AmovPercMwlkSoptWbinDb_rfl";
			up = "AmovPercMwlkSoptWbinDB_rfl";
		};
		class BinocKneelRflActionsWlkBL: BinocKneelRflActions
		{
			PlayerCrouch = "AmovPercMwlkSoptWbinDbl_rfl";
			up = "AmovPercMwlkSoptWbinDbl_rfl";
		};
		class BinocKneelRflActionsWlkBR: BinocKneelRflActions
		{
			PlayerCrouch = "AmovPercMwlkSoptWbinDbr_rfl";
			up = "AmovPercMwlkSoptWbinDbr_rfl";
		};
		class BinocKneelRflActionsRunF: BinocKneelRflActions
		{
			PlayerCrouch = "AmovPercMRunSnonWbinDf_rfl";
			up = "AmovPercMRunSnonWbinDf_rfl";
		};
		class BinocKneelRflActionsRunFL: BinocKneelRflActions
		{
			PlayerCrouch = "AmovPercMRunSnonWbinDfl_rfl";
			up = "AmovPercMRunSnonWbinDfl_rfl";
		};
		class BinocKneelRflActionsRunFR: BinocKneelRflActions
		{
			PlayerCrouch = "AmovPercMRunSnonWbinDfr_rfl";
			up = "AmovPercMRunSnonWbinDfr_rfl";
		};
		class BinocKneelRflActionsRunR: BinocKneelRflActions
		{
			PlayerCrouch = "AmovPercMRunSnonWbinDr_rfl";
			up = "AmovPercMRunSnonWbinDr_rfl";
		};
		class BinocKneelRflActionsRunL: BinocKneelRflActions
		{
			PlayerCrouch = "AmovPercMRunSnonWbinDl_rfl";
			up = "AmovPercMRunSnonWbinDl_rfl";
		};
		class BinocKneelRflActionsRunB: BinocKneelRflActions
		{
			PlayerCrouch = "AmovPercMRunSnonWbinDb_rfl";
			up = "AmovPercMRunSnonWbinDB_rfl";
		};
		class BinocKneelRflActionsRunBL: BinocKneelRflActions
		{
			PlayerCrouch = "AmovPercMRunSnonWbinDbl_rfl";
			up = "AmovPercMRunSnonWbinDbl_rfl";
		};
		class BinocKneelRflActionsRunBR: BinocKneelRflActions
		{
			PlayerCrouch = "AmovPercMRunSnonWbinDbr_rfl";
			up = "AmovPercMRunSnonWbinDbr_rfl";
		};
		class BinocKneelRflActionsEvasiveF: BinocKneelRflActions
		{
			PlayerCrouch = "AmovPercMevaSnonWbinDf_rfl";
			up = "AmovPercMevaSnonWbinDf_rfl";
		};
		class BinocKneelRflActionsEvasiveFL: BinocKneelRflActions
		{
			PlayerCrouch = "AmovPercMevaSnonWbinDfl_rfl";
			up = "AmovPercMevaSnonWbinDfl_rfl";
		};
		class BinocKneelRflActionsEvasiveFR: BinocKneelRflActions
		{
			PlayerCrouch = "AmovPercMevaSnonWbinDfr_rfl";
			up = "AmovPercMevaSnonWbinDfr_rfl";
		};
		class BinocProneRflActions: RifleProneActions
		{
			AdjustF = "";
			AdjustB = "";
			binocOn = "";
			stop = "AwopPpneMstpSoptWbinDnon_rfl";
			stopRelaxed = "AwopPpneMstpSoptWbinDnon_rfl";
			default = "AwopPpneMstpSoptWbinDnon_rfl";
			PlayerStand = "AwopPercMstpSoptWbinDnon_rfl";
			PlayerCrouch = "AwopPknlMstpSoptWbinDnon_rfl";
			PlayerProne = "AwopPpneMstpSoptWbinDnon_rfl";
			upDegree = "ManPosBinocLying";
			down = "AwopPercMstpSoptWbinDnon_rfl";
			up = "AwopPknlMstpSoptWbinDnon_rfl";
			TurnL = "AwopPpneMstpSoptWbinDnon_rfl_turnL";
			TurnR = "AwopPpneMstpSoptWbinDnon_rfl_turnR";
			TurnLRelaxed = "AwopPpneMstpSoptWbinDnon_rfl_turnL";
			TurnRRelaxed = "AwopPpneMstpSoptWbinDnon_rfl_turnR";
			WalkF = "AmovPpneMwlkSoptWbinDf_rfl";
			WalkLF = "AmovPpneMwlkSoptWbinDfl_rfl";
			WalkRF = "AmovPpneMwlkSoptWbinDfr_rfl";
			WalkL = "AmovPpneMwlkSoptWbinDl_rfl";
			WalkR = "AmovPpneMwlkSoptWbinDr_rfl";
			WalkLB = "AmovPpneMwlkSoptWbinDbl_rfl";
			WalkRB = "AmovPpneMwlkSoptWbinDbr_rfl";
			WalkB = "AmovPpneMwlkSoptWbinDb_rfl";
			PlayerWalkF = "AmovPpneMwlkSoptWbinDf_rfl";
			PlayerWalkLF = "AmovPpneMwlkSoptWbinDfl_rfl";
			PlayerWalkRF = "AmovPpneMwlkSoptWbinDfr_rfl";
			PlayerWalkL = "AmovPpneMwlkSoptWbinDl_rfl";
			PlayerWalkR = "AmovPpneMwlkSoptWbinDr_rfl";
			PlayerWalkLB = "AmovPpneMwlkSoptWbinDbl_rfl";
			PlayerWalkRB = "AmovPpneMwlkSoptWbinDbr_rfl";
			PlayerWalkB = "AmovPpneMwlkSoptWbinDb_rfl";
			SlowF = "AmovPpneMrunSnonWbinDf_rfl";
			SlowLF = "AmovPpneMrunSnonWbinDfl_rfl";
			SlowRF = "AmovPpneMrunSnonWbinDfr_rfl";
			SlowL = "AmovPpneMrunSnonWbinDl_rfl";
			SlowR = "AmovPpneMrunSnonWbinDr_rfl";
			SlowLB = "AmovPpneMrunSnonWbinDbl_rfl";
			SlowRB = "AmovPpneMrunSnonWbinDbr_rfl";
			SlowB = "AmovPpneMrunSnonWbinDb_rfl";
			PlayerSlowF = "AmovPpneMrunSnonWbinDf_rfl";
			PlayerSlowLF = "AmovPpneMrunSnonWbinDfl_rfl";
			PlayerSlowRF = "AmovPpneMrunSnonWbinDfr_rfl";
			PlayerSlowL = "AmovPpneMrunSnonWbinDl_rfl";
			PlayerSlowR = "AmovPpneMrunSnonWbinDr_rfl";
			PlayerSlowLB = "AmovPpneMrunSnonWbinDbl_rfl";
			PlayerSlowRB = "AmovPpneMrunSnonWbinDbr_rfl";
			PlayerSlowB = "AmovPpneMrunSnonWbinDb_rfl";
			FastF = "AmovPpneMevaSnonWbinDf_rfl";
			FastLF = "AmovPpneMrunSnonWbinDfl_rfl";
			FastRF = "AmovPpneMrunSnonWbinDfr_rfl";
			FastL = "AmovPpneMrunSnonWbinDl_rfl";
			FastR = "AmovPpneMrunSnonWbinDr_rfl";
			FastLB = "AmovPpneMrunSnonWbinDbl_rfl";
			FastRB = "AmovPpneMrunSnonWbinDbr_rfl";
			FastB = "AmovPpneMrunSnonWbinDb_rfl";
			TactF = "AmovPpneMwlkSoptWbinDf_rfl";
			TactLF = "AmovPpneMwlkSoptWbinDfl_rfl";
			TactRF = "AmovPpneMwlkSoptWbinDfr_rfl";
			TactL = "AmovPpneMwlkSoptWbinDl_rfl";
			TactR = "AmovPpneMwlkSoptWbinDr_rfl";
			TactLB = "AmovPpneMwlkSoptWbinDbl_rfl";
			TactRB = "AmovPpneMwlkSoptWbinDbr_rfl";
			TactB = "AmovPpneMwlkSoptWbinDb_rfl";
			PlayerTactF = "AmovPpneMwlkSoptWbinDf_rfl";
			PlayerTactLF = "AmovPpneMwlkSoptWbinDfl_rfl";
			PlayerTactRF = "AmovPpneMwlkSoptWbinDfr_rfl";
			PlayerTactL = "AmovPpneMwlkSoptWbinDl_rfl";
			PlayerTactR = "AmovPpneMwlkSoptWbinDr_rfl";
			PlayerTactLB = "AmovPpneMwlkSoptWbinDbl_rfl";
			PlayerTactRB = "AmovPpneMwlkSoptWbinDbr_rfl";
			PlayerTactB = "AmovPpneMwlkSoptWbinDb_rfl";
			EvasiveRight = "";
			EvasiveLeft = "";
		};
		class BinocProneRflActionsWlkF: BinocProneRflActions{};
		class BinocProneRflActionsWlkFL: BinocProneRflActions{};
		class BinocProneRflActionsWlkFR: BinocProneRflActions{};
		class BinocProneRflActionsWlkR: BinocProneRflActions{};
		class BinocProneRflActionsWlkL: BinocProneRflActions{};
		class BinocProneRflActionsWlkB: BinocProneRflActions{};
		class BinocProneRflActionsWlkBL: BinocProneRflActions{};
		class BinocProneRflActionsWlkBR: BinocProneRflActions{};
		class BinocProneRflActionsRunF: BinocProneRflActions{};
		class BinocProneRflActionsRunFL: BinocProneRflActions{};
		class BinocProneRflActionsRunFR: BinocProneRflActions{};
		class BinocProneRflActionsRunR: BinocProneRflActions{};
		class BinocProneRflActionsRunL: BinocProneRflActions{};
		class BinocProneRflActionsRunB: BinocProneRflActions{};
		class BinocProneRflActionsRunBL: BinocProneRflActions{};
		class BinocProneRflActionsRunBR: BinocProneRflActions{};
		class BinocProneRflActionsEvasiveF: BinocProneRflActions{};
		class BinocStandPstActions: PistolStandActions
		{
			gestureGo[] = {"GestureGoBStand","Gesture"};
			Crouch = "AwopPercMstpSoptWbinDnon_Pst";
			Stand = "";
			handGunOn = "AwopPercMstpSoptWbinDnon_Pst";
			binocOn = "AwopPercMstpSoptWbinDnon_Pst";
			down = "AwopPpneMstpSoptWbinDnon_Pst";
			up = "AwopPknlMstpSoptWbinDnon_Pst";
			stop = "AwopPercMstpSoptWbinDnon_Pst";
			stopRelaxed = "AwopPercMstpSoptWbinDnon_Pst";
			default = "AwopPercMstpSoptWbinDnon_Pst";
			PlayerStand = "AwopPercMstpSoptWbinDnon_Pst";
			PlayerCrouch = "AwopPknlMstpSoptWbinDnon_Pst";
			PlayerProne = "AwopPpneMstpSoptWbinDnon_Pst";
			upDegree = "ManPosBinocStand";
			TurnL = "AwopPercMstpSoptWbinDnon_Pst_turnL";
			TurnR = "AwopPercMstpSoptWbinDnon_Pst_turnR";
			TurnLRelaxed = "AwopPercMstpSoptWbinDnon_Pst_turnL";
			TurnRRelaxed = "AwopPercMstpSoptWbinDnon_Pst_turnR";
			WalkF = "AmovPercMwlkSoptWbinDf_Pst";
			WalkLF = "AmovPercMwlkSoptWbinDfl_Pst";
			WalkRF = "AmovPercMwlkSoptWbinDfr_Pst";
			WalkL = "AmovPercMwlkSoptWbinDl_Pst";
			WalkR = "AmovPercMwlkSoptWbinDr_Pst";
			WalkLB = "AmovPercMwlkSoptWbinDbl_Pst";
			WalkRB = "AmovPercMwlkSoptWbinDbr_Pst";
			WalkB = "AmovPercMwlkSoptWbinDb_Pst";
			PlayerWalkF = "AmovPercMwlkSoptWbinDf_Pst";
			PlayerWalkLF = "AmovPercMwlkSoptWbinDfl_Pst";
			PlayerWalkRF = "AmovPercMwlkSoptWbinDfr_Pst";
			PlayerWalkL = "AmovPercMwlkSoptWbinDl_Pst";
			PlayerWalkR = "AmovPercMwlkSoptWbinDr_Pst";
			PlayerWalkLB = "AmovPercMwlkSoptWbinDbl_Pst";
			PlayerWalkRB = "AmovPercMwlkSoptWbinDbr_Pst";
			PlayerWalkB = "AmovPercMwlkSoptWbinDb_Pst";
			SlowF = "AmovPercMrunSnonWbinDf_Pst";
			SlowLF = "AmovPercMrunSnonWbinDfl_Pst";
			SlowRF = "AmovPercMrunSnonWbinDfr_Pst";
			SlowL = "AmovPercMrunSnonWbinDl_Pst";
			SlowR = "AmovPercMrunSnonWbinDr_Pst";
			SlowLB = "AmovPercMrunSnonWbinDbl_Pst";
			SlowRB = "AmovPercMrunSnonWbinDbr_Pst";
			SlowB = "AmovPercMrunSnonWbinDb_Pst";
			PlayerSlowF = "AmovPercMrunSnonWbinDf_Pst";
			PlayerSlowLF = "AmovPercMrunSnonWbinDfl_Pst";
			PlayerSlowRF = "AmovPercMrunSnonWbinDfr_Pst";
			PlayerSlowL = "AmovPercMrunSnonWbinDl_Pst";
			PlayerSlowR = "AmovPercMrunSnonWbinDr_Pst";
			PlayerSlowLB = "AmovPercMrunSnonWbinDbl_Pst";
			PlayerSlowRB = "AmovPercMrunSnonWbinDbr_Pst";
			PlayerSlowB = "AmovPercMrunSnonWbinDb_Pst";
			FastF = "AmovPercMevaSnonWbinDf_Pst";
			FastLF = "AmovPercMevaSnonWbinDfl_Pst";
			FastRF = "AmovPercMevaSnonWbinDfr_Pst";
			FastL = "AmovPercMrunSnonWbinDl_Pst";
			FastR = "AmovPercMrunSnonWbinDr_Pst";
			FastLB = "AmovPercMrunSnonWbinDbl_Pst";
			FastRB = "AmovPercMrunSnonWbinDbr_Pst";
			FastB = "AmovPercMrunSnonWbinDb_Pst";
			TactF = "AmovPercMwlkSoptWbinDf_Pst";
			TactLF = "AmovPercMwlkSoptWbinDfl_Pst";
			TactRF = "AmovPercMwlkSoptWbinDfr_Pst";
			TactL = "AmovPercMwlkSoptWbinDl_Pst";
			TactR = "AmovPercMwlkSoptWbinDr_Pst";
			TactLB = "AmovPercMwlkSoptWbinDbl_Pst";
			TactRB = "AmovPercMwlkSoptWbinDbr_Pst";
			TactB = "AmovPercMwlkSoptWbinDb_Pst";
			PlayerTactF = "AmovPercMwlkSoptWbinDf_Pst";
			PlayerTactLF = "AmovPercMwlkSoptWbinDfl_Pst";
			PlayerTactRF = "AmovPercMwlkSoptWbinDfr_Pst";
			PlayerTactL = "AmovPercMwlkSoptWbinDl_Pst";
			PlayerTactR = "AmovPercMwlkSoptWbinDr_Pst";
			PlayerTactLB = "AmovPercMwlkSoptWbinDbl_Pst";
			PlayerTactRB = "AmovPercMwlkSoptWbinDbr_Pst";
			PlayerTactB = "AmovPercMwlkSoptWbinDb_Pst";
			EvasiveRight = "";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
			Diary = "";
			Gear = "";
			GetOver = "";
		};
		class BinocStandPstActionsWlkF: BinocStandPstActions
		{
			PlayerCrouch = "AmovPknlMwlkSoptWbinDf_Pst";
			up = "AmovPknlMwlkSoptWbinDf_Pst";
		};
		class BinocStandPstActionsWlkFL: BinocStandPstActions
		{
			PlayerCrouch = "AmovPknlMwlkSoptWbinDfl_Pst";
			up = "AmovPknlMwlkSoptWbinDfl_Pst";
		};
		class BinocStandPstActionsWlkFR: BinocStandPstActions
		{
			PlayerCrouch = "AmovPknlMwlkSoptWbinDfr_Pst";
			up = "AmovPknlMwlkSoptWbinDfr_Pst";
		};
		class BinocStandPstActionsWlkR: BinocStandPstActions
		{
			PlayerCrouch = "AmovPknlMwlkSoptWbinDr_Pst";
			up = "AmovPknlMwlkSoptWbinDr_Pst";
		};
		class BinocStandPstActionsWlkL: BinocStandPstActions
		{
			PlayerCrouch = "AmovPknlMwlkSoptWbinDl_Pst";
			up = "AmovPknlMwlkSoptWbinDl_Pst";
		};
		class BinocStandPstActionsWlkB: BinocStandPstActions
		{
			PlayerCrouch = "AmovPknlMwlkSoptWbinDb_Pst";
			up = "AmovPknlMwlkSoptWbinDB_Pst";
		};
		class BinocStandPstActionsWlkBL: BinocStandPstActions
		{
			PlayerCrouch = "AmovPknlMwlkSoptWbinDbl_Pst";
			up = "AmovPknlMwlkSoptWbinDbl_Pst";
		};
		class BinocStandPstActionsWlkBR: BinocStandPstActions
		{
			PlayerCrouch = "AmovPknlMwlkSoptWbinDbr_Pst";
			up = "AmovPknlMwlkSoptWbinDbr_Pst";
		};
		class BinocStandPstActionsRunF: BinocStandPstActions
		{
			PlayerCrouch = "AmovPknlMRunSnonWbinDf_Pst";
			up = "AmovPknlMRunSnonWbinDf_Pst";
		};
		class BinocStandPstActionsRunFL: BinocStandPstActions
		{
			PlayerCrouch = "AmovPknlMRunSnonWbinDfl_Pst";
			up = "AmovPknlMRunSnonWbinDfl_Pst";
		};
		class BinocStandPstActionsRunFR: BinocStandPstActions
		{
			PlayerCrouch = "AmovPknlMRunSnonWbinDfr_Pst";
			up = "AmovPknlMRunSnonWbinDfr_Pst";
		};
		class BinocStandPstActionsRunR: BinocStandPstActions
		{
			PlayerCrouch = "AmovPknlMRunSnonWbinDr_Pst";
			up = "AmovPknlMRunSnonWbinDr_Pst";
		};
		class BinocStandPstActionsRunL: BinocStandPstActions
		{
			PlayerCrouch = "AmovPknlMRunSnonWbinDl_Pst";
			up = "AmovPknlMRunSnonWbinDl_Pst";
		};
		class BinocStandPstActionsRunB: BinocStandPstActions
		{
			PlayerCrouch = "AmovPknlMRunSnonWbinDb_Pst";
			up = "AmovPknlMRunSnonWbinDB_Pst";
		};
		class BinocStandPstActionsRunBL: BinocStandPstActions
		{
			PlayerCrouch = "AmovPknlMRunSnonWbinDbl_Pst";
			up = "AmovPknlMRunSnonWbinDbl_Pst";
		};
		class BinocStandPstActionsRunBR: BinocStandPstActions
		{
			PlayerCrouch = "AmovPknlMRunSnonWbinDbr_Pst";
			up = "AmovPknlMRunSnonWbinDbr_Pst";
		};
		class BinocStandPstActionsEvasiveF: BinocStandPstActions
		{
			PlayerCrouch = "AmovPknlMevaSnonWbinDf_Pst";
			up = "AmovPknlMevaSnonWbinDf_Pst";
		};
		class BinocStandPstActionsEvasiveFL: BinocStandPstActions
		{
			PlayerCrouch = "AmovPknlMevaSnonWbinDfl_Pst";
			up = "AmovPknlMevaSnonWbinDfl_Pst";
		};
		class BinocStandPstActionsEvasiveFR: BinocStandPstActions
		{
			PlayerCrouch = "AmovPknlMevaSnonWbinDfr_Pst";
			up = "AmovPknlMevaSnonWbinDfr_Pst";
		};
		class BinocKneelPstActions: PistolKneelActions
		{
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
			Crouch = "AwopPknlMstpSoptWbinDnon_Pst";
			binocOn = "AwopPknlMstpSoptWbinDnon_Pst";
			down = "AwopPpneMstpSoptWbinDnon_Pst";
			up = "AwopPercMstpSoptWbinDnon_Pst";
			stop = "AwopPknlMstpSoptWbinDnon_Pst";
			stopRelaxed = "AwopPknlMstpSoptWbinDnon_Pst";
			default = "AwopPknlMstpSoptWbinDnon_Pst";
			PlayerStand = "AwopPercMstpSoptWbinDnon_Pst";
			PlayerCrouch = "AwopPknlMstpSoptWbinDnon_Pst";
			PlayerProne = "AwopPpneMstpSoptWbinDnon_Pst";
			upDegree = "ManPosBinoc";
			TurnL = "AwopPknlMstpSoptWbinDnon_Pst_turnL";
			TurnR = "AwopPknlMstpSoptWbinDnon_Pst_turnR";
			TurnLRelaxed = "AwopPknlMstpSoptWbinDnon_Pst_turnL";
			TurnRRelaxed = "AwopPknlMstpSoptWbinDnon_Pst_turnR";
			WalkF = "AmovPknlMwlkSoptWbinDf_Pst";
			WalkLF = "AmovPknlMwlkSoptWbinDfl_Pst";
			WalkRF = "AmovPknlMwlkSoptWbinDfr_Pst";
			WalkL = "AmovPknlMwlkSoptWbinDl_Pst";
			WalkR = "AmovPknlMwlkSoptWbinDr_Pst";
			WalkLB = "AmovPknlMwlkSoptWbinDbl_Pst";
			WalkRB = "AmovPknlMwlkSoptWbinDbr_Pst";
			WalkB = "AmovPknlMwlkSoptWbinDb_Pst";
			PlayerWalkF = "AmovPknlMwlkSoptWbinDf_Pst";
			PlayerWalkLF = "AmovPknlMwlkSoptWbinDfl_Pst";
			PlayerWalkRF = "AmovPknlMwlkSoptWbinDfr_Pst";
			PlayerWalkL = "AmovPknlMwlkSoptWbinDl_Pst";
			PlayerWalkR = "AmovPknlMwlkSoptWbinDr_Pst";
			PlayerWalkLB = "AmovPknlMwlkSoptWbinDbl_Pst";
			PlayerWalkRB = "AmovPknlMwlkSoptWbinDbr_Pst";
			PlayerWalkB = "AmovPknlMwlkSoptWbinDb_Pst";
			SlowF = "AmovPknlMrunSnonWbinDf_Pst";
			SlowLF = "AmovPknlMrunSnonWbinDfl_Pst";
			SlowRF = "AmovPknlMrunSnonWbinDfr_Pst";
			SlowL = "AmovPknlMrunSnonWbinDl_Pst";
			SlowR = "AmovPknlMrunSnonWbinDr_Pst";
			SlowLB = "AmovPknlMrunSnonWbinDbl_Pst";
			SlowRB = "AmovPknlMrunSnonWbinDbr_Pst";
			SlowB = "AmovPknlMrunSnonWbinDb_Pst";
			PlayerSlowF = "AmovPknlMrunSnonWbinDf_Pst";
			PlayerSlowLF = "AmovPknlMrunSnonWbinDfl_Pst";
			PlayerSlowRF = "AmovPknlMrunSnonWbinDfr_Pst";
			PlayerSlowL = "AmovPknlMrunSnonWbinDl_Pst";
			PlayerSlowR = "AmovPknlMrunSnonWbinDr_Pst";
			PlayerSlowLB = "AmovPknlMrunSnonWbinDbl_Pst";
			PlayerSlowRB = "AmovPknlMrunSnonWbinDbr_Pst";
			PlayerSlowB = "AmovPknlMrunSnonWbinDb_Pst";
			FastF = "AmovPknlMevaSnonWbinDf_Pst";
			FastLF = "AmovPknlMevaSnonWbinDfl_Pst";
			FastRF = "AmovPknlMevaSnonWbinDfr_Pst";
			FastL = "AmovPknlMrunSnonWbinDl_Pst";
			FastR = "AmovPknlMrunSnonWbinDr_Pst";
			FastLB = "AmovPknlMrunSnonWbinDbl_Pst";
			FastRB = "AmovPknlMrunSnonWbinDbr_Pst";
			FastB = "AmovPknlMrunSnonWbinDb_Pst";
			TactF = "AmovPknlMwlkSoptWbinDf_Pst";
			TactLF = "AmovPknlMwlkSoptWbinDfl_Pst";
			TactRF = "AmovPknlMwlkSoptWbinDfr_Pst";
			TactL = "AmovPknlMwlkSoptWbinDl_Pst";
			TactR = "AmovPknlMwlkSoptWbinDr_Pst";
			TactLB = "AmovPknlMwlkSoptWbinDbl_Pst";
			TactRB = "AmovPknlMwlkSoptWbinDbr_Pst";
			TactB = "AmovPknlMwlkSoptWbinDb_Pst";
			PlayerTactF = "AmovPknlMwlkSoptWbinDf_Pst";
			PlayerTactLF = "AmovPknlMwlkSoptWbinDfl_Pst";
			PlayerTactRF = "AmovPknlMwlkSoptWbinDfr_Pst";
			PlayerTactL = "AmovPknlMwlkSoptWbinDl_Pst";
			PlayerTactR = "AmovPknlMwlkSoptWbinDr_Pst";
			PlayerTactLB = "AmovPknlMwlkSoptWbinDbl_Pst";
			PlayerTactRB = "AmovPknlMwlkSoptWbinDbr_Pst";
			PlayerTactB = "AmovPknlMwlkSoptWbinDb_Pst";
			EvasiveRight = "";
			EvasiveLeft = "";
			Diary = "";
			Gear = "";
		};
		class BinocKneelPstActionsWlkF: BinocKneelPstActions
		{
			PlayerCrouch = "AmovPercMwlkSoptWbinDf_Pst";
			up = "AmovPercMwlkSoptWbinDf_Pst";
		};
		class BinocKneelPstActionsWlkFL: BinocKneelPstActions
		{
			PlayerCrouch = "AmovPercMwlkSoptWbinDfl_Pst";
			up = "AmovPercMwlkSoptWbinDfl_Pst";
		};
		class BinocKneelPstActionsWlkFR: BinocKneelPstActions
		{
			PlayerCrouch = "AmovPercMwlkSoptWbinDfr_Pst";
			up = "AmovPercMwlkSoptWbinDfr_Pst";
		};
		class BinocKneelPstActionsWlkR: BinocKneelPstActions
		{
			PlayerCrouch = "AmovPercMwlkSoptWbinDr_Pst";
			up = "AmovPercMwlkSoptWbinDr_Pst";
		};
		class BinocKneelPstActionsWlkL: BinocKneelPstActions
		{
			PlayerCrouch = "AmovPercMwlkSoptWbinDl_Pst";
			up = "AmovPercMwlkSoptWbinDl_Pst";
		};
		class BinocKneelPstActionsWlkB: BinocKneelPstActions
		{
			PlayerCrouch = "AmovPercMwlkSoptWbinDb_Pst";
			up = "AmovPercMwlkSoptWbinDB_Pst";
		};
		class BinocKneelPstActionsWlkBL: BinocKneelPstActions
		{
			PlayerCrouch = "AmovPercMwlkSoptWbinDbl_Pst";
			up = "AmovPercMwlkSoptWbinDbl_Pst";
		};
		class BinocKneelPstActionsWlkBR: BinocKneelPstActions
		{
			PlayerCrouch = "AmovPercMwlkSoptWbinDbr_Pst";
			up = "AmovPercMwlkSoptWbinDbr_Pst";
		};
		class BinocKneelPstActionsRunF: BinocKneelPstActions
		{
			PlayerCrouch = "AmovPercMRunSnonWbinDf_Pst";
			up = "AmovPercMRunSnonWbinDf_Pst";
		};
		class BinocKneelPstActionsRunFL: BinocKneelPstActions
		{
			PlayerCrouch = "AmovPercMRunSnonWbinDfl_Pst";
			up = "AmovPercMRunSnonWbinDfl_Pst";
		};
		class BinocKneelPstActionsRunFR: BinocKneelPstActions
		{
			PlayerCrouch = "AmovPercMRunSnonWbinDfr_Pst";
			up = "AmovPercMRunSnonWbinDfr_Pst";
		};
		class BinocKneelPstActionsRunR: BinocKneelPstActions
		{
			PlayerCrouch = "AmovPercMRunSnonWbinDr_Pst";
			up = "AmovPercMRunSnonWbinDr_Pst";
		};
		class BinocKneelPstActionsRunL: BinocKneelPstActions
		{
			PlayerCrouch = "AmovPercMRunSnonWbinDl_Pst";
			up = "AmovPercMRunSnonWbinDl_Pst";
		};
		class BinocKneelPstActionsRunB: BinocKneelPstActions
		{
			PlayerCrouch = "AmovPercMRunSnonWbinDb_Pst";
			up = "AmovPercMRunSnonWbinDB_Pst";
		};
		class BinocKneelPstActionsRunBL: BinocKneelPstActions
		{
			PlayerCrouch = "AmovPercMRunSnonWbinDbl_Pst";
			up = "AmovPercMRunSnonWbinDbl_Pst";
		};
		class BinocKneelPstActionsRunBR: BinocKneelPstActions
		{
			PlayerCrouch = "AmovPercMRunSnonWbinDbr_Pst";
			up = "AmovPercMRunSnonWbinDbr_Pst";
		};
		class BinocKneelPstActionsEvasiveF: BinocKneelPstActions
		{
			PlayerCrouch = "AmovPercMevaSnonWbinDf_Pst";
			up = "AmovPercMevaSnonWbinDf_Pst";
		};
		class BinocKneelPstActionsEvasiveFL: BinocKneelPstActions
		{
			PlayerCrouch = "AmovPercMevaSnonWbinDfl_Pst";
			up = "AmovPercMevaSnonWbinDfl_Pst";
		};
		class BinocKneelPstActionsEvasiveFR: BinocKneelPstActions
		{
			PlayerCrouch = "AmovPercMevaSnonWbinDfr_Pst";
			up = "AmovPercMevaSnonWbinDfr_Pst";
		};
		class BinocPronePstActions: PistolProneActions
		{
			AdjustF = "";
			AdjustB = "";
			binocOn = "";
			stop = "AwopPpneMstpSoptWbinDnon_Pst";
			stopRelaxed = "AwopPpneMstpSoptWbinDnon_Pst";
			default = "AwopPpneMstpSoptWbinDnon_Pst";
			PlayerStand = "AwopPercMstpSoptWbinDnon_Pst";
			PlayerCrouch = "AwopPknlMstpSoptWbinDnon_Pst";
			PlayerProne = "AwopPpneMstpSoptWbinDnon_Pst";
			upDegree = "ManPosBinocLying";
			down = "AwopPercMstpSoptWbinDnon_Pst";
			up = "AwopPknlMstpSoptWbinDnon_Pst";
			TurnL = "AwopPpneMstpSoptWbinDnon_Pst_turnL";
			TurnR = "AwopPpneMstpSoptWbinDnon_Pst_turnR";
			TurnLRelaxed = "AwopPpneMstpSoptWbinDnon_Pst_turnL";
			TurnRRelaxed = "AwopPpneMstpSoptWbinDnon_Pst_turnR";
			WalkF = "AmovPpneMwlkSoptWbinDf_Pst";
			WalkLF = "AmovPpneMwlkSoptWbinDfl_Pst";
			WalkRF = "AmovPpneMwlkSoptWbinDfr_Pst";
			WalkL = "AmovPpneMwlkSoptWbinDl_Pst";
			WalkR = "AmovPpneMwlkSoptWbinDr_Pst";
			WalkLB = "AmovPpneMwlkSoptWbinDbl_Pst";
			WalkRB = "AmovPpneMwlkSoptWbinDbr_Pst";
			WalkB = "AmovPpneMwlkSoptWbinDb_Pst";
			PlayerWalkF = "AmovPpneMwlkSoptWbinDf_Pst";
			PlayerWalkLF = "AmovPpneMwlkSoptWbinDfl_Pst";
			PlayerWalkRF = "AmovPpneMwlkSoptWbinDfr_Pst";
			PlayerWalkL = "AmovPpneMwlkSoptWbinDl_Pst";
			PlayerWalkR = "AmovPpneMwlkSoptWbinDr_Pst";
			PlayerWalkLB = "AmovPpneMwlkSoptWbinDbl_Pst";
			PlayerWalkRB = "AmovPpneMwlkSoptWbinDbr_Pst";
			PlayerWalkB = "AmovPpneMwlkSoptWbinDb_Pst";
			SlowF = "AmovPpneMrunSnonWbinDf_Pst";
			SlowLF = "AmovPpneMrunSnonWbinDfl_Pst";
			SlowRF = "AmovPpneMrunSnonWbinDfr_Pst";
			SlowL = "AmovPpneMrunSnonWbinDl_Pst";
			SlowR = "AmovPpneMrunSnonWbinDr_Pst";
			SlowLB = "AmovPpneMrunSnonWbinDbl_Pst";
			SlowRB = "AmovPpneMrunSnonWbinDbr_Pst";
			SlowB = "AmovPpneMrunSnonWbinDb_Pst";
			PlayerSlowF = "AmovPpneMrunSnonWbinDf_Pst";
			PlayerSlowLF = "AmovPpneMrunSnonWbinDfl_Pst";
			PlayerSlowRF = "AmovPpneMrunSnonWbinDfr_Pst";
			PlayerSlowL = "AmovPpneMrunSnonWbinDl_Pst";
			PlayerSlowR = "AmovPpneMrunSnonWbinDr_Pst";
			PlayerSlowLB = "AmovPpneMrunSnonWbinDbl_Pst";
			PlayerSlowRB = "AmovPpneMrunSnonWbinDbr_Pst";
			PlayerSlowB = "AmovPpneMrunSnonWbinDb_Pst";
			FastF = "AmovPpneMevaSnonWbinDf_Pst";
			FastLF = "AmovPpneMrunSnonWbinDfl_Pst";
			FastRF = "AmovPpneMrunSnonWbinDfr_Pst";
			FastL = "AmovPpneMrunSnonWbinDl_Pst";
			FastR = "AmovPpneMrunSnonWbinDr_Pst";
			FastLB = "AmovPpneMrunSnonWbinDbl_Pst";
			FastRB = "AmovPpneMrunSnonWbinDbr_Pst";
			FastB = "AmovPpneMrunSnonWbinDb_Pst";
			TactF = "AmovPpneMwlkSoptWbinDf_Pst";
			TactLF = "AmovPpneMwlkSoptWbinDfl_Pst";
			TactRF = "AmovPpneMwlkSoptWbinDfr_Pst";
			TactL = "AmovPpneMwlkSoptWbinDl_Pst";
			TactR = "AmovPpneMwlkSoptWbinDr_Pst";
			TactLB = "AmovPpneMwlkSoptWbinDbl_Pst";
			TactRB = "AmovPpneMwlkSoptWbinDbr_Pst";
			TactB = "AmovPpneMwlkSoptWbinDb_Pst";
			PlayerTactF = "AmovPpneMwlkSoptWbinDf_Pst";
			PlayerTactLF = "AmovPpneMwlkSoptWbinDfl_Pst";
			PlayerTactRF = "AmovPpneMwlkSoptWbinDfr_Pst";
			PlayerTactL = "AmovPpneMwlkSoptWbinDl_Pst";
			PlayerTactR = "AmovPpneMwlkSoptWbinDr_Pst";
			PlayerTactLB = "AmovPpneMwlkSoptWbinDbl_Pst";
			PlayerTactRB = "AmovPpneMwlkSoptWbinDbr_Pst";
			PlayerTactB = "AmovPpneMwlkSoptWbinDb_Pst";
			EvasiveRight = "";
			EvasiveLeft = "";
		};
		class BinocPronePstActionsWlkF: BinocPronePstActions{};
		class BinocPronePstActionsWlkFL: BinocPronePstActions{};
		class BinocPronePstActionsWlkFR: BinocPronePstActions{};
		class BinocPronePstActionsWlkR: BinocPronePstActions{};
		class BinocPronePstActionsWlkL: BinocPronePstActions{};
		class BinocPronePstActionsWlkB: BinocPronePstActions{};
		class BinocPronePstActionsWlkBL: BinocPronePstActions{};
		class BinocPronePstActionsWlkBR: BinocPronePstActions{};
		class BinocPronePstActionsRunF: BinocPronePstActions{};
		class BinocPronePstActionsRunFL: BinocPronePstActions{};
		class BinocPronePstActionsRunFR: BinocPronePstActions{};
		class BinocPronePstActionsRunR: BinocPronePstActions{};
		class BinocPronePstActionsRunL: BinocPronePstActions{};
		class BinocPronePstActionsRunB: BinocPronePstActions{};
		class BinocPronePstActionsRunBL: BinocPronePstActions{};
		class BinocPronePstActionsRunBR: BinocPronePstActions{};
		class BinocPronePstActionsEvasiveF: BinocPronePstActions{};
		class BinocStandLnrActions: LauncherStandActions
		{
			gestureGo[] = {"GestureGoBStand","Gesture"};
			binocOn = "";
			WeaponOff = "AmovPercMstpSrasWlnrDnon";
			down = "AwopPpneMstpSoptWbinDnon_Lnr";
			up = "AwopPknlMstpSoptWbinDnon_Lnr";
			stop = "AwopPercMstpSoptWbinDnon_Lnr";
			stopRelaxed = "AwopPercMstpSoptWbinDnon_Lnr";
			default = "AwopPercMstpSoptWbinDnon_Lnr";
			PlayerStand = "AwopPercMstpSoptWbinDnon_Lnr";
			PlayerCrouch = "AwopPknlMstpSoptWbinDnon_Lnr";
			PlayerProne = "AwopPpneMstpSoptWbinDnon_Lnr";
			upDegree = "ManPosBinocStand";
			TurnL = "AwopPercMstpSoptWbinDnon_Lnr_turnL";
			TurnR = "AwopPercMstpSoptWbinDnon_Lnr_turnR";
			TurnLRelaxed = "AwopPercMstpSoptWbinDnon_Lnr_turnL";
			TurnRRelaxed = "AwopPercMstpSoptWbinDnon_Lnr_turnR";
			WalkF = "AmovPercMwlkSoptWbinDf_Lnr";
			WalkLF = "AmovPercMwlkSoptWbinDfl_Lnr";
			WalkRF = "AmovPercMwlkSoptWbinDfr_Lnr";
			WalkL = "AmovPercMwlkSoptWbinDl_Lnr";
			WalkR = "AmovPercMwlkSoptWbinDr_Lnr";
			WalkLB = "AmovPercMwlkSoptWbinDbl_Lnr";
			WalkRB = "AmovPercMwlkSoptWbinDbr_Lnr";
			WalkB = "AmovPercMwlkSoptWbinDb_Lnr";
			PlayerWalkF = "AmovPercMwlkSoptWbinDf_Lnr";
			PlayerWalkLF = "AmovPercMwlkSoptWbinDfl_Lnr";
			PlayerWalkRF = "AmovPercMwlkSoptWbinDfr_Lnr";
			PlayerWalkL = "AmovPercMwlkSoptWbinDl_Lnr";
			PlayerWalkR = "AmovPercMwlkSoptWbinDr_Lnr";
			PlayerWalkLB = "AmovPercMwlkSoptWbinDbl_Lnr";
			PlayerWalkRB = "AmovPercMwlkSoptWbinDbr_Lnr";
			PlayerWalkB = "AmovPercMwlkSoptWbinDb_Lnr";
			SlowF = "AmovPercMrunSnonWbinDf_Lnr";
			SlowLF = "AmovPercMrunSnonWbinDfl_Lnr";
			SlowRF = "AmovPercMrunSnonWbinDfr_Lnr";
			SlowL = "AmovPercMrunSnonWbinDl_Lnr";
			SlowR = "AmovPercMrunSnonWbinDr_Lnr";
			SlowLB = "AmovPercMrunSnonWbinDbl_Lnr";
			SlowRB = "AmovPercMrunSnonWbinDbr_Lnr";
			SlowB = "AmovPercMrunSnonWbinDb_Lnr";
			PlayerSlowF = "AmovPercMrunSnonWbinDf_Lnr";
			PlayerSlowLF = "AmovPercMrunSnonWbinDfl_Lnr";
			PlayerSlowRF = "AmovPercMrunSnonWbinDfr_Lnr";
			PlayerSlowL = "AmovPercMrunSnonWbinDl_Lnr";
			PlayerSlowR = "AmovPercMrunSnonWbinDr_Lnr";
			PlayerSlowLB = "AmovPercMrunSnonWbinDbl_Lnr";
			PlayerSlowRB = "AmovPercMrunSnonWbinDbr_Lnr";
			PlayerSlowB = "AmovPercMrunSnonWbinDb_Lnr";
			FastF = "AmovPercMevaSnonWbinDf_Lnr";
			FastLF = "AmovPercMevaSnonWbinDfl_Lnr";
			FastRF = "AmovPercMevaSnonWbinDfr_Lnr";
			FastL = "AmovPercMrunSnonWbinDl_Lnr";
			FastR = "AmovPercMrunSnonWbinDr_Lnr";
			FastLB = "AmovPercMrunSnonWbinDbl_Lnr";
			FastRB = "AmovPercMrunSnonWbinDbr_Lnr";
			FastB = "AmovPercMrunSnonWbinDb_Lnr";
			TactF = "AmovPercMwlkSoptWbinDf_Lnr";
			TactLF = "AmovPercMwlkSoptWbinDfl_Lnr";
			TactRF = "AmovPercMwlkSoptWbinDfr_Lnr";
			TactL = "AmovPercMwlkSoptWbinDl_Lnr";
			TactR = "AmovPercMwlkSoptWbinDr_Lnr";
			TactLB = "AmovPercMwlkSoptWbinDbl_Lnr";
			TactRB = "AmovPercMwlkSoptWbinDbr_Lnr";
			TactB = "AmovPercMwlkSoptWbinDb_Lnr";
			PlayerTactF = "AmovPercMwlkSoptWbinDf_Lnr";
			PlayerTactLF = "AmovPercMwlkSoptWbinDfl_Lnr";
			PlayerTactRF = "AmovPercMwlkSoptWbinDfr_Lnr";
			PlayerTactL = "AmovPercMwlkSoptWbinDl_Lnr";
			PlayerTactR = "AmovPercMwlkSoptWbinDr_Lnr";
			PlayerTactLB = "AmovPercMwlkSoptWbinDbl_Lnr";
			PlayerTactRB = "AmovPercMwlkSoptWbinDbr_Lnr";
			PlayerTactB = "AmovPercMwlkSoptWbinDb_Lnr";
			EvasiveRight = "";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
			Diary = "";
			Gear = "";
			GetOver = "";
		};
		class BinocStandLnrActionsWlkF: BinocStandLnrActions
		{
			PlayerCrouch = "AmovPknlMwlkSoptWbinDf_Lnr";
			up = "AmovPknlMwlkSoptWbinDf_Lnr";
		};
		class BinocStandLnrActionsWlkFL: BinocStandLnrActions
		{
			PlayerCrouch = "AmovPknlMwlkSoptWbinDfl_Lnr";
			up = "AmovPknlMwlkSoptWbinDfl_Lnr";
		};
		class BinocStandLnrActionsWlkFR: BinocStandLnrActions
		{
			PlayerCrouch = "AmovPknlMwlkSoptWbinDfr_Lnr";
			up = "AmovPknlMwlkSoptWbinDfr_Lnr";
		};
		class BinocStandLnrActionsWlkR: BinocStandLnrActions
		{
			PlayerCrouch = "AmovPknlMwlkSoptWbinDr_Lnr";
			up = "AmovPknlMwlkSoptWbinDr_Lnr";
		};
		class BinocStandLnrActionsWlkL: BinocStandLnrActions
		{
			PlayerCrouch = "AmovPknlMwlkSoptWbinDl_Lnr";
			up = "AmovPknlMwlkSoptWbinDl_Lnr";
		};
		class BinocStandLnrActionsWlkB: BinocStandLnrActions
		{
			PlayerCrouch = "AmovPknlMwlkSoptWbinDb_Lnr";
			up = "AmovPknlMwlkSoptWbinDB_Lnr";
		};
		class BinocStandLnrActionsWlkBL: BinocStandLnrActions
		{
			PlayerCrouch = "AmovPknlMwlkSoptWbinDbl_Lnr";
			up = "AmovPknlMwlkSoptWbinDbl_Lnr";
		};
		class BinocStandLnrActionsWlkBR: BinocStandLnrActions
		{
			PlayerCrouch = "AmovPknlMwlkSoptWbinDbr_Lnr";
			up = "AmovPknlMwlkSoptWbinDbr_Lnr";
		};
		class BinocStandLnrActionsRunF: BinocStandLnrActions
		{
			PlayerCrouch = "AmovPknlMRunSnonWbinDf_Lnr";
			up = "AmovPknlMRunSnonWbinDf_Lnr";
		};
		class BinocStandLnrActionsRunFL: BinocStandLnrActions
		{
			PlayerCrouch = "AmovPknlMRunSnonWbinDfl_Lnr";
			up = "AmovPknlMRunSnonWbinDfl_Lnr";
		};
		class BinocStandLnrActionsRunFR: BinocStandLnrActions
		{
			PlayerCrouch = "AmovPknlMRunSnonWbinDfr_Lnr";
			up = "AmovPknlMRunSnonWbinDfr_Lnr";
		};
		class BinocStandLnrActionsRunR: BinocStandLnrActions
		{
			PlayerCrouch = "AmovPknlMRunSnonWbinDr_Lnr";
			up = "AmovPknlMRunSnonWbinDr_Lnr";
		};
		class BinocStandLnrActionsRunL: BinocStandLnrActions
		{
			PlayerCrouch = "AmovPknlMRunSnonWbinDl_Lnr";
			up = "AmovPknlMRunSnonWbinDl_Lnr";
		};
		class BinocStandLnrActionsRunB: BinocStandLnrActions
		{
			PlayerCrouch = "AmovPknlMRunSnonWbinDb_Lnr";
			up = "AmovPknlMRunSnonWbinDB_Lnr";
		};
		class BinocStandLnrActionsRunBL: BinocStandLnrActions
		{
			PlayerCrouch = "AmovPknlMRunSnonWbinDbl_Lnr";
			up = "AmovPknlMRunSnonWbinDbl_Lnr";
		};
		class BinocStandLnrActionsRunBR: BinocStandLnrActions
		{
			PlayerCrouch = "AmovPknlMRunSnonWbinDbr_Lnr";
			up = "AmovPknlMRunSnonWbinDbr_Lnr";
		};
		class BinocStandLnrActionsEvasiveF: BinocStandLnrActions
		{
			PlayerCrouch = "AmovPknlMevaSnonWbinDf_Lnr";
			up = "AmovPknlMevaSnonWbinDf_Lnr";
		};
		class BinocStandLnrActionsEvasiveFL: BinocStandLnrActions
		{
			PlayerCrouch = "AmovPknlMevaSnonWbinDfl_Lnr";
			up = "AmovPknlMevaSnonWbinDfl_Lnr";
		};
		class BinocStandLnrActionsEvasiveFR: BinocStandLnrActions
		{
			PlayerCrouch = "AmovPknlMevaSnonWbinDfr_Lnr";
			up = "AmovPknlMevaSnonWbinDfr_Lnr";
		};
		class BinocKneelLnrActions: LauncherKneelActions
		{
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
			binocOn = "";
			WeaponOff = "AmovPknlMstpSrasWlnrDnon";
			down = "AwopPpneMstpSoptWbinDnon_Lnr";
			up = "AwopPercMstpSoptWbinDnon_Lnr";
			stop = "AwopPknlMstpSoptWbinDnon_Lnr";
			stopRelaxed = "AwopPknlMstpSoptWbinDnon_Lnr";
			default = "AwopPknlMstpSoptWbinDnon_Lnr";
			PlayerStand = "AwopPercMstpSoptWbinDnon_Lnr";
			PlayerCrouch = "AwopPknlMstpSoptWbinDnon_Lnr";
			PlayerProne = "AwopPpneMstpSoptWbinDnon_Lnr";
			upDegree = "ManPosBinoc";
			TurnL = "AwopPknlMstpSoptWbinDnon_Lnr_turnL";
			TurnR = "AwopPknlMstpSoptWbinDnon_Lnr_turnR";
			TurnLRelaxed = "AwopPknlMstpSoptWbinDnon_Lnr_turnL";
			TurnRRelaxed = "AwopPknlMstpSoptWbinDnon_Lnr_turnR";
			WalkF = "AmovPknlMwlkSoptWbinDf_Lnr";
			WalkLF = "AmovPknlMwlkSoptWbinDfl_Lnr";
			WalkRF = "AmovPknlMwlkSoptWbinDfr_Lnr";
			WalkL = "AmovPknlMwlkSoptWbinDl_Lnr";
			WalkR = "AmovPknlMwlkSoptWbinDr_Lnr";
			WalkLB = "AmovPknlMwlkSoptWbinDbl_Lnr";
			WalkRB = "AmovPknlMwlkSoptWbinDbr_Lnr";
			WalkB = "AmovPknlMwlkSoptWbinDb_Lnr";
			PlayerWalkF = "AmovPknlMwlkSoptWbinDf_Lnr";
			PlayerWalkLF = "AmovPknlMwlkSoptWbinDfl_Lnr";
			PlayerWalkRF = "AmovPknlMwlkSoptWbinDfr_Lnr";
			PlayerWalkL = "AmovPknlMwlkSoptWbinDl_Lnr";
			PlayerWalkR = "AmovPknlMwlkSoptWbinDr_Lnr";
			PlayerWalkLB = "AmovPknlMwlkSoptWbinDbl_Lnr";
			PlayerWalkRB = "AmovPknlMwlkSoptWbinDbr_Lnr";
			PlayerWalkB = "AmovPknlMwlkSoptWbinDb_Lnr";
			SlowF = "AmovPknlMrunSnonWbinDf_Lnr";
			SlowLF = "AmovPknlMrunSnonWbinDfl_Lnr";
			SlowRF = "AmovPknlMrunSnonWbinDfr_Lnr";
			SlowL = "AmovPknlMrunSnonWbinDl_Lnr";
			SlowR = "AmovPknlMrunSnonWbinDr_Lnr";
			SlowLB = "AmovPknlMrunSnonWbinDbl_Lnr";
			SlowRB = "AmovPknlMrunSnonWbinDbr_Lnr";
			SlowB = "AmovPknlMrunSnonWbinDb_Lnr";
			PlayerSlowF = "AmovPknlMrunSnonWbinDf_Lnr";
			PlayerSlowLF = "AmovPknlMrunSnonWbinDfl_Lnr";
			PlayerSlowRF = "AmovPknlMrunSnonWbinDfr_Lnr";
			PlayerSlowL = "AmovPknlMrunSnonWbinDl_Lnr";
			PlayerSlowR = "AmovPknlMrunSnonWbinDr_Lnr";
			PlayerSlowLB = "AmovPknlMrunSnonWbinDbl_Lnr";
			PlayerSlowRB = "AmovPknlMrunSnonWbinDbr_Lnr";
			PlayerSlowB = "AmovPknlMrunSnonWbinDb_Lnr";
			FastF = "AmovPknlMevaSnonWbinDf_Lnr";
			FastLF = "AmovPknlMevaSnonWbinDfl_Lnr";
			FastRF = "AmovPknlMevaSnonWbinDfr_Lnr";
			FastL = "AmovPknlMrunSnonWbinDl_Lnr";
			FastR = "AmovPknlMrunSnonWbinDr_Lnr";
			FastLB = "AmovPknlMrunSnonWbinDbl_Lnr";
			FastRB = "AmovPknlMrunSnonWbinDbr_Lnr";
			FastB = "AmovPknlMrunSnonWbinDb_Lnr";
			TactF = "AmovPknlMwlkSoptWbinDf_Lnr";
			TactLF = "AmovPknlMwlkSoptWbinDfl_Lnr";
			TactRF = "AmovPknlMwlkSoptWbinDfr_Lnr";
			TactL = "AmovPknlMwlkSoptWbinDl_Lnr";
			TactR = "AmovPknlMwlkSoptWbinDr_Lnr";
			TactLB = "AmovPknlMwlkSoptWbinDbl_Lnr";
			TactRB = "AmovPknlMwlkSoptWbinDbr_Lnr";
			TactB = "AmovPknlMwlkSoptWbinDb_Lnr";
			PlayerTactF = "AmovPknlMwlkSoptWbinDf_Lnr";
			PlayerTactLF = "AmovPknlMwlkSoptWbinDfl_Lnr";
			PlayerTactRF = "AmovPknlMwlkSoptWbinDfr_Lnr";
			PlayerTactL = "AmovPknlMwlkSoptWbinDl_Lnr";
			PlayerTactR = "AmovPknlMwlkSoptWbinDr_Lnr";
			PlayerTactLB = "AmovPknlMwlkSoptWbinDbl_Lnr";
			PlayerTactRB = "AmovPknlMwlkSoptWbinDbr_Lnr";
			PlayerTactB = "AmovPknlMwlkSoptWbinDb_Lnr";
			EvasiveRight = "";
			EvasiveLeft = "";
			Diary = "";
			Gear = "";
		};
		class BinocKneelLnrActionsWlkF: BinocKneelLnrActions
		{
			PlayerCrouch = "AmovPercMwlkSoptWbinDf_Lnr";
			up = "AmovPercMwlkSoptWbinDf_Lnr";
		};
		class BinocKneelLnrActionsWlkFL: BinocKneelLnrActions
		{
			PlayerCrouch = "AmovPercMwlkSoptWbinDfl_Lnr";
			up = "AmovPercMwlkSoptWbinDfl_Lnr";
		};
		class BinocKneelLnrActionsWlkFR: BinocKneelLnrActions
		{
			PlayerCrouch = "AmovPercMwlkSoptWbinDfr_Lnr";
			up = "AmovPercMwlkSoptWbinDfr_Lnr";
		};
		class BinocKneelLnrActionsWlkR: BinocKneelLnrActions
		{
			PlayerCrouch = "AmovPercMwlkSoptWbinDr_Lnr";
			up = "AmovPercMwlkSoptWbinDr_Lnr";
		};
		class BinocKneelLnrActionsWlkL: BinocKneelLnrActions
		{
			PlayerCrouch = "AmovPercMwlkSoptWbinDl_Lnr";
			up = "AmovPercMwlkSoptWbinDl_Lnr";
		};
		class BinocKneelLnrActionsWlkB: BinocKneelLnrActions
		{
			PlayerCrouch = "AmovPercMwlkSoptWbinDb_Lnr";
			up = "AmovPercMwlkSoptWbinDB_Lnr";
		};
		class BinocKneelLnrActionsWlkBL: BinocKneelLnrActions
		{
			PlayerCrouch = "AmovPercMwlkSoptWbinDbl_Lnr";
			up = "AmovPercMwlkSoptWbinDbl_Lnr";
		};
		class BinocKneelLnrActionsWlkBR: BinocKneelLnrActions
		{
			PlayerCrouch = "AmovPercMwlkSoptWbinDbr_Lnr";
			up = "AmovPercMwlkSoptWbinDbr_Lnr";
		};
		class BinocKneelLnrActionsRunF: BinocKneelLnrActions
		{
			PlayerCrouch = "AmovPercMRunSnonWbinDf_Lnr";
			up = "AmovPercMRunSnonWbinDf_Lnr";
		};
		class BinocKneelLnrActionsRunFL: BinocKneelLnrActions
		{
			PlayerCrouch = "AmovPercMRunSnonWbinDfl_Lnr";
			up = "AmovPercMRunSnonWbinDfl_Lnr";
		};
		class BinocKneelLnrActionsRunFR: BinocKneelLnrActions
		{
			PlayerCrouch = "AmovPercMRunSnonWbinDfr_Lnr";
			up = "AmovPercMRunSnonWbinDfr_Lnr";
		};
		class BinocKneelLnrActionsRunR: BinocKneelLnrActions
		{
			PlayerCrouch = "AmovPercMRunSnonWbinDr_Lnr";
			up = "AmovPercMRunSnonWbinDr_Lnr";
		};
		class BinocKneelLnrActionsRunL: BinocKneelLnrActions
		{
			PlayerCrouch = "AmovPercMRunSnonWbinDl_Lnr";
			up = "AmovPercMRunSnonWbinDl_Lnr";
		};
		class BinocKneelLnrActionsRunB: BinocKneelLnrActions
		{
			PlayerCrouch = "AmovPercMRunSnonWbinDb_Lnr";
			up = "AmovPercMRunSnonWbinDB_Lnr";
		};
		class BinocKneelLnrActionsRunBL: BinocKneelLnrActions
		{
			PlayerCrouch = "AmovPercMRunSnonWbinDbl_Lnr";
			up = "AmovPercMRunSnonWbinDbl_Lnr";
		};
		class BinocKneelLnrActionsRunBR: BinocKneelLnrActions
		{
			PlayerCrouch = "AmovPercMRunSnonWbinDbr_Lnr";
			up = "AmovPercMRunSnonWbinDbr_Lnr";
		};
		class BinocKneelLnrActionsEvasiveF: BinocKneelLnrActions
		{
			PlayerCrouch = "AmovPercMevaSnonWbinDf_Lnr";
			up = "AmovPercMevaSnonWbinDf_Lnr";
		};
		class BinocKneelLnrActionsEvasiveFL: BinocKneelLnrActions
		{
			PlayerCrouch = "AmovPercMevaSnonWbinDfl_Lnr";
			up = "AmovPercMevaSnonWbinDfl_Lnr";
		};
		class BinocKneelLnrActionsEvasiveFR: BinocKneelLnrActions
		{
			PlayerCrouch = "AmovPercMevaSnonWbinDfr_Lnr";
			up = "AmovPercMevaSnonWbinDfr_Lnr";
		};
		class BinocProneLnrActions: LauncherKneelActions
		{
			AdjustF = "";
			AdjustB = "";
			binocOn = "";
			BinocOff = "AmovPpneMstpSnonWnonDnon";
			stop = "AwopPpneMstpSoptWbinDnon_Lnr";
			stopRelaxed = "AwopPpneMstpSoptWbinDnon_Lnr";
			default = "AwopPpneMstpSoptWbinDnon_Lnr";
			PlayerStand = "AwopPercMstpSoptWbinDnon_Lnr";
			PlayerCrouch = "AwopPknlMstpSoptWbinDnon_Lnr";
			PlayerProne = "AwopPpneMstpSoptWbinDnon_Lnr";
			upDegree = "ManPosBinocLying";
			down = "AwopPercMstpSoptWbinDnon_Lnr";
			up = "AwopPknlMstpSoptWbinDnon_Lnr";
			TurnL = "AwopPpneMstpSoptWbinDnon_Lnr_turnL";
			TurnR = "AwopPpneMstpSoptWbinDnon_Lnr_turnR";
			TurnLRelaxed = "AwopPpneMstpSoptWbinDnon_Lnr_turnL";
			TurnRRelaxed = "AwopPpneMstpSoptWbinDnon_Lnr_turnR";
			WalkF = "AmovPpneMwlkSoptWbinDf_Lnr";
			WalkLF = "AmovPpneMwlkSoptWbinDfl_Lnr";
			WalkRF = "AmovPpneMwlkSoptWbinDfr_Lnr";
			WalkL = "AmovPpneMwlkSoptWbinDl_Lnr";
			WalkR = "AmovPpneMwlkSoptWbinDr_Lnr";
			WalkLB = "AmovPpneMwlkSoptWbinDbl_Lnr";
			WalkRB = "AmovPpneMwlkSoptWbinDbr_Lnr";
			WalkB = "AmovPpneMwlkSoptWbinDb_Lnr";
			PlayerWalkF = "AmovPpneMwlkSoptWbinDf_Lnr";
			PlayerWalkLF = "AmovPpneMwlkSoptWbinDfl_Lnr";
			PlayerWalkRF = "AmovPpneMwlkSoptWbinDfr_Lnr";
			PlayerWalkL = "AmovPpneMwlkSoptWbinDl_Lnr";
			PlayerWalkR = "AmovPpneMwlkSoptWbinDr_Lnr";
			PlayerWalkLB = "AmovPpneMwlkSoptWbinDbl_Lnr";
			PlayerWalkRB = "AmovPpneMwlkSoptWbinDbr_Lnr";
			PlayerWalkB = "AmovPpneMwlkSoptWbinDb_Lnr";
			SlowF = "AmovPpneMrunSnonWbinDf_Lnr";
			SlowLF = "AmovPpneMrunSnonWbinDfl_Lnr";
			SlowRF = "AmovPpneMrunSnonWbinDfr_Lnr";
			SlowL = "AmovPpneMrunSnonWbinDl_Lnr";
			SlowR = "AmovPpneMrunSnonWbinDr_Lnr";
			SlowLB = "AmovPpneMrunSnonWbinDbl_Lnr";
			SlowRB = "AmovPpneMrunSnonWbinDbr_Lnr";
			SlowB = "AmovPpneMrunSnonWbinDb_Lnr";
			PlayerSlowF = "AmovPpneMrunSnonWbinDf_Lnr";
			PlayerSlowLF = "AmovPpneMrunSnonWbinDfl_Lnr";
			PlayerSlowRF = "AmovPpneMrunSnonWbinDfr_Lnr";
			PlayerSlowL = "AmovPpneMrunSnonWbinDl_Lnr";
			PlayerSlowR = "AmovPpneMrunSnonWbinDr_Lnr";
			PlayerSlowLB = "AmovPpneMrunSnonWbinDbl_Lnr";
			PlayerSlowRB = "AmovPpneMrunSnonWbinDbr_Lnr";
			PlayerSlowB = "AmovPpneMrunSnonWbinDb_Lnr";
			FastF = "AmovPpneMevaSnonWbinDf_Lnr";
			FastLF = "AmovPpneMrunSnonWbinDfl_Lnr";
			FastRF = "AmovPpneMrunSnonWbinDfr_Lnr";
			FastL = "AmovPpneMrunSnonWbinDl_Lnr";
			FastR = "AmovPpneMrunSnonWbinDr_Lnr";
			FastLB = "AmovPpneMrunSnonWbinDbl_Lnr";
			FastRB = "AmovPpneMrunSnonWbinDbr_Lnr";
			FastB = "AmovPpneMrunSnonWbinDb_Lnr";
			TactF = "AmovPpneMwlkSoptWbinDf_Lnr";
			TactLF = "AmovPpneMwlkSoptWbinDfl_Lnr";
			TactRF = "AmovPpneMwlkSoptWbinDfr_Lnr";
			TactL = "AmovPpneMwlkSoptWbinDl_Lnr";
			TactR = "AmovPpneMwlkSoptWbinDr_Lnr";
			TactLB = "AmovPpneMwlkSoptWbinDbl_Lnr";
			TactRB = "AmovPpneMwlkSoptWbinDbr_Lnr";
			TactB = "AmovPpneMwlkSoptWbinDb_Lnr";
			PlayerTactF = "AmovPpneMwlkSoptWbinDf_Lnr";
			PlayerTactLF = "AmovPpneMwlkSoptWbinDfl_Lnr";
			PlayerTactRF = "AmovPpneMwlkSoptWbinDfr_Lnr";
			PlayerTactL = "AmovPpneMwlkSoptWbinDl_Lnr";
			PlayerTactR = "AmovPpneMwlkSoptWbinDr_Lnr";
			PlayerTactLB = "AmovPpneMwlkSoptWbinDbl_Lnr";
			PlayerTactRB = "AmovPpneMwlkSoptWbinDbr_Lnr";
			PlayerTactB = "AmovPpneMwlkSoptWbinDb_Lnr";
			EvasiveRight = "";
			EvasiveLeft = "";
		};
		class BinocProneLnrActionsWlkF: BinocProneLnrActions{};
		class BinocProneLnrActionsWlkFL: BinocProneLnrActions{};
		class BinocProneLnrActionsWlkFR: BinocProneLnrActions{};
		class BinocProneLnrActionsWlkR: BinocProneLnrActions{};
		class BinocProneLnrActionsWlkL: BinocProneLnrActions{};
		class BinocProneLnrActionsWlkB: BinocProneLnrActions{};
		class BinocProneLnrActionsWlkBL: BinocProneLnrActions{};
		class BinocProneLnrActionsWlkBR: BinocProneLnrActions{};
		class BinocProneLnrActionsRunF: BinocProneLnrActions{};
		class BinocProneLnrActionsRunFL: BinocProneLnrActions{};
		class BinocProneLnrActionsRunFR: BinocProneLnrActions{};
		class BinocProneLnrActionsRunR: BinocProneLnrActions{};
		class BinocProneLnrActionsRunL: BinocProneLnrActions{};
		class BinocProneLnrActionsRunB: BinocProneLnrActions{};
		class BinocProneLnrActionsRunBL: BinocProneLnrActions{};
		class BinocProneLnrActionsRunBR: BinocProneLnrActions{};
		class BinocProneLnrActionsEvasiveF: BinocProneLnrActions{};
		class BinocStandCivilActions: CivilStandActions
		{
			gestureGo[] = {"GestureGoBStand","Gesture"};
			binocOn = "AwopPercMstpSoptWbinDnon_non";
			down = "AwopPpneMstpSoptWbinDnon_non";
			up = "AwopPknlMstpSoptWbinDnon_non";
			stop = "AwopPercMstpSoptWbinDnon_non";
			stopRelaxed = "AwopPercMstpSoptWbinDnon_non";
			default = "AwopPercMstpSoptWbinDnon_non";
			PlayerStand = "AwopPercMstpSoptWbinDnon_non";
			PlayerCrouch = "AwopPknlMstpSoptWbinDnon_non";
			PlayerProne = "AwopPpneMstpSoptWbinDnon_non";
			upDegree = "ManPosBinocStand";
			TurnL = "AwopPercMstpSoptWbinDnon_non_turnL";
			TurnR = "AwopPercMstpSoptWbinDnon_non_turnR";
			TurnLRelaxed = "AwopPercMstpSoptWbinDnon_non_turnL";
			TurnRRelaxed = "AwopPercMstpSoptWbinDnon_non_turnR";
			WalkF = "AmovPercMwlkSoptWbinDf_non";
			WalkLF = "AmovPercMwlkSoptWbinDfl_non";
			WalkRF = "AmovPercMwlkSoptWbinDfr_non";
			WalkL = "AmovPercMwlkSoptWbinDl_non";
			WalkR = "AmovPercMwlkSoptWbinDr_non";
			WalkLB = "AmovPercMwlkSoptWbinDbl_non";
			WalkRB = "AmovPercMwlkSoptWbinDbr_non";
			WalkB = "AmovPercMwlkSoptWbinDb_non";
			PlayerWalkF = "AmovPercMwlkSoptWbinDf_non";
			PlayerWalkLF = "AmovPercMwlkSoptWbinDfl_non";
			PlayerWalkRF = "AmovPercMwlkSoptWbinDfr_non";
			PlayerWalkL = "AmovPercMwlkSoptWbinDl_non";
			PlayerWalkR = "AmovPercMwlkSoptWbinDr_non";
			PlayerWalkLB = "AmovPercMwlkSoptWbinDbl_non";
			PlayerWalkRB = "AmovPercMwlkSoptWbinDbr_non";
			PlayerWalkB = "AmovPercMwlkSoptWbinDb_non";
			SlowF = "AmovPercMrunSnonWbinDf_non";
			SlowLF = "AmovPercMrunSnonWbinDfl_non";
			SlowRF = "AmovPercMrunSnonWbinDfr_non";
			SlowL = "AmovPercMrunSnonWbinDl_non";
			SlowR = "AmovPercMrunSnonWbinDr_non";
			SlowLB = "AmovPercMrunSnonWbinDbl_non";
			SlowRB = "AmovPercMrunSnonWbinDbr_non";
			SlowB = "AmovPercMrunSnonWbinDb_non";
			PlayerSlowF = "AmovPercMrunSnonWbinDf_non";
			PlayerSlowLF = "AmovPercMrunSnonWbinDfl_non";
			PlayerSlowRF = "AmovPercMrunSnonWbinDfr_non";
			PlayerSlowL = "AmovPercMrunSnonWbinDl_non";
			PlayerSlowR = "AmovPercMrunSnonWbinDr_non";
			PlayerSlowLB = "AmovPercMrunSnonWbinDbl_non";
			PlayerSlowRB = "AmovPercMrunSnonWbinDbr_non";
			PlayerSlowB = "AmovPercMrunSnonWbinDb_non";
			FastF = "AmovPercMevaSnonWbinDf_non";
			FastLF = "AmovPercMevaSnonWbinDfl_non";
			FastRF = "AmovPercMevaSnonWbinDfr_non";
			FastL = "AmovPercMrunSnonWbinDl_non";
			FastR = "AmovPercMrunSnonWbinDr_non";
			FastLB = "AmovPercMrunSnonWbinDbl_non";
			FastRB = "AmovPercMrunSnonWbinDbr_non";
			FastB = "AmovPercMrunSnonWbinDb_non";
			TactF = "AmovPercMwlkSoptWbinDf_non";
			TactLF = "AmovPercMwlkSoptWbinDfl_non";
			TactRF = "AmovPercMwlkSoptWbinDfr_non";
			TactL = "AmovPercMwlkSoptWbinDl_non";
			TactR = "AmovPercMwlkSoptWbinDr_non";
			TactLB = "AmovPercMwlkSoptWbinDbl_non";
			TactRB = "AmovPercMwlkSoptWbinDbr_non";
			TactB = "AmovPercMwlkSoptWbinDb_non";
			PlayerTactF = "AmovPercMwlkSoptWbinDf_non";
			PlayerTactLF = "AmovPercMwlkSoptWbinDfl_non";
			PlayerTactRF = "AmovPercMwlkSoptWbinDfr_non";
			PlayerTactL = "AmovPercMwlkSoptWbinDl_non";
			PlayerTactR = "AmovPercMwlkSoptWbinDr_non";
			PlayerTactLB = "AmovPercMwlkSoptWbinDbl_non";
			PlayerTactRB = "AmovPercMwlkSoptWbinDbr_non";
			PlayerTactB = "AmovPercMwlkSoptWbinDb_non";
			EvasiveRight = "";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
			Diary = "";
			Gear = "";
			GetOver = "";
		};
		class BinocStandCivilActionsWlkF: BinocStandCivilActions
		{
			PlayerCrouch = "AmovPknlMwlkSoptWbinDf_non";
			up = "AmovPknlMwlkSoptWbinDf_non";
		};
		class BinocStandCivilActionsWlkFL: BinocStandCivilActions
		{
			PlayerCrouch = "AmovPknlMwlkSoptWbinDfl_non";
			up = "AmovPknlMwlkSoptWbinDfl_non";
		};
		class BinocStandCivilActionsWlkFR: BinocStandCivilActions
		{
			PlayerCrouch = "AmovPknlMwlkSoptWbinDfr_non";
			up = "AmovPknlMwlkSoptWbinDfr_non";
		};
		class BinocStandCivilActionsWlkR: BinocStandCivilActions
		{
			PlayerCrouch = "AmovPknlMwlkSoptWbinDr_non";
			up = "AmovPknlMwlkSoptWbinDr_non";
		};
		class BinocStandCivilActionsWlkL: BinocStandCivilActions
		{
			PlayerCrouch = "AmovPknlMwlkSoptWbinDl_non";
			up = "AmovPknlMwlkSoptWbinDl_non";
		};
		class BinocStandCivilActionsWlkB: BinocStandCivilActions
		{
			PlayerCrouch = "AmovPknlMwlkSoptWbinDb_non";
			up = "AmovPknlMwlkSoptWbinDB_non";
		};
		class BinocStandCivilActionsWlkBL: BinocStandCivilActions
		{
			PlayerCrouch = "AmovPknlMwlkSoptWbinDbl_non";
			up = "AmovPknlMwlkSoptWbinDbl_non";
		};
		class BinocStandCivilActionsWlkBR: BinocStandCivilActions
		{
			PlayerCrouch = "AmovPknlMwlkSoptWbinDbr_non";
			up = "AmovPknlMwlkSoptWbinDbr_non";
		};
		class BinocStandCivilActionsRunF: BinocStandCivilActions
		{
			PlayerCrouch = "AmovPknlMRunSnonWbinDf_non";
			up = "AmovPknlMRunSnonWbinDf_non";
		};
		class BinocStandCivilActionsRunFL: BinocStandCivilActions
		{
			PlayerCrouch = "AmovPknlMRunSnonWbinDfl_non";
			up = "AmovPknlMRunSnonWbinDfl_non";
		};
		class BinocStandCivilActionsRunFR: BinocStandCivilActions
		{
			PlayerCrouch = "AmovPknlMRunSnonWbinDfr_non";
			up = "AmovPknlMRunSnonWbinDfr_non";
		};
		class BinocStandCivilActionsRunR: BinocStandCivilActions
		{
			PlayerCrouch = "AmovPknlMRunSnonWbinDr_non";
			up = "AmovPknlMRunSnonWbinDr_non";
		};
		class BinocStandCivilActionsRunL: BinocStandCivilActions
		{
			PlayerCrouch = "AmovPknlMRunSnonWbinDl_non";
			up = "AmovPknlMRunSnonWbinDl_non";
		};
		class BinocStandCivilActionsRunB: BinocStandCivilActions
		{
			PlayerCrouch = "AmovPknlMRunSnonWbinDb_non";
			up = "AmovPknlMRunSnonWbinDB_non";
		};
		class BinocStandCivilActionsRunBL: BinocStandCivilActions
		{
			PlayerCrouch = "AmovPknlMRunSnonWbinDbl_non";
			up = "AmovPknlMRunSnonWbinDbl_non";
		};
		class BinocStandCivilActionsRunBR: BinocStandCivilActions
		{
			PlayerCrouch = "AmovPknlMRunSnonWbinDbr_non";
			up = "AmovPknlMRunSnonWbinDbr_non";
		};
		class BinocStandCivilActionsEvasiveF: BinocStandCivilActions
		{
			PlayerCrouch = "AmovPknlMevaSnonWbinDf_non";
			up = "AmovPknlMevaSnonWbinDf_non";
		};
		class BinocStandCivilActionsEvasiveFL: BinocStandCivilActions
		{
			PlayerCrouch = "AmovPknlMevaSnonWbinDfl_non";
			up = "AmovPknlMevaSnonWbinDfl_non";
		};
		class BinocStandCivilActionsEvasiveFR: BinocStandCivilActions
		{
			PlayerCrouch = "AmovPknlMevaSnonWbinDfr_non";
			up = "AmovPknlMevaSnonWbinDfr_non";
		};
		class BinocKneelCivilActions: CivilKneelActions
		{
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
			binocOn = "AwopPknlMstpSoptWbinDnon_non";
			down = "AwopPpneMstpSoptWbinDnon_non";
			up = "AwopPercMstpSoptWbinDnon_non";
			stop = "AwopPknlMstpSoptWbinDnon_non";
			stopRelaxed = "AwopPknlMstpSoptWbinDnon_non";
			default = "AwopPknlMstpSoptWbinDnon_non";
			PlayerStand = "AwopPercMstpSoptWbinDnon_non";
			PlayerCrouch = "AwopPknlMstpSoptWbinDnon_non";
			PlayerProne = "AwopPpneMstpSoptWbinDnon_non";
			upDegree = "ManPosBinoc";
			TurnL = "AwopPknlMstpSoptWbinDnon_non_turnL";
			TurnR = "AwopPknlMstpSoptWbinDnon_non_turnR";
			TurnLRelaxed = "AwopPknlMstpSoptWbinDnon_non_turnL";
			TurnRRelaxed = "AwopPknlMstpSoptWbinDnon_non_turnR";
			WalkF = "AmovPknlMwlkSoptWbinDf_non";
			WalkLF = "AmovPknlMwlkSoptWbinDfl_non";
			WalkRF = "AmovPknlMwlkSoptWbinDfr_non";
			WalkL = "AmovPknlMwlkSoptWbinDl_non";
			WalkR = "AmovPknlMwlkSoptWbinDr_non";
			WalkLB = "AmovPknlMwlkSoptWbinDbl_non";
			WalkRB = "AmovPknlMwlkSoptWbinDbr_non";
			WalkB = "AmovPknlMwlkSoptWbinDb_non";
			PlayerWalkF = "AmovPknlMwlkSoptWbinDf_non";
			PlayerWalkLF = "AmovPknlMwlkSoptWbinDfl_non";
			PlayerWalkRF = "AmovPknlMwlkSoptWbinDfr_non";
			PlayerWalkL = "AmovPknlMwlkSoptWbinDl_non";
			PlayerWalkR = "AmovPknlMwlkSoptWbinDr_non";
			PlayerWalkLB = "AmovPknlMwlkSoptWbinDbl_non";
			PlayerWalkRB = "AmovPknlMwlkSoptWbinDbr_non";
			PlayerWalkB = "AmovPknlMwlkSoptWbinDb_non";
			SlowF = "AmovPknlMrunSnonWbinDf_non";
			SlowLF = "AmovPknlMrunSnonWbinDfl_non";
			SlowRF = "AmovPknlMrunSnonWbinDfr_non";
			SlowL = "AmovPknlMrunSnonWbinDl_non";
			SlowR = "AmovPknlMrunSnonWbinDr_non";
			SlowLB = "AmovPknlMrunSnonWbinDbl_non";
			SlowRB = "AmovPknlMrunSnonWbinDbr_non";
			SlowB = "AmovPknlMrunSnonWbinDb_non";
			PlayerSlowF = "AmovPknlMrunSnonWbinDf_non";
			PlayerSlowLF = "AmovPknlMrunSnonWbinDfl_non";
			PlayerSlowRF = "AmovPknlMrunSnonWbinDfr_non";
			PlayerSlowL = "AmovPknlMrunSnonWbinDl_non";
			PlayerSlowR = "AmovPknlMrunSnonWbinDr_non";
			PlayerSlowLB = "AmovPknlMrunSnonWbinDbl_non";
			PlayerSlowRB = "AmovPknlMrunSnonWbinDbr_non";
			PlayerSlowB = "AmovPknlMrunSnonWbinDb_non";
			FastF = "AmovPknlMevaSnonWbinDf_non";
			FastLF = "AmovPknlMevaSnonWbinDfl_non";
			FastRF = "AmovPknlMevaSnonWbinDfr_non";
			FastL = "AmovPknlMrunSnonWbinDl_non";
			FastR = "AmovPknlMrunSnonWbinDr_non";
			FastLB = "AmovPknlMrunSnonWbinDbl_non";
			FastRB = "AmovPknlMrunSnonWbinDbr_non";
			FastB = "AmovPknlMrunSnonWbinDb_non";
			TactF = "AmovPknlMwlkSoptWbinDf_non";
			TactLF = "AmovPknlMwlkSoptWbinDfl_non";
			TactRF = "AmovPknlMwlkSoptWbinDfr_non";
			TactL = "AmovPknlMwlkSoptWbinDl_non";
			TactR = "AmovPknlMwlkSoptWbinDr_non";
			TactLB = "AmovPknlMwlkSoptWbinDbl_non";
			TactRB = "AmovPknlMwlkSoptWbinDbr_non";
			TactB = "AmovPknlMwlkSoptWbinDb_non";
			PlayerTactF = "AmovPknlMwlkSoptWbinDf_non";
			PlayerTactLF = "AmovPknlMwlkSoptWbinDfl_non";
			PlayerTactRF = "AmovPknlMwlkSoptWbinDfr_non";
			PlayerTactL = "AmovPknlMwlkSoptWbinDl_non";
			PlayerTactR = "AmovPknlMwlkSoptWbinDr_non";
			PlayerTactLB = "AmovPknlMwlkSoptWbinDbl_non";
			PlayerTactRB = "AmovPknlMwlkSoptWbinDbr_non";
			PlayerTactB = "AmovPknlMwlkSoptWbinDb_non";
			EvasiveRight = "";
			EvasiveLeft = "";
			Diary = "";
			Gear = "";
		};
		class BinocKneelCivilActionsWlkF: BinocKneelCivilActions
		{
			PlayerCrouch = "AmovPercMwlkSoptWbinDf_non";
			up = "AmovPercMwlkSoptWbinDf_non";
		};
		class BinocKneelCivilActionsWlkFL: BinocKneelCivilActions
		{
			PlayerCrouch = "AmovPercMwlkSoptWbinDfl_non";
			up = "AmovPercMwlkSoptWbinDfl_non";
		};
		class BinocKneelCivilActionsWlkFR: BinocKneelCivilActions
		{
			PlayerCrouch = "AmovPercMwlkSoptWbinDfr_non";
			up = "AmovPercMwlkSoptWbinDfr_non";
		};
		class BinocKneelCivilActionsWlkR: BinocKneelCivilActions
		{
			PlayerCrouch = "AmovPercMwlkSoptWbinDr_non";
			up = "AmovPercMwlkSoptWbinDr_non";
		};
		class BinocKneelCivilActionsWlkL: BinocKneelCivilActions
		{
			PlayerCrouch = "AmovPercMwlkSoptWbinDl_non";
			up = "AmovPercMwlkSoptWbinDl_non";
		};
		class BinocKneelCivilActionsWlkB: BinocKneelCivilActions
		{
			PlayerCrouch = "AmovPercMwlkSoptWbinDb_non";
			up = "AmovPercMwlkSoptWbinDB_non";
		};
		class BinocKneelCivilActionsWlkBL: BinocKneelCivilActions
		{
			PlayerCrouch = "AmovPercMwlkSoptWbinDbl_non";
			up = "AmovPercMwlkSoptWbinDbl_non";
		};
		class BinocKneelCivilActionsWlkBR: BinocKneelCivilActions
		{
			PlayerCrouch = "AmovPercMwlkSoptWbinDbr_non";
			up = "AmovPercMwlkSoptWbinDbr_non";
		};
		class BinocKneelCivilActionsRunF: BinocKneelCivilActions
		{
			PlayerCrouch = "AmovPercMRunSnonWbinDf_non";
			up = "AmovPercMRunSnonWbinDf_non";
		};
		class BinocKneelCivilActionsRunFL: BinocKneelCivilActions
		{
			PlayerCrouch = "AmovPercMRunSnonWbinDfl_non";
			up = "AmovPercMRunSnonWbinDfl_non";
		};
		class BinocKneelCivilActionsRunFR: BinocKneelCivilActions
		{
			PlayerCrouch = "AmovPercMRunSnonWbinDfr_non";
			up = "AmovPercMRunSnonWbinDfr_non";
		};
		class BinocKneelCivilActionsRunR: BinocKneelCivilActions
		{
			PlayerCrouch = "AmovPercMRunSnonWbinDr_non";
			up = "AmovPercMRunSnonWbinDr_non";
		};
		class BinocKneelCivilActionsRunL: BinocKneelCivilActions
		{
			PlayerCrouch = "AmovPercMRunSnonWbinDl_non";
			up = "AmovPercMRunSnonWbinDl_non";
		};
		class BinocKneelCivilActionsRunB: BinocKneelCivilActions
		{
			PlayerCrouch = "AmovPercMRunSnonWbinDb_non";
			up = "AmovPercMRunSnonWbinDB_non";
		};
		class BinocKneelCivilActionsRunBL: BinocKneelCivilActions
		{
			PlayerCrouch = "AmovPercMRunSnonWbinDbl_non";
			up = "AmovPercMRunSnonWbinDbl_non";
		};
		class BinocKneelCivilActionsRunBR: BinocKneelCivilActions
		{
			PlayerCrouch = "AmovPercMRunSnonWbinDbr_non";
			up = "AmovPercMRunSnonWbinDbr_non";
		};
		class BinocKneelCivilActionsEvasiveF: BinocKneelCivilActions
		{
			PlayerCrouch = "AmovPercMevaSnonWbinDf_non";
			up = "AmovPercMevaSnonWbinDf_non";
		};
		class BinocKneelCivilActionsEvasiveFL: BinocKneelCivilActions
		{
			PlayerCrouch = "AmovPercMevaSnonWbinDfl_non";
			up = "AmovPercMevaSnonWbinDfl_non";
		};
		class BinocKneelCivilActionsEvasiveFR: BinocKneelCivilActions
		{
			PlayerCrouch = "AmovPercMevaSnonWbinDfr_non";
			up = "AmovPercMevaSnonWbinDfr_non";
		};
		class BinocProneCivilActions: CivilProneActions
		{
			AdjustF = "";
			AdjustB = "";
			binocOn = "AwopPpneMstpSoptWbinDnon_non";
			stop = "AwopPpneMstpSoptWbinDnon_non";
			stopRelaxed = "AwopPpneMstpSoptWbinDnon_non";
			default = "AwopPpneMstpSoptWbinDnon_non";
			PlayerStand = "AwopPercMstpSoptWbinDnon_non";
			PlayerCrouch = "AwopPknlMstpSoptWbinDnon_non";
			PlayerProne = "AwopPpneMstpSoptWbinDnon_non";
			upDegree = "ManPosBinocLying";
			down = "AwopPercMstpSoptWbinDnon_non";
			up = "AwopPknlMstpSoptWbinDnon_non";
			TurnL = "AwopPpneMstpSoptWbinDnon_non_turnL";
			TurnR = "AwopPpneMstpSoptWbinDnon_non_turnR";
			TurnLRelaxed = "AwopPpneMstpSoptWbinDnon_non_turnL";
			TurnRRelaxed = "AwopPpneMstpSoptWbinDnon_non_turnR";
			WalkF = "AmovPpneMwlkSoptWbinDf_non";
			WalkLF = "AmovPpneMwlkSoptWbinDfl_non";
			WalkRF = "AmovPpneMwlkSoptWbinDfr_non";
			WalkL = "AmovPpneMwlkSoptWbinDl_non";
			WalkR = "AmovPpneMwlkSoptWbinDr_non";
			WalkLB = "AmovPpneMwlkSoptWbinDbl_non";
			WalkRB = "AmovPpneMwlkSoptWbinDbr_non";
			WalkB = "AmovPpneMwlkSoptWbinDb_non";
			PlayerWalkF = "AmovPpneMwlkSoptWbinDf_non";
			PlayerWalkLF = "AmovPpneMwlkSoptWbinDfl_non";
			PlayerWalkRF = "AmovPpneMwlkSoptWbinDfr_non";
			PlayerWalkL = "AmovPpneMwlkSoptWbinDl_non";
			PlayerWalkR = "AmovPpneMwlkSoptWbinDr_non";
			PlayerWalkLB = "AmovPpneMwlkSoptWbinDbl_non";
			PlayerWalkRB = "AmovPpneMwlkSoptWbinDbr_non";
			PlayerWalkB = "AmovPpneMwlkSoptWbinDb_non";
			SlowF = "AmovPpneMrunSnonWbinDf_non";
			SlowLF = "AmovPpneMrunSnonWbinDfl_non";
			SlowRF = "AmovPpneMrunSnonWbinDfr_non";
			SlowL = "AmovPpneMrunSnonWbinDl_non";
			SlowR = "AmovPpneMrunSnonWbinDr_non";
			SlowLB = "AmovPpneMrunSnonWbinDbl_non";
			SlowRB = "AmovPpneMrunSnonWbinDbr_non";
			SlowB = "AmovPpneMrunSnonWbinDb_non";
			PlayerSlowF = "AmovPpneMrunSnonWbinDf_non";
			PlayerSlowLF = "AmovPpneMrunSnonWbinDfl_non";
			PlayerSlowRF = "AmovPpneMrunSnonWbinDfr_non";
			PlayerSlowL = "AmovPpneMrunSnonWbinDl_non";
			PlayerSlowR = "AmovPpneMrunSnonWbinDr_non";
			PlayerSlowLB = "AmovPpneMrunSnonWbinDbl_non";
			PlayerSlowRB = "AmovPpneMrunSnonWbinDbr_non";
			PlayerSlowB = "AmovPpneMrunSnonWbinDb_non";
			FastF = "AmovPpneMevaSnonWbinDf_non";
			FastLF = "AmovPpneMrunSnonWbinDfl_non";
			FastRF = "AmovPpneMrunSnonWbinDfr_non";
			FastL = "AmovPpneMrunSnonWbinDl_non";
			FastR = "AmovPpneMrunSnonWbinDr_non";
			FastLB = "AmovPpneMrunSnonWbinDbl_non";
			FastRB = "AmovPpneMrunSnonWbinDbr_non";
			FastB = "AmovPpneMrunSnonWbinDb_non";
			TactF = "AmovPpneMwlkSoptWbinDf_non";
			TactLF = "AmovPpneMwlkSoptWbinDfl_non";
			TactRF = "AmovPpneMwlkSoptWbinDfr_non";
			TactL = "AmovPpneMwlkSoptWbinDl_non";
			TactR = "AmovPpneMwlkSoptWbinDr_non";
			TactLB = "AmovPpneMwlkSoptWbinDbl_non";
			TactRB = "AmovPpneMwlkSoptWbinDbr_non";
			TactB = "AmovPpneMwlkSoptWbinDb_non";
			PlayerTactF = "AmovPpneMwlkSoptWbinDf_non";
			PlayerTactLF = "AmovPpneMwlkSoptWbinDfl_non";
			PlayerTactRF = "AmovPpneMwlkSoptWbinDfr_non";
			PlayerTactL = "AmovPpneMwlkSoptWbinDl_non";
			PlayerTactR = "AmovPpneMwlkSoptWbinDr_non";
			PlayerTactLB = "AmovPpneMwlkSoptWbinDbl_non";
			PlayerTactRB = "AmovPpneMwlkSoptWbinDbr_non";
			PlayerTactB = "AmovPpneMwlkSoptWbinDb_non";
			EvasiveRight = "";
			EvasiveLeft = "";
		};
		class BinocProneCivilActionsWlkF: BinocProneCivilActions{};
		class BinocProneCivilActionsWlkFL: BinocProneCivilActions{};
		class BinocProneCivilActionsWlkFR: BinocProneCivilActions{};
		class BinocProneCivilActionsWlkR: BinocProneCivilActions{};
		class BinocProneCivilActionsWlkL: BinocProneCivilActions{};
		class BinocProneCivilActionsWlkB: BinocProneCivilActions{};
		class BinocProneCivilActionsWlkBL: BinocProneCivilActions{};
		class BinocProneCivilActionsWlkBR: BinocProneCivilActions{};
		class BinocProneCivilActionsRunF: BinocProneCivilActions{};
		class BinocProneCivilActionsRunFL: BinocProneCivilActions{};
		class BinocProneCivilActionsRunFR: BinocProneCivilActions{};
		class BinocProneCivilActionsRunR: BinocProneCivilActions{};
		class BinocProneCivilActionsRunL: BinocProneCivilActions{};
		class BinocProneCivilActionsRunB: BinocProneCivilActions{};
		class BinocProneCivilActionsRunBL: BinocProneCivilActions{};
		class BinocProneCivilActionsRunBR: BinocProneCivilActions{};
		class BinocProneCivilActionsEvasiveF: BinocProneCivilActions{};
		class RifleProneActions_injured: RifleProneActions
		{
			stop = "";
			default = "";
			stopRelaxed = "";
			turnL = "";
			turnR = "";
			turnLRelaxed = "";
			turnRRelaxed = "";
			reloadMagazine = "";
			reloadGM6 = "";
			reloadMGun = "";
			reloadMortar = "";
			throwPrepare = "";
			throwGrenade[] = {"GestureThrowGrenade","Gesture"};
			WalkF = "AmovPpneMsprSlowWrflDf_injured";
			WalkLF = "";
			WalkRF = "";
			WalkL = "";
			WalkR = "";
			WalkLB = "";
			WalkRB = "";
			WalkB = "";
			PlayerWalkF = "AmovPpneMsprSlowWrflDf_injured";
			PlayerWalkLF = "";
			PlayerWalkRF = "";
			PlayerWalkL = "";
			PlayerWalkR = "";
			PlayerWalkLB = "";
			PlayerWalkRB = "";
			PlayerWalkB = "";
			SlowF = "AmovPpneMsprSlowWrflDf_injured";
			SlowLF = "";
			SlowRF = "";
			SlowL = "";
			SlowR = "";
			SlowLB = "";
			SlowRB = "";
			SlowB = "";
			PlayerSlowF = "AmovPpneMsprSlowWrflDf_injured";
			PlayerSlowLF = "";
			PlayerSlowRF = "";
			PlayerSlowL = "";
			PlayerSlowR = "";
			PlayerSlowLB = "";
			PlayerSlowRB = "";
			PlayerSlowB = "";
			FastF = "AmovPpneMsprSlowWrflDf_injured";
			FastLF = "";
			FastRF = "";
			FastL = "";
			FastR = "";
			FastLB = "";
			FastRB = "";
			FastB = "";
			EvasiveLeft = "";
			EvasiveRight = "";
			down = "";
			up = "AmovPpneMsprSlowWrflDf_injured";
			weaponOn = "";
			weaponOff = "";
			binocOn = "";
			binocOff = "";
			handGunOn = "";
			takeFlag = "";
			putDown = "";
			treated = "AmovPpneMstpSrasWrflDnon_injuredHealed";
			healingFinished = "AmovPpneMstpSrasWrflDnon";
			Combat = "";
			Lying = "";
			Stand = "AmovPpneMsprSlowWrflDf_injured";
			Crouch = "";
			CanNotMove = "";
			Civil = "";
			CivilLying = "";
			FireNotPossible = "";
			strokeGun = "";
			turnSpeed = 0.4;
			limitFast = 0.5;
			PlayerProne = "AmovPpneMstpSrasWrflDnon";
		};
		class HealActionBase: RifleKneelActions
		{
			updegree = "ManPosHealing";
			toAgony = "AinjPpneMstpSnonWrflDnon";
			healStop = "AinvPknlMstpSnonWrflDnon_medicEnd";
			healStart = "AinvPknlMstpSnonWrflDnon_medic";
			healStartUp = "AinvPknlMstpSnonWrflDnon_medicUp";
			healingFinished = "AinjPpneMstpSnonWrflDnon";
			medicStop = "AinvPknlMstpSnonWrflDnon_medicEnd";
			Stop = "AinvPknlMstpSnonWrflDnon_medic0s";
			StopRelaxed = "AinvPknlMstpSnonWrflDnon_medic0s";
			Default = "AinvPknlMstpSnonWrflDnon_medic";
			SceneCommanderTalk = "";
			SceneSleepC = "";
			SceneSleepB = "";
			SceneSleepA = "";
			SceneSitUnarm_R = "";
			SceneSitUnarm_L = "";
			SceneSitRfl_L = "";
			SceneSitRfl_R = "";
			ScenePoslechVelitele = "";
			dooraction = "";
			ReloadMortar = "";
			ThrowPrepare = "";
			startSwim = "";
			surfaceSwim = "";
			bottomSwim = "";
			StartDive = "";
			Up = "";
			Down = "";
			Lying = "";
			Stand = "";
			Combat = "AmovPercMstpSrasWrflDnon";
			Crouch = "";
			CanNotMove = "";
			Civil = "";
			CivilLying = "";
			FireNotPossible = "";
			WeaponOn = "";
			WeaponOff = "";
			StrokeGun = "";
			saluteOff = "";
			GetOver = "";
			Diary = "";
			Surrender = "";
			Gear = "";
			BinocOn = "";
			BinocOff = "";
			PutDown = "";
			LadderOnDown = "";
			LadderOnUp = "";
			GetInLow = "";
			GetInMedium = "";
			GetInHigh = "";
			GetInSDV = "";
			GetOutPara = "";
			GetOutLow = "";
			GetOutMedium = "";
			GetOutHigh = "";
			GetOutHighZamak = "";
			GetOutHighHemtt = "";
			GetOutSDV = "";
			TakeFlag = "";
			TurnL = "AinvPknlMstpSnonWrflDnon_medic0S";
			TurnR = "AinvPknlMstpSnonWrflDnon_medic0S";
			TurnLRelaxed = "AinvPknlMstpSnonWrflDnon_medic0S";
			TurnRRelaxed = "AinvPknlMstpSnonWrflDnon_medic0S";
		};
		class HealSelfActionBase: HealActionBase
		{
			Stop = "AmovPknlMstpSrasWrflDnon";
			StopRelaxed = "AmovPknlMstpSrasWrflDnon";
			medicStop = "AmovPknlMstpSrasWrflDnon";
			medicStartUp = "AmovPknlMstpSrasWrflDnon";
		};
		class HealSelfActionProne: HealSelfActionBase
		{
			Stop = "AmovPpneMstpSrasWrflDnon";
			StopRelaxed = "AmovPpneMstpSrasWrflDnon";
			medicStop = "AmovPpneMstpSrasWrflDnon";
			medicStartUp = "AmovPpneMstpSrasWrflDnon";
		};
		class HealSelfLauncherActionBase: HealActionBase
		{
			Stop = "AmovPknlMstpSrasWlnrDnon";
			StopRelaxed = "AmovPknlMstpSrasWlnrDnon";
			medicStop = "AmovPknlMstpSrasWlnrDnon";
			medicStartUp = "AmovPknlMstpSrasWlnrDnon";
		};
		class HealSelfPistolActionBase: HealActionBase
		{
			Stop = "AmovPknlMstpSrasWpstDnon";
			StopRelaxed = "AmovPknlMstpSrasWpstDnon";
			medicStop = "AmovPknlMstpSrasWpstDnon";
			medicStartUp = "AmovPknlMstpSrasWpstDnon";
		};
		class HealSelfPistolActionProne: HealSelfPistolActionBase
		{
			Stop = "AmovPpneMstpSrasWpstDnon";
			StopRelaxed = "AmovPpneMstpSrasWpstDnon";
			medicStop = "AmovPpneMstpSrasWpstDnon";
			medicStartUp = "AmovPpneMstpSrasWpstDnon";
		};
		class HealSelfCivilActionBase: HealActionBase
		{
			Stop = "AmovPknlMstpSnonWnonDnon";
			StopRelaxed = "AmovPknlMstpSnonWnonDnon";
			medicStop = "AmovPknlMstpSnonWnonDnon";
			medicStartUp = "AmovPknlMstpSnonWnonDnon";
			Civil = "AmovPknlMstpSnonWnonDnon";
		};
		class HealSelfCivilActionProne: HealSelfCivilActionBase
		{
			Stop = "AmovPpneMstpSnonWnonDnon";
			StopRelaxed = "AmovPpneMstpSnonWnonDnon";
			medicStop = "AmovPpneMstpSnonWnonDnon";
			medicStartUp = "AmovPpneMstpSnonWnonDnon";
			Civil = "AmovPpneMstpSnonWnonDnon";
		};
		class HealActionBaseDr: HealActionBase
		{
			Stop = "AinvPknlMstpSnonWrflDr_medic0S";
			StopRelaxed = "AinvPknlMstpSnonWrflDr_medic0S";
			TurnL = "AinvPknlMstpSnonWrflDr_medic0S";
			TurnR = "AinvPknlMstpSnonWrflDr_medic0S";
			TurnLRelaxed = "AinvPknlMstpSnonWrflDr_medic0S";
			TurnRRelaxed = "AinvPknlMstpSnonWrflDr_medic0S";
		};
		class HealActionsNon: CivilKneelActions_gear
		{
			upDegree = "ManPosHealing";
			turnSpeed = 0;
			TestDriver = "";
			TestDriverOut = "";
			TestGunner = "";
			LadderOnUp = "";
			LadderOnDown = "";
			medicStart = "AinvPknlMstpSnonWnonDnon_medic";
			medicStartUp = "AinvPknlMstpSnonWrflDnon_medicUp";
			medicMove = "";
			toAgony = "AinjPpneMstpSnonWrflDnon";
			carriedStill = "AinjPfalMstpSnonWnonDnon_carried_still";
			grabCarry = "AcinPknlMstpSnonWnonDnon_AcinPercMrunSnonWnonDnon";
			PlayerWalkB = "AinvPknlMstpSnonWnonDnon_medicEnd";
			PlayerSlowB = "AinvPknlMstpSnonWnonDnon_medicEnd";
			WalkB = "AinvPknlMstpSnonWnonDnon_medicEnd";
			SlowB = "AinvPknlMstpSnonWnonDnon_medicEnd";
			FastB = "AinvPknlMstpSnonWnonDnon_medicEnd";
			Down = "AinvPknlMstpSnonWnonDnon_medicEnd";
			Stand = "AinvPknlMstpSnonWnonDnon_medicEnd";
			Stop = "AmovPknlMstpSnonWnonDnon";
			StopRelaxed = "AmovPknlMstpSnonWnonDnon";
		};
		class HealActionsNonDr: HealActionsNon
		{
			Stop = "AinvPknlMstpSnonWnonDr_medic0s";
			StopRelaxed = "AinvPknlMstpSnonWnonDr_medic0s";
		};
		class HealSelfActionsNon: HealActionsNon{};
		class MoveWithInjuredMan: NoActions
		{
			upDegree = "ManPosStand";
			stance = "ManStanceCrouch";
			stop = "Helper_SwitchToCarryRfl";
			default = "AcinPknlMstpSrasWrflDnon";
			WalkLB = "AcinPknlMwlkSrasWrflDb";
			WalkRB = "AcinPknlMwlkSrasWrflDb";
			WalkB = "AcinPknlMwlkSrasWrflDb";
			PlayerWalkLB = "AcinPknlMwlkSrasWrflDb";
			PlayerWalkRB = "AcinPknlMwlkSrasWrflDb";
			PlayerWalkB = "AcinPknlMwlkSrasWrflDb";
			SlowLB = "AcinPknlMwlkSrasWrflDb";
			SlowRB = "AcinPknlMwlkSrasWrflDb";
			SlowB = "AcinPknlMwlkSrasWrflDb";
			PlayerSlowLB = "AcinPknlMwlkSrasWrflDb";
			PlayerSlowRB = "AcinPknlMwlkSrasWrflDb";
			PlayerSlowB = "AcinPknlMwlkSrasWrflDb";
			turnSpeed = 2;
			grabCarry = "AcinPknlMstpSrasWrflDnon_AcinPercMrunSrasWrflDnon";
			startSwim = "AswmPercMrunSnonWnonDf";
			surfaceSwim = "AsswPercMrunSnonWnonDf";
			bottomSwim = "AbswPercMrunSnonWnonDf";
			startDive = "AdvePercMstpSnonWnonDnon";
			SurfaceDive = "AsdvPercMstpSnonWnonDnon";
			BottomDive = "AbdvPercMstpSnonWnonDnon";
		};
		class MoveWithInjuredMan_helperRfl: MoveWithInjuredMan
		{
			Combat = "AcinPercMstpSrasWrflDnon";
			WalkF = "AcinPercMstpSrasWrflDnon";
			WalkLF = "AcinPercMstpSrasWrflDnon";
			WalkRF = "AcinPercMstpSrasWrflDnon";
			WalkL = "AcinPercMstpSrasWrflDnon";
			WalkR = "AcinPercMstpSrasWrflDnon";
			WalkLB = "AcinPercMstpSrasWrflDnon";
			WalkRB = "AcinPercMstpSrasWrflDnon";
			WalkB = "AcinPercMstpSrasWrflDnon";
			PlayerWalkF = "AcinPercMstpSrasWrflDnon";
			PlayerWalkLF = "AcinPercMstpSrasWrflDnon";
			PlayerWalkRF = "AcinPercMstpSrasWrflDnon";
			PlayerWalkL = "AcinPercMstpSrasWrflDnon";
			PlayerWalkR = "AcinPercMstpSrasWrflDnon";
			PlayerWalkLB = "AcinPercMstpSrasWrflDnon";
			PlayerWalkRB = "AcinPercMstpSrasWrflDnon";
			PlayerWalkB = "AcinPercMstpSrasWrflDnon";
			SlowF = "AcinPercMstpSrasWrflDnon";
			SlowLF = "AcinPercMstpSrasWrflDnon";
			SlowRF = "AcinPercMstpSrasWrflDnon";
			SlowL = "AcinPercMstpSrasWrflDnon";
			SlowR = "AcinPercMstpSrasWrflDnon";
			SlowLB = "AcinPercMstpSrasWrflDnon";
			SlowRB = "AcinPercMstpSrasWrflDnon";
			SlowB = "AcinPercMstpSrasWrflDnon";
			PlayerSlowF = "AcinPercMstpSrasWrflDnon";
			PlayerSlowLF = "AcinPercMstpSrasWrflDnon";
			PlayerSlowRF = "AcinPercMstpSrasWrflDnon";
			PlayerSlowL = "AcinPercMstpSrasWrflDnon";
			PlayerSlowR = "AcinPercMstpSrasWrflDnon";
			PlayerSlowLB = "AcinPercMstpSrasWrflDnon";
			PlayerSlowRB = "AcinPercMstpSrasWrflDnon";
			PlayerSlowB = "AcinPercMstpSrasWrflDnon";
			FastF = "AcinPercMstpSrasWrflDnon";
			FastLF = "AcinPercMstpSrasWrflDnon";
			FastRF = "AcinPercMstpSrasWrflDnon";
			FastL = "AcinPercMstpSrasWrflDnon";
			FastR = "AcinPercMstpSrasWrflDnon";
			FastLB = "AcinPercMstpSrasWrflDnon";
			FastRB = "AcinPercMstpSrasWrflDnon";
			FastB = "AcinPercMstpSrasWrflDnon";
			TactF = "AcinPercMstpSrasWrflDnon";
			TactLF = "AcinPercMstpSrasWrflDnon";
			TactRF = "AcinPercMstpSrasWrflDnon";
			TactL = "AcinPercMstpSrasWrflDnon";
			TactR = "AcinPercMstpSrasWrflDnon";
			TactLB = "AcinPercMstpSrasWrflDnon";
			TactRB = "AcinPercMstpSrasWrflDnon";
			TactB = "AcinPercMstpSrasWrflDnon";
			PlayerTactF = "AcinPercMstpSrasWrflDnon";
			PlayerTactLF = "AcinPercMstpSrasWrflDnon";
			PlayerTactRF = "AcinPercMstpSrasWrflDnon";
			PlayerTactL = "AcinPercMstpSrasWrflDnon";
			PlayerTactR = "AcinPercMstpSrasWrflDnon";
			PlayerTactLB = "AcinPercMstpSrasWrflDnon";
			PlayerTactRB = "AcinPercMstpSrasWrflDnon";
			PlayerTactB = "AcinPercMstpSrasWrflDnon";
		};
		class MoveWithInjuredMan_helperNon: MoveWithInjuredMan_helperRfl
		{
			medicStart = "AinvPknlMstpSnonWnonDnon_medic";
			medicStartUp = "AinvPknlMstpSnonWrflDnon_medicUp";
			grabCarry = "AcinPercMstpSnonWnonDnon";
			grabDrag = "AmovPercMstpSnonWnonDnon_AcinPknlMwlkSnonWnonDb_2";
			WalkLB = "AcinPknlMwlkSnonWnonDb";
			WalkRB = "AcinPknlMwlkSnonWnonDb";
			WalkB = "AcinPknlMwlkSnonWnonDb";
			PlayerWalkLB = "AcinPknlMwlkSnonWnonDb";
			PlayerWalkRB = "AcinPknlMwlkSnonWnonDb";
			PlayerWalkB = "AcinPknlMwlkSnonWnonDb";
			SlowLB = "AcinPknlMwlkSnonWnonDb";
			SlowRB = "AcinPknlMwlkSnonWnonDb";
			SlowB = "AcinPknlMwlkSnonWnonDb";
			PlayerSlowLB = "AcinPknlMwlkSnonWnonDb";
			PlayerSlowRB = "AcinPknlMwlkSnonWnonDb";
			PlayerSlowB = "AcinPknlMwlkSnonWnonDb";
			FastLB = "AcinPknlMwlkSnonWnonDb";
			FastB = "AcinPknlMwlkSnonWnonDb";
			FastRB = "AcinPknlMwlkSnonWnonDb";
			PlayerStand = "Helper_SwitchToCarryNon";
			Civil = "AcinPknlMstpSrasWrflDnon";
		};
		class MoveWithInjuredMan_helperNonPst: MoveWithInjuredMan_helperNon
		{
			updegree = "ManPosHandGunStand";
			Default = "AcinPknlMstpSnonWpstDnon_AcinPercMrunSnonWpstDnon";
			Civil = "AcinPknlMstpSnonWpstDnon_AcinPercMrunSnonWpstDnon";
			HandGunOn = "AcinPercMstpSnonWpstDnon";
			stop = "AcinPknlMstpSnonWpstDnon_AcinPercMrunSnonWpstDnon";
			grabCarry = "AcinPercMstpSnonWpstDnon";
		};
		class MoveWithInjuredManDragger: MoveWithInjuredMan
		{
			released = "AcinPknlMstpSrasWrflDnon_AmovPknlMstpSrasWrflDnon";
			Up = "Helper_SwitchToCarryRfl";
			Stop = "AcinPknlMstpSrasWrflDnon";
			StopRelaxed = "AcinPknlMstpSrasWrflDnon";
		};
		class MoveWithInjuredManDraggerRfl: MoveWithInjuredManDragger
		{
			WalkF = "AcinPknlMstpSrasWrflDnon";
			WalkLF = "AcinPknlMstpSrasWrflDnon";
			WalkRF = "AcinPknlMstpSrasWrflDnon";
			WalkL = "AcinPknlMstpSrasWrflDnon";
			WalkR = "AcinPknlMstpSrasWrflDnon";
			PlayerWalkF = "AcinPknlMstpSrasWrflDnon";
			PlayerWalkLF = "AcinPknlMstpSrasWrflDnon";
			PlayerWalkRF = "AcinPknlMstpSrasWrflDnon";
			PlayerWalkL = "AcinPknlMstpSrasWrflDnon";
			PlayerWalkR = "AcinPknlMstpSrasWrflDnon";
			SlowF = "AcinPknlMstpSrasWrflDnon";
			SlowLF = "AcinPknlMstpSrasWrflDnon";
			SlowRF = "AcinPknlMstpSrasWrflDnon";
			SlowL = "AcinPknlMstpSrasWrflDnon";
			SlowR = "AcinPknlMstpSrasWrflDnon";
			PlayerSlowF = "AcinPknlMstpSrasWrflDnon";
			PlayerSlowLF = "AcinPknlMstpSrasWrflDnon";
			PlayerSlowRF = "AcinPknlMstpSrasWrflDnon";
			PlayerSlowL = "AcinPknlMstpSrasWrflDnon";
			PlayerSlowR = "AcinPknlMstpSrasWrflDnon";
			FastF = "AcinPknlMstpSrasWrflDnon";
			FastLF = "AcinPknlMstpSrasWrflDnon";
			FastRF = "AcinPknlMstpSrasWrflDnon";
			FastL = "AcinPknlMstpSrasWrflDnon";
			FastR = "AcinPknlMstpSrasWrflDnon";
			EvasiveLeft = "AcinPknlMstpSrasWrflDnon";
			EvasiveRight = "AcinPknlMstpSrasWrflDnon";
			agonyStart = "AinjPpneMstpSnonWrflDnon";
			agonyStop = "AmovPpneMstpSrasWrflDnon";
			medicStop = "AinvPknlMstpSnonWrflDnon_medicEnd";
			medicStart = "AinvPknlMstpSnonWrflDnon_medic";
			medicStartUp = "AinvPknlMstpSnonWrflDnon_medicUp";
			released = "AmovPknlMstpSrasWrflDnon";
			medicStartRightSide = "AinvPknlMstpSnonWrflDr_medic0S";
		};
		class MoveWithInjuredManDraggerPst: MoveWithInjuredManDragger
		{
			upDegree = "ManPosHandGunStand";
			grabDrag = "AmovPercMstpSrasWpstDnon_AcinPknlMwlkSnonWpstDb_2";
			grabDragged = "AinjPpneMrunSnonWnonDb_grab";
			released = "AmovPknlMstpSrasWpstDnon";
			Stop = "AcinPknlMstpSnonWpstDnon";
			StopRelaxed = "AcinPknlMstpSnonWpstDnon";
			WalkLB = "AcinPknlMwlkSnonWpstDb";
			WalkRB = "AcinPknlMwlkSnonWpstDb";
			WalkB = "AcinPknlMwlkSnonWpstDb";
			PlayerWalkLB = "AcinPknlMwlkSnonWpstDb";
			PlayerWalkRB = "AcinPknlMwlkSnonWpstDb";
			PlayerWalkB = "AcinPknlMwlkSnonWpstDb";
			SlowLB = "AcinPknlMwlkSnonWpstDb";
			SlowRB = "AcinPknlMwlkSnonWpstDb";
			SlowB = "AcinPknlMwlkSnonWpstDb";
			PlayerSlowLB = "AcinPknlMwlkSnonWpstDb";
			PlayerSlowRB = "AcinPknlMwlkSnonWpstDb";
			PlayerSlowB = "AcinPknlMwlkSnonWpstDb";
			FastLB = "AcinPknlMwlkSnonWpstDb";
			FastRB = "AcinPknlMwlkSnonWpstDb";
			FastB = "AcinPknlMwlkSnonWpstDb";
			Up = "";
			grabCarry = "Helper_SwitchToCarrynon_pst";
			Default = "AcinPknlMstpSnonWpstDnon";
			HandGunOn = "AcinPknlMstpSnonWpstDnon";
		};
		class MoveWithInjuredManDraggerNon: MoveWithInjuredManDragger
		{
			upDegree = "ManPosNoWeapon";
			grabDrag = "AmovPercMstpSnonWnonDnon_AcinPknlMwlkSnonWnonDb_2";
			grabDragged = "AinjPpneMrunSnonWnonDb_grab";
			released = "AmovPknlMstpSnonWnonDnon";
			Stop = "AcinPknlMstpSnonWnonDnon";
			StopRelaxed = "AcinPknlMstpSnonWnonDnon";
			WalkLB = "AcinPknlMwlkSnonWnonDb";
			WalkRB = "AcinPknlMwlkSnonWnonDb";
			WalkB = "AcinPknlMwlkSnonWnonDb";
			PlayerWalkLB = "AcinPknlMwlkSnonWnonDb";
			PlayerWalkRB = "AcinPknlMwlkSnonWnonDb";
			PlayerWalkB = "AcinPknlMwlkSnonWnonDb";
			SlowLB = "AcinPknlMwlkSnonWnonDb";
			SlowRB = "AcinPknlMwlkSnonWnonDb";
			SlowB = "AcinPknlMwlkSnonWnonDb";
			PlayerSlowLB = "AcinPknlMwlkSnonWnonDb";
			PlayerSlowRB = "AcinPknlMwlkSnonWnonDb";
			PlayerSlowB = "AcinPknlMwlkSnonWnonDb";
			FastLB = "AcinPknlMwlkSnonWnonDb";
			FastRB = "AcinPknlMwlkSnonWnonDb";
			FastB = "AcinPknlMwlkSnonWnonDb";
			Up = "";
			grabCarry = "Helper_SwitchToCarrynon";
			Default = "AcinPknlMstpSnonWnonDnon";
			HandGunOn = "AcinPknlMstpSnonWnonDnon";
		};
		class MoveWithInjuredManCarrier: MoveWithInjuredMan
		{
			Stop = "AcinPercMstpSrasWrflDnon";
			WalkLB = "";
			WalkRB = "";
			WalkB = "";
			PlayerWalkLB = "";
			PlayerWalkRB = "";
			PlayerWalkB = "";
			SlowLB = "";
			SlowRB = "";
			SlowB = "";
			PlayerSlowLB = "";
			PlayerSlowRB = "";
			PlayerSlowB = "";
			Default = "AcinPercMstpSrasWrflDnon";
			LadderOnDown = "";
			LadderOnUp = "";
			TestDriver = "";
			TestDriverOut = "";
			TestGunner = "";
			WalkF = "AcinPercMrunSrasWrflDf";
			WalkLF = "AcinPercMrunSrasWrflDf";
			WalkRF = "AcinPercMrunSrasWrflDf";
			PlayerWalkF = "AcinPercMrunSrasWrflDf";
			PlayerWalkLF = "AcinPercMrunSrasWrflDf";
			PlayerWalkRF = "AcinPercMrunSrasWrflDf";
			SlowF = "AcinPercMrunSrasWrflDf";
			SlowLF = "AcinPercMrunSrasWrflDf";
			SlowRF = "AcinPercMrunSrasWrflDf";
			PlayerSlowF = "AcinPercMrunSrasWrflDf";
			PlayerSlowLF = "AcinPercMrunSrasWrflDf";
			PlayerSlowRF = "AcinPercMrunSrasWrflDf";
			FastF = "AcinPercMrunSrasWrflDf";
			FastLF = "AcinPercMrunSrasWrflDf";
			FastRF = "AcinPercMrunSrasWrflDf";
			PlayerProne = "AcinPercMrunSrasWrflDf_AmovPercMstpSlowWrflDnon";
			StopRelaxed = "AcinPercMstpSrasWrflDnon";
			released = "AcinPercMrunSrasWrflDf_AmovPercMstpSlowWrflDnon";
			grabCarry = "AcinPercMstpSrasWrflDnon";
			grabDrag = "";
			stance = "ManStanceStand";
		};
		class MoveWithInjuredManCarrierRfl: MoveWithInjuredManCarrier
		{
			updegree = "ManPosCombat";
			PlayerProne = "";
			WalkLF = "AcinPercMrunSrasWrflDfl";
			WalkRF = "AcinPercMrunSrasWrflDfr";
			WalkL = "AcinPercMrunSrasWrflDl";
			WalkR = "AcinPercMrunSrasWrflDr";
			WalkLB = "AcinPercMrunSrasWrflDbl";
			WalkRB = "AcinPercMrunSrasWrflDbr";
			WalkB = "AcinPercMrunSrasWrflDb";
			PlayerWalkLF = "AcinPercMrunSrasWrflDfl";
			PlayerWalkRF = "AcinPercMrunSrasWrflDfr";
			PlayerWalkL = "AcinPercMrunSrasWrflDl";
			PlayerWalkR = "AcinPercMrunSrasWrflDr";
			PlayerWalkLB = "AcinPercMrunSrasWrflDbl";
			PlayerWalkRB = "AcinPercMrunSrasWrflDbr";
			PlayerWalkB = "AcinPercMrunSrasWrflDb";
			SlowL = "AcinPercMrunSrasWrflDl";
			SlowR = "AcinPercMrunSrasWrflDr";
			SlowLB = "AcinPercMrunSrasWrflDbl";
			SlowRB = "AcinPercMrunSrasWrflDbr";
			SlowLF = "AcinPercMrunSrasWrflDfl";
			SlowRF = "AcinPercMrunSrasWrflDfr";
			SlowB = "AcinPercMrunSrasWrflDb";
			PlayerSlowL = "AcinPercMrunSrasWrflDl";
			PlayerSlowR = "AcinPercMrunSrasWrflDr";
			PlayerSlowLB = "AcinPercMrunSrasWrflDbl";
			PlayerSlowRB = "AcinPercMrunSrasWrflDbr";
			PlayerSlowLF = "AcinPercMrunSrasWrflDfl";
			PlayerSlowRF = "AcinPercMrunSrasWrflDfr";
			PlayerSlowB = "AcinPercMrunSrasWrflDb";
			TactF = "AcinPercMrunSrasWrflDf";
			TactL = "AcinPercMrunSrasWrflDl";
			TactR = "AcinPercMrunSrasWrflDr";
			TactLB = "AcinPercMrunSrasWrflDbl";
			TactRB = "AcinPercMrunSrasWrflDbr";
			TactLF = "AcinPercMrunSrasWrflDfl";
			TactRF = "AcinPercMrunSrasWrflDfr";
			TactB = "AcinPercMrunSrasWrflDb";
			PlayerTactF = "AcinPercMrunSrasWrflDf";
			PlayerTactL = "AcinPercMrunSrasWrflDl";
			PlayerTactR = "AcinPercMrunSrasWrflDr";
			PlayerTactLB = "AcinPercMrunSrasWrflDbl";
			PlayerTactRB = "AcinPercMrunSrasWrflDbr";
			PlayerTactLF = "AcinPercMrunSrasWrflDfl";
			PlayerTactRF = "AcinPercMrunSrasWrflDfr";
			PlayerTactB = "AcinPercMrunSrasWrflDb";
			FastRF = "AcinPercMrunSrasWrflDfr";
			FastLF = "AcinPercMrunSrasWrflDfl";
			FastL = "AcinPercMrunSrasWrflDl";
			FastR = "AcinPercMrunSrasWrflDl";
			FastLB = "AcinPercMrunSrasWrflDbl";
			FastRB = "AcinPercMrunSrasWrflDbr";
			FastB = "AcinPercMrunSrasWrflDb";
			EvasiveLeft = "AcinPercMstpSrasWrflDnon";
			EvasiveRight = "AcinPercMstpSrasWrflDnon";
			PlayerStand = "AcinPercMstpSrasWrflDnon";
			Stand = "AmovPercMstpSlowWrflDnon";
			CanNotMove = "AcinPercMstpSrasWrflDnon";
			toAgony = "AmovPpneMstpSrasWrflDnon_injured";
			StartSwim = "";
			StartDive = "";
			agonyStart = "AinjPpneMstpSnonWrflDnon";
			agonyStop = "AmovPpneMstpSrasWrflDnon";
			medicStop = "AinvPknlMstpSnonWrflDnon_medicEnd";
			medicStart = "AinvPknlMstpSnonWrflDnon_medic";
			medicStartUp = "AinvPknlMstpSnonWrflDnon_medicUp";
		};
		class MoveWithInjuredManCarrierRflStill: MoveWithInjuredManCarrierRfl
		{
			upDegree = "manPosCarrying";
			grabDrag = "AmovPercMstpSlowWrflDnon_AcinPknlMwlkSlowWrflDb_2";
		};
		class MoveWithInjuredManCarrierNon: MoveWithInjuredManCarrierRfl
		{
			upDegree = "ManPosNoWeapon";
			agonyStart = "AinjPpneMstpSnonWnonDnon";
			agonyStop = "AmovPpneMstpSnonWnonDnon";
			medicStop = "AinvPknlMstpSnonWnonDnon_medicEnd";
			medicStart = "AinvPknlMstpSnonWnonDnon_medic";
			released = "AcinPercMrunSnonWnonDf_AmovPercMstpSnonWnonDnon";
			Stop = "AcinPercMstpSnonWnonDnon";
			StopRelaxed = "AcinPercMstpSnonWnonDnon";
			WalkF = "AcinPercMrunSnonWnonDf";
			WalkLF = "AcinPercMrunSnonWnonDfl";
			WalkRF = "AcinPercMrunSnonWnonDfr";
			WalkL = "AcinPercMrunSnonWnonDl";
			WalkR = "AcinPercMrunSnonWnonDr";
			WalkLB = "AcinPercMrunSnonWnonDbl";
			WalkRB = "AcinPercMrunSnonWnonDbr";
			WalkB = "AcinPercMrunSnonWnonDb";
			PlayerWalkF = "AcinPercMrunSnonWnonDf";
			PlayerWalkLF = "AcinPercMrunSnonWnonDfl";
			PlayerWalkRF = "AcinPercMrunSnonWnonDfr";
			PlayerWalkL = "AcinPercMrunSnonWnonDl";
			PlayerWalkR = "AcinPercMrunSnonWnonDr";
			PlayerWalkLB = "AcinPercMrunSnonWnonDbl";
			PlayerWalkRB = "AcinPercMrunSnonWnonDbr";
			PlayerWalkB = "AcinPercMrunSnonWnonDb";
			SlowF = "AcinPercMrunSnonWnonDf";
			SlowL = "AcinPercMrunSnonWnonDl";
			SlowR = "AcinPercMrunSnonWnonDr";
			SlowLB = "AcinPercMrunSnonWnonDbl";
			SlowRB = "AcinPercMrunSnonWnonDbr";
			SlowLF = "AcinPercMrunSnonWnonDfl";
			SlowRF = "AcinPercMrunSnonWnonDfr";
			SlowB = "AcinPercMrunSnonWnonDb";
			PlayerSlowF = "AcinPercMrunSnonWnonDf";
			PlayerSlowL = "AcinPercMrunSnonWnonDl";
			PlayerSlowR = "AcinPercMrunSnonWnonDr";
			PlayerSlowLB = "AcinPercMrunSnonWnonDbl";
			PlayerSlowRB = "AcinPercMrunSnonWnonDbr";
			PlayerSlowLF = "AcinPercMrunSnonWnonDfl";
			PlayerSlowRF = "AcinPercMrunSnonWnonDfr";
			PlayerSlowB = "AcinPercMrunSnonWnonDb";
			FastF = "AcinPercMrunSnonWnonDf";
			FastRF = "AcinPercMrunSnonWnonDfr";
			FastLF = "AcinPercMrunSnonWnonDfl";
			FastL = "AcinPercMrunSnonWnonDl";
			FastR = "AcinPercMrunSnonWnonDl";
			FastLB = "AcinPercMrunSnonWnonDbl";
			FastRB = "AcinPercMrunSnonWnonDbr";
			FastB = "AcinPercMrunSnonWnonDb";
			EvasiveLeft = "AcinPercMstpSnonWnonDnon";
			EvasiveRight = "AcinPercMstpSnonWnonDnon";
			PlayerStand = "AcinPercMstpSnonWnonDnon";
			Stand = "";
			CanNotMove = "";
			Default = "AcinPercMstpSnonWnonDnon";
			grabCarry = "AcinPercMstpSnonWnonDnon";
			Civil = "AcinPercMstpSnonWnonDnon";
		};
		class MoveWithInjuredManCarrierPst: MoveWithInjuredManCarrierRfl
		{
			upDegree = "ManPosHandGunStand";
			HandGunOn = "AcinPercMstpSnonWpstDnon";
		};
		class MoveWithInjuredManCarrierNonStill: MoveWithInjuredManCarrierNon
		{
			upDegree = "manPosCarrying";
			TactF = "AcinPercMrunSnonWnonDf";
			TactLF = "AcinPercMrunSnonWnonDfl";
			TactRF = "AcinPercMrunSnonWnonDfr";
			TactL = "AcinPercMrunSnonWnonDl";
			TactR = "AcinPercMrunSnonWnonDr";
			TactLB = "AcinPercMrunSnonWnonDbl";
			TactRB = "AcinPercMrunSnonWnonDbr";
			TactB = "AcinPercMrunSnonWnonDb";
			PlayerTactF = "AcinPercMrunSnonWnonDf";
			PlayerTactLF = "AcinPercMrunSnonWnonDfl";
			PlayerTactRF = "AcinPercMrunSnonWnonDfr";
			PlayerTactL = "AcinPercMrunSnonWnonDl";
			PlayerTactR = "AcinPercMrunSnonWnonDr";
			PlayerTactLB = "AcinPercMrunSnonWnonDbl";
			PlayerTactRB = "AcinPercMrunSnonWnonDbr";
			PlayerTactB = "AcinPercMrunSnonWnonDb";
			grabDrag = "AmovPercMstpSnonWnonDnon_AcinPknlMwlkSnonWnonDb_2";
		};
		class MoveWithInjuredManCarrierPstStill: MoveWithInjuredManCarrierNon
		{
			upDegree = "manPosCarrying";
			released = "AcinPercMrunSnonWpstDf_AmovPercMstpSrasWpstDnon";
			Stop = "AcinPercMstpSnonWpstDnon";
			StopRelaxed = "AcinPercMstpSnonWpstDnon";
			WalkF = "AcinPercMrunSnonWpstDf";
			WalkLF = "AcinPercMrunSnonWpstDfl";
			WalkRF = "AcinPercMrunSnonWpstDfr";
			WalkL = "AcinPercMrunSnonWpstDl";
			WalkR = "AcinPercMrunSnonWpstDr";
			WalkLB = "AcinPercMrunSnonWpstDbl";
			WalkRB = "AcinPercMrunSnonWpstDbr";
			WalkB = "AcinPercMrunSnonWpstDb";
			PlayerWalkF = "AcinPercMrunSnonWpstDf";
			PlayerWalkLF = "AcinPercMrunSnonWpstDfl";
			PlayerWalkRF = "AcinPercMrunSnonWpstDfr";
			PlayerWalkL = "AcinPercMrunSnonWpstDl";
			PlayerWalkR = "AcinPercMrunSnonWpstDr";
			PlayerWalkLB = "AcinPercMrunSnonWpstDbl";
			PlayerWalkRB = "AcinPercMrunSnonWpstDbr";
			PlayerWalkB = "AcinPercMrunSnonWpstDb";
			SlowF = "AcinPercMrunSnonWpstDf";
			SlowL = "AcinPercMrunSnonWpstDl";
			SlowR = "AcinPercMrunSnonWpstDr";
			SlowLB = "AcinPercMrunSnonWpstDbl";
			SlowRB = "AcinPercMrunSnonWpstDbr";
			SlowLF = "AcinPercMrunSnonWpstDfl";
			SlowRF = "AcinPercMrunSnonWpstDfr";
			SlowB = "AcinPercMrunSnonWpstDb";
			PlayerSlowF = "AcinPercMrunSnonWpstDf";
			PlayerSlowL = "AcinPercMrunSnonWpstDl";
			PlayerSlowR = "AcinPercMrunSnonWpstDr";
			PlayerSlowLB = "AcinPercMrunSnonWpstDbl";
			PlayerSlowRB = "AcinPercMrunSnonWpstDbr";
			PlayerSlowLF = "AcinPercMrunSnonWpstDfl";
			PlayerSlowRF = "AcinPercMrunSnonWpstDfr";
			PlayerSlowB = "AcinPercMrunSnonWpstDb";
			FastF = "AcinPercMrunSnonWpstDf";
			FastRF = "AcinPercMrunSnonWpstDfr";
			FastLF = "AcinPercMrunSnonWpstDfl";
			FastL = "AcinPercMrunSnonWpstDl";
			FastR = "AcinPercMrunSnonWpstDl";
			FastLB = "AcinPercMrunSnonWpstDbl";
			FastRB = "AcinPercMrunSnonWpstDbr";
			FastB = "AcinPercMrunSnonWpstDb";
			PlayerStand = "AcinPercMstpSnonWpstDnon";
			CanNotMove = "AcinPercMstpSnonWpstDnon";
			Default = "AcinPercMstpSnonWpstDnon";
			TactF = "AcinPercMrunSnonWpstDf";
			TactLF = "AcinPercMrunSnonWpstDfl";
			TactRF = "AcinPercMrunSnonWpstDfr";
			TactL = "AcinPercMrunSnonWpstDl";
			TactR = "AcinPercMrunSnonWpstDr";
			TactLB = "AcinPercMrunSnonWpstDbl";
			TactRB = "AcinPercMrunSnonWpstDbr";
			TactB = "AcinPercMrunSnonWpstDb";
			PlayerTactF = "AcinPercMrunSnonWpstDf";
			PlayerTactLF = "AcinPercMrunSnonWpstDfl";
			PlayerTactRF = "AcinPercMrunSnonWpstDfr";
			PlayerTactL = "AcinPercMrunSnonWpstDl";
			PlayerTactR = "AcinPercMrunSnonWpstDr";
			PlayerTactLB = "AcinPercMrunSnonWpstDbl";
			PlayerTactRB = "AcinPercMrunSnonWpstDbr";
			PlayerTactB = "AcinPercMrunSnonWpstDb";
			grabDrag = "AmovPercMstpSrasWpstDnon_AcinPknlMwlkSnonWpstDb_2";
		};
		class MoveWithInjuredManCarrierRflWc: MoveWithInjuredManCarrierRfl
		{
			toAgony = "AinjPpneMstpSnonWrflDnon";
		};
		class MoveWithInjuredManCarrierPstWc: MoveWithInjuredManCarrierRflWc{};
		class MoveWithInjuredManCarrierNonWc: MoveWithInjuredManCarrierNon{};
		class MoveWithInjuredMan_2Death2: MoveWithInjuredMan{};
		class MoveWithInjuredMan_release: RifleBaseLowStandActions
		{
			Diary = "";
		};
		class InjuredManActions: NoActions
		{
			upDegree = "ManPosLying";
			stance = "ManStanceProne";
			turnSpeed = 0;
			healingFinished = "AmovPpneMstpSrasWrflDnon";
			PlayerWalkF = "AmovPpneMsprSlowWrflDf_injured";
			PlayerSlowF = "AmovPpneMsprSlowWrflDf_injured";
			WalkF = "AmovPpneMsprSlowWrflDf_injured";
			SlowF = "AmovPpneMsprSlowWrflDf_injured";
			FastF = "AmovPpneMsprSlowWrflDf_injured";
			LadderOnDown = "";
			LadderOnUp = "";
			TestDriver = "";
			TestDriverOut = "";
			TestGunner = "";
			medicStop = "";
			medicStart = "";
			medicStartUp = "";
			medic = "AinvPknlMstpSlayWrflDnon_medic";
			medicUp = "AinvPknlMstpSlayWrflDnon_medicUp";
		};
		class InjuredManActionsRfl: InjuredManActions
		{
			turnSpeed = 2;
			Combat = "Unconscious";
			Stop = "AmovPpneMstpSrasWrflDnon_injured";
			Lying = "AmovPpneMstpSrasWrflDnon_injured";
			healedStart = "AinjPpneMstpSnonWrflDnon_injuredHealed";
			healedStop = "AinjPpneMstpSnonWrflDnon";
			agonyStart = "AinjPpneMstpSnonWrflDnon";
			agonyStop = "AmovPpneMstpSrasWrflDnon";
			medicStop = "AinvPknlMstpSnonWrflDnon_medicEnd";
			medicStart = "AinvPknlMstpSnonWrflDnon_medic";
			medicStartUp = "AinvPknlMstpSnonWrflDnon_medicUp";
		};
		class InjuredManActionsNon: InjuredManActionsRfl
		{
			agonyStart = "AinjPpneMstpSnonWnonDnon";
			agonyStop = "AmovPpneMstpSnonWnonDnon";
			medicStop = "AinvPknlMstpSnonWnonDnon_medicEnd";
			medicStart = "AinvPknlMstpSnonWnonDnon_medic";
			grabDrag = "AmovPercMstpSnonWnonDnon_AcinPknlMwlkSnonWnonDb_2";
			Stop = "AmovPpneMstpSnonWnonDnon_injured";
			PlayerWalkF = "AmovPpneMsprSnonWnonDf_injured";
			PlayerSlowF = "AmovPpneMsprSnonWnonDf_injured";
			WalkF = "AmovPpneMsprSnonWnonDf_injured";
			SlowF = "AmovPpneMsprSnonWnonDf_injured";
			FastF = "AmovPpneMsprSnonWnonDf_injured";
			Lying = "AmovPpneMstpSnonWnonDnon_injured";
			healedStart = "AinjPpneMstpSnonWnonDnon_injuredHealed";
			healedStop = "AinjPpneMstpSnonWnonDnon";
			grabDragged = "AinjPpneMrunSnonWnonDb_grab";
			grabCarried = "AinjPfalMstpSnonWnonDnon_carried_Up";
			released = "AinjPpneMstpSnonWnonDnon";
			releasedBad = "AinjPpneMstpSnonWnonDnon";
			carriedStill = "AinjPfalMstpSnonWnonDnon_carried_still";
			medic = "AinvPknlMstpSnonWnonDnon_medic_1";
		};
		class InjuredManActionsNon_norot: InjuredManActionsNon
		{
			turnSpeed = 0;
		};
		class InjuredManActionsNon_healed: InjuredManActionsNon_norot{};
		class InjuredManActionsRfl_norot: InjuredManActionsRfl
		{
			turnSpeed = 0;
			Stop = "AinjPpneMstpSnonWrflDnon";
		};
		class InjuredManActionsRfl_healed: InjuredManActionsRfl_norot
		{
			medicStop = "";
			medicStart = "";
			medicStartUp = "";
			Stop = "AinjPpneMstpSnonWrflDnon_injuredHealed";
			PlayerWalkF = "";
			PlayerSlowF = "";
			WalkF = "";
			SlowF = "";
			FastF = "";
			Lying = "";
			Default = "AinjPpneMstpSnonWrflDnon_injuredHealed";
			PlayerProne = "AinjPpneMstpSnonWrflDnon_injuredHealed";
			PlayerCrouch = "AinjPpneMstpSnonWrflDnon_injuredHealed";
			PlayerStand = "AinjPpneMstpSnonWrflDnon_injuredHealed";
		};
		class InjuredManCarriedActions: InjuredManActions
		{
			WalkF = "";
			PlayerWalkF = "";
			Stop = "AinjPfalMstpSnonWrflDnon_carried_still";
			StopRelaxed = "AinjPfalMstpSnonWrflDnon_carried_still";
			PlayerSlowF = "";
			SlowF = "";
			FastF = "";
			released = "AmovPpneMstpSrasWrflDnon";
			healingFinished = "";
			Default = "AinjPfalMstpSnonWrflDnon_carried_still";
			Lying = "AinjPfalMstpSnonWrflDnon_carried_still";
			PlayerProne = "AinjPfalMstpSnonWrflDnon_carried_still";
			PlayerCrouch = "AinjPfalMstpSnonWrflDnon_carried_still";
			PlayerStand = "AinjPfalMstpSnonWrflDnon_carried_still";
			agonyStop = "AmovPpneMstpSrasWrflDnon";
			Combat = "AinjPfalMstpSnonWnonDnon_carried_still";
		};
		class InjuredManCarriedActionsNon: InjuredManActionsNon
		{
			turnSpeed = 0;
			released = "AinjPfalMstpSnonWnonDnon_carried_Down";
			Stop = "AinjPfalMstpSnonWnonDnon_carried_still";
			StopRelaxed = "AinjPfalMstpSnonWnonDnon_carried_still";
			PlayerStand = "AinjPfalMstpSnonWnonDnon_carried_still";
			Lying = "AinjPfalMstpSnonWnonDnon_carried_still";
			Default = "AinjPfalMstpSnonWnonDnon_carried_still";
			releasedBad = "AinjPfalMstpSnonWnonDf_carried_fall";
			FastF = "";
			SlowF = "";
			WalkF = "";
			upDegree = "ManPosDragged";
		};
		class InjuredManCarriedActionsNonStill: InjuredManCarriedActionsNon{};
		class InjuredManCarriedActionsNonWc: InjuredManCarriedActionsNon
		{
			releasedBad = "AinjPfalMstpSnonWnonDf_carried_fallwc";
		};
		class InjuredManCarriedActionsRfl: InjuredManCarriedActions
		{
			agonyStart = "AinjPpneMstpSnonWrflDnon";
			released = "AinjPfalMstpSnonWrflDnon_carried_Down";
			releasedBad = "AinjPfalMstpSnonWrflDf_carried_fall";
			upDegree = "ManPosDragged";
		};
		class InjuredManCarriedActionsRflStill: InjuredManCarriedActionsRfl
		{
			combat = "";
		};
		class InjuredManCarriedActionsRflWc: InjuredManCarriedActionsRfl
		{
			releasedBad = "AinjPfalMstpSnonWrflDf_carried_fallwc";
		};
		class InjuredManDraggedActions: InjuredManActions
		{
			upDegree = "ManPosDragged";
			released = "AmovPpneMstpSnonWnonDnon";
			PlayerWalkF = "";
			PlayerSlowF = "";
			WalkF = "";
			SlowF = "";
			FastF = "";
			Stop = "AcinPknlMwlkSlowWrflDb_still";
			StopRelaxed = "AcinPknlMwlkSlowWrflDb_still";
			Default = "AcinPknlMwlkSlowWrflDb_still";
		};
		class InjuredManDraggedActionsRfl: InjuredManDraggedActions
		{
			released = "AinjPpneMstpSnonWrflDb_release";
			releasedBad = "AinjPpneMstpSnonWrflDb_release";
			agonyStart = "AinjPpneMstpSnonWrflDnon";
			agonyStop = "AmovPpneMstpSrasWrflDnon";
		};
		class InjuredManDraggedActionsNon: InjuredManDraggedActions
		{
			released = "AinjPpneMrunSnonWnonDb_release";
			grabDrag = "AmovPercMstpSnonWnonDnon_AcinPknlMwlkSnonWnonDb_2";
			releasedBad = "AinjPpneMrunSnonWnonDb_release";
			Stop = "AinjPpneMrunSnonWnonDb_still";
			StopRelaxed = "AinjPpneMrunSnonWnonDb_still";
			Default = "AinjPpneMrunSnonWnonDb_still";
			grabDragged = "AinjPpneMrunSnonWnonDb_grab";
			grabCarried = "AinjPfalMstpSnonWnonDnon_carried_Up";
		};
		class InjuredManDraggedDeadActions: InjuredManDraggedActions
		{
			released = "Unconscious";
		};
		class PistolAdjustStandBaseActions: PistolStandActions
		{
			Lying = "";
			Crouch = "";
		};
		class PistolAdjustLStandActions: PistolAdjustStandBaseActions
		{
			stop = "AadjPercMstpSrasWpstDleft";
			default = "AadjPercMstpSrasWpstDleft";
			StopRelaxed = "AadjPercMstpSrasWpstDleft";
			turnL = "AadjPercMstpSrasWpstDleft";
			turnR = "AadjPercMstpSrasWpstDleft";
			turnLRelaxed = "AadjPercMstpSrasWpstDleft";
			turnRRelaxed = "AadjPercMstpSrasWpstDleft";
			WalkF = "AadjPercMwlkSrasWpstDf_left";
			WalkLF = "AadjPercMwlkSrasWpstDfl_left";
			WalkRF = "AadjPercMwlkSrasWpstDfr_left";
			WalkL = "AadjPercMwlkSrasWpstDl_left";
			WalkR = "AadjPercMwlkSrasWpstDr_left";
			WalkLB = "AadjPercMwlkSrasWpstDbl_left";
			WalkRB = "AadjPercMwlkSrasWpstDbr_left";
			WalkB = "AadjPercMwlkSrasWpstDb_left";
			PlayerWalkF = "AadjPercMwlkSrasWpstDf_left";
			PlayerWalkLF = "AadjPercMwlkSrasWpstDfl_left";
			PlayerWalkRF = "AadjPercMwlkSrasWpstDfr_left";
			PlayerWalkL = "AadjPercMwlkSrasWpstDl_left";
			PlayerWalkR = "AadjPercMwlkSrasWpstDr_left";
			PlayerWalkLB = "AadjPercMwlkSrasWpstDbl_left";
			PlayerWalkRB = "AadjPercMwlkSrasWpstDbr_left";
			PlayerWalkB = "AadjPercMwlkSrasWpstDb_left";
			SlowF = "AadjPercMrunSrasWpstDf_left";
			SlowLF = "AadjPercMrunSrasWpstDfl_left";
			SlowRF = "AadjPercMrunSrasWpstDfr_left";
			SlowL = "AadjPercMrunSrasWpstDl_left";
			SlowR = "AadjPercMrunSrasWpstDr_left";
			SlowLB = "AadjPercMrunSrasWpstDbl_left";
			SlowRB = "AadjPercMrunSrasWpstDbr_left";
			SlowB = "AadjPercMrunSrasWpstDb_left";
			PlayerSlowF = "AadjPercMrunSrasWpstDf_left";
			PlayerSlowLF = "AadjPercMrunSrasWpstDfl_left";
			PlayerSlowRF = "AadjPercMrunSrasWpstDfr_left";
			PlayerSlowL = "AadjPercMrunSrasWpstDl_left";
			PlayerSlowR = "AadjPercMrunSrasWpstDr_left";
			PlayerSlowLB = "AadjPercMrunSrasWpstDbl_left";
			PlayerSlowRB = "AadjPercMrunSrasWpstDbr_left";
			PlayerSlowB = "AadjPercMrunSrasWpstDb_left";
			FastF = "AadjPercMevaSrasWpstDf_left";
			FastLF = "AadjPercMevaSrasWpstDfl_left";
			FastRF = "AadjPercMevaSrasWpstDfr_left";
			FastL = "AadjPercMrunSrasWpstDl_left";
			FastR = "AadjPercMrunSrasWpstDr_left";
			FastLB = "AadjPercMrunSrasWpstDbl_left";
			FastRB = "AadjPercMrunSrasWpstDbr_left";
			FastB = "AadjPercMrunSrasWpstDb_left";
			TactF = "AadjPercMtacSrasWpstDf_left";
			TactLF = "AadjPercMtacSrasWpstDfl_left";
			TactRF = "AadjPercMtacSrasWpstDfr_left";
			TactL = "AadjPercMtacSrasWpstDl_left";
			TactR = "AadjPercMtacSrasWpstDr_left";
			TactLB = "AadjPercMtacSrasWpstDbl_left";
			TactRB = "AadjPercMtacSrasWpstDbr_left";
			TactB = "AadjPercMtacSrasWpstDb_left";
			PlayerTactF = "AadjPercMtacSrasWpstDf_left";
			PlayerTactLF = "AadjPercMtacSrasWpstDfl_left";
			PlayerTactRF = "AadjPercMtacSrasWpstDfr_left";
			PlayerTactL = "AadjPercMtacSrasWpstDl_left";
			PlayerTactR = "AadjPercMtacSrasWpstDr_left";
			PlayerTactLB = "AadjPercMtacSrasWpstDbl_left";
			PlayerTactRB = "AadjPercMtacSrasWpstDbr_left";
			PlayerTactB = "AadjPercMtacSrasWpstDb_left";
			up = "AadjPknlMstpSrasWpstDleft";
			down = "AadjPpneMstpSrasWpstDleft";
			PlayerStand = "AmovPercMstpSrasWpstDnon";
			PlayerCrouch = "AadjPknlMstpSrasWpstDleft";
			Combat = "AadjPercMstpSrasWpstDleft";
			FireNotPossible = "AadjPercMstpSrasWpstDleft";
			Crouch = "AadjPknlMstpSrasWpstDleft";
			AdjustR = "AmovPercMstpSrasWpstDnon";
		};
		class PistolAdjustRStandActions: PistolAdjustStandBaseActions
		{
			stop = "AadjPercMstpSrasWpstDright";
			default = "AadjPercMstpSrasWpstDright";
			StopRelaxed = "AadjPercMstpSrasWpstDright";
			turnL = "AadjPercMstpSrasWpstDright";
			turnR = "AadjPercMstpSrasWpstDright";
			turnLRelaxed = "AadjPercMstpSrasWpstDright";
			turnRRelaxed = "AadjPercMstpSrasWpstDright";
			WalkF = "AadjPercMwlkSrasWpstDf_right";
			WalkLF = "AadjPercMwlkSrasWpstDfl_right";
			WalkRF = "AadjPercMwlkSrasWpstDfr_right";
			WalkL = "AadjPercMwlkSrasWpstDl_right";
			WalkR = "AadjPercMwlkSrasWpstDr_right";
			WalkLB = "AadjPercMwlkSrasWpstDbl_right";
			WalkRB = "AadjPercMwlkSrasWpstDbr_right";
			WalkB = "AadjPercMwlkSrasWpstDb_right";
			PlayerWalkF = "AadjPercMwlkSrasWpstDf_right";
			PlayerWalkLF = "AadjPercMwlkSrasWpstDfl_right";
			PlayerWalkRF = "AadjPercMwlkSrasWpstDfr_right";
			PlayerWalkL = "AadjPercMwlkSrasWpstDl_right";
			PlayerWalkR = "AadjPercMwlkSrasWpstDr_right";
			PlayerWalkLB = "AadjPercMwlkSrasWpstDbl_right";
			PlayerWalkRB = "AadjPercMwlkSrasWpstDbr_right";
			PlayerWalkB = "AadjPercMwlkSrasWpstDb_right";
			SlowF = "AadjPercMrunSrasWpstDf_right";
			SlowLF = "AadjPercMrunSrasWpstDfl_right";
			SlowRF = "AadjPercMrunSrasWpstDfr_right";
			SlowL = "AadjPercMrunSrasWpstDl_right";
			SlowR = "AadjPercMrunSrasWpstDr_right";
			SlowLB = "AadjPercMrunSrasWpstDbl_right";
			SlowRB = "AadjPercMrunSrasWpstDbr_right";
			SlowB = "AadjPercMrunSrasWpstDb_right";
			PlayerSlowF = "AadjPercMrunSrasWpstDf_right";
			PlayerSlowLF = "AadjPercMrunSrasWpstDfl_right";
			PlayerSlowRF = "AadjPercMrunSrasWpstDfr_right";
			PlayerSlowL = "AadjPercMrunSrasWpstDl_right";
			PlayerSlowR = "AadjPercMrunSrasWpstDr_right";
			PlayerSlowLB = "AadjPercMrunSrasWpstDbl_right";
			PlayerSlowRB = "AadjPercMrunSrasWpstDbr_right";
			PlayerSlowB = "AadjPercMrunSrasWpstDb_right";
			FastF = "AadjPercMevaSrasWpstDf_right";
			FastLF = "AadjPercMevaSrasWpstDfl_right";
			FastRF = "AadjPercMevaSrasWpstDfr_right";
			FastL = "AadjPercMrunSrasWpstDl_right";
			FastR = "AadjPercMrunSrasWpstDr_right";
			FastLB = "AadjPercMrunSrasWpstDbl_right";
			FastRB = "AadjPercMrunSrasWpstDbr_right";
			FastB = "AadjPercMrunSrasWpstDb_right";
			TactF = "AadjPercMtacSrasWpstDf_right";
			TactLF = "AadjPercMtacSrasWpstDfl_right";
			TactRF = "AadjPercMtacSrasWpstDfr_right";
			TactL = "AadjPercMtacSrasWpstDl_right";
			TactR = "AadjPercMtacSrasWpstDr_right";
			TactLB = "AadjPercMtacSrasWpstDbl_right";
			TactRB = "AadjPercMtacSrasWpstDbr_right";
			TactB = "AadjPercMtacSrasWpstDb_right";
			PlayerTactF = "AadjPercMtacSrasWpstDf_right";
			PlayerTactLF = "AadjPercMtacSrasWpstDfl_right";
			PlayerTactRF = "AadjPercMtacSrasWpstDfr_right";
			PlayerTactL = "AadjPercMtacSrasWpstDl_right";
			PlayerTactR = "AadjPercMtacSrasWpstDr_right";
			PlayerTactLB = "AadjPercMtacSrasWpstDbl_right";
			PlayerTactRB = "AadjPercMtacSrasWpstDbr_right";
			PlayerTactB = "AadjPercMtacSrasWpstDb_right";
			up = "AadjPknlMstpSrasWpstDright";
			down = "AadjPpneMstpSrasWpstDright";
			PlayerStand = "AmovPercMstpSrasWpstDnon";
			PlayerCrouch = "AadjPknlMstpSrasWpstDright";
			Combat = "AadjPercMstpSrasWpstDright";
			FireNotPossible = "AadjPercMstpSrasWpstDright";
			Crouch = "AadjPknlMstpSrasWpstDright";
			AdjustL = "AmovPercMstpSrasWpstDnon";
		};
		class PistolAdjustFStandActions: PistolAdjustStandBaseActions
		{
			stop = "AadjPercMstpSrasWpstDup";
			default = "AadjPercMstpSrasWpstDup";
			StopRelaxed = "AadjPercMstpSrasWpstDup";
			turnL = "AadjPercMstpSrasWpstDup";
			turnR = "AadjPercMstpSrasWpstDup";
			turnLRelaxed = "AadjPercMstpSrasWpstDup";
			turnRRelaxed = "AadjPercMstpSrasWpstDup";
			WalkF = "AadjPercMwlkSrasWpstDf_up";
			WalkLF = "AadjPercMwlkSrasWpstDfl_up";
			WalkRF = "AadjPercMwlkSrasWpstDfr_up";
			WalkL = "AadjPercMwlkSrasWpstDl_up";
			WalkR = "AadjPercMwlkSrasWpstDr_up";
			WalkLB = "AadjPercMwlkSrasWpstDbl_up";
			WalkRB = "AadjPercMwlkSrasWpstDbr_up";
			WalkB = "AadjPercMwlkSrasWpstDb_up";
			PlayerWalkF = "AadjPercMwlkSrasWpstDf_up";
			PlayerWalkLF = "AadjPercMwlkSrasWpstDfl_up";
			PlayerWalkRF = "AadjPercMwlkSrasWpstDfr_up";
			PlayerWalkL = "AadjPercMwlkSrasWpstDl_up";
			PlayerWalkR = "AadjPercMwlkSrasWpstDr_up";
			PlayerWalkLB = "AadjPercMwlkSrasWpstDbl_up";
			PlayerWalkRB = "AadjPercMwlkSrasWpstDbr_up";
			PlayerWalkB = "AadjPercMwlkSrasWpstDb_up";
			SlowF = "AadjPercMrunSrasWpstDf_up";
			SlowLF = "AadjPercMrunSrasWpstDfl_up";
			SlowRF = "AadjPercMrunSrasWpstDfr_up";
			SlowL = "AadjPercMrunSrasWpstDl_up";
			SlowR = "AadjPercMrunSrasWpstDr_up";
			SlowLB = "AadjPercMrunSrasWpstDbl_up";
			SlowRB = "AadjPercMrunSrasWpstDbr_up";
			SlowB = "AadjPercMrunSrasWpstDb_up";
			PlayerSlowF = "AadjPercMrunSrasWpstDf_up";
			PlayerSlowLF = "AadjPercMrunSrasWpstDfl_up";
			PlayerSlowRF = "AadjPercMrunSrasWpstDfr_up";
			PlayerSlowL = "AadjPercMrunSrasWpstDl_up";
			PlayerSlowR = "AadjPercMrunSrasWpstDr_up";
			PlayerSlowLB = "AadjPercMrunSrasWpstDbl_up";
			PlayerSlowRB = "AadjPercMrunSrasWpstDbr_up";
			PlayerSlowB = "AadjPercMrunSrasWpstDb_up";
			FastF = "AadjPercMevaSrasWpstDf_up";
			FastLF = "AadjPercMevaSrasWpstDfl_up";
			FastRF = "AadjPercMevaSrasWpstDfr_up";
			FastL = "AadjPercMrunSrasWpstDl_up";
			FastR = "AadjPercMrunSrasWpstDr_up";
			FastLB = "AadjPercMrunSrasWpstDbl_up";
			FastRB = "AadjPercMrunSrasWpstDbr_up";
			FastB = "AadjPercMrunSrasWpstDb_up";
			TactF = "AadjPercMtacSrasWpstDf_up";
			TactLF = "AadjPercMtacSrasWpstDfl_up";
			TactRF = "AadjPercMtacSrasWpstDfr_up";
			TactL = "AadjPercMtacSrasWpstDl_up";
			TactR = "AadjPercMtacSrasWpstDr_up";
			TactLB = "AadjPercMtacSrasWpstDbl_up";
			TactRB = "AadjPercMtacSrasWpstDbr_up";
			TactB = "AadjPercMtacSrasWpstDb_up";
			PlayerTactF = "AadjPercMtacSrasWpstDf_up";
			PlayerTactLF = "AadjPercMtacSrasWpstDfl_up";
			PlayerTactRF = "AadjPercMtacSrasWpstDfr_up";
			PlayerTactL = "AadjPercMtacSrasWpstDl_up";
			PlayerTactR = "AadjPercMtacSrasWpstDr_up";
			PlayerTactLB = "AadjPercMtacSrasWpstDbl_up";
			PlayerTactRB = "AadjPercMtacSrasWpstDbr_up";
			PlayerTactB = "AadjPercMtacSrasWpstDb_up";
			up = "AadjPknlMstpSrasWpstDup";
			PlayerStand = "AmovPercMstpSrasWpstDnon";
			PlayerCrouch = "AadjPknlMstpSrasWpstDup";
			Combat = "AadjPercMstpSrasWpstDup";
			FireNotPossible = "AadjPercMstpSrasWpstDup";
			Crouch = "AadjPknlMstpSrasWpstDup";
			AdjustB = "AmovPercMstpSrasWpstDnon";
		};
		class PistolAdjustBStandActions: PistolAdjustStandBaseActions
		{
			stop = "AadjPercMstpSrasWpstDdown";
			default = "AadjPercMstpSrasWpstDdown";
			StopRelaxed = "AadjPercMstpSrasWpstDdown";
			turnL = "AadjPercMstpSrasWpstDdown";
			turnR = "AadjPercMstpSrasWpstDdown";
			turnLRelaxed = "AadjPercMstpSrasWpstDdown";
			turnRRelaxed = "AadjPercMstpSrasWpstDdown";
			WalkF = "AadjPercMwlkSrasWpstDf_down";
			WalkLF = "AadjPercMwlkSrasWpstDfl_down";
			WalkRF = "AadjPercMwlkSrasWpstDfr_down";
			WalkL = "AadjPercMwlkSrasWpstDl_down";
			WalkR = "AadjPercMwlkSrasWpstDr_down";
			WalkLB = "AadjPercMwlkSrasWpstDbl_down";
			WalkRB = "AadjPercMwlkSrasWpstDbr_down";
			WalkB = "AadjPercMwlkSrasWpstDb_down";
			PlayerWalkF = "AadjPercMwlkSrasWpstDf_down";
			PlayerWalkLF = "AadjPercMwlkSrasWpstDfl_down";
			PlayerWalkRF = "AadjPercMwlkSrasWpstDfr_down";
			PlayerWalkL = "AadjPercMwlkSrasWpstDl_down";
			PlayerWalkR = "AadjPercMwlkSrasWpstDr_down";
			PlayerWalkLB = "AadjPercMwlkSrasWpstDbl_down";
			PlayerWalkRB = "AadjPercMwlkSrasWpstDbr_down";
			PlayerWalkB = "AadjPercMwlkSrasWpstDb_down";
			SlowF = "AadjPercMrunSrasWpstDf_down";
			SlowLF = "AadjPercMrunSrasWpstDfl_down";
			SlowRF = "AadjPercMrunSrasWpstDfr_down";
			SlowL = "AadjPercMrunSrasWpstDl_down";
			SlowR = "AadjPercMrunSrasWpstDr_down";
			SlowLB = "AadjPercMrunSrasWpstDbl_down";
			SlowRB = "AadjPercMrunSrasWpstDbr_down";
			SlowB = "AadjPercMrunSrasWpstDb_down";
			PlayerSlowF = "AadjPercMrunSrasWpstDf_down";
			PlayerSlowLF = "AadjPercMrunSrasWpstDfl_down";
			PlayerSlowRF = "AadjPercMrunSrasWpstDfr_down";
			PlayerSlowL = "AadjPercMrunSrasWpstDl_down";
			PlayerSlowR = "AadjPercMrunSrasWpstDr_down";
			PlayerSlowLB = "AadjPercMrunSrasWpstDbl_down";
			PlayerSlowRB = "AadjPercMrunSrasWpstDbr_down";
			PlayerSlowB = "AadjPercMrunSrasWpstDb_down";
			FastF = "AadjPercMevaSrasWpstDf_down";
			FastLF = "AadjPercMevaSrasWpstDfl_down";
			FastRF = "AadjPercMevaSrasWpstDfr_down";
			FastL = "AadjPercMrunSrasWpstDl_down";
			FastR = "AadjPercMrunSrasWpstDr_down";
			FastLB = "AadjPercMrunSrasWpstDbl_down";
			FastRB = "AadjPercMrunSrasWpstDbr_down";
			FastB = "AadjPercMrunSrasWpstDb_down";
			TactF = "AadjPercMtacSrasWpstDf_down";
			TactLF = "AadjPercMtacSrasWpstDfl_down";
			TactRF = "AadjPercMtacSrasWpstDfr_down";
			TactL = "AadjPercMtacSrasWpstDl_down";
			TactR = "AadjPercMtacSrasWpstDr_down";
			TactLB = "AadjPercMtacSrasWpstDbl_down";
			TactRB = "AadjPercMtacSrasWpstDbr_down";
			TactB = "AadjPercMtacSrasWpstDb_down";
			PlayerTactF = "AadjPercMtacSrasWpstDf_down";
			PlayerTactLF = "AadjPercMtacSrasWpstDfl_down";
			PlayerTactRF = "AadjPercMtacSrasWpstDfr_down";
			PlayerTactL = "AadjPercMtacSrasWpstDl_down";
			PlayerTactR = "AadjPercMtacSrasWpstDr_down";
			PlayerTactLB = "AadjPercMtacSrasWpstDbl_down";
			PlayerTactRB = "AadjPercMtacSrasWpstDbr_down";
			PlayerTactB = "AadjPercMtacSrasWpstDb_down";
			up = "AadjPknlMstpSrasWpstDdown";
			PlayerStand = "AmovPercMstpSrasWpstDnon";
			PlayerCrouch = "AadjPknlMstpSrasWpstDdown";
			Combat = "AadjPercMstpSrasWpstDdown";
			FireNotPossible = "AadjPercMstpSrasWpstDdown";
			Crouch = "AadjPknlMstpSrasWpstDdown";
			AdjustF = "AmovPercMstpSrasWpstDnon";
			AdjustB = "AadjPknlMstpSrasWpstDup";
		};
		class PistolAdjustKneelBaseActions: PistolKneelActions
		{
			Lying = "";
			Crouch = "";
		};
		class PistolAdjustLKneelActions: PistolAdjustKneelBaseActions
		{
			stop = "AadjPknlMstpSrasWpstDleft";
			default = "AadjPknlMstpSrasWpstDleft";
			StopRelaxed = "AadjPknlMstpSrasWpstDleft";
			turnL = "AadjPknlMstpSrasWpstDleft";
			turnR = "AadjPknlMstpSrasWpstDleft";
			turnLRelaxed = "AadjPknlMstpSrasWpstDleft";
			turnRRelaxed = "AadjPknlMstpSrasWpstDleft";
			WalkF = "AadjPknlMwlkSrasWpstDf_left";
			WalkLF = "AadjPknlMwlkSrasWpstDfl_left";
			WalkRF = "AadjPknlMwlkSrasWpstDfr_left";
			WalkL = "AadjPknlMwlkSrasWpstDl_left";
			WalkR = "AadjPknlMwlkSrasWpstDr_left";
			WalkLB = "AadjPknlMwlkSrasWpstDbl_left";
			WalkRB = "AadjPknlMwlkSrasWpstDbr_left";
			WalkB = "AadjPknlMwlkSrasWpstDb_left";
			PlayerWalkF = "AadjPknlMwlkSrasWpstDf_left";
			PlayerWalkLF = "AadjPknlMwlkSrasWpstDfl_left";
			PlayerWalkRF = "AadjPknlMwlkSrasWpstDfr_left";
			PlayerWalkL = "AadjPknlMwlkSrasWpstDl_left";
			PlayerWalkR = "AadjPknlMwlkSrasWpstDr_left";
			PlayerWalkLB = "AadjPknlMwlkSrasWpstDbl_left";
			PlayerWalkRB = "AadjPknlMwlkSrasWpstDbr_left";
			PlayerWalkB = "AadjPknlMwlkSrasWpstDb_left";
			SlowF = "AadjPknlMrunSrasWpstDf_left";
			SlowLF = "AadjPknlMrunSrasWpstDfl_left";
			SlowRF = "AadjPknlMrunSrasWpstDfr_left";
			SlowL = "AadjPknlMrunSrasWpstDl_left";
			SlowR = "AadjPknlMrunSrasWpstDr_left";
			SlowLB = "AadjPknlMrunSrasWpstDbl_left";
			SlowRB = "AadjPknlMrunSrasWpstDbr_left";
			SlowB = "AadjPknlMrunSrasWpstDb_left";
			PlayerSlowF = "AadjPknlMrunSrasWpstDf_left";
			PlayerSlowLF = "AadjPknlMrunSrasWpstDfl_left";
			PlayerSlowRF = "AadjPknlMrunSrasWpstDfr_left";
			PlayerSlowL = "AadjPknlMrunSrasWpstDl_left";
			PlayerSlowR = "AadjPknlMrunSrasWpstDr_left";
			PlayerSlowLB = "AadjPknlMrunSrasWpstDbl_left";
			PlayerSlowRB = "AadjPknlMrunSrasWpstDbr_left";
			PlayerSlowB = "AadjPknlMrunSrasWpstDb_left";
			FastF = "AadjPknlMevaSrasWpstDf_left";
			FastLF = "AadjPknlMevaSrasWpstDfl_left";
			FastRF = "AadjPknlMevaSrasWpstDfr_left";
			FastL = "AadjPknlMrunSrasWpstDl_left";
			FastR = "AadjPknlMrunSrasWpstDr_left";
			FastLB = "AadjPknlMrunSrasWpstDbl_left";
			FastRB = "AadjPknlMrunSrasWpstDbr_left";
			FastB = "AadjPknlMrunSrasWpstDb_left";
			TactF = "AadjPknlMtacSrasWpstDf_left";
			TactLF = "AadjPknlMtacSrasWpstDfl_left";
			TactRF = "AadjPknlMtacSrasWpstDfr_left";
			TactL = "AadjPknlMtacSrasWpstDl_left";
			TactR = "AadjPknlMtacSrasWpstDr_left";
			TactLB = "AadjPknlMtacSrasWpstDbl_left";
			TactRB = "AadjPknlMtacSrasWpstDbr_left";
			TactB = "AadjPknlMtacSrasWpstDb_left";
			PlayerTactF = "AadjPknlMtacSrasWpstDf_left";
			PlayerTactLF = "AadjPknlMtacSrasWpstDfl_left";
			PlayerTactRF = "AadjPknlMtacSrasWpstDfr_left";
			PlayerTactL = "AadjPknlMtacSrasWpstDl_left";
			PlayerTactR = "AadjPknlMtacSrasWpstDr_left";
			PlayerTactLB = "AadjPknlMtacSrasWpstDbl_left";
			PlayerTactRB = "AadjPknlMtacSrasWpstDbr_left";
			PlayerTactB = "AadjPknlMtacSrasWpstDb_left";
			up = "AadjPercMstpSrasWpstDleft";
			PlayerStand = "AadjPercMstpSrasWpstDleft";
			Combat = "AadjPknlMstpSrasWpstDleft";
			FireNotPossible = "AadjPknlMstpSrasWpstDleft";
			Stand = "AmovPknlMstpSlowWpstDnon";
			AdjustR = "AmovPknlMstpSrasWpstDnon";
			down = "AadjPpneMstpSrasWpstDleft";
			PlayerProne = "AadjPpneMstpSrasWpstDleft";
		};
		class PistolAdjustRKneelActions: PistolAdjustKneelBaseActions
		{
			stop = "AadjPknlMstpSrasWpstDright";
			default = "AadjPknlMstpSrasWpstDright";
			StopRelaxed = "AadjPknlMstpSrasWpstDright";
			turnL = "AadjPknlMstpSrasWpstDright";
			turnR = "AadjPknlMstpSrasWpstDright";
			turnLRelaxed = "AadjPknlMstpSrasWpstDright";
			turnRRelaxed = "AadjPknlMstpSrasWpstDright";
			WalkF = "AadjPknlMwlkSrasWpstDf_right";
			WalkLF = "AadjPknlMwlkSrasWpstDfl_right";
			WalkRF = "AadjPknlMwlkSrasWpstDfr_right";
			WalkL = "AadjPknlMwlkSrasWpstDl_right";
			WalkR = "AadjPknlMwlkSrasWpstDr_right";
			WalkLB = "AadjPknlMwlkSrasWpstDbl_right";
			WalkRB = "AadjPknlMwlkSrasWpstDbr_right";
			WalkB = "AadjPknlMwlkSrasWpstDb_right";
			PlayerWalkF = "AadjPknlMwlkSrasWpstDf_right";
			PlayerWalkLF = "AadjPknlMwlkSrasWpstDfl_right";
			PlayerWalkRF = "AadjPknlMwlkSrasWpstDfr_right";
			PlayerWalkL = "AadjPknlMwlkSrasWpstDl_right";
			PlayerWalkR = "AadjPknlMwlkSrasWpstDr_right";
			PlayerWalkLB = "AadjPknlMwlkSrasWpstDbl_right";
			PlayerWalkRB = "AadjPknlMwlkSrasWpstDbr_right";
			PlayerWalkB = "AadjPknlMwlkSrasWpstDb_right";
			SlowF = "AadjPknlMrunSrasWpstDf_right";
			SlowLF = "AadjPknlMrunSrasWpstDfl_right";
			SlowRF = "AadjPknlMrunSrasWpstDfr_right";
			SlowL = "AadjPknlMrunSrasWpstDl_right";
			SlowR = "AadjPknlMrunSrasWpstDr_right";
			SlowLB = "AadjPknlMrunSrasWpstDbl_right";
			SlowRB = "AadjPknlMrunSrasWpstDbr_right";
			SlowB = "AadjPknlMrunSrasWpstDb_right";
			PlayerSlowF = "AadjPknlMrunSrasWpstDf_right";
			PlayerSlowLF = "AadjPknlMrunSrasWpstDfl_right";
			PlayerSlowRF = "AadjPknlMrunSrasWpstDfr_right";
			PlayerSlowL = "AadjPknlMrunSrasWpstDl_right";
			PlayerSlowR = "AadjPknlMrunSrasWpstDr_right";
			PlayerSlowLB = "AadjPknlMrunSrasWpstDbl_right";
			PlayerSlowRB = "AadjPknlMrunSrasWpstDbr_right";
			PlayerSlowB = "AadjPknlMrunSrasWpstDb_right";
			FastF = "AadjPknlMevaSrasWpstDf_right";
			FastLF = "AadjPknlMevaSrasWpstDfl_right";
			FastRF = "AadjPknlMevaSrasWpstDfr_right";
			FastL = "AadjPknlMrunSrasWpstDl_right";
			FastR = "AadjPknlMrunSrasWpstDr_right";
			FastLB = "AadjPknlMrunSrasWpstDbl_right";
			FastRB = "AadjPknlMrunSrasWpstDbr_right";
			FastB = "AadjPknlMrunSrasWpstDb_right";
			TactF = "AadjPknlMtacSrasWpstDf_right";
			TactLF = "AadjPknlMtacSrasWpstDfl_right";
			TactRF = "AadjPknlMtacSrasWpstDfr_right";
			TactL = "AadjPknlMtacSrasWpstDl_right";
			TactR = "AadjPknlMtacSrasWpstDr_right";
			TactLB = "AadjPknlMtacSrasWpstDbl_right";
			TactRB = "AadjPknlMtacSrasWpstDbr_right";
			TactB = "AadjPknlMtacSrasWpstDb_right";
			PlayerTactF = "AadjPknlMtacSrasWpstDf_right";
			PlayerTactLF = "AadjPknlMtacSrasWpstDfl_right";
			PlayerTactRF = "AadjPknlMtacSrasWpstDfr_right";
			PlayerTactL = "AadjPknlMtacSrasWpstDl_right";
			PlayerTactR = "AadjPknlMtacSrasWpstDr_right";
			PlayerTactLB = "AadjPknlMtacSrasWpstDbl_right";
			PlayerTactRB = "AadjPknlMtacSrasWpstDbr_right";
			PlayerTactB = "AadjPknlMtacSrasWpstDb_right";
			up = "AadjPercMstpSrasWpstDright";
			PlayerStand = "AadjPercMstpSrasWpstDright";
			Combat = "AadjPknlMstpSrasWpstDright";
			FireNotPossible = "AadjPknlMstpSrasWpstDright";
			Stand = "AmovPknlMstpSlowWpstDnon";
			AdjustL = "AmovPknlMstpSrasWpstDnon";
			down = "AadjPpneMstpSrasWpstDright";
			PlayerProne = "AadjPpneMstpSrasWpstDright";
		};
		class PistolAdjustFKneelActions: PistolAdjustKneelBaseActions
		{
			stop = "AadjPknlMstpSrasWpstDup";
			default = "AadjPknlMstpSrasWpstDup";
			StopRelaxed = "AadjPknlMstpSrasWpstDup";
			turnL = "AadjPknlMstpSrasWpstDup";
			turnR = "AadjPknlMstpSrasWpstDup";
			turnLRelaxed = "AadjPknlMstpSrasWpstDup";
			turnRRelaxed = "AadjPknlMstpSrasWpstDup";
			WalkF = "AadjPknlMwlkSrasWpstDf_up";
			WalkLF = "AadjPknlMwlkSrasWpstDfl_up";
			WalkRF = "AadjPknlMwlkSrasWpstDfr_up";
			WalkL = "AadjPknlMwlkSrasWpstDl_up";
			WalkR = "AadjPknlMwlkSrasWpstDr_up";
			WalkLB = "AadjPknlMwlkSrasWpstDbl_up";
			WalkRB = "AadjPknlMwlkSrasWpstDbr_up";
			WalkB = "AadjPknlMwlkSrasWpstDb_up";
			PlayerWalkF = "AadjPknlMwlkSrasWpstDf_up";
			PlayerWalkLF = "AadjPknlMwlkSrasWpstDfl_up";
			PlayerWalkRF = "AadjPknlMwlkSrasWpstDfr_up";
			PlayerWalkL = "AadjPknlMwlkSrasWpstDl_up";
			PlayerWalkR = "AadjPknlMwlkSrasWpstDr_up";
			PlayerWalkLB = "AadjPknlMwlkSrasWpstDbl_up";
			PlayerWalkRB = "AadjPknlMwlkSrasWpstDbr_up";
			PlayerWalkB = "AadjPknlMwlkSrasWpstDb_up";
			SlowF = "AadjPknlMrunSrasWpstDf_up";
			SlowLF = "AadjPknlMrunSrasWpstDfl_up";
			SlowRF = "AadjPknlMrunSrasWpstDfr_up";
			SlowL = "AadjPknlMrunSrasWpstDl_up";
			SlowR = "AadjPknlMrunSrasWpstDr_up";
			SlowLB = "AadjPknlMrunSrasWpstDbl_up";
			SlowRB = "AadjPknlMrunSrasWpstDbr_up";
			SlowB = "AadjPknlMrunSrasWpstDb_up";
			PlayerSlowF = "AadjPknlMrunSrasWpstDf_up";
			PlayerSlowLF = "AadjPknlMrunSrasWpstDfl_up";
			PlayerSlowRF = "AadjPknlMrunSrasWpstDfr_up";
			PlayerSlowL = "AadjPknlMrunSrasWpstDl_up";
			PlayerSlowR = "AadjPknlMrunSrasWpstDr_up";
			PlayerSlowLB = "AadjPknlMrunSrasWpstDbl_up";
			PlayerSlowRB = "AadjPknlMrunSrasWpstDbr_up";
			PlayerSlowB = "AadjPknlMrunSrasWpstDb_up";
			FastF = "AadjPknlMevaSrasWpstDf_up";
			FastLF = "AadjPknlMevaSrasWpstDfl_up";
			FastRF = "AadjPknlMevaSrasWpstDfr_up";
			FastL = "AadjPknlMrunSrasWpstDl_up";
			FastR = "AadjPknlMrunSrasWpstDr_up";
			FastLB = "AadjPknlMrunSrasWpstDbl_up";
			FastRB = "AadjPknlMrunSrasWpstDbr_up";
			FastB = "AadjPknlMrunSrasWpstDb_up";
			TactF = "AadjPknlMtacSrasWpstDf_up";
			TactLF = "AadjPknlMtacSrasWpstDfl_up";
			TactRF = "AadjPknlMtacSrasWpstDfr_up";
			TactL = "AadjPknlMtacSrasWpstDl_up";
			TactR = "AadjPknlMtacSrasWpstDr_up";
			TactLB = "AadjPknlMtacSrasWpstDbl_up";
			TactRB = "AadjPknlMtacSrasWpstDbr_up";
			TactB = "AadjPknlMtacSrasWpstDb_up";
			PlayerTactF = "AadjPknlMtacSrasWpstDf_up";
			PlayerTactLF = "AadjPknlMtacSrasWpstDfl_up";
			PlayerTactRF = "AadjPknlMtacSrasWpstDfr_up";
			PlayerTactL = "AadjPknlMtacSrasWpstDl_up";
			PlayerTactR = "AadjPknlMtacSrasWpstDr_up";
			PlayerTactLB = "AadjPknlMtacSrasWpstDbl_up";
			PlayerTactRB = "AadjPknlMtacSrasWpstDbr_up";
			PlayerTactB = "AadjPknlMtacSrasWpstDb_up";
			up = "AadjPercMstpSrasWpstDup";
			PlayerStand = "AadjPercMstpSrasWpstDup";
			Combat = "AadjPknlMstpSrasWpstDup";
			FireNotPossible = "AadjPknlMstpSrasWpstDup";
			Stand = "AmovPknlMstpSlowWpstDnon";
			AdjustF = "AadjPercMstpSrasWpstDdown";
			AdjustB = "AmovPknlMstpSrasWpstDnon";
		};
		class PistolAdjustBKneelActions: PistolAdjustKneelBaseActions
		{
			stop = "AadjPknlMstpSrasWpstDdown";
			default = "AadjPknlMstpSrasWpstDdown";
			StopRelaxed = "AadjPknlMstpSrasWpstDdown";
			turnL = "AadjPknlMstpSrasWpstDdown";
			turnR = "AadjPknlMstpSrasWpstDdown";
			turnLRelaxed = "AadjPknlMstpSrasWpstDdown";
			turnRRelaxed = "AadjPknlMstpSrasWpstDdown";
			WalkF = "AadjPknlMwlkSrasWpstDf_down";
			WalkLF = "AadjPknlMwlkSrasWpstDfl_down";
			WalkRF = "AadjPknlMwlkSrasWpstDfr_down";
			WalkL = "AadjPknlMwlkSrasWpstDl_down";
			WalkR = "AadjPknlMwlkSrasWpstDr_down";
			WalkLB = "AadjPknlMwlkSrasWpstDbl_down";
			WalkRB = "AadjPknlMwlkSrasWpstDbr_down";
			WalkB = "AadjPknlMwlkSrasWpstDb_down";
			PlayerWalkF = "AadjPknlMwlkSrasWpstDf_down";
			PlayerWalkLF = "AadjPknlMwlkSrasWpstDfl_down";
			PlayerWalkRF = "AadjPknlMwlkSrasWpstDfr_down";
			PlayerWalkL = "AadjPknlMwlkSrasWpstDl_down";
			PlayerWalkR = "AadjPknlMwlkSrasWpstDr_down";
			PlayerWalkLB = "AadjPknlMwlkSrasWpstDbl_down";
			PlayerWalkRB = "AadjPknlMwlkSrasWpstDbr_down";
			PlayerWalkB = "AadjPknlMwlkSrasWpstDb_down";
			SlowF = "AadjPknlMrunSrasWpstDf_down";
			SlowLF = "AadjPknlMrunSrasWpstDfl_down";
			SlowRF = "AadjPknlMrunSrasWpstDfr_down";
			SlowL = "AadjPknlMrunSrasWpstDl_down";
			SlowR = "AadjPknlMrunSrasWpstDr_down";
			SlowLB = "AadjPknlMrunSrasWpstDbl_down";
			SlowRB = "AadjPknlMrunSrasWpstDbr_down";
			SlowB = "AadjPknlMrunSrasWpstDb_down";
			PlayerSlowF = "AadjPknlMrunSrasWpstDf_down";
			PlayerSlowLF = "AadjPknlMrunSrasWpstDfl_down";
			PlayerSlowRF = "AadjPknlMrunSrasWpstDfr_down";
			PlayerSlowL = "AadjPknlMrunSrasWpstDl_down";
			PlayerSlowR = "AadjPknlMrunSrasWpstDr_down";
			PlayerSlowLB = "AadjPknlMrunSrasWpstDbl_down";
			PlayerSlowRB = "AadjPknlMrunSrasWpstDbr_down";
			PlayerSlowB = "AadjPknlMrunSrasWpstDb_down";
			FastF = "AadjPknlMevaSrasWpstDf_down";
			FastLF = "AadjPknlMevaSrasWpstDfl_down";
			FastRF = "AadjPknlMevaSrasWpstDfr_down";
			FastL = "AadjPknlMrunSrasWpstDl_down";
			FastR = "AadjPknlMrunSrasWpstDr_down";
			FastLB = "AadjPknlMrunSrasWpstDbl_down";
			FastRB = "AadjPknlMrunSrasWpstDbr_down";
			FastB = "AadjPknlMrunSrasWpstDb_down";
			TactF = "AadjPknlMtacSrasWpstDf_down";
			TactLF = "AadjPknlMtacSrasWpstDfl_down";
			TactRF = "AadjPknlMtacSrasWpstDfr_down";
			TactL = "AadjPknlMtacSrasWpstDl_down";
			TactR = "AadjPknlMtacSrasWpstDr_down";
			TactLB = "AadjPknlMtacSrasWpstDbl_down";
			TactRB = "AadjPknlMtacSrasWpstDbr_down";
			TactB = "AadjPknlMtacSrasWpstDb_down";
			PlayerTactF = "AadjPknlMtacSrasWpstDf_down";
			PlayerTactLF = "AadjPknlMtacSrasWpstDfl_down";
			PlayerTactRF = "AadjPknlMtacSrasWpstDfr_down";
			PlayerTactL = "AadjPknlMtacSrasWpstDl_down";
			PlayerTactR = "AadjPknlMtacSrasWpstDr_down";
			PlayerTactLB = "AadjPknlMtacSrasWpstDbl_down";
			PlayerTactRB = "AadjPknlMtacSrasWpstDbr_down";
			PlayerTactB = "AadjPknlMtacSrasWpstDb_down";
			up = "AadjPercMstpSrasWpstDdown";
			PlayerStand = "AadjPercMstpSrasWpstDdown";
			Combat = "AadjPknlMstpSrasWpstDdown";
			FireNotPossible = "AadjPknlMstpSrasWpstDdown";
			Stand = "AmovPknlMstpSlowWpstDnon";
			AdjustF = "AmovPknlMstpSrasWpstDnon";
			AdjustB = "AadjPpneMstpSrasWpstDup";
		};
		class PistolAdjustLStandActionsRunF: PistolAdjustLStandActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDf_left";
			PlayerCrouch = "AadjPknlMrunSrasWpstDf_left";
			Up = "AadjPknlMrunSrasWpstDf_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustLStandActionsWlkF: PistolAdjustLStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWpstDf_left";
			Up = "AadjPknlMwlkSrasWpstDf_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustLStandActionsRunFL: PistolAdjustLStandActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDfl_left";
			PlayerCrouch = "AadjPknlMrunSrasWpstDfl_left";
			Up = "AadjPknlMrunSrasWpstDfl_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustLStandActionsWlkFL: PistolAdjustLStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWpstDfl_left";
			Up = "AadjPknlMwlkSrasWpstDfl_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustLStandActionsRunL: PistolAdjustLStandActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDl_left";
			PlayerCrouch = "AadjPknlMrunSrasWpstDl_left";
			Up = "AadjPknlMrunSrasWpstDl_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustLStandActionsWlkL: PistolAdjustLStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWpstDl_left";
			Up = "AadjPknlMwlkSrasWpstDl_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustLStandActionsRunBL: PistolAdjustLStandActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDbl_left";
			PlayerCrouch = "AadjPknlMrunSrasWpstDbl_left";
			Up = "AadjPknlMrunSrasWpstDbl_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustLStandActionsWlkBL: PistolAdjustLStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWpstDbl_left";
			Up = "AadjPknlMwlkSrasWpstDbl_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustLStandActionsRunB: PistolAdjustLStandActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDb_left";
			PlayerCrouch = "AadjPknlMrunSrasWpstDb_left";
			Up = "AadjPknlMrunSrasWpstDb_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustLStandActionsWlkB: PistolAdjustLStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWpstDb_left";
			Up = "AadjPknlMwlkSrasWpstDb_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustLStandActionsRunBR: PistolAdjustLStandActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDbr_left";
			PlayerCrouch = "AadjPknlMrunSrasWpstDbr_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustLStandActionsWlkBR: PistolAdjustLStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWpstDbr_left";
			Up = "AadjPknlMwlkSrasWpstDbr_left";
			Stand = "AadjPercMwlkSrasWpstDbr_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustLStandActionsRunR: PistolAdjustLStandActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDr_left";
			PlayerCrouch = "AadjPknlMrunSrasWpstDr_left";
			Up = "AadjPknlMrunSrasWpstDr_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustLStandActionsWlkR: PistolAdjustLStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWpstDr_left";
			Up = "AadjPknlMwlkSrasWpstDr_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustLStandActionsRunFR: PistolAdjustLStandActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDfr_left";
			PlayerCrouch = "AadjPknlMrunSrasWpstDfr_left";
			Up = "AadjPknlMrunSrasWpstDfr_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustLStandActionsWlkFR: PistolAdjustLStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWpstDfr_left";
			Up = "AadjPknlMwlkSrasWpstDfr_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustLStandEvasiveActionsF: PistolAdjustLStandActions
		{
			PlayerCrouch = "AadjPknlMevaSrasWpstDf_left";
			Up = "AadjPknlMevaSrasWpstDf_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustLStandEvasiveActionsFR: PistolAdjustLStandActions
		{
			PlayerCrouch = "AadjPknlMevaSrasWpstDfr_left";
			Up = "AadjPknlMevaSrasWpstDfr_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustLStandEvasiveActionsFL: PistolAdjustLStandActions
		{
			PlayerCrouch = "AadjPknlMevaSrasWpstDfl_left";
			Up = "AadjPknlMevaSrasWpstDfl_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustRStandActionsRunF: PistolAdjustRStandActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDf_right";
			PlayerCrouch = "AadjPknlMrunSrasWpstDf_right";
			Up = "AadjPknlMrunSrasWpstDf_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustRStandActionsWlkF: PistolAdjustRStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWpstDf_right";
			Up = "AadjPknlMwlkSrasWpstDf_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustRStandActionsRunFL: PistolAdjustRStandActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDfl_right";
			PlayerCrouch = "AadjPknlMrunSrasWpstDfl_right";
			Up = "AadjPknlMrunSrasWpstDfl_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustRStandActionsWlkFL: PistolAdjustRStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWpstDfl_right";
			Up = "AadjPknlMwlkSrasWpstDfl_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustRStandActionsRunL: PistolAdjustRStandActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDl_right";
			PlayerCrouch = "AadjPknlMrunSrasWpstDl_right";
			Up = "AadjPknlMrunSrasWpstDl_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustRStandActionsWlkL: PistolAdjustRStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWpstDl_right";
			Up = "AadjPknlMwlkSrasWpstDl_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustRStandActionsRunBL: PistolAdjustRStandActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDbl_right";
			PlayerCrouch = "AadjPknlMrunSrasWpstDbl_right";
			Up = "AadjPknlMrunSrasWpstDbl_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustRStandActionsWlkBL: PistolAdjustRStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWpstDbl_right";
			Up = "AadjPknlMwlkSrasWpstDbl_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustRStandActionsRunB: PistolAdjustRStandActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDb_right";
			PlayerCrouch = "AadjPknlMrunSrasWpstDb_right";
			Up = "AadjPknlMrunSrasWpstDb_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustRStandActionsWlkB: PistolAdjustRStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWpstDb_right";
			Up = "AadjPknlMwlkSrasWpstDb_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustRStandActionsRunBR: PistolAdjustRStandActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDbr_right";
			PlayerCrouch = "AadjPknlMrunSrasWpstDbr_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustRStandActionsWlkBR: PistolAdjustRStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWpstDbr_right";
			Up = "AadjPknlMwlkSrasWpstDbr_right";
			Stand = "AadjPercMwlkSrasWpstDbr_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustRStandActionsRunR: PistolAdjustRStandActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDr_right";
			PlayerCrouch = "AadjPknlMrunSrasWpstDr_right";
			Up = "AadjPknlMrunSrasWpstDr_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustRStandActionsWlkR: PistolAdjustRStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWpstDr_right";
			Up = "AadjPknlMwlkSrasWpstDr_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustRStandActionsRunFR: PistolAdjustRStandActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDfr_right";
			PlayerCrouch = "AadjPknlMrunSrasWpstDfr_right";
			Up = "AadjPknlMrunSrasWpstDfr_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustRStandActionsWlkFR: PistolAdjustRStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWpstDfr_right";
			Up = "AadjPknlMwlkSrasWpstDfr_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustRStandEvasiveActionsF: PistolAdjustRStandActions
		{
			PlayerCrouch = "AadjPknlMevaSrasWpstDf_right";
			Up = "AadjPknlMevaSrasWpstDf_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustRStandEvasiveActionsFR: PistolAdjustRStandActions
		{
			PlayerCrouch = "AadjPknlMevaSrasWpstDfr_right";
			Up = "AadjPknlMevaSrasWpstDfr_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustRStandEvasiveActionsFL: PistolAdjustRStandActions
		{
			PlayerCrouch = "AadjPknlMevaSrasWpstDfl_right";
			Up = "AadjPknlMevaSrasWpstDfl_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustFStandActionsRunF: PistolAdjustFStandActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDf_up";
			PlayerCrouch = "AadjPknlMrunSrasWpstDf_up";
			Up = "AadjPknlMrunSrasWpstDf_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustFStandActionsWlkF: PistolAdjustFStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWpstDf_up";
			Up = "AadjPknlMwlkSrasWpstDf_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustFStandActionsRunFL: PistolAdjustFStandActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDfl_up";
			PlayerCrouch = "AadjPknlMrunSrasWpstDfl_up";
			Up = "AadjPknlMrunSrasWpstDfl_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustFStandActionsWlkFL: PistolAdjustFStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWpstDfl_up";
			Up = "AadjPknlMwlkSrasWpstDfl_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustFStandActionsRunL: PistolAdjustFStandActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDl_up";
			PlayerCrouch = "AadjPknlMrunSrasWpstDl_up";
			Up = "AadjPknlMrunSrasWpstDl_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustFStandActionsWlkL: PistolAdjustFStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWpstDl_up";
			Up = "AadjPknlMwlkSrasWpstDl_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustFStandActionsRunBL: PistolAdjustFStandActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDbl_up";
			PlayerCrouch = "AadjPknlMrunSrasWpstDbl_up";
			Up = "AadjPknlMrunSrasWpstDbl_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustFStandActionsWlkBL: PistolAdjustFStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWpstDbl_up";
			Up = "AadjPknlMwlkSrasWpstDbl_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustFStandActionsRunB: PistolAdjustFStandActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDb_up";
			PlayerCrouch = "AadjPknlMrunSrasWpstDb_up";
			Up = "AadjPknlMrunSrasWpstDb_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustFStandActionsWlkB: PistolAdjustFStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWpstDb_up";
			Up = "AadjPknlMwlkSrasWpstDb_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustFStandActionsRunBR: PistolAdjustFStandActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDbr_up";
			PlayerCrouch = "AadjPknlMrunSrasWpstDbr_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustFStandActionsWlkBR: PistolAdjustFStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWpstDbr_up";
			Up = "AadjPknlMwlkSrasWpstDbr_up";
			Stand = "AadjPercMwlkSrasWpstDbr_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustFStandActionsRunR: PistolAdjustFStandActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDr_up";
			PlayerCrouch = "AadjPknlMrunSrasWpstDr_up";
			Up = "AadjPknlMrunSrasWpstDr_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustFStandActionsWlkR: PistolAdjustFStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWpstDr_up";
			Up = "AadjPknlMwlkSrasWpstDr_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustFStandActionsRunFR: PistolAdjustFStandActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDfr_up";
			PlayerCrouch = "AadjPknlMrunSrasWpstDfr_up";
			Up = "AadjPknlMrunSrasWpstDfr_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustFStandActionsWlkFR: PistolAdjustFStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWpstDfr_up";
			Up = "AadjPknlMwlkSrasWpstDfr_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustFStandEvasiveActionsF: PistolAdjustFStandActions
		{
			PlayerCrouch = "AadjPknlMevaSrasWpstDf_up";
			Up = "AadjPknlMevaSrasWpstDf_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustFStandEvasiveActionsFR: PistolAdjustFStandActions
		{
			PlayerCrouch = "AadjPknlMevaSrasWpstDfr_up";
			Up = "AadjPknlMevaSrasWpstDfr_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustFStandEvasiveActionsFL: PistolAdjustFStandActions
		{
			PlayerCrouch = "AadjPknlMevaSrasWpstDfl_up";
			Up = "AadjPknlMevaSrasWpstDfl_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustBStandActionsRunF: PistolAdjustBStandActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDf_down";
			PlayerCrouch = "AadjPknlMrunSrasWpstDf_down";
			Up = "AadjPknlMrunSrasWpstDf_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustBStandActionsWlkF: PistolAdjustBStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWpstDf_down";
			Up = "AadjPknlMwlkSrasWpstDf_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustBStandActionsRunFL: PistolAdjustBStandActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDfl_down";
			PlayerCrouch = "AadjPknlMrunSrasWpstDfl_down";
			Up = "AadjPknlMrunSrasWpstDfl_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustBStandActionsWlkFL: PistolAdjustBStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWpstDfl_down";
			Up = "AadjPknlMwlkSrasWpstDfl_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustBStandActionsRunL: PistolAdjustBStandActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDl_down";
			PlayerCrouch = "AadjPknlMrunSrasWpstDl_down";
			Up = "AadjPknlMrunSrasWpstDl_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustBStandActionsWlkL: PistolAdjustBStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWpstDl_down";
			Up = "AadjPknlMwlkSrasWpstDl_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustBStandActionsRunBL: PistolAdjustBStandActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDbl_down";
			PlayerCrouch = "AadjPknlMrunSrasWpstDbl_down";
			Up = "AadjPknlMrunSrasWpstDbl_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustBStandActionsWlkBL: PistolAdjustBStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWpstDbl_down";
			Up = "AadjPknlMwlkSrasWpstDbl_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustBStandActionsRunB: PistolAdjustBStandActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDb_down";
			PlayerCrouch = "AadjPknlMrunSrasWpstDb_down";
			Up = "AadjPknlMrunSrasWpstDb_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustBStandActionsWlkB: PistolAdjustBStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWpstDb_down";
			Up = "AadjPknlMwlkSrasWpstDb_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustBStandActionsRunBR: PistolAdjustBStandActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDbr_down";
			PlayerCrouch = "AadjPknlMrunSrasWpstDbr_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustBStandActionsWlkBR: PistolAdjustBStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWpstDbr_down";
			Up = "AadjPknlMwlkSrasWpstDbr_down";
			Stand = "AadjPercMwlkSrasWpstDbr_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustBStandActionsRunR: PistolAdjustBStandActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDr_down";
			PlayerCrouch = "AadjPknlMrunSrasWpstDr_down";
			Up = "AadjPknlMrunSrasWpstDr_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustBStandActionsWlkR: PistolAdjustBStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWpstDr_down";
			Up = "AadjPknlMwlkSrasWpstDr_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustBStandActionsRunFR: PistolAdjustBStandActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDfr_down";
			PlayerCrouch = "AadjPknlMrunSrasWpstDfr_down";
			Up = "AadjPknlMrunSrasWpstDfr_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustBStandActionsWlkFR: PistolAdjustBStandActions
		{
			PlayerCrouch = "AadjPknlMwlkSrasWpstDfr_down";
			Up = "AadjPknlMwlkSrasWpstDfr_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustBStandEvasiveActionsF: PistolAdjustBStandActions
		{
			PlayerCrouch = "AadjPknlMevaSrasWpstDf_down";
			Up = "AadjPknlMevaSrasWpstDf_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustBStandEvasiveActionsFR: PistolAdjustBStandActions
		{
			PlayerCrouch = "AadjPknlMevaSrasWpstDfr_down";
			Up = "AadjPknlMevaSrasWpstDfr_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustBStandEvasiveActionsFL: PistolAdjustBStandActions
		{
			PlayerCrouch = "AadjPknlMevaSrasWpstDfl_down";
			Up = "AadjPknlMevaSrasWpstDfl_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustLStandActionsTacF: PistolAdjustLStandActions
		{
			PlayerStand = "AadjPercMrunSrasWpstDf_left";
			PlayerCrouch = "AadjPknlMtacSrasWpstDf_left";
			Up = "AadjPknlMtacSrasWpstDf_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustLStandActionsTacFL: PistolAdjustLStandActions
		{
			PlayerStand = "AadjPercMrunSrasWpstDfl_left";
			PlayerCrouch = "AadjPknlMtacSrasWpstDfl_left";
			Up = "AadjPknlMtacSrasWpstDfl_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustLStandActionsTacL: PistolAdjustLStandActions
		{
			PlayerStand = "AadjPercMrunSrasWpstDl_left";
			PlayerCrouch = "AadjPknlMtacSrasWpstDl_left";
			Up = "AadjPknlMtacSrasWpstDl_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustLStandActionsTacBL: PistolAdjustLStandActions
		{
			PlayerStand = "AadjPercMrunSrasWpstDbl_left";
			PlayerCrouch = "AadjPknlMtacSrasWpstDbl_left";
			Up = "AadjPknlMtacSrasWpstDbl_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustLStandActionsTacB: PistolAdjustLStandActions
		{
			PlayerStand = "AadjPercMrunSrasWpstDb_left";
			PlayerCrouch = "AadjPknlMtacSrasWpstDb_left";
			Up = "AadjPknlMtacSrasWpstDb_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustLStandActionsTacBR: PistolAdjustLStandActions
		{
			PlayerStand = "AadjPercMrunSrasWpstDbr_left";
			PlayerCrouch = "AadjPknlMtacSrasWpstDbr_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustLStandActionsTacR: PistolAdjustLStandActions
		{
			PlayerStand = "AadjPercMrunSrasWpstDr_left";
			PlayerCrouch = "AadjPknlMtacSrasWpstDr_left";
			Up = "AadjPknlMtacSrasWpstDr_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustLStandActionsTacFR: PistolAdjustLStandActions
		{
			PlayerStand = "AadjPercMrunSrasWpstDfr_left";
			PlayerCrouch = "AadjPknlMtacSrasWpstDfr_left";
			Up = "AadjPknlMtacSrasWpstDfr_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustRStandActionsTacF: PistolAdjustRStandActions
		{
			PlayerStand = "AadjPercMrunSrasWpstDf_right";
			PlayerCrouch = "AadjPknlMtacSrasWpstDf_right";
			Up = "AadjPknlMtacSrasWpstDf_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustRStandActionsTacFL: PistolAdjustRStandActions
		{
			PlayerStand = "AadjPercMrunSrasWpstDfl_right";
			PlayerCrouch = "AadjPknlMtacSrasWpstDfl_right";
			Up = "AadjPknlMtacSrasWpstDfl_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustRStandActionsTacL: PistolAdjustRStandActions
		{
			PlayerStand = "AadjPercMrunSrasWpstDl_right";
			PlayerCrouch = "AadjPknlMtacSrasWpstDl_right";
			Up = "AadjPknlMtacSrasWpstDl_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustRStandActionsTacBL: PistolAdjustRStandActions
		{
			PlayerStand = "AadjPercMrunSrasWpstDbl_right";
			PlayerCrouch = "AadjPknlMtacSrasWpstDbl_right";
			Up = "AadjPknlMtacSrasWpstDbl_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustRStandActionsTacB: PistolAdjustRStandActions
		{
			PlayerStand = "AadjPercMrunSrasWpstDb_right";
			PlayerCrouch = "AadjPknlMtacSrasWpstDb_right";
			Up = "AadjPknlMtacSrasWpstDb_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustRStandActionsTacBR: PistolAdjustRStandActions
		{
			PlayerStand = "AadjPercMrunSrasWpstDbr_right";
			PlayerCrouch = "AadjPknlMtacSrasWpstDbr_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustRStandActionsTacR: PistolAdjustRStandActions
		{
			PlayerStand = "AadjPercMrunSrasWpstDr_right";
			PlayerCrouch = "AadjPknlMtacSrasWpstDr_right";
			Up = "AadjPknlMtacSrasWpstDr_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustRStandActionsTacFR: PistolAdjustRStandActions
		{
			PlayerStand = "AadjPercMrunSrasWpstDfr_right";
			PlayerCrouch = "AadjPknlMtacSrasWpstDfr_right";
			Up = "AadjPknlMtacSrasWpstDfr_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustFStandActionsTacF: PistolAdjustFStandActions
		{
			PlayerStand = "AadjPercMrunSrasWpstDf_up";
			PlayerCrouch = "AadjPknlMtacSrasWpstDf_up";
			Up = "AadjPknlMtacSrasWpstDf_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustFStandActionsTacFL: PistolAdjustFStandActions
		{
			PlayerStand = "AadjPercMrunSrasWpstDfl_up";
			PlayerCrouch = "AadjPknlMtacSrasWpstDfl_up";
			Up = "AadjPknlMtacSrasWpstDfl_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustFStandActionsTacL: PistolAdjustFStandActions
		{
			PlayerStand = "AadjPercMrunSrasWpstDl_up";
			PlayerCrouch = "AadjPknlMtacSrasWpstDl_up";
			Up = "AadjPknlMtacSrasWpstDl_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustFStandActionsTacBL: PistolAdjustFStandActions
		{
			PlayerStand = "AadjPercMrunSrasWpstDbl_up";
			PlayerCrouch = "AadjPknlMtacSrasWpstDbl_up";
			Up = "AadjPknlMtacSrasWpstDbl_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustFStandActionsTacB: PistolAdjustFStandActions
		{
			PlayerStand = "AadjPercMrunSrasWpstDb_up";
			PlayerCrouch = "AadjPknlMtacSrasWpstDb_up";
			Up = "AadjPknlMtacSrasWpstDb_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustFStandActionsTacBR: PistolAdjustFStandActions
		{
			PlayerStand = "AadjPercMrunSrasWpstDbr_up";
			PlayerCrouch = "AadjPknlMtacSrasWpstDbr_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustFStandActionsTacR: PistolAdjustFStandActions
		{
			PlayerStand = "AadjPercMrunSrasWpstDr_up";
			PlayerCrouch = "AadjPknlMtacSrasWpstDr_up";
			Up = "AadjPknlMtacSrasWpstDr_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustFStandActionsTacFR: PistolAdjustFStandActions
		{
			PlayerStand = "AadjPercMrunSrasWpstDfr_up";
			PlayerCrouch = "AadjPknlMtacSrasWpstDfr_up";
			Up = "AadjPknlMtacSrasWpstDfr_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustBStandActionsTacF: PistolAdjustBStandActions
		{
			PlayerStand = "AadjPercMrunSrasWpstDf_down";
			PlayerCrouch = "AadjPknlMtacSrasWpstDf_down";
			Up = "AadjPknlMtacSrasWpstDf_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustBStandActionsTacFL: PistolAdjustBStandActions
		{
			PlayerStand = "AadjPercMrunSrasWpstDfl_down";
			PlayerCrouch = "AadjPknlMtacSrasWpstDfl_down";
			Up = "AadjPknlMtacSrasWpstDfl_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustBStandActionsTacL: PistolAdjustBStandActions
		{
			PlayerStand = "AadjPercMrunSrasWpstDl_down";
			PlayerCrouch = "AadjPknlMtacSrasWpstDl_down";
			Up = "AadjPknlMtacSrasWpstDl_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustBStandActionsTacBL: PistolAdjustBStandActions
		{
			PlayerStand = "AadjPercMrunSrasWpstDbl_down";
			PlayerCrouch = "AadjPknlMtacSrasWpstDbl_down";
			Up = "AadjPknlMtacSrasWpstDbl_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustBStandActionsTacB: PistolAdjustBStandActions
		{
			PlayerStand = "AadjPercMrunSrasWpstDb_down";
			PlayerCrouch = "AadjPknlMtacSrasWpstDb_down";
			Up = "AadjPknlMtacSrasWpstDb_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustBStandActionsTacBR: PistolAdjustBStandActions
		{
			PlayerStand = "AadjPercMrunSrasWpstDbr_down";
			PlayerCrouch = "AadjPknlMtacSrasWpstDbr_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustBStandActionsTacR: PistolAdjustBStandActions
		{
			PlayerStand = "AadjPercMrunSrasWpstDr_down";
			PlayerCrouch = "AadjPknlMtacSrasWpstDr_down";
			Up = "AadjPknlMtacSrasWpstDr_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustBStandActionsTacFR: PistolAdjustBStandActions
		{
			PlayerStand = "AadjPercMrunSrasWpstDfr_down";
			PlayerCrouch = "AadjPknlMtacSrasWpstDfr_down";
			Up = "AadjPknlMtacSrasWpstDfr_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustLKneelActionsRunF: PistolAdjustLKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWpstDf_left";
			PlayerStand = "AadjPercMrunSrasWpstDf_left";
			Up = "AadjPercMrunSrasWpstDf_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustLKneelActionsWlkF: PistolAdjustLKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWpstDf_left";
			Up = "AadjPercMwlkSrasWpstDf_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustLKneelActionsRunFL: PistolAdjustLKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWpstDfl_left";
			PlayerStand = "AadjPercMrunSrasWpstDfl_left";
			Up = "AadjPercMrunSrasWpstDfl_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustLKneelActionsWlkFL: PistolAdjustLKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWpstDfl_left";
			Up = "AadjPercMwlkSrasWpstDfl_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustLKneelActionsRunL: PistolAdjustLKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWpstDl_left";
			PlayerStand = "AadjPercMrunSrasWpstDl_left";
			Up = "AadjPercMrunSrasWpstDl_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustLKneelActionsWlkL: PistolAdjustLKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWpstDl_left";
			Up = "AadjPercMwlkSrasWpstDl_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustLKneelActionsRunBL: PistolAdjustLKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWpstDbl_left";
			PlayerStand = "AadjPercMrunSrasWpstDbl_left";
			Up = "AadjPercMrunSrasWpstDbl_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustLKneelActionsWlkBL: PistolAdjustLKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWpstDbl_left";
			Up = "AadjPercMwlkSrasWpstDbl_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustLKneelActionsRunB: PistolAdjustLKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWpstDb_left";
			PlayerStand = "AadjPercMrunSrasWpstDb_left";
			Up = "AadjPercMrunSrasWpstDb_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustLKneelActionsWlkB: PistolAdjustLKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWpstDb_left";
			Up = "AadjPercMwlkSrasWpstDb_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustLKneelActionsRunBR: PistolAdjustLKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWpstDbr_left";
			PlayerStand = "AadjPercMrunSrasWpstDbr_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustLKneelActionsWlkBR: PistolAdjustLKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWpstDbr_left";
			Up = "AadjPercMwlkSrasWpstDbr_left";
			Stand = "AadjPknlMwlkSrasWpstDbr_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustLKneelActionsRunR: PistolAdjustLKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWpstDr_left";
			PlayerStand = "AadjPercMrunSrasWpstDr_left";
			Up = "AadjPercMrunSrasWpstDr_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustLKneelActionsWlkR: PistolAdjustLKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWpstDr_left";
			Up = "AadjPercMwlkSrasWpstDr_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustLKneelActionsRunFR: PistolAdjustLKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWpstDfr_left";
			PlayerStand = "AadjPercMrunSrasWpstDfr_left";
			Up = "AadjPercMrunSrasWpstDfr_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustLKneelActionsWlkFR: PistolAdjustLKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWpstDfr_left";
			Up = "AadjPercMwlkSrasWpstDfr_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustLKneelEvasiveActionsF: PistolAdjustLKneelActions
		{
			PlayerStand = "AadjPercMevaSrasWpstDf_left";
			Up = "AadjPercMevaSrasWpstDf_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustLKneelEvasiveActionsFR: PistolAdjustLKneelActions
		{
			PlayerStand = "AadjPercMevaSrasWpstDfr_left";
			Up = "AadjPercMevaSrasWpstDfr_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustLKneelEvasiveActionsFL: PistolAdjustLKneelActions
		{
			PlayerStand = "AadjPercMevaSrasWpstDfl_left";
			Up = "AadjPercMevaSrasWpstDfl_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustRKneelActionsRunF: PistolAdjustRKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWpstDf_right";
			PlayerStand = "AadjPercMrunSrasWpstDf_right";
			Up = "AadjPercMrunSrasWpstDf_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustRKneelActionsWlkF: PistolAdjustRKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWpstDf_right";
			Up = "AadjPercMwlkSrasWpstDf_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustRKneelActionsRunFL: PistolAdjustRKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWpstDfl_right";
			PlayerStand = "AadjPercMrunSrasWpstDfl_right";
			Up = "AadjPercMrunSrasWpstDfl_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustRKneelActionsWlkFL: PistolAdjustRKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWpstDfl_right";
			Up = "AadjPercMwlkSrasWpstDfl_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustRKneelActionsRunL: PistolAdjustRKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWpstDl_right";
			PlayerStand = "AadjPercMrunSrasWpstDl_right";
			Up = "AadjPercMrunSrasWpstDl_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustRKneelActionsWlkL: PistolAdjustRKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWpstDl_right";
			Up = "AadjPercMwlkSrasWpstDl_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustRKneelActionsRunBL: PistolAdjustRKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWpstDbl_right";
			PlayerStand = "AadjPercMrunSrasWpstDbl_right";
			Up = "AadjPercMrunSrasWpstDbl_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustRKneelActionsWlkBL: PistolAdjustRKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWpstDbl_right";
			Up = "AadjPercMwlkSrasWpstDbl_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustRKneelActionsRunB: PistolAdjustRKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWpstDb_right";
			PlayerStand = "AadjPercMrunSrasWpstDb_right";
			Up = "AadjPercMrunSrasWpstDb_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustRKneelActionsWlkB: PistolAdjustRKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWpstDb_right";
			Up = "AadjPercMwlkSrasWpstDb_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustRKneelActionsRunBR: PistolAdjustRKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWpstDbr_right";
			PlayerStand = "AadjPercMrunSrasWpstDbr_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustRKneelActionsWlkBR: PistolAdjustRKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWpstDbr_right";
			Up = "AadjPercMwlkSrasWpstDbr_right";
			Stand = "AadjPknlMwlkSrasWpstDbr_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustRKneelActionsRunR: PistolAdjustRKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWpstDr_right";
			PlayerStand = "AadjPercMrunSrasWpstDr_right";
			Up = "AadjPercMrunSrasWpstDr_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustRKneelActionsWlkR: PistolAdjustRKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWpstDr_right";
			Up = "AadjPercMwlkSrasWpstDr_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustRKneelActionsRunFR: PistolAdjustRKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWpstDfr_right";
			PlayerStand = "AadjPercMrunSrasWpstDfr_right";
			Up = "AadjPercMrunSrasWpstDfr_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustRKneelActionsWlkFR: PistolAdjustRKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWpstDfr_right";
			Up = "AadjPercMwlkSrasWpstDfr_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustRKneelEvasiveActionsF: PistolAdjustRKneelActions
		{
			PlayerStand = "AadjPercMevaSrasWpstDf_left";
			Up = "AadjPercMevaSrasWpstDf_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustRKneelEvasiveActionsFR: PistolAdjustRKneelActions
		{
			PlayerStand = "AadjPercMevaSrasWpstDfr_left";
			Up = "AadjPercMevaSrasWpstDfr_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustRKneelEvasiveActionsFL: PistolAdjustRKneelActions
		{
			PlayerStand = "AadjPercMevaSrasWpstDfl_left";
			Up = "AadjPercMevaSrasWpstDfl_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustFKneelActionsRunF: PistolAdjustFKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWpstDf_up";
			PlayerStand = "AadjPercMrunSrasWpstDf_up";
			Up = "AadjPercMrunSrasWpstDf_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustFKneelActionsWlkF: PistolAdjustFKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWpstDf_up";
			Up = "AadjPercMwlkSrasWpstDf_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustFKneelActionsRunFL: PistolAdjustFKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWpstDfl_up";
			PlayerStand = "AadjPercMrunSrasWpstDfl_up";
			Up = "AadjPercMrunSrasWpstDfl_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustFKneelActionsWlkFL: PistolAdjustFKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWpstDfl_up";
			Up = "AadjPercMwlkSrasWpstDfl_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustFKneelActionsRunL: PistolAdjustFKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWpstDl_up";
			PlayerStand = "AadjPercMrunSrasWpstDl_up";
			Up = "AadjPercMrunSrasWpstDl_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustFKneelActionsWlkL: PistolAdjustFKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWpstDl_up";
			Up = "AadjPercMwlkSrasWpstDl_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustFKneelActionsRunBL: PistolAdjustFKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWpstDbl_up";
			PlayerStand = "AadjPercMrunSrasWpstDbl_up";
			Up = "AadjPercMrunSrasWpstDbl_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustFKneelActionsWlkBL: PistolAdjustFKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWpstDbl_up";
			Up = "AadjPercMwlkSrasWpstDbl_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustFKneelActionsRunB: PistolAdjustFKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWpstDb_up";
			PlayerStand = "AadjPercMrunSrasWpstDb_up";
			Up = "AadjPercMrunSrasWpstDb_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustFKneelActionsWlkB: PistolAdjustFKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWpstDb_up";
			Up = "AadjPercMwlkSrasWpstDb_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustFKneelActionsRunBR: PistolAdjustFKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWpstDbr_up";
			PlayerStand = "AadjPercMrunSrasWpstDbr_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustFKneelActionsWlkBR: PistolAdjustFKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWpstDbr_up";
			Up = "AadjPercMwlkSrasWpstDbr_up";
			Stand = "AadjPknlMwlkSrasWpstDbr_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustFKneelActionsRunR: PistolAdjustFKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWpstDr_up";
			PlayerStand = "AadjPercMrunSrasWpstDr_up";
			Up = "AadjPercMrunSrasWpstDr_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustFKneelActionsWlkR: PistolAdjustFKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWpstDr_up";
			Up = "AadjPercMwlkSrasWpstDr_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustFKneelActionsRunFR: PistolAdjustFKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWpstDfr_up";
			PlayerStand = "AadjPercMrunSrasWpstDfr_up";
			Up = "AadjPercMrunSrasWpstDfr_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustFKneelActionsWlkFR: PistolAdjustFKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWpstDfr_up";
			Up = "AadjPercMwlkSrasWpstDfr_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustFKneelEvasiveActionsF: PistolAdjustFKneelActions
		{
			PlayerStand = "AadjPercMevaSrasWpstDf_left";
			Up = "AadjPercMevaSrasWpstDf_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustFKneelEvasiveActionsFR: PistolAdjustFKneelActions
		{
			PlayerStand = "AadjPercMevaSrasWpstDfr_left";
			Up = "AadjPercMevaSrasWpstDfr_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustFKneelEvasiveActionsFL: PistolAdjustFKneelActions
		{
			PlayerStand = "AadjPercMevaSrasWpstDfl_left";
			Up = "AadjPercMevaSrasWpstDfl_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustBKneelActionsRunF: PistolAdjustBKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWpstDf_down";
			PlayerStand = "AadjPercMrunSrasWpstDf_down";
			Up = "AadjPercMrunSrasWpstDf_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustBKneelActionsWlkF: PistolAdjustBKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWpstDf_down";
			Up = "AadjPercMwlkSrasWpstDf_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustBKneelActionsRunFL: PistolAdjustBKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWpstDfl_down";
			PlayerStand = "AadjPercMrunSrasWpstDfl_down";
			Up = "AadjPercMrunSrasWpstDfl_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustBKneelActionsWlkFL: PistolAdjustBKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWpstDfl_down";
			Up = "AadjPercMwlkSrasWpstDfl_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustBKneelActionsRunL: PistolAdjustBKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWpstDl_down";
			PlayerStand = "AadjPercMrunSrasWpstDl_down";
			Up = "AadjPercMrunSrasWpstDl_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustBKneelActionsWlkL: PistolAdjustBKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWpstDl_down";
			Up = "AadjPercMwlkSrasWpstDl_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustBKneelActionsRunBL: PistolAdjustBKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWpstDbl_down";
			PlayerStand = "AadjPercMrunSrasWpstDbl_down";
			Up = "AadjPercMrunSrasWpstDbl_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustBKneelActionsWlkBL: PistolAdjustBKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWpstDbl_down";
			Up = "AadjPercMwlkSrasWpstDbl_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustBKneelActionsRunB: PistolAdjustBKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWpstDb_down";
			PlayerStand = "AadjPercMrunSrasWpstDb_down";
			Up = "AadjPercMrunSrasWpstDb_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustBKneelActionsWlkB: PistolAdjustBKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWpstDb_down";
			Up = "AadjPercMwlkSrasWpstDb_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustBKneelActionsRunBR: PistolAdjustBKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWpstDbr_down";
			PlayerStand = "AadjPercMrunSrasWpstDbr_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustBKneelActionsWlkBR: PistolAdjustBKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWpstDbr_down";
			Up = "AadjPercMwlkSrasWpstDbr_down";
			Stand = "AadjPknlMwlkSrasWpstDbr_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustBKneelActionsRunR: PistolAdjustBKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWpstDr_down";
			PlayerStand = "AadjPercMrunSrasWpstDr_down";
			Up = "AadjPercMrunSrasWpstDr_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustBKneelActionsWlkR: PistolAdjustBKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWpstDr_down";
			Up = "AadjPercMwlkSrasWpstDr_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustBKneelActionsRunFR: PistolAdjustBKneelActions
		{
			PlayerCrouch = "AadjPknlMtacSrasWpstDfr_down";
			PlayerStand = "AadjPercMrunSrasWpstDfr_down";
			Up = "AadjPercMrunSrasWpstDfr_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustBKneelActionsWlkFR: PistolAdjustBKneelActions
		{
			PlayerStand = "AadjPercMwlkSrasWpstDfr_down";
			Up = "AadjPercMwlkSrasWpstDfr_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustBKneelEvasiveActionsF: PistolAdjustBKneelActions
		{
			PlayerStand = "AadjPercMevaSrasWpstDf_left";
			Up = "AadjPercMevaSrasWpstDf_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustBKneelEvasiveActionsFR: PistolAdjustBKneelActions
		{
			PlayerStand = "AadjPercMevaSrasWpstDfr_left";
			Up = "AadjPercMevaSrasWpstDfr_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustBKneelEvasiveActionsFL: PistolAdjustBKneelActions
		{
			PlayerStand = "AadjPercMevaSrasWpstDfl_left";
			Up = "AadjPercMevaSrasWpstDfl_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustLKneelActionsTacF: PistolAdjustLKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDf_left";
			PlayerCrouch = "AadjPknlMrunSrasWpstDf_left";
			Up = "AadjPercMtacSrasWpstDf_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustLKneelActionsTacFL: PistolAdjustLKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDfl_left";
			PlayerCrouch = "AadjPknlMrunSrasWpstDfl_left";
			Up = "AadjPercMtacSrasWpstDfl_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustLKneelActionsTacL: PistolAdjustLKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDl_left";
			PlayerCrouch = "AadjPknlMrunSrasWpstDl_left";
			Up = "AadjPercMtacSrasWpstDl_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustLKneelActionsTacBL: PistolAdjustLKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDbl_left";
			PlayerCrouch = "AadjPknlMrunSrasWpstDbl_left";
			Up = "AadjPercMtacSrasWpstDbl_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustLKneelActionsTacB: PistolAdjustLKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDb_left";
			PlayerCrouch = "AadjPknlMrunSrasWpstDb_left";
			Up = "AadjPercMtacSrasWpstDb_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustLKneelActionsTacBR: PistolAdjustLKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDbr_left";
			PlayerCrouch = "AadjPknlMrunSrasWpstDbr_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustLKneelActionsTacR: PistolAdjustLKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDr_left";
			PlayerCrouch = "AadjPknlMrunSrasWpstDr_left";
			Up = "AadjPercMtacSrasWpstDr_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustLKneelActionsTacFR: PistolAdjustLKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDfr_left";
			PlayerCrouch = "AadjPknlMrunSrasWpstDfr_left";
			Up = "AadjPercMtacSrasWpstDfr_left";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustRKneelActionsTacF: PistolAdjustRKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDf_right";
			PlayerCrouch = "AadjPknlMrunSrasWpstDf_right";
			Up = "AadjPercMtacSrasWpstDf_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustRKneelActionsTacFL: PistolAdjustRKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDfl_right";
			PlayerCrouch = "AadjPknlMrunSrasWpstDfl_right";
			Up = "AadjPercMtacSrasWpstDfl_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustRKneelActionsTacL: PistolAdjustRKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDl_right";
			PlayerCrouch = "AadjPknlMrunSrasWpstDl_right";
			Up = "AadjPercMtacSrasWpstDl_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustRKneelActionsTacBL: PistolAdjustRKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDbl_right";
			PlayerCrouch = "AadjPknlMrunSrasWpstDbl_right";
			Up = "AadjPercMtacSrasWpstDbl_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustRKneelActionsTacB: PistolAdjustRKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDb_right";
			PlayerCrouch = "AadjPknlMrunSrasWpstDb_right";
			Up = "AadjPercMtacSrasWpstDb_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustRKneelActionsTacBR: PistolAdjustRKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDbr_right";
			PlayerCrouch = "AadjPknlMrunSrasWpstDbr_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustRKneelActionsTacR: PistolAdjustRKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDr_right";
			PlayerCrouch = "AadjPknlMrunSrasWpstDr_right";
			Up = "AadjPercMtacSrasWpstDr_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustRKneelActionsTacFR: PistolAdjustRKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDfr_right";
			PlayerCrouch = "AadjPknlMrunSrasWpstDfr_right";
			Up = "AadjPercMtacSrasWpstDfr_right";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustFKneelActionsTacF: PistolAdjustFKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDf_up";
			PlayerCrouch = "AadjPknlMrunSrasWpstDf_up";
			Up = "AadjPercMtacSrasWpstDf_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustFKneelActionsTacFL: PistolAdjustFKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDfl_up";
			PlayerCrouch = "AadjPknlMrunSrasWpstDfl_up";
			Up = "AadjPercMtacSrasWpstDfl_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustFKneelActionsTacL: PistolAdjustFKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDl_up";
			PlayerCrouch = "AadjPknlMrunSrasWpstDl_up";
			Up = "AadjPercMtacSrasWpstDl_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustFKneelActionsTacBL: PistolAdjustFKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDbl_up";
			PlayerCrouch = "AadjPknlMrunSrasWpstDbl_up";
			Up = "AadjPercMtacSrasWpstDbl_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustFKneelActionsTacB: PistolAdjustFKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDb_up";
			PlayerCrouch = "AadjPknlMrunSrasWpstDb_up";
			Up = "AadjPercMtacSrasWpstDb_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustFKneelActionsTacBR: PistolAdjustFKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDbr_up";
			PlayerCrouch = "AadjPknlMrunSrasWpstDbr_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustFKneelActionsTacR: PistolAdjustFKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDr_up";
			PlayerCrouch = "AadjPknlMrunSrasWpstDr_up";
			Up = "AadjPercMtacSrasWpstDr_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustFKneelActionsTacFR: PistolAdjustFKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDfr_up";
			PlayerCrouch = "AadjPknlMrunSrasWpstDfr_up";
			Up = "AadjPercMtacSrasWpstDfr_up";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustBKneelActionsTacF: PistolAdjustBKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDf_down";
			PlayerCrouch = "AadjPknlMrunSrasWpstDf_down";
			Up = "AadjPercMtacSrasWpstDf_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustBKneelActionsTacFL: PistolAdjustBKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDfl_down";
			PlayerCrouch = "AadjPknlMrunSrasWpstDfl_down";
			Up = "AadjPercMtacSrasWpstDfl_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustBKneelActionsTacL: PistolAdjustBKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDl_down";
			PlayerCrouch = "AadjPknlMrunSrasWpstDl_down";
			Up = "AadjPercMtacSrasWpstDl_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustBKneelActionsTacBL: PistolAdjustBKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDbl_down";
			PlayerCrouch = "AadjPknlMrunSrasWpstDbl_down";
			Up = "AadjPercMtacSrasWpstDbl_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustBKneelActionsTacB: PistolAdjustBKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDb_down";
			PlayerCrouch = "AadjPknlMrunSrasWpstDb_down";
			Up = "AadjPercMtacSrasWpstDb_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustBKneelActionsTacBR: PistolAdjustBKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDbr_down";
			PlayerCrouch = "AadjPknlMrunSrasWpstDbr_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustBKneelActionsTacR: PistolAdjustBKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDr_down";
			PlayerCrouch = "AadjPknlMrunSrasWpstDr_down";
			Up = "AadjPercMtacSrasWpstDr_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class PistolAdjustBKneelActionsTacFR: PistolAdjustBKneelActions
		{
			PlayerStand = "AadjPercMtacSrasWpstDfr_down";
			PlayerCrouch = "AadjPknlMrunSrasWpstDfr_down";
			Up = "AadjPercMtacSrasWpstDfr_down";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
		};
		class ParachuteFreeFall: NoActions
		{
			upDegree = "ManPosFreefall";
			Stop = "AmovPpneMstpSnonWnonDnon";
			StopRelaxed = "AmovPpneMstpSnonWnonDnon";
			Default = "HaloFreeFall_non";
			WalkF = "HaloFreeFall_F";
			WalkLF = "HaloFreeFall_FL";
			WalkRF = "HaloFreeFall_FR";
			WalkL = "HaloFreeFall_L";
			WalkR = "HaloFreeFall_R";
			WalkLB = "HaloFreeFall_BL";
			WalkRB = "HaloFreeFall_BR";
			WalkB = "HaloFreeFall_B";
			PlayerWalkF = "HaloFreeFall_F";
			PlayerWalkLF = "HaloFreeFall_FL";
			PlayerWalkRF = "HaloFreeFall_FR";
			PlayerWalkL = "HaloFreeFall_L";
			PlayerWalkR = "HaloFreeFall_R";
			PlayerWalkLB = "HaloFreeFall_BL";
			PlayerWalkRB = "HaloFreeFall_BR";
			PlayerWalkB = "HaloFreeFall_B";
			SlowF = "HaloFreeFall_F";
			SlowLF = "HaloFreeFall_FL";
			SlowRF = "HaloFreeFall_FR";
			SlowL = "HaloFreeFall_L";
			SlowR = "HaloFreeFall_R";
			SlowLB = "HaloFreeFall_BL";
			SlowRB = "HaloFreeFall_BR";
			SlowB = "HaloFreeFall_B";
			PlayerSlowF = "HaloFreeFall_F";
			PlayerSlowLF = "HaloFreeFall_FL";
			PlayerSlowRF = "HaloFreeFall_FR";
			PlayerSlowL = "HaloFreeFall_L";
			PlayerSlowR = "HaloFreeFall_R";
			PlayerSlowLB = "HaloFreeFall_BL";
			PlayerSlowRB = "HaloFreeFall_BR";
			PlayerSlowB = "HaloFreeFall_B";
			FastF = "HaloFreeFall_F";
			FastLF = "HaloFreeFall_FL";
			FastRF = "HaloFreeFall_FR";
			FastL = "HaloFreeFall_L";
			FastR = "HaloFreeFall_R";
			FastLB = "HaloFreeFall_BL";
			FastRB = "HaloFreeFall_BR";
			FastB = "HaloFreeFall_B";
			TactF = "HaloFreeFall_F";
			TactLF = "HaloFreeFall_FL";
			TactRF = "HaloFreeFall_FR";
			TactL = "HaloFreeFall_L";
			TactR = "HaloFreeFall_R";
			TactLB = "HaloFreeFall_BL";
			TactRB = "HaloFreeFall_BR";
			TactB = "HaloFreeFall_B";
			PlayerTactF = "HaloFreeFall_F";
			PlayerTactLF = "HaloFreeFall_FL";
			PlayerTactRF = "HaloFreeFall_FR";
			PlayerTactL = "HaloFreeFall_L";
			PlayerTactR = "HaloFreeFall_R";
			PlayerTactLB = "HaloFreeFall_BL";
			PlayerTactRB = "HaloFreeFall_BR";
			PlayerTactB = "HaloFreeFall_B";
			EvasiveLeft = "HaloFreeFall_FL";
			EvasiveRight = "HaloFreeFall_FR";
			Combat = "AmovPercMstpSrasWrflDnon";
			Civil = "AmovPercMstpSnonWnonDnon";
			startSwim = "AswmPercMrunSnonWnonDf";
			surfaceSwim = "AsswPercMrunSnonWnonDf";
			bottomSwim = "AbswPercMrunSnonWnonDf";
			StopSwim = "AmovPercMstpSnonWnonDnon";
		};
		class RifleStandActions_inv: RifleLowStandActions
		{
			Stop = "AinvPercMstpSrasWrflDnon";
			StopRelaxed = "AinvPercMstpSrasWrflDnon";
			Default = "AinvPercMstpSrasWrflDnon";
			PlayerStand = "AmovPercMstpSrasWrflDnon";
			Civil = "AinvPercMstpSnonWnonDnon";
			HandGunOn = "AinvPercMstpSrasWpstDnon";
		};
		class RifleKneelActions_inv: RifleKneelLowActions
		{
			Stop = "AinvPknlMstpSrasWrflDnon";
			StopRelaxed = "AinvPknlMstpSrasWrflDnon";
			Default = "AinvPknlMstpSrasWrflDnon";
			PlayerCrouch = "AmovPknlMstpSrasWrflDnon";
			Civil = "AinvPknlMstpSnonWnonDnon";
			HandGunOn = "AinvPknlMstpSrasWpstDnon";
		};
		class RifleProneActions_inv: RifleProneActions
		{
			Stop = "AinvPpneMstpSrasWrflDnon";
			StopRelaxed = "AinvPpneMstpSrasWrflDnon";
			Default = "AinvPpneMstpSrasWrflDnon";
			PlayerProne = "AmovPpneMstpSrasWrflDnon";
			Civil = "AinvPpneMstpSnonWnonDnon";
			HandGunOn = "AinvPpneMstpSrasWpstDnon";
		};
		class PistolStandActions_inv: PistolStandActions
		{
			Stop = "AinvPercMstpSrasWpstDnon";
			StopRelaxed = "AinvPercMstpSrasWpstDnon";
			Default = "AinvPercMstpSrasWpstDnon";
			PlayerStand = "AmovPercMstpSrasWpstDnon";
			Civil = "AinvPercMstpSnonWnonDnon";
		};
		class PistolKneelActions_inv: PistolKneelActions
		{
			Stop = "AinvPknlMstpSrasWpstDnon";
			StopRelaxed = "AinvPknlMstpSrasWpstDnon";
			Default = "AinvPknlMstpSrasWpstDnon";
			Civil = "AinvPknlMstpSnonWnonDnon";
		};
		class PistolProneActions_inv: PistolProneActions
		{
			Stop = "AinvPpneMstpSrasWpstDnon";
			StopRelaxed = "AinvPpneMstpSrasWpstDnon";
			Default = "AinvPpneMstpSrasWpstDnon";
			PlayerProne = "AinvPpneMstpSnonWnonDnon";
			Civil = "AmovPknlMstpSnonWnonDnon_gear";
		};
		class CivilStandActions_inv: CivilStandActions
		{
			Stop = "AinvPercMstpSnonWnonDnon";
			StopRelaxed = "AinvPercMstpSnonWnonDnon";
			Default = "AinvPercMstpSnonWnonDnon";
			PlayerStand = "AmovPercMstpSnonWnonDnon";
			HandGunOn = "AinvPercMstpSrasWpstDnon";
		};
		class CivilKneelActions_inv: CivilKneelActions
		{
			Stop = "AinvPknlMstpSnonWnonDnon";
			StopRelaxed = "AinvPknlMstpSnonWnonDnon";
			Default = "AinvPknlMstpSnonWnonDnon";
			PlayerCrouch = "AmovPknlMstpSnonWnonDnon";
			HandGunOn = "AinvPknlMstpSrasWpstDnon";
		};
		class CivilProneActions_inv: CivilProneActions
		{
			Stop = "AinvPpneMstpSnonWnonDnon";
			StopRelaxed = "AinvPpneMstpSnonWnonDnon";
			Default = "AinvPpneMstpSnonWnonDnon";
			HandGunOn = "AinvPpneMstpSrasWpstDnon";
		};
		class LauncherStandActions_inv: LauncherStandActions
		{
			Stop = "AinvPercMstpSrasWlnrDnon";
			StopRelaxed = "AinvPercMstpSrasWlnrDnon";
			Default = "AinvPercMstpSrasWlnrDnon";
			PlayerStand = "AmovPercMstpSrasWlnrDnon";
			Civil = "AinvPercMstpSnonWnonDnon";
			HandGunOn = "AinvPercMstpSrasWpstDnon";
		};
		class LauncherKneelActions_inv: LauncherKneelActions
		{
			Stop = "AinvPknlMstpSrasWlnrDnon";
			StopRelaxed = "AinvPknlMstpSrasWlnrDnon";
			Default = "AinvPknlMstpSrasWlnrDnon";
			Civil = "AinvPknlMstpSnonWnonDnon";
			HandGunOn = "AinvPknlMstpSrasWpstDnon";
		};
		class Acts_SittingJumpingSaluting_actions: RifleBaseLowStandActions
		{
			Stop = "Acts_SittingJumpingSaluting_loop";
			StopRelaxed = "Acts_SittingJumpingSaluting_loop";
			Default = "Acts_SittingJumpingSaluting_loop";
			WeaponOn = "Acts_SittingJumpingSaluting_loop";
			WeaponOff = "Acts_SittingJumpingSaluting_loop";
			Stand = "Acts_SittingJumpingSaluting_loop";
			Combat = "Acts_SittingJumpingSaluting_loop";
		};
		class Acts_SittingJumpingSaluting2_actions: RifleLowStandActions
		{
			GetOver = "";
		};
		class Acts_NavigatingChopper_Actions: RifleLowStandActions
		{
			Stop = "Acts_NavigatingChopper_Loop";
			StopRelaxed = "Acts_NavigatingChopper_Loop";
			Default = "Acts_NavigatingChopper_Loop";
			Combat = "Acts_NavigatingChopper_Loop";
		};
		class Acts_TreatingWounded_actions: RifleLowStandActions
		{
			Stop = "Acts_TreatingWounded_loop";
			StopRelaxed = "Acts_TreatingWounded_loop";
			Default = "Acts_TreatingWounded_loop";
			Combat = "Acts_TreatingWounded_loop";
		};
		class Acts_LyingWounded_actions: RifleLowStandActions
		{
			Stop = "Acts_LyingWounded_loop";
			StopRelaxed = "Acts_LyingWounded_loop";
			Combat = "Acts_LyingWounded_loop";
			Default = "Acts_LyingWounded_loop";
		};
		class Acts_ShowingTheRightWay_actions: RifleLowStandActions
		{
			Stop = "Acts_ShowingTheRightWay_loop";
			StopRelaxed = "Acts_ShowingTheRightWay_loop";
			Default = "Acts_ShowingTheRightWay_loop";
			Combat = "Acts_ShowingTheRightWay_loop";
		};
		class Acts_CarFixingWheel_actions: RifleStandActions
		{
			Stop = "AmovPknlMstpSnonWnonDnon";
			StopRelaxed = "AmovPknlMstpSnonWnonDnon";
			Default = "Acts_carFixingWheel";
			PlayerStand = "";
			PrimaryWeapon = "AmovPknlMstpSlowWrflDnon";
		};
		class Acts_ShieldFromSun_actions: RifleLowStandActions
		{
			Stop = "Acts_ShieldFromSun_loop";
			StopRelaxed = "Acts_ShieldFromSun_loop";
			Combat = "Acts_ShieldFromSun_loop";
			Default = "Acts_ShieldFromSun_loop";
		};
		class Acts_listeningToRadio_actions: RifleLowStandActions
		{
			Stop = "Acts_listeningToRadio_Loop";
			StopRelaxed = "Acts_listeningToRadio_Loop";
			Combat = "Acts_listeningToRadio_Loop";
			Default = "Acts_listeningToRadio_Loop";
		};
		class Acts_UnconsciousStandUp_Actions: CivilStandActions
		{
			Stop = "Acts_UnconsciousStandUp_part1";
			StopRelaxed = "Acts_UnconsciousStandUp_part1";
			Combat = "Acts_UnconsciousStandUp_part1";
			Default = "Acts_UnconsciousStandUp_part1";
		};
		class Acts_SittingWounded_actions: RifleLowStandActions
		{
			Stop = "Acts_SittingWounded_loop";
			StopRelaxed = "Acts_SittingWounded_loop";
			Combat = "Acts_SittingWounded_loop";
			Default = "Acts_SittingWounded_loop";
		};
		class Acts_starterPistol_loop: PistolStandActions
		{
			Stop = "Acts_starterPistol_loop";
			StopRelaxed = "Acts_starterPistol_loop";
			Combat = "Acts_starterPistol_loop";
			Default = "Acts_starterPistol_loop";
		};
		class Acts_Helicargo_actions: RifleLowSitActions
		{
			Stop = "Acts_HeliCargo_loop";
			StopRelaxed = "Acts_HeliCargo_loop";
			Default = "Acts_HeliCargo_loop";
			Combat = "Acts_HeliCargo_loop";
		};
		class Acts_HelicargoTalking_actions: RifleLowSitActions
		{
			Stop = "Acts_HeliCargoTalking_loop";
			StopRelaxed = "Acts_HeliCargoTalking_loop";
			Default = "Acts_HeliCargoTalking_loop";
			Combat = "Acts_HeliCargoTalking_loop";
		};
		class Acts_Kore_IdleNoWeapon_actions: RifleLowStandActions
		{
			Stop = "Acts_Kore_IdleNoWeapon_loop";
			StopRelaxed = "Acts_Kore_IdleNoWeapon_loop";
			Combat = "Acts_Kore_IdleNoWeapon_loop";
			Default = "Acts_Kore_IdleNoWeapon_loop";
		};
		class Acts_Kore_TalkingOverRadio_actions: RifleLowStandActions
		{
			Stop = "Acts_Kore_TalkingOverRadio_loop";
			StopRelaxed = "Acts_Kore_TalkingOverRadio_loop";
			Combat = "Acts_Kore_TalkingOverRadio_loop";
			Default = "Acts_Kore_TalkingOverRadio_loop";
		};
		class Acts_SittingTiedHands_actions: CivilSitActions
		{
			Stop = "Acts_AidlPsitMstpSsurWnonDnon_loop";
			StopRelaxed = "Acts_AidlPsitMstpSsurWnonDnon_loop";
			Combat = "Acts_AidlPsitMstpSsurWnonDnon_loop";
			Default = "Acts_AidlPsitMstpSsurWnonDnon_loop";
			agonyStart = "";
			agonyStop = "";
			medicStop = "";
			medicStart = "";
			medicStartUp = "";
			grabCarry = "";
			grabCarried = "";
			grabDrag = "";
			grabDragged = "";
			carriedStill = "";
			TurnLRelaxed = "";
			TurnRRelaxed = "";
			ReloadMagazine = "";
			reloadGM6 = "";
			ReloadMGun = "";
			ReloadRPG = "";
			ReloadMortar = "";
			WalkF = "";
			WalkLF = "";
			WalkRF = "";
			WalkL = "";
			WalkR = "";
			WalkLB = "";
			WalkRB = "";
			WalkB = "";
			PlayerWalkF = "";
			PlayerWalkLF = "";
			PlayerWalkRF = "";
			PlayerWalkR = "";
			PlayerWalkL = "";
			PlayerWalkLB = "";
			PlayerWalkRB = "";
			PlayerWalkB = "";
			SlowF = "";
			SlowLF = "";
			SlowRF = "";
			SlowL = "";
			SlowR = "";
			SlowLB = "";
			SlowRB = "";
			SlowB = "";
			PlayerSlowF = "";
			PlayerSlowLF = "";
			PlayerSlowRF = "";
			PlayerSlowL = "";
			PlayerSlowR = "";
			PlayerSlowLB = "";
			PlayerSlowRB = "";
			PlayerSlowB = "";
			FastF = "";
			FastLF = "";
			FastRF = "";
			FastL = "";
			FastR = "";
			FastLB = "";
			FastRB = "";
			FastB = "";
			TactF = "";
			TactLF = "";
			TactRF = "";
			TactL = "";
			TactR = "";
			TactLB = "";
			TactB = "";
			TactRB = "";
			PlayerTactF = "";
			PlayerTactLF = "";
			PlayerTactRF = "";
			PlayerTactR = "";
			PlayerTactL = "";
			PlayerTactLB = "";
			PlayerTactRB = "";
			PlayerTactB = "";
			EvasiveLeft = "";
			EvasiveRight = "";
			startSwim = "";
			surfaceSwim = "";
			bottomSwim = "";
			startDive = "";
			SurfaceDive = "";
			BottomDive = "";
			Down = "";
			Up = "";
			PlayerCrouch = "";
			PlayerProne = "";
			Lying = "";
			Stand = "";
			Crouch = "";
			CanNotMove = "";
			Civil = "";
			CivilLying = "";
			FireNotPossible = "";
			WeaponOn = "";
			WeaponOff = "";
			StrokeGun = "";
			Salute = "";
			SitDown = "";
			saluteOff = "";
			Surrender = "";
			Gear = "";
			BinocOn = "";
			BinocOff = "";
			PutDown = "";
			Medic = "";
			Treated = "";
			LadderOnDown = "";
			LadderOnUp = "";
			GetInLow = "";
			GetInMedium = "";
			GetInVertical = "";
			GetInHigh = "";
			GetInSDV = "";
			GetInHelicopterCargo = "";
			GetInMRAP_01 = "";
			GetOutMRAP_01 = "";
			GetInMRAP_01_cargo = "";
			GetOutMRAP_01_cargo = "";
			GetOutHelicopterCargo = "";
			GetOutLow = "";
			GetOutMedium = "";
			GetOutHigh = "";
			GetOutHighZamak = "";
			GetOutHighHemtt = "";
			GetOutSDV = "";
			GetInBoat = "";
			GetOutBoat = "";
			TakeFlag = "";
			HandGunOn = "";
			TestDriver = "";
			TestDriverOut = "";
			TestGunner = "";
			Relax = "";
			StartFreefall = "";
			PrimaryWeapon = "";
			SecondaryWeapon = "";
			Binoculars = "";
		};
		class Acts_WarmUp_actions: RifleLowStandActions
		{
			Stop = "Acts_AidlPercMstpSlowWrflDnon_warmup_loop";
			Default = "Acts_AidlPercMstpSlowWrflDnon_warmup_loop";
			WalkF = "";
			WalkLF = "";
			WalkRF = "";
			WalkL = "";
			WalkR = "";
			WalkLB = "";
			WalkRB = "";
			WalkB = "";
			PlayerWalkF = "";
			PlayerWalkLF = "";
			PlayerWalkRF = "";
			PlayerWalkL = "";
			TurnL = "";
			TurnR = "";
			PlayerWalkR = "";
			PlayerWalkLB = "";
			PlayerWalkRB = "";
			PlayerWalkB = "";
			SlowF = "";
			SlowLF = "";
			SlowRF = "";
			SlowL = "";
			SlowR = "";
			SlowLB = "";
			SlowRB = "";
			SlowB = "";
			PlayerSlowF = "";
			PlayerSlowLF = "";
			PlayerSlowRF = "";
			PlayerSlowL = "";
			PlayerSlowR = "";
			PlayerSlowLB = "";
			PlayerSlowRB = "";
			PlayerSlowB = "";
			FastF = "";
			FastLF = "";
			FastRF = "";
			FastL = "";
			FastR = "";
			FastLB = "";
			FastRB = "";
			FastB = "";
			TactF = "";
			TactLF = "";
			TactRF = "";
			TactL = "";
			TactR = "";
			TactLB = "";
			TactRB = "";
			TactB = "";
			PlayerTactF = "";
			PlayerTactLF = "";
			PlayerTactRF = "";
			PlayerTactL = "";
			PlayerTactR = "";
			PlayerTactLB = "";
			PlayerTactRB = "";
			PlayerTactB = "";
			Down = "";
			Up = "";
			Stand = "";
			Combat = "";
			Gear = "";
			HandGunOn = "";
			PrimaryWeapon = "";
			SecondaryWeapon = "";
			Binoculars = "";
			GetOver = "";
			CivilLying = "";
			Civil = "";
			FireNotPossible = "";
			upDegree = "ManPosNoWeapon";
			PlayerCrouch = "";
			PlayerProne = "";
			SitDown = "";
			Salute = "";
			PutDown = "";
			BinocOn = "";
			BinocOff = "";
			Medic = "";
			MedicOther = "";
			Treated = "";
			LadderOnDown = "";
			LadderOnUp = "";
			Surrender = "";
			saluteOff = "";
			StrokeGun = "";
			WeaponOff = "";
			WeaponOn = "";
			CanNotMove = "";
			Crouch = "";
			Lying = "";
			startSwim = "";
			surfaceSwim = "";
			bottomSwim = "";
			startDive = "";
			SurfaceDive = "";
			BottomDive = "";
			TurnLRelaxed = "";
			TurnRRelaxed = "";
			dooraction = "";
			agonyStart = "";
			agonyStop = "";
			medicStop = "";
			medicStart = "";
			medicStartUp = "";
			medicStartRightSide = "";
			grabCarry = "";
			grabCarried = "";
			grabDrag = "";
			grabDragged = "";
			carriedStill = "";
			StopRelaxed = "";
			StartFreefall = "";
			Relax = "";
			healedStop = "";
			healedStart = "";
		};
		class FiringDrillsRifleStandActions: RifleStandActions
		{
			FDStart = "AmovPercMstpSrasWrflDnon";
			PlayerWalkF = "AfdsPercMstpSrasWrflDnon";
			PlayerWalkLF = "AfdsPercMstpSrasWrflDnon";
			PlayerWalkRF = "AfdsPercMstpSrasWrflDnon";
			PlayerWalkL = "AfdsPercMstpSrasWrflDnon";
			PlayerWalkR = "AfdsPercMstpSrasWrflDnon";
			PlayerWalkLB = "AfdsPercMstpSrasWrflDnon";
			PlayerWalkRB = "AfdsPercMstpSrasWrflDnon";
			PlayerWalkB = "AfdsPercMstpSrasWrflDnon";
			PlayerSlowF = "AfdsPercMstpSrasWrflDnon";
			PlayerSlowLF = "AfdsPercMstpSrasWrflDnon";
			PlayerSlowRF = "AfdsPercMstpSrasWrflDnon";
			PlayerSlowL = "AfdsPercMstpSrasWrflDnon";
			PlayerSlowR = "AfdsPercMstpSrasWrflDnon";
			PlayerSlowRB = "AfdsPercMstpSrasWrflDnon";
			PlayerSlowLB = "AfdsPercMstpSrasWrflDnon";
			PlayerSlowB = "AfdsPercMstpSrasWrflDnon";
			PlayerTactF = "AfdsPercMstpSrasWrflDnon";
			PlayerTactLF = "AfdsPercMstpSrasWrflDnon";
			PlayerTactRF = "AfdsPercMstpSrasWrflDnon";
			PlayerTactL = "AfdsPercMstpSrasWrflDnon";
			PlayerTactR = "AfdsPercMstpSrasWrflDnon";
			PlayerTactLB = "AfdsPercMstpSrasWrflDnon";
			PlayerTactRB = "AfdsPercMstpSrasWrflDnon";
			PlayerTactB = "AfdsPercMstpSrasWrflDnon";
			Default = "AfdsPercMstpSrasWrflDnon";
			PrimaryWeapon = "AfdsPercMstpSrasWrflDnon";
			Stand = "AfdsPercMstpSlowWrflDnon";
			Stop = "AfdsPercMstpSrasWrflDnon";
			Combat = "AfdsPercMstpSrasWrflDnon";
			HandGunOn = "AfdsPercMstpSrasWpstDnon";
			Up = "AfdsPknlMstpSrasWrflDnon";
			Down = "AfdsPpneMstpSrasWrflDnon";
			TurnL = "AfdsPercMstpSrasWrflDnon_turnL";
			TurnR = "AfdsPercMstpSrasWrflDnon_turnR";
			WalkF = "AfdsPercMstpSrasWrflDnon";
			WalkLF = "AfdsPercMstpSrasWrflDnon";
			WalkRF = "AfdsPercMstpSrasWrflDnon";
			WalkL = "AfdsPercMstpSrasWrflDnon";
			WalkR = "AfdsPercMstpSrasWrflDnon";
			WalkLB = "AfdsPercMstpSrasWrflDnon";
			WalkRB = "AfdsPercMstpSrasWrflDnon";
			WalkB = "AfdsPercMstpSrasWrflDnon";
			SlowF = "AfdsPercMstpSrasWrflDnon";
			SlowLF = "AfdsPercMstpSrasWrflDnon";
			SlowRF = "AfdsPercMstpSrasWrflDnon";
			SlowL = "AfdsPercMstpSrasWrflDnon";
			SlowR = "AfdsPercMstpSrasWrflDnon";
			SlowLB = "AfdsPercMstpSrasWrflDnon";
			SlowRB = "AfdsPercMstpSrasWrflDnon";
			SlowB = "AfdsPercMstpSrasWrflDnon";
			FastF = "AfdsPercMstpSrasWrflDnon";
			FastLF = "AfdsPercMstpSrasWrflDnon";
			FastRF = "AfdsPercMstpSrasWrflDnon";
			FastL = "AfdsPercMstpSrasWrflDnon";
			FastR = "AfdsPercMstpSrasWrflDnon";
			FastLB = "AfdsPercMstpSrasWrflDnon";
			FastRB = "AfdsPercMstpSrasWrflDnon";
			FastB = "AfdsPercMstpSrasWrflDnon";
			TactF = "AfdsPercMstpSrasWrflDnon";
			TactLF = "AfdsPercMstpSrasWrflDnon";
			TactRF = "AfdsPercMstpSrasWrflDnon";
			TactL = "AfdsPercMstpSrasWrflDnon";
			TactR = "AfdsPercMstpSrasWrflDnon";
			TactLB = "AfdsPercMstpSrasWrflDnon";
			TactRB = "AfdsPercMstpSrasWrflDnon";
			TactB = "AfdsPercMstpSrasWrflDnon";
			Lying = "AfdsPpneMstpSrasWrflDnon";
			Crouch = "AfdsPknlMstpSrasWrflDnon";
			Gear = "AfdsPercMstpSrasWrflDnon_inv";
			Civil = "AfdsPercMstpSnonWnonDnon";
			CivilLying = "AfdsPpneMstpSnonWnonDnon";
			EvasiveLeft = "AfdsPercMstpSrasWrflDnon";
			EvasiveRight = "AfdsPercMstpSrasWrflDnon";
			GetOver = "";
			Binoculars = "AfdsPercMstpSoptWbinDnon";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
			FireNotPossible = "AfdsPercMstpSrasWrflDnon";
		};
		class FiringDrillsRifleLowStandActions: FiringDrillsRifleStandActions
		{
			Stop = "AfdsPercMstpSlowWrflDnon";
			Default = "AfdsPercMstpSlowWrflDnon";
			Up = "AfdsPknlMstpSlowWrflDnon";
			FDStart = "AmovPercMstpSlowWrflDnon";
			Crouch = "AfdsPknlMstpSlowWrflDnon";
			Gear = "AfdsPercMstpSlowWrflDnon_inv";
			upDegree = "ManPosStand";
			Stand = "AfdsPercMstpSrasWrflDnon";
			WalkF = "AfdsPercMstpSlowWrflDnon";
			WalkLF = "AfdsPercMstpSlowWrflDnon";
			WalkRF = "AfdsPercMstpSlowWrflDnon";
			WalkL = "AfdsPercMstpSlowWrflDnon";
			WalkR = "AfdsPercMstpSlowWrflDnon";
			WalkLB = "AfdsPercMstpSlowWrflDnon";
			WalkRB = "AfdsPercMstpSlowWrflDnon";
			WalkB = "AfdsPercMstpSlowWrflDnon";
			PlayerWalkF = "AfdsPercMstpSlowWrflDnon";
			PlayerWalkLF = "AfdsPercMstpSlowWrflDnon";
			PlayerWalkRF = "AfdsPercMstpSlowWrflDnon";
			PlayerWalkL = "AfdsPercMstpSlowWrflDnon";
			PlayerWalkR = "AfdsPercMstpSlowWrflDnon";
			PlayerWalkLB = "AfdsPercMstpSlowWrflDnon";
			PlayerWalkRB = "AfdsPercMstpSlowWrflDnon";
			PlayerWalkB = "AfdsPercMstpSlowWrflDnon";
			SlowF = "AfdsPercMstpSlowWrflDnon";
			SlowLF = "AfdsPercMstpSlowWrflDnon";
			SlowRF = "AfdsPercMstpSlowWrflDnon";
			SlowL = "AfdsPercMstpSlowWrflDnon";
			SlowR = "AfdsPercMstpSlowWrflDnon";
			SlowLB = "AfdsPercMstpSlowWrflDnon";
			SlowRB = "AfdsPercMstpSlowWrflDnon";
			SlowB = "AfdsPercMstpSlowWrflDnon";
			PlayerSlowF = "AfdsPercMstpSlowWrflDnon";
			PlayerSlowLF = "AfdsPercMstpSlowWrflDnon";
			PlayerSlowRF = "AfdsPercMstpSlowWrflDnon";
			PlayerSlowL = "AfdsPercMstpSlowWrflDnon";
			PlayerSlowR = "AfdsPercMstpSlowWrflDnon";
			PlayerSlowLB = "AfdsPercMstpSlowWrflDnon";
			PlayerSlowRB = "AfdsPercMstpSlowWrflDnon";
			PlayerSlowB = "AfdsPercMstpSlowWrflDnon";
			FastF = "AfdsPercMstpSlowWrflDnon";
			FastLF = "AfdsPercMstpSlowWrflDnon";
			FastRF = "AfdsPercMstpSlowWrflDnon";
			FastL = "AfdsPercMstpSlowWrflDnon";
			FastR = "AfdsPercMstpSlowWrflDnon";
			FastLB = "AfdsPercMstpSlowWrflDnon";
			FastRB = "AfdsPercMstpSlowWrflDnon";
			FastB = "AfdsPercMstpSlowWrflDnon";
			TactF = "AfdsPercMstpSlowWrflDnon";
			TactLF = "AfdsPercMstpSlowWrflDnon";
			TactRF = "AfdsPercMstpSlowWrflDnon";
			TactL = "AfdsPercMstpSlowWrflDnon";
			TactR = "AfdsPercMstpSlowWrflDnon";
			TactLB = "AfdsPercMstpSlowWrflDnon";
			TactRB = "AfdsPercMstpSlowWrflDnon";
			TactB = "AfdsPercMstpSlowWrflDnon";
			PlayerTactF = "AfdsPercMstpSlowWrflDnon";
			PlayerTactLF = "AfdsPercMstpSlowWrflDnon";
			PlayerTactRF = "AfdsPercMstpSlowWrflDnon";
			PlayerTactL = "AfdsPercMstpSlowWrflDnon";
			PlayerTactR = "AfdsPercMstpSlowWrflDnon";
			PlayerTactLB = "AfdsPercMstpSlowWrflDnon";
			PlayerTactRB = "AfdsPercMstpSlowWrflDnon";
			PlayerTactB = "AfdsPercMstpSlowWrflDnon";
			EvasiveLeft = "AfdsPercMstpSlowWrflDnon";
			EvasiveRight = "AfdsPercMstpSlowWrflDnon";
			TurnL = "AfdsPercMstpSlowWrflDnon_turnL";
			TurnR = "AfdsPercMstpSlowWrflDnon_turnR";
		};
		class FiringDrillsRifleKneelActions: RifleKneelActions
		{
			GetOver = "";
			PlayerWalkF = "AfdsPknlMstpSrasWrflDnon";
			PlayerWalkLF = "AfdsPknlMstpSrasWrflDnon";
			PlayerWalkRF = "AfdsPknlMstpSrasWrflDnon";
			PlayerWalkL = "AfdsPknlMstpSrasWrflDnon";
			PlayerWalkR = "AfdsPknlMstpSrasWrflDnon";
			PlayerWalkLB = "AfdsPknlMstpSrasWrflDnon";
			PlayerWalkRB = "AfdsPknlMstpSrasWrflDnon";
			PlayerWalkB = "AfdsPknlMstpSrasWrflDnon";
			PlayerSlowF = "AfdsPknlMstpSrasWrflDnon";
			PlayerSlowLF = "AfdsPknlMstpSrasWrflDnon";
			PlayerSlowRF = "AfdsPknlMstpSrasWrflDnon";
			PlayerSlowL = "AfdsPknlMstpSrasWrflDnon";
			PlayerSlowR = "AfdsPknlMstpSrasWrflDnon";
			PlayerSlowLB = "AfdsPknlMstpSrasWrflDnon";
			PlayerSlowRB = "AfdsPknlMstpSrasWrflDnon";
			PlayerSlowB = "AfdsPknlMstpSrasWrflDnon";
			Stop = "AfdsPknlMstpSrasWrflDnon";
			Stand = "AfdsPknlMstpSlowWrflDnon";
			Combat = "AfdsPknlMstpSrasWrflDnon";
			FDStart = "AmovPknlMstpSrasWrflDnon";
			HandGunOn = "AfdsPknlMstpSrasWpstDnon";
			Up = "AfdsPercMstpSrasWrflDnon";
			Down = "AfdsPpneMstpSrasWrflDnon";
			Default = "AfdsPknlMstpSrasWrflDnon";
			TurnL = "AfdsPknlMstpSrasWrflDnon_turnL";
			TurnR = "AfdsPknlMstpSrasWrflDnon_turnR";
			WalkF = "AfdsPknlMstpSrasWrflDnon";
			WalkLF = "AfdsPknlMstpSrasWrflDnon";
			WalkRF = "AfdsPknlMstpSrasWrflDnon";
			WalkL = "AfdsPknlMstpSrasWrflDnon";
			WalkR = "AfdsPknlMstpSrasWrflDnon";
			WalkLB = "AfdsPknlMstpSrasWrflDnon";
			WalkRB = "AfdsPknlMstpSrasWrflDnon";
			WalkB = "AfdsPknlMstpSrasWrflDnon";
			SlowF = "AfdsPknlMstpSrasWrflDnon";
			SlowRF = "AfdsPknlMstpSrasWrflDnon";
			SlowLF = "AfdsPknlMstpSrasWrflDnon";
			SlowR = "AfdsPknlMstpSrasWrflDnon";
			SlowL = "AfdsPknlMstpSrasWrflDnon";
			SlowLB = "AfdsPknlMstpSrasWrflDnon";
			SlowRB = "AfdsPknlMstpSrasWrflDnon";
			SlowB = "AfdsPknlMstpSrasWrflDnon";
			FastF = "AfdsPknlMstpSrasWrflDnon";
			FastLF = "AfdsPknlMstpSrasWrflDnon";
			FastL = "AfdsPknlMstpSrasWrflDnon";
			FastRF = "AfdsPknlMstpSrasWrflDnon";
			FastR = "AfdsPknlMstpSrasWrflDnon";
			FastLB = "AfdsPknlMstpSrasWrflDnon";
			FastRB = "AfdsPknlMstpSrasWrflDnon";
			FastB = "AfdsPknlMstpSrasWrflDnon";
			TactF = "AfdsPknlMstpSrasWrflDnon";
			TactLF = "AfdsPknlMstpSrasWrflDnon";
			TactRF = "AfdsPknlMstpSrasWrflDnon";
			TactL = "AfdsPknlMstpSrasWrflDnon";
			TactR = "AfdsPknlMstpSrasWrflDnon";
			TactLB = "AfdsPknlMstpSrasWrflDnon";
			TactRB = "AfdsPknlMstpSrasWrflDnon";
			TactB = "AfdsPknlMstpSrasWrflDnon";
			PlayerTactF = "AfdsPknlMstpSrasWrflDnon";
			PlayerTactLF = "AfdsPknlMstpSrasWrflDnon";
			PlayerTactRF = "AfdsPknlMstpSrasWrflDnon";
			PlayerTactL = "AfdsPknlMstpSrasWrflDnon";
			PlayerTactR = "AfdsPknlMstpSrasWrflDnon";
			PlayerTactLB = "AfdsPknlMstpSrasWrflDnon";
			PlayerTactRB = "AfdsPknlMstpSrasWrflDnon";
			PlayerTactB = "AfdsPknlMstpSrasWrflDnon";
			PlayerStand = "AfdsPercMstpSrasWrflDnon";
			PlayerProne = "AfdsPpneMstpSrasWrflDnon";
			Lying = "AfdsPpneMstpSrasWrflDnon";
			Crouch = "AfdsPknlMstpSrasWrflDnon";
			EvasiveLeft = "AfdsPknlMstpSrasWrflDnon";
			EvasiveRight = "AfdsPknlMstpSrasWrflDnon";
			Civil = "AfdsPknlMstpSnonWnonDnon";
			CivilLying = "AfdsPpneMstpSnonWnonDnon";
			Gear = "AfdsPknlMstpSrasWrflDnon_inv";
			PrimaryWeapon = "AfdsPknlMstpSrasWrflDnon";
			Binoculars = "AfdsPknlMstpSoptWbinDnon";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
			FireNotPossible = "AfdsPknlMstpSrasWrflDnon";
		};
		class FiringDrillsRifleLowKneelActions: FiringDrillsRifleKneelActions
		{
			Stop = "AfdsPknlMstpSlowWrflDnon";
			Default = "AfdsPknlMstpSlowWrflDnon";
			Combat = "AfdsPknlMstpSrasWrflDnon";
			Up = "AfdsPercMstpSlowWrflDnon";
			PlayerStand = "AfdsPercMstpSlowWrflDnon";
			FDStart = "AmovPknlMstpSlowWrflDnon";
			TurnL = "AfdsPknlMstpSlowWrflDnon_turnL";
			TurnR = "AfdsPknlMstpSlowWrflDnon_turnR";
			Stand = "AfdsPknlMstpSrasWrflDnon";
			WalkF = "AfdsPknlMstpSlowWrflDnon";
			WalkLF = "AfdsPknlMstpSlowWrflDnon";
			WalkRF = "AfdsPknlMstpSlowWrflDnon";
			WalkL = "AfdsPknlMstpSlowWrflDnon";
			WalkR = "AfdsPknlMstpSlowWrflDnon";
			WalkLB = "AfdsPknlMstpSlowWrflDnon";
			WalkRB = "AfdsPknlMstpSlowWrflDnon";
			WalkB = "AfdsPknlMstpSlowWrflDnon";
			PlayerWalkF = "AfdsPknlMstpSlowWrflDnon";
			PlayerWalkLF = "AfdsPknlMstpSlowWrflDnon";
			PlayerWalkRF = "AfdsPknlMstpSlowWrflDnon";
			PlayerWalkL = "AfdsPknlMstpSlowWrflDnon";
			PlayerWalkR = "AfdsPknlMstpSlowWrflDnon";
			PlayerWalkLB = "AfdsPknlMstpSlowWrflDnon";
			PlayerWalkRB = "AfdsPknlMstpSlowWrflDnon";
			PlayerWalkB = "AfdsPknlMstpSlowWrflDnon";
			SlowF = "AfdsPknlMstpSlowWrflDnon";
			SlowLF = "AfdsPknlMstpSlowWrflDnon";
			SlowRF = "AfdsPknlMstpSlowWrflDnon";
			SlowL = "AfdsPknlMstpSlowWrflDnon";
			SlowR = "AfdsPknlMstpSlowWrflDnon";
			SlowLB = "AfdsPknlMstpSlowWrflDnon";
			SlowRB = "AfdsPknlMstpSlowWrflDnon";
			SlowB = "AfdsPknlMstpSlowWrflDnon";
			PlayerSlowF = "AfdsPknlMstpSlowWrflDnon";
			PlayerSlowLF = "AfdsPknlMstpSlowWrflDnon";
			PlayerSlowRF = "AfdsPknlMstpSlowWrflDnon";
			PlayerSlowL = "AfdsPknlMstpSlowWrflDnon";
			PlayerSlowR = "AfdsPknlMstpSlowWrflDnon";
			PlayerSlowLB = "AfdsPknlMstpSlowWrflDnon";
			PlayerSlowRB = "AfdsPknlMstpSlowWrflDnon";
			PlayerSlowB = "AfdsPknlMstpSlowWrflDnon";
			FastF = "AfdsPknlMstpSlowWrflDnon";
			FastLF = "AfdsPknlMstpSlowWrflDnon";
			FastRF = "AfdsPknlMstpSlowWrflDnon";
			FastL = "AfdsPknlMstpSlowWrflDnon";
			FastR = "AfdsPknlMstpSlowWrflDnon";
			FastLB = "AfdsPknlMstpSlowWrflDnon";
			FastRB = "AfdsPknlMstpSlowWrflDnon";
			FastB = "AfdsPknlMstpSlowWrflDnon";
			TactF = "AfdsPknlMstpSlowWrflDnon";
			TactLF = "AfdsPknlMstpSlowWrflDnon";
			TactRF = "AfdsPknlMstpSlowWrflDnon";
			TactL = "AfdsPknlMstpSlowWrflDnon";
			TactR = "AfdsPknlMstpSlowWrflDnon";
			TactLB = "AfdsPknlMstpSlowWrflDnon";
			TactRB = "AfdsPknlMstpSlowWrflDnon";
			TactB = "AfdsPknlMstpSlowWrflDnon";
			PlayerTactF = "AfdsPknlMstpSlowWrflDnon";
			PlayerTactLF = "AfdsPknlMstpSlowWrflDnon";
			PlayerTactRF = "AfdsPknlMstpSlowWrflDnon";
			PlayerTactL = "AfdsPknlMstpSlowWrflDnon";
			PlayerTactR = "AfdsPknlMstpSlowWrflDnon";
			PlayerTactLB = "AfdsPknlMstpSlowWrflDnon";
			PlayerTactRB = "AfdsPknlMstpSlowWrflDnon";
			PlayerTactB = "AfdsPknlMstpSlowWrflDnon";
			EvasiveLeft = "AfdsPknlMstpSlowWrflDnon";
			EvasiveRight = "AfdsPknlMstpSlowWrflDnon";
		};
		class FiringDrillsRifleProneActions: RifleProneActions
		{
			PlayerWalkF = "AfdsPpneMstpSrasWrflDnon";
			PlayerWalkLF = "AfdsPpneMstpSrasWrflDnon";
			PlayerWalkRF = "AfdsPpneMstpSrasWrflDnon";
			PlayerWalkL = "AfdsPpneMstpSrasWrflDnon";
			PlayerWalkR = "AfdsPpneMstpSrasWrflDnon";
			PlayerWalkLB = "AfdsPpneMstpSrasWrflDnon";
			PlayerWalkRB = "AfdsPpneMstpSrasWrflDnon";
			PlayerWalkB = "AfdsPpneMstpSrasWrflDnon";
			PlayerSlowF = "AfdsPpneMstpSrasWrflDnon";
			PlayerSlowLF = "AfdsPpneMstpSrasWrflDnon";
			PlayerSlowRF = "AfdsPpneMstpSrasWrflDnon";
			PlayerSlowL = "AfdsPpneMstpSrasWrflDnon";
			PlayerSlowR = "AfdsPpneMstpSrasWrflDnon";
			PlayerSlowLB = "AfdsPpneMstpSrasWrflDnon";
			PlayerSlowRB = "AfdsPpneMstpSrasWrflDnon";
			PlayerSlowB = "AfdsPpneMstpSrasWrflDnon";
			PlayerTactF = "AfdsPpneMstpSrasWrflDnon";
			PlayerTactLF = "AfdsPpneMstpSrasWrflDnon";
			PlayerTactRF = "AfdsPpneMstpSrasWrflDnon";
			PlayerTactL = "AfdsPpneMstpSrasWrflDnon";
			PlayerTactLB = "AfdsPpneMstpSrasWrflDnon";
			PlayerTactR = "AfdsPpneMstpSrasWrflDnon";
			PlayerTactRB = "AfdsPpneMstpSrasWrflDnon";
			PlayerTactB = "AfdsPpneMstpSrasWrflDnon";
			Stop = "AfdsPpneMstpSrasWrflDnon";
			Stand = "AfdsPercMstpSlowWrflDnon";
			Combat = "AfdsPercMstpSrasWrflDnon";
			TurnL = "AfdsPpneMstpSrasWrflDnon_turnL";
			TurnR = "AfdsPpneMstpSrasWrflDnon_turnR";
			FDStart = "AmovPpneMstpSrasWrflDnon";
			WalkF = "AfdsPpneMstpSrasWrflDnon";
			WalkLF = "AfdsPpneMstpSrasWrflDnon";
			WalkRF = "AfdsPpneMstpSrasWrflDnon";
			WalkL = "AfdsPpneMstpSrasWrflDnon";
			WalkR = "AfdsPpneMstpSrasWrflDnon";
			WalkLB = "AfdsPpneMstpSrasWrflDnon";
			WalkRB = "AfdsPpneMstpSrasWrflDnon";
			WalkB = "AfdsPpneMstpSrasWrflDnon";
			SlowLF = "AfdsPpneMstpSrasWrflDnon";
			SlowF = "AfdsPpneMstpSrasWrflDnon";
			SlowRF = "AfdsPpneMstpSrasWrflDnon";
			SlowL = "AfdsPpneMstpSrasWrflDnon";
			SlowR = "AfdsPpneMstpSrasWrflDnon";
			SlowLB = "AfdsPpneMstpSrasWrflDnon";
			SlowRB = "AfdsPpneMstpSrasWrflDnon";
			SlowB = "AfdsPpneMstpSrasWrflDnon";
			FastF = "AfdsPpneMstpSrasWrflDnon";
			FastLF = "AfdsPpneMstpSrasWrflDnon";
			FastRF = "AfdsPpneMstpSrasWrflDnon";
			FastL = "AfdsPpneMstpSrasWrflDnon";
			FastR = "AfdsPpneMstpSrasWrflDnon";
			FastLB = "AfdsPpneMstpSrasWrflDnon";
			FastRB = "AfdsPpneMstpSrasWrflDnon";
			FastB = "AfdsPpneMstpSrasWrflDnon";
			TactF = "AfdsPpneMstpSrasWrflDnon";
			TactLF = "AfdsPpneMstpSrasWrflDnon";
			TactRF = "AfdsPpneMstpSrasWrflDnon";
			TactL = "AfdsPpneMstpSrasWrflDnon";
			TactR = "AfdsPpneMstpSrasWrflDnon";
			TactLB = "AfdsPpneMstpSrasWrflDnon";
			TactRB = "AfdsPpneMstpSrasWrflDnon";
			TactB = "AfdsPpneMstpSrasWrflDnon";
			Up = "AfdsPknlMstpSrasWrflDnon";
			Down = "AfdsPercMstpSrasWrflDnon";
			PlayerStand = "AfdsPercMstpSrasWrflDnon";
			PlayerCrouch = "AfdsPknlMstpSrasWrflDnon";
			Crouch = "AfdsPknlMstpSrasWrflDnon";
			HandGunOn = "AfdsPpneMstpSrasWpstDnon";
			EvasiveLeft = "AfdsPpneMstpSrasWrflDnon";
			EvasiveRight = "AfdsPpneMstpSrasWrflDnon";
			Civil = "AfdsPercMstpSnonWnonDnon";
			CivilLying = "AfdsPpneMstpSnonWnonDnon";
			Default = "AfdsPpneMstpSrasWrflDnon";
			Lying = "AfdsPpneMstpSrasWrflDnon";
			PrimaryWeapon = "AfdsPpneMstpSrasWrflDnon";
			Gear = "AfdsPpneMstpSrasWrflDnon_inv";
			Binoculars = "AfdsPpneMstpSoptWbinDnon";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
			FireNotPossible = "AfdsPpneMstpSrasWrflDnon";
		};
		class FiringDrillsPistolStandActions: PistolStandActions
		{
			PrimaryWeapon = "AfdsPercMstpSrasWrflDnon";
			Default = "AfdsPercMstpSrasWpstDnon";
			Combat = "AfdsPercMstpSrasWrflDnon";
			Stand = "AfdsPercMstpSlowWpstDnon";
			Stop = "AfdsPercMstpSrasWpstDnon";
			Up = "AfdsPknlMstpSrasWpstDnon";
			Down = "AfdsPpneMstpSrasWpstDnon";
			FDStart = "AmovPercMstpSrasWpstDnon";
			TurnL = "AfdsPercMstpSrasWpstDnon_turnL";
			TurnR = "AfdsPercMstpSrasWpstDnon_turnR";
			HandGunOn = "AfdsPercMstpSrasWrflDnon";
			PlayerStand = "AfdsPercMstpSlowWpstDnon";
			PlayerCrouch = "AfdsPknlMstpSrasWpstDnon";
			PlayerProne = "AfdsPpneMstpSrasWpstDnon";
			Crouch = "AfdsPknlMstpSrasWpstDnon";
			GetOver = "";
			Civil = "AfdsPercMstpSnonWnonDnon";
			CivilLying = "AfdsPpneMstpSnonWnonDnon";
			Lying = "AfdsPpneMstpSrasWpstDnon";
			WalkF = "AfdsPercMstpSrasWpstDnon";
			WalkLF = "AfdsPercMstpSrasWpstDnon";
			WalkRF = "AfdsPercMstpSrasWpstDnon";
			WalkL = "AfdsPercMstpSrasWpstDnon";
			WalkR = "AfdsPercMstpSrasWpstDnon";
			WalkLB = "AfdsPercMstpSrasWpstDnon";
			WalkRB = "AfdsPercMstpSrasWpstDnon";
			WalkB = "AfdsPercMstpSrasWpstDnon";
			PlayerWalkF = "AfdsPercMstpSrasWpstDnon";
			PlayerWalkLF = "AfdsPercMstpSrasWpstDnon";
			PlayerWalkRF = "AfdsPercMstpSrasWpstDnon";
			PlayerWalkL = "AfdsPercMstpSrasWpstDnon";
			PlayerWalkR = "AfdsPercMstpSrasWpstDnon";
			PlayerWalkLB = "AfdsPercMstpSrasWpstDnon";
			PlayerWalkRB = "AfdsPercMstpSrasWpstDnon";
			PlayerWalkB = "AfdsPercMstpSrasWpstDnon";
			SlowF = "AfdsPercMstpSrasWpstDnon";
			SlowLF = "AfdsPercMstpSrasWpstDnon";
			SlowRF = "AfdsPercMstpSrasWpstDnon";
			SlowL = "AfdsPercMstpSrasWpstDnon";
			SlowR = "AfdsPercMstpSrasWpstDnon";
			SlowLB = "AfdsPercMstpSrasWpstDnon";
			SlowRB = "AfdsPercMstpSrasWpstDnon";
			SlowB = "AfdsPercMstpSrasWpstDnon";
			PlayerSlowF = "AfdsPercMstpSrasWpstDnon";
			PlayerSlowLF = "AfdsPercMstpSrasWpstDnon";
			PlayerSlowRF = "AfdsPercMstpSrasWpstDnon";
			PlayerSlowL = "AfdsPercMstpSrasWpstDnon";
			PlayerSlowR = "AfdsPercMstpSrasWpstDnon";
			PlayerSlowLB = "AfdsPercMstpSrasWpstDnon";
			PlayerSlowRB = "AfdsPercMstpSrasWpstDnon";
			PlayerSlowB = "AfdsPercMstpSrasWpstDnon";
			FastF = "AfdsPercMstpSrasWpstDnon";
			FastLF = "AfdsPercMstpSrasWpstDnon";
			FastRF = "AfdsPercMstpSrasWpstDnon";
			FastL = "AfdsPercMstpSrasWpstDnon";
			FastR = "AfdsPercMstpSrasWpstDnon";
			FastLB = "AfdsPercMstpSrasWpstDnon";
			FastRB = "AfdsPercMstpSrasWpstDnon";
			FastB = "AfdsPercMstpSrasWpstDnon";
			TactF = "AfdsPercMstpSrasWpstDnon";
			TactLF = "AfdsPercMstpSrasWpstDnon";
			TactRF = "AfdsPercMstpSrasWpstDnon";
			TactL = "AfdsPercMstpSrasWpstDnon";
			TactR = "AfdsPercMstpSrasWpstDnon";
			TactLB = "AfdsPercMstpSrasWpstDnon";
			TactRB = "AfdsPercMstpSrasWpstDnon";
			TactB = "AfdsPercMstpSrasWpstDnon";
			PlayerTactF = "AfdsPercMstpSrasWpstDnon";
			PlayerTactLF = "AfdsPercMstpSrasWpstDnon";
			PlayerTactRF = "AfdsPercMstpSrasWpstDnon";
			PlayerTactL = "AfdsPercMstpSrasWpstDnon";
			PlayerTactR = "AfdsPercMstpSrasWpstDnon";
			PlayerTactLB = "AfdsPercMstpSrasWpstDnon";
			PlayerTactRB = "AfdsPercMstpSrasWpstDnon";
			PlayerTactB = "AfdsPercMstpSrasWpstDnon";
			EvasiveLeft = "AfdsPercMstpSrasWpstDnon";
			EvasiveRight = "AfdsPercMstpSrasWpstDnon";
			Gear = "AfdsPercMstpSrasWpstDnon_inv";
			Binoculars = "AfdsPercMstpSoptWbinDnon";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
			FireNotPossible = "AfdsPercMstpSrasWpstDnon";
		};
		class FiringDrillsPistolLowStandActions: FiringDrillsPistolStandActions
		{
			Stop = "AfdsPercMstpSlowWpstDnon";
			Default = "AfdsPercMstpSlowWpstDnon";
			HandGunOn = "AfdsPercMstpSrasWpstDnon";
			FDStart = "AmovPercMstpSlowWpstDnon";
			Up = "AfdsPknlMstpSlowWpstDnon";
			TurnL = "AfdsPercMstpSlowWpstDnon_turnL";
			TurnR = "AfdsPercMstpSlowWpstDnon_turnR";
			Stand = "AfdsPercMstpSrasWpstDnon";
			WalkF = "AfdsPercMstpSlowWpstDnon";
			WalkLF = "AfdsPercMstpSlowWpstDnon";
			WalkRF = "AfdsPercMstpSlowWpstDnon";
			WalkL = "AfdsPercMstpSlowWpstDnon";
			WalkR = "AfdsPercMstpSlowWpstDnon";
			WalkLB = "AfdsPercMstpSlowWpstDnon";
			WalkRB = "AfdsPercMstpSlowWpstDnon";
			WalkB = "AfdsPercMstpSlowWpstDnon";
			PlayerWalkF = "AfdsPercMstpSlowWpstDnon";
			PlayerWalkLF = "AfdsPercMstpSlowWpstDnon";
			PlayerWalkRF = "AfdsPercMstpSlowWpstDnon";
			PlayerWalkL = "AfdsPercMstpSlowWpstDnon";
			PlayerWalkR = "AfdsPercMstpSlowWpstDnon";
			PlayerWalkLB = "AfdsPercMstpSlowWpstDnon";
			PlayerWalkRB = "AfdsPercMstpSlowWpstDnon";
			PlayerWalkB = "AfdsPercMstpSlowWpstDnon";
			SlowF = "AfdsPercMstpSlowWpstDnon";
			SlowLF = "AfdsPercMstpSlowWpstDnon";
			SlowRF = "AfdsPercMstpSlowWpstDnon";
			SlowL = "AfdsPercMstpSlowWpstDnon";
			SlowR = "AfdsPercMstpSlowWpstDnon";
			SlowLB = "AfdsPercMstpSlowWpstDnon";
			SlowRB = "AfdsPercMstpSlowWpstDnon";
			SlowB = "AfdsPercMstpSlowWpstDnon";
			PlayerSlowF = "AfdsPercMstpSlowWpstDnon";
			PlayerSlowLF = "AfdsPercMstpSlowWpstDnon";
			PlayerSlowRF = "AfdsPercMstpSlowWpstDnon";
			PlayerSlowL = "AfdsPercMstpSlowWpstDnon";
			PlayerSlowR = "AfdsPercMstpSlowWpstDnon";
			PlayerSlowLB = "AfdsPercMstpSlowWpstDnon";
			PlayerSlowRB = "AfdsPercMstpSlowWpstDnon";
			PlayerSlowB = "AfdsPercMstpSlowWpstDnon";
			FastF = "AfdsPercMstpSlowWpstDnon";
			FastLF = "AfdsPercMstpSlowWpstDnon";
			FastRF = "AfdsPercMstpSlowWpstDnon";
			FastL = "AfdsPercMstpSlowWpstDnon";
			FastR = "AfdsPercMstpSlowWpstDnon";
			FastLB = "AfdsPercMstpSlowWpstDnon";
			FastRB = "AfdsPercMstpSlowWpstDnon";
			FastB = "AfdsPercMstpSlowWpstDnon";
			TactF = "AfdsPercMstpSlowWpstDnon";
			TactLF = "AfdsPercMstpSlowWpstDnon";
			TactRF = "AfdsPercMstpSlowWpstDnon";
			TactL = "AfdsPercMstpSlowWpstDnon";
			TactR = "AfdsPercMstpSlowWpstDnon";
			TactLB = "AfdsPercMstpSlowWpstDnon";
			TactRB = "AfdsPercMstpSlowWpstDnon";
			TactB = "AfdsPercMstpSlowWpstDnon";
			PlayerTactF = "AfdsPercMstpSlowWpstDnon";
			PlayerTactLF = "AfdsPercMstpSlowWpstDnon";
			PlayerTactRF = "AfdsPercMstpSlowWpstDnon";
			PlayerTactL = "AfdsPercMstpSlowWpstDnon";
			PlayerTactR = "AfdsPercMstpSlowWpstDnon";
			PlayerTactLB = "AfdsPercMstpSlowWpstDnon";
			PlayerTactRB = "AfdsPercMstpSlowWpstDnon";
			PlayerTactB = "AfdsPercMstpSlowWpstDnon";
			EvasiveLeft = "AfdsPercMstpSlowWpstDnon";
			EvasiveRight = "AfdsPercMstpSlowWpstDnon";
		};
		class FiringDrillsPistolKneelActions: PistolKneelActions
		{
			Stop = "AfdsPknlMstpSrasWpstDnon";
			TurnL = "AfdsPknlMstpSrasWpstDnon_turnL";
			PlayerWalkF = "AfdsPknlMstpSrasWpstDnon";
			PlayerWalkLF = "AfdsPknlMstpSrasWpstDnon";
			PlayerWalkRF = "AfdsPknlMstpSrasWpstDnon";
			PlayerWalkL = "AfdsPknlMstpSrasWpstDnon";
			PlayerWalkR = "AfdsPknlMstpSrasWpstDnon";
			PlayerWalkLB = "AfdsPknlMstpSrasWpstDnon";
			PlayerWalkRB = "AfdsPknlMstpSrasWpstDnon";
			PlayerWalkB = "AfdsPknlMstpSrasWpstDnon";
			PlayerSlowF = "AfdsPknlMstpSrasWpstDnon";
			PlayerSlowLF = "AfdsPknlMstpSrasWpstDnon";
			PlayerSlowRF = "AfdsPknlMstpSrasWpstDnon";
			PlayerSlowL = "AfdsPknlMstpSrasWpstDnon";
			PlayerSlowR = "AfdsPknlMstpSrasWpstDnon";
			PlayerSlowLB = "AfdsPknlMstpSrasWpstDnon";
			PlayerSlowRB = "AfdsPknlMstpSrasWpstDnon";
			PlayerSlowB = "AfdsPknlMstpSrasWpstDnon";
			PlayerTactF = "AfdsPknlMstpSrasWpstDnon";
			PlayerTactLF = "AfdsPknlMstpSrasWpstDnon";
			PlayerTactRF = "AfdsPknlMstpSrasWpstDnon";
			PlayerTactL = "AfdsPknlMstpSrasWpstDnon";
			PlayerTactR = "AfdsPknlMstpSrasWpstDnon";
			PlayerTactLB = "AfdsPknlMstpSrasWpstDnon";
			PlayerTactRB = "AfdsPknlMstpSrasWpstDnon";
			PlayerTactB = "AfdsPknlMstpSrasWpstDnon";
			TurnR = "AfdsPknlMstpSrasWpstDnon_turnR";
			Down = "AfdsPpneMstpSrasWpstDnon";
			Up = "AfdsPercMstpSrasWpstDnon";
			Combat = "AfdsPknlMstpSrasWrflDnon";
			Default = "AfdsPknlMstpSrasWpstDnon";
			PrimaryWeapon = "AfdsPknlMstpSrasWrflDnon";
			Gear = "AfdsPknlMstpSrasWpstDnon_inv";
			FDStart = "AmovPknlMstpSrasWpstDnon";
			HandGunOn = "AfdsPknlMstpSrasWrflDnon";
			Stand = "AfdsPknlMstpSlowWpstDnon";
			WalkF = "AfdsPknlMstpSrasWpstDnon";
			WalkLF = "AfdsPknlMstpSrasWpstDnon";
			WalkRF = "AfdsPknlMstpSrasWpstDnon";
			WalkL = "AfdsPknlMstpSrasWpstDnon";
			WalkR = "AfdsPknlMstpSrasWpstDnon";
			WalkLB = "AfdsPknlMstpSrasWpstDnon";
			WalkRB = "AfdsPknlMstpSrasWpstDnon";
			WalkB = "AfdsPknlMstpSrasWpstDnon";
			SlowF = "AfdsPknlMstpSrasWpstDnon";
			SlowLF = "AfdsPknlMstpSrasWpstDnon";
			SlowRF = "AfdsPknlMstpSrasWpstDnon";
			SlowL = "AfdsPknlMstpSrasWpstDnon";
			SlowR = "AfdsPknlMstpSrasWpstDnon";
			SlowLB = "AfdsPknlMstpSrasWpstDnon";
			SlowRB = "AfdsPknlMstpSrasWpstDnon";
			SlowB = "AfdsPknlMstpSrasWpstDnon";
			FastF = "AfdsPknlMstpSrasWpstDnon";
			FastLF = "AfdsPknlMstpSrasWpstDnon";
			FastRF = "AfdsPknlMstpSrasWpstDnon";
			FastL = "AfdsPknlMstpSrasWpstDnon";
			FastR = "AfdsPknlMstpSrasWpstDnon";
			FastLB = "AfdsPknlMstpSrasWpstDnon";
			FastRB = "AfdsPknlMstpSrasWpstDnon";
			FastB = "AfdsPknlMstpSrasWpstDnon";
			TactF = "AfdsPknlMstpSrasWpstDnon";
			TactLF = "AfdsPknlMstpSrasWpstDnon";
			TactRF = "AfdsPknlMstpSrasWpstDnon";
			TactL = "AfdsPknlMstpSrasWpstDnon";
			TactR = "AfdsPknlMstpSrasWpstDnon";
			TactLB = "AfdsPknlMstpSrasWpstDnon";
			TactRB = "AfdsPknlMstpSrasWpstDnon";
			TactB = "AfdsPknlMstpSrasWpstDnon";
			PlayerStand = "AfdsPercMstpSrasWpstDnon";
			PlayerCrouch = "AfdsPknlMstpSrasWpstDnon";
			PlayerProne = "AfdsPpneMstpSrasWpstDnon";
			Crouch = "AfdsPknlMstpSrasWpstDnon";
			EvasiveLeft = "AfdsPknlMstpSrasWpstDnon";
			EvasiveRight = "AfdsPknlMstpSrasWpstDnon";
			Civil = "AfdsPknlMstpSnonWnonDnon";
			CivilLying = "AfdsPpneMstpSnonWnonDnon";
			Lying = "AfdsPpneMstpSrasWpstDnon";
			GetOver = "";
			Binoculars = "AfdsPknlMstpSoptWbinDnon";
			AdjustF = "";
			AdjustB = "";
			AdjustL = "";
			AdjustR = "";
			FireNotPossible = "AfdsPknlMstpSrasWpstDnon";
		};
		class FiringDrillsPistolLowKneelActions: FiringDrillsPistolKneelActions
		{
			Stop = "AfdsPknlMstpSlowWpstDnon";
			Up = "AfdsPercMstpSlowWpstDnon";
			FDStart = "AmovPknlMstpSlowWpstDnon";
			Default = "AfdsPknlMstpSlowWpstDnon";
			PlayerStand = "AfdsPercMstpSlowWpstDnon";
			HandGunOn = "AfdsPknlMstpSrasWpstDnon";
			TurnL = "AfdsPknlMstpSlowWpstDnon_turnL";
			TurnR = "AfdsPknlMstpSlowWpstDnon_turnR";
			Stand = "AfdsPknlMstpSrasWpstDnon";
			WalkF = "AfdsPknlMstpSlowWpstDnon";
			WalkLF = "AfdsPknlMstpSlowWpstDnon";
			WalkRF = "AfdsPknlMstpSlowWpstDnon";
			WalkL = "AfdsPknlMstpSlowWpstDnon";
			WalkR = "AfdsPknlMstpSlowWpstDnon";
			WalkLB = "AfdsPknlMstpSlowWpstDnon";
			WalkRB = "AfdsPknlMstpSlowWpstDnon";
			WalkB = "AfdsPknlMstpSlowWpstDnon";
			PlayerWalkF = "AfdsPknlMstpSlowWpstDnon";
			PlayerWalkLF = "AfdsPknlMstpSlowWpstDnon";
			PlayerWalkRF = "AfdsPknlMstpSlowWpstDnon";
			PlayerWalkL = "AfdsPknlMstpSlowWpstDnon";
			PlayerWalkR = "AfdsPknlMstpSlowWpstDnon";
			PlayerWalkLB = "AfdsPknlMstpSlowWpstDnon";
			PlayerWalkRB = "AfdsPknlMstpSlowWpstDnon";
			PlayerWalkB = "AfdsPknlMstpSlowWpstDnon";
			SlowF = "AfdsPknlMstpSlowWpstDnon";
			SlowLF = "AfdsPknlMstpSlowWpstDnon";
			SlowRF = "AfdsPknlMstpSlowWpstDnon";
			SlowL = "AfdsPknlMstpSlowWpstDnon";
			SlowR = "AfdsPknlMstpSlowWpstDnon";
			SlowLB = "AfdsPknlMstpSlowWpstDnon";
			SlowRB = "AfdsPknlMstpSlowWpstDnon";
			SlowB = "AfdsPknlMstpSlowWpstDnon";
			PlayerSlowF = "AfdsPknlMstpSlowWpstDnon";
			PlayerSlowLF = "AfdsPknlMstpSlowWpstDnon";
			PlayerSlowRF = "AfdsPknlMstpSlowWpstDnon";
			PlayerSlowL = "AfdsPknlMstpSlowWpstDnon";
			PlayerSlowR = "AfdsPknlMstpSlowWpstDnon";
			PlayerSlowLB = "AfdsPknlMstpSlowWpstDnon";
			PlayerSlowRB = "AfdsPknlMstpSlowWpstDnon";
			PlayerSlowB = "AfdsPknlMstpSlowWpstDnon";
			FastF = "AfdsPknlMstpSlowWpstDnon";
			FastLF = "AfdsPknlMstpSlowWpstDnon";
			FastRF = "AfdsPknlMstpSlowWpstDnon";
			FastL = "AfdsPknlMstpSlowWpstDnon";
			FastR = "AfdsPknlMstpSlowWpstDnon";
			FastLB = "AfdsPknlMstpSlowWpstDnon";
			FastRB = "AfdsPknlMstpSlowWpstDnon";
			FastB = "AfdsPknlMstpSlowWpstDnon";
			TactF = "AfdsPknlMstpSlowWpstDnon";
			TactLF = "AfdsPknlMstpSlowWpstDnon";
			TactRF = "AfdsPknlMstpSlowWpstDnon";
			TactL = "AfdsPknlMstpSlowWpstDnon";
			TactR = "AfdsPknlMstpSlowWpstDnon";
			TactLB = "AfdsPknlMstpSlowWpstDnon";
			TactRB = "AfdsPknlMstpSlowWpstDnon";
			TactB = "AfdsPknlMstpSlowWpstDnon";
			PlayerTactF = "AfdsPknlMstpSlowWpstDnon";
			PlayerTactLF = "AfdsPknlMstpSlowWpstDnon";
			PlayerTactRF = "AfdsPknlMstpSlowWpstDnon";
			PlayerTactL = "AfdsPknlMstpSlowWpstDnon";
			PlayerTactR = "AfdsPknlMstpSlowWpstDnon";
			PlayerTactLB = "AfdsPknlMstpSlowWpstDnon";
			PlayerTactRB = "AfdsPknlMstpSlowWpstDnon";
			PlayerTactB = "AfdsPknlMstpSlowWpstDnon";
			EvasiveLeft = "AfdsPknlMstpSlowWpstDnon";
			EvasiveRight = "AfdsPknlMstpSlowWpstDnon";
		};
		class FiringDrillsPistolProneActions: PistolProneActions
		{
			TurnL = "AfdsPpneMstpSrasWpstDnon_turnL";
			TurnR = "AfdsPpneMstpSrasWpstDnon_turnR";
			Stop = "AfdsPpneMstpSrasWpstDnon";
			WalkF = "AfdsPpneMstpSrasWpstDnon";
			WalkLF = "AfdsPpneMstpSrasWpstDnon";
			WalkRF = "AfdsPpneMstpSrasWpstDnon";
			WalkL = "AfdsPpneMstpSrasWpstDnon";
			WalkR = "AfdsPpneMstpSrasWpstDnon";
			WalkLB = "AfdsPpneMstpSrasWpstDnon";
			WalkRB = "AfdsPpneMstpSrasWpstDnon";
			WalkB = "AfdsPpneMstpSrasWpstDnon";
			PlayerWalkF = "AfdsPpneMstpSrasWpstDnon";
			PlayerWalkLF = "AfdsPpneMstpSrasWpstDnon";
			PlayerWalkRF = "AfdsPpneMstpSrasWpstDnon";
			PlayerWalkL = "AfdsPpneMstpSrasWpstDnon";
			PlayerWalkR = "AfdsPpneMstpSrasWpstDnon";
			PlayerWalkLB = "AfdsPpneMstpSrasWpstDnon";
			PlayerWalkRB = "AfdsPpneMstpSrasWpstDnon";
			PlayerWalkB = "AfdsPpneMstpSrasWpstDnon";
			SlowF = "AfdsPpneMstpSrasWpstDnon";
			SlowLF = "AfdsPpneMstpSrasWpstDnon";
			SlowL = "AfdsPpneMstpSrasWpstDnon";
			SlowRF = "AfdsPpneMstpSrasWpstDnon";
			SlowR = "AfdsPpneMstpSrasWpstDnon";
			SlowLB = "AfdsPpneMstpSrasWpstDnon";
			SlowRB = "AfdsPpneMstpSrasWpstDnon";
			SlowB = "AfdsPpneMstpSrasWpstDnon";
			PlayerSlowF = "AfdsPpneMstpSrasWpstDnon";
			PlayerSlowLF = "AfdsPpneMstpSrasWpstDnon";
			PlayerSlowRF = "AfdsPpneMstpSrasWpstDnon";
			PlayerSlowL = "AfdsPpneMstpSrasWpstDnon";
			PlayerSlowLB = "AfdsPpneMstpSrasWpstDnon";
			PlayerSlowR = "AfdsPpneMstpSrasWpstDnon";
			PlayerSlowRB = "AfdsPpneMstpSrasWpstDnon";
			PlayerSlowB = "AfdsPpneMstpSrasWpstDnon";
			FastF = "AfdsPpneMstpSrasWpstDnon";
			FastLF = "AfdsPpneMstpSrasWpstDnon";
			FastRF = "AfdsPpneMstpSrasWpstDnon";
			FastL = "AfdsPpneMstpSrasWpstDnon";
			FastR = "AfdsPpneMstpSrasWpstDnon";
			FastLB = "AfdsPpneMstpSrasWpstDnon";
			FastRB = "AfdsPpneMstpSrasWpstDnon";
			FastB = "AfdsPpneMstpSrasWpstDnon";
			TactF = "AfdsPpneMstpSrasWpstDnon";
			TactLF = "AfdsPpneMstpSrasWpstDnon";
			TactRF = "AfdsPpneMstpSrasWpstDnon";
			TactL = "AfdsPpneMstpSrasWpstDnon";
			TactR = "AfdsPpneMstpSrasWpstDnon";
			TactLB = "AfdsPpneMstpSrasWpstDnon";
			TactRB = "AfdsPpneMstpSrasWpstDnon";
			TactB = "AfdsPpneMstpSrasWpstDnon";
			PlayerTactF = "AfdsPpneMstpSrasWpstDnon";
			PlayerTactLF = "AfdsPpneMstpSrasWpstDnon";
			PlayerTactRF = "AfdsPpneMstpSrasWpstDnon";
			PlayerTactR = "AfdsPpneMstpSrasWpstDnon";
			PlayerTactL = "AfdsPpneMstpSrasWpstDnon";
			PlayerTactLB = "AfdsPpneMstpSrasWpstDnon";
			PlayerTactB = "AfdsPpneMstpSrasWpstDnon";
			PlayerTactRB = "AfdsPpneMstpSrasWpstDnon";
			Up = "AfdsPknlMstpSrasWpstDnon";
			Down = "AfdsPercMstpSrasWpstDnon";
			PlayerStand = "AfdsPercMstpSrasWpstDnon";
			PlayerCrouch = "AfdsPknlMstpSrasWpstDnon";
			PlayerProne = "AfdsPpneMstpSrasWpstDnon";
			Lying = "AfdsPpneMstpSrasWpstDnon";
			Combat = "AfdsPpneMstpSrasWrflDnon";
			Crouch = "AfdsPknlMstpSrasWpstDnon";
			Default = "AfdsPpneMstpSrasWpstDnon";
			HandGunOn = "AfdsPpneMstpSrasWrflDnon";
			PrimaryWeapon = "AfdsPpneMstpSrasWrflDnon";
			FDStart = "AmovPpneMstpSrasWpstDnon";
			EvasiveLeft = "AfdsPpneMstpSrasWpstDnon";
			EvasiveRight = "AfdsPpneMstpSrasWpstDnon";
			Civil = "AfdsPpneMstpSnonWnonDnon";
			CivilLying = "AfdsPpneMstpSnonWnonDnon";
			Stand = "AfdsPercMstpSlowWpstDnon";
			Binoculars = "AfdsPpneMstpSoptWbinDnon";
			FireNotPossible = "AfdsPpneMstpSrasWpstDnon";
		};
		class FiringDrillsCivilStandActions: CivilStandActions
		{
			Stop = "AfdsPercMstpSnonWnonDnon";
			TurnL = "AfdsPercMstpSnonWnonDnon_turnL";
			TurnR = "AfdsPercMstpSnonWnonDnon_turnR";
			WalkF = "AfdsPercMstpSnonWnonDnon";
			WalkLF = "AfdsPercMstpSnonWnonDnon";
			WalkRF = "AfdsPercMstpSnonWnonDnon";
			WalkL = "AfdsPercMstpSnonWnonDnon";
			WalkR = "AfdsPercMstpSnonWnonDnon";
			WalkLB = "AfdsPercMstpSnonWnonDnon";
			WalkRB = "AfdsPercMstpSnonWnonDnon";
			WalkB = "AfdsPercMstpSnonWnonDnon";
			PlayerWalkF = "AfdsPercMstpSnonWnonDnon";
			PlayerWalkLF = "AfdsPercMstpSnonWnonDnon";
			PlayerWalkRF = "AfdsPercMstpSnonWnonDnon";
			PlayerWalkL = "AfdsPercMstpSnonWnonDnon";
			PlayerWalkR = "AfdsPercMstpSnonWnonDnon";
			PlayerWalkLB = "AfdsPercMstpSnonWnonDnon";
			PlayerWalkRB = "AfdsPercMstpSnonWnonDnon";
			PlayerWalkB = "AfdsPercMstpSnonWnonDnon";
			SlowF = "AfdsPercMstpSnonWnonDnon";
			SlowLF = "AfdsPercMstpSnonWnonDnon";
			SlowRF = "AfdsPercMstpSnonWnonDnon";
			SlowL = "AfdsPercMstpSnonWnonDnon";
			SlowR = "AfdsPercMstpSnonWnonDnon";
			SlowLB = "AfdsPercMstpSnonWnonDnon";
			SlowRB = "AfdsPercMstpSnonWnonDnon";
			SlowB = "AfdsPercMstpSnonWnonDnon";
			PlayerSlowF = "AfdsPercMstpSnonWnonDnon";
			PlayerSlowLF = "AfdsPercMstpSnonWnonDnon";
			PlayerSlowRF = "AfdsPercMstpSnonWnonDnon";
			PlayerSlowL = "AfdsPercMstpSnonWnonDnon";
			PlayerSlowR = "AfdsPercMstpSnonWnonDnon";
			PlayerSlowLB = "AfdsPercMstpSnonWnonDnon";
			PlayerSlowRB = "AfdsPercMstpSnonWnonDnon";
			PlayerSlowB = "AfdsPercMstpSnonWnonDnon";
			FastF = "AfdsPercMstpSnonWnonDnon";
			FastLF = "AfdsPercMstpSnonWnonDnon";
			FastRF = "AfdsPercMstpSnonWnonDnon";
			FastL = "AfdsPercMstpSnonWnonDnon";
			FastR = "AfdsPercMstpSnonWnonDnon";
			FastLB = "AfdsPercMstpSnonWnonDnon";
			FastRB = "AfdsPercMstpSnonWnonDnon";
			FastB = "AfdsPercMstpSnonWnonDnon";
			TactF = "AfdsPercMstpSnonWnonDnon";
			TactLF = "AfdsPercMstpSnonWnonDnon";
			TactRF = "AfdsPercMstpSnonWnonDnon";
			TactL = "AfdsPercMstpSnonWnonDnon";
			TactR = "AfdsPercMstpSnonWnonDnon";
			TactLB = "AfdsPercMstpSnonWnonDnon";
			TactRB = "AfdsPercMstpSnonWnonDnon";
			TactB = "AfdsPercMstpSnonWnonDnon";
			PlayerTactF = "AfdsPercMstpSnonWnonDnon";
			PlayerTactLF = "AfdsPercMstpSnonWnonDnon";
			PlayerTactRF = "AfdsPercMstpSnonWnonDnon";
			PlayerTactL = "AfdsPercMstpSnonWnonDnon";
			PlayerTactR = "AfdsPercMstpSnonWnonDnon";
			PlayerTactLB = "AfdsPercMstpSnonWnonDnon";
			PlayerTactRB = "AfdsPercMstpSnonWnonDnon";
			PlayerTactB = "AfdsPercMstpSnonWnonDnon";
			EvasiveLeft = "AfdsPercMstpSnonWnonDnon";
			EvasiveRight = "AfdsPercMstpSnonWnonDnon";
			Stand = "AfdsPercMstpSnonWnonDnon";
			Up = "AfdsPknlMstpSnonWnonDnon";
			Down = "AfdsPpneMstpSnonWnonDnon";
			Combat = "AfdsPercMstpSrasWrflDnon";
			Crouch = "AfdsPknlMstpSnonWnonDnon";
			Civil = "AfdsPercMstpSnonWnonDnon";
			CivilLying = "AfdsPpneMstpSnonWnonDnon";
			GetOver = "";
			HandGunOn = "AfdsPercMstpSrasWpstDnon";
			PrimaryWeapon = "AfdsPercMstpSrasWrflDnon";
			FDStart = "AmovPercMstpSnonWnonDnon";
			Lying = "AfdsPpneMstpSnonWnonDnon";
			Binoculars = "AfdsPercMstpSoptWbinDnon";
		};
		class FiringDrillsCivilKneelActions: CivilKneelActions
		{
			Stop = "AfdsPknlMstpSnonWnonDnon";
			TurnL = "AfdsPknlMstpSnonWnonDnon_turnL";
			TurnR = "AfdsPknlMstpSnonWnonDnon_turnR";
			WalkF = "AfdsPknlMstpSnonWnonDnon";
			WalkLF = "AfdsPknlMstpSnonWnonDnon";
			WalkRF = "AfdsPknlMstpSnonWnonDnon";
			WalkL = "AfdsPknlMstpSnonWnonDnon";
			WalkR = "AfdsPknlMstpSnonWnonDnon";
			WalkLB = "AfdsPknlMstpSnonWnonDnon";
			WalkRB = "AfdsPknlMstpSnonWnonDnon";
			WalkB = "AfdsPknlMstpSnonWnonDnon";
			PlayerWalkF = "AfdsPknlMstpSnonWnonDnon";
			PlayerWalkLF = "AfdsPknlMstpSnonWnonDnon";
			PlayerWalkRF = "AfdsPknlMstpSnonWnonDnon";
			PlayerWalkL = "AfdsPknlMstpSnonWnonDnon";
			PlayerWalkR = "AfdsPknlMstpSnonWnonDnon";
			PlayerWalkLB = "AfdsPknlMstpSnonWnonDnon";
			PlayerWalkRB = "AfdsPknlMstpSnonWnonDnon";
			PlayerWalkB = "AfdsPknlMstpSnonWnonDnon";
			SlowF = "AfdsPknlMstpSnonWnonDnon";
			SlowLF = "AfdsPknlMstpSnonWnonDnon";
			SlowRF = "AfdsPknlMstpSnonWnonDnon";
			SlowL = "AfdsPknlMstpSnonWnonDnon";
			SlowR = "AfdsPknlMstpSnonWnonDnon";
			SlowLB = "AfdsPknlMstpSnonWnonDnon";
			SlowRB = "AfdsPknlMstpSnonWnonDnon";
			SlowB = "AfdsPknlMstpSnonWnonDnon";
			PlayerSlowF = "AfdsPknlMstpSnonWnonDnon";
			PlayerSlowLF = "AfdsPknlMstpSnonWnonDnon";
			PlayerSlowRF = "AfdsPknlMstpSnonWnonDnon";
			PlayerSlowL = "AfdsPknlMstpSnonWnonDnon";
			PlayerSlowR = "AfdsPknlMstpSnonWnonDnon";
			PlayerSlowLB = "AfdsPknlMstpSnonWnonDnon";
			PlayerSlowRB = "AfdsPknlMstpSnonWnonDnon";
			PlayerSlowB = "AfdsPknlMstpSnonWnonDnon";
			FastF = "AfdsPknlMstpSnonWnonDnon";
			FastLF = "AfdsPknlMstpSnonWnonDnon";
			FastRF = "AfdsPknlMstpSnonWnonDnon";
			FastL = "AfdsPknlMstpSnonWnonDnon";
			FastR = "AfdsPknlMstpSnonWnonDnon";
			FastLB = "AfdsPknlMstpSnonWnonDnon";
			FastRB = "AfdsPknlMstpSnonWnonDnon";
			FastB = "AfdsPknlMstpSnonWnonDnon";
			TactF = "AfdsPknlMstpSnonWnonDnon";
			TactLF = "AfdsPknlMstpSnonWnonDnon";
			TactRF = "AfdsPknlMstpSnonWnonDnon";
			TactL = "AfdsPknlMstpSnonWnonDnon";
			TactR = "AfdsPknlMstpSnonWnonDnon";
			TactLB = "AfdsPknlMstpSnonWnonDnon";
			TactRB = "AfdsPknlMstpSnonWnonDnon";
			TactB = "AfdsPknlMstpSnonWnonDnon";
			PlayerTactF = "AfdsPknlMstpSnonWnonDnon";
			PlayerTactLF = "AfdsPknlMstpSnonWnonDnon";
			PlayerTactRF = "AfdsPknlMstpSnonWnonDnon";
			PlayerTactL = "AfdsPknlMstpSnonWnonDnon";
			PlayerTactR = "AfdsPknlMstpSnonWnonDnon";
			PlayerTactLB = "AfdsPknlMstpSnonWnonDnon";
			PlayerTactRB = "AfdsPknlMstpSnonWnonDnon";
			PlayerTactB = "AfdsPknlMstpSnonWnonDnon";
			EvasiveLeft = "AfdsPknlMstpSnonWnonDnon";
			EvasiveRight = "AfdsPknlMstpSnonWnonDnon";
			Lying = "AfdsPpneMstpSnonWnonDnon";
			Stand = "AfdsPercMstpSlowWrflDnon";
			Combat = "AfdsPknlMstpSrasWrflDnon";
			Crouch = "AfdsPknlMstpSnonWnonDnon";
			Civil = "AfdsPercMstpSnonWnonDnon";
			CivilLying = "AfdsPpneMstpSnonWnonDnon";
			GetOver = "";
			PrimaryWeapon = "AfdsPknlMstpSrasWrflDnon";
			FDStart = "AmovPknlMstpSnonWnonDnon";
			Binoculars = "AfdsPknlMstpSoptWbinDnon";
		};
		class FiringDrillsCivilProneActions: CivilProneActions
		{
			Stop = "AfdsPpneMstpSnonWnonDnon";
			TurnL = "AfdsPpneMstpSnonWnonDnon_turnL";
			TurnR = "AfdsPpneMstpSnonWnonDnon_turnR";
			WalkF = "AfdsPpneMstpSnonWnonDnon";
			WalkLF = "AfdsPpneMstpSnonWnonDnon";
			WalkRF = "AfdsPpneMstpSnonWnonDnon";
			WalkL = "AfdsPpneMstpSnonWnonDnon";
			WalkR = "AfdsPpneMstpSnonWnonDnon";
			WalkLB = "AfdsPpneMstpSnonWnonDnon";
			WalkRB = "AfdsPpneMstpSnonWnonDnon";
			WalkB = "AfdsPpneMstpSnonWnonDnon";
			PlayerWalkF = "AfdsPpneMstpSnonWnonDnon";
			PlayerWalkLF = "AfdsPpneMstpSnonWnonDnon";
			PlayerWalkRF = "AfdsPpneMstpSnonWnonDnon";
			PlayerWalkL = "AfdsPpneMstpSnonWnonDnon";
			PlayerWalkR = "AfdsPpneMstpSnonWnonDnon";
			PlayerWalkLB = "AfdsPpneMstpSnonWnonDnon";
			PlayerWalkRB = "AfdsPpneMstpSnonWnonDnon";
			PlayerWalkB = "AfdsPpneMstpSnonWnonDnon";
			SlowF = "AfdsPpneMstpSnonWnonDnon";
			SlowLF = "AfdsPpneMstpSnonWnonDnon";
			SlowRF = "AfdsPpneMstpSnonWnonDnon";
			SlowL = "AfdsPpneMstpSnonWnonDnon";
			SlowR = "AfdsPpneMstpSnonWnonDnon";
			SlowLB = "AfdsPpneMstpSnonWnonDnon";
			SlowRB = "AfdsPpneMstpSnonWnonDnon";
			SlowB = "AfdsPpneMstpSnonWnonDnon";
			PlayerSlowF = "AfdsPpneMstpSnonWnonDnon";
			PlayerSlowLF = "AfdsPpneMstpSnonWnonDnon";
			PlayerSlowRF = "AfdsPpneMstpSnonWnonDnon";
			PlayerSlowL = "AfdsPpneMstpSnonWnonDnon";
			PlayerSlowR = "AfdsPpneMstpSnonWnonDnon";
			PlayerSlowLB = "AfdsPpneMstpSnonWnonDnon";
			PlayerSlowRB = "AfdsPpneMstpSnonWnonDnon";
			PlayerSlowB = "AfdsPpneMstpSnonWnonDnon";
			FastF = "AfdsPpneMstpSnonWnonDnon";
			FastLF = "AfdsPpneMstpSnonWnonDnon";
			FastRF = "AfdsPpneMstpSnonWnonDnon";
			FastL = "AfdsPpneMstpSnonWnonDnon";
			FastR = "AfdsPpneMstpSnonWnonDnon";
			FastLB = "AfdsPpneMstpSnonWnonDnon";
			FastRB = "AfdsPpneMstpSnonWnonDnon";
			FastB = "AfdsPpneMstpSnonWnonDnon";
			TactF = "AfdsPpneMstpSnonWnonDnon";
			TactLF = "AfdsPpneMstpSnonWnonDnon";
			TactRF = "AfdsPpneMstpSnonWnonDnon";
			TactL = "AfdsPpneMstpSnonWnonDnon";
			TactR = "AfdsPpneMstpSnonWnonDnon";
			TactLB = "AfdsPpneMstpSnonWnonDnon";
			TactRB = "AfdsPpneMstpSnonWnonDnon";
			TactB = "AfdsPpneMstpSnonWnonDnon";
			PlayerTactF = "AfdsPpneMstpSnonWnonDnon";
			PlayerTactLF = "AfdsPpneMstpSnonWnonDnon";
			PlayerTactRF = "AfdsPpneMstpSnonWnonDnon";
			PlayerTactL = "AfdsPpneMstpSnonWnonDnon";
			PlayerTactR = "AfdsPpneMstpSnonWnonDnon";
			PlayerTactLB = "AfdsPpneMstpSnonWnonDnon";
			PlayerTactRB = "AfdsPpneMstpSnonWnonDnon";
			PlayerTactB = "AfdsPpneMstpSnonWnonDnon";
			EvasiveLeft = "AfdsPpneMstpSnonWnonDnon";
			EvasiveRight = "AfdsPpneMstpSnonWnonDnon";
			Lying = "AfdsPpneMstpSrasWrflDnon";
			Stand = "AfdsPercMstpSnonWnonDnon";
			Combat = "AfdsPercMstpSrasWrflDnon";
			Crouch = "AfdsPpneMstpSnonWnonDnon";
			Civil = "AfdsPercMstpSnonWnonDnon";
			CivilLying = "AfdsPpneMstpSnonWnonDnon";
			PrimaryWeapon = "AfdsPpneMstpSrasWrflDnon";
			FDStart = "AmovPpneMstpSnonWnonDnon";
			Binoculars = "AfdsPpneMstpSoptWbinDnon";
		};
		class FiringDrillsBinocStandActions: BinocStandActions
		{
			Stop = "AfdsPercMstpSoptWbinDnon";
			TurnL = "AfdsPercMstpSoptWbinDnon_turnL";
			TurnR = "AfdsPercMstpSoptWbinDnon_turnR";
			WalkF = "AfdsPercMstpSoptWbinDnon";
			WalkLF = "AfdsPercMstpSoptWbinDnon";
			WalkRF = "AfdsPercMstpSoptWbinDnon";
			WalkL = "AfdsPercMstpSoptWbinDnon";
			WalkR = "AfdsPercMstpSoptWbinDnon";
			WalkLB = "AfdsPercMstpSoptWbinDnon";
			WalkRB = "AfdsPercMstpSoptWbinDnon";
			WalkB = "AfdsPercMstpSoptWbinDnon";
			PlayerWalkF = "AfdsPercMstpSoptWbinDnon";
			PlayerWalkLF = "AfdsPercMstpSoptWbinDnon";
			PlayerWalkRF = "AfdsPercMstpSoptWbinDnon";
			PlayerWalkL = "AfdsPercMstpSoptWbinDnon";
			PlayerWalkR = "AfdsPercMstpSoptWbinDnon";
			PlayerWalkLB = "AfdsPercMstpSoptWbinDnon";
			PlayerWalkRB = "AfdsPercMstpSoptWbinDnon";
			PlayerWalkB = "AfdsPercMstpSoptWbinDnon";
			SlowF = "AfdsPercMstpSoptWbinDnon";
			SlowLF = "AfdsPercMstpSoptWbinDnon";
			SlowRF = "AfdsPercMstpSoptWbinDnon";
			SlowL = "AfdsPercMstpSoptWbinDnon";
			SlowR = "AfdsPercMstpSoptWbinDnon";
			SlowLB = "AfdsPercMstpSoptWbinDnon";
			SlowRB = "AfdsPercMstpSoptWbinDnon";
			SlowB = "AfdsPercMstpSoptWbinDnon";
			PlayerSlowF = "AfdsPercMstpSoptWbinDnon";
			PlayerSlowLF = "AfdsPercMstpSoptWbinDnon";
			PlayerSlowRF = "AfdsPercMstpSoptWbinDnon";
			PlayerSlowL = "AfdsPercMstpSoptWbinDnon";
			PlayerSlowR = "AfdsPercMstpSoptWbinDnon";
			PlayerSlowLB = "AfdsPercMstpSoptWbinDnon";
			PlayerSlowRB = "AfdsPercMstpSoptWbinDnon";
			PlayerSlowB = "AfdsPercMstpSoptWbinDnon";
			FastF = "AfdsPercMstpSoptWbinDnon";
			FastLF = "AfdsPercMstpSoptWbinDnon";
			FastRF = "AfdsPercMstpSoptWbinDnon";
			FastL = "AfdsPercMstpSoptWbinDnon";
			FastR = "AfdsPercMstpSoptWbinDnon";
			FastLB = "AfdsPercMstpSoptWbinDnon";
			FastRB = "AfdsPercMstpSoptWbinDnon";
			FastB = "AfdsPercMstpSoptWbinDnon";
			TactF = "AfdsPercMstpSoptWbinDnon";
			TactLF = "AfdsPercMstpSoptWbinDnon";
			TactRF = "AfdsPercMstpSoptWbinDnon";
			TactL = "AfdsPercMstpSoptWbinDnon";
			TactR = "AfdsPercMstpSoptWbinDnon";
			TactLB = "AfdsPercMstpSoptWbinDnon";
			TactRB = "AfdsPercMstpSoptWbinDnon";
			TactB = "AfdsPercMstpSoptWbinDnon";
			PlayerTactF = "AfdsPercMstpSoptWbinDnon";
			PlayerTactLF = "AfdsPercMstpSoptWbinDnon";
			PlayerTactRF = "AfdsPercMstpSoptWbinDnon";
			PlayerTactL = "AfdsPercMstpSoptWbinDnon";
			PlayerTactR = "AfdsPercMstpSoptWbinDnon";
			PlayerTactLB = "AfdsPercMstpSoptWbinDnon";
			PlayerTactRB = "AfdsPercMstpSoptWbinDnon";
			PlayerTactB = "AfdsPercMstpSoptWbinDnon";
			EvasiveLeft = "AfdsPercMstpSoptWbinDnon";
			EvasiveRight = "AfdsPercMstpSoptWbinDnon";
			Down = "AfdsPpneMstpSoptWbinDnon";
			Up = "AfdsPknlMstpSoptWbinDnon";
			Stand = "AfdsPercMstpSlowWrflDnon";
			Combat = "AfdsPercMstpSrasWrflDnon";
			Crouch = "AfdsPknlMstpSrasWrflDnon";
			Civil = "AfdsPercMstpSnonWnonDnon";
			CivilLying = "AfdsPpneMstpSnonWnonDnon";
			Lying = "AfdsPpneMstpSrasWrflDnon";
			HandGunOn = "AfdsPercMstpSrasWpstDnon";
			PrimaryWeapon = "AfdsPercMstpSrasWrflDnon";
			Binoculars = "AfdsPercMstpSoptWbinDnon";
			FDStart = "AmovPercMstpSoptWbinDnon";
			Default = "AfdsPercMstpSoptWbinDnon";
		};
		class FiringDrillsBinocKneelActions: BinocKneelActions
		{
			Stop = "AfdsPknlMstpSoptWbinDnon";
			TurnL = "AfdsPknlMstpSoptWbinDnon_turnL";
			TurnR = "AfdsPknlMstpSoptWbinDnon_turnR";
			WalkF = "AfdsPknlMstpSoptWbinDnon";
			WalkLF = "AfdsPknlMstpSoptWbinDnon";
			WalkRF = "AfdsPknlMstpSoptWbinDnon";
			WalkL = "AfdsPknlMstpSoptWbinDnon";
			WalkR = "AfdsPknlMstpSoptWbinDnon";
			WalkLB = "AfdsPknlMstpSoptWbinDnon";
			WalkRB = "AfdsPknlMstpSoptWbinDnon";
			WalkB = "AfdsPknlMstpSoptWbinDnon";
			PlayerWalkF = "AfdsPknlMstpSoptWbinDnon";
			PlayerWalkLF = "AfdsPknlMstpSoptWbinDnon";
			PlayerWalkRF = "AfdsPknlMstpSoptWbinDnon";
			PlayerWalkL = "AfdsPknlMstpSoptWbinDnon";
			PlayerWalkR = "AfdsPknlMstpSoptWbinDnon";
			PlayerWalkLB = "AfdsPknlMstpSoptWbinDnon";
			PlayerWalkRB = "AfdsPknlMstpSoptWbinDnon";
			PlayerWalkB = "AfdsPknlMstpSoptWbinDnon";
			SlowF = "AfdsPknlMstpSoptWbinDnon";
			SlowLF = "AfdsPknlMstpSoptWbinDnon";
			SlowRF = "AfdsPknlMstpSoptWbinDnon";
			SlowL = "AfdsPknlMstpSoptWbinDnon";
			SlowR = "AfdsPknlMstpSoptWbinDnon";
			SlowLB = "AfdsPknlMstpSoptWbinDnon";
			SlowRB = "AfdsPknlMstpSoptWbinDnon";
			SlowB = "AfdsPknlMstpSoptWbinDnon";
			PlayerSlowF = "AfdsPknlMstpSoptWbinDnon";
			PlayerSlowLF = "AfdsPknlMstpSoptWbinDnon";
			PlayerSlowRF = "AfdsPknlMstpSoptWbinDnon";
			PlayerSlowL = "AfdsPknlMstpSoptWbinDnon";
			PlayerSlowR = "AfdsPknlMstpSoptWbinDnon";
			PlayerSlowLB = "AfdsPknlMstpSoptWbinDnon";
			PlayerSlowRB = "AfdsPknlMstpSoptWbinDnon";
			PlayerSlowB = "AfdsPknlMstpSoptWbinDnon";
			FastF = "AfdsPknlMstpSoptWbinDnon";
			FastLF = "AfdsPknlMstpSoptWbinDnon";
			FastRF = "AfdsPknlMstpSoptWbinDnon";
			FastL = "AfdsPknlMstpSoptWbinDnon";
			FastR = "AfdsPknlMstpSoptWbinDnon";
			FastLB = "AfdsPknlMstpSoptWbinDnon";
			FastRB = "AfdsPknlMstpSoptWbinDnon";
			FastB = "AfdsPknlMstpSoptWbinDnon";
			TactF = "AfdsPknlMstpSoptWbinDnon";
			TactLF = "AfdsPknlMstpSoptWbinDnon";
			TactRF = "AfdsPknlMstpSoptWbinDnon";
			TactL = "AfdsPknlMstpSoptWbinDnon";
			TactR = "AfdsPknlMstpSoptWbinDnon";
			TactLB = "AfdsPknlMstpSoptWbinDnon";
			TactRB = "AfdsPknlMstpSoptWbinDnon";
			TactB = "AfdsPknlMstpSoptWbinDnon";
			PlayerTactF = "AfdsPknlMstpSoptWbinDnon";
			PlayerTactLF = "AfdsPknlMstpSoptWbinDnon";
			PlayerTactRF = "AfdsPknlMstpSoptWbinDnon";
			PlayerTactL = "AfdsPknlMstpSoptWbinDnon";
			PlayerTactR = "AfdsPknlMstpSoptWbinDnon";
			PlayerTactLB = "AfdsPknlMstpSoptWbinDnon";
			PlayerTactRB = "AfdsPknlMstpSoptWbinDnon";
			PlayerTactB = "AfdsPknlMstpSoptWbinDnon";
			EvasiveLeft = "AfdsPknlMstpSoptWbinDnon";
			EvasiveRight = "AfdsPknlMstpSoptWbinDnon";
			Down = "AfdsPpneMstpSoptWbinDnon";
			Up = "AfdsPercMstpSoptWbinDnon";
			Lying = "AfdsPpneMstpSrasWrflDnon";
			Stand = "AfdsPknlMstpSlowWrflDnon";
			Combat = "AfdsPercMstpSrasWrflDnon";
			Crouch = "AfdsPknlMstpSrasWrflDnon";
			Civil = "AfdsPercMstpSnonWnonDnon";
			CivilLying = "AfdsPpneMstpSnonWnonDnon";
			GetOver = "";
			FDStart = "AmovPknlMstpSoptWbinDnon";
			Binoculars = "AfdsPknlMstpSoptWbinDnon";
			PrimaryWeapon = "AfdsPknlMstpSrasWrflDnon";
			Default = "AfdsPknlMstpSoptWbinDnon";
		};
		class FiringDrillsBinocProneActions: BinocProneActions
		{
			Stop = "AfdsPpneMstpSoptWbinDnon";
			TurnL = "AfdsPpneMstpSoptWbinDnon_turnL";
			TurnR = "AfdsPpneMstpSoptWbinDnon_turnR";
			WalkF = "AfdsPpneMstpSoptWbinDnon";
			WalkLF = "AfdsPpneMstpSoptWbinDnon";
			WalkRF = "AfdsPpneMstpSoptWbinDnon";
			WalkL = "AfdsPpneMstpSoptWbinDnon";
			WalkR = "AfdsPpneMstpSoptWbinDnon";
			WalkLB = "AfdsPpneMstpSoptWbinDnon";
			WalkRB = "AfdsPpneMstpSoptWbinDnon";
			WalkB = "AfdsPpneMstpSoptWbinDnon";
			PlayerWalkF = "AfdsPpneMstpSoptWbinDnon";
			PlayerWalkLF = "AfdsPpneMstpSoptWbinDnon";
			PlayerWalkRF = "AfdsPpneMstpSoptWbinDnon";
			PlayerWalkL = "AfdsPpneMstpSoptWbinDnon";
			PlayerWalkR = "AfdsPpneMstpSoptWbinDnon";
			PlayerWalkLB = "AfdsPpneMstpSoptWbinDnon";
			PlayerWalkRB = "AfdsPpneMstpSoptWbinDnon";
			PlayerWalkB = "AfdsPpneMstpSoptWbinDnon";
			SlowF = "AfdsPpneMstpSoptWbinDnon";
			SlowLF = "AfdsPpneMstpSoptWbinDnon";
			SlowRF = "AfdsPpneMstpSoptWbinDnon";
			SlowL = "AfdsPpneMstpSoptWbinDnon";
			SlowR = "AfdsPpneMstpSoptWbinDnon";
			SlowLB = "AfdsPpneMstpSoptWbinDnon";
			SlowRB = "AfdsPpneMstpSoptWbinDnon";
			SlowB = "AfdsPpneMstpSoptWbinDnon";
			PlayerSlowF = "AfdsPpneMstpSoptWbinDnon";
			PlayerSlowLF = "AfdsPpneMstpSoptWbinDnon";
			PlayerSlowRF = "AfdsPpneMstpSoptWbinDnon";
			PlayerSlowL = "AfdsPpneMstpSoptWbinDnon";
			PlayerSlowR = "AfdsPpneMstpSoptWbinDnon";
			PlayerSlowLB = "AfdsPpneMstpSoptWbinDnon";
			PlayerSlowRB = "AfdsPpneMstpSoptWbinDnon";
			PlayerSlowB = "AfdsPpneMstpSoptWbinDnon";
			FastF = "AfdsPpneMstpSoptWbinDnon";
			FastLF = "AfdsPpneMstpSoptWbinDnon";
			FastRF = "AfdsPpneMstpSoptWbinDnon";
			FastL = "AfdsPpneMstpSoptWbinDnon";
			FastR = "AfdsPpneMstpSoptWbinDnon";
			FastLB = "AfdsPpneMstpSoptWbinDnon";
			FastRB = "AfdsPpneMstpSoptWbinDnon";
			FastB = "AfdsPpneMstpSoptWbinDnon";
			TactF = "AfdsPpneMstpSoptWbinDnon";
			TactLF = "AfdsPpneMstpSoptWbinDnon";
			TactRF = "AfdsPpneMstpSoptWbinDnon";
			TactL = "AfdsPpneMstpSoptWbinDnon";
			TactR = "AfdsPpneMstpSoptWbinDnon";
			TactLB = "AfdsPpneMstpSoptWbinDnon";
			TactRB = "AfdsPpneMstpSoptWbinDnon";
			TactB = "AfdsPpneMstpSoptWbinDnon";
			PlayerTactF = "AfdsPpneMstpSoptWbinDnon";
			PlayerTactLF = "AfdsPpneMstpSoptWbinDnon";
			PlayerTactRF = "AfdsPpneMstpSoptWbinDnon";
			PlayerTactL = "AfdsPpneMstpSoptWbinDnon";
			PlayerTactR = "AfdsPpneMstpSoptWbinDnon";
			PlayerTactLB = "AfdsPpneMstpSoptWbinDnon";
			PlayerTactRB = "AfdsPpneMstpSoptWbinDnon";
			PlayerTactB = "AfdsPpneMstpSoptWbinDnon";
			EvasiveLeft = "AfdsPpneMstpSoptWbinDnon";
			EvasiveRight = "AfdsPpneMstpSoptWbinDnon";
			Down = "AfdsPercMstpSoptWbinDnon";
			Up = "AfdsPknlMstpSoptWbinDnon";
			Lying = "AfdsPpneMstpSrasWrflDnon";
			Stand = "AfdsPercMstpSlowWrflDnon";
			Combat = "AfdsPercMstpSrasWrflDnon";
			Crouch = "AfdsPknlMstpSrasWrflDnon";
			Civil = "AfdsPercMstpSnonWnonDnon";
			CivilLying = "AfdsPpneMstpSnonWnonDnon";
			Default = "AfdsPpneMstpSoptWbinDnon";
			FDStart = "AmovPpneMstpSoptWbinDnon";
			PrimaryWeapon = "AfdsPpneMstpSrasWrflDnon";
			Binoculars = "AfdsPpneMstpSoptWbinDnon";
			Gear = "AfdsPpneMstpSrasWrflDnon_inv";
		};
		class FiringDrillsRifleStandActions_inv: FiringDrillsRifleStandActions
		{
			Stop = "AfdsPercMstpSrasWrflDnon_inv";
			Default = "AfdsPercMstpSrasWrflDnon_inv";
			HandGunOn = "AfdsPercMstpSrasWpstDnon_inv";
			PlayerStand = "AfdsPercMstpSrasWrflDnon";
		};
		class FiringDrillsRifleLowStandActions_inv: FiringDrillsRifleLowStandActions
		{
			Stop = "AfdsPercMstpSlowWrflDnon_inv";
			Default = "AfdsPercMstpSlowWrflDnon_inv";
			PlayerStand = "AfdsPercMstpSlowWrflDnon";
			HandGunOn = "AfdsPercMstpSrasWpstDnon_inv";
		};
		class FiringDrillsRifleKneelActions_inv: FiringDrillsRifleKneelActions
		{
			Stop = "AfdsPknlMstpSrasWrflDnon_inv";
			Default = "AfdsPknlMstpSrasWrflDnon_inv";
		};
		class FiringDrillsRifleLowKneelActions_inv: FiringDrillsRifleLowKneelActions
		{
			Stop = "AfdsPknlMstpSlowWrflDnon_inv";
			Default = "AfdsPknlMstpSlowWrflDnon_inv";
		};
		class FiringDrillsRifleProneActions_inv: FiringDrillsRifleProneActions
		{
			Stop = "AfdsPpneMstpSrasWrflDnon_inv";
			Default = "AfdsPpneMstpSrasWrflDnon_inv";
		};
		class FiringDrillsPistolStandActions_inv: FiringDrillsPistolStandActions
		{
			Stop = "AfdsPercMstpSrasWpstDnon_inv";
			PlayerStand = "AfdsPercMstpSrasWpstDnon";
			Default = "AfdsPercMstpSrasWpstDnon_inv";
		};
		class FiringDrillsPistolLowStandActions_inv: FiringDrillsPistolStandActions
		{
			Stop = "AfdsPercMstpSrasWpstDnon_inv";
			Default = "AfdsPercMstpSrasWpstDnon_inv";
		};
		class FiringDrillsPistolKneelActions_inv: FiringDrillsPistolKneelActions
		{
			Stop = "AfdsPknlMstpSrasWpstDnon_inv";
			Stand = "AfdsPknlMstpSlowWpstDnon_inv";
			Default = "AfdsPknlMstpSrasWpstDnon_inv";
		};
		class FiringDrillsPistolLowKneelActions_inv: FiringDrillsPistolLowKneelActions
		{
			Stop = "AfdsPknlMstpSlowWpstDnon_inv";
			Stand = "AfdsPknlMstpSlowWpstDnon_inv";
			Default = "AfdsPknlMstpSlowWpstDnon_inv";
		};
		class FiringDrillsPistolProneActions_inv: FiringDrillsPistolProneActions
		{
			Stop = "AfdsPpneMstpSrasWpstDnon_inv";
			Default = "AfdsPpneMstpSrasWpstDnon_inv";
		};
		class FiringDrillsCivilStandActions_inv: FiringDrillsCivilStandActions
		{
			Stop = "AfdsPercMstpSnonWnonDnon_inv";
			Default = "AfdsPercMstpSnonWnonDnon_inv";
		};
		class FiringDrillsCivilKneelActions_inv: FiringDrillsCivilKneelActions{};
		class FiringDrillsCivilProneActions_inv: FiringDrillsCivilProneActions{};
		class DeployedProneActions: RifleProneActions
		{
			GestureReloadM200[] = {"RifleReloadDeployedM200","Gesture"};
			GestureReloadMk20[] = {"RifleReloadDeployedMk20","Gesture"};
			GestureReloadMk20UGL[] = {"RifleReloadDeployedMk20UGL","Gesture"};
			GestureReloadMXUGL[] = {"RifleReloadDeployedMXUGL","Gesture"};
			GestureReloadMX[] = {"RifleReloadDeployedMX","Gesture"};
			GestureReloadMXCompact[] = {"RifleReloadDeployedMXCompact","Gesture"};
			GestureReloadMXSniper[] = {"RifleReloadDeployedMXSniper","Gesture"};
			GestureReloadTRG[] = {"RifleReloadDeployedTRG","Gesture"};
			GestureReloadKatiba[] = {"RifleReloadDeployedKatiba","Gesture"};
			GestureReloadKatibaUGL[] = {"RifleReloadDeployedKatibaUGL","Gesture"};
			GestureReloadTRGUGL[] = {"RifleReloadDeployedTRGUGL","Gesture"};
			GestureReloadLRR[] = {"RifleReloadDeployedLRR","Gesture"};
			GestureReloadEBR[] = {"RifleReloadDeployedEBR","Gesture"};
			GestureReloadSMG_03[] = {"RifleReloadDeployedSMG_03","Gesture"};
			GestureReloadSMG_02[] = {"RifleReloadDeployedSMG_02","Gesture"};
			GestureReloadSMG_01[] = {"RifleReloadDeployedSMG_01","Gesture"};
			GestureReloadSDAR[] = {"RifleReloadDeployedSDAR","Gesture"};
			GestureReloadDMR[] = {"RifleReloadDeployedDMR","Gesture"};
			GestureReloadDMR02[] = {"RifleReloadDeployedDMR02","Gesture"};
			GestureReloadDMR03[] = {"RifleReloadDeployedDMR03","Gesture"};
			GestureReloadDMR04[] = {"RifleReloadDeployedDMR04","Gesture"};
			GestureReloadDMR05[] = {"RifleReloadDeployedDMR05","Gesture"};
			GestureReloadDMR06[] = {"RifleReloadDeployedDMR06","Gesture"};
			GestureReloadMMG01[] = {"RifleReloadDeployedMMG01","Gesture"};
			GestureReloadMMG02[] = {"RifleReloadDeployedMMG02","Gesture"};
			GestureReloadM4SSAS[] = {"RifleReloadDeployedM4SSAS","Gesture"};
			ReloadGM6[] = {"RifleReloadDeployedGM6","Gesture"};
		};
		class MortarActions: CivilStandActions
		{
			Gear = "";
		};
	};
	primaryActionMaps[] = {"RifleProneActions_injured","DeadActions","LauncherKneelActions","BinocProneRflActions","BinocProneCivilActions","RifleProneActions","PistolProneActions","RifleKneelActions","PistolKneelActions","RifleStandActions","PistolStandActions","RifleLowStandActions","SwimmingActions","CivilStandActions","BinocKneelRflActions","BinocStandRflActions"};
	class Interpolations{};
	transitionsInterpolated[] = {};
	transitionsSimple[] = {};
	transitionsDisabled[] = {};
	class BlendAnims
	{
		aimingDefault[] = {};
		aimingKneelUnarmedDefault = "";
		legsDefault[] = {};
		headDefault[] = {};
		aimingNo[] = {};
		legsNo[] = {};
		headNo[] = {};
		aimingUpDefault[] = {};
		empty[] = {};
	};
	class AgonyBase: Default
	{
		disableWeaponsLong = 1;
		actions = "InjuredManActions";
		headBobMode = 2;
		headBobStrength = -1;
		collisionShape = "A3\anims_f\Data\Geom\Sdr\geom_Adth.p3d";
		collisionShapeSafe = "A3\anims_f\Data\Geom\Sdr\geom_Adth.p3d";
	};
	class AgonyBaseRfl: AgonyBase
	{
		actions = "InjuredManActionsRfl";
	};
	class InjuredMovedBase: Default
	{
		actions = "InjuredManCarriedActions";
		speed = 1;
		visibleSize = 0.600122;
		headBobMode = 1;
		headBobStrength = -1;
	};
};
