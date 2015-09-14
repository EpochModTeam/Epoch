
/*
	File: init.sqf
	Author: Karel Moricky

	Description:
	Function library initialization.

	Parameter(s):
	_this select 0: 'Function manager' logic

	Returns:
	Nothing
*/

#define VERSION	4.0

//--- Check version, has to match config version
if (getnumber (configfile >> "CfgFunctions" >> "version") != VERSION) exitwith {
	textlogformat [
		"Log: ERROR: Functions versions mismatch - config is %1, but script is %2",
		getnumber (configfile >> "CfgFunctions" >> "version"),
		VERSION
	];
};

//--- Fake header
_fnc_scriptName = if (isnil "_fnc_scriptName") then {"Functions Init"} else {_fnc_scriptName};


/******************************************************************************************************
	DEFINE HEADERS

	Headers are pieces of code inserted on the beginning of every function code before compiling.
	Using 'BIS_fnc_functionsDebug', you can alter the headers to provide special debug output.

	Modes can be following:
	0: No Debug - header saves parent script name and current script name into variables
	1: Save script Map - header additionaly save an array of all parent scripts into variable
	2: Save and log script map - apart from saving into variable, script map is also logged through debugLog

	Some system function are using simplified header unaffected to current debug mode.
	These functions has headerType = 1; set in config.

******************************************************************************************************/

private ["_this","_headerNoDebug","_headerSaveScriptMap","_headerLogScriptMap","_headerSystem","_debug","_headerDefault","_fncCompile","_recompile"];

_headerNoDebug = "
	_fnc_scriptNameParentTemp = if !(isnil '_fnc_scriptName') then {_fnc_scriptName} else {'%1'};
	private ['_fnc_scriptNameParent'];
	_fnc_scriptNameParent = _fnc_scriptNameParentTemp;
	_fnc_scriptNameParentTemp = nil;

	private ['_fnc_scriptName'];
	_fnc_scriptName = '%1';
	scriptname _fnc_scriptName;
";
_headerSaveScriptMap = "
	_fnc_scriptMapTemp = if !(isnil '_fnc_scriptMap') then {_fnc_scriptMap} else {[]};
	private ['_fnc_scriptMap'];
	_fnc_scriptMap = _fnc_scriptMapTemp + [_fnc_scriptName];
	_fnc_scriptMapTemp = nil;
";
_headerLogScriptMap = "
	_this call {
		private '_fnc_scriptMapText';
		_fnc_scriptMapText = '';
		{
			_fnc_scriptMapText = _fnc_scriptMapText + ' >> ' + _x;
		} foreach _fnc_scriptMap;
		textlogformat ['%2',_fnc_scriptMapText,_this];
	};
";
_headerSystem = "
	private ['_fnc_scriptNameParent'];
	_fnc_scriptNameParent = if !(isnil '_fnc_scriptName') then {_fnc_scriptName} else {'%1'};
	scriptname '%1';
";
_headerNone = "";

//--- Compose headers based on current debug mode
_debug = uinamespace getvariable ["bis_fnc_initFunctions_debugMode",0];
_headerDefault = switch _debug do {

	//--- 0 - Debug mode off
	default {
		_headerNoDebug
	};

	//--- 1 - Save script map (order of executed functions) to '_fnc_scriptMap' variable
	case 1: {
		_headerNoDebug + _headerSaveScriptMap
	};

	//--- 2 - Save script map and log it
	case 2: {
		_headerNoDebug + _headerSaveScriptMap + _headerLogScriptMap
	};
};


///////////////////////////////////////////////////////////////////////////////////////////////////////
//--- Compile function
_fncCompile = {
	private ["_fncVar","_fncMeta","_fncPath","_fncHeader","_fncExt","_header","_debugMessage"];
	_fncVar = _this select 0;
	_fncMeta = _this select 1;
	_fncHeader = _this select 2;
	_fncFinal = _this select 3;

	_fncPath = _fncMeta select 0;
	_fncExt = _fncMeta select 1;

	switch _fncExt do {

		//--- SQF
		case ".sqf": {
			_header = switch (_fncHeader) do {

				//--- No header (used in low-level functions, like 'fired' event handlers for every weapon)
				case -1: {
					_headerNone
				};

				//--- System functions' header (rewrite default header based on debug mode)
				case 1: {
					_headerSystem
				};


				//--- Full header
				default {
					_headerDefault
				}
			};
			_debugMessage = "Log: [Functions]%1 | %2";
			if (_fncFinal) then {
				compileFinal (format [_header,_fncVar,_debugMessage] + preprocessfilelinenumbers _fncPath);
			} else {
				compile (format [_header,_fncVar,_debugMessage] + preprocessfilelinenumbers _fncPath);
			};
		};

		//--- FSM
		case ".fsm": {
			compileFinal format ["%1_fsm = _this execfsm '%2'; %1_fsm",_fncVar,_fncPath];
		};

		default {0}
	};
};


