/*
	Author: Andrew Gregory - EpochMod.com

    Contributors: Aaron Clark - EpochMod.com

	Description:
	Mission: cage a sapper

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/missions/EPOCH_mission_cage_sapper.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_cage","_cage2","_cagePos","_sapper","_sound","_sounds","_startCage"];
//[[[end]]]
params ["_sapper","_trader"];

_cagePos = (getPosATL _trader) findEmptyPosition [1,50,"Land_Cages_F"];
_cage = createVehicle ["Land_Cages_F", _cagePos, [], 2, "CAN_COLLIDE"] ;
_cage setVectorDirAndUp [[0,0,1],[0,1,0]];
_cage2 = createVehicle ["Land_Cages_F", _cagePos, [], 2, "CAN_COLLIDE"] ;
_cage2 setVectorDirAndUp [[0,0,1],[0,1,0]];
_cage attachTo [_cage2,[0,1.3,0]];

// send to server
[_cage,_cage2] remoteExec ["EPOCH_localCleanup",2];

_startCage = diag_tickTime;
while {_sapper distance _cage > 3 || diag_tickTime - _startCage < 12} do {
	_sapper moveTo _cagePos;
	uiSleep 3;
};

deleteVehicle _sapper;
_sapper = createAgent ["Epoch_Sapper_F", getPos _cage2, [], 0, "FORM"];
_sapper setUnitPos "UP";
_sapper attachTo [_cage2,[0.4,-0.6,-0.4]];
_sapper setVectorDirAndUp [[0,0,1],[0,1,0]];
_sapper forcespeed 0;

if !(isNull _sapper) then {
	// send to server
	[_sapper] remoteExec ["EPOCH_localCleanup",2];
};

[player,Epoch_personalToken,objNull,false,25] remoteExec ["EPOCH_server_fillContainer",2];


while {player distance _sapper < 100 && alive player} do {
	if ((random 100) < 0.5) then {
		_sounds = ["sapper_groan0","sapper_groan1","sapper_groan2"];
		_sound = selectRandom _sounds;
		_sapper say3D _sound;
		[player, _sapper,_sound, Epoch_personalToken] remoteExec ["EPOCH_server_handle_say3D",2];
	};
	uiSleep 0.5;
};
