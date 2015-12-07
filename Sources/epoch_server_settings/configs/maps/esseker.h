/*
	Author: Aaron Clark - EpochMod.com

    Contributors: Riche

	Description:
	Epoch gamemode server Side map specific configs for esseker.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server_settngs/configs/maps/esseker.h
*/
class Esseker : Default
{
	worldSize = 12000;
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
	traderBlds[] = { "Land_i_House_Big_02_V3_dam_F", "Land_A_GeneralStore_01", "Land_A_GeneralStore_01a", "Land_sara_domek_zluty", "Land_Tovarna2", "Land_Shed_Ind02", "Land_i_House_Big_01_V3_dam_F", "Land_HouseV2_02_Interier", "Land_i_House_Small_01_V3_dam_F", "Land_HouseV_1I4", "Land_dum_rasovna", "Land_FuelStation_Build_F", "Land_CarService_F", "Land_u_House_Small_02_V1_F", "Land_i_Stone_HouseSmall_V1_F", "Land_i_Stone_Shed_V1_F"};

	containerPos[] = {};

	telePos[] = {
		// N [-0.286865,8.17383,-10.3098]
		// S [-0.415527,-7.05298,-10.3098]
		// E [13.5127,0.410156,-10.3098]
		// W [-14.4316,0.112793,-10.3098]
		{ "Transport_N_EPOCH", { -0.286865, 8.17383, -10.3098 }, "", { 5073.31, 8903.09, 0 } },
		{ "Transport_W_EPOCH", { -14.4316, 0.112793, -10.3098 }, "", { 4407.77, 6054.78, 0 } },
		{ "Transport_E_EPOCH", { 13.5127,0.410156,-10.3098 }, "", { 8692.93, 3854.72, 0 } }
	};

