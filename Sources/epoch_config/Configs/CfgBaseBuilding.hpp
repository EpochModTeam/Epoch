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
// Power Sources (only for Energy Calculations)
	class Land_spp_Tower_F
	{
        powerCapacity = 10;
        powerType = 1;			// Solar
	};
	class Land_wpp_Turbine_V1_F
	{
        powerCapacity = 10;
        powerType = 2;			// Wind
	};
	class Land_wpp_Turbine_V2_F : Land_wpp_Turbine_V1_F {};
	class Land_Wreck_Satellite_EPOCH
	{
        powerCapacity = 10;
        powerType = 3;			// Satellite
	};

// BaseBuilding
    class Default
    {
        upgradeBuilding[] = {};
        removeParts[] = {};
		maxSnapDistance = 1;
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
		maxSnapDistance = 4.5;
		// snap points for Foundation_EPOCH
		C[] = {0,0,0.806411};
		N[] = {0,10.474,0};
		E[] = {10.474,0,0};
		S[] = {0,-10.474,0};
		W[] = {-10.474,0,0};
		NE[] = {2.47112,2.46379,0.269223};
		NW[] = {-2.4783,2.46379,0.269223};
		SE[] = {2.47112,-2.46097,0.269223};
		SW[] = {-2.4783,-2.46097,0.269223};
		NF[] = {0,5.23361,0.806411};
		SF[] = {0,-5.25013,0.806411};
		EF[] = {5.24796,0,0.806219};
		WF[] = {-5.21655,0,0.806219};
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
		maxSnapDistance = 3;
		// snap points for Foundation_EPOCH
		C[] = {0,0,0.806411};
		N[] = {0,10.474,0};
		E[] = {10.474,0,0};
		S[] = {0,-10.474,0};
		W[] = {-10.474,0,0};
		NE[] = {2.47112,2.46379,0.269223};
		NW[] = {-2.4783,2.46379,0.269223};
		SE[] = {2.47112,-2.46097,0.269223};
		SW[] = {-2.4783,-2.46097,0.269223};
		NF[] = {0,5.23361,0.806411};
		SF[] = {0,-5.25013,0.806411};
		EF[] = {5.24796,0,0.806219};
		WF[] = {-5.21655,0,0.806219};
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
		// snap points for Hesco3_EPOCH
		C[] = {0,0,1.2};
		E[] = {3.375,0,0};
		W[] = {-3.375,0,0};
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
        upgradeBuilding[] = {{"PlotPole_M_EPOCH",{{"ItemCorrugatedLg",5},{"EnergyPackLg",2},{"CircuitParts",3},{"ItemBattery",3},{"ItemPipe",1}}}};
        removeParts[] = {{"KitPlotPole",1}};
        GhostPreview = "PlotPole_EPOCH";
        staticClass = "PlotPole_EPOCH";
        simulClass = "PlotPole_SIM_EPOCH";
        bypassJammer = 1;
    };
    class PlotPole_SIM_EPOCH : PlotPole_EPOCH
    {
        upgradeBuilding[] = {};
        removeParts[] = {};
    };
    class PlotPole_M_EPOCH : Default
    {
        upgradeBuilding[] = {{"PlotPole_L_EPOCH",{{"ItemCorrugatedLg",5},{"EnergyPackLg",2},{"CircuitParts",3},{"ItemBattery",3},{"ItemPipe",1}}}};
        removeParts[] = {{"KitPlotPole_M",1}};
        GhostPreview = "PlotPole_M_EPOCH";
        staticClass = "PlotPole_M_EPOCH";
        simulClass = "PlotPole_M_SIM_EPOCH";
        bypassJammer = 1;
    };
    class PlotPole_M_SIM_EPOCH : PlotPole_M_EPOCH
    {
        upgradeBuilding[] = {};
        removeParts[] = {};
    };
    class PlotPole_L_EPOCH : Default
    {
        upgradeBuilding[] = {{"PlotPole_XL_EPOCH",{{"ItemCorrugatedLg",5},{"EnergyPackLg",2},{"CircuitParts",3},{"ItemBattery",3},{"ItemPipe",1}}}};
        removeParts[] = {{"KitPlotPole_L",1}};
        GhostPreview = "PlotPole_L_EPOCH";
        staticClass = "PlotPole_L_EPOCH";
        simulClass = "PlotPole_L_SIM_EPOCH";
        bypassJammer = 1;
    };
    class PlotPole_L_SIM_EPOCH : PlotPole_L_EPOCH
    {
        upgradeBuilding[] = {};
        removeParts[] = {};
    };
    class PlotPole_XL_EPOCH : Default
    {
        upgradeBuilding[] = {{"PlotPole_XXL_EPOCH",{{"ItemCorrugatedLg",5},{"EnergyPackLg",2},{"CircuitParts",3},{"ItemBattery",3},{"ItemPipe",1}}}};
        removeParts[] = {{"KitPlotPole_XL",1}};
        GhostPreview = "PlotPole_XL_EPOCH";
        staticClass = "PlotPole_XL_EPOCH";
        simulClass = "PlotPole_XL_SIM_EPOCH";
        bypassJammer = 1;
    };
    class PlotPole_XL_SIM_EPOCH : PlotPole_XL_EPOCH
    {
        upgradeBuilding[] = {};
        removeParts[] = {};
    };
    class PlotPole_XXL_EPOCH : Default
    {
        upgradeBuilding[] = {};
        removeParts[] = {{"KitPlotPole_XXL",1}};
        GhostPreview = "PlotPole_XXL_EPOCH";
        staticClass = "PlotPole_XXL_EPOCH";
        simulClass = "PlotPole_XXL_SIM_EPOCH";
        bypassJammer = 1;
    };
    class PlotPole_XXL_SIM_EPOCH : PlotPole_XXL_EPOCH
    {
        upgradeBuilding[] = {};
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
        upgradeBuilding[] = {{"MetalFloor_EPOCH",{{"ItemCorrugatedLg",3}}}};
        removeParts[] = {{"PartPlankPack",4}};
        simulClass = "WoodFloor_SIM_EPOCH";
        staticClass = "WoodFloor_EPOCH";
        GhostPreview = "WoodFloor_Ghost_EPOCH";
        snapPointsPara[] = {"NF","SF","EF","WF","C","CB","Cx2","NWQF","NQF","NEQF","SWQF","SQF","SEQF","ENQF","EQF","ESQF","WNQF","WQF","WSQF","NWHF","NEHF","SWHF","SEHF","WNHF","WSHF","ENHF","ESHF"};
        snapPointsPerp[] = {"N","S","E","W","CinN","CinS","CinE","CinW"};
        energyCost = 0.2;
		// snap points for WoodFloor_EPOCH
		C[] = {0,0,3.31243};
		Cx2[] = {0,0,6.37277};
		CB[] = {0,0,0.268722};
		CinN[] = {0,2.87136,-0.000576986};
		CinE[] = {2.87868,0,-0.000576986};
		CinS[] = {0,-2.86826,-0.000576986};
		CinW[] = {-2.88969,0,-0.000576986};
		N[] = {0,2.46379,0.269223};
		E[] = {2.47112,0,0.269223};
		S[] = {0,-2.46097,0.269223};
		W[] = {-2.4783,0,0.269223};
		NE[] = {2.47112,2.46379,0.269223};
		NW[] = {-2.4783,2.46379,0.269223};
		SE[] = {2.47112,-2.46097,0.269223};
		SW[] = {-2.4783,-2.46097,0.269223};
		NF[] = {0,5.237,0};
		SF[] = {0,-5.237,0};
		EF[] = {5.237,0,0};
		WF[] = {-5.237,0,0};
		NWQF[] = {-1.30925,3.92775,0};
		NQF[] = {0,3.92775,0};
		NEQF[] = {1.30925,3.92775,0};
		SWQF[] = {-1.30925,-3.92775,0};
		SQF[] = {0,-3.92775,0};
		SEQF[] = {1.30925,-3.92775,0};
		ENQF[] = {3.92775,1.30925,0};
		EQF[] = {3.92775,0,0};
		ESQF[] = {3.92775,-1.30925,0};
		WNQF[] = {-3.92775,1.30925,0};
		WQF[] = {-3.92775,0,0};
		WSQF[] = {-3.92775,-1.30925,0};
		
		NWHF[] = {-1.30925,5.237,0};
		NEHF[] = {1.30925,5.237,0};
		SWHF[] = {-1.30925,-5.237,0};
		SEHF[] = {1.30925,-5.237,0};
		WNHF[] = {-5.237,1.30925,0};
		WSHF[] = {-5.237,-1.30925,0};
		ENHF[] = {5.237,1.30925,0};
		ESHF[] = {5.237,-1.30925,0};
		
    };
    class WoodFloor_SIM_EPOCH : WoodFloor_EPOCH
    {
        allowedSnapPoints[] = {"NF","SF","EF","WF","C","Cx2"};
        allowedSnapObjects[] = {"Const_floors_static_F","Constructions_foundation_F"};
        upgradeBuilding[] = {};
        removeParts[] = {};
    };
    class WoodFloor_Ghost_EPOCH : WoodFloor_SIM_EPOCH {};
	class WoodHalfFloor_EPOCH : Default
    {
        upgradeBuilding[] = {{"MetalHalfFloor_EPOCH",{{"ItemCorrugatedLg",2}}}};
        removeParts[] = {{"PartPlankPack",2}};
        simulClass = "WoodHalfFloor_SIM_EPOCH";
        staticClass = "WoodHalfFloor_EPOCH";
        GhostPreview = "WoodHalfFloor_Ghost_EPOCH";
        snapPointsPara[] = {"NF","SF","EF","WF","C","Cx2","CB","NWQF","NQF","NEQF","SWQF","SQF","SEQF","ENQF","EQF","ESQF","WNQF","WQF","WSQF","NWHF","NEHF","SWHF","SEHF","WNHF","WSHF","ENHF","ESHF"};
        snapPointsPerp[] = {"N","S","E","W","CinN","CinS","CinE","CinW"};
        energyCost = 0.2;
		// snap points for WoodHalfFloor_EPOCH
		C[] = {0,0,3.31243};
		Cx2[] = {0,0,6.37277};
		CB[] = {0,0,0.268722};
		CinN[] = {0,2.87136,-0.000576986};
		CinE[] = {1.444845,0,-0.000576986};
		CinS[] = {0,-2.86826,-0.000576986};
		CinW[] = {-1.444845,0,-0.000576986};
		N[] = {0,2.46379,0.269223};
		E[] = {1.15,0,0.269223};
		S[] = {0,-2.46097,0.269223};
		W[] = {-1.15,0,0.269223};
		NE[] = {1.23556,2.46379,0.269223};
		NW[] = {-1.23915,2.46379,0.269223};
		SE[] = {1.23556,-2.46097,0.269223};
		SW[] = {-1.23915,-2.46097,0.269223};
		NF[] = {0,5.237,0};
		SF[] = {0,-5.237,0};
		EF[] = {3.92775,0,0};
		WF[] = {-3.92775,0,0};
		NWQF[] = {-1.30925,3.92775,0};
		NQF[] = {0,3.92775,0};
		NEQF[] = {1.30925,3.92775,0};
		SWQF[] = {1.30925,-3.92775,0};
		SQF[] = {0,-3.92775,0};
		SEQF[] = {-1.30925,-3.92775,0};
		ENQF[] = {2.6185,1.30925,0};
		EQF[] = {2.6185,0,0};
		ESQF[] = {2.6185,-1.30925,0};
		WNQF[] = {-2.6185,1.30925,0};
		WQF[] = {-2.6185,0,0};
		WSQF[] = {-2.6185,-1.30925,0};
		
		NWHF[] = {-1.30925,5.237,0};
		NEHF[] = {1.30925,5.237,0};
		SWHF[] = {-1.30925,-5.237,0};
		SEHF[] = {1.30925,-5.237,0};
		WNHF[] = {-3.92775,1.30925,0};
		WSHF[] = {-3.92775,-1.30925,0};
		ENHF[] = {3.92775,1.30925,0};
		ESHF[] = {3.92775,-1.30925,0};
		
    };
    class WoodHalfFloor_SIM_EPOCH : WoodHalfFloor_EPOCH
    {
        allowedSnapPoints[] = {"C","Cx2","NF","SF","EF","WF","NQF","SQF","EQF","WQF","NWHF","NEHF","SWHF","SEHF","WNHF","WSHF","ENHF","ESHF"};
        allowedSnapObjects[] = {"Const_floors_static_F"};
        upgradeBuilding[] = {};
        removeParts[] = {};
    };
    class WoodHalfFloor_Ghost_EPOCH : WoodHalfFloor_SIM_EPOCH {};
	class WoodQuarterFloor_EPOCH : Default
    {
        upgradeBuilding[] = {{"MetalQuarterFloor_EPOCH",{{"ItemCorrugatedLg",1}}}};
        removeParts[] = {{"PartPlankPack",1}};
        simulClass = "WoodQuarterFloor_SIM_EPOCH";
        staticClass = "WoodQuarterFloor_EPOCH";
        GhostPreview = "WoodQuarterFloor_Ghost_EPOCH";
        snapPointsPara[] = {"NF","SF","EF","WF","C","Cx2","CB","NQF","SQF","EQF","WQF"};
        snapPointsPerp[] = {"N","S","E","W","CinN","CinS","CinE","CinW"};
        energyCost = 0.1;
		// snap points for WoodQuarterFloor_EPOCH
		C[] = {0,0,3.31243};
		Cx2[] = {0,0,6.37277};
		CB[] = {0,0,0.268722};
		CinN[] = {0,1.43568,-0.000576986};
		CinE[] = {1.444845,0,-0.000576986};
		CinS[] = {0,-1.43412,-0.000576986};
		CinW[] = {-1.444845,0,-0.000576986};
		N[] = {0,1.15,0.269223};
		E[] = {1.15,0,0.269223};
		S[] = {0,-1.15,0.269223};
		W[] = {-1.15,0,0.269223};
		NE[] = {1.23556,1.231895,0.269223};
		NW[] = {-1.23915,1.231895,0.269223};
		SE[] = {1.23556,-1.230485,0.269223};
		SW[] = {-1.23915,-1.230485,0.269223};
		NF[] = {0,3.92775,0};
		SF[] = {0,-3.92775,0};
		EF[] = {3.92775,0,0};
		WF[] = {-3.92775,0,0};
		NQF[] = {0,2.6185,0};
		SQF[] = {0,-2.6185,0};
		EQF[] = {2.6185,0,0};
		WQF[] = {-2.6185,0,0};
    };
	class WoodQuarterFloor_SIM_EPOCH : WoodQuarterFloor_EPOCH
    {
        allowedSnapPoints[] = {"C","Cx2","NWQF","NQF","NEQF","SWQF","SQF","SEQF","ENQF","EQF","ESQF","WNQF","WQF","WSQF"};
        allowedSnapObjects[] = {"Const_floors_static_F"};
        upgradeBuilding[] = {};
        removeParts[] = {};
    };
    class WoodQuarterFloor_Ghost_EPOCH : WoodQuarterFloor_SIM_EPOCH {};
    class MetalFloor_EPOCH : WoodFloor_EPOCH
    {
        upgradeBuilding[] = {{"CinderFloor_EPOCH",{{"CinderBlocks",3},{"MortarBucket",3}}}};
        removeParts[] = {{"ItemCorrugatedLg",1},{"ItemCorrugated",1}};
        simulClass = "MetalFloor_SIM_EPOCH";
        staticClass = "MetalFloor_EPOCH";
        GhostPreview = "MetalFloor_Ghost_EPOCH";
        energyCost = 0.5;
    };
    class MetalFloor_SIM_EPOCH : MetalFloor_EPOCH
	{
        allowedSnapPoints[] = {"NF","SF","EF","WF","C","Cx2"};
        allowedSnapObjects[] = {"Const_floors_static_F","Constructions_foundation_F"};
        upgradeBuilding[] = {};
        removeParts[] = {};
	};
    class MetalFloor_Ghost_EPOCH : MetalFloor_SIM_EPOCH {};
	class MetalHalfFloor_EPOCH : WoodHalfFloor_EPOCH
    {
        upgradeBuilding[] = {{"CinderHalfFloor_EPOCH",{{"CinderBlocks",2},{"MortarBucket",2}}}};
        removeParts[] = {{"ItemCorrugatedLg",1}};
        simulClass = "MetalHalfFloor_SIM_EPOCH";
        staticClass = "MetalHalfFloor_EPOCH";
        GhostPreview = "MetalHalfFloor_Ghost_EPOCH";
        energyCost = 0.2;
    };
    class MetalHalfFloor_SIM_EPOCH : MetalHalfFloor_EPOCH
	{
        allowedSnapPoints[] = {"C","Cx2","NF","SF","EF","WF","NWQF","NQF","NEQF","SWQF","SQF","SEQF","ENQF","EQF","ESQF","WNQF","WQF","WSQF","NWHF","NEHF","SWHF","SEHF","WNHF","WSHF","ENHF","ESHF"};
        allowedSnapObjects[] = {"Const_floors_static_F"};
        upgradeBuilding[] = {};
        removeParts[] = {};
	};
    class MetalHalfFloor_Ghost_EPOCH : MetalHalfFloor_SIM_EPOCH {};
	class MetalQuarterFloor_EPOCH : WoodQuarterFloor_EPOCH
    {
        upgradeBuilding[] = {{"CinderQuarterFloor_EPOCH",{{"CinderBlocks",1},{"MortarBucket",1}}}};
        removeParts[] = {{"ItemCorrugated",1}};
        simulClass = "MetalQuarterFloor_SIM_EPOCH";
        staticClass = "MetalQuarterFloor_EPOCH";
        GhostPreview = "MetalQuarterFloor_Ghost_EPOCH";
        energyCost = 0.1;
    };
    class MetalQuarterFloor_SIM_EPOCH : MetalQuarterFloor_EPOCH
	{
        allowedSnapPoints[] = {"C","Cx2","NWQF","NQF","NEQF","SWQF","SQF","SEQF","ENQF","EQF","ESQF","WNQF","WQF","WSQF"};
        allowedSnapObjects[] = {"Const_floors_static_F"};
        upgradeBuilding[] = {};
        removeParts[] = {};
	};
    class MetalQuarterFloor_Ghost_EPOCH : MetalQuarterFloor_SIM_EPOCH {};
    class CinderFloor_EPOCH : WoodFloor_EPOCH
    {
        upgradeBuilding[] = {};
        removeParts[] = {{"CinderBlocks",2},{"MortarBucket",1}};
        simulClass = "CinderFloor_SIM_EPOCH";
        staticClass = "CinderFloor_EPOCH";
        GhostPreview = "CinderFloor_Ghost_EPOCH";
        energyCost = 1;
    };
    class CinderFloor_SIM_EPOCH : CinderFloor_EPOCH
	{
        allowedSnapPoints[] = {"NF","SF","EF","WF","C","Cx2"};
        allowedSnapObjects[] = {"Const_floors_static_F","Constructions_foundation_F"};
        upgradeBuilding[] = {};
        removeParts[] = {};
	};
    class CinderFloor_Ghost_EPOCH : CinderFloor_SIM_EPOCH {};
	class CinderHalfFloor_EPOCH : WoodHalfFloor_EPOCH
    {
		upgradeBuilding[] = {};
        removeParts[] = {{"CinderBlocks",1},{"MortarBucket",1}};
        simulClass = "CinderHalfFloor_SIM_EPOCH";
        staticClass = "CinderHalfFloor_EPOCH";
        GhostPreview = "CinderHalfFloor_Ghost_EPOCH";
        energyCost = 0.5;
    };
    class CinderHalfFloor_SIM_EPOCH : CinderHalfFloor_EPOCH
	{
        allowedSnapPoints[] = {"C","Cx2","NF","SF","EF","WF","NWQF","NQF","NEQF","SWQF","SQF","SEQF","ENQF","EQF","ESQF","WNQF","WQF","WSQF","NWHF","NEHF","SWHF","SEHF","WNHF","WSHF","ENHF","ESHF"};
        allowedSnapObjects[] = {"Const_floors_static_F"};
        upgradeBuilding[] = {};
        removeParts[] = {};
	};
    class CinderHalfFloor_Ghost_EPOCH : CinderHalfFloor_SIM_EPOCH {};
	class CinderQuarterFloor_EPOCH : WoodQuarterFloor_EPOCH
    {
        upgradeBuilding[] = {};
        removeParts[] = {{"CinderBlocks",1}};
        simulClass = "CinderQuarterFloor_SIM_EPOCH";
        staticClass = "CinderQuarterFloor_EPOCH";
        GhostPreview = "CinderQuarterFloor_Ghost_EPOCH";
        energyCost = 0.25;
    };
    class CinderQuarterFloor_SIM_EPOCH : CinderQuarterFloor_EPOCH
	{
        allowedSnapPoints[] = {"C","Cx2","NWQF","NQF","NEQF","SWQF","SQF","SEQF","ENQF","EQF","ESQF","WNQF","WQF","WSQF"};
        allowedSnapObjects[] = {"Const_floors_static_F"};
        upgradeBuilding[] = {};
        removeParts[] = {};
	};
    class CinderQuarterFloor_Ghost_EPOCH : CinderQuarterFloor_SIM_EPOCH {};
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
		// snap points for CinderWall_EPOCH
		N[] = {0,0,3.06034};
		E[] = {5.237,0,0};
		W[] = {-5.237,0,0};
    };
    class CinderWall_window_EPOCH : Default
    {
        removeParts[] = {{"CinderBlocks",4},{"ItemCorrugatedLg",2},{"ItemGlass",1}};
        staticClass = "CinderWall_window_EPOCH";
        snapType = "snapPointsPara";
        snapPointsPara[] = {"N","E","W","CAM"};
        allowedSnapPoints[] = {"N","S","E","W"};
        energyCost = 0.5;
		// snap points for CinderWall_EPOCH
		N[] = {0,0,3.06034};
		E[] = {5.237,0,0};
		W[] = {-5.237,0,0};
		CAM[] = {0,-0.47,2.8};
    };
	// Kit_Garden
	class Garden_EPOCH : Default
    {
        removeParts[] = {{"Kit_Garden",1}};
        simulClass = "Garden_SIM_EPOCH";
        staticClass = "Garden_EPOCH";
        GhostPreview = "Garden_Ghost_EPOCH";
        snapPointsPara[] = {"NF","SF","EF","WF","C","CB"};
        snapPointsPerp[] = {"N","S","E","W","CinN","CinS","CinE","CinW"};
        energyCost = 0.5;
		// snap points for Garden_EPOCH
		C[] = {-0.000379709,0.000134847,2.6837};
		CB[] = {-0.000379709,0.000134847,0.279171};
		CinN[] = {-0.000379709,2.26851,0.0664249};
		CinE[] = {2.27378,0.000134847,0.0664249};
		CinS[] = {-0.000379709,-2.26579,0.0664249};
		CinW[] = {-2.28323,0.000134847,0.0664249};
		N[] = {-0.000379709,1.94653,0.279567};
		E[] = {1.95181,0.000134847,0.279567};
		S[] = {-0.000379709,-1.94403,0.279567};
		W[] = {-1.95824,0.000134847,0.279567};
		NE[] = {1.95181,1.94653,0.279567};
		NW[] = {-1.95824,1.94653,0.279567};
		SE[] = {1.95181,-1.94403,0.279567};
		SW[] = {-1.95824,-1.94403,0.279567};
		NF[] = {-0.000379709,4.13736,0.0668807};
		SF[] = {-0.000379709,-4.1371,0.0668807};
		EF[] = {4.13685,0.000134847,0.0668807};
		WF[] = {-4.13761,0.000134847,0.0668807};
    };
    class Garden_SIM_EPOCH : Garden_EPOCH
    {
        allowedSnapPoints[] = {"NF","SF","EF","WF","C"};
        allowedSnapObjects[] = {"Const_floors_static_F","Constructions_foundation_F"};
        removeParts[] = {};
    };
    class Garden_Ghost_EPOCH : Garden_SIM_EPOCH {};
	class BarbedWire_EPOCH : Default
    {
        removeParts[] = {{"ItemScraps",10},{"ItemRope",2}};
        simulClass = "BarbedWire_SIM_EPOCH";
        staticClass = "BarbedWire_EPOCH";
        GhostPreview = "BarbedWire_Ghost_EPOCH";
        energyCost = 0.5;
    };
	class BarbedWire_SIM_EPOCH : BarbedWire_EPOCH
    {
		allowedSnapObjects[] = {"BarbedWire_SIM_EPOCH"};
		removeParts[] = {};
	};
	class BarbedWire_Ghost_EPOCH : BarbedWire_SIM_EPOCH {};

    class CinderWallGarage_SIM_EPOCH : CinderWallGarage_EPOCH
    {
        allowedSnapObjects[] = {"Const_Cinder_static_F","Const_floors_static_F","Const_WoodWalls_static_F"};
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
        snapPointsPara[] = {"N","E","W","CAM"};
        allowedSnapPoints[] = {"N","S","E","W"};
		// snap points for CinderWallHalf_EPOCH
		N[] = {0,0,1.57378};
		E[] = {5.237,0,0};
		W[] = {-5.237,0,0};
		CAM[] = {0,-0.47,1.4};
    };
    class CinderWallHalf_SIM_EPOCH : CinderWallHalf_EPOCH
    {
        allowedSnapObjects[] = {"Const_Cinder_static_F","Const_floors_static_F","Const_WoodWalls_static_F"};
        removeParts[] = {};
        upgradeBuilding[] = {};
    };
    class CinderWallHalf_Ghost_EPOCH : CinderWallHalf_SIM_EPOCH {};
    class CinderWall_EPOCH : Default
    {
        upgradeBuilding[] = {{"CinderWallGarage_EPOCH",{{"ItemCorrugatedLg",1},{"CircuitParts",1}}},{"CinderWallDoorwHatch_EPOCH",{{"ItemCorrugatedLg",1},{"CircuitParts",1}}},{"CinderWall_window_EPOCH",{{"ItemCorrugatedLg",2},{"ItemGlass",1}}}};
        removeParts[] = {{"CinderBlocks",4},{"ItemRock",2}};
        simulClass = "CinderWall_SIM_EPOCH";
        staticClass = "CinderWall_EPOCH";
        GhostPreview = "CinderWall_EPOCH";
        snapType = "snapPointsPara";
        snapPointsPara[] = {"N","E","W","CAM"};
        allowedSnapPoints[] = {"N","S","E","W"};
        energyCost = 0.4;
		// snap points for CinderWall_EPOCH
		N[] = {0,0,3.06034};
		E[] = {5.237,0,0};
		W[] = {-5.237,0,0};
		CAM[] = {0,-0.47,2.8};
    };
    class CinderWall_SIM_EPOCH : CinderWall_EPOCH
    {
        allowedSnapObjects[] = {"Const_Cinder_static_F","Const_floors_static_F","Const_WoodWalls_static_F"};
        upgradeBuilding[] = {};
        removeParts[] = {};
    };
    class CinderWallDoorwHatch_EPOCH : Default
    {
        removeParts[] = {{"CinderBlocks",4},{"ItemCorrugatedLg",1},{"CircuitParts",1}};
        staticClass = "CinderWallDoorwHatch_EPOCH";
        snapType = "snapPointsPara";
        snapPointsPara[] = {"N","E","W","CAM"};
        allowedSnapPoints[] = {"N","S","E","W"};
		// snap points for CinderWall_EPOCH
		N[] = {0,0,3.06034};
		E[] = {5.237,0,0};
		W[] = {-5.237,0,0};
		CAM[] = {0,-0.47,2.8};
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
		// snap points for WoodLargeWall_EPOCH
		N[] = {0,0,3.06034};
		E[] = {5.237,0,0};
		W[] = {-5.237,0,0};
    };
    class WoodLargeWall_SIM_EPOCH : WoodLargeWall_EPOCH
    {
        upgradeBuilding[] = {};
        removeParts[] = {};
        allowedSnapObjects[] = {"Const_floors_static_F","Const_WoodWalls_static_F","Const_Cinder_static_F"};
    };
    class WoodLargeWall_Ghost_EPOCH : WoodLargeWall_SIM_EPOCH {};
	class JailWall_EPOCH : Default
    {
        upgradeBuilding[] = {{"JailWallDoor_EPOCH",{{"ItemPipe",2},{"ItemCorrugated",2}}}};
        removeParts[] = {{"ItemPipe",2},{"ItemScraps",2}};
        simulClass = "JailWall_SIM_EPOCH";
        staticClass = "JailWall_EPOCH";
        GhostPreview = "JailWall_Ghost_EPOCH";
        snapType = "snapPointsPara";
        snapPointsPara[] = {"N","E","W"};
        allowedSnapPoints[] = {"N","S","E","W"};
		// snap points for WoodLargeWall_EPOCH
		N[] = {0,0,3.06034};
		E[] = {5.237,0,0};
		W[] = {-5.237,0,0};
    };
    class JailWall_SIM_EPOCH : JailWall_EPOCH
    {
        upgradeBuilding[] = {};
        removeParts[] = {};
        allowedSnapObjects[] = {"Const_floors_static_F","Const_WoodWalls_static_F","Const_Cinder_static_F"};
    };
    class JailWall_Ghost_EPOCH : JailWall_SIM_EPOCH {};
    class JailWallDoor_EPOCH : Default
    {
        removeParts[] = {{"ItemPipe",3},{"ItemScraps",4}};
        staticClass = "JailWallDoor_EPOCH";
        snapType = "snapPointsPara";
        snapPointsPara[] = {"N","E","W"};
        allowedSnapPoints[] = {"N","S","E","W"};
		// snap points for WoodLargeWall_EPOCH
		N[] = {0,0,3.06034};
		E[] = {5.237,0,0};
		W[] = {-5.237,0,0};
    };
	class PlyThirdWall_EPOCH : Default
    {
        upgradeBuilding[] = {};
        removeParts[] = {{"PartPlankPack",1},{"ItemPlywoodPack",1}};
        simulClass = "PlyThirdWall_SIM_EPOCH";
        staticClass = "PlyThirdWall_EPOCH";
        GhostPreview = "PlyThirdWall_Ghost_EPOCH";
        snapType = "snapPointsPara";
        snapPointsPara[] = {"N","E","W"};
        allowedSnapPoints[] = {"N","S","E","W"};
		// snap points for WoodLargeWall_EPOCH
		N[] = {0,0,1.02012};
		E[] = {5.237,0,0};
		W[] = {-5.237,0,0};
    };
    class PlyThirdWall_SIM_EPOCH : PlyThirdWall_EPOCH
    {
        upgradeBuilding[] = {};
        removeParts[] = {};
        allowedSnapObjects[] = {"Const_floors_static_F","Const_WoodWalls_static_F","Const_Cinder_static_F"};
    };
    class PlyThirdWall_Ghost_EPOCH : PlyThirdWall_SIM_EPOCH {};
    class WoodWall1_EPOCH : Default
    {
        upgradeBuilding[] = {{"WoodWall2_EPOCH",{{"PartPlankPack",1}}},{"WoodLargeWallCor_EPOCH",{{"ItemCorrugated",1}}},{"WoodWallWindow_EPOCH",{{"ItemGlass",2}}},{"WoodWallGarage_EPOCH",{{"ItemPlywoodPack",1},{"PartPlankPack",4},{"CircuitParts",1}}}};
        removeParts[] = {{"PartPlankPack",2}};
        simulClass = "WoodWall1_SIM_EPOCH";
        staticClass = "WoodWall1_EPOCH";
        GhostPreview = "WoodWall1_EPOCH";
        snapType = "snapPointsPara";
        snapPointsPara[] = {"N","E","W","CAM"};
        allowedSnapPoints[] = {"N","S","E","W"};
        energyCost = 0.2;
		// snap points for WoodLargeWall_EPOCH
		N[] = {0,0,3.06034};
		E[] = {5.237,0,0};
		W[] = {-5.237,0,0};
		CAM[] = {0,-0.4,2.8};
    };
    class WoodWall1_SIM_EPOCH : WoodWall1_EPOCH
    {
        allowedSnapObjects[] = {"Const_floors_static_F","Const_WoodWalls_static_F","Const_Cinder_static_F"};
        energyCost = 0.2;
        upgradeBuilding[] = {};
        removeParts[] = {};
    };
    class WoodWallWindow_EPOCH : Default
    {
        removeParts[] = {{"ItemGlass",2},{"PartPlankPack",2}};
        staticClass = "WoodWallWindow_EPOCH";
        snapType = "snapPointsPara";
        snapPointsPara[] = {"N","E","W","CAM"};
        allowedSnapPoints[] = {"N","S","E","W"};
        energyCost = 0.5;
		// snap points for WoodLargeWall_EPOCH
		N[] = {0,0,3.06034};
		E[] = {5.237,0,0};
		W[] = {-5.237,0,0};
		CAM[] = {0,-0.4,2.8};
    };
    class WoodLargeWallCor_EPOCH : Default
    {
        upgradeBuilding[] = {{"WoodLargeWallDoorway_EPOCH",{{"PartPlankPack",1}}},{"MetalWallGarage_EPOCH",{{"ItemCorrugated",1},{"PartPlankPack",4},{"CircuitParts",1}}}};
        removeParts[] = {{"PartPlankPack",2},{"ItemCorrugated",1}};
        simulClass = "WoodLargeWallCor_SIM_EPOCH";
        staticClass = "WoodLargeWallCor_EPOCH";
        GhostPreview = "WoodLargeWallCor_EPOCH";
        snapType = "snapPointsPara";
        snapPointsPara[] = {"N","E","W","CAM"};
        allowedSnapPoints[] = {"N","S","E","W"};
        energyCost = 0.2;
        availableTextures[] = {"\x\addons\a3_epoch_assets\textures\cor\corrugated_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_black_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_blue_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_brown_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_green_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_orange_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_purple_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_red_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_teal_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_yellow_co.paa"};
		// snap points for WoodLargeWall_EPOCH
		N[] = {0,0,3.06034};
		E[] = {5.237,0,0};
		W[] = {-5.237,0,0};
		CAM[] = {0,-0.47,2.8};
    };
    class WoodLargeWallCor_SIM_EPOCH : WoodLargeWallCor_EPOCH
    {
        allowedSnapObjects[] = {"Const_floors_static_F","Const_WoodWalls_static_F","Const_Cinder_static_F"};
        upgradeBuilding[] = {};
        removeParts[] = {};
    };
	class MetalWallGarage_EPOCH : Default
	{
        removeParts[] = {{"PartPlankPack",2},{"ItemScraps",2},{"CircuitParts",1}};
        simulClass = "MetalWallGarage_SIM_EPOCH";
        staticClass = "MetalWallGarage_EPOCH";
        GhostPreview = "MetalWallGarage_EPOCH";
        snapType = "snapPointsPara";
        snapPointsPara[] = {"N","E","W"};
        allowedSnapPoints[] = {"N","S","E","W"};
        energyCost = 0.5;
		// snap points for CinderWall_EPOCH
		N[] = {0,0,3.06034};
		E[] = {5.237,0,0};
		W[] = {-5.237,0,0};
	};
    class MetalWallGarage_SIM_EPOCH : MetalWallGarage_EPOCH
    {
        allowedSnapObjects[] = {"Const_Cinder_static_F","Const_floors_static_F","Const_WoodWalls_static_F"};
        removeParts[] = {};
    };
	class WoodWallGarage_EPOCH : Default
	{
        removeParts[] = {{"PartPlankPack",2},{"CircuitParts",1}};
        simulClass = "WoodWallGarage_SIM_EPOCH";
        staticClass = "WoodWallGarage_EPOCH";
        GhostPreview = "WoodWallGarage_EPOCH";
        snapType = "snapPointsPara";
        snapPointsPara[] = {"N","E","W"};
        allowedSnapPoints[] = {"N","S","E","W"};
        energyCost = 0.5;
		// snap points for CinderWall_EPOCH
		N[] = {0,0,3.06034};
		E[] = {5.237,0,0};
		W[] = {-5.237,0,0};
	};
    class WoodWallGarage_SIM_EPOCH : MetalWallGarage_EPOCH
    {
        allowedSnapObjects[] = {"Const_Cinder_static_F","Const_floors_static_F","Const_WoodWalls_static_F"};
        removeParts[] = {};
    };
    class WoodWall2_EPOCH : Default
    {
        upgradeBuilding[] = {{"WoodWall3_EPOCH",{{"ItemPlywoodPack",1},{"PartPlankPack",1}}},{"WoodLargeWallDoor_EPOCH",{{"ItemCorrugated",1},{"PartPlankPack",1}}}};
        removeParts[] = {{"ItemPlywoodPack",1},{"PartPlankPack",2}};
        simulClass = "WoodWall2_SIM_EPOCH";
        staticClass = "WoodWall2_EPOCH";
        GhostPreview = "WoodWall2_EPOCH";
        snapPointsPara[] = {"N","E","W","CAM"};
        allowedSnapPoints[] = {"N","S","E","W"};
        energyCost = 0.2;
		// snap points for WoodLargeWall_EPOCH
		N[] = {0,0,3.06034};
		E[] = {5.237,0,0};
		W[] = {-5.237,0,0};
		CAM[] = {0,-0.4,2.8};
    };
    class WoodWall2_SIM_EPOCH : WoodWall2_EPOCH
    {
        allowedSnapObjects[] = {"Const_floors_static_F","Const_WoodWalls_static_F","Const_Cinder_static_F"};
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
        snapPointsPara[] = {"N","E","W","CAM"};
        allowedSnapPoints[] = {"N","S","E","W"};
        energyCost = 0.2;
        availableTextures[] = {"\x\addons\a3_epoch_assets\textures\cor\corrugated_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_black_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_blue_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_brown_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_green_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_orange_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_purple_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_red_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_teal_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_yellow_co.paa"};
		// snap points for WoodLargeWall_EPOCH
		N[] = {0,0,3.06034};
		E[] = {5.237,0,0};
		W[] = {-5.237,0,0};
		CAM[] = {0,-0.47,2.8};
    };
    class WoodLargeWallDoorway_SIM_EPOCH : WoodLargeWallDoorway_EPOCH
    {
        allowedSnapObjects[] = {"Const_floors_static_F","Const_WoodWalls_static_F","Const_Cinder_static_F"};
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
        snapPointsPara[] = {"N","E","W","CAM"};
        allowedSnapPoints[] = {"N","S","E","W"};
        energyCost = 0.2;
		// snap points for WoodLargeWall_EPOCH
		N[] = {0,0,3.06034};
		E[] = {5.237,0,0};
		W[] = {-5.237,0,0};
		CAM[] = {0,-0.4,2.8};
    };
    class WoodWall3_SIM_EPOCH : WoodWall3_EPOCH
    {
        allowedSnapObjects[] = {"Const_floors_static_F","Const_WoodWalls_static_F","Const_Cinder_static_F"};
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
        snapPointsPara[] = {"N","E","W","CAM"};
        allowedSnapPoints[] = {"N","S","E","W"};
        availableTextures[] = {"\x\addons\a3_epoch_assets\textures\cor\corrugated_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_black_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_blue_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_brown_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_green_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_orange_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_purple_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_red_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_teal_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_yellow_co.paa"};
        energyCost = 0.2;
		// snap points for WoodLargeWall_EPOCH
		N[] = {0,0,3.06034};
		E[] = {5.237,0,0};
		W[] = {-5.237,0,0};
		CAM[] = {0,-0.47,2.8};
    };
    class WoodLargeWallDoor_SIM_EPOCH : WoodLargeWallDoor_EPOCH
    {
        allowedSnapObjects[] = {"Const_floors_static_F","Const_WoodWalls_static_F","Const_Cinder_static_F"};
        upgradeBuilding[] = {};
        removeParts[] = {};
    };
    class WoodWall4_EPOCH : Default
    {
        removeParts[] = {{"ItemPlywoodPack",1},{"PartPlankPack",2},{"CircuitParts",1}};
        simulClass = "WoodWall4_SIM_EPOCH";
        staticClass = "WoodWall4_EPOCH";
        GhostPreview = "WoodWall4_EPOCH";
        snapPointsPara[] = {"N","E","W","CAM"};
        allowedSnapPoints[] = {"N","S","E","W"};
        energyCost = 0.2;
		// snap points for WoodLargeWall_EPOCH
		N[] = {0,0,3.06034};
		E[] = {5.237,0,0};
		W[] = {-5.237,0,0};
		CAM[] = {0,-0.4,2.8};
    };
    class WoodWall4_SIM_EPOCH : WoodWall4_EPOCH
    {
        allowedSnapObjects[] = {"Const_floors_static_F","Const_WoodWalls_static_F","Const_Cinder_static_F"};
        upgradeBuilding[] = {};
        removeParts[] = {};
    };
    class WoodLargeWallDoorL_EPOCH : Default
    {
        removeParts[] = {{"PartPlankPack",2},{"ItemCorrugated",1},{"CircuitParts",1}};
        simulClass = "WoodLargeWallDoorL_SIM_EPOCH";
        staticClass = "WoodLargeWallDoorL_EPOCH";
        GhostPreview = "WoodLargeWallDoorL_EPOCH";
        snapPointsPara[] = {"N","E","W","CAM"};
        allowedSnapPoints[] = {"N","S","E","W"};
        availableTextures[] = {"\x\addons\a3_epoch_assets\textures\cor\corrugated_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_black_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_blue_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_brown_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_green_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_orange_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_purple_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_red_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_teal_co.paa","\x\addons\a3_epoch_assets\textures\cor\corrugated_yellow_co.paa"};
        energyCost = 0.2;
		// snap points for WoodLargeWall_EPOCH
		N[] = {0,0,3.06034};
		E[] = {5.237,0,0};
		W[] = {-5.237,0,0};
		CAM[] = {0,-0.47,2.8};
    };
    class WoodLargeWallDoorL_SIM_EPOCH : WoodLargeWallDoorL_EPOCH
    {
        allowedSnapObjects[] = {"Const_floors_static_F","Const_WoodWalls_static_F","Const_Cinder_static_F"};
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
		// snap points for WoodStairs_EPOCH
		NF2[] = {0,5.237,0};
		SF2[] = {0,-5.237,0};
		EF2[] = {5.237,0,0};
		WF2[] = {-5.237,-0.003,0};
		C[] = {-0.000251044,-0.00293543,6.37273};
		CB[] = {-0.000299305,-0.000390954,3.32902};
		CinN[] = {0.0214193,2.87136,3.05972};
		CinE[] = {2.87868,-0.000390954,3.05972};
		CinS[] = {0.0214193,-2.86826,3.05972};
		CinW[] = {-2.88969,-0.000390954,3.05972};
		N[] = {0.0195083,2.46379,3.32952};
		E[] = {2.47112,-0.000253316,3.32952};
		S[] = {0.0195083,-2.46097,3.32952};
		W[] = {-2.4783,-0.000253316,3.32952};
		NE[] = {2.47112,2.46379,3.32952};
		NW[] = {-2.4783,2.46379,3.32952};
		SE[] = {2.47112,-2.46097,3.32952};
		SW[] = {-2.4783,-2.46097,3.32952};
		NF[] = {0,5.237,3.06};
		SF[] = {0,-5.237,3.06};
		EF[] = {5.237,0,3.06};
		WF[] = {-5.237,0,3.06};
		NWQF[] = {-1.30925,3.92775,3.06};
		NQF[] = {0,3.92775,3.06};
		NEQF[] = {1.30925,3.92775,3.06};
		SWQF[] = {-1.30925,-3.92775,3.06};
		SQF[] = {0,-3.92775,3.06};
		SEQF[] = {1.30925,-3.92775,3.06};
		ENQF[] = {3.92775,1.30925,3.06};
		EQF[] = {3.92775,0,3.06};
		ESQF[] = {3.92775,-1.30925,3.06};
		WNQF[] = {-3.92775,1.30925,3.06};
		WQF[] = {-3.92775,0,3.06};
		WSQF[] = {-3.92775,-1.30925,3.06};
		
		NWHF[] = {-1.30925,5.237,3.06};
		NEHF[] = {1.30925,5.237,3.06};
		SWHF[] = {-1.30925,-5.237,3.06};
		SEHF[] = {1.30925,-5.237,3.06};
		WNHF[] = {-5.237,1.30925,3.06};
		WSHF[] = {-5.237,-1.30925,3.06};
		ENHF[] = {5.237,1.30925,3.06};
		ESHF[] = {5.237,-1.30925,3.06};
		
    };
    class WoodStairs_SIM_EPOCH : WoodStairs_EPOCH
    {
        allowedSnapPoints[] = {"NF","SF","EF","WF","CB","CS"};
        allowedSnapObjects[] = {"Const_floors_static_F","Constructions_foundation_F"};
        upgradeBuilding[] = {};
        removeParts[] = {};
    };
    class WoodStairs_Ghost_EPOCH : WoodStairs_SIM_EPOCH {};
    class WoodStairs2_EPOCH : Default
    {
        upgradeBuilding[] = {{"WoodStairs3_EPOCH",{{"ItemPipe",1},{"CircuitParts",1}}}};
        removeParts[] = {{"PartPlankPack",4}};
        simulClass = "WoodStairs2_SIM_EPOCH";
        staticClass = "WoodStairs2_EPOCH";
        GhostPreview = "WoodStairs2_EPOCH";
        snapPointsPara[] = {"NF2","SF2","EF2","WF2","NF","SF","EF","WF","C","CB","NWQF","NQF","NEQF","SWQF","SQF","SEQF","ENQF","EQF","ESQF","WNQF","WQF","WSQF","NWHF","NEHF","SWHF","SEHF","WNHF","WSHF","ENHF","ESHF"};
        snapPointsPerp[] = {"N","S","E","W","CinN","CinS","CinE","CinW"};
        energyCost = 0.3;
		// snap points for WoodStairs_EPOCH
		NF2[] = {0,5.237,0};
		SF2[] = {0,-5.237,0};
		EF2[] = {5.237,0,0};
		WF2[] = {-5.237,-0.003,0};
		C[] = {-0.000251044,-0.00293543,6.37273};
		CB[] = {-0.000299305,-0.000390954,3.32902};
		CS[] = {-0.000251044,-0.00293543,3.060298};		// 2x WoodStairs without Space for Floor
		CinN[] = {0.0214193,2.87136,3.05972};
		CinE[] = {2.87868,-0.000390954,3.05972};
		CinS[] = {0.0214193,-2.86826,3.05972};
		CinW[] = {-2.88969,-0.000390954,3.05972};
		N[] = {0.0195083,2.46379,3.32952};
		E[] = {2.47112,-0.000253316,3.32952};
		S[] = {0.0195083,-2.46097,3.32952};
		W[] = {-2.4783,-0.000253316,3.32952};
		NE[] = {2.47112,2.46379,3.32952};
		NW[] = {-2.4783,2.46379,3.32952};
		SE[] = {2.47112,-2.46097,3.32952};
		SW[] = {-2.4783,-2.46097,3.32952};
		NF[] = {0,5.237,3.06};
		SF[] = {0,-5.237,3.06};
		EF[] = {5.237,0,3.06};
		WF[] = {-5.237,0,3.06};
		NWQF[] = {-1.30925,3.92775,3.06};
		NQF[] = {0,3.92775,3.06};
		NEQF[] = {1.30925,3.92775,3.06};
		SWQF[] = {-1.30925,-3.92775,3.06};
		SQF[] = {0,-3.92775,3.06};
		SEQF[] = {1.30925,-3.92775,3.06};
		ENQF[] = {3.92775,1.30925,3.06};
		EQF[] = {3.92775,0,3.06};
		ESQF[] = {3.92775,-1.30925,3.06};
		WNQF[] = {-3.92775,1.30925,3.06};
		WQF[] = {-3.92775,0,3.06};
		WSQF[] = {-3.92775,-1.30925,3.06};
		
		NWHF[] = {-1.30925,5.237,3.06};
		NEHF[] = {1.30925,5.237,3.06};
		SWHF[] = {-1.30925,-5.237,3.06};
		SEHF[] = {1.30925,-5.237,3.06};
		WNHF[] = {-5.237,1.30925,3.06};
		WSHF[] = {-5.237,-1.30925,3.06};
		ENHF[] = {5.237,1.30925,3.06};
		ESHF[] = {5.237,-1.30925,3.06};
		
    };
    class WoodStairs2_SIM_EPOCH : WoodStairs2_EPOCH
    {
        allowedSnapPoints[] = {"NF","SF","EF","WF","CB"};
        allowedSnapObjects[] = {"Const_floors_static_F","Constructions_foundation_F"};
        removeParts[] = {};
    };
    class WoodStairs3_EPOCH : Default
    {
		removeParts[] = {{"PartPlankPack",4},{"ItemPipe",1},{"CircuitParts",1}};
        simulClass = "WoodStairs3_SIM_EPOCH";
        staticClass = "WoodStairs3_EPOCH";
        GhostPreview = "WoodStairs3_EPOCH";
        snapPointsPara[] = {"NF2","SF2","EF2","WF2","NF","SF","EF","WF","C","CB","NWQF","NQF","NEQF","SWQF","SQF","SEQF","ENQF","EQF","ESQF","WNQF","WQF","WSQF","NWHF","NEHF","SWHF","SEHF","WNHF","WSHF","ENHF","ESHF"};
        snapPointsPerp[] = {"N","S","E","W","CinN","CinS","CinE","CinW"};
        energyCost = 0.3;
		// snap points for WoodStairs_EPOCH
		NF2[] = {0,5.237,0};
		SF2[] = {0,-5.237,0};
		EF2[] = {5.237,0,0};
		WF2[] = {-5.237,-0.003,0};
		C[] = {-0.000251044,-0.00293543,6.37273};
		CB[] = {-0.000299305,-0.000390954,3.32902};
		CS[] = {-0.000251044,-0.00293543,3.060298};		// 2x WoodStairs without Space for Floor
		CinN[] = {0.0214193,2.87136,3.05972};
		CinE[] = {2.87868,-0.000390954,3.05972};
		CinS[] = {0.0214193,-2.86826,3.05972};
		CinW[] = {-2.88969,-0.000390954,3.05972};
		N[] = {0.0195083,2.46379,3.32952};
		E[] = {2.47112,-0.000253316,3.32952};
		S[] = {0.0195083,-2.46097,3.32952};
		W[] = {-2.4783,-0.000253316,3.32952};
		NE[] = {2.47112,2.46379,3.32952};
		NW[] = {-2.4783,2.46379,3.32952};
		SE[] = {2.47112,-2.46097,3.32952};
		SW[] = {-2.4783,-2.46097,3.32952};
		NF[] = {0,5.237,3.06};
		SF[] = {0,-5.237,3.06};
		EF[] = {5.237,0,3.06};
		WF[] = {-5.237,0,3.06};
		NWQF[] = {-1.30925,3.92775,3.06};
		NQF[] = {0,3.92775,3.06};
		NEQF[] = {1.30925,3.92775,3.06};
		SWQF[] = {-1.30925,-3.92775,3.06};
		SQF[] = {0,-3.92775,3.06};
		SEQF[] = {1.30925,-3.92775,3.06};
		ENQF[] = {3.92775,1.30925,3.06};
		EQF[] = {3.92775,0,3.06};
		ESQF[] = {3.92775,-1.30925,3.06};
		WNQF[] = {-3.92775,1.30925,3.06};
		WQF[] = {-3.92775,0,3.06};
		WSQF[] = {-3.92775,-1.30925,3.06};
		
		NWHF[] = {-1.30925,5.237,3.06};
		NEHF[] = {1.30925,5.237,3.06};
		SWHF[] = {-1.30925,-5.237,3.06};
		SEHF[] = {1.30925,-5.237,3.06};
		WNHF[] = {-5.237,1.30925,3.06};
		WSHF[] = {-5.237,-1.30925,3.06};
		ENHF[] = {5.237,1.30925,3.06};
		ESHF[] = {5.237,-1.30925,3.06};
		
    };
    class WoodStairs3_SIM_EPOCH : WoodStairs3_EPOCH
    {
        allowedSnapPoints[] = {"NF","SF","EF","WF","CB"};
        allowedSnapObjects[] = {"Const_floors_static_F","Constructions_foundation_F"};
        removeParts[] = {};
    };
    class WoodTower_EPOCH : Default
    {
        removeParts[] = {{"PartPlankPack",4}};
		upgradeBuilding[] = {{"MetalTower_EPOCH",{{"ItemCorrugatedLg",4}}}};
        upgradeBuildingPart[] = {{"ItemPlywoodPack",1},{"PartPlankPack",2}};
        removeBuildingPart[] = {{"ItemPlywoodPack",1},{"PartPlankPack",2}};
        simulClass = "WoodTower_SIM_EPOCH";
        staticClass = "WoodTower_EPOCH";
        GhostPreview = "WoodTower_Ghost_EPOCH";
        snapPointsPara[] = {"NF2","SF2","EF2","WF2","NF","SF","EF","WF","C","CB"};
        snapPointsPerp[] = {"N","S","E","W","CinN","CinS","CinE","CinW"};
        persistAnimations[] = {"NWall","EWall","SWall","WWall"};
        energyCost = 0.3;
		// snap points for WoodTower_EPOCH
		NF2[] = {0,5.237,0};
		SF2[] = {0,-5.237,0};
		EF2[] = {5.237,0,0};
		WF2[] = {-5.237,-0.003,0};
		C[] = {-0.000251044,-0.00293543,6.36635};
		CB[] = {-0.000299305,-0.000390954,3.32569};
		CinN[] = {0.0214193,2.87136,3.05666};
		CinE[] = {2.87868,-0.000390954,3.05666};
		CinS[] = {0.0214193,-2.86826,3.05666};
		CinW[] = {-2.88969,-0.000390954,3.05666};
		N[] = {0.0195083,2.46379,3.32619};
		E[] = {2.47112,-0.000253316,3.32619};
		S[] = {0.0195083,-2.46097,3.32619};
		W[] = {-2.4783,-0.000253316,3.32619};
		NE[] = {2.47112,2.46379,3.32619};
		NW[] = {-2.4783,2.46379,3.32619};
		SE[] = {2.47112,-2.46097,3.32619};
		SW[] = {-2.4783,-2.46097,3.32619};
		NF[] = {0,5.237,3.05694};
		SF[] = {0,-5.237,3.05694};
		EF[] = {5.237,0,3.05694};
		WF[] = {-5.237,0,3.05694};
    };
    class WoodTower_SIM_EPOCH : WoodTower_EPOCH
    {
        allowedSnapPoints[] = {"NF2","SF2","EF2","WF2","CB"};
        allowedSnapObjects[] = {"WoodTower_EPOCH","Const_floors_static_F","Constructions_foundation_F"};
        energyCost = 0.3;
    };
    class WoodTower_Ghost_EPOCH : WoodTower_SIM_EPOCH {};
	class MetalTower_EPOCH : WoodTower_EPOCH
    {
        removeParts[] = {{"ItemCorrugatedLg",2}};
		upgradeBuilding[] = {{"CinderTower_EPOCH",{{"CinderBlocks",4},{"MortarBucket",4}}}};
        upgradeBuildingPart[] = {{"ItemCorrugatedLg",2}};
        removeBuildingPart[] = {{"ItemCorrugatedLg",1}};
        simulClass = "MetalTower_SIM_EPOCH";
        staticClass = "MetalTower_EPOCH";
        GhostPreview = "MetalTower_Ghost_EPOCH";
        energyCost = 0.4;
    };
    class MetalTower_SIM_EPOCH : MetalTower_EPOCH
    {
        allowedSnapPoints[] = {"NF2","SF2","EF2","WF2","CB"};
        allowedSnapObjects[] = {"MetalTower_EPOCH","Const_floors_static_F","Constructions_foundation_F"};
    };
    class MetalTower_Ghost_EPOCH : MetalTower_SIM_EPOCH {};
	class CinderTower_EPOCH : WoodTower_EPOCH
    {
        removeParts[] = {{"CinderBlocks",2},{"MortarBucket",2}};
        upgradeBuildingPart[] = {{"CinderBlocks",2},{"MortarBucket",2}};
        removeBuildingPart[] = {{"CinderBlocks",2}};
        simulClass = "CinderTower_SIM_EPOCH";
        staticClass = "CinderTower_EPOCH";
        GhostPreview = "CinderTower_Ghost_EPOCH";
        energyCost = 0.5;
    };
    class CinderTower_SIM_EPOCH : CinderTower_EPOCH
    {
        allowedSnapPoints[] = {"NF2","SF2","EF2","WF2","CB"};
        allowedSnapObjects[] = {"CinderTower_EPOCH","Const_floors_static_F","Constructions_foundation_F"};
    };
    class CinderTower_Ghost_EPOCH : CinderTower_SIM_EPOCH {};

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
	class TentA_EPOCH  : Default
    {
        removeParts[] = {{"KitTentA",1}};
        GhostPreview = "TentA_Ghost_EPOCH";
        staticClass = "TentA_EPOCH";
        simulClass = "TentA_SIM_EPOCH";
        limitNearby = 2;
        bypassJammer = 1;
    };
    class TentA_SIM_EPOCH : TentA_EPOCH
    {
        simulClass = "TentA_SIM_EPOCH";
        staticClass = "TentA_EPOCH";
        limitNearby = 2;
        bypassJammer = 1;
        removeParts[] = {};
    };
	class TentA_Ghost_EPOCH : TentA_SIM_EPOCH {};
	class TentDome_EPOCH  : Default
	{
		removeParts[] = {{"KitTentDome",1}};
		GhostPreview = "TentDome_Ghost_EPOCH";
		staticClass = "TentDome_EPOCH";
		simulClass = "TentDome_SIM_EPOCH";
		limitNearby = 2;
		bypassJammer = 1;
	};
	class TentDome_SIM_EPOCH : TentA_EPOCH
	{
		simulClass = "TentDome_SIM_EPOCH";
		staticClass = "TentDome_EPOCH";
		limitNearby = 2;
		bypassJammer = 1;
		removeParts[] = {};
	};
	class TentDome_Ghost_EPOCH : TentDome_SIM_EPOCH {};
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
    class SolarCharger_EPOCH : Default
    {
        removeParts[] = {{"KitSolarCharger",1}};
        GhostPreview = "SolarCharger_Ghost_EPOCH";
        staticClass = "SolarCharger_EPOCH";
        simulClass = "SolarCharger_SIM_EPOCH";
    };
    class SolarCharger_SIM_EPOCH : SolarCharger_EPOCH
    {
        removeParts[] = {};
    };
    class SolarCharger_Ghost_EPOCH : SolarCharger_SIM_EPOCH {};
    class SolarChargerXL_EPOCH : Default
    {
        removeParts[] = {{"KitSolarChargerXL",1}};
        GhostPreview = "SolarChargerXL_Ghost_EPOCH";
        staticClass = "SolarChargerXL_EPOCH";
        simulClass = "SolarChargerXL_SIM_EPOCH";
    };
    class SolarChargerXL_SIM_EPOCH : SolarChargerXL_EPOCH
    {
        removeParts[] = {};
    };
    class SolarChargerXL_Ghost_EPOCH : SolarChargerXL_SIM_EPOCH {};
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
    class Safe_s_EPOCH : Default
    {
        returnOnPack[] = {{"ItemSafe_s",1}};
        simulClass = "Safe_s_SIM_EPOCH";
        staticClass = "Safe_s_EPOCH";
        weaponHolderProxy = "SafeProxy_EPOCH";
        GhostPreview = "Safe_s_EPOCH";
        bypassJammer = 1;
        limitNearby = 2;
        isSecureStorage = 1;
    };
    class Safe_s_SIM_EPOCH : Safe_s_EPOCH
    {
        returnOnPack[] = {};
    };
    class GunSafe_EPOCH : Default
    {
        returnOnPack[] = {{"ItemGunSafe",1}};
        simulClass = "GunSafe_SIM_EPOCH";
        staticClass = "GunSafe_EPOCH";
        weaponHolderProxy = "SafeProxy_EPOCH";
        GhostPreview = "GunSafe_EPOCH";
        bypassJammer = 1;
        limitNearby = 2;
        isSecureStorage = 1;
    };
    class GunSafe_SIM_EPOCH : GunSafe_EPOCH
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
    class BurnBarrel_EPOCH : Default
    {
        removeParts[] = {{"KitBurnBarrel",1}};
        GhostPreview = "BurnBarrel_Ghost_EPOCH";
        staticClass = "BurnBarrel_EPOCH";
        simulClass = "BurnBarrel_SIM_EPOCH";
    };
    class BurnBarrel_SIM_EPOCH : BurnBarrel_EPOCH
    {
        removeParts[] = {};
    };
    class BurnBarrel_Ghost_EPOCH : BurnBarrel_SIM_EPOCH {};
    class LightPole_EPOCH : Default
    {
        removeParts[] = {{"KitLightPole",1}};
        GhostPreview = "LightPole_Ghost_EPOCH";
        staticClass = "LightPole_EPOCH";
        simulClass = "LightPole_SIM_EPOCH";
    };
    class LightPole_SIM_EPOCH : LightPole_EPOCH
    {
        removeParts[] = {};
    };
    class LightPole_Ghost_EPOCH : LightPole_SIM_EPOCH {};
    class SmallForestCamoNet_EPOCH : Default
    {
        removeParts[] = {{"KitSmallForestCamoNet",1}};
        GhostPreview = "SmallForestCamoNet_Ghost_EPOCH";
        staticClass = "SmallForestCamoNet_EPOCH";
        simulClass = "SmallForestCamoNet_SIM_EPOCH";
    };
    class SmallForestCamoNet_SIM_EPOCH : SmallForestCamoNet_EPOCH
    {
        removeParts[] = {};
    };
    class SmallForestCamoNet_Ghost_EPOCH : SmallForestCamoNet_SIM_EPOCH {};
    class SmallDesertCamoNet_EPOCH : Default
    {
        removeParts[] = {{"KitSmallDesertCamoNet",1}};
        GhostPreview = "SmallDesertCamoNet_Ghost_EPOCH";
        staticClass = "SmallDesertCamoNet_EPOCH";
        simulClass = "SmallDesertCamoNet_SIM_EPOCH";
    };
    class SmallDesertCamoNet_SIM_EPOCH : SmallDesertCamoNet_EPOCH
    {
        removeParts[] = {};
    };
    class SmallDesertCamoNet_Ghost_EPOCH : SmallDesertCamoNet_SIM_EPOCH {};
    class LargeForestCamoNet_EPOCH : Default
    {
        removeParts[] = {{"KitLargeForestCamoNet",1}};
        GhostPreview = "LargeForestCamoNet_Ghost_EPOCH";
        staticClass = "LargeForestCamoNet_EPOCH";
        simulClass = "LargeForestCamoNet_SIM_EPOCH";
    };
    class LargeForestCamoNet_SIM_EPOCH : LargeForestCamoNet_EPOCH
    {
        removeParts[] = {};
    };
    class LargeForestCamoNet_Ghost_EPOCH : LargeForestCamoNet_SIM_EPOCH {};
    class LargeDesertCamoNet_EPOCH : Default
    {
        removeParts[] = {{"KitLargeDesertCamoNet",1}};
        GhostPreview = "LargeDesertCamoNet_Ghost_EPOCH";
        staticClass = "LargeDesertCamoNet_EPOCH";
        simulClass = "LargeDesertCamoNet_SIM_EPOCH";
    };
    class LargeDesertCamoNet_SIM_EPOCH : LargeDesertCamoNet_EPOCH
    {
        removeParts[] = {};
    };
    class LargeDesertCamoNet_Ghost_EPOCH : LargeDesertCamoNet_SIM_EPOCH {};
    class FirePlace_02_EPOCH : Default
    {
        removeParts[] = {{"KitFirePlace_02",1}};
        GhostPreview = "FirePlace_02_Ghost_EPOCH";
        staticClass = "FirePlace_02_EPOCH";
        simulClass = "FirePlace_02_SIM_EPOCH";
    };
    class FirePlace_02_SIM_EPOCH : FirePlace_02_EPOCH
    {
        removeParts[] = {};
    };
    class FirePlace_02_Ghost_EPOCH : FirePlace_02_SIM_EPOCH {};
    class FieldToilet_EPOCH : Default
    {
        removeParts[] = {{"KitFieldToilet",1}};
        GhostPreview = "FieldToilet_Ghost_EPOCH";
        staticClass = "FieldToilet_EPOCH";
        simulClass = "FieldToilet_SIM_EPOCH";
    };
    class FieldToilet_SIM_EPOCH : FieldToilet_EPOCH
    {
        removeParts[] = {};
    };
    class FieldToilet_Ghost_EPOCH : FieldToilet_SIM_EPOCH {};
    class Scaffolding_EPOCH : Default
    {
        removeParts[] = {{"KitScaffolding",1}};
        GhostPreview = "Scaffolding_Ghost_EPOCH";
        staticClass = "Scaffolding_EPOCH";
        simulClass = "Scaffolding_SIM_EPOCH";
    };
    class Scaffolding_SIM_EPOCH : Scaffolding_EPOCH
    {
        removeParts[] = {};
    };
    class Scaffolding_Ghost_EPOCH : Scaffolding_SIM_EPOCH {};
    class Sink_EPOCH : Default
    {
        removeParts[] = {{"KitSink",1}};
        GhostPreview = "Sink_Ghost_EPOCH";
        staticClass = "Sink_EPOCH";
        simulClass = "Sink_SIM_EPOCH";
    };
    class Sink_SIM_EPOCH : Sink_EPOCH
    {
        removeParts[] = {};
    };
    class Sink_Ghost_EPOCH : Sink_SIM_EPOCH {};
    class PortableLight_Single_EPOCH : Default
    {
        removeParts[] = {{"KitPortableLight_Single",1}};
        GhostPreview = "PortableLight_Single_Ghost_EPOCH";
        staticClass = "PortableLight_Single_EPOCH";
        simulClass = "PortableLight_Single_SIM_EPOCH";
    };
    class PortableLight_Single_SIM_EPOCH : PortableLight_Single_EPOCH
    {
        removeParts[] = {};
    };
    class PortableLight_Single_Ghost_EPOCH : PortableLight_Single_SIM_EPOCH {};
    class PortableLight_Double_EPOCH : Default
    {
        removeParts[] = {{"KitPortableLight_Double",1}};
        GhostPreview = "PortableLight_Double_Ghost_EPOCH";
        staticClass = "PortableLight_Double_EPOCH";
        simulClass = "PortableLight_Double_SIM_EPOCH";
    };
    class PortableLight_Double_SIM_EPOCH : PortableLight_Double_EPOCH
    {
        removeParts[] = {};
    };
    class PortableLight_Double_Ghost_EPOCH : PortableLight_Double_SIM_EPOCH {};
    class WatchTower_EPOCH : Default
    {
        removeParts[] = {{"KitWatchTower",1}};
        GhostPreview = "WatchTower_Ghost_EPOCH";
        staticClass = "WatchTower_EPOCH";
        simulClass = "WatchTower_SIM_EPOCH";
    };
    class WatchTower_SIM_EPOCH : WatchTower_EPOCH
    {
        removeParts[] = {};
    };
    class WatchTower_Ghost_EPOCH : WatchTower_SIM_EPOCH {};
    class SunShade_EPOCH : Default
    {
        removeParts[] = {{"KitSunShade",1}};
        GhostPreview = "SunShade_Ghost_EPOCH";
        staticClass = "SunShade_EPOCH";
        simulClass = "SunShade_SIM_EPOCH";
    };
    class SunShade_SIM_EPOCH : SunShade_EPOCH
    {
        removeParts[] = {};
    };
    class SunShade_Ghost_EPOCH : SunShade_SIM_EPOCH {};
    class FuelPump_EPOCH : Default
    {
        removeParts[] = {{"KitFuelPump",1}};
        GhostPreview = "FuelPump_Ghost_EPOCH";
        staticClass = "FuelPump_EPOCH";
        simulClass = "FuelPump_SIM_EPOCH";
    };
    class FuelPump_SIM_EPOCH : FuelPump_EPOCH
    {
        removeParts[] = {};
    };
    class FuelPump_Ghost_EPOCH : FuelPump_SIM_EPOCH {};
    class BagBunker_EPOCH : Default
    {
        removeParts[] = {{"KitBagBunker",1}};
        GhostPreview = "BagBunker_Ghost_EPOCH";
        staticClass = "BagBunker_EPOCH";
        simulClass = "BagBunker_SIM_EPOCH";
    };
    class BagBunker_SIM_EPOCH : BagBunker_EPOCH
    {
        removeParts[] = {};
    };
    class BagBunker_Ghost_EPOCH : BagBunker_SIM_EPOCH {};
    class SandbagWall_EPOCH : Default
    {
        removeParts[] = {{"KitSandbagWall",1}};
        GhostPreview = "SandbagWall_Ghost_EPOCH";
        staticClass = "SandbagWall_EPOCH";
        simulClass = "SandbagWall_SIM_EPOCH";
    };
    class SandbagWall_SIM_EPOCH : SandbagWall_EPOCH
    {
        removeParts[] = {};
    };
    class SandbagWall_Ghost_EPOCH : SandbagWall_SIM_EPOCH {};
    class SandbagWallLong_EPOCH : Default
    {
        removeParts[] = {{"KitSandbagWallLong",1}};
        GhostPreview = "SandbagWallLong_Ghost_EPOCH";
        staticClass = "SandbagWallLong_EPOCH";
        simulClass = "SandbagWallLong_SIM_EPOCH";
    };
    class SandbagWallLong_SIM_EPOCH : SandbagWallLong_EPOCH
    {
        removeParts[] = {};
    };
    class SandbagWallLong_Ghost_EPOCH : SandbagWallLong_SIM_EPOCH {};
    class BarGate_EPOCH : Default
    {
        removeParts[] = {{"KitBarGate",1}};
        GhostPreview = "BarGate_Ghost_EPOCH";
        staticClass = "BarGate_EPOCH";
        simulClass = "BarGate_SIM_EPOCH";
    };
    class BarGate_SIM_EPOCH : BarGate_EPOCH
    {
        removeParts[] = {};
    };
    class BarGate_Ghost_EPOCH : BarGate_SIM_EPOCH {};
    class WaterPump_EPOCH : Default
    {
        removeParts[] = {{"KitWaterPump",1}};
        GhostPreview = "WaterPump_Ghost_EPOCH";
        staticClass = "WaterPump_EPOCH";
        simulClass = "WaterPump_SIM_EPOCH";
    };
    class WaterPump_SIM_EPOCH : WaterPump_EPOCH
    {
        removeParts[] = {};
    };
    class WaterPump_Ghost_EPOCH : WaterPump_SIM_EPOCH {};
    class BaseCam_EPOCH : Default
    {
        removeParts[] = {{"BaseCam",1}};
        GhostPreview = "BaseCam_Ghost_EPOCH";
        staticClass = "BaseCam_EPOCH";
        simulClass = "BaseCam_SIM_EPOCH";
    };
    class BaseCam_SIM_EPOCH : BaseCam_EPOCH
    {
        removeParts[] = {};
        allowedSnapPoints[] = {"CAM"};
        allowedSnapObjects[] = {"Const_WoodWalls_static_F","Const_Cinder_static_F"};
    };
    class BaseCam_Ghost_EPOCH : BaseCam_SIM_EPOCH {};
    class BaseCamTerminal_EPOCH : Default
    {
        removeParts[] = {{"BaseCamTerminal",1}};
        GhostPreview = "BaseCamTerminal_Ghost_EPOCH";
        staticClass = "BaseCamTerminal_EPOCH";
        simulClass = "BaseCamTerminal_SIM_EPOCH";
    };
    class BaseCamTerminal_SIM_EPOCH : BaseCamTerminal_EPOCH
    {
        removeParts[] = {};
    };
    class BaseCamTerminal_Ghost_EPOCH : BaseCamTerminal_SIM_EPOCH {};
    class snowman_EPOCH : Default
    {
        removeParts[] = {{1,"KitSnowman"}};
        GhostPreview = "snowman_Ghost_EPOCH";
        staticClass = "snowman_EPOCH";
        simulClass = "snowman_SIM_EPOCH";
    };
    class snowman_SIM_EPOCH : snowman_EPOCH
    {
        removeParts[] = {};
    };
    class snowman_Ghost_EPOCH : snowman_SIM_EPOCH {};
};

/*[[[end]]]*/
