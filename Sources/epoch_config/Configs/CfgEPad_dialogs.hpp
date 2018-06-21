class RscText
{
	deletable = 0;
	fade = 0;
	access = 0;
	type = 0;
	idc = -1;
	colorBackground[] = 
	{
		0,
		0,
		0,
		0
	};
	colorText[] = 
	{
		1,
		1,
		1,
		1
	};
	text = "";
	fixedWidth = 0;
	colorShadow[] = 
	{
		0,
		0,
		0,
		0.5
	};
	tooltipColorText[] = 
	{
		1,
		1,
		1,
		1
	};
	tooltipColorBox[] = 
	{
		1,
		1,
		1,
		1
	};
	tooltipColorShade[] = 
	{
		0,
		0,
		0,
		0.65
	};
	x = 0;
	y = 0;
	h = 0.037;
	w = 0.3;
	style = 0;
	shadow = 1;
	font = "RobotoCondensed";
	SizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	linespacing = 1;
};
class RscStructuredText
{
	deletable = 0;
	fade = 0;
	access = 0;
	type = 13;
	idc = -1;
	style = 0;
	colorText[] = 
	{
		1,
		1,
		1,
		1
	};
	class Attributes
	{
		font = "RobotoCondensed";
		color = "#ffffff";
		colorLink = "#D09B43";
		align = "left";
		shadow = 1;
	};
	x = 0;
	y = 0;
	h = 0.035;
	w = 0.1;
	text = "";
	size = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	shadow = 1;
};
class RscPicture
{
	deletable = 0;
	fade = 0;
	access = 0;
	type = 0;
	idc = -1;
	style = 48;
	colorBackground[] = 
	{
		0,
		0,
		0,
		0
	};
	colorText[] = 
	{
		1,
		1,
		1,
		1
	};
	font = "TahomaB";
	sizeEx = 0;
	lineSpacing = 0;
	text = "";
	fixedWidth = 0;
	tooltipColorText[] = 
	{
		1,
		1,
		1,
		1
	};
	tooltipColorBox[] = 
	{
		1,
		1,
		1,
		1
	};
	tooltipColorShade[] = 
	{
		0,
		0,
		0,
		0.65
	};
	shadow = 0;
	x = 0;
	y = 0;
	w = 0.2;
	h = 0.15;
};
class RscListBox
{
	deletable = 0;
	fade = 0;
	access = 0;
	type = 5;
	rowHeight = 0;
	colorText[] = 
	{
		1,
		1,
		1,
		1
	};
	colorDisabled[] = 
	{
		1,
		1,
		1,
		0.25
	};
	colorScrollbar[] = 
	{
		1,
		0,
		0,
		0
	};
	colorSelect[] = 
	{
		0,
		0,
		0,
		1
	};
	colorSelect2[] = 
	{
		0,
		0,
		0,
		1
	};
	colorSelectBackground[] = 
	{
		0.95,
		0.95,
		0.95,
		1
	};
	colorSelectBackground2[] = 
	{
		1,
		1,
		1,
		0.5
	};
	colorBackground[] = 
	{
		0,
		0,
		0,
		0.3
	};
	soundSelect[] = 
	{
		"\A3\ui_f\data\sound\RscListbox\soundSelect",
		0.09,
		1
	};
	autoScrollSpeed = -1;
	autoScrollDelay = 5;
	autoScrollRewind = 0;
	arrowEmpty = "#(argb,8,8,3)color(1,1,1,1)";
	arrowFull = "#(argb,8,8,3)color(1,1,1,1)";
	colorPicture[] = 
	{
		1,
		1,
		1,
		1
	};
	colorPictureSelected[] = 
	{
		1,
		1,
		1,
		1
	};
	colorPictureDisabled[] = 
	{
		1,
		1,
		1,
		0.25
	};
	colorPictureRight[] = 
	{
		1,
		1,
		1,
		1
	};
	colorPictureRightSelected[] = 
	{
		1,
		1,
		1,
		1
	};
	colorPictureRightDisabled[] = 
	{
		1,
		1,
		1,
		0.25
	};
	colorTextRight[] = 
	{
		1,
		1,
		1,
		1
	};
	colorSelectRight[] = 
	{
		0,
		0,
		0,
		1
	};
	colorSelect2Right[] = 
	{
		0,
		0,
		0,
		1
	};
	tooltipColorText[] = 
	{
		1,
		1,
		1,
		1
	};
	tooltipColorBox[] = 
	{
		1,
		1,
		1,
		1
	};
	tooltipColorShade[] = 
	{
		0,
		0,
		0,
		0.65
	};
	class ListScrollBar
	{
		color[] = 
		{
			1,
			1,
			1,
			1
		};
		autoScrollEnabled = 1;
	};
	colorShadow[] = 
	{
		0,
		0,
		0,
		0.5
	};
	x = 0;
	y = 0;
	w = 0.3;
	h = 0.3;
	style = 16;
	font = "RobotoCondensed";
	sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	shadow = 0;
	period = 1.2;
	maxHistoryDelay = 1;
};
class RscButton
{
	deletable = 0;
	fade = 0;
	access = 0;
	type = 1;
	text = "";
	colorText[] = 
	{
		1,
		1,
		1,
		1
	};
	colorDisabled[] = 
	{
		1,
		1,
		1,
		0.25
	};
	colorBackground[] = 
	{
		0,
		0,
		0,
		0.5
	};
	colorBackgroundDisabled[] = 
	{
		0,
		0,
		0,
		0.5
	};
	colorBackgroundActive[] = 
	{
		0,
		0,
		0,
		1
	};
	colorFocused[] = 
	{
		0,
		0,
		0,
		1
	};
	colorShadow[] = 
	{
		0,
		0,
		0,
		0
	};
	colorBorder[] = 
	{
		0,
		0,
		0,
		1
	};
	soundEnter[] = 
	{
		"\A3\ui_f\data\sound\RscButton\soundEnter",
		0.09,
		1
	};
	soundPush[] = 
	{
		"\A3\ui_f\data\sound\RscButton\soundPush",
		0.09,
		1
	};
	soundClick[] = 
	{
		"\A3\ui_f\data\sound\RscButton\soundClick",
		0.09,
		1
	};
	soundEscape[] = 
	{
		"\A3\ui_f\data\sound\RscButton\soundEscape",
		0.09,
		1
	};
	idc = -1;
	style = 2;
	x = 0;
	y = 0;
	w = 0.095589;
	h = 0.039216;
	shadow = 2;
	font = "RobotoCondensed";
	sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	url = "";
	offsetX = 0;
	offsetY = 0;
	offsetPressedX = 0;
	offsetPressedY = 0;
	borderSize = 0;
};



