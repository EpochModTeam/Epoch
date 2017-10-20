/*
	Authors: Aaron Clark - EpochMod.com
			 Niklas Wagner - skaronator.com
    Contributors:

	Description:
    Arma 3 Epoch ANTIHACK/ADMINTOOL

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/init/server_securityfunctions.sqf
*/
private ["_code","_functionName","_remoteExecClientStr","_onLoad","_onUnload","_skn_blockedSpawnMenuUID","_temp","_skn_adminMenuOwner","_case","_skn_adminMenuHigh","_skn_adminMenuLow","_config","_debugClass","_cfg_systemDebug","_skn_systemDebug1","_skn_systemDebug2","_skn_systemDebug3","_skn_systemDebug4","_skn_systemDebug5","_cfg_remoteExecClient","_remoteExecClient_NAMES","_cfg_limits","_skn_playerCryptoLimit","_cfg_learning","_skn_trustedUsers","_str_learningModeCheck","_cfg_quality","_skn_perfMode","_skn_viewDistance","_skn_viewDistanceObects","_skn_terrainGrid","_cfg_blacklistConfig","_skn_badDisplaysArray","_skn_badAnimations","_cfg_variablesConfig","_skn_badVarCheckArray","_skn_nilVarCheckArray","_skn_commandMenuArray","_skn_addEHConfig","_skn_displayAddEHChecks","_skn_addEHArray","_serverSettingsConfig","_skn_enableAntihack","_skn_check_addons","_checkFiles","_skn_check_files","_skn_whitelist_cfgPatches","_skn_adminsOwner","_skn_adminsHigh","_skn_adminsLow","_banReasons","_skn_banReason","_antihack_banDuration","_epoch_banReasons","_kickReasons","_epoch_kickReason","_epoch_kickReasons","_ownerSettings","_skn_adminMenuOwnerSetting","_adminSettings","_skn_adminMenuHighSetting","_lowSettings","_skn_adminMenuLowSetting","_skn_adminMenuMenuKey","_skn_adminMenuInfrontTeleport","_skn_adminMenuBanReasons","_skn_adminMenuCryproCfg","_skn_cfgPatchesCfg","_skn_PVSPrefix","_rndVAR_Count","_skn_rndVA","_skn_PVC_INDEX","_skn_AH_rndVarVehicle","_skn_AH_rndVarPlayer","_skn_AH_rndVarAHInitCheck","_skn_AH_Init","_skn_AH_Code","_skn_AH_Code_CA","_skn_AH_Code_CB","_skn_AH_Ban","_skn_AH_rndVar","_skn_doKickBan","_skn_pv_hackerLog","_skn_pv_adminLog","_skn_server_adminLog","_skn_doAdminRequest","_skn_doAdminLog","_skn_doTokenAuth","_skn_antiTeleportPVC","_skn_Admin_Code","_skn_Admin_Init","_skn_adminRequest_PVC","_skn_adminLog_PVC","_skn_adminLog","_skn_AdminKeyDown","_skn_AdminMenu_Init","_skn_getCtrl","_skn_fnc_Spec","_skn_Update_AdminButtons","_skn_mainMenuCfg","_skn_FillMainMenu","_skn_FillPlayerMenu","_skn_switchMainMenu","_skn_dbClickMainMenu","_skn_spawnMenu","_skn_spawnSpawnMenu","_skn_removespawnMenu","_skn_fillSpawnMenu","_skn_hackerLog","_skn_switchTable","_skn_customBanreason","_skn_flipVehicle","_skn_freeCam","_skn_delete","_skn_deleteMenu","_skn_deleteNow","_skn_doBan","_skn_mapTeleport","_skn_old_esp","_skn_hideAdmin","_skn_old_espMap","_skn_infrontTP","_skn_esp","_skn_godMode","_skn_repairVehicle","_skn_spawnLoot","_skn_mapLootArray","_skn_mapAnimalArray","_skn_mapAIArray","_skn_mapBasesArray","_skn_tg_Spec","_skn_tg_sortOrder","_skn_tg_toggle","_skn_tg_BanPlayer","_skn_tg_delete","_skn_tg_mapTeleport","_skn_tg_spawnTyp","_skn_tg_limitSpawn","_skn_tg_old_espMap","_skn_tg_old_esp","_skn_tg_hideAdmin","_skn_tg_infrontTP","_skn_tg_godMode","_skn_tg_map_player","_skn_tg_map_corpse","_skn_tg_map_loot","_skn_tg_map_animals","_skn_tg_map_vehicle","_skn_tg_map_ai","_skn_tg_map_trader","_skn_tg_map_basebuilding","_skn_t1","_skn_t2","_skn_t3","_skn_t4","_skn_t5","_skn_AH_rndVarAHInitCheckToken","_stringInArray","_displaysArray","_displays","_cfg_displayArray","_skn_adminUIDArray","_skn_adminNAMEArray","_skn_tempuid","_skn_spawnPointCenter","_centerDistance","_sknBanANDSleep","_sknBanANDSleepQuick","_sknPatches","_skn_addonCheckCode","_skn_fileCheckCode","_sknAddActionCheck","_skn_code_ban","_skn_code_init","_skn_code_antihack","_skn_admincode","_skn_admininit","_configs"];

_config = (configFile >> "CfgSecConf");
if (isClass _config) then {diag_log "Loading config..."};

_debugClass = if ([_config,"debug",false] call EPOCH_fnc_returnConfigEntry) then { "DebugActive" } else { "DebugDisabled" };

_cfg_systemDebug  = (_config >> _debugClass);
_skn_systemDebug1 = getText(_cfg_systemDebug >> "systemChat1");
_skn_systemDebug2 = getText(_cfg_systemDebug >> "systemChat2");
_skn_systemDebug3 = getText(_cfg_systemDebug >> "systemChat3");
_skn_systemDebug4 = getText(_cfg_systemDebug >> "systemChat4");
_skn_systemDebug5 = getText(_cfg_systemDebug >> "systemChat5");

_cfg_remoteExecClient = (_config >> "remoteExecClient");
_remoteExecClient_NAMES = [_cfg_remoteExecClient, "functions", []] call EPOCH_fnc_returnConfigEntry;

_cfg_limits = (_config >> "limits");
_skn_playerCryptoLimit = [_cfg_limits, "playerCrypto", 250000] call EPOCH_fnc_returnConfigEntry;

_cfg_learning		  = (_config >> "learning");
_skn_trustedUsers	  = [_cfg_learning,"trustedUsers",[]] call EPOCH_fnc_returnConfigEntry;
_str_learningModeCheck = if ([_cfg_learning,"mode",true] call EPOCH_fnc_returnConfigEntry) then{"((getPlayerUID _player) in "+str _skn_trustedUsers+")"} else {"true"};

_cfg_quality			= (_config >> "forcedQuality");
_skn_perfMode		   = getText(_cfg_quality >> "mode");
_skn_viewDistance	   = [_cfg_quality >> _skn_perfMode, "viewDistance", 2500] call EPOCH_fnc_returnConfigEntry;
_skn_viewDistanceObects = [_cfg_quality >> _skn_perfMode, "viewDistanceObects", 2000] call EPOCH_fnc_returnConfigEntry;
_skn_terrainGrid		= [_cfg_quality >> _skn_perfMode, "terrainGrid", 10] call EPOCH_fnc_returnConfigEntry;

_cfg_blacklistConfig  = (_config >> "blacklist");
_skn_badDisplaysArray = [_cfg_blacklistConfig, "badDisplays", [-1337,17,19,30,32,45,59,69,71,125,132,155,156,157,162,165,166,167,312,1320,1321,2727,2928,2929,316000]] call EPOCH_fnc_returnConfigEntry;
_skn_badAnimations	= [_cfg_blacklistConfig, "animations", ['AmovPercMstpSnonWnonDnon_exerciseKata','AmovPercMstpSnonWnonDnon_exercisePushup','GestureSpasm1','GestureSpasm4','GestureNod']] call EPOCH_fnc_returnConfigEntry;

_cfg_variablesConfig  = (_config >> "variables");
_skn_badVarCheckArray = [_cfg_variablesConfig, "badVars", ['EPOCH_GMODE','ESP_map','ESP_mainMap','ESP_adminMap','AntiAntiAntiAntiHax','fnc_usec_damageHandler','fnc_usec_unconscious','VAGINA_secret','yolo','VERSION','life_fnc_handleDamage','EPOCH_spawnVehicle_PVS','CLASS911_Menu','nuke_vars','JJMMEE_INIT_MENU','PLAYERON','PLAYERNEXT2','ALTISLIFEON','LY_Menu','PLAY','LY_SwaggerLikeUs','BIS_fnc_dbg_reminder_value','BIS_fnc_dbg_reminder']] call EPOCH_fnc_returnConfigEntry;
_skn_nilVarCheckArray = [_cfg_variablesConfig, "nilVars", ['EPOCH_antiWallCount','EPOCH_playerEnergy','EPOCH_playerHunger','EPOCH_playerStamina','EPOCH_playerCrypto','EPOCH_target','EPOCH_ESP_TARGETS','EPOCH_ESPMAP_TARGETS','EPOCH_taxRate','EPOCH_ESP_VEHICLEPLAYER','EPOCH_ESP_PLAYER','EPOCH_ESP_VEHICLES']] call EPOCH_fnc_returnConfigEntry;
_skn_commandMenuArray = [(_config >> "commandMenu"), "menus",['','RscSelectTeam','RscTeam','RscMoveHigh','#GETIN','#RscStatus','#WATCH0','RscCombatMode','RscMenuReply','RscCallSupport','#CUSTOM_RADIO','#User:BIS_fnc_addCommMenuItem_menu','RscRadio','RscReply','#ACTION','RscMenuFormations','#WATCH','RscGroupRootMenu','RscMainMenu','RscMenuMove','RscWatchDir','RscWatchMoveDir','#User:BIS_Menu_GroupCommunication','RscMenuStatus','RscFormations']] call EPOCH_fnc_returnConfigEntry;

_skn_addEHConfig		= (_config >> "addEventHandler");
_skn_displayAddEHChecks = [_skn_addEHConfig, "checks",[]] call EPOCH_fnc_returnConfigEntry;

_skn_addEHArray = [];
{
	_code = ["CfgEpochClient", _x, ""] call EPOCH_fnc_returnConfigEntryV2;
	_skn_addEHArray pushBack [_x,_code,(_code != "")];
} forEach _skn_displayAddEHChecks;

_serverSettingsConfig = configFile >> "CfgEpochServer";
_skn_enableAntihack = [_serverSettingsConfig, "antihack_Enabled", true] call EPOCH_fnc_returnConfigEntry;
_skn_check_addons = [_serverSettingsConfig, "antihack_cfgPatchesCheck", true] call EPOCH_fnc_returnConfigEntry;
_checkFiles = [
	["epoch_code\compile\setup\EPOCH_clientInit.sqf", "EPOCH_clientInit"],
	["epoch_code\compile\EPOCH_onEachFrame.sqf", "EPOCH_onEachFrame"],
	["epoch_code\compile\setup\EPOCH_client_rejectPlayer.sqf", "EPOCH_client_rejectPlayer"],
	["epoch_code\compile\setup\EPOCH_clientRespawn.sqf", "EPOCH_clientRespawn"]
];
_skn_check_files = [_serverSettingsConfig, "antihack_checkFilesNew", _checkFiles] call EPOCH_fnc_returnConfigEntry;

_skn_whitelist_cfgPatches = [_serverSettingsConfig, "antihack_whitelistedCfgPatches", []] call EPOCH_fnc_returnConfigEntry;
_skn_adminsOwner = [_serverSettingsConfig, "adminMenu_Owner", []] call EPOCH_fnc_returnConfigEntry;
_skn_adminsHigh = [_serverSettingsConfig, "adminMenu_High", []] call EPOCH_fnc_returnConfigEntry;
_skn_adminsLow = [_serverSettingsConfig, "adminMenu_Low", []] call EPOCH_fnc_returnConfigEntry;
_banReasons = [
	"Mod mismatch, check that the mods you have enabled match server."
];
_skn_banReason = [_serverSettingsConfig, "antihack_banReason", "EpochMod.com Autoban"] call EPOCH_fnc_returnConfigEntry;
_antihack_banDuration = [_serverSettingsConfig, "antihack_banDuration", 5] call EPOCH_fnc_returnConfigEntry;
_epoch_banReasons = [_serverSettingsConfig, "antihack_banReasons", _banReasons] call EPOCH_fnc_returnConfigEntry;
_kickReasons = [
	"Mod mismatch, check that mods enabled match server."
];
_epoch_kickReason = [_serverSettingsConfig, "antihack_kickReason", "EpochMod.com Autokick"] call EPOCH_fnc_returnConfigEntry;
_epoch_kickReasons = [_serverSettingsConfig, "antihack_kickReasons", _kickReasons] call EPOCH_fnc_returnConfigEntry;
_ownerSettings = ["ESP-PLAYER","ESP-VEHICLE","ESP-LOOT","OLD-ESP","OLD-MAP","PLAYER-TELEPORT","MAP-TELEPORT","INFRONT-TELEPORT","MAP-PLAYER","MAP-CORPSE","MAP-LOOT","MAP-VEHICLE","MAP-AI","MAP-BASEBUILDING","TARGET-HEAL","TARGET-AMMO","TARGET-KILL","TARGET-CRYPTO","TARGET-VEHICLEREPAIR","VEHICLEFLIP","BANPANNEL","SPAWN-MENU","FREE-CAM","INVISIBLE","SPAWNLOOT","GODMODE","HEAL","VEHICLEREPAIR"];
_skn_adminMenuOwnerSetting = [_serverSettingsConfig, "adminMenu_OwnerSetting", _ownerSettings] call EPOCH_fnc_returnConfigEntry;
_adminSettings = ["PLAYER-TELEPORT","MAP-TELEPORT","TARGET-HEAL","TARGET-AMMO","TARGET-KILL","VEHICLEFLIP","BANPANNEL"];
_skn_adminMenuHighSetting = [_serverSettingsConfig, "adminMenu_HighSetting", _adminSettings] call EPOCH_fnc_returnConfigEntry;
_lowSettings = ["PLAYER-TELEPORT","MAP-TELEPORT","TARGET-HEAL"];
_skn_adminMenuLowSetting = [_serverSettingsConfig, "adminMenu_LowSetting", _lowSettings] call EPOCH_fnc_returnConfigEntry;
_skn_adminMenuMenuKey = [_serverSettingsConfig, "adminMenu_menuKey", 0x3B] call EPOCH_fnc_returnConfigEntry;
_skn_adminMenuInfrontTeleport = [_serverSettingsConfig, "adminMenu_infrontTeleport", 0x06] call EPOCH_fnc_returnConfigEntry;
_skn_adminMenuBanReasons = [_serverSettingsConfig, "adminMenu_BanReasons", ["Traderzone","Hacking","Glitch","Combat Log"]] call EPOCH_fnc_returnConfigEntry;
_skn_adminMenuCryproCfg = [_serverSettingsConfig, "adminMenu_cryptoCfg", [2500,1000,500,100,50,-1000]] call EPOCH_fnc_returnConfigEntry;
_skn_cfgPatchesCfg = [_serverSettingsConfig, "antihack_cfgPatchesMode", [2]] call EPOCH_fnc_returnConfigEntry;
_skn_PVSPrefix = [_serverSettingsConfig, "antihack_PVSPrefix", "EPAH_"] call EPOCH_fnc_returnConfigEntry;

