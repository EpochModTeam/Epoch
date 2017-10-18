/*
	Author/s:
		Aaron Clark - EpochMod.com

	Description:
		VIP Event - Reveals the map location of a random player that possesses a specific item every x minutes.

	Improvements and or bugfixes and other contributions are welcome via the github:
	https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server_vip_event/EpochEvents/event1.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_marker","_name","_owner","_player","_players","_position"];
//[[[end]]]
params [["_item","ItemBriefcaseGold100oz"]];
// marker name
_marker = "VIPMarker1";
// remove any previous markers
if (_marker in allMapMarkers) then {
    deleteMarker _marker;
};
// get all alive players with the VIP item.
_players = allPlayers select {(alive _x && (_item in magazines _x))};
// continue if players found
if !(_players isEqualTo []) then {
        // select random player
        _player = selectRandom _players;
        _position = getpos _player;
        _owner = owner _player;
        _name = name _player;
        // make marker
        _marker = createMarker[_marker, _position];
        _marker setMarkerShape "ICON";
        _marker setMarkerType "hd_objective";
        _marker setMarkerColor "ColorRed";
        _marker setMarkerText "VIP";
        // tell player about VIP status
        ["You are the VIP!", 5] remoteExec ['Epoch_message',_player];
        // broadcast to everyone else
        [format["%1 is the VIP!",_name], 5] remoteExec ['Epoch_message',[-2,-_owner]];
        // debug
        diag_log format["Epoch: VIP Marker triggered on %1", _player];
};
