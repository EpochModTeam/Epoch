if (isNull _this) exitWith{ false };
_return = false;

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

params ["_object"];

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

if (_this isKindOf "Constructions_static_F") then {

	// take upgrade item from player here
	_config = 'CfgBaseBuilding' call EPOCH_returnConfig;
	_upgrade = getArray(_config >> (typeOf _this) >> "upgradeBuilding");
	if !(_upgrade isEqualTo []) then {

		_upgradeParts = _upgrade select 1;

		_canUpgrade = true;
		_canUpgradePartCount = 0;
		_missingParts = [];
		{
			_part = _x select 0;
			_req = _x select 1;
			_partCheck = {_x == _part} count (magazines player);
			//diag_log format["DEBUG: _partCheck %1", _partCheck];
			//diag_log format["DEBUG: _x %1", _x];
			if (_partCheck < _req) then {
				_missingCount = _req - _partCheck;

				//diag_log format["DEBUG: _missingCount %1", _missingCount];

				_canUpgrade = false;
				_missingParts pushBack format["Missing %1 %2", _missingCount, (_part call EPOCH_itemDisplayName)];
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
				EPOCH_UPBUILD = [_this,player,Epoch_personalToken];
				publicVariableServer "EPOCH_UPBUILD";
				_return = true;
				_dt = ["<t size='0.8' shadow='0' color='#99ffffff'>Upgraded</t>", 0, 1, 5, 2, 0, 1] spawn bis_fnc_dynamictext;
			};
		} else {
			_dt = [format["<t size='0.8' shadow='0' color='#99ffffff'>%1</t>", _missingParts], 0, 1, 5, 2, 0, 1] spawn bis_fnc_dynamictext;
		};
	};
};
_return
