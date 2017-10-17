/*
	Author: He-Man

    Contributors: DirtySanchez

	Description:
	Upgrade Vehicle Check

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/vehicles/EPOCH_client_upgradeVehicleCheck.sqf
*/

private ["_veh","_vehType","_config","_classUpgrade","_reqMaterials","_mattxt","_displayname"];
_veh = _this;

Ignatz_VehicleUpgradeArray = [];
if (isnull _veh) exitwith {
	["Upgrade failed - Vehicle not found",5] call Epoch_message;
};
if (player distance _veh > 12) exitwith {
	["Upgrade failed - Vehicle to far away",5] call Epoch_message;
};

_vehType = typeOf _veh;
_config = 'CfgVehicleUpgrades' call EPOCH_returnConfig;
if !(isclass (_config >> _vehType)) exitwith {
	["Vehicle not upgradeable",5] call Epoch_message;
};
_classUpgrade = getarray (_config >> _vehType >> "upgradeToVehicle");
if (_classUpgrade isequalto []) exitwith {
	["Vehicle not upgradeable",5] call Epoch_message;
};
if ((_veh getvariable ["Vehicle_Slot","-1"]) isequalto "-1") exitwith {
	["Vehicle not upgradeable",5] call Epoch_message;
};

{
	_classUpgrade = _x;
	if (_x isequaltype []) then {
		_classUpgrade = selectrandom _x;
	};
	if (isclass (_config >> _vehType >> _classUpgrade)) then {
		_reqMaterials = getArray (_config >> _vehType >> _classUpgrade >> "ReqMaterials");
		_mattxt = "Needed:";
		{
			_mattxt = _mattxt + format [' %1 %2,', _x select 0, (_x select 1) call EPOCH_itemDisplayName];
		} forEach _reqMaterials;
		_displayname = _classUpgrade call EPOCH_itemDisplayName;
		Ignatz_VehicleUpgradeArray pushback [_veh,_classUpgrade,_displayname,_mattxt];
	};
} foreach _classUpgrade;