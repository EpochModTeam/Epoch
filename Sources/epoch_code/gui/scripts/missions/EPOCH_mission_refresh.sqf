/*
	Author: Andrew Gregory - EpochMod.com

    Contributors: Aaron Clark

	Description:
	TODO: Description

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_code/gui/scripts/missions/EPOCH_mission_refresh.sqf
*/
private ["_index","_missionList","_disabledMissions"];
_missionList = getArray(getMissionConfig "MissionList" >> "traderMissionNames");
_disabledMissions = getArray(getMissionConfig "MissionList" >> "traderMissionDisabled");
{
	if !(_forEachIndex in _disabledMissions) then {
		_index = lbAdd[1500, _x];
		lbSetValue[1500, _index, _forEachIndex];
	};
}forEach _missionList;
