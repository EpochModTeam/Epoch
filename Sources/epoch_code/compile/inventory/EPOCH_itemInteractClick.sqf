/*
 Dynamic inventory sub menu
 By Aaron Clark - Epoch Mod
*/
//[[[cog import generate_private_arrays ]]]
private ["_CfgEpochClient","_Suppressed","_activeControl","_bg","_btn_arr","_buffer","_buttonTXT","_button_gen","_button_texts","_cfgItemInteractions","_config","_control","_data","_display","_interactActions","_interactOption","_magCount","_pos","_start_idc","_type","_y2d"];
//[[[end]]]
_button_texts = [];

_activeControl = uiNamespace getVariable ["EPOCH_active_button_control", controlNull];
if (!isNull _activeControl) then {
    _activeControl ctrlShow false;
    ctrlDelete _activeControl;
};

_this call EPOCH_selectInventoryItem;
_data = EPOCH_InteractedItem select 1;

_interactOption = 0;
_buttonTXT = "";
_magCount = 1;
_interactActions = [];
_config = (configfile >> "CfgWeapons" >> _data);
_CfgEpochClient = 'CfgEpochClient' call EPOCH_returnConfig;
_Suppressed = getarray (_CfgEpochClient >> "SuppressedCraftingItems");
// _cfgItemInteractions = (('CfgItemInteractions' call EPOCH_returnConfig) >> _data);
_cfgItemInteractions = ["CfgItemInteractions", _data] call EPOCH_returnConfigV2;
if (isClass (_config)) then {
    _type = getNumber (_config >> "type");
    _interactOption = getNumber (_cfgItemInteractions >> "interactAction");
    _buttonTXT = getText(_cfgItemInteractions >> "interactText");
    _interactActions = getArray(_cfgItemInteractions >> "interactActions");
} else {
	if (EPOCH_AdvancedVehicleRepair_Enabled && _data in ["VehicleRepair","VehicleRepairLg"]) exitwith {};
    _config = (configfile >> "CfgMagazines" >> _data);
    _type = getNumber (_config >> "type");
    _interactOption = getNumber (_cfgItemInteractions >> "interactAction");
    _buttonTXT = getText(_cfgItemInteractions >> "interactText");
    _magCount = getNumber (_config >> "count");
    _interactActions = getArray(_cfgItemInteractions >> "interactActions");
};

// legacy
if (_buttonTXT != "") then {
  _button_texts pushBack [_buttonTXT];
};
// additional interactActions
if !(_interactActions isEqualTo []) then {
    {
         _button_texts pushBack _x;
    } forEach _interactActions;
};
// ammo repack
if (_magCount > 1) then {
    _button_texts pushBack ["REPACK","[0] call EPOCH_consumeItem;"];
};

_config = 'CfgCrafting' call EPOCH_returnConfig;
if (isClass (_config >> _data) && !(_data in _Suppressed)) then {
	EPOCH_CraftingItem = EPOCH_InteractedItem select 0;
	_button_texts pushBack ["CRAFT","EPOCH_CraftingItem call EPOCH_crafting_load;"];
}
else {
	EPOCH_CraftingItem = "";
};

/* Moved to DynaMenu
_config = 'CfgVehicleUpgrades' call EPOCH_returnConfig;
if (isClass (_config >> _data)) then {
    {
        if (isclass (_config >> _data >> (typeof _x))) exitwith {
            EPOCH_UpgradeVehicle = [_data,_x];
            _reqMaterials = getArray (_config >> _data >> (typeof _x) >> "ReqMaterials");
            _itemtxt = "required: ";
            {
                _itemtxt = _itemtxt + str (_x select 0) + ((_x select 1) call EPOCH_itemDisplayName) + ", ";
            } foreach _reqMaterials;
            _txt1 = format ["Upgrade %1", (typeof _x) call EPOCH_itemDisplayName];
            _txt2 = "EPOCH_UpgradeVehicle call EPOCH_Client_UpgradeVehicle;";
            _button_texts pushBack [_txt1,_txt2];
        };
    } foreach (nearestobjects [player,["Landvehicle","SHIP","AIR","TANK"],10]);
};
*/

if !(_button_texts isEqualTo []) then {
    _display = ctrlParent (_this select 0);
    _pos = getMousePosition;

    _control = _display ctrlCreate ["RscControlsGroupNoScrollbars", 5678910];
    uiNamespace setVariable ["EPOCH_active_button_control", _control];

    _control ctrlSetPosition [(_pos select 0)-0.03,(_pos select 1)-0.03,1,1];
    _control ctrlCommit 0;

    _bg = _display ctrlCreate ["RscButtonTextOnly", 12349,_control];
    _bg ctrlSetPosition [0,0,1,1];
    _bg ctrlCommit 0;
    _bg ctrlAddEventHandler ["MouseEnter",{
        _activeControl = uiNamespace getVariable ["EPOCH_active_button_control", controlNull];
        if !(isNull _activeControl) then {
            _activeControl ctrlShow false;
        };
    }];

    _buffer = _display ctrlCreate ["RscButtonTextOnly", 12345,_control];
    _buffer ctrlSetPosition [0.02,0.02,0.25,0.0625 + (0.0625 * (count _button_texts))];
    _buffer ctrlAddEventHandler ["ButtonClick",{
        _activeControl = uiNamespace getVariable ["EPOCH_active_button_control", controlNull];
        if !(isNull _activeControl) then {
            _activeControl ctrlShow false;
        };
    }];

    _buffer ctrlCommit 0;

    _y2d = 0.06;
    _btn_arr = [];
    _start_idc = 12346;
    {
        _x params [["_btn_text","EXAMINE"],["_btn_code","[] call EPOCH_consumeItem;"]];
        _button_gen = _display ctrlCreate ["RscButtonMenu", _start_idc,_control];
        _start_idc = _start_idc + 1;
        _button_gen ctrlSetPosition [0.06,_y2d,0.20,0.06];
        _button_gen ctrlSetText _btn_text;
        _button_gen ctrlCommit 0;
        _button_gen ctrlSetEventHandler ["ButtonClick",_btn_code + "(uiNamespace getVariable [""EPOCH_active_button_control"", controlNull]) ctrlShow false;"];
        _y2d = _y2d + 0.0625;
        _btn_arr pushBack _button_gen;
    } forEach _button_texts;

    reverse _btn_arr;
    uiNamespace setVariable ["EPOCH_active_controls", ([_control,_bg,_buffer] + _btn_arr) ];
    // uiNamespace setVariable ["EPOCH_active_buttons", _btn_arr ];
    {ctrlSetFocus _x} forEach (uiNamespace getVariable ["EPOCH_active_controls", []]);
};
