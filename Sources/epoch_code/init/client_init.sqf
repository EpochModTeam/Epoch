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
EPOCH_lastTrash = diag_tickTime;
EPOCH_tradeDone = false;
EPOCH_bankBalance = 0;
EPOCH_antiWallCount = 0;
EPOCH_lastTargetTime = diag_tickTime;
EPOCH_arr_countdown = [];
EP_light = objNull;
EPOCH_p2ptradeTarget = objNull;
EPOCH_Holstered = "";
Epoch_invited_GroupUID = "";
Epoch_invited_GroupName = "";
Epoch_invited_GroupUIDs = [];
Epoch_invited_GroupUIDsPrev = [];
Epoch_my_Group = [];
Epoch_invited_tempGroupUID = "";
Epoch_invited_tempGroupName = "";
Epoch_invited_tempGroupUIDs = [];
Epoch_invited_tempGroupUIDsPrev = [];
Epoch_my_tempGroup = [];
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
EPOCH_IsAutoRunning = false;
EPOCH_Earplugsin = false;
EPOCH_LastAutoRunKeyPressed = diag_ticktime;
EPOCH_PlayerMarkerOn = false;
EPOCH_DeathMarkerOn = false;

//Radiation
EPOCH_geiger_shown = false;
EPOCH_geiger_mute_counter = true;
EPOCH_geiger_mute_warning = true;
EPOCH_ambientRadiation = 0; //TODO: needs to go server side. Adds constant incremental radiation to all players. Use in special events.

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
EPOCH_maxBuildingHeight = ["CfgEpochClient", "maxBuildingHeight", 100] call EPOCH_fnc_returnConfigEntryV2;
EPOCH_MaxBuildingTilt = ["CfgEpochClient", "MaxBuildingTilt", 180] call EPOCH_fnc_returnConfigEntryV2;
Epoch_NuisanceMulti = ["CfgEpochClient", "NuisanceMulti", 0.5] call EPOCH_fnc_returnConfigEntryV2;

// Use Eventhandler "Fired" on Reviver instead of Eventhandler "HandeDamage" on Client to be revived for Heal / Revive Player
EPOCH_OldRevive = ["CfgEpochClient", "UseOldRevive", false] call EPOCH_fnc_returnConfigEntryV2;

//ON INIT and RESPAWN
call EPOCH_clientInit;

[] execFSM "epoch_code\system\player_login.fsm";

if (isclass (configFile >> "CfgPatches" >> "ace_common")) then {
	if (["CfgEpochClient", "DisableDoorInteractForACE", true] call EPOCH_fnc_returnConfigEntryV2) then {
		[] spawn {
			private _start = diag_ticktime;
			waituntil {!isnil "MACRO_DOOR_REACH_DISTANCE" || diag_ticktime - _start > 90};
			MACRO_DOOR_REACH_DISTANCE = -1;
		};
	};
};

true
