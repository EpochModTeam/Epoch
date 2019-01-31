class e_pad_config
{
	LoadVarsFromProfile[] = {													// Variables, that will be loaded from profile on connect
		{"EPOCH_AutoEarplug","true"},
		{"EPOCH_debugMode","false"},
		{"EPOCH_PlayerMarkerOn","false"},
		{"EPOCH_DeathMarkerOn","false"},
		{"EPOCH_EpadButtonOn","true"}
	};
	class Apps
	{
/*
		class FullExample
		{
			ButtonText = "app10";												// Static Button Text
			ButtonTextCode = "if (true) then {'Text'} else {''}";				// Variable Button Text - will overwrite static Button Text, if defined
			Description = "";													// Static Description Text
			DescriptionCode = "if (true) then {'Desctription'} else {''}";		// Variable Description Text - will overwrite static Description Text, if defined
			Icon = "";															// Static Icon on Button
			IconCode = "if (true) then {'addons\MyIcon.paa'} else {''}";		// Variable Icon - will overwrite static Icon, if defined
			color[] = {1,1,1,1};												// default color for Icon / Button text
			colortoggled[] = {0,1,0,1};											// Icon / Button color if toggleable and variable is toggled (true)
			html = "epoch_code\customs\E_Pad\ServerInfos.html";					// Path to a html-file (if defined or not "", the action will only load this web site into the e-pad)
			action = "";														// code to run on button click
			Tooltip = "PLACE-HOLDER";											// Static Tooltip
			TooltipCode = "if (true) then {'My ToolTip'} else {''}";			// Variable Tooltip - will overwrite static Tooltip, if defined
			ToggleVar = "";														// Script will check this variable. If true, Button is toggled and color change to "colortoggled"
			ToggleAble = "false";												// if "true", the defined variable will be toggled (and saved to profile) on buttonclick
			class SubMenu {														// If a Sub-Menu is defined, on Buttonclick, a new submenu will be opened with defined classes here
				ButtonText = "app10";
				ButtonTextCode = "if (true) then {'Text'} else {''}";
				Description = "";
				DescriptionCode = "if (true) then {'Desctription'} else {''}";
				Icon = "";
				IconCode = "if (true) then {'addons\MyIcon.paa'} else {''}";
				color[] = {1,1,1,1};
				colortoggled[] = {0,1,0,1};
				html = "epoch_code\customs\E_Pad\ServerInfos.html";
				action = "";
				Tooltip = "PLACE-HOLDER";
				TooltipCode = "if (true) then {'My ToolTip'} else {''}";
				ToggleVar = "";
				ToggleAble = "false";
			};
		};
*/
		class settings
		{
			ButtonText = "";
			Description = "Settings";
			icon = "x\addons\a3_epoch_code\Data\UI\epad\settings_ca.paa";
			color[] = {1,1,0,1};
			colortoggled[] = {0,1,0,1};
			action = "";
			Tooltip = "Settings";
			ToggleVar = "";
			ToggleAble = "false";
			class EpadButton {
				ButtonText = "";
				Description = "Epad Dyna";
				icon = "x\addons\a3_epoch_code\Data\UI\epad\epoch_tablet_back.paa";
				color[] = {1,0,0,1};
				colortoggled[] = {0,1,0,1};
				action = "";
				Tooltip = "Add / Remove E-Pad Button from DynaMenu (you can still open it with F10)";
				ToggleVar = "EPOCH_EpadButtonOn";
				ToggleAble = "true";
			};
			class playerMarker
			{
				ButtonText = "";
				Description = "Playermarker";
				icon = "x\addons\a3_epoch_code\Data\UI\epad\gps.paa";
				color[] = {1,0,0,1};
				colortoggled[] = {0,1,0,1};
				action = "if (!EPOCH_PlayerMarkerOn) then {if !('ItemGPS' in (assignedItems player)) then {['You need a GPS to see your Position',5] call epoch_message}}";
				tooltip = "Toggle player marker";
				ToggleVar = "EPOCH_PlayerMarkerOn";
				ToggleAble = "true";
			};
			class deathMarker
			{
				ButtonText = "";
				Description = "DeathMarker";
				icon = "x\addons\a3_epoch_code\Data\UI\epad\skull.paa";
				color[] = {1,0,0,1};
				colortoggled[] = {0,1,0,1};
				action = "if (!EPOCH_DeathMarkerOn) then {if ((profileNameSpace getVariable ['EPOCHLastKnownDeath',[]]) isequalto []) then {['You had no GPS on last death',5] call epoch_message}}";
				tooltip = "Toggle death marker";
				ToggleVar = "EPOCH_DeathMarkerOn";
				ToggleAble = "true";
			};
			class blockedMarker
			{
				ButtonText = "";
				Description = "Blocked Areas";
				icon = "x\addons\a3_epoch_code\Data\UI\epad\blocked.paa";
				color[] = {1,0,0,1};
				colortoggled[] = {0,1,0,1};
				action = "call compile preprocessfilelinenumbers 'epoch_code\customs\E_Pad\BlockedAreas.sqf'";
				tooltip = "Show / Hide blocked areas on the map";
				ToggleVar = "Epoch_BlockedMarkeron";
				ToggleAble = "true";
			};
			class Earplug {
				ButtonText = "";
				Description = "Auto-Earplugs";
				icon = "x\addons\a3_epoch_code\Data\UI\epad\Earplugs.paa";
				color[] = {1,0,0,1};
				colortoggled[] = {0,1,0,1};
				action = "";
				Tooltip = "Toggle Auto-Earplugs";
				ToggleVar = "EPOCH_AutoEarplug";
				ToggleAble = "true";
			};
			class Reset {
				ButtonText = "Reset";
				Description = "Reset Settings";
				Icon = "";
				color[] = {1,1,0,1};
				colortoggled[] = {0,1,0,1};
				action = "[] spawn {_confirm = ['Reset all E-Pad Settings? Sure?','WARNING!',true,true] call BIS_fnc_guiMessage; if (_confirm) then {call Epoch_EPad_Reset; [] call EPOCH_EPad_dialog}}";
				Tooltip = "Reset all settings";
				ToggleVar = "";
				ToggleAble = "false";
			};
/*
			class SubSub {
				ButtonText = "SubMenu";
				Description = "Sub Menu";
				Icon = "";
				color[] = {1,1,1,1};
				colortoggled[] = {0,1,0,1};
				action = "";
				Tooltip = "Open Sub-Sub Menu";
				ToggleVar = "";
				ToggleAble = "false";
				class SubSub1 {
					ButtonText = "SubSub1";
					Description = "Sub Sub Menu";
					Icon = "";
					color[] = {1,1,1,1};
					colortoggled[] = {0,1,0,1};
					action = "";
					Tooltip = "App in SubSub Menu";
					ToggleVar = "";
					ToggleAble = "false";
				};
			};
*/
		};
		class infos
		{
			ButtonText = "";
			Description = "Infos";
			icon = "x\addons\a3_epoch_code\Data\UI\epad\server_info_icon_ca.paa";
			color[] = {1,1,1,1};
			colortoggled[] = {0,1,0,1};
			action = "";
			Tooltip = "Info-Menu";
			ToggleVar = "";
			ToggleAble = "false";
			class contact
			{
				ButtonText = "";
				Description = "Contact";
				icon = "x\addons\a3_epoch_code\Data\UI\epad\Contact1.paa";
				color[] = {1,1,1,1};
				colortoggled[] = {0,1,0,1};
				html = "epoch_code\customs\E_Pad\ServerContacts.html";
				action = "";
				Tooltip = "COntact us";
				ToggleVar = "";
				ToggleAble = "false";
			};
			class serverinfo
			{
				ButtonText = "";
				Description = "Server Info";
				icon = "x\addons\a3_epoch_code\Data\UI\epad\info.paa";
				color[] = {1,1,1,1};
				colortoggled[] = {0,1,0,1};
				html = "epoch_code\customs\E_Pad\ServerInfos.html";
				action = "";
				Tooltip = "Display Server Infos";
				ToggleVar = "";
				ToggleAble = "false";
			};
			class serversettings
			{
				ButtonText = "";
				Description = "Server Settings";
				icon = "x\addons\a3_epoch_code\Data\UI\epad\seversettings.paa";
				color[] = {1,1,1,1};
				colortoggled[] = {0,1,0,1};
				html = "epoch_code\customs\E_Pad\ServerSettings.html";
				action = "";
				Tooltip = "Display Server Settings";
				ToggleVar = "";
				ToggleAble = "false";
			};
			class serverrules
			{
				ButtonText = "";
				Description = "Server Rules";
				icon = "x\addons\a3_epoch_code\Data\UI\epad\Rules.paa";
				color[] = {1,1,1,1};
				colortoggled[] = {0,1,0,1};
				html = "epoch_code\customs\E_Pad\ServerRules.html";
				action = "createDialog 'server_info_picture'";
				Tooltip = "Display Server Rules";
				ToggleVar = "";
				ToggleAble = "false";
			};
		};
		class debug
		{
			ButtonText = "";
			Description = "Debug";
			icon = "x\addons\a3_epoch_code\Data\UI\epad\debug_ca.paa";
			color[] = {1,0,0,1};
			colortoggled[] = {0,1,0,1};
			action = "if !(EPOCH_debugMode) then {['Debug Mode Enabled', 5,[[0,0,0,0.5],[1,1,0,1]]] call Epoch_message;} else {['Debug Mode Disabled', 5,[[0,0,0,0.5],[1,1,0,1]]] call Epoch_message;hintSilent ''};";
			Tooltip = "DebugMonitor";
			ToggleVar = "EPOCH_debugMode";
			ToggleAble = "true";
		};
		class reviveable
		{
			ButtonText = "";
			Description = "Reviveable?";
			icon = "x\addons\a3_epoch_code\Data\UI\epad\Reviveable.paa";
			color[] = {1,0,0,1};
			colortoggled[] = {0,1,0,1};
			action = "";
			Tooltipcode = "if (Epoch_canBeRevived) then {'Reviveable: true'} else {'Reviveable: false'}";
			ToggleVar = "Epoch_canBeRevived";
			ToggleAble = "false";
		};
		class news
		{
			ButtonText = "News";
			Description = "Tips";
			Icon = "";
			color[] = {1,1,1,1};
			colortoggled[] = {0,1,0,1};
			action = "call compile preprocessfilelinenumbers 'epoch_code\customs\E_Pad\traderDiag_news.sqf'";
			Tooltip = "News";
			ToggleVar = "";
			ToggleAble = "false";
		};
		class vehs
		{
			ButtonText = "Vehicle";
			Description = "Near Vehicle";
			Icon = "";
			color[] = {1,1,1,1};
			colortoggled[] = {0,1,0,1};
			action = "[250,1000] call compile preprocessfilelinenumbers 'epoch_code\customs\E_Pad\traderDiag_nearVehicles.sqf'";
			Tooltip = "Scan for near Vehicles (costs 250 energy)";
			ToggleVar = "";
			ToggleAble = "false";
		};
		class players
		{
			ButtonText = "Player";
			Description = "Near Player";
			Icon = "";
			color[] = {1,1,1,1};
			colortoggled[] = {0,1,0,1};
			action = "[250,250] call compile preprocessfilelinenumbers 'epoch_code\customs\E_Pad\traderDiag_nearPlayers.sqf'";
			Tooltip = "Scan for near Players (costs 250 energy)";
			ToggleVar = "";
			ToggleAble = "false";
		};
		class suicide
		{
			ButtonText = "";
			Description = "Kill yourself";
			icon = "x\addons\a3_epoch_code\Data\UI\epad\suicide.paa";
			color[] = {1,1,1,1};
			colortoggled[] = {0,1,0,1};
			action = "[] spawn {_confirm = ['Are you sure to kill yourself?','Suicide!',true,true] call BIS_fnc_guiMessage;if (_confirm) then {while {dialog} do {closedialog 0};disableUserInput true;Player playAction 'GestureSuicide';uisleep 3;Player setdamage 1;disableUserInput false;};};";
			Tooltip = "Kill yourself to respawn";
			ToggleVar = "";
			ToggleAble = "false";
		};
	};
};