//IMPORTANT - do not add semicolons here, script takes care of it

class cfgDynamicMenu 
{
	/** GLOBAL VARIABLES ONLY - removed automatically **/
	class variableDefines //must be global, nil when menu closes
	{
		dyna_cursorTarget = "cursorTarget";
		dyna_typeOfCursorTarget = "typeOf cursorTarget";
		
		dyna_player = "vehicle player";
		dyna_itemsPlayer = "items player";
	};
	
	/** BUTTON DEFINES **/
	class dynaButtons
	{
		class example /** Single button **/
		{
			condition = "true"; //must be value
			action = "hint 'example button'";
			icon = "#(rgb,8,8,3)color(1,1,1,0.5)";
			tooltip = "example button";
		};
		
		class example2: example /** Single button from inherited values above **/
		{
			icon = "#(rgb,8,8,3)color(1,0,1,0.5)";
			action = "systemchat 'example button 2'";
		};
		
		/** ------------------------------ **/
		// Category works like a folder, when clicked, it replaces current buttons
		// with fresh batch from it's own subclasses
		/** ------------------------------ **/
		
		class category_example /** Category button, add subclasses to enable this mode**/
		{
			condition = "true"; //must be value
			action = "hint 'Category button 1'"; //can be empty for categories
			icon = "#(rgb,8,8,3)color(1,0,0,0.5)";
			tooltip = "Category button 1";
			
			class category_subclass_example  /** Same config as the rest **/
			{
				condition = "true"; //must be value
				action = "hint 'example category button 1'";
				icon = "#(rgb,8,8,3)color(1,1,1,0.5)";
				tooltip = "example button";
			};
			
			class category_subclass_example2: category_subclass_example /** Subclass inheritance **/
			{
				action = "hint 'example category button 2'";
			};
		};
		class category_example2: category_example /** Category Inheritance, includes all buttons **/
		{
			action = "hint 'Category button 2'";
			tooltip = "Category button 2";
			class category_subclass_example2 /** REPLACE inherited button **/
			{
				condition = "true"; //must be value
				action = "hint 'inherited category button replaced'";
				icon = "#(rgb,8,8,3)color(1,1,1,0.5)";
				tooltip = "replaced button";
			};
		};
	};
};