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

EPOCH_snapExtents = [];

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




EPOCH_snapExtents = [];
_playerPos = player modelToWorld [0,5,5];
EPOCH_currentBuildObj = EPOCH_selectedBuildClass createVehicle _playerPos;
EPOCH_currentBuildObj setPosATL _playerPos;
EPOCH_currentBuildObj disableCollisionWith player;
_numberOfContacts = 0;
for "_i" from 0 to 10 do {
};
_pos1 = EPOCH_currentBuildObj modelToWorld [0,0,10];
_pos2 = EPOCH_currentBuildObj modelToWorld [0,0,0];
_ins = lineIntersectsSurfaces [AGLToASL _pos1,AGLToASL _pos2,player];
if (count _ins == 0) then {
} else {
  _pos3 = (_ins select 0 select 0);
  if !(surfaceIsWater _pos3) then {_pos3 = ASLtoATL _pos3};
  _offset = EPOCH_currentBuildObj worldToModelVisual _pos3;
  EPOCH_snapExtents pushBack _offset;
  _numberOfContacts = _numberOfContacts + 1;

  _fullHeight = _offset select 0;
  _halfHeight = _fullHeight/2;



  _pos1 = EPOCH_currentBuildObj modelToWorld [0,10,_halfHeight];
  _pos2 = EPOCH_currentBuildObj modelToWorld [0,0,_halfHeight];
  _ins = lineIntersectsSurfaces [AGLToASL _pos1,AGLToASL _pos2,player];
  if (count _ins == 0) then {
  } else {
    _pos3 = (_ins select 0 select 0);
    if !(surfaceIsWater _pos3) then {_pos3 = ASLtoATL _pos3};
    _offset = EPOCH_currentBuildObj worldToModelVisual _pos3;
    EPOCH_snapExtents pushBack _offset;
    _numberOfContacts = _numberOfContacts + 1;
  };

  _pos1 = EPOCH_currentBuildObj modelToWorld [0,-10,_halfHeight];
  _pos2 = EPOCH_currentBuildObj modelToWorld [0,0,_halfHeight];
  _ins = lineIntersectsSurfaces [AGLToASL _pos1,AGLToASL _pos2,player];
  if (count _ins == 0) then {
  } else {
    _pos3 = (_ins select 0 select 0);
    if !(surfaceIsWater _pos3) then {_pos3 = ASLtoATL _pos3};
    _offset = EPOCH_currentBuildObj worldToModelVisual _pos3;
    EPOCH_snapExtents pushBack _offset;
    _numberOfContacts = _numberOfContacts + 1;
  };

  _pos1 = EPOCH_currentBuildObj modelToWorld [10,0,_halfHeight];
  _pos2 = EPOCH_currentBuildObj modelToWorld [0,0,_halfHeight];
  _ins = lineIntersectsSurfaces [AGLToASL _pos1,AGLToASL _pos2,player];
  if (count _ins == 0) then {
  } else {
    _pos3 = (_ins select 0 select 0);
    if !(surfaceIsWater _pos3) then {_pos3 = ASLtoATL _pos3};
    _offset = EPOCH_currentBuildObj worldToModelVisual _pos3;
    EPOCH_snapExtents pushBack _offset;
    _numberOfContacts = _numberOfContacts + 1;
  };

  _pos1 = EPOCH_currentBuildObj modelToWorld [-10,0,_halfHeight];
  _pos2 = EPOCH_currentBuildObj modelToWorld [0,0,_halfHeight];
  _ins = lineIntersectsSurfaces [AGLToASL _pos1,AGLToASL _pos2,player];
  if (count _ins == 0) then {
  } else {
    _pos3 = (_ins select 0 select 0);
    if !(surfaceIsWater _pos3) then {_pos3 = ASLtoATL _pos3};
    _offset = EPOCH_currentBuildObj worldToModelVisual _pos3;
    EPOCH_snapExtents pushBack _offset;
    _numberOfContacts = _numberOfContacts + 1;
  };


  _pos1 = EPOCH_currentBuildObj modelToWorld [0,0,-4.5];
  _pos2 = EPOCH_currentBuildObj modelToWorld [0,0,0];
  _ins = lineIntersectsSurfaces [AGLToASL _pos1,AGLToASL _pos2,player];
  if (count _ins == 0) then {
  } else {
    _pos3 = (_ins select 0 select 0);
    if !(surfaceIsWater _pos3) then {_pos3 = ASLtoATL _pos3};
    _offset = EPOCH_currentBuildObj worldToModelVisual _pos3;
    EPOCH_snapExtents pushBack _offset;
    _numberOfContacts = _numberOfContacts + 1;
  };

};
onEachFrame {
  {
    drawIcon3D ["a3\modules_f\data\iconlock_ca.paa", [1,1,1,1], EPOCH_currentBuildObj modelToWorld _x, 1, 1, 45, "Snap", 1, 0.05, "TahomaB"];
  } forEach EPOCH_snapExtents;
};
