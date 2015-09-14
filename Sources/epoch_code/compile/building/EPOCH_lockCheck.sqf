private["_jammed", "_jammer"];
_config = "CfgEpochClient" call EPOCH_returnConfig;
_buildingJammerRange = getNumber(_config >> "buildingJammerRange");
if (_buildingJammerRange == 0) then { _buildingJammerRange = 75; };

_jammer = nearestObjects[player, ["PlotPole_EPOCH"], _buildingJammerRange];
_jammed = false;
if !(_jammer isEqualTo[]) then {
  {
    if (alive _x) then {
      _jammed = !((_x getVariable["BUILD_OWNER", "-1"]) in [getPlayerUID player, Epoch_my_GroupUID]);
    };
    if (_jammed) exitWith{};
  } forEach _jammer;
};
_jammed
