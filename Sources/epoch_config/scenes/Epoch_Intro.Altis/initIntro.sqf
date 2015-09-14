titleCut ["", "BLACK FADED", 10e10];

0 fadeMusic 0.5;
0 fadeSound 0.1;
1 call bis_fnc_setovercast;
0 setRain 0.75;
0 setLightnings 1;
0 setFog [0.7,0.07,5];

//Remove A3 News Feed
((findDisplay 0) displayCtrl 2300) ctrlShow false;

playMusic "LeadTrack01a_F_EPB";
addMusicEventHandler ["MusicStop", {[] spawn {sleep (random 5)+5; playMusic "LeadTrack02b_F_EPB"}}];

_date = [2035,7,16,19,15 + random 2];
setDate _date;
uiSleep 0.01;
setDate _date;

showCinemaBorder false;

createVehicle ["Epoch_Sapper_F", [3932.53,12633.6,0.00144005], [], 0, "FORM"];

_logopos = [3943.34,12636.34,2.09695];
_logo = createvehicle ["logo_plane_EPOCH", _logopos, [], 0, "can_collide"];
_logo setDir 130.489;
_logo setPosATL _logopos;

/*################################################################
							1. Cutscene
################################################################*/

_camera = "camera" camCreate [3941.1,12636,1.63952];
_camera cameraEffect ["internal", "back"];
_camera camPrepareTarget [3960.31,12621,1.24998];
_camera camPreparePos [3941.1,12636,1.63952];
_camera camPrepareFOV 0.7;
_camera camCommitPrepared 0;
waitUntil {preloadCamera [3941.1,12636,1.63952]};

5 fadeMusic 0.8;
5 fadeSound 0.65;

titleCut ["", "BLACK IN", 3];

_camera camSetPos [3943.29,12638.5,2.65598];
_camera camCommit 20;

uiSleep 10;
_pos = [4001.23,12592,0.190382];

_bolt = createvehicle ["LightningBolt", _pos, [], 0, "can_collide"];
_bolt setPosATL _pos;
_bolt setVelocity [0, 0, -10];

_light1 = "#lightpoint" createVehicleLocal _pos;
_light1 setPosATL _pos;
_light1 setLightBrightness 30;
_light1 setLightAmbient [0.5, 0.5, 1];
_light1 setlightcolor [1, 1, 2];

_light2 = "lightning_F" createVehicleLocal _pos;
_light2 setDir random 360;
_light2 setPosATL _pos;

uiSleep (0.2 + random 0.1);

deletevehicle _bolt;
deletevehicle _light1;
deletevehicle _light2;

uiSleep (random 0.2);

_thunder = ["thunder_1", "thunder_2"] call BIS_fnc_selectRandom;
playSound _thunder;

uiSleep 3;
/*################################################################
							2. Cutscene
################################################################*/
_pos = [17383.8,12570.3,0.00143814];
_unit = createAgent ["Epoch_Cloak_F", _pos, [], 0, "CAN_COLLIDE"];
_unit setDir 312;

titleCut ["", "BLACK OUT", 1.8];
uiSleep 1.8;


_camera camPreparePos [17388.3,12569.3,2.20389];
_camera camPrepareTarget [17363.8,12574,1];
_camera camCommitPrepared 0;


uiSleep 0.1;
titleCut ["", "BLACK IN", 2];


_camera camSetTarget [17363.8,12574,0];
_camera camCommit 7;
_camera camSetPos [17389.1,12570.7,2.70086];
_camera camCommit 12;

uiSleep 8;
titleCut ["", "BLACK OUT", 2];


//Player "Epoch_Cloak_F"
//Pos [17384.3,12569.8,0.127153]
//Dir 311.943

//LEFT SIDE//
//PosCam1 [17384.6,12565.1,1.89488]
//Target1 [17379.4,12585.1,1]
//PosCam2 [17383.2,12564.2,2.79376]
//Target2 [17379.4,12585.1,0]

//RIGHT SIDE//
//PosCam1 [17388.3,12569.3,2.20389]
//Target1 [17363.8,12574,1]
//PosCam2 [17389.1,12570.7,2.70086]
//Target2 [17363.8,12574,0]



/*
if (true) then {
	[] spawn {
		_group = createGroup resistance;
		_pos = [3937.4,12655.1,0.0014286];
		_unit = _group createUnit ["Epoch_Cloak_F", _pos, [], 0, "CAN_COLLIDE"];
		uiSleep 0.5;
		_unit doMove _pos;
		_unit setDir 217;
	};


	uiSleep 1;

	_camera camPreparePos [3932.84,12649.6,2.78759];
	_camera camPrepareTarget [3934.74,12652,0.537243];
	_camera camCommitPrepared 0;

	uiSleep 0.1;
	titleCut ["", "BLACK IN", 2];


	_camera camSetTarget [3947.64,12668.4,0];
	_camera camCommit 16;
	_camera camSetPos [3934.93,12652.2,2.60123];
	_camera camCommit 20;
};

if (true) then  {
	//Pos1 [17360.9,12567.9,0.68]

	//Pos2 [17358.2,12567.1,0.67]

	//Target [17385.3,12569.2,1.99722] //1.09 2nd Possible hight

	uiSleep 1.8;

	_camera camPreparePos [17360.9,12567.9,0.68];
	_camera camPrepareTarget [17385.3,12569.2,1.99722];
	_camera camCommitPrepared 0;

	uiSleep 0.1;
	titleCut ["", "BLACK IN", 2];

	_camera camSetFov 0.6;
	_camera camSetPos [17358.2,12567.1,0.67];
	_camera camCommit 10;
};
*/

