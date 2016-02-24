_missionList = getArray(missionConfigFile >> "MissionList" >> "traderMissionNames");
_disabledMissions = getArray(missionConfigFile >> "MissionList" >> "traderMissionDisabled");

{
	if !(_forEachIndex in _disabledMissions) then {
		_index = lbAdd[1500, _x];
		lbSetValue[1500, _index, _forEachIndex];
	};
}forEach _missionList;
