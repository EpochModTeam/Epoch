/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors:

	Description:
	Creates special dialog that allows players to reposition (move) all HUD groups on the screen and save to profile

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/scripts/dynamicHUD/Epoch_dynamicHUD_adjust.sqf
*/
_this spawn {
	disableSerialization;
	(findDisplay 49) closeDisplay 0;
	
	waitUntil {isNull (findDisplay 49)};
	
	if (_this) then {
		findDisplay 46 createDisplay "rmx_moveDynamicHUD";
		_dsp = findDisplay 66666;
		rmx_var_dynamicHUD_groupsAdjust = [];
		rmx_var_drag_MouseDown = false;
		{
			_c = _dsp ctrlCreate ["rmx_drag_RscActivePicture", call epoch_getIDC];
			_c ctrlSetText "#(rgb,8,8,3)color(1,1,1,1)";
			_c ctrlSetPosition (ctrlPosition _x);
			_c ctrlCommit 0;
			rmx_var_dynamicHUD_groupsAdjust set [_forEachIndex, _c];
		} forEach rmx_var_dynamicHUD_groups;

		waitUntil {!isNull (findDisplay 66666)};
		while {!isNull (findDisplay 66666)} do {
			if !(rmx_var_drag_MouseDown) then {
				{
					_c = (rmx_var_dynamicHUD_groups select _forEachIndex);
					_c ctrlSetPosition (ctrlPosition _x);
					_c ctrlCommit 0;
				} forEach rmx_var_dynamicHUD_groupsAdjust;
			};
			uiSleep 0.1;
		};
	} else {
		//reset hud positions
	};
};

true
