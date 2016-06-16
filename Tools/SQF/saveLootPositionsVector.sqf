/*
 Made for A3 Epoch Mod
 EpochMod.com
 by Aaron Clark - [VB]AWOL

 This work is licensed under a Creative Commons Attribution-ShareAlike 4.0 International License.
 http://creativecommons.org/licenses/by-sa/4.0/

 Changelog:
 axeman - Added Load option. Looks in mission config (description.ext) for standard Epoch CfgBuildingLootPos. If not found in mission loads from configFile then warns if not found.
 axeman - Added / Updated hints.
 axeman - Add Loot / UnLoot Object.

 Controls:
~ = starts the placement
Enter = to Select new Building target
< or > = Cycle between building classes found in the EPB array
Space = picks up and drops
Delete = delete cursorTarget
Ctrl+C = Create config and fill clipboard
End = Delete Everything
PageUp/Down = cycle loot objects (Shift =  to switch to simulated)
Up/Down Arrow = Raise /lower loot placement (Alt = Slow, Ctrl = Fast)
Right/Left Arrow = Rotate placement (Alt = Slow, Ctrl = Fast)
L = Load loot objects from mission config, if not found defaults from config are loaded.
Ctrl+L = Load all existing configured buildings into EPB array.
Ctrl+X = remove loot objects
Q or Z = Move object in or out.
R = Loot / UnLoot Object.
*/


BIS_fnc_returnVector = {
    private ["_v","_d","_x","_y"];
    _v = +(_this select 0);
    _d = _this select 1;
    _x = _v select 0;
    _y = _v select 1;
    _v set [0, (cos _d)*_x - (sin _d)*_y];
    _v set [1, (sin _d)*_x + (cos _d)*_y];
    _v
};

_import = ["Land_Slum_01_F","Land_Shed_03_F","Land_Slum_02_F","Land_House_Native_02_F","Land_House_Small_03_F","Land_House_Native_01_F","Land_Shed_05_F","Land_Shed_04_F","Land_Addon_05_F","Land_Shed_06_F","Land_House_Small_04_F","Land_House_Small_01_F","Land_Shop_Town_04_F","Land_Shop_Town_01_F","Land_House_Small_05_F","Land_Slum_05_F","Land_WaterTower_01_F","Land_Shed_02_F","Land_House_Small_06_F","Land_Shop_Town_02_F","Land_House_Small_02_F","Land_Shed_01_F","Land_Shop_Town_03_F","Land_Addon_03_F","Land_MetalShelter_01_F","Land_MetalShelter_02_F","Land_Slum_03_F","Land_Supermarket_01_F","Land_Shop_City_04_F","Land_Addon_02_F","Land_Addon_04_F","Land_House_Big_05_F","Land_Shop_City_07_F","Land_Addon_01_F","Land_House_Big_03_F","Land_House_Big_01_F","Land_Hotel_02_F","Land_Slum_04_F","Land_GarageShelter_01_F","Land_WoodenShelter_01_F","Land_PierWooden_02_hut_F","Land_Church_03_F","Land_Shed_07_F","Land_School_01_F","Land_Temple_Native_01_F","Land_Shop_City_06_F","Land_Shop_Town_05_F","Land_Shop_City_03_F","Land_Church_01_F","Land_Warehouse_03_F","Land_FireEscape_01_short_F","Land_House_Big_04_F","Land_Shop_City_02_F","Land_Shop_City_01_F","Land_Hotel_01_F","Land_WindmillPump_01_F","Land_Shop_Town_05_addon_F","Land_FuelStation_01_shop_F","Land_FuelStation_01_workshop_F","Land_FuelStation_01_pump_F","Land_FuelStation_02_workshop_F","Land_Mausoleum_01_F","Land_Barracks_01_grey_F","Land_Church_02_F","Land_SCF_01_warehouse_F","Land_Shed_Small_F","Land_GuardHouse_01_F","Land_Airport_01_controlTower_F","Land_Airport_01_terminal_F","Land_FuelStation_02_pump_F","Land_dp_smallTank_F","Land_Barracks_01_camo_F","Land_spp_Transformer_F","Land_TBox_F","Land_FuelStation_02_roof_F","Land_House_Big_02_F","Land_PierWooden_01_dock_F","Land_PierWooden_01_hut_F","Land_SCF_01_storageBin_medium_F","Land_ContainerLine_01_F","Land_DPP_01_waterCooler_F","Land_DPP_01_smallFactory_F","Land_GantryCrane_01_F","Land_ContainerLine_03_F","Land_StorageTank_01_small_F","Land_MobileCrane_01_F","Land_SCF_01_shed_F","Land_ContainerLine_02_F","Land_FireEscape_01_tall_F","Land_MobileCrane_01_hook_F","Land_Shop_City_05_F","Land_MultistoryBuilding_01_F","Land_MultistoryBuilding_03_F","Land_MultistoryBuilding_04_F","Land_Cathedral_01_F","Land_Airport_01_hangar_F","Land_Airport_02_controlTower_F","Land_Airport_02_terminal_F","Land_Airport_02_hangar_right_F","Land_Airport_02_hangar_left_F","Land_BasaltWall_01_gate_F","Land_DPP_01_mainFactory_F","Land_CombineHarvester_01_wreck_F","Land_SCF_01_heap_bagasse_F","Land_SCF_01_generalBuilding_F","Land_SCF_01_washer_F","Land_SCF_01_shredder_F","Land_SCF_01_clarifier_F","Land_SCF_01_feeder_F","Land_SCF_01_chimney_F","Land_SCF_01_boilerBuilding_F","Land_SCF_01_crystallizer_F","Land_SCF_01_crystallizerTowers_F","Land_Radar_Small_F","Land_MiningShovel_01_abandoned_F","Land_SM_01_reservoirTower_F","Land_HaulTruck_01_abandoned_F","Land_Warehouse_01_F","Land_Warehouse_02_F","Land_SM_01_shelter_narrow_F","Land_SM_01_shelter_wide_F","Land_SM_01_shed_unfinished_F","Land_WarehouseShelter_01_F","Land_SY_01_reclaimer_F","Land_SY_01_stockpile_01_F","Land_SY_01_stockpile_02_F","Land_ContainerCrane_01_F","Land_SM_01_shed_F"];

