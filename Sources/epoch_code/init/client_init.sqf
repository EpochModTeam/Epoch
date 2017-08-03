/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Initalize variables used client side and start login FSM

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/init/client_init.sqf
*/
EPOCH_Vehicle_MaintainLock = false;
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
EPOCH_playerIsSwimming = false;
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
Epoch_my_Group = [];
EPOCH_lastPlayerPos = [0,0,0];
EPOCH_prevOffer = [];
EPOCH_drawIcon3d = false;
EPOCH_velTransform = false;
EPOCH_stabilityTarget = objNull;
EPOCH_currentTarget = objNull;
EPOCH_currentTargetMode = 0;
EPOCH_LootedBlds = [];
EPOCH_lootObjects = [];
EPOCH_soundLevel = 1;
EPOCH_arr_interactedObjs = [];
EPOCH_buildOption = 0;
EPOCH_nearestLocations = [];
EPOCH_lastFiredLocation = [];

rmx_var_drag_MouseDown = false;
rmx_var_dynamicHUD_groups = [];
rmx_var_dynamicHUD_groupCTRL = [];

//Favorites bar
EPOCH_favBar_itemConsumed = false;
rmx_var_favBar_Item = "";
EPOCH_modKeys = [false,false,false];

["EPOCH_onEachFrame", "onEachFrame", EPOCH_onEachFrame] call BIS_fnc_addStackedEventHandler;

// Custom Keys
EPOCH_keysActionPressed = false; //prevents EH spam
0 call EPOCH_clientKeyMap;

// load some frequently used configs to variables
private _CfgEpochClient = 'CfgEpochClient' call EPOCH_returnConfig;
EPOCH_maxBuildingHeight = getNumber(_CfgEpochClient >> "maxBuildingHeight");

//ON INIT and RESPAWN
call EPOCH_clientInit;

[] execFSM "epoch_code\system\SPVEH.fsm";
[] execFSM "epoch_code\system\player_login.fsm";

//Start processing right after Loading screen is done and game has started
[] spawn {
	waitUntil {!isNull (findDisplay 46) && (!isNil "EPOCH_loadingScreenDone")};
	'load' call epoch_favBar_draw;
};


true
