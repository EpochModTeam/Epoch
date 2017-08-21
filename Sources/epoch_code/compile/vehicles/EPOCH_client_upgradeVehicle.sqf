/*
	Author: He-Man / DirtySanchez

    Contributors: 

	Description:
	Upgrade Vehicle

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/vehicles/EPOCH_client_upgradeVehicle.sqf
*/

private ["_vehType","_config","_reqMaterials","_crypto","_hasall","_missing","_has","_msg"];
params [["_veh",objnull],["_classUpgrade",""],["_displayname",""],["_mattxt",""]];

Ignatz_VehicleUpgradeArray = [];
if (isnull _veh) exitwith {
	["Upgrade failed - Vehicle not found",5] call Epoch_message;
};

_vehType = typeOf _veh;
_config = 'CfgVehicleUpgrades' call EPOCH_returnConfig;
if !(isclass (_config >> _vehType)) exitwith {
	["Vehicle not upgradeable",5] call Epoch_message;
};
_reqMaterials = getArray (_config >> _vehType >> _classUpgrade >> "ReqMaterials");

_crypto = 0;
if(_reqMaterials isEqualTo [])exitWith{
	["Required Materials list not found, report this error to an admin",5] call Epoch_message;
};
_hasall = true;
_missing = [];
{
	_x params ["_count","_item"];
	_has = 0;
	if (_item isequalto "Crypto") then {
		_has = Epoch_Playercrypto;
	}
	else {
		_has = {_x == _item} count ((magazines player)+(items player));
	};
	if (_has < _count) then {
		_missing pushback [_count-_has,_item];
		_hasall = false
	};
}forEach _reqMaterials;
if (!_hasall) exitwith {
	_msg = 'Missing:';
	{
		_msg = _msg + format [' %1 %2,', _x select 0, (_x select 1) call EPOCH_itemDisplayName];
	} foreach _missing;
	[_msg,5] call Epoch_message;
};
if !(local _veh) exitwith {
	["Upgrade failed - Go in as Driver first",5] call Epoch_message;
};
if !(crew _veh isequalto []) exitwith {
	["Upgrade failed - All passengers must leave the Vehicle",5] call Epoch_message;
};
if (player distance _veh > 15) exitwith {
	["Upgrade failed - Vehicle to far away",5] call Epoch_message;
};
if (player distance _veh < 4.5) exitwith {
	["Upgrade failed - Take a bit distance and try again",5] call Epoch_message;
};

{
	_x params ["_count","_item"];
	if (_item isequalto "Crypto") then {
		_crypto = _crypto + _count;
	}
	else {
		for "_i" from 1 to _count do{
			player removeItem _item;
		};
	};
} forEach _reqMaterials;

[[_veh,_classUpgrade,_crypto],player,Epoch_personalToken] remoteExec ["EPOCH_server_upgrade_vehicle",2];
