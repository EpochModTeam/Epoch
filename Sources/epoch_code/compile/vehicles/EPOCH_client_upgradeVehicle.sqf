if (isnil 'EPOCH_UpgradeVehicle') exitwith {
	["Upgrade failed - Error",5] call Epoch_message;
};

EPOCH_UpgradeVehicle params ["_data",["_veh",objnull]]; 
EPOCH_UpgradeVehicle = nil;

if (isnull _veh) exitwith {
	["Upgrade failed - Vehicle not found",5] call Epoch_message;
};
if (player distance _veh > 12) exitwith {
	["Upgrade failed - Vehicle to far away",5] call Epoch_message;
};
if !(local _veh) exitwith {
	["Upgrade failed - Go in as Driver first",5] call Epoch_message;
};
if !(crew _veh isequalto []) exitwith {
	["Upgrade failed - All passengers must leave the Vehicle",5] call Epoch_message;
};

_vehType = typeOf _veh;

_config = 'CfgVehicleUpgrades' call EPOCH_returnConfig;
_classUpgrade = gettext (_config >> _data >> _vehType >> "upgradeToVehicle");
_reqMaterials = getArray (_config >> _data >> _vehType >> "ReqMaterials");

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
