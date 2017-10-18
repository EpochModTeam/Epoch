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
		dyna_magazinesPlayer = "magazines player";
		dyna_assigneditems = "assignedItems player";
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
		
		dyna_blockWeapons = "[]";
		dyna_Turret = "if (!dyna_inVehicle) then {[]} else {if ((assignedVehicleRole player) isequalto ['driver']) then {[-1]} else {if (count (assignedVehicleRole player) == 2) then {(assignedVehicleRole player) select 1}else {[]}}}";
		dyna_weaponsTurret = "if (!dyna_inVehicle) then {[]}else {((vehicle player) weaponsTurret dyna_Turret) select {!((getArray(configFile >> 'CfgWeapons' >> _x >> 'magazines')) select {!((getText (configFile >> 'CfgMagazines' >> _x >> 'picture')) isequalto '')} isequalto [])}}";
		dyna_WeapsMagsTurret = "call {_out = [];if (dyna_inVehicle) then {_added = [];{_weapon = _x;_WeaponMags = ((vehicle player) magazinesTurret dyna_Turret) select {(_x in (getArray (configFile >> 'CfgWeapons' >> _weapon >> 'magazines'))) && !((getText (configFile >> 'CfgMagazines' >> _x >> 'picture')) isequalto '')};if !(_WeaponMags isequalto []) then {{if !(_x in _added) then {_out pushback [_weapon,_x];_added pushback _x;};} foreach _WeaponMags;};} foreach dyna_weaponsTurret;};_out}";
		
		dyna_mapPlayerMarkerON = "(getNumber(('CfgEpochClient' call EPOCH_returnConfig) >> 'playerLocationMarkerGPSOnly') isEqualTo 1)";
		dyna_mapPlayerMarker = "(((getArray(('CfgMarkerSets' call EPOCH_returnConfig) >> 'PlayerMarker' >> 'markerArray') select 0) select 0) in allMapMarkers)";
		
		dyna_deathMarkerON = "(getNumber(('CfgEpochClient' call EPOCH_returnConfig) >> 'playerDeathMarkerGPSOnly') isEqualTo 1)";
		dyna_deathMarker = "profileNameSpace getVariable['EPOCHLastKnownDeath',[]]";
		dyna_deathMarkerAvail = "!(dyna_deathMarker isEqualTo [])";
		dyna_mapDeathMarker = "(((getArray(('CfgMarkerSets' call EPOCH_returnConfig) >> 'DeathMarker' >> 'markerArray') select 0) select 0) in allMapMarkers)";
	};

	class self
	{
		#include "CfgActionMenu_self.hpp"
	};

	class target
	{
		#include "CfgActionMenu_target.hpp"
	};
	
	class map
	{
		#include "CfgActionMenu_map.hpp"
	};
};
