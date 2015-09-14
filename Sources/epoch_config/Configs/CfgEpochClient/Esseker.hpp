class Esseker {
	blockedArea[] = {
			{ { 208.778, 353.779, 0 }, 300 }, //Cave
			{ { 1997.77, 4177.22, 0 }, 200 }, //Krupa
			{ { 2710.82, 4577.82, 0 }, 300 }, //Kupress
			{ { 6698.04, 3901.16, 0 }, 220 }, //Plava Vrana Military
			{ { 9441.22, 4768.86, 0 }, 500 }, //Adela AF West
			{ { 10336, 4809.92, 0 }, 280 }, //Adela AF East
			{ { 6453.85, 5454.12, 0 }, 200 }, //Neptune resort
			{ { 5237.39, 4756.58, 0 }, 200 }, //Power station
			{ { 5034.75, 5126.94, 0 }, 300 }, //Kula
			{ { 6317.04, 6194.92, 0 }, 200 }, //Gulash
			{ { 3023.79, 6078.66, 0 }, 400 }, //Danilov Grad
			{ { 8665.26, 5643.09, 0 }, 600 }, //Old Esseker (West)
			{ { 9676.37, 5592.46, 0 }, 600 }, //Esseker (Central)
			{ { 10547.4, 5465.63, 0 }, 600 }, //Lower Esseker (East)
			{ { 11896.2, 7941.4, 0 }, 200 }, //Novi Grad
			{ { 10136.3, 7917, 0 }, 60 }, //Chardak Resort
			{ { 9054.67, 7902.84, 0 }, 150 }, //Pilana Sawmill
			{ { 7780.88, 6914.07, 0 }, 200 }, //Posestra
			{ { 6199.98, 6919.69, 0 }, 150 }, //Lug
			{ { 3503.95, 6888.93, 0 }, 170 }, //Melina
			{ { 1953.28, 7815.1, 0 }, 210 }, //Rama
			{ { 4791.52, 8074.88, 0 }, 200 }, //Chokory
			{ { 3967.84, 9242.61, 0 }, 120 }, //ES Petrol
			{ { 1171.25, 10280.1, 0 }, 150 }, //Camp Spencer
			{ { 7169.08, 9298.94, 0 }, 150 }, //Tuk
			{ { 7676.77, 10152.7, 0 }, 100 }, //Igman Military Base
			{ { 10060.6, 9901.3, 0 }, 200 } //Borosh
	};
	Rocks[] = {
		"sharpstones_erosion.p3d",
		"sharprock_spike.p3d",
		"sharprock_wallh.p3d",
		"w_sharpstones_erosion.p3d",
		"bluntstone_02.p3d",
		"bluntstone_03.p3d",
		"sharpstone_02.p3d",
		"decal_rock_dark.p3d"
	};
	ATM[] = {
		"atm_02_f.p3d",
		"atm_01_f.p3d",
		"phonebooth_01_f.p3d",
		"phonebooth_02_f.p3d"
	};
	Water[] = {
		"rasman_pond.p3d",
		"misc_well.p3d",
		"misc_wellpump.p3d",
		"water_source_f.p3d",
		"kasna_new.p3d"
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
	};
	Trash[] = {
		"tyres_f.p3d",
		"junkpile_f.p3d",
		"garbagewashingmachine_f.p3d",
		"garbagebags_f.p3d",
		"kontejner.p3d",
		"garbagepallet_f.p3d",
		"popelnice.p3d"
	};
	Trees[] = {
		"str osika.p3d",
		"cwr2_a2_t_sorbus2s.p3d",
		"ind_pec_03.p3d",
		"t_populusb2s_ep1.p3d",
		"t_populusf2s_ep1.p3d",
		"str lipa.p3d",
		"t_picea2s.p3d",
		"hrusen2.p3d",
		"cwr2_a2_t_fagus2w.p3d",
		"cwr2_a2_t_alnus2s.p3d",
		"dd_borovice02.p3d",
		"t_picea3f.p3d",
		"t_pinuss2f.p3d",
		"t_pinuss1s_f.p3d",
		"t_carpinus2s.p3d",
		"t_quercusir2s_f.p3d",
		"jablon.p3d",
		"mb_t_ulmus_large.p3d",
		"cwr_aleppopine.p3d",
		"t_fagus2f_summer.p3d",
		"t_fagus2f.p3d",
		"t_populus3s.p3d",
		"t_pinusn2s.p3d",
		"t_picea1s.p3d",
		"cwr2_a2_t_quercus3s.p3d",
		"str kastan.p3d",
		"t_populusn3s_f.p3d",
		"cwr2_a2_t_fraxinus2s.p3d",
		"t_poplar2f_dead_f.p3d",
		"misc_fallentree2.p3d",
		"t_oleae1s_f.p3d",
		"t_fraxinusav2s_f.p3d",
		"t_oleae2s_f.p3d",
		"t_prunuss2s_ep1.p3d"
	};
	Bushes[] = {
		"krovi_long.p3d",
		"cwr2_a2_b_canina2s.p3d",
		"b_salix2s.p3d",
		"cwr2_a2_b_craet1.p3d",
		"str krovisko vysoke.p3d",
		"krovi2.p3d",
		"ker s bobulema.p3d",
		"t_malus1s.p3d",
		"cwr2_a2_b_prunus.p3d",
		"b_ficusc1s_f.p3d",
		"hospital_side1_f.p3d",
		"b_craet1_summer.p3d",
		"b_neriumo2s_f.p3d",
		"b_neriumo2s_white_f.p3d",
		"cwr2_a2_b_sambucus.p3d"
	};
	Wrecks[] = {
		"wreck_ural_f.p3d",
		"rubble_metal_plates_04.p3d",
		"rubble_metal_plates_02.p3d",
		"wreck_car2_f.p3d",
		"rubble_metal_plates_01.p3d",
		"wreck_truck_dropside_f.p3d",
		"wreck_brdm2_f.p3d",
		"wreck_bmp2_f.p3d",
		"wreck_heli_attack_01_f.p3d",
		"bmp_break.p3d",
		"wreck_t72_hull_f.p3d",
		"wreck_t72_turret_f.p3d",
		"wreck_uaz_f.p3d",
		"wreck_hmmwv_f.p3d",
		"kamaz_bort.p3d",
		"wreck_van_f.p3d",
		"kamaz_awtobas.p3d",
		"wreck_offroad_f.p3d",
		"wreck_car3_f.p3d",
		"maz.p3d",
		"wreck_offroad2_f.p3d",
		"wreck_car_f.p3d",
		"wreck_skodovka_f.p3d",
		"wreck_cardismantled_f.p3d",
		"wreck_truck_f.p3d",
		"kamaz_pozarka.p3d",
		"zaporosez.p3d",
		"kamaz_tent.p3d",
		"uaz_wrecked.p3d",
		"ural_wrecked.p3d"
	};
};