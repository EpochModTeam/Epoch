/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	code that executes onEachFrame is used for 3d movment, ESP, and 3d icons.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/EPOCH_onEachFrame.sqf
*/
if (EPOCH_velTransform) then {
	if (EPOCH_playerEnergy > 0) then {
		_pos1 = getPosASL EPOCH_target;
		_vel1 = velocity EPOCH_target;
		_dir1 = vectorDir EPOCH_target;
		_up1 = vectorUp EPOCH_target;
		_interval = 0.1;

		if !(EP_velocityTransformation isEqualTo []) then {
			EPOCH_target setvelocitytransformation[_pos1, (EP_velocityTransformation select 0), _vel1, (EP_velocityTransformation select 1), _dir1, (EP_velocityTransformation select 2), _up1, (EP_velocityTransformation select 3), _interval];
		} else {
			_pos2 = player modelToWorld[EPOCH_X_OFFSET, EPOCH_Y_OFFSET, EPOCH_Z_OFFSET];
			if !(EPOCH_maxBuildingHeight == 0) then {
				if (_pos2 select 2 > EPOCH_maxBuildingHeight) then {
					_pos2 set[2, EPOCH_maxBuildingHeight];
				};
			};
			if ((_pos2 select 2) < 0) then { _pos2 set[2, 0] };
			if ((_pos1 distance _pos2) > 0) then {
				_newpos = AGLtoASL _pos2;
				if (surfaceiswater _pos2) then {
					_newpos = _pos2;
				};
				EPOCH_target setvelocitytransformation[_pos1, _newpos, _vel1, _vel1, _dir1, _dir1, _up1, _up1, _interval];
			};
		};
	} else {
		EPOCH_velTransform = false;
	};
};
if (!isNull EPOCH_currentTarget && vehicle player == player) then {
	_currentTarget = EPOCH_currentTarget;

	_distance = player distance _currentTarget;
	if (_distance < 9) then {

		_stability = 0;
		_color = [1, 1, 1, 1];
		_text = format ["Hold (%1)",EPOCH_keysAction call BIS_fnc_keyCode];
		_icon = "\x\addons\a3_epoch_code\Data\UI\ui_question_ca.paa";

		switch EPOCH_currentTargetMode do {
			case 0: {
				_stability = 100 - round(damage _currentTarget * 100);
				_icon = "\x\addons\a3_epoch_code\Data\UI\loading_bar_%1.paa";
				_color = [100,0,_stability,1] call EPOCH_colorRange;
			};
			case 1: {
				// _text = if (EPOCH_buildMode > 0) then[{_text}, { format ["Hold (%1)",EPOCH_keysBuildMode1 call BIS_fnc_keyCode] }];
				_stability = if (EPOCH_buildMode > 0) then[{_currentTarget getVariable["stability", 100]}, {100 - round(damage _currentTarget * 100)}];
				_icon = "\x\addons\a3_epoch_code\Data\UI\loading_bar_%1.paa";
				_color = [100,0,_stability,1] call EPOCH_colorRange;
			};
			case 2: {
				if (alive _currentTarget) then{
					// TODO move accept trade into dynamic menu
					_text = format["%1 - %2", if (isStreamFriendlyUIEnabled && isPlayer _currentTarget) then[{"Player"}, { name _currentTarget }],_text];
					_stability = 100 - round(damage _currentTarget * 100);
					_icon = "\x\addons\a3_epoch_code\Data\UI\loading_bar_%1.paa";
					_color = [100,0,_stability,1] call EPOCH_colorRange;
				} else {
					//_text = "Press (Inventory)";
					_icon = "\x\addons\a3_epoch_code\Data\UI\ui_crossbones_ca.paa";
				};
			};
			case 3: {
				// Animals, Drone, Sappers
				if (!alive _currentTarget && _distance < 2) then{
					_text = format ["Gut - %1",_text];
					_icon = "\x\addons\a3_epoch_code\Data\UI\ui_crossbones_ca.paa";
					_color = [1,1,1,1];
				};
			};
			case 4: {
				// Base Objects With Storage
				_text = if (EPOCH_buildMode > 0) then[{_text}, { format ["Hold (%1) or (%2)",EPOCH_keysAction call BIS_fnc_keyCode, ((actionKeys "Gear" select 0) call BIS_fnc_keyCode),_text] }];
				_stability = if (EPOCH_buildMode > 0) then[{_currentTarget getVariable["stability", 100]}, {100 - round(damage _currentTarget * 100)}];
				_icon = "\x\addons\a3_epoch_code\Data\UI\loading_bar_%1.paa";
				_color = [100,0,_stability,1] call EPOCH_colorRange;
			};
		};

		if (!isNull EPOCH_stabilityTarget) then {
			if (([10] call EPOCH_fnc_cursorTarget) != EPOCH_stabilityTarget) then {
				EPOCH_stabilityTarget = objNull;
			} else {
				_text = "";
				if ((diag_tickTime - EPOCH_lastTargetTime) >= 0.05) then {
					_stability = (_stability - 1) max 0;
					EPOCH_stabilityTarget setVariable["stability", _stability];
					EPOCH_lastTargetTime = diag_tickTime;
				};
				if (_stability == 0) then {
					switch EPOCH_buildOption do {
						case 0: {EPOCH_stabilityTarget call EPOCH_removeBUILD};
						case 1: {EPOCH_stabilityTarget call EPOCH_upgradeBUILD};
						case 2: {EPOCH_stabilityTarget call EPOCH_fnc_SelectTargetBuild};
					};
					EPOCH_stabilityTarget = objNull;
				};
			};
		};

		_pos = visiblePositionASL _currentTarget;
		_pos set[2, (_currentTarget modelToWorld[0, 0, 0]) select 2];
		_size = 2.5;
		drawIcon3D[format[_icon, _stability], _color, _pos, _size, _size, 0, _text, 0, _size / 60, "PuristaMedium"];
	};
} else {
	EPOCH_stabilityTarget = objNull;
};