class RscHTML
{
	idc = -1;
	type = 9;
	style = 0x00;
	x=0;
	y=0;
	w=0.1;
	h=0.1;
	colorText[]={1,1,1,1};
	colorBold[]={1,1,1,1};
	colorLink[]={1,1,1,0.75};
	colorLinkActive[]={1,1,1,1};
	sizeEx="(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	prevPage="\A3\ui_f\data\gui\rsccommon\rschtml\arrow_left_ca.paa";
	nextPage="\A3\ui_f\data\gui\rsccommon\rschtml\arrow_right_ca.paa";
	shadow=2;
	class H1
	{
		font="RobotoCondensed";
		fontBold="RobotoCondensedBold";
		sizeEx="(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1.2)";
		align="left";
	};
	class H2
	{
		font="RobotoCondensed";
		fontBold="RobotoCondensedBold";
		sizeEx="(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
		align="right";
	};
	class H3
	{
		font="RobotoCondensed";
		fontBold="RobotoCondensedBold";
		sizeEx="(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
		align="left";
	};
	class H4
	{
		font="RobotoCondensed";
		fontBold="RobotoCondensedBold";
		sizeEx="(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
		align="left";
	};
	class H5
	{
		font="RobotoCondensed";
		fontBold="RobotoCondensedBold";
		sizeEx="(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
		align="left";
	};
	class H6
	{
		font="RobotoCondensed";
		fontBold="RobotoCondensedBold";
		sizeEx="(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
		align="left";
	};
	class P
	{
		font="RobotoCondensed";
		fontBold="RobotoCondensedBold";
		sizeEx="(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
		align="left";
	};
	tooltipColorText[]={1,1,1,1};
	tooltipColorBox[]={1,1,1,1};
	tooltipColorShade[]={0,0,0,0.64999998};
};



