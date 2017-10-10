// makes loot and price configs for missing compatible items.

// get all model classes
EP = (configProperties [configFile >> "CfgVehicles", "isClass _x" , true]);

// list existing uniforms
_existing = ["U_O_CombatUniform_ocamo",
"U_O_GhillieSuit",
"U_O_PilotCoveralls",
"U_O_Wetsuit",
"U_C_Poor_1",
"U_C_WorkerCoveralls",
"U_C_Journalist",
"U_C_Scientist",
"U_OrestesBody",
"U_O_FullGhillie_lsh",
"U_O_FullGhillie_sard",
"U_O_FullGhillie_ard",
"U_C_Poloshirt_stripped",
"U_C_Poloshirt_blue",
"U_C_Poloshirt_burgundy",
"U_C_Poloshirt_tricolour",
"U_C_Poloshirt_salmon",
"U_C_Poloshirt_redwhite",
"U_OG_Guerilla1_1",
"U_OG_Guerilla2_1",
"U_OG_Guerilla2_2",
"U_OG_Guerilla2_3",
"U_OG_Guerilla3_1",
"U_OG_Guerilla3_2",
"U_OG_leader",
"U_C_Driver_1",
"U_C_Driver_2",
"U_C_Driver_3",
"U_C_Driver_4",
"U_C_Driver_1_black",
"U_C_Driver_1_blue",
"U_C_Driver_1_green",
"U_C_Driver_1_red",
"U_C_Driver_1_white",
"U_C_Driver_1_yellow",
"U_C_Driver_1_orange",
"U_C_Driver_1_red"];

_compatibleUniformClasses = EP select {(3 in getArray(_x >> "modelSides")) && !(1 in getArray(_x >> "modelSides"))};
_compatibleUniforms = [];
{
	_uniform = getText(_x >> "uniformClass");
	if !(_uniform in ["","-"]) then {
		_compatibleUniforms pushBackUnique _uniform;
	};
} forEach _compatibleUniformClasses;

_badUniforms = [];
{
	if !(_x in _compatibleUniforms) then {
		_badUniforms pushBackUnique _x;
	};
} forEach _existing;
EP = _badUniforms;

// remove
_finalUniforms = _compatibleUniforms - _existing;

_configStr = "";
{
	_configStr = _configStr + format['
{ { "%1", "item" }, 1 },',_x];
} forEach _finalUniforms;


{
	_configStr = _configStr + format['
class %1
{
	price = 7;
};',_x];
} forEach _finalUniforms;

copyToClipboard _configStr;
