class traderDiagTime{
author = "axeman";
title = "Trader Time";
//Simple task will skip all monitoring and run the provided code (call, fsm, sqf) only.
simpleTask = 1;
initsqf = "epoch_code\compile\missions\tasks\traderDiag_timePlease.sqf";
initfsm = "";
initcall = "";
//Next task is allowed to trigger a task if required.
nextTask[] = {};
};

class traderDiagNearby{
author = "axeman";
title = "Trader Near By Players";
simpleTask = 1;
initsqf = "epoch_code\compile\missions\tasks\traderDiag_nearPlayers.sqf";
initfsm = "";
initcall = "";
nextTask[] = {};
};

class traderDiagNews{
author = "axeman";
title = "Trader News";
simpleTask = 1;
initsqf = "epoch_code\compile\missions\tasks\traderDiag_news.sqf";
initfsm = "";
initcall = "";
nextTask[] = {};
};

class traderDiagName{
author = "axeman";
title = "Traders Name";
simpleTask = 1;
initsqf = "epoch_code\compile\missions\tasks\traderDiag_name.sqf";
initfsm = "";
initcall = "";
nextTask[] = {};
};

class traderNearVehicles{
author = "axeman";
title = "Trader Nearby Vehicles";
simpleTask = 1;
initsqf = "epoch_code\compile\missions\tasks\traderDiag_nearVehicles.sqf";
initfsm = "";
initcall = "";
nextTask[] = {};
};

class traderTriggerAirDrop{
author = "axeman";
title = "Trigger AirDrop";
simpleTask = 1;
initsqf = "epoch_code\compile\missions\tasks\traderDiag_triggerAirDrop.sqf";
initfsm = "";
initcall = "";
nextTask[] = {};
};

class traderMissionReset{
author = "axeman";
title = "Reset Missions";
simpleTask = 1;
initsqf = "epoch_code\compile\missions\tasks\traderDebug_resetMissions.sqf";
initfsm = "";
initcall = "";
nextTask[] = {};
};