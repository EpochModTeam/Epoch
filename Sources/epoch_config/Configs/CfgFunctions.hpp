/*[[[cog from arma_config_tools import *; json_to_arma()]]]*/
/*
    @author = "Aaron Clark - https://EpochMod.com";
    @contributors[] = {};
    @description = "Epoch cfgfunctions";
    @licence = "Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike";
    @github = "https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_config/Configs/CfgFunctions.hpp";
*/
class cfgFunctions
{
    class A3
    {
        tag = "BIS";
        class functions
        {
            class returnVector
            {
                file = "epoch_code\compile\bis_functions\returnVector.sqf";
            };
        };
    };
    class EPOCH
    {
        tag = "EPOCH";
        class functions
        {
            class arrayToLogic
            {
                file = "epoch_code\compile\functions\EPOCH_fnc_arrayToLogic.sqf";
            };
            class returnConfigEntryV2
            {
                file = "epoch_code\compile\functions\EPOCH_fn_returnConfigEntryV2.sqf";
            };
            class isAny
            {
                file = "epoch_code\compile\both\EPOCH_isAny.sqf";
            };
			class weightedArray
            {
                file = "epoch_code\compile\both\EPOCH_weightedArray.sqf";
            };
            class compiler
            {
                file = "epoch_code\compile\both\EPOCH_compiler.sqf";
            };
        };
        class Client
        {
            class init
            {
                file = "epoch_code\init\fn_init.sqf";
                preInit = 1;
            };
            class postinit
            {
                file = "epoch_code\init\fn_postinit.sqf";
                postInit = 1;
            };
        };
    };
};

/*[[[end]]]*/