	propsPos[] = {
		//Banking
		{"Land_PhoneBooth_02_F", {2676.67, 4481.42, 0.971237}, 251.364},
	    {"Land_PhoneBooth_02_F", {4780.24, 5036.36, 0}, 61.8182},
	    {"Land_PhoneBooth_02_F", {8375, 5886.44, 0.874567}, 260},
	    {"Land_PhoneBooth_02_F", {9066.22, 5711.39, 1.01706}, 92.2728},
	    {"Land_PhoneBooth_02_F", {10274, 5426.17, 0.389097}, 5.90916},
	    {"Land_PhoneBooth_02_F", {11867.5, 7928.89, 0}, 0},
	    {"Land_PhoneBooth_02_F", {1954.29, 7823.96, 0}, 19.5454},
	    {"Land_PhoneBooth_02_F", {7229.75, 9369.1, 0}, 2.72723},
		// Turbines
		{"Land_wpp_Turbine_V2_F", {660.226, 10060.1, 0}, 0},
	    {"Land_wpp_Turbine_V2_F", {638.57, 10022.9, 0}, 0},
	    {"Land_wpp_Turbine_V2_F", {619.792, 9992.28, 0}, 0},
	    {"Land_wpp_Turbine_V2_F", {8460.08, 10413.9, 0}, 0},
	    {"Land_wpp_Turbine_V2_F", {8454.32, 10389.2, 0}, 0},
	    {"Land_wpp_Turbine_V2_F", {9049.06, 7300.92, 0}, 0},
	    {"Land_wpp_Turbine_V2_F", {9076.69, 7307.17, 0}, 0},
	    {"Land_wpp_Turbine_V2_F", {9106.83, 7312.57, 0}, 0},
	    {"Land_wpp_Turbine_V2_F", {10366.2, 4436.95, 0}, 0},
	    {"Land_wpp_Turbine_V2_F", {10388.1, 4432.72, 0}, 0},
	    {"Land_wpp_Turbine_V2_F", {10409.6, 4431.36, 0}, 0},
	    {"Land_wpp_Turbine_V2_F", {10477.8, 1711.21, 0}, 0},
	    {"Land_wpp_Turbine_V2_F", {10450.9, 1722.47, 0}, 0},
	    {"Land_wpp_Turbine_V2_F", {10427.2, 1732.72, 0}, 0},
	    {"Land_wpp_Turbine_V2_F", {6786.74, 1593.55, 0}, 0},
	    {"Land_wpp_Turbine_V2_F", {6815.66, 1599.61, 0}, 0},
	    {"Land_wpp_Turbine_V2_F", {5271.16, 701.119, 0}, 0},
	    {"Land_wpp_Turbine_V2_F", {5299.02, 686.961, 0}, 0},
	    {"Land_wpp_Turbine_V2_F", {5333.93, 680.457, 0}, 0},
	    {"Land_wpp_Turbine_V2_F", {1004.79, 995.512, 0}, 0},
	    {"Land_wpp_Turbine_V2_F", {1013.99, 964.396, 0}, 0},
	    {"Land_wpp_Turbine_V2_F", {1781.4, 4202.1, 0}, 0},
	    {"Land_wpp_Turbine_V2_F", {1809.62, 4202.09, 0}, 0},
	    {"Land_wpp_Turbine_V2_F", {3322.47, 6256.38, 0}, 0},
	    {"Land_wpp_Turbine_V2_F", {3354.45, 6249.63, 0}, 0},
	    {"Land_wpp_Turbine_V2_F", {3380.16, 6244.95, 0}, 0},
	    {"Land_wpp_Turbine_V2_F", {1185.73, 7709.4, 0}, 0},
	    {"Land_wpp_Turbine_V2_F", {1223.07, 7716, 0}, 0},
	    {"Land_wpp_Turbine_V2_F", {5535.8, 8959.03, 0}, 0},
	    {"Land_wpp_Turbine_V2_F", {5507.72, 8966.35, 0}, 0},
	    // Esseker South Trader
	    {"ClutterCutter_EP1", {8694.08, 3853.14, 0}, 0},
	    {"ClutterCutter_EP1", {8691.68, 3859.46, 0}, 0},
	    {"land_Objects11", {8699.23, 3858.52, 0}, 319.546},
	    {"RU_WarfareBVehicleServicePoint", {8693.92, 3864.09, -0.126221}, 149.545},
	    {"CDF_WarfareBBarrier10x", {8692.13, 3865.79, -0.315292}, 329.545},
	    {"CDF_WarfareBBarrier10x", {8705.19, 3862.98, -0.226089}, 60.4545},
	    {"CDF_WarfareBBarrier10x", {8700.07, 3851.64, 0}, 329.545},
	    {"CDF_WarfareBBarrier10x", {8687.66, 3853.77, -0.350647}, 59.5454},
	    {"Land_Fire_barrel_burning", {8700.64, 3856.44, 0}, 60.9091},
	    {"Land_Ind_BoardsPack2", {8689.38, 3853.65, 0}, 327.273},
	    {"Paleta2", {8691.03, 3851.63, 0}, 0},
	    {"Land_cages_EP1", {8696.63, 3851.24, 0}, 240},
	    {"Land_transport_kiosk_EP1", {8689.07, 3861.7, 0}, 60.4545},
	    {"Land_stand_waterl_EP1", {8698.58, 3852.75, 0}, 149.545},
	    {"Land_tires_EP1", {8690.3, 3854.55, 0}, 0},
	    {"Misc_TyreHeapEP1", {8688.46, 3856.11, 0}, 0},
	    {"Land_transport_crates_EP1", {8693.05, 3859.05, 0}, 0},
	    {"Campfire_burning_F", {8696.22, 3857.09, 0}, 0},
	    {"Land_bags_EP1", {8687.38, 3861.25, 0}, 0},
	    // West Trader
		{"ClutterCutter_EP1", {4403.29, 6054.46, 0}, 0},
	    {"CDF_WarfareBBarrier10x", {4399.01, 6060.29, -0.514542}, 307.273},
	    {"CDF_WarfareBBarrier10x", {4411.15, 6059.94, 0}, 217.273},
	    {"CDF_WarfareBBarrier10x", {4414.62, 6048.48, -0.14389}, 306.818},
	    {"CDF_WarfareBBarrier10x", {4402.54, 6048.84, -0.160172}, 37.7273},
	    {"USMC_WarfareBVehicleServicePoint", {4405.97, 6049.83, 0}, 127.727},
	    {"Misc_cargo_cont_net2", {4400.11, 6053.7, 0}, 304.545},
	    {"Land_StallWater_F", {4399.67, 6058.44, 0}, 307.273},
	    {"Land_Sacks_heap_F", {4405.97, 6061.98, 0}, 0},
	    {"Land_Sacks_goods_F", {4407.62, 6060.97, 0}, 35.4546},
	    {"Land_CratesShabby_F", {4401.47, 6061.99, 0}, 40},
	    {"Land_CratesPlastic_F", {4412.85, 6049.18, 0}, 0},
	    {"Land_WoodenCart_F", {4412.07, 6047.53, 0}, 34.091},
	    {"Land_Cages_F", {4401.22, 6060.5, 0}, 0},
	    {"Land_fort_bagfence_corner", {4410.22, 6059.21, 0}, 36.3637},
	    {"Land_fort_bagfence_corner", {4412.56, 6057.64, 0}, 305.455},
	    {"Land_Campfire_burning", {4403.67, 6057.8, 0.0157471}, 0},
	    {"Land_stand_small_EP1", {4414.19, 6049.87, 0}, 126.818},
	    {"Land_transport_kiosk_EP1", {4414.51, 6051.86, 0}, 215},
	    {"Land_Fire_barrel_burning", {4413.8, 6056.01, 0}, 0},
		// North Trader
		{"ClutterCutter_EP1", {5068.43, 8897.88, 0}, 0},
	    {"CDF_WarfareBBarrier10x", {5065.82, 8891.55, -0.294769}, 29.5455},
	    {"CDF_WarfareBBarrier10x", {5064.97, 8903.57, -0.186707}, 302.727},
	    {"CDF_WarfareBBarrier10x", {5077, 8896.71, -0.080307}, 299.545},
	    {"CDF_WarfareBBarrier10x", {5076.48, 8908.56, -0.235596}, 29.5455},
	    {"land_Objects70", {5067.69, 8903.17, 0}, 119.545},
	    {"Land_bags_EP1", {5078.3, 8901.94, 0}, 29.5454},
	    {"Land_Fire_barrel_burning", {5067.41, 8895.88, 0}, 0},
	    {"Land_Ind_BoardsPack2", {5072.56, 8908.35, 0}, 208.182},
	    {"Land_Campfire_burning", {5070.59, 8897.51, 0}, 0},
	    {"Land_Carpet_rack_EP1", {5077.88, 8906.5, 0}, 30},
	    {"Misc_palletsfoiled_heap", {5064.94, 8895.37, 0}, 29.5455},
	    {"Land_bags_stack_EP1", {5077.46, 8899.98, 0}, 300},
	    {"Land_Misc_IronPipes_EP1", {5075.13, 8898.29, 0}, 275.909},
	    {"Land_cages_EP1", {5073.74, 8893.72, 0}, 314.545},
	    {"Land_Reservoir_EP1", {5075.23, 8907.88, 0}, 146.364},
	    {"Land_Crates_stack_EP1", {5064.93, 8901.7, 0}, 31.3636},
	    {"ShedSmall", {5067.43, 8893.46, 0}, 28.6363},
	    // Protection Domes
		{ "ProtectionZone_Invisible_F", { 5073.31, 8903.09, 0 }, 0, true },
		{ "ProtectionZone_Invisible_F", { 4407.77, 6054.78, 0 }, 0, true },
		{ "ProtectionZone_Invisible_F", { 8692.93, 3854.72, 0 }, 0, true }
	};

	staticNpcPos[] = {
	    //South
		{ "C_man_hunter_1_F", {8700.09, 3859.75, -0.0334778}, 241},
		//West
		{ "C_man_w_worker_F", {4411.08, 6058.25, 0}, 24.5455},
		//North
		{ "C_man_shorts_4_F_asia", {5068.45, 8893.52, 0}, 30}
	};
};
