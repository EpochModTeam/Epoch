if !(_this in Epoch_invited_GroupUIDs) then {
  Epoch_invited_GroupUIDs pushBack _this;
  _dt = ["<t size = ""0.8"" shadow = ""0"" color = ""#99ffffff"">Group request received</t>", 0, 1, 5, 2, 0, 1] spawn bis_fnc_dynamictext;
};
