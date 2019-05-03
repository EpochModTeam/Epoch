class CfgPainting {
	class DefaultVehicle 
	{
		UseArmaDefaultColors = "true";
		PaintingCosts = 500;
		icon = "x\addons\a3_epoch_code\Data\UI\buttons\Paint.paa";
	};
};

/*
############################ Start Full Example #################################
class CfgPainting {
	class DefaultVehicle 
	{
		UseArmaDefaultColors = "true";									// Use all availabe default colours from Arma (for all Vehicles)
		PaintingCosts = 500;											// Crypto costs for Painting
		icon = "x\addons\a3_epoch_code\Data\UI\buttons\Paint.paa";		// Icon for the DynaMenu
		
		class Pink														// Define custom colors for ALL Vehicle classes within "DefaultVehicle"
		{
			ColorName = "Pink";											// Will be used as Tooltip in DynaMenu
			iconcolor[] = {1,0.0784,0.576,1};							// Color for the Icon [R,G,B,ALPHA] (0-1)
			textures[] = {												// Texture array. Use "#(rgb,8,8,3)color(R,G,B,1)" for simple colors
				"#(rgb,8,8,3)color(1,0.0784,0.576,1)"					// Texture for first selection (most vehicles only need one selection texture)
			};
		};
	};
	class C_Hatchback_01_EPOCH : DefaultVehicle							// Define custom colors for a unique Vehicle Class
	{
		UseArmaDefaultColors = "true";									// Use also all availabe default colours from Arma (for this Vehicle Class)
		class Green
		{3
			ColorName = "Green";
			iconcolor[] = {0,1,0,1};
			textures[] = {
				"#(rgb,8,8,3)color(0,1,0,1)"
			};
		};
	};
	class C_Hatchback_01_EPOCH1: C_Hatchback_01_EPOCH{};				// Inherit classes from already defined classes like this
	class C_Hatchback_01_EPOCH2: C_Hatchback_01_EPOCH{};
	class C_Quadbike_01_EPOCH : DefaultVehicle
	{
		UseArmaDefaultColors = "false";									// This Quad can only be colored with the defined color(s)
		class Black
		{
			ColorName = "Black";
			iconcolor[] = {0,0,0,1};
			textures[] = {
				"\A3\Soft_F_Beta\Quadbike_01\Data\Quadbike_01_CIV_BLACK_CO.paa",
				"\A3\Soft_F_Beta\Quadbike_01\Data\Quadbike_01_wheel_CIVBLACK_CO.paa"
			};
		};
	};
};
############################ End Full Example #################################
*/