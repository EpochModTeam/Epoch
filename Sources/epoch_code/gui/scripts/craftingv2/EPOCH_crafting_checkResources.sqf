/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors:

	Description:
	DESC-TBA

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/scripts/craftingv2/EPOCH_crafting_checkResources.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_animSpeed","_cfg","_chck","_cnt","_color","_count","_countTxt","_ctrl","_display","_h","_img","_imgParsed","_ncCFrame","_ncCLB","_ncGroup","_ncRFrame","_ncRText","_nearbyArr","_out","_selection","_stText","_txt"];
//[[[end]]]
params [["_in",false,[true] ] ];

//Defines
_out = true;
_cfg = 'CfgCrafting' call EPOCH_returnConfig;
_selection = lbCurSel (rmx_var_crafting_ctrl_main select 0);
_nearbyArr = rmx_var_crafting_SearchConfigData select _selection select 8;

//check nearby resources only, requires false args
if !(_in) exitWith {
	if !(_nearbyArr isEqualTo []) then { //just to be safe
		{
			_out = _x call EPOCH_crafting_checkNearby;
			if !(_out) exitWith {};
		} forEach _nearbyArr;
	};
	_out
};

disableSerialization;
private ["_display","_ncGroup","_ncCFrame","_ncRFrame","_ncRText","_ncCLB"];
_display = findDisplay 77700;

if (isNil "rmx_var_crafting_ctrl_GROUP") then {
	rmx_var_crafting_ctrl_GROUP = [_display ctrlCreate ["rmx_rscControlsGroup",77821]];
} else {
	ctrlDelete (rmx_var_crafting_ctrl_GROUP select 0);
	rmx_var_crafting_ctrl_GROUP = [_display ctrlCreate ["rmx_rscControlsGroup",77821]];
};

_ncCFrame = rmx_var_crafting_ctrl_main select 3;
_ncRFrame = rmx_var_crafting_ctrl_main select 4;
_ncRText = rmx_var_crafting_ctrl_main select 5;
_ncCLB = rmx_var_crafting_ctrl_main select 1;
_ncGroup = rmx_var_crafting_ctrl_GROUP select 0;

if !(_nearbyArr isEqualTo []) then {
	_ncGroup ctrlShow true;
	_ncRFrame ctrlShow true;
	_ncRText ctrlShow true;

	private ["_chck","_color","_img","_imgParsed","_cnt","_countTxt","_txt","_stText","_count","_h","_animSpeed"];
	{
		private "_ctrl";
		_chck = _x call EPOCH_crafting_checkNearby;
		if !(_chck) then {_out = false};

		_color = if (_chck) then {"#00FF00"} else {"#FF0000"};

		_img = if (_x select 1 isEqualTo "") then {
			format ["\x\addons\a3_epoch_code\Data\UI\crafting\%1_%2.paa",(_x select 2),_chck]
		} else {
			format ["%1%2_%3",(_x select 1),(_x select 2),_chck]
		};

		_imgParsed = parseText format ["<t size='2'><img image='%1' /></t>",_img];

		_cnt = if ((_x select 5) < 1) then {1} else {_x select 5};
		_countTxt = if (_cnt isEqualTo 1) then {""} else {format ["%1x",_cnt]};
		_txt = parseText format ["<t size='1' color='%1'> %3 %2 %4m</t>",_color,(_x select 0),_countTxt,(_x select 4)];

		_stText = composeText [_imgParsed,_txt];

		_ctrl = _display ctrlCreate ["RscStructuredText", -(77800 + _forEachIndex),_ncGroup];
		_ctrl ctrlSetPosition [0,(0.08 * _forEachIndex),0.3,0.08];
		_ctrl ctrlCommit 0;
		_ctrl ctrlSetStructuredText _stText;
	} forEach _nearbyArr;

	_count = 8 min (count _nearbyArr); //maximum 8 of resources displayed
	_h = 0.08 * _count;
	_animSpeed = 0.2;

	[_ncGroup,	[0.3,1,0.3,0],				[0.3,(1-_h),0.3,_h],			_animSpeed]	call EPOCH_crafting_animate;
	[_ncCFrame,	[0.3,0,0.3,1], 				[0.3,0,0.3,(1-_h)],				_animSpeed] call EPOCH_crafting_animate;
	[_ncRFrame,	[0.3,1,0.3,0],				[0.3,(0.96-_h),0.3,(_h + 0.04)],_animSpeed] call EPOCH_crafting_animate;
	[_ncRText,	[0.3,0.96,0.3,0.04],		[0.3,(0.96-_h),0.3,0.04],		_animSpeed]	call EPOCH_crafting_animate;
	[_ncCLB,	[0.3,0.04,0.3,0.96],		[0.3,0.04,0.3,(0.96-_h)],		_animSpeed]	call EPOCH_crafting_animate;

} else {
	_ncGroup ctrlShow false;
	_ncRFrame ctrlShow false;
	_ncRText ctrlShow false;

	_ncCLB ctrlSetPosition [0.3,0.04,0.3,0.96];
	_ncCLB ctrlCommit 0;

	_ncCFrame ctrlSetPosition [0.3,0,0.3,1];
	_ncCFrame ctrlCommit 0;
};

_out
