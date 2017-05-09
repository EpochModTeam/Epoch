class inGameTasks {
	
	//Preset custom vars for use in task conditions - Count must match
	//At task start the varNames variables will be added as missionNameSpace variables using the corresponding varData.
	varName[] = {"_milBuildings","_testVar"};
	varData[] = {{"Cargo_HQ_base_F","Cargo_Tower_base_F","Cargo_Patrol_base_F"},"""TestVal"""};
	
	//Filter out building classes from spawn areas. Some buildings just aren't suitable. NB. A garrison (buildingPos) point is required when spawning items in a building.
	filterBuilds[] = {"Land_i_Addon_03_V1_F","Land_Offices_01_V1_F"};
	
	//Path to task files (sqf,fsm etc.)
	file = "epoch_code\compile\missions\tasks";
	//Path to main task control fsm - NB. Requires manually setting in mission accept sqf.
	fsmpath = "epoch_code\system";

#include "CfgMissions\CfgTraderDiags.hpp"
#include "CfgMissions\CfgmissionDelivery.hpp"
#include "CfgMissions\CfgmissionUav.hpp"
#include "CfgMissions\CfgmissionMilitary.hpp"
#include "CfgMissions\CfgmissionMonster.hpp"
#include "CfgMissions\CfgmissionFish.hpp"
};