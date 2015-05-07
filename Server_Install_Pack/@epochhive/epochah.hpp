// Anti Hack
antihack_Enabled = true; // built-in Anti-Hack
antihack_cfgPatchesCheck = true; // cfgPatches (AddOn Check)
antihack_PVSPrefix = "EPAH_"; // used to help whitelist pveh variables in BE without BEC and watchdog, leave blank to use no prefix.
antihack_cfgPatchesCfg[] = {0}; // 0 == BAN - 1 = LOG
antihack_ahInitAuthCfg[] = {0,90}; // 0 == BAN - 1 = LOG, 60 = ban or log if anti hack is not started in 90 seconds
antihack_whitelistedCfgPatches[] = {"A3_AIR_F_RTD","AiA_Worlds_Author","AiA_Worlds_Grid","AiA_BaseConfig_F","AiA_A1AlwaysDummy","CAVideo2_PMC","CA_AnimsHotfix","CA_CutSceneAnims","CAIntroAnims","CAUSMCD","CAVoice","CAweapons3_aks74pso","CAWeapons3_ammocrates","CAweapons3_ksvk","CAweapons3_m107","CAweapons3_m16a4_acg_gl","CAweapons3_m16a4_acg","CAweapons3_m16a4_gl","CAweapons3_m16a4","CAWeapons3","CTI_buildingsBmp2_hq","CTI_buildingsM113_hq","DSHkM_Mini","M2HD_Mini","MK19_Tripod","Warfare","WarfareBuildings_Stinger_Twice_static","WarfareBuildings_T72_RACS","WarfareBuildings_TOW_Tripod","AiA_cba_xeh_a2_Dummy","AiA_CBA_A2_xeh_Dummy","AiA_cba_xeh_oa_Dummy","AiA_CBA_OA_xeh_Dummy","AiA_CA_Data","AiA_A10_Data","AiA_Afghan_Data","AiA_Air2_Data","AiA_Air3_Data","AiA_Air_Data","AiA_Air_e_Data","AiA_Animations_Data","AiA_Animations_Config","AiA_Bohemia_Data","AiA_Bootcamp_acr_Data","AiA_Buildings2_Data","AiA_Buildings2_Ind_Cementworks_Data","AiA_Buildings_Data","AiA_Ca_acr_Data","AiA_CA_Config","CAData","AiA_CA_Config_Data_ParticleEffects","CAData_ParticleEffects","AiA_Ca_e_Data","AiA_Ca_pmc_Data","AiA_Characters2_Data","AiA_Chernarus_Data","AiA_Chernarus_Data_Data","AiA_Chernarus_Data_Layers_Data","AiA_Chernarus_Summer_Data","AiA_Cti_buildings_Data","AiA_CA_Data_Data_ParticleEffects","AiA_Data_baf_Data","AiA_Desert2_Data","Desert2_Objects","AiA_Desert_Data","AiA_Desert_e_Data","AiA_Hotfix_Data","AiA_Introanims_Data","CALanguage","AiA_Language_acr_Data","AiA_Language_baf_Data","AiA_Language_e_Data","AiA_Language_pmc_Data","CALanguage_missions","AiA_Languagemissions_acr_Data","AiA_Languagemissions_baf_Data","CALanguage_missions_e","AiA_Languagemissions_pmc_Data","AiA_Misc2_Data","AiA_Misc3_Data","AiA_Misc_Data","AiA_Misc_acr_Data","AiA_Misc_e_Data","AiA_Plants2_Bush_Data","AiA_Plants2_Clutter_Data","AiA_Plants2_Misc_Data","AiA_Plants2_Plant_Data","AiA_Plants2_Tree_Data","AiA_Plants_Data","AiA_Plants_Config","CAPlants","AiA_Plants_e2_Data","AiA_Plants_e_Data","AiA_Plants_pmc_Data","AiA_Provinggrounds_pmc_Data","AiA_Roads2_Data","AiA_Roads2_Config","CARoads2","CARoads2Bridge","CARoads2Dam","AiA_Roads_Data","AiA_Roads_Config","CARoads","AiA_Roads_e_Data","AiA_Roads_pmc_Data","AiA_Roads_pmc_Config","CARoads_PMC_Bridge","AiA_Rocks2_Data","AiA_Rocks2_Config","CARocks2","AiA_Rocks_Data","AiA_Rocks_Config","CARocks","AiA_Rocks_e_Data","AiA_Sara_Data","AiA_Saralite_Data","AiA_Shapur_baf_Data","AiA_Signs2_Data","AiA_Signs2_Config","CASigns2","AiA_Signs_Data","AiA_Signs_Config","CASigns","AiA_Signs_e_Data","AiA_Sounds_Data","AiA_Sounds_Config","CASounds","AiA_Sounds_e_Data","AiA_Structures_Data","pond_test","AiA_Structures_e_Data","AiA_Structures_pmc_Data","AiA_Takistan_Data","AiA_Takistan_Data_Data","AiA_Takistan_Data_Layers_Data","AiA_Tracked2_Data","AiA_Tracked_Data","AiA_Tracked_e_Data","AiA_Ui_Data","AiA_Utes_Data","AiA_Utes_Config","Utes","AiA_Water2_Data","CAWater2_LHD","AiA_Water_Data","AiA_Weapons2_Data","AiA_Weapons_Data","AiA_Weapons_e_Data","AiA_Weapons_pmc_Data","AiA_Wheeled2_Data","AiA_Wheeled_Data","AiA_Wheeled_e_Data","AiA_Zargabad_Data","AiA_Models_DBE1_Data","Music_DBE1","ploty_DBE1","Roads_DBE1","AiA_Sara_dbe1_Data","Disable_XEH_Logging","AiA_TKOH_Dummy","HSim_Data_H","HSim_Data_H_data_ParticleEffects","HSim_Data_H_data_ParticleEffects_rotor_blades","HSim_Dubbing_H","HSim_DubbingRadio_H","HSim_Editor_H","Intro_Island_H","HSim_Missions_H","HSim_ModulesCore_H","HSim_ModulesCore_H_AmbientCombat","HSim_ModulesCore_H_DynO","HSim_ModulesCore_H_Functions","HSim_ModulesCore_H_GarbageCollector","HSim_ModulesCore_H_Functions_E","HSim_ModulesCore_H_OO","HSim_ModulesCore_H_Functions_PMC","HSim_Music_H","HSim_Sounds_H","South_Asia_H","HSim_UIFonts_H","United_States_H","HSim_Animals_H","HSim_Animals_H_Anim_Config","HSim_Animals_H_Dog","HSim_Characters_H_Faces","HSim_Characters_H_Heads","HSim_Modules_H","HSim_UI_H","HSim_Weapons_H","HSim_Weapons_H_AK47","HSim_Weapons_H_DShKM","HSim_Weapons_H_Glock","HSim_Weapons_H_HandItems","HSim_Weapons_H_M16","HSim_Weapons_US_H","HSim_Characters_H","HSim_Characters_US_H","HSim_Missions_H_FreeFlight","HSim_Functions_Base_H","HSim_Water_H","HSim_Water_H_Civ_FishingBoat_Large","HSim_Water_H_Civ_Jetboat","HSim_Water_H_Civ_Yacht","HSim_Water_H_Container_Ship","HSim_Water_H_Cruise_Ship","HSim_Water_H_Destroyer","HSim_Water_H_Fishing_Boat","HSim_Water_H_Fregata","HSim_Water_H_LHD","HSim_Water_H_Oil_tanker","HSim_Water_H_Rubber_Boat","HSim_Water_H_Whales","HSim_Water_H_Whales_GreyWhale","HSim_Water_H_Whales_Whale1","HSim_Weapons_H_IGLA","HSim_Weapons_US_H_M2","HSim_Wheeled_H","HSim_Wheeled_H_Ambulance","HSim_Wheeled_H_FireTruck","HSim_Wheeled_H_Hatchback","HSim_Wheeled_H_Military_Offroad_LR","HSim_Wheeled_H_Military_Pickup_DSHKM","HSim_Wheeled_H_Offroad","HSim_Wheeled_H_Police_Car","HSim_Wheeled_H_TowingTractor","HSim_Wheeled_H_Tractor","HSim_Wheeled_H_Trailers","HSim_Wheeled_H_Truck_Light_Transport","HSim_Wheeled_H_Ural","HSim_Wheeled_H_Van_Passenger","HSim_Wheeled_US_H","HSim_Wheeled_US_H_Military_Offroad","HSim_Wheeled_US_H_Military_Truck","HSim_Wheeled_US_H_Pickup_01","HSim_Wheeled_US_H_Pickup_02","HSim_Wheeled_US_H_SUV","HSim_Wheeled_US_H_Truck_US_Type","HSim_Air_H","HSim_Air_H_Aircraft_A","HSim_Air_H_Aircraft_C","HSim_Air_H_Aircraft_D","HSim_Air_H_Aircraft_E_H","HSim_Air_H_Airliner_A","HSim_Air_H_Airliner_B","HSim_Air_H_Parachute","HSim_Air_US_H","HSim_Air_US_H_Helicopters_Heavy","HSim_Air_US_H_Helicopters_Light","HSim_Air_US_H_Helicopters_Medium","HSim_Misc_H","HSim_Misc_H_Antena","HSim_Misc_H_Barels","HSim_Misc_H_Bleacher","HSim_Misc_H_BoardsPack","HSim_Misc_H_CncBlock","HSim_Misc_H_Doghouse","HSim_Misc_H_Engine_Crane","HSim_Misc_H_Fence","HSim_Misc_H_Fire_Extinguisher","HSim_Misc_H_Fire_Suppression","HSim_Misc_H_First_Aid","HSim_Misc_H_Flagpole","HSim_Misc_H_Folding_Ladder","HSim_Misc_H_FuelCan","HSim_Misc_H_Heliport_Furniture","HSim_Misc_H_Helicopter_Parts","HSim_Misc_H_Helipads","HSim_Misc_H_Heliport_Objects","HSim_Misc_H_Helpers","HSim_Misc_H_Info_Board","HSim_Misc_H_Infostands","HSim_Misc_H_Inspection_Visuals","HSim_Misc_H_Interior","HSim_Misc_H_Loudspeakers","HSim_Misc_H_Market","HSim_Misc_H_Office_Objects","HSim_Misc_H_Perimeter_Ligh","HSim_Misc_H_Pike","HSim_Misc_H_Platform_Cart","HSim_Misc_H_Portable_Generator","HSim_Misc_H_Props","HSim_Misc_H_SawHorse","HSim_Misc_H_Shooting_Range","HSim_Misc_H_Signs","HSim_Misc_H_Sink","HSim_Misc_H_Targets","HSim_Misc_H_Tent","HSim_Misc_H_Toilet","HSim_Misc_H_Tools","HSim_Misc_H_Tools_Racking","HSim_Misc_H_Trash","HSim_Misc_H_Weather_Station","HSim_Misc_H_Weld_Gastank","HSim_Misc_H_Wheel_Chocks","HSim_Misc_H_Wheeled_Scaffolding","HSim_Misc_H_wheeled_tool_cart","HSim_Misc_H_Wheeled_Whiteboard","HSim_Misc_H_Winch","HSim_Misc_H_Windsock","HSim_Misc_H_Workbench","HSim_Misc_H_Wrecks","HSim_Structures_H","HSim_Structures_H_Airport_Papi","HSim_Structures_H_Harbour","HSim_Structures_H_Heliports_Heliport_Big","HSim_Structures_H_Heliports_Heliport_Small","HSim_Structures_H_Industrial_A_CraneCon","HSim_Structures_H_Industrial_Rooftop_Objects","HSim_Structures_US_H","HSim_Structures_US_H_Bld_US","HSim_Structures_US_H_Landmarks_Space_Needle","HSim_Tracked_H","HSim_Tracked_H_BMP2","HSim_Tracked_US_H","HSim_Tracked_US_H_M1A2","HSim_Tracked_US_H_MLRS","HSim_Data_H_EditorGroups","HSim_Anims_H","HSim_Anims_H_config_sdr","HSim_Anims_H_config_wmn","Hsim_Language_H","Hsim_Language_missions_H","AiA_StandaloneTerrainPack_Dummy","CA_ACR","CA_Animals2_Anim_Config","CA_Anims_Char","CA_Anims_E_Wmn","CA_E","CA_PMC","CAAir","CACharacters","CATracked","CAUI","CAWater","CAWater2","CAWater2_seafox","CAWeapons","CAWeapons_Warfare_weapons","CAWheeled","CAWheeled_E","CAWheeled2","6G30_DBE1","Arma2_Ka52","BI_SRRS","CA_AH64D","CA_AIR_E_MQ9PredatorB","CA_AIR_E_Su25","CA_AIR2_Su25","CA_Animals_E","CA_Animals2","CA_Animals2_Chicken","CA_Animals2_Cow","CA_Animals2_Dogs","CA_Animals2_Dogs_Fin","CA_Animals2_Dogs_Pastor","CA_Animals2_Goat","CA_Animals2_Rabbit","CA_Animals2_Sheep","CA_Animals2_WildBoar","CA_Anims","CA_Anims_E","CA_Anims_E_Sdr","CA_Anims_Sdr","CA_Anims_Wmn","CA_CommunityConfigurationProject_E","CA_CruiseMissile","CA_Dubbing","CA_Dubbing_Baf","CA_Dubbing_Counterattack","CA_Dubbing_E","CA_Dubbing_PMC","CA_DubbingRadio_E","CA_DubbingRadio_PMC","CA_E_ParticleEffects","CA_Editor","CA_HC_Sounds","CA_Heads","CA_HighCommand","CA_L39","CA_Missions","CA_Missions_AlternativeInjurySimulation","CA_Missions_AmbientCombat","CA_Missions_Armory1","CA_Missions_Armory2","CA_Missions_BAF","CA_Missions_BAF_2","CA_Missions_BAF_Templates_SecOps","CA_Missions_BattlefieldClearance","CA_Missions_E","CA_Missions_E_Armory2","CA_Missions_E_SecOps","CA_Missions_E_Templates_SecOps","CA_Missions_FirstAidSystem","CA_Missions_GarbageCollector","CA_Missions_PMC","CA_Missions_SecOps","CA_Missions_Templates_SecOps","CA_Missions2_PMC","CA_Modules","CA_Modules_Alice","CA_Modules_Animals","CA_Modules_ARTY","CA_Modules_clouds","CA_Modules_Coin","CA_Modules_DynO","CA_Modules_E","CA_Modules_E_DynO","CA_Modules_E_Jukebox","CA_Modules_E_OO","CA_Modules_E_UAV","CA_Modules_E_UAV_Heli","CA_Modules_E_Weather","CA_Modules_Functions","CA_Modules_Marta","CA_Modules_PMC","CA_Modules_PMC_SimpleFIrstAid","CA_Modules_Silvie","CA_Modules_StratLayer","CA_Modules_UAV","CA_Modules_ZoRA","CA_MPA","CA_MPA_Challenges","CA_MPA_Core","CA_MPA_MP","CA_MPA_Scenarios","CA_Sounds_Baf","CA_SoundsMissions_E","CA_Support","CAA10","CAAir_BAF","CAAir_BAF_CH_47F","CAAir_E","CAAir_E_A10","CAAir_E_AH64D","CAAir_E_AH6J","CAAir_E_An2","CAAir_E_C130J","CAAir_E_CH_47F","CAAir_E_Halo","CAAir_E_Mi24","CAAir_E_MI8","CAAir_E_UH1H_EP1","CAAir_E_UH60M","CAAir_PMC","CAAir_PMC_KA137","CAAir_PMC_KA60","CAAir2","CAAir2_C130J","CAAir2_ChukarTarget","CAAir2_F35B","CAAir2_MQ9PredatorB","CAAir2_MV22","CAAir2_Pchela1T","CAAir2_UH1Y","CAAir3","CAAir3_Su34","CAAnimals","CACharacters_BAF","CACharacters_BAF_Head","CACharacters_E","CACharacters_E_Head","CACharacters_PMC","CACharacters_PMC_Head","CACharacters_W_BAF","CACharacters2","CAFonts","CAMisc_fix","CAMisc_fix_A2FREE","CAMisc_fix_air","CAMisc_fix_Ch2","CAMisc_fix_Str","CAMisc_fix_Weap","CAMP_Armory_Misc","CAMP_Armory_Misc_Concrete_Wall","CAMP_Armory_Misc_Entrance_Gate","CAMP_Armory_Misc_Info_Board","CAMP_Armory_Misc_Infostands","CAMP_Armory_Misc_Laptop","CAMP_Armory_Misc_Loudspeakers","CAMP_Armory_Misc_Plasticpole","CAMP_Armory_Misc_Red_Light","CAMP_Armory_Misc_Sign_Armex","CAMP_Armory_Misc_Sign_Direction","CAMusic","CAMusic_E","CAMusic_PMC","CASounds_E","CASounds_Missions","CATracked_BAF","CATracked_E","CATracked_E_BMP2","CATracked_E_M1_Abrams","CATracked_E_M113","CATracked_E_M2A2_Bradley","CATracked_E_T34","CATracked_E_T55","CATracked_E_T72","CATracked_E_us_m270mlrs","CATracked_E_ZSU","CATracked_W_BAF","CATracked2","CATracked2_2S6M_Tunguska","CATracked2_AAV","CATracked2_BMP3","CATracked2_T34","CATracked2_T90","CATracked2_us_m270mlrs","CAWater2_Destroyer","CAWater2_fishing_boat","CAWater2_Fregata","CAWater2_smallboat_1","CAWeapons_2b14_82mm_Mortar","CAWeapons_AK","CAWeapons_AmmoBoxes","CAWeapons_BAF","CAWeapons_bizon","CAWeapons_Colt1911","CAWeapons_DMR","CAWeapons_E","CAWeapons_E_AGS","CAWeapons_E_AK","CAWeapons_E_AmmoBoxes","CAWeapons_E_Colt1911","CAWeapons_E_D30","CAWeapons_E_DSHKM","CAWeapons_E_FIM92_static","CAWeapons_E_fnfal","CAWeapons_E_G36","CAWeapons_E_GrenadeLauncher","CAWeapons_E_Igla","CAWeapons_E_Javelin","CAWeapons_E_KORD","CAWeapons_E_ksvk","CAWeapons_E_LeeEnfield","CAweapons_E_m107","CAWeapons_E_M110","CAWeapons_E_M119_Howitzer","CAWeapons_E_M136","CAWeapons_E_M14","CAWeapons_E_M16","CAWeapons_E_M240","CAWeapons_E_M252_81mm_Mortar","CAWeapons_E_M2StaticMG","CAWeapons_E_M47","CAWeapons_E_M9","CAWeapons_E_MAAWS","CAWeapons_E_Makarov","CAWeapons_E_Metis","CAWeapons_E_Mk19_MiniTriPod","CAWeapons_E_PK","CAWeapons_E_Podnos_2b14_82mm","CAWeapons_E_RPG18","CAWeapons_E_RPG7","CAWeapons_E_scar","CAWeapons_E_Searchlight","CAWeapons_E_SPG9","CAWeapons_E_STATIC","CAWeapons_E_Stinger","CAWeapons_E_Strela","CAWeapons_E_TOW","CAWeapons_E_ZU23","CAWeapons_Kord","CAweapons_ksvk","CAWeapons_M1014","CAweapons_m107","CAWeapons_M252_81mm_Mortar","CAWeapons_Metis_AT_13","CAWeapons_PMC","CAWeapons_PMC_AA_12","CAWeapons_PMC_AS50","CAWeapons_PMC_XM8","CAWeapons_Saiga12K","CAWeapons_SPG9","CAWeapons_VSS_vintorez","CAWeapons_ZU23","CAWeapons2","CAWeapons2_HuntingRifle","CAWeapons2_RPG18","CAWeapons2_SMAW","CAWheeled_D_BAF","CAWheeled_E_ATV","CAWheeled_E_BRDM2","CAWheeled_E_BTR40","CAWheeled_E_BTR60","CAWheeled_E_HMMWV","CAWheeled_E_Ikarus","CAWheeled_E_LADA","CAWheeled_E_LandRover","CAWheeled_E_M1030","CAWheeled_E_MTVR","CAWheeled_E_Offroad","CAWheeled_E_Old_bike","CAWheeled_E_Old_moto","CAWheeled_E_Pickup","CAWheeled_E_s1203","CAWheeled_E_SCUD","CAWheeled_E_stryker","CAWheeled_E_SUV","CAWheeled_E_TT650","CAWheeled_E_UAZ","CAWheeled_E_Ural","CAWheeled_E_V3S","CAWheeled_E_Volha","CAWheeled_Offroad","CAWheeled_Pickup","CAWheeled_PMC","CAWheeled_PMC_ArmoredSUV","CAWheeled_W_BAF","CAWheeled2_BTR90","CAWheeled2_GAZ39371","CAWheeled2_HMMWV_Ambulance","CAWheeled2_HMMWV_BASE","CAWheeled2_Ikarus","CAWheeled2_Kamaz","CAWheeled2_LADA","CAWheeled2_LAV25","CAWheeled2_M1114_Armored","CAWheeled2_M998A2_Avenger","CAWheeled2_MMT","CAWheeled2_MTVR","CAWheeled2_TowingTractor","CAWheeled2_V3S","CAWheeled2_VWGolf","CAWheeled3","CAWheeled3_M1030","CAWheeled3_TT650","Datsun_armed_DBE1","DBE1","DBE1_UI","DC3_DBE1","HALO_Test","Hilux_armed_DBE1","Warfare2","Warfare2_E","Warfare2Vehicles","AiA_Buildings_Config","CABuildings","CABuildings_Misc","Desert2_Buildings","CA_desert2_Characters","DBE1_Hotfix","AiA_Language_acr_Config","CALanguage_ACR","AiA_Language_e_Config","CALanguage_e","AiA_Language_pmc_Config","CALanguage_PMC","AiA_Languagemissions_acr_Config","CALanguage_missions_ACR","AiA_Languagemissions_pmc_Config","CALanguage_missions_PMC","AiA_Misc_Config","CAMisc","CAWater2_seafox_EP1","AiA_Roads_e_Config","CARoads_E","AiA_Rocks_e_Config","CARocks_E","AiA_Sara_Config","Sara","AiA_Saralite_Config","SaraLite","AiA_Structures_Config","CAStructures","CAStructures_A_BuildingWIP","CAStructures_A_CraneCon","CAStructuresLand_A_MunicipalOffice","CAStructuresBarn_W","CAStructures_Castle","CAStructuresHouse","CAStructuresHouse_A_FuelStation","CAStructuresHouse_A_Hospital","CAStructuresHouse_A_Office01","CAStructuresHouse_A_Office02","CAStructuresHouse_a_stationhouse","CAStructuresHouse_Church_02","CAStructuresHouse_Church_03","CAStructuresHouse_Church_05R","CAStructuresHouse_HouseBT","CAStructuresHouse_HouseV2","CAStructuresHouse_HouseV","CAStructuresLand_Ind_Stack_Big","CAStructures_IndPipe1","CAStructuresInd_Quarry","Ind_SawMill","CAStructures_Mil","CAStructures_Misc","CAStructures_Misc_Armory","CAStructures_Misc_Armory_Armor_Popuptarget","CAStructures_Misc_Powerlines","CAStructures_Nav","CAStructuresLand_Nav_Boathouse","CAStructures_Proxy_BuildingParts","CAStructures_Proxy_Ruins","CAStructures_Rail","CAStructuresHouse_rail_station_big","CAStructures_Ruins","CAStructuresShed_Small","CAStructuresHouse_Shed_Ind","CAStructures_Wall","AiA_Models_DBE1_Config","Models_DBE1","Anims_DBE1","HMMWV_DBE1","Kamenolom_DBE1","Mercenary_DBE1","Misc_DBE1","NPCs_DBE1","Pila_DBE1","Prisoners_DBE1","UH60Desert","UI_DBE1","Vysilac_DBE1","Zakladna_DBE1","AiA_Sara_dbe1_Config","Sara_dbe1","AiA_Buildings2_Config","CABuildings2","A_Crane_02","A_GeneralStore_01","CABuildings2_A_Pub","A_statue","Barn_Metal","CABuildingParts","CABuildingParts_Signs","CATEC","Church_01","Farm_Cowshed","Farm_WTower","CAHouseBlock_A","CAHouseBlock_B","CAHouseBlock_C","CAHouseBlock_D","HouseRuins","Ind_Dopravnik","Ind_Expedice","Ind_MalyKomin","Ind_Mlyn","Ind_Pec","ind_silomale","Ind_SiloVelke","Ind_Vysypka","Ind_Garage01","CAStructures_IndPipe1_todo_delete","IndPipe2","Ind_Shed_01","Ind_Shed_02","Ind_Tank","Ind_Workshop01","CABuildings2_Misc_Cargo","Misc_PowerStation","Misc_WaterStation","Rail_House_01","Shed_small","Shed_wooden","particle_effects","AiA_Chernarus_Config","Chernarus","AiA_Chernarus_Summer_Config","Chernarus_Summer","AiA_Desert2_Config","Porto","AiA_Desert_Config","Desert","AiA_Hotfix_Config","CA_Hotfix","CA_QGClutterHotfix","CA_Hotfix_vez_ropa","AiA_Misc2_Config","CAMisc2","AiA_Misc3_Config","CAMisc3","WarfareBuildings","AiA_Misc_e_Config","CAMisc_E","CAMisc_E_WF","AiA_Signs_e_Config","CASigns_E","A_TVTower","CAStructures_Nav_pier","CAStructures_Railway","AiA_Structures_e_Config","CAStructures_E","CAStructures_E_HouseA","CAStructures_E_HouseA_A_BuildingWIP","CAStructures_E_HouseA_A_CityGate1","CAStructures_E_HouseA_A_Minaret","CAStructures_E_HouseA_A_Minaret_Porto","CAStructures_E_HouseA_A_Mosque_big","CAStructures_E_HouseA_A_Mosque_small","CAStructures_E_HouseA_A_Office01","CAStructures_E_HouseA_a_stationhouse","CAStructures_E_HouseA_A_Statue","CAStructures_E_HouseA_A_Villa","CAStructures_E_HouseC","CAStructures_E_HouseK","CAStructures_E_HouseL","CAStructures_E_Ind","CAStructures_E_Ind_Ind_Coltan_Mine","CAStructures_E_Ind_Ind_FuelStation","CAStructures_E_Ind_Ind_Garage01","CAStructures_E_Ind_Oil_Mine","CAStructures_E_Ind_IndPipes","CAStructures_E_Ind_Misc_PowerStation","CAStructures_E_Ind_Ind_Shed","CAStructures_E_Mil","CAStructures_E_Misc","CAStructures_E_Misc_Misc_cables","CAStructures_E_Misc_Misc_Construction","CAStructures_E_Misc_Misc_Garbage","CAStructures_E_Misc_Misc_Interier","CAStructures_E_Misc_Misc_Lamp","CAStructures_E_Misc_Misc_Market","CAStructures_E_Misc_Misc_powerline","CAStructures_E_Misc_Misc_Water","CAStructures_E_Misc_Misc_Well","CAStructures_E_Wall","CAStructures_E_Wall_Wall_L","AiA_Structures_pmc_Config","CAStructures_PMC","CAStructures_PMC_Buildings","CAStructures_PMC_Buildings_Bunker","CAStructures_PMC_Buildings_GeneralStore_PMC","CAStructures_PMC_Buildings_Ruin_Cowshed","CAStructures_PMC_Ind","CAStructures_PMC_FuelStation","CAStructures_PMC_Misc","CAStructures_PMC_Misc_Shed","CAStructures_PMC_Ruins","CAStructures_PMC_Walls","AiA_Takistan_Config","Takistan","AiA_Zargabad_Config","zargabad","AiA_Afghan_Config","Mountains_ACR","AiA_Bohemia_Config","Woodland_ACR","AiA_Bootcamp_acr_Config","Bootcamp_ACR","AiA_Data_baf_Config","CA_BAF","AiA_Desert_e_Config","Desert_E","AiA_Language_baf_Config","CALanguage_Baf","AiA_Languagemissions_baf_Config","CALanguageMissions_baf","AiA_Misc_acr_Config","CAMisc_ACR","CAMisc_ACR_3DMarkers","CAMisc_ACR_Container","CAMisc_ACR_Dog","CAMisc_ACR_Helpers","CAMisc_ACR_PBX","CAMisc_ACR_ScaffoldingSmall","CAMisc_ACR_Shooting_range","CAMisc_ACR_Sign_Mines","CAMisc_ACR_Targets","CAMisc_ACR_Targets_InvisibleTarget","CAMisc_ACR_TestSphere","AiA_Provinggrounds_pmc_Config","ProvingGrounds_PMC","AiA_Shapur_baf_Config","Shapur_BAF","AiA_Core","AiA_Worlds","AiA_Worlds_Ambient","AiA_Worlds_Clutter","AiA_Worlds_ClutterDist","AiA_Worlds_Delete","AiA_Worlds_DisableInfiniteTerrain","AiA_Worlds_DustEffects","AiA_Worlds_EnvSounds","AiA_Worlds_FullDetailDist","AiA_Worlds_Intros","AiA_Worlds_Lighting","AiA_Worlds_Lighting_Chernarus","AiA_Worlds_Lighting_Desert","AiA_Worlds_MapSize","AiA_Worlds_MidDetailTexture","AiA_Worlds_NoDetailDist","AiA_Worlds_PictureMap","AiA_Worlds_PictureShot","AiA_Worlds_Seabed","AiA_Worlds_SkyTexture","AiA_Worlds_StreetLamp","AiA_Worlds_Surfaces","AiA_Worlds_Water","AiA_StandaloneTerrainPack_Core","AiA_StandaloneTerrainPack_Core_Faction","AiA_StandaloneTerrainPack_Core_VehicleClass"}; //whitelisted cfgPatches for AiA TP
antihack_InvOpenCheck[] = {}; // blank array disables, enable with {6} distance in meters disallows gear access if another player is within this range also disables gear access in vehicles.
antihack_banReason = "EpochMod.com Autoban";
antihack_checkFiles[] = { //script check, leave it blank to disable it
	{"\x\addons\a3_epoch_code\compile\setup\EPOCH_clientInit.sqf", "EPOCH_clientInit"},
	{"\x\addons\a3_epoch_code\compile\EPOCH_onEachFrame.sqf", "EPOCH_onEachFrame"},
	{"\x\addons\a3_epoch_code\compile\setup\EPOCH_masterLoop.sqf", "EPOCH_masterLoop"},
	{"\x\addons\a3_epoch_code\compile\setup\EPOCH_client_rejectPlayer.sqf", "EPOCH_client_rejectPlayer"},
	{"\x\addons\a3_epoch_code\compile\setup\EPOCH_clientRespawn.sqf", "EPOCH_clientRespawn"},
	{"\x\addons\a3_epoch_code\compile\interface_event_handlers\EPOCH_KeyDown.sqf", "EPOCH_KeyDown"}
};
antihack_addActionCheck = true; // false to diable addAction checks
antihack_customVariablesCheck = false; // true enables variable scanning on missionNamespace
antihack_customVariables[] = {}; //Add global variables from custom scripts, example: {"MyOwnVar","CP_KK"} //Global Variables begin without "_" !!
antihack_customVariablesCheckMode = 0; // 0 = Ban, 1 = Log, 2 == learning mode (only enable with trusted players in a passwored server to profile your variables keep disabled for normal operation)

