/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Splits a position into two arrays: Whole number array and decimal array.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_traders/EPOCH_server_spawnTraders.sqf
*/
//[[[cog import generate_private_arrays ]]]
private [	"_serverSettingsConfig","_acceptableBlds","_agent","_aiClass","_aiTables","_buildingHome","_buildingWork","_buildings","_checkBuilding","_config","_endTime","_home",
			"_homes","_markers","_objHiveKey","_pos","_position","_randomAIUniform","_return","_schedule","_slot","_spawnCount","_startTime","_traderHomes","_usedBuildings","_work",
			"_WinterDeco","_HelloweenDeco","_TraderDeco","_TraderMinDistance","_traderblockblds","_Traderblocks"
];
//[[[end]]]
_serverSettingsConfig = configFile >> "CfgEpochServer";
_TraderGodMode = [_serverSettingsConfig, "TraderGodMode", false] call EPOCH_fnc_returnConfigEntry;
_spawnCount = count EPOCH_TraderSlots;
_config = (configFile >> "CfgEpoch" >> worldName);
if !(isclass _config) then {
	_config = (configFile >> "CfgEpoch" >> "Default");
};
_aiTables = getArray(_config >> "traderUniforms");
_acceptableBlds = getArray(_config >> "traderBlds");
_TraderMinDistance = getnumber(_config >> "TraderMinDistance");
if (_TraderMinDistance isEqualto 0) then {
	_TraderMinDistance = worldsize / 12;
};
_traderblockblds = getArray(_config >> "traderblockblds");
if (_traderblockblds isEqualto []) then {
	_traderblockblds = ["pier","bridge","fireescape","medevac_house","pillboxbunker","containerine"];
};
_traderHomes = getArray(_config >> "traderHomes");
_TraderDeco = [_serverSettingsConfig, "TraderDeco", true] call EPOCH_fnc_returnConfigEntry;

_WinterDeco = (Epoch_ServerRealtime select 1) == 12 && (Epoch_ServerRealtime select 2) > 20 && _TraderDeco;
_HelloweenDeco = (((Epoch_ServerRealtime select 1) == 10 && (Epoch_ServerRealtime select 2) >= 24) || ((Epoch_ServerRealtime select 1) == 11 && (Epoch_ServerRealtime select 2) <= 3)) && _TraderDeco;

_usedBuildings = [];
_checkBuilding = {
	private ["_return"];
	params ["_building","_aiClass"];
	_return = !(_building in _usedBuildings);
	if !(_return) exitWith {_return};
	_return = !((_building buildingPos -1) isEqualTo []);
	if !(_return) exitWith {_return};
	_return = (_building nearEntities [_aiClass, 50]) isEqualTo [];
	if !(_return) exitWith {_return};
	_return = ({(tolower (typeOf _building) find _x) > -1} count _traderblockblds) < 1;
	_return
};
_Traderblocks = [];
{
	if (alive _x) then {
		_Traderblocks pushback [getpos _x, _TraderMinDistance];
	};
} foreach EPOCH_Traders;

for "_i" from 1 to _spawnCount do {
	_position = [epoch_centerMarkerPosition, 0, EPOCH_dynamicVehicleArea, 0, 0, 1000, 0, _Traderblocks] call BIS_fnc_findSafePos;
	if (count _position == 2) then {
		_randomAIUniform = selectRandom _aiTables;
		_aiClass = "C_man_1";
		_homes = (nearestObjects[_position, _traderHomes, 500]) select {[_x,_aiClass] call _checkBuilding};
		if !(_homes isEqualTo []) then {
			_buildingHome = selectRandom _homes;
			_usedBuildings pushBack _buildingHome;
			_buildings = (nearestObjects[_buildingHome, _acceptableBlds, 500]) select {[_x,_aiClass] call _checkBuilding};
			if !(_buildings isEqualTo []) then {
				_buildingWork = selectRandom _buildings;
				_usedBuildings pushBack _buildingWork;
				_home = selectRandom (_buildingHome buildingPos -1);
				_work = selectRandom (_buildingWork buildingPos -1);
				if ((nearestobjects [_home,call EPOCH_JammerClasses, call EPOCH_MaxJammerRange]) isequalto [] && (nearestobjects [_work,call EPOCH_JammerClasses, call EPOCH_MaxJammerRange]) isequalto []) then {
					_startTime = floor(random 16);
					_endTime = _startTime + 8;
					_schedule = [_startTime, _endTime];
					_pos = _home;
					if (daytime > _startTime && daytime < _endTime) then {
						_pos = _work;
					};
					_agent = createAgent [_aiClass, _pos, [], 0, "CAN_COLLIDE"];
					addToRemainsCollector[_agent];
					_agent addUniform _randomAIUniform;
					if !(EPOCH_forceStaticTraders) then {
						[_agent, _home, [_work, _schedule]] execFSM "\epoch_server\system\Trader_brain.fsm";
					};
					if (_HelloweenDeco) then {
						removeHeadgear _agent;
						_agent addHeadgear (selectrandom ["thor_mask_epoch","iron_mask_epoch","wolf_mask_epoch","pkin_mask_epoch","clown_mask_epoch","hockey_mask_epoch","plague_mask_epoch","ghostface_mask_epoch","skull_mask_epoch","witch_mask_epoch"]);
					}
					else {
						if (_WinterDeco) then {
							removeHeadgear _agent;
							_agent addHeadgear "santa_hat_epoch";
						};
					};
					_agent allowdamage !_TraderGodMode;
					if (surfaceiswater _pos) then {
						_agent setPosASL _pos;
					}
					else {
						_agent setPosATL _pos;
					};
					_slot = EPOCH_TraderSlots deleteAt 0;
					_agent setVariable["AI_SLOT", _slot, true];
					_agent setVariable["AI_ITEMS", EPOCH_starterTraderItems, true];
					_objHiveKey = format["%1:%2", (call EPOCH_fn_InstanceID), _slot];
					["AI_ITEMS", _objHiveKey, EPOCH_expiresAIdata, EPOCH_starterTraderItems] call EPOCH_fnc_server_hiveSETEX;
					_agent addEventHandler["Killed", { _this call EPOCH_server_traderKilled; }];
					["AI", _objHiveKey, [_aiClass, _home, [_work, _schedule]] ] call EPOCH_fnc_server_hiveSET;
					if (EPOCH_SHOW_TRADERS) then {
						_markers = ["NewDynamicTrader",_pos] call EPOCH_server_createGlobalMarkerSet;
						_agent setVariable["MARKER_REF", _markers];
					};
					EPOCH_Traders pushback _agent;
					_Traderblocks pushback [getpos _agent, _TraderMinDistance];
					Epoch_DynamicTraders pushback _agent;
				};
			};
		};
	};
};
true
