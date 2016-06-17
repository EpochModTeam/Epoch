/*
 Made for A3 Epoch Mod 
 EpochMod.com
 by Aaron Clark - [VB]AWOL

 This work is licensed under a Creative Commons Attribution-ShareAlike 4.0 International License.
 http://creativecommons.org/licenses/by-sa/4.0/
 
 pageup/down toggle modes
space selects target
delete remove target from data set
ctrl+c fills clipboard with config data
 
 EP_IMPORT = [["watertank_01_f_p3d","watertank_02_f_p3d","barrelwater_f_p3d","water_source_f_p3d","waterbarrel_f_p3d","canisterplastic_f_p3d","watertank_f_p3d","misc_well_p3d","misc_wellpump_p3d","kasna_new_p3d","rasman_pond_p3d","pumpa_p3d","misc_well_c_ep1_p3d","misc_well_l_ep1_p3d","stand_water_ep1_p3d","misc_concbox_ep1_p3d","Land_water_tank","Land_Pumpa","watertank_04_f_p3d","watertank_03_f_p3d"],["atm_01_f_p3d","phonebooth_01_f_p3d","atm_02_f_p3d","phonebooth_02_f_p3d","nastenka_p3d","nastenka2_p3d","nastenka3_p3d","phone_box_south_p3d","mailboxsouth_p3d","Land_PhoneBooth_02_F","Land_PhoneBooth_01_F","Land_Atm_01_F","Land_Atm_02_F","Land_Laptop_device_F"],["cliff_stone_big_lc_f_p3d","sharpstone_03_lc_p3d","sharpstone_02_lc_p3d","sharpstone_01_lc_p3d","sharpstone_02_p3d","sharpstone_03_p3d","sharprock_monolith_p3d","sharprock_apart_p3d","sharpstones_erosion_p3d","bluntstone_01_lc_p3d","bluntstone_02_lc_p3d","bluntstone_03_lc_p3d","bluntstones_erosion_p3d","bluntstone_01_p3d","bluntstone_03_p3d","sharprock_spike_p3d","sharprock_wallh_p3d","w_sharpstone_03_p3d","w_sharpstone_02_p3d","w_sharpstone_01_p3d","bluntrock_apart_p3d","bluntstone_02_p3d","bluntrock_monolith_p3d","bluntrock_wallh_p3d","sharprock_wallv_p3d","stonesharp_medium_p3d","stone_medium_f_p3d","stonesharp_big_p3d","stonesharp_small_p3d","small_stone_02_f_p3d","stone_small_f_p3d","stone_big_f_p3d","bluntrock_spike_p3d","r2_boulder1_p3d","r2_boulder2_p3d","r2_rock1_p3d","r2_rocktower_p3d","r2_rockwall_p3d","r_rock_02_ep1_p3d","brownrock2_p3d","brownrock3_p3d","desertrock_p3d","desertrock2_p3d","desertrock3_p3d","r_stone_01_ep1_p3d","brownrock_p3d","rockn_02_p3d","sharpstone_01_p3d","r_rock_03_ep1_p3d","rocks_02_p3d","skala3_5_p3d","skala3_4_p3d","skala1_4_p3d","bo_r2_boulder1_p3d","bo_r2_boulder2_p3d","bo_r2_rock1_p3d","bo_r2_rocktower_p3d","bo_r2_rockwall_p3d","w_sharpstones_erosion_p3d","decal_rock_dark_p3d","r_stone_01_pmc_p3d","r_stone_02_pmc_p3d","stone4_p3d","stone3_p3d","stone4_invert_p3d","rocks_01_p3d","stone4a_p3d","stone3a_p3d","rockn_01_p3d","r_tk_stone_01_ep1_p3d","r_tk_stone_02_ep1_p3d","r_tk_rock_03_ep1_p3d","r_tk_boulder_03_ep1_p3d","r_tk_rock_02_ep1_p3d","r_tk_boulder_01_ep1_p3d","r_tk_boulder_02_ep1_p3d","r_tk_rock_01_ep1_p3d","cliff_wall_long_f_p3d","cliff_stone_medium_lc_f_p3d","cliff_stone_small_lc_f_p3d","cliff_boulder_f_p3d","cliff_peak_f_p3d","cliff_wall_round_f_p3d","cliff_stonecluster_f_p3d","cliff_wall_tall_f_p3d","lavaboulder_03_f_p3d","lavastone_small_lc_f_p3d","lavaboulder_02_f_p3d","lavaboulder_01_f_p3d","lavastone_big_lc_f_p3d","lavastonecluster_large_f_p3d","lavaboulder_04_f_p3d","lavastonecluster_small_f_p3d","cliff_stone_medium_f_p3d"],["p_fiberplant_ep1_p3d"],["p_pumpkin_summer_p3d","pumpkin_p3d"],["woodencrate_01_stack_x3_f_p3d","garbageheap_03_f_p3d","garbageheap_04_f_p3d","garbageheap_02_f_p3d","garbagecontainer_closed_f_p3d","sack_f_p3d","garbagebags_f_p3d","pallets_f_p3d","junkpile_f_p3d","garbagepallet_f_p3d","garbagewashingmachine_f_p3d","basket_f_p3d","sacks_goods_f_p3d","crateswooden_f_p3d","cratesplastic_f_p3d","garbagebin_01_f_p3d","barrelsand_f_p3d","cratesshabby_f_p3d","bucket_f_p3d","garbagebarrel_01_f_p3d","tyres_f_p3d","cargobox_v1_f_p3d","metalbarrel_f_p3d","sacks_heap_f_p3d","woodenbox_f_p3d","grave_v1_f_p3d","grave_v2_f_p3d","calvary_02_v2_f_p3d","fishinggear_02_f_p3d","fishinggear_01_f_p3d","humanskull_f_p3d","calvary_02_v1_f_p3d","rack_f_p3d","wreck_uaz_f_p3d","humanskeleton_f_p3d","shelvesmetal_f_p3d","popelnice_p3d","garbage_misc_p3d","paletyc_p3d","junkpile_p3d","kontejner_p3d","misc_chickencoop_p3d","misc_boogieman_p3d","misc_hutch_p3d","garbage_paleta_p3d","misc_cargo1a_p3d","misc_cargo2a_p3d","misc_greenhouse_p3d","zastavka_stojan_p3d","podesta_s10_p3d","kontejner_sklo_p3d","paletyd_p3d","popelnice_2_p3d","garbage_plastic_p3d","garbage_metal_p3d","jeept_tanker_p3d","kontejner_plasty_p3d","odpadkovy_kos_p3d","socha_p3d","kontejner_papir_p3d","metalcrate_p3d","hrob2_p3d","barel5_p3d","barel4_p3d","tires_ep1_p3d","barel2_p3d","barels_p3d","barel1_p3d","barels2_p3d","barels3_p3d","bricks_v2_f_p3d","Land_GarbagePallet_F","Land_GarbageBags_F","garb_misc_pmc_p3d","garb_paleta_pmc_p3d","garb_heap_pmc_p3d","drevena_bedna_p3d","barel3_p3d","dum_olez_istan1_p3d","misc_rubble_ep1_p3d","bags_stack_ep1_p3d","crates_ep1_p3d","cages_ep1_p3d","crates_stack_ep1_p3d","transport_cart_ep1_p3d","stand_small_ep1_p3d","stand_meat_ep1_p3d","bags_ep1_p3d","misc_garb_heap_ep1_p3d","garbageheap_01_f_p3d","woodencrate_01_stack_x5_f_p3d","woodencrate_01_f_p3d","clothesline_01_short_f_p3d","boat_01_abandoned_red_f_p3d","grave_01_f_p3d","grave_03_f_p3d"],["garbagebin_02_f_p3d","misc_postbox_p3d"],["t_cocosnucifera3s_tall_f_p3d","t_leucaena_f_p3d","t_ficus_medium_f_p3d","t_cyathea_f_p3d","t_ficus_small_f_p3d","t_ficusb1s_f_p3d","t_oleae1s_f_p3d","t_ficusb2s_f_p3d","t_broussonetiap1s_f_p3d","t_pinuss2s_f_p3d","t_pinuss2s_b_f_p3d","t_pinuss1s_f_p3d","t_oleae2s_f_p3d","t_fraxinusav2s_f_p3d","t_pinusp3s_f_p3d","t_poplar2f_dead_f_p3d","t_populusn3s_f_p3d","t_phoenixc1s_f_p3d","t_populus3s_p3d","t_fagus2w_p3d","t_betula2s_p3d","t_fagus2s_p3d","t_fagus2f_p3d","t_sorbus2s_p3d","t_fraxinus2w_p3d","t_salix2s_p3d","t_malus1s_p3d","t_betula1f_p3d","t_pinusn2s_p3d","t_picea2s_p3d","t_larix3s_p3d","t_picea3f_p3d","t_picea1s_p3d","misc_fallentree2_p3d","misc_stub2_p3d","t_fraxinus2s_p3d","t_quercus2f_p3d","misc_trunk_water_p3d","misc_trunk_torzo_p3d","t_alnus2s_p3d","misc_fallentree1_p3d","t_betula2f_p3d","t_pinusn1s_p3d","t_pinuss2f_p3d","t_quercus3s_p3d","t_carpinus2s_p3d","misc_fallenspruce_p3d","t_stub_picea_p3d","misc_stub1_p3d","t_acer2s_p3d","t_betula2w_p3d","t_pyrus2s_p3d","t_pinuss3s_ep1_p3d","t_pinuse2s_ep1_p3d","t_populusf2s_ep1_p3d","str_topol_p3d","les_singlestrom_b_p3d","banana_3_p3d","jablon_p3d","str_pinie_p3d","t_ficusb2s_ep1_p3d","palm_01_p3d","vysilac_budova_p3d","palm_10_p3d","palm_03_p3d","palm_04_p3d","t_pistacial2s_ep1_p3d","panelak_p3d","str_kastan_p3d","a_hospital_p3d","i_barracks_v1_f_p3d","dum_istan3_hromada_p3d","dum_istan3_hromada2_p3d","dum_istan4_big_inverse_p3d","panelak2_p3d","podesta_1_mid_p3d","podesta_1_cornl_p3d","t_prunuss2s_ep1_p3d","dum_istan2_02_p3d","dum_istan4_inverse_p3d","podesta_1_stairs2_p3d","podesta_1_mid_cornl_p3d","hrusen2_p3d","zed_kamenna_p3d","str_dub_p3d","str_dub_jiny_p3d","smrk_siroky_p3d","smrk_maly_p3d","les_singlestrom_p3d","palm_02_p3d","brg_banana_3_p3d","banana_2_p3d","oliva_p3d","brg_umbrella_acacia02b_p3d","brg_umbrella_acacia01b_p3d","brg_umbrella_acacia04b_p3d","brg_umbrella_acacia03b_p3d","str_buk_p3d","les_dub_p3d","b_pinusm1s_ep1_p3d","krovi_long_p3d","str_lipa_p3d","str_javor_p3d","str_trnka_p3d","t_poplar2f_dead_pmc_p3d","t_quercusir2s_f_p3d","dd_bush01_p3d","t_fagus2f_summer_p3d","akat02s_p3d","t_amygdalusc2s_ep1_p3d","str_osika_p3d","palm_09_p3d","dd_borovice_p3d","dd_borovice02_p3d","str_topol2_p3d","brg_umbrella_acacia_shrub02_p3d","t_populusb2s_ep1_p3d","les_dub_jiny_p3d","les_buk_p3d","str_fikovnik_p3d","str_briza_rovna_p3d","str_jerabina_p3d","str_habr_p3d","les_fikovnik2_p3d","bo_t_populus3s_p3d","bo_t_fagus2w_p3d","bo_t_betula2s_p3d","bo_t_fagus2s_p3d","bo_t_fagus2f_p3d","bo_t_sorbus2s_p3d","bo_t_fraxinus2w_p3d","bo_t_salix2s_p3d","bo_t_malus1s_p3d","bo_t_betula1f_p3d","bo_t_pinusn2s_p3d","bo_t_picea2s_p3d","bo_t_larix3s_p3d","bo_t_picea3f_p3d","bo_t_picea1s_p3d","bo_misc_fallentree2_p3d","bo_misc_stub2_p3d","bo_t_fraxinus2s_p3d","bo_t_quercus2f_p3d","bo_misc_trunk_water_p3d","bo_misc_trunk_torzo_p3d","bo_t_alnus2s_p3d","bo_misc_fallentree1_p3d","bo_t_betula2f_p3d","bo_t_pinusn1s_p3d","bo_t_pinuss2f_p3d","bo_t_quercus3s_p3d","bo_t_carpinus2s_p3d","bo_t_stub_picea_p3d","bo_t_acer2s_p3d","bo_t_betula2w_p3d","bo_t_pyrus2s_p3d","bo_b_corylus_p3d","t_fagus2s_summer_p3d","t_betula2s_summer_p3d","cwr2_a2_t_sorbus2s_p3d","cwr2_a2_t_fagus2w_p3d","cwr2_a2_t_alnus2s_p3d","mb_t_ulmus_large_p3d","cwr_aleppopine_p3d","cwr2_a2_t_quercus3s_p3d","cwr2_a2_t_fraxinus2s_p3d","misc_torzotree_pmc_p3d","misc_brokenspruce_pmc_p3d","misc_stubleafs_pmc_p3d","str_fikovnik2_p3d","str_fikovnik_ker_p3d","str_briza_kriva_p3d","smrk_velky_p3d","str_briza_p3d","misc_trunk_torzo_ep1_p3d","t_juniperusc2s_ep1_p3d","misc_trunk_water_ep1_p3d","woodenplanks_01_f_p3d","t_cocosnucifera2s_small_f_p3d","t_millettia_f_p3d","t_inocarpus_f_p3d","t_cocosnucifera3s_bend_f_p3d","t_agathis_wide_f_p3d","timberpile_01_f_p3d","d_treestump_cut_small_f_p3d","d_treestump_natural_small_f_p3d","d_treestump_natural_large_f_p3d","t_albizia_f_p3d","t_agathis_tall_f_p3d","t_palaquium_f_p3d","t_ficus_big_f_p3d"],["b_colored_red_f_p3d","b_colored_yellow_f_p3d","b_cestrum_f_p3d","b_calochlaena_f_p3d","b_gardenia_f_p3d","b_gardenia_dec_01_f_p3d","b_gardenia_dec_02_f_p3d","b_leucaena_f_p3d","b_ficusc2d_f_p3d","b_ficusc1s_f_p3d","b_neriumo2d_f_p3d","b_arundod2s_f_p3d","b_arundod3s_f_p3d","b_ficusc2s_f_p3d","b_craet1_p3d","b_craet2_p3d","b_corylus_p3d","b_corylus2s_p3d","b_betulahumilis_p3d","b_sambucus_p3d","b_salix2s_p3d","b_canina2s_p3d","b_pmugo_p3d","b_prunus_p3d","krovi_bigest_p3d","krovi4_p3d","krovi_p3d","ker_s_bobulema_p3d","ker_pichlavej_p3d","pinus_mugo_lowpoly_p3d","b_amygdalusn1s_ep1_p3d","banana_4_p3d","banana_1_p3d","palm_08small_p3d","ker_deravej_p3d","brg_umbrella_acacia_shrub2_p3d","krovi2_p3d","brg_banana_4_p3d","bo_b_craet1_p3d","bo_b_craet2_p3d","bo_b_corylus2s_p3d","bo_b_betulahumilis_p3d","bo_b_sambucus_p3d","salix2s_p3d","bo_b_canina2s_p3d","bo_b_pmugo_p3d","bo_b_prunus_p3d","b_corylus2s_summer_p3d","b_craet1_summer_p3d","b_betula2w_summer_p3d","b_canina2s_summer_p3d","cwr2_a2_b_canina2s_p3d","cwr2_a2_b_craet1_p3d","str_krovisko_vysoke_p3d","cwr2_a2_b_prunus_p3d","b_neriumo2s_f_p3d","b_neriumo2s_white_f_p3d","cwr2_a2_b_sambucus_p3d","b_hip2s_pmc_p3d","b_elderberry2s_pmc_p3d","ker_buxus_p3d","str_liskac_p3d","dd_bush02_p3d","b_pistacial1s_ep1_p3d","t_pritchardia_f_p3d","b_pipermeth_f_p3d","t_banana_f_p3d","t_banana_slim_f_p3d","t_banana_wild_f_p3d"],["cinderblocks_f_p3d","cinderblocks_01_f_p3d"],["parkingmeter_01_f_p3d","wall_tin_4_2_p3d","mil_wiredfence_f_p3d","cages_f_p3d","wreck_car_f_p3d","pipes_small_f_p3d","pipe_fence_4m_f_p3d","spp_tower_f_p3d","wreck_ural_f_p3d","wreck_car3_f_p3d","ironpipes_f_p3d","pipes_large_f_p3d","coil_f_p3d","wreck_offroad_f_p3d","wreck_offroad2_f_p3d","crabcages_f_p3d","metalbarrel_empty_f_p3d","net_fenced_8m_f_p3d","net_fence_8m_f_p3d","wavepowerplantbroken_f_p3d","wreck_truck_dropside_f_p3d","wavepowerplant_f_p3d","wreck_traw_f_p3d","wreck_slammer_f_p3d","maroula_f_p3d","indfnc_9_f_p3d","indfnc_3_f_p3d","indfnc_3_d_f_p3d","wreck_car2_f_p3d","net_fence_4m_f_p3d","wreck_truck_f_p3d","wreck_hunter_f_p3d","wreck_slammer_hull_f_p3d","wall_fen1_5_pole_p3d","wall_fen1_5_2_p3d","wall_fen1_5_p3d","wall_indfnc_3_p3d","wall_indfnc_9_p3d","wall_indfnc_corner_p3d","misc_concrete_high_p3d","plot_vlnplech2_p3d","misc_g_pipes_p3d","wall_tincom_9_p3d","wall_tin_4_p3d","plot_vlnplech1_p3d","wall_tincom_9_2_p3d","wall_tincom_3_p3d","wall_tincom_pole_p3d","datsun01t_p3d","datsun02t_p3d","skodovka_wrecked_p3d","lada_wrecked_p3d","hiluxt_p3d","uaz_wrecked_p3d","ural_wrecked_p3d","rubble_metal_plates_04_p3d","rubble_metal_plates_02_p3d","rubble_metal_plates_01_p3d","wreck_brdm2_f_p3d","wreck_bmp2_f_p3d","wreck_heli_attack_01_f_p3d","bmp_break_p3d","wreck_t72_hull_f_p3d","wreck_t72_turret_f_p3d","wreck_hmmwv_f_p3d","kamaz_bort_p3d","wreck_van_f_p3d","kamaz_awtobas_p3d","maz_p3d","wreck_skodovka_f_p3d","wreck_cardismantled_f_p3d","kamaz_pozarka_p3d","zaporosez_p3d","kamaz_tent_p3d","budova5_p3d","pletivo_dira_p3d","pletivo_p3d","wall_indfnc_pole_p3d","wall_indfnc_3_d_p3d","t72_wrecked_p3d","t72_wrecked_turret_p3d","pipefence_01_m_d_f_p3d","pipefence_01_m_8m_f_p3d","pipefence_01_m_gate_v2_f_p3d","fuelstation_02_prices_f_p3d","tinwall_01_m_4m_v2_f_p3d","pipefence_01_m_pole_f_p3d","wiredfence_01_16m_f_p3d","wiredfence_01_8m_d_f_p3d","wiredfence_01_8m_f_p3d","netfence_01_m_8m_f_p3d","netfence_01_m_d_f_p3d","netfence_01_m_4m_f_p3d","tinwall_02_l_4m_f_p3d","scf_01_warehouse_f_p3d","tinwall_02_l_8m_f_p3d","bulldozer_01_wreck_f_p3d","excavator_01_wreck_f_p3d"]];

{
	_tempVars = missionNamespace getVariable [_x,[]];
	{
		_tempVars pushBackUnique _x;
	} forEach (EP_IMPORT select _forEachIndex);
	missionNamespace setVariable [_x,_tempVars];
} forEach EP_modes;
 
*/



