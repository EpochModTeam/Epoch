/*
	Author: He-Man - EpochMod.com

    Contributors:

	Description:
	Server side Loot Spawner

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_looting/EPOCH_server_spawnLoot.sqf
*/

private [	"_masterConfig","_building","_buildingLoot","_selectedConfig","_config","_EpochLootChance","_cfgBaseBuilding","_loots","_lootLimit","_possibleLoots","_posName","_positions","_possibleCount","_randomIndex","_selectedLoot",
			"_pos","_dir","_item","_color","_GroundSpawnChance","_MinGroundContainers","_MaxGroundContainers","_lootType"
];

params [["_player",objNull,[objNull]],["_token","",[""]],["_objects",[]]];

if !([_player, _token] call EPOCH_server_getPToken) exitWith{};

_masterConfig = getmissionconfig "CfgBuildingLootPos";
{
	_building = _x;
	_buildingLoot = [];
	if !(_building in Epoch_LootedBuildings) then {
		_building setvariable ["Epoch_LootCleanup",diag_ticktime + Epoch_LootCleanupTime];
		Epoch_LootedBuildings pushBackUnique _building;
		_selectedConfig = typeOf _building;
		if (_selectedConfig isEqualTo "") then {
			(getModelInfo _building) params [["_modelName",""]];
			if (!isnil "_modelName") then {
				_selectedConfig = (_modelName splitString " .") joinString "_";
			};
		};
		_config = _masterConfig >> _selectedConfig;
		if (isClass(_config)) then {
			_EpochLootChance = getNumber (_config >> "EpochLootChance");
			if ((random 100) < _EpochLootChance) then {
				_cfgBaseBuilding = 'CfgBaseBuilding' call EPOCH_returnConfig;
				_loots = getArray(_config >> "loottypes");
				_lootLimit = (round random(getNumber(_config >> "limit"))) max 1;
				_possibleLoots = [];
				{
					_x params ["_posNameTMP","_class","_randomColor"];
					_posName = _posNameTMP;
					_positions = getArray(_config >> _posName);
					{
						_possibleLoots pushBack [_class,_randomColor,_x];
					} forEach _positions;
				} forEach _loots;
				if !(_possibleLoots isEqualTo []) then {
					for "_i" from 1 to _lootLimit do {
						_possibleCount = count _possibleLoots;
						if (_possibleCount > 0) then {
							_randomIndex = (floor random(_possibleCount));
							_selectedLoot = _possibleLoots deleteAt _randomIndex;
							_selectedLoot params ["_class","_randomColor","_position"];
							_position params ["_m2WPos","_relDir"];
							_pos = _building modelToWorld _m2WPos;
							if (_pos select 2 < 0) then {
								_pos set[2, 0];
							};
							if (_class isEqualType []) then {
								_class = selectRandom _class;
							};
							_dir = _relDir + (getDir _building);
							_item = createVehicle[_class, _pos, [], 0, "CAN_COLLIDE"];
							_item setvariable ["Epoch_ParentBuilding",_building];
							_buildingLoot pushback _item;
							_item setDir _dir;
							if (surfaceIsWater _pos) then {
								_item setPosASL _pos;
							} 
							else {
								_item setPosATL _pos;
							};
							if (_randomColor isEqualTo "true") then {
								_colors = getArray(_cfgBaseBuilding >> _class >> "availableTextures");
								if !(_colors isEqualTo[]) then {
									_color = selectRandom _colors;
									_item setObjectTextureGlobal[0, _color];
								};
							};
						};
					};
					_building setvariable ["Epoch_BuildingLoot",_buildingLoot];
				};
			}
			else {
				_GroundSpawnChance = getNumber (_config >> "GroundSpawnChance");
				if ((random 100) < _GroundSpawnChance) then {
					_MinGroundContainers = getNumber (_config >> "MinGroundContainers");
					_MaxGroundContainers = getNumber (_config >> "MaxGroundContainers");
					_lootType = getText(_config >> "lootType");
					_loots = getArray(_config >> "loottypes");
					_positions = [];
					{
						_x params ["_posName","_class","_randomColor"];
						if !((tolower _posName) in ["cabinetpos","toolrackpos"]) then {
							_positions = _positions + getArray (_config >> _posName);
						};
					} forEach _loots;
					if !(_positions isEqualTo []) then {
						for "_i" from 1 to (_MinGroundContainers + (round (random (_MaxGroundContainers - _MinGroundContainers)))) do {
							if ((count _positions) > 0) then {
								_position = _positions deleteat (floor (random (count _positions)));
								_position params ["_m2WPos","_relDir"];
								_pos = _building modelToWorld _m2WPos;
								_pos vectoradd [0,0,0.1];
								if (_pos select 2 < 0) then {
									_pos set[2, 0];
								};
								_item = createVehicle ["Epoch_LootHolder", _pos, [], 0, "CAN_COLLIDE"];
								_buildingLoot pushback _item;
								if (surfaceIsWater _pos) then {
									_item setPosASL _pos;
								} 
								else {
									_item setPosATL _pos;
								};
								[_item, format ["loots_%1",_lootType]] call EPOCH_serverLootObject;
							};
						};
						_building setvariable ["Epoch_BuildingLoot",_buildingLoot,true];		// true for debug!
					};
				};
			};
		};
	};
} foreach _objects;