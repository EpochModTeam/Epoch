/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Server side damage and trash looting

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_looting/EPOCH_server_destroyTrash.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_antagTable","_antagTableArray","_config","_errorMsg","_item","_nearPlayers","_payout","_posWH","_target","_triggerType","_weightedArray"];
//[[[end]]]
params [["_object",objNull,[objNull]],["_type",0,[0]],["_player",objNull,[objNull]],["_token","",[""]] ];

if (isNull _object) exitWith{};
if !([_player, _token] call EPOCH_server_getPToken) exitWith{};

if (alive _object) then {

	_config = 'CfgEpochClient' call EPOCH_returnConfig;
	_payout = getArray(_config >> worldname >> "TrashClasses") param [_type, "Trash"];

	_posWH = getPosATL _player;

    if (isSimpleObject _object) then {
        // just remove for now, object will respawn on restart.
        deleteVehicle _object;
    } else {
        _object setdamage 1;
    };

	_item = createVehicle["groundWeaponHolder", _posWH, [], 0.0, "CAN_COLLIDE"];
	_item setPosATL _posWH;

	_config = (configFile >> "CfgMainTable" >> _payout);
	if (isClass _config) then {
		if (random 1 < getNumber(_config >> "chance")) then {
			[_item, _payout] call EPOCH_serverLootObject;
			// force player to open gear on this object.
			[_item, {player action["Gear", _this]}] remoteExec ["call", _player];
		};
	};

};
true
