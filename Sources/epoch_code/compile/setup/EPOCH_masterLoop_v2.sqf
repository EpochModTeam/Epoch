// EPOCHMOD.com
disableSerialization;
_config = 'CfgMasterLoop' call EPOCH_returnConfig;
_build_sqf = preprocessFile getText (_config >> "Init" >> "file");
_configs = "true" configClasses (_config >> "Events");
_condition = getText (_config >> "Events" >> "condition");
_file = getText (_config >> "Events" >> "file");
{
	_configName = configName _x;
	_varName = format["_EPOCH_%1",_configName];
	_build_sqf = _build_sqf + '
		'+_varName+' = diag_tickTime;
	';
}forEach _configs;
_build_sqf = _build_sqf + '
while {'+_condition+'} do {
	_tickTime = diag_tickTime;
';
{
	_delay = getNumber(_x >> "delay");
	_configName = configName _x;
	_varName = format["_EPOCH_%1",_configName];
	_code = preprocessFile format ["%1\%2.sqf",_file,_configName];
	_build_sqf = _build_sqf + '
	if ((_tickTime - '+_varName+') > '+str(_delay)+') then {
		'+_varName+' = _tickTime;
		'+_code+'
	};
	';
}forEach _configs;
_build_sqf = _build_sqf + '
	if (vehicle player != player) then {
		if (isNull EPOCH_currentVehicle) then {
			EPOCH_currentVehicle = vehicle player;
			EPOCH_currentVehicle addEventHandler["GetOut", "_this call EPOCH_antiWall"];
		};
	};
	uiSleep 0.1;
};';
call compile _build_sqf;
