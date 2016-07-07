/*
	Author: Andrew Gregory - EpochMod.com

    Contributors: Aaron Clark

	Description:
    Detonate a boss sapper bomb at player position.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_antagonists/EPOCH_server_playerDeathOptions.sqf
*/
params ["_player", "_token"];
diag_log format["Epoch: ADMIN: Attempting player detonate on %1.", getPlayerUID _player];
if !([_player,_token]call EPOCH_server_getPToken)exitWith{};

_pos = getPosATL _player;
_bomb = createVehicle["SapperB_Charge_Ammo", _pos, [], 0, "CAN_COLLIDE"];
_bomb setDamage 1;
hideObjectGlobal _player;