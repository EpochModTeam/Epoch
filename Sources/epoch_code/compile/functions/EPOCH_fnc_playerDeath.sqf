/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Player death handler

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_code/compile/functions/EPOCH_fnc_playerDeath.sqf

    Example:
    player addEventHandler ["Killed", {_this call EPOCH_fnc_playerDeath}];

    Parameter(s):
		_this select 0: OBJECT - player
		_this select 1: OBJECT - killer

	Returns:
	BOOL
*/

private["_unit", "_killer"];
_unit = _this select 0;
_killer = _this select 1;

// test ejecting unit from vehicle if dead client side
if (vehicle _unit != _unit) then {
	_unit action["Eject", vehicle _unit];
};

EPOCH_deadPlayer_PVS = [player,_killer,toArray profileName,Epoch_personalToken];
publicVariableServer  "EPOCH_deadPlayer_PVS";

// disable build mode
EPOCH_buildMode = 0;
EPOCH_snapDirection = 0;
EPOCH_Target = objNull;

if (Epoch_canBeRevived) then {
	setPlayerRespawnTime 600;
	createDialog "TapOut";
} else {
	setPlayerRespawnTime 15;
	_dt = ["<t size='0.8' shadow='0' color='#99ffffff'>You can be just revived once per life!</t>", 0, 1, 5, 2, 0, 1] spawn bis_fnc_dynamictext;
};

[] spawn{
	while {!alive player} do {

		if (playerRespawnTime <= 1) exitWith{ (findDisplay 46) closeDisplay 0; };
		if (playerRespawnTime > 15 && !dialog) then {
			createDialog "TapOut";
		};
		uiSleep 0.1;
	};
};
