/*
	Function Name:			rmx_fnc_dev_quickFnc
	Author:					Raimonds Virtoss | Raymix
	Description:			Function quick-launch dialog
*/
private ["_display","_diag","_listBox"];
disableSerialization;

switch (rmx_var_quickFncEnabled) do {
	case false: 
		{
			_diag = createDialog "dUI_quickFunction";
			_display = findDisplay 9400;
			_listBox = _display displayCtrl 9403;
			_editBox = _display displayCtrl 9404;
			_listBox ctrlSetEventHandler ["LBDblClick","_editBox = ctrlText (findDisplay 9400 displayCtrl 9404); _fnc = ((_this select 0) lbData (_this select 1)); systemChat _fnc; call compile (_editBox + ' ' + _fnc);"];
			_editBox ctrlSetText (profileNamespace getVariable ["rmx_var_quickFnc_editBox","Params"]);
			
			{
				_idx = _listBox lbAdd (_x select 1);
				_listBox lbSetColor [_idx,(_x select 0)];
				_listBox lbSetData [_idx,(_x select 2)];
				_listBox lbSetTooltip [_idx,(_x select 2)];
			} count rmx_var_quickFnc_items;
			
			rmx_var_quickFncEnabled = true;
		};
	case true:
		{
			profileNamespace setVariable ["rmx_var_quickFnc_editBox",ctrlText (findDisplay 9400 displayCtrl 9404)];
			closeDialog 0;
			rmx_var_quickFncEnabled = false;
		};
};
