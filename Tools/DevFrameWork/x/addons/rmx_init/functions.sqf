//--- Fake header
_fnc_scriptName = if (isnil "_fnc_scriptName") then {"Dev Function Libs"} else {_fnc_scriptName};

/******************************************************************************************************
	DEFINE HEADERS
******************************************************************************************************/

private ["_this","_headerMetaData","_headerBuffer","_headerDebugOff","_headerNone","_headerSQF","_debugLevel","_debugEnabled","_headerDefault","_fncCompile","_recompile","_debugHeader","_debugDestination"];

_headerMetaData = "
	_fnc_scriptNameParentTemp = if !(isnil '_fnc_scriptName') then {_fnc_scriptName} else {'%1'};
	private ['_fnc_scriptNameParent'];
	_fnc_scriptNameParent = _fnc_scriptNameParentTemp;
	_fnc_scriptNameParentTemp = nil;

	private ['_fnc_scriptName'];
	_fnc_scriptName = '%1';
	scriptname _fnc_scriptName;
";

_headerBuffer = "
	_sendInfo = {rmx_var_logMsg pushBack [0,_fnc_scriptName,_this]};
	_sendWarning = {rmx_var_logMsg pushBack [1,_fnc_scriptName,_this]};
	_sendCritical = {rmx_var_logMsg pushBack [2,_fnc_scriptName,_this]};

";

_headerDebugOff = "
	_sendInfo = {};
	_sendWarning = {};
	_sendCritical = {};

";
_headerNone = "";

_debugEnabled = getNumber (configfile >> "devFunctions" >> "debugEnabled");

//default headers if no specific entries are given
_headerDefault = if (_debugEnabled > 0) then {_headerMetaData + _headerBuffer} else {_headerNone + _headerDebugOff};
/******************************************************************************************************
	Compile function
******************************************************************************************************/

_fncCompile = {
	private ["_fncVar","_fncMeta","_fncPath","_fncHeader","_fncExt","_header","_fncFinal","_footer"];
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
					_headerNone + _headerDebugOff
				};
				case 1: {
					_headerMetaData + _headerBuffer
				};
				default {
					_headerDefault
				};
			};
			
			if (_fncFinal) then {
				compileFinal (format [_header,_fncVar] + preprocessfilelinenumbers _fncPath);
			} else {
				compile (format [_header,_fncVar] + preprocessfilelinenumbers _fncPath);
			};
		};

		//--- FSM
		case ".fsm": {
			compileFinal format ["%1_fsm = _this execfsm '%2';",_fncVar,_fncPath];
		};

		default {0}
	};
};

_fnc_recompile = {
	private "_this";
	_fnc_scriptname = "rmx_recompile";
	{
		diag_log format ["Recompiling: %1",_x];
		_x call rmx_fnc_recompile;
	} count _this;
};

_fnc_init = {
	private ["_this","_call"];
	_fnc_scriptname = _this select 0;
	_call = _this select 1;
	{
		diag_log format ["[%2]: Calling: %1",_x,_fnc_scriptname];
		call (missionNamespace getVariable _x); //with missionNamespace do {call _x;};
	} count _call;
};

_fnc_createShortcuts = {
	private "_this";
	{
		_allowRecompile = (_x call (uiNamespace getvariable "bis_fnc_functionMeta")) select 5;
		_xCode = uiNamespace getvariable _x; //shortcut copied over directly
		if (_allowRecompile) then {
			_xCode = call compile str (uiNamespace getvariable _x); //shortcut call compiles every mission start
		};
		//diag_log format ["[%2]: Creating shortcut: %1",_x,_fnc_scriptname];
		missionNamespace setvariable [_x,_xCode];
	} foreach _this;
};
/******************************************************************************************************
	COMPILE ONE FUNCTION

	When input is string containing function name, only that one function is recompiled.

	The script stops here, reads function's meta data and recompile the function
	based on its extension and header. 
	Basically - it takes meta data from uiNamespace and uses it to replace function inside missionNamespace.
	
	This will work even if recompile = 0; is set, but will fail because it's compileFinal in this case

******************************************************************************************************/

//--- Compile only selected
if (isnil "_this") then {_this = [];};
if (typename _this != typename []) then {_this = [_this];};
_recompile = if (count _this > 0) then {_this select 0} else {0};

