/*
 Made for A3 Epoch Mod 
 EpochMod.com
 by Aaron Clark - [VB]AWOL

 This work is licensed under a Creative Commons Attribution-ShareAlike 4.0 International License.
 http://creativecommons.org/licenses/by-sa/4.0/
*/

player allowDamage false;
player enableFatigue false;

Epoch_selectedIndex = 0;
EP_modes = ["Rocks","ATM","Water","Trash","Trees","Bushes","Wrecks"];
EP_selectedMode = EP_modes select Epoch_selectedIndex;
EP_modeColors = [[0,0,0,1],[0,0.5,0.9,1],[0,0,1,1],[1,0,0,1],[0,1,0,1],[0.5,0.5,0,1],[1,0.5,0.5,1],[1,1,1,1]];
EP_modesCount = (count EP_modes)-1;


EPOCH_dbg_saveMapConfig = {
    _br         = toString [13,10];
    _config_str = "class " + worldName +  " {" + _br;
    _array      = [];
    { 
        _config_str = _config_str +  format['    %1[] = {%2',_x,_br];             
        _printData = missionNamespace getVariable [_x,[]];
        _countArray = (count _printData) - 1;
        {
            _config_str      = _config_str +  format['        "%1"%2', _x, if (_forEachIndex isEqualTo _countArray) then {_br} else {("," + _br)}];   
        } forEach _printData; 
        _config_str = _config_str +  "    };" + _br;  
    } forEach EP_modes;
    _config_str = _config_str + "};" + _br;
    _config_str
};


EPOCH_KeyDownCustom = {
    _dikCode = _this select 1;
    _shift = _this select 2;
    _ctrl = _this select 3;
    _alt = _this select 4;
    _handled = false;

    switch (_dikCode) do {
        case 0x2E: {
            if (_ctrl) then {
            	hint "Saved to clipboard";
                copyToClipboard call EPOCH_dbg_saveMapConfig;

                EP_modesExport = [];
				{
				  	EP_modesExport pushBack (missionNamespace getVariable [_x,[]]);
				} forEach EP_modes;
            };
        };

        case 0xC9 : { 
            Epoch_selectedIndex = ((Epoch_selectedIndex + 1) min EP_modesCount) max 0;
            EP_selectedMode = EP_modes select Epoch_selectedIndex;
            hint EP_selectedMode;
            _handled = true;
        }; 
        case 0xD1 : { 
            Epoch_selectedIndex = ((Epoch_selectedIndex - 1) min EP_modesCount) max 0;
            EP_selectedMode = EP_modes select Epoch_selectedIndex;
            hint EP_selectedMode;
            _handled = true;
        }; 

        case 0xD3: {
            
            _handled = true;
            
			_currentPos = screenToWorld [0.5,0.5];

			if !(surfaceIsWater _currentPos) then {
				_currentPos = ATLtoASL _currentPos;
			};    
			EP_objects = lineIntersectsObjs[eyePos player, _currentPos, player, objNull, true, 2];

			{
				if (typeOf _x == "") then {
					_objStr = str _x;
					_findStart = _objStr find ": ";
					if (_findStart != -1) then {
						_p3dName = _objStr select [_findStart+2,999];
						EPOCH_ALL = EPOCH_ALL - [_p3dName];
						{
						    _varDataDel =  missionNamespace getVariable [_x,[]];
						  	if (_p3dName in _varDataDel) exitWith {
								_varDataDel = _varDataDel - [_p3dName];
								missionNamespace setVariable [_x,_varDataDel];
							};
						} forEach EP_modes;
					};
				};
			} forEach EP_objects;
        };
        
        
        case 0x39 : { 
            _handled = true;
            
			_currentPos = screenToWorld [0.5,0.5];  

			if !(surfaceIsWater _currentPos) then {      
				_currentPos = ATLtoASL _currentPos;
			};    
			EP_objects = lineIntersectsObjs[eyePos player, _currentPos, player, objNull, true, 2];

			_varData = missionNamespace getVariable [EP_selectedMode, []];
			_allData = missionNamespace getVariable ["EPOCH_ALL", []];
			{
				_objStr = str _x;
				_findStart = _objStr find ": ";
				if (_findStart != -1) then {
					_p3dName = _objStr select [_findStart+2,999];
					if !(_p3dName in _allData) then {
						if !(_p3dName in _varData) then {
							_allData pushBack _p3dName;
							_varData pushBack _p3dName;
						};
					};

				};
			} forEach EP_objects;
			missionNamespace setVariable [EP_selectedMode, _varData];
			missionNamespace setVariable ["EPOCH_ALL", _allData];


        };
    };
 
    _handled
};


[] spawn {
    (findDisplay 46) displayRemoveAllEventHandlers "KeyDown";
    (findDisplay 46) displayAddEventHandler["KeyDown",{_this call EPOCH_KeyDownCustom}];
};


onEachFrame {
	_all = nearestObjects [player, [], 20];
	{
		if (typeOf _x == "") then {
			_objStr = str _x;
			_findStart = _objStr find ": ";
			if (_findStart != -1) then {
				_p3dName = _objStr select [_findStart+2,999];	
				_color = [1,1,1,1];
				{
				  	if (_p3dName in (missionNamespace getVariable [_x,[]])) exitWith {
						_color = EP_modeColors select _foreachindex;
					};
				} forEach EP_modes;
				drawIcon3D ["a3\weapons_f\data\clear_empty.paa", _color, getPos _x, 1, 1, 45, _p3dName, 1, 0.04, "PuristaMedium"];
			};
		};
	} forEach _all;
	_lineColor = EP_modeColors select Epoch_selectedIndex;
	drawLine3D [ASLtoATL eyePos player, screenToWorld [0.5,0.5], _lineColor];
};




