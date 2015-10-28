if !(isNil "EPOCH_maintainLockout") exitWith {_dt = ["<t size=""0.8"" shadow=""0"" color=""#99ffffff"">Already Maintaining a base.</t>", 0, 1, 5, 2, 0, 1] spawn bis_fnc_dynamictext;};
if (EPOCH_playerCrypto > 0) then {
  _config = "CfgEpochClient" call EPOCH_returnConfig;
  _buildingJammerRange = getNumber(_config >> "buildingJammerRange");
  if (_buildingJammerRange == 0) then { _buildingJammerRange = 75; };

  _maintainCount = {(damage _x) > 0} count nearestObjects[_this, ["Constructions_static_F","Constructions_foundation_F","Buildable_Storage","Constructions_lockedstatic_F"], _buildingJammerRange];
  if (_maintainCount > 0) then {

    if (EPOCH_playerCrypto < _maintainCount) then {
      _maintainCount = EPOCH_playerCrypto;
    };

    _rnd = format ["rmx_var_temp%1%2",floor random 100, ["A","B","C","D","E","F"] select random 5];
    [_this modelToWorld [0,0,0.2],20,"x\addons\a3_epoch_code\Data\UI\buttons\timer.paa", "Maintaining",60,_rnd] call epoch_gui3dWorldPos;

    EPOCH_maintainLockout = true;

    EPOCH_MAINTBUILD = [_this, player, _maintainCount, Epoch_personalToken];
    publicVariableServer "EPOCH_MAINTBUILD";

    [_rnd,_maintainCount] spawn {
      params ["_rnd","_maintainCount"];
      uiSleep _maintainCount;
      missionNamespace setVariable [_rnd,false];
      uiSleep 1;
      missionNamespace setVariable [_rnd,nil];
      EPOCH_maintainLockout = nil;
    };

    _dt = [format["<t size=""0.8"" shadow=""0"" color=""#99ffffff"">Cost %1 Krypto to maintain base.</t>", _maintainCount], 0, 1, 5, 2, 0, 1] spawn bis_fnc_dynamictext;
  } else {
    _dt = ["<t size=""0.8"" shadow=""0"" color=""#99ffffff"">Nothing needs maintained.</t>", 0, 1, 5, 2, 0, 1] spawn bis_fnc_dynamictext;
  };
} else {
  _dt = ["<t size=""0.8"" shadow=""0"" color=""#99ffffff"">You need Krypto to maintain a base.</t>", 0, 1, 5, 2, 0, 1] spawn bis_fnc_dynamictext;
};
