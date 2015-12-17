/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Epoch gamemode server Side map specific configs for stratis.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server_settngs/configs/maps/stratis.h
*/
class Stratis : Default
{
	worldSize = 6000;
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
	containerPos[] = {
			{ 2583.59, 6024.51, 0 },
			{ 3830.73, 7823.08, 0 },
			{ 5153.42, 7048.41, 0 },
			{ 6871.89, 5628.74, 0 },
			{ 4429.52, 2354.84, 0 },
			{ 2907.18, 543.774, 0 },
			{ 2213.17, 1095.78, 0 },
			{ 1663.35, 2728.73, 0 },
			{ 1661.67, 2861.41, 0 },
			{ 1646.04, 2882.86, 0 },
			{ 1748.63, 3488.93, 0 },
			{ 1461.86, 4783.48, 0 }
	};
	telePos[] = {

		// N [-0.286865,8.17383,-10.3098]
		// S [-0.415527,-7.05298,-10.3098]
		// E [13.5127,0.410156,-10.3098]
		// W [-14.4316,0.112793,-10.3098]

			{ "Transport_C_EPOCH", { -0.286865, 8.17383, -10.3098 }, "", { 4089.82, 4597.71, 0.00143433 } }
	};
	propsPos[] = {
			{ "Land_Castle_01_wall_08_F", { 1830.55, 3389.67, 0 }, 285.304 },
			{ "Land_Castle_01_tower_F", { 1852.1, 3361.42, 1.51087 }, 283.624 },
			{ "Land_Stone_HouseBig_V1_ruins_F", { 1877.76, 2747.02, 0.58992 }, 350.47 },
			{ "Land_Research_house_V1_F", { 1882.16, 3420.11, 0 }, 114.473 },
			{ "Land_Research_house_V1_F", { 1926.81, 3483.25, 0 }, 78.3937 },
			{ "Land_Research_house_V1_F", { 1981.81, 3454.27, 0 }, 114.473 },
			{ "Land_Swing_01_F", { 1985.26, 4154.77, 0.000238657 }, 0 },
			{ "Land_LifeguardTower_01_F", { 1984.14, 4165.94, 0.0106359 }, 96.173 },
			{ "Land_i_House_Small_02_V1_F", { 2038.01, 4155.31, -2.38419e-007 }, 104.737 },
			{ "Land_d_House_Small_02_V1_F", { 2078.54, 4114.41, 2.38419e-007 }, 0 },
			{ "Land_Offices_01_V1_F", { 2057.75, 5451.7, 4.76837e-007 }, 282.813 },
			{ "Land_Hospital_side1_F", { 2058.38, 5592.42, 0 }, 192.575 },
			{ "Land_Hospital_main_F", { 2070.05, 5623.08, 0 }, 192.575 },
			{ "Land_i_House_Big_01_V3_F", { 2086.85, 4150.62, 0 }, 107.808 },
			{ "Land_Kiosk_papers_F", { 2093.64, 5570.47, 6.53267e-005 }, 283.475 },
			{ "Land_Hospital_side2_F", { 2099.4, 5626.81, 0 }, 192.575 },
			{ "Land_Slum_House03_F", { 2141.66, 4792.06, 0.0015676 }, 0 },
			{ "Land_Slum_House02_F", { 2143.03, 4775.16, -0.0263515 }, 0 },
			{ "Land_Kiosk_blueking_F", { 2727.62, 5826.22, 0.000421524 }, 132.967 },
			{ "Land_d_House_Small_01_V1_F", { 2801.58, 1046.55, 0 }, 41.0052 },
			{ "Land_Chapel_V1_F", { 2871.78, 6067.89, 0 }, 211.514 },
			{ "Land_Cargo_HQ_V3_F", { 2971.3, 1866.99, 0 }, 179.108 },
			{ "Land_u_House_Small_01_V1_F", { 2973.94, 6218.94, 0.325663 }, 0 },
			{ "Land_Cargo_House_V3_F", { 2995.03, 1873.41, 1.52588e-005 }, 0 },
			{ "Land_i_Garage_V2_F", { 2989, 6223.63, -1.90735e-006 }, 273.954 },
			{ "Land_i_House_Big_01_V1_F", { 3049.42, 5942.24, 2.38419e-007 }, 311.557 },
			{ "Land_Kiosk_redburger_F", { 3044.55, 6076.2, 9.44138e-005 }, 91.6749 },
			{ "Land_i_House_Small_02_V3_F", { 3155.17, 6013.37, 0.458257 }, 332.154 },
			{ "Land_Chapel_V2_F", { 3232.37, 6857.66, 0.685185 }, 272.76 },
			{ "Land_cargo_house_slum_F", { 3538.77, 2707.56, 0 }, 177.058 },
			{ "Land_cargo_addon01_V1_F", { 3541.2, 2705.14, 0 }, 357.446 },
			{ "Land_d_Stone_HouseBig_V1_F", { 3623.09, 5245.06, 0.009758 }, 166.481 },
			{ "Land_d_House_Small_01_V1_F", { 3743.54, 4780.82, 1.57976 }, 0 },
			{ "Land_Slum_House03_F", { 3797.53, 2993.58, 0 }, 0 },
			{ "Land_Slum_House02_F", { 3831.47, 2971.8, 0 }, 0 },
			{ "Land_HelipadCircle_F", { 4067.47, 4572.62, 1.52588e-005 }, 359.244 },
			{ "Land_TouristShelter_01_F", { 4073.64, 4549.6, 0 }, 192.51 },
			{ "Land_cargo_addon02_V1_F", { 4078.63, 4592.18, 0 }, 0 },
			{ "Land_Loudspeakers_F", { 4092.04, 4598.9, 0 }, 0 },
			{ "Land_ScrapHeap_1_F", { 4079.07, 4596.36, 0.00553894 }, 99.9798 },
			{ "Land_CncBarrierMedium4_F", { 4079.99, 4588.74, 0.0153656 }, 359.686 },
			{ "Land_CncWall4_F", { 4089.64, 4588.13, -0.00886536 }, 12.7799 },
			{ "Land_CncWall4_F", { 4094.76, 4586.89, -0.00213623 }, 12.7868 },
			{ "Land_LampShabby_F", { 4076.45, 4589.55, 0 }, 121.571 },
			{ "Land_BC_Basket_F", { 4078.18, 4602.15, 1.52588e-005 }, 106.029 },
			{ "Land_InvisibleBarrier_F", { 4075.89, 4589.43, 0.753189 }, 201.944 },
			{ "Land_InvisibleBarrier_F", { 4075.31, 4596.73, 1.33836 }, 120.492 },
			{ "Land_InvisibleBarrier_F", { 4075.13, 4590.7, 1.13405 }, 81.5166 },
			{ "Land_InvisibleBarrier_F", { 4076.48, 4600.02, 1.22104 }, 115.878 },
			{ "Land_InvisibleBarrier_F", { 4078.54, 4604.28, 1.28917 }, 115.887 },
			{ "Land_InvisibleBarrier_F", { 4075.15, 4594.21, 1.20979 }, 96.9556 },
			{ "Land_InvisibleBarrier_F", { 4080.46, 4607.96, 1.49496 }, 115.887 },
			{ "Land_CncBarrierMedium_F", { 4085.46, 4589.37, 0.00686646 }, 359.902 },
			{ "Land_Garbage_square3_F", { 4081.92, 4590.14, 0.0126038 }, 359.751 },
			{ "Land_Garbage_square3_F", { 4087.47, 4605.58, 0 }, 0 },
			{ "Land_Campfire_F", { 4087.44, 4605.57, 0 }, 359.692 },
			{ "Land_HBarrier_1_F", { 4073.01, 4589.24, 0.00802612 }, 196.111 },
			{ "Land_HBarrier_1_F", { 4074.2, 4587.82, 0.0124664 }, 104.304 },
			{ "Land_WoodenTable_large_F", { 4080.83, 4591.95, -0.00935364 }, 359.965 },
			{ "Land_Bench_01_F", { 4090.86, 4589.01, 0 }, 187.798 },
			{ "Land_Graffiti_03_F", { 4090.15, 4587.4, 2.04541 }, 13.1322 },
			{ "Land_Tyre_F", { 4077.24, 4593.93, -0.0040741 }, 359.906 },
			{ "Land_cargo_addon02_V2_F", { 4088.04, 4609.67, 0.864685 }, 0 },
			{ "Land_CncWall4_F", { 4095.45, 4610.17, 0 }, 19.8004 },
			{ "Flag_US_F", { 4083.69, 4609.71, 0 }, 0 },
			{ "Land_InvisibleBarrier_F", { 4090.66, 4611.46, 1.21396 }, 181.969 },
			{ "Land_InvisibleBarrier_F", { 4083.03, 4610.92, 1.30064 }, 155.064 },
			{ "Land_InvisibleBarrier_F", { 4085.83, 4611.93, 1.50397 }, 181.969 },
			{ "Land_GarbageContainer_open_F", { 4093.96, 4612.7, 1.52588e-005 }, 14.0197 },
			{ "Land_Sun_chair_F", { 4089.87, 4609.37, 0.0206299 }, 230.807 },
			{ "Land_WoodenTable_small_F", { 4087.48, 4609.82, 0 }, 0.0139882 },
			{ "Land_ChairPlastic_F", { 4085.61, 4609.59, 4.57764e-005 }, 56.7009 },
			{ "Land_PartyTent_01_F", { 4102.91, 4597.95, 0 }, 99.5276 },
			{ "Land_spp_Mirror_F", { 4116.51, 4586.74, 0.00367737 }, 123.312 },
			{ "Land_spp_Mirror_Broken_F", { 4112.67, 4580.57, 0.0202332 }, 125.593 },
			{ "Land_CncWall4_F", { 4106.1, 4604.81, -0.00102234 }, 19.7979 },
			{ "Land_LampShabby_F", { 4096.18, 4607.97, 0 }, 206.995 },
			{ "Land_LampShabby_F", { 4097.33, 4587.92, 0.0244751 }, 31.518 },
			{ "Land_InvisibleBarrier_F", { 4109.2, 4597.37, 1.52361 }, 277.612 },
			{ "Land_InvisibleBarrier_F", { 4108.27, 4592.6, 1.73965 }, 277.612 },
			{ "Land_InvisibleBarrier_F", { 4109.82, 4601.67, 1.56946 }, 277.612 },
			{ "Land_InvisibleBarrier_F", { 4107.04, 4586.27, 1.85316 }, 319.546 },
			{ "Land_InvisibleBarrier_F", { 4104.05, 4585.58, 1.68684 }, 7.11481 },
			{ "Land_InvisibleBarrier_F", { 4099.71, 4585.46, 1.77679 }, 2.57549 },
			{ "Land_WorkStand_F", { 4099.94, 4600.94, -1.52588e-005 }, 295.919 },
			{ "Land_WaterTank_F", { 4104.34, 4589.11, 0.0553589 }, 268.9 },
			{ "Land_CncBarrierMedium_F", { 4102.32, 4607.87, -6.10352e-005 }, 227.793 },
			{ "Land_Garbage_square3_F", { 4097.21, 4596.75, 0 }, 0 },
			{ "Land_PowerGenerator_F", { 4102.48, 4603.53, 0 }, 195.669 },
			{ "Land_PortableLight_double_F", { 4106.97, 4601.45, 1.52588e-005 }, 54.431 },
			{ "Land_CargoBox_V1_F", { 4105.27, 4594.12, 0.0321808 }, 359.692 },
			{ "Land_HBarrier_1_F", { 4108.91, 4587.86, 0.0543213 }, 190.858 },
			{ "Land_HBarrier_1_F", { 4104.23, 4584.41, 0.0659485 }, 102.162 },
			{ "Land_HBarrier_1_F", { 4105.92, 4584.86, 0.0720825 }, 91.1097 },
			{ "Land_HBarrier_1_F", { 4108.57, 4586.13, 0.00216675 }, 192.397 },
			{ "Land_HBarrier_1_F", { 4107.47, 4584.94, 0.060257 }, 102.162 },
			{ "Land_HBarrier_1_F", { 4102.35, 4584.26, 0.0769043 }, 102.051 },
			{ "Land_HBarrier_1_F", { 4109.11, 4589.47, 0.11763 }, 9.99734 },
			{ "Land_PaperBox_open_full_F", { 4102.1, 4594.33, 1.52588e-005 }, 263.73 },
			{ "Land_PaperBox_open_empty_F", { 4105.48, 4596.11, -0.0014801 }, 0 },
			{ "Land_Cages_F", { 4105.58, 4591.83, 0.0664368 }, 185.048 },
			{ "Land_CncBarrier_F", { 4097.61, 4596.8, 0 }, 99.6326 },
			{ "Land_CncBarrier_F", { 4100.22, 4593.2, 3.05176e-005 }, 190.22 },
			{ "Land_CampingTable_F", { 4101.72, 4596.48, 0.00106812 }, 281.325 },
			{ "Land_BagFence_Corner_F", { 4097.22, 4593.88, 0.0379028 }, 190.245 },
			{ "Land_CratesPlastic_F", { 4103.75, 4593.7, -0.000549316 }, 359.881 },
			{ "Land_Axe_F", { 4099.65, 4600.64, -0.00337219 }, 295.967 },
			{ "Land_Bucket_F", { 4097.32, 4594.08, 6.10352e-005 }, 356.543 },
			{ "Land_ToiletBox_F", { 4096.96, 4611.27, 0.000183105 }, 289.938 },
			{ "Land_CncBarrierMedium_F", { 4099.65, 4608.55, 0 }, 359.899 },
			{ "Land_Research_HQ_F", { 4380.18, 3823.79, 0 }, 355.975 },
			{ "Land_Unfinished_Building_01_F", { 4649.67, 5884.08, 0.293839 }, 198.291 },
			{ "Land_Unfinished_Building_02_F", { 5174.01, 5007.38, 0 }, 243.495 },
			{ "Land_i_Stone_HouseBig_V3_F", { 5498.5, 4727.75, -0.0115128 }, 293.658 },
			{ "Land_i_Stone_Shed_V2_F", { 5505.49, 4702.41, 0.00200653 }, 297.882 },
			{ "Land_i_Stone_HouseSmall_V1_F", { 5981.14, 4959.02, 0 }, 9.37543 },
			{ "Land_i_Stone_Shed_V3_F", { 6023.49, 4945.2, 0 }, 176.441 },
			{ "Land_WIP_F", { 6366.69, 5475.46, 0 }, 130.712 },
			{ "Land_BC_Court_F", { 6419.24, 5433.65, 0.43597 }, 223.519 },
			{ "Land_BC_Basket_F", { 6411.08, 5425.05, -4.76837e-007 }, 44.4966 },
			{ "Land_BC_Basket_F", { 6427.29, 5442.33, 4.76837e-007 }, 223.664 },
			{ "ProtectionZone_Invisible_F", { 4079.01, 4573.1, 0.0611725 }, 359.768 },
			// Coastline trader
			{ "Land_LightHouse_F", { 1845.07, 2988.35, -1.90735e-006 }, 0 },
			{ "Land_HelipadEmpty_F", { 1882.75, 2942.03, 1.42167 }, 358.907 },
			{ "Land_Pier_small_F", { 1891.08, 2938.65, -2.98023e-007 }, 56.3395 },
			{ "Land_RowBoat_V2_F", { 1909.67, 2941.81, 0.0138569 }, 2.33694 },
			{ "Land_WorkStand_F", { 1908.58, 2944.58, -0.020708 }, 122.503 },
			{ "Land_CargoBox_V1_F", { 1907.39, 2947.01, 0.0350925 }, 359.867 },
			{ "Land_Axe_F", { 1908.74, 2945.41, -0.00328684 }, 359.986 },
			{ "Land_ToiletBox_F", { 1913.84, 2986.91, 0.0251269 }, 349.174 },
			{ "Land_BeachBooth_01_F", { 1907.22, 2978.81, -0.00382352 }, 55.1352 },
			{ "Land_TentDome_F", { 1937.39, 2959.15, -0.0218604 }, 326.44 },
			{ "Land_Campfire_F", { 1933.14, 2949.95, -0.00123048 }, 359.804 },
			{ "Land_Sun_chair_F", { 1933.75, 2952.72, 0.0220282 }, 197.997 },
			{ "ProtectionZone_Invisible_F", { 1912.9, 2950.53, 0.0313282 }, 359.93 }
	};
	staticNpcPos[] = {
			{ "C_man_hunter_1_F", { 4079.2, 4592.1, 0.00123596 }, 358.384 },
			{ "C_man_w_worker_F", { 4103, 4595.83, 0.00146484 }, 265.753 },
			// Coastline trader
			{ "C_man_shorts_4_F_asia", { 1899.42, 2944, 0.500793 }, 255.304 }
	};
};
