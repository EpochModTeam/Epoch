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
Q or Z = Move object in or out.
R = Loot / UnLoot Object.
*/

EPB = ["Land_Ind_SawMillPen","Land_seno_balik","Land_Shed_W03","Land_Ind_TankSmall","Land_Nasypka","Land_Shed_W4","Land_HouseV_1T","Land_HouseV_3I4","Land_Wall_Gate_Village","Land_Ind_TankSmall2","Land_HouseV_2I","Land_HouseV2_03","Land_Dum_olezlina","Land_Gate_wood2_5","Land_SignB_Pub_CZ2","Land_Ind_Expedice_2","Land_IndPipe2_bigBuild2_L","Land_Gate_Wood1_5","Land_IndPipe2_big_18ladder","Land_Ind_Expedice_3","Land_IndPipe2_big_18","Land_houseV_2T1","Land_IndPipe2_bigBuild1_R","Land_Misc_Cargo1Bo","Land_Ind_MalyKomin","Land_IndPipe2_big_ground1","Land_Lampa_ind","Land_Misc_Cargo1Ao","Land_Misc_GContainer_Big","Land_sloup_vn_drat","Land_sloup_vn","Land_Misc_Cargo1F","Land_IndPipe2_big_9","Land_Misc_Cargo1B","Land_HouseV_3I1","Land_Fuel_tank_big","Land_Ind_Stack_Big","Land_Dum_mesto3","Land_Sara_domek_vilka","Land_ladder","Land_Misc_Cargo1C","Land_MBG_Killhouse_4","Land_MBG_Warehouse","Land_Farm_WTower","Land_Nav_Boathouse_PierL","Land_Nav_Boathouse","Land_Trafostanica_velka_draty","Land_Kontejner","Land_aif_tovarna1","Land_Fuel_tank_stairs","Land_Trafostanica_velka","Land_Ind_Workshop01_02","Land_Wall_Gate_Ind1_R","Land_Dum_mesto2l","Land_Lampa_sidl","Land_MBG_Cinderwall_5","Land_MBG_Cinderwall_5_Corner","Land_HouseV2_03B","Land_Ind_Timbers","land_nav_pier_m_end","Land_CncBlock","Land_Ind_SawMill","land_nav_pier_m_1","Land_MBG_Killhouse_3","Land_fuel_tank_small","Land_MBG_Killhouse_2","Land_Nav_Boathouse_PierT","Land_A_Castle_Bastion","Land_Plot_green_branka","Land_Wall_Gate_Ind2A_R","Land_A_Castle_Wall2_30","Land_water_tank","land_nav_pier_m","Land_Ind_Shed_02_end","Land_Ind_Shed_02_main","Land_aif_zluty_statek_in","Land_A_Castle_Wall1_20","land_mbg_brickhouse_01","Land_A_Castle_Wall1_Corner","Land_A_Castle_Wall1_End_2","Land_A_Castle_Wall1_End","Land_aif_hotel","Land_A_Castle_Wall2_End_2","Land_A_Castle_Wall2_End","Land_Shed_M03","Land_Cihlovej_Dum_in","Land_HouseV_3I3","Land_MBG_Killhouse_1","Land_HouseV_3I2","Land_Misc_Scaffolding","Land_SignB_Pub_CZ3","Land_Sara_domek_ruina","Land_HouseBlock_C4","Land_HouseBlock_C5","Land_HouseBlock_B5","Land_House_C_4_EP1","Land_HouseBlock_B3","Land_HouseBlock_B2","Land_HouseBlock_B6","Land_HouseV2_01B","Land_HouseBlock_C1","Land_HouseBlock_B1","Land_HouseBlock_A1","Land_HouseBlock_D1","Land_MBG_GER_HUS_4","Land_Brana02nodoor","Land_HouseBlock_C3","Land_SignB_Hotel_CZ","Land_HouseBlock_A2","Land_SignB_Hotel_CZ3","Land_HouseBlock_D2","Land_SignB_Pharmacy","Land_House_C_10_EP1","Land_kolotoc","Land_HouseBlock_C2","Land_MBG_Cinderwall_5_SteelDoor","Land_Company3_2","Land_Wall_Gate_Ind2B_L","land_mbg_apartments_big_04","Land_Misc_Coltan_Heap_EP1","Land_MBG_Cinderwall_5_Gate","Land_Wall_Gate_Ind2A_L","Land_Misc_WaterStation","Land_Misc_Cargo1E","Land_zavora_2","Land_A_FuelStation_Feed","Land_A_FuelStation_Shed","Land_MBG_GER_RHUS_5","Land_Ind_Mlyn_D1","Land_Nav_Boathouse_PierR","Land_Lampa_ind_zebr","Land_HouseV2_05","Land_Wall_Gate_Wood1","land_mbg_apartments_big_01","Land_BoatSmall_1","Land_Dum_zboreny_total","Land_MBG_Cinderwall_5_WoodDoor","Land_Kostel","Land_A_Villa_EP1","Land_PowLine_wire_A_right_EP1","Land_Plot_green_vrata","Land_PowLine_wire_AB_EP1","Land_PowLine_wire_BB_EP1","Land_PowLine_wire_A_left_EP1","Land_Budova4_in","Land_IndPipe2_bigL_L","Land_Ind_Pec_03","Land_IndPipe2_bigL_R","Land_Misc_Cargo2E","Land_Ind_Coltan_Main_EP1","Land_Ind_Shed_01_end","Land_Ind_Shed_01_main","Land_Ind_Coltan_Hopper_EP1","Land_Trafostanica_mala","Land_MBG_GER_ESTATE_2","Land_sloup_vn_dratZ","Land_BoatSmall_2a","Land_BoatSmall_2b","Land_Dam_Barrier_40","Land_A_TVTower_Top","Land_A_TVTower_Mid","Land_MBG_GER_PUB_2","land_nav_pier_c_90","Land_Ind_Workshop01_03","land_nav_pier_c_t15","Land_Misc_CargoMarket1a_EP1","Land_Wall_Gate_Ind1_L","Land_Gate_IndVar2_5","Land_MBG_Shoothouse_1","Land_Leseni2x","Land_Komin","land_nav_pier_C_L30","land_nav_pier_c2","land_nav_pier_c","Land_Misc_Cargo1D","land_nav_pier_c2_end","Land_A_Crane_02b","Land_A_Crane_02a","Land_Dum_m2","Land_Misc_Cargo2C","land_nav_pier_C_R30","Land_Misc_Cargo2D","Land_Misc_Cargo1G","Land_Misc_Cargo2B","Land_HouseBlock_A1_2","Land_Ind_SiloVelke_02","Land_Ind_SiloVelke_most","Land_NAV_Lighthouse","Land_Shed_M01","Land_KBud","land_nav_pier_F_23","Land_Pumpa","Land_Shed_W02","Land_Church_05R","Land_ruin_01_PMC","Land_HouseBlock_A2_1","Land_Domek_rosa","Land_Bouda1","land_mbg_brickhouse_03","Land_Bouda_plech","Land_MBG_GER_RHUS_2","Land_MBG_GER_RHUS_1","Land_MBG_Garage_Single_B","Land_Terrace_K_1_EP1","Land_Stoplight02","Land_A_Castle_WallS_10","Land_A_Castle_WallS_5_D","land_nav_pier_c_270","Land_SignB_Hotel_CZ2","Land_A_Castle_Wall1_20_Turn","Land_HouseV_1I2","Land_aif_watertower1","Land_MBG_Cinderwall_2p5","Land_Statek_hl_bud","Land_Plot_rust_branka","Land_Wall_Gate_Kolchoz","Land_mbg_cinderwall_5_low","Land_Ind_BoardsPack1","Land_Bouda3","Land_A_statue01","Land_Sara_domek_kovarna","Land_Deutshe","Land_Lampa_sidl_2","Land_Wall_CGry_5_D","Land_Ind_BoardsPack2","Land_houpacka","Land_Mil_Barracks_L","Land_aif_strazni_vez","Land_NavigLight","Land_runway_edgelight","Land_Dirthump03_EP1","Land_Dirthump02_EP1","Land_Church_tomb_3","Land_Church_tomb_2","Land_Dirthump01_EP1","Land_Wall_Gate_Ind2B_R","Land_Kostel3","Land_IndPipe1_stair","land_nav_pier_C_L","land_nav_pier_C_R","Land_MBG_ATC_Tower","Land_MBG_ATC_Segment","Land_MBG_ATC_Base","land_nav_pier_C_R10","Land_aif_hlaska","Land_aif_kasarna_rohova","Land_aif_kasarna_prujezd","Land_aif_kasarna","Land_Mil_Barracks","Land_aif_heavyf","land_nav_pier_C_L10","Land_aif_hotel_bio","Land_Plot_Ohrada_Pruchozi","Land_A_Castle_WallS_End","Land_HouseV2_04_interier_dam","Land_Zed_dira_civil","Land_Wall_Gate_Ind2Rail_R","Land_Wall_Gate_Ind2Rail_L","Land_HouseV_2L_dam","Land_Fort_Watchtower","Land_Dam_Conc_20","Land_HouseV2_03B_dam","Land_Lampa_sidl_3","Land_HouseV2_01B_dam","Land_HouseV2_01A_dam","Land_HouseV2_03_dam","Land_Ind_Pec_02","Land_Dam_ConcP_20","Land_Kostel_trosky","Land_HouseV_1I3","Land_Wall_CBrk_5_D"];
EPBCount = count EPB;

