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
private ["_buildingAllowed","_buildingCountLimit","_buildingJammerRange","_canUpgrade","_canUpgradePartCount","_config","_config2","_countdoors","_countgates","_doors","_gates","_jammer","_maxdoors","_maxgates","_missingCount","_missingParts","_nearestJammer","_ownedJammerExists","_part","_partCheck","_removedPartCount","_req","_return","_stability","_targeter","_upgrade","_upgradeParts","_upgrades","_upgradeto"];
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
_config = 'CfgEpochClient' call EPOCH_returnConfig;
_buildingJammerRange = getNumber(_config >> "buildingJammerRange");
_buildingCountLimit = getNumber(_config >> "buildingCountLimit");

// defaults
if (_buildingJammerRange == 0) then { _buildingJammerRange = 75; };
if (_buildingCountLimit == 0) then { _buildingCountLimit = 200; };

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

_jammer = nearestObjects[player, ["PlotPole_EPOCH"], _buildingJammerRange];

if !(_jammer isEqualTo[]) then {
		{
			if (alive _x) exitWith{
				_nearestJammer = _x;
			};
		} foreach _jammer;

		if !(isNull _nearestJammer) then {
			if ((_nearestJammer getVariable["BUILD_OWNER", "-1"]) in[getPlayerUID player, Epoch_my_GroupUID]) then {
				_ownedJammerExists = true;
			}
			else {
				_buildingAllowed = false;
				["Upgrade Disallowed: Frequency Blocked", 5] call Epoch_message;
			};
		};
};
if !(_buildingAllowed)exitWith{ false };

if (_object isKindOf "Constructions_static_F") then {

	// take upgrade item from player here
	_config = 'CfgBaseBuilding' call EPOCH_returnConfig;
	_config2 = 'CfgEpochClient' call EPOCH_returnConfig;
	_buildingJammerRange = getNumber(_config2 >> "buildingJammerRange");
	_maxdoors = getNumber(_config2 >> "maxdoors");
	_maxgates = getNumber(_config2 >> "maxgates");
	if (_buildingJammerRange == 0) then {_buildingJammerRange = 150};
	if (_maxdoors == 0) then {_maxdoors = 12};
	if (_maxgates == 0) then {_maxgates = 10};

	_upgrades = getArray(_config >> (typeOf _object) >> "upgradeBuilding");
	if !(_upgrades isEqualTo []) then {

    // get selected upgrade
    _upgrade = _upgrades param [Epoch_upgradeIndex,[]];

		_upgradeParts = _upgrade select 1;

		_canUpgrade = true;
		_canUpgradePartCount = 0;
		_missingParts = "";
		{
			_part = _x select 0;
			_req = _x select 1;
			_partCheck = {_x == _part} count (magazines player);

			if (_partCheck < _req) then {
				_missingCount = _req - _partCheck;

				_canUpgrade = false;
				_missingParts = _missingParts + format["Missing %1 %2, ", _missingCount, (_part call EPOCH_itemDisplayName)];
			};
			_canUpgradePartCount = _canUpgradePartCount + _req;
		} forEach _upgradeParts;

		_doors = ["WoodLargeWallDoorL_EPOCH","WoodWall4_EPOCH","CinderWallDoorwHatch_EPOCH"];
		_gates = ["CinderWallGarage_EPOCH"];
		if (_canUpgrade) then {
			_upgradeto = _upgrade select 0;
			if (_upgradeto in _doors) then {
				_countdoors = count (nearestobjects [_nearestJammer,_doors,_buildingJammerRange]);
				if (_countdoors >= _maxdoors) then {
					_canUpgrade = false;
					_missingParts = _missingParts + format["Can not upgrade to locked Door! Max %1 allowed per Base!", _maxdoors];
				};
			};
			if (_upgradeto in _gates) then {
				_countgates = count (nearestobjects [_nearestJammer,_gates,_buildingJammerRange]);
				if (_countgates >= _maxgates) then {
					_canUpgrade = false;
					_missingParts = _missingParts + format["Can not upgrade to Gate! Max %1 allowed per Base!", _maxgates];
				};
			};
		};

		_removedPartCount = 0;
		if (_canUpgrade) then {
			{
				for "_i" from 1 to (_x select 1) do {
					if ((_x select 0) in (magazines player)) then {
						player removeMagazine (_x select 0);
						_removedPartCount = _removedPartCount + 1;
					};
				};
			} forEach _upgradeParts;

			if (_canUpgradePartCount == _removedPartCount) then {
				// send to server for upgrade
				[_object,player,Epoch_upgradeIndex,Epoch_personalToken] remoteExec ["EPOCH_server_upgradeBUILD",2];
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
