/*
	Author: Andrew Gregory - EpochMod.com

    Contributors: Aaron Clark

	Description:
	Loads trader menu with available missions from config. Applies conditions and tooltips.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/scripts/missions/EPOCH_mission_refresh.sqf
*/
private ["_lbl","_missionClasses","_missionName","_menuCondition","_toolTip","_uiNSTask"];
params [["_currentTask",""]];
_missionClasses = getArray(getMissionConfig "EpochMissionList" >> "traderMissionClasses");
_uiNSTask = "";
if (count EPOCH_ActiveTraderMission > 0) then {
	_uiNSTask = EPOCH_ActiveTraderMission select 1;
};
{
	_missionName = getText(getMissionConfig "epochMissions" >> _x >> "missionName");
	if!(_missionName == "")then{
		_lbl = lbAdd[1500, _missionName];
		lbSetValue[1500, _lbl, _forEachIndex];
		_toolTip = getText(getMissionConfig "epochMissions" >> _x >> "missionToolTip");
		_menuCondition = getText(getMissionConfig "epochMissions" >> _x >> "missionDeny");
		if!(_menuCondition=="")then{
			if(call compile _menuCondition)then{
			lbSetColor [1500, _lbl, [0.73,0.24,0.11,1] ] ;
			_toolTip = getText(getMissionConfig "epochMissions" >> _x >> "missionDenyToolTip");
			};
		};
		if(_uiNSTask in getArray(getMissionConfig "epochMissions" >> _x >> "tasksList"))then{
			lbSetColor [1500, _lbl, [0.98,0.98,0.33,1]] ;
			_toolTip = "CONTINUE - " + _toolTip;
		};
		lbSetTooltip [1500, _lbl, _toolTip];
	};
}forEach _missionClasses;
