/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Server side container looting

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_looting/EPOCH_server_lootContainer.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_animated","_antagTable","_antagTableArray","_class","_config","_dir","_errorMsg","_lootClasses","_object","_pos","_triggerType","_type","_weightedArray","_whConfig"];
//[[[end]]]
params ["_object","_player",["_token","",[""]] ];
if !([_player, _token] call EPOCH_server_getPToken) exitWith{};

if (isNull _object) exitWith{};
if !(alive _object) exitWith{};
if (_player distance _object > 20) exitWith{};

if !(_object in EPOCH_cleanupQueue) then {

	EPOCH_cleanupQueue pushBack _object;

	_type = typeOf _object;

	_animated = configFile >> "CfgVehicles" >> _type >> "Destruction" >> "animations";
	if (isArray _animated) then {
		_object setDamage 1;
	};
	_config = (configFile >> "CfgMainTable" >> _type);
	_lootClasses = getArray(_config >> "tables");

	if !(_lootClasses isEqualTo []) then {
		_whConfig = configFile >> "CfgVehicles" >> _type >> "weaponHolderProxy";
		if (isText _whConfig) then {
			_class = getText (_whConfig);
			_pos = getPosATL _object;
			_dir = getDir _object;
			_object = createVehicle [_class, _pos, [], 0.0, "CAN_COLLIDE"];
			_object setDir _dir;
			_object setPosATL _pos;
		};

		[_object, _type] call EPOCH_serverLootObject;
		// force player to open gear on this object.
		if !(_type isequalto "Cargo_Container") then {
			[_object, {player action["Gear", _this]}] remoteExec ["call", _player];
		};
	} else {
		[_object, "Food"] call EPOCH_serverLootObject;
		// force player to open gear on this object.
		[_object, {player action["Gear", _this]}] remoteExec ["call", _player];
	};

};
