/*
	Author: Aaron Clark - EpochMod.com - @vbawol

	Contributors: @Skaronator @raymix @Fank

	Description:
	Key Down EH functions

	Licence:
	Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Github:
	https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/interface_event_handlers/EPOCH_KeyDown.sqf

	Example:
	_this call EPOCH_KeyDown;

	Parameter(s):
		_this select 0: CONTROL - _display
		_this select 1: NUMBER - _dikcode
		_this select 2: BOOL - Shift State
		_this select 3: BOOL - Ctrl State
		_this select 4: BOOL - Alt State

	Returns:
	BOOL
*/
//[[[cog import generate_private_arrays ]]]
private ["_adj","_currentPos","_handled","_playerEnergy","_playerEnergyKeyFinal","_playerStaminaKeyFinal","_step"];
//[[[end]]]
params ["_display","_dikCode","_shift","_ctrl","_alt"];

_playerStaminaKeyFinal = "EPOCH_playerStamina";
_playerEnergyKeyFinal = "EPOCH_playerEnergy";
if !(isNil "_playerStaminaKey") then {_playerStaminaKeyFinal = _playerStaminaKey};
if !(isNil "_playerEnergyKey") then {_playerEnergyKeyFinal = _playerEnergyKey};

_handled = false;

_this call Epoch_custom_EH_KeyDown;
if (_handled) exitWith{ true };

if !(alive player) exitWith{ false };

EPOCH_doRotate = false;

if !(EPOCH_modKeys isequalto [_shift,_ctrl,_alt]) then {
	EPOCH_modKeys = [_shift,_ctrl,_alt];
	call epoch_favBar_modifier;
};

//Favorites bar
if (_dikCode in [EPOCH_keysfav1,EPOCH_keysfav2,EPOCH_keysfav3,EPOCH_keysfav4,EPOCH_keysfav5]) then {
	if (isnull EPOCH_Target) then {
		_handled = _this call epoch_favBar_action;
	} else {
		"Can't use while in building mode!" call epoch_message;
	};
};

// increase vol
if (_ctrl && _dikCode == EPOCH_keysVolumeUp) then {
	EPOCH_soundLevel = (EPOCH_soundLevel + 0.1) min 1;
	5 fadeSound EPOCH_soundLevel;
	[format["Internal sound level: %1%2", EPOCH_soundLevel * 100, "%"], 5,[[0,0,0,0.5],[0,1,1,1]]] call Epoch_message;
};
// lower vol
if (_ctrl && _dikCode == EPOCH_keysVolumeDown) then {
	EPOCH_soundLevel = (EPOCH_soundLevel - 0.1) max 0.1;
	5 fadeSound EPOCH_soundLevel;
	[format["Internal sound level: %1%2", EPOCH_soundLevel * 100,"%"], 5,[[0,0,0,0.5],[0,1,1,1]]] call Epoch_message;
};

// ESC default to cancel
if (_dikCode in (actionKeys "ingamePause")) then {
	if !(isNull EPOCH_Target) then {
		if !(EPOCH_Target isKindOf "ThingX") then {
			deleteVehicle EPOCH_Target;
		} else {
			EPOCH_Target = objNull;
		};
		["Build Canceled", 5] call Epoch_message;
	};
	if !(EPOCH_arr_interactedObjs isEqualTo[]) then {
		[EPOCH_arr_interactedObjs] remoteExec["EPOCH_server_save_vehicles", 2];
		EPOCH_arr_interactedObjs = [];
	};
};

// Debug Monitor
if (_dikCode == EPOCH_keysDebugMon) then {
	EPOCH_debugMode = !EPOCH_debugMode;
	if (EPOCH_debugMode) then {
		["Debug Mode Enabled", 5,[[0,0,0,0.5],[1,1,0,1]]] call Epoch_message;
	} else {
		["Debug Mode Disabled", 5,[[0,0,0,0.5],[1,1,0,1]]] call Epoch_message;
		hintSilent "";
	};
	_handled = true;
};

// E-Pad
if (_dikCode == EPOCH_keysEPad) then {
	if (isnull (finddisplay 9898)) then {
		createdialog 'epoch_tablet_gui';
	};
};

