//Variables
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
EPOCH_keysBuildMode1 = profileNamespace getVariable["EPOCH_BuildMode1", 2]; // 2 = 1
EPOCH_keysBuildMode2 = profileNamespace getVariable["EPOCH_BuildMode2", 3]; // 3 = 2
EPOCH_keysBuildDir = profileNamespace getVariable["EPOCH_BuildDir", 4]; // 4 = 3
EPOCH_keysBuildStatic = profileNamespace getVariable["EPOCH_BuildStatic", 5]; // 5 = 4
EPOCH_keysHolster = profileNamespace getVariable["EPOCH_Holster", 35]; // 35 = H
EPOCH_keysDebugMon = profileNamespace getVariable["EPOCH_DebugMon", 41]; // 41 = ~
EPOCH_keysBuildMovUp = profileNamespace getVariable["EPOCH_BuildMovUp", 0xC9]; // PgUp
EPOCH_keysBuildMovDn = profileNamespace getVariable["EPOCH_BuildMovDn", 0xD1]; // PgDown
EPOCH_keysBuildMovFwd = profileNamespace getVariable["EPOCH_BuildMovFwd", 0xC7]; // Home
EPOCH_keysBuildMovBak = profileNamespace getVariable["EPOCH_BuildMovBak", 0xCF]; // End
EPOCH_keysBuildMovL = profileNamespace getVariable["EPOCH_BuildMovL", 0xD2]; // Left
EPOCH_keysBuildMovR = profileNamespace getVariable["EPOCH_BuildMovR", 0xD3]; // Right
EPOCH_keysBuildRotL = profileNamespace getVariable["EPOCH_BuildRotL", 0x12]; // E
EPOCH_keysBuildRotR = profileNamespace getVariable["EPOCH_BuildRotR", 0x10]; // Q
EPOCH_keysBuildIt = profileNamespace getVariable["EPOCH_BuildIt", 0x39]; // Space
EPOCH_keysAcceptTrade = profileNamespace getVariable["EPOCH_AcceptTrade", 0x14]; // T

//ON INIT and RESPAWN
call EPOCH_clientInit;

[] execFSM "\x\addons\a3_epoch_code\system\SPVEH.fsm";
[] execFSM "\x\addons\a3_epoch_code\system\player_login.fsm";

true
