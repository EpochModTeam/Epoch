/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Custom Fire Effect emitter (not in use)

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_config/scripts/fireR.sqf
*/

params ["_object"];
_pos01 = getPos _object;

/*
_soundSource = createSoundSource ["Sound_Fire", _pos01, [], 0];
_soundSource attachto [_object,[0,0,0]];
*/

_source01 = "#particlesource" createVehicleLocal _pos01;
_source01 setParticleClass "ObjectDestructionFire1SmallxR";
_source01 attachto [_object,[0,0,0]];

_source03 = "#particlesource" createVehicleLocal _pos01;
_source03 setParticleClass "FireSparks";
_source03 attachto [_object,[0,0,0]];

_li = "#lightpoint" createVehicleLocal _pos01;
_li setLightBrightness 0.08;
_li setLightAmbient [1,0.28,0.05];
_li setLightColor [1,0.28,0.05];
_li lightAttachObject [_object, [0,0,0]];

uiSleep 5;

{
	deleteVehicle _x;
} foreach [_source01,_source03,_li];

deleteVehicle _object;
