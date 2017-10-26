/*
	Function Name:			rmx_fnc_variables
	Author:					Raimonds Virtoss | Raymix
	
*/

#include <\x\Addons\rmx_init\defines.inc>

/*********************************** QUICK FUNCTION ***********************************/
if (isNil "rmx_var_godMode") then {rmx_var_godMode = true;};
/*
	Add function or FSM to quicklaunch menu. If exists, params from dialog are attached in front
	Careful with params if not function, will break ofc...
	Usage:
	[color, name, function]
	
	Server compile example (removed) ::>
	//fnc grabs code block from specified function and sends it trough PV
	//requires EH on server to combine and call compile elements ie - call compile (format ["%1 = %2",_this select 0, _this select 1]);
	[[1,1,1,1],"Server recompile example","['rmx_fnc_remoteRecompile','rmx_fnc_remoteRecompileLocal'] call rmx_fnc_recompileOnServer;"],
*/
rmx_var_quickFnc_items = 
[
	[[0.76,0.99,0.4,1],"exec sandbox.sqf ( CTRL + Backspace)","'rmx_fnc_sandbox' call rmx_fnc_recompile; [] spawn rmx_fnc_sandbox;"],
	[[0,1,0,1],"Output params","call rmx_fnc_output;"],
	[[1,0,0,1],format ["allowDamage: [%1]",rmx_var_godMode],"rmx_var_godMode = if (rmx_var_godMode) then {false} else {true}; player allowDamage rmx_var_godMode; call rmx_fnc_variables"],
	
	[[0,0,0,0],"-----------","Separator"],
	[[1,0.5,0,1],"Recompile dev variables","'rmx_fnc_variables' call rmx_fnc_recompile; call rmx_fnc_variables"],
	[[1,0.5,0,1],"Recompile ALL functions","call rmx_fnc_recompile;"], //can be used with params, but use generated list
	[[0,1,1,1],"*** Generated recompile list ***","don't run this line"] //leave this one, easier on github merge because no comma
];

// generates list of functions with recompile tag
{
	rmx_var_quickFnc_items pushBack [[1,1,1,0.4],format ["%1",_x],format ["'%1' call rmx_fnc_recompile;",_x]];
} forEach (call (uiNamespace getvariable ["rmx_functions_listRecompile",{[]}]));

/***************************************************************************************/

true
