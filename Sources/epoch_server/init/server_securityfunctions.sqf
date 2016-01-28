comment 'Epoch Mod Antihack - Niklas Wagner - www.skaronator.com - Aaron Clark - www.epochmod.com - License: (CC) Attribution-NonCommercial-NoDerivatives 4.0 International';

/* ANTIHACK SETTINGS */

_config = (configFile >> "CfgSecConf");
if (isClass _config) then {diag_log "Loading config..."};

_debugClass = if ([_config,"debug",false] call EPOCH_fnc_returnConfigEntry) then { "DebugActive" } else { "DebugDisabled" };

_cfg_systemDebug  = (_config >> _debugClass);
_skn_systemDebug1 = getText(_cfg_systemDebug >> "systemChat1");
_skn_systemDebug2 = getText(_cfg_systemDebug >> "systemChat2");
_skn_systemDebug3 = getText(_cfg_systemDebug >> "systemChat3");
_skn_systemDebug4 = getText(_cfg_systemDebug >> "systemChat4");
_skn_systemDebug5 = getText(_cfg_systemDebug >> "systemChat5");

_cfg_limits = (_config >> "limits");
_skn_playerCryptoLimit = [_cfg_limits, "playerCrypto", 25000] call EPOCH_fnc_returnConfigEntry;

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
_skn_badVarCheckArray = [_cfg_variablesConfig, "badVars", ['ESP_map','ESP_mainMap','ESP_adminMap','AntiAntiAntiAntiHax','fnc_usec_damageHandler','fnc_usec_unconscious','VAGINA_secret','yolo','VERSION','life_fnc_handleDamage','EPOCH_spawnVehicle_PVS','CLASS911_Menu','nuke_vars','JJMMEE_INIT_MENU','PLAYERON','PLAYERNEXT2','ALTISLIFEON','LY_Menu','PLAY','LY_SwaggerLikeUs','BIS_fnc_dbg_reminder_value','BIS_fnc_dbg_reminder']] call EPOCH_fnc_returnConfigEntry;
_skn_nilVarCheckArray = [_cfg_variablesConfig, "nilVars", ['EPOCH_antiWallCount','EPOCH_playerEnergy','EPOCH_playerHunger','EPOCH_playerStamina','EPOCH_playerCrypto','EPOCH_target','EPOCH_ESP_TARGETS','EPOCH_ESPMAP_TARGETS','EPOCH_taxRate','EPOCH_ESP_VEHICLEPLAYER','EPOCH_ESP_PLAYER','EPOCH_ESP_VEHICLES']] call EPOCH_fnc_returnConfigEntry;
_skn_commandMenuArray = [(_config >> "commandMenu"), "menus",['','RscSelectTeam','RscTeam','RscMoveHigh','#GETIN','#RscStatus','#WATCH0','RscCombatMode','RscMenuReply','RscCallSupport','#CUSTOM_RADIO','#User:BIS_fnc_addCommMenuItem_menu','RscRadio','RscReply','#ACTION','RscMenuFormations','#WATCH','RscGroupRootMenu','RscMainMenu','RscMenuMove','RscWatchDir','RscWatchMoveDir','#User:BIS_Menu_GroupCommunication','RscMenuStatus','RscFormations']] call EPOCH_fnc_returnConfigEntry;

_skn_displayAddEHKeyDown = [(_config >> "displayAddEventHandler"), "keyDown",'_this call EPOCH_KeyDown'] call EPOCH_fnc_returnConfigEntry;
_skn_displayAddEHKeyUp   = [(_config >> "displayAddEventHandler"), "keyUp",'_this call EPOCH_KeyUp'] call EPOCH_fnc_returnConfigEntry;

_skn_addEHConfig		= (_config >> "addEventHandler");
_skn_displayAddEHChecks = [_skn_addEHConfig, "checks",[]] call EPOCH_fnc_returnConfigEntry;

_skn_addEHArray = [];
{
	_code = [_skn_addEHConfig, _x,""] call EPOCH_fnc_returnConfigEntry;
	_skn_addEHArray pushBack [_x,_code,(_code != "")];
} forEach _skn_displayAddEHChecks;