if (typename _recompile == typename "") exitwith {
	private ["_fnc","_fncMeta","_headerType","_var","_fncUINamespace"];

	//--- Recompile specific function
	_fncUINamespace = true;
	_fnc = uiNamespace getvariable _recompile;
	if (isnil "_fnc") then {_fnc = missionNamespace getvariable _recompile; _fncUINamespace = false;};
	if !(isnil "_fnc") then {
		_fncMeta = _recompile call (uiNamespace getvariable "bis_fnc_functionMeta");
		_headerType = if (count _this > 1) then {_this select 1} else {0};
		_var = [_recompile,[_recompile,_fncMeta,_headerType,false] call _fncCompile];
		if (_fncUINamespace) then {uiNamespace setvariable _var;};
		missionNamespace setvariable _var;
		if (isnil "_functions_listRecompile") then {
			diag_log format ["[%3]: %1 recompiled with _meta %2",_recompile,_fncMeta,_fnc_scriptname];
		};
	} else {
			diag_log format ["[%2]: %1 is not a function.",_recompile,_fnc_scriptname];
	};
};


/******************************************************************************************************
If params passed did not contain string, function will automatically detect if: fresh compiles, new mission or recompile

Detection is done by finalizing devlibs_init boolean inside 2 namespaces:
If bool doesn't exist anywhere, then game is launched
If bool exists only in uiNamespace then game was started, but not mission
If bool exists in missionNamespace, then server/client is running and will only recompile non-final functions.

To make functions non-final while developing, use recompile = 1; inside pbo configs, simple as that.
******************************************************************************************************/


if (call (uiNamespace getvariable ["devlibs_init",{false}])) exitWith {
	private ["_functions_list","_functions_listRecompile","_functions_listPreInit","_functions_listPostInit"];
	
	_functions_listRecompile = call (uiNamespace getvariable ["rmx_functions_listRecompile",{[]}]);
	
	if (call (missionNamespace getvariable ["devlibs_init",{false}])) then {
		_functions_listRecompile call _fnc_recompile;
	} else {
		_functions_list = call (uiNamespace getvariable ["rmx_functions_list",{[]}]);
		_functions_listPreInit = call (uiNamespace getvariable ["rmx_functions_listPreInit",{[]}]);
		_functions_listPostInit = call (uiNamespace getvariable ["rmx_functions_listPostInit",{[]}]);
		
		_functions_listRecompile call _fnc_recompile;
		
		_functions_list call _fnc_createShortcuts;
		["preInit",_functions_listPreInit] call _fnc_init;
		
		[_functions_listPostInit,_fnc_init] spawn {
			waitUntil {!isNil {missionNamespace getVariable "bis_fnc_init"}};
			["postInit",(_this select 0)] call (_this select 1);
		};
		missionNamespace setvariable ["devlibs_init",compileFinal "true"];
	}; 
};

_functions_list = [];
uiNamespace setvariable ["rmx_functions_list",_functions_list];
_functions_listPreInit = [];
uiNamespace setvariable ["rmx_functions_listPreInit",_functions_listPreInit];
_functions_listPostInit = [];
uiNamespace setvariable ["rmx_functions_listPostInit",_functions_listPostInit];
_functions_listRecompile = [];
uiNamespace setvariable ["rmx_functions_listRecompile",_functions_listRecompile];
_functions_listPreStart = [];

/******************************************************************************************************
SCAN devFunctions if devlibs_init was not detected anywhere. 
This part is done only once per game launch. Because of this an extra var inside uiNamespace is created with suffix _meta.
These _meta variables contain path to files, but are final.
If config file, file name or file path are changed, you'll have to re-PBO the whole structure again.

Go through devFunctions, scan categories and declare all functions.

Following variables are stored:
<tag>_fnc_<functionName> - actual code of the function
<tag>_fnc_<functionName>_meta - additional meta data of this format
	[<path>,<extension>,<header>,<preInit>,<postInit>,<recompile>,<category>]
	* path - path to actual file
	* extension - file extension, either ".sqf" or ".fsm"
	* debugLevel - header type
	* preInit - function is executed automatically upon mission start, before objects are initalized
	* postInit - function is executed automatically upon mission start, after objects are initialized
	* recompile - function is recompiled upon mission start
	* category - function's category based on config structure

******************************************************************************************************/

private ["_pathFile","_devFunctions"];
_pathFile = gettext (configfile >> "devFunctions" >> "file");

