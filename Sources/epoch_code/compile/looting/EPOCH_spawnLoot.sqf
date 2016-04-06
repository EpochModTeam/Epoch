/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Runs chances to spawn loot objects on building

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_code/compile/looting/EPOCH_spawnLoot.sqf

    Example:
    [_building] call EPOCH_spawnLoot;

    Parameter(s):
		_this select 0: OBJECT - building
        _this select 1: NUMBER - Number of buildings checked before a building in the array can reattempt looting. Default: 333
        _this select 2: NUMBER - Limit of loot objects, as new are created old ones will be removed. Default: 33

	Returns:
	BOOL
*/
params [["_building",objNull,[objNull]], ["_lootCheckBufferLimit",333], ["_lootObjectLimit",33]];

_masterConfig = 'CfgBuildingLootPos' call EPOCH_returnConfig;
_config = _masterConfig >> (typeOf _building);

// exit with false if building is not lootable
_return = false;
if !(isClass(_config)) exitWith {_return};

_lootBias = getNumber(_config >> "lootBias");
_lootType = getText(_config >> "lootType");
_loots = getArray(_config >> _lootType);
_lootLimit = ceil random(getNumber(_config >> "limit"));

EPOCH_LootedBlds pushBackUnique _building;
if (count EPOCH_LootedBlds >= _lootCheckBufferLimit) then {
    EPOCH_LootedBlds deleteAt 0;
};

if ((random 100) < _lootBias) then {
    _possibleLoots = [];
    {
        _x params ["_posName","_class","_randomColor"];
        _positions = getArray(_config >> _posName);
        {
            _possibleLoots pushBack [_class,_randomColor,_x];
        } forEach _positions;
    } forEach _loots;

    if !(_possibleLoots isEqualTo []) then {
        for "_i" from 1 to _lootLimit do
        {
            _return = true;
            _possibleCount = count _possibleLoots;
            if (_possibleCount > 0) then {
                _randomIndex = (floor random(_possibleCount));

                _selectedLoot = _possibleLoots deleteAt _randomIndex;
                //
                _selectedLoot params ["_class","_randomColor","_position"];
                _position params ["_m2WPos","_relDir"];
                _pos = _building modelToWorld _m2WPos;
                // force item to ground level if resulting z pos is below ground.
                if (_pos select 2 < 0) then {
                    _pos set[2, 0];
                };
                if (_class isEqualType []) then {
                    _class = selectRandom _class;
                };
                _dir = _relDir + (getDir _building);
                _item = createVehicle[_class, _pos, [], 0.0, "CAN_COLLIDE"];
                _item setDir _dir;

                EPOCH_lootObjects pushBack _item;
                if (count EPOCH_lootObjects > _lootObjectLimit) then {
                    deleteVehicle (EPOCH_lootObjects deleteAt 0);
                };

                if (surfaceIsWater _pos) then {
                    _item setPosASL _pos;
                } else {
                    _item setPosATL _pos;
                };

                if (_randomColor isEqualTo "true") then {
                    _colors = getArray(configFile >> "CfgVehicles" >> _class >> "availableTextures");
                    if !(_colors isEqualTo[]) then {
                        _color = selectRandom _colors;
                        _item setObjectTextureGlobal[0, _color];
                    };
                };
            };
        };
    } else {
        diag_log format["DEBUG: no positions for: %1",_posName];
    };
};
_return
