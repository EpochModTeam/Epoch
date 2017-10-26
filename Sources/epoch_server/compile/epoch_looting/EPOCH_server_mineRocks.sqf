/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Server side rock mining

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_looting/EPOCH_server_mineRocks.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_config","_posWH","_selectedConfig"];
//[[[end]]]
params ["_object","_index","_player",["_token","",[""]] ];
if !([_player, _token] call EPOCH_server_getPToken) exitWith{};

// make sure object still exists and is proper object type and alive.
if (_object isEqualType objNull && {!(isNull _object)} && {alive _object}) then {

	_posWH = getPosATL _player;
	_posWH set[2, 0];

	// define loot table class
	_selectedConfig = typeOf _object;
	if (_selectedConfig isEqualTo "") then {
		// handle simple/terrain objects
		(getModelInfo _object) params [["_modelName",""]];
		if (!isnil "_modelName") then {
			// replace spaces and periods with underscores
			_selectedConfig = (_modelName splitString " .") joinString "_";
		};
	};

	_config = configFile >> "CfgMainTable" >> _selectedConfig;
	if !(isClass(_config)) then {
		// allow override with generic loot classes if object class is not in CfgMainTable
		switch (_index) do {
			case 0: { _selectedConfig = "Rock" };
			case 1: { _selectedConfig = "Cinder" };
			case 2: { _selectedConfig = "Wreck" };
			case 3: { _selectedConfig = "Ore" };
		};
	};

	if (isSimpleObject _object) then {
		// just remove for now, object will respawn on restart.
		deleteVehicle _object;
	} else {
		_object setdamage 1;
	};

	// output loot
	[objNull, _selectedConfig, false, _posWH] call EPOCH_serverLootObject;
};
true
