/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Custom paricle effects

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_config/Configs/CfgCloudlets.hpp
*/

class CfgCloudlets
{
	class Default;

	class SpikeCraterEffect: Default
	{
		interval = 0.001;
    circleRadius = 0;
    circleVelocity[] = {0,0,0};
    particleShape = "\x\addons\a3_epoch_assets_3\CfgVehicles\Defense\spike.p3d";
    particleFSNtieth = 0;
    particleFSIndex = 1;
    particleFSFrameCount = 0;
    particleFSLoop = 0;
    angleVar = 1;
    animationName = "";
    particleType = "spaceobject";
    timerPeriod = 1;
    lifeTime = 20;
    moveVelocity[] = {0,0,0};
    rotationVelocity = 1;
    weight = 5;
    volume = 1;
    rubbing = 0.01;
    size[] = {1,1};
    color[] = {{1,1,1,1},{1,1,1,0}};
		animationSpeed[] = {0};
		animationSpeedCoef = 1;
		randomDirectionPeriod = 0.1;
		randomDirectionIntensity = 0.05;
    onTimerScript = "";
    beforeDestroyScript = "";
    destroyOnWaterSurface = 1;
    destroyOnWaterSurfaceOffset = -0.1;
    lifeTimeVar = 0;
		position[] = {0, 0, 0};
		positionVar[] = {1,1,1};
		moveVelocityVar[] = {2,2,2};
		positionVarConst[] = {0, 0, 0};

    rotationVelocityVar = 360;
    sizeVar = 0;
    colorVar[] = {0,0,0,0};
    randomDirectionPeriodVar = 0;
    randomDirectionIntensityVar = 0;

		bounceOnSurface = 0.01;
		bounceOnSurfaceVar = 0.01;

	};

	class ScrapsCraterEffect: Default
	{
		interval = 0.002;
    circleRadius = 0;
    circleVelocity[] = {0,0,0};
		particleShape = "\x\addons\a3_epoch_assets\models\scraps.p3d";
    particleFSNtieth = 0;
    particleFSIndex = 1;
    particleFSFrameCount = 0;
    particleFSLoop = 0;
    angleVar = 1;
    animationName = "";
    particleType = "spaceobject";
    timerPeriod = 1;
    lifeTime = 20;
    moveVelocity[] = {0,0,0};
    rotationVelocity = 1;
    weight = 5;
    volume = 1;
    rubbing = 0.01;
    size[] = {1,1};
    color[] = {{1,1,1,1},{1,1,1,0}};
		animationSpeed[] = {0};
		animationSpeedCoef = 1;
		randomDirectionPeriod = 0.1;
		randomDirectionIntensity = 0.05;
    onTimerScript = "";
    beforeDestroyScript = "";
    destroyOnWaterSurface = 1;
    destroyOnWaterSurfaceOffset = -0.1;
    lifeTimeVar = 0;
		position[] = {0, 0, 0};
		positionVar[] = {1,1,1};
		moveVelocityVar[] = {2,2,2};
		positionVarConst[] = {0, 0, 0};

    rotationVelocityVar = 360;
    sizeVar = 0;
    colorVar[] = {0,0,0,0};
    randomDirectionPeriodVar = 0;
    randomDirectionIntensityVar = 0;

		bounceOnSurface = 0.01;
		bounceOnSurfaceVar = 0.01;

	};

