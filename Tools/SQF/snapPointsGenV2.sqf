Hesco3_EPOCH = [
    [[0,0,-0.6],[0,0,-0.75]],
    [[1.6,0,-0.0307557],[1.8625,0,-0.0307557]],
    [[-1.6,0,-0.0307557],[-1.8625,0,-0.0307557]]
];
WoodWall1_EPOCH = [
    [[0,0,0.120775],[0,0,-0.190775]],
    [[2.46932,0,1.5],[2.76932,0,1.5]],
    [[-2.46932,0,1.5],[-2.76932,0,1.5]]
];
WoodWall2_EPOCH = [
    [[0,0,0.120775],[0,0,-0.190775]],
    [[2.46932,0,1.5],[2.76932,0,1.5]],
    [[-2.46932,0,1.5],[-2.76932,0,1.5]]
];
WoodWall3_EPOCH = [
    [[0,0,0.120775],[0,0,-0.190775]],
    [[2.46932,0,1.5],[2.76932,0,1.5]],
    [[-2.46932,0,1.5],[-2.76932,0,1.5]]
];
WoodWall4_EPOCH = [
    [[0,0,0.120775],[0,0,-0.190775]],
    [[2.46932,0,1.5],[2.76932,0,1.5]],
    [[-2.46932,0,1.5],[-2.76932,0,1.5]]
];
WoodLargeWall_EPOCH = [
    [[0,0,0.120775],[0,0,-0.190775]],
    [[2.46932,0,1.5],[2.76932,0,1.5]],
    [[-2.46932,0,1.5],[-2.76932,0,1.5]]
];
WoodFloor_Epoch = [
    [[2.5555,0,0.15],[2.8555,0,0.15]],
    [[0,-2.5555,0.15],[0,2.8555,0.15]],
    [[-2.5555,0,0.15],[-2.8555,0,0.15]],
    [[0,-2.5555,0.15],[0,-2.8555,0.15]],

    [[2.5555,0,0.15],[2.5555,0,-0.15]],
    [[-2.5555,0,0.15],[-2.5555,0,-0.15]],
    [[0,-2.5555,0.15],[0,-2.5555,-0.15]],
    [[0,2.5555,0.15],[0,2.5555,-0.15]]
];
MetalFloor_EPOCH = [
    [[2.5555,0,0.15],[2.8555,0,0.15]],
    [[0,-2.5555,0.15],[0,2.8555,0.15]],
    [[-2.5555,0,0.15],[-2.8555,0,0.15]],
    [[0,-2.5555,0.15],[0,-2.8555,0.15]],

    [[2.5555,0,0.15],[2.5555,0,-0.15]],
    [[-2.5555,0,0.15],[-2.5555,0,-0.15]],
    [[0,-2.5555,0.15],[0,-2.5555,-0.15]],
    [[0,2.5555,0.15],[0,2.5555,-0.15]]
];
WoodLargeWallCor_EPOCH = [
    [[0,0,0.120775],[0,0,-0.190775]],
    [[2.46932,0,1.5],[2.76932,0,1.5]],
    [[-2.46932,0,1.5],[-2.76932,0,1.5]]
];
WoodLargeWallDoorway_EPOCH = [
    [[0,0,0.120775],[0,0,-0.190775]],
    [[2.46932,0,1.5],[2.76932,0,1.5]],
    [[-2.46932,0,1.5],[-2.76932,0,1.5]]
];
WoodLargeWallDoor_EPOCH = [
    [[0,0,0.120775],[0,0,-0.190775]],
    [[2.46932,0,1.5],[2.76932,0,1.5]],
    [[-2.46932,0,1.5],[-2.76932,0,1.5]]
];
WoodLargeWallDoorL_EPOCH = [
    [[0,0,0.120775],[0,0,-0.190775]],
    [[2.46932,0,1.5],[2.76932,0,1.5]],
    [[-2.46932,0,1.5],[-2.76932,0,1.5]]
];
WoodStairs_EPOCH = [
    [[0,0,0.05],[0,0,-0.20]]
];
WoodStairs2_EPOCH = [
    [[0,0,0.05],[0,0,-0.20]]
];
WoodTower_EPOCH = [
    [[0,0,0.05],[0,0,-0.20]]
];
WoodRamp_EPOCH = [
    [[0,0,0.05],[0,0,-0.20]]
];
CinderWallGarage_EPOCH = [
    [[0,0,0.120775],[0,0,-0.190775]],
    [[2.46932,0,1.5],[2.76932,0,1.5]],
    [[-2.46932,0,1.5],[-2.76932,0,1.5]]
];
CinderWall_EPOCH = [
    [[0,0,0.120775],[0,0,-0.190775]],
    [[2.46932,0,1.5],[2.76932,0,1.5]],
    [[-2.46932,0,1.5],[-2.76932,0,1.5]]
];
CinderWallHalf_EPOCH = [
    [[0,0,0.120775],[0,0,-0.190775]],
    [[2.46932,0,1.5],[2.76932,0,1.5]],
    [[-2.46932,0,1.5],[-2.76932,0,1.5]]
];


