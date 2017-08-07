/*[[[cog from arma_config_tools import *; json_to_arma()]]]*/
/*
    @author = "Aaron Clark - https://EpochMod.com";
    @contributors[] = {};
    @description = "Configs for base building upgrades and removal";
    @licence = "Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike";
    @github = "https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_config/Configs/CfgBaseBuilding.hpp";
*/
class CfgBaseBuilding
{
    class Default
    {
        upgradeBuilding[] = {};
        removeParts[] = {};
    };
    class FirePlace_EPOCH : Default
    {
        upgradeBuilding[] = {{"FirePlaceOn_EPOCH",{{"WoodLog_EPOCH",1}}}};
        removeParts[] = {{"ItemRock",2}};
        staticClass = "FirePlace_EPOCH";
        simulClass = "Fireplace_SIM_EPOCH";
        GhostPreview = "FirePlace_EPOCH";
        limitNearby = 2;
        bypassJammer = 1;
        isTemporary = 1;
    };
    class Fireplace_SIM_EPOCH : FirePlace_EPOCH
    {
        upgradeBuilding[] = {};
        removeParts[] = {};
    };
    class FirePlaceOn_EPOCH : FirePlace_EPOCH
    {
        upgradeBuilding[] = {};
    };
    class Foundation_EPOCH : Default
    {
        removeParts[] = {{"ItemRock",4}};
        GhostPreview = "Foundation_Ghost_EPOCH";
        staticClass = "Foundation_EPOCH";
        snapPointsPara[] = {"N","S","E","W","C"};
        snapPointsPerp[] = {};
        maxHeight = 2.5;
    };
    class Foundation_Ghost_EPOCH : Foundation_EPOCH
    {
        allowedSnapPoints[] = {"N","S","E","W"};
        allowedSnapObjects[] = {"Constructions_foundation_F"};
    };
    class WoodFoundation_EPOCH : Default
    {
        removeParts[] = {{"PartPlankPack",4}};
        GhostPreview = "WoodFoundation_Ghost_EPOCH";
        staticClass = "WoodFoundation_EPOCH";
        snapPointsPara[] = {"N","S","E","W","C"};
        snapPointsPerp[] = {};
        allowedSnapPoints[] = {"N","S","E","W"};
        allowedSnapObjects[] = {"Constructions_foundation_F"};
        maxHeight = 2.5;
    };
    class WoodFoundation_Ghost_EPOCH : WoodFoundation_EPOCH
    {
        allowedSnapPoints[] = {"N","S","E","W"};
        allowedSnapObjects[] = {"Constructions_foundation_F"};
    };
    class Hesco3_EPOCH : Default
    {
        removeParts[] = {{"KitHesco3",1}};
        simulClass = "Hesco3_SIM_EPOCH";
        staticClass = "Hesco3_EPOCH";
        GhostPreview = "Hesco3_Ghost_EPOCH";
        snapType = "snapPointsPara";
        snapPointsPara[] = {"C","E","W"};
        energyCost = 0.4;
        limitNearby = 4;
        bypassJammer = 1;
    };
    class Hesco3_SIM_EPOCH : Hesco3_EPOCH
    {
        allowedSnapPoints[] = {"C","E","W"};
        allowedSnapObjects[] = {"Hesco3_EPOCH"};
        removeParts[] = {};
    };
    class Hesco3_Ghost_EPOCH : Hesco3_SIM_EPOCH {};
    class TankTrap_EPOCH : Default
    {
        removeParts[] = {{"KitTankTrap",1}};
        simulClass = "TankTrap_SIM_EPOCH";
        staticClass = "TankTrap_EPOCH";
        GhostPreview = "TankTrap_EPOCH";
        energyCost = 0.2;
        limitNearby = 4;
        bypassJammer = 1;
    };
    class TankTrap_SIM_EPOCH : TankTrap_EPOCH
    {
        removeParts[] = {};
    };
    class Spike_TRAP_EPOCH : Default
    {
        simulClass = "Spike_TRAP_SIM_EPOCH";
        staticClass = "Spike_TRAP_EPOCH";
        GhostPreview = "Spike_TRAP_EPOCH";
        ammoClass = "Spike_TRAP_AMMO_EPOCH";
        energyCost = 0.2;
        limitNearby = 2;
        bypassJammer = 1;
    };
    class Spike_TRAP_SIM_EPOCH : Spike_TRAP_EPOCH {};
    class Metal_TRAP_EPOCH : Default
    {
        simulClass = "Metal_TRAP_SIM_EPOCH";
        staticClass = "Metal_TRAP_EPOCH";
        GhostPreview = "Metal_TRAP_EPOCH";
        ammoClass = "Metal_TRAP_AMMO_EPOCH";
        energyCost = 0.4;
        limitNearby = 2;
        bypassJammer = 1;
    };
    class Metal_TRAP_SIM_EPOCH : Metal_TRAP_EPOCH {};
    class SolarGen_EPOCH : Default
    {
        removeParts[] = {{"KitSolarGen",1}};
        powerCapacity = 10;
        powerType = 1;
        GhostPreview = "SolarGen_EPOCH";
        staticClass = "SolarGen_EPOCH";
        simulClass = "SolarGen_SIM_EPOCH";
    };
    class SolarGen_SIM_EPOCH : SolarGen_EPOCH
    {
        removeParts[] = {};
    };
    class PlotPole_EPOCH : Default
    {
        removeParts[] = {{"KitPlotPole",1}};
        GhostPreview = "PlotPole_EPOCH";
        staticClass = "PlotPole_EPOCH";
        simulClass = "PlotPole_SIM_EPOCH";
        bypassJammer = 1;
    };
    class PlotPole_SIM_EPOCH : PlotPole_EPOCH
    {
        removeParts[] = {};
    };
    class WoodRamp_EPOCH : Default
    {
        removeParts[] = {{"PartPlankPack",3}};
        simulClass = "WoodRamp_SIM_EPOCH";
        staticClass = "WoodRamp_EPOCH";
        GhostPreview = "WoodRamp_Ghost_EPOCH";
        snapPointsPara[] = {};
        snapPointsPerp[] = {};
        energyCost = 0.2;
    };
    class WoodRamp_SIM_EPOCH : WoodRamp_EPOCH
    {
        allowedSnapPoints[] = {"NF","SF","EF","WF","CB"};
        allowedSnapObjects[] = {"Const_floors_static_F","Constructions_foundation_F"};
        removeParts[] = {};
    };
    class WoodRamp_Ghost_EPOCH : WoodRamp_SIM_EPOCH {};
    class WoodFloor_EPOCH : Default
    {
        upgradeBuilding[] = {{"MetalFloor_EPOCH",{{"ItemCorrugatedLg",2}}}};
        removeParts[] = {{"PartPlankPack",2}};
        simulClass = "WoodFloor_SIM_EPOCH";
        staticClass = "WoodFloor_EPOCH";
        GhostPreview = "WoodFloor_Ghost_EPOCH";
        snapPointsPara[] = {"NF","SF","EF","WF","C","CB"};
        snapPointsPerp[] = {"N","S","E","W","CinN","CinS","CinE","CinW"};
        energyCost = 0.2;
    };
    class WoodFloor_SIM_EPOCH : WoodFloor_EPOCH
    {
        allowedSnapPoints[] = {"NF","SF","EF","WF","C"};
        allowedSnapObjects[] = {"Const_floors_static_F","Constructions_foundation_F"};
        upgradeBuilding[] = {};
        removeParts[] = {};
    };
    class WoodFloor_Ghost_EPOCH : WoodFloor_SIM_EPOCH {};
	class WoodHalfFloor_EPOCH : Default
    {
        upgradeBuilding[] = {{"WoodFloor_EPOCH",{{"KitWoodHalfFloor",1}}}};
        removeParts[] = {{"KitWoodHalfFloor",1}};
        simulClass = "WoodHalfFloor_SIM_EPOCH";
        staticClass = "WoodHalfFloor_EPOCH";
        GhostPreview = "WoodHalfFloor_Ghost_EPOCH";
        snapPointsPara[] = {"NF","SF","EF","WF","C","CB"};
        snapPointsPerp[] = {"N","S","E","W","CinN","CinS","CinE","CinW"};
        energyCost = 0.2;
    };
    class WoodHalfFloor_SIM_EPOCH : WoodHalfFloor_EPOCH
    {
        allowedSnapPoints[] = {"NF","SF","EF","WF","C"};
        allowedSnapObjects[] = {"WoodHalfFloor_EPOCH"};
        upgradeBuilding[] = {};
        removeParts[] = {};
    };
    class WoodHalfFloor_Ghost_EPOCH : WoodHalfFloor_SIM_EPOCH {};
	class WoodQuarterFloor_EPOCH : Default
    {
        upgradeBuilding[] = {{"WoodHalfFloor_EPOCH",{{"KitWoodQuarterFloor",1}}}};
        removeParts[] = {{"KitWoodQuarterFloor",1}};
        simulClass = "WoodQuarterFloor_SIM_EPOCH";
        staticClass = "WoodQuarterFloor_EPOCH";
        GhostPreview = "WoodQuarterFloor_Ghost_EPOCH";
        snapPointsPara[] = {"NF","SF","EF","WF","C","CB"};
        snapPointsPerp[] = {"N","S","E","W","CinN","CinS","CinE","CinW"};
        energyCost = 0.1;
    };
    class WoodQuarterFloor_SIM_EPOCH : WoodQuarterFloor_EPOCH
    {
        allowedSnapPoints[] = {"NF","SF","EF","WF","C"};
        allowedSnapObjects[] = {"WoodQuarterFloor_EPOCH"};
        upgradeBuilding[] = {};
        removeParts[] = {};
    };
    class WoodQuarterFloor_Ghost_EPOCH : WoodQuarterFloor_SIM_EPOCH {};
    class MetalFloor_EPOCH : Default
    {
        removeParts[] = {{"ItemCorrugatedLg",2}};
        simulClass = "MetalFloor_SIM_EPOCH";
        staticClass = "MetalFloor_EPOCH";
        GhostPreview = "MetalFloor_Ghost_EPOCH";
        snapPointsPara[] = {"NF","SF","EF","WF","C","CB"};
        snapPointsPerp[] = {"N","S","E","W","CinN","CinS","CinE","CinW"};
        energyCost = 0.5;
    };
    class MetalFloor_SIM_EPOCH : Default
    {
        allowedSnapPoints[] = {"NF","SF","EF","WF","C"};
        allowedSnapObjects[] = {"Const_floors_static_F","Constructions_foundation_F"};
        removeParts[] = {};
    };
    class MetalFloor_Ghost_EPOCH : MetalFloor_SIM_EPOCH {};
    class CinderWallGarage_EPOCH : Default
    {
        removeParts[] = {{"CinderBlocks",4},{"ItemCorrugatedLg",1},{"CircuitParts",1}};
        simulClass = "CinderWallGarage_SIM_EPOCH";
        staticClass = "CinderWallGarage_EPOCH";
        GhostPreview = "CinderWallGarage_EPOCH";
        snapType = "snapPointsPara";
        snapPointsPara[] = {"N","E","W"};
        allowedSnapPoints[] = {"N","S","E","W"};
        energyCost = 0.5;
    };
    class CinderFloor_EPOCH : Default
    {
        removeParts[] = {{"CinderBlocks",2},{"MortarBucket",2}};
        simulClass = "CinderFloor_SIM_EPOCH";
        staticClass = "CinderFloor_EPOCH";
        GhostPreview = "CinderFloor_Ghost_EPOCH";
        snapPointsPara[] = {"NF","SF","EF","WF","C","CB"};
        snapPointsPerp[] = {"N","S","E","W","CinN","CinS","CinE","CinW"};
        energyCost = 0.5;
    };
    class CinderFloor_SIM_EPOCH : Default
    {
        allowedSnapPoints[] = {"NF","SF","EF","WF","C"};
        allowedSnapObjects[] = {"Const_floors_static_F","Constructions_foundation_F"};
        removeParts[] = {};
    };
    class CinderFloor_Ghost_EPOCH : CinderFloor_SIM_EPOCH {};
    class CinderWallGarage_SIM_EPOCH : CinderWallGarage_EPOCH
    {
        allowedSnapObjects[] = {"Const_Cinder_static_F","Const_floors_static_F"};
        removeParts[] = {};
    };
    class CinderWallHalf_EPOCH : Default
    {
        upgradeBuilding[] = {{"CinderWall_EPOCH",{{"CinderBlocks",2},{"MortarBucket",1}}}};
        removeParts[] = {{"CinderBlocks",2},{"ItemRock",1}};
        simulClass = "CinderWallHalf_SIM_EPOCH";
        staticClass = "CinderWallHalf_EPOCH";
        GhostPreview = "CinderWallHalf_Ghost_EPOCH";
        energyCost = 0.2;
        snapType = "snapPointsPara";
        snapPointsPara[] = {"N","E","W"};
        allowedSnapPoints[] = {"N","S","E","W"};
    };
    class CinderWallHalf_SIM_EPOCH : CinderWallHalf_EPOCH
    {
        allowedSnapObjects[] = {"Const_Cinder_static_F","Const_floors_static_F"};
        removeParts[] = {};
        upgradeBuilding[] = {};
    };
    class CinderWallHalf_Ghost_EPOCH : CinderWallHalf_SIM_EPOCH {};
    class CinderWall_EPOCH : Default
    {
        upgradeBuilding[] = {{"CinderWallGarage_EPOCH",{{"ItemCorrugatedLg",1},{"CircuitParts",1}}}};
        removeParts[] = {{"CinderBlocks",4},{"ItemRock",2}};
        simulClass = "CinderWall_SIM_EPOCH";
        staticClass = "CinderWall_EPOCH";
        GhostPreview = "CinderWall_EPOCH";
        snapType = "snapPointsPara";
        snapPointsPara[] = {"N","E","W"};
        allowedSnapPoints[] = {"N","S","E","W"};
        energyCost = 0.4;
    };
    class CinderWall_SIM_EPOCH : CinderWall_EPOCH
    {
        allowedSnapObjects[] = {"Const_Cinder_static_F","Const_floors_static_F"};
        upgradeBuilding[] = {};
        removeParts[] = {};
    };
    class WoodLargeWall_EPOCH : Default
    {
        upgradeBuilding[] = {{"WoodWall1_EPOCH",{{"ItemPlywoodPack",1}}},{"WoodLargeWallCor_EPOCH",{{"ItemCorrugated",1}}}};
        removeParts[] = {{"PartPlankPack",2}};
        simulClass = "WoodLargeWall_SIM_EPOCH";
        staticClass = "WoodLargeWall_EPOCH";
        GhostPreview = "WoodLargeWall_Ghost_EPOCH";
        snapType = "snapPointsPara";
        snapPointsPara[] = {"N","E","W"};
        allowedSnapPoints[] = {"N","S","E","W"};
    };
    class WoodLargeWall_SIM_EPOCH : WoodLargeWall_EPOCH
    {
        upgradeBuilding[] = {};
        removeParts[] = {};
        allowedSnapObjects[] = {"Const_floors_static_F","Const_WoodWalls_static_F"};
    };
    class WoodLargeWall_Ghost_EPOCH : WoodLargeWall_SIM_EPOCH {};
    class WoodWall1_EPOCH : Default
    {
        upgradeBuilding[] = {{"WoodWall2_EPOCH",{{"PartPlankPack",1}}},{"WoodLargeWallCor_EPOCH",{{"ItemCorrugated",1}}}};
        removeParts[] = {{"PartPlankPack",2}};
        simulClass = "WoodWall1_SIM_EPOCH";
        staticClass = "WoodWall1_EPOCH";
        GhostPreview = "WoodWall1_EPOCH";
        snapType = "snapPointsPara";
        snapPointsPara[] = {"N","E","W"};
        allowedSnapPoints[] = {"N","S","E","W"};
        energyCost = 0.2;
    };
    class WoodWall1_SIM_EPOCH : WoodWall1_EPOCH
    {
        allowedSnapObjects[] = {"Const_floors_static_F","Const_WoodWalls_static_F"};
        energyCost = 0.2;
        upgradeBuilding[] = {};
        removeParts[] = {};
    };
    class WoodLargeWallCor_EPOCH : Default
    {
        upgradeBuilding[] = {{"WoodLargeWallDoorway_EPOCH",{{"PartPlankPack",1}}}};
        removeParts[] = {{"PartPlankPack",2},{"ItemCorrugated",1}};
        simulClass = "WoodLargeWallCor_SIM_EPOCH";
        staticClass = "WoodLargeWallCor_EPOCH";
        GhostPreview = "WoodLargeWallCor_EPOCH";
        snapType = "snapPointsPara";
        snapPointsPara[] = {"N","E","W"};
        allowedSnapPoints[] = {"N","S","E","W"};
        energyCost = 0.2;
        availableTextures[] = {"\x\addons\a3_epoch_assets\textures\cor\corrugated_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_black_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_blue_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_brown_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_green_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_orange_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_purple_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_red_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_teal_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_yellow_co.paa"};
    };
    class WoodLargeWallCor_SIM_EPOCH : WoodLargeWallCor_EPOCH
    {
        allowedSnapObjects[] = {"Const_floors_static_F","Const_WoodWalls_static_F"};
        upgradeBuilding[] = {};
        removeParts[] = {};
    };
    class WoodWall2_EPOCH : Default
    {
        upgradeBuilding[] = {{"WoodWall3_EPOCH",{{"ItemPlywoodPack",1},{"PartPlankPack",1}}},{"WoodLargeWallDoor_EPOCH",{{"ItemCorrugated",1},{"PartPlankPack",1}}}};
        removeParts[] = {{"ItemPlywoodPack",1},{"PartPlankPack",2}};
        simulClass = "WoodWall2_SIM_EPOCH";
        staticClass = "WoodWall2_EPOCH";
        GhostPreview = "WoodWall2_EPOCH";
        snapPointsPara[] = {"N","E","W"};
        allowedSnapPoints[] = {"N","S","E","W"};
        energyCost = 0.2;
    };
    class WoodWall2_SIM_EPOCH : WoodWall2_EPOCH
    {
        allowedSnapObjects[] = {"Const_floors_static_F","Const_WoodWalls_static_F"};
        upgradeBuilding[] = {};
        removeParts[] = {};
    };
    class WoodLargeWallDoorway_EPOCH : Default
    {
        upgradeBuilding[] = {{"WoodLargeWallDoor_EPOCH",{{"ItemCorrugated",1},{"PartPlankPack",1}}}};
        removeParts[] = {{"PartPlankPack",2},{"ItemCorrugated",1}};
        simulClass = "WoodLargeWallDoorway_SIM_EPOCH";
        staticClass = "WoodLargeWallDoorway_EPOCH";
        GhostPreview = "WoodLargeWallDoorway_EPOCH";
        snapPointsPara[] = {"N","E","W"};
        allowedSnapPoints[] = {"N","S","E","W"};
        energyCost = 0.2;
        availableTextures[] = {"\x\addons\a3_epoch_assets\textures\cor\corrugated_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_black_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_blue_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_brown_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_green_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_orange_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_purple_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_red_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_teal_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_yellow_co.paa"};
    };
    class WoodLargeWallDoorway_SIM_EPOCH : WoodLargeWallDoorway_EPOCH
    {
        allowedSnapObjects[] = {"Const_floors_static_F","Const_WoodWalls_static_F"};
        upgradeBuilding[] = {};
        removeParts[] = {};
    };
    class WoodWall3_EPOCH : Default
    {
        upgradeBuilding[] = {{"WoodWall4_EPOCH",{{"CircuitParts",1}}},{"WoodLargeWallDoorL_EPOCH",{{"ItemCorrugated",1},{"CircuitParts",1}}}};
        removeParts[] = {{"ItemPlywoodPack",1},{"PartPlankPack",2}};
        simulClass = "WoodWall3_SIM_EPOCH";
        staticClass = "WoodWall3_EPOCH";
        GhostPreview = "WoodWall3_EPOCH";
        snapPointsPara[] = {"N","E","W"};
        allowedSnapPoints[] = {"N","S","E","W"};
        energyCost = 0.2;
    };
    class WoodWall3_SIM_EPOCH : WoodWall3_EPOCH
    {
        allowedSnapObjects[] = {"Const_floors_static_F","Const_WoodWalls_static_F"};
        upgradeBuilding[] = {};
        removeParts[] = {};
    };
    class WoodLargeWallDoor_EPOCH : Default
    {
        upgradeBuilding[] = {{"WoodLargeWallDoorL_EPOCH",{{"ItemCorrugated",1},{"CircuitParts",1}}}};
        removeParts[] = {{"PartPlankPack",2},{"ItemCorrugated",1}};
        simulClass = "WoodLargeWallDoor_SIM_EPOCH";
        staticClass = "WoodLargeWallDoor_EPOCH";
        GhostPreview = "WoodLargeWallDoor_EPOCH";
        snapPointsPara[] = {"N","E","W"};
        allowedSnapPoints[] = {"N","S","E","W"};
        availableTextures[] = {"\x\addons\a3_epoch_assets\textures\cor\corrugated_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_black_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_blue_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_brown_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_green_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_orange_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_purple_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_red_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_teal_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_yellow_co.paa"};
        energyCost = 0.2;
    };
    class WoodLargeWallDoor_SIM_EPOCH : WoodLargeWallDoor_EPOCH
    {
        allowedSnapObjects[] = {"Const_floors_static_F","Const_WoodWalls_static_F"};
        upgradeBuilding[] = {};
        removeParts[] = {};
    };
    class WoodWall4_EPOCH : Default
    {
        removeParts[] = {{"ItemPlywoodPack",1},{"PartPlankPack",2},{"CircuitParts",1}};
        simulClass = "WoodWall4_SIM_EPOCH";
        staticClass = "WoodWall4_EPOCH";
        GhostPreview = "WoodWall4_EPOCH";
        snapPointsPara[] = {"N","E","W"};
        allowedSnapPoints[] = {"N","S","E","W"};
        energyCost = 0.2;
    };
    class WoodWall4_SIM_EPOCH : WoodWall4_EPOCH
    {
        allowedSnapObjects[] = {"Const_floors_static_F","Const_WoodWalls_static_F"};
        upgradeBuilding[] = {};
        removeParts[] = {};
    };
    class WoodLargeWallDoorL_EPOCH : Default
    {
        removeParts[] = {{"PartPlankPack",2},{"ItemCorrugated",1},{"CircuitParts",1}};
        simulClass = "WoodLargeWallDoorL_SIM_EPOCH";
        staticClass = "WoodLargeWallDoorL_EPOCH";
        GhostPreview = "WoodLargeWallDoorL_EPOCH";
        snapPointsPara[] = {"N","E","W"};
        allowedSnapPoints[] = {"N","S","E","W"};
        availableTextures[] = {"\x\addons\a3_epoch_assets\textures\cor\corrugated_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_black_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_blue_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_brown_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_green_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_orange_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_purple_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_red_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_teal_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_yellow_co.paa"};
        energyCost = 0.2;
    };
    class WoodLargeWallDoorL_SIM_EPOCH : WoodLargeWallDoorL_EPOCH
    {
        allowedSnapObjects[] = {"Const_floors_static_F","Const_WoodWalls_static_F"};
        upgradeBuilding[] = {};
        removeParts[] = {};
    };
    class WoodStairs_EPOCH : Default
    {
        upgradeBuilding[] = {{"WoodStairs2_EPOCH",{{"PartPlankPack",4}}}};
        removeParts[] = {{"PartPlankPack",4}};
        simulClass = "WoodStairs_SIM_EPOCH";
        staticClass = "WoodStairs_EPOCH";
        GhostPreview = "WoodStairs_Ghost_EPOCH";
        snapPointsPara[] = {};
        snapPointsPerp[] = {};
        energyCost = 0.2;
    };
    class WoodStairs_SIM_EPOCH : WoodStairs_EPOCH
    {
        allowedSnapPoints[] = {"NF","SF","EF","WF","CB"};
        allowedSnapObjects[] = {"Const_floors_static_F","Constructions_foundation_F"};
        upgradeBuilding[] = {};
        removeParts[] = {};
    };
    class WoodStairs_Ghost_EPOCH : WoodStairs_SIM_EPOCH {};
    class WoodStairs2_EPOCH : Default
    {
        removeParts[] = {{"PartPlankPack",4}};
        simulClass = "WoodStairs2_SIM_EPOCH";
        staticClass = "WoodStairs2_EPOCH";
        GhostPreview = "WoodStairs2_EPOCH";
        snapPointsPara[] = {"NF2","SF2","EF2","WF2","NF","SF","EF","WF","C","CB"};
        snapPointsPerp[] = {"N","S","E","W","CinN","CinS","CinE","CinW"};
        energyCost = 0.3;
    };
    class WoodStairs2_SIM_EPOCH : WoodStairs2_EPOCH
    {
        allowedSnapPoints[] = {"NF","SF","EF","WF","CB"};
        allowedSnapObjects[] = {"Const_floors_static_F","Constructions_foundation_F"};
        removeParts[] = {};
    };
    class WoodTower_EPOCH : Default
    {
        removeParts[] = {{"PartPlankPack",4}};
        upgradeBuildingPart[] = {{"ItemPlywoodPack",1},{"PartPlankPack",2}};
        removeBuildingPart[] = {{"ItemPlywoodPack",1},{"PartPlankPack",2}};
        simulClass = "WoodTower_SIM_EPOCH";
        staticClass = "WoodTower_EPOCH";
        GhostPreview = "WoodTower_Ghost_EPOCH";
        snapPointsPara[] = {"NF2","SF2","EF2","WF2","NF","SF","EF","WF","C","CB"};
        snapPointsPerp[] = {"N","S","E","W","CinN","CinS","CinE","CinW"};
        persistAnimations[] = {"NWall","EWall","SWall","WWall"};
        energyCost = 0.3;
    };
    class WoodTower_SIM_EPOCH : WoodTower_EPOCH
    {
        allowedSnapPoints[] = {"NF2","SF2","EF2","WF2","CB"};
        allowedSnapObjects[] = {"WoodTower_EPOCH","Const_floors_static_F","Constructions_foundation_F"};
        energyCost = 0.3;
    };
    class WoodTower_Ghost_EPOCH : WoodTower_SIM_EPOCH {};
    class WoodLadder_EPOCH : Default
    {
        removeParts[] = {{"PartPlankPack",2}};
        simulClass = "WoodLadder_SIM_EPOCH";
        staticClass = "WoodLadder_EPOCH";
        GhostPreview = "WoodLadder_Ghost_EPOCH";
        energyCost = 0.1;
    };
    class WoodLadder_SIM_EPOCH : WoodLadder_EPOCH
    {
        removeParts[] = {};
    };
    class WoodLadder_Ghost_EPOCH : WoodLadder_SIM_EPOCH {};
    class Tipi_EPOCH : Default
    {
        removeParts[] = {{"Pelt_EPOCH",2},{"PartPlankPack",1}};
        GhostPreview = "Tipi_Ghost_EPOCH";
        staticClass = "Tipi_EPOCH";
        simulClass = "Tipi_SIM_EPOCH";
        limitNearby = 2;
        bypassJammer = 1;
    };
    class Tipi_SIM_EPOCH : Tipi_EPOCH
    {
        simulClass = "Tipi_SIM_EPOCH";
        staticClass = "Tipi_EPOCH";
        limitNearby = 2;
        bypassJammer = 1;
        removeParts[] = {};
    };
    class Tipi_Ghost_EPOCH : Tipi_SIM_EPOCH {};
    class StorageShelf_EPOCH : Default
    {
        removeParts[] = {{"ItemCorrugated",2}};
        GhostPreview = "StorageShelf_Ghost_EPOCH";
        staticClass = "StorageShelf_EPOCH";
        simulClass = "StorageShelf_SIM_EPOCH";
        limitNearby = 5;
        bypassJammer = 1;
    };
    class StorageShelf_SIM_EPOCH : StorageShelf_EPOCH
    {
        removeParts[] = {};
    };
    class StorageShelf_Ghost_EPOCH : StorageShelf_SIM_EPOCH {};
    class Workbench_EPOCH : Default
    {
        removeParts[] = {{"PartPlankPack",2}};
        GhostPreview = "WorkBench_Ghost_EPOCH";
        staticClass = "WorkBench_EPOCH";
        simulClass = "WorkBench_SIM_EPOCH";
        limitNearby = 5;
        bypassJammer = 1;
    };
    class WorkBench_SIM_EPOCH : Workbench_EPOCH
    {
        removeParts[] = {};
    };
    class WorkBench_Ghost_EPOCH : WorkBench_SIM_EPOCH {};
    class LockBox_EPOCH : Default
    {
        returnOnPack[] = {{"ItemLockbox",1}};
        simulClass = "LockBox_SIM_EPOCH";
        staticClass = "LockBox_EPOCH";
        weaponHolderProxy = "LockBoxProxy_EPOCH";
        GhostPreview = "LockBox_EPOCH";
        bypassJammer = 1;
        limitNearby = 2;
        isSecureStorage = 1;
    };
    class LockBox_SIM_EPOCH : LockBox_EPOCH
    {
        returnOnPack[] = {};
    };
    class Safe_EPOCH : Default
    {
        returnOnPack[] = {{"ItemSafe",1}};
        simulClass = "Safe_SIM_EPOCH";
        staticClass = "Safe_EPOCH";
        weaponHolderProxy = "SafeProxy_EPOCH";
        GhostPreview = "Safe_EPOCH";
        bypassJammer = 1;
        limitNearby = 2;
        isSecureStorage = 1;
    };
    class Safe_SIM_EPOCH : Safe_EPOCH
    {
        returnOnPack[] = {};
    };
    class Jack_EPOCH : Default
    {
        simulClass = "Jack_SIM_EPOCH";
        staticClass = "Jack_EPOCH";
        GhostPreview = "Jack_EPOCH";
        limitNearby = 2;
        bypassJammer = 1;
        energyCost = 0.1;
    };
    class Jack_SIM_EPOCH : Jack_EPOCH {};
};

/*[[[end]]]*/
