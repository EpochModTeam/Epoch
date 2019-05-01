class CfgPainting {
	class DefaultVehicle 
	{
		PaintingCosts = 500;
		icon = "x\addons\a3_epoch_code\Data\UI\buttons\Paint.paa";
		class Pink
		{
			ColorName = "Pink";
			iconcolor[] = {1,0.0784,0.576,1};
			textures[] = {
				{0,"#(rgb,8,8,3)color(1,0.0784,0.576,1)"}
			};
		};
	};
    class C_Hatchback_01_EPOCH : DefaultVehicle
	{
		class White
		{
			ColorName = "White";
			iconcolor[] = {1, 1, 1, 1};
			textures[] = {
				{0,"\A3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_CO.paa"}
			};
		};
		class Green
		{
			ColorName = "Green";
			iconcolor[] = {0, 1, 0, 1};
			textures[] = {
				{0,"\A3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_BASE02_CO.paa"}
			};
		};
		class Blue
		{
			ColorName = "Blue";
			iconcolor[] = {0, 0, 1, 1};
			textures[] = {
				{0,"\A3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_BASE04_CO.paa"}
			};
		};
		class Yellow
		{
			ColorName = "Yellow";
			iconcolor[] = {1, 1, 0, 1};
			textures[] = {
				{0,"\A3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_BASE06_CO.paa"}
			};
		};
		class Grey
		{
			ColorName = "Grey";
			iconcolor[] = {0.5, 0.5, 0.5, 1};
			textures[] = {
				{0,"\A3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_BASE07_CO.paa"}
			};
		};
		class Black
		{
			ColorName = "Black";
			iconcolor[] = {0.1, 0.1, 0.1, 1};
			textures[] = {
				{0,"\A3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_BASE09_CO.paa"}
			};
		};
    };
	class C_Hatchback_01_EPOCH1: C_Hatchback_01_EPOCH{};
	class C_Hatchback_01_EPOCH2: C_Hatchback_01_EPOCH{};
	class C_Hatchback_01_EPOCH3: C_Hatchback_01_EPOCH{};
	class C_Hatchback_01_EPOCH4: C_Hatchback_01_EPOCH{};
	class C_Hatchback_02_EPOCH: C_Hatchback_01_EPOCH{};
	class C_Hatchback_02_EPOCH1: C_Hatchback_02_EPOCH{};
	class C_Hatchback_02_EPOCH2: C_Hatchback_02_EPOCH{};
	class C_Hatchback_02_EPOCH3: C_Hatchback_02_EPOCH{};
	class C_Hatchback_02_EPOCH4: C_Hatchback_02_EPOCH{};
    class C_Offroad_01_EPOCH : DefaultVehicle
	{
		class Red
		{
			ColorName = "Red";
			iconcolor[] = {1, 0, 0, 1};
			textures[] = {
				{0,"\A3\soft_F\Offroad_01\Data\Offroad_01_ext_co.paa"}
			};
		};
		class White
		{
			ColorName = "White";
			iconcolor[] = {1, 1, 1, 1};
			textures[] = {
				{0,"\A3\soft_F\Offroad_01\Data\Offroad_01_ext_BASE02_CO.paa"}
			};
		};
		class Blue
		{
			ColorName = "Blue";
			iconcolor[] = {0, 0, 1, 1};
			textures[] = {
				{0,"\A3\soft_F\Offroad_01\Data\Offroad_01_ext_BASE03_CO.paa"}
			};
		};
		class DarkRed
		{
			ColorName = "Dark Red";
			iconcolor[] = {0.8, 0, 0, 1};
			textures[] = {
				{0,"\A3\soft_F\Offroad_01\Data\Offroad_01_ext_BASE04_CO.paa"}
			};
		};
		class BlackWhite
		{
			ColorName = "Black / White";
			iconcolor[] = {0.1, 0.1, 0.1, 1};
			textures[] = {
				{0,"\A3\soft_F\Offroad_01\Data\Offroad_01_ext_BASE05_CO.paa"}
			};
		};
    };
	class C_Offroad_01_EPOCH1: C_Offroad_01_EPOCH{};
	class C_Offroad_01_EPOCH2: C_Offroad_01_EPOCH{};
	class C_Offroad_01_EPOCH3: C_Offroad_01_EPOCH{};
	class C_Offroad_01_EPOCH4: C_Offroad_01_EPOCH{};
    class C_SUV_01_EPOCH : DefaultVehicle
	{
		class Red
		{
			ColorName = "Red";
			iconcolor[] = {1, 0, 0, 1};
			textures[] = {
				{0,"\A3\Soft_F_Gamma\SUV_01\Data\SUV_01_ext_CO.paa"}
			};
		};
		class Black
		{
			ColorName = "Black";
			iconcolor[] = {0.1, 0.1, 0.1, 1};
			textures[] = {
				{0,"\A3\Soft_F_Gamma\SUV_01\Data\SUV_01_ext_02_CO.paa"}
			};
		};
		class White
		{
			ColorName = "White";
			iconcolor[] = {1, 1, 1, 1};
			textures[] = {
				{0,"\A3\Soft_F_Gamma\SUV_01\Data\SUV_01_ext_03_CO.paa"}
			};
		};
		class Orange
		{
			ColorName = "Orange";
			iconcolor[] = {1, 0.9, 0, 1};
			textures[] = {
				{0,"\A3\Soft_F_Gamma\SUV_01\Data\SUV_01_ext_04_CO.paa"}
			};
		};
    };
	class C_SUV_01_EPOCH1: C_SUV_01_EPOCH{};
	class C_SUV_01_EPOCH2: C_SUV_01_EPOCH{};
	class C_SUV_01_EPOCH3: C_SUV_01_EPOCH{};
	class C_SUV_01_EPOCH4: C_SUV_01_EPOCH{};
};