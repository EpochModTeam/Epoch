/*
	Author: Andrew Gregory - EpochMod.com

    Contributors:

	Description:
	test code to spawn flocks (unused)

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_code/compile/startFlock.sqf
*/

//
//Flocking (Emergent) Behaviour AI Test / Demo
//
//An attempt to make UAVs fly with flock / bird / fly swarm like behaviour.
//Using the three rules of flocking behaviour with some modifications for Arma
//Currently only controls X & Y, Z to be added..
//
//USAGE
//
// As it's only testing at the moment you need to call this sqf (startFlock.sqf) with []execVM "\x\addons\epoch_code\compile\startFlock.sqf"
//
//CONTROLS:
//
//INS / DEL - Alignment Up / Down
//Home / End - Cohesion Up / Down
//PG Up / Pg Dn - Separate up / Down
//Up / Down Arrow - Speed Up / Down
//Left / Right Arrow - Script Speed Up / Down
//
//Notes
//
//Once you have a flock moving away try adding another. Flock spawns above player.

_disableAI = {
	{_this disableAI _x}forEach["TARGET","AUTOTARGET","FSM"];
};
_targetPos = getPosATL player;
_targetPos set[2, 42];
axeUAV = createVehicle["I_UAV_01_F", _targetPos, [], 56, "FLY"];
addToRemainsCollector[axeUAV];
axeUAV allowdamage false;
axeUAV flyInHeight 42;
_grp = createGroup RESISTANCE;
_driver = _grp createUnit["I_UAV_AI", position axeUAV, [], 0, "CAN_COLLIDE"];
_driver moveInAny axeUAV;
axeUAV call _disableAI;
axeHandle = [axeUAV] execFSM "\x\addons\epoch_code\system\flocking.fsm";
for [{_i=0}, {_i<12}, {_i=_i+1}] do
{
_targetPos = getPosATL player;
_targetPos set[2, 42];
_uav = createVehicle["I_UAV_01_F", _targetPos, [], 56, "FLY"];
addToRemainsCollector[_uav];
_uav flyInHeight 42;
_grp = createGroup RESISTANCE;
_driver = _grp createUnit["I_UAV_AI", position _uav, [], 0, "CAN_COLLIDE"];
_driver moveInAny _uav;
_uav allowdamage false;
_uav call _disableAI;
	[_uav] execFSM "\x\addons\epoch_code\system\flocking.fsm";
};

axeLineStart = getPosATL player;
axeLineFinish = getPosATL player;
onEachFrame {
	drawLine3D [axeLineStart, axeLineFinish, [1,1,1,1]];
};

EPOCH_KeyDownCustom = {
    _dikCode = _this select 1;
    _shift = _this select 2;
    _ctrl = _this select 3;
    _alt = _this select 4;
_handled = false;

	switch (_dikCode) do {

        case 0xD2: {
		axeWeightAlign = axeWeightAlign + 0.01;
		hint format ["ALIGN: %1", axeWeightAlign];
_handled = true;
        };

	case 0xD3: {
		axeWeightAlign = axeWeightAlign - 0.01;
		hint format ["ALIGN: %1", axeWeightAlign];
_handled = true;
        };

	case 0xC7: {
		axeWeightCohese = axeWeightCohese + 0.01;
		hint format ["COHESE: %1", axeWeightCohese];
_handled = true;
        };

	case 0xCF: {
		axeWeightCohese = axeWeightCohese - 0.01;
		hint format ["COHESE: %1", axeWeightCohese];
_handled = true;
        };

	case 0xC9: {
		axeWeightSpearate = axeWeightSpearate + 0.01;
		hint format ["SEPARATE: %1", axeWeightSpearate];
_handled = true;
        };

	case 0xD1: {
		axeWeightSpearate = axeWeightSpearate - 0.01;
		hint format ["SEPARATE: %1", axeWeightSpearate];
_handled = true;
        };

	case 0xC8: {
		axeSpeed = axeSpeed + 0.1;
		hint format ["SPEED: %1", axeSpeed];
_handled = true;
        };

	case 0xD0: {
		axeSpeed = axeSpeed - 0.1;
		hint format ["SPEED: %1", axeSpeed];
_handled = true;
        };

	case 0xCB: {
		axeLoopTime = axeLoopTime + 0.05;
		hint format ["RESPONSE: %1", axeLoopTime];
_handled = true;
        };


	case 0xCD: {
		axeLoopTime = axeLoopTime - 0.05;
		hint format ["RESPONSE: %1", axeLoopTime];
_handled = true;
        };



	};
_handled
};


[] spawn {
    (findDisplay 46) displayRemoveAllEventHandlers "KeyDown";
    (findDisplay 46) displayAddEventHandler["KeyDown",{_this call EPOCH_KeyDownCustom}];
};

while {true}
do
{
if (!isNull player) then{

			onMapSingleClick "player setpos _pos;true;";

};
};
