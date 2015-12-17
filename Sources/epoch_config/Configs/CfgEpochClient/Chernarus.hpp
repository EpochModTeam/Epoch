/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Epoch gamemode config for Chernarus

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_config/Configs/CfgEpochClient/Chernarus.hpp
*/
class Chernarus {
	blockedArea[] = {
			{ { 10203, 1886, 0 }, 430 }, //South Electro
			{ { 6822, 2498, 0 }, 600 }, //Cherno
			{ { 4612, 9670, 0 }, 140 }, //NWAF south barack
			{ { 4907, 10117, 0 }, 250 }, //NWAF NE hangas
			{ { 4707, 10384, 0 }, 200 }, //NWAF north barack
			{ { 4069, 10778, 0 }, 75 }, //NWAF west hangas
			{ { 4553, 10722, 0 }, 150 }, //NWAF NW hangas
			{ { 12279, 9505, 0 }, 350 }, //Berenzino Mid
			{ { 12816, 9816, 0 }, 400 }, //Berenzino SE
			{ { 12991, 10147, 0 }, 375 }, //Berenzino Docs
			{ { 2693, 5138, 0 }, 200 }, //Zeleno
			{ { 11467, 7508, 0 }, 150 }, //Polana Factory
			{ { 13092, 7096, 0 }, 140 } //Solnichniy Factory
	};
	Rocks[] = {
		"r2_boulder1.p3d",
		"r2_boulder2.p3d",
		"r2_rock1.p3d",
		"r2_rocktower.p3d",
		"r2_rockwall.p3d"
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
	TrashClasses[] = { "Trash", "TrashSmall", "TrashVehicle", "PumpkinPatch", "TrashFood" };

	TrashSmall[] = {
		"misc_postbox.p3d"
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
		"zastavka_stojan.p3d"
	};
	Trees[] = {
		"t_populus3s.p3d",
		"t_fagus2w.p3d",
		"t_betula2s.p3d",
		"t_fagus2s.p3d",
		"t_fagus2f.p3d",
		"t_sorbus2s.p3d",
		"t_fraxinus2w.p3d",
		"t_salix2s.p3d",
		"t_malus1s.p3d",
		"t_betula1f.p3d",
		"t_pinusn2s.p3d",
		"t_picea2s.p3d",
		"t_larix3s.p3d",
		"t_picea3f.p3d",
		"t_picea1s.p3d",
		"misc_fallentree2.p3d",
		"misc_stub2.p3d",
		"t_fraxinus2s.p3d",
		"t_quercus2f.p3d",
		"misc_trunk_water.p3d",
		"misc_trunk_torzo.p3d",
		"t_alnus2s.p3d",
		"misc_fallentree1.p3d",
		"t_betula2f.p3d",
		"t_pinusn1s.p3d",
		"t_pinuss2f.p3d",
		"t_quercus3s.p3d",
		"t_carpinus2s.p3d",
		"misc_fallenspruce.p3d",
		"t_stub_picea.p3d",
		"misc_stub1.p3d",
		"t_acer2s.p3d",
		"t_betula2w.p3d",
		"t_pyrus2s.p3d"
	};
	Bushes[] = {
		"b_craet1.p3d",
		"b_craet2.p3d",
		"b_corylus.p3d",
		"b_corylus2s.p3d",
		"b_betulahumilis.p3d",
		"b_sambucus.p3d",
		"b_salix2s.p3d",
		"b_canina2s.p3d",
		"b_pmugo.p3d",
		"b_prunus.p3d"
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
