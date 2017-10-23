/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Unisex check for vests, gives swing ammo and performs radio changed check

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/setup/EPOCH_masterLoop.sqf

    Example:
    [] spawn EPOCH_masterLoop;

    Parameter(s):
		NONE

	Returns:
	NOTHING
*/
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
	uiSleep 0.1;
};';
call compile _build_sqf;
