if (isnil "LootMarkersPositions" && isnil "LootMarkers") then {
	_Skipbuildings = [
		"Land_LandMark_F",
		"Land_wpp_Turbine_V2_F",
		"Land_Mil_Barracks_L",
		"Land_Mil_Guardhouse",
		"Land_Mil_ControlTower_ruins",
		"Land_Mil_ControlTower",
		"Land_Mil_Barracks",
		"Land_Mil_House",
		"Land_SS_hangar",
		"Land_a_stationhouse",
		"Land_Misc_WaterStation",
		"Land_HouseV_3I4",
		"Land_HouseV_3I3",
		"Land_HouseV_3I2",
		"Land_HouseV_3I1",
		"Land_HouseV_2T2",
		"Land_HouseV_2T1",
		"Land_HouseV_2L",
		"Land_HouseV_2I",
		"Land_HouseV_1t",
		"Land_HouseV_1L2",
		"Land_StoneWell_01_F",
		"Land_FeedRack_01_F",
		"Land_HighVoltageTower_largeCorner_F",
		"Land_HighVoltageTower_large_F",
		"Land_Hutch_01_F",
		"Land_Communication_F",
		"Land_ChickenCoop_01_F",
		"Land_MysteriousBell_01_F",
		"Land_Calvary_03_F",
		"Land_Chapel_02_white_ruins_F",
		"Land_Sawmill_01_illuminati_tower_F",
		"Land_DryToilet_01_F",
		"Land_House_2B02_ruins_F",
		"Land_House_1W08_ruins_F",
		"Land_FuelStation_Shed_F",
		"Land_FuelStation_Feed_F",
		"Land_Greenhouse_01_damaged_F",
		"Land_Slums02_4m",
		"Land_Metal_Shed_ruins_F",
		"Land_FeedShack_01_F",
		"Land_TBox_ruins_F",
		"Land_Slum_House03_ruins_F",
		"Land_Smokestack_03_ruins_F",
		"Land_Slum_House02_ruins_F",
		"Land_TTowerSmall_2_F",
		"Land_Chapel_02_yellow_ruins_F",
		"Land_Radar_01_antenna_F",
		"Land_FeedStorage_01_F",
		"Land_House_1W04_ruins_F",
		"Land_Smokestack_01_factory_F",
		"Land_HouseRuin_Small_01_half_F",
		"Land_CoalPlant_01_Conveyor_F",
		"Land_Cross_01_small_F",
		"Land_GuardTower_02_F",
		"Land_Church_04_small_red_damaged_F",
		"Land_Slum_House01_ruins_F",
		"Land_HighVoltageEnd_F",
		"Land_WaterTower_02_F",
		"Land_Shed_05_ruins_F",
		"Land_Cowshed_01_A_F",
		"Land_Cowshed_01_C_F",
		"Land_Shed_Ind_old_ruins_F",
		"Land_Smokestack_03_F",
		"Land_Smokestack_02_F",
		"Land_Radar_01_cooler_F",
		"Land_Substation_01_F",
		"Land_Radar_01_airshaft_F",
		"Land_MobileRadar_01_generator_F",
		"Land_HouseRuin_Big_02_half_F",
		"Land_CoalPlant_01_LoadingHouse_F",
		"Land_DeerStand_01_F",
		"Land_ruin_01",
		"Land_Church_02a",
		"Land_Loudspeakers_F",
		"Land_A_FuelStation_Shed",
		"Land_fortified_nest_small",
		"Land_CncBlock_D",
		"clone_empty_static_F",
		"Land_Psi_bouda",
		"Land_Slums01_8m",
		"Land_Razorwire_F",
		"Land_Ind_Shed_01_end",
		"Land_TentA_F",
		"Land_Wall_CGry_5_D",
		"Land_ruin_wall",
		"Land_ruin_rubble",
		"Land_PaperBox_closed_F",
		"Land_Tyres_F",
		"Land_Ind_BoardsPack2",
		"Land_JunkPile_F",
		"Land_CratesShabby_F",
		"Land_PowerPoleWooden_L_F",
		"Land_seno_balik",
		"CinderFloor_EPOCH",
		"Land_Shed_W02_EP1",
		"clone_female_static_F",
		"clone_female_static_F",
		"CinderWall_EPOCH",
		"CinderWallGarage_EPOCH",
		"WoodFloor_EPOCH",
		"Land_Zed_dira_civil",
		"Land_Helfenburk_zed",
		"Land_PowLines_ConcL",
		"Land_Shed_M01_EP1",
		"Land_Shed_W03",
		"Land_Helfenburk_brana",
		"Land_Vysilac_chodba",
		"Land_Com_tower_ep1",
		"Land_Fuelstation_army",
		"Land_Ind_BoardsPack1",
		"Land_OrlHot",
		"Land_Dumruina_mini",
		"TP_Booth_c_EPOCH",
		"Land_popelnice",
		"Land_Ind_Timbers",
		"Epoch_LootHolder",
		"Land_A_Crane_02b",
		"paintshop",
		"FirePlace_02_EPOCH",
		"clone_male_static_F",
		"Land_Atm_01_F",
		"Land_TTowerSmall_1_F",
		"Land_vodni_vez",
		"Land_Kontejner",
		"Land_Bench_04_F",
		"Land_Sara_domek_zluty_bez",
		"Land_Helfenburk_cimburi",
		"CinderWallHalf_EPOCH",
		"Land_A_statue02",
		"CinderWall_window_EPOCH",
		"Debug_static_F",
		"Land_HouseV2_04",
		"Goldenseal_EPOCH",
		"Land_Vysilac_vez"	
	];
	_skipstrings = [
		"land_powerwire",
		"land_containerline",
		"land_telephoneline",
		"land_power_pole",
		"land_netfence",
		"land_woodenwall",
		"land_brickwall",
		"land_grave",
		"sign",
		"powerline",
		"stairs",
		"protection",
		"invisible",
		"concrete",
		"light",
		"lamp",
		"runway",
		"pier",
		"pipe",
		"cargo",
		"bridge",
		"boat",
		"castle",
		"mirror",
		"gate",
		"wreck",
		"powerlines",
		"tank",
		"plot",
		"garbage",
		"wired",
		"barrier",
		"bagfence",
		"luggage",
		"helipad",
		"pump"
	];
	LootMarkersPositions = [];
	LootMarkers = [];
	if (isnil 'LootArray') then {LootArray = []};
	_allbuildingtypes = [];
	_allmapbuildings = nearestobjects [player,['building'],40000];
	_masterConfig = (missionConfigFile >> "CfgBuildingLootPos");
	_c = 1;
	{
		_building = _x;
		if !(typeof _building in _Skipbuildings) then {
			if !(typeof _building in _allbuildingtypes) then {
				if ({typeof _building == (_x select 0)} count LootArray == 0) then {
					_config = _masterConfig >> (typeOf _building);
					if !(isClass(_config)) then {
						_skip = false;
						{
							if (tolower (typeOf _building) find _x > -1) exitwith {
								_skip = true;
							};
						} foreach _skipstrings;
						if !(_skip) then {
							_allbuildingtypes pushback (typeof _building);
							_marker = createMarker [typeof _building, (getpos _building)];
							_marker setmarkertype "mil_dot";
							_marker setMarkerColor 'ColorRed';
							_marker setMarkerText (typeof _building);
							LootMarkersPositions pushback (getpos _building);
							LootMarkers pushback (typeof _building);
							_c = _c+1;
						};
					};
				};
			};
		};
	} foreach _allmapbuildings;
	publicvariable "LootMarkersPositions";
	publicvariable "LootMarkers";
};


