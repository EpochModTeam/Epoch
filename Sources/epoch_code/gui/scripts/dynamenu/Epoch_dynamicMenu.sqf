/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors:

	Description:
	DESC-TBA

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_code/gui/scripts/dynamenu/Epoch_dynamicMenu.sqf
*/
disableSerialization;
private ["_selfOrTarget","_display","_cfg","_arr","_buttonSettings","_hasTarget","_checkConfigs","_entries"];
params [["_in","",[""]]];

_display = findDisplay 66600;
_cfg = "CfgActionMenu" call EPOCH_returnConfig;
_arr = [];
_buttonSettings = [];

/** Variable Defines **/
{
	call compile (format ["%1 = %2;",configName _x,getText _x]);
} count (configProperties [(_cfg >> "variableDefines"),"true",false]);

_hasTarget = !(dyna_cursorTarget isEqualTo objNull);

if (isNull _display && dialog) exitWith {call Epoch_dynamicMenuCleanup; false};

if (isNull _display) then {
	if (_hasTarget) then {
		createDialog "rmx_dynamenu";
	} else {
		findDisplay 46 createDisplay "rmx_dynamenu";
	};
};

_selfOrTarget = if !(_hasTarget) then {"self"} else {"target"};
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

					if (_selfOrTarget isEqualTo "self" || dyna_distance) then {

						_subclasses = configProperties [_x, "isClass _x",true];

						_action = if (_subclasses isEqualTo []) then {
							format ["%1; true call Epoch_dynamicMenuCleanup;",getText(_x >> "action")]
						} else {
							format ["%2 %1 call Epoch_dynamicMenu;",_arr + [(configName _x)],getText(_x >> "action")]
						};

						_buttonSettings pushBack [
							getText(_x >> "icon"),
							getText(_x >> "tooltip"),
							_action
						];
					};
				};
			} forEach _configs;
		};
	};
};

call _checkConfigs;
if (_buttonSettings isEqualTo []) then {_selfOrTarget = "self"; call _checkConfigs;};

_entries = count _buttonSettings;
if !(_entries <= 0) then {
	[_entries, _buttonSettings] call epoch_dynamicMenuPopulate;
} else {
	true call Epoch_dynamicMenuCleanup;
};

true
