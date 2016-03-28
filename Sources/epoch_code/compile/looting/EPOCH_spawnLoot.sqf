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

	Returns:
	BOOL
*/
params [["_building",objNull,[objNull]]];

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
if (count EPOCH_LootedBlds >= 334) then {
    EPOCH_LootedBlds deleteAt 0;
};
diag_log format["TIME start: %1",diag_tickTime];

if ((random 100) < _lootBias) then {
    _possibleLoots = [];
    {
        _x params ["_posName","_class","_randomColor"];
        _positions = getArray(_config >> _posName);
        {
            _possibleLoots pushBack [_class,_randomColor,_x];
        } forEach _positions;
    } forEach _loots;
    diag_log format["TIME mid: %1",diag_tickTime];

    for "_i" from 1 to _lootLimit do
    {
        _return = true;
        _selectedLoot = _possibleLoots deleteAt (floor random(count _possibleLoots));
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
        if (count EPOCH_lootObjects > 50) then {
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

diag_log format["TIME fin: %1",diag_tickTime];
_return
