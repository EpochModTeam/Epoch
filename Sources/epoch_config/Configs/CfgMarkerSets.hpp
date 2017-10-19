/*
	DirtySanchez
	
	Local Markers are single instance and can only be seen by the player
	Use ['Name',position] call EPOCH_fnc_createLocalMarkerSet;
	
	Global Markers are mostly for server use
	Use ['Name',position] call EPOCH_server_createGlobalMarkerSet;
	
*/
class CfgMarkerSets
{
	brushes[] = {"Solid","SolidFull","Horizontal","Vertical","Grid","FDiagonal","BDiagonal","DiagGrid","Cross","Border","SolidBorder"};
	class PlayerMarker {
		markerArray[] = {
			{"EPOCH_PlayerMarker1","ICON","EpochActive_Hex","ColorBlue",1,{0.9,0.9}},
			{"EPOCH_PlayerMarker2","ICON","EpochBG_Hex","ColorWhite",0.3,{0.9,0.9}},
			{"EPOCH_PlayerMarker3","ICON","EpochGPS","ColorBlue",1,{0.8,0.8},0,"format['%1/%2',(format[mapGridPosition player]) select  [0,3],(format[mapGridPosition player]) select  [3,3]]"}
		};
	};
	class DeathMarker {
		markerArray[] = {
			
			{"EPOCH_DeathMarker1","ICON","EpochActive_Circle","ColorRed",1,{0.9,0.9}},
			{"EPOCH_DeathMarker2","ICON","EpochBG_Circle","ColorPink",0.3,{0.9,0.9}},
			{"EPOCH_DeathMarker3","ICON","EpochSkull","ColorRed",1,{0.8,0.8},0,"str(name player)"}
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
			{"","ICON","EpochActive_Diamond","ColorGreen",1,{1.1,1.1}},
			{"","ICON","EpochBG_Diamond","ColorBlack",0.2,{1.1,1.1}},
			{"","ICON","EpochPlant","ColorGreen",0.9,{1.2,1.2}}
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
			{"","ICON","EpochActive_Diamond","ColorOrange",1,{1.2,1.2}},
			{"","ICON","EpochBG_Diamond","ColorBlack",0.2,{1.2,1.2}},
			{"","ICON","EpochCarnival","ColorOrange",0.75,{1.3,1.3}}
		};
	};
	class Container {
		markerArray[] = {
			{"","ICON","EpochActive_Diamond","ColorOrange",1,{1.2,1.2}},
			{"","ICON","EpochBG_Diamond","ColorBlack",0.2,{1.2,1.2}},
			{"","ICON","EpochContainer","ColorOrange",0.75,{1.3,1.3}}
		};
	};
	class EarthQuake {
		markerArray[] = {
			{"","ICON","EpochActive_Circle","ColorGrey",1,{1.2,1.2}},
			{"","ICON","EpochBG_Circle","ColorBlack",0.2,{1.2,1.2}},
			{"","ICON","EpochGem","ColorRed",1,{1.3,1.3}}
		};
	};
	class ServicePoint {
        markerArray[] = {
            {"","ICON","EpochBG_Circle","ColorGrey",0.25,{0.85,0.85}}, 
            {"","ICON","EpochActive_Circle","ColorBlack",1,{0.85,0.85}}, 
            {"","ICON","EpochService","ColorGrey",1,{0.9,0.9},0,"'Service Point'"}
        };
	};
	class Radiation {
        markerArray[] = {
            {"","ICON","EpochBG_Triangle","ColorBlack",0.3,{1.8,1.8}}, 
            {"","ICON","EpochActive_Triangle","ColorYellow",1,{1.7,1.7}}, 
            {"","ICON","EpochRadiation","ColorYellow",1,{0.95,0.95}}
        };
	};
	class Satellite {
        markerArray[] = {
            {"","ICON","EpochBG_Triangle","ColorBlack",0.15,{1.5,1.5},58}, 
            {"","ICON","EpochActive_Triangle","ColorYellow",0.5,{1.3,1.3},58}, 
            {"","ICON","EpochSatellite","ColorYellow",1,{0.75,0.75},58}
        };
	};
	class MissionNoob {
		markerArray[] = {
			{"","ICON","EpochBG_Square","ColorBlack",0.15,{1.2,1.2}}, 
            {"","ICON","EpochActive_Square","ColorGreen",0.5,{1.2,1.2}}, 
            {"","ICON","EpochMissionNoob1","ColorYellow",1,{1,1}}
		};
	};
	class MissionNoobPlus {
		markerArray[] = {
			{"","ICON","EpochBG_Square","ColorBlack",0.15,{1.2,1.2}}, 
            {"","ICON","EpochActive_Square","ColorGreen",0.75,{1.2,1.2}}, 
            {"","ICON","EpochMissionNoob2","ColorYellow",1,{1,1}}
		};
	};
	class MissionSurvivor {
		markerArray[] = {
			{"","ICON","EpochBG_Square","ColorBlack",0.15,{1.2,1.2}}, 
            {"","ICON","EpochActive_Square","ColorBlue",0.5,{1.2,1.2}}, 
            {"","ICON","EpochMissionMedium1","ColorGreen",1,{1,1}}
		};
	};
	class MissionSurvivorPlus {
		markerArray[] = {
			{"","ICON","EpochBG_Square","ColorBlack",0.15,{1.2,1.2}}, 
            {"","ICON","EpochActive_Square","ColorBlue",0.75,{1.2,1.2}}, 
            {"","ICON","EpochMissionMedium2","ColorGreen",1,{1,1}}
		};
	};
	class MissionSlaughter {
		markerArray[] = {
			{"","ICON","EpochBG_Square","ColorBlack",0.15,{1.2,1.2}}, 
            {"","ICON","EpochActive_Square","ColorRed",0.5,{1.2,1.2}},
            {"","ICON","EpochMissionVeteran1","ColorBlue",1,{1,1}}
		};
	};
	class MissionSlaughterPlus {
		markerArray[] = {
			{"","ICON","EpochBG_Square","ColorBlack",0.15,{1.2,1.2}}, 
            {"","ICON","EpochActive_Square","ColorRed",0.75,{1.2,1.2}}, 
            {"","ICON","EpochMissionVeteran2","ColorBlue",1,{1,1}}
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
			{"","ICON","EpochBG_Circle","ColorWhite",0.15,{0.8,0.8}}, 
            {"","ICON","EpochActive_Circle","ColorRed",0.75,{0.8,0.8}}, 
            {"","ICON","EpochStaticTrader","ColorBlack",1,{0.7,0.7}}
		};
	};
	class DynamicTrader {
		markerArray[] = {
			{"","ICON","EpochBG_Circle","ColorWhite",0.15,{0.8,0.8}}, 
            {"","ICON","EpochActive_Circle","ColorGreen",0.75,{0.8,0.8}}, 
            {"","ICON","EpochDynamicTrader","ColorBrown",1,{0.7,0.7}}
		};
	};
	class NewDynamicTrader {
		markerArray[] = {
			{"","ICON","EpochBG_Circle","ColorWhite",0.15,{0.8,0.8}}, 
            {"","ICON","EpochActive_Circle","ColorKhaki",0.75,{0.8,0.8}}, 
            {"","ICON","EpochStaticTrader","ColorKhaki",1,{0.7,0.7}}
		};
	};
	class Shipwreck {
		markerArray[] = {
			{"","ICON","EpochBG_Circle","ColorWhite",0.15,{1.2,1.2}}, 
            {"","ICON","EpochActive_Circle","ColorOrange",1,{1.2,1.2}}, 
            {"","ICON","EpochShipwreck","ColorOrange",1,{1.3,1.3}}
		};
	};
};
