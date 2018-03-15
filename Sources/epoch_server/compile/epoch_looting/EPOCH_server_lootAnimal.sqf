/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Server side animal looting

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_looting/EPOCH_server_lootAnimal.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_class","_classOverride","_config","_errorMsg","_item","_objectClass","_pos"];
//[[[end]]]
params ["_object","_player",["_token","",[""]] ];
if !([_player, _token] call EPOCH_server_getPToken) exitWith{};

if !(isNull _object) then {
	_pos = getPosATL _object;
	_objectClass = typeOf _object;
	_classOverride = getText (configFile >> "CfgVehicles" >> _objectClass >> "epochLootClass");
	if (_classOverride != "") then {
		_objectClass = _classOverride;
	};
	deleteVehicle _object;
	_item = createVehicle["groundWeaponHolder", [0,0,0], [], 0.0, "CAN_COLLIDE"];
	if (_objectClass isequalto "GreatWhite_F") then {
		_item setvariable ["EPOCH_Loot",true,true];
	};
	_item setPosATL _pos;
	_class = "SeaFood";
	_config = configFile >> "CfgMainTable" >> _objectClass;
	if (isClass(_config)) then {
		_class = _objectClass;
	};
	[_item, _class, true] call EPOCH_serverLootObject;

	// force player to open gear on this object.
	[_item, {player action["Gear", _this]}] remoteExec ["call", _player];
};
true
