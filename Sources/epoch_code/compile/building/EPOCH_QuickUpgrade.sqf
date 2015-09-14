_target = param [0,objNull];
if (!isNull _target) then {

  _targetClass = typeOf _target;

  _config = 'CfgBaseBuilding' call EPOCH_returnConfig;

  _recipes = getArray(_config >> _targetClass >> "upgradeBuilding");
  if !(_recipes isEqualTo []) then {

    createDialog "QuickUpgrade";
    {
      _upgradeClass = _x select 0;
      _upgradeRecipe = _x select 1;
      _index = lbAdd[1500, getText(configfile >> "CfgVehicles" >> _upgradeClass >> "DisplayName")];
      lbSetData[1500, _index, _upgradeClass];
      lbSetValue[1500, _index, _forEachIndex];

      _toolTip = "";
      {
        _recipeClass = _x;
        _recipeQty = 1;
        if (typeName _recipeClass == "ARRAY") then {
          _recipeClass = _x select 0;
          _recipeQty = _x select 1;
        };
        _toolTip = _toolTip + format["%1 x %2, ",_recipeQty,getText(configfile >> "CfgMagazines" >> _recipeClass >> "DisplayName")];
      } forEach _upgradeRecipe;
      lbSetTooltip [1500, _index, _toolTip];

    } foreach _recipes;

  };

};
