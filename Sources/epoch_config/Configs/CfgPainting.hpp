class CfgPainting {
	class DefaultVehicle 
	{
		UseArmaDefaultColors = "true";			// Use all availabe default colours from Arma
		PaintingCosts = 500;
		icon = "x\addons\a3_epoch_code\Data\UI\buttons\Paint.paa";
		class Pink								// Colour will be available for ALL Vehicles
		{
			ColorName = "Pink";
			iconcolor[] = {1,0.0784,0.576,1};
			textures[] = {
				"#(rgb,8,8,3)color(1,0.0784,0.576,1)"
			};
		};
	};
/* // Define custom colours for each Type like this
    class C_Hatchback_01_EPOCH : DefaultVehicle
	{
		UseArmaDefaultColors = "true";			// Use all availabe default colours from Arma
		class Green
		{
			ColorName = "Green";
			iconcolor[] = {0,1,0,1};
			textures[] = {
				"#(rgb,8,8,3)color(0,1,0,1)"
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
*/
};