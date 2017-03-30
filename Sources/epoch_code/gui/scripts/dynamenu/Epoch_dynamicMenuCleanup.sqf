/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors:

	Description:
	DESC-TBA

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/scripts/dynamenu/Epoch_dynamicMenuCleanup.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_cfg","_cleanupVars","_close"];
//[[[end]]]
disableSerialization;
_close = param [0,false,[false]];

_cleanupVars = {
	_cfg = "CfgActionMenu" call EPOCH_returnConfig;
	{
		// call compile (format ["%1 = nil;",configName _x]);
		missionNamespace setVariable [configName _x,nil];
	} count (configProperties [(_cfg >> "variableDefines"),"true",false]);
};

if (_close) then {
    _display = findDisplay 66600;
    if !(isNull _display) then {
        _display closeDisplay 1;
    };
};

if (uiNamespace getVariable ["rmx_var_dynamicMenuInProgress",false]) then {

	uiNamespace setVariable ["rmx_var_dynamicMenuInProgress", nil];

	call _cleanupVars;


	[rmx_var_dynamenuPPHandle, 1, [0]] call epoch_postprocessAdjust;
	rmx_var_dynaControls = nil;
	rmx_var_dynamenuPPHandle call epoch_postprocessDestroy;
	rmx_var_dynamenuPPHandle = nil;
} else {
	call _cleanupVars;
};
true
