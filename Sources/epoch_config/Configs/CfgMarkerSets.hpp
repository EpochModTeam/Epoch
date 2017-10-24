/*
	DirtySanchez
	
	Local Markers are single instance and can only be seen by the player
	Use ['Name',position] call EPOCH_fnc_createLocalMarkerSet;
	
	Global Markers are mostly for server use
	Use ['Name',position] call EPOCH_server_createGlobalMarkerSet;
	
	
		Config setup and small explanation:
	
	{_markerName, _markerShape, _markerTypeOrBrush, _markerColor, _markerAlpha, _markerSize, _markerDir, _markerTextorCode},
	
	_markerName - setting this as "" will assume marker name as a counter starting with marker_0
	
	_markerShape - Selects the shape of the marker. Shape can be "ICON", "RECTANGLE" or "ELLIPSE".
				 - if Shape is not ICON it will look for a Brush in the next variable
	
	_markerTypeOrBrush - (type) this can be any marker from CfgMarkers. ie "KIA" from arma 3 or "EpochSkull" in epoch community assets
					 - (brush) https://community.bistudio.com/wiki/setMarkerBrushLocal for more info
	
	_markerColor(optional) - follows arma 3 colors. ie "ColorBlue", "ColorPink"
	
	_markerAlpha(optional) - alpha channel 0-1 value
	
	_markerSize(optional) -  [x,y] https://community.bistudio.com/wiki/setMarkerSize
	
	_markerDir(optional) - degrees
	
	_markerTextOrCode(optional) - Text - place any text in here as: "'Service Point #1'"
								- Code - place any code in here such as: "str(player name)"
									   - for GPS coords use this: "format['%1/%2',(format[mapGridPosition player]) select  [0,3],(format[mapGridPosition player]) select  [3,3]]"
	
		Marker sets:
	
	Active Marker sets include 1 Active shape, 1 Background(BG) shape and 1 Epoch marker or your marker of choice
	for example the PlayerMarker below is 1 EpochActive_Hex, 1 EpochBG_Hex and the EpochGPS marker
*/
class CfgMarkerSets
{
	brushes[] = {"Solid","SolidFull","Horizontal","Vertical","Grid","FDiagonal","BDiagonal","DiagGrid","Cross","Border","SolidBorder"};
	mapScalerPresets[] = {
		{1.00,2},
		{0.80,2.25},
		{0.60,2.5},
		{0.30,2.75},
		{0.21,3.25},
		{0.12,3.5},
		{0.8,3.75}
	};
	class PlayerMarker {
		markerArray[] = {
			{"EPOCH_PlayerMarker1","ICON","EpochActive_Hex","ColorBlue",1,{0.6,0.6}},
			{"EPOCH_PlayerMarker2","ICON","EpochBG_Hex","ColorWhite",0.3,{0.6,0.6}},
			{"EPOCH_PlayerMarker3","ICON","EpochGPS","ColorBlue",1,{0.5,0.5},0,"format['%1/%2',(format[mapGridPosition player]) select  [0,3],(format[mapGridPosition player]) select  [3,3]]"}
		};
	};
	class DeathMarker {
		markerArray[] = {
			
			{"EPOCH_DeathMarker1","ICON","EpochActive_Circle","ColorRed",1,{0.6,0.6}},
			{"EPOCH_DeathMarker2","ICON","EpochBG_Circle","ColorPink",0.3,{0.6,0.6}},
			{"EPOCH_DeathMarker3","ICON","EpochSkull","ColorRed",1,{0.5,0.5},0,"str(name player)"}
		};
	};
	class EpochDebugBox {
		markerArray[] = {
			{"","ICON","EpochActive_Square","ColorGreen",1,{1,1}},
			{"","ICON","EpochBG_Square","ColorBlack",0.2,{1,1}},
			{"","ICON","EpochRespawn","ColorGreen",0.75,{1,1}}
		};
	};
	class PlantSpawn {
		markerArray[] = {
			{"","ICON","EpochActive_Diamond","ColorGreen",1,{0.8,0.8}},
			{"","ICON","EpochBG_Diamond","ColorBlack",0.2,{0.8,0.8}},
			{"","ICON","EpochPlant","ColorGreen",0.9,{0.9,0.9}}
		};
	};
	class AirDrop {
		markerArray[] = {
			{"","ICON","EpochActive_Diamond","ColorGreen",1,{1.1,1.1}},
			{"","ICON","EpochBG_Diamond","ColorBlack",0.2,{1.1,1.1}},
			{"","ICON","EpochAirdrop","ColorGreen",0.75,{1.2,1.2}}
		};
	};
	class Carnival {
		markerArray[] = {
			{"","ICON","EpochActive_Diamond","ColorOrange",1,{1,1}},
			{"","ICON","EpochBG_Diamond","ColorBlack",0.2,{1,1}},
			{"","ICON","EpochCarnival","ColorOrange",0.75,{1.1,1.1}}
		};
	};
	class Container {
		markerArray[] = {
			{"","ICON","EpochActive_Diamond","ColorOrange",1,{1,1}},
			{"","ICON","EpochBG_Diamond","ColorBlack",0.2,{1,1}},
			{"","ICON","EpochContainer","ColorOrange",0.75,{1.1,1.1}}
		};
	};
	class EarthQuake {
		markerArray[] = {
			{"","ICON","EpochActive_Circle","ColorGrey",1,{0.8,0.8}},
			{"","ICON","EpochBG_Circle","ColorBlack",0.2,{0.8,0.8}},
			{"","ICON","EpochGem","ColorRed",1,{0.9,0.9}}
		};
	};
	class ServicePoint {
        markerArray[] = {
            {"","ICON","EpochBG_Circle","ColorGrey",0.25,{0.85,0.85}}, 
            {"","ICON","EpochActive_Circle","ColorBlack",1,{0.85,0.85}}, 
            {"","ICON","EpochService","ColorWhite",1,{0.9,0.9},0,"'Service Point'"}
        };
	};
	class Radiation {
        markerArray[] = {
           {"","ICON","EpochBG_Triangle","ColorBlack",0.3,{0.7,0.7}},
            {"","ICON","EpochActive_Triangle","ColorYellow",1,{0.7,0.7}},
            {"","ICON","EpochRadiation","ColorYellow",1,{0.9,0.9}}
        };
	};
	class Satellite {
        markerArray[] = {
            {"","ICON","EpochBG_Triangle","ColorBlack",0.15,{0.7,0.7},58}, 
            {"","ICON","EpochActive_Triangle","ColorYellow",0.5,{0.7,0.7},58}, 
            {"","ICON","EpochSatellite","ColorYellow",1,{0.9,0.9},58}
        };
	};
	class MissionNoob {
		markerArray[] = {
			{"","ICON","EpochBG_Square","ColorBlack",0.15,{1,1}},
            {"","ICON","EpochActive_Square","ColorGreen",0.5,{1,1}},
            {"","ICON","EpochMissionNoob1","ColorYellow",1,{0.9,0.9}}
		};
	};
	class MissionNoobPlus {
		markerArray[] = {
			{"","ICON","EpochBG_Square","ColorBlack",0.15,{1,1}},
            {"","ICON","EpochActive_Square","ColorGreen",0.75,{1,1}},
            {"","ICON","EpochMissionNoob2","ColorYellow",1,{0.9,0.9}}
		};
	};
	class MissionSurvivor {
		markerArray[] = {
			{"","ICON","EpochBG_Square","ColorBlack",0.15,{1,1}},
            {"","ICON","EpochActive_Square","ColorBlue",0.5,{1,1}},
            {"","ICON","EpochMissionMedium1","ColorGreen",1,{0.9,0.9}}
		};
	};
	class MissionSurvivorPlus {
		markerArray[] = {
			{"","ICON","EpochBG_Square","ColorBlack",0.15,{1,1}},
            {"","ICON","EpochActive_Square","ColorBlue",0.75,{1,1}},
            {"","ICON","EpochMissionMedium2","ColorGreen",1,{0.9,0.9}}
		};
	};
	class MissionSlaughter {
		markerArray[] = {
			{"","ICON","EpochBG_Square","ColorBlack",0.15,{1,1}},
            {"","ICON","EpochActive_Square","ColorRed",0.5,{1,1}},
            {"","ICON","EpochMissionVeteran1","ColorBlue",1,{0.9,0.9}}
		};
	};
	class MissionSlaughterPlus {
		markerArray[] = {
			{"","ICON","EpochBG_Square","ColorBlack",0.15,{1,1}},
            {"","ICON","EpochActive_Square","ColorRed",0.75,{1,1}},
            {"","ICON","EpochMissionVeteran2","ColorBlue",1,{0.9,0.9}}
		};
	};
	class IGSafeZones {
		markerArray[] = {
			{"","ICON","mil_warning","ColorRed",1,{1,1},0,"format['SafeZone%1',IGSZCounter];IGSZCounter = IGSZCounter+1"},
			{"","ELLIPSE","Grid","ColorGreen",1,{250,250}}
		};
	};
	class StaticTrader {
		markerArray[] = {
			{"","ICON","EpochBG_Circle","ColorWhite",0.15,{0.6,0.6}},
            {"","ICON","EpochActive_Circle","ColorRed",0.75,{0.6,0.6}},
            {"","ICON","EpochStaticTrader","ColorBlack",1,{0.5,0.5}}
		};
	};
	class DynamicTrader {
		markerArray[] = {
			{"","ICON","EpochBG_Circle","ColorWhite",0.15,{0.6,0.6}},
            {"","ICON","EpochActive_Circle","ColorGreen",0.75,{0.6,0.6}},
            {"","ICON","EpochDynamicTrader","ColorBrown",1,{0.5,0.5}}
		};
	};
	class NewDynamicTrader {
		markerArray[] = {
			{"","ICON","EpochBG_Circle","ColorWhite",0.15,{0.6,0.6}},
            {"","ICON","EpochActive_Circle","ColorKhaki",0.75,{0.6,0.6}},
            {"","ICON","EpochStaticTrader","ColorKhaki",1,{0.5,0.5}}
		};
	};
	class Shipwreck {
		markerArray[] = {
			{"","ICON","EpochBG_Circle","ColorWhite",0.15,{0.6,0.6}},
            {"","ICON","EpochActive_Circle","ColorOrange",1,{0.6,0.6}},
            {"","ICON","EpochShipwreck","ColorOrange",1,{0.5,0.5}}
		};
	};
};
