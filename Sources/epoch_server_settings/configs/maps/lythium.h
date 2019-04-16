/*
	Author: Aaron Clark - EpochMod.com

    Contributors: Uro1, Robio

	Description:
	Epoch gamemode server Side map specific configs for chernarus redux.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server_settngs/configs/maps/chernarusredux.h
*/
class Lythium : Default
{
	worldSize = 12000;
	plantLimit = 10;
	vehicleSpawnTypes[] = {
		{"FlatAreaCity",1},
		{"FlatAreaCitySmall",1},
		{"NameCity",2},
		{"NameVillage",1},
		{"NameCityCapital",4},
		{"Airport",5},
		{"NameLocal",2},
		{"StrongpointArea",1},
		{"VegetationBroadleaf",1},
		{"VegetationFir",1},
		{"ViewPoint",1}
	};
	traderBlds[] = { 
		"Land_A_FuelStation_Build", 
		"Land_A_GeneralStore_01", 
		"Land_A_GeneralStore_01a",
		"Land_A_Office01", 
		"Land_Ind_Garage01", 
		"Land_Ind_Workshop01_04", 
		"Land_Ind_Workshop01_L", 
		"Land_Shed_Ind02", 
		"Land_Tovarna2", 
		"Land_sara_hasic_zbroj" 
	};
	telePos[] = {
		//[9305.75,0,15320.2], respawn_north
		//[8859.85,0,6356.99], respawn_south
		//[4489.75,0,11967.3], respawn_west
		//[18040.1,0,12909.7], respawn_east

	// N [-0.286865,8.17383,-10.3098]
		// S [-0.415527,-7.05298,-10.3098]
		// E [13.5127,0.410156,-10.3098]
		// W [-14.4316,0.112793,-10.3098]
			//{ "Transport_W_EPOCH", { -14.4316, 0.112793, -10.3098 }, "", { 4489.75, 11967.3, 0 } }, //  West
			{ "Transport_C_EPOCH", { -0.286865, 8.17383, -10.3098 }, "", { 10575.8, 9284.92, 0 } }, //  East 10575/9284
			{ "Transport_W_EPOCH", { -14.4316, 0.112793, -10.3098 }, "", { 14325.1, 18769.7, 0 } }, 
			{ "Transport_E_EPOCH", { 13.5127, 0.410156, -10.3098 }, "", { 12313.85, 1129.99, 0 } } // South //  12313/1129
	};
	propsPos[] = {

	};
	staticNpcPos[] = {
		//  Eaample: { "C_man_w_worker_F", { 13323.1, 14527.3, 0.00144649 }, 201.163 },
		// Central
		{ C_Man_UtilityWorker_01_F,{10575,9284.19,0.0143967},67.6322 },
		{ C_man_sport_1_F_afro,{10581.2,9284.84,0.208435},274.638 },
		{ C_man_sport_2_F_tanoan,{10577.4,9279.94,-5.34058e-005},15.5608 },
		//{ C_man_p_fugitive_F_euro,{10572.7,9296.96,0.00154877},155.608 },
		//North
		{ C_Man_UtilityWorker_01_F,{14360,18784.4,0.00143433},116.53 },
		{ C_man_sport_1_F_afro,{14364.7,18780.4,0.00143433},314.072 },
		{ C_man_sport_2_F_tanoan,{14358.5,18779.8,0.00143433},57.9831 },
		//{ C_man_p_fugitive_F_euro,{12413.8,19894.9,0.00292969},155.608 },
		//South
		{ C_Man_UtilityWorker_01_F,{12338.7,1139.92,0.00128555},270 },
		{ C_man_sport_1_F_afro,{12332.6,1139.89,0.00128937},84.9434 },
		{ C_man_sport_2_F_tanoan,{12336.8,1144.39,0.00127792},184.952 }
	
	
	};
};