player allowDamage false;
player enableFatigue false;
EP_distance = 2;
EPOCH_vehTarget = objNull;
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

        case 0xD3: {

            if !(isNull(cursorTarget)) then {
                deleteVehicle cursorTarget;
                hint "Deleted Object";
            };
        };

        case 0xCF: {
            {deleteVehicle _x} forEach allMissionObjects "";
            hint "Deleted All Objects";
        };

        case 0x1C: {
            if !(isNull(cursorTarget)) then {
                EP_building = cursorTarget;
                hint format["Target Changed: %1", typeOf EP_building];
            };
        };

        case 0x29 : {

            hint "tilde";

            if (isnil "EPOCH_vehTarget") then {
                EPOCH_vehTarget = createVehicle [_selectedClass, _worldPos, [], 0, "CAN_COLLIDE"];
                EPOCH_vehTarget setDir Base_angle;
                EPOCH_vehTarget setPosATL _worldPos;

                hint str(EPOCH_vehTarget);
            } else {
                deleteVehicle EPOCH_vehTarget;
                EPOCH_vehTarget = nil;
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
            Base_Z_height   = Base_Z_height + _num;
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
            if (isnil "EPOCH_vehTarget") then {

                if (!isnull(cursorTarget)) then {
                   if (cursorTarget isKindOf "WH_Loot" or cursorTarget isKindOf "Constructions_modular_F"  or cursorTarget isKindOf "Animated_Loot") then {

                        EPOCH_vehTarget = cursorTarget;
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

                if (!isnull(EPOCH_vehTarget)) then {
                    detach EPOCH_vehTarget;
                    EPOCH_vehTarget = nil;
                };
            };
        };

		case 0x13 : {

			if(({(_x find typeof cursortarget) > -1} count EPOCH_lootClassesRaw) > 0)then{
				if(damage cursorTarget < 1)then{
				cursorTarget setDamage 1;
				Hint format ["%1 Looted",typeof cursorTarget];
				}else{
				cursorTarget setDamage 0;
				Hint format ["%1 Un-Looted",typeof cursorTarget];
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
					_buildLoading = cursorTarget;
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
            _config_str = _config_str +  format['%1[] = {%2',_x select 0,_br];
            _countArray = (count _objectsArray) - 1;
            {
                _ppos            = EP_building worldToModel (getposATL _x);
                _directionOffset = [_x,EP_building] call EPOCH_dirOffset;
                _config_str      = _config_str +  format['{ %1, %2 }%3', _ppos call EPOCH_dbg_replaceBrackets, _directionOffset,if (_forEachIndex isEqualTo _countArray) then {_br} else {("," + _br)}];
            } forEach _objectsArray;
            _config_str = _config_str +  "};" + _br;
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
    (findDisplay 46) displayRemoveAllEventHandlers "KeyDown";
    (findDisplay 46) displayAddEventHandler["KeyDown",{_this call EPOCH_KeyDownCustom}];
};


onEachFrame {
    if (!isnull(EPOCH_vehTarget)) then {
        _worldPos = player modelToWorld[0, EP_distance, 0];

        _worldPos set [2,Base_Z_height];
        if !(surfaceIsWater _worldPos) then {
            _worldPos = ATLToASL _worldPos;
        };

        _target =  player;
        if (!isnull(EP_building)) then {
           _target = EP_building;
        };

        _finalVectorDir = [vectorDir _target, Base_angle] call EPOCH_returnVector;
        EP = [getPosASL EPOCH_vehTarget,_worldPos,velocity EPOCH_vehTarget,velocity player,vectorDir EPOCH_vehTarget,_finalVectorDir,vectorUp EPOCH_vehTarget,vectorUp player,1];
        EPOCH_vehTarget setVelocityTransformation [getPosASL EPOCH_vehTarget,_worldPos,velocity EPOCH_vehTarget,velocity player,vectorDir EPOCH_vehTarget,_finalVectorDir,vectorUp EPOCH_vehTarget,vectorUp player,1];
    };

    if (!isnull(EP_building)) then {
        EP_building call KK_boundingBox;
    };
};