Itemarray = ["toilet_epoch","Shelf_EPOCH","Fridge_EPOCH","Bunk_EPOCH","Couch_EPOCH","wardrobe_epoch","cooker_epoch","ChairRed_EPOCH","Filing_epoch","Pelican_EPOCH","Table_EPOCH","Locker_EPOCH","ToolRack_EPOCH","Shoebox_EPOCH","Tarp_EPOCH","Freezer_EPOCH","Cabinet_EPOCH","KitchenSink_epoch"];
ItemArrayCount = count Itemarray;
SkippedBuildings = [];
Item = objNull;
Building = ObjNull;
SelectedItem = 0;
if (isnil 'LootArray') then {LootArray = []};
player allowdamage false;

(findDisplay 12 displayCtrl 51) ctrlAddEventHandler ['MouseButtonDown',{
	params ["_displayorcontrol", "_button", "_xPos", "_yPos", "_shift", "_ctrl", "_alt"];
	if (_ctrl) then {
		params ["","",""];
		_pos = (_displayorcontrol posScreenToWorld [_xPos, _yPos]);
		vehicle player setPosATL _pos;
	};
}];
(findDisplay 12 displayCtrl 51) ctrlAddEventHandler['Draw',{
	params ["_control"];
	_veh = vehicle player;
	_type = typeOf _veh;
	_icon = getText(configFile >> 'CfgVehicles' >> _type >> 'icon');
	_clr = [0,0,1,1];
	_txt = (name player);
	_control drawIcon [
		_icon,
		_clr,
		getPosASL _veh,
		((1 - ctrlMapScale _control) max .2) * 28,
		((1 - ctrlMapScale _control) max .2) * 28,
		getdir _veh,
		_txt
	];
}];
(findDisplay 46) displayAddEventHandler ["KeyDown",
	{
		params ["_ctrl", "_dikCode", "_shift", "_ctrlKey", "_alt"];
		_handled = false;
		_stepspeed = if (_ctrlKey) then {0.15} else {0.05};
		_dirspeed = if (_ctrlKey) then {1.5} else {0.5};
		switch _dikCode do {
			case 0x1C: {
				if (cursorobject iskindof 'building') then {
					Building = cursorobject;
				}
				else {
					Building = nearestbuilding player;
				};
				if (isClass(missionConfigFile >> "CfgBuildingLootPos" >> (typeof cursorobject))) then {
					systemchat format ['WARNING !!! %1 is already in LootList!!!',typeof Building];
					hint format ['WARNING !!! %1 is already in LootList!!!',typeof Building];
					Building = ObjNull;
				}
				else {
					systemchat format ['Selected Building = %1',typeof Building];
					hint format ['Selected Building = %1',typeof Building];
				};
			};
			case 0x4B: {
				if (!isNull Item) then {
					_oldPos = getposasl Item;
					_newpos = (getposasl Item) getPos [_stepspeed,(getdir player)-90];
					_newpos set [2,_oldPos select 2];
					Item setposasl _newpos;
					_handled = true;
				};
			};
			case 0x4D: {
				if (!isNull Item) then {
					_oldPos = getposasl Item;
					_newpos = (getposasl Item) getPos [_stepspeed,(getdir player)+90];
					_newpos set [2,_oldPos select 2];
					Item setposasl _newpos;
					_handled = true;
				};
			};
			case 0x48: {
				if (!isNull Item) then {
					_oldPos = getposasl Item;
					_newpos = (getposasl Item) getPos [_stepspeed,(getdir player)];
					_newpos set [2,_oldPos select 2];
					Item setposasl _newpos;
					_handled = true;
				};
			};
			case 0x50: {
				if (!isNull Item) then {
					_oldPos = getposasl Item;
					_newpos = (getposasl Item) getPos [_stepspeed,(getdir player)+180];
					_newpos set [2,_oldPos select 2];
					Item setposasl _newpos;
					_handled = true;
				};
			};
			case 0xC7: {
				SelectedItem = ((SelectedItem + 1) min (ItemArrayCount-1)) max 0;
				if !(isNull Item) then {
					deletevehicle Item;
				};
				_pos = player modeltoworld [0,5,0];
				_selectedClass = Itemarray select SelectedItem;
				Item = createVehicle [_selectedClass, _pos, [], 0, "CAN_COLLIDE"];
				Item setvectorup [0,0,1];
				if (surfaceiswater _pos) then {
					Item setposasl _pos;
				};
			};
			case 0xCF: {
				SelectedItem = ((SelectedItem - 1) min (ItemArrayCount-1)) max 0;
				if !(isNull Item) then {
					deletevehicle Item;
				};
				_pos = player modeltoworld [0,5,0];
				_selectedClass = Itemarray select SelectedItem;
				Item = createVehicle [_selectedClass, _pos, [], 0, "CAN_COLLIDE"];
				Item setvectorup [0,0,1];
				if (surfaceiswater _pos) then {
					Item setposasl _pos;
				};
			};
			case 0xC9: {
				if (!isNull Item) then {
					_newpos = getposasl Item;
					_newpos set [2,((getposasl Item) select 2)+_stepspeed];
					Item setposasl _newpos;
					_handled = true;
				};
			};
			case 0xD1: {
			
				if (!isNull Item) then {
					_newpos = getposasl Item;
					_newpos set [2,((getposasl Item) select 2)-_stepspeed];
					Item setposasl _newpos;
					_handled = true;
				};
			};
			case 0x47: {
				if (!isNull Item) then {
					_dir = getdir Item;
					_newdir = _dir - _dirspeed;
					Item setdir _newdir;
					_handled = true;
				};
			};
			case 0x49: {
				if (!isNull Item) then {
					_dir = getdir Item;
					_newdir = _dir + _dirspeed;
					Item setdir _newdir;
					_handled = true;
				};
			};
			case 0x39: {
				if (!isNull Item && !isnull Building) then {
					if !(Building distance Item > 80) then {
						_c = 0;
						_found = false;
						{
							if (typeof Building == (_x select 0)) exitwith {_found = true;};
							_c = _c+1;
						} foreach Lootarray;
						if (_found) then {
						
							_Buildingarray = Lootarray select _c;
							_allitemsarray = _Buildingarray select 1;
							_d = 0;
							_found2 = false;
							{
								if (typeof Item == (_x select 0)) exitwith {_found2 = true};
								_d = _d+1;
							} foreach _allitemsarray;
							if (_found2) then {
								_Itemarray = _allitemsarray select _d;
								_Itemsposarray = _Itemarray select 1;
								_Itemsposarray pushback [Building worldToModel (getposatl Item),getdir Item - getdir Building];
							}
							else {
								_allitemsarray pushback [typeof Item,[[Building worldToModel (getposatl Item),getdir Item - getdir Building]]];
							};
						}
						else {
							Lootarray pushback [typeof Building, [[typeof Item,[[Building worldToModel (getposatl Item),getdir Item - getdir Building]]]]];
							_idx = LootMarkers find (typeof Building);
							if (_idx > -1) then {
								LootMarkers deleteat _idx;
								LootMarkersPositions deleteat _idx;
								publicvariable "LootMarkersPositions";
								publicvariable "LootMarkers";
							};
							deleteMarker (typeof Building);
						};
						systemchat format ['saved %1 position to %2',typeof Item, typeof Building];
						hint format ['saved %1 position to %2',typeof Item, typeof Building];
						{diag_log str (lootarray select _foreachindex)}foreach lootarray;
						publicvariable 'lootarray';
						Item = ObjNull;
					}
					else {
						systemchat format ['WARNING, the Item is to far away from the Building! - not safed!'];
						hint format ['WARNING, the Item is to far away from the Building! - not saved!'];
					};
					_handled = true;
				}
				else {
					if (isnull Building) exitwith {
						systemchat format ['Select a Building first!'];
						hint format ['Select a Building first!'];
					};
					if (isnull Item) exitwith {
						systemchat format ['Place a Loot-Item first!'];
						hint format ['Place a Loot-Item first!'];
					};
				};
			};
			case 1: {
				if (!isNull Item) then {
					deletevehicle Item;
					Item = ObjNull;
					_handled = true;
				};
			};
			case 0x57: {
				if (count LootMarkersPositions > 0) then {
					_idx = round (random ((count LootMarkersPositions)-1));
					player setpos (LootMarkersPositions select _idx);
					Building = (nearestObjects [player, [LootMarkers select _idx],200]) param [0,objnull];
					if !(isnull Building) then {
						systemchat format ['Selected Building = %1',typeof Building];
						hint format ['Selected Building = %1',typeof Building];
					}
					else {
						systemchat "Error - Building not found";
						hint "Error - Building not found";
					};
				}
				else {
					hint "No more positions found!";
				};			
			};
			case 0x43: {
				if (isnull Building) exitwith {
					hint "No Building selected to remove from List";
				};
				if (Building distance2D player > 20) exitwith {
				
					hint "Building too far away to remove from List";
				};
				_idx = LootMarkers find (typeof Building);
				if (_idx > -1) then {
					LootMarkers deleteat _idx;
					LootMarkersPositions deleteat _idx;
					publicvariable "LootMarkersPositions";
					publicvariable "LootMarkers";
				};
				deleteMarker (typeof Building);
				SkippedBuildings pushback (typeof Building);
				publicvariable "SkippedBuildings";
				Building = objnull;
				hint "Building removed from list without defining lootpositions";
			};
			case 0x06: {
				_plr = vehicle player;
				_dir = getdir _plr;
				_dist = 10;
				if (surfaceIsWater position _plr) then {
					_pos = getPosASL _plr;
					_pos = [(_pos select 0)+_dist*sin(_dir),(_pos select 1)+_dist*cos(_dir),(_pos select 2)];
					_plr setPosASL _pos;
				}
				else {
					_pos = getPosATL _plr;
					_pos = [(_pos select 0)+_dist*sin(_dir),(_pos select 1)+_dist*cos(_dir),(_pos select 2)];
					_plr setPosATL _pos;
				};
				player setdamage 0;
			};
			case 0x05: {
				player allowdamage false;
				_vel = velocity player;
				player setVelocity [(_vel select 0),(_vel select 1),8];
				player setdamage 0;
			};
		};	
		_handled
	}
];