if (_dikCode == EPOCH_Earplugs) then {
	if (EPOCH_Earplugsin) then {
		EPOCH_Earplugsin = false;
		1 fadeSound 1;
	}
	else {
		EPOCH_Earplugsin = true;
		1 fadeSound 0.15;
	};
};

//Action Menu
if (_dikCode == EPOCH_keysAction) then {
	//_handled = true;
	{player reveal _x;} foreach (player nearObjects 50);
	if !(EPOCH_keysActionPressed) then {
		EPOCH_keysActionPressed = true;
		if (cursorTarget isKindOf "AllVehicles") then {
			call epoch_dynamicMenu;
		} else {
			[] spawn {
				uiSleep 0.2;
				if (EPOCH_keysActionPressed) then {call epoch_dynamicMenu};
			};
		};
	};
};

// Player only code
if (vehicle player == player) then {

	if ((_dikCode == EPOCH_keysBuildMode1 && !EPOCH_favBar_itemConsumed) && EPOCH_buildMode > 0) then {
		EPOCH_buildMode = 0;
		["Build Mode: Disabled", 5] call Epoch_message;
		EPOCH_Target = objNull;
		_handled = true;
	};

	// H - holster unholster
	if (_dikCode == EPOCH_keysHolster) then {
		if (player nearObjects["Const_All_Walls_F", 3] isEqualTo[] && speed player == 0) then {
			if (currentweapon player != "") then {
				EPOCH_Holstered = currentweapon player;
				player action["switchWeapon", player, player, 100];
			}
			else {
				if (EPOCH_Holstered != "") then {
					player selectWeapon EPOCH_Holstered;
				};
			};
		};
	};

	if (EPOCH_buildMode > 0) then {
		if (!isnull EPOCH_Target) then {
			if (!_ctrl) then {
				_step = 0.5;
				if(_shift)then{_step = 1.5;};
				if(_alt)then{_step = 0.01;};
				switch (_dikCode) do {
					case EPOCH_keysBuildMovUp: { _adj = 0.1;if(_shift)then{_adj = 0.5};if(_alt)then{_adj = 0.01};EPOCH_Z_OFFSET = (EPOCH_Z_OFFSET + _adj) min 6; _handled = true };
					case EPOCH_keysBuildMovDn: { _adj = 0.1;if(_shift)then{_adj = 0.5};if(_alt)then{_adj = 0.01};EPOCH_Z_OFFSET = (EPOCH_Z_OFFSET - _adj) max - 3; _handled = true };
					case EPOCH_keysBuildMovFwd: { _adj = 0.1;if(_shift)then{_adj = 0.5};if(_alt)then{_adj = 0.01};EPOCH_Y_OFFSET = (EPOCH_Y_OFFSET + _adj) min 5; _handled = true };
					case EPOCH_keysBuildMovBak: { _adj = 0.1;if(_shift)then{_adj = 0.5};if(_alt)then{_adj = 0.01};EPOCH_Y_OFFSET = (EPOCH_Y_OFFSET - _adj) max -5; _handled = true };
					case EPOCH_keysBuildMovL: { _adj = 0.1;if(_shift)then{_adj = 0.5};if(_alt)then{_adj = 0.01};EPOCH_X_OFFSET = (EPOCH_X_OFFSET + _adj) min 5; _handled = true };
					case EPOCH_keysBuildMovR: { _adj = 0.1;if(_shift)then{_adj = 0.5};if(_alt)then{_adj = 0.01};EPOCH_X_OFFSET = (EPOCH_X_OFFSET - _adj) max -5; _handled = true };
					case EPOCH_keysBuildRotL: { _adj = 1;if(_shift)then{_adj = 2.5};if(_alt)then{_adj = 0.5};EPOCH_buildDirection = (EPOCH_buildDirection + _adj) min 180; EPOCH_doRotate = true; _handled = true };
					case EPOCH_keysBuildRotR: { _adj = 1;if(_shift)then{_adj = 2.5};if(_alt)then{_adj = 0.5};EPOCH_buildDirection = (EPOCH_buildDirection - _adj) max -180; EPOCH_doRotate = true; _handled = true };
					/*case EPOCH_keysBuildIt: { cursorTarget call EPOCH_fnc_SelectTarget; _handled = true };*/
					case eXpoch_keysVectorResetObject: { EPOCH_X_OFFSET = 0;EPOCH_Y_OFFSET = 5;EPOCH_Z_OFFSET = 0;EPOCH_buildDirection = 0;EPOCH_buildDirectionPitch = 0;EPOCH_buildDirectionRoll = 0;EPOCH_doRotate = true;_handled = true };
				};
				if (Epoch_target iskindof 'Const_Ghost_EPOCH') then {
					switch (_dikCode) do {
						case eXpoch_keysVectorTiltL: {_adj = 1;if(_shift)then{_adj = 2.5};if(_alt)then{_adj = 0.5};EPOCH_buildDirectionRoll = (EPOCH_buildDirectionRoll - _adj) max -EPOCH_MaxBuildingTilt; EPOCH_doRotate = true; _handled = true };
						case eXpoch_keysVectorTiltR: {_adj = 1;if(_shift)then{_adj = 2.5};if(_alt)then{_adj = 0.5};EPOCH_buildDirectionRoll = (EPOCH_buildDirectionRoll + _adj) min EPOCH_MaxBuildingTilt; EPOCH_doRotate = true; _handled = true };
						case eXpoch_keysVectorTiltAwy: {_adj = 1;if(_shift)then{_adj = 2.5};if(_alt)then{_adj = 0.5};EPOCH_buildDirectionPitch = (EPOCH_buildDirectionPitch - _adj) max -EPOCH_MaxBuildingTilt; EPOCH_doRotate = true; _handled = true };
						case eXpoch_keysVectorTiltTwd: {_adj = 1;if(_shift)then{_adj = 2.5};if(_alt)then{_adj = 0.5};EPOCH_buildDirectionPitch = (EPOCH_buildDirectionPitch + _adj) min EPOCH_MaxBuildingTilt; EPOCH_doRotate = true; _handled = true };
					};
				};
			};
		};
	};

	if (_dikCode in(actionKeys "moveFastForward") || _dikCode in(actionKeys "moveForward")) then {
		if ((diag_tickTime - EPOCH_lastAGTime) > 0.5) then {
			EPOCH_lastAGTime = diag_tickTime;
			if !(player nearObjects["Const_All_Walls_F", 6] isEqualTo[]) then {
				_currentPos = player modelToWorld[0, 1.75, 1];
				if !(surfaceIsWater _currentPos) then {
					_currentPos = ATLtoASL _currentPos;
				};
				player forceWalk(lineIntersects[eyePos player, _currentPos, player, objNull]);
			}
			else {
				player forceWalk false;
			};
		};
	};

	if ((_dikCode in(actionKeys "moveDown") || _dikCode in(actionKeys "Prone")) && speed player > 0) then {
		_currentPos = player modelToWorld[0, 5, 0.5];
		if !(surfaceIsWater _currentPos) then {
			_currentPos = ATLtoASL _currentPos;
		};
		_handled = (lineIntersects[eyePos player, _currentPos, player, objNull]);
	};

	if (!_ctrl && _dikCode in(actionKeys "GetOver")) then {
		if ((diag_tickTime - EPOCH_lastJumptime) > 2) then {

			_currentPos = player modelToWorld[0, 2, 1];
			if !(surfaceIsWater _currentPos) then {
				_currentPos = ATLtoASL _currentPos;
			};

			if !(lineIntersects[eyePos player, _currentPos, player, objNull]) then {
				EPOCH_lastJumptime = diag_tickTime;
				if (isTouchingGround player && speed player > 10) then {
					if ((primaryWeapon player != "") && (currentWeapon player == primaryWeapon player)) then {
						player switchMove "AovrPercMrunSrasWrflDf";
						[player, "AovrPercMrunSrasWrflDf", Epoch_personalToken] remoteExec ["EPOCH_server_handle_switchMove",2];
						[_playerStaminaKeyFinal, -30, 1000 , 0] call EPOCH_fnc_setVariableLimited;
						_handled = true;
					} else {
						if (currentWeapon player == "") then {
							player switchMove "epoch_unarmed_jump";
							[player, "epoch_unarmed_jump", Epoch_personalToken] remoteExec ["EPOCH_server_handle_switchMove",2];
							[_playerStaminaKeyFinal, -30, 1000 , 0] call EPOCH_fnc_setVariableLimited;
							_handled = true;
						};
					};
				};
			} else {
				_handled = true;
			};
		} else {
			_handled = true;
		};
	};

	if (_dikCode in(actionKeys "Gear") && !EPOCH_gearKeyPressed) then {
		EPOCH_gearKeyPressed = true;
		if !(isNull EPOCH_Target) then {
			if !(EPOCH_Target isKindOf "ThingX") then {
				deleteVehicle EPOCH_Target;
			} else {
				EPOCH_Target = objNull;
			};
			["Build Canceled", 5] call Epoch_message;
		};
		if (isTouchingGround player) then {
			// _handled = call EPOCH_lootTrash;
		};
	};
	if (EPOCH_IsAutoRunning) then {
		if (_dikCode in ((actionKeys "moveForward") + (actionKeys "TurnLeft") + (actionKeys "TurnRight") + (actionKeys "moveBack"))) then {
			EPOCH_IsAutoRunning = false;
			player switchMove "";
		};
	};
}; // end player only code