EPOCH_buildClasses = [
"Hesco3_EPOCH",
"WoodWall1_EPOCH",
"WoodWall2_EPOCH",
"WoodWall3_EPOCH",
"WoodWall4_EPOCH",

"MetalFloor_EPOCH",
"WoodFloor_EPOCH",

"WoodLargeWall_EPOCH",
"WoodLargeWallCor_EPOCH",
"WoodLargeWallDoorway_EPOCH",
"WoodLargeWallDoor_EPOCH",
"WoodLargeWallDoorL_EPOCH",

"WoodStairs_EPOCH",
"WoodStairs2_EPOCH",
"WoodTower_EPOCH",
"WoodRamp_EPOCH",

"CinderWallGarage_EPOCH",
"CinderWall_EPOCH",
"CinderWallHalf_EPOCH"
];

EPOCH_buildClassesCount = count EPOCH_buildClasses - 1;
Epoch_selectedBuildClasIndex = 0;
EPOCH_selectedBuildClass = EPOCH_buildClasses select 0;

EPOCH_objPOS = player modelToWorld[0, 5, 1];
if !(surfaceIsWater _currentPos) then {
    EPOCH_objPOS = ATLtoASL _currentPos;
};

{
    detach _x;
} forEach attachedObjects player;

EPOCH_currentBuildObj = EPOCH_selectedBuildClass createVehicle EPOCH_objPOS;
EPOCH_currentBuildObj setPosATL EPOCH_objPOS;
EPOCH_currentBuildObj attachTo[player];
EPOCH_selectedEditIndex = 0;

EPOCH_fnc_AGLToATL = {
    _pos = _this;
    if !(surfaceIsWater _pos) then {_pos = ASLToATL _pos};
    _pos
};

