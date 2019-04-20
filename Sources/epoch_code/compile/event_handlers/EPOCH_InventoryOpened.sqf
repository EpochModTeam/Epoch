/*
	Author: Aaron Clark - EpochMod.com

    Contributors: [Ignatz] He-Man

	Description:
	A3 Epoch InventoryOpened Eventhandler

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/event_handlers/EPOCH_InventoryOpened.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_InvTarget","_stored","_savecontainer","_blocked","_containerlocked","_seclocked"];
//[[[end]]]
params ["_unit","_container","_sec"];

_InvTarget = ObjNull;
{
	if (_x isKindOf "MAN" && {player distance _x < 2} && {lifeState _x == "INCAPACITATED"} && {!(_x in [_container,_sec])}) exitwith {
		_InvTarget = _x;
	};
} foreach [cursortarget,cursorobject];
if (!isnull _InvTarget) exitwith {
	player action ["Gear",_InvTarget];
	true
};

setMousePosition[0.5, 0.5];
call EPOCH_showStats;
_this spawn EPOCH_initUI;
_containerlocked = (locked _container in [2, 3] || _container getVariable['EPOCH_Locked', false]);
_seclocked = false;
if !(isNull _sec) then {
	_seclocked = (locked _sec in [2, 3] || _sec getVariable['EPOCH_Locked', false]);
};
_blocked = (_containerlocked && _seclocked);
if (!_blocked && _containerlocked || _seclocked) then {
	[] spawn {

		disableSerialization;
		waitUntil {!isNull findDisplay 602};
		private _d = findDisplay 602;
		private _cargo = _d displayCtrl 6401;
		private _ground = _d displayCtrl 6321;
		_cargo ctrlEnable false;
		ctrlSetFocus _ground;
		ctrlActivate _ground;
	};
};

_savecontainer = objnull;
_vehSlot1 = _container getVariable["VEHICLE_SLOT", "ABORT"];
_storageSlot1 = _container getVariable["STORAGE_SLOT", "ABORT"];
_vehSlot2 = _sec getVariable["VEHICLE_SLOT", "ABORT"];
_storageSlot2 = _sec getVariable["STORAGE_SLOT", "ABORT"];
if (_vehSlot1 != "ABORT" || _storageSlot1 != "ABORT") then{
	_savecontainer = _container;
}
else {
	if (_vehSlot2 != "ABORT" || _storageSlot2 != "ABORT") then{
		_savecontainer = _sec;
	};
};
if (!_blocked) then {
	_savecontainer spawn {
		waituntil {!isnull (findDisplay 602)};
		call EPOCH_CryptoButtons;
		if (!isnull _this) then {
			while {!isnull (findDisplay 602)} do {
				_stored = [itemcargo _this, magazinecargo _this, backpackcargo _this];
				waituntil {uisleep 0.5; !(_stored isequalto [itemcargo _this, magazinecargo _this, backpackcargo _this]) || isnull (findDisplay 602)};
				if !(_stored isequalto [itemcargo _this, magazinecargo _this, backpackcargo _this]) then {
					_this call EPOCH_interact;
				};
			};
		};
	};
};

_blocked
