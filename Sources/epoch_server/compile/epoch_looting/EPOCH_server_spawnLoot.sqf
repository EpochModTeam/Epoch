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

params [["_player",objNull,[objNull]],["_token","",[""]],["_LootsArray",[]]];

if !([_player, _token] call EPOCH_server_getPToken) exitWith{};

_masterConfig = getmissionconfig "CfgBuildingLootPos";
{
	_x params [["_Building",objnull],["_LootType",""],["_buildingLootArray",[]]];
	if (!isnull _Building) then {
		if !(_building in Epoch_LootedBuildings) then {
			_buildingLoot = [];
			_building setvariable ["Epoch_LootCleanup",diag_ticktime + Epoch_LootCleanupTime];
			Epoch_LootedBuildings pushBackUnique _building;
			switch _LootType do {
				case "EpochLoot": {
					{
						_x params ["_class","_pos","_dir","_color"];
						if (_class in (call Epoch_LootContainers)) then {
							_item = createVehicle [_class, _pos, [], 0, "CAN_COLLIDE"];
							_item setvariable ["Epoch_ParentBuilding",_building];
							_buildingLoot pushback _item;
							_item setDir _dir;
							if (surfaceIsWater _pos) then {
								_item setPosASL _pos;
							} 
							else {
								_item setPosATL _pos;
							};
							if !(_color isEqualTo "") then {
								_item setObjectTextureGlobal [0, _color];
							};
						};
					} foreach _buildingLootArray;
				};
				case "GroundLoot": {
					{
						_x params ["_lootType","_pos"];
						_item = createVehicle ["Epoch_LootHolder", _pos, [], 0, "CAN_COLLIDE"];
						_buildingLoot pushback _item;
						if (surfaceIsWater _pos) then {
							_item setPosASL _pos;
						} 
						else {
							_item setPosATL _pos;
						};
						[_item, format ["loots_%1",_lootType]] call EPOCH_serverLootObject;
					
					
					} foreach _buildingLootArray;
				};
			};
			if !(_buildingLoot isEqualTo []) then {
				_building setvariable ["Epoch_BuildingLoot",_buildingLoot];
			};
		};
	};
} foreach _LootsArray;