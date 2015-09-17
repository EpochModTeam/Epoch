private ["_class","_pos","_dir","_object","_whConfig","_type","_lootClasses","_player","_maxLoot","_triggerType","_eventArray","_animated","_config"];

_object = _this select 0;

_player = _this select 1;

if !([_player,  _this select 2] call EPOCH_server_getPToken) exitWith{};
if (isNull _object) exitWith{};
if !(alive _object) exitWith{};
if (_player distance _object > 20) exitWith{};


if !(_object in EPOCH_cleanupQueue) then {
	
	EPOCH_cleanupQueue pushBack _object;

	_type = typeOf _object;

	_animated = configFile >> "CfgVehicles" >> _type >> "Destruction" >> "animations";
	if (isArray _animated) then {
		_object setDamage 1;
		//diag_log format["DEBUG: lootContainer %1", _object];
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
			_weightedArrayCount = _antagTable select 2;

			_triggerType = _antagTableArray select(_weightedArray select floor(random _weightedArrayCount));
			
			[_player, _triggerType] call EPOCH_server_triggerEvent;
		};
	};
};
