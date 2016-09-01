/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors:

	Description:
	DESC-TBA

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/scripts/config/Epoch_config_keymap.sqf

    Example:
    _this call Epoch_config_keymap;
*/
//[[[cog import generate_private_arrays ]]]
private ["_arr","_ctrl","_ctrlCurrent","_ctrlDefault","_ctrlEdit","_data","_default","_display","_idx","_input","_lb","_new","_old","_txt","_txtCurrent","_txtDefault","_var"];
//[[[end]]]
params ["_ctrl"];

_display = if (typeName _ctrl isEqualTo "CONTROL") then {ctrlParent _ctrl} else {displayNull};
_input = if (_ctrl isEqualType "STRING") then {_ctrl} else {str _ctrl};

switch (_input) do {
	default {diag_log format ["[Epoch_config_keymap] Wrong params: %1",_this]};

	case "load":
	{
		private ["_ctrl","_arr","_idx"];
		_ctrl = (findDisplay 49) displayCtrl 78008;

		_arr = 2 call EPOCH_clientKeyMap;

		{
			_idx = _ctrl lbAdd (_x select 0);
			_ctrl lbSetTooltip [_idx, _x select 0];
			_ctrl lbSetData [_idx, _x select 1];
		} forEach _arr;

		_ctrl lbSetCurSel 0;

	};
	case "Control #78008": //lb
	{
		private ["_ctrlDefault","_ctrlCurrent","_ctrlEdit","_arr","_var","_default","_txtDefault","_txtCurrent"];
		params ["_lb","_idx"];

		_ctrlDefault = _display displayCtrl 78006;
		_ctrlCurrent = _display displayCtrl 78007;
		_ctrlEdit = _display displayCtrl 78009;

		_ctrlEdit ctrlSetText "";

		_arr = 2 call EPOCH_clientKeyMap;
		_var = _arr select _idx select 1;
		_default = _arr select _idx select 2;

		_txtDefault = _default call BIS_fnc_keyCode;
		_ctrlDefault ctrlSetText format ["Default: [%1]",_txtDefault];

		_txtCurrent = (missionNamespace getVariable _var) call BIS_fnc_keyCode;
		_ctrlCurrent ctrlSetText format ["Current: [%1]",_txtCurrent];
	};
	case "Control #78009": //edit
	{
		private ["_edit","_key","_shift","_ctrl","_alt","_txt"];
		params ["_edit","_key","_shift","_ctrl","_alt"];

		if !(_shift || _ctrl || _alt) then { //blacklisted modifiers
			if !(_key in [29,42,54,56,157,184,219]) then { //blacklisted keys
				_txt = _key call BIS_fnc_keyCode;
				_edit ctrlSetText _txt;
			};
		} else {
			_edit ctrlSetText "";
		};
	};
	case "Control #78010": //save
	{
		private ["_ctrlEdit","_lb","_new","_idx","_data"];
		_ctrlEdit = _display displayCtrl 78009;
		_lb = _display displayCtrl 78008;

		_new = ctrlText _ctrlEdit;

		_idx = lbCurSel _lb;
		_data = _lb lbData _idx;

		if !(_new isEqualTo "") then {
			missionNamespace setVariable [_data, _new call BIS_fnc_keyCode];
			profileNamespace setVariable [_data, _new call BIS_fnc_keyCode];
			_lb lbSetCurSel _idx;
		} else {
			_ctrlEdit ctrlSetText "Empty field";
		};
	};
	case "Control #78011": //reset
	{
		private ["_ctrlEdit","_lb","_idx","_data","_arr","_old"];
		_ctrlEdit = _display displayCtrl 78009;
		_lb = _display displayCtrl 78008;

		_idx = lbCurSel _lb;
		_data = _lb lbData _idx;

		_arr = 2 call EPOCH_clientKeyMap;
		_old = _arr select _idx select 2;

		missionNamespace setVariable [_data, _old];
		profileNamespace setVariable [_data, _old];

		_lb lbSetCurSel _idx;
	};
	case "Control #78012": //reset all
	{
		private ["_lb","_idx"];
		1 call EPOCH_clientKeyMap;
		0 call EPOCH_clientKeyMap;
		_lb = _display displayCtrl 78008;
		_idx = lbCurSel _lb;
		_lb lbSetCurSel _idx;
	};
};

true
