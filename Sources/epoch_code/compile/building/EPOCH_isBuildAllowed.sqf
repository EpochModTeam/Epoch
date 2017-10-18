/*
	Author: Aaron Clark - EpochMod.com

    Contributors: Raimonds Virtoss

	Description:
	check if building is allowed

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/building/EPOCH_isBuildAllowed.sqf

    Example:
    _isAllowed = "" call EPOCH_isBuildAllowed;
	_isAllowed = _objType call EPOCH_isBuildAllowed;

    Parameter(s):
		_this select 0: OBJECT - Base building object

	Returns:
	BOOL
*/
//[[[cog import generate_private_arrays ]]]
private ["_alljammer","_buildingAllowed","_buildingCountLeader","_buildingCountLimit","_buildingCountPerMember","_buildingJammerRange","_bypassJammer","_c","_cfgBaseBuilding","_config","_ghostClass","_isAllowed","_jammer","_jammerGLOnly","_jammerPerGroup","_limitNearby","_maxBuildingHeight","_membercount","_minJammerDistance","_myPosATL","_nearestJammer","_obj","_objType","_objectscount","_ownedJammerExists","_range","_restricted","_restrictedArray","_restrictedLocations","_restrictedLocationsArray","_restrictedLocationsRange","_simulClass","_staticClass","_storageCountLeader","_storageCountLimit","_storageCountPerMember","_useGroupCountLimits","_useSplitCountLimits"];
//[[[end]]]

_buildingAllowed = true;
_ownedJammerExists = false;
_useSplitCountLimits = false;
_useGroupCountLimits = true;
_nearestJammer = objNull;
_jammerGLOnly = true;

// reject building if in vehicle
if (vehicle player != player)exitWith{["Building Disallowed: Inside Vehicle", 5] call Epoch_message; false };

// defaults
_config = 'CfgEpochClient' call EPOCH_returnConfig;
_cfgBaseBuilding = 'CfgBaseBuilding' call EPOCH_returnConfig;
_buildingJammerRange = getNumber(_config >> "buildingJammerRange");
_buildingCountLimit = getNumber(_config >> "buildingCountLimit");
_storageCountLimit = getNumber(_config >> "storageCountLimit");
_buildingCountLeader = getNumber(_config >> "buildingCountLeader");
_buildingCountPerMember = getNumber(_config >> "buildingCountPerMember");
_storageCountLeader = getNumber(_config >> "storageCountLeader");
_storageCountPerMember = getNumber(_config >> "storageCountPerMember");
_minJammerDistance = getNumber(_config >> "minJammerDistance");
_maxBuildingHeight = getNumber(_config >> "maxBuildingHeight");
_jammerPerGroup = getNumber(_config >> "jammerPerGroup");
if(getNumber(_config >> "useGroupCountLimits") == 0)then{_useGroupCountLimits=false};
if(getNumber(_config >> "splitCountLimits") == 1)then{_useSplitCountLimits=true};
if(getNumber(_config >> "jammerGLOnly") == 0)then{_jammerGLOnly=false};
if(_buildingJammerRange == 0)then{_buildingJammerRange = 75};
if(_buildingCountLimit == 0)then{_buildingCountLimit = 200};
if(_buildingCountLeader == 0)then{_buildingCountLeader = _buildingCountLimit};
if(_storageCountLeader == 0)then{_storageCountLeader = 100};
if(_minJammerDistance == 0)then{_minJammerDistance = _buildingJammerRange*3};
if(_maxBuildingHeight == 0)then{_maxBuildingHeight = 100};
if(_jammerPerGroup == 0)then{_jammerPerGroup = 2};

// input
params ["_objType"];
_obj = objNull;
if (_objType isEqualType objNull) then {
	_obj = _objType;
	_objType = typeOf _objType;
};

_staticClass = getText(_cfgBaseBuilding >> _objType >> "staticClass");
_simulClass = getText(_cfgBaseBuilding >> _objType >> "simulClass");
_ghostClass = getText(_cfgBaseBuilding >> _objType >> "GhostPreview");
_bypassJammer = getNumber(_cfgBaseBuilding >> _staticClass >> "bypassJammer");