player allowDamage false;
player enableFatigue false;

EPOCH_colorRange = {
private ["_ratio","_b","_r","_g"];
params ["_minimum", "_maximum", "_value", "_alpha"];
_ratio = 2 * (_value-_minimum) / (_maximum - _minimum);
_b = 0 max (255*(1 - _ratio));
_r = 0 max (255*(_ratio - 1));
_g = (255 - _b - _r);
_return = [_r, _g, _b] apply {linearConversion [0, 255, _x, 0, 1, true]};
_return pushBack _alpha;
_return
};

Epoch_selectedIndex = 0;
EP_modes = ["Water","bankTerminal","Rocks","HempFiber","PumpkinPatch","Trash","TrashSmall","Trees","Bushes","Cinder","Wrecks"];
EP_selectedMode = EP_modes select Epoch_selectedIndex;
EP_modeColors = [];
_value = 0;
{
	EP_modeColors pushBack ([0,100,_value,1] call EPOCH_colorRange);
	_value = _value + (100/(count EP_modes));
} forEach EP_modes;

EP_modesCount = (count EP_modes)-1;


EP_replaceChar = {
	params ["_STRING","_needle","_replace"];
	_STRING splitString _needle joinString _replace
};

EPOCH_dbg_saveMapConfig = {
    _br         = toString [13,10];
    _config_str = "";
    _array      = [];
    { 
        _modeClass = _x;
        _printData = missionNamespace getVariable [_modeClass,[]];
		_configWorldInteractions = ((getMissionConfig "CfgEpochClient") >> "CfgWorldInteractions");
		{
			_printData pushBackUnique (configName _x);
		} forEach ("configName(inheritsFrom _x) == _modeClass" configClasses (_configWorldInteractions));
		
		missionNamespace setVariable [_modeClass,_printData];
		
        _countArray = (count _printData) - 1;
        {
			_p3dName = [[_x,".","_"] call EP_replaceChar," ","_"] call EP_replaceChar;
            _config_str = _config_str +  format['    class %1 : %3 {}; %2', _p3dName, _br, _modeClass];   
        } forEach _printData; 
    } forEach EP_modes;
    _config_str
};


