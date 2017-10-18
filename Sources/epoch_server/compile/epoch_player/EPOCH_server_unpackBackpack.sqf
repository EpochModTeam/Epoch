/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Unpack backpack

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_player/EPOCH_server_unpackBackpack.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_nearByHolder","_wH","_wHPos"];
//[[[end]]]
params ["_item","_player",["_token","",[""]] ];

if !([_player,_token] call EPOCH_server_getPToken) exitWith {};
if (_item isKindOf "Bag_Base") then {
	_wH = objNull;
	_nearByHolder = nearestObjects [_player,["groundWeaponHolder"],3];
	if (_nearByHolder isEqualTo []) then {
		_wHPos = _player modelToWorld [0,1,0];
		if (surfaceIsWater _wHPos) then {
			_wHPos = ASLToATL _wHPos;
		};
		_wH = createVehicle ["groundWeaponHolder",_wHPos, [], 0, "CAN_COLLIDE"];
	} else {
		_wH = _nearByHolder select 0;
	};
	_wH addBackpackCargoGlobal [_item,1];
};