	class ObjectDestructionFire1SmallxG: Default
	{
		interval = 0.01;
		circleRadius = 0;
		circleVelocity[] = {0,0,0};
		particleFSNtieth = 16;
		particleFSIndex = 10;
		particleFSFrameCount = 32;
		particleFSLoop = 1;
		angleVar = 0.1;
		particleShape = "\x\addons\a3_epoch_assets\ParticleEffect\UniversalG";
		animationName = "";
		particleType = "Billboard";
		timerPeriod = 1;
		lifeTime = 1.5;
		moveVelocity[] = {0,1,0};
		rotationVelocity = 0;
		weight = 0.045;
		volume = 0.04;
		rubbing = 0.05;
		size[] = {"1.2 * 1.5 + 1","0.1 * 1.5 + 0.2"};
		color[] = {{ 1,1,1,-1 }};
		animationSpeed[] = {0.5,1};
		randomDirectionPeriod = 0;
		randomDirectionIntensity = 0;
		onTimerScript = "";
		beforeDestroyScript = "";
		lifeTimeVar = 0.4;
		positionVar[] = {0.1,0.3,0.1};
		moveVelocityVar[] = {0.1,0.5,0.1};
		rotationVelocityVar = 10;
		sizeVar = 0.5;
		colorVar[] = {0.1,0.1,0.1,0};
		randomDirectionPeriodVar = 0;
		randomDirectionIntensityVar = 0;
		coreIntensity = 1.25;
		coreDistance = 1.0;
		damageTime = 0.7;
		constantDistance = 1.0;
		damageType = "Fire";
	};
	class ObjectDestructionFire1SmallxR: Default
	{
		interval = 0.01;
		circleRadius = 0;
		circleVelocity[] = {0,0,0};
		particleFSNtieth = 16;
		particleFSIndex = 10;
		particleFSFrameCount = 32;
		particleFSLoop = 1;
		angleVar = 0.1;
		particleShape = "\x\addons\a3_epoch_assets\ParticleEffect\UniversalR";
		animationName = "";
		particleType = "Billboard";
		timerPeriod = 1;
		lifeTime = 1.5;
		moveVelocity[] = {0,1,0};
		rotationVelocity = 0;
		weight = 0.045;
		volume = 0.04;
		rubbing = 0.05;
		size[] = {"1.2 * 1.5 + 1","0.1 * 1.5 + 0.2"};
		color[] = {{ 1,1,1,-1 }};
		animationSpeed[] = {0.5,1};
		randomDirectionPeriod = 0;
		randomDirectionIntensity = 0;
		onTimerScript = "";
		beforeDestroyScript = "";
		lifeTimeVar = 0.4;
		positionVar[] = {0.1,0.3,0.1};
		moveVelocityVar[] = {0.1,0.5,0.1};
		rotationVelocityVar = 10;
		sizeVar = 0.5;
		colorVar[] = {0.1,0.1,0.1,0};
		randomDirectionPeriodVar = 0;
		randomDirectionIntensityVar = 0;
		coreIntensity = 1.25;
		coreDistance = 1.0;
		damageTime = 0.5;
		constantDistance = 1.0;
		damageType = "Fire";
	};
	class ObjectDestructionFire1SmallxB: Default
	{
		interval = 0.01;
		circleRadius = 0;
		circleVelocity[] = {0,0,0};
		particleFSNtieth = 16;
		particleFSIndex = 10;
		particleFSFrameCount = 32;
		particleFSLoop = 1;
		angleVar = 0.1;
		particleShape = "\x\addons\a3_epoch_assets\ParticleEffect\UniversalB";
		animationName = "";
		particleType = "Billboard";
		timerPeriod = 1;
		lifeTime = 1.5;
		moveVelocity[] = {0,1,0};
		rotationVelocity = 0;
		weight = 0.045;
		volume = 0.04;
		rubbing = 0.05;
		size[] = {"1.2 * 1.5 + 1","0.1 * 1.5 + 0.2"};
		color[] = {{ 1,1,1,-1 }};
		animationSpeed[] = {0.5,1};
		randomDirectionPeriod = 0;
		randomDirectionIntensity = 0;
		onTimerScript = "";
		beforeDestroyScript = "";
		lifeTimeVar = 0.4;
		positionVar[] = {0.1,0.3,0.1};
		moveVelocityVar[] = {0.1,0.5,0.1};
		rotationVelocityVar = 10;
		sizeVar = 0.5;
		colorVar[] = {0.1,0.1,0.1,0};
		randomDirectionPeriodVar = 0;
		randomDirectionIntensityVar = 0;
		coreIntensity = 1.25;
		coreDistance = 1.0;
		damageTime = 0.2;
		constantDistance = 1.0;
		damageType = "Fire";
	};

