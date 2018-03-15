/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Sets marker for trader to red and triggers drone to spawn on killer

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_server/EPOCH_server_traderKilled.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_markers","_objHiveKey","_slot","_playerCStats","_playerKarma","_playerKarmaAdj","_kIndex"];
//[[[end]]]
params ["_trader","_player"];
if (!isNull _trader) then {
	_markers = _trader getVariable["MARKER_REF",[]];
	if !(_markers isequalto []) then {
		{
			_x setMarkerColor "ColorRed";
		}forEach _markers;
	};
	_slot = _trader getVariable["AI_SLOT", -1];
	if (_slot != -1) then {
		// Spawn Drone on player
		[_player, "UAV"] call EPOCH_server_triggerEvent;
		_objHiveKey = format ["%1:%2", (call EPOCH_fn_InstanceID), _slot];
		["AI", _objHiveKey] call EPOCH_fnc_server_hiveDEL;
		["AI_ITEMS", _objHiveKey] call EPOCH_fnc_server_hiveDEL;
	};
	// send karma stat to seller
	_kIndex = EPOCH_communityStats find "Karma";
	_playerCStats = _player getVariable["COMMUNITY_STATS", EPOCH_defaultStatVars];
	_playerKarma = _playerCStats select _kIndex;
	_playerKarmaAdj = -5;
	if(_playerKarma < 0)then{_playerKarmaAdj = 5};
	[_player, "Karma", _playerKarmaAdj, true] call EPOCH_server_updatePlayerStats;
};