EPOCH_favBar_itemConsumed = false;

if (_dikCode in (actionKeys "Salute")) then {
	if (_ctrl) then {
		player playactionNow "GestureFinger";
		_handled = true;
	};
};
if (_dikCode in (actionKeys "TacticalView")) then {
	_handled = true;
};
if (_dikCode in (actionKeys "NightVision")) then {
	_playerEnergy = missionNamespace getVariable [_playerEnergyKeyFinal,0];
	if (_playerEnergy == 0) then {
		["Night Vision Goggles: Need Energy", 5] call Epoch_message;
		_handled = true;
	};
};

if(!_ctrl && (_dikCode in (actionKeys "HeliRopeAction")))then{
	if (player == vehicle player) exitwith {};
	_msg = "";
	if(currentPilot vehicle player isEqualTo player)then{
		if(EPOCH_ArmaSlingLoad)then{
			if (["CfgEpochClient", "ActionHookRope", true] call EPOCH_fnc_returnConfigEntryV2) then {
				_slung = ropeAttachedObjects vehicle player;
				if(_slung isEqualTo [])then{
					if!('ItemRope' in magazines player) then {
						_msg = "You need rope to hook";
						_handled = true;
					}else{
						player removeItem 'ItemRope';
					};
				}else{
					player addItem 'ItemRope';
				};
			};
		}else{
			_msg = "Hook/Unhook Malfunction, overrode by R3F or AdvSlingLoad";
			_handled = true;
		};
	};
	if!(_msg isEqualTo "")then{
		[_msg,5,[[0,0,0,0.2],[1,1,1,1]]] call Epoch_message_stack;
	};
};

