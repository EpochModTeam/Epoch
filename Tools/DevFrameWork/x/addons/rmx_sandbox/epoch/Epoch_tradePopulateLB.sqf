params ["_trigger", ["_category", "All"]];

switch _trigger do {
	case "left":
	{
		
	};
	case "right":
	{
		_cfg = [];
		
		if (_category isEqualTo "All") then {
			{
				if (configName _x in rmx_var_traderCategories) then {
					_cfg pushBack _x;
				};
			} forEach rmx_var_RCatConfigs;
		
		} else {
			{
				if (getText (_x >> "displayName") isEqualTo _category) exitWith {_cfg = [_x]};
			} forEach rmx_var_RCatConfigs;
		};
		
		_rLB = rmx_var_tradeCtrls select 7;
		lbClear _rLB;
		{
			_items = "true" configClasses _x;
			{
				_itemData = [(configName _x),["displayName", "picture"]] call epoch_itemData;
				if !(_itemData isEqualTo [""]) then {
					_idx = _rLB lbAdd (_itemData select 0);
					_rLB lbSetPicture [_idx,(_itemData select 1)];
				};
			} forEach _items;
			
		} forEach _cfg;
		_rLB lbSetCurSel 0;
	//call LB sorting from here (plus make EH and fnc itself)
	};
	case "log":
	{
		
	};
};