EPB = [];
{
    if !(_x in EPB) then {
        EPB pushBack _x;
    };
} forEach _import;

EPBCount = count EPB;

player allowDamage false;
player enableFatigue false;
EP_distance = 2;
EPOCH_vehTarget = objNull;

Bed_EPOCH = [[[0,0,0.6],[0,0,-0.1]],[[0,0,0.6],[0,0,0.9]],[[0,0,0.5],[1.1,0,0.5]],[[0,0,0.5],[-0.7,0,0.5]],[[0,0,0.5],[0,1.4,0.5]],[[0,0,0.5],[0,-1.4,0.5]]];
Fridge_EPOCH = [[[0,0,1.1],[0,0,-0.1]],[[0,0,1.1],[0,0,2.1]],[[0,0,1.1],[0.5,0,1.1]],[[0,0,1.1],[-0.5,0,1.1]],[[0,0,1.1],[0,0.4,1.1]],[[0,0,1.1],[0,-0.9,1.1]]];
Shelf_EPOCH = [[[0,0,1],[0,0,-0.1]],[[0,0,1],[0,0,1.8]],[[0,0,1],[0.5,0,1]],[[0,0,1],[-0.5,0,1]],[[0,0,1],[0,0.2,1]],[[0,0,1],[0,-0.6,1]]];
Couch_EPOCH = [[[0,0,0.4],[0,0,-0.1]],[[0,0,0.4],[0,0,1.2]],[[0,0,0.4],[1.3,0,0.4]],[[0,0,0.4],[-0.3,0,0.4]],[[0,0,0.4],[0,1.4,0.4]],[[0,0,0.4],[0,-1.4,0.4]]];
wardrobe_epoch = [[[0,0,1.3],[0,0,-0.1]],[[0,0,1.3],[0,0,2.3]],[[0,0,1.3],[0.7,0,1.3]],[[0,0,1.3],[-0.7,0,1.3]],[[0,0,1.3],[0,0.4,1.3]],[[0,0,1.3],[0,-0.6,1.3]]];
cooker_epoch = [[[0,0,0],[0,0,-0.1]],[[0,0,0],[0,0,0.7]],[[0,0,0],[0.4,0,0]],[[0,0,0],[-0.4,0,0]],[[0,0,0],[0,0.5,0]],[[0,0,0],[0,-0.7,0]]];
Chair_EPOCH = [[[0,0,0.5],[0,0,-0.1]],[[0,0,0.5],[0,0,1.5]],[[0,0,0.6],[0.6,0,0.6]],[[0,0,0.6],[-0.6,0,0.6]],[[0,0,0.6],[0,0.6,0.6]],[[0,0,0.5],[0,-0.6,0.5]]];
Filing_epoch = [[[0,0,0.8],[0,0,-0.1]],[[0,0,0.8],[0,0,1.6]],[[0,0,0.8],[0.3,0,0.8]],[[0,0,0.8],[-0.3,0,0.8]],[[0,0,0.8],[0,0.4,0.8]],[[0,0,0.8],[0,-0.5,0.8]]];
Pelican_EPOCH = [[[0,0,0.2],[0,0,-0.1]],[[0,0,0.2],[0,0,0.7]],[[0,0,0.2],[0.9,0,0.2]],[[0,0,0.2],[-0.9,0,0.2]],[[0,0,0.2],[0,0.6,0.2]],[[0,0,0.2],[0,-0.4,0.2]]];
Table_EPOCH = [[[0,0,0.5],[0,0,-0.1]],[[0,0,0.5],[0,0,0.8]],[[0,0,0.5],[1.1,0,0.5]],[[0,0,0.5],[-1,0,0.5]],[[0,0,0.5],[0,0.5,0.5]],[[0,0,0.5],[0,-0.7,0.5]]];
Locker_EPOCH = [[[0,0,1.1],[0,0,-0.1]],[[0,0,1.1],[0,0,2.1]],[[0,0,1.1],[1,0,1.1]],[[0,0,1.1],[-0.9,0,1.1]],[[0,0,1.1],[0,0.4,1.1]],[[0,0,1.1],[0,-0.5,1.1]]];
ToolRack_EPOCH = [[[0,0,1.5],[0,0,-0.1]],[[0,0,1.5],[0,0,2.3]],[[0,0,1.5],[1,0,1.5]],[[0,0,1.5],[-0.9,0,1.5]],[[0,0,1.5],[0,0.05,1.5]],[[0,0,1.5],[0,-0.4,1.5]]];
Shoebox_EPOCH = [[[0,0,0.1],[0,0,-0.1]],[[0,0,0.1],[0,0,0.3]],[[0,0,0.1],[0.3,0,0.1]],[[0,0,0.1],[-0.3,0,0.1]],[[0,0,0.1],[0,0.2,0.1]],[[0,0,0.1],[0,-0.2,0.1]]];
Tarp_EPOCH = [[[0,0,0.2],[0,0,-0.1]],[[0,0,0.2],[0,0,1]],[[0,0,0.2],[0.9,0,0.2]],[[0,0,0.2],[-0.9,0,0.2]],[[0,0,0.2],[0,1,0.2]],[[0,0,0.2],[0,-0.9,0.2]]];
Freezer_EPOCH = [[[0,0,0.5],[0,0,-0.1]],[[0,0,0.5],[0,0,1.1]],[[0,0,0.5],[0.7,0,0.5]],[[0,0,0.5],[-0.7,0,0.5]],[[0,0,0.5],[0,0.5,0.5]],[[0,0,0.5],[0,-0.6,0.5]]];
Cabinet_EPOCH = [[[0,0,0],[0,0,-0.4]],[[0,0,0],[0,0,0.4]],[[0,0,0],[0.2,0,0]],[[0,0,0],[-0.1,0,0]],[[0,0,0],[0,0.3,0]],[[0,0,0],[0,-0.3,0]]];

