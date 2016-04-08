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
private["_index","_missionDesc"];
_index = lbCurSel 1500;
_missionDesc = getArray(getMissionConfig "MissionList" >> "traderMissionLongDesc");
ctrlSetText [1001, _missionDesc select _index];
