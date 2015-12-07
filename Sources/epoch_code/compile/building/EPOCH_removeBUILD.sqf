private["_buildingAllowed", "_jammer", "_restricted", "_restrictedLocations", "_myPosATL"];
_buildingAllowed = true;
_ownedJammerExists = false;
_nearestJammer = objNull;
_config = 'CfgEpochClient' call EPOCH_returnConfig;
_buildingJammerRange = getNumber(_config >> "buildingJammerRange");
_buildingCountLimit = getNumber(_config >> "buildingCountLimit");

// defaults
if (_buildingJammerRange == 0) then { _buildingJammerRange = 75; };
if (_buildingCountLimit == 0) then { _buildingCountLimit = 200; };

EPOCH_buildOption = 0;

params ["_object"];
_objType = typeOf _object;

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

if (_objType == "PlotPole_EPOCH") then {
	if ((_object getVariable["BUILD_OWNER", "-1"]) != getPlayerUID player) then{
		_buildingAllowed = false;
		_dt = ["<t size = '0.8' shadow = '0' color = '#99ffffff'>Remove Disallowed: Frequency Blocked</t>", 0, 1, 5, 2, 0, 1] spawn bis_fnc_dynamictext;
	};
} 
else {
	_jammer = nearestObjects[player, ["PlotPole_EPOCH"], _buildingJammerRange];
	if !(_jammer isEqualTo[]) then{
		{
			if (alive _x) exitWith{
				_nearestJammer = _x;
			};
		} foreach _jammer;

		if !(isNull _nearestJammer) then{
			if ((_nearestJammer getVariable["BUILD_OWNER", "-1"]) in[getPlayerUID player, Epoch_my_GroupUID]) then{
				_ownedJammerExists = true;
			}
			else {
				_buildingAllowed = false;
				_dt = ["<t size = '0.8' shadow = '0' color = '#99ffffff'>Remove Disallowed: Frequency Blocked</t>", 0, 1, 5, 2, 0, 1] spawn bis_fnc_dynamictext;
			};
		};
	};
};

if !(_buildingAllowed)exitWith{false};

_removeParts = getArray(('CfgBaseBuilding' call EPOCH_returnConfig) >> _objType >> "removeParts");
if !(_removeParts isEqualTo[]) then{
	EPOCH_REMBUILD = [_this, player, Epoch_personalToken];
	publicVariableServer "EPOCH_REMBUILD";
	_return = true;
	_dt = ["<t size='0.8' shadow='0' color='#99ffffff'>Removed</t>", 0, 1, 5, 2, 0, 1] spawn bis_fnc_dynamictext;
};
_return
