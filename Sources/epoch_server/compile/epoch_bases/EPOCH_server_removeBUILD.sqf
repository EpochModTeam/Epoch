/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Remove Building

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_bases/EPOCH_server_removeBUILD.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_ammoObj","_arrCount","_attachments","_cfgBaseBuilding","_gwh","_inventory","_isTemporary","_magazineName","_magazineSize","_magsAmmoCargo","_nearbyWH","_objQty","_objType","_objTypes","_posWH","_qty","_removeParts","_storageSlot","_vehSlot","_wMags","_wMagsArray","_wepsItemsCargo"];
//[[[end]]]
params ["_building","_player",["_token","",[""]] ];

if !([_player, _token] call EPOCH_server_getPToken) exitWith{};
if (isNull _building) exitWith{};
if (_player distance _building > 20) exitWith{};
if (_building getvariable ['Build_LockedForRemoving',false]) exitwith {};
_building setvariable ['Build_LockedForRemoving',true];

// TODO add group check here since this should only be removed by group or owner of pole
_objType = typeOf _building;
_cfgBaseBuilding = 'CfgBaseBuilding' call EPOCH_returnConfig;
_isTemporary = getNumber(_cfgBaseBuilding >> _objType >> "isTemporary");

// check that object has building or storage slot
_vehSlot = _building getVariable["BUILD_SLOT", -1];
_storageSlot = _building getVariable["STORAGE_SLOT", "ABORT"];

if (_vehSlot != -1 || _storageSlot != "ABORT" || _isTemporary == 1) then{

	_removeParts = getArray(_cfgBaseBuilding >> _objType >> "removeParts");
	if !(_removeParts isEqualTo []) then {

		_posWH = getPosATL _player;
		_gwh = objNull;
		// give player a refund of parts
		_nearbyWH = nearestObjects[_posWH, ["groundWeaponHolder"], 2];
		if !(_nearbyWH isEqualTo[]) then{
			_gwh = _nearbyWH select 0;
			// _posWH = getPosATL _gwh;
		} else {
			_gwh = createVehicle["groundWeaponHolder", [0,0,0], [], 0, "CAN_COLLIDE"];
			_gwh setPosATL _posWH;
		};

		if !(isNull _gwh) then{

			// if normal storage device dump items on ground.
			if (_building isKindOf "Buildable_Storage") then {
				_inventory = _building call EPOCH_server_CargoSave;
				[_building, _player] call EPOCH_server_save_killedStorage;
				deleteVehicle _building;
				[_gwh,_inventory] call EPOCH_server_CargoFill;
			} else {

				// Remove trap object
				_ammoObj = _building getVariable ["EPOCH_TRAP_OBJ",objNull];
				if !(isNull _ammoObj) then {
					deleteVehicle _ammoObj;
				};

				[_building, _player] call EPOCH_server_save_killedBuilding;
				deleteVehicle _building;
			};
			// Normal config based payout
			_nearbyWH = nearestObjects[_posWH, ["groundWeaponHolder"], 2];
			if !(_nearbyWH isEqualTo[]) then{
				_gwh = _nearbyWH select 0;
				// _posWH = getPosATL _gwh;
			} else {
				_gwh = createVehicle["groundWeaponHolder", [0,0,0], [], 0, "CAN_COLLIDE"];
				_gwh setPosATL _posWH;
			};

			{
				_gwh addMagazineCargoGlobal[_x select 0, _x select 1];
			} forEach _removeParts;
		};
	};
};