if (!isnull (finddisplay -1200) && !isnull Epoch_ActiveCam) then {
	_multi = 1;
	if (isnil 'Epoch_CamTrigger') then {
		Epoch_CamTrigger = diag_ticktime - 0.2;
	};
	if (diag_ticktime - Epoch_CamTrigger < 0.1) then {
		_multi = 3;
	};
	Epoch_CamTrigger = diag_ticktime;
	switch _dikCode do {
		case Epoch_KB_BaseCamNextCam: {	/* Num Enter */
			call Epoch_CamUse;
		};
		case Epoch_KB_BaseCamLeft: {	/* Num 4 */
			Epoch_AutoCam = false;
			Epoch_CamAdjust = [-3*_multi,0,0];
		};
		case Epoch_KB_BaseCamRight: {	/* Num 6 */
			Epoch_AutoCam = false;
			Epoch_CamAdjust = [3*_multi,0,0];
		};
		case Epoch_KB_BaseCamUp: {	/* Num 8 */
			Epoch_AutoCam = false;
			Epoch_CamAdjust = [0,8*_multi,0];
		};
		case Epoch_KB_BaseCamDown: {	/* Num 2 */
			Epoch_AutoCam = false;
			Epoch_CamAdjust = [0,-8*_multi,0];
		};
		case Epoch_KB_BaseCamZoomOut: {	/* Num - */
			Epoch_AutoCam = false;
			Epoch_CamAdjust = [0,0,0.1*_multi];
		};
		case Epoch_KB_BaseCamZoomIn: { /* Num + */
			Epoch_AutoCam = false;
			Epoch_CamAdjust = [0,0,-0.1*_multi];
		};
		case Epoch_KB_BaseCamAutoCam: { /* Num 0 */
			Epoch_AutoCam = true;
			Epoch_CamAdjust = [0,0,0];
		};
	};
};
_handled
