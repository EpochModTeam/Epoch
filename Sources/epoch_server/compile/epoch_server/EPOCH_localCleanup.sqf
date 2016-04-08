/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Cleanup server side temp spawned objects by players

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_server/compile/epoch_server/EPOCH_localCleanup.sqf

    Example:
    _object(s) call EPOCH_localCleanup;

    Parameter(s):
		_this: OBJECT or ARRAY of Objects

	Returns:
	NOTHING
*/
if !(_this isEqualType []) then {
	_this = [_this];
};
{
	if (!isNull _x) then {
		_x addEventHandler["local", {
			params ["_unit","_isLocal"];
			if (_isLocal) then {
				if (!isNull _unit) then{
					{
						_unit removeAllMPEventHandlers _x;
					}forEach["mpkilled", "mphit", "mprespawn"];
					{
						_unit removeAllEventHandlers _x;
					}forEach["FiredNear", "HandleDamage", "Killed", "Fired", "GetOut", "GetIn", "Local"];
					deleteVehicle _unit;
					deleteGroup(group _unit);
				};
			};
		}];
	};
}forEach _this;
