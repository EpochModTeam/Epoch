/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors:

	Description:
	DESC-TBA

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/scripts/craftingv2/EPOCH_crafting_checkGear.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_cN","_cP","_near","_nearObjects","_out","_player","_recipe"];
//[[[end]]]
params ["_recipes"];

_nearObjects = nearestObjects [player,["WeaponHolder","LandVehicle","Air"],10];

_near = []; _out = [];
{
	_near append magazineCargo _x;
	_near append itemCargo _x;
	_near append weaponCargo _x;
} forEach _nearObjects;

_player = (magazines player) + (items player) + (weapons player);

{
	_recipe = if (_x isEqualType "STRING") then {[_x,1]} else {_x};
	_cP = {_x == (_recipe select 0)} count _player;
	_cN = {_x == (_recipe select 0)} count _near;
	_out pushBack [_cP, _cN, _recipe select 1];
} forEach _recipes;

_out
