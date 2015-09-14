_missionList = getArray(configfile >> "MissionList" >> "traderMissionNames");
_disabledMissions = getArray(configfile >> "MissionList" >> "traderMissionDisabled");

{
	if !(_forEachIndex in _disabledMissions) then {
		_index = lbAdd[1500, _x];
		lbSetValue[1500, _index, _forEachIndex];
	};
}forEach _missionList;