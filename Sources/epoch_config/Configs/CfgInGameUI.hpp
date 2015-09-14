class RscUnitInfo;
class RscText;
class RscControlsGroup;
class HScrollbar;
class VScrollbar;
class RscInGameUI
{
	class RscOptics_nightstalker: RscUnitInfo
	{
		idd = 300;
		controls[] = {"CA_IGUI_elements_group"};
		class CA_IGUI_elements_group: RscControlsGroup
		{
			idc = 170;
			class VScrollbar: VScrollbar
			{
				width = 0;
			};
			class HScrollbar: HScrollbar
			{
				height = 0;
			};
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "53.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_Distance: RscText
				{
					idc = 151;
					style = 0;
					sizeEx = "0.045*SafezoneH";
					colorText[] = {0,1,0,0.5};
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "- - - -";
					x = "38 * 		(0.01875 * SafezoneH)";
					y = "19.1 * 		(0.025 * SafezoneH)";
					w = "5.6 * 		(0.01875 * SafezoneH)";
					h = "2 * 		(0.025 * SafezoneH)";
				};
				class CA_VisionMode: RscText
				{
					idc = 179;
					style = 0;
					sizeEx = "0.045*SafezoneH";
					colorText[] = {0,1,0,0.5};
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "VIS";
					x = "10.5 * 		(0.01875 * SafezoneH)";
					y = "19.1 * 		(0.025 * SafezoneH)";
					w = "5 * 		(0.01875 * SafezoneH)";
					h = "2 * 		(0.025 * SafezoneH)";
				};
				class CA_OpticsZoom: RscText
				{
					idc = 180;
					style = 1;
					sizeEx = "0.028*SafezoneH";
					colorText[] = {0,1,0,0.5};
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "5.5";
					x = "38.8 * 		(0.01875 * SafezoneH)";
					y = "20.8 * 		(0.025 * SafezoneH)";
					w = "4 * 		(0.01875 * SafezoneH)";
					h = "1.5 * 		(0.025 * SafezoneH)";
				};
				class CA_Bracket: RscText
				{
					idc = 181;
					style = "0x30 + 0x800";
					sizeEx = "0.035*SafezoneH";
					shadow = 0;
					font = "EtelkaMonospacePro";
					//text = "A3\weapons_f\acc\Data\reticle_nightstalker_bracket_ca.paa";
					text = "";
					x = "16.5 * 		(0.01875 * SafezoneH)";
					y = "9.75 * 		(0.025 * SafezoneH)";
					w = "20.5 * 		(0.01875 * SafezoneH)";
					h = "20.5 * 		(0.025 * SafezoneH)";
				};
			};
		};
	};
};