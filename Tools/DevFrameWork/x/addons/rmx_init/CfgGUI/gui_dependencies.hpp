class RscPicture;
class RscButton;
class RscProgress;
class RscCombo;
class RscListBox;
class ScrollBar;
class HScrollbar;
class VScrollbar;
class RscText;
class RscStructuredText;
class RscShortcutButton;
class RscIGUIShortcutButton;
class RscGearShortcutButton;
class IGUIBack;
class CA_Title;
class RscControlsGroup;
class RscActiveText;
class RscLineBreak;
class RscIGUIListNBox;
class Attributes;
class RscFrame;
class RscCheckbox;
class RscEdit;
class RscSlider;

//Fucking ninja cancer new to A3?
class RscActivePicture;
class RscActivePictureKeepAspect;

class dUI_ConsoleText { //structured text for console
	idc = -1; 
	type = 13;  // defined constant
	style = 0x00;           
	colorBackground[] = {0.2,0.2,0.2,0.7};
	x = 0 * safezoneW;
	y = 0 * safezoneH;
	w = 1 * safezoneW;
	h = 0.025 * safezoneH;
	size = 0.02;
	text = "";
	
	class Attributes {
		font = "LucidaConsoleB"; //https://community.bistudio.com/wiki/File:Arma3Fonts.png
		color = "#000000";
		align = "left"; //align of text. Values can be "left", "center" or "right"
		valign = "middle"; //vertical align of text. Values can be "top", "middle", "bottom".
		shadow = false;
		shadowColor = "#ff0000";
		size = "1.25";
	};
};

class dUI_rscText: RscText {
	style = 0x02;
	shadow = 2;
};

class dUI_sandbox {
	idd = 666666;
	enableSimulation = 1;
	//movingEnable = 1;
	class controls {};
};

class rmx_ST3
{
	x=0;
	y=0;
	h=0.035;
	w=0.1;
	text="";
	//size="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	size = 0.04;
	colorText[]={1,1,1,1};
	colorBackground[] = {0.2,0.2,0.2,0.7};
	shadow=2;
	type = 13;
	style = 0x02; 
	class Attributes
	{
		font="PuristaMedium"; // "RobotoCondensed";
		color="#ffffff";
		colorLink="#D09B43";
		align="center";
		valign = "top"
		shadow=2;
	};
};

class rmx_watcherProgress: RscProgress
{
	idc = -1;
	texture = "#(argb,8,8,3)color(1,1,1,1)";
	textureExt = "";
	colorBar[] = {1, 1, 1, 0.1};
	colorExtBar[] = {1, 1, 1, 1};
	colorFrame[] = {1, 1, 1, 1};
	x = 0.6;
	y = 0.92;
	w = 0.3;
	h = 0.08;

};
