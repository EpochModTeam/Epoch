/*
	Possible Ways:
	 1. Display always on game start
	 2. Display only one time, then never again
	 3. Display once and just again when a update released

	Current way: 2 but with possibility to use 3rd way
*/
private ["_display","_version","_shouldShow_Main","_shouldShow_Boot"];

_display = _this select 0;
if ((configName (configFile >> "CfgPatches" >> "A3_Missions_F_EPC")) != "") then { //Full game

	_shouldShow_Main = profileNamespace getVariable ["BIS_welcomeScreenShown", 0] == 0;
	_shouldShow_Boot = profileNamespace getVariable ["BIS_welcomeScreenBootcampShown", 0] == 0;
	_currentVersion = getNumber(configFile >> "CfgMods" >> "Epoch" >> "majorVersion");
	_oldVersion = profileNamespace getVariable ["EPOCH_welcomeScreenShown_majorVersion", 0];

	if (_currentVersion > _oldVersion) then {
		_display createDisplay "RscWelcomeEpoch";
		
		profileNamespace setVariable ["EPOCH_welcomeScreenShown_majorVersion", _currentVersion];
		profileNamespace setVariable ["BIS_welcomeScreenShown", 1];
		profileNamespace setVariable ["BIS_welcomeScreenBootcampShown", 1];
		profileNamespace setVariable ["EPOCH_welcomeScreenShown_Version", getText(configFile >> "CfgMods" >> "Epoch" >> "version")];
		saveProfileNamespace;
	};
};

/*
	HANDLE DEVELOPMENT BRANCH / BOOTCAMP MAIN MANU
*/
//if (productVersion select 2 > 126) then {} else {};


["onLoad",_this,"RscDisplayMain","GUI"] call compile preprocessFileLineNumbers "A3\ui_f\scripts\initDisplay.sqf";

if (_shouldShow_Main) then {
	profileNamespace setVariable ["BIS_welcomeScreenShown", 0];
	saveProfileNamespace;
};
if (_shouldShow_Boot) then {
	profileNamespace setVariable ["BIS_welcomeScreenBootcampShown", 0];
	saveProfileNamespace;
};