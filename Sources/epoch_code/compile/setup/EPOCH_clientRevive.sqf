/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Unisex check for vests, gives swing ammo and performs radio changed check

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/setup/EPOCH_clientRevive.sqf

    Example:
    _data call EPOCH_clientRevive;

    Parameter(s):
		_this select 0: OBJECT - player object
        _this select 1: STRING - personal token

	Returns:
	NOTHING
*/
//[[[cog import generate_private_arrays ]]]
private ["_group","_playerObject","_ply"];
//[[[end]]]
_playerObject = _this select 0;
if !(alive player && alive _playerObject && !isPlayer _playerObject) then {
	_ply = player;
	_group = group player;
	selectPlayer _playerObject;
	deleteVehicle _ply;

	Epoch_canBeRevived = false;
	Epoch_personalToken = _this select 1;

	[] spawn EPOCH_masterLoop;
	[5, 100] call EPOCH_niteLight;

	closeDialog 0;
	("BIS_fnc_respawnCounter" call BIS_fnc_rscLayer) cutText ["","PLAIN"];

	{
		player removeEventHandler [_x, 0];
		player addEventHandler [_x,(["CfgEpochClient", _x, ""] call EPOCH_fnc_returnConfigEntryV2)];
	} forEach (["CfgEpochClient", "addEventHandler", []] call EPOCH_fnc_returnConfigEntryV2);

	// reset blood Pressure to warning level
	EPOCH_playerBloodP = 120;
} else {
	deleteVehicle _playerObject;
};

true call EPOCH_pushCustomVar;
