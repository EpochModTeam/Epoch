/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Gear armor stats UI refresh code

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/inventory/EPOCH_refeshUI.sqf

    Example:
        0 call EPOCH_refeshUI;

    Parameter(s):
	   None

	Returns:
	NOTHING
*/
//[[[cog import generate_private_arrays ]]]
private ["_bar","_bar_compare","_finalArmor","_headgearArmor","_newArmor","_selectedClass","_selectedItem","_totalArmor","_totalArmorMax","_totalArmorUI","_uniformArmor","_vestArmor"];
//[[[end]]]
disableSerialization;
if (!isNull findDisplay 602) then {

  _selectedClass = "";
  if !(EPOCH_InteractedItem isEqualTo []) then {
    _selectedClass = EPOCH_InteractedItem select 1;
  };

  if (isNil "EPOCH_MAX_ARMOR") then {
      call EPOCH_maxArmorInit;
  };

  _totalArmor = 0;
  _totalArmorMax = EPOCH_MAX_ARMOR select 3;

  _newArmor = 0;

  _selectedItem =  getnumber (configFile >> "CfgWeapons" >> _selectedClass >> "ItemInfo" >> "type");

  _bar = uiNameSpace getVariable "RscCustomProgressUniform";
  _uniformArmor = (uniform player) call EPOCH_uniformArmorCalc;
  _totalArmor = _totalArmor + _uniformArmor;
  _finalArmor = linearConversion [0,EPOCH_MAX_ARMOR select 0,_uniformArmor,0.01,1,true];
  _bar progressSetPosition _finalArmor;

  if (_selectedItem == 801) then {
    _newArmor = _newArmor + (_selectedClass call EPOCH_uniformArmorCalc);
  } else {
    _newArmor = _newArmor + _uniformArmor;
  };

  _bar = uiNameSpace getVariable "RscCustomProgressVest";
  _vestArmor = (vest player) call EPOCH_gearArmorCalc;
  _totalArmor = _totalArmor + _vestArmor;
  _finalArmor = linearConversion [0,EPOCH_MAX_ARMOR select 1,_vestArmor,0.01,1,true];
  _bar progressSetPosition _finalArmor;

  if (_selectedItem == 701) then {
    _newArmor = _newArmor + (_selectedClass call EPOCH_gearArmorCalc);
  } else {
    _newArmor = _newArmor + _vestArmor;
  };

  _bar = uiNameSpace getVariable "RscCustomProgressHeadgear";
  _headgearArmor = (headgear player) call EPOCH_gearArmorCalc;
  _totalArmor = _totalArmor + _headgearArmor;
  _finalArmor = linearConversion [0,EPOCH_MAX_ARMOR select 2,_headgearArmor,0.01,1,true];
  _bar progressSetPosition _finalArmor;

  if (_selectedItem == 605) then {
    _newArmor = _newArmor + (_selectedClass call EPOCH_gearArmorCalc);
  } else {
    _newArmor = _newArmor + _headgearArmor;
  };

  _totalArmorUI = uiNameSpace getVariable "RscCustomProgressTotal";
  _bar = _totalArmorUI select 0;
  _finalArmor = linearConversion [0,_totalArmorMax,_totalArmor,0.01,1,true];
  _bar progressSetPosition _finalArmor;

  _bar_compare = _totalArmorUI select 1;
  _finalArmor = linearConversion [0,_totalArmorMax,_newArmor,0.01,1,true];
  _bar_compare progressSetPosition _finalArmor;
};
