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
class base_mode_snap_direction
{
	condition = "EPOCH_buildMode == 1";
	action = "EPOCH_snapDirection = EPOCH_snapDirection + 1; if (EPOCH_snapDirection > 3) then {EPOCH_snapDirection = 0};[format['SNAP DIRECTION: %1°', EPOCH_snapDirection*90], 5] call Epoch_message;";
	icon = "x\addons\a3_epoch_code\Data\UI\buttons\build_move.paa";
	tooltip = "Build Mode: Rotate 90°";
	tooltipcode = "format ['Build Mode: Switch Snap Direction to %1° (current %2°)',if (EPOCH_snapDirection < 3) then {(EPOCH_snapDirection+1)*90} else {0},EPOCH_snapDirection*90]";
};
class base_mode_detach
{
	condition = "EPOCH_buildMode > 0 && !isnull EPOCH_target && EPOCH_target_attachedTo isequalto player && Epoch_target iskindof 'Const_Ghost_EPOCH'";
	action = "EPOCH_target_attachedTo = objnull; ['Object Detached', 5] call Epoch_message;";
	icon = "x\addons\a3_epoch_code\Data\UI\buttons\build_move.paa";
	tooltip = "Build Mode: Detach Object";
};
class base_mode_attach
{
	condition = "EPOCH_buildMode > 0 && !isnull EPOCH_target && !(EPOCH_target_attachedTo isequalto player) && Epoch_target iskindof 'Const_Ghost_EPOCH'";
	action = "EPOCH_target_attachedTo = player; ['Object Attached', 5] call Epoch_message;";
	icon = "x\addons\a3_epoch_code\Data\UI\buttons\build_move.paa";
	tooltip = "Build Mode: Attach Object";
};
class Drink
{
	condition = "_nearObjects = nearestObjects [player, [], 2];_check = 'water';_ok = false;{if (alive _x) then {_ok = [_x, _check] call EPOCH_worldObjectType;};if (_ok) exitWith {};} forEach _nearObjects;_ok";
	action = "if (currentweapon player == '') then {player playmove 'AinvPknlMstpSnonWnonDnon_Putdown_AmovPknlMstpSnonWnonDnon';}else {if (currentweapon player == handgunweapon player) then {player playmove 'AinvPknlMstpSrasWpstDnon_Putdown_AmovPknlMstpSrasWpstDnon';}else {	player playmove 'AinvPknlMstpSrasWrflDnon_Putdown_AmovPknlMstpSrasWrflDnon';};};{_output = _x call EPOCH_giveAttributes;if (_output != '') then {[_output, 5] call Epoch_message;};} foreach [['Toxicity',4,1],['Stamina',10],['Thirst',100]];";
	icon = "x\addons\a3_epoch_code\Data\UI\buttons\Drink.paa";
	tooltip = "Drink";
};
class ServicePoint
{
	condition = "call EPOCH_SP_Check";
	action = "call EPOCH_SP_Start;";
    icon = "x\addons\a3_epoch_code\Data\UI\buttons\Repair_man.paa";
	tooltip = "Service Point";

	class Refuel
	{
		condition = "true";
		action = "(Ignatz_Refuel select 1) spawn EPOCH_SP_Refuel";
        icon = "x\addons\a3_epoch_code\Data\UI\buttons\vehicle_refuel.paa";
		tooltipcode = "Ignatz_Refuel select 0";
	};
	class Repair
	{
		condition = "true";
		action = "(Ignatz_Repair select 1) spawn EPOCH_SP_Repair";
        icon = "x\addons\a3_epoch_code\Data\UI\buttons\repair.paa";
		tooltipcode = "Ignatz_Repair select 0";
	};
	class Rearm0
	{
		condition = "!isnil 'Ignatz_Rearm0'";
		action = "(Ignatz_Rearm0 select 1) call EPOCH_SP_Rearm";
        icon = "x\addons\a3_epoch_code\Data\UI\buttons\Rearm.paa";
		tooltipcode = "Ignatz_Rearm0 select 0";
	};
	class Rearm1
	{
		condition = "!isnil 'Ignatz_Rearm1'";
		action = "(Ignatz_Rearm1 select 1) call EPOCH_SP_Rearm";
        icon = "x\addons\a3_epoch_code\Data\UI\buttons\Rearm.paa";
		tooltipcode = "Ignatz_Rearm1 select 0";
	};
	class Rearm2
	{
		condition = "!isnil 'Ignatz_Rearm2'";
		action = "(Ignatz_Rearm2 select 1) call EPOCH_SP_Rearm";
        icon = "x\addons\a3_epoch_code\Data\UI\buttons\Rearm.paa";
		tooltipcode = "Ignatz_Rearm2 select 0";
	};
};