adminMenu_Owner[] = {}; 
adminMenu_OwnerSetting[] = {
	"ESP-PLAYER",
	"ESP-VEHICLE",
	"ESP-LOOT",
	//"OLD-ESP",
	//"OLD-MAP",
	"PLAYER-TELEPORT",
	"MAP-TELEPORT",
	"INFRONT-TELEPORT",
	"MAP-PLAYER",
	"MAP-CORPSE",
	// "MAP-LOOT",
	"MAP-VEHICLE",
	"MAP-AI",
	// "MAP-BASEBUILDING", 
	"TARGET-HEAL",
	"TARGET-AMMO",
	"TARGET-KILL",
	"TARGET-CRYPTO",
	"TARGET-VEHICLEREPAIR",
	"VEHICLEFLIP",
	"BANPANNEL",
	"SPAWN-MENU",
	"FREE-CAM",
	"INVISIBLE",
	// "SPAWNLOOT",
	"GODMODE",
	"HEAL",
	"VEHICLEREPAIR"
};

adminMenu_High[] = {};
adminMenu_HighSetting[] = {"PLAYER-TELEPORT","MAP-TELEPORT","TARGET-HEAL","TARGET-AMMO","TARGET-KILL","VEHICLEFLIP","BANPANNEL"};

adminMenu_Low[] = {};
adminMenu_LowSetting[] = {"PLAYER-TELEPORT","MAP-TELEPORT","TARGET-HEAL"};

