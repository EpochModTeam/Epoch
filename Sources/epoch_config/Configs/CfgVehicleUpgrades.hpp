/*
    @author = "Aaron Clark - https://EpochMod.com";
    @contributors[] = {"DirtySanchez"};
    @description = "Vehicle Upgrade configs";
    @licence = "Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike";
    @github = "https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_config/Configs/CfgItemInteractions.hpp";
*/
class CfgVehicleUpgrades
{
	class C_Hatchback_01_EPOCH
	{
		ReqMaterials[] = {{1,"ItemVehDoc1"},{1,"ItemCables"},{1,"CircuitParts"},{2,"VehicleRepairLg"}};
		upgradeToVehicle = "C_Hatchback_01_EPOCH1";
	};
	class C_Hatchback_01_EPOCH1
	{
		ReqMaterials[] = {{1,"ItemVehDoc2"},{2,"SpareTire"},{2,"KitTankTrap"}};
		upgradeToVehicle = "C_Hatchback_01_EPOCH2";
	};
	class C_Hatchback_01_EPOCH2
	{
		ReqMaterials[] = {{1,"ItemVehDoc3"},{2,"ItemPipe"},{2,"KitShelf"}};
		upgradeToVehicle = "C_Hatchback_01_EPOCH3";
	};
	class C_Hatchback_01_EPOCH3
	{
		ReqMaterials[] = {{1,"ItemVehDoc4"},{1,"CircuitParts"},{2,"ItemScraps"},{1,"jerrycan_epoch"}};
		upgradeToVehicle = "C_Hatchback_01_EPOCH4";
	};
	class C_Hatchback_02_EPOCH
	{
		ReqMaterials[] = {{1,"ItemVehDoc1"},{1,"ItemCables"},{1,"CircuitParts"},{2,"VehicleRepairLg"}};
		upgradeToVehicle = "C_Hatchback_02_EPOCH1";
	};
	class C_Hatchback_02_EPOCH1
	{
		ReqMaterials[] = {{1,"ItemVehDoc2"},{2,"SpareTire"},{2,"KitTankTrap"}};
		upgradeToVehicle = "C_Hatchback_02_EPOCH2";
	};
	class C_Hatchback_02_EPOCH2
	{
		ReqMaterials[] = {{1,"ItemVehDoc3"},{2,"ItemPipe"},{2,"KitShelf"}};
		upgradeToVehicle = "C_Hatchback_02_EPOCH3";
	};
	class C_Hatchback_02_EPOCH3
	{
		ReqMaterials[] = {{1,"ItemVehDoc4"},{1,"CircuitParts"},{2,"ItemScraps"},{1,"jerrycan_epoch"}};
		upgradeToVehicle = "C_Hatchback_02_EPOCH4";
	};
	class C_Offroad_01_EPOCH
    {
		upgradeReqItems[] = {{1,"ItemVehDoc1"},{1,"ItemCables"},{1,"CircuitParts"},{2,"VehicleRepairLg"}};
		upgradeToVehicle = "C_Offroad_01_EPOCH1";
	};
	class C_Offroad_01_EPOCH1
	{
		ReqMaterials[] = {{1,"ItemVehDoc2"},{2,"SpareTire"},{2,"KitTankTrap"}};
		upgradeToVehicle = "C_Offroad_01_EPOCH2";
	};
	class C_Offroad_01_EPOCH2
	{
		ReqMaterials[] = {{1,"ItemVehDoc3"},{2,"ItemPipe"},{2,"KitShelf"}};
		upgradeToVehicle = "C_Offroad_01_EPOCH3";
	};
	class C_Offroad_01_EPOCH3
	{
		ReqMaterials[] = {{1,"ItemVehDoc4"},{1,"CircuitParts"},{2,"ItemScraps"},{1,"jerrycan_epoch"}};
		upgradeToVehicle = "C_Offroad_01_EPOCH4";
	};
	class C_SUV_01_EPOCH
	{
		upgradeReqItems[] = {{1,"ItemVehDoc1"},{1,"ItemCables"},{1,"CircuitParts"},{2,"VehicleRepairLg"}};
		upgradeToVehicle = "C_SUV_01_EPOCH1";
	};
	class C_SUV_01_EPOCH1
	{
		ReqMaterials[] = {{1,"ItemVehDoc2"},{2,"SpareTire"},{2,"KitTankTrap"}};
		upgradeToVehicle = "C_SUV_01_EPOCH2";
	};
	class C_SUV_01_EPOCH2
	{
		ReqMaterials[] = {{1,"ItemVehDoc3"},{2,"ItemPipe"},{2,"KitShelf"}};
		upgradeToVehicle = "C_SUV_01_EPOCH3";
	};
	class C_SUV_01_EPOCH3
	{
		ReqMaterials[] = {{1,"ItemVehDoc4"},{1,"CircuitParts"},{2,"ItemScraps"},{1,"jerrycan_epoch"}};
		upgradeToVehicle = "C_SUV_01_EPOCH4";
	};
	class B_G_Offroad_01_armed_EPOCH
	{
		upgradeReqItems[] = {{1,"ItemVehDoc1"},{1,"ItemCables"},{1,"CircuitParts"},{2,"VehicleRepairLg"}};
		upgradeToVehicle = "B_G_Offroad_01_armed_EPOCH1";
	};
	class B_G_Offroad_01_armed_EPOCH1
	{
		ReqMaterials[] =  {{1,"ItemVehDoc2"},{2,"SpareTire"},{2,"KitTankTrap"}};
		upgradeToVehicle = "B_G_Offroad_01_armed_EPOCH2";
	};
	class B_G_Offroad_01_armed_EPOCH2
	{
		ReqMaterials[] = {{1,"ItemVehDoc3"},{2,"ItemPipe"},{2,"KitShelf"}};
		upgradeToVehicle = "B_G_Offroad_01_armed_EPOCH3";
	};
	class B_G_Offroad_01_armed_EPOCH3
	{
		ReqMaterials[] = {{1,"ItemVehDoc4"},{1,"CircuitParts"},{2,"ItemScraps"},{1,"jerrycan_epoch"}};
		upgradeToVehicle = "B_G_Offroad_01_armed_EPOCH4";
	};
};
