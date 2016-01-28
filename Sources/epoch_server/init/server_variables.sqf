EPOCH_BuildingSlots = [];
EPOCH_TraderSlots = [];
EPOCH_saveBldQueue = [];
EPOCH_saveVehQueue = [];
EPOCH_saveStorQueue = [];
EPOCH_saveBuildQueue = [];
EPOCH_cleanupQueue = [];
EPOCH_defaultVars_SEPXVar = EPOCH_defaultVars;
EPOCH_group_upgrade_lvl_SEPXVar = EPOCH_group_upgrade_lvl;
EPOCH_staticTraderLocations = [];
EPOCH_staticNPCTraderPos = [];

_configArray = [
	["serverRestart", false],
    ["forceRestartTime", 14400],
    ["StorageSlotsLimit",1500],
    ["BuildingSlotsLimit", 1500],
    ["StaticDateTime", []],
    ["timeDifference", 0],
    ["lootMultiplier", 0.5],
    ["WeatherChangeTime", 1200],
    ["WeatherStaticForecast", []],
    ["showEarthQuakes", true],
    ["showShippingContainers", true],
    ["cloneCost", 100],
    ["vehicleLockTime", 1800],
    ["antagonistChanceTrash", 0.09],
    ["antagonistChancePDeath", 0.33],
    ["antagonistChanceLoot", 0.09],
    ["allowedVehiclesList",
        [
            ["C_Offroad_01_EPOCH", 8],
            ["C_Quadbike_01_EPOCH", 8],
            ["C_Hatchback_01_EPOCH", 10],
            ["C_Hatchback_02_EPOCH", 10],
            ["C_SUV_01_EPOCH", 10],
            ["C_Rubberboat_EPOCH", 5],
            ["C_Rubberboat_02_EPOCH", 5],
            ["C_Rubberboat_03_EPOCH", 5],
            ["C_Rubberboat_04_EPOCH", 5],
            ["C_Van_01_box_EPOCH", 8],
            ["C_Van_01_transport_EPOCH", 9],
            ["C_Boat_Civil_01_EPOCH", 5],
            ["C_Boat_Civil_01_police_EPOCH", 5],
            ["C_Boat_Civil_01_rescue_EPOCH", 5],
            ["B_Heli_Light_01_EPOCH", 2],
            ["B_SDV_01_EPOCH", 2],
            ["B_MRAP_01_EPOCH", 3],
			["I_MRAP_03_EPOCH", 3],
            ["B_Truck_01_transport_EPOCH", 1],
            ["B_Truck_01_covered_EPOCH", 2],
            ["B_Truck_01_mover_EPOCH", 1],
            ["B_Truck_01_box_EPOCH", 1],
            ["O_Truck_02_covered_EPOCH", 2],
            ["O_Truck_02_transport_EPOCH", 1],
            ["O_Truck_03_covered_EPOCH", 1],
            ["O_Truck_02_box_EPOCH", 1],
            ["I_Heli_light_03_unarmed_EPOCH", 1],
            ["O_Heli_Light_02_unarmed_EPOCH", 1],
            ["I_Heli_Transport_02_EPOCH", 1],
            ["O_Heli_Transport_04_EPOCH", 1],
            ["O_Heli_Transport_04_bench_EPOCH", 1],
            ["O_Heli_Transport_04_box_EPOCH", 1],
            ["O_Heli_Transport_04_covered_EPOCH", 1],
            ["B_Heli_Transport_03_unarmed_EPOCH", 1],
            ["jetski_epoch", 7],
            ["K01", 2],
            ["K02", 2],
            ["K03", 2],
            ["K04", 2],
            ["ebike_epoch", 7],
            ["mosquito_epoch", 5],
			["C_Heli_Light_01_civil_EPOCH",5]
        ]
    ],
    ["taxRate", 0.1],
    ["starterTraderItems", [[], []]],
    ["SHOW_TRADERS", true],
    ["SHOW_JAMMERS", true],
    ["SHOW_BOATLOOT", true],
    ["NPCSlotsLimit", 50],
    ["forceStaticTraders", true],
    ["expiresBuilding", "604800"],
    ["expiresPlayer", "2592000"],
    ["expiresBank", "7776000"],
    ["expiresVehicle", "604800"],
    ["expiresAIdata", "604800"],
    ["hiveAsync", true],
    ["hiveAdminCmdExec", false],
    ["hiveAdminSavePlayerList", true],
    ["hiveAdminCmdTime", 5],
    ["DEBUG_VEH", false]
];

EPOCH_fnc_returnConfigEntry = {
    private["_defaultData", "_config", "_varData"];
    _defaultData = _this select 2;
	if (isClass(_this select 0)) then{
		_config = (_this select 0) >> (_this select 1);
		_varData = switch (typeName _defaultData) do {
			case "SCALAR": {if (isNumber (_config)) then { getNumber _config } else {_defaultData} };
			case "BOOL": {if (isText (_config)) then { (getText _config) isEqualTo "true" } else {_defaultData} };
			case "ARRAY": {if (isArray (_config)) then { getArray _config } else {_defaultData} };
			case "STRING": {if (isText (_config)) then { getText _config } else {_defaultData} };
			default {_defaultData};
		};
	} else {
		_varData = _defaultData;
	};
    _varData
};

// Cast default vars to global vars
// Note: TODO not all of these should be cast to a global var to save memory. If used only once use config lookup.
_serverSettingsConfig = configFile >> "CfgEpochServer";
{
    _varData = [_serverSettingsConfig,_x select 0,_x select 1] call EPOCH_fnc_returnConfigEntry;
    missionNamespace setVariable[format["EPOCH_%1", _x select 0], _varData];
}forEach _configArray;

// Vehicle slot limit set to total of all allowed limits
if (!isNil "EPOCH_allowedVehiclesList") then {
    _vehicleSlotLimit = 0;
    {_vehicleSlotLimit = _vehicleSlotLimit + (_x select 1)} forEach EPOCH_allowedVehiclesList;
    EPOCH_VehicleSlotsLimit = _vehicleSlotLimit;
};
