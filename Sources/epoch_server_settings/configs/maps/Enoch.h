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
class Enoch : Default
{
	worldSize = 12800;
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
	telePos[] = {
		// N [-0.286865,8.17383,-10.3098, 0]
		// S [-0.415527,-7.05298,-10.3098, 180]
		// E [13.5127,0.410156,-10.3098, 90]
		// W [-14.4316,0.112793,-10.3098, -90]
			{ "TP_Booth_n_EPOCH", { -0.286865, 8.17383, -10.3098, 0}, "", { 5890,10710,0 } }, 	// North
			{ "TP_Booth_s_EPOCH", { -0.286865, -8.17383, -10.3098, 180}, "", { 6356,2768,0 } }, // South
			{ "TP_Booth_w_EPOCH", { -14.4316, 0.112793, -10.3098, -90}, "", { 1927,6372,0 } }, // West
			{ "TP_Booth_e_EPOCH", { 13.5127, 0.410156, -10.3098, 90}, "", { 10328,7022,0} }		// East
	};
	propsPos[] = {
	};
	staticNpcPos[] = {
	};

	// Prefered locations for vehicles
	class whitelistedVehiclePos {
	};

};
