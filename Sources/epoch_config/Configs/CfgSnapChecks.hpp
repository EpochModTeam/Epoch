// Snap Checks - EpochMod.com
class Hesco3_EPOCH {
    nails[] = {
        {{0,0,-0.6},{0,0,-0.75}},
        {{1.6,0,-0.0307557},{1.8625,0,-0.0307557}},
        {{-1.6,0,-0.0307557},{-1.8625,0,-0.0307557}}
    };
};
class WoodLargeWall_EPOCH {
    nails[] = {
        {{0,0,0.120775},{0,0,-0.190775}},
        {{2.46932,0,1.5},{2.76932,0,1.5}},
        {{-2.46932,0,1.5},{-2.76932,0,1.5}}
    };
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
class CinderWall_EPOCH : WoodLargeWall_EPOCH {};
class CinderWallHalf_EPOCH : WoodLargeWall_EPOCH {};
class WoodFloor_Epoch {
    nails[] = {
        {{2.5555,0,0.15},{2.8555,0,0.15}},
        {{0,-2.5555,0.15},{0,2.8555,0.15}},
        {{-2.5555,0,0.15},{-2.8555,0,0.15}},
        {{0,-2.5555,0.15},{0,-2.8555,0.15}},

        {{2.5555,0,0.15},{2.5555,0,-0.15}},
        {{-2.5555,0,0.15},{-2.5555,0,-0.15}},
        {{0,-2.5555,0.15},{0,-2.5555,-0.15}},
        {{0,2.5555,0.15},{0,2.5555,-0.15}}
    };
};
class MetalFloor_EPOCH : WoodFloor_Epoch {};
class WoodStairs_EPOCH {
    nails[] = {
        {{0,0,0.05},{0,0,-0.20}}
    };
};
class WoodStairs2_EPOCH : WoodStairs_EPOCH {};
class WoodTower_EPOCH : WoodStairs_EPOCH {};
class WoodRamp_EPOCH : WoodStairs_EPOCH {};
