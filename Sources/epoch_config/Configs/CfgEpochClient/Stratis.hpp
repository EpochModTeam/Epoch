class Stratis {
	blockedArea[] = {}; 
	Rocks[] = {
		"sharpstone_03_lc.p3d",
		"sharpstone_02_lc.p3d",
		"sharpstone_01_lc.p3d",
		"sharpstone_02.p3d",
		"sharpstone_03.p3d",
		"sharprock_monolith.p3d",
		"sharprock_apart.p3d",
		"sharpstones_erosion.p3d",
		"bluntstone_01_lc.p3d",
		"bluntstone_02_lc.p3d",
		"bluntstone_03_lc.p3d",
		"bluntstones_erosion.p3d",
		"bluntstone_01.p3d",
		"bluntstone_03.p3d",
		"sharprock_spike.p3d",
		"sharprock_wallh.p3d",
		"w_sharpstone_03.p3d",
		"w_sharpstone_02.p3d",
		"w_sharpstone_01.p3d",
		"bluntrock_apart.p3d",
		"bluntstone_02.p3d",
		"bluntrock_monolith.p3d",
		"bluntrock_wallh.p3d",
		"sharprock_wallv.p3d",
		"stonesharp_medium.p3d",
		"stone_medium_f.p3d",
		"stonesharp_big.p3d",
		"stonesharp_small.p3d",
		"small_stone_02_f.p3d",
		"stone_small_f.p3d",
		"stone_big_f.p3d",
		"bluntrock_spike.p3d"
	};
	ATM[] = {
		"atm_01_f.p3d",
		"phonebooth_01_f.p3d",
		"atm_02_f.p3d",
		"phonebooth_02_f.p3d"
	};
	Water[] = {
		"barrelwater_f.p3d",
		"water_source_f.p3d",
		"waterbarrel_f.p3d",
		"canisterplastic_f.p3d",
		"watertank_f.p3d"
	};
	// main config 
	TrashClasses[] = { "Trash", "TrashSmall", "TrashVehicle", "PumpkinPatch", "TrashFood" };

	TrashSmall[] = {
	};
	TrashVehicle[] = {
	};
	PumpkinPatch[] = {
		"p_pumpkin_summer.p3d",
		"pumpkin.p3d",
	};
	TrashFood[] = {
		"basket_f.p3d",
		"sacks_goods_f.p3d"

	};
	Trash[] = {
		"sack_f.p3d",
		"garbagebags_f.p3d",
		"pallets_f.p3d",
		"junkpile_f.p3d",
		"garbagepallet_f.p3d",
		"garbagewashingmachine_f.p3d",
		"crateswooden_f.p3d",
		"cratesplastic_f.p3d",
		"garbagebin_01_f.p3d",
		"barrelsand_f.p3d",
		"garbagecontainer_closed_f.p3d",
		"cratesshabby_f.p3d",
		"bucket_f.p3d",
		"garbagebarrel_01_f.p3d",
		"tyres_f.p3d",
		"cargobox_v1_f.p3d",
		"metalbarrel_f.p3d",
		"sacks_heap_f.p3d",
		"woodenbox_f.p3d",
		"grave_v1_f.p3d",
		"grave_v2_f.p3d",
		"calvary_02_v2_f.p3d",
		"fishinggear_02_f.p3d",
		"fishinggear_01_f.p3d",
		"humanskull_f.p3d",
		"calvary_02_v1_f.p3d",
		"rack_f.p3d",
		"wreck_uaz_f.p3d",
		"humanskeleton_f.p3d",
		"shelvesmetal_f.p3d"
	};
	Trees[] = {
		"t_ficusb1s_f.p3d",
		"t_oleae1s_f.p3d",
		"t_ficusb2s_f.p3d",
		"t_broussonetiap1s_f.p3d",
		"t_pinuss2s_f.p3d",
		"t_pinuss2s_b_f.p3d",
		"t_pinuss1s_f.p3d",
		"t_oleae2s_f.p3d",
		"i_house_big_01_v2_f.p3d",
		"i_house_big_02_v1_f.p3d",
		"i_addon_02_v1_f.p3d",
		"t_fraxinusav2s_f.p3d",
		"t_pinusp3s_f.p3d",
		"t_poplar2f_dead_f.p3d",
		"t_populusn3s_f.p3d",
		"t_phoenixc1s_f.p3d"
	};
	Bushes[] = {
		"b_ficusc2d_f.p3d",
		"b_ficusc1s_f.p3d",
		"b_neriumo2d_f.p3d",
		"b_arundod2s_f.p3d",
		"b_arundod3s_f.p3d",
		"b_ficusc2s_f.p3d"
	};
	Cinder[] = {
		"cinderblocks_f.p3d"
	};
	Wrecks[] = {
		"wall_tin_4_2.p3d",
		"mil_wiredfence_f.p3d",
		"cages_f.p3d",
		"wreck_car_f.p3d",
		"pipes_small_f.p3d",
		"pipe_fence_4m_f.p3d",
		"spp_tower_f.p3d",
		"wreck_ural_f.p3d",
		"wreck_car3_f.p3d",
		"ironpipes_f.p3d",
		"pipes_large_f.p3d",
		"coil_f.p3d",
		"wreck_offroad_f.p3d",
		"wreck_offroad2_f.p3d",
		"crabcages_f.p3d",
		"metalbarrel_empty_f.p3d",
		"net_fenced_8m_f.p3d",
		"net_fence_8m_f.p3d",
		"wavepowerplantbroken_f.p3d",
		"wreck_truck_dropside_f.p3d",
		"wavepowerplant_f.p3d",
		"wreck_traw_f.p3d",
		"wreck_slammer_f.p3d",
		"maroula_f.p3d",
		"indfnc_9_f.p3d",
		"indfnc_3_f.p3d",
		"indfnc_3_d_f.p3d",
		"wreck_car2_f.p3d",
		"net_fence_4m_f.p3d",
		"wreck_truck_f.p3d",
		"wreck_hunter_f.p3d",
		"wreck_slammer_hull_f.p3d"
	};
};