EPOCH_KeyDownFunctionhandler = {
    _dikCode = _this select 1;
    _shift = _this select 2;
    _ctrl = _this select 3;
    _alt = _this select 4;
    _handled = false;

    switch (_dikCode) do {

        case 0xC7 : {
            _index = missionNamespace getVariable ["EPOCH_selectedEditIndex",0];
            _index = _index + 1;
            missionNamespace setVariable ["EPOCH_selectedEditIndex",_index];
            hint str(_index);
            _handled = true;
        };
        case 0xCF : {

            _index = missionNamespace getVariable ["EPOCH_selectedEditIndex",0];
            _index = _index - 1;
            missionNamespace setVariable ["EPOCH_selectedEditIndex",_index];
            hint str(_index);
            _handled = true;
        };

        case 0xC8 : {
            hint "UP";
            _extents = (missionNamespace getVariable EPOCH_selectedBuildClass) ;
            _new = [];
            {
                if (_foreachindex == EPOCH_selectedEditIndex) then {
                    _extents1 = _x select 0;
                    _extents2 = _x select 1;
                    _new pushBack ([[_extents1 select 0, _extents1 select 1, (_extents1 select 2)-0.1],[_extents2 select 0, _extents2 select 1, (_extents2 select 2)+0.1]]);
                } else {
                    _new pushBack _x;
                };
            } forEach _extents;
            missionNamespace setVariable [EPOCH_selectedBuildClass,_new];
            _handled = true;
        };
        case 0xD0     : {
            hint "DOWN";
            _extents = (missionNamespace getVariable EPOCH_selectedBuildClass) ;
            _new = [];
            {
                if (_foreachindex == EPOCH_selectedEditIndex) then {
                    _extents1 = _x select 0;
                    _extents2 = _x select 1;
                    _new pushBack ([[_extents1 select 0, _extents1 select 1, (_extents1 select 2)+0.1],[_extents2 select 0, _extents2 select 1, (_extents2 select 2)-0.1]]);
                } else {
                    _new pushBack _x;
                };
            } forEach _extents;
            missionNamespace setVariable [EPOCH_selectedBuildClass,_new];
            _handled = true;
        };
        case 0xCB     : {
            hint "LEFT";
            _extents = (missionNamespace getVariable EPOCH_selectedBuildClass) ;
            _new = [];
            {
                if (_foreachindex == EPOCH_selectedEditIndex) then {
                    _extents1 = _x select 0;
                    _extents2 = _x select 1;

                    if (_ctrl) then {
                        _new pushBack [[_extents1 select 0, (_extents1 select 1)-0.1, _extents1 select 2],[_extents2 select 0, (_extents2 select 1)+0.1, _extents2 select 2]];
                    } else {
                        _new pushBack [[(_extents1 select 0)-0.1, _extents1 select 1, _extents1 select 2],[(_extents2 select 0)+0.1, _extents2 select 1, _extents2 select 2]];
                    };


                } else {
                    _new pushBack _x;
                };
            } forEach _extents;
            missionNamespace setVariable [EPOCH_selectedBuildClass,_new];

            _handled = true;
        };
        case 0xCD     : {
            hint "RIGHT";
            _extents = (missionNamespace getVariable EPOCH_selectedBuildClass) ;

            _new = [];
            {
                if (_foreachindex == EPOCH_selectedEditIndex) then {
                    _extents1 = _x select 0;
                    _extents2 = _x select 1;

                    if (_ctrl) then {
                        _new pushBack [[_extents1 select 0, (_extents1 select 1)+0.1, _extents1 select 2],[_extents2 select 0, (_extents2 select 1)-0.1, _extents2 select 2]];
                    } else {
                        _new pushBack [[(_extents1 select 0)+0.1, _extents1 select 1, _extents1 select 2],[(_extents2 select 0)-0.1, _extents2 select 1, _extents2 select 2]];
                    };


                } else {
                    _new pushBack _x;
                };
            } forEach _extents;
            missionNamespace setVariable [EPOCH_selectedBuildClass,_new];

            _handled = true;
        };
        case 0xC9 : {
            Epoch_selectedBuildClasIndex = ((Epoch_selectedBuildClasIndex + 1) min EPOCH_buildClassesCount) max 0;
            EPOCH_selectedBuildClass = EPOCH_buildClasses select Epoch_selectedBuildClasIndex;

            if !(isNull EPOCH_currentBuildObj) then {
                deleteVehicle EPOCH_currentBuildObj;
                EPOCH_currentBuildObj = EPOCH_selectedBuildClass createVehicle EPOCH_objPOS;
                EPOCH_currentBuildObj setPosATL EPOCH_objPOS;
                EPOCH_currentBuildObj attachTo[player];



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
                EPOCH_currentBuildObj = EPOCH_selectedBuildClass createVehicle EPOCH_objPOS;
                EPOCH_currentBuildObj setPosATL EPOCH_objPOS;
                EPOCH_currentBuildObj attachTo[player];


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

onEachFrame {

    _numberOfContacts = 0;
    _maxWidth = 0;
    _maxLength = 0;
    _maxHeight = 0;

    _getSettings = missionNamespace getVariable format["%1_MAX",(typeOf EPOCH_currentBuildObj)];
    if !(isNil "_getSettings") then {
        _maxWidth = _getSettings param [0,0];
        _maxLength = _getSettings param [1,0];
        _maxHeight = _getSettings param [2,0];

    } else {
        _bbr = boundingBoxReal EPOCH_currentBuildObj;
        _p1 = _bbr select 0;
        _p2 = _bbr select 1;
        _maxWidth = abs ((_p2 select 0) - (_p1 select 0)/2);
        _maxLength = abs ((_p2 select 1) - (_p1 select 1)/2);
        _maxHeight = abs ((_p2 select 2) - (_p1 select 2));
        missionNamespace setVariable [format["%1_MAX",(typeOf EPOCH_currentBuildObj)],[_maxWidth,_maxLength,_maxHeight]];
    };
    _color = [0,0,1,1];

    {
        _pos1 = EPOCH_currentBuildObj modelToWorld (_x select 0);
        _pos2 = EPOCH_currentBuildObj modelToWorld (_x select 1);
        drawLine3D [_pos1,_pos2,_color];
    } forEach[
        [[0,0,_maxHeight],[0,0,-_maxHeight]],
        [[_maxWidth,0,_maxHeight],[-_maxWidth,0,_maxHeight]],
        [[0,_maxLength,_maxHeight],[0,-_maxLength,_maxHeight]]
    ];

    _color = [0,1,0,1];
    {
        _pos1 = EPOCH_currentBuildObj modelToWorld (_x select 0);
        _pos2 = EPOCH_currentBuildObj modelToWorld (_x select 1);

        _ins = lineIntersectsSurfaces [AGLToASL _pos1, AGLToASL _pos2,player,EPOCH_currentBuildObj,true,1,"VIEW","FIRE"];
        if (count _ins == 0) then {
            drawIcon3D ["a3\weapons_f\data\clear_empty.paa", [1,1,1,1], _pos2, 1, 1, 45, "no", 1, 0.02, "TahomaB"];
        } else {
            drawIcon3D ["a3\weapons_f\data\clear_empty.paa", [1,1,1,1], ASLToATL (_ins select 0 select 0), 1, 1, 45, "yes", 1, 0.02, "TahomaB"];
        };

        drawLine3D [_pos1,_pos2,_color];
    } forEach (missionNamespace getVariable format["%1",(typeOf EPOCH_currentBuildObj)]);

};
