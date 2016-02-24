/*
	Author: Karel Moricky

	Description:
	Select respawn template from CfgRespawnTemplates and execute its script / function

	Parameter(s):
		0: STRING - engine script which called the function
		1: ARRAY - script arguments

	Returns:
	ARRAY of SCRIPTs
*/

_mode = [_this,0,"",[""]] call bis_fnc_param;
_args = [_this,1,[],[[]]] call bis_fnc_param;

//--- Get engine respawn
_respawn = 0 call bis_fnc_missionRespawnType;

//--- Detect what script was called
_isDeath = false;
switch (_mode) do {

	//--- Death (NONE): [<unit>,<killer>]
	case "playerKilledScript": {
		_respawn = 0;
		_isDeath = true;
	};

	//--- Death (INSTANT, BASE): [<oldUnit>,<killer>,<respawnDelay>]
	case "playerRespawnScript": {
		_args resize 2;
		missionnamespace setvariable ["BIS_fnc_selectRespawnTemplates_args",[_args select 0]];
		_isDeath = true;
	};

	//--- Respawn (BIRD, GROUP, SIDE): [<unit>,<killer>,<seagull>]
	case "playerRespawnSeagullScript": {
		_args = [_args select 2,_args select 0];
		_respawn = 1;
	};

	//--- Respawn (INSTANT, BASE, GROUP): [<newUnit>]
	case "playerResurrectScript": {
		if (_respawn == 4) then {_respawn = -1;};
		_args = _args + (missionnamespace getvariable ["BIS_fnc_selectRespawnTemplates_args",[objnull]]);
	};

	//--- Respawn (GROUP, SIDE): [<oldUnit>,<killer>,<newUnit>]
	case "playerRespawnOtherUnitScript": {
		_args = [_args select 2,_args select 0];
	};

	//--- Forced respawn
	case "initRespawn": {
		if !(_respawn in [2,3]) then {_respawn = -1;};
		_isDeath = true;
	};

	//--- Death: [objnull,objnull,objnull]
	case "initRespawnStart": {
		if !(_respawn in [2,3]) then {_respawn = -1;};
		_isDeath = true;
	};

	//--- Respawn: [objnull,objnull,objnull]
	case "initRespawnEnd": {
		if !(_respawn in [2,3]) then {_respawn = -1;};
	};
};

//--- Terminate when playerResurrectScript is triggered in GROUP respawn to prevent duplicate call
if (_respawn < 0) exitwith {[]};

//--- Get respawn templates
_respawnTemplates = [configfile >> "CfgRespawnTemplates","respawnTemplates" + (["",_respawn] call bis_fnc_missionRespawnType)] call bis_fnc_returnconfigentry;
if (ismultiplayer || _mode in ["initRespawn","initRespawnStart","initRespawnEnd"]) then {
	_playerside = if (player call bis_fnc_isUnitVirtual) then {"VIRTUAL"} else {str (player call bis_fnc_objectSide)};
	_respawnTemplates = [missionconfigfile,"respawnTemplates",_respawnTemplates] call bis_fnc_returnconfigentry;
	_respawnTemplates = [missionconfigfile,"respawnTemplates" + _playerside,_respawnTemplates] call bis_fnc_returnconfigentry;
};
if !(_respawnTemplates isEqualType []) then {_respawnTemplates = [_respawnTemplates];};

//--- Forced respawn






// -- Changed by Skaronator
/*

if (_isDeath && alive player) then {
	if (ismultiplayer) then {
		if (isnumber (missionconfigfile >> "respawnOnStart")) then {
			_respawnOnStart = getnumber (missionconfigfile >> "respawnOnStart") > 0;
		} else {
			{
				_cfgRespawn = [["CfgRespawnTemplates",_x],configfile] call bis_fnc_loadClass;
				if (_cfgRespawn != configfile) then {
					_respawnOnStart = _respawnOnStart || (getnumber (_cfgRespawn >> "respawnOnStart") > 0);
				};
			} foreach _respawnTemplates;
		};
	};
	if (_respawnOnStart) then {
		player setpos [10,10,10];
		player hideobject true;
		player enablesimulation false;
		forcerespawn player;
	} else {
		_isDeath = false;
	};
};
*/

if (_isDeath && alive player) then {
	_isDeath = false;
};


//if (_respawnOnStart) exitwith {[]};
// -- END








//--- Increase respawn count (displayed in the debriefing screen)
if (_isDeath && ismultiplayer) then {["BIS_fnc_missionHandlers_reloads",1] call bis_fnc_counter;};

//--- Show loading screen to speed up the process when respawning
if !(_isDeath) then {["bis_fnc_selectRespawnTemplate","RscDisplayLoadingBlack"] call bis_fnc_startloadingscreen;};

//--- Calculate respawn delay
_respawnDelay = ([missionconfigfile,"respawnDelay",-1] call bis_fnc_returnconfigentry) call bis_fnc_parsenumber;
_scriptName = if (_isDeath) then {"onPlayerKilled"} else {"onPlayerRespawn"};
_scripts = [];
{
	_cfgRespawn = [["CfgRespawnTemplates",_x],configfile] call bis_fnc_loadClass;
	if (_cfgRespawn != configfile) then {

		//--- Template specific respawn delay
		if (_respawnDelay < 0) then {
			_respawnDelay = ([_cfgRespawn,"respawnDelay",-1] call bis_fnc_returnconfigentry) call bis_fnc_parsenumber;
			if (_respawnDelay >= 0) then {setplayerrespawntime _respawnDelay;};
		};
	};
} foreach _respawnTemplates;
_respawnDelay = _respawnDelay max 0;

//--- Execute codes
{
	_cfgRespawn = [["CfgRespawnTemplates",_x],configfile] call bis_fnc_loadClass;
	if (_cfgRespawn != configfile) then {

		//--- Get the code
		_scriptPath = gettext (_cfgRespawn >> _scriptName);
		if (_scriptPath != "") then {
			_code = missionnamespace getvariable _scriptPath;
			_codeType = "function";
			if (isnil {_code}) then {
				_code = compile preprocessfilelinenumbers _scriptPath;
				_codeType = "file";
			};

			//--- Execute the code
			_script = (_args + [_respawn,_respawnDelay]) spawn _code;
			_scripts pushBack _script;
			["%4 template '%1' executed from %2 '%3'",_x,_codeType,_scriptPath,_scriptName] call bis_fnc_logFormat;
		} else {
			//["'%1' entry is missing in respawn template '%2'.",_scriptName,_x] call bis_fnc_error;
		};
	} else {
		["Respawn template '%1' not found.",_x] call bis_fnc_error;
	};
} foreach _respawnTemplates;

//--- Execute mission respawn
_script = (_args + [_respawn,_respawnDelay]) spawn compile preprocessfilelinenumbers (_scriptName + ".sqf");
_scripts pushBack _script;

//--- End the loading screen after short delay
if !(_isDeath) then {
	[] spawn {
		"bis_fnc_selectRespawnTemplate" call bis_fnc_endloadingscreen;
	};

	// -- Changed by Skaronator
	/*
	if !(player getvariable ["bis_fnc_selectRespawnTemplate_respawned",false]) then {
		player setvariable ["bis_fnc_selectRespawnTemplate_respawned",true,true]; //--- ToDo: Remove once engine solution is implemented
	};*/
	// -- END
};

_scripts
