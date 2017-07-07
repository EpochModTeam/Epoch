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
		class C_Hatchback_02_EPOCH: C_Hatchback_01_EPOCH	{	upgradeToVehicle = "C_Hatchback_02_EPOCH1";	};
		class C_Offroad_01_EPOCH: C_Hatchback_01_EPOCH		{	upgradeToVehicle = "C_Offroad_01_EPOCH1";	};
		class C_SUV_01_EPOCH: C_Hatchback_01_EPOCH			{	upgradeToVehicle = "C_SUV_01_EPOCH1";		};
		class B_MRAP_01_EPOCH: C_Hatchback_01_EPOCH			{	upgradeToVehicle = "B_MRAP_01_EPOCH1";		};
		class O_MRAP_02_EPOCH: C_Hatchback_01_EPOCH			{	upgradeToVehicle = "O_MRAP_02_EPOCH1";		};
		class I_MRAP_03_EPOCH: C_Hatchback_01_EPOCH			{	upgradeToVehicle = "I_MRAP_03_EPOCH1";		};
	};
	class KitVehicleUpgradeI_100_EPOCH
	{
		class C_Hatchback_01_EPOCH
		{
			ReqMaterials[] = {{1,"KitVehicleUpgradeI_100_EPOCH"}};
			upgradeToVehicle = "C_Hatchback_01_EPOCH1";
		};
		class C_Hatchback_02_EPOCH: C_Hatchback_01_EPOCH	{	upgradeToVehicle = "C_Hatchback_02_EPOCH1";	};
		class C_Offroad_01_EPOCH: C_Hatchback_01_EPOCH		{	upgradeToVehicle = "C_Offroad_01_EPOCH1";	};
		class C_SUV_01_EPOCH: C_Hatchback_01_EPOCH			{	upgradeToVehicle = "C_SUV_01_EPOCH1";		};
		class B_MRAP_01_EPOCH: C_Hatchback_01_EPOCH			{	upgradeToVehicle = "B_MRAP_01_EPOCH1";		};
		class O_MRAP_02_EPOCH: C_Hatchback_01_EPOCH			{	upgradeToVehicle = "O_MRAP_02_EPOCH1";		};
		class I_MRAP_03_EPOCH: C_Hatchback_01_EPOCH			{	upgradeToVehicle = "I_MRAP_03_EPOCH1";		};
	};
	class KitVehicleUpgradeI_200_EPOCH
	{
		class C_Hatchback_01_EPOCH
		{
			ReqMaterials[] = {{1,"KitVehicleUpgradeI_200_EPOCH"}};
			upgradeToVehicle = "C_Hatchback_01_EPOCH1";
		};
		class C_Hatchback_02_EPOCH: C_Hatchback_01_EPOCH	{	upgradeToVehicle = "C_Hatchback_02_EPOCH1";	};
		class C_Offroad_01_EPOCH: C_Hatchback_01_EPOCH		{	upgradeToVehicle = "C_Offroad_01_EPOCH1";	};
		class C_SUV_01_EPOCH: C_Hatchback_01_EPOCH			{	upgradeToVehicle = "C_SUV_01_EPOCH1";		};
		class B_MRAP_01_EPOCH: C_Hatchback_01_EPOCH			{	upgradeToVehicle = "B_MRAP_01_EPOCH1";		};
		class O_MRAP_02_EPOCH: C_Hatchback_01_EPOCH			{	upgradeToVehicle = "O_MRAP_02_EPOCH1";		};
		class I_MRAP_03_EPOCH: C_Hatchback_01_EPOCH			{	upgradeToVehicle = "I_MRAP_03_EPOCH1";		};
	};
	class KitVehicleUpgradeI_300_EPOCH
	{
		class C_Hatchback_01_EPOCH
		{
			ReqMaterials[] = {{1,"KitVehicleUpgradeI_300_EPOCH"}};
			upgradeToVehicle = "C_Hatchback_01_EPOCH1";
		};
		class C_Hatchback_02_EPOCH: C_Hatchback_01_EPOCH	{	upgradeToVehicle = "C_Hatchback_02_EPOCH1";	};
		class C_Offroad_01_EPOCH: C_Hatchback_01_EPOCH		{	upgradeToVehicle = "C_Offroad_01_EPOCH1";	};
		class C_SUV_01_EPOCH: C_Hatchback_01_EPOCH			{	upgradeToVehicle = "C_SUV_01_EPOCH1";		};
		class B_MRAP_01_EPOCH: C_Hatchback_01_EPOCH			{	upgradeToVehicle = "B_MRAP_01_EPOCH1";		};
		class O_MRAP_02_EPOCH: C_Hatchback_01_EPOCH			{	upgradeToVehicle = "O_MRAP_02_EPOCH1";		};
		class I_MRAP_03_EPOCH: C_Hatchback_01_EPOCH			{	upgradeToVehicle = "I_MRAP_03_EPOCH1";		};
	};
	class ItemVehDoc2
	{
		class C_Hatchback_01_EPOCH1
		{
			ReqMaterials[] = {{1,"ItemVehDoc2"},{2,"SpareTire"},{2,"KitTankTrap"}};
			upgradeToVehicle = "C_Hatchback_01_EPOCH2";
		};
		class C_Hatchback_02_EPOCH1: C_Hatchback_01_EPOCH1		{	upgradeToVehicle = "C_Hatchback_02_EPOCH2";	};
		class C_Offroad_01_EPOCH1: C_Hatchback_01_EPOCH1		{	upgradeToVehicle = "C_Offroad_01_EPOCH2";	};
		class C_SUV_01_EPOCH1: C_Hatchback_01_EPOCH1			{	upgradeToVehicle = "C_SUV_01_EPOCH2";		};
		class B_MRAP_01_EPOCH1: C_Hatchback_01_EPOCH1			{	upgradeToVehicle = "B_MRAP_01_EPOCH2";		};
		class O_MRAP_02_EPOCH1: C_Hatchback_01_EPOCH1			{	upgradeToVehicle = "O_MRAP_02_EPOCH2";		};
		class I_MRAP_03_EPOCH1: C_Hatchback_01_EPOCH1			{	upgradeToVehicle = "I_MRAP_03_EPOCH2";		};
	};
	class KitVehicleUpgradeII_100_EPOCH
	{
		class C_Hatchback_01_EPOCH1
		{
			ReqMaterials[] = {{1,"KitVehicleUpgradeII_100_EPOCH"}};
			upgradeToVehicle = "C_Hatchback_01_EPOCH2";
		};
		class C_Hatchback_02_EPOCH1: C_Hatchback_01_EPOCH1		{	upgradeToVehicle = "C_Hatchback_02_EPOCH2";	};
		class C_Offroad_01_EPOCH1: C_Hatchback_01_EPOCH1		{	upgradeToVehicle = "C_Offroad_01_EPOCH2";	};
		class C_SUV_01_EPOCH1: C_Hatchback_01_EPOCH1			{	upgradeToVehicle = "C_SUV_01_EPOCH2";		};
		class B_MRAP_01_EPOCH1: C_Hatchback_01_EPOCH1			{	upgradeToVehicle = "B_MRAP_01_EPOCH2";		};
		class O_MRAP_02_EPOCH1: C_Hatchback_01_EPOCH1			{	upgradeToVehicle = "O_MRAP_02_EPOCH2";		};
		class I_MRAP_03_EPOCH1: C_Hatchback_01_EPOCH1			{	upgradeToVehicle = "I_MRAP_03_EPOCH2";		};
	};
	class KitVehicleUpgradeII_200_EPOCH
	{
		class C_Hatchback_01_EPOCH1
		{
			ReqMaterials[] = {{1,"KitVehicleUpgradeII_200_EPOCH"}};
			upgradeToVehicle = "C_Hatchback_01_EPOCH2";
		};
		class C_Hatchback_02_EPOCH1: C_Hatchback_01_EPOCH1		{	upgradeToVehicle = "C_Hatchback_02_EPOCH2";	};
		class C_Offroad_01_EPOCH1: C_Hatchback_01_EPOCH1		{	upgradeToVehicle = "C_Offroad_01_EPOCH2";	};
		class C_SUV_01_EPOCH1: C_Hatchback_01_EPOCH1			{	upgradeToVehicle = "C_SUV_01_EPOCH2";		};
		class B_MRAP_01_EPOCH1: C_Hatchback_01_EPOCH1			{	upgradeToVehicle = "B_MRAP_01_EPOCH2";		};
		class O_MRAP_02_EPOCH1: C_Hatchback_01_EPOCH1			{	upgradeToVehicle = "O_MRAP_02_EPOCH2";		};
		class I_MRAP_03_EPOCH1: C_Hatchback_01_EPOCH1			{	upgradeToVehicle = "I_MRAP_03_EPOCH2";		};
	};
	class KitVehicleUpgradeII_300_EPOCH
	{
		class C_Hatchback_01_EPOCH1
		{
			ReqMaterials[] = {{1,"KitVehicleUpgradeII_300_EPOCH"}};
			upgradeToVehicle = "C_Hatchback_01_EPOCH2";
		};
		class C_Hatchback_02_EPOCH1: C_Hatchback_01_EPOCH1		{	upgradeToVehicle = "C_Hatchback_02_EPOCH2";	};
		class C_Offroad_01_EPOCH1: C_Hatchback_01_EPOCH1		{	upgradeToVehicle = "C_Offroad_01_EPOCH2";	};
		class C_SUV_01_EPOCH1: C_Hatchback_01_EPOCH1			{	upgradeToVehicle = "C_SUV_01_EPOCH2";		};
		class B_MRAP_01_EPOCH1: C_Hatchback_01_EPOCH1			{	upgradeToVehicle = "B_MRAP_01_EPOCH2";		};
		class O_MRAP_02_EPOCH1: C_Hatchback_01_EPOCH1			{	upgradeToVehicle = "O_MRAP_02_EPOCH2";		};
		class I_MRAP_03_EPOCH1: C_Hatchback_01_EPOCH1			{	upgradeToVehicle = "I_MRAP_03_EPOCH2";		};
	};
	class ItemVehDoc3
	{
		class C_Hatchback_01_EPOCH2
		{
			ReqMaterials[] = {{1,"ItemVehDoc3"},{2,"ItemPipe"},{2,"KitShelf"}};
			upgradeToVehicle = "C_Hatchback_01_EPOCH3";
		};
		class C_Hatchback_02_EPOCH2: C_Hatchback_01_EPOCH2		{	upgradeToVehicle = "C_Hatchback_02_EPOCH3";	};
		class C_Offroad_01_EPOCH2: C_Hatchback_01_EPOCH2		{	upgradeToVehicle = "C_Offroad_01_EPOCH3";	};
		class C_SUV_01_EPOCH2: C_Hatchback_01_EPOCH2			{	upgradeToVehicle = "C_SUV_01_EPOCH3";		};
		class B_MRAP_01_EPOCH2: C_Hatchback_01_EPOCH2			{	upgradeToVehicle = "B_MRAP_01_EPOCH3";		};
		class O_MRAP_02_EPOCH2: C_Hatchback_01_EPOCH2			{	upgradeToVehicle = "O_MRAP_02_EPOCH3";		};
		class I_MRAP_03_EPOCH2: C_Hatchback_01_EPOCH2			{	upgradeToVehicle = "I_MRAP_03_EPOCH3";		};
		class C_Van_01_box_EPOCH: C_Hatchback_01_EPOCH2			{	upgradeToVehicle = "C_Van_01_box_EPOCH3";	};
		class C_Van_01_transport_EPOCH: C_Hatchback_01_EPOCH2	
		{
			ReqMaterials[] = {{1,"ItemVehDoc3"},{5,"ItemCorrugatedLg"},{8,"ItemPipe"},{4,"KitShelf"}};
			upgradeToVehicle = "C_Van_01_transport_EPOCH3";
		};
		class O_Truck_02_covered_EPOCH: C_Hatchback_01_EPOCH2			{	upgradeToVehicle = "O_Truck_02_covered_EPOCH3";	};
		class O_Truck_02_transport_EPOCH: C_Hatchback_01_EPOCH2	
		{
			ReqMaterials[] = {{1,"ItemVehDoc3"},{6,"ItemBurlap"},{6,"ItemPipe"},{4,"KitShelf"}};
			upgradeToVehicle = "O_Truck_02_transport_EPOCH3";
		};
	};
	class KitVehicleUpgradeIII_100_EPOCH
	{
		class C_Hatchback_01_EPOCH2
		{
			ReqMaterials[] = {{1,"KitVehicleUpgradeIII_100_EPOCH"}};
			upgradeToVehicle = "C_Hatchback_01_EPOCH3";
		};
		class C_Hatchback_02_EPOCH2: C_Hatchback_01_EPOCH2		{	upgradeToVehicle = "C_Hatchback_02_EPOCH3";	};
		class C_Offroad_01_EPOCH2: C_Hatchback_01_EPOCH2		{	upgradeToVehicle = "C_Offroad_01_EPOCH3";	};
		class C_SUV_01_EPOCH2: C_Hatchback_01_EPOCH2			{	upgradeToVehicle = "C_SUV_01_EPOCH3";		};
		class B_MRAP_01_EPOCH2: C_Hatchback_01_EPOCH2			{	upgradeToVehicle = "B_MRAP_01_EPOCH3";		};
		class O_MRAP_02_EPOCH2: C_Hatchback_01_EPOCH2			{	upgradeToVehicle = "O_MRAP_02_EPOCH3";		};
		class I_MRAP_03_EPOCH2: C_Hatchback_01_EPOCH2			{	upgradeToVehicle = "I_MRAP_03_EPOCH3";		};
		class C_Van_01_box_EPOCH: C_Hatchback_01_EPOCH2			{	upgradeToVehicle = "C_Van_01_box_EPOCH3";	};
		class C_Van_01_transport_EPOCH: C_Hatchback_01_EPOCH2	
		{
			ReqMaterials[] = {{1,"KitVehicleUpgradeIII_100_EPOCH"},{5,"ItemCorrugatedLg"},{6,"ItemPipe"},{2,"KitShelf"}};
			upgradeToVehicle = "C_Van_01_transport_EPOCH3";
		};
		class O_Truck_02_covered_EPOCH: C_Hatchback_01_EPOCH2			{	upgradeToVehicle = "O_Truck_02_covered_EPOCH3";	};
		class O_Truck_02_transport_EPOCH: C_Hatchback_01_EPOCH2	
		{
			ReqMaterials[] = {{1,"KitVehicleUpgradeIII_100_EPOCH"},{6,"ItemBurlap"},{4,"ItemPipe"},{2,"KitShelf"}};
			upgradeToVehicle = "O_Truck_02_transport_EPOCH3";
		};
	};
	class KitVehicleUpgradeIII_200_EPOCH
	{
		class C_Hatchback_01_EPOCH2
		{
			ReqMaterials[] = {{1,"KitVehicleUpgradeIII_200_EPOCH"}};
			upgradeToVehicle = "C_Hatchback_01_EPOCH3";
		};
		class C_Hatchback_02_EPOCH2: C_Hatchback_01_EPOCH2		{	upgradeToVehicle = "C_Hatchback_02_EPOCH3";	};
		class C_Offroad_01_EPOCH2: C_Hatchback_01_EPOCH2		{	upgradeToVehicle = "C_Offroad_01_EPOCH3";	};
		class C_SUV_01_EPOCH2: C_Hatchback_01_EPOCH2			{	upgradeToVehicle = "C_SUV_01_EPOCH3";		};
		class B_MRAP_01_EPOCH2: C_Hatchback_01_EPOCH2			{	upgradeToVehicle = "B_MRAP_01_EPOCH3";		};
		class O_MRAP_02_EPOCH2: C_Hatchback_01_EPOCH2			{	upgradeToVehicle = "O_MRAP_02_EPOCH3";		};
		class I_MRAP_03_EPOCH2: C_Hatchback_01_EPOCH2			{	upgradeToVehicle = "I_MRAP_03_EPOCH3";		};
		class C_Van_01_box_EPOCH: C_Hatchback_01_EPOCH2			{	upgradeToVehicle = "C_Van_01_box_EPOCH3";	};
		class C_Van_01_transport_EPOCH: C_Hatchback_01_EPOCH2	
		{
			ReqMaterials[] = {{1,"KitVehicleUpgradeIII_200_EPOCH"},{5,"ItemCorrugatedLg"},{6,"ItemPipe"},{2,"KitShelf"}};
			upgradeToVehicle = "C_Van_01_transport_EPOCH3";
		};
		class O_Truck_02_covered_EPOCH: C_Hatchback_01_EPOCH2			{	upgradeToVehicle = "O_Truck_02_covered_EPOCH3";	};
		class O_Truck_02_transport_EPOCH: C_Hatchback_01_EPOCH2	
		{
			ReqMaterials[] = {{1,"KitVehicleUpgradeIII_100_EPOCH"},{6,"ItemBurlap"},{4,"ItemPipe"},{2,"KitShelf"}};
			upgradeToVehicle = "O_Truck_02_transport_EPOCH3";
		};
	};
	class KitVehicleUpgradeIII_300_EPOCH
	{
		class C_Hatchback_01_EPOCH2
		{
			ReqMaterials[] = {{1,"KitVehicleUpgradeIII_300_EPOCH"}};
			upgradeToVehicle = "C_Hatchback_01_EPOCH3";
		};
		class C_Hatchback_02_EPOCH2: C_Hatchback_01_EPOCH2		{	upgradeToVehicle = "C_Hatchback_02_EPOCH3";	};
		class C_Offroad_01_EPOCH2: C_Hatchback_01_EPOCH2		{	upgradeToVehicle = "C_Offroad_01_EPOCH3";	};
		class C_SUV_01_EPOCH2: C_Hatchback_01_EPOCH2			{	upgradeToVehicle = "C_SUV_01_EPOCH3";		};
		class B_MRAP_01_EPOCH2: C_Hatchback_01_EPOCH2			{	upgradeToVehicle = "B_MRAP_01_EPOCH3";		};
		class O_MRAP_02_EPOCH2: C_Hatchback_01_EPOCH2			{	upgradeToVehicle = "O_MRAP_02_EPOCH3";		};
		class I_MRAP_03_EPOCH2: C_Hatchback_01_EPOCH2			{	upgradeToVehicle = "I_MRAP_03_EPOCH3";		};
		class C_Van_01_box_EPOCH: C_Hatchback_01_EPOCH2			{	upgradeToVehicle = "C_Van_01_box_EPOCH3";	};
		class C_Van_01_transport_EPOCH: C_Hatchback_01_EPOCH2	
		{
			ReqMaterials[] = {{1,"KitVehicleUpgradeIII_300_EPOCH"},{5,"ItemCorrugatedLg"},{6,"ItemPipe"},{2,"KitShelf"}};
			upgradeToVehicle = "C_Van_01_transport_EPOCH3";
		};
		class O_Truck_02_covered_EPOCH: C_Hatchback_01_EPOCH2			{	upgradeToVehicle = "O_Truck_02_covered_EPOCH3";	};
		class O_Truck_02_transport_EPOCH: C_Hatchback_01_EPOCH2	
		{
			ReqMaterials[] = {{1,"KitVehicleUpgradeIII_100_EPOCH"},{6,"ItemBurlap"},{4,"ItemPipe"},{2,"KitShelf"}};
			upgradeToVehicle = "O_Truck_02_transport_EPOCH3";
		};
	};
	class ItemVehDoc4
	{
		class C_Hatchback_01_EPOCH3
		{
			ReqMaterials[] = {{1,"ItemVehDoc3"},{1,"CircuitParts"},{2,"ItemScraps"},{2,"jerrycan_epoch"}};
			upgradeToVehicle = "C_Hatchback_01_EPOCH4";
		};
		class C_Hatchback_02_EPOCH3: C_Hatchback_01_EPOCH3		{	upgradeToVehicle = "C_Hatchback_02_EPOCH4";	};
		class C_Offroad_01_EPOCH3: C_Hatchback_01_EPOCH3		{	upgradeToVehicle = "C_Offroad_01_EPOCH4";	};
		class C_SUV_01_EPOCH3: C_Hatchback_01_EPOCH3			{	upgradeToVehicle = "C_SUV_01_EPOCH4";		};
		class B_MRAP_01_EPOCH3: C_Hatchback_01_EPOCH3			{	upgradeToVehicle = "B_MRAP_01_EPOCH4";		};
		class O_MRAP_02_EPOCH3: C_Hatchback_01_EPOCH3			{	upgradeToVehicle = "O_MRAP_02_EPOCH4";		};
		class I_MRAP_03_EPOCH3: C_Hatchback_01_EPOCH3			{	upgradeToVehicle = "I_MRAP_03_EPOCH4";		};
		class C_Van_01_box_EPOCH3: C_Hatchback_01_EPOCH3		{	upgradeToVehicle = "C_Van_01_box_EPOCH4";	};
		class C_Van_01_transport_EPOCH3: C_Hatchback_01_EPOCH3	{	upgradeToVehicle = "C_Van_01_transport_EPOCH4";	};
		class O_Truck_02_covered_EPOCH3: C_Hatchback_01_EPOCH3	{	upgradeToVehicle = "O_Truck_02_covered_EPOCH4";	};
		class O_Truck_02_transport_EPOCH3: C_Hatchback_01_EPOCH3 {	upgradeToVehicle = "O_Truck_02_transport_EPOCH4"; };
	};
	class KitVehicleUpgradeIV_100_EPOCH
	{
		class C_Hatchback_01_EPOCH3
		{
			ReqMaterials[] = {{1,"KitVehicleUpgradeIV_100_EPOCH"}};
			upgradeToVehicle = "C_Hatchback_01_EPOCH4";
		};
		class C_Hatchback_02_EPOCH3: C_Hatchback_01_EPOCH3		{	upgradeToVehicle = "C_Hatchback_02_EPOCH4";	};
		class C_Offroad_01_EPOCH3: C_Hatchback_01_EPOCH3		{	upgradeToVehicle = "C_Offroad_01_EPOCH4";	};
		class C_SUV_01_EPOCH3: C_Hatchback_01_EPOCH3			{	upgradeToVehicle = "C_SUV_01_EPOCH4";		};
		class B_MRAP_01_EPOCH3: C_Hatchback_01_EPOCH3			{	upgradeToVehicle = "B_MRAP_01_EPOCH4";		};
		class O_MRAP_02_EPOCH3: C_Hatchback_01_EPOCH3			{	upgradeToVehicle = "O_MRAP_02_EPOCH4";		};
		class I_MRAP_03_EPOCH3: C_Hatchback_01_EPOCH3			{	upgradeToVehicle = "I_MRAP_03_EPOCH4";		};
		class C_Van_01_box_EPOCH3: C_Hatchback_01_EPOCH3		{	upgradeToVehicle = "C_Van_01_box_EPOCH4";	};
		class C_Van_01_transport_EPOCH3: C_Hatchback_01_EPOCH3	{	upgradeToVehicle = "C_Van_01_transport_EPOCH4";	};
		class O_Truck_02_covered_EPOCH3: C_Hatchback_01_EPOCH3	{	upgradeToVehicle = "O_Truck_02_covered_EPOCH4";	};
		class O_Truck_02_transport_EPOCH3: C_Hatchback_01_EPOCH3 {	upgradeToVehicle = "O_Truck_02_transport_EPOCH4"; };
	};
	class KitVehicleUpgradeIV_200_EPOCH
	{
		class C_Hatchback_01_EPOCH3
		{
			ReqMaterials[] = {{1,"KitVehicleUpgradeIV_200_EPOCH"}};
			upgradeToVehicle = "C_Hatchback_01_EPOCH4";
		};
		class C_Hatchback_02_EPOCH3: C_Hatchback_01_EPOCH3		{	upgradeToVehicle = "C_Hatchback_02_EPOCH4";	};
		class C_Offroad_01_EPOCH3: C_Hatchback_01_EPOCH3		{	upgradeToVehicle = "C_Offroad_01_EPOCH4";	};
		class C_SUV_01_EPOCH3: C_Hatchback_01_EPOCH3			{	upgradeToVehicle = "C_SUV_01_EPOCH4";		};
		class B_MRAP_01_EPOCH3: C_Hatchback_01_EPOCH3			{	upgradeToVehicle = "B_MRAP_01_EPOCH4";		};
		class O_MRAP_02_EPOCH3: C_Hatchback_01_EPOCH3			{	upgradeToVehicle = "O_MRAP_02_EPOCH4";		};
		class I_MRAP_03_EPOCH3: C_Hatchback_01_EPOCH3			{	upgradeToVehicle = "I_MRAP_03_EPOCH4";		};
		class C_Van_01_box_EPOCH3: C_Hatchback_01_EPOCH3		{	upgradeToVehicle = "C_Van_01_box_EPOCH4";	};
		class C_Van_01_transport_EPOCH3: C_Hatchback_01_EPOCH3	{	upgradeToVehicle = "C_Van_01_transport_EPOCH4";	};
		class O_Truck_02_covered_EPOCH3: C_Hatchback_01_EPOCH3	{	upgradeToVehicle = "O_Truck_02_covered_EPOCH4";	};
		class O_Truck_02_transport_EPOCH3: C_Hatchback_01_EPOCH3 {	upgradeToVehicle = "O_Truck_02_transport_EPOCH4"; };
	};
	class KitVehicleUpgradeIV_300_EPOCH
	{
		class C_Hatchback_01_EPOCH3
		{
			ReqMaterials[] = {{1,"KitVehicleUpgradeIV_300_EPOCH"}};
			upgradeToVehicle = "C_Hatchback_01_EPOCH4";
		};
		class C_Hatchback_02_EPOCH3: C_Hatchback_01_EPOCH3		{	upgradeToVehicle = "C_Hatchback_02_EPOCH4";	};
		class C_Offroad_01_EPOCH3: C_Hatchback_01_EPOCH3		{	upgradeToVehicle = "C_Offroad_01_EPOCH4";	};
		class C_SUV_01_EPOCH3: C_Hatchback_01_EPOCH3			{	upgradeToVehicle = "C_SUV_01_EPOCH4";		};
		class B_MRAP_01_EPOCH3: C_Hatchback_01_EPOCH3			{	upgradeToVehicle = "B_MRAP_01_EPOCH4";		};
		class O_MRAP_02_EPOCH3: C_Hatchback_01_EPOCH3			{	upgradeToVehicle = "O_MRAP_02_EPOCH4";		};
		class I_MRAP_03_EPOCH3: C_Hatchback_01_EPOCH3			{	upgradeToVehicle = "I_MRAP_03_EPOCH4";		};
		class C_Van_01_box_EPOCH3: C_Hatchback_01_EPOCH3		{	upgradeToVehicle = "C_Van_01_box_EPOCH4";	};
		class C_Van_01_transport_EPOCH3: C_Hatchback_01_EPOCH3	{	upgradeToVehicle = "C_Van_01_transport_EPOCH4";	};
		class O_Truck_02_covered_EPOCH3: C_Hatchback_01_EPOCH3	{	upgradeToVehicle = "O_Truck_02_covered_EPOCH4";	};
		class O_Truck_02_transport_EPOCH3: C_Hatchback_01_EPOCH3 {	upgradeToVehicle = "O_Truck_02_transport_EPOCH4"; };
	};
	class ItemVehDocRara 
	{
		class K01
		{
			ReqMaterials[] = {{1,"ItemVehDocRara"},{2,"PaintCanOra"},{4,"ItemPipe"},{2,"jerrycan_epoch"}};
			upgradeToVehicle = "mosquito_epoch";
		};
		class K02: K01{};
		class K03: K01{};
		class K04: K01{};
	};
	class C_Offroad_01_EPOCH4		
	{	
		ReqMaterials[] = {{1,"ItemVehDocRara"},{1,"PaintCanBlu"},{1,"PaintCanRed"},{1,"CircuitParts"},{1,"ItemBattery"}};
		upgradeToVehicle = "C_Offroad_01_EPOCH5";	
	};
};