private["_index","_missionDesc"];
_index = lbCurSel 1500;
_missionDesc = getArray(missionConfigFile >> "MissionList" >> "traderMissionLongDesc"); 
ctrlSetText [1001, _missionDesc select _index];
