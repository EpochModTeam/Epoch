/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Epoch gamemode server Side map specific configs for Zargabad.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server_settngs/configs/maps/zargabad.h
*/
class Zargabad : Default
{
	worldSize = 0; // 0 = default to worldSize command
	plantLimit = 5;
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
	traderBlds[] = { "Land_Kiosk_blueking_F", "Land_FuelStation_Build_F", "Land_CarService_F", "Land_i_Garage_V1_F", "Land_i_Shed_Ind_F", "Land_i_Shop_01_V1_F" };
	shipwreckLootEnabled = 0;
	telePos[] = {
		// N [-0.286865,8.17383,-10.3098, 0]
		// S [-0.415527,-7.05298,-10.3098, 180]
		// E [13.5127,0.410156,-10.3098, 90]
		// W [-14.4316,0.112793,-10.3098, -90]
			{ "TP_Booth_n_EPOCH", { 13.5127,0.410156,-10.3098, 90}, "", "north" },
			{ "TP_Booth_c_EPOCH", { -0.415527,-7.05298,-10.3098, 180}, "", "south" }
	};
	
	propsPos[] = {
	};

	staticNpcPos[] = {
	};
};