_devFunctions = (configfile >> "devFunctions");
for "_c" from 0 to (count _devFunctions - 1) do {
	private ["_currentTag"];
	_currentTag = _devFunctions select _c;

	//--- Is Tag
	if (isclass _currentTag) then {
		private ["_tag","_tagName","_itemPathTag"];
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
						private ["_epoch","_str","_itemName","_itemPathItem","_itemExt","_itemPreInit","_itemPostInit","_itemPreStart","_itemPath","_itemVar","_itemCompile","_itemRecompile"];

						//--- Read function
						_itemName = configname _currentItem;
						_itemPathItem = gettext (_currentItem >> "file");
						_itemExt = gettext (_currentItem >> "ext");
						_itemPreInit = getnumber (_currentItem >> "preInit");
						_itemPostInit = getnumber (_currentItem >> "postInit");
						_itemPreStart = getnumber (_currentItem >> "preStart");
						_itemRecompile = getnumber (_currentItem >> "recompile");
						if (_itemExt == "") then {_itemExt = ".sqf"};
						_itemPath = if (_itemPathItem != "") then {
							if (_tagName in ["rmx"]) then { //more tags can be added
								//--- Disable rewriting of global functions from outside
								private ["_itemPathItemRMX","_itemPathSlash"];
								_itemPathItemRMX = (tolower _itemPathItem) find "x";
								_itemPathSlash = (tolower _itemPathItem) find "\";
								diag_log format ["Not compiling: %1",_itemPathItem]; //remove later?
								if ((_itemPathItemRMX < 0 || _itemPathItemRMX > 1) && _itemPathSlash > 0) then {_itemPathItem = "";};
							};
							_itemPathItem
						} else {
							""
						};
						
						_epoch = _tagName in ["EPOCH","A3E"];
						
						//path in category
						if (_itemPath == "") then {
							if (_epoch) then {
								_itemPath = if (_itemPathCat != "") then {_itemPathCat + "\EPOCH_" + _itemName + _itemExt} else {
								""
							};
							} else {
								_itemPath = if (_itemPathCat != "") then {_itemPathCat + "\" + _itemName + _itemExt} else {
									if (_itemPathTag != "") then {_itemPathTag + "\" + _itemName + _itemExt} else {""};
								};
							};
						};
						
						_itemHeader = getnumber (_currentItem >> "debugHeader");
						_str = if (_epoch) then {"_"} else {"_fnc_"};
						
						//category name as folder
						if (_itemPath == "") then {
							if (_epoch) then {
								_itemPath = _itemPathTag + "\" + _categoryName + "\EPOCH_" + _itemName + _itemExt
							} else {
								_itemPath = _pathFile + "\" + _categoryName + "\" + _itemName + _itemExt
							};
						};
						
						_itemVar = _tagName + _str + _itemName;
						_itemMeta = [_itemPath,_itemExt,_itemHeader,_itemPreInit > 0,_itemPostInit > 0,_itemRecompile> 0,_tag,_categoryName,_itemName];
						_itemCompile = if (_itemRecompile > 0) then {
							[_itemVar,_itemMeta,_itemHeader,false] call _fncCompile;
						} else {
							[_itemVar,_itemMeta,_itemHeader,true] call _fncCompile;
						};

						//--- Register function
						if !(_itemVar in _functions_list) then {
								//---- Save function
								uiNamespace setvariable [_itemVar, _itemCompile];
								//--- Save function meta data
								uiNamespace setvariable [_itemVar + "_meta",compileFinal str _itemMeta];
							
							_functions_list set [count _functions_list,_itemVar];
						};
						//--- Add to list of functions executed when missionNamespace is created (during loading screen)
						if (_itemPreInit > 0) then {
							if !(_itemVar in _functions_listPreInit) then {
								_functions_listPreInit set [count _functions_listPreInit,_itemVar];
							};
						};
						//--- Add to list of functions executed after client, world and vehicles are created.
						if (_itemPostInit > 0) then {
							if !(_itemVar in _functions_listPostInit) then {
								_functions_listPostInit set [count _functions_listPostInit,_itemVar];
							};
						};
						//--- Add to list of functions executed upon game start where missionNamespace does not exist.
						if (_itemPreStart > 0) then {
							if !(_itemVar in _functions_listPreStart) then {
								_functions_listPreStart set [count _functions_listPreStart,_itemVar];
							};
						};
						//--- Add to list of functions that are not finalized and can be recompiled (DEV only). use recompile = 1;
						if (_itemRecompile > 0) then {
							if !(_itemVar in _functions_listRecompile) then {
								_functions_listRecompile set [count _functions_listRecompile,_itemVar];
							};
						};
					};
				};
			};
		};
	};
};

//--- Save the lists
uiNamespace setvariable ["rmx_functions_list",compileFinal str (_functions_list)];
uiNamespace setvariable ["rmx_functions_listRecompile",compileFinal str (_functions_listRecompile)];
uiNamespace setvariable ["rmx_functions_listPreInit",compileFinal str (_functions_listPreInit)];
uiNamespace setvariable ["rmx_functions_listPostInit",compileFinal str (_functions_listPostInit)];
uiNamespace setvariable ["devlibs_init",compileFinal "true"];

// Call preStarted functions

{
	_function = [] call (uiNamespace getvariable _x);
	uiNamespace setvariable [_x + "_preStart",_function];
} foreach _functions_listPreStart;

diag_log format ["[%1]: functions compiled",_fnc_scriptName];