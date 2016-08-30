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
private ["_handled","_currentPos"];
params ["_display","_dikCode","_shift","_ctrl","_alt"];

_handled = false;

if !(alive player) exitWith{ false };

EPOCH_doRotate = false;

if (_dikCode in [0x02,0x03,0x04,0x58,0x57,0x44,0x43,0x42,0x41,0x40,0x3F,0x3E,0x3D,0x3C,0x3B,0x0B,0x0A,0x09,0x08,0x07,0x06,0x05,0x0E]) then {
	_handled = true;
};

// increase vol
if (_ctrl && _dikCode == EPOCH_keysVolumeUp) then {
	EPOCH_soundLevel = (EPOCH_soundLevel + 0.1) min 1;
	5 fadeSound EPOCH_soundLevel;
	[format["Internal sound level: %1%2", EPOCH_soundLevel * 100, "%"], 5] call Epoch_message;
};
// lower vol
if (_ctrl && _dikCode == EPOCH_keysVolumeDown) then {
	EPOCH_soundLevel = (EPOCH_soundLevel - 0.1) max 0.1;
	5 fadeSound EPOCH_soundLevel;
	[format["Internal sound level: %1%2", EPOCH_soundLevel * 100,"%"], 5] call Epoch_message;
};

// ESC default to cancel
if (_dikCode == 0x01) then {
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
		["Debug Mode Enabled", 5] call Epoch_message;
	} else {
		["Debug Mode Disabled", 5] call Epoch_message;
		hintSilent "";
	};
	_handled = true;
};

//Action Menu
if (_dikCode == EPOCH_keysAction) then {
	_handled = true;
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
	_disableBuildMode = {
		EPOCH_buildMode = 0;
		EPOCH_snapDirection = 0;
		["Build Mode Disabled", 5] call Epoch_message;
		EPOCH_Target = objNull;
		EPOCH_Z_OFFSET = 0;
		EPOCH_X_OFFSET = 0;
		EPOCH_Y_OFFSET = 5;
	};
	if (_dikCode == EPOCH_keysBuildMode1) then {
		if (EPOCH_buildMode == 1) then {
			call _disableBuildMode;
		} else {
			if (EPOCH_playerEnergy > 0) then {
				EPOCH_stabilityTarget = objNull;
				EPOCH_buildMode = 1;
				["Build Mode Enabled: Snap alignment", 5] call Epoch_message;
				EPOCH_buildDirection = 0;
			} else {
				["Need Energy", 5] call Epoch_message;
			};
		};
		_handled = true;
	};
	if (_dikCode == EPOCH_keysBuildMode2) then {
		if (EPOCH_buildMode == 2) then {
			call _disableBuildMode;
		} else {
			if (EPOCH_playerEnergy > 0) then {
				EPOCH_stabilityTarget = objNull;
				EPOCH_buildMode = 2;
				["Build Mode Enabled: Free", 5] call Epoch_message;
				EPOCH_buildDirection = 0;
			}
			else {
				["Need Energy", 5] call Epoch_message;
			};
		};
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
		if (_dikCode == EPOCH_keysBuildDir) then {
			EPOCH_snapDirection = EPOCH_snapDirection + 1;
			if (EPOCH_snapDirection > 3) then {
				EPOCH_snapDirection = 0;
				["SNAP DIRECTION MODE: 0", 5] call Epoch_message;
			}
			else {
				[format["SNAP DIRECTION MODE: %1", EPOCH_snapDirection], 5] call Epoch_message;
			};
			_handled = true;
		};

		if (!_ctrl) then {
			switch (_dikCode) do {
			case EPOCH_keysBuildMovUp: { EPOCH_Z_OFFSET = (EPOCH_Z_OFFSET + 0.1) min 6; _handled = true };
			case EPOCH_keysBuildMovDn: { EPOCH_Z_OFFSET = (EPOCH_Z_OFFSET - 0.1) max - 3; _handled = true };
			case EPOCH_keysBuildMovFwd: { EPOCH_Y_OFFSET = (EPOCH_Y_OFFSET + 0.1) min 5; _handled = true };
			case EPOCH_keysBuildMovBak: { EPOCH_Y_OFFSET = (EPOCH_Y_OFFSET - 0.1) max 2; _handled = true };
			case EPOCH_keysBuildMovL: { EPOCH_X_OFFSET = (EPOCH_X_OFFSET + 0.1) min 5; _handled = true };
			case EPOCH_keysBuildMovR: { EPOCH_X_OFFSET = (EPOCH_X_OFFSET - 0.1) max - 5; _handled = true };
			case EPOCH_keysBuildRotL: { EPOCH_buildDirection = (EPOCH_buildDirection + 1) min 360; EPOCH_doRotate = true; _handled = true };
			case EPOCH_keysBuildRotR: { EPOCH_buildDirection = (EPOCH_buildDirection - 1) max 0; EPOCH_doRotate = true; _handled = true };
			//case EPOCH_keysBuildIt: { cursorTarget call EPOCH_fnc_SelectTarget; _handled = true };
			};
		};
	};

	if (_dikCode in(actionKeys "moveFastForward") || _dikCode in(actionKeys "moveForward")) then {
		if ((diag_tickTime - EPOCH_lastAGTime) > 1) then {
			EPOCH_lastAGTime = diag_tickTime;
			if !(player nearObjects["Const_All_Walls_F", 6] isEqualTo[]) then {
				_currentPos = player modelToWorld[0, 1, 1];
				if !(surfaceIsWater _currentPos) then {
					_currentPos = ATLtoASL _currentPos;
				};
				player forceWalk(lineIntersects[eyePos player, _currentPos, player, objNull]);
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
						_handled = true;
					} else {
						if (currentWeapon player == "") then {
							player switchMove "epoch_unarmed_jump";
							[player, "epoch_unarmed_jump", Epoch_personalToken] remoteExec ["EPOCH_server_handle_switchMove",2];
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

}; // end player only code

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
	if (EPOCH_playerEnergy == 0) then {
		["Night Vision Goggles: Need Energy", 5] call Epoch_message;
		_handled = true;
	};
};

// only return anything if _handled actually is true
if (_handled isEqualTo true) then {true};