EPOCH_lootClassesRaw = [
    ["shelfPos", "Shelf_EPOCH", true],
    ["fridgePos", "Fridge_EPOCH", true],
    ["bedPos", "Bed_EPOCH", false],
    ["couchPos", "Couch_EPOCH", false],
    ["wardrobePos", "wardrobe_epoch", false],
    ["cookerPos", "cooker_epoch", false],
    ["chairPos", "Chair_EPOCH", true],
    ["filingPos", "Filing_epoch", true],
    ["pelicanPos", "Pelican_EPOCH", false],
    ["tablePos", "Table_EPOCH", false],
    ["lockerPos", "Locker_EPOCH", false],
    ["toolRackPos", "ToolRack_EPOCH", false],
    ["shoeboxPos", "Shoebox_EPOCH", false],
    ["palletPos", "Tarp_EPOCH", false],
    ["freezerPos", "Freezer_EPOCH", false],
      ["cabinetPos", "Cabinet_EPOCH", false]
];
EPOCH_lootSIMClassesRaw = [
    ["shelfPos", "Shelf_SIM_EPOCH", true],
    ["fridgePos", "Fridge_SIM_EPOCH", true],
    ["bedPos", "Bed_SIM_EPOCH", false],
    ["couchPos", "Couch_SIM_EPOCH", false],
    ["wardrobePos", "wardrobe_SIM_epoch", false],
    ["cookerPos", "cooker_SIM_epoch", false],
    ["chairPos", "Chair_SIM_EPOCH", true],
    ["filingPos", "Filing_SIM_epoch", true],
    ["pelicanPos", "Pelican_SIM_EPOCH", false],
    ["tablePos", "Table_SIM_EPOCH", false],
    ["lockerPos", "Locker_SIM_EPOCH", false],
    ["toolRackPos", "ToolRack_SIM_EPOCH", false],
    ["shoeboxPos", "Shoebox_SIM_EPOCH", false],
    ["palletPos", "Tarp_SIM_EPOCH", false],
    ["freezerPos", "Freezer_SIM_EPOCH", false],
      ["cabinetPos", "Cabinet_EPOCH", false]
];

