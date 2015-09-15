private ["_bar","_uniformArmor","_totalArmor","_finalArmor","_vestArmor","_headgearArmor","_bar_pos","_bar_compare","_color","_colorCompare","_display","_totalArmorMax"];
disableSerialization;

EPOCH_InteractedItem = [];

if (isNil "EPOCH_MAX_ARMOR") then {
    call EPOCH_maxArmorInit;
};

EPOCH_lastContainer = _this select 1;

waitUntil {!isNull findDisplay 602};
_display = (findDisplay 602);

{(_display displayCtrl _x) ctrlEnable false} forEach [-13,-14];

_totalArmor = 0;
_totalArmorMax = EPOCH_MAX_ARMOR select 3;

_color = [0.6,0.6,0.6,1];
_colorCompare = [0.4,0.6,1,0.4];

_bar = _display displayCtrl 7304;
uiNameSpace setVariable ["RscCustomProgressUniform", _bar];
_bar ctrlSetTextColor _color;

_bar = _display displayCtrl 7305;
uiNameSpace setVariable ["RscCustomProgressVest", _bar];
_bar ctrlSetTextColor _color;

_bar = _display displayCtrl 7240;
uiNameSpace setVariable ["RscCustomProgressHeadgear", _bar];
_bar ctrlSetTextColor _color;

_bar = _display displayCtrl 7308;
_bar ctrlSetTextColor _color;

_bar_compare = _display displayCtrl 7309;
_bar_compare ctrlSetTextColor _colorCompare;

uiNameSpace setVariable ["RscCustomProgressTotal", [_bar,_bar_compare]];

0 call EPOCH_refeshUI;
