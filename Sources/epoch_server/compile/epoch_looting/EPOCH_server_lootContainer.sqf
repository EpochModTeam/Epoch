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
private ["_class","_pos","_dir","_object","_whConfig","_type","_lootClasses","_player","_maxLoot","_triggerType","_eventArray","_animated","_config"];
params ["_object","_player",["_token","",[""]]];
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
	} else {
		[_object, "Food"] call EPOCH_serverLootObject;
	};

	if ((random 1) <= EPOCH_antagonistChanceLoot) then{
		_antagTable = [_type, "CfgMainTable", "antagonists"] call EPOCH_weightedArray;
		_antagTableArray = _antagTable select 0;
		if !(_antagTableArray isEqualTo[]) then{
			_weightedArray = _antagTable select 1;
			_triggerType = _antagTableArray select(selectRandom _weightedArray);
			[_player, _triggerType] call EPOCH_server_triggerEvent;
		};
	};
};
