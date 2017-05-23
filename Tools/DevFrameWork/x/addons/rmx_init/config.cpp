#include "BIS_AddonInfo.hpp"
//Author: Raimonds Virtoss / Raymix
class CfgPatches {
	class rmx_init {
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		//requiredAddons[] = {""};
	};
};
class CfgMods
{
	class rmx_devLibs
	{
		dir = "@EpochDEV";
		name = "RMX Dev library";
		picture = "";
		hidePicture = 0;
		hideName = 0;
		action = "http://raimonds.me";
		version = "0.1";
	};
};

class CfgAddons
{
	access = 1;
	class PreloadBanks
	{
	};
	class PreloadAddons
	{
		class rmx_devLibs
		{
			list[] = {};
		};
	};
};

// deps needs cleanup
#include "CfgGUI\gui_dependencies.hpp"

// dominion custom console, use Shift + F2 to activate
#include "CfgGUI\console.hpp"

// quick function launcher, developers only, use dev_variables.sqf ... F2 to activate
#include "CfgGUI\quickFunction.hpp"

// Code Editor ... ENTER to activate
#include "CfgGUI\editor.hpp"

// Variable Watcher ... CTRL + ENTER to activate
#include "CfgGUI\watcher.hpp"

// AtmosFEAR ... F5 to activate
#include "CfgGUI\atmosFEAR.hpp"

// ppEffects viewer ... F6 to activate
#include "CfgGUI\ppEffects.hpp"

class RscTitles {
	class Default //use to delete title resources
	{
		idd = -1;
		fadein = 0;
		fadeout = 0;
		duration = 0;
	};
	//default console, F2 to activate (Shift + F2 to make buttons active)
	#include "CfgGUI\console2.hpp"
	#include "CfgGUI\watcher2.hpp"
};

//+++++++++++++++++++++++++++++++++++++++++++++++++++++
// Dev functions init - do not edit, important!
//+++++++++++++++++++++++++++++++++++++++++++++++++++++
class devFunctions { //don't add fnc here, use appropriate pbo
	init = "x\Addons\rmx_init\functions.sqf";
	
	class rmx {
		class raymix_dialogs {
			file = "x\Addons\rmx_init\functions";
			class dialogVars {preInit = 1;recompile = 1;}; // vars
			class buffer {preInit = 1;};
			class eventHandlers {preInit = 1;};
			
			class getColorScheme{};
			class atmosFear {}; //Press F5 to toggle
			class atmosFearActions {};
			class atmosFearUpdate {};
			class ppViewer {}; //Press F6 to toggle
			class ppViewerUpdate {};
			class ppViewerEffects {};
			class ppViewerGetSet {};
			class console {}; //press F2 or shift + F2 to toggle
			class consoleFilters {};
			class consoleUpdate {};
			class quickFnc {}; //press F3 to toggle dialog
			class keyDown {recompile = 1;};
			class keyUp {};
			class output {};
			class codeEditor {recompile = 1;}; //press ENTER to toggle
			class codeEditorActions {recompile = 1;};
			class watcher {recompile = 1;}; //press CTRL + ENTER to toggle
			class watcherActions {recompile = 1;};
			class watcherAddRemove {recompile = 1;};
			class watcherRunner {recompile = 1;};
		};
	};
};
class cfgFunctions { //DO NOT EDIT BELOW
	class rmx {
		class rec {
			file = "x\Addons\rmx_init";
			class recompile {
				preInit = 1;
				postInit = 1;
			};
		};
	};
};
class RscStandardDisplay;
class RscDisplayStart: RscStandardDisplay
{
	onLoad = "[2] call compile preprocessfilelinenumbers gettext (configfile >> 'CfgFunctions' >> 'init'); call compile preprocessfilelinenumbers gettext (configfile >> 'devFunctions' >> 'init'); ['onLoad',_this,'RscDisplayLoading','Loading'] call (uinamespace getvariable 'BIS_fnc_initDisplay')";
};

