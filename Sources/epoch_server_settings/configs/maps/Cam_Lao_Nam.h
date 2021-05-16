/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Epoch gamemode server Side map specific configs for altis.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server_settngs/configs/maps/altis.h
*/
class Cam_Lao_Nam : Default
{
	worldSize = 20480;
	plantLimit = 10;
	// vehicles - Max vehicle slots is calculated from per vehicle limits below. Warning! Higher the number lower the performance.
	vehicleSpawnTypes[] = {
		{"FlatAreaCity",1},
		{"FlatAreaCitySmall",1},
		{"NameCity",2},
		{"NameVillage",1},
		{"NameCityCapital",4},
		{"Airport",5}
	};

	// Override Trader Uniforms
	traderUniforms[] = {"vn_o_uniform_nva_dc_13_07", "vn_o_uniform_nva_dc_13_08", "vn_o_uniform_nva_dc_13_04", "vn_o_uniform_nva_dc_13_02", "vn_o_uniform_nva_dc_14_01", "vn_o_uniform_nva_dc_14_04"};

	// Override Shipwreck Models
	shipwreckCustomWrecks[] = {"Land_vn_uwreck_fishingBoat_f", "Land_vn_uwreck_traw_f", "Land_vn_uwreck_traw2_f", "Land_vn_boat_03_wreck", "Land_vn_boat_04_wreck", "Land_vn_boat_05_wreck", "Land_vn_boat_06_wreck"};

	// Ocerride Helo Crash Models
	availableHeliCrashes[] = {{"vn_b_air_uh1c_07_07","vn_air_uh1c_01_wreck"},{"vn_b_air_uh1d_01_07","vn_air_uh1d_med_wreck"},{"vn_b_air_uh1d_02_07","vn_air_uh1d_01_wreck"},{"vn_b_air_ch34_01_01","vn_air_ch34_01_wreck"},{"vn_b_air_oh6a_01","vn_air_oh6a_01_wreck"},{"vn_o_air_mi2_01_01","vn_air_mi2_01_wreck"}};

	telePos[] = {
		// N [-0.286865,8.17383,-10.3098, 0]
		// S [-0.415527,-7.05298,-10.3098, 180]
		// E [13.5127,0.410156,-10.3098, 90]
		// W [-14.4316,0.112793,-10.3098, -90]
			{ "TP_Booth_n_EPOCH", { -0.286865, 8.17383, -10.3098, 0}, "", { 8516,17931,0 } }, 	// North
			{ "TP_Booth_s_EPOCH", { -0.286865, -8.17383, -10.3098, 180}, "", { 14501,1683,0 } }, // South
			{ "TP_Booth_w_EPOCH", { -14.4316, 0.112793, -10.3098, -90}, "", { 1219,13702,0 } }, // West
			{ "TP_Booth_e_EPOCH", { 13.5127, 0.410156, -10.3098, 90}, "", { 18490,10696,0} }		// East
	};
	propsPos[] = {
	};
	staticNpcPos[] = {
	};

	// Prefered locations for vehicles
	class whitelistedVehiclePos {
	};

};
