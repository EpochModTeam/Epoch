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
private ["_StorageClasses","_BuildingClasses","_CamCountLimit","_alljammer","_buildingAllowed","_buildingCountLeader","_buildingCountLimit","_buildingCountPerMember","_buildingJammerRange","_bypassJammer","_c","_cfgBaseBuilding","_config","_ghostClass","_isAllowed","_jammer","_jammerGLOnly","_jammerPerGroup","_limitNearby","_maxBuildingHeight","_membercount","_myPosATL","_nearestJammer","_obj","_objType","_objectscount","_ownedJammerExists","_range","_restricted","_restrictedArray","_restrictedLocations","_restrictedLocationsArray","_restrictedLocationsRange","_simulClass","_staticClass","_storageCountLeader","_storageCountLimit","_storageCountPerMember","_useGroupCountLimits","_useSplitCountLimits"];
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
_JammerConfig = (_config >> "CfgJammers");
_cfgBaseBuilding = 'CfgBaseBuilding' call EPOCH_returnConfig;
if(getNumber(_config >> "useGroupCountLimits") == 0)then{_useGroupCountLimits=false};
if(getNumber(_config >> "splitCountLimits") == 1)then{_useSplitCountLimits=true};
if(getNumber(_config >> "jammerGLOnly") == 0)then{_jammerGLOnly=false};

_StorageClasses = ["CfgEpochClient", "StorageClasses", ["Buildable_Storage","Buildable_Storage_SIM","Buildable_Storage_Ghost","Constructions_lockedstatic_F","Secure_Storage_Temp"]] call EPOCH_fnc_returnConfigEntryV2;
_BuildingClasses = ["CfgEpochClient", "BuildingClasses", ["Constructions_static_F","Constructions_foundation_F","Const_Ghost_EPOCH"]] call EPOCH_fnc_returnConfigEntryV2;
_maxBuildingHeight = ["CfgEpochClient", "maxBuildingHeight", 100] call EPOCH_fnc_returnConfigEntryV2;
_jammerPerGroup = ["CfgEpochClient", "jammerPerGroup", 1] call EPOCH_fnc_returnConfigEntryV2;

_JammerClasses = call EPOCH_JammerClasses;
_JammerGhosts = call EPOCH_JammerGhosts;
_JammerCheckClasses = _JammerClasses + _JammerGhosts;

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
_jammer = (nearestObjects[player, _JammerCheckClasses, call EPOCH_MaxJammerRange]) select {player distance _x < (getnumber (_JammerConfig >> (typeof _x) >> "buildingJammerRange"))};
if !(_jammer isEqualTo []) then {
	if (_objType in _JammerCheckClasses) then {
		{
			if (alive _x) exitWith{
				_buildingAllowed = false;
				["Building Disallowed: Existing Jammer Signal", 5] call Epoch_message;
			};
		} foreach _jammer;
	}
	else {
		{
			if (alive _x) exitWith{
				_nearestJammer = _x;
				_JammerConfig = (_JammerConfig >> (typeof _nearestJammer));
			};
		} foreach _jammer;
		if !(isNull _nearestJammer) then {
			if !((_nearestJammer getVariable["BUILD_OWNER", "-1"]) in[getPlayerUID player, Epoch_my_GroupUID]) exitwith {
				_buildingAllowed = false;
				["Building Disallowed: Frequency Blocked", 5] call Epoch_message;
			};
			_ownedJammerExists = true;
			_membercount = 0;
			Epoch_my_Group params [
				["_groupName",""],
				["_leaderName",""],
				["_groupSize",0],
				["_modArray",[]],
				["_memberArray",[]]
			];
			_membercount = count _modArray + count _memberArray;
			_buildingJammerRange = getnumber (_JammerConfig >> "buildingJammerRange");
			_storageCountLimit = (getnumber (_JammerConfig >> "storageCountLimit")) + ((getnumber (_JammerConfig >> "storageCountPerMember")) * _membercount);
			_buildingCountLimit = (getnumber (_JammerConfig >> "buildingCountLimit")) + ((getnumber (_JammerConfig >> "buildingCountPerMember")) * _membercount);
			_CamCountLimit = getnumber (_JammerConfig >> "maxCams");

			if (_useSplitCountLimits) then {
				if({_objType iskindof _x} count _StorageClasses > 0) then {
					if ((count (nearestObjects[_nearestJammer,_StorageClasses,_buildingJammerRange]-[_obj])) >= _storageCountLimit) exitwith {
						_buildingAllowed = false;
						[format["Building Disallowed: Max. %1 Storage Objects",_storageCountLimit],5] call Epoch_message
					};
				}
				else {
					if ((count (nearestObjects[_nearestJammer,_BuildingClasses,_buildingJammerRange]-[_obj])) >= _buildingCountLimit) exitwith {
						_buildingAllowed = false;
						[format["Building Disallowed: Max. %1 Constructions",_buildingCountLimit],5] call Epoch_message
					};
				};
			}
			else {
				if ((count (nearestObjects [_nearestJammer,(_StorageClasses + _BuildingClasses),_buildingJammerRange]-[_obj])) >= _buildingCountLimit) exitwith {
					_buildingAllowed = false;
					[format["Building Disallowed, Frequency Overloaded: Limit %1",_buildingCountLimit],5] call Epoch_message
				};
			};
			if !((getPosATL player) select 2 < _maxBuildingHeight) exitwith {
				_buildingAllowed = false;
				["Building Disallowed: Max building height reached",5] call Epoch_message;
			};
			if (_objType isequalto "BaseCam_EPOCH" && _buildingAllowed) then {
				if ((count (nearestObjects[_nearestJammer,["BaseCam_EPOCH","BaseCam_SIM_EPOCH","BaseCam_Ghost_EPOCH"],_buildingJammerRange]-[_obj])) >= _CamCountLimit) then {
					_buildingAllowed = false;
					[format["Building Disallowed: Max %1 Cams per Base!", _CamCountLimit], 5] call Epoch_message;
				};
			};
		};
	};
}
else {
	if (_objType in _JammerCheckClasses) then {
		if (!(EPOCH_my_groupUID isequalto "") && !((getplayeruid player) isequalto EPOCH_my_groupUID) && _jammerGLOnly) exitwith {
			_buildingAllowed = false;
			["The Group Leader must place the Jammer!", 5] call Epoch_message;
		};
		_c = 0;
		{
			if ((_x getVariable["BUILD_OWNER", "-1"]) in[getPlayerUID player, Epoch_my_GroupUID]) then {
				_c = _c+1;
			};
		} foreach (missionnamespace getvariable ["Epoch_Plotpoles",call {_allplots = [];{_allplots append (allmissionobjects _x)} foreach (call EPOCH_JammerClasses);_allplots}]);
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
		_objectscount = count (nearestObjects[player, [_staticClass, _simulClass], 100]-[_obj]);
		if (_objectscount >= _limitNearby) then{
			_buildingAllowed = false;
			[format["Building Disallowed: Limit %1", _limitNearby], 5] call Epoch_message;
		};
	};
};
if !(_buildingAllowed)exitWith{ false };

// require jammer check if not found as owner of jammer
if (getNumber(_config >> "buildingRequireJammer") == 1 && _bypassJammer == 0) then{
	if !(_objType in _JammerCheckClasses) then {
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