EPOCH_lootClassesCustom = [];
{
    EPOCH_lootClassesCustom pushBack (_x select 1);
} forEach EPOCH_lootClassesRaw;
EPOCH_lootClassesCount = count EPOCH_lootClassesCustom - 1;

EPOCH_lootClassesCustom2 = [];
{
    EPOCH_lootClassesCustom2 pushBack (_x select 1);
} forEach EPOCH_lootSIMClassesRaw;
EPOCH_lootClasses2Count = count EPOCH_lootClassesCustom2 - 1;

EPOCH_KeyUpCustom = {
    _dikCode = _this select 1;
    _shift = _this select 2;
    _ctrl = _this select 3;
    _alt = _this select 4;
    _handled = false;



    _handled
};

EPOCH_KeyDownCustom = {
    _dikCode = _this select 1;
    _shift = _this select 2;
    _ctrl = _this select 3;
    _alt = _this select 4;
    _handled = false;

    _zheightChanged = false;
    _pickupTarget   = false;

    if (isNil "Base_Z_height") then {
        Base_Z_height = 1;
    };

    if (isNil "Base_angle") then {
        Base_angle = getDir player;
    };

    if (isNil "Epoch_lootSelectedClassIndex") then {
        Epoch_lootSelectedClassIndex = 0;
    };

    if (isNil "Epoch_bldSelectedClassIndex") then {
        Epoch_bldSelectedClassIndex = 0;
    };


    _staticORSimArray = EPOCH_lootClassesCustom;
    if (_shift) then {
        _staticORSimArray = EPOCH_lootClassesCustom2;
    };

    _selectedClass = _staticORSimArray select Epoch_lootSelectedClassIndex;

    _worldPos = player modeltoworld [0,5,Base_Z_height];

    switch (_dikCode) do {
        case 0x2E: {
            hint "Saved to clipboard";
            if (_ctrl) then {
                copyToClipboard call EPOCH_dbg_saveLootPos;
            }
        };

        case 0x2D: {

            if (_ctrl) then {
                hint "removed loot objects";
                {
                    {deleteVehicle _x} forEach allMissionObjects _x;
                } forEach EPOCH_lootClassesCustom;
            }
        };

        case 0xD3: {

            if !(isNull(cursorObject)) then {
                deleteVehicle cursorObject;
                hint "Deleted Object";
            };
        };

        case 0xCF: {
            {deleteVehicle _x} forEach allMissionObjects "";
            hint "Deleted All Objects";
        };

        case 0x1C: {
            if !(isNull(cursorObject)) then {
                EP_building = cursorObject;
                hint format["Target Changed: %1", typeOf EP_building];
            };
        };

        case 0x29 : {

            hint "tilde";

            if (isNull EPOCH_vehTarget) then {
                EPOCH_vehTarget = createVehicle [_selectedClass, _worldPos, [], 0, "CAN_COLLIDE"];
                EPOCH_vehTarget disableCollisionWith player;

                EPOCH_vehTarget setDir Base_angle;
                EPOCH_vehTarget setPosATL _worldPos;

                hint str(EPOCH_vehTarget);
            } else {
                deleteVehicle EPOCH_vehTarget;
                hint "deleted";
            };
            _handled = true;
        };


        case 0x33 : {


            Epoch_bldSelectedClassIndex = ((Epoch_bldSelectedClassIndex + 1) min EPBCount) max 0;
            _selectedClass = EPB select Epoch_bldSelectedClassIndex;
            hint _selectedClass;

            {deleteVehicle _x} forEach allMissionObjects "";

            _selectedClass call EPOCH_LOOT;

            _handled = true;

        };

        case 0x34 : {


            Epoch_bldSelectedClassIndex = ((Epoch_bldSelectedClassIndex - 1) min EPBCount) max 0;
            _selectedClass = EPB select Epoch_bldSelectedClassIndex;
            hint _selectedClass;

            {deleteVehicle _x} forEach allMissionObjects "";

            _selectedClass call EPOCH_LOOT;
            _handled = true;

        };

        case 0xC9 : {

            Epoch_lootSelectedClassIndex = ((Epoch_lootSelectedClassIndex + 1) min EPOCH_lootClassesCount) max 0;
            _selectedClass = _staticORSimArray select Epoch_lootSelectedClassIndex;
            hint _selectedClass;

            _handled = true;

        };
        case 0xD1 : {
            Epoch_lootSelectedClassIndex = ((Epoch_lootSelectedClassIndex - 1) min EPOCH_lootClassesCount) max 0;
            _selectedClass = _staticORSimArray select Epoch_lootSelectedClassIndex;
            hint _selectedClass;
            _handled = true;

        };

        case 0xC8 : { hint "arrowup";
            _num = 0.1;
            if (_alt) then {
                _num = _num / 10;
            };
            if (_ctrl) then {
                _num = _num * 10;
            };
            if (_shift) then {
                _playerZ = getposATL player select 2;
                Base_Z_height = _playerZ;
            } else {
                Base_Z_height   = Base_Z_height + _num;
            };
            _zheightChanged = true;
            _handled        = true;
        };
        case 0xD0 : { hint "arrowdown";
            _num = 0.1;
            if (_alt) then {
                _num = _num / 10;
            };
            if (_ctrl) then {
                _num = _num * 10;
            };

            Base_Z_height   = Base_Z_height - _num;
            _zheightChanged = true;
            _handled        = true;
        };

        case 0x10: {
            _num = 0.1;
            if (_alt) then {
                _num = _num / 10;
            };
            if (_ctrl) then {
                _num = _num * 10;
            };
            EP_distance = ((EP_distance + _num) min 5) max 2 ;
            _handled        = true;
        };

        case 0x2C: {
            _num = 0.1;
            if (_alt) then {
                _num = _num / 10;
            };
            if (_ctrl) then {
                _num = _num * 10;
            };
            EP_distance = ((EP_distance - _num) min 5) max 2 ;
            _handled        = true;
        };

        case 0xCB : {

            _num = 1;
            if (_alt) then {
                _num = _num / 10;
            };
            if (_ctrl) then {
                _num = _num * 10;
            };

            Base_angle = Base_angle + _num;
            if (Base_angle > 360) then {
                Base_angle = 0;
            };

            hint "left";

            _handled = true;
        };
        case 0xCD : { hint "right";

            _num = 1;
            if (_alt) then {
                _num = _num / 10;
            };
            if (_ctrl) then {
                _num = _num * 10;
            };

            Base_angle = Base_angle - _num;
            if (Base_angle < 0) then {
                Base_angle = 360;
            };

            hint "right";

            _handled   = true;
        };

        case 0x39 : { hint "space";
            _handled = true;
            if (isNull EPOCH_vehTarget) then {
                if (!isnull(cursorObject)) then {
                   if (cursorObject isKindOf "WH_Loot" or cursorObject isKindOf "Constructions_modular_F"  or cursorObject isKindOf "Animated_Loot") then {

                        EPOCH_vehTarget = cursorObject;
                        _selectedClass  = typeOF EPOCH_vehTarget;

                        _index1 = EPOCH_lootClassesCustom find _selectedClass;
                        _index2 = EPOCH_lootClassesCustom2 find _selectedClass;
                        if (_index1 > -1) then {
                            Epoch_lootSelectedClassIndex = _index1;
                        } else {
                            if (_index2 > -1) then {
                                Epoch_lootSelectedClassIndex = _index1;
                            };
                        };
                        _pickupTarget = true;
                        Base_Z_height = (getposATL EPOCH_vehTarget) select 2;
                   };
                };
            } else {
                EPOCH_vehTarget = objNull;
            };
        };

        case 0x13 : {

            if(({(_x find typeof cursortarget) > -1} count EPOCH_lootClassesRaw) > 0)then{
                if(damage cursorObject < 1)then{
                    cursorObject setDamage 1;
                    Hint format ["%1 Looted",typeof cursorObject];
                }else{
                    cursorObject setDamage 0;
                    Hint format ["%1 Un-Looted",typeof cursorObject];
                };
            };
        };

        case 0x26 : {


            if (_ctrl) then {
                EPB = []; "if (isclass _x) then {EPB pushBack (configName _x); true}" configClasses (configFile >> "CfgBuildingLootPos")
            } else {

                _buildLoading = objNull;
                if !(isNull(EP_building)) then {
                    _buildLoading = EP_building
                }else{
                    _buildLoading = cursorObject;
                };

                _buildingPos = getPosATL _buildLoading;
                _config = missionConfigFile;
                _customLoot = true;
                _lootCount = 0;

                if!(isClass (_config >> "CfgBuildingLootPos" >> typeOf _buildLoading))then{
                _config = configFile;
                _customLoot = false;
                };

                if(isClass (_config >> "CfgBuildingLootPos" >> typeOf _buildLoading))then{

                    {
                        _thisLoot = _x select 1;
                        _thisRawLootPos = _x select 0;

                            {
                            _pos = _buildLoading modelToWorld [(_x select 0 select 0),(_x select 0 select 1),(_x select 0 select 2)];
                            _newLoot = createVehicle [_thisLoot,_pos, [], 0, "CAN_COLLIDE"];

                            _dir = (_x select 1) + (getDir _buildLoading);
                            if (_dir > 360) then {
                                _dir = _dir - 360;
                            };

                            _newLoot setDir _dir;
                            _lootCount = _lootCount + 1;
                            }forEach getArray(_config >> "CfgBuildingLootPos" >> typeOf _buildLoading >> _thisRawLootPos);

                    } forEach EPOCH_lootClassesRaw;

                hint format["Loading House %2\nCustom Loot: %1\nLoot Count: %3",_customLoot,typeOf _buildLoading, _lootCount];
                }else{
                hint format["House %1 Not Found",typeOf _buildLoading];

                };
            };

        };
    };


    if (!isnull(EPOCH_vehTarget)) then {
        if (typeOf EPOCH_vehTarget != _selectedClass) then {
            _curPos = getPos EPOCH_vehTarget;

            deleteVehicle EPOCH_vehTarget;

            EPOCH_vehTarget = createVehicle [_selectedClass, _curPos, [], 0, "CAN_COLLIDE"];
            EPOCH_vehTarget disableCollisionWith player;
            EPOCH_vehTarget setDir Base_angle;
            EPOCH_vehTarget setPosATL _curPos;
        }
    };
    _handled
};


