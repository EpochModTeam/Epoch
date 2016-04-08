/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Player Disconnect

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server/compile/epoch_player/EPOCH_server_onPlayerDisconnect.sqf
*/
private ["_return"];
params ["_player","_id","_uid","_name"];

_return = false;
if (!isNull _player) then {
	if (_player getVariable["SETUP", false]) then {
		[_player, _player getVariable["VARS", []]] call EPOCH_server_savePlayer;
		if (alive _player) then {
			_player setVariable ["VARS", nil];
			deleteVehicle _player;
		};
	} else {
		deleteVehicle _player;
	};
};
_return
