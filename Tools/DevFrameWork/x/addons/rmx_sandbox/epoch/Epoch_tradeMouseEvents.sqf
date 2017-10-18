params ["_trigger", "_event",["_category", "All"]];
disableSerialization;

switch _trigger do {
	case "left":
	{
		_leftBG = rmx_var_tradeCtrls select 2;
		switch _event do {
			case "enter": 
			{
				_leftBG ctrlSetPosition [-0.2,0,0.2,1.06];
				_leftBG ctrlCommit 0.1;
				
				{
					_temp = ctrlPosition (_x select 0);
					_temp set [0, 0];
					_temp set [2, 0.2];
					(_x select 0) ctrlSetPosition _temp;
					(_x select 0) ctrlCommit 0.1;
					
					_temp = ctrlPosition (_x select 1);
					_temp set [0, 0.01];
					(_x select 1) ctrlSetPosition _temp;
					(_x select 1) ctrlCommit 0.1;
					
					(_x select 2) ctrlSetFade 0;
					(_x select 2) ctrlCommit 0.3;
				} forEach rmx_var_traderLeftMenuCTRLs;
				
			};
			case "exit": 
			{
				_leftBG ctrlSetPosition [-0.06,0,0.06,1.06];
				_leftBG ctrlCommit 0.1;
				
				{
					_temp = ctrlPosition (_x select 0);
					_temp set [0, 0.14];
					_temp set [2, 0.06];
					(_x select 0) ctrlSetPosition _temp;
					(_x select 0) ctrlCommit 0.1;
					
					_temp = ctrlPosition (_x select 1);
					_temp set [0, 0.15];
					(_x select 1) ctrlSetPosition _temp;
					(_x select 1) ctrlCommit 0.1;
					
					(_x select 2) ctrlSetFade 1;
					(_x select 2) ctrlCommit 0;
				} forEach rmx_var_traderLeftMenuCTRLs;
			};
			case "click":
			{
				[_trigger,_category] call Epoch_tradePopulateLB;
			};
		};
	};
	case "right":
	{
		_rightBG = rmx_var_tradeCtrls select 3;
		switch _event do {
			case "enter": 
			{
				_rightBG ctrlSetPosition [1,0,0.2,1.06];
				_rightBG ctrlCommit 0.1;
				
				{
					_temp = ctrlPosition (_x select 0);
					_temp set [2, 0.2];
					(_x select 0) ctrlSetPosition _temp;
					(_x select 0) ctrlCommit 0.1;
					
					_temp = ctrlPosition (_x select 1);
					_temp set [0, 0.15];
					(_x select 1) ctrlSetPosition _temp;
					(_x select 1) ctrlCommit 0.1;
					
					(_x select 2) ctrlSetFade 0;
					(_x select 2) ctrlCommit 0.3;
				} forEach rmx_var_traderRightMenuCTRLs;
				
				ctrlSetFocus (rmx_var_traderGroupCTRLs select 1);
			};
			case "exit": 
			{
				_rightBG ctrlSetPosition [1,0,0.06,1.06];
				_rightBG ctrlCommit 0.1;
				
				{
					_temp = ctrlPosition (_x select 0);
					_temp set [2, 0.06];
					(_x select 0) ctrlSetPosition _temp;
					(_x select 0) ctrlCommit 0.1;
					
					_temp = ctrlPosition (_x select 1);
					_temp set [0, 0.01];
					(_x select 1) ctrlSetPosition _temp;
					(_x select 1) ctrlCommit 0.1;
					
					(_x select 2) ctrlSetFade 1;
					(_x select 2) ctrlCommit 0;
				} forEach rmx_var_traderRightMenuCTRLs;
			};
			case "click":
			{
				[_trigger,_category] call Epoch_tradePopulateLB;
			};
		};
	};
	case "btn":
	{
		switch _event do {
			case "close": {systemChat "Close";};
			case "trade": {systemChat "Trade";};
		};
	};
};

true
