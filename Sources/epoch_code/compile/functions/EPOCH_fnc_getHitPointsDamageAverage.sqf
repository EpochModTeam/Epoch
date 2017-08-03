/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Function to check HitPointDamageAverage.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/functions/EPOCH_fnc_getHitPointsDamageAverage.sqf

    Example:
    _average = [cursorObject, "steering", 1] call EPOCH_fnc_getHitPointsDamageAverage;;

    Parameter(s):
		_this select 0: OBJECT - Object to check Hitpoints
        _this select 1: STRING - String to find in Hitpointname (e.g. "wheel");
        _this select 2: SCALAR - Sub-Array in getAllHitPointsDamage to search for String (default = 0)
		_this select 3: SCALAR - Sub-Array for Hitpoint-Values in getAllHitPointsDamage (default = 2)

	Returns:
	SCALAR
*/
params [ "_object", "_match", ["_indexIn", 0], ["_indexOut", 2]  ];
_dmg = 0;
_parts = 0;
_allHitPoints = getAllHitPointsDamage _object;
{
	 if ((toLower(_x) find _match) != -1) then {
		 _dmg = _dmg + ((_allHitPoints select _indexOut) select _forEachIndex);
		 _parts = _parts + 1;
	 };
} forEach (_allHitPoints select _indexIn);
(_dmg / _parts)
