/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	repair object via hit index

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/vehicles/EPOCH_client_repairVehicle.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_currentDMG","_god"];
//[[[end]]]
params ["_vehicle","_value"];
if (local _vehicle) then {
	_god = !(isDamageAllowed _vehicle);
	if (_god) then {_vehicle allowdamage true;};
	{
		if ((_x select 0) isequaltype 0) then {
			_vehicle setHitIndex [_x select 0, _x select 1];
		}
		else {
			_vehicle setHitPointDamage [_x select 0, _x select 1];
		};
	} foreach _value;
	if (_god) then {_vehicle allowdamage false;};
	
	if !({_x > 0} count ((getAllHitPointsDamage _vehicle) select 2) > 0) then {
		[_vehicle,["ALL",0],player,Epoch_personalToken] remoteExec ["EPOCH_server_repairVehicle",2];
	};
	
	_vehicle call EPOCH_interact;
	if !(EPOCH_arr_interactedObjs isEqualTo[]) then {
		[EPOCH_arr_interactedObjs] remoteExec['EPOCH_server_save_vehicles', 2];
		EPOCH_arr_interactedObjs = [];
	};
};
