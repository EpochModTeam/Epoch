/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Base building maintain base code

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/building/EPOCH_maintainIT.sqf

    Example:
    cursorTarget call EPOCH_maintainIT;

    Parameter(s):
		_this: OBJECT - Base building object ("Constructions_static_F","Constructions_foundation_F","Buildable_Storage","Constructions_lockedstatic_F")

	Returns:
	NOTHING
*/
//[[[cog import generate_private_arrays ]]]
private ["_buildingJammerRange","_config","_maintainCount","_rnd"];
//[[[end]]]

if !(isNil "EPOCH_maintainLockout") exitWith {["Already Maintaining a base.", 5] call Epoch_message;};
if (EPOCH_playerCrypto > 0) then {
  _config = "CfgEpochClient" call EPOCH_returnConfig;
  _buildingJammerRange = getNumber(_config >> "buildingJammerRange");
  if (_buildingJammerRange == 0) then { _buildingJammerRange = 75; };

  _maintainCount = {(damage _x) > 0} count nearestObjects[_this, ["Constructions_static_F","Constructions_foundation_F","Buildable_Storage","Constructions_lockedstatic_F"], _buildingJammerRange];
  if (_maintainCount > 0) then {

    if (EPOCH_playerCrypto < _maintainCount) exitwith {
      [format ["You need %1 Krypto to maintain your base.",_maintainCount], 5] call Epoch_message;
    };

    _rnd = format ["rmx_var_temp%1%2",floor random 100, selectRandom ["A","B","C","D","E","F"]];
    [_this modelToWorld [0,0,0.2],20,"x\addons\a3_epoch_code\Data\UI\buttons\timer.paa", "Maintaining",60,_rnd] call epoch_gui3dWorldPos;

    EPOCH_maintainLockout = true;

    [_this, player, _maintainCount, Epoch_personalToken] remoteExec ["EPOCH_server_maintBUILD",2];

    [_rnd,_maintainCount] spawn {
      params ["_rnd","_maintainCount"];
      uiSleep _maintainCount;
      missionNamespace setVariable [_rnd,false];
      uiSleep 1;
      missionNamespace setVariable [_rnd,nil];
      EPOCH_maintainLockout = nil;
    };

    [format["Cost %1 Krypto to maintain base.", _maintainCount], 5] call Epoch_message;
  } else {
    ["Nothing needs Maintaining", 5] call Epoch_message;
  };
} else {
  ["You need Krypto to maintain a base.", 5] call Epoch_message;
};