EPOCH_dirOffset = {
    _return = ((getdir (_this select 0)) - (getdir (_this select 1)));
    if (_return < 0) then {
        _return = _return + 360;
    };
    _return
};

EPOCH_dbg_replaceBrackets = {
    _return = [];
    {
        _string = _x;
        if (_string == 93) then {
            _string = 125;
        };
        if (_string == 91) then {
            _string = 123;
        };
        _return pushBack _string;
    } forEach toArray(format['%1',_this]);
    _return = toString _return;
    _return
};

EPOCH_dbg_saveLootPos = {

    if (isNull(EP_building)) then {
        EP_building = nearestBuilding player;
    };

    _buildingClass = typeOf EP_building;

    _br         = toString [13,10];

    _config_str = "class " + _buildingClass +  " : Default {" + _br;
    _array      = [];

    {
        _simClass     = EPOCH_lootSIMClassesRaw select _forEachIndex;
        _objectsArray = nearestObjects [EP_building, [_x select 1, _simClass select 1], 100];
        if !(_objectsArray isEqualTo []) then {
            _config_str = _config_str +  format['    %1[] = {%2',_x select 0,_br];
            _countArray = (count _objectsArray) - 1;
            {
                _ppos            = EP_building worldToModel (getposATL _x);
                _directionOffset = [_x,EP_building] call EPOCH_dirOffset;
                _config_str      = _config_str +  format['        { %1, %2 }%3', _ppos call EPOCH_dbg_replaceBrackets, _directionOffset,if (_forEachIndex isEqualTo _countArray) then {_br} else {("," + _br)}];
            } forEach _objectsArray;
            _config_str = _config_str +  "    };" + _br;
        };
    } forEach EPOCH_lootClassesRaw;
    _config_str = _config_str + "};" + _br;
    _config_str
};