/******************************************************************************************************
	COMPILE ONE FUNCTION

	When input is string containing function name instead of number, only the function is recompiled.

	The script stops here, reads function's meta data and recompile the function
	based on its extension and header.

	Instead of creating missionNamespace shortcut, it saves the function directly. Use it only for debugging!

******************************************************************************************************/

//--- Compile only selected
if (isnil "_this") then {_this = [];};
if (typename _this != typename []) then {_this = [_this];};
_recompile = if (count _this > 0) then {_this select 0} else {0};

if (typename _recompile == typename "") exitwith {
	private ["_fnc","_fncMeta","_headerType","_var"];

	//--- Recompile specific function
	_fnc = uinamespace getvariable _recompile;
	if !(isnil "_fnc") then {
		_fncMeta = _recompile call (uinamespace getvariable "bis_fnc_functionMeta");
		_headerType = if (count _this > 1) then {_this select 1} else {0};
		_var = [_recompile,[_recompile,_fncMeta,_headerType,false] call _fncCompile];
		uinamespace setvariable _var;
		missionnamespace setvariable _var;
		if (isnil "_functions_listRecompile") then {
			textlogformat ["Log: [Functions]: %1 recompiled with meta %2",_recompile,_fncMeta];
		};
	} else {
		_fncError = uinamespace getvariable "bis_fnc_error";
		if !(isnil "_fncError") then {
			["%1 is not a function.",_recompile] call _fncError;
		} else {
			textlogformat ["Log: [Functions]: ERROR: %1 is not a function.",_recompile];
		};
	};
};


/******************************************************************************************************
	COMPILE EVERYTHING IN GIVEN NAMESPACE(S)

	Function codes are present only in uiNamespace. Mission variables contains only shortcuts to uiNamespace.
	To executed only required compilation section, input param can be one of following numbers:

	0 - Autodetect what compile type should be used
	1 - Forced recompile of all the things
	2 - Create only uiNamespace variables (used in UI)
	3 - Create missionNamespace variables and initialize mission
	4 - Create only missionNamespace variables

******************************************************************************************************/

RscDisplayLoading_progressMission = nil;

//--- Get existing lists (create new ones when they doesn't exist)
private ["_functions_list","_functions_listPreInit","_functions_listPostInit","_functions_listPreStart","_functions_listRecompile","_file","_cfgSettings","_listConfigs","_recompileNames"];

_functions_listPreStart = [];
_functions_list = call (uinamespace getvariable ["bis_functions_list",{[]}]);
_functions_listPreInit = [call (uinamespace getvariable ["bis_functions_listPreInit",{[]}]),[]];
_functions_listPostInit = [call (uinamespace getvariable ["bis_functions_listPostInit",{[]}]),[]];
_functions_listRecompile = call (uinamespace getvariable ["bis_functions_listRecompile",{[]}]);

//--- When not forced, recompile only mission if uiNamespace functions exists
if (typename _recompile != typename 1) then {
	_recompile = if (count _functions_list > 0) then {3} else {0};
};

//--- When autodetect, recognize what recompile type is required
if (_recompile == 0 && !isnil {uinamespace getvariable "bis_fnc_init"}) then {_recompile = 3;};
if (_recompile == 3 && !isnil {missionnamespace getvariable "bis_fnc_init"}) then {_recompile = 4;};

_file = gettext (configfile >> "cfgFunctions" >> "file");
_cfgSettings = [
	[	configfile,		_file,		0	],	//--- 0
	[	campaignconfigfile,	"functions",	1	],	//--- 1
	[	missionconfigfile,	"functions",	1	]	//--- 2
];
	
