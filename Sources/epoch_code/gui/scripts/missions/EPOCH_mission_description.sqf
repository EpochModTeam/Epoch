/*
	Author: Andrew Gregory - EpochMod.com

    Contributors: Aaron Clark

	Description:
	Reload trader menu description, from config, when mission is clicked on. Filter out disabled missions.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/gui/scripts/missions/EPOCH_mission_refresh.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_index","_menuCondition","_missionClasses","_missionDesc"];
//[[[end]]]
_missionClasses = getArray(getMissionConfig "EpochMissionList" >> "traderMissionClasses");

_index = lbCurSel 1500;

_menuCondition = getText(getMissionConfig "epochMissions" >> (_missionClasses select _index) >> "missionDeny");
_missionDesc = getText(getMissionConfig "epochMissions" >> (_missionClasses select _index) >> "missionDesc");

if!(_menuCondition=="")then{
	if(call compile _menuCondition)then{
	_missionDesc = "NOT AVAILABLE - " + _missionDesc;
	lbSetColor [1001, 0, [0.73,0.24,0.11,1] ] ;
	};
};

ctrlSetText [1001, _missionDesc];
