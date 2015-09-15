/*
_object = _this;
_pos01 = getPosATL _object;


_soundSource = createSoundSource ["Sound_Fire", _pos01, [], 0];
_soundSource attachto [_object,[0,0,0]];


_source01 = "#particlesource" createVehicleLocal _pos01;
_source01 setParticleClass "ObjectDestructionBloodE";
_source01 attachto [_object,[0,0,0]];

_source03 = "#particlesource" createVehicleLocal _pos01;
_source03 setParticleClass "FireSparks";
_source03 attachto [_object,[0,0,0]];

uiSleep 1;


{
	deleteVehicle _x;
} foreach [_source01,_source03,_li,_soundSource];

deleteVehicle _source01;
deleteVehicle _object;
*/