EPOCH_KeyDownCustom = {
    _dikCode = _this select 1;
    _shift = _this select 2;
    _ctrl = _this select 3;
    _alt = _this select 4;
    _handled = false;

    switch (_dikCode) do {
        case 0x2E: {
            if (_ctrl) then {
            	hint "Saved to clipboard";
                copyToClipboard call EPOCH_dbg_saveMapConfig;

                EP_modesExport = [];
				{
				  	EP_modesExport pushBack (missionNamespace getVariable [_x,[]]);
				} forEach EP_modes;
            };
        };

        case 0xC9 : { 
            Epoch_selectedIndex = ((Epoch_selectedIndex + 1) min EP_modesCount) max 0;
            EP_selectedMode = EP_modes select Epoch_selectedIndex;
            hint EP_selectedMode;
            _handled = true;
        }; 
        case 0xD1 : { 
            Epoch_selectedIndex = ((Epoch_selectedIndex - 1) min EP_modesCount) max 0;
            EP_selectedMode = EP_modes select Epoch_selectedIndex;
            hint EP_selectedMode;
            _handled = true;
        }; 

        case 0xD3: {
            
            _handled = true;
			EP_objects = [];
			_intersect_objects = lineIntersectsSurfaces [AGLToASL positionCameraToWorld [0,0,0], AGLToASL positionCameraToWorld [0,0,1000], player, objNull, true, 1];
			{EP_objects pushback (_x select 2); if(true) exitWith{};} forEach _intersect_objects;
			
			{
				if (typeOf _x == "") then {
					_objStr = str _x;
					_findStart = _objStr find ": ";
					if (_findStart != -1) then {
						_p3dName = _objStr select [_findStart+2,999];
						_p3dName = [[_p3dName,".","_"] call EP_replaceChar," ","_"] call EP_replaceChar;
						EPOCH_ALL = EPOCH_ALL - [_p3dName];
						{
						    _varDataDel =  missionNamespace getVariable [_x,[]];
						  	if (_p3dName in _varDataDel) exitWith {
								_varDataDel = _varDataDel - [_p3dName];
								missionNamespace setVariable [_x,_varDataDel];
							};
						} forEach EP_modes;
					};
				};
			} forEach EP_objects;
        };
        
        
        case 0x39 : { 
            _handled = true;
              
			EP_objects = [];
			_intersect_objects = lineIntersectsSurfaces [AGLToASL positionCameraToWorld [0,0,0], AGLToASL positionCameraToWorld [0,0,1000], player, objNull, true, 1];
			{EP_objects pushback (_x select 2); if(true) exitWith{};} forEach _intersect_objects;

			_varData = missionNamespace getVariable [EP_selectedMode, []];
			_allData = missionNamespace getVariable ["EPOCH_ALL", []];
			{
				_objStr = str _x;
				_findStart = _objStr find ": ";
				if (_findStart != -1) then {
					_p3dName = _objStr select [_findStart+2,999];
					_p3dName = [[_p3dName,".","_"] call EP_replaceChar," ","_"] call EP_replaceChar;
					if !(_p3dName in _allData) then {
						if !(_p3dName in _varData) then {
							_allData pushBack _p3dName;
							_varData pushBack _p3dName;
							deleteMarker _p3dName;
						};
					};

				};
			} forEach EP_objects;
			missionNamespace setVariable [EP_selectedMode, _varData];
			missionNamespace setVariable ["EPOCH_ALL", _allData];


        };
    };
 
    _handled
};


[] spawn {
    (findDisplay 46) displayRemoveAllEventHandlers "KeyDown";
    (findDisplay 46) displayAddEventHandler["KeyDown",{_this call EPOCH_KeyDownCustom}];
};


onEachFrame {
	_all = nearestObjects [player, [], 20];
	{
		if (typeOf _x == "") then {
			_objStr = str _x;
			_findStart = _objStr find ": ";
			if (_findStart != -1) then {
				_p3dName = _objStr select [_findStart+2,999];
				_p3dName = [[_p3dName,".","_"] call EP_replaceChar," ","_"] call EP_replaceChar;				
				_color = [1,1,1,1];
				{
				  	if (_p3dName in (missionNamespace getVariable [_x,[]])) exitWith {
						_color = EP_modeColors select _foreachindex;
					};
				} forEach EP_modes;
				drawIcon3D ["a3\weapons_f\data\clear_empty.paa", _color, getPos _x, 1, 1, 45, _p3dName, 1, 0.04, "PuristaMedium"];
			};
		};
	} forEach _all;
	_lineColor = EP_modeColors select Epoch_selectedIndex;
	drawLine3D [positionCameraToWorld [0,0,0], positionCameraToWorld [0,0,1000], _lineColor];
};
