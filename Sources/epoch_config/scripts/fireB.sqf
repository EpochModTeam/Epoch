_object = _this;
_pos01 = getPos _object;

/*
_soundSource = createSoundSource ["Sound_Fire", _pos01, [], 0];
_soundSource attachto [_object,[0,0,0]];
*/
_source01 = "#particlesource" createVehicleLocal _pos01;
_source01 setParticleClass "ObjectDestructionFire1SmallxB";
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