// Jammer
_jammer = nearestObjects[player, ["PlotPole_EPOCH"], _minjammerdistance];
if !(_jammer isEqualTo []) then {
	if (_objType in ["PlotPole_EPOCH", "PlotPole_SIM_EPOCH"]) then {
		{
			if (alive _x) exitWith{
				_buildingAllowed = false;
				["Building Disallowed: Existing Jammer Signal", 5] call Epoch_message;
			};
		} foreach _jammer;
	}
	else {
		{
			if (alive _x && (_x distance player) <= _buildingJammerRange) exitWith{
				_nearestJammer = _x;
			};
		} foreach _jammer;
		if !(isNull _nearestJammer) then {
			if !((_nearestJammer getVariable["BUILD_OWNER", "-1"]) in[getPlayerUID player, Epoch_my_GroupUID]) exitwith {
				_buildingAllowed = false;
				["Building Disallowed: Frequency Blocked", 5] call Epoch_message;
			};
			_ownedJammerExists = true;
			if(_useGroupCountLimits)then{
				_membercount = 0;
                Epoch_my_Group params [
                    ["_groupName",""],
                    ["_leaderName",""],
                    ["_groupSize",0],
                    ["_modArray",[]],
                    ["_memberArray",[]]
                ];
				_membercount = count _modArray + count _memberArray;
				_storageCountLimit = _storageCountLeader + (_storageCountPerMember * _membercount);
				_buildingCountLimit = _buildingCountLeader + (_buildingCountPerMember * _membercount);
			};
			if (_useSplitCountLimits) then {
				if(_objType in ["WorkBench_EPOCH","StorageShelf_EPOCH","Tipi_EPOCH","TentA_EPOCH","TentDome_EPOCH","LockBox_EPOCH","Safe_EPOCH","StorageShelf_SIM_EPOCH","LockBox_SIM_EPOCH","Safe_SIM_EPOCH","Workbench_SIM_EPOCH","Tipi_SIM_EPOCH"]) then {
					if ((count (nearestObjects[_nearestJammer,["Buildable_Storage","Constructions_lockedstatic_F","LockBox_SIM_EPOCH","Safe_SIM_EPOCH","StorageShelf_SIM_EPOCH","WorkBench_SIM_EPOCH"],_buildingJammerRange]-[_obj])) >= _storageCountLimit) exitwith {
						_buildingAllowed = false;
						[format["Building Disallowed: Max. %1 Storage Objects",_storageCountLimit],5] call Epoch_message
					};
				}
				else {
					if ((count (nearestObjects[_nearestJammer,["Constructions_static_F","Constructions_foundation_F","Const_Ghost_EPOCH"],_buildingJammerRange]-[_obj])) >= _buildingCountLimit) exitwith {
						_buildingAllowed = false;
						[format["Building Disallowed: Max. %1 Constructions",_buildingCountLimit],5] call Epoch_message
					};
				};
			}
			else {
				if ((count (nearestObjects [_nearestJammer,["Buildable_Storage","Constructions_lockedstatic_F","LockBox_SIM_EPOCH","Safe_SIM_EPOCH","StorageShelf_SIM_EPOCH","WorkBench_SIM_EPOCH","Constructions_static_F","Constructions_foundation_F","Const_Ghost_EPOCH"],_buildingJammerRange]-[_obj])) >= _buildingCountLimit) exitwith {
					_buildingAllowed = false;
					[format["Building Disallowed, Frequency Overloaded: Limit %1",_buildingCountLimit],5] call Epoch_message
				};
			};
			if !((getPosATL player) select 2 < _maxBuildingHeight) exitwith {
				_buildingAllowed = false;
				["Building Disallowed: Max building height reached",5] call Epoch_message;
			};
		};
	};
}
else {
	if (_objType in ["PlotPole_EPOCH", "PlotPole_SIM_EPOCH"]) then {
		if (!(EPOCH_my_groupUID isequalto "") && !((getplayeruid player) isequalto EPOCH_my_groupUID) && _jammerGLOnly) exitwith {
			_buildingAllowed = false;
			["The Group Leader must place the Jammer!", 5] call Epoch_message;
		};
		// TODO: rework not ideal to use allmissionobjects
		_alljammer = allmissionobjects 'PlotPole_EPOCH';
		_c = 0;
		{
			if ((_x getVariable["BUILD_OWNER", "-1"]) in[getPlayerUID player, Epoch_my_GroupUID]) then {
				_c = _c+1;
			};
		} foreach _alljammer;
		if (_c >= _jammerPerGroup) then {
			_buildingAllowed = false;
			[format["Building Disallowed: Max %1 Jammer per Group!", _jammerPerGroup], 5] call Epoch_message;
		};
	};
};
if !(_buildingAllowed)exitWith{ false };

// Max object
if (!_ownedJammerExists) then{
	_limitNearby = getNumber(_cfgBaseBuilding >> _staticClass >> "limitNearby");

	if (_limitNearby > 0) then{
		// remove current target from objects
		_objectscount = count (nearestObjects[player, [_staticClass, _simulClass], _buildingJammerRange]-[_obj]);
		if (_objectscount >= _limitNearby) then{
			_buildingAllowed = false;
			[format["Building Disallowed: Limit %1", _limitNearby], 5] call Epoch_message;
		};
	};
};
if !(_buildingAllowed)exitWith{ false };

// require jammer check if not found as owner of jammer
if (getNumber(_config >> "buildingRequireJammer") == 1 && _bypassJammer == 0) then{
	if !(_objType in ["PlotPole_EPOCH", "PlotPole_SIM_EPOCH"]) then {
		_buildingAllowed = _ownedJammerExists;
		if !(_buildingAllowed) then {
			["Building Disallowed: Frequency Jammer Needed", 5] call Epoch_message;
		};
	};
};
if !(_buildingAllowed)exitWith{ false };

if (getNumber(_config >> "buildingNearbyMilitary") == 0) then{
	_range = getNumber(_config >> "buildingNearbyMilitaryRange");
	if (_range > 0) then {
		_restrictedArray = ["ProtectionZone_Invisible_F"];
		_restrictedArray append getArray(_config >> "buildingNearbyMilitaryClasses");
		_restricted = nearestObjects [player, _restrictedArray, _range];
	};
} else {
	_restricted = nearestObjects [player, ["ProtectionZone_Invisible_F"], 300];
};
if !(_restricted isEqualTo []) then {
	_buildingAllowed = false;
	["Building Disallowed: Area Blocked", 5] call Epoch_message;
};

_restrictedLocationsArray = getArray(_config >> "restrictedLocations");
_restrictedLocationsRange = getNumber(_config >> "restrictedLocationsRange");
if !(_restrictedLocationsArray isEqualTo []) then {
	_restrictedLocations = nearestLocations [player, _restrictedLocationsArray, _restrictedLocationsRange];
	if !(_restrictedLocations isEqualTo []) then {
		_buildingAllowed = false;
		["Building Disallowed: Area Blocked", 5] call Epoch_message;
	};
};

_myPosATL = getPosATL player;
{
	if ((_x select 0) distance _myPosATL < (_x select 1)) exitWith {
		_buildingAllowed = false;
		["Building Disallowed: Area Blocked", 5] call Epoch_message;
	};
} forEach(getArray(_config >> worldname >> "blockedArea"));

_buildingAllowed