_serverSettingsConfig = configFile >> "CfgEpochServer";
_skn_enableAntihack = [_serverSettingsConfig, "antihack_Enabled", true] call EPOCH_fnc_returnConfigEntry;
_skn_check_addons = [_serverSettingsConfig, "antihack_cfgPatchesCheck", true] call EPOCH_fnc_returnConfigEntry;
_checkFiles = [
	["\x\addons\a3_epoch_code\compile\setup\EPOCH_clientInit.sqf", "EPOCH_clientInit"],
	["\x\addons\a3_epoch_code\compile\EPOCH_onEachFrame.sqf", "EPOCH_onEachFrame"],
	["\x\addons\a3_epoch_code\compile\setup\EPOCH_masterLoop.sqf", "EPOCH_masterLoop"],
	["\x\addons\a3_epoch_code\compile\setup\EPOCH_client_rejectPlayer.sqf", "EPOCH_client_rejectPlayer"],
	["\x\addons\a3_epoch_code\compile\setup\EPOCH_clientRespawn.sqf", "EPOCH_clientRespawn"],
	["\x\addons\a3_epoch_code\compile\interface_event_handlers\EPOCH_KeyDown.sqf", "EPOCH_KeyDown"]
];
_skn_check_files = [_serverSettingsConfig, "antihack_checkFiles", _checkFiles] call EPOCH_fnc_returnConfigEntry;
_whitelistPatches = ["A3Data","A3_BaseConfig_F","A3_Dubbing_Radio_F","A3_Functions_F","A3_Functions_F_EPA","A3_Functions_F_EPC","A3_Language_F_MP_Mark","A3_LanguageMissions_F_MP_Mark","Map_VR","A3_Map_VR_Scenes","CUP_A10_Data","CUP_Afghan_Data","CUP_Air2_Data","CUP_Air3_Data","CUP_Air_Data","CUP_Air_d_baf_Data","CUP_Air_e_Data","CUP_Air_pmc_Data","CUP_CA_animals2","CA_animals2","CUP_Animations_Data","CUP_Animations_Config","CUP_Bohemia_Data","CUP_Bootcamp_acr_Data","CUP_Buildings2_Data","CUP_Buildings2_Ind_Cementworks_Data","CUP_Buildings_Data","CUP_Ca_acr_Data","CUP_CA_Config","CAData","CUP_Ca_e_Data","CUP_Ca_pmc_Data","CUP_Characters2_Data","CUP_Chernarus_Data","CUP_Chernarus_Summer_Data","CUP_Cti_buildings_Data","CUP_CA_Data","CUP_CAData_ParticleEffects","CAData_ParticleEffects","CUP_Data_baf_Data","CUP_dbe1_data","CUP_Desert2_Data","CUP_Desert2_Objects","Desert2_Objects","CUP_Desert_Data","CUP_Desert_e_Data","CUP_Hotfix_Data","CUP_L39_Data","CUP_CALanguage","CALanguage","CUP_CALanguage_ACR","CALanguage_ACR","CUP_CALanguage_missions","CALanguage_missions","CUP_CALanguage_missions_e","CALanguage_missions_e","CUP_Misc3_Data","CUP_CAMisc","CUP_Misc_Data","CAMisc","CUP_Misc_acr_Data","CUP_Misc_e_Data","CUP_CA_MPA","CA_MPA","CUP_CA_Plants2_Clutter","CA_Plants2_Clutter","CUP_CAPlants","CAPlants","CUP_CA_Plants_E_Clutter","CA_Plants_E_Clutter","CUP_Provinggrounds_pmc_Data","CUP_CARoads2","CARoads2","CUP_CARoads2Dam","CARoads2Dam","CUP_CARoads","CARoads","CUP_CARoads_E","CARoads_E","CUP_CARoads_PMC","CARoads_PMC","CUP_CARocks2","CARocks2","CUP_CARocks","CARocks","CUP_CARocks_E","CARocks_E","CUP_Sara_Data","CUP_Saralite_Data","CUP_Shapur_baf_Data","CUP_CASigns","CASigns","CUP_CASigns_E","CASigns_E","CUP_Sounds_Data","CUP_Sounds_Config","CASounds","CUP_Sounds_e_Data","CUP_Structures_Data","CUP_pond_test","pond_test","CUP_Structures_e_Data","CUP_Structures_pmc_Data","CUP_Takistan_Data","CUP_Tracked2_Data","CUP_Tracked_Data","CUP_Tracked_e_Data","CUP_CAFonts","CAFonts","CUP_Utes_Data","CUP_Water2_Data","CUP_Water_Data","CUP_Weapons2_Data","CUP_Weapons_Data","CUP_Weapons_e_Data","CUP_Weapons_pmc_Data","CUP_Wheeled2_Data","CUP_Wheeled_Data","CUP_Wheeled_e_Data","CUP_Zargabad_Data","CUP_A1AlwaysDummy","CAVideo2_PMC","CA_AnimsHotfix","CA_CutSceneAnims","CAIntroAnims","CAUSMCD","CAVoice","CAweapons3_aks74pso","CAWeapons3_ammocrates","CAweapons3_ksvk","CAweapons3_m107","CAweapons3_m16a4_acg_gl","CAweapons3_m16a4_acg","CAweapons3_m16a4_gl","CAweapons3_m16a4","CAWeapons3","CTI_buildingsBmp2_hq","CTI_buildingsM113_hq","DSHkM_Mini","M2HD_Mini","MK19_Tripod","Warfare","WarfareBuildings_Stinger_Twice_static","WarfareBuildings_T72_RACS","WarfareBuildings_TOW_Tripod","CUP_AiA_compat","AiA_A1AlwaysDummy","AiA_Afghan_Config","AiA_Afghan_Data","AiA_BaseConfig_F","AiA_Bohemia_Config","AiA_Bohemia_Data","AiA_Bootcamp_acr_Config","AiA_Bootcamp_acr_Data","AiA_Buildings_Config","AiA_Buildings_Data","AiA_Buildings2_Config","AiA_Buildings2_Data","AiA_Buildings2_Ind_Cementworks_Config","AiA_Buildings2_Ind_Cementworks_Data","AiA_Ca_acr_Config","AiA_Ca_acr_Data","AiA_CA_Config","AiA_CA_Config_Data_ParticleEffects","AiA_CA_Data","AiA_Ca_e_Config","AiA_Ca_e_Data","AiA_Ca_pmc_Config","AiA_Ca_pmc_Data","AiA_CBA_A2_xeh_Dummy","AiA_CBA_OA_xeh_Dummy","AiA_cba_xeh_a2_Dummy","AiA_cba_xeh_oa_Dummy","AiA_Chernarus_Config","AiA_Chernarus_Data","AiA_Chernarus_Summer_Config","AiA_Chernarus_Summer_Data","AiA_Core","AiA_Cti_buildings_Config","AiA_Cti_buildings_Data","AiA_Data_baf_Config","AiA_Data_baf_Data","AiA_Desert_Config","AiA_Desert_Data","AiA_Desert_e_Config","AiA_Desert_e_Data","AiA_Desert2_Config","AiA_Desert2_Data","AiA_Hotfix_Config","AiA_Hotfix_Data","AiA_Language_acr_Config","AiA_Language_acr_Data","AiA_Language_baf_Config","AiA_Language_baf_Data","AiA_Language_e_Config","AiA_Language_e_Data","AiA_Language_pmc_Config","AiA_Language_pmc_Data","AiA_Languagemissions_acr_Config","AiA_Languagemissions_acr_Data","AiA_Languagemissions_baf_Config","AiA_Languagemissions_baf_Data","AiA_Languagemissions_pmc_Config","AiA_Languagemissions_pmc_Data","AiA_Misc_acr_Config","AiA_Misc_acr_Data","AiA_Misc_Config","AiA_Misc_Data","AiA_Misc_e_Config","AiA_Misc_e_Data","AiA_Misc2_Config","AiA_Misc2_Data","AiA_Misc3_Config","AiA_Misc3_Data","AiA_Models_DBE1_Config","AiA_Models_DBE1_Data","AiA_Plants_Config","AiA_Plants_Data","AiA_Plants_e_Config","AiA_Plants_e_Data","AiA_Plants_e2_Config","AiA_Plants_e2_Data","AiA_Plants_pmc_Config","AiA_Plants_pmc_Data","AiA_Plants2_Bush_Config","AiA_Plants2_Bush_Data","AiA_Plants2_Clutter_Config","AiA_Plants2_Clutter_Data","AiA_Plants2_Misc_Config","AiA_Plants2_Misc_Data","AiA_Plants2_Plant_Config","AiA_Plants2_Plant_Data","AiA_Plants2_Tree_Config","AiA_Plants2_Tree_Data","AiA_Provinggrounds_pmc_Config","AiA_Provinggrounds_pmc_Data","AiA_Roads_Config","AiA_Roads_Data","AiA_Roads_e_Config","AiA_Roads_e_Data","AiA_Roads_pmc_Config","AiA_Roads_pmc_Data","AiA_Roads2_Config","AiA_Roads2_Data","AiA_Rocks_Config","AiA_Rocks_Data","AiA_Rocks_e_Config","AiA_Rocks_e_Data","AiA_Rocks2_Config","AiA_Rocks2_Data","AiA_Sara_Config","AiA_Sara_Data","AiA_Sara_dbe1_Config","AiA_Sara_dbe1_Data","AiA_Saralite_Config","AiA_Saralite_Data","AiA_Shapur_baf_Config","AiA_Shapur_baf_Data","AiA_Signs_Config","AiA_Signs_Data","AiA_Signs_e_Config","AiA_Signs_e_Data","AiA_Signs2_Config","AiA_Signs2_Data","AiA_Sounds_Config","AiA_Sounds_Data","AiA_StandaloneTerrainPack_Core","AiA_StandaloneTerrains_Core","AiA_Structures_Config","AiA_Structures_Data","AiA_Structures_e_Config","AiA_Structures_e_Data","AiA_Structures_pmc_Config","AiA_Structures_pmc_Data","AiA_Takistan_Config","AiA_Takistan_Data","AiA_Ui_Config","AiA_Ui_Data","AiA_Utes_Config","AiA_Utes_Data","AiA_Water_Config","AiA_Water_Data","AiA_Water2_Config","AiA_Water2_Data","AiA_Weapons_Config","AiA_Weapons_Data","AiA_Weapons_e_Config","AiA_Weapons_e_Data","AiA_Weapons_pmc_Config","AiA_Weapons_pmc_Data","AiA_Weapons2_Config","AiA_Weapons2_Data","AiA_Wheeled_Config","AiA_Wheeled_Data","AiA_Wheeled_e_Config","AiA_Wheeled_e_Data","AiA_Wheeled2_Config","AiA_Wheeled2_Data","AiA_Worlds","AiA_Worlds_Ambient","AiA_Worlds_Author","AiA_Worlds_Clutter","AiA_Worlds_ClutterDist","AiA_Worlds_Delete","AiA_Worlds_DisableInfiniteTerrain","AiA_Worlds_DustEffects","AiA_Worlds_EnvSounds","AiA_Worlds_FullDetailDist","AiA_Worlds_Grid","AiA_Worlds_Intros","AiA_Worlds_Lighting","AiA_Worlds_Lighting_Chernarus","AiA_Worlds_Lighting_Desert","AiA_Worlds_MapSize","AiA_Worlds_MidDetailTexture","AiA_Worlds_NoDetailDist","AiA_Worlds_Seabed","AiA_Worlds_SkyTexture","AiA_Worlds_StreetLamp","AiA_Worlds_Surfaces","AiA_Worlds_Water","AiA_Zargabad_Config","AiA_Zargabad_Data","CUP_StandaloneTerrains_Dummy","CA_ACR","CA_Animals2_Anim_Config","CA_Anims_Char","CA_Anims_E_Wmn","CA_E","CA_PMC","CAAir","CACharacters","CATracked","CAWater","CAWater2","CAWater2_seafox","CAWeapons","CAWeapons_Warfare_weapons","CAWheeled","CAWheeled_E","CAWheeled2","6G30_DBE1","Arma2_Ka52","BI_SRRS","CA_AH64D","CA_AIR_E_MQ9PredatorB","CA_AIR_E_Su25","CA_AIR2_Su25","CA_Animals_E","CA_Animals2_Chicken","CA_Animals2_Cow","CA_Animals2_Dogs","CA_Animals2_Dogs_Fin","CA_Animals2_Dogs_Pastor","CA_Animals2_Goat","CA_Animals2_Rabbit","CA_Animals2_Sheep","CA_Animals2_WildBoar","CA_Anims","CA_Anims_E","CA_Anims_E_Sdr","CA_Anims_Sdr","CA_Anims_Wmn","CA_CommunityConfigurationProject_E","CA_CruiseMissile","CA_Dubbing","CA_Dubbing_Baf","CA_Dubbing_Counterattack","CA_Dubbing_E","CA_Dubbing_PMC","CA_DubbingRadio_E","CA_DubbingRadio_PMC","CA_E_ParticleEffects","CA_Editor","CA_HC_Sounds","CA_Heads","CA_HighCommand","CA_L39","CA_Missions","CA_Missions_AlternativeInjurySimulation","CA_Missions_AmbientCombat","CA_Missions_Armory1","CA_Missions_Armory2","CA_Missions_BAF","CA_Missions_BAF_2","CA_Missions_BAF_Templates_SecOps","CA_Missions_BattlefieldClearance","CA_Missions_E","CA_Missions_E_Armory2","CA_Missions_E_SecOps","CA_Missions_E_Templates_SecOps","CA_Missions_FirstAidSystem","CA_Missions_GarbageCollector","CA_Missions_PMC","CA_Missions_SecOps","CA_Missions_Templates_SecOps","CA_Missions2_PMC","CA_Modules","CA_Modules_Alice","CA_Modules_Animals","CA_Modules_ARTY","CA_Modules_clouds","CA_Modules_Coin","CA_Modules_DynO","CA_Modules_E","CA_Modules_E_DynO","CA_Modules_E_Jukebox","CA_Modules_E_OO","CA_Modules_E_UAV","CA_Modules_E_UAV_Heli","CA_Modules_E_Weather","CA_Modules_Functions","CA_Modules_Marta","CA_Modules_PMC","CA_Modules_PMC_SimpleFIrstAid","CA_Modules_Silvie","CA_Modules_StratLayer","CA_Modules_UAV","CA_Modules_ZoRA","CA_MPA_Challenges","CA_MPA_Core","CA_MPA_MP","CA_MPA_Scenarios","CA_Sounds_Baf","CA_SoundsMissions_E","CA_Support","CAA10","CAAir_BAF","CAAir_BAF_CH_47F","CAAir_E","CAAir_E_A10","CAAir_E_AH64D","CAAir_E_AH6J","CAAir_E_An2","CAAir_E_C130J","CAAir_E_CH_47F","CAAir_E_Halo","CAAir_E_Mi24","CAAir_E_MI8","CAAir_E_UH1H_EP1","CAAir_E_UH60M","CAAir_PMC","CAAir_PMC_KA137","CAAir_PMC_KA60","CAAir2","CAAir2_C130J","CAAir2_ChukarTarget","CAAir2_F35B","CAAir2_MQ9PredatorB","CAAir2_MV22","CAAir2_Pchela1T","CAAir2_UH1Y","CAAir3","CAAir3_Su34","CAAnimals","CACharacters_BAF","CACharacters_BAF_Head","CACharacters_E","CACharacters_E_Head","CACharacters_PMC","CACharacters_PMC_Head","CACharacters_W_BAF","CACharacters2","CAMisc_fix","CAMisc_fix_A2FREE","CAMisc_fix_air","CAMisc_fix_Ch2","CAMisc_fix_Str","CAMisc_fix_Weap","CAMusic","CAMusic_E","CAMusic_PMC","CASounds_E","CASounds_Missions","CATracked_BAF","CATracked_E","CATracked_E_BMP2","CATracked_E_M1_Abrams","CATracked_E_M113","CATracked_E_M2A2_Bradley","CATracked_E_T34","CATracked_E_T55","CATracked_E_T72","CATracked_E_us_m270mlrs","CATracked_E_ZSU","CATracked_W_BAF","CATracked2","CATracked2_2S6M_Tunguska","CATracked2_AAV","CATracked2_BMP3","CATracked2_T34","CATracked2_T90","CATracked2_us_m270mlrs","CAWater2_Destroyer","CAWater2_fishing_boat","CAWater2_Fregata","CAWater2_smallboat_1","CAWeapons_2b14_82mm_Mortar","CAWeapons_AK","CAWeapons_AmmoBoxes","CAWeapons_BAF","CAWeapons_bizon","CAWeapons_Colt1911","CAWeapons_DMR","CAWeapons_E","CAWeapons_E_AGS","CAWeapons_E_AK","CAWeapons_E_AmmoBoxes","CAWeapons_E_Colt1911","CAWeapons_E_D30","CAWeapons_E_DSHKM","CAWeapons_E_FIM92_static","CAWeapons_E_fnfal","CAWeapons_E_G36","CAWeapons_E_GrenadeLauncher","CAWeapons_E_Igla","CAWeapons_E_Javelin","CAWeapons_E_KORD","CAWeapons_E_ksvk","CAWeapons_E_LeeEnfield","CAweapons_E_m107","CAWeapons_E_M110","CAWeapons_E_M119_Howitzer","CAWeapons_E_M136","CAWeapons_E_M14","CAWeapons_E_M16","CAWeapons_E_M240","CAWeapons_E_M252_81mm_Mortar","CAWeapons_E_M2StaticMG","CAWeapons_E_M47","CAWeapons_E_M9","CAWeapons_E_MAAWS","CAWeapons_E_Makarov","CAWeapons_E_Metis","CAWeapons_E_Mk19_MiniTriPod","CAWeapons_E_PK","CAWeapons_E_Podnos_2b14_82mm","CAWeapons_E_RPG18","CAWeapons_E_RPG7","CAWeapons_E_scar","CAWeapons_E_Searchlight","CAWeapons_E_SPG9","CAWeapons_E_STATIC","CAWeapons_E_Stinger","CAWeapons_E_Strela","CAWeapons_E_TOW","CAWeapons_E_ZU23","CAWeapons_Kord","CAweapons_ksvk","CAWeapons_M1014","CAweapons_m107","CAWeapons_M252_81mm_Mortar","CAWeapons_Metis_AT_13","CAWeapons_PMC","CAWeapons_PMC_AA_12","CAWeapons_PMC_AS50","CAWeapons_PMC_XM8","CAWeapons_Saiga12K","CAWeapons_SPG9","CAWeapons_VSS_vintorez","CAWeapons_ZU23","CAWeapons2","CAWeapons2_HuntingRifle","CAWeapons2_RPG18","CAWeapons2_SMAW","CAWheeled_D_BAF","CAWheeled_E_ATV","CAWheeled_E_BRDM2","CAWheeled_E_BTR40","CAWheeled_E_BTR60","CAWheeled_E_HMMWV","CAWheeled_E_Ikarus","CAWheeled_E_LADA","CAWheeled_E_LandRover","CAWheeled_E_M1030","CAWheeled_E_MTVR","CAWheeled_E_Offroad","CAWheeled_E_Old_bike","CAWheeled_E_Old_moto","CAWheeled_E_Pickup","CAWheeled_E_s1203","CAWheeled_E_SCUD","CAWheeled_E_stryker","CAWheeled_E_SUV","CAWheeled_E_TT650","CAWheeled_E_UAZ","CAWheeled_E_Ural","CAWheeled_E_V3S","CAWheeled_E_Volha","CAWheeled_Offroad","CAWheeled_Pickup","CAWheeled_PMC","CAWheeled_PMC_ArmoredSUV","CAWheeled_W_BAF","CAWheeled2_BTR90","CAWheeled2_GAZ39371","CAWheeled2_HMMWV_Ambulance","CAWheeled2_HMMWV_BASE","CAWheeled2_Ikarus","CAWheeled2_Kamaz","CAWheeled2_LADA","CAWheeled2_LAV25","CAWheeled2_M1114_Armored","CAWheeled2_M998A2_Avenger","CAWheeled2_MMT","CAWheeled2_MTVR","CAWheeled2_TowingTractor","CAWheeled2_V3S","CAWheeled2_VWGolf","CAWheeled3","CAWheeled3_M1030","CAWheeled3_TT650","Datsun_armed_DBE1","DBE1","DBE1_UI","DC3_DBE1","HALO_Test","Hilux_armed_DBE1","Warfare2","Warfare2_E","Warfare2Vehicles","CUP_Models_DBE1_Data","CUP_Anims_DBE1","Anims_DBE1","CUP_HMMWV_DBE1","HMMWV_DBE1","CUP_Mercenary_DBE1","Mercenary_DBE1","CUP_Misc_DBE1","Misc_DBE1","CUP_Music_DBE1","Music_DBE1","CUP_NPCs_DBE1","NPCs_DBE1","CUP_ploty_DBE1","ploty_DBE1","CUP_Prisoners_DBE1","Prisoners_DBE1","CUP_Roads_DBE1","Roads_DBE1","CUP_UH60Desert","UH60Desert","CUP_Sara_dbe1_Data","CUP_TKOH_Dummy","HSim_Data_H","HSim_Data_H_data_ParticleEffects","HSim_Data_H_data_ParticleEffects_rotor_blades","HSim_Dubbing_H","HSim_DubbingRadio_H","HSim_Editor_H","Intro_Island_H","HSim_Missions_H","HSim_ModulesCore_H","HSim_ModulesCore_H_AmbientCombat","HSim_ModulesCore_H_DynO","HSim_ModulesCore_H_Functions","HSim_ModulesCore_H_GarbageCollector","HSim_ModulesCore_H_Functions_E","HSim_ModulesCore_H_OO","HSim_ModulesCore_H_Functions_PMC","HSim_Music_H","HSim_Sounds_H","South_Asia_H","HSim_UIFonts_H","United_States_H","HSim_Animals_H","HSim_Animals_H_Anim_Config","HSim_Animals_H_Dog","HSim_Characters_H_Faces","HSim_Characters_H_Heads","HSim_Modules_H","HSim_UI_H","HSim_Weapons_H","HSim_Weapons_H_AK47","HSim_Weapons_H_DShKM","HSim_Weapons_H_Glock","HSim_Weapons_H_HandItems","HSim_Weapons_H_M16","HSim_Weapons_US_H","HSim_Characters_H","HSim_Characters_US_H","HSim_Missions_H_FreeFlight","HSim_Functions_Base_H","HSim_Water_H","HSim_Water_H_Civ_FishingBoat_Large","HSim_Water_H_Civ_Jetboat","HSim_Water_H_Civ_Yacht","HSim_Water_H_Container_Ship","HSim_Water_H_Cruise_Ship","HSim_Water_H_Destroyer","HSim_Water_H_Fishing_Boat","HSim_Water_H_Fregata","HSim_Water_H_LHD","HSim_Water_H_Oil_tanker","HSim_Water_H_Rubber_Boat","HSim_Water_H_Whales","HSim_Water_H_Whales_GreyWhale","HSim_Water_H_Whales_Whale1","HSim_Weapons_H_IGLA","HSim_Weapons_US_H_M2","HSim_Wheeled_H","HSim_Wheeled_H_Ambulance","HSim_Wheeled_H_FireTruck","HSim_Wheeled_H_Hatchback","HSim_Wheeled_H_Military_Offroad_LR","HSim_Wheeled_H_Military_Pickup_DSHKM","HSim_Wheeled_H_Offroad","HSim_Wheeled_H_Police_Car","HSim_Wheeled_H_TowingTractor","HSim_Wheeled_H_Tractor","HSim_Wheeled_H_Trailers","HSim_Wheeled_H_Truck_Light_Transport","HSim_Wheeled_H_Ural","HSim_Wheeled_H_Van_Passenger","HSim_Wheeled_US_H","HSim_Wheeled_US_H_Military_Offroad","HSim_Wheeled_US_H_Military_Truck","HSim_Wheeled_US_H_Pickup_01","HSim_Wheeled_US_H_Pickup_02","HSim_Wheeled_US_H_SUV","HSim_Wheeled_US_H_Truck_US_Type","HSim_Air_H","HSim_Air_H_Aircraft_A","HSim_Air_H_Aircraft_C","HSim_Air_H_Aircraft_D","HSim_Air_H_Aircraft_E_H","HSim_Air_H_Airliner_A","HSim_Air_H_Airliner_B","HSim_Air_H_Parachute","HSim_Air_US_H","HSim_Air_US_H_Helicopters_Heavy","HSim_Air_US_H_Helicopters_Light","HSim_Air_US_H_Helicopters_Medium","HSim_Misc_H","HSim_Misc_H_Antena","HSim_Misc_H_Barels","HSim_Misc_H_Bleacher","HSim_Misc_H_BoardsPack","HSim_Misc_H_CncBlock","HSim_Misc_H_Doghouse","HSim_Misc_H_Engine_Crane","HSim_Misc_H_Fence","HSim_Misc_H_Fire_Extinguisher","HSim_Misc_H_Fire_Suppression","HSim_Misc_H_First_Aid","HSim_Misc_H_Flagpole","HSim_Misc_H_Folding_Ladder","HSim_Misc_H_FuelCan","HSim_Misc_H_Heliport_Furniture","HSim_Misc_H_Helicopter_Parts","HSim_Misc_H_Helipads","HSim_Misc_H_Heliport_Objects","HSim_Misc_H_Helpers","HSim_Misc_H_Info_Board","HSim_Misc_H_Infostands","HSim_Misc_H_Inspection_Visuals","HSim_Misc_H_Interior","HSim_Misc_H_Loudspeakers","HSim_Misc_H_Market","HSim_Misc_H_Office_Objects","HSim_Misc_H_Perimeter_Ligh","HSim_Misc_H_Pike","HSim_Misc_H_Platform_Cart","HSim_Misc_H_Portable_Generator","HSim_Misc_H_Props","HSim_Misc_H_SawHorse","HSim_Misc_H_Shooting_Range","HSim_Misc_H_Signs","HSim_Misc_H_Sink","HSim_Misc_H_Targets","HSim_Misc_H_Tent","HSim_Misc_H_Toilet","HSim_Misc_H_Tools","HSim_Misc_H_Tools_Racking","HSim_Misc_H_Trash","HSim_Misc_H_Weather_Station","HSim_Misc_H_Weld_Gastank","HSim_Misc_H_Wheel_Chocks","HSim_Misc_H_Wheeled_Scaffolding","HSim_Misc_H_wheeled_tool_cart","HSim_Misc_H_Wheeled_Whiteboard","HSim_Misc_H_Winch","HSim_Misc_H_Windsock","HSim_Misc_H_Workbench","HSim_Misc_H_Wrecks","HSim_Structures_H","HSim_Structures_H_Airport_Papi","HSim_Structures_H_Harbour","HSim_Structures_H_Heliports_Heliport_Big","HSim_Structures_H_Heliports_Heliport_Small","HSim_Structures_H_Industrial_A_CraneCon","HSim_Structures_H_Industrial_Rooftop_Objects","HSim_Structures_US_H","HSim_Structures_US_H_Bld_US","HSim_Structures_US_H_Landmarks_Space_Needle","HSim_Tracked_H","HSim_Tracked_H_BMP2","HSim_Tracked_US_H","HSim_Tracked_US_H_M1A2","HSim_Tracked_US_H_MLRS","HSim_Data_H_EditorGroups","HSim_Anims_H","HSim_Anims_H_config_sdr","HSim_Anims_H_config_wmn","CUP_Hsim_Language_H","Hsim_Language_H","CUP_Hsim_Language_missions_H","Hsim_Language_missions_H","Enhanced_Epoch_AiASupport","A3_epoch_assets_1","epoch_objects","A3_epoch_assets_3","Underground_Epoch","A3_epoch_vehicles","a3_epoch_weapons","A3_Data_F","A3_Data_F_Hook","A3_Data_F_ParticleEffects","A3_Data_F_Bootcamp","A3_Data_F_Exp_A","A3_Data_F_Kart_ParticleEffects","A3_Data_F_Mark","A3_Editor_F","A3_Functions_F_Bootcamp","A3_Functions_F_Curator","A3_Functions_F_Exp_A","A3_Functions_F_Heli","A3_Functions_F_Mark","A3_Functions_F_MP_Mark","A3_Language_F","A3_Language_F_Beta","A3_Language_F_Curator","A3_Language_F_EPA","A3_Language_F_EPB","A3_Language_F_EPC","A3_Language_F_Gamma","A3_Language_F_Heli","A3_Language_F_Kart","A3_Language_F_Mark","A3_LanguageMissions_F","A3_LanguageMissions_F_Beta","A3_LanguageMissions_F_Gamma","A3_LanguageMissions_F_Kart","A3_Misc_F","A3_Misc_F_Helpers","A3_Modules_F","A3_Modules_F_DynO","A3_Modules_F_Effects","A3_Modules_F_Events","A3_Modules_F_GroupModifiers","A3_Modules_F_HC","A3_Modules_F_Intel","A3_Modules_F_LiveFeed","A3_Modules_F_Marta","A3_Modules_F_Misc","A3_Modules_F_Multiplayer","A3_Modules_F_ObjectModifiers","A3_Modules_F_Sites","A3_Modules_F_Skirmish","A3_Modules_F_StrategicMap","A3_Modules_F_Supports","A3_Modules_F_UAV","A3_Modules_F_Beta","A3_Modules_F_Beta_FiringDrills","A3_Modules_F_EPB","A3_Modules_F_EPB_Misc","A3_Modules_F_Heli","A3_Modules_F_Heli_SpawnAi","A3_Modules_F_Mark","A3_Modules_F_Mark_FiringDrills","A3_Modules_F_MP_Mark","A3_Modules_F_Mark_Objectives","A3_Music_F","A3_Music_F_Bootcamp","A3_Music_F_EPA","A3_Music_F_EPB","A3_Music_F_EPC","A3_Music_F_Heli","A3_Music_F_Mark","A3_Roads_F","A3_Rocks_F","A3_Sounds_F","A3_Sounds_F_Bootcamp","A3_Sounds_F_EPB","A3_Sounds_F_EPC","A3_Sounds_F_Exp_A","A3_Structures_F","A3_Structures_F_Bridges","A3_Structures_F_Civ","A3_Structures_F_Civ_Accessories","A3_Structures_F_Civ_Ancient","A3_Structures_F_Civ_BellTowers","A3_Structures_F_Civ_Calvaries","A3_Structures_F_Civ_Camping","A3_Structures_F_Civ_Chapels","A3_Structures_F_Civ_Constructions","A3_Structures_F_Civ_Dead","A3_Structures_F_Civ_Garbage","A3_Structures_F_Civ_Graffiti","A3_Structures_F_Civ_InfoBoards","A3_Structures_F_Civ_Kiosks","A3_Structures_F_Civ_Lamps","A3_Structures_F_Civ_Market","A3_Structures_F_Civ_Offices","A3_Structures_F_Civ_Pavements","A3_Structures_F_Civ_PlayGround","A3_Structures_F_Civ_SportsGrounds","A3_Structures_F_Civ_Statues","A3_Structures_F_Civ_Tourism","A3_Structures_F_Dominants","A3_Structures_F_Dominants_Amphitheater","A3_Structures_F_Dominants_Castle","A3_Structures_F_Dominants_Church","A3_Structures_F_Dominants_Hospital","A3_Structures_F_Dominants_Lighthouse","A3_Structures_F_Dominants_WIP","A3_Structures_F_Furniture","A3_Structures_F_Households","A3_Structures_F_Households_Addons","A3_Structures_F_Households_House_Big01","A3_Structures_F_Households_House_Big02","A3_Structures_F_Households_House_Shop01","A3_Structures_F_Households_House_Shop02","A3_Structures_F_Households_House_Small01","A3_Structures_F_Households_House_Small02","A3_Structures_F_Households_House_Small03","A3_Structures_F_Households_Slum","A3_Structures_F_Households_Stone_Big","A3_Structures_F_Households_Stone_Shed","A3_Structures_F_Households_Stone_Small","A3_Structures_F_Households_WIP","A3_Structures_F_Ind","A3_Structures_F_Ind_AirPort","A3_Structures_F_Ind_Cargo","A3_Structures_F_Ind_CarService","A3_Structures_F_Ind_ConcreteMixingPlant","A3_Structures_F_Ind_Crane","A3_Structures_F_Ind_DieselPowerPlant","A3_Structures_F_Ind_Factory","A3_Structures_F_Ind_FuelStation","A3_Structures_F_Ind_FuelStation_Small","A3_Structures_F_Ind_Pipes","A3_Structures_F_Ind_PowerLines","A3_Structures_F_Ind_ReservoirTank","A3_Structures_F_Ind_Shed","A3_Structures_F_Ind_SolarPowerPlant","A3_Structures_F_Ind_Tank","A3_Structures_F_Ind_Transmitter_Tower","A3_Structures_F_Ind_WavePowerPlant","A3_Structures_F_Ind_Windmill","A3_Structures_F_Ind_WindPowerPlant","A3_Structures_F_Items","A3_Structures_F_Items_Documents","A3_Structures_F_Items_Electronics","A3_Structures_F_Items_Cans","A3_Structures_F_Items_Gadgets","A3_Structures_F_Items_Luggage","A3_Structures_F_Items_Medical","A3_Structures_F_Items_Military","A3_Structures_F_Items_Stationery","A3_Structures_F_Items_Tools","A3_Structures_F_Items_Valuables","A3_Structures_F_Items_Vessels","A3_Structures_F_Mil","A3_Structures_F_Mil_BagBunker","A3_Structures_F_Mil_BagFence","A3_Structures_F_Mil_Barracks","A3_Structures_F_Mil_Bunker","A3_Structures_F_Mil_Cargo","A3_Structures_F_Mil_Flags","A3_Structures_F_Mil_Fortification","A3_Structures_F_Mil_Helipads","A3_Structures_F_Mil_Offices","A3_Structures_F_Mil_Radar","A3_Structures_F_Mil_Shelters","A3_Structures_F_Mil_TentHangar","A3_Structures_F_Naval","A3_Structures_F_Naval_Buoys","A3_Structures_F_Naval_Fishing","A3_Structures_F_Naval_Piers","A3_Structures_F_Naval_RowBoats","A3_Structures_F_Research","A3_Structures_F_System","A3_Structures_F_Training","A3_Structures_F_Training_InvisibleTarget","A3_Structures_F_Walls","A3_Structures_F_Bootcamp_Ind_Cargo","A3_Structures_F_Bootcamp_Items_Sport","A3_Structures_F_Bootcamp_System","A3_Structures_F_Bootcamp_Training","A3_Structures_F_Bootcamp_VR_Blocks","A3_Structures_F_Bootcamp_VR_CoverObjects","A3_Structures_F_Bootcamp_VR_Helpers","A3_Structures_F_EPA_Civ_Camping","A3_Structures_F_EPA_Civ_Constructions","A3_Structures_F_EPA_Items_Electronics","A3_Structures_F_EPA_Items_Food","A3_Structures_F_EPA_Items_Medical","A3_Structures_F_EPA_Items_Tools","A3_Structures_F_EPA_Items_Vessels","A3_Structures_F_EPA_Walls","A3_Structures_F_EPB_Civ_Accessories","A3_Structures_F_EPB_Civ_Camping","A3_Structures_F_EPB_Civ_Dead","A3_Structures_F_EPB_Civ_Garbage","A3_Structures_F_EPB_Civ_Graffiti","A3_Structures_F_EPB_Civ_PlayGround","A3_Structures_F_EPB_Furniture","A3_Structures_F_EPB_Items_Documents","A3_Structures_F_EPB_Items_Luggage","A3_Structures_F_EPB_Items_Military","A3_Structures_F_EPB_Items_Vessels","A3_Structures_F_EPB_Naval_Fishing","A3_Structures_F_EPC_Civ_Accessories","A3_Structures_F_EPC_Civ_Camping","A3_Structures_F_EPC_Civ_Garbage","A3_Structures_F_EPC_Civ_InfoBoards","A3_Structures_F_EPC_Civ_Kiosks","A3_Structures_F_EPC_Civ_PlayGround","A3_Structures_F_EPC_Civ_Tourism","A3_Structures_F_EPC_Dominants_GhostHotel","A3_Structures_F_EPC_Dominants_Stadium","A3_Structures_F_EPC_Furniture","A3_Structures_F_EPC_Items_Documents","A3_Structures_F_EPC_Items_Electronics","A3_Structures_F_EPC_Walls","A3_Structures_F_Exp_A","A3_Structures_F_Exp_A_VR_Blocks","A3_Structures_F_Exp_A_VR_Helpers","A3_Structures_F_Heli_Civ_Accessories","A3_Structures_F_Heli_Civ_Constructions","A3_Structures_F_Heli_Civ_Garbage","A3_Structures_F_Heli_Civ_Market","A3_Structures_F_Heli_Furniture","A3_Structures_F_Heli_Ind_AirPort","A3_Structures_F_Heli_Ind_Cargo","A3_Structures_F_Heli_Ind_Machines","A3_Structures_F_Heli_Items_Airport","A3_Structures_F_Heli_Items_Luggage","A3_Structures_F_Heli_Items_Sport","A3_Structures_F_Heli_Items_Tools","A3_Structures_F_Heli_VR_Helpers","A3_Structures_F_Kart_Civ_SportsGrounds","A3_Structures_F_Kart_Mil_Flags","A3_Structures_F_Mark_Items_Military","A3_Structures_F_Mark_Items_Sport","A3_Structures_F_Mark_Mil_Flags","A3_Structures_F_Mark_Training","A3_Structures_F_Mark_VR_Helpers","A3_Structures_F_Mark_VR_Shapes","A3_Structures_F_Mark_VR_Targets","A3_UIFonts_F","CUP_Buildings_Config","CABuildings","CUP_CABuildings_Misc","CABuildings_Misc","CUP_Desert2_Buildings","Desert2_Buildings","CUP_CA_desert2_Characters","CA_desert2_Characters","CUP_Desert_Config","Desert","CUP_DBE1_Hotfix","DBE1_Hotfix","CUP_CALanguage_e","CALanguage_e","CUP_CALanguage_PMC","CALanguage_PMC","CUP_CALanguage_missions_PMC","CALanguage_missions_PMC","CUP_CAWater2_seafox_EP1","CAWater2_seafox_EP1","CUP_CA_Plants2","CA_Plants2","CUP_CA_Plants2_Plant","CA_Plants2_Plant","CUP_CA_Plants2_Tree","CA_Plants2_Tree","CUP_CA_Plants_E2","CA_Plants_E2","CUP_CA_Plants_E","CA_Plants_E","CUP_CA_Plants_E_Misc","CA_Plants_E_Misc","CUP_CA_Plants_E_Plant","CA_Plants_E_Plant","CUP_CA_Plants_E_Tree","CA_Plants_E_Tree","CUP_Sara_Config","Sara","CUP_Saralite_Config","SaraLite","CUP_CASigns2","CASigns2","CUP_Structures_Config","CAStructures","CUP_CAStructures_A_BuildingWIP","CAStructures_A_BuildingWIP","CUP_CAStructures_A_CraneCon","CAStructures_A_CraneCon","CUP_CAStructuresLand_A_MunicipalOffice","CAStructuresLand_A_MunicipalOffice","CUP_CAStructuresBarn_W","CAStructuresBarn_W","CUP_CAStructures_Castle","CAStructures_Castle","CUP_CAStructuresHouse","CAStructuresHouse","CUP_CAStructuresHouse_A_FuelStation","CAStructuresHouse_A_FuelStation","CUP_CAStructuresHouse_A_Hospital","CAStructuresHouse_A_Hospital","CUP_CAStructuresHouse_A_Office01","CAStructuresHouse_A_Office01","CUP_CAStructuresHouse_A_Office02","CAStructuresHouse_A_Office02","CUP_CAStructuresHouse_a_stationhouse","CAStructuresHouse_a_stationhouse","CUP_CAStructuresHouse_Church_02","CAStructuresHouse_Church_02","CUP_CAStructuresHouse_Church_03","CAStructuresHouse_Church_03","CUP_CAStructuresHouse_Church_05R","CAStructuresHouse_Church_05R","CUP_CAStructuresHouse_HouseBT","CAStructuresHouse_HouseBT","CUP_CAStructuresHouse_HouseV2","CAStructuresHouse_HouseV2","CUP_CAStructuresHouse_HouseV","CAStructuresHouse_HouseV","CUP_CAStructuresLand_Ind_Stack_Big","CAStructuresLand_Ind_Stack_Big","CUP_CAStructures_IndPipe1","CAStructures_IndPipe1","CUP_CAStructuresInd_Quarry","CAStructuresInd_Quarry","CUP_Ind_SawMill","Ind_SawMill","CUP_CAStructures_Mil","CAStructures_Mil","CUP_CAStructures_Misc","CAStructures_Misc","CUP_CAStructures_Misc_Armory","CAStructures_Misc_Armory","CUP_CAStructures_Misc_Armory_Armor_Popuptarget","CAStructures_Misc_Armory_Armor_Popuptarget","CUP_CAStructures_Misc_Powerlines","CAStructures_Misc_Powerlines","CUP_CAStructures_Nav","CAStructures_Nav","CUP_CAStructuresLand_Nav_Boathouse","CAStructuresLand_Nav_Boathouse","CUP_CAStructures_Proxy_BuildingParts","CAStructures_Proxy_BuildingParts","CUP_CAStructures_Proxy_Ruins","CAStructures_Proxy_Ruins","CUP_CAStructures_Rail","CAStructures_Rail","CUP_CAStructuresHouse_rail_station_big","CAStructuresHouse_rail_station_big","CUP_CAStructures_Ruins","CAStructures_Ruins","CUP_CAStructuresShed_Small","CAStructuresShed_Small","CUP_CAStructuresHouse_Shed_Ind","CAStructuresHouse_Shed_Ind","CUP_CAStructures_Wall","CAStructures_Wall","CUP_CAUI","CAUI","CUP_CAWater2_LHD","CAWater2_LHD","CUP_Models_DBE1_Config","Models_DBE1","CUP_Kamenolom_DBE1","Kamenolom_DBE1","CUP_Pila_DBE1","Pila_DBE1","CUP_UI_DBE1","UI_DBE1","CUP_Vysilac_DBE1","Vysilac_DBE1","CUP_Zakladna_DBE1","Zakladna_DBE1","CUP_Sara_dbe1_Config","Sara_dbe1","a3_epoch_structures","A3_Animals_F","A3_Animals_F_AnimConfig","A3_Animals_F_Fishes","A3_Animals_F_Kestrel","A3_Animals_F_Rabbit","A3_Animals_F_Seagull","A3_Animals_F_Snakes","A3_Animals_F_Turtle","A3_Animals_F_Chicken","A3_Animals_F_Dog","A3_Animals_F_Goat","A3_Animals_F_Sheep","A3_Anims_F","A3_Anims_F_Config_Sdr","A3_Anims_F_EPA","A3_Anims_F_EPC","A3_Anims_F_Exp_A","A3_Anims_F_Kart","A3_Anims_F_Mark_Deployment","A3_Language_F_Bootcamp","A3_Language_F_Exp_A","A3_Map_Data","A3_Map_Stratis","A3_Map_Stratis_Scenes","A3_Plants_F_Bush","A3_Props_F_Exp_A","A3_Props_F_Exp_A_Military","A3_Signs_F","A3_Signs_F_AD","A3_Structures_F_Signs_Companies","A3_Structures_F_Bootcamp_Civ_Camping","A3_Structures_F_Bootcamp_Civ_SportsGrounds","A3_Structures_F_Bootcamp_Items_Electronics","A3_Structures_F_Bootcamp_Items_Food","A3_Structures_F_Heli_Items_Electronics","A3_Structures_F_Heli_Items_Food","A3_Structures_F_Kart_Signs_Companies","A3_UI_F","A3_UI_F_Curator","A3_UI_F_Kart","A3_UI_F_Mark","A3_UI_F_MP_Mark","A3_Weapons_F","A3_Weapons_F_NATO","A3_Weapons_F_CSAT","A3_Weapons_F_AAF","A3_weapons_F_FIA","A3_Weapons_F_ItemHolders","A3_Weapons_F_Headgear","A3_Weapons_F_Uniforms","A3_Weapons_F_Vests","A3_Weapons_F_Ammoboxes","A3_Weapons_F_DummyWeapons","A3_Weapons_F_Explosives","A3_Weapons_F_Items","A3_Weapons_F_Launchers_NLAW","A3_Weapons_F_Launchers_LAW","A3_Weapons_F_Launchers_Titan","A3_Weapons_F_EPA_LongRangeRifles_DMR_01","A3_Weapons_F_EBR","A3_Weapons_F_LongRangeRifles_GM6","A3_Weapons_F_LongRangeRifles_M320","A3_Weapons_F_Machineguns_M200","A3_Weapons_F_Machineguns_Zafir","A3_Weapons_F_Pistols_ACPC2","A3_Weapons_F_Pistols_P07","A3_Weapons_F_Pistols_Pistol_heavy_01","A3_Weapons_F_Pistols_Pistol_heavy_02","A3_Weapons_F_Pistols_Rook40","A3_Weapons_F_Rifles_Khaybar","A3_Weapons_F_Rifles_Mk20","A3_Weapons_F_Rifles_MX","A3_Weapons_F_EPB_Rifles_MX_Black","A3_Weapons_F_Rifles_SDAR","A3_Weapons_F_Rifles_TRG20","A3_Weapons_F_Pistols_PDW2000","A3_Weapons_F_Rifles_Vector","a3_weapons_f_rifles_SMG_02","A3_Weapons_F_beta","A3_Weapons_F_Beta_Ammoboxes","A3_Weapons_F_beta_EBR","A3_Weapons_F_EPA_LongRangeRifles_GM6","A3_Weapons_F_EPB_LongRangeRifles_M320","A3_Weapons_F_beta_Rifles_Khaybar","A3_Weapons_F_beta_Rifles_MX","A3_Weapons_F_beta_Rifles_TRG20","A3_Weapons_F_Bootcamp_LongRangeRifles_GM6","A3_Weapons_F_Bootcamp_LongRangeRifles_M320","A3_Weapons_F_EPB_LongRangeRifles_GM3","A3_Weapons_F_gamma","A3_Weapons_F_Gamma_Ammoboxes","A3_Weapons_F_EPA_EBR","A3_Weapons_F_EPA_Rifles_MX","A3_Weapons_F_Kart_Pistols_Pistol_Signal_F","A3_Weapons_F_Mark_LongRangeRifles_DMR_01","A3_Weapons_F_Mark_EBR","A3_Weapons_F_Mark_LongRangeRifles_GM6","A3_Weapons_F_Mark_LongRangeRifles_GM6_camo","A3_Weapons_F_Mark_LongRangeRifles_M320","A3_Weapons_F_Mark_LongRangeRifles_M320_camo","A3_Weapons_F_Mark_Machineguns_M200","A3_Weapons_F_Mark_Machineguns_Zafir","A3_Weapons_F_Mark_Rifles_Khaybar","A3_Weapons_F_Mark_Rifles_Mk20","A3_Weapons_F_Mark_Rifles_MX","A3_Weapons_F_Mark_Rifles_SDAR","A3_Weapons_F_Mark_Rifles_TRG20","CUP_Buildings2_Config","CABuildings2","CUP_A_Crane_02","A_Crane_02","CUP_A_GeneralStore_01","A_GeneralStore_01","CUP_CABuildings2_A_Pub","CABuildings2_A_Pub","CUP_A_statue","A_statue","CUP_Barn_Metal","Barn_Metal","CUP_CABuildingParts","CABuildingParts","CUP_CABuildingParts_Signs","CABuildingParts_Signs","CUP_CATEC","CATEC","CUP_Church_01","Church_01","CUP_Farm_Cowshed","Farm_Cowshed","CUP_Farm_WTower","Farm_WTower","CUP_CAHouseBlock_A","CAHouseBlock_A","CUP_CAHouseBlock_B","CAHouseBlock_B","CUP_CAHouseBlock_C","CAHouseBlock_C","CUP_CAHouseBlock_D","CAHouseBlock_D","CUP_HouseRuins","HouseRuins","CUP_Ind_Dopravnik","Ind_Dopravnik","CUP_Ind_Expedice","Ind_Expedice","CUP_Ind_MalyKomin","Ind_MalyKomin","CUP_Ind_Mlyn","Ind_Mlyn","CUP_Ind_Pec","Ind_Pec","CUP_ind_silomale","ind_silomale","CUP_Ind_SiloVelke","Ind_SiloVelke","CUP_Ind_Vysypka","Ind_Vysypka","CUP_Ind_Garage01","Ind_Garage01","CUP_CAStructures_IndPipe1_todo_delete","CAStructures_IndPipe1_todo_delete","CUP_IndPipe2","IndPipe2","CUP_Ind_Shed_01","Ind_Shed_01","CUP_Ind_Shed_02","Ind_Shed_02","CUP_Ind_Tank","Ind_Tank","CUP_Ind_Workshop01","Ind_Workshop01","CUP_CABuildings2_Misc_Cargo","CABuildings2_Misc_Cargo","CUP_Misc_PowerStation","Misc_PowerStation","CUP_Misc_WaterStation","Misc_WaterStation","CUP_Rail_House_01","Rail_House_01","CUP_Shed_small","Shed_small","CUP_Shed_wooden","Shed_wooden","CUP_particle_effects","particle_effects","CUP_Chernarus_Config","Chernarus","CUP_Chernarus_Summer_Config","Chernarus_Summer","CUP_Desert2_Config","Porto","CUP_Hotfix_Config","CA_Hotfix","CUP_CA_QGClutterHotfix","CA_QGClutterHotfix","CUP_CA_Hotfix_vez_ropa","CA_Hotfix_vez_ropa","CUP_CAMisc2","CAMisc2","CUP_Misc3_Config","CAMisc3","CUP_WarfareBuildings","WarfareBuildings","CUP_Misc_e_Config","CAMisc_E","CUP_CAMisc_E_WF","CAMisc_E_WF","CUP_CAMP_Armory_Misc","CAMP_Armory_Misc","CUP_CAMP_Armory_Misc_Concrete_Wall","CAMP_Armory_Misc_Concrete_Wall","CUP_CAMP_Armory_Misc_Entrance_Gate","CAMP_Armory_Misc_Entrance_Gate","CUP_CAMP_Armory_Misc_Info_Board","CAMP_Armory_Misc_Info_Board","CUP_CAMP_Armory_Misc_Infostands","CAMP_Armory_Misc_Infostands","CUP_CAMP_Armory_Misc_Laptop","CAMP_Armory_Misc_Laptop","CUP_CAMP_Armory_Misc_Loudspeakers","CAMP_Armory_Misc_Loudspeakers","CUP_CAMP_Armory_Misc_Plasticpole","CAMP_Armory_Misc_Plasticpole","CUP_CAMP_Armory_Misc_Red_Light","CAMP_Armory_Misc_Red_Light","CUP_CAMP_Armory_Misc_Sign_Armex","CAMP_Armory_Misc_Sign_Armex","CUP_CAMP_Armory_Misc_Sign_Direction","CAMP_Armory_Misc_Sign_Direction","CUP_CA_Plants2_Bush","CA_Plants2_Bush","CUP_CA_Plants2_Misc","CA_Plants2_Misc","CUP_CA_Plants_E_Bush","CA_Plants_E_Bush","CUP_CA_Plants_PMC","CA_Plants_PMC","CUP_CARoads2Bridge","CARoads2Bridge","CUP_CARoads_PMC_Bridge","CARoads_PMC_Bridge","CUP_A_TVTower","A_TVTower","CUP_CAStructures_Nav_pier","CAStructures_Nav_pier","CUP_CAStructures_Railway","CAStructures_Railway","CUP_Structures_e_Config","CAStructures_E","CUP_CAStructures_E_HouseA","CAStructures_E_HouseA","CUP_CAStructures_E_HouseA_A_BuildingWIP","CAStructures_E_HouseA_A_BuildingWIP","CUP_CAStructures_E_HouseA_A_CityGate1","CAStructures_E_HouseA_A_CityGate1","CUP_CAStructures_E_HouseA_A_Minaret","CAStructures_E_HouseA_A_Minaret","CUP_CAStructures_E_HouseA_A_Minaret_Porto","CAStructures_E_HouseA_A_Minaret_Porto","CUP_CAStructures_E_HouseA_A_Mosque_big","CAStructures_E_HouseA_A_Mosque_big","CUP_CAStructures_E_HouseA_A_Mosque_small","CAStructures_E_HouseA_A_Mosque_small","CUP_CAStructures_E_HouseA_A_Office01","CAStructures_E_HouseA_A_Office01","CUP_CAStructures_E_HouseA_a_stationhouse","CAStructures_E_HouseA_a_stationhouse","CUP_CAStructures_E_HouseA_A_Statue","CAStructures_E_HouseA_A_Statue","CUP_CAStructures_E_HouseA_A_Villa","CAStructures_E_HouseA_A_Villa","CUP_CAStructures_E_HouseC","CAStructures_E_HouseC","CUP_CAStructures_E_HouseK","CAStructures_E_HouseK","CUP_CAStructures_E_HouseL","CAStructures_E_HouseL","CUP_CAStructures_E_Ind","CAStructures_E_Ind","CUP_CAStructures_E_Ind_Ind_Coltan_Mine","CAStructures_E_Ind_Ind_Coltan_Mine","CUP_CAStructures_E_Ind_Ind_FuelStation","CAStructures_E_Ind_Ind_FuelStation","CUP_CAStructures_E_Ind_Ind_Garage01","CAStructures_E_Ind_Ind_Garage01","CUP_CAStructures_E_Ind_Oil_Mine","CAStructures_E_Ind_Oil_Mine","CUP_CAStructures_E_Ind_IndPipes","CAStructures_E_Ind_IndPipes","CUP_CAStructures_E_Ind_Misc_PowerStation","CAStructures_E_Ind_Misc_PowerStation","CUP_CAStructures_E_Ind_Ind_Shed","CAStructures_E_Ind_Ind_Shed","CUP_CAStructures_E_Mil","CAStructures_E_Mil","CUP_CAStructures_E_Misc","CAStructures_E_Misc","CUP_CAStructures_E_Misc_Misc_cables","CAStructures_E_Misc_Misc_cables","CUP_CAStructures_E_Misc_Misc_Construction","CAStructures_E_Misc_Misc_Construction","CUP_CAStructures_E_Misc_Misc_Garbage","CAStructures_E_Misc_Misc_Garbage","CUP_CAStructures_E_Misc_Misc_Interier","CAStructures_E_Misc_Misc_Interier","CUP_CAStructures_E_Misc_Misc_Lamp","CAStructures_E_Misc_Misc_Lamp","CUP_CAStructures_E_Misc_Misc_Market","CAStructures_E_Misc_Misc_Market","CUP_CAStructures_E_Misc_Misc_powerline","CAStructures_E_Misc_Misc_powerline","CUP_CAStructures_E_Misc_Misc_Water","CAStructures_E_Misc_Misc_Water","CUP_CAStructures_E_Misc_Misc_Well","CAStructures_E_Misc_Misc_Well","CUP_CAStructures_E_Wall","CAStructures_E_Wall","CUP_CAStructures_E_Wall_Wall_L","CAStructures_E_Wall_Wall_L","CUP_Structures_pmc_Config","CAStructures_PMC","CUP_CAStructures_PMC_Buildings","CAStructures_PMC_Buildings","CUP_CAStructures_PMC_Buildings_Bunker","CAStructures_PMC_Buildings_Bunker","CUP_CAStructures_PMC_Buildings_GeneralStore_PMC","CAStructures_PMC_Buildings_GeneralStore_PMC","CUP_CAStructures_PMC_Buildings_Ruin_Cowshed","CAStructures_PMC_Buildings_Ruin_Cowshed","CUP_CAStructures_PMC_Ind","CAStructures_PMC_Ind","CUP_CAStructures_PMC_FuelStation","CAStructures_PMC_FuelStation","CUP_CAStructures_PMC_Misc","CAStructures_PMC_Misc","CUP_CAStructures_PMC_Misc_Shed","CAStructures_PMC_Misc_Shed","CUP_CAStructures_PMC_Ruins","CAStructures_PMC_Ruins","CUP_CAStructures_PMC_Walls","CAStructures_PMC_Walls","CUP_Takistan_Config","Takistan","CUP_Utes_Config","Utes","CUP_Zargabad_Config","zargabad","CUP_ibr_plants","ibr_plants","a2_epoch_weapons","A3_epoch_assets","A3_Anims_F_Heli","A3_Characters_F","A3_Characters_F_BLUFOR","A3_Characters_F_Civil","A3_Characters_F_Heads","A3_Characters_F_OPFOR","A3_Characters_F_Proxies","A3_Characters_F_Beta","A3_Characters_F_INDEP","A3_Characters_F_Bootcamp","A3_Characters_F_EPB_Heads","A3_Characters_F_Gamma","A3_Characters_F_Mark","A3_Data_F_Curator","A3_Data_F_Curator_Eagle","A3_Data_F_Curator_Intel","A3_Data_F_Curator_Misc","A3_Data_F_Curator_Respawn","3DEN","A3_Data_F_Kart","A3_UAV_F_Characters_F_Gamma","A3_UAV_F_Weapons_F_Gamma_Ammoboxes","A3_Weapons_F_gamma_Items","A3_Map_Altis","A3_Map_Altis_Scenes","A3_Missions_F","A3_Missions_F_Beta","A3_Missions_F_Gamma","A3_Missions_F_Kart","A3_Modules_F_Bootcamp","A3_Modules_F_Curator","A3_Modules_F_Curator_Animals","A3_Modules_F_Curator_CAS","A3_Modules_F_Curator_Curator","A3_Modules_F_Curator_Effects","A3_Modules_F_Curator_Environment","A3_Modules_F_Curator_Flares","A3_Modules_F_Curator_Intel","A3_Modules_F_Curator_Lightning","A3_Modules_F_Curator_Mines","A3_Modules_F_Curator_Misc","A3_Modules_F_Curator_Multiplayer","A3_Modules_F_Curator_Objectives","A3_Modules_F_Curator_Ordnance","A3_Modules_F_Curator_Respawn","A3_Modules_F_Curator_Smokeshells","A3_Modules_F_Exp_A","A3_Modules_F_Kart","A3_Modules_F_Kart_TimeTrials","A3_Props_F_Exp_A_Military_Equipment","A3_Static_F","A3_Static_F_Mortar_01","A3_Static_F_Beta_Mortar_01","A3_Static_F_Gamma","A3_Static_F_Gamma_Mortar_01","A3_Static_F_Mark_Designator_01","A3_Static_F_Mark_Designator_02","A3_Supplies_F_Heli","A3_Supplies_F_Heli_Bladders","A3_Supplies_F_Heli_CargoNets","A3_Supplies_F_Heli_Fuel","A3_Supplies_F_Heli_Slingload","A3_Supplies_F_Mark","A3_UI_F_Bootcamp","A3_UI_F_Exp_A","A3_UI_F_Heli","A3_Weapons_F_Acc","A3_Weapons_F_Beta_Acc","A3_Weapons_F_Bootcamp_Ammoboxes","A3_Weapons_F_EPA","A3_Weapons_F_EPA_Acc","A3_Weapons_F_EPA_Ammoboxes","A3_Weapons_F_EPB","A3_Weapons_F_EPB_Acc","A3_Weapons_F_EPB_Ammoboxes","A3_Weapons_F_EPC","A3_Weapons_F_gamma_Acc","A3_Weapons_F_Kart","A3_Weapons_F_Mark_Acc","CUP_Afghan_Config","Mountains_ACR","CUP_Bohemia_Config","Woodland_ACR","CUP_Bootcamp_acr_Config","Bootcamp_ACR","CUP_Data_baf_Config","CA_BAF","CUP_Desert_e_Config","Desert_E","CUP_CALanguage_Baf","CALanguage_Baf","CUP_CALanguageMissions_baf","CALanguageMissions_baf","CUP_Misc_acr_Config","CAMisc_ACR","CUP_CAMisc_ACR_3DMarkers","CAMisc_ACR_3DMarkers","CUP_CAMisc_ACR_Container","CAMisc_ACR_Container","CUP_CAMisc_ACR_Dog","CAMisc_ACR_Dog","CUP_CAMisc_ACR_Helpers","CAMisc_ACR_Helpers","CUP_CAMisc_ACR_PBX","CAMisc_ACR_PBX","CUP_CAMisc_ACR_ScaffoldingSmall","CAMisc_ACR_ScaffoldingSmall","CUP_CAMisc_ACR_Shooting_range","CAMisc_ACR_Shooting_range","CUP_CAMisc_ACR_Sign_Mines","CAMisc_ACR_Sign_Mines","CUP_CAMisc_ACR_Targets","CAMisc_ACR_Targets","CUP_CAMisc_ACR_Targets_InvisibleTarget","CAMisc_ACR_Targets_InvisibleTarget","CUP_CAMisc_ACR_TestSphere","CAMisc_ACR_TestSphere","CUP_CAMisc_BAF","CAMisc_BAF","CUP_Provinggrounds_pmc_Config","ProvingGrounds_PMC","CUP_Shapur_baf_Config","Shapur_BAF","CUP_BaseConfig_F","A3_Air_F","A3_Air_F_Heli_Light_01","A3_Air_F_Heli_Light_02","A3_Air_F_Beta","A3_Air_F_Beta_Heli_Attack_01","A3_Air_F_Beta_Heli_Attack_02","A3_Air_F_Beta_Heli_Transport_01","A3_Air_F_Beta_Heli_Transport_02","A3_Air_F_Beta_Parachute_01","A3_Air_F_Beta_Parachute_02","A3_Air_F_EPB_Heli_Light_03","A3_Air_F_EPC_Plane_CAS_01","A3_Air_F_EPC_Plane_CAS_02","A3_Air_F_Gamma_Plane_Fighter_03","A3_Air_F_Heli","A3_Air_F_Heli_Heli_Attack_01","A3_Air_F_Heli_Heli_Attack_02","A3_Air_F_Heli_Heli_Light_01","A3_Air_F_Heli_Heli_Light_02","A3_Air_F_Heli_Heli_Light_03","A3_Air_F_Heli_Heli_Transport_01","A3_Air_F_Heli_Heli_Transport_02","A3_Air_F_Heli_Heli_Transport_03","A3_Air_F_Heli_Heli_Transport_04","A3_Armor_F","A3_armor_f_beta","A3_Armor_F_Panther","A3_armor_f_beta_APC_Tracked_02","A3_Armor_F_EPB_APC_tracked_03","A3_Armor_F_EPB_MBT_03","A3_Armor_F_Slammer","A3_Armor_F_T100K","A3_Boat_F","A3_Boat_F_Boat_Armed_01","A3_Boat_F_Boat_Transport_01","A3_Boat_F_Beta_Boat_Armed_01","A3_Boat_F_Beta_Boat_Transport_01","A3_Boat_F_SDV_01","A3_Boat_F_EPC_Submarine_01_F","A3_Boat_F_Civilian_Boat","A3_Boat_F_Trawler","A3_Boat_F_Gamma_Boat_Transport_01","A3_Boat_F_Heli_Boat_Armed_01","A3_Boat_F_Heli_SDV_01","A3_Characters_F_Common","A3_Characters_F_Bootcamp_Common","A3_Characters_F_EPA","A3_Characters_F_EPB","A3_Characters_F_EPC","A3_Characters_F_Kart","A3_Data_F_Curator_Characters","A3_Data_F_Curator_Virtual","A3_Data_F_Exp_A_Virtual","A3_Data_F_Heli","A3_Air_F_Gamma_UAV_01","A3_Air_F_Gamma_UAV_02","A3_Missions_F_Bootcamp","A3_Missions_F_Curator","A3_Missions_F_EPA","A3_Missions_F_EPB","A3_Missions_F_EPC","A3_Missions_F_Exp_A","A3_Missions_F_Heli","A3_Missions_F_Mark","A3_Missions_F_MP_Mark","A3_Modules_F_Bootcamp_Misc","A3_Modules_F_Curator_Chemlights","A3_Soft_F","A3_Soft_F_MRAP_01","A3_Soft_F_MRAP_02","A3_Soft_F_Offroad_01","A3_Soft_F_Quadbike","A3_Soft_F_MRAP_03","A3_Soft_F_Beta_Quadbike","A3_Soft_F_HEMTT","A3_Soft_F_TruckHeavy","A3_Soft_F_EPC_Truck_03","A3_Soft_F_Car","A3_Soft_F_Gamma_Offroad","A3_Soft_F_Gamma_Quadbike","A3_Soft_F_SUV","A3_Soft_F_Gamma_HEMTT","A3_Soft_F_Gamma_TruckHeavy","A3_Soft_F_Truck","A3_Soft_F_Heli_Car","A3_Soft_F_Heli_MRAP_01","A3_Soft_F_Heli_MRAP_02","A3_Soft_F_Heli_MRAP_03","A3_Soft_F_Heli_Quadbike","A3_Soft_F_Heli_SUV","A3_Soft_F_Heli_Truck","A3_Soft_F_Kart_Kart_01","A3_Static_F_Gamma_AA","A3_Static_F_Gamma_AT","A3_Structures_F_Mil_Scrapyard","A3_Structures_F_Wrecks","A3_Structures_F_EPA_Mil_Scrapyard","A3_Weapons_F_Bootcamp","A3_Weapons_F_Mark","A3_Weapons_F_Mark_LongRangeRifles_DMR_02","A3_Weapons_F_Mark_LongRangeRifles_DMR_03","A3_Weapons_F_Mark_LongRangeRifles_DMR_04","A3_Weapons_F_Mark_LongRangeRifles_DMR_05","A3_Weapons_F_Mark_LongRangeRifles_DMR_06","A3_Weapons_F_Mark_Machineguns_MMG_01","A3_Weapons_F_Mark_Machineguns_MMG_02","A3_epoch_language","A3_epoch_vehicles_1","A3_Air_F_EPC_Plane_Fighter_03","A3_Armor_F_AMV","A3_Armor_F_Marid","A3_Armor_F_EPC_MBT_01","A3_Armor_F_APC_Wheeled_03","A3_CargoPoses_F","A3_CargoPoses_F_Heli","A3_Soft_F_Crusher_UGV","A3_Soft_F_Bootcamp_Offroad_01","A3_Soft_F_Bootcamp_Quadbike","A3_Soft_F_Bootcamp_Truck","A3_Soft_F_Heli_Crusher_UGV","CUP_Core","CUP_StandaloneTerrains_Core","CUP_StandaloneTerrains_Core_Faction","CUP_StandaloneTerrains_Core_VehicleClass","CUP_Worlds","CUP_Worlds_Ambient","CUP_Worlds_Author","CUP_Worlds_Clutter","CUP_Worlds_ClutterDist","CUP_Worlds_Delete","CUP_Worlds_DisableInfiniteTerrain","CUP_Worlds_DustEffects","CUP_Worlds_EnvSounds","CUP_Worlds_FullDetailDist","CUP_Worlds_Grid","CUP_Worlds_Intros","CUP_Worlds_Lighting","CUP_Worlds_Lighting_Chernarus","CUP_Worlds_Lighting_Desert","CUP_Worlds_MapSize","CUP_Worlds_MidDetailTexture","CUP_Worlds_NoDetailDist","CUP_Worlds_PictureMap","CUP_Worlds_PictureShot","CUP_Worlds_Seabed","CUP_Worlds_SkyTexture","CUP_Worlds_StreetLamp","CUP_Worlds_Surfaces","CUP_Worlds_Water","A3_epoch_config","CUP_A1_EditorObjects","CUP_A2_EditorObjects","A3_epoch_code","A3_epoch_functions"];
_skn_whitelist_cfgPatches = [_serverSettingsConfig, "antihack_whitelistedCfgPatches", _whitelistPatches] call EPOCH_fnc_returnConfigEntry;
_skn_adminsOwner = [_serverSettingsConfig, "adminMenu_Owner", []] call EPOCH_fnc_returnConfigEntry;
_skn_adminsHigh = [_serverSettingsConfig, "adminMenu_High", []] call EPOCH_fnc_returnConfigEntry;
_skn_adminsLow = [_serverSettingsConfig, "adminMenu_Low", []] call EPOCH_fnc_returnConfigEntry;
_skn_banReason = [_serverSettingsConfig, "antihack_banReason", "EpochMod.com Autoban"] call EPOCH_fnc_returnConfigEntry;
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
_skn_cfgPatchesCfg = [_serverSettingsConfig, "antihack_cfgPatchesCfg", [0]] call EPOCH_fnc_returnConfigEntry;
_skn_PVSPrefix = [_serverSettingsConfig, "antihack_PVSPrefix", "EPAH_"] call EPOCH_fnc_returnConfigEntry;
_skn_customVariablesCheck = [_serverSettingsConfig, "antihack_customVariablesCheck", true] call EPOCH_fnc_returnConfigEntry;
_skn_customVariables = [_serverSettingsConfig, "antihack_customVariables", []] call EPOCH_fnc_returnConfigEntry;
_loots = ["CfgEpochClient", "lootClasses", EPOCH_lootClasses] call EPOCH_fnc_returnConfigEntryV2;

