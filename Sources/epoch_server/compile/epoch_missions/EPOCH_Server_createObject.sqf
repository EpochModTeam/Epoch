/*
	Author: Andrew Gregory - EpochMod.com

    Contributors: Aaron Clark

	Description:
	Server side spawing of mission objects

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_missions/EPOCH_Server_createObject.sqf
*/
private ["_grp","_driver","_gunner","_commander","_crew","_missionVehList","_obj","_cfgPricing","_objClass","_vehicles","_backpacks","_weapons","_items","_magazines","_vehAllowed"];
params ["_player",["_token","",[""]],["_objArr",[]],["_pos",[]],["_wepHolder",objNull],["_clearCargo",true],["_objSpc","CAN_COLLIDE"],["_driverType",""],["_gunnerType",""],["_commanderType",""],["_crewType",""],["_doDamage",false]];

if !([_player,_token]call EPOCH_server_getPToken) exitWith {};
if (typeName _objArr != "ARRAY")then{_objArr = [_objArr];};
if (count _objArr < 1) exitWith {};

diag_log format["Epoch: Attempt Create Object: %1 for %2",_objArr, name _player];

_cfgPricing = 'CfgPricing' call EPOCH_returnConfig;
_allowedVehicleListName = ["allowedVehiclesList","allowedVehiclesList_CUP"] select EPOCH_modCUPVehiclesEnabled;
_allowedVehiclesList = getArray(configFile >> "CfgEpoch" >> worldName >> _allowedVehicleListName);
//diag_log format ["DEBUG: Allowed Vehs: %1",_allowedVehiclesList];
_vehicles = [];
_backpacks = [];
_weapons = [];
_items = [];
_magazines = [];

if (_pos isEqualTo []) then {
	_pos = (getPosATL _player);
};

if(count _pos < 3)then{
_pos set [2,0];
};


//Sort Object Array
{
	
	//Weapons / Items
		if(isClass (configFile >> "CfgWeapons" >> _x))then{
			
			diag_log format["Epoch: Server_CreateObject: %1 Weapon / Item Found",_x];
			
			if("ItemCore" in ([configFile >> "CfgWeapons" >> _x, true] call BIS_fnc_returnParents))then{
			_items pushBack _x;
			}else{
			_weapons pushBack _x;
			};
			
		};
		
		//Magazines
		if(isClass (configFile >> "CfgMagazines" >> _x))then{
			
			diag_log format["Epoch: Server_CreateObject: %1 Magazine Found",_x];
			
			if("ItemCore" in ([configFile >> "CfgMagazines" >> _x, true] call BIS_fnc_returnParents))then{
			_items pushBack _x;
			}else{
			_magazines pushBack _x;
			};
			
		};
		
	//BackPacks / Vehicles
	if(isClass (configFile >> "CfgVehicles" >> _x))then{
		if("Bag_Base" in ([configFile >> "CfgVehicles" >> _x, true] call BIS_fnc_returnParents))then{
		_backpacks pushBack _x;
		}else{
			
			_vehAllowed = true;
			
			//If not destroying vehcile then check if allowed
			if!(_doDamage)then{
			_veh = _x;
			_vehAllowed = false;
				{
				if (_veh in _x)then{_vehAllowed = true;};
				} forEach _allowedVehiclesList;
			};
			
				
				if(_vehAllowed)then{
					//If not destroying (mission object) then find safe position
					if!(_doDamage)then{
						if(_x isKindOf "CAR" || _x isKindOf "AIR")then{
						_pos = [position _player, 0, 250, 6, 0, 1000, 0] call BIS_fnc_findSafePos;
						_pos = _pos findEmptyPosition [1,75,_x];
						};

						if(_x isKindOf "SHIP")then{
						_pos = [position _player, 0, EPOCH_dynamicVehicleArea, 10, 1, 1000, 0] call BIS_fnc_findSafePos;
						_pos = _pos findEmptyPosition [1,75,_x];
						};
					};
					
					_vehicles pushBack [_x,_pos];
				};
		};
	};

}forEach _objArr;

//Weapons, ammo, items, backpacks
if(count _weapons > 0 || count _items > 0 || count _magazines > 0 || count _backpacks > 0)then{

if(isNull _wepHolder)then{
_wepHolder = createVehicle["groundWeaponHolder", _pos, [], 0.0, "CAN_COLLIDE"];
};


	//Weapons
	if(count _weapons > 0)then{
		{
		diag_log format["Epoch: Server_CreateObject: %1 Weapon Spawn",_x];
		_wepHolder addWeaponCargoGlobal [_x,1];
		} forEach _weapons;
	};
	
	//Items
	if(count _items > 0)then{
		{
		diag_log format["Epoch: Server_CreateObject: %1 Item Spawn",_x];
		_wepHolder addItemCargoGlobal [_x,1];
		} forEach _items;
	};
	
	//Magazines
	if(count _magazines > 0)then{
		{
		diag_log format["Epoch: Server_CreateObject: %1 Magazine Spawn",_x];
		_wepHolder addMagazineCargoGlobal [_x,1];
		} forEach _magazines;
	};
	
	//Backpacks
	if(count _backpacks > 0)then{
		{
		diag_log format["Epoch: Server_CreateObject: %1 Backpack Spawn",_x];
		_wepHolder addBackPackCargoGlobal [_x,1];
		}forEach _backpacks;
	};

};

if(count _vehicles > 0)then{
	{
		diag_log format["Epoch: Server_CreateObject: %1 Vehicle Spawn",_x];
		//Need to create slot to createVehicle a persistent Epoch vehicle.
		//_obj = [_x select 0, _x select 1, random 360, true, (EPOCH_storedVehicleCount + 1), _player, "CAN_COLLIDE", !_clearCargo, false] call EPOCH_spawn_vehicle;
		
		_obj =  createVehicle[(_x select 0), (_x select 1), [], 15, "CAN_COLLIDE"];
		
		_obj allowdamage false;

			if (_driverType != "" || _gunnerType != "" || _commanderType != "") then {
				_grp = createGroup RESISTANCE;
			};

			if (_driverType != "") then {
				_driver = _grp createUnit[_driverType, position _obj, [], 1, "CAN_COLLIDE"];
				_driver assignAsDriver _obj;
				_driver moveInDriver _obj;
				//if (_doOwner) then {_driver setOwner (owner _player)};
			};

			if (_gunnerType != "") then {
				_gunner = _grp createUnit[_gunnerType, position _obj, [], 1, "CAN_COLLIDE"];
				_gunner assignAsGunner _obj;
				_gunner moveInGunner _obj;
				//if (_doOwner) then {_gunner setOwner (owner _player)};
			};

			if (_commanderType != "") then {
				_commander = _grp createUnit[_commanderType, position _obj, [], 1, "CAN_COLLIDE"];
				_commander assignAsCommander _obj;
				_commander moveInCommander _obj;
				//if (_doOwner) then {_commander setOwner (owner _player)};
			};

			if (_crewType != "") then {
				_crew = _grp createUnit[_crewType, position _obj, [], 1, "CAN_COLLIDE"];
				_crew assignAsCargo _obj;
				_crew moveInCargo _obj;
				//if (_doOwner) then {_crew setOwner (owner _player)};
			};
		_obj allowdamage true;
	
		if(_doDamage)then{_obj setDamage 1;};
	
	}forEach _vehicles;
	
	
};
