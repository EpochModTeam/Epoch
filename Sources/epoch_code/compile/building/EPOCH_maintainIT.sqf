if (EPOCH_playerCrypto > 0) then {
  _config = "CfgEpochClient" call EPOCH_returnConfig;
  _buildingJammerRange = getNumber(_config >> "buildingJammerRange");
  if (_buildingJammerRange == 0) then { _buildingJammerRange = 75; };

  _maintainCount = {(damage _x) > 0} count nearestObjects[_this, ["Constructions_static_F", "Constructions_foundation_F"], _buildingJammerRange];
  if (EPOCH_playerCrypto < _maintainCount) then {
    _maintainCount = EPOCH_playerCrypto;
  };

  EPOCH_MAINTBUILD = [_this, player, _maintainCount, Epoch_personalToken];
  publicVariableServer "EPOCH_MAINTBUILD";

  _dt = [format["<t size=""0.8"" shadow=""0"" color=""#99ffffff"">Cost %1 Krypto to maintain base.</t>", _maintainCount], 0, 1, 5, 2, 0, 1] spawn bis_fnc_dynamictext;
} else {
  _dt = ["<t size=""0.8"" shadow=""0"" color=""#99ffffff"">You need Krypto to maintain a base.</t>", 0, 1, 5, 2, 0, 1] spawn bis_fnc_dynamictext;
};
