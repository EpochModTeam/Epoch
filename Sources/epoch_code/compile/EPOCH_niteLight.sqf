/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	setup nightlight to provide improved night vision

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/EPOCH_niteLight.sqf
*/
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
