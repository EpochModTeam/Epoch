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
								{											// Kavala Pier
									{3238,12907,0},							// Pos
									40,										// max distance
									{"Ship"},								// Vehicle Types for SP
									"Service Point Ship"					// Marker Text (Leave it Blank to disable Marker)
								},
								{											// Kavala Workshop
									{3755,13472.5,0},						// Pos
									40,										// max distance
									{"Landvehicle","TANK"},					// Vehicle Types for SP
									"Service Point Land"					// Marker Text (Leave it Blank to disable Marker)
								},
								{											// Airfield Workshop
									{14160,16533.5,0},						// Pos
									40,										// max distance
									{"Landvehicle","TANK"},					// Vehicle Types for SP
									"Service Point Land"					// Marker Text (Leave it Blank to disable Marker)
								},
								{											// Airfield Terminal
									{14641.5,16754.5,0},					// Pos
									40,										// max distance
									{"AIR"},								// Vehicle Types for SP
									"Service Point AIR"						// Marker Text (Leave it Blank to disable Marker)
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
	/* Get all Weapons and Turrets with "magazinesAllTurrets vehicle" -> https://community.bistudio.com/wiki/magazinesAllTurrets */
	class VehiclesAndAmmo {
/*
		class VehicleType {
			MagsTurrets[] = {
				{"Ammoclass",{Turretpath},MaxMagsCount,PricePerMag,Bullets per mag (optional, if you want to reduce bullets per mag)},
				{"Ammoclass",{Turretpath},MaxMagsCount,PricePerMag,Bullets per mag (optional, if you want to reduce bullets per mag)}
			};
		};
*/

		class a2_ch47f_armed_EPOCH {
			MagsTurrets[] = {
				{"200Rnd_65x39_Belt",{1},3,200},
				{"200Rnd_65x39_Belt",{2},3,200}
			};
		};
		class a2_ch47f_armed_plus_EPOCH {
			MagsTurrets[] = {
				{"200Rnd_762x51_Belt",{0},3,200},
				{"200Rnd_762x51_Belt",{1},3,200}
			};
		};
		class uh1h_armed_EPOCH {
			MagsTurrets[] = {
				{"200Rnd_65x39_Belt",{1},3,200},
				{"200Rnd_65x39_Belt",{2},3,200}
			};
		};
		class uh1h_armed_plus_EPOCH {
			MagsTurrets[] = {
				{"200Rnd_762x51_Belt",{0},3,200},
				{"200Rnd_762x51_Belt",{1},3,200}
			};
		};
		class C_Heli_Light_01_armed_EPOCH {
			MagsTurrets[] = {
				{"200Rnd_65x39_Belt",{-1},3,200}
			};
		};
		class C_Heli_Light_01_armed_plus_EPOCH {
			MagsTurrets[] = {
				{"200Rnd_762x51_Belt",{-1},3,200}
			};
		};
		class A2_SUV_armed_EPOCH {
			MagsTurrets[] = {
				{"200Rnd_762x51_Belt",{0},3,200}
			};
		};
		class B_G_Offroad_01_armed_F {
			MagsTurrets[] = {
				{"100Rnd_127x99_mag_Tracer_Yellow",{0},4,200}
			};
		};
		class O_G_Offroad_01_armed_F : B_G_Offroad_01_armed_F {};
		class I_G_Offroad_01_armed_F : B_G_Offroad_01_armed_F {};
		class I_MRAP_03 {
			MagsTurrets[] = {
				{"SmokeLauncherMag",{0},1,150}
			};
		};
		class I_MRAP_03_EPOCH {
			MagsTurrets[] = {
			};
		};
		class O_MRAP_02_F {
			MagsTurrets[] = {
				{"SmokeLauncherMag",{-1},1,150}
			};
		};
		class B_LSV_01_armed_olive_F {
			MagsTurrets[] = {
				{"100Rnd_127x99_mag_Tracer_Red",{0},3,200},
				{"130Rnd_338_Mag",{1},3,260}
			};
		};
		class B_LSV_01_armed_black_F : B_LSV_01_armed_olive_F {};
		class O_T_LSV_02_armed_black_F {
			MagsTurrets[] = {
				{"500Rnd_65x39_Belt_Tracer_Green_Splash",{0},3,500}
			};
		};
		class O_T_LSV_02_armed_ghex_F : O_T_LSV_02_armed_black_F {};
		class B_SDV_01_EPOCH {
			MagsTurrets[] = {
			};
		};
		class B_Heli_Light_01_armed_F {
			MagsTurrets[] = {
				{"5000Rnd_762x51_Belt",{-1},1,1600}
			};
		};
		class O_Heli_Light_02_unarmed_EPOCH {
			MagsTurrets[] = {
				{"168Rnd_CMFlare_Chaff_Magazine",{-1},1,150}
			};
		};
		class O_Heli_Light_02_v2_F {
			MagsTurrets[] = {
				{"2000Rnd_65x39_Belt_Tracer_Green_Splash",{-1},1,1200},
				{"168Rnd_CMFlare_Chaff_Magazine",{-1},1,150}
			};
		};
		class B_Heli_Transport_01_EPOCH {
			MagsTurrets[] = {
				{"168Rnd_CMFlare_Chaff_Magazine",{-1},1,150},
				{"2000Rnd_65x39_Belt_Tracer_Red",{1},1,1200},
				{"2000Rnd_65x39_Belt_Tracer_Red",{2},1,1200}
			};
		};
		class I_Heli_Transport_02_F {
			MagsTurrets[] = {
				{"168Rnd_CMFlare_Chaff_Magazine",{-1},1,150}
			};
		};
		class I_Heli_Transport_02_EPOCH : I_Heli_Transport_02_F {};
		class B_Heli_Transport_03_F {
			MagsTurrets[] = {
				{"168Rnd_CMFlare_Chaff_Magazine",{-1},1,150},
				{"2000Rnd_65x39_Belt_Tracer_Red",{1},1,1200},
				{"2000Rnd_65x39_Belt_Tracer_Red",{2},1,1200}
			};
		};
		class B_Heli_Transport_03_black_F : B_Heli_Transport_03_F {};
		class B_Heli_Transport_03_unarmed_EPOCH {
			MagsTurrets[] = {
				{"168Rnd_CMFlare_Chaff_Magazine",{-1},1,150}
			};
		};
		class I_Heli_light_03_unarmed_EPOCH {
			MagsTurrets[] = {
				{"168Rnd_CMFlare_Chaff_Magazine",{-1},1,150}
			};
		};
		class B_T_VTOL_01_vehicle_blue_F {
			MagsTurrets[] = {
				{"240Rnd_CMFlare_Chaff_Magazine",{-1},1,150}
			};
		};
		class B_T_VTOL_01_infantry_olive_F : B_T_VTOL_01_vehicle_blue_F {};
		class B_T_VTOL_01_infantry_blue_F : B_T_VTOL_01_vehicle_blue_F {};
		class O_T_VTOL_02_vehicle_F {
			MagsTurrets[] = {
				{"168Rnd_CMFlare_Chaff_Magazine",{-1},1,150}
			};
		};
		class O_T_VTOL_02_vehicle_grey_F : O_T_VTOL_02_vehicle_F {};
		class O_T_VTOL_02_infantry_F : O_T_VTOL_02_vehicle_F {};
		class B_Heli_Attack_01_F {
			MagsTurrets[] = {
				{"240Rnd_CMFlare_Chaff_Magazine",{-1},1,150}
			};
		};
		class O_Heli_Attack_02_black_F {
			MagsTurrets[] = {
				{"192Rnd_CMFlare_Chaff_Magazine",{-1},1,150}
			};
		};
		class O_Heli_Attack_02_F : O_Heli_Attack_02_black_F {};
		class O_Boat_Armed_01_hmg_F {
			MagsTurrets[] = {
				{"SmokeLauncherMag_boat",{-1},1,100},
				{"200Rnd_127x99_mag_Tracer_Green",{1},3,300}
			};
		};
		class mosquito_epoch_armedG {
			MagsTurrets[] = {
                {"3Rnd_MosquitoGrenade",{-1},1,60}
			};
        };
	};
};