_skn_PVC_NAMES = ['tradeRequest', 'repairVehicle', 'lockVehicle', 'unlockVehicle', 'fillVehicle', 'clientRevive', 'earthQuake', 'unitSpawn', 'say3D', 'switchMove', 'bankBalance', 'effectCrypto', 'resetGroup', 'BADHIVE', 'groupUpdate', 'groupUidUpdate', 'groupInvitePlayer', 'serverMessage', 'healPlayer', 'airDrop'];
_rndVAR_Count = 83 + (count _skn_PVC_NAMES); // 82 = number of (_skn_rndVA deleteAt 0) uses + _skn_PVC_NAMES count
_skn_rndVA = call compile('epochserver' callExtension format['810|%1', _rndVAR_Count]);

EPOCH_hiveWhitelistVarsArray = [];
if (_skn_customVariablesCheck) then{
	_whitelistConfig = _cfg_variablesConfig >> "whitelist";
	_skn_customVariables append(getArray(_whitelistConfig >> "bis")); //BIS Variables
	_skn_customVariables append(getArray(_whitelistConfig >> "epoch")); //Epoch Variables
	_skn_customVariables append(getArray(_whitelistConfig >> "custom")); //Custom Variables
	// Get any automatically added whitelist vars from Learning feature.
	_response = ["AH-WhitelistVars", (call EPOCH_fn_InstanceID)] call EPOCH_fnc_server_hiveGETRANGE;
	if ((_response select 0) == 1 && typeName(_response select 1) == "ARRAY") then{
		if !((_response select 1) isEqualTo[]) then{
			EPOCH_hiveWhitelistVarsArray = _response select 1;
			_skn_customVariables append EPOCH_hiveWhitelistVarsArray;
		};
	};
};