_listConfigs = switch _recompile do {
	case 0: {
		[0,1,2];
	};
	case 1: {
		_functions_list = [];
		uinamespace setvariable ["bis_functions_list",_functions_list];
		_functions_listPreInit = [[],[]];
		uinamespace setvariable ["bis_functions_listPreInit",_functions_listPreInit];
		_functions_listPostInit = [[],[]];
		uinamespace setvariable ["bis_functions_listPostInit",_functions_listPostInit];
		_functions_listRecompile = [];
		uinamespace setvariable ["bis_functions_listRecompile",_functions_listRecompile];
		[0,1,2];
	};
	case 2: {
		[0];
	};
	case 3: {
		[1,2];
	};
	case 4: {
		[1,2];
	};
};


/******************************************************************************************************
	SCAN CFGFUNCTIONS

	Go through CfgFunctions, scan categories and declare all functions.

	Following variables are stored:
	<tag>_fnc_<functionName> - actual code of the function
	<tag>_fnc_<functionName>_meta - additional meta data of this format
		[<path>,<extension>,<header>,<preInit>,<postInit>,<recompile>,<category>]
		* path - path to actual file
		* extension - file extension, either ".sqf" or ".fsm"
		* header - header type. Usually 0, system functions are using 1 (see DEFINE HEADERS section)
		* preInit - function is executed automatically upon mission start, before objects are initalized
		* postInit - function is executed automatically upon mission start, after objects are initialized
		* recompile - function is recompiled upon mission start
		* category - function's category based on config structure

******************************************************************************************************/

//--- Allow recompile in dev version, in the editor and when description.ext contains 'allowFunctionsRecompile = 1;'
_compileFinal =
	//--- Dev version
	!cheatsEnabled
	&&
	//--- Editor mission
	((uinamespace getvariable ["gui_displays",[]]) find (finddisplay 26) != 1);
	//&&
	//--- Manual toggle
	//getnumber (missionconfigfile >> "allowFunctionsRecompile") == 0;

