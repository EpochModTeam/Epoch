/*
	Author: Andrew Gregory - EpochMod.com

    Contributors: Aaron Clark - EpochMod.com

	Description:
	Handle mission select from trader menu

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/missions/EPOCH_mission_accept.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_epochmissionsconfig","_inGameTasksconfig","_menuCondition","_missionAllowed","_missionClasses","_missionIndex","_missionTasks","_missionname","_msg","_newtask","_nexttask","_nrEnts","_selectedMission","_simpleTask","_taskCall","_taskSQF","_taskname","_trader"];
//[[[end]]]
_missionIndex = lbCurSel 1500;
_missionAllowed = true;
_missionClasses = getArray(getMissionConfig "EpochMissionList" >> "traderMissionClasses");

_nrEnts = player nearEntities ["Man", 20];
_trader = objNull;
{
	if ((_x getVariable ["AI_SLOT", -1]) > -1) exitWith {
		_trader = _x;
	};
}forEach _nrEnts;

if !(isNull _trader) then {
	_selectedMission = _missionClasses select _missionIndex;
	_epochmissionsconfig = getMissionConfig "epochMissions";
	_menuCondition = getText (_epochmissionsconfig >> _selectedMission >> "missionDeny");
	if!(_menuCondition == "")then{
		if(call compile _menuCondition) then {
			_missionAllowed = false;
		};
	};
	if(_missionAllowed)then{
		_missionTasks = getArray (_epochmissionsconfig >> _selectedMission >> "tasksList");
		_missionname = getText (_epochmissionsconfig >> _selectedMission >> "missionName");
		_inGameTasksconfig = getMissionConfig "inGameTasks";
		_taskname = _missionTasks select 0;
		_simpleTask = getNumber (_inGameTasksconfig >> _taskname >> "simpleTask");

		if (_selectedMission isequalto "debugResetMission") exitwith {
			EPOCH_ResetTraderMission = true;
		};
		if !(EPOCH_ActiveTraderMission isequalto []) exitwith {
			EPOCH_ActiveTraderMission params ['','',['_missionname','ERROR']];
			_msg = format ['You are already running %1. Finish or cancel it first',_missionname];
			[_msg, 5] call Epoch_message;
		};

		if (_simpleTask > 0) then {	//Simple Task
			_taskSQF = getText ( _inGameTasksconfig >> _taskName >> "initsqf");
			if !(_taskSQF isequalto '') then {
				call compile format ["[_taskName,player,_unit,_taskItem] execVM ""%1""",_taskSQF];
			};
			_taskCall = getText ( _inGameTasksconfig >> _taskName >> "initcall");
			if !(_taskCall isequalto '') then {
				call compile _taskCall
			};
			_nexttask = getArray ( _inGameTasksconfig >> _taskName >> "nextTask");
			if !(_nexttask isequalto []) then {
				_newtask = selectrandom _nexttask;
				EPOCH_mission_startTime = diag_ticktime;
				EPOCH_ActiveTraderMission = [_inGameTasksconfig,_newtask,_missionname];
			};
		}
		else {
			EPOCH_mission_startTime = diag_ticktime;
			EPOCH_ActiveTraderMission = [_inGameTasksconfig,_taskname,_missionname];
		};
		["TraderMissions",1,true] call EPOCH_client_updatePlayerStat;
	}
	else {
		[format["Mission Not Allowed !",_menuCondition], 5] call Epoch_message; //Not formatting, is this intended?
	};
}
else {
	["Trader Lost. Goodbye.", 5] call Epoch_message;
};
