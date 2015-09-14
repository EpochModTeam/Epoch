EPOCH_buildClasses = ["Land_Obstacle_Bridge_F",

"Land_Shoot_House_Wall_F",
"Land_Shoot_House_Wall_Stand_F",
"Land_Shoot_House_Wall_Crouch_F",
"Land_Shoot_House_Wall_Prone_F",
"Land_Shoot_House_Wall_Long_F",
"Land_Shoot_House_Wall_Long_Stand_F",
"Land_Shoot_House_Wall_Long_Crouch_F",
"Land_Shoot_House_Wall_Long_Prone_F",
"Land_Shoot_House_Corner_F",
"Land_Shoot_House_Corner_Stand_F",
"Land_Shoot_House_Corner_Crouch_F",
"Land_Shoot_House_Corner_Prone_F",
"Land_Shoot_House_Panels_F",
"Land_Shoot_House_Panels_Crouch_F",
"Land_Shoot_House_Panels_Prone_F",
"Land_Shoot_House_Panels_Vault_F",
"Land_Shoot_House_Panels_Window_F",
"Land_Shoot_House_Panels_Windows_F",
"Land_Shoot_House_Tunnel_F",
"Land_Shoot_House_Tunnel_Stand_F",
"Land_Shoot_House_Tunnel_Crouch_F",
"Land_Shoot_House_Tunnel_Prone_F",


"Land_Obstacle_RunAround_F","Land_Obstacle_Saddle_F","Land_RampConcrete_F","Land_RampConcreteHigh_F","Land_GH_Stairs_F","Land_Billboard_F","Land_HBarrier_1_F","Land_HBarrier_3_F","Land_HBarrier_5_F","Land_Razorwire_F","Land_HBarrierWall6_F","WoodFloor_EPOCH","WoodLargeWall_EPOCH","Land_BagFence_Long_F","Land_BagFence_Corner_F","Land_BagFence_End_F","Land_BagFence_Round_F","Land_BagFence_Short_F"];
EPOCH_buildClassesCount = count EPOCH_buildClasses - 1;
Epoch_selectedBuildClasIndex = 0;
EPOCH_selectedBuildClass = EPOCH_buildClasses select 0;

EPOCH_buildWorldspace = [[0,0,0],[0,0,0],[0,0,0]];
EPOCH_KeyDownFunctionhandler = {
  _dikCode = _this select 1;
  _shift = _this select 2;
  _ctrl = _this select 3;
  _alt = _this select 4;

  switch (_dikCode) do {
    case 0x39 : {
      _worldspace = EPOCH_buildWorldspace;
      _newObj = EPOCH_selectedBuildClass createVehicle (_worldspace select 0);
      _newObj setVectorDirAndUp [_worldspace select 1,_worldspace select 2];
      _newObj setposASL (_worldspace select 0);
      _handled = true;
    };
    case 0xC9 : {
        Epoch_selectedBuildClasIndex = ((Epoch_selectedBuildClasIndex + 1) min EPOCH_buildClassesCount) max 0;
        EPOCH_selectedBuildClass = EPOCH_buildClasses select Epoch_selectedBuildClasIndex;

        if !(isNull EPOCH_currentBuildObj) then {
          deleteVehicle EPOCH_currentBuildObj;
          EPOCH_currentBuildObj = EPOCH_selectedBuildClass createVehicle [0,0,0];
          EPOCH_currentBuildObj disableCollisionWith player;
          EPOCH_currentBuildObj setObjectTextureGlobal [0, "#(rgb,8,8,3)color(0,0,1,1)"];
        };

        hint EPOCH_selectedBuildClass;
        _handled = true;
    };
    case 0xD1 : {
        Epoch_selectedBuildClasIndex = ((Epoch_selectedBuildClasIndex - 1) min EPOCH_buildClassesCount) max 0;
        EPOCH_selectedBuildClass = EPOCH_buildClasses select Epoch_selectedBuildClasIndex;
        hint EPOCH_selectedBuildClass;

        if !(isNull EPOCH_currentBuildObj) then {
          deleteVehicle EPOCH_currentBuildObj;
          EPOCH_currentBuildObj = EPOCH_selectedBuildClass createVehicle [0,0,0];
          EPOCH_currentBuildObj disableCollisionWith player;
          EPOCH_currentBuildObj setObjectTextureGlobal [0, "#(rgb,8,8,3)color(0,0,1,1)"];
        };

        _handled = true;
    };
  };
  _handled
};


[] spawn {
    (findDisplay 46) displayRemoveAllEventHandlers "KeyDown";
    (findDisplay 46) displayAddEventHandler["KeyDown",{_this call EPOCH_KeyDownFunctionhandler}];
};

EPOCH_currentBuildObj = EPOCH_selectedBuildClass createVehicle [0,0,0];
EPOCH_currentBuildObj disableCollisionWith player;
EPOCH_currentBuildObj setObjectTextureGlobal [0, "#(rgb,8,8,3)color(0,0,1,1)"];

onEachFrame {
  _ins = lineIntersectsSurfaces [AGLToASL positionCameraToWorld [0,0,0],AGLToASL positionCameraToWorld [0,0,10],player,EPOCH_currentBuildObj];
  if (count _ins == 0) exitWith {EPOCH_currentBuildObj setPosASL [0,0,0]};

  _intersectObj = (_ins select 0 select 2);
  if (isNull _intersectObj) then {_intersectObj = player};
  EPOCH_currentBuildObj setVectorDirAndUp [vectordir _intersectObj,(_ins select 0 select 1)];
  EPOCH_currentBuildObj setPosASL (_ins select 0 select 0);
  EPOCH_buildWorldspace = [(_ins select 0 select 0),vectordir _intersectObj,(_ins select 0 select 1)];

  _currentPos = (_ins select 0 select 0);
  _numberOfContacts = 0;

  _currentDir = direction EPOCH_currentBuildObj;

  _bbr = boundingBoxReal EPOCH_currentBuildObj;
  _p1 = _bbr select 0;
  _p2 = _bbr select 1;
  _maxWidth = abs ((_p2 select 0) - (_p1 select 0)) / 2;
  _maxLength = abs ((_p2 select 1) - (_p1 select 1)) / 2;
  _maxHeight = abs ((_p2 select 2) - (_p1 select 2)) / 2;

  {
    _pos1 = EPOCH_currentBuildObj modelToWorld [0,0,_maxHeight];
    _pos2 = EPOCH_currentBuildObj modelToWorld _x;
    _ins = lineIntersectsSurfaces [AGLToASL _pos1,AGLToASL _pos2,player,EPOCH_currentBuildObj];
    _color = [0,0,1,1];

    if (count _ins == 0) then {


      _color = [0,0,1,1];
      drawIcon3D ["a3\modules_f\data\iconunlock_ca.paa", [1,1,1,1], _pos2, 1, 1, 45, "", 1, 0.05, "TahomaB"];


    } else {
      _numberOfContacts = _numberOfContacts + 1;
      drawIcon3D ["a3\modules_f\data\iconlock_ca.paa", [1,1,1,1], ASLToATL (_ins select 0 select 0), 1, 1, 45, "Snap", 1, 0.05, "TahomaB"];
      _color = [1,0,0,1];
    };

    drawLine3D [
        _pos1,
        _pos2,
        _color
    ];

  } forEach[[_maxWidth,0,_maxHeight], [0,_maxLength,_maxHeight], [-_maxWidth,0,_maxHeight], [0,-_maxLength,_maxHeight], [0,0,-_maxHeight]];
};
