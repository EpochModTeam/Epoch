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

EPB = ["Land_runway_edgelight_blue_F","Land_Flush_Light_red_F","Land_TTowerBig_1_F","Land_LampHalogen_F","Land_Vysilac_FM","Land_Ss_hangard","Land_TTowerBig_2_F","Land_Dome_Small_F","Land_Ammostore2","Land_Garaz_s_tankem","Land_Army_hut2_int","Land_obihacka","Land_prebehlavka","Land_prolejzacka","Land_podlejzacka","Land_Army_hut_int","Land_Army_hut3_long_int","Land_Budova4_in","Land_Zed_dira_civil","Land_Ind_Shed_02_EP1","Land_Ind_Shed_01_EP1","Land_Radar_F","Land_Army_hut_storrage","Land_wpp_Turbine_V2_F","Land_Communication_F","Land_Army_hut2","Land_Com_tower_ep1","Land_Lampa_vysoka","Land_LampSolar_F","Land_ReservoirTank_Airport_F","Land_LampStreet_small_F","Land_LampDecor_F","Land_Pub_C","Land_HouseB1","Land_Kulna","Land_Fuel_tank_big","Land_fuel_tank_small","Land_Podesta_s10","Land_HouseA","Land_HouseA1","Land_IGA_GeneralStore","Land_Stoplight01","Land_Stoplight02","Land_HouseB","Land_Podesta_1_stairs4","Land_A_BuildingWIP_EP1","Land_Kostelik","Land_kolotoc","Land_houpacka","Land_Piskoviste","Land_Misc_GContainer_Big","Land_ladder_half","Land_Dum_istan4_big","Land_ladder","Land_Podesta_1_mid","Land_Market_stalls_02_EP1","Land_Podesta_1_mid_cornp","Land_Podesta_1_stairs2","Land_Panelak3","Land_water_tank","Land_Podesta_1_cornl","Land_Dum_istan2_01","Land_Lampa_sidl","Land_Zastavka_jih","Land_fs_feed_F","Land_Lampa_sidl_2","Land_Ind_FuelStation_Feed_EP1","Land_Ind_TankSmall","Land_Psi_bouda","Land_Dum_istan3_pumpa","Land_Podesta_5","Land_KBud","Land_Ind_FuelStation_Shed_EP1","Land_Metal_Shed_F","Land_Lampa_ind","Land_Ind_FuelStation_Build_EP1","Land_fs_roof_F","Land_Plot_rust_vrata","Land_Plot_rust_branka","Land_Komin","Land_Ind_Workshop01_02","Land_Nasypka","Land_Dum_istan3_hromada2","Land_LampShabby_F","Land_Hut_old02","Land_Misc_Cargo1Ao","Land_IGA_GeneralStore2","Land_Zastavka_sever","Land_seno_balik","Land_Ind_SawMillPen","Land_PoliceStation","Land_PostB","Land_E76_shop_single1","Land_Misc_Cargo1C","Land_BarGate_F","Land_Budova5","Land_Fuelstation","Land_Letistni_hala","Land_Nabrezi_najezd","Land_Molo_krychle2","Land_Molo_krychle","Land_House_C_10_EP1","Land_Pub_A","Land_Fuel_tank_stairs","Land_Plot_green_vrata","Land_Plot_istan1_rovny_gate","Land_Plot_Ohrada_Pruchozi","Land_Podesta_1_mid_cornl","Land_nav_pier_m_2","Land_Podesta_1_cube_long","Land_Wall_Gate_Ind2B_L","Land_sloup_vn","Land_sloup_vn_drat","Land_Plot_zed_drevo1_branka","land_nav_pier_m_end","Land_Bouda2_vnitrek","Land_E76_shop_multi1","Land_LampStreet_F","Land_A_Office02C","Land_Misc_Cargo1G","Land_Misc_Cargo2D","Land_Misc_Cargo1D","Land_Misc_Cargo2E","Land_Misc_Cargo1F","Land_Misc_Cargo2B","Land_Misc_Cargo1B","Land_Misc_Cargo2C","Land_Hotel","Land_Podesta_10","Land_Market_stalls_01_EP1","Land_Vysilac_FM2","Land_Vysilac_budova","Land_Telek1","Land_House_C_5_EP1","Land_Molo_drevo","Land_ruin_rubble","Land_Ind_Garage01_EP1","Land_Benzina_schnell","Land_Trafostanica_mala","Land_Ind_PowerStation_EP1","Land_Watertower1","Land_Ind_Pec_03","Land_Ind_Expedice_3","Land_Ind_BoardsPack1","Land_Tovarna1","Land_Ind_Coltan_Main_EP1","Land_Ind_Coltan_Conv1_end_EP1","Land_Ind_Coltan_Conv1_10_EP1","Land_Ind_Coltan_Conv1_Main_EP1","Land_Ind_Coltan_Hopper_EP1","Land_Misc_Coltan_Heap_EP1","Land_Ind_Coltan_Conv2_EP1","Land_Budova2","Land_Budova1","land_nav_pier_c","Land_IndPipe2_bigL_L","Land_Misc_Cargo1E","Land_IndPipe2_big_ground1","Land_A_Crane_02b","Land_Misc_Cargo1Bo","Land_A_Crane_02a","Land_IndPipe2_big_18","Land_IndPipe2_big_ground2","land_nav_pier_c_90","land_nav_pier_C_R","Land_NavigLight","land_nav_pier_C_R30","Land_Runway_edgelight","Land_Runway_PAPI_4","Land_Runway_PAPI_3","Land_Ind_BoardsPack2","Land_Runway_PAPI_2","Land_Runway_PAPI","Land_Ind_Timbers","land_nav_pier_C_L","Land_Zidka_branka","Land_New_WiredFence_10m_F","Land_Leseni4x","Land_House_C_4_EP1","Land_Fuelstation_army","Land_Dome_Big_F","Land_New_WiredFence_10m_Dam_F","land_nav_pier_c_t20","land_nav_pier_c_big","Land_Army_hut3_long","Land_Molo_drevo_bs","Land_Posed","Land_Molo_drevo_end","Land_Flush_Light_green_F","Land_GuardShed","Target","Land_fortified_nest_small","Land_Hlaska","Land_Bouda_plech","Land_Dam_Conc_20","Land_Dam_ConcP_20","Land_HelipadCircle_F","Land_Lampa_ind_zebr","Land_Hut03","Land_Hut01","Land_Podesta_1_stairs","Land_Leseni2x","Land_Dum_istan4_big_inverse","Land_Dum_istan4_detaily1","Land_Dum_istan4_inverse","Land_BoatSmall_1","Land_LampHarbour_F","Land_Radar_Small_F","Land_Garaz_bez_tanku","land_nav_pier_M_fuel","Land_Ind_SawMill","Land_Ind_Workshop01_03","Land_dp_smallTank_F","Land_SignB_Hotel_CZ","Land_Hotel_riviera1","Land_Podesta_1_cube","Land_Podesta_1_stairs3","Land_Hotel_riviera2","Land_Dum_mesto3_istan","Land_SignB_Hotel_CZ2","Land_Dum_istan2_02","Land_Dum_istan2_03","Land_Dum_istan3_hromada","Land_Dum_istan2_04a","Land_Dum_istan2b","Land_Dum_istan2_03a","Land_Cihlovej_Dum_in","Land_Cihlovej_dum","Land_Kostel2","Land_Sign_Bar_RU","Land_SignB_Hotel_CZ3","Land_Molo_beton","Land_Podesta_1_cornp","Land_Garaz","Land_TTowerSmall_2_F","Land_TTowerSmall_1_F","Land_Hut04","Land_BoatSmall_2a","Land_BoatSmall_2b","Land_Statek_kulna","Land_Nav_Boathouse_PierL","land_nav_pier_F_17","Land_Nav_Boathouse","Land_GH_Stairs_F","Land_Dum_istan4","Land_Nav_Boathouse_PierR","Land_Dum_istan3","Land_E76_tower2","Land_E76_tower4","Land_Strazni_vez","Land_Flush_Light_yellow_F","Land_Nabrezi","Land_Ind_Pec_03a","Land_Ind_Workshop01_box","Land_IndPipe2_SmallBuild2_R","Land_IndPipe2_Small_9","Land_IndPipe2_T_L","Land_IndPipe2_SmallL_L","Land_IndPipe2_bigL_R","Land_IndPipe2_big_18ladder","Land_Ind_Expedice_2","Land_Ind_MalyKomin","Land_IndPipe2_SmallBuild2_L","Land_IndPipe2_Small_ground1","Land_IndPipe2_bigBuild2_L","Land_Net_Fence_Gate_F","Land_Device_assembled_F","Land_Pier_F","Land_Podesta_s5","Land_HighVoltageEnd_F","Land_TBox_F","Land_A_TVTower_Mid","Land_A_TVTower_Top","Land_spp_Transformer_F","Land_Misc_Scaffolding","Land_dp_mainFactory_F","Land_Ind_TankSmall2","land_nav_pier_F_23","Land_Helfenburk_zed","Land_Dum_mesto_in","Land_Ind_Mlyn_02","Land_Ind_Mlyn_03","Land_Ind_Pec_02","Land_Ind_Mlyn_04","Land_LHD_1","Land_LHD_2","Land_LHD_3","Land_LHD_house_1","land_nav_pier_c2","Land_LHD_4","Land_LHD_house_2","Land_LHD_5","Land_LHD_elev_R","Land_LHD_6"];
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
