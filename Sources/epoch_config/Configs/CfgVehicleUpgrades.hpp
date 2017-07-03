/*
    @author = "Aaron Clark - https://EpochMod.com";
    @contributors[] = {"DirtySanchez"};
    @description = "Vehicle Upgrade configs";
    @licence = "Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike";
    @github = "https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_config/Configs/CfgItemInteractions.hpp";
*/
class CfgVehicleUpgrades
{
	class ItemVehDoc1
	{
		class C_Hatchback_01_EPOCH
		{
			ReqMaterials[] = {{1,"ItemVehDoc1"},{1,"ItemCables"},{1,"CircuitParts"},{2,"VehicleRepairLg"}};
			upgradeToVehicle = "C_Hatchback_01_EPOCH1";
		};
		class C_Hatchback_02_EPOCH: C_Hatchback_01_EPOCH
		{
			upgradeToVehicle = "C_Hatchback_02_EPOCH1";
		};
		class C_Offroad_01_EPOCH: C_Hatchback_01_EPOCH
		{
			upgradeToVehicle = "C_Offroad_01_EPOCH1";
		};
		class C_SUV_01_EPOCH: C_Hatchback_01_EPOCH
		{
			upgradeToVehicle = "C_SUV_01_EPOCH1";
		};
	};
	class ItemVehDoc2
	{
		class C_Hatchback_01_EPOCH1
		{
			ReqMaterials[] = {{1,"ItemVehDoc2"},{2,"SpareTire"},{2,"KitTankTrap"}};
			upgradeToVehicle = "C_Hatchback_01_EPOCH2";
		};
		class C_Hatchback_02_EPOCH1: C_Hatchback_01_EPOCH1
		{
			upgradeToVehicle = "C_Hatchback_02_EPOCH2";
		};
		class C_Offroad_01_EPOCH1: C_Hatchback_01_EPOCH1
		{
			upgradeToVehicle = "C_Offroad_01_EPOCH2";
		};
		class C_SUV_01_EPOCH1: C_Hatchback_01_EPOCH1
		{
			upgradeToVehicle = "C_SUV_01_EPOCH2";
		};
	};
	class ItemVehDoc3
	{
		class C_Hatchback_01_EPOCH2
		{
			ReqMaterials[] = {{1,"ItemVehDoc3"},{2,"ItemPipe"},{2,"KitShelf"}};
			upgradeToVehicle = "C_Hatchback_01_EPOCH3";
		};
		class C_Hatchback_02_EPOCH2: C_Hatchback_01_EPOCH2
		{
			upgradeToVehicle = "C_Hatchback_02_EPOCH3";
		};
		class C_Offroad_01_EPOCH2: C_Hatchback_01_EPOCH2
		{
			upgradeToVehicle = "C_Offroad_01_EPOCH3";
		};
		class C_SUV_01_EPOCH2: C_Hatchback_01_EPOCH2
		{
			upgradeToVehicle = "C_SUV_01_EPOCH3";
		};
	};
	class ItemVehDoc4
	{
		class C_Hatchback_01_EPOCH3
		{
			ReqMaterials[] = {{1,"ItemVehDoc3"},{2,"ItemPipe"},{2,"KitShelf"}};
			upgradeToVehicle = "C_Hatchback_01_EPOCH4";
		};
		class C_Hatchback_02_EPOCH3: C_Hatchback_01_EPOCH3
		{
			upgradeToVehicle = "C_Hatchback_02_EPOCH4";
		};
		class C_Offroad_01_EPOCH3: C_Hatchback_01_EPOCH3
		{
			upgradeToVehicle = "C_Offroad_01_EPOCH4";
		};
		class C_SUV_01_EPOCH3: C_Hatchback_01_EPOCH3
		{
			upgradeToVehicle = "C_SUV_01_EPOCH4";
		};
	};
};