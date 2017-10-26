/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors:

	Description: Takes in total cost of vehicle and returns new price with damage % taken into account

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/scripts/favBar/epoch_favBar_refresh.sqf

	Usage: [_vehOBJ,_costINT] call EPOCH_calcDamageCost;
*/

private ["_dmg","_hitPoints"];
params [["_obj",objNull, [objNull]],["_cost",0, [0]]];

if (_obj isEqualTo objNull) exitWith {-1};

_hitPoints = getAllHitPointsDamage _obj;
_totalHPoints = count (_hitPoints select 1);
_totalDamagedPoints = 0;
{
	_dmg = _hitPoints select 2 select _forEachIndex;
	if (_dmg > 0) then {
		_totalDamagedPoints = _totalDamagedPoints +1;
	};
} forEach (_hitPoints select 1);

_math = round (_totalDamagedPoints / _totalHPoints * 100);
_newCost = _cost - _math;

_newCost 