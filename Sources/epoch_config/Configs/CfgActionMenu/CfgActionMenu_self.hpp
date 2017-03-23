/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors: Aaron Clark

	Description:
	Action Menu Self Config

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_config/Configs/CfgActionMenu/CfgActionMenu_self.hpp
*/

class veh_lock
{
	condition = "dyna_inVehicle && !dyna_lockedInVehicle";
	action = "[vehicle player, true, player, Epoch_personalToken] remoteExec ['EPOCH_server_lockVehicle',2];";
	icon = "x\addons\a3_epoch_code\Data\UI\buttons\pad_cannot_lock.paa";
	tooltip = "Lock";
};
class veh_unLock
{
	condition = "dyna_inVehicle && dyna_lockedInVehicle";
	action = "[vehicle player, false, player, Epoch_personalToken] remoteExec ['EPOCH_server_lockVehicle',2];";
	icon = "x\addons\a3_epoch_code\Data\UI\buttons\pad_can_unlock.paa";
	tooltip = "Unlock";
};
class player_inspect
{
	condition = "!dyna_inVehicle";
	action = "call EPOCH_lootTrash;";
	icon = "x\addons\a3_epoch_code\Data\UI\buttons\player_inspect.paa";
	tooltip = "Examine";
};
class player_group_menu
{
	condition = "true";
	action = "call EPOCH_Inventory_Group;";
	icon = "x\addons\a3_epoch_code\Data\UI\buttons\group_menu_ca.paa";
	tooltip = "Group Menu";
};
class player_group_requests
{
	condition = "!(Epoch_invited_GroupUIDs isEqualTo[])";
	action = "call EPOCH_Inventory_iGroup;";
	icon = "x\addons\a3_epoch_code\Data\UI\buttons\group_requests_ca.paa";
	tooltip = "Group Requests";
};

class base_mode_enable
{
	condition = "EPOCH_buildMode in [0,2] && !dyna_inVehicle";
	action = "if (EPOCH_playerEnergy > 0) then {EPOCH_stabilityTarget = objNull;EPOCH_buildMode = 1;['Build Mode: Enabled Snap alignment', 5] call Epoch_message;EPOCH_buildDirection = 0} else {['Need Energy!', 5] call Epoch_message};";
	icon = "x\addons\a3_epoch_code\Data\UI\buttons\build_maintain.paa";
	tooltip = "Build Mode: Snap alignment";
};
class base_mode_enable_free
{
	condition = "EPOCH_buildMode == 1 && EPOCH_playerEnergy > 0";
	action = "EPOCH_stabilityTarget = objNull;EPOCH_buildMode = 2;['Build Mode: Enabled Free alignment', 5] call Epoch_message;EPOCH_buildDirection = 0;";
	icon = "x\addons\a3_epoch_code\Data\UI\buttons\build_maintain.paa";
	tooltip = "Build Mode: Free alignment";
};
class base_mode_disable
{
	condition = "EPOCH_buildMode > 0";
	action = "EPOCH_buildMode = 0;EPOCH_snapDirection = 0;['Build Mode: Disabled', 5] call Epoch_message;EPOCH_Target = objNull;EPOCH_Z_OFFSET = 0;EPOCH_X_OFFSET = 0;EPOCH_Y_OFFSET = 5;";
	icon = "x\addons\a3_epoch_code\Data\UI\buttons\build_remove.paa";
	tooltip = "Build Mode: Disable";
};

class base_mode_snap_direction_0
{
	condition = "EPOCH_buildMode == 1 && EPOCH_snapDirection != 0";
	action = "EPOCH_snapDirection = 0;[format['SNAP DIRECTION MODE: %1', EPOCH_snapDirection], 5] call Epoch_message;";
	icon = "x\addons\a3_epoch_code\Data\UI\buttons\build_move.paa";
	tooltip = "Build Mode: Snap Direction 0°";
};
class base_mode_snap_direction_1
{
	condition = "EPOCH_buildMode == 1 && EPOCH_snapDirection != 1";
	action = "EPOCH_snapDirection = 1;[format['SNAP DIRECTION MODE: %1', EPOCH_snapDirection], 5] call Epoch_message;";
	icon = "x\addons\a3_epoch_code\Data\UI\buttons\build_move.paa";
	tooltip = "Build Mode: Snap Direction 90°";
};
class base_mode_snap_direction_2
{
	condition = "EPOCH_buildMode == 1 && EPOCH_snapDirection != 2";
	action = "EPOCH_snapDirection = 2;[format['SNAP DIRECTION MODE: %1', EPOCH_snapDirection], 5] call Epoch_message;";
	icon = "x\addons\a3_epoch_code\Data\UI\buttons\build_move.paa";
	tooltip = "Build Mode: Snap Direction 180°";
};
class base_mode_snap_direction_3
{
	condition = "EPOCH_buildMode == 1 && EPOCH_snapDirection != 3";
	action = "EPOCH_snapDirection = 3;[format['SNAP DIRECTION MODE: %1', EPOCH_snapDirection], 5] call Epoch_message;";
	icon = "x\addons\a3_epoch_code\Data\UI\buttons\build_move.paa";
	tooltip = "Build Mode: Snap Direction 270°";
};