	class ObjectDestructionBloodE : Default
	{
		interval = 0.01;
		circleRadius = 0;
		circleVelocity[] = { 0, 0, 0 };
		particleShape = "\A3\data_f\ParticleEffects\Universal\Universal";
		particleFSNtieth = 16;
		particleFSIndex = 13;
		particleFSFrameCount = 1;
		particleFSLoop = 0;
		angleVar = 360;
		animationName = "";
		particleType = "Billboard";
		timerPeriod = 1;
		lifeTime = 0.2;
		moveVelocity[] = { 0, -0.1, 0 };
		rotationVelocity = 1;
		weight = 0.1275;
		volume = 0.1;
		rubbing = 0.05;
		size[] = { 0, 0.1 };
		color[] = { { 0.4, 0.3, 0.3, 2 }, { 0.4, 0.3, 0.3, 2 }, { 0.4, 0.3, 0.3, 1.4 }, { 0.4, 0.3, 0.3, 0.8 }, { 0.4, 0.3, 0.3, 0.4 }, { 0.4, 0.3, 0.3, 0.05 }, { 0.4, 0.3, 0.3, 0.001 } };
		animationSpeed[] = { 0.1 };
		randomDirectionPeriod = 0;
		randomDirectionIntensity = 0;
		onTimerScript = "";
		beforeDestroyScript = "";
		destroyOnWaterSurface = 1;
		destroyOnWaterSurfaceOffset = -0.3;
		blockAIVisibility = 0;
		lifeTimeVar = 0.2;
		positionVar[] = { 0.01, 0.01, 0.01 };
		MoveVelocityVar[] = { 0, 0, 0 };
		rotationVelocityVar = 1;
		sizeVar = 0.1;
		colorVar[] = { 0, 0, 0, 0.2 };
		randomDirectionPeriodVar = 0;
		randomDirectionIntensityVar = 0;
		coreIntensity = 1.25;
		coreDistance = 1.0;
		damageTime = 0.2;
		constantDistance = 1.0;
		damageType = "Fire";
	};
	class ObjectDestructionFire2SmallxB: Default
	{
		interval = 0.2;
		circleRadius = 0;
		circleVelocity[] = {0,0,0};
		particleFSNtieth = 16;
		particleFSIndex = 10;
		particleFSFrameCount = 32;
		particleFSLoop = 1;
		angleVar = 0.1;
		particleShape = "\x\addons\a3_epoch_assets\ParticleEffect\UniversalB";
		animationName = "";
		particleType = "Billboard";
		timerPeriod = 1;
		lifeTime = 1.5;
		moveVelocity[] = {0,1,0};
		rotationVelocity = 0;
		weight = 0.045;
		volume = 0.04;
		rubbing = 0.05;
		size[] = {"1.2 * 1.5 + 1","0.1 * 1.5 + 0.2"};
		color[] = {{ 1,1,1,-1 }};
		animationSpeed[] = {0.5,1};
		randomDirectionPeriod = 0;
		randomDirectionIntensity = 0;
		onTimerScript = "";
		beforeDestroyScript = "";
		lifeTimeVar = 0.4;
		positionVar[] = {0.1,0.3,0.1};
		moveVelocityVar[] = {0.1,0.5,0.1};
		rotationVelocityVar = 10;
		sizeVar = 0.5;
		colorVar[] = {0.1,0.1,0.1,0};
		randomDirectionPeriodVar = 0;
		randomDirectionIntensityVar = 0;
		coreIntensity = 0.25;
		coreDistance = 1.75;
		damageTime = 0.75;
		constantDistance = 1.0;
		damageType = "Fire";
	};

