/*
    Trigger Air drop client side via randomly selected player.
	by Aaron Clark - EpochMod.com

	Improvements and or bugfixes and other contributions are welcome via the github:
	https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server_settings/EpochEvents/AirDrop.sqf
*/
// 50% chance every 45 minutes by default
//[[[cog import generate_private_arrays ]]]
private ["_chance","_player","_players"];
//[[[end]]]
_chance = 50;
if (random 100 < _chance) then {

    // get all alive players
    _players = allPlayers select {alive _x};

    // continue if players found alive
    if !(_players isEqualTo []) then {

        // select random player
        _player = selectRandom _players;

        // Trigger air drop via player
        ["B_Heli_Transport_01_F", _player, true] remoteExec ['EPOCH_unitSpawn',_player];

        diag_log format["Epoch: Air Drop Triggered on %1", _player];
    };
};
