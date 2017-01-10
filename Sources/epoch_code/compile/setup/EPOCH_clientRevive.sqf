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
        _this select 2: NUMBER - loadABS

	Returns:
	NOTHING
*/
//[[[cog import generate_private_arrays ]]]
private ["_prevPlayerObject"];
//[[[end]]]
params [
    ["_playerObject",objNull,[objNull]],
    ["_personalToken","",[""]],
    ["_loadAbs",0,[0]]
];
if (isNull _playerObject) exitWith { diag_log "EPOCH-DEBUG: New Player Object was Null cannot revive." };
if !(alive player && alive _playerObject && !isPlayer _playerObject) then {

    // reveal new player object (to hopefully propagate info faster).
    player reveal _playerObject;

    // spawn a thread to wait for loadAbs to sync before using selectPlayer
    [_playerObject,_personalToken,_loadAbs] spawn {
        params ["_playerObject","_personalToken","_loadAbs"];

        // get current player object
        _prevPlayerObject = player;

        // wait for loadAbs to sync
        waitUntil {_loadAbs isEqualTo (loadAbs _playerObject)};

        // switch to new playerObject
        selectPlayer _playerObject;

        // delete previous player object
        deleteVehicle _prevPlayerObject;

        // set token and can revive to false
        Epoch_canBeRevived = false;
        Epoch_personalToken = _personalToken;

        // restart masterloop
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
    };
} else {
	deleteVehicle _playerObject;
};

true call EPOCH_pushCustomVar;
