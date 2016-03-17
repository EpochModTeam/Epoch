if !(_this in Epoch_invited_GroupUIDs) then {
  Epoch_invited_GroupUIDs pushBack _this;
  ["<t size = ""1.6"" color = ""#99ffffff"">Group request received</t>", 5] call Epoch_dynamicText;
};
