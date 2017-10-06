/*
	Garden Manager
	by Aaron Clark - EpochMod.com

	Improvements and or bugfixes and other contributions are welcome via the github:
	https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server_settings/EpochEvents/GardenManager.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_babies","_babyClasses","_cargo","_garden","_mature","_matureClasses","_modifiedGardens","_seedClasses","_seeds","_spoil","_teenClasses","_teens"];
//[[[end]]]

_seedClasses = ["SeedPacket_GoldenSeal","SeedPacket_Hemp","SeedPacket_Poppy","SeedPacket_Pumpkin","SeedPacket_Sunflower"];
_babyClasses = ["Sapling_GoldenSeal","Sapling_Hemp","Sapling_Poppy","Sapling_Pumpkin","Sapling_Sunflower"];
_teenClasses = ["SaplingTeen_GoldenSeal","SaplingTeen_Hemp","SaplingTeen_Poppy","SaplingTeen_Pumpkin","SaplingTeen_Sunflower"];
_matureClasses = ["GoldenSeal","Hemp","Poppy","Pumpkin","Sunflower"];
_spoil = false;

// init var if not set
if (isNil "EPOCH_activeGardens") then {EPOCH_activeGardens = []};
// remove any null objects
EPOCH_activeGardens = EPOCH_activeGardens - [objNull];

_modifiedGardens = [];
{
	_garden = _x;
	_cargo = magazineCargo _x;
	// find all seeds
	_seeds = _cargo select {_x in _seedClasses};
	// find all baby plants
	_babies = _cargo select {_x in _babyClasses};
	// find all teen plants
	_teens = _cargo select {_x in _teenClasses};
	// find all mature plants
	_mature = _cargo select {_x in _matureClasses};

	// normalize storage
	clearWeaponCargoGlobal _x;
	clearMagazineCargoGlobal _x;
	clearBackpackCargoGlobal _x;
	clearItemCargoGlobal _x;

	// convert seeds to baby plants.
	{
		_garden addMagazineCargoGlobal [(_babyClasses param [_seedClasses find _x, _x]), 1];
	} forEach _seeds;

	// convert baby plants to teen
	{
		_garden addMagazineCargoGlobal [(_teenClasses param [_babyClasses find _x, _x]), 1];
	} forEach _babies;

	// convert teen plants to mature
	{
		_garden addMagazineCargoGlobal [(_matureClasses param [_teenClasses find _x, _x]), 1];
	} forEach _teens;

	// readd mature plants if spoil == false
	if !(_spoil) then {
		{
			_garden addMagazineCargoGlobal [_x, 1];
		} forEach _mature;
	};

	// push to temp array for save
	if !((magazineCargo _garden) isEqualTo _cargo) then {
		_modifiedGardens pushBack _garden;
	};

} forEach EPOCH_activeGardens;

// force all modified gardens to save via queue
if !(_modifiedGardens isEqualTo []) then {
	_modifiedGardens call EPOCH_server_save_vehicles;
};
