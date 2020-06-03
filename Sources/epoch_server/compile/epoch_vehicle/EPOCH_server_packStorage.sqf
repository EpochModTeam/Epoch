/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
    Dumps inventory of safe/lockbox to ground

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server/compile/epoch_vehicle/EPOCH_server_packStorage.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_arrCount","_attachments","_class","_config","_gwh","_inventory","_magazineName","_magazineSize","_magsAmmoCargo","_objQty","_objType","_objTypes","_owners","_posWH","_qty","_returnItems","_wMags","_wMagsArray","_wepsItemsCargo"];
//[[[end]]]
params ["_unit","_player",["_token","",[""]] ];

if !([_player, _token] call EPOCH_server_getPToken) exitWith{};
if (isNull _unit) exitWith{};
if (_player distance _unit > 20) exitWith{};

_class = typeOf _unit;
if (_class isKindOf 'Constructions_lockedstatic_F') then {

	_owners = _unit getVariable["STORAGE_OWNERS", []];
	if ((getPlayerUID _player) in _owners) then {

		_posWH = getPosATL _unit;

		_inventory = _unit call EPOCH_server_CargoSave;
		[_unit, _player] call EPOCH_server_save_killedStorage;
		deleteVehicle _unit;

		_gwh = createVehicle["groundWeaponHolder", _posWH, [], 0, "CAN_COLLIDE"];
		_gwh setPosATL _posWH;
		[_gwh,_inventory] call EPOCH_server_CargoFill;
		_config = 'CfgBaseBuilding' call EPOCH_returnConfig;
		_returnItems = getArray(_config >> _class >> "returnOnPack");
		{
			_gwh addMagazineCargoGlobal _x;
		} forEach _returnItems;
	};
};
