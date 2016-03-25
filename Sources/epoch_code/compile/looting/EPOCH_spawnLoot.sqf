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
_loots = ["CfgEpochClient", "lootClasses", EPOCH_lootClasses] call EPOCH_fnc_returnConfigEntryV2;
_masterConfig = 'CfgBuildingLootPos' call EPOCH_returnConfig;
_config = _masterConfig >> (typeOf _building);

// exit with false if building is not lootable
if !(isClass(_config)) exitWith {false};
_return = false;

_lootBiasPos = getNumber(_config >> "lootBiasPos");
_lootType = getText(_config >> "lootType");

EPOCH_LootedBlds pushBackUnique _building;
if (count EPOCH_LootedBlds >= 100) then {
    EPOCH_LootedBlds deleteAt 0;
};

{
    _positions = getArray(_config >> (_x select 0));
    if !(_positions isEqualTo[]) then {
        _class = _x select 1;
        _randomColor = _x select 2;
        {

            if ((random 100) < _lootBiasPos) then {

                _pos = _building modelToWorld(_x select 0);

                if (nearestObjects[_pos, ["WH_Loot", "Animated_Loot"], 2] isEqualTo[]) then {
                    _return = true;

                    if (_class isEqualType []) then {
                        _class = selectRandom _class;
                    };

                    _dir = (_x select 1) + (getDir _building);
                    if (_dir > 360) then {
                        _dir = _dir - 360;
                    };

                    // Temp for now till we get more
                    if (_lootType == "mil" && _class == "Bed_EPOCH") then {
                        _class = "Bunk_EPOCH";
                    };

                    _item = createVehicle[_class, _pos, [], 0.0, "CAN_COLLIDE"];
                    _item setDir _dir;


                    // force item to ground level is resulting z pos is below ground.
                    if (_pos select 2 < 0) then {
                        _pos set[2, 0];
                    };

                    if (surfaceIsWater _pos) then {
                        _item setPosASL _pos;
                    } else {
                        _item setPosATL _pos;
                    };

                    if (_randomColor isEqualType "STRING") then {
                        _randomColor = _randomColor isEqualTo "true";
                    };

                    if (_randomColor) then {
                        _colors = getArray(configFile >> "CfgVehicles" >> _class >> "availableTextures");
                        if !(_colors isEqualTo[]) then {
                            _color = selectRandom _colors;
                            _item setObjectTextureGlobal[0, _color];
                        };
                    };
                };
            };
        }forEach _positions;
    };
}forEach _loots;
_return