// For client PVC
_skn_PVC_INDEX = _skn_rndVA deleteAt 0;
{
	_ret = EPOCH_SERVER pushBack (_skn_rndVA deleteAt 0);
}count _skn_PVC_NAMES;

// [["function", _transferBankBalance],owner _transferTarget]
EPOCH_sendPublicVariableClient = compileFinal ("
	private '_index';
	_index = "+str _skn_PVC_NAMES+" find (_this select 0 select 0);
	if (_index != -1) then {
		"+_skn_PVC_INDEX+" = ["+str EPOCH_SERVER+" select _index, _this select 0 select 1];
		(_this select 1) publicVariableClient '"+_skn_PVC_INDEX+"';
	};
");
// [["serverMessage",["str_epoch_restart_in",5]]]
EPOCH_sendPublicVariableAll = compileFinal("
private '_index';
_index = "+str _skn_PVC_NAMES+" find(_this select 0 select 0);
if (_index != -1) then{
	"+_skn_PVC_INDEX+" = ["+str EPOCH_SERVER+" select _index, _this select 0 select 1];
	publicVariable '"+_skn_PVC_INDEX+"';
};
");

_skn_AH_rndVarVehicle = _skn_rndVA deleteAt 0;
_skn_AH_rndVarPlayer  = _skn_rndVA deleteAt 0;

EPOCH_serverCommand = compileFinal ("
switch (_this select 0) do {
		case 'shutdown': { 'epochserver' callExtension '991' };
		case 'message': { 'epochserver' callExtension format['901|%1', _this select 1] };
		case 'lock': { 'epochserver' callExtension '931' };
		case 'unlock': { 'epochserver' callExtension '930' };
		case 'kick': {
			_playerUID = _this select 1;
			if (typeName _playerUID == 'OBJECT') then{
				if (!isNull(_playerUID)) then{
					_playerUID = getPlayerUID _playerUID;
				};
			};
			if (_playerUID != '') then{
				'epochserver' callExtension format['911|%1|%2', _playerUID, _this select 2];
			};
		};
		case 'ban': {
			_playerUID = _this select 1;
			if (typeName _playerUID == 'OBJECT') then{
				if (!isNull(_playerUID)) then{
					_playerUID = getPlayerUID _playerUID;
				};
			};
			if (_playerUID != '') then{
				'epochserver' callExtension format['921|%1|%2|%3', _playerUID, _this select 2, _this select 3];
			};
		};
	};
");

EPOCH_server_getVToken = compileFinal ("_this getVariable ['"+_skn_AH_rndVarVehicle+"',false]");
EPOCH_server_setVToken = compileFinal ("_this setVariable ['"+_skn_AH_rndVarVehicle+"',true];true");
EPOCH_server_getPToken = compileFinal ("private['_ret','_var'];_ret = false;if (typeName(_this select 0)=='OBJECT')then{if (!isNull(_this select 0))then{_var=(_this select 0) getVariable '"+_skn_AH_rndVarPlayer+"';if (!isNil '_var') then {_ret= _var==(_this select 1)}}};if(!_ret)then{['kick',(_this select 0),'Token Check Failed'] call EPOCH_serverCommand};_ret");
EPOCH_server_setPToken = compileFinal ("private '_var';_var = 'epochserver' callExtension '810';_this setVariable ['"+_skn_AH_rndVarPlayer+"',_var];_var");

if (!_skn_enableAntihack) exitWith {
	EPOCH_server_pushPlayer = compileFinal ("EPOCH_C_SET = _this select 2;EPOCH_C_SET pushBack '"+_skn_PVC_INDEX+"';EPOCH_C_SET pushBack '';(_this select 0) publicVariableClient 'EPOCH_C_SET'");
	EPOCH_server_isPAdmin = compileFinal ("false");
	EPOCH_server_Authed = compileFinal ("true");
	EPOCH_server_disconnect = compileFinal("true");
	EPOCH_server_kickToLobby = compileFinal("true");
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


_skn_server_getRealTime = _skn_rndVA deleteAt 0;
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
_skn_tg_map_vehicle	  = _skn_rndVA deleteAt 0;
_skn_tg_map_ai		   = _skn_rndVA deleteAt 0;
_skn_tg_map_basebuilding = _skn_rndVA deleteAt 0;

_skn_t1 = _skn_rndVA deleteAt 0;
_skn_t2 = _skn_rndVA deleteAt 0;
_skn_t3 = _skn_rndVA deleteAt 0;
_skn_t4 = _skn_rndVA deleteAt 0;
_skn_t5 = _skn_rndVA deleteAt 0;

_skn_kickToLobby   = _skn_rndVA deleteAt 0;
_skn_whitelistVars = _skn_rndVA deleteAt 0;

if (_skn_customVariablesCheck) then{
	// Gather all random global vars from AH for whitelist var checks
	_skn_customVariables append [_skn_PVC_INDEX,_skn_whitelistVars,_skn_kickToLobby,toLower(_skn_doKickBan),toLower(_skn_doTokenAuth)];
	_skn_customVariables append [_skn_AH_Init,_skn_AH_Code,_skn_AH_Code_CA,_skn_AH_Code_CB,_skn_AH_Ban,_skn_antiTeleportPVC,_skn_Admin_Init];
	_skn_customVariables append [toLower("FW"+_skn_AH_rndVar),toLower("FA"+_skn_AH_rndVar),toLower("FWC"+_skn_AH_rndVar)];

	// Globally brodcast whitelist vars array
	missionNamespace setVariable [_skn_whitelistVars,_skn_customVariables];
	call compile("publicVariable " + str _skn_whitelistVars + ";");
};

EPOCH_server_kickToLobby = compileFinal ("if !(isNull _this) then {"+_skn_kickToLobby+" = true;(owner _this) publicVariableClient '"+_skn_kickToLobby+"';};");

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

_stringInArray = {
	private "_ret";
	_ret = false;
	{if (_x in _case)exitWith {_ret = true}}forEach _this;
	_ret
};

_displaysArray = [];
{_displaysArray pushBack [_x,[],[]]} forEach ["RscDisplayMainMap","RscDisplayGetReady","RscDisplayInventory","RscDisplayLoadMission","RscDisplayInterrupt","RscDisplayOptionsVideo","RscDisplayOptions","RscDisplayAVTerminal","RscDisplayConfigure","RscDisplayConfigureAction","RscDisplayConfigureControllers","RscDisplayControlSchemes","RscDisplayCustomizeController","RscDisplayDebriefing","RscDisplayDiary","RscDisplayGameOptions","RscDisplayJoystickSchemes","RscDisplayLoading","RscDisplayMicSensitivityOptions","RscDisplayOptionsAudio","RscDisplayOptionsLayout","RscDisplayStart","RscDisplayVehicleMsgBox","RscDisplayInsertMarker"];
_displays = [(_config >> "displayOnload"), "checkDisplays", _displaysArray] call EPOCH_fnc_returnConfigEntry;


_escapeQuotes = {
	_return = [];
	{
		_return pushback _x;
		if (_x == 34) then {
			_return pushback _x;
		};
	} forEach toArray _this;
	toString _return
};

_cfg_displayArray = [];
{
	_onLoad   = ((getText(configFile >> (_x select 0) >> "onLoad")) call _escapeQuotes);
	_onUnload = ((getText(configFile >> (_x select 0) >> "onUnload")) call _escapeQuotes);
	_onLoad   = [_onLoad];
	_onUnload = [_onUnload];
	{
		_onLoad pushBack(_x call _escapeQuotes);
	} forEach(_x select 1);
	{
		_onUnload pushBack(_x call _escapeQuotes);
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
	if (["MAP-PLAYER","MAP-CORPSE","MAP-LOOT","MAP-VEHICLE","MAP-AI","MAP-BASEBUILDING"] call _stringInArray) then {
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
				,['  Loot Marker', [], {"+_skn_tg_map_loot+" = !"+_skn_tg_map_loot+"; if ("+_skn_tg_map_loot+") then {waitUntil {"+_skn_mapLootArray+" = nearestObjects[getPos player, ['WH_Loot', 'Animated_Loot'], 10000];uiSleep 10;!"+_skn_tg_map_loot+"};"+_skn_mapLootArray+" = []};['Loot MARKER',if ("+_skn_tg_map_loot+") then [{2},{1}]] call "+_skn_adminLog_PVC+"}, '2', []]
			";
		};
		if ("MAP-VEHICLE" in _case) then {
			_temp = _temp + "
				,['  Vehicle Marker', [], {"+_skn_tg_map_vehicle+" = !"+_skn_tg_map_vehicle+"; ['Vehicle MARKER',if ("+_skn_tg_map_vehicle+") then [{2},{1}]] call "+_skn_adminLog_PVC+"}, '2', []]
			";
		};
		if ("MAP-AI" in _case) then {
			_temp = _temp + "
				,['  AI Marker', [], {"+_skn_tg_map_ai+" = !"+_skn_tg_map_ai+"; ['AI MARKER',if ("+_skn_tg_map_ai+") then [{2},{1}]] call "+_skn_adminLog_PVC+"}, '2', []]
			";
		};
		if ("MAP-BASEBUILDING" in _case) then {
			_temp = _temp + "
				,['  Base Building Marker (WIP)', [], {"+_skn_tg_map_basebuilding+" = !"+_skn_tg_map_basebuilding+"; ['Base Building MARKER',if ("+_skn_tg_map_basebuilding+") then [{2},{1}]] call "+_skn_adminLog_PVC+"}, '2', []]
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
_centerDistance = 30;

// Only set these if prefix is not used since we can filter for it
if (_skn_PVSPrefix == "") then {
	"epochserver" callExtension format["800|%1|%2|%3|%4", _skn_doKickBan, _skn_doAdminRequest, _skn_doAdminLog, _skn_doTokenAuth];
};

EPOCH_server_pushPlayer = compileFinal ("
	EPOCH_C_SET = _this select 2;
	if (_this select 1 in "+ str _skn_adminUIDArray+") then {
		(_this select 0) publicVariableClient '"+_skn_Admin_Code+"';
		(_this select 0) publicVariableClient '"+_skn_pv_adminLog+"';
		(_this select 0) publicVariableClient '"+_skn_pv_hackerLog+"';
		EPOCH_C_SET pushBack '"+_skn_PVC_INDEX+"';
		EPOCH_C_SET pushBack '[] spawn "+_skn_Admin_Init+"';
	} else {
		EPOCH_C_SET pushBack '"+_skn_PVC_INDEX+"';
		EPOCH_C_SET pushBack '[] spawn "+_skn_AH_Init+"';
	};
	(_this select 0) publicVariableClient 'EPOCH_C_SET';
	true
");
EPOCH_server_isPAdmin = compileFinal ("if (isNull _this) then {false} else {getPlayerUID _this in "+str _skn_adminUIDArray+"}");

_sknBanANDSleep = _skn_AH_Ban+"; uiSleep 60";
_sknBanANDSleepQuick = _skn_AH_Ban+"; uiSleep 1";

// CfgPatches Check
_sknPatches = [];
"_sknPatches pushBack (configName _x)" configClasses (configFile >> "CfgPatches");
{if !(_x in _sknPatches) then {_sknPatches pushBack _x}}forEach _skn_whitelist_cfgPatches;
_skn_addonCheckCode = if (_skn_check_addons) then {"[] spawn{_config = '!(configName _x in "+str _sknPatches+")' configClasses (configFile >> 'CfgPatches');if !(_config isEqualTo []) then {[format['Disallowed Addon %1',_config],"+str (_skn_cfgPatchesCfg select 0)+"] call "+_skn_AH_Ban+"}};"} else {""};
_skn_fileCheckCode = if (_skn_check_files isEqualTo []) then {""} else {"{if (str(compile preprocessFileLineNumbers (_x select 0)) != str(missionNamespace getVariable [_x select 1,'']))exitWith{[format['Modified File %1 (%2/%3)',_x select 1,count toArray str (compile preprocessFileLineNumbers (_x select 0)),count toArray str(missionNamespace getVariable [_x select 1,''])],0] call "+_skn_AH_Ban+"}} forEach "+str _skn_check_files+";"};

_sknCustomVarCheckModeCode = [_serverSettingsConfig, "antihack_customVariablesCheckMode", 0] call EPOCH_fnc_returnConfigEntry;
_sknCustomVarCheckCode = if (_skn_customVariablesCheck) then {"
{
	if !(_x in (missionNamespace getVariable ["+str _skn_whitelistVars+",[]])) then{
		[format['(WIP) Unknown Variable (missionNamespace): %1', _x], ["+str _sknCustomVarCheckModeCode+",[toArray(_x)]]] call "+_sknBanANDSleepQuick+";
	}
}forEach(allVariables missionNamespace);
"} else {""};


_sknAddActionCheck = if ([_serverSettingsConfig, "antihack_addActionCheck", true] call EPOCH_fnc_returnConfigEntry) then{ "
if (player == _ActionVehicle) then[{_ActionCount = _ActionCount + 1}, { _ActionVehicle = player; _ActionCount = 0 }];
_addCase = player addAction['', '', [], -5, false, true, '', 'false'];
player removeAction _addCase;
if (_addCase != _ActionCount) then{
	[format['addAction %1/%2', _addCase, _ActionCount], 0] call "+_sknBanANDSleep+";
};
"} else {""};


call compile (_skn_server_getRealTime+" = {
	_time = call compile ('epochserver' callExtension '510');
	_hour = _time select 3;
	_min = _time select 4;
	if (_min < 10) then {_min = '0'+str _min};
	if (_hour < 10) then {_hour = '0'+str _hour};
	format ['%1:%2',_hour,_min]
};");

//[_data,_player,_token];
call compile("'"+_skn_doTokenAuth+"' addPublicVariableEventHandler {
	_array = _this select 1;
	_tokenSet = false;
	if !([_array select 1, _array select 2] call EPOCH_server_getPToken) exitWith{};
	if (typeName(_array select 0) == 'STRING') then {
		if (_array select 0 == '"+_skn_AH_rndVarAHInitCheckToken+"') then {
			_tokenSet = true;
			_puid = (_array select 1) getVariable['PUID', ''];
			if (_puid != '') then {
				if !(_puid in "+_skn_AH_rndVarAHInitCheck+") then {
					"+_skn_AH_rndVarAHInitCheck+" pushBack _puid;
					diag_log format['DEBUG: player auth token set %1', _array];
				};
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


//[[_case,_time,_name,_uid,_save],[1, 0, 0, 1]]
call compile ("'"+_skn_doKickBan+"' addPublicVariableEventHandler {
	_array = _this select 1;
	_player =_array select 2;
	if !([_player,_array select 3] call EPOCH_server_getPToken) exitWith {
		['ahe', format['Token is different [%1,%2] %3',if (!isNull _player) then { _player getVariable ['"+_skn_AH_rndVarPlayer+"','']}else{'PlayerObj NULL'}, _array select 3, _array]] call EPOCH_fnc_server_hiveLog;
	};
	_text = toString(_array select 0);

	_mode = _array select 1;
	_data = [];
	if (typeName _mode == 'ARRAY') then{
		_mode = (_array select 1) select 0;
		_data = (_array select 1) select 1;
	};

	if (_mode == 0) then{
		['ahb', format['%1 (%2): %3', name _player, getPlayerUID _player, _text]] call EPOCH_fnc_server_hiveLog;
		"+_skn_pv_hackerLog+" pushBack [[0,call "+_skn_server_getRealTime+",name _player,getPlayerUID _player,_text],[1, 0, 0, 1]];
		'epochserver' callExtension format['820|%1|"+_skn_banReason+"',getPlayerUID _player];
	} else {
		if (_mode == 2) then{
			_unknownVar = toString(_data select 0);
			_safeVars   = missionNamespace getVariable ["+str _skn_whitelistVars+",[]];
			_trusted	= "+_str_learningModeCheck+";
			if !(_unknownVar in _safeVars) then{
				if (_trusted) then {

					_safeVars pushBack _unknownVar;
					missionNamespace setVariable ["+str _skn_whitelistVars+",_safeVars];
					publicVariable "+str _skn_whitelistVars+";

					if !(_unknownVar in EPOCH_hiveWhitelistVarsArray) then{
						EPOCH_hiveWhitelistVarsArray pushBack _unknownVar;
						['AH-WhitelistVars', (call EPOCH_fn_InstanceID), EPOCH_hiveWhitelistVarsArray] call EPOCH_fnc_server_hiveSET;
					};

					['ahl', format['LEARNING: %1 (%2): %3', name _player, getPlayerUID _player, _text]] call EPOCH_fnc_server_hiveLog;
					"+_skn_pv_hackerLog+" pushBack[[1, call "+_skn_server_getRealTime+", name _player, getPlayerUID _player, format['LEARNING: %1',_text]], []];
				} else {
					['ahb', format['%1 (%2): %3', name _player, getPlayerUID _player, _text]] call EPOCH_fnc_server_hiveLog;
					"+_skn_pv_hackerLog+" pushBack [[0,call "+_skn_server_getRealTime+",name _player,getPlayerUID _player,_text],[1, 0, 0, 1]];
					_banID = 1;
					'epochserver' callExtension format['820|%1|"+_skn_banReason+" #V%2',getPlayerUID _player,_banID];
				};
			};
		}else {
			['ahl', format['%1 (%2): %3', name _player, getPlayerUID _player, _text]] call EPOCH_fnc_server_hiveLog;
			"+_skn_pv_hackerLog+" pushBack[[1, call "+_skn_server_getRealTime+", name _player, getPlayerUID _player, _text], []];
		};
	};
	{
		if (_x call EPOCH_server_isPAdmin) then {
			(owner _x) publicVariableClient '"+_skn_pv_hackerLog+"';
		};
	}forEach playableUnits;
};");
//0 = BAN
//1 = LOG
//[2,varname] = Self-learning vars from trusted users.

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
		"+_skn_doKickBan+" = [format['Cannot Load AH [%1,%2]',!isNil '"+_skn_AH_Code_CA+"',!isNil '"+_skn_AH_Code_CB+"'],1,player,Epoch_personalToken];
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
		"+_skn_doKickBan+" = [format['Cannot Load AH [%1,%2]',!isNil '"+_skn_AH_Code_CA+"',!isNil '"+_skn_AH_Code_CB+"'],1,player,Epoch_personalToken];
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
			onEachFrame EPOCH_onEachFrame;

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
		_displayCountKD = 0;
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
			_display46 = findDisplay 46;
			if !(isNull _display46) then {
				_display46 displayRemoveAllEventHandlers 'KeyDown';
				_addCase = _display46 displayAddEventHandler ['KeyDown',{"+_skn_displayAddEHKeyDown+"}];
				if (_addCase != _displayCountKD) then {
					[format['DEH: KeyDown %1/%2',_addCase,_displayCountKD],0] call "+_sknBanANDSleep+";
				};
				_display46 displayRemoveAllEventHandlers 'KeyUp';
				_addCase = _display46 displayAddEventHandler ['KeyUp',{"+_skn_displayAddEHKeyUp+"}];
				if (_addCase != _displayCount) then {
					[format['DEH: KeyUp %1/%2',_addCase,_displayCount],0] call "+_sknBanANDSleep+";
				};
			};
			uiSleep ((random 1)+1);
		};
	};
	_t = _t + '"+_skn_t3+"';
	[] spawn {
		_cntBan = 0;
		while {true} do {
			_lastTime = diag_tickTime;
			_lastPos = getPosATL vehicle player;
			_notNearbySpawn = _lastPos distance "+str _skn_spawnPointCenter+" > "+str _centerDistance+";
			while {alive player} do {
				_curTime = diag_tickTime;
				_curPos = getPosATL vehicle player;
				_distance = _lastPos distance _curPos;

				if ((_curTime-_lastTime)>1 || _distance>10) then {
					if (((_distance/(_curTime-_lastTime)) > 10) && _notNearbySpawn && (player == vehicle player)) then {
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
	};
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
			"+_sknCustomVarCheckCode+"
			uiSleep ((random 10)+10);
		};
	};
	_t = _t + '"+_skn_t5+"';
	"+_skn_doTokenAuth+" = [_t,player,Epoch_personalToken];
	publicVariableServer '"+_skn_doTokenAuth+"';
	"+_skn_doTokenAuth+" = nil;
	'"+_skn_kickToLobby+"' addPublicVariableEventHandler {
		[] spawn {waitUntil {(findDisplay 46) closeDisplay 0; false}}
	};
	"+_skn_AH_Code_CB+" = true;
	true
");

call compile (_skn_AH_Ban+" = _skn_code_ban;publicVariable '"+_skn_AH_Ban+"'");
call compile (_skn_AH_Code+" = _skn_code_antihack;publicVariable '"+_skn_AH_Code+"'");
call compile (_skn_AH_Init+" = _skn_code_init;publicVariable '"+_skn_AH_Init+"'");
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

		"+_skn_pv_adminLog+" pushBack [call "+_skn_server_getRealTime+",_adminNAME,_toggle,_this select 0];
		diag_log format ['SKN2 AdminRequest %1',"+_skn_pv_adminLog+"];
		{
			if (_x call EPOCH_server_isPAdmin) then {
				(owner _x) publicVariableClient '"+_skn_pv_adminLog+"';
			};
		}forEach playableUnits;
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
		[['healPlayer'], owner _playerObj] call EPOCH_sendPublicVariableClient;
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
		deleteVehicle _content;
	};
	if (_case == 106) then {
		_admin hideObjectGlobal _content;
	};
	if (_case == 107) then {
		_player = objectFromNetId (_content select 0);
		if (!isNull _player) then {
			_cIndex = EPOCH_customVars find 'Crypto';
			_vars = _player getVariable['VARS', [] + EPOCH_defaultVars_SEPXVar];
			_current_crypto = (((_vars select _cIndex) + (_content select 1)) min "+str _skn_playerCryptoLimit+") max 0;
			[['effectCrypto', _current_crypto], (owner _player)] call EPOCH_sendPublicVariableClient;
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
				[['fillVehicle', [_content, 1]], owner _admin] call EPOCH_sendPublicVariableClient;
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
					_position = getPosATL _target;

					_slot = EPOCH_VehicleSlots select 0;
					EPOCH_VehicleSlots = EPOCH_VehicleSlots - [_slot];
					EPOCH_VehicleSlotCount = count EPOCH_VehicleSlots;
					publicVariable 'EPOCH_VehicleSlotCount';

					_vehObj = createVehicle[_item, _position, [], 20, 'NONE'];
					_return = true;
					_vehObj call EPOCH_server_setVToken;
					addToRemainsCollector[_vehObj];

					_vehObj disableTIEquipment true;

					clearWeaponCargoGlobal	_vehObj;
					clearMagazineCargoGlobal  _vehObj;
					clearBackpackCargoGlobal  _vehObj;
					clearItemCargoGlobal	  _vehObj;
					_vehObj lock true;

					_plyrUID = getPlayerUID _target;
					_plyrGroup = _target getVariable['GROUP', ''];

					_lockOwner = _plyrUID;
					if (_plyrGroup != '') then {
						_lockOwner = _plyrGroup;
					};

					_vehLockHiveKey = format['%1:%2', (call EPOCH_fn_InstanceID), _slot];
					['VehicleLock', _vehLockHiveKey, EPOCH_vehicleLockTime, [_lockOwner]] call EPOCH_fnc_server_hiveSETEX;

					_config = (configFile >> 'CfgVehicles' >> _item >> 'availableColors');
					if (isArray(_config)) then {
						_textureSelectionIndex = configFile >> 'CfgVehicles' >> _item >> 'textureSelectionIndex';
						_selections = if (isArray(_textureSelectionIndex)) then {getArray(_textureSelectionIndex)} else {[0]};
						_colors = getArray(_config);
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
	comment 'Epoch Mod Antihack - Niklas Wagner - www.skaronator.com - Aaron Clark - www.epochmod.com - License: (CC) Attribution-NonCommercial-NoDerivatives 4.0 International';
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
	"+_skn_tg_map_vehicle+" = false;
	"+_skn_tg_map_ai+" = false;
	"+_skn_tg_map_basebuilding+" = false;

	uiNamespace setVariable['ESP_mainMap', findDisplay 12 displayCtrl 51];
	uiNamespace setVariable['ESP_adminMap', findDisplay -1337 displayCtrl 7];
	(findDisplay 46) displayAddEventHandler ['KeyDown','_this call "+_skn_AdminKeyDown+"'];
	((findDisplay 12) displayCtrl 51) ctrlAddEventHandler ['MouseButtonDown', 'if (_this select 5) then {_this call "+_skn_mapTeleport+"}'];

	{
		(uiNamespace getVariable _x) ctrlRemoveAllEventHandlers 'Draw';
		(uiNamespace getVariable _x) ctrlAddEventHandler['Draw',{

			_getDmgColor = {
				_color = [1,1,1,1];
				_dmg = damage _this;
				if (_dmg >= 0.25) then {_color = [1,1,0,1];
					if (_dmg >= 0.5) then { _color = [1,0.55,0,1];
						if (_dmg >= 0.75) then { _color = [1,0,0,1];
							if (_dmg >= 0.9) then { _color = [0,0,0,1];
							};
						};
					};
				};
				_color
			};
			_display = _this select 0;
			if ("+_skn_tg_map_player+") then {
				_size = (0.5/ctrlMapScale _display) max 20;
				{
					if (isPlayer _x) then {
						_display drawIcon [
							getText (configFile >> 'CfgVehicles' >> typeOf _x >> 'Icon'), _x call _getDmgColor, visiblePosition _x, _size, _size, getDir _x, name _x
						];
					};
				}forEach playableUnits;
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
			if ("+_skn_tg_map_vehicle+") then {
				_size = (1/ctrlMapScale _display) max 20;
				{
					if (alive _x) then {
						_display drawIcon [
							getText (configFile >> 'CfgVehicles' >> typeOf _x >> 'Icon'), _x call _getDmgColor, visiblePosition _x, _size, _size, getDir _x,
							getText (configFile >> 'CfgVehicles' >> typeOf _x >> 'displayName')
						];
					};
				}forEach vehicles;
			};
			if ("+_skn_tg_map_ai+") then {
				_size = (0.5/ctrlMapScale _display) max 20;
				{
					_agent = agent _x;
					_display drawIcon [
						getText (configFile >> 'CfgVehicles' >> typeOf _agent >> 'Icon'), _agent call _getDmgColor, visiblePosition _agent, _size, _size, getDir _agent,
						getText (configFile >> 'CfgVehicles' >> typeOf _agent >> 'displayName')
					];
				}forEach agents;
			};
			if ("+_skn_tg_map_basebuilding+") then {

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
		(1 call "+_skn_getCtrl+") ctrlSetText format['Players %1 of %2',count playableUnits,playersNumber civilian];
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
			waitUntil {
				player setBleedingRemaining 0;
				player setOxygenRemaining 1;
				player allowDamage false;
				{
					missionNamespace setVariable[format['EPOCH_player%1', _x], EPOCH_defaultVars select(EPOCH_customVars find _x)]
				} forEach['Temp','Hunger','Thirst','Toxicity','Stamina','HitPoints','BloodP'];
				EPOCH_playerEnergy = EPOCH_playerEnergyMax;
				uiSleep 0.25;
				!"+_skn_tg_godMode+"
			};
			player allowDamage true;
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
		_lootLoc = getPosASL player;
		_lootClasses = (configFile >> 'CfgBuildingLootPos') call Bis_fnc_getCfgSubClasses;
		_lootClasses = _lootClasses - ['Default'];

		_objects = nearestObjects[_lootLoc, _lootClasses, _this];

		_cntItem = 0;
		_cntBuildings = 0;

		{
			_building = _x;
			_pos = getPosATL _building;
			_config = configFile >> 'CfgBuildingLootPos' >> (typeOf _building);
			if (isClass(_config)) then {
				_cntBuildings = _cntBuildings + 1;
				{
					_positions = [] + getArray(_config >> (_x select 0));
					if !(_positions isEqualTo[]) then {
						_class = _x select 1;
						_randomColor = _x select 2;
						{
							_lootBiasPos = getNumber(_config >> 'lootBiasPos');
							_lootType = getText(_config >> 'lootType');
							if ((random 100) < _lootBiasPos) then {

								_pos = _building modelToWorld(_x select 0);

								if (nearestObjects[_pos, ['WH_Loot', 'Animated_Loot'], 2] isEqualTo[]) then {
									_cntItem = _cntItem + 1;

									if ((typeName _class) == 'ARRAY') then {
										_class = _class select(floor(random(count _class)));
									};
									_dir = (_x select 1) + (getDir _building);
									if (_dir > 360) then {
										_dir = _dir - 360;
									};
									if (_lootType == 'mil' && _class == 'Bed_EPOCH') then {
										_class = 'Bunk_EPOCH';
									};
									_item = createVehicle[_class, _pos, [], 0.0, 'CAN_COLLIDE'];
									_item setDir _dir;

									if (_pos select 2 < 0) then {
										_pos set[2, 0];
									};

									if (surfaceIsWater _pos) then {
										_item setPosASL _pos;
									} else {
										_item setPosATL _pos;
									};

									if (typeName _randomColor isEqualTo 'STRING') then{
										_randomColor = _randomColor isEqualTo 'true';
									};

									if (_randomColor) then {
										_colors = [] + getArray(configFile >> 'CfgVehicles' >> _class >> 'availableTextures');
										if !(_colors isEqualTo[]) then {
											_color = _colors select floor(random(count _colors));
											_item setObjectTextureGlobal[0, _color];
										};
									};
								};
							};
						}forEach _positions;
					};
				}forEach "+str _loots+";
			};
		}forEach (nearestObjects[getPosASL player, _lootClasses, _this]);
		[format['Spawn Loot (%1) for %2 Buildings (%3 Container)',_this,_cntBuildings,_cntItem],0] call "+_skn_adminLog_PVC+";
		hint format['Spawned Loot for %1 Buildings (%2 Container)',_cntBuildings,_cntItem];
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
						reverse _lastPos;
						if (count _lastPos > 101) then {
							_lastPos resize 101;
						};
						reverse _lastPos;
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
		_cam setDir([_getPos, player] call BIS_fnc_dirTo);
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
		if (typeName (_data select 1) == 'CODE') then {(_data select 0) spawn (_data select 1)};
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
		if (_this == 61) then {
			_airVehicles = ""
					getText(_x >> 'displayName') != '' &&
					getText(_x >> 'picture') != '' &&
					getNumber(_x >> 'type') != 0 &&
					getText (_x >> 'vehicleClass') in ['Air']
			""configClasses (configFile >> 'CfgVehicles');
			{
				_config = 'CfgPricing' call EPOCH_returnConfig;
				if (isClass(_config >> configName _x)) then{
					_index = _ctrl lbAdd format['%1', getText(_x >> 'displayName')];
					_ctrl lbSetData[_index, str[configName _x, 6, 0]];
					_ctrl lbSetPicture[_index, getText(_x >> 'picture')];
				};
			}forEach _airVehicles;
		};
		if (_this == 62) then {
			_landVehicles = ""
					getText(_x >> 'displayName') != '' &&
					getText(_x >> 'picture') != '' &&
					configName _x != 'PaperCar' &&
					getText (_x >> 'vehicleClass') in ['Car']
			""configClasses (configFile >> 'CfgVehicles');
			{
				_config = 'CfgPricing' call EPOCH_returnConfig;
				if (isClass(_config >> configName _x)) then{
					_index = _ctrl lbAdd format['%1', getText(_x >> 'displayName')];
					_ctrl lbSetData[_index, str[configName _x, 6, 1]];
					_ctrl lbSetPicture[_index, getText(_x >> 'picture')];
				};
			}forEach _landVehicles;
		};
		if (_this == 63) then {
			_shipVehicles = ""
					getText(_x >> 'displayName') != '' &&
					getText(_x >> 'picture') != '' &&
					getNumber(_x >> 'type') in [1,2,3,4] &&
					getText (_x >> 'vehicleClass') in ['Ship']
			""configClasses (configFile >> 'CfgVehicles');
			{
				_config = 'CfgPricing' call EPOCH_returnConfig;
				if (isClass(_config >> configName _x)) then{
					_index = _ctrl lbAdd format['%1', getText(_x >> 'displayName')];
					_ctrl lbSetData[_index, str[configName _x, 6, 2]];
					_ctrl lbSetPicture[_index, getText(_x >> 'picture')];
				};
			}forEach _shipVehicles;
		};
		if (_this == 64) then {
			_weapons = ""
					getText(_x >> 'displayName') != '' &&
					getText(_x >> 'picture') != '' &&
					getNumber(_x >> 'scope') in [0,2] &&
					getNumber(_x >> 'type') in [1,2,4]
			""configClasses (configFile >> 'CfgWeapons');
			{
				_config = 'CfgPricing' call EPOCH_returnConfig;
				if (isClass(_config >> configName _x)) then{
					_index = _ctrl lbAdd format['%1', getText(_x >> 'displayName')];
					_type = getNumber(_x >> 'type') - 1;
					if (getNumber(_x >> 'type') == 4) then { _type = 2 };
					_ctrl lbSetData[_index, str[configName _x, _type, _type + 3]];
					_ctrl lbSetPicture[_index, getText(_x >> 'picture')];
				};
			}forEach _weapons;
		};
		if (_this == 65) then {
			_magazines = ""
					getText(_x >> 'displayName') != '' &&
					getText(_x >> 'picture') != '' &&
					getNumber(_x >> 'scope') in [0,2] &&
					getText(_x >> 'ammo') != ''
			""configClasses (configFile >> 'CfgMagazines');
			{
				_config = 'CfgPricing' call EPOCH_returnConfig;
				if (isClass(_config >> configName _x)) then{
					_index = _ctrl lbAdd format['%1', getText(_x >> 'displayName')];
					_ctrl lbSetData[_index, str[configName _x, -1, 6]];
					_ctrl lbSetPicture[_index, getText(_x >> 'picture')];
				};
			}forEach _magazines;
		};
		if (_this == 66) then {
			_magazines = ""
			getText(_x >> 'displayName') != '' &&
			getText(_x >> 'picture') != '' &&
			getNumber(_x >> 'scope') in[0, 2] &&
			getText(_x >> 'ammo') == ''
			""configClasses(configFile >> 'CfgMagazines');
			{
				_config = 'CfgPricing' call EPOCH_returnConfig;
				if (isClass(_config >> configName _x)) then{
					_index = _ctrl lbAdd format['%1', getText(_x >> 'displayName')];
					_ctrl lbSetData[_index, str[configName _x, -1, 7]];
					_ctrl lbSetPicture[_index, getText(_x >> 'picture')];
				};
			}forEach _magazines;
		};
		if (_this == 67) then {

			_backpack = ""getText(_x >> 'displayName') != '' && getText(_x >> 'picture') != '' &&  getNumber(_x >> 'isbackpack') == 1""configClasses(configFile >> 'CfgVehicles');
			{
				_config = 'CfgPricing' call EPOCH_returnConfig;
				if (isClass(_config >> configName _x)) then{
					_index = _ctrl lbAdd format['%1', getText(_x >> 'displayName')];
					_ctrl lbSetData[_index, str[configName _x, 3, 8]];
					_ctrl lbSetPicture[_index, getText(_x >> 'picture')];
				};
			}forEach _backpack;
		};
		if (_this == 68) then {
			_uniforms = ['U_O_FullGhillie_lsh',
				'U_O_FullGhillie_sard',
				'U_O_FullGhillie_ard',
				'U_O_CombatUniform_ocamo',
				'U_O_GhillieSuit',
				'U_O_PilotCoveralls',
				'U_O_Wetsuit',
				'U_OG_Guerilla1_1',
				'U_OG_Guerilla2_1',
				'U_OG_Guerilla2_2',
				'U_OG_Guerilla2_3',
				'U_OG_Guerilla3_1',
				'U_OG_Guerilla3_2',
				'U_OG_leader',
				'U_C_Poloshirt_stripped',
				'U_C_Poloshirt_blue',
				'U_C_Poloshirt_burgundy',
				'U_C_Poloshirt_tricolour',
				'U_C_Poloshirt_salmon',
				'U_C_Poloshirt_redwhite',
				'U_C_Poor_1',
				'U_C_WorkerCoveralls',
				'U_C_Journalist',
				'U_C_Scientist',
				'U_OrestesBody',
				'U_Wetsuit_uniform',
				'U_Wetsuit_White',
				'U_Wetsuit_Blue',
				'U_Wetsuit_Purp',
				'U_Wetsuit_Camo',
				'U_CamoRed_uniform',
				'U_CamoBrn_uniform',
				'U_CamoBlue_uniform',
				'U_Camo_uniform',
				'U_ghillie1_uniform',
				'U_ghillie2_uniform',
				'U_ghillie3_uniform',
				'U_C_Driver_1',
				'U_C_Driver_2',
				'U_C_Driver_3',
				'U_C_Driver_4',
				'U_C_Driver_1_black',
				'U_C_Driver_1_blue',
				'U_C_Driver_1_green',
				'U_C_Driver_1_red',
				'U_C_Driver_1_white',
				'U_C_Driver_1_yellow',
				'U_C_Driver_1_orange',
				'U_C_Driver_1_red'];

			{
				_index = _ctrl lbAdd format['%1', getText(configFile >> 'CfgWeapons' >> _x >> 'displayName')];
				_ctrl lbSetData[_index, str[_x, -1, 9]];
				_ctrl lbSetPicture[_index, getText(configFile >> 'CfgWeapons' >> _x >> 'picture')];
			}forEach _uniforms;
		};
		if (_this == 69) then {
			_optics = ['optic_Arco', 'optic_Hamr', 'optic_Aco', 'optic_ACO_grn', 'optic_Aco_smg', 'optic_ACO_grn_smg', 'optic_Holosight', 'optic_Holosight_smg', 'optic_SOS', 'optic_MRCO', 'optic_DMS', 'optic_Yorris', 'optic_MRD', 'optic_LRPS', 'optic_NVS', 'optic_tws', 'optic_tws_mg'];
			_muzzles = ['muzzle_snds_H','muzzle_snds_L','muzzle_snds_M','muzzle_snds_B','muzzle_snds_H_MG','muzzle_snds_acp','Heal_EPOCH','Defib_EPOCH','Repair_EPOCH','acc_flashlight','acc_pointer_IR'];
			_misc = ['Binocular','NVG_EPOCH','ItemCompass','ItemGPS','ItemMap','EpochRadio0','EpochRadio1','EpochRadio2','EpochRadio3','EpochRadio4','EpochRadio5','EpochRadio6','EpochRadio7','EpochRadio8','EpochRadio9','ItemWatch'];
			_attachments = _optics + _muzzles + _misc;
			{
				_config = 'CfgPricing' call EPOCH_returnConfig;
				if (isClass(_config >> _x)) then{
					_index = _ctrl lbAdd format['%1', getText(configFile >> 'CfgWeapons' >> _x >> 'displayName')];
					_ctrl lbSetData[_index, str[_x, -1, 9]];
					_ctrl lbSetPicture[_index, getText(configFile >> 'CfgWeapons' >> _x >> 'picture')];
				};
			}forEach _attachments;
		};
		if (_this == 70) then {
			_headgear = ['wolf_mask_epoch','pkin_mask_epoch','clown_mask_epoch'];
			for '_h' from 1 to 104 do
			{
				_headgear pushBack format['H_%1_EPOCH',_h];
			};
			{
				_index = _ctrl lbAdd format['%1', getText(configFile >> 'cfgWeapons' >> _x >> 'displayName')];
				_ctrl lbSetData[_index, str[_x, -1, 9]];
				_ctrl lbSetPicture[_index, getText(configFile >> 'cfgWeapons' >> _x >> 'picture')];
			}forEach _headgear;
		};
		if (_this == 71) then {
			_vests = [];
			for '_v' from 1 to 40 do
			{
				_vests pushBack format['V_%1_EPOCH', _v];
			};
			{
				_index = _ctrl lbAdd format['%1', getText(configFile >> 'cfgWeapons' >> _x >> 'displayName')];
				_ctrl lbSetData[_index, str[_x, -1, 9]];
				_ctrl lbSetPicture[_index, getText(configFile >> 'cfgWeapons' >> _x >> 'picture')];
			}forEach _vests;
		};
	};
	"+_skn_FillPlayerMenu+" = {
		_ctrl = 5 call "+_skn_getCtrl+";
		lbclear _ctrl;

		_sorted = [];
		_unsorted = playableUnits;

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

		_alphabetically = _unsortedName call BIS_fnc_sortAlphabetically;
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
	if (typename (_this select 2) == 'STRING') then {
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
call compile (_skn_Admin_Init+" = _skn_admininit;publicVariable '"+_skn_Admin_Init+"'");