class RscButton_EPad : RscButton
{
	colorFocused[] = {0,0,0,0.5};
	colorBackgroundActive[] = {0,0,0,0.5};
	w = 0.0400931 * safezoneW;                                             
	h = 0.0550151 * safezoneH;
	action = "";
};
class RscButtonPDATrans : RscButton
{
	fade = 0;
	colorText[] = {1,1,1,0};
	colorDisabled[] = {1,1,1,0};
	colorBackground[] = {0,0,0,0};
	colorBackgroundDisabled[] = {0,0,0,0};
	colorBackgroundActive[] = {0,0,0,0};
	colorFocused[] = {0,0,0,0};
	colorShadow[] = {0,0,0,0};
	colorBorder[] = {0,0,0,0};
	shadow = 2;
};

class epoch_tablet_gui
{
	idd = 9898;
	movingEnabled = false;
	onLoad = "[] spawn {waituntil {!isnull (finddisplay 9898)}; Epoch_E_Pad_Page = 1; ['',true] call EPOCH_EPad_dialog}";
	class controls
	{
		class background: RscPicture
		{
			idc = 1200;
			text = "epoch_code\customs\images\epoch_tablet_back.paa";
			x = 0.184983 * safezoneW + safezoneX;
			y = 0.114894 * safezoneH + safezoneY;
			w = 0.635763 * safezoneW;
			h = 0.80322 * safezoneH;
		};
		class close: RscButtonPDATrans
		{
			idc = 1600;
			x = 0.574459 * safezoneW + safezoneX;
			y = 0.213921 * safezoneH + safezoneY;
			w = 0.0286379 * safezoneW;
			h = 0.0440121 * safezoneH;
			action = "closeDialog 0;";
			tooltip = "Close PDA";
		};
		class app1: RscButton_EPad
		{
			idc = 1601;
			x = 0.414086 * safezoneW + safezoneX;                                  
			y = 0.301946 * safezoneH + safezoneY;                                  
		};
		class app1_background: RscPicture
		{
			idc = 1701;
			text = "";
			x = 0.414086 * safezoneW + safezoneX;
			y = 0.301946 * safezoneH + safezoneY;
			w = 0.0400931 * safezoneW;
			h = 0.0550151 * safezoneH;
		};
		class app1txt: RscText
		{
			idc = 1801;
			style = 0x02;
			x = 0.414086 * safezoneW + safezoneX;
			y = (0.301946+0.0550151) * safezoneH + safezoneY;
			w = 0.0400931 * safezoneW;
			h = 0.016 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
			colorText[] = {1,1,1,1};
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.7)";
			text = "";
		};
		class app2: RscButton_EPad
		{
			idc = 1602;
			x = 0.471362 * safezoneW + safezoneX;
			y = 0.301946 * safezoneH + safezoneY;
		};
		class app2_background: RscPicture
		{
			idc = 1702;
			text = "";
			x = 0.471362 * safezoneW + safezoneX;
			y = 0.301946 * safezoneH + safezoneY;
			w = 0.0400931 * safezoneW;
			h = 0.0550151 * safezoneH;
		};
		class app2txt: RscText
		{
			idc = 1802;
			style = 0x02;
			x = 0.471362 * safezoneW + safezoneX;
			y = (0.301946+0.0550151) * safezoneH + safezoneY;
			w = 0.0400931 * safezoneW;
			h = 0.016 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
			colorText[] = {1,1,1,1};
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.7)";
			text = "";
		};
		class app3: RscButton_EPad
		{
			idc = 1603;
			x = 0.528638 * safezoneW + safezoneX;
			y = 0.301946 * safezoneH + safezoneY;
		};
		class app3_background: RscPicture
		{
			idc = 1703;
			text = "";
			x = 0.528638 * safezoneW + safezoneX;
			y = 0.301946 * safezoneH + safezoneY;
			w = 0.0400931 * safezoneW;
			h = 0.0550151 * safezoneH;
		};
		class app3txt: RscText
		{
			idc = 1803;
			style = 0x02;
			x = 0.528638 * safezoneW + safezoneX;
			y = (0.301946+0.0550151) * safezoneH + safezoneY;
			w = 0.0400931 * safezoneW;
			h = 0.016 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
			colorText[] = {1,1,1,1};
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.7)";
			text = "";
		};
		class app4: RscButton_EPad
		{
			idc = 1604;
			x = 0.414086 * safezoneW + safezoneX;
			y = 0.378967 * safezoneH + safezoneY;
		};
		class app4_background: RscPicture
		{
			idc = 1704;
			text = "";
			x = 0.414086 * safezoneW + safezoneX;
			y = 0.378967 * safezoneH + safezoneY;
			w = 0.0400931 * safezoneW;
			h = 0.0550151 * safezoneH;
		};
		class app4txt: RscText
		{
			idc = 1804;
			style = 0x02;
			x = 0.414086 * safezoneW + safezoneX;
			y = (0.378967+0.0550151) * safezoneH + safezoneY;
			w = 0.0400931 * safezoneW;
			h = 0.016 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
			colorText[] = {1,1,1,1};
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.7)";
			text = "";
		};
		class app5: RscButton_EPad
		{
			idc = 1605;
			x = 0.471362 * safezoneW + safezoneX;
			y = 0.378967 * safezoneH + safezoneY;
		};
		class app5_background: RscPicture
		{
			idc = 1705;
			text = "";                                                             
			x = 0.471362 * safezoneW + safezoneX;
			y = 0.378967 * safezoneH + safezoneY;
			w = 0.0400931 * safezoneW;
			h = 0.0550151 * safezoneH;
		};
		class app5txt: RscText
		{
			idc = 1805;
			style = 0x02;
			x = 0.471362 * safezoneW + safezoneX;
			y = (0.378967+0.0550151) * safezoneH + safezoneY;
			w = 0.0400931 * safezoneW;
			h = 0.016 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
			colorText[] = {1,1,1,1};
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.7)";
			text = "";
		};
		class app6: RscButton_EPad
		{
			idc = 1606;
			x = 0.528638 * safezoneW + safezoneX;
			y = 0.378967 * safezoneH + safezoneY;
		};
		class app6_background: RscPicture
		{
			idc = 1706;
			text = "";                                                             
			x = 0.528638 * safezoneW + safezoneX;
			y = 0.378967 * safezoneH + safezoneY;
			w = 0.0400931 * safezoneW;
			h = 0.0550151 * safezoneH;
		};
		class app6txt: RscText
		{
			idc = 1806;
			style = 0x02;
			x = 0.528638 * safezoneW + safezoneX;
			y = (0.378967+0.0550151) * safezoneH + safezoneY;
			w = 0.0400931 * safezoneW;
			h = 0.016 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
			colorText[] = {1,1,1,1};
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.7)";
			text = "";
		};
		class app7: RscButton_EPad
		{
			idc = 1607;
			x = 0.414086 * safezoneW + safezoneX;
			y = 0.455988 * safezoneH + safezoneY;
		};
		class app7_background: RscPicture
		{
			idc = 1707;
			text = "";                                                             
			x = 0.414086 * safezoneW + safezoneX;
			y = 0.455988 * safezoneH + safezoneY;
			w = 0.0400931 * safezoneW;
			h = 0.0550151 * safezoneH;
		};
		class app7txt: RscText
		{
			idc = 1807;
			style = 0x02;
			x = 0.414086 * safezoneW + safezoneX;
			y = (0.455988+0.0550151) * safezoneH + safezoneY;
			w = 0.0400931 * safezoneW;
			h = 0.016 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
			colorText[] = {1,1,1,1};
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.7)";
			text = "";
		};
		class app8: RscButton_EPad
		{
			idc = 1608;
			x = 0.471362 * safezoneW + safezoneX;
			y = 0.455988 * safezoneH + safezoneY;
		};
		class app8_background: RscPicture
		{
			idc = 1708;
			text = "";                                                             
			x = 0.471362 * safezoneW + safezoneX;
			y = 0.455988 * safezoneH + safezoneY;
			w = 0.0400931 * safezoneW;
			h = 0.0550151 * safezoneH;
		};
		class app8txt: RscText
		{
			idc = 1808;
			style = 0x02;
			x = 0.471362 * safezoneW + safezoneX;
			y = (0.455988+0.0550151) * safezoneH + safezoneY;
			w = 0.0400931 * safezoneW;
			h = 0.016 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
			colorText[] = {1,1,1,1};
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.7)";
			text = "";
		};
		class app9: RscButton_EPad
		{
			idc = 1609;
			x = 0.528638 * safezoneW + safezoneX;
			y = 0.455988 * safezoneH + safezoneY;
		};
		class app9_background: RscPicture
		{
			idc = 1709;
			text = "";                                                             
			x = 0.528638 * safezoneW + safezoneX;
			y = 0.455988 * safezoneH + safezoneY;
			w = 0.0400931 * safezoneW;
			h = 0.0550151 * safezoneH;
		};
		class app9txt: RscText
		{
			idc = 1809;
			style = 0x02;
			x = 0.528638 * safezoneW + safezoneX;
			y = (0.455988+0.0550151) * safezoneH + safezoneY;
			w = 0.0400931 * safezoneW;
			h = 0.016 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
			colorText[] = {1,1,1,1};
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.7)";
			text = "";
		};
		class app10: RscButton_EPad
		{
			idc = 1610;
			x = 0.414086 * safezoneW + safezoneX;
			y = 0.533009 * safezoneH + safezoneY;
		};
		class app10_background: RscPicture
		{
			idc = 1710;
			text = "";                                                             
			x = 0.414086 * safezoneW + safezoneX;
			y = 0.533009 * safezoneH + safezoneY;
			w = 0.0400931 * safezoneW;
			h = 0.0550151 * safezoneH;
		};
		class app10txt: RscText
		{
			idc = 1810;
			style = 0x02;
			x = 0.414086 * safezoneW + safezoneX;
			y = (0.533009+0.0550151) * safezoneH + safezoneY;
			w = 0.0400931 * safezoneW;
			h = 0.016 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
			colorText[] = {1,1,1,1};
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.7)";
			text = "";
		};
		class app11: RscButton_EPad
		{
			idc = 1611;
			x = 0.471362 * safezoneW + safezoneX;
			y = 0.533009 * safezoneH + safezoneY;
		};
		class app11_background: RscPicture
		{
			idc = 1711;
			text = "";                                                             
			x = 0.471362 * safezoneW + safezoneX;
			y = 0.533009 * safezoneH + safezoneY;
			w = 0.0400931 * safezoneW;
			h = 0.0550151 * safezoneH;
		};
		class app11txt: RscText
		{
			idc = 1811;
			style = 0x02;
			x = 0.471362 * safezoneW + safezoneX;
			y = (0.533009+0.0550151) * safezoneH + safezoneY;
			w = 0.0400931 * safezoneW;
			h = 0.016 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
			colorText[] = {1,1,1,1};
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.7)";
			text = "";
		};
		class app12: RscButton_EPad
		{
			idc = 1612;
			x = 0.528638 * safezoneW + safezoneX;
			y = 0.533009 * safezoneH + safezoneY;
		};
		class app12_background: RscPicture
		{
			idc = 1712;
			text = "";                                                             
			x = 0.528638 * safezoneW + safezoneX;
			y = 0.533009 * safezoneH + safezoneY;
			w = 0.0400931 * safezoneW;
			h = 0.0550151 * safezoneH;
		};
		class app12txt: RscText
		{
			idc = 1812;
			style = 0x02;
			x = 0.528638 * safezoneW + safezoneX;
			y = (0.533009+0.0550151) * safezoneH + safezoneY;
			w = 0.0400931 * safezoneW;
			h = 0.016 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
			colorText[] = {1,1,1,1};
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.7)";
			text = "";
		};
		class app13: RscButton_EPad	// prev page
		{
			idc = 1614;
			x = 0.414086 * safezoneW + safezoneX;
			y = 0.599027 * safezoneH + safezoneY;
		};
		class app13_background: RscPicture
		{
			idc = 1714;
			text = "epoch_code\customs\images\back_ca.paa";
			tooltip = "prev page";                                                             
			x = 0.414086 * safezoneW + safezoneX;
			y = 0.599027 * safezoneH + safezoneY;
			w = 0.0400931 * safezoneW;
			h = 0.0550151 * safezoneH;
		};
		class app14: RscButton_EPad
		{
			idc = 1613;
			x = 0.471362 * safezoneW + safezoneX;
			y = 0.599027 * safezoneH + safezoneY;
		};
		class app14_background: RscPicture
		{
			idc = 1713;
			text = "";                                                             
			x = 0.471362 * safezoneW + safezoneX;
			y = 0.599027 * safezoneH + safezoneY;
			w = 0.0400931 * safezoneW;
			h = 0.0550151 * safezoneH;
		};
		class app14txt: RscText
		{
			idc = 1814;
			style = 0x02;
			x = 0.471362 * safezoneW + safezoneX;
			y = (0.599027+0.0550151) * safezoneH + safezoneY;
			w = 0.0400931 * safezoneW;
			h = 0.016 * safezoneH;
			colorBackground[] = {0,0,0,0.5};
			colorText[] = {1,1,1,1};
			sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.7)";
			text = "";
		};
		class app15: RscButton_EPad  //next page
		{
			idc = 1615;
			x = 0.528638 * safezoneW + safezoneX;
			y = 0.599027 * safezoneH + safezoneY;
		};
		class app15_background: RscPicture
		{
			idc = 1715;
			text = "epoch_code\customs\images\next.paa";
			tooltip = "next page";                                                             
			x = 0.528638 * safezoneW + safezoneX;
			y = 0.599027 * safezoneH + safezoneY;
			w = 0.0400931 * safezoneW;
			h = 0.0550151 * safezoneH;
		};
		class home: RscButtonPDATrans
		{
			idc = 1616;
			x = 0.408359 * safezoneW + safezoneX;
			y = 0.72006 * safezoneH + safezoneY;
			w = 0.0400931 * safezoneW;
			h = 0.0440121 * safezoneH;
			action = "Epoch_E_Pad_Page = 1; [] call EPOCH_EPad_dialog";
			tooltip = "home";	
		};
		class call: RscButtonPDATrans
		{
			idc = 1617;
			x = 0.454179 * safezoneW + safezoneX;
			y = 0.72006 * safezoneH + safezoneY;
			w = 0.0400931 * safezoneW;
			h = 0.0440121 * safezoneH;
			action = "";
			tooltip = "";	
		};
		class end: RscButtonPDATrans
		{
			idc = 1618;
			x = 0.494272 * safezoneW + safezoneX;
			y = 0.72006 * safezoneH + safezoneY;
			w = 0.0400931 * safezoneW;
			h = 0.0440121 * safezoneH;
			action = "";
			tooltip = "";	
		};
		class sms: RscButtonPDATrans
		{
			idc = 1619;
			x = 0.540093 * safezoneW + safezoneX;
			y = 0.72006 * safezoneH + safezoneY;
			w = 0.0400931 * safezoneW;
			h = 0.0440121 * safezoneH;
			action = "['WIP',5] call epoch_message";
			tooltip = "sms (wip)";	
		};
