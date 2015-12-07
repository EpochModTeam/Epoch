/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Fixes to remove global exec of killed eh payload on map objects. Update: 12/4/2015 still needed as of 1.54

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_config/Configs/CfgVehicles/Fixes.hpp
*/

class House;
class House_F: House
{
	class DestructionEffects;
};
class House_Small_F;
class Ruins_F;

class PowerLines_base_F : House_F
{
	mapSize = 2.35;
	author = "$STR_A3_Bohemia_Interactive";
	_generalMacro = "PowerLines_base_F";
	scope = 0;
	scopeCurator = 0;
	displayName = "";
	model = "\A3\Weapons_F\empty.p3d";
	vehicleClass = "Structures_Infrastructure";
	cost = 100;
	compatibleWires[] = {};
	class EventHandlers
	{
		killed = "if (isServer) then {this call compile preprocessFileLineNumbers ""\A3\Structures_F\Ind\PowerLines\Scripts\column_ruins.sqf""};";
	};
};

class PowerLines_Small_base_F : House_Small_F
{
	mapSize = 2.79;
	author = "$STR_A3_Bohemia_Interactive";
	_generalMacro = "PowerLines_Small_base_F";
	scope = 0;
	scopeCurator = 0;
	displayName = "";
	model = "\A3\Weapons_F\empty.p3d";
	vehicleClass = "Structures_Infrastructure";
	compatibleWires[] = {};
	cost = 100;
	class EventHandlers
	{
		killed = "if (isServer) then {this call compile preprocessFileLineNumbers ""\A3\Structures_F\Ind\PowerLines\Scripts\column_ruins.sqf""};";
	};
};

class Land_Communication_anchor_F : House_F
{
	mapSize = 9.73;
	author = "$STR_A3_Bohemia_Interactive";
	_generalMacro = "Land_Communication_anchor_F";
	scope = 1;
	scopeCurator = 2;
	displayName = "$STR_A3_CfgVehicles_Land_Communication_anchor_F0";
	model = "\A3\Structures_F\Ind\Transmitter_Tower\Communication_anchor_F.p3d";
	vehicleClass = "Structures_Infrastructure";
	class DestructionEffects
	{
		class DestroyPhase1
		{
			simulation = "destroy";
			type = "DelayedDestruction";
			lifeTime = 1;
			position = "";
			intensity = 1;
			interval = 1;
		};
	};
	class EventHandlers
	{
		killed = "if (isServer) then {this call compile preprocessFileLineNumbers ""\A3\Structures_F\Ind\Transmitter_Tower\Scripts\anchor_ruins.sqf""};";
	};
};
class Land_Communication_F : House_F
{
	mapSize = 4.53;
	author = "$STR_A3_Bohemia_Interactive";
	_generalMacro = "Land_Communication_F";
	scope = 1;
	scopeCurator = 2;
	displayName = "$STR_A3_CfgVehicles_Land_Communication_F0";
	model = "\A3\Structures_F\Ind\Transmitter_Tower\Communication_F.p3d";
	vehicleClass = "Structures_Infrastructure";
	cost = 40000;
	class EventHandlers
	{
		killed = "if (isServer) then {this call compile preprocessFileLineNumbers ""\A3\Structures_F\Ind\Transmitter_Tower\Scripts\tower_ruins.sqf""};";
	};
};
