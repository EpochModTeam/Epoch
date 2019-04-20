/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Base building upgrade code

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/building/EPOCH_upgradeBUILD.sqf

    Example:
    [cursorTarget,_index] call EPOCH_upgradeBUILD;

    Parameter(s):
		_this select 0: OBJECT - Base building object
		_this select 1: NUMBER - index of array from (CfgBaseBuilding >> "upgradeBuilding")

	Returns:
	NOTHING
*/
//[[[cog import generate_private_arrays ]]]
private ["_buildingAllowed","_canUpgrade","_canUpgradePartCount","_config","_config2","_countdoors","_countgates","_doors","_gates","_jammer","_maxdoors","_maxgates","_missingCount","_missingParts","_nearestJammer","_ownedJammerExists","_part","_partCheck","_removedPartCount","_req","_return","_stability","_targeter","_upgrade","_upgradeParts","_upgrades","_upgradeto","_buildingJammerRange","_JammerConfig","_CryptoCosts"];
//[[[end]]]
params [
	["_object",objNull,[objNull]],
	["_index",-1,[0]]
];
_return = false;

if !(_index isEqualTo -1) then {Epoch_upgradeIndex = _index};
if (isNull _object) exitWith {false};

_buildingAllowed = true;
_ownedJammerExists = false;
_nearestJammer = objNull;

EPOCH_buildOption = 1;

_targeter = _object getVariable["last_targeter", objNull];
if (!isNull _targeter && _targeter != player && (player distance _object > _targeter distance _object)) exitWith{ EPOCH_stabilityTarget = objNull; false };

_stability = _object getVariable["stability", 100];
if (_stability > 0) exitWith{
	if (isNull EPOCH_stabilityTarget) then {
		_object setVariable["last_targeter", player, true];
		EPOCH_stabilityTarget = _object;
	};
};

_jammer = (nearestObjects[_object, call EPOCH_JammerClasses, call EPOCH_MaxJammerRange]) select {alive _x && {_object distance _x < (getnumber (getmissionconfig "CfgEpochClient" >> "CfgJammers" >> (typeof _x) >> "buildingJammerRange"))}};

if !(_jammer isEqualTo[]) then {
	_nearestJammer = _jammer select 0;
	if ((_nearestJammer getVariable["BUILD_OWNER", "-1"]) in[getPlayerUID player, Epoch_my_GroupUID]) then {
		_ownedJammerExists = true;
	}
	else {
		_buildingAllowed = false;
		["Upgrade Disallowed: Frequency Blocked", 5] call Epoch_message;
	};
};
if !(_buildingAllowed)exitWith{ false };

if (_object isKindOf "Constructions_static_F" || {(typeof _object) in (call EPOCH_JammerClasses)}) then {

	// take upgrade item from player here
	_config = 'CfgBaseBuilding' call EPOCH_returnConfig;
	_config2 = getmissionconfig "CfgEpochClient" >> "CfgJammers" >> (typeof _object);

	_upgrades = getArray(_config >> (typeOf _object) >> "upgradeBuilding");
	if !(_upgrades isEqualTo []) then {

    // get selected upgrade
    _upgrade = _upgrades param [Epoch_upgradeIndex,[]];

		_upgradeParts = _upgrade select 1;

		_canUpgrade = true;
		_canUpgradePartCount = 0;
		_missingParts = "Missing: ";
		_CryptoCosts = 0;
		{
			_part = _x select 0;
			_req = _x select 1;
			_partCheck = if (_part IsEqualTo "Krypto") then {
				_CryptoCosts = _CryptoCosts + _req;
				EPOCH_PlayerCrypto
			}
			else {
				{_x == _part} count (magazines player)
			};

			if (_partCheck < _req) then {
				_missingCount = _req - _partCheck;

				_canUpgrade = false;
				_missingParts = _missingParts + format["%1 %2, ", _missingCount, (_part call EPOCH_itemDisplayName)];
			};
			_canUpgradePartCount = _canUpgradePartCount + _req;
		} forEach _upgradeParts;

		if (_canUpgrade) then {
			_doors = ["CfgEpochClient", "DoorClasses", ["WoodLargeWallDoorL_EPOCH","WoodWall4_EPOCH","CinderWallDoorwHatch_EPOCH","WoodStairs3_EPOCH","JailWallDoor_EPOCH"]] call EPOCH_fnc_returnConfigEntryV2;
			_gates = ["CfgEpochClient", "GateClasses", ["CinderWallGarage_EPOCH","WoodWallGarage_EPOCH","MetalWallGarage_EPOCH"]] call EPOCH_fnc_returnConfigEntryV2;
			_JammerConfig = getmissionconfig "CfgEpochClient" >> "CfgJammers" >> (typeof _nearestJammer);
			_buildingJammerRange = getnumber (_JammerConfig >> "buildingJammerRange");
			_maxdoors = getnumber (_JammerConfig >> "maxdoors");
			_maxgates = getnumber (_JammerConfig >> "maxgates");
			if (_maxdoors == 0) then {_maxdoors = 12};
			if (_maxgates == 0) then {_maxgates = 10};

			_upgradeto = _upgrade select 0;
			if (_upgradeto in _doors) then {
				_countdoors = count ((nearestobjects [_nearestJammer,_doors,_buildingJammerRange]) - [_object]);
				if (_countdoors >= _maxdoors) then {
					_canUpgrade = false;
					_missingParts = format["Can not upgrade to locked Door / Stairs! Max %1 allowed per Base!", _maxdoors];
				};
			};
			if (_upgradeto in _gates) then {
				_countgates = count ((nearestobjects [_nearestJammer,_gates,_buildingJammerRange]) - [_object]);
				if (_countgates >= _maxgates) then {
					_canUpgrade = false;
					_missingParts = format["Can not upgrade to Gate! Max %1 allowed per Base!", _maxgates];
				};
			};
		};

		_removedPartCount = 0;
		if (_canUpgrade) then {
			{
				_x params ["_part","_req"];
				if !(_part IsEqualTo "Krypto") then {
					for "_i" from 1 to _req do {
						if (_part in (magazines player)) then {
							player removeMagazine _part;
							_removedPartCount = _removedPartCount + 1;
						};
					};
				}
				else {
					_removedPartCount = _removedPartCount + _req;
				};
			} forEach _upgradeParts;

			if (_canUpgradePartCount == _removedPartCount) then {
				// send to server for upgrade
				[_object,player,Epoch_upgradeIndex,Epoch_personalToken,_CryptoCosts] remoteExec ["EPOCH_server_upgradeBUILD",2];
				Epoch_upgradeIndex = nil;
				_return = true;
				["Upgraded", 5] call Epoch_message;
			};
		} else {
			[_missingParts, 5] call Epoch_message;
		};
	};
};
_return
