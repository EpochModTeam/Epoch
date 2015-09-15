class Bornholm {
	blockedArea[] = {
			{ { 1433, 8071, 0 }, 250 }, //Roenne NorthEast
			{ { 1939, 7788, 0 }, 250 }, //Roenne East
			{ { 1553, 7103, 0 }, 400 }, //Roenne South
			{ { 3052, 5412, 0 }, 400 }, //Main Airport
			{ { 3676, 5148, 0 }, 300 }, //Airport addons
			{ { 9547, 5541, 0 }, 600 }, //Aakirkeby
			{ { 17433, 5106, 0 }, 600 }, //Nexoe
			{ { 17989, 9844, 0 }, 600 }, //Svaneke
			{ { 11600, 14723, 0 }, 500 }, //Gudhjem
			{ { 5010, 19132, 0 }, 250 }, //Allinge
			{ { 5291, 12450, 0 }, 450 }, //Klemensker
			{ { 3386, 10088, 0 }, 350 }, //Nyker
			{ { 14560, 5130, 0 }, 300 }, //South Airport
			{ { 148786, 5024, 0 }, 300 }, //South Airport Base
			{ { 12993, 10197, 0 }, 250 }, //Oestermarie
			{ { 13867, 10672, 0 }, 300 }, //East Airport
			{ { 8564, 15015, 0 }, 350 }, //Roe
			{ { 6554, 5866, 0 }, 400 }, //Lobbaek
			{ { 5350, 5724, 0 }, 300 }, //Nylars
			{ { 12438, 2980, 0 }, 400 }, //Pedersker
			{ { 14121, 11331, 0 }, 200 }, //Central Spawn
			{ { 1322, 8733, 0 }, 200 }, //West Spawn
			{ { 15639, 191, 0 }, 200 } //East Spawn
	};
	Rocks[] = {
		"bo_r2_boulder1.p3d",
		"bo_r2_boulder2.p3d",
		"bo_r2_rock1.p3d",
		"bo_r2_rocktower.p3d",
		"bo_r2_rockwall.p3d"
	};
	ATM[] = {
		"nastenka.p3d",
		"nastenka2.p3d",
		"nastenka3.p3d"
	};
	Water[] = {
		"misc_well.p3d",
		"misc_wellpump.p3d",
		"kasna_new.p3d"
	};	

	// main config 
	TrashClasses[] = {"Trash","TrashSmall","TrashVehicle","PumpkinPatch","TrashFood"};

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
		"misc_postbox.p3d",
		"popelnice.p3d",
		"garbage_misc.p3d",
		"paletyc.p3d",
		"junkpile.p3d",
		"kontejner.p3d",
		"misc_chickencoop.p3d",
		"misc_boogieman.p3d",
		"misc_hutch.p3d",
		"garbage_paleta.p3d",
		"misc_cargo1a.p3d",
		"misc_cargo2a.p3d",
		"misc_greenhouse.p3d",
		"zastavka_stojan.p3d",
		"p_helianthus.p3d",
		"junkpile_f.p3d",
		"bricks_v2_f.p3d",
		"woodenbox_f.p3d"
	};
	Trees[] = {
		"bo_t_populus3s.p3d",
		"bo_t_fagus2w.p3d",
		"bo_t_betula2s.p3d",
		"bo_t_fagus2s.p3d",
		"bo_t_fagus2f.p3d",
		"bo_t_sorbus2s.p3d",
		"bo_t_fraxinus2w.p3d",
		"bo_t_salix2s.p3d",
		"bo_t_malus1s.p3d",
		"bo_t_betula1f.p3d",
		"bo_t_pinusn2s.p3d",
		"bo_t_picea2s.p3d",
		"bo_t_larix3s.p3d",
		"bo_t_picea3f.p3d",
		"bo_t_picea1s.p3d",
		"bo_misc_fallentree2.p3d",
		"bo_misc_stub2.p3d",
		"bo_t_fraxinus2s.p3d",
		"bo_t_quercus2f.p3d",
		"bo_misc_trunk_water.p3d",
		"bo_misc_trunk_torzo.p3d",
		"bo_t_alnus2s.p3d",
		"bo_misc_fallentree1.p3d",
		"bo_t_betula2f.p3d",
		"bo_t_pinusn1s.p3d",
		"bo_t_pinuss2f.p3d",
		"bo_t_quercus3s.p3d",
		"bo_t_carpinus2s.p3d",
		"misc_fallenspruce.p3d",
		"bo_t_stub_picea.p3d",
		"misc_stub1.p3d",
		"bo_t_acer2s.p3d",
		"bo_t_betula2w.p3d",
		"bo_t_pyrus2s.p3d",
		"bo_b_corylus.p3d"
	};
	Bushes[] = {
		"bo_b_craet1.p3d",
		"bo_b_craet2.p3d",
		"bo_b_corylus.p3d",
		"bo_b_corylus2s.p3d",
		"bo_b_betulahumilis.p3d",
		"bo_b_sambucus.p3d",
		"salix2s.p3d",
		"bo_b_canina2s.p3d",
		"bo_b_pmugo.p3d",
		"bo_b_prunus.p3d"
	};
	Cinder[] = {
		"cinderblocks_f.p3d"
	};
	Wrecks[] = {
		"wall_fen1_5_pole.p3d",
		"wall_fen1_5_2.p3d",
		"wall_tin_4_2.p3d",
		"wall_fen1_5.p3d",
		"wall_indfnc_3.p3d",
		"wall_indfnc_9.p3d",
		"wall_indfnc_corner.p3d",
		"misc_concrete_high.p3d",
		"plot_vlnplech2.p3d",
		"misc_g_pipes.p3d",
		"wall_tincom_9.p3d",
		"wall_tin_4.p3d",
		"plot_vlnplech1.p3d",
		"wall_tincom_9_2.p3d",
		"wall_tincom_3.p3d",
		"wall_tincom_pole.p3d",
		"datsun01t.p3d",
		"datsun02t.p3d",
		"skodovka_wrecked.p3d",
		"lada_wrecked.p3d",
		"hiluxt.p3d",
		"uaz_wrecked.p3d",
		"ural_wrecked.p3d"
	};
};