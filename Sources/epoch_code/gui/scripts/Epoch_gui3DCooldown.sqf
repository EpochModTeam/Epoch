/*
	Attach a cooldown to a 3D world space that will be visible on a UI
	[_pos, _time, _distance, "myVariable"] call Epoch_gui3DCooldown;
	
	Position is a world position
	Time is time it takes for cooldown to do full animation
	Distance (optional) is used to exit cooldown if distance from player is greater than this value, default 10m
	
	Variable name is optional, but it allows you to remove cooldown externally:
		should be a global boolean
		must exist
		must be true
*/

_this spawn {
	private ["_error","_pos","_time","_distance","_bool","_display","_ctrlPos","_ctrlGrp","_ctrl","_partTime","_ct","_cl"];
	disableSerialization;
	params 
	[
		["_pos", false, [[]], 3],
		["_time", false, [0]],
		["_distance", 10, [0]],
		["_bool", "", [""]]
	];
	
	_error = "Wrong params, requires [position, time, distance (optional), variable name (bool, optional)]";
	
	if (typeName _pos isEqualTo "BOOL") exitWith {hint _error};
	if (typeName _time isEqualTo "BOOL") exitWith {hint _error};
	
	_display = findDisplay 46;
	_ctrlPos = [0.469062 * safezoneW + safezoneX, 0.445 * safezoneH + safezoneY, 0.061875 * safezoneW, 0.11 * safezoneH];

	_ctrlGrp = _display ctrlCreate ["RscControlsGroupNoScrollbars",call epoch_getIDC];
	_ctrlGrp ctrlSetPosition _ctrlPos;
	_ctrlGrp ctrlCommit 0;

	_id = call compile format 
	[
	"
		missionNamespace setVariable ['rmx_var_3DCD_temp%1',[_ctrlGrp, _distance, _pos]];
		_id = addMissionEventHandler ['Draw3D',{
			_arr = missionNamespace getVariable 'rmx_var_3DCD_temp%1';
			_scale = linearConversion [0, (_arr select 1), player distance (_arr select 2), 0, 1, false];
			(_arr select 0) ctrlSetPosition (worldToScreen (_arr select 2));
			(_arr select 0) ctrlSetFade _scale;
			(_arr select 0) ctrlCommit 0;
		}];
		[_id,'rmx_var_3DCD_temp%1']
	"
	,floor random 10000
	];
	
	_ctrl = [];
	for "_i" from 0 to 9 do {
		_ct = _display ctrlCreate ["RscPicture",call epoch_getIDC,_ctrlGrp];
		_ct ctrlSetText format ["x\addons\a3_epoch_code\Data\UI\cooldown\%1.paa",_i];
		_ct ctrlSetPosition [0.0375,0.05,(_ctrlPos select 2) / 2,(_ctrlPos select 3) / 2];
		_ct ctrlSetFade 1;
		_ct ctrlCommit 0;
		_ctrl set [_i,_ct];
	};
	
	_ctrl2 = _display ctrlCreate ["RscText",call epoch_getIDC,_ctrlGrp];
	_ctrl2 ctrlSetPosition [0.0375,0,_ctrlPos select 2,_ctrlPos select 3];
	_ctrl2 ctrlCommit 0;
	
	_partTime = _time / 10;
	_continue = true;
	_tock = diag_tickTime;
	
	for "_i" from 0 to 9 do {
		_cl = _ctrl select _i;
		_cl ctrlSetFade 0;
		_cl ctrlSetPosition [0,0,_ctrlPos select 2,_ctrlPos select 3];
		_cl ctrlCommit _partTime;
		
		_ctrl2 ctrlSetTextColor [1-(_i / 10),_i / 10,0,1];
		
		_tick = diag_tickTime;

		while {(diag_tickTime - _tick) < _partTime} do {
			if !(missionNamespace getVariable [_bool, true]) exitWith {_continue = false};
			if ((player distance _pos) > _distance) exitWith {_continue = false};
			_ctrl2 ctrlSetText ([1 + _time - (diag_tickTime - _tock),"MM:SS"] call BIS_fnc_secondsToString);
		};
		
		if !(_continue) exitWith {};
	};
	removeMissionEventHandler ["Draw3D", _id select 0];
	missionNamespace setVariable [_id select 1, nil];
	{
		_x call epoch_getIDC;
		ctrlDelete _x;
	} forEach _ctrl;
	
	_ctrl2 call epoch_getIDC;
	_ctrlGrp call epoch_getIDC;
	
	ctrlDelete _ctrl2;
	ctrlDelete _ctrlGrp;
};

true
