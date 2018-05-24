/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Tells server when a radio is equpped for use with custom radio channels

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/EPOCH_PutHandler.sqf
*/
params ["_unit", "_container", "_class"];
//Radio Check
if (configName(inheritsFrom(configFile >> "CfgWeapons" >> _class)) == "ItemRadio") then {
	if !(_class in(assignedItems player)) then {
		EPOCH_equippedItem_PVS = [_class,false,player];
	};
};

if (_class in ["EnergyPack","EnergyPackLg"] && (typeof _container) in ["SolarCharger_EPOCH","SolarChargerXL_EPOCH"]) then {
	["Charging ...",5,[[0,1,0,0.2],[1,1,1,1]]] call Epoch_Message;
};
