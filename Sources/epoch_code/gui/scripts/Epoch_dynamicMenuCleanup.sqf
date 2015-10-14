_test = param [1,0];
if (_test != 57) exitWith {true}; //dirty fix, TODO: read values from epoch startup vars for key

_this spawn {
	if !(isNil "rmx_var_dynamicMenuInProgress") exitWith {};
	_args = param [0,false,[false]]; //true if redirected with category, false for full cleanup
	
	 if (_args) then {rmx_var_dynamicMenuHOLD = true;} else {rmx_var_dynamicMenuHOLD = nil; rmx_var_dynamicMenuCat = nil;};

	disableSerialization;
	private "_animSpeed";
	_animSpeed = 0.1;
	{
		_x ctrlSetPosition [0.4625,0.45,0.075,0.1];
		_x ctrlSetFade 1;
		_x ctrlCommit _animSpeed;
	} forEach rmx_var_controls;
	
	[rmx_var_dynamenuPPHandle, _animSpeed, [0]] call epoch_postprocessAdjust;
	
	uiSleep _animSpeed;

	findDisplay 66600 closeDisplay 1;

	rmx_var_controls = nil;
	
	rmx_var_dynamenuPPHandle call epoch_postprocessDestroy;
	rmx_var_dynamenuPPHandle = nil;
};

true