	/*
	class Blood1 : Default
	{
		interval = "0.004 * (hit interpolate [20,20.01,-1,1])";
		circleRadius = 0;
		circleVelocity[] = { 0, 0, 0 };
		particleShape = "\A3\data_f\ParticleEffects\Universal\Universal";
		particleFSNtieth = 16;
		particleFSIndex = 13;
		particleFSFrameCount = 1;
		particleFSLoop = 0;
		angleVar = 360;
		animationName = "";
		particleType = "Billboard";
		timerPeriod = 1;
		lifeTime = 0.12;
		moveVelocity[] = { "(inDirX * 2 - surfNormalX / 4) * inSpeed / 350 * 2", "(inDirY * 2 - surfNormalY / 4) * inSpeed / 350 * 2", "(inDirZ * 2 - surfNormalZ / 4) * inSpeed / 350 * 2" };
		rotationVelocity = 1;
		weight = 0.1275;
		volume = 0.1;
		rubbing = 0.4;
		size[] = { 0.02, 0.5, 0.8 };
		color[] = { { 1, 0.8, 0.8, 0.7 }, { 1, 0.8, 0.8, 0.7 }, { 1, 0.8, 0.8, 0.7 }, { 1, 0.8, 0.8, 0.5 }, { 1, 0.8, 0.8, 0.3 }, { 1, 0.8, 0.8, 0.1 }, { 1, 0.8, 0.8, 0.05 } };
		animationSpeed[] = { 0.1 };
		randomDirectionPeriod = 0;
		randomDirectionIntensity = 0;
		onTimerScript = "";
		beforeDestroyScript = "";
		destroyOnWaterSurface = 1;
		destroyOnWaterSurfaceOffset = -0.3;
		blockAIVisibility = 0;
		lifeTimeVar = 0.1;
		positionVar[] = { 0.01, 0.01, 0.01 };
		MoveVelocityVar[] = { 0.8, 0.8, 0.8 };
		rotationVelocityVar = 1;
		sizeVar = 0.1;
		colorVar[] = { 0, 0, 0, 0.2 };
		randomDirectionPeriodVar = 0;
		randomDirectionIntensityVar = 0;
	};
	class Blood2 : Default
	{
		interval = "(0.02 + 0.1/((hit interpolate [0.1,45,0.1,45])+0.001)) * (hit interpolate [20,20.01,-1,1])";
		circleRadius = 0;
		circleVelocity[] = { 0, 0, 0 };
		particleShape = "\A3\data_f\ParticleEffects\Universal\Meat_ca";
		particleFSNtieth = 1;
		particleFSIndex = 0;
		particleFSFrameCount = 1;
		particleFSLoop = 0;
		angleVar = 360;
		animationName = "";
		particleType = "SpaceObject";
		timerPeriod = 1;
		lifeTime = 2;
		moveVelocity[] = { 0, 1.5, 0 };
		rotationVelocity = 1;
		weight = 22;
		volume = 1;
		rubbing = 0.2;
		size[] = { 1.5 };
		color[] = { { 0.25, 0.05, 0.05, 0.7 }, { 0.25, 0.05, 0.05, 0.7 }, { 0.25, 0.05, 0.05, 0.7 }, { 0.25, 0.05, 0.05, 0.5 }, { 0.25, 0.05, 0.05, 0.3 }, { 0.25, 0.05, 0.05, 0.1 }, { 0.25, 0.05, 0.05, 0.05 } };
		animationSpeed[] = { 0.1 };
		randomDirectionPeriod = 0;
		randomDirectionIntensity = 0;
		onTimerScript = "";
		beforeDestroyScript = "";
		bounceOnSurface = 0;
		bounceOnSurfaceVar = 0;
		destroyOnWaterSurface = 1;
		destroyOnWaterSurfaceOffset = -0.3;
		blockAIVisibility = 0;
		lifeTimeVar = 0.1;
		positionVar[] = { 0.01, 0.01, 0.01 };
		MoveVelocityVar[] = { "1.8*((hit interpolate [0,45,0,45])/30)", "1.8*((hit interpolate [0,45,0,45])/30)", "1.8*((hit interpolate [0,45,0,45])/30)" };
		rotationVelocityVar = 8;
		sizeVar = 0.05;
		colorVar[] = { 0, 0, 0, 0.2 };
		randomDirectionPeriodVar = 0;
		randomDirectionIntensityVar = 0;
	};
	class Blood3 : Default
	{
		interval = "0.015 + 0.1/((hit interpolate [0.1,45,0.1,45])+0.001))";
		circleRadius = 0;
		circleVelocity[] = { 0, 0, 0 };
		particleShape = "\A3\data_f\ParticleEffects\Universal\Meat_ca";
		particleFSNtieth = 1;
		particleFSIndex = 0;
		particleFSFrameCount = 1;
		particleFSLoop = 0;
		angleVar = 360;
		animationName = "";
		particleType = "SpaceObject";
		timerPeriod = 1;
		lifeTime = 2;
		moveVelocity[] = { 0, 1.5, 0 };
		rotationVelocity = 1;
		weight = 22;
		volume = 1;
		rubbing = 0.2;
		size[] = { 0.3 };
		color[] = { { 0.25, 0.05, 0.05, 0.7 }, { 0.25, 0.05, 0.05, 0.7 }, { 0.25, 0.05, 0.05, 0.7 }, { 0.25, 0.05, 0.05, 0.5 }, { 0.25, 0.05, 0.05, 0.3 }, { 0.25, 0.05, 0.05, 0.1 }, { 0.25, 0.05, 0.05, 0.05 } };
		animationSpeed[] = { 0.1 };
		randomDirectionPeriod = 0;
		randomDirectionIntensity = 0;
		onTimerScript = "";
		beforeDestroyScript = "";
		bounceOnSurface = 0;
		bounceOnSurfaceVar = 0;
		destroyOnWaterSurface = 1;
		destroyOnWaterSurfaceOffset = -0.3;
		blockAIVisibility = 0;
		lifeTimeVar = 0.1;
		positionVar[] = { 0.01, 0.01, 0.01 };
		MoveVelocityVar[] = { "2*((hit interpolate [0,45,0,45])/10)", "2*((hit interpolate [0,45,0,45])/10)", "2*((hit interpolate [0,45,0,45])/10)" };
		rotationVelocityVar = 8;
		sizeVar = 0.05;
		colorVar[] = { 0, 0, 0, 0.2 };
		randomDirectionPeriodVar = 0;
		randomDirectionIntensityVar = 0;
	};
	*/
};