if (EPOCH_drawIcon3d) then {
	{
		if (!isPlayer _x) then {
			_pos = visiblePositionASL _x;
			_pos set[2, (_x modelToWorld[0, 0, 0]) select 2];
			_endTime = _x getVariable["EPOCH_endTime", 0];
			_num = (round(_endTime - diag_tickTime)) max 0;
			_color = [10,0,_num,1] call EPOCH_colorRange;
			drawIcon3D[format["\x\addons\a3_epoch_code\Data\UI\loading_bar_%1.paa", _num], _color, _pos, 4, 4, 0, "", 1, 0.05, "PuristaMedium"];
		};
	}forEach EPOCH_arr_countdown;
};

{
	_distance = player distance _x;
	if (_distance < 9) then {
		_pos = _x;
		_color = [1, 1, 1, 0.7];
		_size = 1;
		drawIcon3D["x\addons\a3_epoch_code\Data\UI\snap_ca.paa", _color, _pos, _size, _size, 0, "", 1, _size / 60, "PuristaMedium"];
	};
}forEach EPOCH_arr_snapPoints;

{
	if (!isNull _x) then {
		_pos = visiblePositionASL _x;
		_pos set[2, (_x modelToWorld[0, 0, 0]) select 2];
		_dmg = damage _x;
		_color = [0,1,_dmg,1] call EPOCH_colorRange;
		_text = format['%1 : %2m', [typeOf _x,name _x] select (isPlayer _x), round(player distance _x)];
		drawIcon3D["\x\addons\a3_epoch_code\Data\Member.paa", _color, _pos, 1, 1, 0, _text, 1, 0.025, "PuristaMedium"];
	};
}forEach EPOCH_ESP_TARGETS;

if (EPOCH_ESP_PLAYER || EPOCH_ESP_VEHICLES) then {
	_viewDistance = viewDistance max 1000 min 2500;
	{
		if (!isNull _x) then {
			_distance = round(player distance _x);
			_pos = visiblePositionASL _x;
			if (isPlayer _x) then {
				if (EPOCH_ESP_PLAYER) then {
					_pos set[2, (_x modelToWorld[0, 0, 1.8]) select 2];
					_text = '';
					if (vehicle _x == _x) then {
						_text = format['%1 (%2m)', name _x, _distance];
					}
					else {
						_name = [];
						{if (alive _x && isPlayer _x) then { _id = _name pushBack(name _x) }} count crew vehicle _x;
						_text = format['%1 (%2m) - %3', _name, _distance, getText(configFile >> "CfgVehicles" >> typeOf vehicle _x >> "displayName")];
					};
					drawIcon3D['', [1, 0, 0, abs((_distance) / _viewDistance - 1)], _pos, 0.2, 0.2, 0, _text, 1, 0.03, "PuristaMedium"];
				};
			}
			else {
				if (EPOCH_ESP_VEHICLES) then {
					_pos set[2, (_x modelToWorld[0, 0, 0]) select 2];
					drawIcon3D['', [0, 0.5, 1, abs((_distance) / _viewDistance - 1)], _pos, 0.2, 0.2, 0, getText(configFile >> "CfgVehicles" >> typeOf _x >> "displayName"), 1, 0.03, "PuristaMedium"];
				};
			};
		};
	} forEach EPOCH_ESP_VEHICLEPLAYER;
};

call Epoch_custom_OnEachFrame;
