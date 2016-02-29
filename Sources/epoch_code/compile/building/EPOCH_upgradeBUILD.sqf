/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Base building upgrade code

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_code/compile/building/EPOCH_upgradeBUILD.sqf

    Example:
    [cursorTarget,_index] call EPOCH_upgradeBUILD;

    Parameter(s):
		_this select 0: OBJECT - Base building object
		_this select 1: NUMBER - index of array from (CfgBaseBuilding >> "upgradeBuilding")

	Returns:
	NOTHING
*/
private ["_buildingJammerRange","_buildingCountLimit","_nearestJammer","_ownedJammerExists","_buildingAllowed","_dt","_missingCount","_canUpgrade","_missingParts","_part","_req","_partCheck","_canUpgradePartCount","_removedPartCount","_return","_upgrade","_upgradeParts","_config","_upgrades","_targeter","_stability","_jammer"];
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



// check if another player has target
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
				_dt = ["<t size = '0.8' shadow = '0' color = '#99ffffff'>Upgrade Disallowed: Frequency Blocked</t>", 0, 1, 5, 2, 0, 1] spawn bis_fnc_dynamictext;
			};
		};
};
if !(_buildingAllowed)exitWith{ false };

if (_object isKindOf "Constructions_static_F") then {

	// take upgrade item from player here
	_config = 'CfgBaseBuilding' call EPOCH_returnConfig;

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
				_dt = ["<t size='0.8' shadow='0' color='#99ffffff'>Upgraded</t>", 0, 1, 5, 2, 0, 1] spawn bis_fnc_dynamictext;
			};
		} else {
			_dt = [format["<t size='0.8' shadow='0' color='#99ffffff'>%1</t>", _missingParts], 0, 1, 5, 2, 0, 1] spawn bis_fnc_dynamictext;
		};
	};
};
_return