adminMenu_BanReasons[] = {"Traderzone","Hacking","Glitch","Combat Log"};
adminMenu_cryptoCfg[] = {2500,1000,500,100,50,-1000};
//You can find the Key Codes here: https://community.bistudio.com/wiki/DIK_KeyCodes#F1..15
adminMenu_menuKey = 0x3B;
adminMenu_infrontTeleport = 0x06;

/*
AH CONFIG README

adminMenu_Owner[] = {
	{"STEAMID64","ADMINNAME1"},
	{"STEAMID64","ADMINNAME2"},
	{"STEAMID64","ADMINNAME3"} //<- No comma on the last entry
}; 
adminMenu_High[] = {
	{"STEAMID64","ADMINNAME4"},
	{"STEAMID64","ADMINNAME5"},
	{"STEAMID64","ADMINNAME6"} //<- No comma on the last entry
};
adminMenu_Low[] = {
	{"STEAMID64","ADMINNAME7"},
	{"STEAMID64","ADMINNAME8"},
	{"STEAMID64","ADMINNAME9"} //<- No comma on the last entry
};

ADMINNAME will be used for the Admin log instead of in-game name.

Available Settings:
"PLAYER-TELEPORT" => Teleport Admin To Player and Player To Admin
"MAP-TELEPORT" => Click on Map to Teleport
"INFRONT-TELEPORT" => Teleport you infront
"FREE-CAM" => Free flying Cam
"INVISIBLE" => Make Playermodel invisible but other player can still hear your steps

"GODMODE" => Godmode for yourself which heal you as well
"HEAL" => Heal yourself
"VEHICLEREPAIR" => Repeair the vehicle you're looking on, or be inside

"MAP-PLAYER" => Player Marker
"MAP-CORPSE" => Corpse (Dead Player etc.) Marker
"MAP-LOOT" => Loot Marker
"MAP-VEHICLE" => Vehicle Marker
"MAP-AI" => AI Marker
"MAP-BASEBUILDING" => Base Building Marker

"ESP-PLAYER" => 3D ESP for Player
"ESP-VEHICLE" => 3D ESP for Vehicles
"ESP-LOOT" => 3D ESP for Loot Objects


"OLD-ESP" => Old 3D ESP
"OLD-MAP" => Old Map Marker

"TARGET-CRYPTO" => Give crypto to target
"TARGET-HEAL" => Heal Target
"TARGET-AMMO" => Give Target Ammo
"TARGET-KILL" => Kill Target
"TARGET-VEHICLEREPAIR" => Repair the Vehicle if target is inside of a vehicle

"VEHICLEFLIP" => Flip Vehicle
"BANPANNEL" => Access to Banpannel
"SPAWNLOOT" => Spawn Loot in Buildings (within 25m)

"SPAWN-MENU" => Access to Spawn Menu

*/