/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Epoch debug monitor

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/EPOCH_debugMonitor.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_customVars","_hours","_val"];
//[[[end]]]
_hours = floor(servertime/60/60);

_customVars = "";
{
	_val = missionNamespace getVariable [format ["EPOCH_player%1",_x],EPOCH_defaultVars select _forEachIndex];
	if !(_x in ["AliveTime","SpawnArray","HitPoints","MissionArray"]) then {
		if (_x == "Temp") then {
			_customVars = _customVars + format["<t size='1.15' font='puristaLight' align='left'>%1: </t><t size='1.15' font='puristaLight' align='right'>%2°F | %3°C</t><br/>", _x,_val,_val call EPOCH_convertTemp];
		} else {
			_customVars = _customVars + format["<t size='1.15' font='puristaLight' align='left'>%1: </t><t size='1.15' font='puristaLight' align='right'>%2</t><br/>", _x,_val];
		};
	}
}forEach EPOCH_customVars;

hintSilent parseText format ["
	<t size='1.25' font='puristaLight' align='center'>Welcome to Epoch!</t><br/>
	<t size='1.18' font='puristaLight' align='center'>Current Version: %1</t><br/>
	<t size='1.0' font='puristaLight' align='center'>Build: %2</t><br/>

	" + _customVars + "
	<br/>

	<t size='1.15' font='puristaLight' align='left'>Fatigue: </t><t size='1.15' font='puristaLight' align='right'>%3</t><br/>
	<t size='1.15' font='puristaLight' align='left'>Damage: </t><t size='1.15' font='puristaLight' align='right'>%4</t><br/>
	<t size='1.15' font='puristaLight' align='left'>Bleeding: </t><t size='1.15' font='puristaLight' align='right'>%5</t><br/>
	<t size='1.15' font='puristaLight' align='left'>Bleed Time: </t><t size='1.15' font='puristaLight' align='right'>%6</t><br/>
	<t size='1.15' font='puristaLight' align='left'>Oxygen: </t><t size='1.15' font='puristaLight' align='right'>%7</t><br/>
	<br/>
	<t size='1.15' font='puristaLight' align='left'>Air Temp: </t><t size='1.15' font='puristaLight' align='right'>%8</t><br/>
	<t size='1.15' font='puristaLight' align='left'>Water Temp: </t><t size='1.15' font='puristaLight' align='right'>%9</t><br/>
	<t size='1.15' font='puristaLight' align='left'>Rain: </t><t size='1.15' font='puristaLight' align='right'>%10</t><br/>
	<t size='1.15' font='puristaLight' align='left'>Overcast: </t><t size='1.15' font='puristaLight' align='right'>%11</t><br/>
	<br/>
	<t size='1.15' font='puristaLight' align='left'>Hours Alive: </t><t size='1.15' font='puristaLight' align='right'>%12</t><br/>
	<t size='1.15' font='puristaLight' align='left'>FPS: </t><t size='1.15' font='puristaLight' align='right'>%13</t><br/>
	<t size='1.15' font='puristaLight' align='left'>Server uptime: </t><t size='1.15' font='puristaLight' align='right'>%14h %15m</t><br/>
	<t size='1.15' font='puristaLight' align='left'>Server FPS: </t><t size='1.15' font='puristaLight' align='right'>%16</t><br/>",
	getText(configFile >> "CfgMods" >> "Epoch" >> "version"),
	getNumber(missionConfigFile >> "CfgEpochBuild" >> "build"),
	(getFatigue player),
	(damage player),
	(isBleeding player),
	(getBleedingRemaining player),
	(getOxygenRemaining player),
	format ["%1°F | %2°C",EPOCH_CURRENT_WEATHER,EPOCH_CURRENT_WEATHER call EPOCH_convertTemp],
	format ["%1°F | %2°C",(EPOCH_CURRENT_WEATHER/2),(EPOCH_CURRENT_WEATHER/2) call EPOCH_convertTemp],
	rain,
	overcast,

	round(EPOCH_playerAliveTime/360)/10,
	round diag_fps,
	_hours,
	round((serverTime/60)-(_hours*60)),
	if (EPOCH_diag_fps isEqualType 0) then [{EPOCH_diag_fps},{"MANIPULATED"}]
];
