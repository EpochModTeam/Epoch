/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Server side damage and tree/bush looting

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_looting/EPOCH_server_knockDownTree.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_doPayout","_item","_lootType","_nearbyWH","_posWH"];
//[[[end]]]
params ["_object","_type","_player",["_token","",[""]] ];
if !([_player, _token] call EPOCH_server_getPToken) exitWith{};

if (isNull _object) exitWith{};
if (_player distance2D (getposATL _object) > 6) exitWith{};
_doPayout = false;
if (alive _object) then {
	_posWH = getPosATL _object;
	_posWH set[2, 0];

	if (isSimpleObject _object) then {
		// just remove for now, object will respawn on restart.
		deleteVehicle _object;
		_doPayout = true;
	} else {
		if (damage _object > 0.7) then {
			_object setdamage 1;
			_doPayout = true;

		} else {
			_object setdamage((damage _object) + 0.25) min 1;
		};
	};

	if (_doPayout) then {
		_lootType = "Tree";
		if (_type == 1) then {
			_lootType = "Bush";
		};

		_nearbyWH = nearestObjects[_posWH, ["groundWeaponHolder"], 2];
		if !(_nearbyWH isEqualTo[]) then {
			[(_nearbyWH select 0), _lootType] call EPOCH_serverLootObject;
		} else {
			_item = createVehicle["groundWeaponHolder", _posWH, [], 0, "CAN_COLLIDE"];
			_item setPosATL _posWH;
			[_item, _lootType] call EPOCH_serverLootObject;
		};
	};
};

true