////////////////////////////////////////
/////////Picture Backgrounds start//////
////////////////////////////////////////
		class PDA_HTML : RscHTML
		{
			idc = 1901;
			type = 9;
			style = 0x00;
			x = 0.414086 * safezoneW + safezoneX;                                  
			y = 0.301946 * safezoneH + safezoneY;                                  
			w = 0.1646451 * safezoneW;
			h = 0.3520961 * safezoneH;
			filename = "";
			text="";
			colorBackground[] = {0.02,0,0.03,0.6};
			colorBold[] = {1,0,0,1};
			colorLink[] = {1,1,0,1};
			colorLinkActive[] = {1,1,0,1};
			colorPicture[] = {1,1,1,1};
			colorPictureBorder[] = {1,0,0,1};
			colorPictureLink[] = {1,1,1,1};
			colorPictureSelected[] = {1,1,1,1};
			colorText[] = {1,1,1,1};
			class H1 {
				font = "puristaMedium";
				fontBold = "PuristaBold";
				SizeEx = 0.035;
			};
			class H2 {
				font = "puristaLight";
				fontBold = "PuristaBold";
				SizeEx = 0.035;
			};
			class H3:H2{};
			class H4:H2{};
			class H5:H2{};
			class H6:H2{};
			class P {
				font = "puristaMedium";
				fontBold = "PuristaBold";
				SizeEx = 0.032;
			};
		};
		class PDASMSText_Box : RscStructuredText
		{
			idc = 1902;
			x = 0.414086 * safezoneW + safezoneX;                                  
			y = 0.301946 * safezoneH + safezoneY;                                  
			w = 0.1646451 * safezoneW;
			h = 0.3520961 * safezoneH;
		};
		class PDAListBox: RscListBox
		{
			idc = 1903;
			onLBDblClick = "_this call Epoch_SMS_OpenDiag";
			x = 0.414086 * safezoneW + safezoneX;                                  
			y = 0.301946 * safezoneH + safezoneY;                                  
			w = 0.1646451 * safezoneW;
			h = 0.3520961 * safezoneH;
		};
	};
 };
class server_info_picture 
{
	idd = 98989;
	movingEnabled = false;
	class controls 
	{	
	   class server_info: RscPicture
       {
			idc = 98999;
			text = "epoch_code\customs\images\server_info_ca.paa";
			x = 0.184983 * safezoneW + safezoneX;
			y = 0.114894 * safezoneH + safezoneY;
			w = 0.635763 * safezoneW;
			h = 0.80322 * safezoneH;
       }; 
	};	   
};