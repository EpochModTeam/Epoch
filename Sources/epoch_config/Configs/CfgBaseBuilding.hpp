class CfgBaseBuilding {
	class Default {
		upgradeBuilding[] = {};
		removeParts[] = {};
	};
	class FirePlace_EPOCH : Default
	{
		upgradeBuilding[] = { { "FirePlaceOn_EPOCH", { { "WoodLog_EPOCH", 1 } } } };
		removeParts[] = { { "ItemRock", 2 } };
	};
	class FirePlaceOn_EPOCH : Default
	{
		removeParts[] = { { "ItemRock", 2 } };
	};
	class Foundation_EPOCH : Default
	{
		removeParts[] = { { "ItemRock", 4 } };
	};
	class WoodFoundation_EPOCH : Default
	{
		removeParts[] = { { "PartPlankPack", 4 } };
	};
	class SolarGen_EPOCH : Default
	{
		removeParts[] = { { "KitSolarGen", 1 } };
	};
	class PlotPole_EPOCH : Default
	{
		removeParts[] = { { "KitPlotPole", 1 } };
	};
	class WoodRamp_EPOCH : Default
	{
		removeParts[] = { { "PartPlankPack", 3 } };
	};
	class WoodFloor_EPOCH : Default
	{
		removeParts[] = { { "PartPlankPack", 2 } };
	};
	class CinderWallGarage_EPOCH : Default
	{
		removeParts[] = { { "CinderBlocks", 4 }, { "ItemCorrugatedLg", 1 }, { "CircuitParts", 1 } };
	};
	class CinderWallHalf_EPOCH : Default{
		upgradeBuilding[] = { { "CinderWall_EPOCH", { { "CinderBlocks", 2 }, { "MortarBucket", 1 } } } };
		removeParts[] = { { "CinderBlocks", 2 }, { "ItemRock", 1 } };
	};
	class CinderWall_EPOCH : Default{
		upgradeBuilding[] = { { "CinderWallGarage_EPOCH", { { "ItemCorrugatedLg", 1 }, { "CircuitParts", 1 } } } };
		removeParts[] = { { "CinderBlocks", 4 }, { "ItemRock", 2 } };
	};
	class WoodLargeWall_EPOCH : Default{
		upgradeBuilding[] = {
				{ "WoodWall1_EPOCH", { { "PartPlankPack", 1 } } },
				{ "WoodLargeWallCor_EPOCH", { { "ItemCorrugated", 1 } } }
		};
		removeParts[] = { { "PartPlankPack", 2 } };
	};
	class WoodWall1_EPOCH : Default{
		upgradeBuilding[] = {
				{ "WoodWall2_EPOCH", { { "PartPlankPack", 1 } } },
				{ "WoodLargeWallCor_EPOCH", { { "ItemCorrugated", 1 } } }
		};
		removeParts[] = { { "PartPlankPack", 2 } };
	};
	class WoodLargeWallCor_EPOCH : Default{
		upgradeBuilding[] = { { "WoodLargeWallDoorway_EPOCH", { { "PartPlankPack", 1 } } } };
		removeParts[] = { { "PartPlankPack", 2 }, { "ItemCorrugated", 1 } };
	};
	class WoodWall2_EPOCH : Default{
		upgradeBuilding[] = {
				{ "WoodWall3_EPOCH", { { "PartPlankPack", 1 } } },
				{ "WoodLargeWallDoor_EPOCH", { { "ItemCorrugated", 1 }, { "PartPlankPack", 1 } } },
		};
		removeParts[] = { { "PartPlankPack", 2 } };
	};
	class WoodLargeWallDoorway_EPOCH : Default{
		upgradeBuilding[] = { { "WoodLargeWallDoor_EPOCH", { { "ItemCorrugated", 1 }, { "PartPlankPack", 1 } } } };
		removeParts[] = { { "PartPlankPack", 2 }, { "ItemCorrugated", 1 } };
	};
	class WoodWall3_EPOCH : Default{
		upgradeBuilding[] = {
				{ "WoodWall4_EPOCH", { { "CircuitParts", 1 } } },
				{ "WoodLargeWallDoorL_EPOCH", { { "ItemCorrugated", 1 }, { "CircuitParts", 1 } } },
		};
		removeParts[] = { { "PartPlankPack", 2 } };
	};
	class WoodLargeWallDoor_EPOCH : Default{
		upgradeBuilding[] = { { "WoodLargeWallDoorL_EPOCH", { { "ItemCorrugated", 1 }, { "CircuitParts", 1 } } } };
		removeParts[] = { { "PartPlankPack", 2 }, { "ItemCorrugated", 1 } };
	};
	class WoodWall4_EPOCH : Default {
		removeParts[] = { { "PartPlankPack", 2 }, { "CircuitParts", 1 } };
	};
	class WoodLargeWallDoorL_EPOCH : Default
	{
		removeParts[] = { { "PartPlankPack", 2 }, { "ItemCorrugated", 1 }, { "CircuitParts", 1 } };
	};
	class WoodStairs_EPOCH : Default{
		upgradeBuilding[] = { { "WoodStairs2_EPOCH", { { "PartPlankPack", 4 } } } };
		removeParts[] = { { "PartPlankPack", 4 } };
	};
	class WoodStairs2_EPOCH : Default
	{
		removeParts[] = { { "PartPlankPack", 4 } };
	};
	class WoodTower_EPOCH : Default
	{
		removeParts[] = { { "PartPlankPack", 4 } };
		upgradeBuildingPart[] = { { "PartPlankPack", 2 } };
		removeBuildingPart[] = { { "PartPlankPack", 1 } };
	};
	class WoodLadder_EPOCH : Default
	{
		removeParts[] = { { "PartPlankPack", 2 } };
	};
	class Tipi_EPOCH : Default
	{
		removeParts[] = { { "Pelt_EPOCH", 2 }, { "PartPlankPack", 1 } };
	};
	class StorageShelf_EPOCH : Default
	{
		removeParts[] = { { "ItemCorrugated", 2 } };
	};
	class Workbench_EPOCH : Default
	{
		removeParts[] = { { "PartPlankPack", 2 } };
	};
};
