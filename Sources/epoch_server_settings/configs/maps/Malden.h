/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Epoch gamemode server Side map specific configs for Malden.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server_settngs/configs/maps/Malden.h
*/
class Malden : Default
{
	worldSize = 0; // 0 = default to worldSize command
	plantLimit = 8;
	vehicleSpawnTypes[] = {
        {"FlatAreaCity",1},
		{"FlatAreaCitySmall",1},
		{"NameCity",2},
		{"NameVillage",1},
		{"NameCityCapital",4},
		{"Airport",5}
	};
    traderBlds[] = { "Land_Kiosk_blueking_F", "Land_FuelStation_Build_F", "Land_CarService_F", "Land_i_Garage_V1_F", "Land_i_Shed_Ind_F", "Land_i_Shop_01_V1_F" };
	containerPos[] = {};
	telePos[] = {
		// N [-0.286865,8.17383,-10.3098]
		// S [-0.415527,-7.05298,-10.3098]
		// E [13.5127,0.410156,-10.3098]
		// W [-14.4316,0.112793,-10.3098]
			//{ "Transport_N_EPOCH", { -0.286865, 8.17383, -10.3098 }, "", "north" },
			{ "Transport_W_EPOCH", { -14.4316, 0.112793, -10.3098 }, "", "west" },
			{ "Transport_E_EPOCH", { 13.5127,0.410156,-10.3098 }, "", "east" }
			//{ "Transport_C_EPOCH", { 13.5127, 0.410156, -10.3098 }, "", "south" }
	};
	propsPos[] = {
		// ATMs and Phones in gas stations and towns. Note, if a phone looks like it attached to the side of a house then it probably is part of the house model itself and will not work as an ATM
		{ "Land_ATM_02_malden_F", {3225.01,6276.43,0}, {{0.951241,-0.30845,0},{0,0,1}}, true },
    		{ "Land_PhoneBooth_01_malden_F", {3746.04,3256.26,0.161957}, {{-0.967747,-0.251925,0},{0,0,1}}, true },
    		{ "Land_ATM_01_malden_F", {5103,9074.26,0.508453}, {{0.595228,0.803557,0},{0,0,1}}, true },
    		{ "Land_PhoneBooth_01_malden_F", {5354.97,2805.33,0}, {{-0.384161,-0.923266,0},{0,0,1}}, true },
    		{ "Land_PhoneBooth_01_malden_F", {5495.61,7005.75,0.166534}, {{0.448686,-0.893689,0},{0,0,1}}, true },
    		{ "Land_PhoneBooth_02_malden_F", {5490.94,7003.29,0.169525}, {{0.440054,-0.897971,0},{0,0,1}}, true },
    		{ "Land_ATM_02_malden_F", {5507.85,3484.96,0}, {{0.984902,-0.173111,0},{0,0,1}}, true },
    		{ "Land_PhoneBooth_01_malden_F", {6028.37,8621.77,0}, {{-0.21328,-0.976991,0},{0,0,1}}, true },
    		{ "Land_PhoneBooth_01_malden_F", {6636.54,8819.84,-7.62939e-006}, {{-0.150817,0.988562,0},{0,0,1}}, true },
    		{ "Land_PhoneBooth_01_malden_F", {6639.32,8820.08,0}, {{-0.0954069,0.995438,0},{0,0,1}}, true },
    		{ "Land_PhoneBooth_01_malden_F", {6637.91,8819.96,0}, {{-0.103969,0.994581,0},{0,0,1}}, true },
   	 	{ "Land_PhoneBooth_02_malden_F", {7053.47,7058.09,0}, {{0.999621,-0.027522,0},{0,0,1}}, true },
    		{ "Land_PhoneBooth_02_malden_F", {7150.51,6003.52,0}, {{-0.0176981,0.999843,0},{0,0,1}}, true },
    		{ "Land_ATM_01_malden_F", {7211.19,7791.62,0.101868}, {{0.857566,0.514374,0},{0,0,1}}, true },
    		{ "Land_ATM_01_malden_F", {8057.78,4054.92,0.233646}, {{0.753691,-0.657229,0},{0,0,1}}, true }
	};
	staticNpcPos[] = {
	};
};