for "_t" from 0 to (count _listConfigs - 1) do {
	private ["_cfg","_pathConfig","_pathFile","_pathAccess","_cfgFunctions"];
	_cfg = _cfgSettings select (_listConfigs select _t);
	_pathConfig = _cfg select 0;
	_pathFile = _cfg select 1;
	_pathAccess = _cfg select 2;

	_cfgFunctions = (_pathConfig >> "cfgfunctions");
	for "_c" from 0 to (count _cfgFunctions - 1) do {
		private ["_currentTag"];
		_currentTag = _cfgFunctions select _c;

		//--- Is Tag
		if (isclass _currentTag) then {

			//--- Check of all required patches are in CfgPatches
			private ["_requiredAddons","_requiredAddonsMet"];
			_requiredAddons = getarray (_currentTag >> "requiredAddons");
			_requiredAddonsMet = true;
			{
				_requiredAddonsMet = _requiredAddonsMet && isclass (configfile >> "CfgPatches" >> _x);
			} foreach _requiredAddons;

			if (_requiredAddonsMet) then {

				//--- Initialize tag
				private ["_tag","_tagName","_itemPathRag"];
				_tag = configname _currentTag;
				_tagName = gettext (_currentTag >> "tag");
				if (_tagName == "") then {_tagName = configname _currentTag};
				_itemPathTag = gettext (_currentTag >> "file");

				for "_i" from 0 to (count _currentTag - 1) do {
					private ["_currentCategory"];
					_currentCategory = _currentTag select _i;

					//--- Is Category
					if (isclass _currentCategory) then {
						private ["_categoryName","_itemPathCat"];
						_categoryName = configname _currentCategory;
						_itemPathCat = gettext (_currentCategory >> "file");

						for "_n" from 0 to (count _currentCategory - 1) do {
							private ["_currentItem"];
							_currentItem = _currentCategory select _n;

							//--- Is Item
							if (isclass _currentItem) then {
								private ["_itemName","_itemPathItem","_itemExt","_itemPath","_itemVar","_itemCompile","_itemPreInit","_itemPostInit","_itemPreStart","_itemRecompile","_itemCheatsEnabled"];

								//--- Read function
								_itemName = configname _currentItem;
								_itemPathItem = gettext (_currentItem >> "file");
								_itemExt = gettext (_currentItem >> "ext");
								_itemPreInit = getnumber (_currentItem >> "preInit");
								_itemPostInit = getnumber (_currentItem >> "postInit");
								_itemPreStart = getnumber (_currentItem >> "preStart");
								_itemRecompile = getnumber (_currentItem >> "recompile");
								_itemCheatsEnabled = getnumber (_currentItem >> "cheatsEnabled");
								if (_itemExt == "") then {_itemExt = ".sqf"};
								_itemPath = if (_itemPathItem != "") then {_itemPathItem} else {
									if (_itemPathCat != "") then {_itemPathCat + "\fn_" + _itemName + _itemExt} else {
										if (_itemPathTag != "") then {_itemPathTag + "\fn_" + _itemName + _itemExt} else {""};
									};
								};
								_itemHeader = getnumber (_currentItem >> "headerType");

								//--- Compile function
								if (_itemPath == "") then {_itemPath = _pathFile + "\" + _categoryName + "\fn_" + _itemName + _itemExt};
								_itemVar = _tagName + "_fnc_" + _itemName;
								_itemMeta = [_itemPath,_itemExt,_itemHeader,_itemPreInit > 0,_itemPostInit > 0,_itemRecompile> 0,_tag,_categoryName,_itemName];

								/*
								_itemCompile = if (_itemName in ["animalBehaviour","guiEffectTiles_coef","GUImessage","guiEffectTiles","param","setIDCStreamFriendly","overviewauthor",
									"diagAARrecord","diagKey","missionHandlers","getServerVariable","missionFlow","initParams","initRespawn","missionTasksLocal",
									"missionConversationsLocal","missionCon","preload","logFormat","recompile","moduleInit","feedback_allowPP","feedback_allowDeathScreen",
									"feedbackInit","initMultiplayer","MP","displayMission","feedback_fatiguePP","respawnBase","dirTo","secondsToString","guiMessage_status",
									"selectRespawnTemplate","guiMessage_defaultPositions","startLoadingScreen_ids","damageChanged","incapacitatedEffect","invRemove",
									"relpos","inString","findSafePos","isPosBlacklisted","timeToString","distance2D","effectKilled","dynamictext","inAngleSector",
									"functionMeta","fatigueEffect","Functions Init","setovercast","postInit","recompile","preInit","script"
									]
								|| _categoryName in ["GUI","MP","Diagnostic","Effects","Feedback"]) then {
									[_itemVar,_itemMeta,_itemHeader,_compileFinal] call _fncCompile;
								} else {
									compileFinal "false"
								};
								*/

								_itemCompile = if (_itemCheatsEnabled == 0 || (_itemCheatsEnabled > 0 && cheatsEnabled)) then {
									[_itemVar, _itemMeta, _itemHeader, _compileFinal] call _fncCompile;
								}
								else {
									{false} //--- Function not available in retail version
								};

								//--- Register function
								if (typename _itemCompile == typename {}) then {
									if !(_itemVar in _functions_list) then {
										private ["_namespaces"];
										_namespaces = if (_pathAccess == 0) then {[uinamespace]} else {[missionnamespace]};
										{
											//---- Save function
											_x setvariable [
												_itemVar,
												_itemCompile
											];
											//--- Save function meta data
											_x setvariable [
												_itemVar + "_meta",
												compileFinal str _itemMeta
											];
										} foreach _namespaces;
										if (_pathAccess == 0) then {_functions_list set [count _functions_list,_itemVar];};
									};

									//--- Add to list of functions executed upon mission start
									if (_itemPreInit > 0) then {
										_functions_listPreInitAccess = _functions_listPreInit select _pathAccess;
										if !(_itemVar in _functions_listPreInitAccess) then {
											_functions_listPreInitAccess set [count _functions_listPreInitAccess,_itemVar];
										};
									};
									if (_itemPostInit > 0) then {
										_functions_listPostInitAccess = _functions_listPostInit select _pathAccess;
										if !(_itemVar in _functions_listPostInitAccess) then {
											_functions_listPostInitAccess set [count _functions_listPostInitAccess,_itemVar];
										};
									};

									//--- Add to list of functions executed upon game start
									if (_itemPreStart > 0) then {
										if (_pathAccess == 0) then {
											if !(_itemVar in _functions_listPreStart) then {
												_functions_listPreStart set [count _functions_listPreStart,_itemVar];
											};
										} else {
											_errorFnc = uinamespace getvariable "bis_fnc_error";
											_errorText = "%1 is a mission / campaign function and cannot contain 'preStart = 1;' param";
											if !(isnil {_errorFnc}) then {[_errorText,_itemVar] call _errorFnc;} else {diag_log format ["Log: [Functions]: " + _errorText,_itemVar];};
										};
									};

									//--- Add to list of functions recompiled upon mission start
									if (_itemRecompile > 0) then {
										if (_pathAccess == 0) then {
											if !(_itemVar in _functions_listRecompile) then {
												_functions_listRecompile set [count _functions_listRecompile,_itemVar];
											};
										} else {
											_errorFnc = uinamespace getvariable "bis_fnc_error";
											_errorText = "Redundant use of 'recompile = 1;' in %1 - mission / campaign functions are recompiled on start by default.";
											if !(isnil {_errorFnc}) then {[_errorText,_itemVar] call _errorFnc;} else {diag_log format ["Log: [Functions]: " + _errorText,_itemVar];};
										};
									};

									//if (_itemRecompile > 0) then {
									//	_functions_listRecompileAccess = _functions_listRecompile select _pathAccess;
									//	_functions_listRecompileAccess set [count _functions_listRecompileAccess,_itemVar];
									//};
									//--- Debug
									//debuglog ["Log:::::::::::::::::::Function",_itemVar,_itemPath,_pathAccess];
								};
							};
						};
					};
				};
			};
		};
	};
};

//--- Save the lists
uinamespace setvariable ["BIS_functions_list",compileFinal str (_functions_list)];
uinamespace setvariable ["BIS_functions_listPreInit",compileFinal str (_functions_listPreInit select 0)];
uinamespace setvariable ["BIS_functions_listPostInit",compileFinal str (_functions_listPostInit select 0)];
uinamespace setvariable ["BIS_functions_listRecompile",compileFinal str (_functions_listRecompile)];


/******************************************************************************************************
	FINISH

	When functions are saved, following operations are executed:
	1. MissionNamespace shortcuts are created
	2. Functions with 'recompile' param set to 1 are recompiled
	3. Functions with 'preInit' param set to 1 are executed
	4. Multiplayer framework is initialized
	5. Modules are initialized (running their own scripts, functions just wait until those scripts are ready)
	6. Automatic scripts "initServer.sqf", "initPlayerServer.sqf" and "initPlayerLocal.sqf" are executed
	7. Functions with 'postInit' param set to 1 are executed

	When done, system will set 'bis_fnc_init' to true so other systems can catch it.

******************************************************************************************************/

//--- Not core
if (_recompile in [0,1,3,4]) then {
	{
		_allowRecompile = (_x call (uinamespace getvariable "bis_fnc_functionMeta")) select 5;

		_xCode = uinamespace getvariable _x;
		if (_allowRecompile || !_compileFinal) then {
			_xCode = call compile str (uinamespace getvariable _x);
		};
		missionnamespace setvariable [_x,_xCode];
	} foreach _functions_list;
};

//--- Core only
if (_recompile == 2) then {
	//--- Call preStart functions
	if (isnull (finddisplay 0)) then {
		{
			["preStart %1",_x] call bis_fnc_logFormat;
			_function = [] call (uinamespace getvariable _x);
			uinamespace setvariable [_x + "_initStart",_function];
		} foreach _functions_listPreStart;
	};
};

//--- Mission only
if (_recompile == 3) then {

	//--- Switch to mission loading bar
	RscDisplayLoading_progressMission = true;

	//--- Execute script preload
	[] call bis_fnc_preload;

	//--- Create functions logic (cannot be created when game is launching; server only)
	if (isserver && isnull (missionnamespace getvariable ["bis_functions_mainscope",objnull]) && !isnil {uinamespace getvariable "bis_fnc_init"} && worldname != "") then {
		private ["_grpLogic"];
		createcenter sidelogic;
		_grpLogic = creategroup sidelogic;
		bis_functions_mainscope = _grpLogic createunit ["Logic",[9,9,9],[],0,"none"];
		bis_functions_mainscope setvariable ["isDedicated",isDedicated,true];
		publicvariable "bis_functions_mainscope";
	};
	(group bis_functions_mainscope) setgroupid [localize "str_dn_modules"]; //--- Name the group for curator

	if (!isNil "bis_functions_mainscope") then {
		private ["_test", "_test2"];
		_test = bis_functions_mainscope setPos (position bis_functions_mainscope); if (isnil "_test") then {_test = false};
		_test2 = bis_functions_mainscope playMove ""; if (isnil "_test2") then {_test2 = false};
		if (_test || _test2) then {0 call (compile (preprocessFileLineNumbers "a3\functions_f\misc\fn_initCounter.sqf"))};
	};

	//--- Recompile selected functions
	_fnc_scriptname = "recompile";
	{
		["recompile %1",_x] call bis_fnc_logFormat;
		_x call bis_fnc_recompile;
	} foreach _functions_listRecompile;

	//--- Call preInit functions
	_fnc_scriptname = "preInit";
	{
		{
			_time = diag_ticktime;
			[_x]call {
				private ["_recompile","_functions_list","_functions_listPreInit","_functions_listPostInit","_functions_listRecompile","_time"];
				["preInit"] call (missionnamespace getvariable (_this select 0))
			};
			["%1 (%2 ms)",_x,(diag_ticktime - _time) * 1000] call bis_fnc_logFormat;
		} foreach _x;
	} foreach _functions_listPreInit;

	//--- Call postInit functions once player is present
	_functions_listPostInit spawn {
		_fnc_scriptName = "script";
		_didJIP = false;
		0.15 call bis_fnc_progressloadingscreen;

		//--- Wait until server is initialized (to avoid running scripts before the server)
		waituntil {call (missionnamespace getvariable ["BIS_fnc_preload_server",{isserver}]) || getClientState == "LOGGED IN"};
		if (getClientState == "LOGGED IN") exitwith {}; //--- Server lost
		0.30 call bis_fnc_progressloadingscreen;

		//--- After JIP, units cannot be initialized during the loading screen		
		if !(isserver) then {
			endloadingscreen;
			waituntil {!isnull cameraon && getClientState != "MISSION RECEIVED" && getClientState != "GAME LOADED"};
			_didJIP = getClientState == "BRIEFING READ";
			startloadingscreen [""];
		};
		bis_functions_mainscope setvariable ["didJIP",_didJIP];
		0.45 call bis_fnc_progressloadingscreen;

		//--- Start MP framework and execute persistent functions
		[] call bis_fnc_initMultiplayer;
		0.60 call bis_fnc_progressloadingscreen;

		//--- Wait until module inits are initialized
		[] call bis_fnc_initModules;
		0.75 call bis_fnc_progressloadingscreen;

		//--- Execute automatic scripts
		if (isserver) then {
			[] execvm "initServer.sqf";
			"initServer.sqf" call bis_fnc_logFormat;
		};

		//--- Run mission scripts
		if !(isDedicated) then {
			[player,_didJIP] execvm "initPlayerLocal.sqf";
			[[[player,_didJIP],"initPlayerServer.sqf"],"bis_fnc_execvm",false,false] call bis_fnc_mp;
			"initPlayerLocal.sqf" call bis_fnc_logFormat;
			"initPlayerServer.sqf" call bis_fnc_logFormat;
		};
		0.90 call bis_fnc_progressloadingscreen;

		//--- Call postInit functions
		_fnc_scriptname = "postInit";
		{
			{
				_time = diag_ticktime;
				[_x,_didJIP] call {
					private ["_didJIP","_time"];
					["postInit",_this select 1] call (missionnamespace getvariable (_this select 0))
				};
				["%1 (%2 ms)",_x,(diag_ticktime - _time) * 1000] call bis_fnc_logFormat;
			} foreach _x;
		} foreach _this;
		1.0 call bis_fnc_progressloadingscreen;

		//--- MissionNamespace init
		missionnamespace setvariable ["bis_fnc_init",true];
	};
};

//--- Not mission
if (_recompile in [0,1,2]) then {

	//--- UInameSpace init
	uinamespace setvariable ["bis_fnc_init",true]
};

//--- Only mission variables
if (_recompile in [4]) then {

	//--- MissionNameSpace init
	missionnamespace setvariable ["bis_fnc_init",true];
};

//--- Only mission variables
if (_recompile in [1]) then {
	"Functions recompiled" call bis_fnc_log;
};

//--- Log the info about selected recompile type
_recompileNames = [
	"ERROR: Autodetect failed",
	"Forced",			
	"Core Only",
	"Mission/Campaign Only"	
];
//["Initialized: %1.",_recompileNames select _recompile] call (uinamespace getvariable "bis_fnc_logFormat");