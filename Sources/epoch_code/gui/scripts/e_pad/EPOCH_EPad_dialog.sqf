disableSerialization;
if (isnull (finddisplay 9898)) exitwith {};
_display = finddisplay 9898;
call EPOCH_EPad_clearscreen;

params [["_in",""],["_animate",false]];
_cfg = "e_pad_config" call EPOCH_returnConfig;
_arr = [];
_buttonSettings = [];

_config = switch (_in) do {
	case "":
	{
		(_cfg >> "Apps")
	};
	default
	{
		_c = format ["_cfg >> '%1'","Apps"];
		_arr = _in;
		{
			_c = _c + (format [" >> '%1'",_x]);
		} forEach _arr;

		(call compile _c)
	};
};
_configs = "true" configClasses _config;
for "_i" from ((Epoch_E_Pad_Page-1)*13) to (((count _configs)-1) min (((Epoch_E_Pad_Page-1)*13)+12)) do {
	_configx = _configs select _i;
	_subclasses = configProperties [_configx, "isClass _x",true];
	_action = format ["%1;",getText(_configx >> "action")];
	_togglevar = getText(_configx >> "ToggleVar");
	if !(_subclasses isEqualTo []) then {
		_action = _action + format ["Epoch_E_Pad_Page = 1; [%1] call EPOCH_EPad_dialog", _arr + [(configName _configx)]];
	}
	else {
		if (tolower (getText(_configx >> "ToggleAble")) isequalto "true") then {
			if !(_togglevar isequalto "") then {
				_action = _action + format ["%1 = %2; ['Epoch_ToggleVars','%1',%2] call Epoch_SaveVarsToProfile; [%3] call EPOCH_EPad_dialog",_togglevar,!(missionnamespace getvariable [format ["%1",_togglevar],false]),_arr];
			};
		};
	};

	_ButtonText = "";
	_ButtonTextcode = getText(_configx >> "ButtonTextCode");
	if (_ButtonTextcode != "") then {_ButtonText = call compile _ButtonTextcode;} else {_ButtonText = getText(_configx >> "ButtonText");};
	if !(_ButtonText isequaltype "") then {_ButtonText = ""};

	_Description = "";
	_DescriptionCode = getText(_configx >> "DescriptionCode");
	if (_DescriptionCode != "") then {_Description = call compile _DescriptionCode;} else {	_Description = getText(_configx >> "Description");};
	if !(_Description isequaltype "") then {_Description = ""};

	_tooltip = "";
	_tooltipcode = getText(_configx >> "tooltipcode");
	if (_tooltipcode != "") then {_tooltip = call compile _tooltipcode;} else {_tooltip = getText(_configx >> "tooltip");};
	if !(_tooltip isequaltype "") then {_tooltip = ""};

	_icon = "";
	_iconcode = getText(_configx >> "iconcode");
	if (_iconcode != "") then {_icon = call compile _iconcode;} else {_icon = getText(_configx >> "icon");};
	if !(_icon isequaltype "") then {_icon = ""};

	_color = [1,1,1,1];
	_cfgcolor = getarray(_configx >> "color");
	if (!(_cfgcolor isequalto []) && count _cfgcolor == 4) then {_color = _cfgcolor;};

	_colortoggled = [0,1,0,1];
	_cfgcolortoggled = getarray(_configx >> "colortoggled");
	if (!(_cfgcolortoggled isequalto []) && count _cfgcolortoggled == 4) then {_colortoggled = _cfgcolortoggled;};

	_buttonSettings pushBack [
		_ButtonText,
		_tooltip,
		_action,
		_togglevar,
		_icon,
		_color,
		_colortoggled,
		_Description
	];
};

_entries = count _buttonSettings;
if (_entries <= 0) exitwith {};
for "_i" from 0 to (_entries - 1) do {
	(_buttonSettings select _i) params ["_ButtonText","_tooltip","_action","_togglevar","_icon","_color","_colortoggled","_Description"];
	private ["_ctrl","_ctrl2"];
	_ctrl = _display displayctrl (_i+1601);
	_ctrl2 = _display displayctrl (_i+1701);
	_ctrl3 = _display displayctrl (_i+1801);
	_ctrl ctrlShow true;
	_ctrl ctrlSetText _ButtonText;
	_ctrl ctrlSetEventHandler ["mouseButtonDown", _action];
	_ctrl ctrlEnable !(_action isequalto ";");
	if !(_togglevar isequalto "") then {
		_toggled = missionnamespace getvariable [format ["%1",_togglevar],false];
		if (_toggled) then {
			_ctrl ctrlsettextcolor _colortoggled;
			_ctrl2 ctrlsettextcolor _colortoggled;
		}
		else {
			_ctrl ctrlsettextcolor _color;
			_ctrl2 ctrlsettextcolor _color;
		};
	}
	else {
		_ctrl ctrlsettextcolor _color;
		_ctrl2 ctrlsettextcolor _color;
	};
	if !(_icon isequalto "") then {
		_ctrl2 ctrlShow true;
		_ctrl2 ctrlSetText _icon;
	};
	_ctrl ctrlSetTooltip _tooltip;
	_ctrl2 ctrlSetTooltip _tooltip;
	_ctrl3 ctrlShow true;
	_ctrl3 ctrlSetText _Description;
	if (_animate) then {
		{
			_pos = ctrlposition (_display displayCtrl _x);
			_display displayCtrl _x ctrlSetposition [0.5 * safezoneW + safezoneX, 0.599027 * safezoneH + safezoneY, 0, 0];
			_display displayCtrl _x ctrlcommit 0;
			_display displayCtrl _x ctrlSetposition _pos;
			_display displayCtrl _x ctrlcommit 0.5;
		} foreach [_i+1601,_i+1701,_i+1801];
	};
};

{
	(_display displayctrl _x) ctrlshow true;
} foreach [1614,1615,1714,1715];
if (Epoch_E_Pad_Page > 1) then {
	(_display displayctrl 1614) ctrlenable true;
	(_display displayctrl 1614) ctrlSetEventHandler ["mouseButtonDown",format ["Epoch_E_Pad_Page = Epoch_E_Pad_Page - 1; [%1] call EPOCH_EPad_dialog",_arr]];
	(_display displayctrl 1714) ctrlsettextcolor [1,1,1,1];
}
else {
	(_display displayctrl 1614) ctrlenable false;
	(_display displayctrl 1714) ctrlsettextcolor [1,1,1,0.5];
};
if ((count _configs) > (((Epoch_E_Pad_Page-1)*13)+12)) then {
	(_display displayctrl 1615) ctrlenable true;
	(_display displayctrl 1615) ctrlSetEventHandler ["mouseButtonDown",format ["Epoch_E_Pad_Page = Epoch_E_Pad_Page + 1; [%1] call EPOCH_EPad_dialog",_arr]];
	(_display displayctrl 1715) ctrlsettextcolor [1,1,1,1];
}
else {
	(_display displayctrl 1615) ctrlenable false;
	(_display displayctrl 1715) ctrlsettextcolor [1,1,1,0.5];
};
if (_animate) then {
	{
		_pos = ctrlposition (_display displayCtrl _x);
		_display displayCtrl _x ctrlSetposition [0.5 * safezoneW + safezoneX, 0.599027 * safezoneH + safezoneY, 0, 0];
		_display displayCtrl _x ctrlcommit 0;
		_display displayCtrl _x ctrlSetposition _pos;
		_display displayCtrl _x ctrlcommit 0.5;
	} foreach [1614,1615,1714,1715];
};
ctrlSetFocus (_display displayctrl 1599);