EPOCH_LOOT = {

    if !(isNull(EP_building)) then {
        deleteVehicle EP_building;
    };

    EP_building = createVehicle [_this, player modelToWorld [0,25,0] , [], 0, "CAN_COLLIDE"];
    EP_building setDir Base_angle;
    EP_building setPosATL _curPos;

    _loots = [
        ["shelfPos", "Shelf_EPOCH", true],
        ["fridgePos", "Fridge_EPOCH", true],
        ["bedPos", "Bed_EPOCH", false],
        ["couchPos", "Couch_EPOCH", false],
        ["wardrobePos", "wardrobe_epoch", false],
        ["cookerPos", "cooker_epoch", false],
        ["chairPos", "Chair_EPOCH", true],
        ["filingPos", "Filing_epoch", true],
        ["pelicanPos", "Pelican_EPOCH", false],
        ["tablePos", "Table_EPOCH", false],
        ["lockerPos", "Locker_EPOCH", false],
        ["toolRackPos", "ToolRack_EPOCH", false],
        ["shoeboxPos", "Shoebox_EPOCH", false],
        ["palletPos", "Tarp_EPOCH", false],
        ["freezerPos", "Freezer_EPOCH", false],
        ["cabinetPos", "Cabinet_EPOCH", false]
    ];

    _building = EP_building;

    _config = configFile >> 'CfgBuildingLootPos' >> (typeOf _building);

    _buildingPos = (getPosATL _building);

    {
        _configPos = _x select 0;
        _positions = getArray (_config >> _configPos);
        diag_log str(_positions);
        if (!(_positions isEqualTo [])) then{
            _class       = _x select 1;
            _randomColor = _x select 2;
            {
                if ((typeName _class) == 'ARRAY') then {
                    _classCount = count _class;
                    _class = _class select (floor(random _classCount));
                };

                _pos = _building modelToWorld (_x select 0);
                _buildingDir = getDir _building;
                _dir = (_x select 1) + _buildingDir;
                if (_dir > 360) then {
                    _dir = _dir - 360;
                };
                _item = createVehicle [_class, _pos, [], 0.0, 'CAN_COLLIDE'];
                _item setDir _dir;
                _item setPosATL _pos;

            } forEach _positions;
        };
    } forEach _loots;
};

