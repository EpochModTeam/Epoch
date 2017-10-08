/*
	DirtySanchez
	
	Local Markers are single instance and can only be seen by the player
	Use ['Name',position] call EPOCH_fnc_createLocalMarkerSet;
	
	Global Markers are mostly for server use
	Use ['Name',position] call EPOCH_fnc_createGlobalMarkerSet;
	
*/
class CfgLocalMarkerSets
{
	brushes[] = {"Solid","SolidFull","Horizontal","Vertical","Grid","FDiagonal","BDiagonal","DiagGrid","Cross","Border","SolidBorder"};
	class PlayerMarker {
		markerArray[] = {
			{"PlayerMarker1","ICON","EpochGPS","ColorBlue",1,{0.8,0.8},0,"format['%1/%2',(format[mapGridPosition player]) select  [0,3],(format[mapGridPosition player]) select  [3,3]]"},
			{"PlayerMarker2","ICON","EpochActive_Hex","ColorBlue",1,{0.8,0.8}},
			{"PlayerMarker3","ICON","EpochBG_Hex","ColorWhite",0.3,{0.8,0.8}}
		};
	};
	class DeathMarker {
		markerArray[] = {
			{"DeathMarker1","ICON","EpochSkull","ColorRed",1,{0.8,0.8},0,"str(name player)"},
			{"DeathMarker2","ICON","EpochActive_Circle","ColorRed",1,{0.8,0.8}},
			{"DeathMarker3","ICON","EpochBG_Circle","ColorPink",0.3,{0.8,0.8}}
		};
	};
};
