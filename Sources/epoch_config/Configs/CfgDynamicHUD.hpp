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
	_index = each group hosts multiple elements, each element has it's index, starting from 0
	[_ConfigName, _index] call epoch_getHUDCtrl;
	["myHUDname", 3] call epoch_getHUDCtrl;
*/

class rmx_dynamicHUD
{
	class topRight //ConfigName matters to be able to use function!
	{
		classname = "RscPicture";
		defaultPos = 2;
		defaultPopulate = 1;
		arraySize = 8;
		width = 4;
		height = 4;
		offSetX = 0;
		offSetY = 0;
	};
	class botcenter
	{
		classname = "RscPicture";
		defaultPos = 7;
		defaultPopulate = 4;
		arraySize = 9;
		width = 5;
		height = 5;
	};

};