KK_boundingBox = {
    private ["_obj","_bb","_bbx","_bby","_bbz","_arr","_y","_z"];
    _obj = _this;
    _bb = {
        _bbx = [_this select 0 select 0, _this select 1 select 0];
        _bby = [_this select 0 select 1, _this select 1 select 1];
        _bbz = [_this select 0 select 2, _this select 1 select 2];
        _arr = [];
        0 = {
            _y = _x;
            0 = {
                _z = _x;
                0 = {
                    0 = _arr pushBack (_obj modelToWorld [_x,_y,_z]);
                } count _bbx;
            } count _bbz;
            reverse _bbz;
        } count _bby;
        _arr pushBack (_arr select 0);
        _arr pushBack (_arr select 1);
        _arr
    };
    bbox = boundingBox _obj call _bb;

    for "_i" from 0 to 7 step 2 do {
        drawLine3D [
            bbox select _i,
            bbox select (_i + 2),
            [0,0,1,1]
        ];
        drawLine3D [
            bbox select (_i + 2),
            bbox select (_i + 3),
            [0,0,1,1]
        ];
        drawLine3D [
            bbox select (_i + 3),
            bbox select (_i + 1),
            [0,0,1,1]
        ];
    };
};



[] spawn {

    (findDisplay 46) displayAddEventHandler["KeyDown",{_this call EPOCH_KeyDownCustom}];
    (findDisplay 46) displayAddEventHandler["KeyUp",{_this call EPOCH_KeyUpCustom}];
};



