/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Base building object lock check code

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/building/EPOCH_lockCheck.sqf

    Example:
    call EPOCH_lockCheck

    Parameter(s):
		NONE

	Returns:
	BOOL
*/
//[[[cog import generate_private_arrays ]]]
private ["_buildingJammerRange","_config","_jammed","_jammer"];
//[[[end]]]

_config = "CfgEpochClient" call EPOCH_returnConfig;
_buildingJammerRange = getNumber(_config >> "buildingJammerRange");
if (_buildingJammerRange == 0) then { _buildingJammerRange = 75; };

_jammer = nearestObjects[cameraon, ["PlotPole_EPOCH"], _buildingJammerRange];
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
