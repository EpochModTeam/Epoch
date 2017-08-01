/*
defaultPos:
	0 - top left
	1 - top center
	2 - top right
	3 - mid left
	4 - mid center
	5 - mid right
	6 - bottom left
	7 - bottom center
	8 - bottom right

defaultPopulate:
	0 - right
	1 - left
	2 - down
	3 - up
	4 - horizontal grow
	5 - vertical grow

offSetX: Positive = right, Negative = left
offSetY: Positive = down, Negative = up
	Offsets group of controls, unit measurement is width or height of group. The bigger the group the more it will be offset.
	Offsets are optional, don't have to be included

classname:
	https://community.bistudio.com/wiki/ctrlCreate/classnames

Obtaining Controls:
	use epoch_getHUDCtrl function to obtain controls for manipulation
	_name = Config name of your group
	_index = each group hosts multiple elements, each element has it's index, starting from 1! Don't use 0 as it returns configName
	[_ConfigName, _index] call epoch_getHUDCtrl;
	["myHUDname", 3] call epoch_getHUDCtrl;
*/
/*[[[cog from arma_config_tools import *; json_to_arma()]]]*/
/*
    @author = "Raimonds Virtoss - https://EpochMod.com";
    @contributors[] = {};
    @description = "Epoch dynamic player HUD config";
    @licence = "Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike";
    @github = "https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_config/Configs/CfgDynamicHUD.hpp";
*/
class rmx_dynamicHUD
{
    class topRight
    {
        classname = "RscPictureKeepAspect";
        defaultPos = 2;
        defaultPopulate = 1;
        arraySize = 10;
        width = 4;
        height = 4;
        offSetX = 0;
        offSetY = 1.3;
        angle[] = {-5,0.5,0.5,0.5};
        scale[] = {1,0.05};
    };
    class fav_pic_bg
    {
        classname = "RscPictureKeepAspect";
        defaultPos = 7;
        defaultPopulate = 0;
        arraySize = 5;
        width = 4;
        height = 4;
    };
    class fav_pic
    {
        classname = "RscPictureKeepAspect";
        defaultPos = 7;
        defaultPopulate = 0;
        arraySize = 5;
        width = 4;
        height = 4;
    };
    class fav_equipped
    {
        classname = "RscPicture";
        defaultPos = 7;
        defaultPopulate = 0;
        arraySize = 5;
        width = 4;
        height = 4;
    };
    class fav_keymap
    {
        classname = "fav_keymap";
        defaultPos = 7;
        defaultPopulate = 0;
        arraySize = 5;
        width = 4;
        height = 1;
    };
};

/*[[[end]]]*/
