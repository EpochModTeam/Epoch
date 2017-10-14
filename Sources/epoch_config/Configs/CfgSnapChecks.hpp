/*[[[cog from arma_config_tools import *; json_to_arma()]]]*/
/*
    @author = "Aaron Clark - https://EpochMod.com";
    @contributors[] = {};
    @description = "Custom Epoch config for base building Snap check offsets";
    @licence = "Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike";
    @github = "https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_config/Configs/CfgSnapChecks.hpp";
*/
class CfgSnapChecks
{
    class Hesco3_EPOCH
    {
        nails[] = {{{1.6,0,-0.6},{1.6,0,-0.75}},{{-1.6,0,-0.6},{-1.6,0,-0.75}},{{0,0,-0.0307557},{1.8625,0,-0.0307557}},{{0,0,-0.0307557},{-1.8625,0,-0.0307557}}};
    };
    class WoodLargeWall_EPOCH
    {
        nails[] = {{{2.46932,0,0.120775},{2.46932,0,-0.190775}},{{-2.46932,0,0.120775},{-2.46932,0,-0.190775}},{{0,0,1.5},{2.76932,0,1.5}},{{0,0,1.5},{-2.76932,0,1.5}}};
    };
    class WoodWall1_EPOCH : WoodLargeWall_EPOCH {};
    class WoodWall2_EPOCH : WoodLargeWall_EPOCH {};
    class WoodWall3_EPOCH : WoodLargeWall_EPOCH {};
    class WoodWall4_EPOCH : WoodLargeWall_EPOCH {};
    class WoodLargeWallCor_EPOCH : WoodLargeWall_EPOCH {};
    class WoodLargeWallDoorway_EPOCH : WoodLargeWall_EPOCH {};
    class WoodLargeWallDoor_EPOCH : WoodLargeWall_EPOCH {};
    class WoodLargeWallDoorL_EPOCH : WoodLargeWall_EPOCH {};
    class CinderWallGarage_EPOCH : WoodLargeWall_EPOCH {};
    class CinderWallDoorwHatch_EPOCH : WoodLargeWall_EPOCH {};
    class CinderWall_EPOCH : WoodLargeWall_EPOCH {};
    class CinderWallHalf_EPOCH : WoodLargeWall_EPOCH {};
    class WoodFloor_Epoch
    {
        nails[] = {{{0,0,0.15},{2.8555,0,0.15}},{{0,0,0.15},{0,2.8555,0.15}},{{0,0,0.15},{-2.8555,0,0.15}},{{0,0,0.15},{0,-2.8555,0.15}},{{2.5555,0,0.15},{2.5555,0,-0.15}},{{-2.5555,0,0.15},{-2.5555,0,-0.15}},{{0,-2.5555,0.15},{0,-2.5555,-0.15}},{{0,2.5555,0.15},{0,2.5555,-0.15}}};
    };
    class WoodHalfFloor_EPOCH
    {
        nails[] = {{{0,0,0.15},{1.42775,0,0.15}},{{0,0,0.15},{0,2.8555,0.15}},{{0,0,0.15},{-1.42775,0,0.15}},{{0,0,0.15},{0,-2.8555,0.15}},{{1.12775,0,0.15},{1.12775,0,-0.15}},{{-1.12775,0,0.15},{-1.12775,0,-0.15}},{{0,-2.5555,0.15},{0,-2.5555,-0.15}},{{0,2.5555,0.15},{0,2.5555,-0.15}}};
    };
    class WoodQuarterFloor_EPOCH
    {
        nails[] = {{{0,0,0.15},{1.42775,0,0.15}},{{0,0,0.15},{0,1.42775,0.15}},{{0,0,0.15},{-1.42775,0,0.15}},{{0,0,0.15},{0,-1.42775,0.15}},{{1.12775,0,0.15},{1.12775,0,-0.15}},{{-1.12775,0,0.15},{-1.12775,0,-0.15}},{{0,-1.12775,0.15},{0,-1.12775,-0.15}},{{0,1.12775,0.15},{0,1.12775,-0.15}}};
    };
    class MetalFloor_EPOCH : WoodFloor_Epoch {};
    class CinderFloor_EPOCH : WoodFloor_Epoch {};
    class WoodStairs_EPOCH
    {
        nails[] = {{{0.1,0,0.05},{0.1,0,-0.2}},{{-0.1,0,0.05},{-0.1,0,-0.2}}};
    };
    class WoodStairs2_EPOCH : WoodStairs_EPOCH {};
    class WoodTower_EPOCH : WoodStairs_EPOCH {};
    class MetalTower_EPOCH : WoodStairs_EPOCH {};
    class CinderTower_EPOCH : WoodStairs_EPOCH {};
    class WoodRamp_EPOCH : WoodStairs_EPOCH {};
};

/*[[[end]]]*/
