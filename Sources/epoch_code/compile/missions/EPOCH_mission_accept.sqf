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
private ["_missionTasks","_selectedMission","_simpleTask","_simpleTaskFSM","_simpleTaskSQF","_simpleTaskFNC","_taskNS","_itemCompile","_fnc_path","_path","_taskControl","_missionAllowed","_missionIndex","_plyrVar"];
_missionIndex = lbCurSel 1500;
_missionAllowed = true;
//systemChat format ["Mission Acepted: %1",_missionIndex];
_missionClasses = getArray(getMissionConfig "EpochMissionList" >> "traderMissionClasses");

_nrEnts = player nearEntities ["Man", 20];
_trader = objNull;
{
	if ((_x getVariable ["AI_SLOT", -1]) > -1) exitWith {
		_trader = _x;
	};
}forEach _nrEnts;

if !(isNull _trader) then {

_menuCondition = getText(getMissionConfig "epochMissions" >> (_missionClasses select _missionIndex) >> "missionDeny");
	if!(_menuCondition=="")then{
		if(call compile _menuCondition)then{_missionAllowed = false;};
	};


	if(_missionAllowed)then{
	_selectedMission = _missionClasses select _missionIndex;
	_missionTasks = getArray(getMissionConfig "epochMissions" >> _selectedMission >> "tasksList");

	_simpleTask = getNumber (getMissionConfig "inGameTasks" >> (_missionTasks select 0) >> "simpleTask");

	//systemChat format ["Simple Task: %1 | Mission: %2 from %3",_simpleTask,_selectedMission,_missionTasks];

		if(_simpleTask > 0)then{//Simple Task

		_simpleTaskFSM = getText (getMissionConfig "inGameTasks" >> (_missionTasks select 0) >> "initfsm");
		_simpleTaskSQF = getText (getMissionConfig "inGameTasks" >> (_missionTasks select 0) >> "initsqf");
		_simpleTaskFNC = getText (getMissionConfig "inGameTasks" >> (_missionTasks select 0) >> "initcall");

			if!(_simpleTaskSQF == "")then{//Compile and store SQF Function
			_tag = getText (getMissionConfig "CfgClientFunctions" >> "A3E" >> "tag");
			_path = getText (getMissionConfig "inGameTasks" >> "file");
			_taskNS = _tag + "_" + ((_simpleTaskSQF splitString ".") select 0);
			_fnc_path = _path + "\" +_simpleTaskSQF;

				if!((typeName _taskNS)=="CODE")then{
				_itemCompile = compileFinal preprocessFileLineNumbers _fnc_path;
				missionNamespace setvariable [_taskNS,_itemCompile];
				}else{
				_itemCompile = missionNamespace getVariable ["_taskNS",""];
				};

			//Emulating CfgClientFunctions - Is this required ?
			[] call _itemCompile;

			};

			if!(_simpleTaskFSM == "")then{
			_simpleTaskFSM = _path + "\" + _simpleTaskFSM;
			epochSimpleTaskHandle = [] execFSM _simpleTaskFSM;
			};

			if!(_simpleTaskFNC == "")then{
			call compile _simpleTaskFNC;
			};

		}else{//Run Task / Mission Monitor

			_doTask = (_missionTasks select 0);
			_allowTask = true;

			_plyrVar = missionNamespace getVariable ["EPOCH_playerMissionArray",[]] select {_x find "axeTask" > -1;};
			_uiNSTask = "";
			if(count _plyrVar > 0)then{
			_uiNSTask = _plyrVar select 0 select 1;
			};
			_miNSTask = missionNameSpace getVariable ["axeTask",""];

			//Allow continuation of mission from Cached Task
			if!(_uiNSTask == "")then{
				if(_miNSTask == "")then{
				_doTask = _uiNSTask;
				}else{
				_allowTask = false;
				[format ["Already on a mission - %1",selectRandom ['Chop Chop !','Get on With It !','What are you waiting for ?','No bonuses for tardiness !']], 5] call Epoch_message;
				};
			};

			if(_allowTask)then{
			epochTaskHandle = [_doTask] execFSM "epoch_code\System\task_control.fsm"
			};

		};

	}else{

	[format["Mission Not Allowed !",_menuCondition], 5] call Epoch_message; //Not formatting, is this intended?

	};


} else {
//systemChat format ["Trader Not Found",""];
["Trader Lost. Goodbye.", 5] call Epoch_message;
};
