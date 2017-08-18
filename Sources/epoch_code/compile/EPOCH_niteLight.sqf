/*
	Author: Aaron Clark - EpochMod.com

    Contributors: Andrew Gregory

	Description:
	setup nightlight to provide improved night vision

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_code/compile/EPOCH_niteLight.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_config","_nlSettings","_pos"];
//[[[end]]]
if (!isNull EP_light) then {
	deleteVehicle EP_light;
};
_config = 'CfgEpochClient' call EPOCH_returnConfig;
_nlSettings = getArray( _config >> "niteLight");
_nlSettings params [["_nlEnabled",1],["_nlBright",1.88],["_nlZ",22]];
if (_nlEnabled isEqualTo 1) then {
	_pos = (getPosATL player);
	_pos set [2,_nlZ];
	EP_light = "#lightpoint" createvehiclelocal _pos;
	EP_light setposATL _pos;
	EP_light attachTo [player,[0,8.11,_nlZ]]; //offset infront of player so that the darkness is 'following' them.
	EP_light setLightDayLight false; //Sets light so it can only be used at night.
	EP_light setLightBrightness _nlBright;
	EP_light setLightAmbient [0.435, 0.439, 0.439];//Using new Colours.
	EP_light setlightcolor [0.435, 0.439, 0.439];
};
true
