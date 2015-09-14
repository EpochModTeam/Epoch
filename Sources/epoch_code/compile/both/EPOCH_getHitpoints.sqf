private["_hitpoints", "_type", "_cachekey", "_na"];
_hitpoints = [];
if (!isNull _this) then {
	_type = typeOf _this;
	_cachekey = format["%1_HP", _type];
	_hitpoints = missionNamespace getVariable[_cachekey, []];
	if (_hitpoints isEqualTo []) then {
		_na = configProperties[configFile >> "CfgVehicles" >> _type >> "HitPoints", "_hitpoints pushBack configName _x; true", true];
		missionNamespace setVariable[_cachekey, _hitpoints];
	};
};
_hitpoints