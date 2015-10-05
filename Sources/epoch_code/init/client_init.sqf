//Variables
EPOCH_CraftingItem = "";
EPOCH_ESP_TARGETS = [];
EPOCH_ESPMAP_TARGETS = [];
EPOCH_ESPGROUPS = [];
EPOCH_ESPGROUPCOLORS = [];
EPOCH_ESP_PLAYER = false;
EPOCH_ESP_VEHICLES = false;
EPOCH_ESP_VEHICLEPLAYER = [];
EPOCH_group_level_img = ["x\addons\a3_epoch_code\data\owner.paa", "x\addons\a3_epoch_code\data\mod.paa", "x\addons\a3_epoch_code\data\member.paa"];
if (isNil 'EPOCH_diag_fps') then {
	EPOCH_diag_fps = 0;
};
EPOCH_lastTrash = diag_tickTime;
EPOCH_tradeDone = false;
EPOCH_bankBalance = 0;
EPOCH_antiWallCount = 0;
EPOCH_lastTargetTime = diag_tickTime;
EPOCH_lastSave = diag_tickTime;
EPOCH_arr_countdown = [];
EP_light = objNull;
EPOCH_p2ptradeTarget = objNull;
EPOCH_lastPlayerPos = getPosATL player;
EPOCH_Holstered = "";
Epoch_invited_GroupUID = "";
Epoch_invited_GroupName = "";
Epoch_invited_GroupUIDs = [];
Epoch_invited_GroupUIDsPrev = [];
EPOCH_lastPlayerPos = [0,0,0];
EPOCH_prevOffer = [];
EPOCH_drawIcon3d = false;
EPOCH_velTransform = false;
EPOCH_stabilityTarget = objNull;
EPOCH_currentVehicle = objNull;
EPOCH_currentTarget = objNull;
EPOCH_LootedBlds = [];
EPOCH_soundLevel = 1;
EPOCH_arr_interactedObjs = [];
EPOCH_buildOption = 0;
EPOCH_nearestLocations = [];
onEachFrame EPOCH_onEachFrame;

EPOCH_LastAirDrop = time;
EPOCH_AirDropCheck = getNumber(missionConfigFile >> "CfgEpochAirDrop" >> "AirDropFreq");
if(EPOCH_AirDropCheck < 120)then{EPOCH_AirDropCheck = 120;};
EPOCH_AirDropChance = getNumber(missionConfigFile >> "CfgEpochAirDrop" >> "AirDropChance");
if(EPOCH_AirDropChance < 0)then{EPOCH_AirDropChance = 101;EPOCH_AirDropCheck = 99999;};

EPOCH_droneRndChance = 100;

// Custom Keys
0 call EPOCH_clientKeyMap;

//ON INIT and RESPAWN
call EPOCH_clientInit;

[] execFSM "\x\addons\a3_epoch_code\system\SPVEH.fsm";
[] execFSM "\x\addons\a3_epoch_code\system\player_login.fsm";

true
