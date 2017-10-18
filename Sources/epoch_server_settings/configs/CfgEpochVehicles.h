/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Epoch Server side config to persist vehicle colors, these are also used to randomly colorize new spawns.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server_settngs/configs/CfgEpochVehicles.h
*/
class CfgEpochVehicles
{
    class C_Hatchback_01_EPOCH {
        textureSelectionIndex[] = {0};
		availableColors[] = {{ "\A3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_CO.paa","\A3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_BASE01_CO.paa","\A3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_BASE02_CO.paa","\A3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_BASE03_CO.paa","\A3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_BASE04_CO.paa","\A3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_BASE05_CO.paa","\A3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_BASE06_CO.paa","\A3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_BASE07_CO.paa","\A3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_BASE08_CO.paa","\A3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_BASE09_CO.paa" }};
    };
	class C_Hatchback_01_EPOCH1: C_Hatchback_01_EPOCH{};
	class C_Hatchback_01_EPOCH2: C_Hatchback_01_EPOCH{};
	class C_Hatchback_01_EPOCH3: C_Hatchback_01_EPOCH{};
	class C_Hatchback_01_EPOCH4: C_Hatchback_01_EPOCH{};
    class C_Offroad_01_EPOCH {
        textureSelectionIndex[] = {0,1};
		availableColors[] = {{ "\A3\soft_F\Offroad_01\Data\Offroad_01_ext_co.paa","\A3\soft_F\Offroad_01\Data\Offroad_01_ext_BASE01_CO.paa","\A3\soft_F\Offroad_01\Data\Offroad_01_ext_BASE02_CO.paa","\A3\soft_F\Offroad_01\Data\Offroad_01_ext_BASE03_CO.paa","\A3\soft_F\Offroad_01\Data\Offroad_01_ext_BASE04_CO.paa","\A3\soft_F\Offroad_01\Data\Offroad_01_ext_BASE05_CO.paa" }};
    };
	class C_Offroad_01_EPOCH1: C_Offroad_01_EPOCH{};
	class C_Offroad_01_EPOCH2: C_Offroad_01_EPOCH{};
	class C_Offroad_01_EPOCH3: C_Offroad_01_EPOCH{};
	class C_Offroad_01_EPOCH4: C_Offroad_01_EPOCH{};
    class C_SUV_01_EPOCH {
        textureSelectionIndex[] = {0};
		availableColors[] = {{ "\A3\Soft_F_Gamma\SUV_01\Data\SUV_01_ext_CO.paa","\A3\Soft_F_Gamma\SUV_01\Data\SUV_01_ext_02_CO.paa","\A3\Soft_F_Gamma\SUV_01\Data\SUV_01_ext_03_CO.paa","\A3\Soft_F_Gamma\SUV_01\Data\SUV_01_ext_04_CO.paa" }};
    };
	class C_SUV_01_EPOCH1: C_SUV_01_EPOCH{};
	class C_SUV_01_EPOCH2: C_SUV_01_EPOCH{};
	class C_SUV_01_EPOCH3: C_SUV_01_EPOCH{};
	class C_SUV_01_EPOCH4: C_SUV_01_EPOCH{};
    class C_Van_01_transport_EPOCH {
        textureSelectionIndex[] = {0};
        availableColors[] = {{ "\A3\soft_f_gamma\van_01\Data\van_01_ext_CO.paa","\A3\soft_f_gamma\van_01\Data\van_01_ext_red_CO.paa" }};
    };
    class C_Hatchback_02_EPOCH {
        textureSelectionIndex[] = {0};
		availableColors[] = {{ "\A3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_SPORT01_CO.paa","\A3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_SPORT02_CO.paa","\A3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_SPORT03_CO.paa","\A3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_SPORT04_CO.paa","\A3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_SPORT05_CO.paa","\A3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_SPORT06_CO.paa" }};
    };
	class C_Hatchback_02_EPOCH1: C_Hatchback_02_EPOCH{};
	class C_Hatchback_02_EPOCH2: C_Hatchback_02_EPOCH{};
	class C_Hatchback_02_EPOCH3: C_Hatchback_02_EPOCH{};
	class C_Hatchback_02_EPOCH4: C_Hatchback_02_EPOCH{};
    class C_Quadbike_01_EPOCH {
        textureSelectionIndex[] = {0,1};
		availableColors[] = {{ "\A3\Soft_F_Beta\Quadbike_01\Data\Quadbike_01_CIV_BLACK_CO.paa","\A3\Soft_F_Beta\Quadbike_01\Data\Quadbike_01_CIV_BLUE_CO.paa","\A3\Soft_F_Beta\Quadbike_01\Data\Quadbike_01_CIV_RED_CO.paa","\A3\Soft_F_Beta\Quadbike_01\Data\Quadbike_01_CIV_WHITE_CO.paa" },{ "\A3\Soft_F_Beta\Quadbike_01\Data\Quadbike_01_wheel_CIVBLACK_CO.paa","\A3\Soft_F_Beta\Quadbike_01\Data\Quadbike_01_wheel_CIVBLUE_CO.paa","\A3\Soft_F_Beta\Quadbike_01\Data\Quadbike_01_wheel_CIVRED_CO.paa","\A3\Soft_F_Beta\Quadbike_01\Data\Quadbike_01_wheel_CIVWHITE_CO.paa" }};
    };
    class C_Van_01_box_EPOCH {
        textureSelectionIndex[] = {0};
        availableColors[] = {{ "\A3\soft_f_gamma\van_01\Data\van_01_ext_CO.paa","\A3\soft_f_gamma\van_01\Data\van_01_ext_red_CO.paa" }};
    };
    class C_Heli_Light_01_civil_EPOCH {
        textureSelectionIndex[] = { 0 };
        availableColors[] = { { "A3\Air_f\Heli_Light_01\Data\Heli_Light_01_ext_co.paa", "\a3\air_f\Heli_Light_01\Data\heli_light_01_ext_blue_co.paa", "\a3\air_f\Heli_Light_01\Data\heli_light_01_ext_co.paa", "\a3\air_f\Heli_Light_01\Data\heli_light_01_ext_ion_co.paa", "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_blueLine_co.paa", "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_digital_co.paa", "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_elliptical_co.paa", "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_furious_co.paa", "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_graywatcher_co.paa", "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_jeans_co.paa", "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_light_co.paa", "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_shadow_co.paa", "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_sheriff_co.paa", "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_speedy_co.paa", "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_sunset_co.paa", "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_vrana_co.paa", "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_wasp_co.paa", "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_wave_co.paa" } };
    };
};
