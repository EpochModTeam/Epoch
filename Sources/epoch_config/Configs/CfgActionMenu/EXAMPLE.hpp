class CfgActionMenu
{
	/** GLOBAL VARIABLES ONLY - removed automatically **/
	class variableDefines //must be global, nil when menu closes
	{
		dyna_cursorTarget = "cursorTarget";
		dyna_typeOfCursorTarget = "typeOf cursorTarget";

		dyna_player = "vehicle player";
		dyna_itemsPlayer = "items player";
	};

	/** No cursor target **/
	class CfgActionMenu_self
	{
		class player_craftMenu
		{
			condition = "true";
			action = "call EPOCH_crafting_load;";
			icon = "x\addons\a3_epoch_code\Data\UI\buttons\build_maintain.paa";
			tooltip = "Crafting V2";
		};
	};

	/** Has cursor target **/
	class CfgActionMenu_target
	{
		class player_inspect
		{
			condition = "dyna_typeOfCursorTarget isEqualTo 'someClassName'";
			action = "hint 'Detective is on the case'";
			icon = "x\addons\a3_epoch_code\Data\UI\buttons\player_inspect.paa";
			tooltip = "Examine";
		};
	};
};

/** Sub-category example **/
/*
class CAT_pad
{
	condition = "true"; //must be value
	action = ""; //can be empty for categories
	icon = "#(rgb,8,8,3)color(1,0,1,0.5)";
	tooltip = "Main cat";

	class SUB_CAT_test1
	{
		condition = "true"; //must be value
		action = ""; //can be empty for categories
		icon = "#(rgb,8,8,3)color(1,1,1,0.5)";
		tooltip = "Subcat1";

		class SUB_CAT_test2
		{
			condition = "true"; //must be value
			action = ""; //can be empty for categories
			icon = "#(rgb,8,8,3)color(1,0,0,0.5)";
			tooltip = "Subcat2";

			class SUB_CAT_test3
			{
				condition = "true"; //must be value
				action = ""; //can be empty for categories
				icon = "#(rgb,8,8,3)color(0,1,1,0.5)";
				tooltip = "Subcat3";

				class SUB_CAT_test4
				{
					condition = "true"; //must be value
					action = ""; //can be empty for categories
					icon = "#(rgb,8,8,3)color(0,1,0,0.5)";
					tooltip = "Subcat4";
				};
			};
		};
	};
};
*/
