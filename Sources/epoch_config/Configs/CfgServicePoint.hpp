class CfgServicePoint {
	class Altis {
		ServicePoints[] =	{	// Array of coords for ServicePoints
/*
								{pos1},
								{pos2}
								OR
								{
									pos1,
									dist1,
									{VehType_1,VehType_1,...},
									"MarkerText1"
								},
								{
									pos2,
									dist2,
									{VehType,VehType,...},
									"MarkerText2"
								}
*/
								{								// Central
									{13325,14477,0},						// Pos
									40,										// max distance
									{"Landvehicle","Ship","Tank","AIR"},	// Vehicle Types for SP
									"Service Point Land / Ship / Air"		// Marker Text (Leave it Blank to disable Marker)
								}
							};
	};
	class Tanoa {
		ServicePoints[] =	{	// Array of coords for ServicePoints
/*
								{2157.79,3477.65,0},
								{11731.5,3125.95,0},
								{7008.93,7582.59,0},
								{2326.28,13167.9,0},
								{11805.8,13100.6,0},

								{5525.8,10345.2,0},
								{11916,2383.88,0},
								{13562.4,12139.5,0}
*/								
							};
	};
	class Chernarus {	// Array of coords for ServicePoints
		ServicePoints[] =	{

							};
	};
	ServicePointClasses[] = {	// Array of Classnames where also are ServicePoints (not separat configurable for Vehicle types / distance)
//								"Land_Pillar_Pier_F",
//								"Land_CarService_F",
//								"Land_fs_feed_F",
//								"Land_fs_roof_F"
	};
	PreventRepairs[] = {		// These Hitpints will not be repaired, if damage >= value (Prevent from Duping Tires / Engines)
		{"HitLFWheel",1},		// {"HitPoint",value}
		{"HitLF2Wheel",1},
		{"HitLMWheel",1},
		{"HitLBWheel",1},
		{"HitRFWheel",1},
		{"HitRF2Wheel",1},
		{"HitRMWheel",1},
		{"HitRBWheel",1},
		{"HitEngine",1}
	};
	ServicePointDist = 40;
	refuel_updateInterval = 1;
	refuel_amount = 0.1;
	repairTime = 1.2;
	repair_costs[] = {
		{"Air",0},
		{"Tank",0},
		{"Ship",0},
		{"Landvehicle",0}
	};
	refuel_costs[] = {
		{"Air",0},
		{"Tank",0},
		{"Ship",0},
		{"Landvehicle",0}
	};
	VehiclesAndAmmo[] = {
/*
		{
			"typeof vehicle",
			{
				{"Ammoclass",{Turretpath},MaxMagsCount,PricePerMag},
				{"Ammoclass",{Turretpath},MaxMagsCount,PricePerMag}
			}
		},
*/
		{
			"B_G_Offroad_01_armed_F",
			{
				{"100Rnd_127x99_mag_Tracer_Yellow",{0},4,200}
			}
		},
		{
			"O_G_Offroad_01_armed_F",
			{
				{"100Rnd_127x99_mag_Tracer_Yellow",{0},4,200}
			}
		},
		{
			"I_G_Offroad_01_armed_F",
			{
				{"100Rnd_127x99_mag_Tracer_Yellow",{0},4,200}
			}
		},
		{
			"I_MRAP_03",
			{
				{"SmokeLauncherMag",{0},1,150}
			}
		},
		{
			"I_MRAP_03_EPOCH",
			{
			}
		},
		{
			"O_MRAP_02_F",
			{
				{"SmokeLauncherMag",{-1},1,150}
			}
		},
		{
			"B_LSV_01_armed_olive_F",
			{
				{"100Rnd_127x99_mag_Tracer_Red",{0},3,200},
				{"130Rnd_338_Mag",{1},3,260}
			}
		},
		{
			"B_LSV_01_armed_black_F",
			{
				{"100Rnd_127x99_mag_Tracer_Red",{0},3,200},
				{"130Rnd_338_Mag",{1},3,260}
			}
		},
		{
			"O_T_LSV_02_armed_black_F",
			{
				{"500Rnd_65x39_Belt_Tracer_Green_Splash",{0},3,500}
			}
		},
		{
			"O_T_LSV_02_armed_ghex_F",
			{
				{"500Rnd_65x39_Belt_Tracer_Green_Splash",{0},3,500}
			}
		},
		{
			"B_SDV_01_EPOCH",
			{
			}
		},
		{
			"B_Heli_Light_01_armed_F",
			{
				{"5000Rnd_762x51_Belt",{-1},1,1600}
			}
		},
		{
			"O_Heli_Light_02_unarmed_EPOCH",
			{
				{"168Rnd_CMFlare_Chaff_Magazine",{-1},1,150}
			}
		},
		{
			"O_Heli_Light_02_v2_F",
			{
				{"2000Rnd_65x39_Belt_Tracer_Green_Splash",{-1},1,1200},
				{"168Rnd_CMFlare_Chaff_Magazine",{-1},1,150}
			}
		},
		{
			"B_Heli_Transport_01_EPOCH",
			{
				{"168Rnd_CMFlare_Chaff_Magazine",{-1},1,150},
				{"2000Rnd_65x39_Belt_Tracer_Red",{1},1,1200},
				{"2000Rnd_65x39_Belt_Tracer_Red",{2},1,1200}
			}
		},
		{
			"I_Heli_Transport_02_F",
			{
				{"168Rnd_CMFlare_Chaff_Magazine",{-1},1,150}
			}
		},
		{
			"I_Heli_Transport_02_EPOCH",
			{
				{"168Rnd_CMFlare_Chaff_Magazine",{-1},1,150}
			}
		},
		{
			"B_Heli_Transport_03_F",
			{
				{"168Rnd_CMFlare_Chaff_Magazine",{-1},1,150},
				{"2000Rnd_65x39_Belt_Tracer_Red",{1},1,1200},
				{"2000Rnd_65x39_Belt_Tracer_Red",{2},1,1200}
			}
		},
		{
			"B_Heli_Transport_03_black_F",
			{
				{"168Rnd_CMFlare_Chaff_Magazine",{-1},1,150},
				{"2000Rnd_65x39_Belt_Tracer_Red",{1},1,1200},
				{"2000Rnd_65x39_Belt_Tracer_Red",{2},1,1200}
			}
		},
		{
			"B_Heli_Transport_03_unarmed_EPOCH",
			{
				{"168Rnd_CMFlare_Chaff_Magazine",{-1},1,150}
			}
		},
		{
			"I_Heli_light_03_unarmed_EPOCH",
			{
				{"168Rnd_CMFlare_Chaff_Magazine",{-1},1,150}
			}
		},
		{
			"B_T_VTOL_01_vehicle_blue_F",
			{
				{"240Rnd_CMFlare_Chaff_Magazine",{-1},1,150}
			}
		},
		{
			"B_T_VTOL_01_infantry_olive_F",
			{
				{"240Rnd_CMFlare_Chaff_Magazine",{-1},1,150}
			}
		},
		{
			"B_T_VTOL_01_infantry_blue_F",
			{
				{"240Rnd_CMFlare_Chaff_Magazine",{-1},1,150}
			}
		},
		{
			"O_T_VTOL_02_vehicle_F",
			{
				{"168Rnd_CMFlare_Chaff_Magazine",{-1},1,150}
			}
		},
		{
			"O_T_VTOL_02_vehicle_grey_F",
			{
				{"168Rnd_CMFlare_Chaff_Magazine",{-1},1,150}
			}
		},
		{
			"O_T_VTOL_02_infantry_F",
			{
				{"168Rnd_CMFlare_Chaff_Magazine",{-1},1,150}
			}
		},
		{
			"B_Heli_Attack_01_F",
			{
				{"240Rnd_CMFlare_Chaff_Magazine",{-1},1,150}
			}
		},
		{
			"O_Heli_Attack_02_black_F",
			{
				{"192Rnd_CMFlare_Chaff_Magazine",{-1},1,150}
			}
		},
		{
			"O_Heli_Attack_02_F",
			{
				{"192Rnd_CMFlare_Chaff_Magazine",{-1},1,150}
			}
		},
		{
			"O_Boat_Armed_01_hmg_F",
			{
				{"SmokeLauncherMag_boat",{-1},1,100},
				{"200Rnd_127x99_mag_Tracer_Green",{1},3,300}
			}
		},
		{
            "mosquito_epoch_armedG",
            {
                {"3Rnd_MosquitoGrenade",{-1},1,60}
            }
        }
	};
};
