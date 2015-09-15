private ["_pos"];

if (!isNull EP_light) then {
	deleteVehicle EP_light;
};

_pos = (getPosATL player);
_pos set [2,(_this select 1)];
EP_light = "#lightpoint" createvehiclelocal _pos;
EP_light setposATL _pos;
EP_light attachTo [player];

EP_light setLightDayLight true;
EP_light setLightBrightness (_this select 0);
EP_light setLightAmbient[0.05, 0.05, 0.05];
EP_light setlightcolor[0.05, 0.05, 0.05];

true