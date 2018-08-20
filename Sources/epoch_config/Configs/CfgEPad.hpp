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
			action = "";														// code to run on button click
			Tooltip = "PLACE-HOLDER";											// Static Tooltip
			TooltipCode = "if (true) then {'My ToolTip'} else {''}";			// Variable Tooltip - will overwrite static Tooltip, if defined
			ToggleVar = "";														// Script will check this variable. If true, Button is toggled and color change to "colortoggled"
			ToggleAble = "false";												// if "true", the defined variable will be toggled (and saved to profile) on buttonclick
			class SubMenu {														// On Buttonclick, a new submenu will be opened with defined classes here
				...
				...
			}
		};
*/
		class settings
		{
			ButtonText = "";
			Description = "Settings";
			Icon = "epoch_code\customs\images\settings_ca.paa";
			color[] = {1,1,0,1};
			colortoggled[] = {0,1,0,1};
			action = "";
			Tooltip = "Settings";
			ToggleVar = "";
			ToggleAble = "false";
			class EpadButton {
				ButtonText = "";
				Description = "Epad Dyna";
				Icon = "epoch_code\customs\images\epoch_tablet_back.paa";
				color[] = {1,0,0,1};
				colortoggled[] = {0,1,0,1};
				action = "";
				Tooltip = "Add / Remove E-Pad Button from DynaMenu (you can still open it with F10)";
				ToggleVar = "EPOCH_EpadButtonOn";
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
			class playerMarker
			{
				ButtonText = "";
				Description = "Playermarker";
				icon = "epoch_code\customs\images\gps.paa";
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
				icon = "epoch_code\customs\images\skull.paa";
				color[] = {1,0,0,1};
				colortoggled[] = {0,1,0,1};
				action = "if (!EPOCH_DeathMarkerOn) then {if ((profileNameSpace getVariable ['EPOCHLastKnownDeath',[]]) isequalto []) then {['You had no GPS on last death',5] call epoch_message}}";
				tooltip = "Toggle death marker";
				ToggleVar = "EPOCH_DeathMarkerOn";
				ToggleAble = "true";
			};
			class Earplug {
				ButtonText = "";
				Description = "Auto-Earplugs";
				icon = "epoch_code\customs\images\Earplugs.paa";
				color[] = {1,0,0,1};
				colortoggled[] = {0,1,0,1};
				action = "";
				Tooltip = "Toggle Auto-Earplugs";
				ToggleVar = "EPOCH_AutoEarplug";
				ToggleAble = "true";
			};
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
		};
		class info
		{
			ButtonText = "";
			Description = "Server Info";
			Icon = "epoch_code\customs\images\server_info_icon_ca.paa";
			color[] = {1,1,1,1};
			colortoggled[] = {0,1,0,1};
			action = "createDialog 'server_info_picture'";
			Tooltip = "Display server Info";
			ToggleVar = "";
			ToggleAble = "false";
		};
		class debug
		{
			ButtonText = "";
			Description = "Debug";
			Icon = "epoch_code\customs\images\debug_ca.paa";
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
			Icon = "epoch_code\customs\images\Reviveable.paa";
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
			action = "call compile preprocessfilelinenumbers ""epoch_code\gui\scripts\e_pad\Apps\traderDiag_news.sqf""";
			Tooltip = "News";
			ToggleVar = "";
			ToggleAble = "false";
		};
		class web
		{
			ButtonText = "WEB";
			Description = "Web links";
			Icon = "";
			color[] = {1,1,1,1};
			colortoggled[] = {0,1,0,1};
			action = "call compile preprocessfilelinenumbers ""epoch_code\gui\scripts\e_pad\Apps\web.sqf""";
			Tooltip = "WEB LINK";
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
			action = "[250,1000] call compile preprocessfilelinenumbers ""epoch_code\gui\scripts\e_pad\Apps\traderDiag_nearVehicles.sqf""";
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
			action = "[250,250] call compile preprocessfilelinenumbers ""epoch_code\gui\scripts\e_pad\Apps\traderDiag_nearPlayers.sqf""";
			Tooltip = "Scan for near Players (costs 250 energy)";
			ToggleVar = "";
			ToggleAble = "false";
		};
	};
};