// build array with X number of random strings
_rndVAR_Count = 84; // 85 = number of (_skn_rndVA deleteAt 0)
_skn_rndVA = parseSimpleArray ('epochserver' callExtension format['810|%1', _rndVAR_Count]);

EPOCH_hiveWhitelistVarsArray = [];

// For client PVC
_skn_PVC_INDEX = _skn_rndVA deleteAt 0;
// [["function", _transferBankBalance],_transferTarget]
EPOCH_sendRemoteExecClient = compileFinal ("
	params ['_first','_target'];
	_first params ['_functionName','_data'];
	[_functionName, _data] remoteExec ['EPOCH_"+_skn_PVC_INDEX+"',_target];
");

// build dynamic RE-C functions
_remoteExecClientStr = "params [""_function"",""_data""];switch (_function) do {";
{
	_functionName = format ["EPOCH_dyn_%1",_x];
	missionNamespace setVariable [_functionName, compileFinal ([_cfg_remoteExecClient, _x, ""] call EPOCH_fnc_returnConfigEntry), true];
	_remoteExecClientStr = _remoteExecClientStr + format['case "%1": {_data call %2};',_x,_functionName];
} forEach _remoteExecClient_NAMES;
_remoteExecClientStr = _remoteExecClientStr + "};";

// broadcast main RE-C function
missionNamespace setVariable [format["EPOCH_%1",_skn_PVC_INDEX], compileFinal _remoteExecClientStr, true];

// diag_log format["DEBUG: _remoteExecClientStr %1",_remoteExecClientStr];

_skn_AH_rndVarVehicle = _skn_rndVA deleteAt 0;
_skn_AH_rndVarPlayer  = _skn_rndVA deleteAt 0;

EPOCH_server_getVToken = compileFinal ("_this getVariable ['"+_skn_AH_rndVarVehicle+"',false]");
EPOCH_server_setVToken = compileFinal ("_this setVariable ['"+_skn_AH_rndVarVehicle+"',true];true");
EPOCH_server_getPToken = compileFinal ("private['_ret','_var'];_ret = false;if ((_this select 0) isEqualType objNull)then{if (!isNull(_this select 0))then{_var=(_this select 0) getVariable '"+_skn_AH_rndVarPlayer+"';if (!isNil '_var') then {_ret= _var==(_this select 1)}}};if(!_ret)then{['kick',(_this select 0),'Token Check Failed'] call EPOCH_serverCommand};_ret");
EPOCH_server_setPToken = compileFinal ("private '_var';_var = 'epochserver' callExtension '810';_this setVariable ['"+_skn_AH_rndVarPlayer+"',_var];_var");

if (!_skn_enableAntihack) exitWith {
	EPOCH_server_pushPlayer = compileFinal ("
	params ['_playerNetID','_playerUID','_C_SET','_fsmHandle','_player'];
	_C_SET pushBack '';
	[_fsmHandle,['_C_SET', _C_SET]] remoteExecCall ['setFSMVariable', _player];
	");
	EPOCH_server_isPAdmin = compileFinal ("false");
	EPOCH_server_Authed = compileFinal ("true");
	EPOCH_server_disconnect = compileFinal("true");
};

// Check AH init code
_skn_AH_rndVarAHInitCheck = _skn_rndVA deleteAt 0;
// Init as array
call compile(_skn_AH_rndVarAHInitCheck+"=[];");

_skn_AH_Init			= _skn_rndVA deleteAt 0;
_skn_AH_Code			= _skn_rndVA deleteAt 0;
_skn_AH_Code_CA		 = _skn_rndVA deleteAt 0;
_skn_AH_Code_CB		 = _skn_rndVA deleteAt 0;
_skn_AH_Ban			 = _skn_rndVA deleteAt 0;
_skn_AH_rndVar		  = _skn_rndVA deleteAt 0;
_skn_doKickBan		  = _skn_PVSPrefix + (_skn_rndVA deleteAt 0);

//ADMIN STUFF:
//PVC from SERVER:
_skn_pv_hackerLog = _skn_rndVA deleteAt 0;
_skn_pv_adminLog  = _skn_rndVA deleteAt 0;
//Server Functions:
_skn_server_adminLog = _skn_rndVA deleteAt 0;

//PVS from CLIENT:
_skn_doAdminRequest  = _skn_PVSPrefix + (_skn_rndVA deleteAt 0);
_skn_doAdminLog	  = _skn_PVSPrefix + (_skn_rndVA deleteAt 0);
_skn_doTokenAuth	 = _skn_PVSPrefix + (_skn_rndVA deleteAt 0);
_skn_antiTeleportPVC = _skn_rndVA deleteAt 0;

//ADMIN MENU CODE & INIT
_skn_Admin_Code = _skn_rndVA deleteAt 0;
_skn_Admin_Init = _skn_rndVA deleteAt 0;

//ADMIN FUNCTIONS
_skn_adminRequest_PVC	= _skn_rndVA deleteAt 0;
_skn_adminLog_PVC		= _skn_rndVA deleteAt 0;
_skn_adminLog			= _skn_rndVA deleteAt 0;
_skn_AdminKeyDown		= _skn_rndVA deleteAt 0;
_skn_AdminMenu_Init	  = _skn_rndVA deleteAt 0;
_skn_getCtrl			 = _skn_rndVA deleteAt 0;
_skn_fnc_Spec			= _skn_rndVA deleteAt 0;
_skn_Update_AdminButtons = _skn_rndVA deleteAt 0;
_skn_mainMenuCfg		 = _skn_rndVA deleteAt 0;
_skn_FillMainMenu		= _skn_rndVA deleteAt 0;
_skn_FillPlayerMenu	  = _skn_rndVA deleteAt 0;
_skn_switchMainMenu	  = _skn_rndVA deleteAt 0;
_skn_dbClickMainMenu	 = _skn_rndVA deleteAt 0;
_skn_spawnMenu		   = _skn_rndVA deleteAt 0;
_skn_spawnSpawnMenu	  = _skn_rndVA deleteAt 0;
_skn_removespawnMenu	 = _skn_rndVA deleteAt 0;
_skn_fillSpawnMenu	   = _skn_rndVA deleteAt 0;
_skn_hackerLog		   = _skn_rndVA deleteAt 0;
_skn_switchTable		 = _skn_rndVA deleteAt 0;
_skn_customBanreason	 = _skn_rndVA deleteAt 0;
_skn_flipVehicle		 = _skn_rndVA deleteAt 0;
_skn_freeCam			 = _skn_rndVA deleteAt 0;
_skn_delete			  = _skn_rndVA deleteAt 0;
_skn_deleteMenu		  = _skn_rndVA deleteAt 0;
_skn_deleteNow		   = _skn_rndVA deleteAt 0;
_skn_doBan			   = _skn_rndVA deleteAt 0;
_skn_mapTeleport		 = _skn_rndVA deleteAt 0;
_skn_old_esp			 = _skn_rndVA deleteAt 0;
_skn_hideAdmin		   = _skn_rndVA deleteAt 0;
_skn_old_espMap		  = _skn_rndVA deleteAt 0;
_skn_infrontTP		   = _skn_rndVA deleteAt 0;
_skn_esp				 = _skn_rndVA deleteAt 0;
_skn_godMode			 = _skn_rndVA deleteAt 0;
_skn_repairVehicle	   = _skn_rndVA deleteAt 0;
_skn_spawnLoot		   = _skn_rndVA deleteAt 0;
_skn_mapLootArray		= _skn_rndVA deleteAt 0;
_skn_mapAnimalArray		= _skn_rndVA deleteAt 0;
_skn_mapAIArray		= _skn_rndVA deleteAt 0;
_skn_mapBasesArray		= _skn_rndVA deleteAt 0;

//ADMIN TOGGLE VARIABLES
_skn_tg_Spec		= _skn_rndVA deleteAt 0;
_skn_tg_sortOrder   = _skn_rndVA deleteAt 0;
_skn_tg_toggle	  = _skn_rndVA deleteAt 0;
_skn_tg_BanPlayer   = _skn_rndVA deleteAt 0;
_skn_tg_delete	  = _skn_rndVA deleteAt 0;
_skn_tg_mapTeleport = _skn_rndVA deleteAt 0;
_skn_tg_spawnTyp	= _skn_rndVA deleteAt 0;
_skn_tg_limitSpawn  = _skn_rndVA deleteAt 0;
_skn_tg_old_espMap  = _skn_rndVA deleteAt 0;
_skn_tg_old_esp	 = _skn_rndVA deleteAt 0;
_skn_tg_hideAdmin   = _skn_rndVA deleteAt 0;
_skn_tg_infrontTP   = _skn_rndVA deleteAt 0;
_skn_tg_godMode	 = _skn_rndVA deleteAt 0;

_skn_tg_map_player	   = _skn_rndVA deleteAt 0;
_skn_tg_map_corpse	   = _skn_rndVA deleteAt 0;
_skn_tg_map_loot		 = _skn_rndVA deleteAt 0;
_skn_tg_map_animals		 = _skn_rndVA deleteAt 0;
_skn_tg_map_vehicle	  = _skn_rndVA deleteAt 0;
_skn_tg_map_ai		   = _skn_rndVA deleteAt 0;
_skn_tg_map_trader		   = _skn_rndVA deleteAt 0;
_skn_tg_map_basebuilding = _skn_rndVA deleteAt 0;

_skn_t1 = _skn_rndVA deleteAt 0;
_skn_t2 = _skn_rndVA deleteAt 0;
_skn_t3 = _skn_rndVA deleteAt 0;
_skn_t4 = _skn_rndVA deleteAt 0;
_skn_t5 = _skn_rndVA deleteAt 0;

_skn_AH_rndVarAHInitCheckToken = _skn_t1+_skn_t2+_skn_t3+_skn_t4+_skn_t5;
EPOCH_server_Authed = compileFinal("_this in "+_skn_AH_rndVarAHInitCheck);
EPOCH_server_disconnect = compileFinal("
	_ret = false;
	_index = " +_skn_AH_rndVarAHInitCheck + " find _this;
	if (_index != -1) then {
		" +_skn_AH_rndVarAHInitCheck + " deleteAt _index;
		_ret = true;
	};
	_ret
");

EPOCH_server_movePlayer = compileFinal("
params [['_playerObj',objNull,[objNull]],['_pos',[],[[]]]];
if !(isNull _playerObj) then {
	"+_skn_antiTeleportPVC+" = true;
	(owner _playerObj) publicVariableClient '"+_skn_antiTeleportPVC+"';
	[format['Teleport %1 (%2) To Position: %3', name _playerObj, getPlayerUID _playerObj,_pos], 0] call "+_skn_server_adminLog+";
	[vehicle _playerObj,_pos] spawn {
		uiSleep 0.5;
		(_this select 0) setPosATL (_this select 1);
	};
};
");

EPOCH_server_teleportCheck = compileFinal("
params [['_playerObj',objNull,[objNull]],'_allow'];
if !(isNull _playerObj) then {
	"+_skn_antiTeleportPVC+" = _allow;
	(owner _playerObj) publicVariableClient '"+_skn_antiTeleportPVC+"';
};
");

_stringInArray = {
	private "_ret";
	_ret = false;
	{if (_x in _case)exitWith {_ret = true}}forEach _this;
	_ret
};

_displaysArray = [];
{_displaysArray pushBack [_x,[],[]]} forEach ["RscDisplayMainMap","RscDisplayGetReady","RscDisplayInventory","RscDisplayLoadMission","RscDisplayInterrupt","RscDisplayOptionsVideo","RscDisplayOptions","RscDisplayAVTerminal","RscDisplayConfigure","RscDisplayConfigureAction","RscDisplayConfigureControllers","RscDisplayControlSchemes","RscDisplayCustomizeController","RscDisplayDebriefing","RscDisplayDiary","RscDisplayGameOptions","RscDisplayJoystickSchemes","RscDisplayLoading","RscDisplayMicSensitivityOptions","RscDisplayOptionsAudio","RscDisplayOptionsLayout","RscDisplayStart","RscDisplayVehicleMsgBox","RscDisplayInsertMarker"];
_displays = [(_config >> "displayOnload"), "checkDisplays", _displaysArray] call EPOCH_fnc_returnConfigEntry;

_cfg_displayArray = [];
{
	_onLoad   = (getText(configFile >> (_x select 0) >> "onLoad"));
	_onUnload = (getText(configFile >> (_x select 0) >> "onUnload"));
	_onLoad   = [_onLoad];
	_onUnload = [_onUnload];
	{
		_onLoad pushBack _x;
	} forEach(_x select 1);
	{
		_onUnload pushBack _x;
	} forEach(_x select 2);
	_cfg_displayArray pushBack[(_x select 0), _onLoad, _onUnload];
}forEach _displays;

_skn_adminUIDArray  = [];
_skn_adminNAMEArray = [];
_skn_tempuid		= [];
{
	_skn_adminUIDArray pushBack(_x select 0);
	_skn_adminNAMEArray pushBack(_x select 1);

} forEach _skn_adminsOwner;
_skn_adminsOwner = _skn_adminUIDArray;
{
	_skn_tempuid pushBack(_x select 0);
	_skn_adminUIDArray pushBack(_x select 0);
	_skn_adminNAMEArray pushBack(_x select 1);

} forEach _skn_adminsHigh;
_skn_adminsHigh = _skn_tempuid;
_skn_tempuid	= [];
{
	_skn_adminUIDArray pushBack(_x select 0);
	_skn_tempuid pushBack(_x select 0);
	_skn_adminNAMEArray pushBack(_x select 1);
} forEach _skn_adminsLow;
_skn_adminsLow = _skn_tempuid;
_skn_tempuid   = nil;

{_skn_adminMenuOwnerSetting set[_forEachIndex, toUpper _x]}forEach _skn_adminMenuOwnerSetting;
{_skn_adminMenuHighSetting set [_forEachIndex,toUpper _x]}forEach _skn_adminMenuHighSetting;
{_skn_adminMenuLowSetting set [_forEachIndex,toUpper _x]}forEach _skn_adminMenuLowSetting;

_skn_adminMenuOwner = "[]";
_skn_adminMenuHigh  = "[]";
_skn_adminMenuLow   = "[]";

_skn_blockedSpawnMenuUID = [];
if !("SPAWN-MENU" in _skn_adminMenuHighSetting) then {_skn_blockedSpawnMenuUID = _skn_adminsHigh};
if !("SPAWN-MENU" in _skn_adminMenuLowSetting) then {{_skn_blockedSpawnMenuUID pushBack _x}forEach _skn_adminsLow};
if !("SPAWN-MENU" in _skn_adminMenuOwnerSetting) then {{_skn_blockedSpawnMenuUID pushBack _x}forEach _skn_adminsOwner};

_case = _skn_adminMenuOwnerSetting; //All Cfg for Owner Menu
for "_i" from 1 to 3 do {
	_temp = "[['=============== MAIN MENU ===============',[],'','1',[]]";
	if (["PLAYER-TELEPORT","MAP-TELEPORT","INFRONT-TELEPORT"] call _stringInArray) then {

		if ("PLAYER-TELEPORT" in _case) then {
			_temp = _temp + "
				,['  Player To Admin',[],{[101,_this select 1] call "+_skn_adminRequest_PVC+"},'4',[]]
				,['  Admin To Player', [], { [102, _this select 1] call "+_skn_adminRequest_PVC+" },'4',[]]
			";
		};
		if ("INFRONT-TELEPORT" in _case) then {
			_temp = _temp + "
				,['  In Front', [], {"+_skn_tg_infrontTP+" = !"+_skn_tg_infrontTP+"},'2',[]]
			";
		};
		if ("MAP-TELEPORT" in _case) then {
			_temp = _temp + "
				,['  Ctrl+Click Map', [], {"+_skn_tg_mapTeleport+"=!"+_skn_tg_mapTeleport+";['Map to Teleport', if ("+_skn_tg_mapTeleport+") then[{2}, { 1 }]] call "+_skn_adminLog_PVC+" },'2',[]]
			";
		};
	};
	if (["FREE-CAM","INVISIBLE"] call _stringInArray) then {
		_temp = _temp + ",['Spectate', [],'','1',[]]";
		if ("MAP-TELEPORT" in _case) then {
			_temp = _temp + "
				,['  Free Look Cam ', [], "+_skn_freeCam+",'0',[]]
			";
		};
		if ("INVISIBLE" in _case) then {
			_temp = _temp + "
				,['  Invisible Mode', [], "+_skn_hideAdmin+", '2', []]
			";
		};
	};
	if (["MAP-PLAYER","MAP-CORPSE","MAP-LOOT","MAP-ANIMALS","MAP-VEHICLE","MAP-AI","MAP-BASEBUILDING"] call _stringInArray) then {
		_temp = _temp + ",['Map Tools', [],'','1',[]]";
		if ("MAP-PLAYER" in _case) then {
			_temp = _temp + "
				,['  Player Marker', [], {"+_skn_tg_map_player+" = !"+_skn_tg_map_player+"; ['Player MARKER',if ("+_skn_tg_map_player+") then [{2},{1}]] call "+_skn_adminLog_PVC+"}, '2', []]
			";
		};
		if ("MAP-CORPSE" in _case) then {
			_temp = _temp + "
				,['  Corpse Marker', [], {"+_skn_tg_map_corpse+" = !"+_skn_tg_map_corpse+"; ['Corpse MARKER',if ("+_skn_tg_map_corpse+") then [{2},{1}]] call "+_skn_adminLog_PVC+"}, '2', []]
			";
		};
		if ("MAP-LOOT" in _case) then {
			_temp = _temp + "
				,['  Loot Marker', [], {"+_skn_tg_map_loot+" = !"+_skn_tg_map_loot+"; if ("+_skn_tg_map_loot+") then {waitUntil {"+_skn_mapLootArray+" = nearestObjects[player,['WH_Loot', 'Animated_Loot'], 12500];uiSleep 10;!"+_skn_tg_map_loot+"};"+_skn_mapLootArray+" = []};['Loot MARKER',if ("+_skn_tg_map_loot+") then [{2},{1}]] call "+_skn_adminLog_PVC+"}, '2', []]
			";
		};
		if ("MAP-ANIMALS" in _case) then {
			_temp = _temp + "
				,['  Animal Marker', [], {"+_skn_tg_map_animals+" = !"+_skn_tg_map_animals+"; if ("+_skn_tg_map_animals+") then {waitUntil {"+_skn_mapAnimalArray+" = nearestObjects[player, ['Sheep_random_EPOCH','Goat_random_EPOCH','Snake_random_EPOCH','Snake2_random_EPOCH','Hen_random_EPOCH','Cock_random_EPOCH','Fin_random_EPOCH','Alsatian_random_EPOCH','Rabbit_EPOCH'], 12500];uiSleep 10;!"+_skn_tg_map_animals+"};"+_skn_mapAnimalArray+" = []};['Animal MARKER',if ("+_skn_tg_map_animals+") then [{2},{1}]] call "+_skn_adminLog_PVC+"}, '2', []]
			";
		};
		if ("MAP-VEHICLE" in _case) then {
			_temp = _temp + "
				,['  Vehicle Marker', [], {"+_skn_tg_map_vehicle+" = !"+_skn_tg_map_vehicle+"; ['Vehicle MARKER',if ("+_skn_tg_map_vehicle+") then [{2},{1}]] call "+_skn_adminLog_PVC+"}, '2', []]
			";
		};
		if ("MAP-AI" in _case) then {
			_temp = _temp + "
				,['  AI Marker', [], {"+_skn_tg_map_ai+" = !"+_skn_tg_map_ai+"; if ("+_skn_tg_map_ai+") then {waitUntil {"+_skn_mapAIArray+" = nearestObjects[player, ['I_Soldier_EPOCH','I_Soldier1_EPOCH','I_Soldier2_EPOCH','I_Soldier3_EPOCH','O_recon_F'], 12500];uiSleep 10;!"+_skn_tg_map_ai+"};"+_skn_mapAIArray+" = []}; ['AI MARKER',if ("+_skn_tg_map_ai+") then [{2},{1}]] call "+_skn_adminLog_PVC+"}, '2', []]
			";
		};
		if ("MAP-TRADER" in _case) then {
			_temp = _temp + "
				,['  Trader Marker', [], {"+_skn_tg_map_trader+" = !"+_skn_tg_map_trader+"; ['Trader MARKER',if ("+_skn_tg_map_trader+") then [{2},{1}]] call "+_skn_adminLog_PVC+"}, '2', []]
			";
		};
		if ("MAP-BASEBUILDING" in _case) then {
			_temp = _temp + "
				,['  Base Building Marker', [], {"+_skn_tg_map_basebuilding+" = !"+_skn_tg_map_basebuilding+"; if ("+_skn_tg_map_basebuilding+") then {waitUntil {"+_skn_mapBasesArray+" = ([worldSize/2,worldSize/2,0]) nearObjects['PlotPole_EPOCH', 12500];uiSleep 15;!"+_skn_tg_map_basebuilding+"};"+_skn_mapBasesArray+" = []}; ['Base Building MARKER',if ("+_skn_tg_map_basebuilding+") then [{2},{1}]] call "+_skn_adminLog_PVC+"}, '2', []]
			";
		};
	};
	if (["ESP-PLAYER","ESP-LOOT","ESP-VEHICLE"] call _stringInArray) then {
		_temp = _temp + ",['3D Tools', [],'','1',[]]";
		if ("ESP-PLAYER" in _case) then {
			_temp = _temp + "
				,['  Player ESP', true, "+_skn_esp+", '2', []]
			";
		};
		if ("ESP-VEHICLE" in _case) then {
			_temp = _temp + "
				,['  Vehicle ESP', false, "+_skn_esp+", '2', []]
			";
		};
		if ("ESP-LOOT" in _case) then {
			_temp = _temp + "
				,['  Loot ESP (WIP)', [], '', '1', []]
			";
		};
	};
	if (["OLD-ESP","OLD-MAP"] call _stringInArray) then {
		_temp = _temp + ",['Old Visualisation Tools', [],'','1',[]]";
		if ("OLD-ESP" in _case) then {
			_temp = _temp + ",['  3D ESP', [], "+_skn_old_esp+", '2', []]";
		};
		if ("OLD-MAP" in _case) then {
			_temp = _temp + ",['  MAP ESP', [], "+_skn_old_espMap+", '2', []]";
		};
	};
	if (["GODMODE","HEAL","VEHICLEREPAIR"] call _stringInArray) then {
		_temp = _temp + ",['Self Menu', [], '', '1', []]";
		if ("GODMODE" in _case) then {
			_temp = _temp + ",['  Godmode', [], "+_skn_godMode+", '2', []]";
		};
		if ("HEAL" in _case) then {
			_temp = _temp + ",['  Heal',[],{[103,netId player] call "+_skn_adminRequest_PVC+"},'4',[0.016,0.702,0.078,1]]";
		};
		if ("VEHICLEREPAIR" in _case) then {
			_temp = _temp + ",['  Repair Vehicle', [], "+_skn_repairVehicle+", '0', []]";
		};
	};
	if (["TARGET-HEAL","TARGET-AMMO","TARGET-KILL","TARGET-CRYPTO","TARGET-VEHICLEREPAIR"] call _stringInArray) then {
		_temp = _temp + ",['Target Actions', [], '', '1', []]";
		if ("TARGET-HEAL" in _case) then {
			_temp = _temp + ",['  Heal',[],{[103,_this select 1] call "+_skn_adminRequest_PVC+"},'4',[0.016,0.702,0.078,1]]";
		};
		if ("TARGET-KILL" in _case) then {
			_temp = _temp + ",['  Kill',[],{[100,_this select 1] call "+_skn_adminRequest_PVC+"},'4',[0.859,0.094,0.094,1]]";
		};
		if ("TARGET-AMMO" in _case) then {
			_temp = _temp + ",['  Give Ammo',[],{[200,_this select 1] call "+_skn_adminRequest_PVC+"},'4',[]]";
		};
		if ("TARGET-VEHICLEREPAIR" in _case) then {
			_temp = _temp + ",['  Repair Vehicle', [], "+_skn_flipVehicle+", '0', []]";
		};
		if ("TARGET-CRYPTO" in _case) then {
			{
				_temp = _temp + ",['  Give Crypto - "+str _x+"',"+str _x+",{[107,[_this select 1,_this select 2]] call "+_skn_adminRequest_PVC+"},'4',[]]"
			}count _skn_adminMenuCryproCfg;
		};
	};
	_temp = _temp + ",['Custom Stuff', [], '', '1', []]";
	if ("VEHICLEFLIP" in _case) then {
		_temp = _temp + ",['  Unflip Vehicle', [], "+_skn_flipVehicle+", '0', []]";
	};
	if ("SPAWNLOOT" in _case) then {
		_temp = _temp + ",['  Loot Buildings (25m)', 25, "+_skn_spawnLoot+", '0', []]";
	};
	_temp = _temp + ",['  Disconnect yourself', [], { (findDisplay 46) closeDisplay 0 }, '0', []]";
	if ("BANPANNEL" in _case) then {
		_temp = _temp + ",['Ban Menu',[],'','1',[]]
			,['  BattlEye Ban - Custom Ban Reason',[],"+_skn_customBanreason+",'4',[]]
		";
		{
			_temp = _temp + ",['  BattlEye Ban - "+_x+"','"+_x+"',"+_skn_customBanreason+",'4',[]]"
		}count _skn_adminMenuBanReasons;
	};

	_temp = _temp + "
		,['Key Binds',[],'','1',[]]
		,['  3 Key - Teleport In Front',[],'','1',[]]
		,['  F2 - Cancel Spectating',[],'','1',[]]
		,['  F5 - Delete Target',[],'','1',[]]
		];
	";
	if (_i == 1) then {
		_skn_adminMenuOwner = _temp;
		_case = _skn_adminMenuHighSetting;
	};
	if (_i == 2) then {
		_skn_adminMenuHigh = _temp;
		_case = _skn_adminMenuLowSetting;
	};
	if (_i == 3) then {
		_skn_adminMenuLow = _temp;
	};
};

_skn_spawnPointCenter = getMarkerPos "respawn_west";
_centerDistance = [_serverSettingsConfig, "antihack_TPcenterDistance", 30] call EPOCH_fnc_returnConfigEntry;
_maxTravelDistance = [_serverSettingsConfig, "antihack_maxTravelDistance", 30] call EPOCH_fnc_returnConfigEntry;

// Only set these if prefix is not used since we can filter for it
if (_skn_PVSPrefix == "") then {
	"epochserver" callExtension format["800|%1|%2|%3|%4", _skn_doKickBan, _skn_doAdminRequest, _skn_doAdminLog, _skn_doTokenAuth];
};

EPOCH_server_pushPlayer = compileFinal ("
	params ['_playerNetID','_playerUID','_C_SET','_fsmHandle','_player'];
	if (_playerUID in "+ str _skn_adminUIDArray+") then {
		_playerNetID publicVariableClient '"+_skn_Admin_Code+"';
		_playerNetID publicVariableClient '"+_skn_pv_adminLog+"';
		_playerNetID publicVariableClient '"+_skn_pv_hackerLog+"';
		_C_SET pushBack '[] spawn "+_skn_Admin_Init+"';
	} else {
		_C_SET pushBack '[] spawn "+_skn_AH_Init+"';
	};
	[_fsmHandle,['_C_SET', _C_SET]] remoteExecCall ['setFSMVariable', _player];
	true
");
EPOCH_server_isPAdmin = compileFinal ("if (isNull _this) then {false} else {getPlayerUID _this in "+str _skn_adminUIDArray+"}");

_sknBanANDSleep = _skn_AH_Ban+"; uiSleep 60";
_sknBanANDSleepQuick = _skn_AH_Ban+"; uiSleep 1";

// CfgPatches Check
_sknPatches = [];
"_sknPatches pushBack (configName _x); true" configClasses (configFile >> "CfgPatches");
{_sknPatches pushBackUnique _x}forEach _skn_whitelist_cfgPatches;
_skn_addonCheckCode = if (_skn_check_addons) then {"[] spawn{_config = '!(configName _x in "+str _sknPatches+")' configClasses (configFile >> 'CfgPatches');if !(_config isEqualTo []) then {[format['Disallowed Addon %1',_config],["+str (_skn_cfgPatchesCfg select 0)+",0]] call "+_skn_AH_Ban+"}};"} else {""};
_skn_fileCheckCode = if (_skn_check_files isEqualTo []) then {""} else {"{if (str(compile preprocessFileLineNumbers (_x select 0)) != str(missionNamespace getVariable [_x select 1,'']))exitWith{[format['Modified File %1 (%2/%3)',_x select 1,count toArray str (compile preprocessFileLineNumbers (_x select 0)),count toArray str(missionNamespace getVariable [_x select 1,''])],0] call "+_skn_AH_Ban+"}} forEach "+str _skn_check_files+";"};

// Addaction Checks
_sknAddActionCheck = if ([_serverSettingsConfig, "antihack_addActionCheck", true] call EPOCH_fnc_returnConfigEntry) then{ "
if (player == _ActionVehicle) then[{_ActionCount = _ActionCount + 1}, { _ActionVehicle = player; _ActionCount = 0 }];
_addCase = player addAction['', '', [], -5, false, true, '', 'false'];
player removeAction _addCase;
if (_addCase != _ActionCount) then{
	[format['addAction %1/%2', _addCase, _ActionCount], 0] call "+_sknBanANDSleep+";
};
"} else {""};

// Anti teleport checks
_antiTeleportCheck = if ([_serverSettingsConfig, "antihack_antiTeleportCheck", true] call EPOCH_fnc_returnConfigEntry) then{"
_cntBan = 0;
while {true} do {
	_lastTime = diag_tickTime;
	_lastPos = getPosATL vehicle player;
	_notNearbySpawn = _lastPos distance "+str _skn_spawnPointCenter+" > "+str _centerDistance+";
	while {alive player} do {
		_curTime = diag_tickTime;
		_curPos = getPosATL vehicle player;
		_distance = _lastPos distance _curPos;

		if ((_curTime-_lastTime) > 1 || _distance > "+str _maxTravelDistance+") then {
			if (((_distance/(_curTime-_lastTime)) > "+str _maxTravelDistance+") && _notNearbySpawn && (player == vehicle player)) then {
				if (isNil '"+_skn_antiTeleportPVC+"') then {
					[format['[TEST] TP from %1 to %2, %3 meters, now at %4', _lastPos, _curPos, round _distance, getPosATL player],1] call "+_sknBanANDSleep+";
					vehicle player setPosATL _lastPos;
					_cntBan = _cntBan + 1;
					if (_cntBan > 4) then {

					};
				} else {
					uiSleep 10;
					_lastPos = getPosATL vehicle player;
					_lastTime = diag_tickTime;
					_notNearbySpawn = false;
				};
			} else {
				_lastPos = _curPos;
				_lastTime = _curTime;
				_notNearbySpawn = _lastPos distance "+str _skn_spawnPointCenter+" > "+str _centerDistance+";
			};
		};
	};
	uiSleep 0.1;
};
uiSleep 0.25;
"} else {""};

// Init Server Side Event Handlers
//[_data,_player,_token];
call compile("'"+_skn_doTokenAuth+"' addPublicVariableEventHandler {
	_array = _this select 1;
	_tokenSet = false;
	if !([_array select 1, _array select 2] call EPOCH_server_getPToken) exitWith{};
	if (_array select 0 isEqualTo '"+_skn_AH_rndVarAHInitCheckToken+"') then {
		_tokenSet = true;
		_puid = (_array select 1) getVariable['PUID', ''];
		if (_puid != '') then {
			if !(_puid in "+_skn_AH_rndVarAHInitCheck+") then {
				"+_skn_AH_rndVarAHInitCheck+" pushBack _puid;
				diag_log format['DEBUG: player auth token set %1', _array];
			};
		};
	};
	if !(_tokenSet) then {
		_playerUID = getPlayerUID (_array select 1);
		if (_playerUID != '') then{
			'epochserver' callExtension format['911|%1|%2', _playerUID, 'Auth failure, Please reconnect'];
		};
	};
};");

call compile ("'"+_skn_doKickBan+"' addPublicVariableEventHandler {
	_array = _this select 1;
	_array params ['_text','_mode','_player','_token'];
	if !([_player,_token] call EPOCH_server_getPToken) exitWith {
		['ahe', format['Token is different [%1,%2] %3',if (!isNull _player) then { _player getVariable ['"+_skn_AH_rndVarPlayer+"','']}else{'PlayerObj NULL'}, _array select 3, _array]] call EPOCH_fnc_server_hiveLog;
	};
	_text = toString(_text);
	_reasonIndex = -1;
	if (_mode isEqualType []) then{
		_mode = _mode select 0;
		_reasonIndex = _mode select 1;
	};
	_reason = '';
	_logName = 'ahl';
	_logMode = 1;
	_logColor = [1,1,1,1];
	switch _mode do {
		case 0: {
			_logName = 'ahb';
			_logColor = [1,0,0,1];
			_logMode = 0;
			if (_reasonIndex != -1) then {
				_reason = "+str(_epoch_banReasons)+" select _reasonIndex;
			};
			['ban', _player , format['"+_skn_banReason+" %1',_reason], "+str(_antihack_banDuration)+"] call EPOCH_serverCommand;
		};
		case 2: {
			_logName = 'ahk';
			_logColor = [0,0,1,1];
			if (_reasonIndex != -1) then {
				_reason = "+str(_epoch_kickReasons)+" select _reasonIndex;
			};
			['kick', _player , format['"+_epoch_kickReason+" %1',_reason]] call EPOCH_serverCommand;
		};
	};
	"+_skn_pv_hackerLog+" pushBack[[_logMode, call EPOCH_server_getRealTime, name _player, getPlayerUID _player, _text], _logColor];
	[_logName, format['%1 (%2): %3', name _player, getPlayerUID _player, _text]] call EPOCH_fnc_server_hiveLog;
	diag_log str([_logName, format['%1 (%2): %3', name _player, getPlayerUID _player, _text]]);
	{
		if (_x call EPOCH_server_isPAdmin) then {
			(owner _x) publicVariableClient '"+_skn_pv_hackerLog+"';
		};
	}forEach allPlayers;
};");
//0 = BAN
//1 = LOG
//2 = KICK

_skn_code_ban = compileFinal ("
	_this set [0,toArray (_this select 0)];
	_this pushBack player;
	_this pushBack Epoch_personalToken;
	"+_skn_doKickBan+" = _this;
	publicVariableServer '"+_skn_doKickBan+"';
	true
");
_skn_code_init = compileFinal ("
	comment 'Epoch Mod Antihack - Niklas Wagner - www.skaronator.com - Aaron Clark - www.epochmod.com - License: (CC) Attribution-NonCommercial-NoDerivatives 4.0 International';
	waitUntil {(getPlayerUID player) != ''};
	_start = diag_tickTime;
	waitUntil {!isNil '"+_skn_AH_Code+"' || (diag_tickTime-_start > 20)};
	if (isNil '"+_skn_AH_Code+"') exitWith {
		"+_skn_doKickBan+" = [format['Cannot Load AH [%1,%2]',!isNil '"+_skn_AH_Code_CA+"',!isNil '"+_skn_AH_Code_CB+"'],2,player,Epoch_personalToken];
		publicVariableServer '"+_skn_doKickBan+"';
		(findDisplay 46) closeDisplay 0
	};
	[] spawn "+_skn_AH_Code+";
	uiSleep 3;
	if ((isNil '"+_skn_AH_Code_CA+"') || (isNil '"+_skn_AH_Code_CB+"')) then {
		uiSleep 5;
		if ((isNil '"+_skn_AH_Code_CA+"') || (isNil '"+_skn_AH_Code_CB+"')) then {
			[] spawn "+_skn_AH_Code+";
			uiSleep 3;
		};
	};
	uiSleep 5;
	if ((isNil '"+_skn_AH_Code_CA+"') || (isNil '"+_skn_AH_Code_CB+"')) then {
		"+_skn_doKickBan+" = [format['Cannot Load AH [%1,%2]',!isNil '"+_skn_AH_Code_CA+"',!isNil '"+_skn_AH_Code_CB+"'],2,player,Epoch_personalToken];
		publicVariableServer '"+_skn_doKickBan+"';
		(findDisplay 46) closeDisplay 0
	};
	");
_skn_code_antihack = compileFinal ("
	comment 'Epoch Mod Antihack - Niklas Wagner - www.skaronator.com - Aaron Clark - www.epochmod.com - License: (CC) Attribution-NonCommercial-NoDerivatives 4.0 International';
	if ((!isNil '"+_skn_AH_Code_CA+"') && (!isNil '"+_skn_AH_Code_CB+"')) exitWith {};
	"+_skn_AH_Code_CA+" = true;
	"+_skn_addonCheckCode+"
	_t = '"+_skn_t1+"';
	[] spawn {
		uiSleep 5;
		FW"+_skn_AH_rndVar+" = '';
		FA"+_skn_AH_rndVar+" = 0;
		FWC"+_skn_AH_rndVar+" = 0;
		_sknOnFire = {
			_wep = _this select 1;
			_ammo = player ammo _wep;
			if !(_wep in ['Throw','Put']) then {
				if (FW"+_skn_AH_rndVar+" == _wep && FA"+_skn_AH_rndVar+" == _ammo) then {
					if (FWC"+_skn_AH_rndVar+" > 1) then {
						[format['[TEST] Unlimited Ammo: [%1,%2]', _wep, _ammo], 1] call "+_skn_AH_Ban+";
						[] spawn {uiSleep 60;FWC"+_skn_AH_rndVar+" = 0};
					};
					FWC"+_skn_AH_rndVar+" = FWC"+_skn_AH_rndVar+" +1;
					[] spawn {uiSleep 20;FWC"+_skn_AH_rndVar+" = 0};
				};
			};
			FA"+_skn_AH_rndVar+" = _ammo;
			FW"+_skn_AH_rndVar+" = _wep;
			true
		};

		uiNamespace setVariable['RscDisplayRemoteMissions',displayNull];
		uiNamespace setVariable['RscDisplayArsenal',displayNull];
		missionnamespace setVariable['BIS_fnc_showNotification_queue',nil];
		while {true} do {
			{
				if (!isNull (_x select 0)) then {
					[format['Menu: %1',_x select 1],0] call "+_sknBanANDSleep+";
				};
			}forEach[
				[(findDisplay 64) displayCtrl 1002,'findDisplay 64'],
				[(findDisplay 49) displayCtrl 0,'findDisplay 49'],
				[uiNamespace getVariable 'RscDisplayRemoteMissions','RscDisplayRemoteMissions'],
				[uiNamespace getVariable 'RscDisplayArsenal','RscDisplayArsenal'],
				[missionnamespace getvariable 'BIS_fnc_showNotification_queue','showNotification']
			];
			{
				if (!isNull (findDisplay _x)) then {
					[format['Menu: findDisplay %1',_x],0] call "+_sknBanANDSleep+";
				};
			}forEach "+str _skn_badDisplaysArray+";
			if (!isNull (uiNamespace getVariable 'RscDisplayConfigureAction')) then {
				_ctrlTxt = toLower ctrlText 1000;
				if (_ctrlTxt != '') then {
					if (_ctrlTxt != toLower localize 'STR_A3_RscDisplayConfigureAction_Title') then {
						[format['Menu: RscDisplayConfigureAction-A %1',_ctrlTxt],0] call "+_sknBanANDSleep+";
					};
				};
				{
					if (buttonAction _x != '') then {
						[format['Menu: RscDisplayConfigureAction-B (%1)',_x],0] call "+_sknBanANDSleep+";
					};
				}forEach [1,104,105,106,107,108,109];
			};
			if (!isNull (uiNamespace getVariable 'RscDisplayInsertMarker')) then {
				_ctrlTxt = toLower ctrlText 1001;
				if (_ctrlTxt != '') then {
					if (_ctrlTxt != toLower localize 'STR_A3_RscDisplayInsertMarker_Title') then {
						[format['Menu: RscDisplayInsertMarker-A %1',_ctrlTxt],0] call "+_sknBanANDSleep+";
					};
				};
				if ((buttonAction 1 != '') || (buttonAction 2 != '')) then {
					[format['Menu: RscDisplayInsertMarker-B [%1,%2]',buttonAction 1,buttonAction 2],0] call "+_sknBanANDSleep+";
				};
			};
			if (!isNull (findDisplay 129)) then {closeDialog 0};

			if !(commandingMenu in "+str _skn_commandMenuArray+") then {
				[format['Menu: commandMenu: %1',commandingMenu],0] call "+_sknBanANDSleep+";
			};

			onMapSingleClick '';
			player allowDamage true;
			vehicle player allowDamage true;

			{
				_ehKey = _x select 0;
				if (_x select 2) then {
					player removeEventHandler [_ehKey, 0];
				};
				_ehCode  = _x select 1;
				if (_ehKey == 'Fired') then {_ehCode = (_ehCode + '_this call '+str(_sknOnFire)) };
				_addCase = player addEventHandler [_ehKey, _ehCode];
				if !(_x select 2) then {
					player removeEventHandler [_ehKey, 0];
				};
				if (_addCase > 0) then {
					[format['EH: %1 %2',_ehKey,_addCase],0] call "+_sknBanANDSleep+";
				};
			} forEach "+str _skn_addEHArray+";

			uiSleep 0.01;
		};
	};
	_t = _t + '"+_skn_t2+"';
	[] spawn {
		disableSerialization;
		_ActionCount = -1;
		_ActionVehicle = player;
		_displayCount = 0;
		_personalToken = Epoch_personalToken;
		_antiWallCount = 0;
		waitUntil{!isNull (findDisplay 46)};
		setViewDistance "+str _skn_viewDistance+";
		setObjectViewDistance["+str _skn_viewDistanceObects+", 100];
		setTerrainGrid "+str _skn_terrainGrid+";
		uiSleep 5;
		while {true} do {
			if (isNil 'Epoch_personalToken') then {
				"+_skn_doKickBan+" = [format['personalToken NIL: %1/%2',Epoch_personalToken,_personalToken],0,player,_personalToken];
				publicVariableServer '"+_skn_doKickBan+"';
				uiSleep 60;
			};
			{
				if (isNil _x) then {
					[format['%1: nil',_x],0] call "+_sknBanANDSleep+";
				};
			}forEach "+str _skn_nilVarCheckArray+";
			if !(groupIconsVisible isEqualTo [false,false]) then {
				[format['GroupIcons %1',groupIconsVisible],0] call "+_sknBanANDSleep+";
			};
			if (unitRecoilCoefficient player != 1) then {
				[format['Recoil %1',unitRecoilCoefficient player],0] call "+_sknBanANDSleep+";
			};
			if (animationState player in "+str _skn_badAnimations+") then {
				[format['BadMove: %1',animationState player],0] call "+_sknBanANDSleep+";
			};
			if (EPOCH_playerEnergy > 2500 || EPOCH_playerEnergy < 0) then {
				[format['Energy: %1',EPOCH_playerEnergy],0] call "+_sknBanANDSleep+";
			};
			if (EPOCH_playerHunger > 5000 || EPOCH_playerHunger < 0) then {
				[format['Hunger: %1',EPOCH_playerHunger],0] call "+_sknBanANDSleep+";
			};
			if (EPOCH_playerThirst > 2500 || EPOCH_playerThirst < 0) then {
				[format['Thirsk: %1',EPOCH_playerThirst],0] call "+_sknBanANDSleep+";
			};
			if (EPOCH_playerStamina > 2500 || EPOCH_playerStamina < 0) then {
				[format['Stamina: %1',EPOCH_playerStamina],0] call "+_sknBanANDSleep+";
			};
			if (EPOCH_playerCrypto > "+str _skn_playerCryptoLimit+" || EPOCH_playerCrypto < 0) then {
				[format['Crypto: %1',EPOCH_playerCrypto],0] call "+_sknBanANDSleep+";
			};
			if (_antiWallCount != EPOCH_antiWallCount) then {
				if (_antiWallCount > EPOCH_antiWallCount) then {
					[format['antiWall: %1/%2',EPOCH_antiWallCount,_antiWallCount],0] call "+_sknBanANDSleep+";
				};
				_antiWallCount = EPOCH_antiWallCount;
			};
			if (EPOCH_target isEqualTo player) then {
				[format['setVelocityTarget: %1', EPOCH_target], 0] call "+_sknBanANDSleep+";
			};
			if !(EPOCH_ESP_TARGETS isEqualTo []) then {
				[format['ESP-O: %1', EPOCH_ESP_TARGETS], 0] call "+_sknBanANDSleep+";
			};
			if !(EPOCH_ESPMAP_TARGETS isEqualTo []) then {
				[format['MAP-ESP: %1', EPOCH_ESPMAP_TARGETS], 0] call "+_sknBanANDSleep+";
			};
			if !(EPOCH_ESP_VEHICLEPLAYER isEqualTo []) then {
				[format['ESP-N: %1', EPOCH_ESP_VEHICLEPLAYER], 0] call "+_sknBanANDSleep+";
			};
			if (EPOCH_ESP_PLAYER || EPOCH_ESP_VEHICLES) then {
				[format['ESP-N: %1', EPOCH_ESP_VEHICLES], 0] call "+_sknBanANDSleep+";
			};
			if (EPOCH_taxRate != "+str EPOCH_taxRate+") then {
				[format['taxTate: %1',EPOCH_taxRate],0] call "+_sknBanANDSleep+";
			};
			if !(EPOCH_group_upgrade_lvl isEqualTo "+str EPOCH_group_upgrade_lvl+") then {
				[format['groupUpgradeLvL: %1',EPOCH_group_upgrade_lvl],0] call "+_sknBanANDSleep+";
			};
			if (viewDistance != "+str _skn_viewDistance+") then{
				[format['viewDistance %1',viewDistance],0] call "+_sknBanANDSleep+";
			};
			"+_sknAddActionCheck+"
			_display = findDisplay 46;
			if !(isNull _display) then {
				{
					_display displayRemoveAllEventHandlers _x;
					_addCase = _display displayAddEventHandler [_x,([""CfgEpochClient"", _x, """"] call EPOCH_fnc_returnConfigEntryV2)];
					if (_addCase != _displayCount) then {
						[format['DEH: %3 %1/%2',_addCase,_displayCount,_x],0] call "+_sknBanANDSleep+";
					};
				} forEach (['CfgEpochClient', 'displayAddEventHandler', []] call EPOCH_fnc_returnConfigEntryV2);
			};
			uiSleep ((random 1)+1);
		};
	};
	_t = _t + '"+_skn_t3+"';
	[] spawn {"+_antiTeleportCheck+"};
	_t = _t + '"+_skn_t4+"';
	[] spawn {
		uiNamespace setVariable['ESP_mainMap', nil];
		uiNamespace setVariable['ESP_adminMap', nil];
		while {true} do {
			{
				_badVar = _x;
				{
					_var = _x getVariable _badVar;
					if (!isNil '_var') then {
						[format['BadVar %1=%2 (%3)',_badVar,_var,_forEachIndex],0] call "+_sknBanANDSleep+";
						_x setVariable [_badVar,nil];
					};
				}forEach [missionNamespace, parsingNamespace, uiNamespace];
			}forEach "+str _skn_badVarCheckArray+";
			"+_skn_fileCheckCode+"
			{
				_display = _x select 0;
				_displayCheckOkay = false;
				{
					if ((getText(configFile>>_display>>'onLoad'))==_x) exitWith { _displayCheckOkay = true };
				}forEach (_x select 1);
				if (!_displayCheckOkay) then {
					[format['Changed %1 >> onLoad >> %2', _display, getText(configFile>>_display>>'onLoad')],0] call "+_sknBanANDSleep+";
					_displayCheckOkay = false;
				};
				{
					if ((getText(configFile>>_display>>'onUnload'))==_x) exitWith { _displayCheckOkay = true };
				}forEach (_x select 2);
				if (!_displayCheckOkay) then {
					[format['Changed %1 >> onUnload >> %2', _display, getText(configFile>>_display>>'onUnload')],0] call "+_sknBanANDSleep+";
				}
			}forEach "+str _cfg_displayArray+";
			uiSleep ((random 10)+10);
		};
	};
	_t = _t + '"+_skn_t5+"';
	"+_skn_doTokenAuth+" = [_t,player,Epoch_personalToken];
	publicVariableServer '"+_skn_doTokenAuth+"';
	"+_skn_doTokenAuth+" = nil;
	"+_skn_AH_Code_CB+" = true;
	true
");

missionNamespace setVariable [_skn_AH_Ban, _skn_code_ban, true];
missionNamespace setVariable [_skn_AH_Code, _skn_code_antihack, true];
missionNamespace setVariable [_skn_AH_Init, _skn_code_init, true];

/*********************************************** ADMIN MENU *****************************************************/
/*********************************************** ADMIN MENU *****************************************************/
/*********************************************** ADMIN MENU *****************************************************/
/*********************************************** ADMIN MENU *****************************************************/
/*********************************************** ADMIN MENU *****************************************************/
call compile ("
	"+_skn_pv_adminLog+" = [];
	"+_skn_pv_hackerLog+" = [];
	"+_skn_server_adminLog+" = {
		_toggle = ' -----';
		if ((_this select 1) != 0) then {
			_toggle = if ((_this select 1) == 2) then {' -ON-'} else {'-OFF-'};
		};
		_adminUID = getPlayerUID _admin;
		_adminNAME = "+str _skn_adminNAMEArray+" select ("+str _skn_adminUIDArray+" find _adminUID);
		['aml', format['%1 (%2): [%4] %3',_adminNAME,_adminUID,_this select 0,_toggle]] call EPOCH_fnc_server_hiveLog;

		"+_skn_pv_adminLog+" pushBack [call EPOCH_server_getRealTime,_adminNAME,_toggle,_this select 0];
		diag_log format ['SKN2 AdminRequest %1',"+_skn_pv_adminLog+"];
		{
			if (_x call EPOCH_server_isPAdmin) then {
				(owner _x) publicVariableClient '"+_skn_pv_adminLog+"';
			};
		}forEach allPlayers;
		true
	};
");
//[text,toggle,admin,token]
//toggle: 0:NOTHING 1:OFF 2:ON
call compile ("'"+_skn_doAdminLog+"' addPublicVariableEventHandler {
	_array = _this select 1;
	diag_log format ['SKN AdminLog %1',_array];
	_admin = _array select 2;

	if !([_admin,_array select 3] call EPOCH_server_getPToken) exitWith {};
	if !(_admin call EPOCH_server_isPAdmin) exitWith {};
	[_array select 0,_array select 1] call "+_skn_server_adminLog+"};
");
//[case,[contentarray],player,token]
call compile ("'"+_skn_doAdminRequest+"' addPublicVariableEventHandler {
	_array = _this select 1;
	diag_log format ['SKN AdminRequest %1',_array];
	_admin = _array select 2;

	if !([_admin,_array select 3] call EPOCH_server_getPToken) exitWith {};
	if !(_admin call EPOCH_server_isPAdmin) exitWith {};

	_case = _array select 0;
	_content = _array select 1;

	if (_case == 100) then {
		_playerObj = objectFromNetId _content;
		[format['Kill Target: %1 (%2)',name _playerObj,getPlayerUID _playerObj],0] call "+_skn_server_adminLog+";
		_playerObj setDamage 1;
	};
	if (_case == 101) then {
		_playerObj = objectFromNetId _content;
		"+_skn_antiTeleportPVC+" = true;
		(owner _playerObj) publicVariableClient '"+_skn_antiTeleportPVC+"';
		[format['Teleport To Admin: %1 (%2)', name _playerObj, getPlayerUID _playerObj], 0] call "+_skn_server_adminLog+";
		[vehicle _playerObj,_admin] spawn {
			uiSleep 0.5;
			(_this select 0) setPos ((_this select 1) modelToWorld [0,1,0]);
			(_this select 0) setDir (getDir (_this select 1));
		};
	};
	if (_case == 102) then {
		_playerObj = objectFromNetId _content;
		_behindM = if (vehicle _playerObj == _playerObj) then [{-1},{-5}];

		vehicle _admin setPos (_playerObj modelToWorld [0,_behindM,0]);
		vehicle _admin setDir (getDir _playerObj);
		[format['Teleport Admin To: %1 (%2)', name _playerObj, getPlayerUID _playerObj], 0] call "+_skn_server_adminLog+";
	};
	if (_case == 103) then {
		_playerObj = objectFromNetId _content;
		_playerObj setDamage 0;
		[['healPlayer',true], _playerObj] call EPOCH_sendRemoteExecClient;
		if (_playerObj == _admin) then {
			['Healed Self',0] call "+_skn_server_adminLog+";
		} else {
			[format['Heal Target: %1 (%2)',name _playerObj,getPlayerUID _playerObj],0] call "+_skn_server_adminLog+";
		}
	};
	if (_case == 104) then {
		if ((_content isKindOf 'LandVehicle') || (_content isKindOf 'Air') || (_content isKindOf 'Ship') || (_content isKindOf 'Tank')) then {
			[_content, _admin] call EPOCH_server_save_killedVehicle;
		} else {
			if (_content isKindOf 'Constructions_lockedstatic_F' || (_content isKindOf 'Buildable_Storage')) then{
				[_content, _admin] call EPOCH_server_save_killedStorage;
			} else {
				[_content, _admin] call EPOCH_server_save_killedBuilding;
			};
		};
		[format['Delete: %1 at [%2]',typeOf _content, getPos _content],0] call "+_skn_server_adminLog+";
        _content spawn {
            if !(isNull _this) then {
                _this hideObjectGlobal true;
                sleep 1;
                if !(isNull _this) then {deleteVehicle _this};
            };
        };
	};
	if (_case == 106) then {
		_admin hideObjectGlobal _content;
	};
	if (_case == 107) then {
		_player = objectFromNetId (_content select 0);
		if (!isNull _player) then {
			_cIndex = EPOCH_customVars find 'Crypto';
			_vars = _player getVariable['VARS', call EPOCH_defaultVars_SEPXVar];
			_current_crypto = (((_vars select _cIndex) + (_content select 1)) min "+str _skn_playerCryptoLimit+") max 0;
			_current_crypto remoteExec ['EPOCH_effectCrypto',_player];
			_vars set[_cIndex, _current_crypto];
			_player setVariable['VARS', _vars];
			if (_player == _admin) then {
				[format['Give Crypto Myself: %1',_content select 1],0] call "+_skn_server_adminLog+";
			} else {
				[format['Give Crypto to %1 (%2): %3',name _player,getPlayerUID _player,_content select 1],0] call "+_skn_server_adminLog+";
			}
		};
	};
	if (_case == 108) then {
		if (!isNull _content) then {
			[format['Repaire Vehicle: %1',typeOf _content],0] call "+_skn_server_adminLog+";
			_content setDamage 0;
			diag_log format ['Debug-Vehicle: Repair: 108,%1',_content];
			if (local _content) then {
				_content setFuel 1;
			} else {
				[_content, 1] remoteExec ['EPOCH_client_fillVehicle',_admin];
			};
			_content call EPOCH_server_save_vehicle;
		};
	};
	if (_case == 109) then {
		if (surfaceIsWater _content) then [{vehicle _admin setPosASL _content},{vehicle _admin setPosATL _content}];
	};
	if (_case == 200) then {
		_playerObj = objectFromNetId _content;
		_weaponClass = currentWeapon _playerObj;
		_mags = getArray(configFile >> 'CfgWeapons' >> _weaponClass >> 'magazines');
		if !(_mags isEqualTo[]) then {
			_firstMag = _mags select 0;
			_magazineSizeMax = getNumber(configFile >> 'CfgMagazines' >> _firstMag >> 'count');
			_playerObj addMagazine[_firstMag, _magazineSizeMax];
			if (_playerObj == _admin) then {
				[format['Gave Ammo (%1) to Self', _firstMag], 0] call "+_skn_server_adminLog+";
			} else {
				[format['Gave Ammo (%3) to Target: %1 (%2)', name _playerObj, getPlayerUID _playerObj, _firstMag], 0] call "+_skn_server_adminLog+";
			};
		};
	};
	if (_case == 555) then {
		_target = objectFromNetId (_content select 1);

		_itemSpawner = {
			_nearbyWH = objNull;
			if (vehicle _target != _target) then {
				_nearbyWH = vehicle _target;
			} else {
				_nearbyWHArr = nearestObjects[_target, ['groundWeaponHolder'], 2];
				if !(_nearbyWHArr isEqualTo[]) then {
					_nearbyWH = _nearbyWHArr select 0;
				} else {
					_posWH = getposATL _target;
					_nearbyWH = createVehicle['groundWeaponHolder', _posWH, [], 0, 'CAN_COLLIDE'];
					_nearbyWH setPosATL _posWH;
				};
			};
			if !(isNull _nearbyWH) then {
				switch (_this select 1) do {
					case 1: { _nearbyWH addMagazineCargoGlobal[(_this select 0), 1] };
					case 2: { _nearbyWH addWeaponCargoGlobal[(_this select 0), 1] };
					case 3: { _nearbyWH addItemCargoGlobal[(_this select 0), 1] };
					case 4: { _nearbyWH addBackpackCargoGlobal[(_this select 0), 1] };
				};
			};
		};

		_permVehicleSpawner = {
			_item = _this;
			_return = false;
			if (_item isKindOf 'Air' || _item isKindOf 'Ship' || _item isKindOf 'LandVehicle') then {
				if !(EPOCH_VehicleSlots isEqualTo[]) then {
					_serverSettingsConfig = configFile >> 'CfgEpochServer';
					_removeweapons = [_serverSettingsConfig, 'removevehweapons', []] call EPOCH_fnc_returnConfigEntry;
					_removemagazinesturret = [_serverSettingsConfig, 'removevehmagazinesturret', []] call EPOCH_fnc_returnConfigEntry;
					_position = getPosATL _target;

					_slot = EPOCH_VehicleSlots select 0;
					EPOCH_VehicleSlots = EPOCH_VehicleSlots - [_slot];
					missionNamespace setVariable ['EPOCH_VehicleSlotCount', count EPOCH_VehicleSlots, true];

					_vehObj = createVehicle[_item, _position, [], 20, 'NONE'];
					_return = true;
					_vehObj call EPOCH_server_setVToken;
					addToRemainsCollector[_vehObj];

					_vehObj disableTIEquipment true;

					clearWeaponCargoGlobal	_vehObj;
					clearMagazineCargoGlobal  _vehObj;
					clearBackpackCargoGlobal  _vehObj;
					clearItemCargoGlobal	  _vehObj;

					if !(_removeweapons isequalto []) then {
						{
							_vehObj removeWeaponGlobal _x;
						} foreach _removeweapons;
					};
					if !(_removemagazinesturret isequalto []) then {
						{
							_vehObj removeMagazinesTurret _x;
						} foreach _removemagazinesturret;
					};

					_vehObj lock true;

					_playerUID = getPlayerUID _target;
					_playerGroup = _target getVariable['GROUP', ''];

					_lockOwner = _playerUID;
					if (_playerGroup != '') then {
						_lockOwner = _playerGroup;
					};

					_vehLockHiveKey = format['%1:%2', (call EPOCH_fn_InstanceID), _slot];
					['VehicleLock', _vehLockHiveKey, EPOCH_vehicleLockTime, [_lockOwner]] call EPOCH_fnc_server_hiveSETEX;

					_cfgEpochVehicles = 'CfgEpochVehicles' call EPOCH_returnConfig;
					_availableColorsConfig = (_cfgEpochVehicles >> _item >> 'availableColors');

					if (isArray(_availableColorsConfig)) then {
						_textureSelectionIndex = (_cfgEpochVehicles >> _item >> 'textureSelectionIndex');
						_selections = if (isArray(_textureSelectionIndex)) then {getArray(_textureSelectionIndex)} else {[0]};
						_colors = getArray(_availableColorsConfig);
						_textures = _colors select 0;
						_color = floor(random(count _textures));
						_count = (count _colors) - 1;
						{
							if (_count >= _forEachIndex) then {
								_textures = _colors select _forEachIndex;
							};
							_vehObj setObjectTextureGlobal[_x, (_textures select _color)];
						} forEach _selections;
						_vehObj setVariable['VEHICLE_TEXTURE', _color];
					};

					_vehObj setVariable['VEHICLE_SLOT', _slot, true];
					_vehObj call EPOCH_server_save_vehicle;
					_vehObj call EPOCH_server_vehicleInit;
				} else {
					diag_log 'ADMIN: Unable to spawn vehicle, no slots available';
				};
			};
			_return
		};

		_allClasses = [];
		{
			_classname = _x select 0;
			_allClasses pushBack _classname;
			_type = _x select 1;
			if (_type in [0,1,2]) then {_classname call _permVehicleSpawner};
			if (_type in [3,4,5]) then {[_classname,2] call _itemSpawner};
			if (_type in [6,7]) then {[_classname,1] call _itemSpawner};
			if (_type == 8) then {[_classname,4] call _itemSpawner};
			if (_type == 9) then {[_classname,3] call _itemSpawner};
		}forEach (_content select 0);

		if (_target == _admin) then {
			[format['Spawn: %1',_allClasses], 0] call "+_skn_server_adminLog+";
		} else {
			[format['Spawn Target: %1 (%2) %3', name _target, getPlayerUID _target, _allClasses], 0] call "+_skn_server_adminLog+";
		};
	};
	if (_case == 666) then {
		_playerObj = objectFromNetId (_content select 1);
		_banID = 0;
		'epochserver' callExtension format['820|%1|"+_skn_banReason+" #%2',getPlayerUID _playerObj,_banID];
		['amb', format['%1 (%2): %3', name _playerObj, getPlayerUID _playerObj, _content select 0]] call EPOCH_fnc_server_hiveLog;
	};
};");

_skn_admincode = compileFinal ("

	waitUntil {(getPlayerUID player) != ''};
	"+_skn_tg_sortOrder+" = 'Range';
	"+_skn_tg_toggle+" = [];
	"+_skn_tg_BanPlayer+" = objNull;
	"+_skn_tg_delete+" = objNull;
	"+_skn_tg_mapTeleport+" = false;
	"+_skn_tg_old_esp+" = false;
	"+_skn_tg_godMode+" = false;
	"+_skn_tg_old_espMap+" = false;
	"+_skn_tg_spawnTyp+" = 64;
	"+_skn_tg_hideAdmin+" = false;
	"+_skn_tg_infrontTP+" = false;

	"+_skn_tg_map_player+" = false;
	"+_skn_tg_map_corpse+" = false;
	"+_skn_tg_map_loot+" = false;
	"+_skn_mapLootArray+" = [];
	"+_skn_tg_map_animals+" = false;
	"+_skn_mapAnimalArray+" = [];
	"+_skn_tg_map_vehicle+" = false;
	"+_skn_tg_map_ai+" = false;
	"+_skn_mapAIArray+" = [];
	"+_skn_tg_map_trader+" = false;
	"+_skn_tg_map_basebuilding+" = false;
	"+_skn_mapBasesArray+" = [];

	uiNamespace setVariable['ESP_mainMap', findDisplay 12 displayCtrl 51];
	uiNamespace setVariable['ESP_adminMap', findDisplay -1337 displayCtrl 7];
	(findDisplay 46) displayAddEventHandler ['KeyDown','_this call "+_skn_AdminKeyDown+"'];
	((findDisplay 12) displayCtrl 51) ctrlAddEventHandler ['MouseButtonDown', 'if (_this select 5) then {_this call "+_skn_mapTeleport+"}'];

	{
		(uiNamespace getVariable _x) ctrlRemoveAllEventHandlers 'Draw';
		(uiNamespace getVariable _x) ctrlAddEventHandler['Draw',{
			_getDmgColor = {
				_dmg = damage _this;
				[0,1,_dmg,1] call EPOCH_colorRange
			};
			_display = _this select 0;
			if ("+_skn_tg_map_player+") then {
				_size = (0.5/ctrlMapScale _display) max 20;
				{
					_display drawIcon [
						getText (configFile >> 'CfgVehicles' >> typeOf _x >> 'Icon'), _x call _getDmgColor, visiblePosition _x, _size, _size, getDir _x, name _x
					];
				}forEach (allPlayers select {alive _x});
			};
			if ("+_skn_tg_map_corpse+") then {
				_size = (1/ctrlMapScale _display) max 20;
				{
					if (!isNull _x) then {
						_color = [1,1,1,1];
						_display drawIcon [
							getText (configFile >> 'CfgVehicles' >> typeOf _x >> 'Icon'), _color, visiblePosition _x, _size, _size, getDir _x, typeOf _x
						];
					};
				}forEach allDeadMen;
			};
			if ("+_skn_tg_map_loot+") then {
				{
					if (!isNull _x) then {
						_color = [1,1,1,1];
						_display drawRectangle [
							visiblePosition _x,
							5,
							5,
							getDir _x,
							[1,1,1,1],
							'#(rgb,8,8,3)color(1,0,0,1)'
						];
					};
				}forEach "+_skn_mapLootArray+";
			};
			if ("+_skn_tg_map_animals+") then {
				_size = (0.5/ctrlMapScale _display) max 20;
				{
					if (alive _x) then {
						_display drawIcon [
							getText (configFile >> 'CfgVehicles' >> typeOf _x >> 'Icon'), _x call _getDmgColor, visiblePosition _x, _size, _size, getDir _x,
							getText (configFile >> 'CfgVehicles' >> typeOf _x >> 'displayName')
						];
					};
				}forEach "+_skn_mapAnimalArray+";
			};
			if ("+_skn_tg_map_vehicle+") then {
				_size = (1/ctrlMapScale _display) max 20;
				{
					if((_x isKindOf 'LandVehicle') || (_x isKindOf 'Ship') || (_x isKindOf 'Air') || (_x isKindOf 'Tank'))then{
						if (alive _x) then {
							_display drawIcon [
								getText (configFile >> 'CfgVehicles' >> typeOf _x >> 'Icon'), _x call _getDmgColor, visiblePosition _x, _size, _size, getDir _x,
								getText (configFile >> 'CfgVehicles' >> typeOf _x >> 'displayName')
							];
						};
					};
				}forEach vehicles;
			};
			if ("+_skn_tg_map_ai+") then {
				_size = (0.5/ctrlMapScale _display) max 20;
				{
					if (alive _x) then {
						_display drawIcon [
							getText (configFile >> 'CfgVehicles' >> typeOf _x >> 'Icon'), _x call _getDmgColor, visiblePosition _x, _size, _size, getDir _x,
							getText (configFile >> 'CfgVehicles' >> typeOf _x >> 'displayName')
						];
					};
				}forEach "+_skn_mapAIArray+";
			};
			if ("+_skn_tg_map_trader+") then {
				_size = (0.5/ctrlMapScale _display) max 20;
				{
					_agent = agent _x;
					_typeOf = typeOf _agent;
					if!(_typeOf in ['Sheep_random_EPOCH','Goat_random_EPOCH','Snake_random_EPOCH','Snake2_random_EPOCH','Hen_random_EPOCH','Cock_random_EPOCH','Fin_random_EPOCH','Alsatian_random_EPOCH','Rabbit_EPOCH'])then{
						_display drawIcon [
							getText (configFile >> 'CfgVehicles' >> _typeOf >> 'Icon'), _agent call _getDmgColor, visiblePosition _agent, _size, _size, getDir _agent,
							getText (configFile >> 'CfgVehicles' >> _typeOf >> 'displayName')
						];
					};
				}forEach agents;
			};
			if ("+_skn_tg_map_basebuilding+") then {
				_size = (1/ctrlMapScale _display) max 20;
				{
					_display drawIcon [
						getText (configFile >> 'CfgVehicles' >> 'PlotPole_Epoch' >> 'Icon'), _x call _getDmgColor, visiblePosition _x, _size, _size, getDir _x,
						str(_x getVariable ['BUILD_OWNER', _owner])+' '+(getText (configFile >> 'CfgVehicles' >> 'PlotPole_Epoch' >> 'displayName'))
					];
				}forEach "+_skn_mapBasesArray+";
			};
			if ("+_skn_tg_old_espMap+") then {
				{
					if !(isNull _x) then {
						_pos = visiblePosition _x;
						if (isPlayer _x) then {
							_lastPos = _x getVariable['ESP_old_MAP', []];
							_playerGrp = group _x;
							_grpColorIndex = EPOCH_ESPGROUPS find _playerGrp;
							if (_grpColorIndex == -1) then {
								EPOCH_ESPGROUPCOLORS pushBack[random 1, random 1, random 1, 1];
								_grpColorIndex = EPOCH_ESPGROUPS pushBack _playerGrp;
							};
							_color = EPOCH_ESPGROUPCOLORS select _grpColorIndex;
							(_this select 0) drawIcon[getText(configFile >> 'CfgVehicles' >> typeOf(vehicle _x) >> 'Icon'), _color, _pos, 0.5 / ctrlMapScale(_this select 0), 0.5 / ctrlMapScale(_this select 0), getDir _x, name _x, 1, 0.05, 'PuristaMedium'];
							if ((count _lastPos) >= 100) then {
								for '_i' from 10 to 100 step 10 do {
									_pos1 = _lastPos select(_i - 10);
									_pos2 = _lastPos select _i;
									if (!isNil '_pos1' && !isNil '_pos2') then {
										(_this select 0) drawLine[_pos1, _pos2, [1, 0, 0, 1]];
									};
								};
							};
						};
					};
				}forEach EPOCH_ESPMAP_TARGETS;
			};
		}];
	}forEach ['ESP_mainMap','ESP_adminMap'];
	"+_skn_adminRequest_PVC+" = {
		_this pushBack player;
		_this pushBack Epoch_personalToken;
		"+_skn_doAdminRequest+" = _this;
		publicVariableServer '"+_skn_doAdminRequest+"';
	};
	"+_skn_adminLog_PVC+" = {
		_this pushBack player;
		_this pushBack Epoch_personalToken;
		"+_skn_doAdminLog+" = _this;
		publicVariableServer '"+_skn_doAdminLog+"';
	};
	"+_skn_AdminKeyDown+" = {
		_keyDown = _this select 1;
		if (_keyDown == "+str _skn_adminMenuMenuKey+") then {call "+_skn_AdminMenu_Init+"};
		if (_keyDown == 0x3C) then {if (cameraOn != vehicle player) then { vehicle player switchCamera 'External' } };
		if (_keyDown == "+str _skn_adminMenuInfrontTeleport+") then {call "+_skn_infrontTP+"};
		if (_keyDown == 0x3F) then {call "+_skn_delete+"};
	};
	"+_skn_AdminMenu_Init+" = {
		disableSerialization;
		_hours = floor(servertime/60/60);
		_minutes = round((serverTime/60)-(_hours*60));

		if (!dialog) then {createDialog 'Skaronator_AdminMenu';
		{(_x call "+_skn_getCtrl+") ctrlShow false}forEach[40,41,42,43,50,51,52,60,61,62,63,64,65,66,67,68,69,70,71] };
		if (getPlayerUID player in "+str _skn_blockedSpawnMenuUID+") then {ctrlEnable [21,false]};
		ctrlEnable [22,false];
		(1 call "+_skn_getCtrl+") ctrlSetText format['Players %1 of %2',count allPlayers,playersNumber civilian];
		(2 call "+_skn_getCtrl+") ctrlSetText format['Epoch Mod Admin Menu by Skaronator.com - Server Uptime: %1h %2min', _hours, _minutes];
		(5 call "+_skn_getCtrl+") ctrlSetEventHandler ['LBDblClick', '_this call "+_skn_fnc_Spec+"'];
		(6 call "+_skn_getCtrl+") ctrlSetEventHandler ['LBDblClick', '_this call "+_skn_dbClickMainMenu+"'];
		(7 call "+_skn_getCtrl+") ctrlSetEventHandler ['MouseButtonDown', 'if (_this select 5) then {_this call "+_skn_mapTeleport+"}'];
		if (call "+_skn_removespawnMenu+") then {uiSleep 0.4};

		call "+_skn_Update_AdminButtons+";
		_menu = call "+_skn_mainMenuCfg+";
		_menu call "+_skn_FillMainMenu+";
		call "+_skn_FillPlayerMenu+";
		0 call "+_skn_switchMainMenu+";
	};
	"+_skn_hideAdmin+" = {
		"+_skn_tg_hideAdmin+" = !"+_skn_tg_hideAdmin+";
		[106, "+_skn_tg_hideAdmin+"] call "+_skn_adminRequest_PVC+";
	};
	"+_skn_esp+" = {
		_enable = false;
		if (_this) then {
			EPOCH_ESP_PLAYER = !EPOCH_ESP_PLAYER;
			if (EPOCH_ESP_PLAYER) then {
				['Player ESP',2] call "+_skn_adminLog_PVC+";
				_enable = true
			} else {
				['Player ESP',1] call "+_skn_adminLog_PVC+";
			}
		} else {
			EPOCH_ESP_VEHICLES = !EPOCH_ESP_VEHICLES;
			if (EPOCH_ESP_VEHICLES) then {
				['Vehicle ESP',2] call "+_skn_adminLog_PVC+";
				_enable = true
			} else {
				['Vehicle ESP',1] call "+_skn_adminLog_PVC+";
			}
		};

		if (EPOCH_ESP_VEHICLEPLAYER isEqualTo [] && _enable) then {
			waitUntil {
				EPOCH_ESP_VEHICLEPLAYER = (cameraOn nearEntities [['Epoch_Male_F', 'Epoch_Female_F', 'LandVehicle', 'Ship', 'Air', 'Tank'], viewDistance max 1000 min 2500]) - [vehicle player];
				uiSleep 1;
				!EPOCH_ESP_PLAYER && !EPOCH_ESP_VEHICLES
			};
			EPOCH_ESP_VEHICLEPLAYER = [];
		};
	};
	"+_skn_godMode+" = {
		"+_skn_tg_godMode+" = !"+_skn_tg_godMode+";
		if ("+_skn_tg_godMode+") then {
			['God Mode',2] call "+_skn_adminLog_PVC+";
			EPOCH_GMODE = true;
			waitUntil {
				player setBleedingRemaining 0;
				player setOxygenRemaining 1;
				player allowDamage false;
				uiSleep 0.25;
				!"+_skn_tg_godMode+"
			};
			player allowDamage true;
			EPOCH_GMODE = nil;
		} else {
			['God Mode',1] call "+_skn_adminLog_PVC+";
		}
	};
	"+_skn_repairVehicle+" = {
		"+_skn_systemDebug5+"
		_veh = objNull;
		if (_this isEqualTo []) then {
			if (vehicle player == player) then {
				_veh = cursorTarget
			} else {
				_veh = vehicle player
			}
		} else {
			_player = netId (_this select 1);
			if (vehicle _player != _player) then {
				_veh = vehicle _player
			}
		};
		"+_skn_systemDebug4+"
		if (!isNull _veh) then {
			if ((_veh isKindOf 'LandVehicle') || (_veh isKindOf 'Air') || (_veh isKindOf 'Ship') || (_veh isKindOf 'Tank')) then {
				[108,_veh] call "+_skn_adminRequest_PVC+";
				"+_skn_systemDebug3+"
			}
		}
	};
	"+_skn_spawnLoot+" = {
		_masterConfig = 'CfgBuildingLootPos' call EPOCH_returnConfig;
		_lootClasses = [];
		_lootClassesIgnore = ['Default'];
		'_cN = configName _x;if !(_cN in _lootClassesIgnore)then{_lootClasses pushBack _cN}; true' configClasses _masterConfig;
		_cntBuildings = 0;
		{
			if (_x call EPOCH_spawnLoot) then {
				_cntBuildings = _cntBuildings + 1;
			};
		}forEach (nearestObjects[player, _lootClasses, _this]);
		[format['Looting %2 Buildings within (%1)m',_this,_cntBuildings],0] call "+_skn_adminLog_PVC+";
		hint format['Spawned Loot for %1 Buildings',_cntBuildings];
	};
	"+_skn_old_esp+" = {
		"+_skn_tg_old_esp+" = !"+_skn_tg_old_esp+";
		if ("+_skn_tg_old_esp+") then {
			['ESP Old',2] call "+_skn_adminLog_PVC+";
			waitUntil{
				EPOCH_ESP_TARGETS = (cameraOn nearEntities[['Epoch_Male_F', 'Epoch_Female_F', 'LandVehicle', 'Ship', 'Air', 'Tank'], 1000]) - [vehicle player];
				uiSleep 1;
				!"+_skn_tg_old_esp+"
			};
		} else {
			['ESP Old',1] call "+_skn_adminLog_PVC+";
			EPOCH_ESP_TARGETS = [];
		};
	};
	"+_skn_old_espMap+" = {
		"+_skn_tg_old_espMap+" = !"+_skn_tg_old_espMap+";
		if ("+_skn_tg_old_espMap+") then {
			['ESP-map Old', 2] call "+_skn_adminLog_PVC+";
			waitUntil{
				uiSleep 1;
				EPOCH_ESPMAP_TARGETS = (cameraOn nearEntities[['CAManBase', 'LandVehicle', 'Ship', 'Air', 'Tank'], 10000]) - [player, vehicle player];
				{
					if (isPlayer _x) then {
						_pos = visiblePosition _x;
						_lastPos = _x getVariable['ESP_old_MAP', []];
						_lastPos pushBack _pos;
						if (count _lastPos > 101) then {
							_lastPos deleteAt 0;
						};
						_x setVariable['ESP_old_MAP', _lastPos];
					};
				}forEach EPOCH_ESPMAP_TARGETS;
				!"+_skn_tg_old_espMap+"
			};
		} else {
			['ESP-map Old', 1] call "+_skn_adminLog_PVC+";
			EPOCH_ESPMAP_TARGETS = [];
		};
	};
	"+_skn_getCtrl+" = compileFinal '(findDisplay -1337) displayCtrl _this';
	"+_skn_Update_AdminButtons+" = {
		disableSerialization;

		{((_x select 0) call "+_skn_getCtrl+") ctrlSetText (_x select 1)}forEach
		[
			[23,format['Hacker Log (%1)',count "+_skn_pv_hackerLog+"]],
			[24,format['Admin Log (%1)',count "+_skn_pv_adminLog+"]]
		];
	};
	"+_skn_mapTeleport+" = {
		if ("+_skn_tg_mapTeleport+") then {
			_pos = (_this select 0) posScreenToWorld [_this select 2, _this select 3];
			if (vehicle player == player) then {
				if (surfaceIsWater _pos) then [{vehicle player setPosASL _pos},{vehicle player setPosATL _pos}];
			} else {
				[109,_pos] call "+_skn_adminRequest_PVC+";
			};
			if (!dialog) then {openMap [false, false]};
		};
	};
	"+_skn_deleteMenu+" = [
		['Delete Menu',true],
		[format ['%1',typeOf "+_skn_tg_delete+"], [-1], '', -5, [['expression', '']], '1', '0'],
		['Delete', [2], '', -5, [['expression', '[] spawn "+_skn_deleteNow+"']], '1', '1'],
		['Exit', [0], '', -5, [['expression', '']], '1', '1']
	];
	"+_skn_deleteNow+" = {
		if (!isNull "+_skn_tg_delete+") then {
			if (!isPlayer "+_skn_tg_delete+") then {
				[104,"+_skn_tg_delete+"] call "+_skn_adminRequest_PVC+";
			};
		};
		"+_skn_tg_delete+" = objNull;
	};
	"+_skn_delete+" = {
		showCommandingMenu '';
		if (!isNull cursorTarget) then {
			"+_skn_tg_delete+" = cursorTarget;
			showCommandingMenu '#USER:"+_skn_deleteMenu+"';
		};
	};
	"+_skn_fnc_Spec+" = {
		_player = objectFromNetId (_this select 0 lbData (_this select 1));
		if (isNull _player) exitWith {};
		if (!isPlayer _player) exitWith {};
		cutText ['F2 To Cancel!','PLAIN DOWN',1];
		vehicle _player switchCamera 'External';
	};
	"+_skn_mainMenuCfg+" = {"+_skn_adminMenuLow+"};
	if (getPlayerUID player in "+str _skn_adminsOwner+") then {
		"+_skn_mainMenuCfg+" = {"+_skn_adminMenuOwner+"};
	};
	if (getPlayerUID player in "+str _skn_adminsHigh+") then {
		"+_skn_mainMenuCfg+" = {"+_skn_adminMenuHigh+"};
	};
	"+_skn_freeCam+" = {
		_getPos = player modelToWorld[0, -1.5, 1.75];
		_cam = 'camera' camCreate _getPos;
		_cam setDir (_getPos getDir player);
		_cam camCommand 'MANUAL ON';
		_cam camCommand 'INERTIA OFF';
		_cam cameraEffect['INTERNAL', 'BACK'];
		showCinemaBorder false;
		cutText['Right Click To Cancel!', 'PLAIN DOWN', 1];
	};
	"+_skn_FillMainMenu+" = {
		lbClear (8 call "+_skn_getCtrl+");
		_ctrl = 6 call "+_skn_getCtrl+";
		lbClear _ctrl;
		for '_i' from 0 to count _menu -1 do {
			_item = _menu select _i;

			_titleoption = _item select 3;
			_color = _item select 4;

			_index = _ctrl lbAdd format['%1',_item select 0];
			if (count _color == 0) then {
				_color = [1, 1, 1, 1];
				if (_titleoption == '1') then {_color = [0.42,0.64,0.88,1]};
				if (_titleoption == '3') then {_color = [0.27,0.39,0.53,1]};
			};

			if (_titleoption == '2') then {
				_color = if (_index in "+_skn_tg_toggle+") then [{[0.17,1,0,1]},{[0.51,0.51,0.51,1]}];
			};

			_ctrl lbSetColor [_i,_color];
			_ctrl lbSetData [_i,str [_item select 1,_item select 2,_titleoption]];
		};
	};
	"+_skn_switchMainMenu+" = {
		disableSerialization;

		_main = 6 call "+_skn_getCtrl+";
		_map = 7 call "+_skn_getCtrl+";
		_table = 8 call "+_skn_getCtrl+";
		if (_this == 0) then {
			_main ctrlSetPosition [0.293698 * safezoneW + safezoneX,0.2888 * safezoneH + safezoneY,0.206297 * safezoneW,0.4862 * safezoneH];
			_map ctrlSetPosition [0.501031 * safezoneW + safezoneX,0.28836 * safezoneH + safezoneY,0.205265 * safezoneW,0.486548 * safezoneH];
			_table ctrlShow false;
			_table ctrlSetPosition [0.293698 * safezoneW + safezoneX,0.2888 * safezoneH + safezoneY,0.206297 * safezoneW,0.4862 * safezoneH];
			_table ctrlCommit 0;
			_main ctrlSetFade 0;
			_map ctrlShow true;
		};
		if (_this in [1,2]) then {
			{(_x call "+_skn_getCtrl+") ctrlShow false}forEach[30,31,32,33,34];

			_main ctrlSetPosition [0.293698 * safezoneW + safezoneX,0.2888 * safezoneH + safezoneY,0.412598 * safezoneW,0.4862 * safezoneH];
			_map ctrlSetPosition [0.709388 * safezoneW + safezoneX,0.28836 * safezoneH + safezoneY,-0.00312413 * safezoneW,0.486548 * safezoneH];
			_main ctrlSetFade 0;
			if (_this == 2) then {
				_main ctrlcommit 0;
				_main ctrlSetFade 1;
			};
		};
		_main ctrlCommit 0.8;
		_map ctrlCommit 0.8;
	};
	"+_skn_dbClickMainMenu+" = {
		_currentSelect = _this select 1;
		_data = call compile (_this select 0 lbData _currentSelect);
		_tO = _data select 2;

		if (_tO == '1') exitWith {};
		if (_tO == '2') exitWith {
			(_data select 0) spawn (_data select 1);
			if (_currentSelect in "+_skn_tg_toggle+") then {
				lbSetColor [6,_currentSelect,[0.51,0.51,0.51,1]];
				"+_skn_tg_toggle+" = "+_skn_tg_toggle+" - [_currentSelect];
			} else {
				lbSetColor [6,_currentSelect,[0.165,1,0,1]];
				"+_skn_tg_toggle+" pushBack _currentSelect;
			};
		};
		if (_tO == '4') exitWith {
			if ((lbCurSel 5) >= 0) then {
				[_text,lbData [5, lbCurSel 5],(_data select 0)] spawn (_data select 1);
			};
		};
		if ((_data select 1) isEqualType {}) then {(_data select 0) spawn (_data select 1)};
	};
	Skaronator_fnc_handleButton = compileFinal ('
		disableSerialization;
		_idc = ctrlIDC (_this select 0);
		if (_idc == 10) then { "+_skn_tg_sortOrder+" = ''Range''; call "+_skn_FillPlayerMenu+"};
		if (_idc == 11) then { "+_skn_tg_sortOrder+" = ''Alphabetically''; call "+_skn_FillPlayerMenu+"};

		if (_idc == 20) then {call "+_skn_AdminMenu_Init+"};
		if (_idc == 21) then {call "+_skn_spawnMenu+"};

		if (_idc == 23) then {call "+_skn_hackerLog+"};
		if (_idc == 24) then {call "+_skn_adminLog+"};

		if (_idc == 32) then {true call "+_skn_doBan+"};
		if (_idc == 33) then {false call "+_skn_doBan+"};

		if (_idc == 50) then {lbClear 43;"+_skn_tg_limitSpawn+" = [true,true,true,true,true,true,true,true,true,true,true]};
		if (_idc == 51) then {true call "+_skn_spawnSpawnMenu+"};
		if (_idc == 52) then {false call "+_skn_spawnSpawnMenu+"};
		if (_idc in [61,62,63,64,65,66,67,68,69,70,71]) then {
			"+_skn_tg_spawnTyp+" = _idc;
			_idc call "+_skn_fillSpawnMenu+";
		};
	');
	"+_skn_spawnSpawnMenu+" = {
		_target = objNull;
		if (_this) then {
			if ((lbCurSel 5) >= 0) then {
				_target = objectFromNetId (lbData [5, lbCurSel 5]);
			};
		} else {
			_target = player;
		};
		if (isNull _target) exitWith {};
		_ctrl = 43 call "+_skn_getCtrl+";
		_spawn = [];
		for '_i' from 0 to (lbSize _ctrl)-1 do {
			_data = call compile (_ctrl lbData _i);
			_spawn pushBack [_data select 0, _data select 2];
		};
		lbClear _ctrl;
		"+_skn_tg_limitSpawn+" = [true,true,true,true,true,true,true,true,true,true,true];
		"+_skn_systemDebug2+"
		[555,[_spawn,netId _target]] call "+_skn_adminRequest_PVC+";
	};
	"+_skn_spawnMenu+" = {
		false call "+_skn_doBan+";
		if (!isNull "+_skn_tg_BanPlayer+") then {uiSleep 0.8;false spawn "+_skn_switchTable+"};
		2 call "+_skn_switchMainMenu+";
		lbclear (6 call "+_skn_getCtrl+");
		_table = 8 call "+_skn_getCtrl+";
		lbclear _table;
		_table ctrlShow false;
		"+_skn_tg_limitSpawn+" = [true,true,true,true,true,true,true,true,true,true,true];
		comment '[primaryWeapon,secondaryWeapon,launcher,backpack,map,rangefinderSlot,vehicleSlot]';
		(41 call "+_skn_getCtrl+") ctrlSetEventHandler ['LBDblClick', ""
			_ctrl = _this select 0;
			_currentSelect = _this select 1;
			_type = call compile (_ctrl lbData _currentSelect) select 1;
			_allowed = true;
			if (_type != -1) then {
				_allowed = "+_skn_tg_limitSpawn+" select _type;
				"+_skn_tg_limitSpawn+" set [_type,false];
			};
			"+_skn_systemDebug1+"
			if (_allowed) then {
				_otherList = 43 call "+_skn_getCtrl+";
				_index = _otherList lbAdd format ['%1',_ctrl lbText _currentSelect];
				_otherList lbSetData [_index, _ctrl lbData _currentSelect];
				_otherList lbSetPicture [_index,_ctrl lbPicture _currentSelect];
			} else {
				hint 'You can just select one Weapon/Item of this Type!';
			};
		""];

		(43 call "+_skn_getCtrl+") ctrlSetEventHandler ['LBDblClick', '
			_ctrl = _this select 0;
			_currentSelect = _this select 1;
			_type = call compile (_ctrl lbData _currentSelect) select 1;
			if (_type != -1) then {
				"+_skn_tg_limitSpawn+" set [_type,true];
			};
			_ctrl lbDelete _currentSelect;
		'];

		{_i = _x call "+_skn_getCtrl+";_i ctrlShow true;_i ctrlSetFade 1;_i ctrlcommit 0;_i ctrlSetFade 0;_i ctrlcommit 0.8}forEach[40,41,42,43,50,51,52,60,61,62,63,64,65,66,67,68,69,70,71];
		"+_skn_tg_spawnTyp+" call "+_skn_fillSpawnMenu+";
	};
	"+_skn_removespawnMenu+" = {
		if (ctrlShown (40 call "+_skn_getCtrl+")) then {
			{_i = _x call "+_skn_getCtrl+";_i ctrlShow true;_i ctrlSetFade 1;_i ctrlcommit 0.8}forEach[40,41,42,43,50,51,52,60,61,62,63,64,65,66,67,68,69,70,71];
			[] spawn {uiSleep 0.8;{_x call "+_skn_getCtrl+" ctrlShow false}forEach[40,41,42,43,50,51,52,60,61,62,63,64,65,66,67,68,69,70,71]};
			true
		} else {false};
	};
	"+_skn_fillSpawnMenu+" = {
		_ctrl = 41 call "+_skn_getCtrl+";
		lbclear _ctrl;
		_button = _this call "+_skn_getCtrl+";
		_button ctrlSetTextColor [1, 0, 0, 1];
		{_x call "+_skn_getCtrl+" ctrlSetTextColor [1, 1, 1, 1]}forEach([61,62,63,64,65,66,67,68,69,70,71]-[_this]);
		_cfgPricing = 'CfgPricing' call EPOCH_returnConfig;
		if (_this == 61) then {
			_airVehicles = ""
				getText(_x >> 'displayName') != '' &&
				getText(_x >> 'picture') != '' &&
				getNumber(_x >> 'type') != 0 &&
				getText (_x >> 'vehicleClass') in ['Air'] &&
				isClass(_cfgPricing >> configName _x)
			""configClasses (configFile >> 'CfgVehicles');
			{
				_index = _ctrl lbAdd format['%1', getText(_x >> 'displayName')];
				_ctrl lbSetData[_index, str[configName _x, 6, 0]];
				_ctrl lbSetPicture[_index, getText(_x >> 'picture')];
			}forEach _airVehicles;
		};
		if (_this == 62) then {
			_landVehicles = ""
				getText(_x >> 'displayName') != '' &&
				getText(_x >> 'picture') != '' &&
				configName _x != 'PaperCar' &&
				getText (_x >> 'vehicleClass') in ['Car'] &&
				isClass(_cfgPricing >> configName _x)
			""configClasses (configFile >> 'CfgVehicles');
			{
				_index = _ctrl lbAdd format['%1', getText(_x >> 'displayName')];
				_ctrl lbSetData[_index, str[configName _x, 6, 1]];
				_ctrl lbSetPicture[_index, getText(_x >> 'picture')];
			}forEach _landVehicles;
		};
		if (_this == 63) then {
			_shipVehicles = ""
				getText(_x >> 'displayName') != '' &&
				getText(_x >> 'picture') != '' &&
				getNumber(_x >> 'type') in [1,2,3,4] &&
				getText (_x >> 'vehicleClass') in ['Ship'] &&
				isClass(_cfgPricing >> configName _x)
			""configClasses (configFile >> 'CfgVehicles');
			{
				_index = _ctrl lbAdd format['%1', getText(_x >> 'displayName')];
				_ctrl lbSetData[_index, str[configName _x, 6, 2]];
				_ctrl lbSetPicture[_index, getText(_x >> 'picture')];
			}forEach _shipVehicles;
		};
		if (_this == 64) then {
			_weapons = ""
				getText(_x >> 'displayName') != '' &&
				getText(_x >> 'picture') != '' &&
				getNumber(_x >> 'scope') in [1,2] &&
				getNumber(_x >> 'type') in [1,2,4] &&
				isClass(_cfgPricing >> configName _x)
			""configClasses (configFile >> 'CfgWeapons');
			{
				_index = _ctrl lbAdd format['%1', getText(_x >> 'displayName')];
				_type = getNumber(_x >> 'type') - 1;
				if (getNumber(_x >> 'type') == 4) then { _type = 2 };
				_ctrl lbSetData[_index, str[configName _x, _type, _type + 3]];
				_ctrl lbSetPicture[_index, getText(_x >> 'picture')];
			}forEach _weapons;
		};
		if (_this == 65) then {
			_magazines = ""
				getText(_x >> 'displayName') != '' &&
				getText(_x >> 'picture') != '' &&
				getNumber(_x >> 'scope') in [1,2] &&
				getText(_x >> 'ammo') != '' &&
				isClass(_cfgPricing >> configName _x)
			""configClasses (configFile >> 'CfgMagazines');
			{
				_index = _ctrl lbAdd format['%1', getText(_x >> 'displayName')];
				_ctrl lbSetData[_index, str[configName _x, -1, 6]];
				_ctrl lbSetPicture[_index, getText(_x >> 'picture')];
			}forEach _magazines;
		};
		if (_this == 66) then {
			_magazines = ""
				getText(_x >> 'displayName') != '' &&
				getText(_x >> 'picture') != '' &&
				getNumber(_x >> 'scope') in [1,2] &&
				getText(_x >> 'ammo') == '' &&
				isClass(_cfgPricing >> configName _x)
			""configClasses(configFile >> 'CfgMagazines');
			{
				_index = _ctrl lbAdd format['%1', getText(_x >> 'displayName')];
				_ctrl lbSetData[_index, str[configName _x, -1, 7]];
				_ctrl lbSetPicture[_index, getText(_x >> 'picture')];
			}forEach _magazines;
		};
		if (_this == 67) then {
			_backpack = ""
				getText(_x >> 'displayName') != '' &&
				getText(_x >> 'picture') != '' &&
				getNumber(_x >> 'isbackpack') == 1 &&
				isClass(_cfgPricing >> configName _x)
			""configClasses(configFile >> 'CfgVehicles');
			{
				_index = _ctrl lbAdd format['%1', getText(_x >> 'displayName')];
				_ctrl lbSetData[_index, str[configName _x, 3, 8]];
				_ctrl lbSetPicture[_index, getText(_x >> 'picture')];
			}forEach _backpack;
		};
		if (_this == 68) then {
			_uniforms = ""
				getText(_x >> 'displayName') != '' &&
				getText(_x >> 'picture') != '' &&
				getNumber(_x >> 'scope') in [1,2] &&
				getNumber(_x >> 'ItemInfo' >> 'type') in [801] &&
				isClass(_cfgPricing >> configName _x)
			""configClasses(configFile >> 'CfgWeapons');
			{
				_index = _ctrl lbAdd format['%1', getText(_x >> 'displayName')];
				_ctrl lbSetData[_index, str[configName _x, -1, 9]];
				_ctrl lbSetPicture[_index, getText(_x >> 'picture')];
			}forEach _uniforms;
		};
		if (_this == 69) then {
			_attachments = ""
				getText(_x >> 'displayName') != '' &&
				getText(_x >> 'picture') != '' &&
				getNumber(_x >> 'scope') in [1,2] &&
				((configName _x) call BIS_fnc_itemType) select 0 in ['Item'] &&
				isClass(_cfgPricing >> configName _x)
			""configClasses(configFile >> 'CfgWeapons');
			{
				_index = _ctrl lbAdd format['%1', getText(_x >> 'displayName')];
				_ctrl lbSetData[_index, str[configName _x, -1, 9]];
				_ctrl lbSetPicture[_index, getText(_x >> 'picture')];
			}forEach _attachments;
		};
		if (_this == 70) then {
			_headgear = ""
				getText(_x >> 'displayName') != '' &&
				getText(_x >> 'picture') != '' &&
				getNumber(_x >> 'scope') in [1,2] &&
				((configName _x) call BIS_fnc_itemType) select 1 in ['Headgear'] &&
				isClass(_cfgPricing >> configName _x)
			""configClasses(configFile >> 'CfgWeapons');
			{
				_index = _ctrl lbAdd format['%1', getText(_x >> 'displayName')];
				_ctrl lbSetData[_index, str[configName _x, -1, 9]];
				_ctrl lbSetPicture[_index, getText(_x >> 'picture')];
			}forEach _headgear;
		};
		if (_this == 71) then {
			_vests = ""
				getText(_x >> 'displayName') != '' &&
				getText(_x >> 'picture') != '' &&
				getNumber(_x >> 'scope') in [1,2] &&
				((configName _x) call BIS_fnc_itemType) select 1 in ['Vest'] &&
				isClass(_cfgPricing >> configName _x)
			""configClasses(configFile >> 'CfgWeapons');
			{
				_index = _ctrl lbAdd format['%1', getText(_x >> 'displayName')];
				_ctrl lbSetData[_index, str[configName _x, -1, 9]];
				_ctrl lbSetPicture[_index, getText(_x >> 'picture')];
			}forEach _vests;
		};
	};
	"+_skn_FillPlayerMenu+" = {
		_ctrl = 5 call "+_skn_getCtrl+";
		lbclear _ctrl;

		_sorted = [];
		_unsorted = allPlayers;

		_buttonRange = 10 call "+_skn_getCtrl+";
		_buttonRange ctrlSetText 'Range';
		_buttonAlphabetically = 11 call "+_skn_getCtrl+";
		_buttonAlphabetically ctrlSetText 'Alphabet';

		if ("+_skn_tg_sortOrder+" == 'Range') then {
			_pos = getPosATL vehicle player;
			{
				_temp = _x;
				{
					if ((getPosATL _x distance _pos) < (getPosATL _temp distance _pos)) exitWith {
						_unsorted = _unsorted - [_x];
						_sorted pushBack _x;
					_temp = _x;
				};
			}forEach _unsorted;
		}forEach _unsorted;
		_buttonRange ctrlSetTextColor [1, 0, 0, 1];
		_buttonAlphabetically ctrlSetTextColor [1, 1, 1, 1];
	};
	if ("+_skn_tg_sortOrder+" == 'Alphabetically') then {
		_unsortedName = [];
		{
			_unsortedName pushBack (name _x);
		}forEach _unsorted;
		_alphabetically = _unsortedName;
		_alphabetically sort true;
		{
			{
				if (name _x == (_alphabetically select 0)) exitWith {
					_alphabetically = _alphabetically - [_alphabetically select 0];
					_unsorted = _unsorted - [_x];
					_sorted pushBack _x;
				};
			}forEach _unsorted;
		}forEach _unsorted;

		_buttonAlphabetically ctrlSetTextColor [1, 0, 0, 1];
		_buttonRange ctrlSetTextColor [1, 1, 1, 1];
	};
	if (_sorted isEqualTo []) then {_sorted = [player]};
	_skn_fnc_addPlayerToList = {
		_player = _this select 0;
		_index = _ctrl lbAdd format ['%1', name _player];
		_ctrl lbSetData [_index, netId _player];
		_ctrl lbSetColor [_index, _this select 1];
		if (vehicle _player == _player) then {
			_pic = '';
			if (currentWeapon _player != '') then {
				_pic = getText(configFile >> 'CfgWeapons' >> currentweapon _player >> 'picture')
			} else {
				if (primaryWeapon _player == '') then {
					_pic = getText(configFile >> 'CfgVehicles' >> typeof vehicle _player >> 'picture')
				} else {
					_pic = getText(configFile >> 'CfgWeapons' >> primaryweapon _player >> 'picture')
				};
			};
			_ctrl lbSetPicture [_index,_pic];
		} else {
			_ctrl lbSetPicture [_index,getText(configFile >> 'CfgVehicles' >> typeof vehicle _player >> 'picture')];
		};
	};

	_ctrl lbAdd '	  Admins';
	_ctrl lbSetColor [(lbsize _ctrl)-1, [0,0.6,1,1]];
	{
		if (getPlayerUID _x in "+str _skn_adminUIDArray+") then {_sorted = _sorted - [_x];[_x,[0,1,0,1]] call _skn_fnc_addPlayerToList};
	}forEach _sorted;
	_ctrl lbAdd '';
	_ctrl lbAdd '	  Normal Player';
	_ctrl lbSetColor [(lbsize _ctrl)-1, [1,1,1,1]];

	{
		if (vehicle _x == _x) then {_sorted = _sorted - [_x];[_x,[0,1,0,1]] call _skn_fnc_addPlayerToList};
	}forEach _sorted;
	_ctrl lbAdd '';
	_ctrl lbAdd '	  Vehicle Player';
	_ctrl lbSetColor [(lbsize _ctrl)-1, [1,1,1,1]];

	{[_x,[0,1,0,1]] call _skn_fnc_addPlayerToList}forEach _sorted;
	_ctrl lbAdd '';_ctrl lbAdd '';
};
"+_skn_switchTable+" = {
	disableSerialization;
	_map = 7 call "+_skn_getCtrl+";
	_table = 8 call "+_skn_getCtrl+";

	if ((ctrlPosition _table) isEqualTo [0.293698 * safezoneW + safezoneX,0.2888 * safezoneH + safezoneY,0.206297 * safezoneW,0.4862 * safezoneH]) then {
		_table ctrlSetPosition [0.293698 * safezoneW + safezoneX,0.2888 * safezoneH + safezoneY,0.206297 * safezoneW,0.4862 * safezoneH];
		_table ctrlCommit 0;


		_table ctrlSetEventHandler ['LBSelChanged', 'if ((_this select 1) != -1) then {lnbSetCurSelRow [8,-1]};'];

		_table ctrlShow _this;
		_table ctrlSetPosition [0.293698 * safezoneW + safezoneX,0.2888 * safezoneH + safezoneY,0.412598 * safezoneW,0.4862 * safezoneH];
		_table ctrlCommit 0.8;
	};

	_time = diag_tickTime;
	waitUntil {
		if (diag_tickTime-_time>1) exitWith {true};
		if ((ctrlPosition _map) isEqualTo [0.709388 * safezoneW + safezoneX,0.28836 * safezoneH + safezoneY,-0.00312413 * safezoneW,0.486548 * safezoneH]) exitWith {_map ctrlShow false;true};
	};
};
"+_skn_hackerLog+" = {
	1 call "+_skn_switchMainMenu+";

	lbClear (6 call "+_skn_getCtrl+");
	_table = 8 call "+_skn_getCtrl+";
	lbClear _table;
	true spawn "+_skn_switchTable+";
	if (call "+_skn_removespawnMenu+") then {
		uiSleep 0.4;
		_table ctrlSetFade 1;
		_table ctrlcommit 0;
		_table ctrlSetFade 0;
		_table ctrlcommit 0.8;
	};

	_table ctrlShow true;
	_table lnbAddRow ['==================================== HACKER LOG ======================================'];

	{
		_player = _x select 0;
		_color = _x select 1;

		_index = _table lnbAddRow [_player select 1,_player select 2,nil,if (_player select 0 == 0) then [{format['BANNED: %1',_player select 4]},{_player select 4}]];
		if (count _color > 0) then {
			lnbSetColor [8,[_index,0],_color];
			lnbSetColor [8,[_index,1],_color];
			lnbSetColor [8,[_index,3],_color];
		};
	}forEach "+_skn_pv_hackerLog+";
};
"+_skn_adminLog+" = {
	1 call "+_skn_switchMainMenu+";
	lbClear (6 call "+_skn_getCtrl+");

	_table = 8 call "+_skn_getCtrl+";
	lbClear _table;
	true spawn "+_skn_switchTable+";
	if (call "+_skn_removespawnMenu+") then {uiSleep 0.4;
		_table ctrlSetFade 1;
		_table ctrlcommit 0;
		_table ctrlSetFade 0;
		_table ctrlcommit 0.8;
	};

	_table ctrlShow true;
	_table lnbAddRow ['===================================== ADMIN LOG ======================================'];

	{_table lnbAddRow _x}forEach "+_skn_pv_adminLog+";
};
"+_skn_flipVehicle+" = {
	_target = cursorTarget;
	if (isNull _target) then {
		_vehicles = player nearEntities[['LandVehicle', 'Ship', 'Air'], 15];
		if !(_vehicles isEqualTo []) then {
			_target = _vehicles select 0;
		};
	};

	if (!isNull _target) then {
		if (!isPlayer _target) then {
			_target setVectorUp [0, 0, 1];
			cutText [format ['Unflipping Vehicle..'],'PLAIN DOWN'];
		};
	};
};
"+_skn_infrontTP+" = {
	"+_skn_tg_infrontTP+" = !"+_skn_tg_infrontTP+";
	if ("+_skn_tg_infrontTP+") then {
		if (vehicle player == player) then {
			_distance = 10;
			_object = vehicle player;
			_dir = getdir _object;
			_pos = getPosATL _object;
			if (_object isKindOf 'Air') then {
				_distance = 50;
				_pos = [(_pos select 0)+_distance*sin(_dir),(_pos select 1)+_distance*cos(_dir),((getpos _object) select 2)+100];
			} else {
				_pos = [(_pos select 0)+_distance*sin(_dir),(_pos select 1)+_distance*cos(_dir),0];
				if (surfaceIsWater _pos) then {_pos set [2,2]};
			};
			if (surfaceIsWater _pos) then [{vehicle player setPosASL _pos},{vehicle player setPosATL _pos}];
		} else {
			cutText ['You can just Teleport Infront when you are not inside of a Vehicle!','PLAIN DOWN'];
		};
	};
};
"+_skn_customBanreason+" = {
	disableSerialization;
	_player = objectFromNetId (_this select 1);
	_name = name _player;
	{(_x call "+_skn_getCtrl+") ctrlShow true}forEach[30,31,32,33,34];

	_edit = 31 call "+_skn_getCtrl+";
	_edit ctrlSetText '';
	if ((_this select 2) isEqualType 'STRING') then {
		_edit ctrlSetText format['%1',(_this select 2)];
	};

	_text = 34 call "+_skn_getCtrl+";
	_text ctrlSetText format ['Custom Banreason for %1:',_name];
	"+_skn_tg_BanPlayer+" = _player;
	findDisplay -1337 displayAddEventHandler ['Unload', {"+_skn_tg_BanPlayer+" = objNull}];

	_map = 7 call "+_skn_getCtrl+";
	_map ctrlSetPosition [0.501031 * safezoneW + safezoneX,0.44456 * safezoneH + safezoneY,0.205265 * safezoneW,0.328148 * safezoneH];
	_map ctrlCommit 0.8;
};
"+_skn_doBan+" = {
	disableSerialization;
	if (_this && !isNull "+_skn_tg_BanPlayer+") then {
		_reason = ctrlText 31;
		if (_reason == '') then {
			ctrlSetText [31, 'Please enter a banreason!'];
		} else {
			[666,[_reason,netId "+_skn_tg_BanPlayer+"]] call "+_skn_adminRequest_PVC+";
		};
	};

	{_i = _x call "+_skn_getCtrl+";_i ctrlShow false;_i ctrlShow true}forEach[32,33];

	"+_skn_tg_BanPlayer+" = objNull;

	_map = 7 call "+_skn_getCtrl+";
	_map ctrlSetPosition [0.501031 * safezoneW + safezoneX,0.28836 * safezoneH + safezoneY,0.205265 * safezoneW,0.486548 * safezoneH];
	_map ctrlCommit 0.8;
};
");

_skn_admininit = compileFinal ("waitUntil {(!isNil '"+_skn_Admin_Code+"') && (!isNil '"+_skn_pv_adminLog+"') && (!isNil '"+_skn_pv_hackerLog+"')};[] spawn "+_skn_Admin_Code+"");
call compile (_skn_Admin_Code+" = _skn_admincode");

missionNamespace setVariable [_skn_Admin_Init, _skn_admininit, true];
