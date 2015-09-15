private ["_newArmor","_totalArmor","_totalArmorMax","_selectedClass","_selectedItem","_bar","_uniformArmor","_finalArmor","_vestArmor","_headgearArmor","_totalArmorUI","_bar_compare"];
disableSerialization;
if (!isNull findDisplay 602) then {

  _selectedClass = "";
  if !(EPOCH_InteractedItem isEqualTo []) then {
    _selectedClass = EPOCH_InteractedItem select 1;
  };

  _totalArmor = 0;
  _totalArmorMax = EPOCH_MAX_ARMOR select 3;

  _newArmor = 0;

  _selectedItem =  getnumber (configFile >> "CfgWeapons" >> _selectedClass >> "ItemInfo" >> "type");

  _bar = uiNameSpace getVariable "RscCustomProgressUniform";
  _uniformArmor = (uniform player) call EPOCH_uniformArmorCalc;
  _totalArmor = _totalArmor + _uniformArmor;
  _finalArmor = linearConversion [0,EPOCH_MAX_ARMOR select 0,_uniformArmor,0.01,1];
  _bar progressSetPosition _finalArmor;

  if (_selectedItem == 801) then {
    _newArmor = _newArmor + (_selectedClass call EPOCH_uniformArmorCalc);
  } else {
    _newArmor = _newArmor + _uniformArmor;
  };

  _bar = uiNameSpace getVariable "RscCustomProgressVest";
  _vestArmor = (vest player) call EPOCH_gearArmorCalc;
  _totalArmor = _totalArmor + _vestArmor;
  _finalArmor = linearConversion [0,EPOCH_MAX_ARMOR select 1,_vestArmor,0.01,1];
  _bar progressSetPosition _finalArmor;

  if (_selectedItem == 701) then {
    _newArmor = _newArmor + (_selectedClass call EPOCH_gearArmorCalc);
  } else {
    _newArmor = _newArmor + _vestArmor;
  };

  _bar = uiNameSpace getVariable "RscCustomProgressHeadgear";
  _headgearArmor = (headgear player) call EPOCH_gearArmorCalc;
  _totalArmor = _totalArmor + _headgearArmor;
  _finalArmor = linearConversion [0,EPOCH_MAX_ARMOR select 2,_headgearArmor,0.01,1];
  _bar progressSetPosition _finalArmor;

  if (_selectedItem == 605) then {
    _newArmor = _newArmor + (_selectedClass call EPOCH_gearArmorCalc);
  } else {
    _newArmor = _newArmor + _headgearArmor;
  };

  _totalArmorUI = uiNameSpace getVariable "RscCustomProgressTotal";
  _bar = _totalArmorUI select 0;
  _finalArmor = linearConversion [0,_totalArmorMax,_totalArmor,0.01,1];
  _bar progressSetPosition _finalArmor;

  _bar_compare = _totalArmorUI select 1;
  _finalArmor = linearConversion [0,_totalArmorMax,_newArmor,0.01,1];
  _bar_compare progressSetPosition _finalArmor;

};
