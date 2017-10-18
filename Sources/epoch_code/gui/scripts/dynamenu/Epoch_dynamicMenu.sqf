/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors: He-Man

	Description:
	DESC-TBA

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/scripts/dynamenu/Epoch_dynamicMenu.sqf
*/
disableSerialization;
//[[[cog import generate_private_arrays ]]]
private ["_iconcode","_action","_arr","_buttonSettings","_c","_cfg","_checkConfigs","_config","_configs","_dName","_display","_entries","_hasTarget","_icon","_in","_selfOrTarget","_subclasses","_tTip","_tooltip","_tooltipcode","_x"];
//[[[end]]]
_in = [_this, 0, "",[""]] call BIS_fnc_param;

_display = findDisplay 66600;
_cfg = "CfgActionMenu" call EPOCH_returnConfig;
_arr = [];
_buttonSettings = [];

/** Variable Defines **/
{
	call compile (format ["%1 = %2;",configName _x,getText _x]);
} count (configProperties [(_cfg >> "variableDefines"),"true",false]);

_hasTarget = !(dyna_cursorTarget isEqualTo objNull);

if (isNull _display && dialog) exitWith {false call Epoch_dynamicMenuCleanup; false};

if (isNull _display) then {
	if!(visibleMap)then{
		if (_hasTarget) then {
			createDialog "rmx_dynamenu";
		} else {
			findDisplay 46 createDisplay "rmx_dynamenu";
		}
	} else {
		findDisplay 12 createDisplay "rmx_dynamenu";
	};
};

_selfOrTarget = if!(visibleMap)then{ if !(_hasTarget) then {"self"} else {"target"} } else {"map"};
_checkConfigs = {

	_config = switch (_in) do {
		case "build_upgrade":
		{
			_cfg = "CfgBaseBuilding" call EPOCH_returnConfig;
			(_cfg >> dyna_cursorTargetType)
		};
		case "":
		{
			(_cfg >> _selfOrTarget)
		};
		default
		{
			_c = format ["_cfg >> '%1'",_selfOrTarget];
			_arr = _this;
			{
				_c = _c + (format [" >> '%1'",_x]);
			} forEach _arr;

			(call compile _c)
		};
	};

	switch (_in) do {
		case "build_upgrade":
		{
			if !(isClass _config) exitWith {_in = "";};

			{
				_dName = getText(configfile >> "CfgVehicles" >> (_x select 0) >> "DisplayName");
				_tTip = "";
				_icon = "";
				{
					if !(_x isEqualType []) then {_x = [_x, 1]};
					_c = configfile >> "CfgMagazines" >> (_x select 0);
					_tTip = _tTip + format ["[%1 x %2] ", _x select 1, getText(_c >> "DisplayName")];
					if (_icon isEqualTo "") then {_icon = getText (_c >> "picture")};
				} forEach (_x select 1);

				_tooltip = format ["%1 >> %2 ",_dName,_tTip];
				_action = format ["[dyna_cursorTarget,%1] call EPOCH_upgradeBUILD; true call Epoch_dynamicMenuCleanup;",_forEachIndex];

				_buttonSettings pushBack [
					_icon,
					_tooltip,
					_action
				];

			} forEach (getArray (_config >> "upgradeBuilding"));


		};
		default
		{
			_configs = "true" configClasses _config;
			{
				if (call compile (getText(_x >> "condition"))) then {

					if (_selfOrTarget in ["self","map"] || dyna_distance) then {

						_subclasses = configProperties [_x, "isClass _x",true];

						_action = if (_subclasses isEqualTo []) then {
							format ["%1; true call Epoch_dynamicMenuCleanup;",getText(_x >> "action")]
						} else {
							format ["%2 %1 call Epoch_dynamicMenu;",_arr + [(configName _x)],getText(_x >> "action")]
						};

						_tooltip = "";
						_tooltipcode = getText(_x >> "tooltipcode");
						if (_tooltipcode != "") then {
							_tooltip = [] call compile _tooltipcode;
						}
						else {
							_tooltip = getText(_x >> "tooltip");
						};
						
						_icon = "";
						_iconcode = getText(_x >> "iconcode");
						if (_iconcode != "") then {
							_icon = [] call compile _iconcode;
						}
						else {
							_icon = getText(_x >> "icon");
						};
						if (!(_icon isequaltype "") || _icon isequalto "") then {
							_icon = "x\addons\a3_epoch_code\Data\UI\buttons\player_inspect.paa";
						};

						_buttonSettings pushBack [
							_icon,
							_tooltip,
							_action
						];

					};
				};
			} forEach _configs;
		};
	};
};

call _checkConfigs;
if (_buttonSettings isEqualTo []) then {_selfOrTarget = if!(visibleMap)then{"self"}else{"map"}; call _checkConfigs;};

_entries = count _buttonSettings;
if !(_entries <= 0) then {
	[_entries, _buttonSettings] spawn epoch_dynamicMenuPopulate;
} else {
	true call Epoch_dynamicMenuCleanup;
};

true
