/*
	Author: Raimonds Virtoss - EpochMod.com

    Contributors: Aaron Clark

	Description:
	Action Menu Core Config

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_config/Configs/CfgActionMenu/CfgActionMenu_core.hpp
*/

class CfgActionMenu
{
	class variableDefines //must be global, nil when menu closes
	{
		dyna_cursorTarget = "([10] call EPOCH_fnc_cursorTarget)";
		dyna_cursorTargetType = "typeOf ([10] call EPOCH_fnc_cursorTarget)";
		dyna_inVehicle = "vehicle player != player";
		dyna_itemsPlayer = "items player";
		dyna_sizeOf = "((sizeOf dyna_cursorTargetType/2) max 6) min 30";
		dyna_distance = "(player distance dyna_cursorTarget) <= dyna_sizeOf";

		dyna_buildMode = "([10] call EPOCH_fnc_cursorTarget) call EPOCH_checkBuild;";
		dyna_isVehicle = "if (!(isNull dyna_cursorTarget) && alive dyna_cursorTarget) then {((dyna_cursorTarget isKindOf 'LandVehicle') || (dyna_cursorTarget isKindOf 'Air') || (dyna_cursorTarget isKindOf 'Ship') || (dyna_cursorTarget isKindOf 'Tank'))} else {false}";
		dyna_isTrader = "if (!(isNull dyna_cursorTarget) && alive dyna_cursorTarget) then {((dyna_cursorTarget isKindOf 'Man') && (dyna_cursorTarget != player) && (!isPlayer dyna_cursorTarget) && ((dyna_cursorTarget getVariable['AI_SLOT', -1]) != -1))} else {false}";
		dyna_isPlayer = "if (!(isNull dyna_cursorTarget) && alive dyna_cursorTarget) then {((dyna_cursorTarget isKindOf 'Man') && (dyna_cursorTarget != player) && (isPlayer dyna_cursorTarget))} else {false}";
		dyna_isDeadPlayer = "if (!(isNull dyna_cursorTarget) && !(alive dyna_cursorTarget)) then {(dyna_cursorTargetType in ['Epoch_Male_F','Epoch_Female_F'])} else {false}";
		dyna_canAcceptTrade = "if (!(isNull EPOCH_pendingP2ptradeTarget) && alive EPOCH_pendingP2ptradeTarget) then {((EPOCH_pendingP2ptradeTarget isKindOf 'Man') && (dyna_cursorTarget isEqualTo EPOCH_pendingP2ptradeTarget))} else {false}";
		dyna_locked = "locked dyna_cursorTarget in [2,3]";
		dyna_lockedInVehicle = "locked vehicle player in [2,3]";
		
		dyna_inDriver = "driver vehicle player == player";
		dyna_inTurret = "gunner vehicle player == player";
		dyna_inCommander = "player isEqualTo commander objectParent player";
		dyna_vehicleRoleEmpty = "((assignedVehicleRole player) isEqualTo [])";
		
		dyna_blockTurrets = "['Horn', 'MiniCarHorn', 'SportCarHorn', 'TruckHorn2', 'TruckHorn', 'BikeHorn', 'CarHorn', 'TruckHorn3']";
		
		dyna_weaponsTurret = "if!(dyna_vehicleRoleEmpty)then{(vehicle player) weaponsTurret ((assignedVehicleRole player) select 1)}else{nil}";
		dyna_weaponsTurretPath = "if(!isNil {dyna_weaponsTurret})then{((assignedVehicleRole player) select 1)}else{nil}";
		dyna_weaponsTurretMags = "if(!isNil {dyna_weaponsTurret})then{vehicle player magazinesTurret dyna_weaponsTurretPath}else{[]}";
		
		dyna_driverTurret = "if(dyna_inDriver)then{vehicle player weaponsTurret[-1]}else{nil}";
		dyna_driverTurretMags = "if(!isNil {dyna_driverTurret})then{vehicle player magazinesTurret[-1]}else{[]}";
		
		dyna_isGunning = "if(dyna_inVehicle && dyna_inTurret && !dyna_inDriver)then{(!isNil {dyna_weaponsTurret})}else{false}";
		dyna_isDriving = "if(dyna_inVehicle && dyna_inDriver)then{(!isNil {dyna_driverTurret})}else{false}";
		dyna_isCommanding = "if(dyna_inVehicle && dyna_inCommander)then{(!isNil {dyna_weaponsTurret})}else{false}";
	};

	class self
	{
		#include "CfgActionMenu_self.hpp"
	};

	class target
	{
		#include "CfgActionMenu_target.hpp"
	};
};
