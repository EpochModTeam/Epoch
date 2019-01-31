class lingor3 : Default
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
	shipwreckLootEnabled = 0;
	telePos[] = {
		// N [-0.286865,8.17383,-10.3098, 0]
		// S [-0.415527,-7.05298,-10.3098, 180]
		// E [13.5127,0.410156,-10.3098, 90]
		// W [-14.4316,0.112793,-10.3098, -90]
			{ "TP_Booth_c_EPOCH", { 13.5127, 0.410156, -10.3098, 90}, "", "center" } // temp for now
	};
	propsPos[] = {
	};
	staticNpcPos[] = {
	};
};