"EPOCH_onEachFrame" call BIS_fnc_removeaddStackedEventHandler;
["EPOCH_onEachFrame", "onEachFrame", {

    if (!isnull(EPOCH_vehTarget)) then {

        if (!isnull(DUMMY)) then {
            deleteVehicle DUMMY;
        };
        DUMMY = "Sign_Arrow_Direction_F" createVehicle getpos player;

        _blocked = false;

        _target =  player;
        if (!isnull(EP_building)) then {
            _target = EP_building;
        };

        _worldPos = player modelToWorld[0, EP_distance, 0];
        _worldPos set [2,Base_Z_height];

        if (_worldPos distance player > 10) then {
            _blocked = true;
        };

        _worldPos = AGLtoASL _worldPos;

        _finalVectorDir = [vectorDir _target, Base_angle] call BIS_fnc_returnVector;
        DUMMY setVelocityTransformation [getPosASL DUMMY,_worldPos,velocity DUMMY,velocity DUMMY,vectorDir DUMMY,_finalVectorDir,vectorUp DUMMY,vectorUp player,1];
        _targetType = typeof EPOCH_vehTarget;


        {
            _x params ["_startV","_stopV"];

            _start = DUMMY modelToWorld _startV;
            _stop = DUMMY modelToWorld _stopV;

            _color = [1,1,1,1];
            _ins = lineIntersectsSurfaces [AGLToASL _start,AGLToASL _stop,EPOCH_vehTarget,player,true,1,"FIRE","NONE"];
            if !(_ins isEqualTo []) then {
                _color = [1,0,0,1];
                (_ins select 0) params ["_intersectPosASL","_surfaceNormal","_intersectObject","_parentObject"];
                hint str ([_forEachIndex,EPOCH_vehTarget]);
                switch (_forEachIndex) do {
                    case 0: {
                        _worldPos set [2, _intersectPosASL select 2];
                    };
                    case 1: {
                        _worldPos set [2, _intersectPosASL select 2];
                    };
                    case 2;
                    case 3;
                    case 4;
                    case 5: {
                        _blocked = true;
                    };
                };
            };

            drawLine3D [
                _start,
                _stop,
                _color
            ];

        } forEach (missionNamespace getVariable [_targetType,[]]);

        if (_blocked) then {
            _worldPos = getPosASL EPOCH_vehTarget;
        };
        EPOCH_vehTarget setVelocityTransformation [getPosASL EPOCH_vehTarget,_worldPos,velocity EPOCH_vehTarget,velocity EPOCH_vehTarget,vectorDir EPOCH_vehTarget,_finalVectorDir,vectorUp EPOCH_vehTarget,vectorUp player,1];
    };
    if (!isnull(EP_building)) then {
        EP_building call KK_boundingBox;
    };
}] call BIS_fnc_addStackedEventHandler;
