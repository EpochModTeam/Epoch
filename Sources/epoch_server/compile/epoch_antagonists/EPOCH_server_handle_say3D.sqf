/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    3d Sound System

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_antagonists/EPOCH_server_handle_say3D.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_nearBy","_range","_say3dsoundsConfig","_selectedSound","_target","_targets"];
//[[[end]]]
params [["_player",objNull,[objNull]],["_target",objNull],["_sound","",[""]], ["_token","",[""]] ];

if !([_player, _token] call EPOCH_server_getPToken) exitWith{};
if (isNull _target) then {_target = _player};

_say3dsoundsConfig = 'CfgSay3Dhandler' call EPOCH_returnConfig;
_selectedSound = (_say3dsoundsConfig >> _sound);
if (isClass _selectedSound) then {
	// get nearby players based on range
	_range = getNumber(_selectedSound >> "distance");
	_nearBy = (_target nearEntities [["Epoch_Male_F","Epoch_Female_F","LandVehicle","Ship","Air","Tank"], _range]) select {isPlayer _x};
	 // send sound to everyone except caller.
	_targets = _nearBy - [_player];
	if !(_targets isEqualTo []) then {
		[_target, _sound] remoteExec ['say3D',_targets];
	};
};
