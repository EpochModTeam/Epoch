/*
	Author: He-Man - EpochMod.com

	Contributors:

	Description:
	Fill Server Stats Dialog

	Licence:
	Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Github:
	https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/EPOCH_ServerStatsDialog.sqf
*/

private [
	"_display","_UsedStats","_Stat1Pos","_MainDistX","_MainDistY","_SubDistX1","_SubDistX2","_SubDistY1","_SubDistY2","_MainWidth","_SubWidth1","_SubWidth2","_SubWidth3",
	"_MainHeight","_SubHeight","_ZeroX","_ZeroY","_c","_posX","_posY","_ListedStats","_ctrl","_SubPosY","_ImIn","_SubPosX"
];

disableSerialization;
_display = findDisplay -1200;
if (isnull _display) exitwith {};
_UsedStats = ["CfgEpochClient", "TopStatsDialogEntries", []] call EPOCH_fnc_returnConfigEntryV2;
_Stat1Pos = [
	0.0720312 * safezoneW + safezoneX,
	0.071 * safezoneH + safezoneY,
	0.134062 * safezoneW,
	0.033 * safezoneH
	];
_MainDistX = 0.216406-0.0720312;
_MainDistY = 0.489-0.071;
_SubDistX1 = 0.0926562-0.0720312;
_SubDistX2 = 0.175156-0.0926562;
_SubDistY1 = 0.115-0.071;
_SubDistY2 = 0.148-0.115-0.002;
_MainWidth = 0.134062;
_SubWidth1 = 0.0154688;
_SubWidth2 = 0.0773437;
_SubWidth3 = 0.0309375;
_MainHeight = 0.033;
_SubHeight = 0.022;

_ZeroX = 0.0720312;
_ZeroY = 0.071;


_c = 1;
_posX = _ZeroX;
_posY = _ZeroY;
_ListedStats = [];
{
	_x params ["_stattype","_entrytext",["_calc","%1"]];
	_ctrl = _display ctrlCreate['RscText', -1];
	_ctrl ctrlSetPosition [
		-_MainWidth * safezoneW + safezoneX,
		_posY * safezoneH + safezoneY,
		_MainWidth * safezoneW,
		_MainHeight * safezoneH
	];
	_ctrl ctrlSetText _entrytext;
	_ctrl ctrlsetbackgroundcolor [0.02,0,0.03,0.6];
	_ctrl ctrlsetTextColor [1,1,0,1];
	_ctrl ctrlCommit 0;
	_ctrl ctrlSetPosition [
		_posX * safezoneW + safezoneX,
		_posY * safezoneH + safezoneY
	];
	_ctrl ctrlCommit 0.02;
	_SubPosY = _posY+_SubDistY1;
	_ImIn = false;
	{
		_x params ["_value","_UID","_name"];
		_SubPosX = _posX;
		_ctrl = _display ctrlCreate['RscText', -1];
		_ctrl ctrlSetPosition [
			-_MainWidth * safezoneW + safezoneX,
			_SubPosY * safezoneH + safezoneY,
			_SubWidth1 * safezoneW,
			_SubHeight * safezoneH
		];
		_ctrl ctrlCommit 0;
		_ctrl ctrlSetText str (_foreachindex + 1);
		_ctrl ctrlsetbackgroundcolor [0.02,0,0.03,0.6];
		_ctrl ctrlSetPosition [
			_SubPosX * safezoneW + safezoneX,
			_SubPosY * safezoneH + safezoneY
		];
		_ctrl ctrlCommit 0.02;
		_SubPosX = _SubPosX + _SubDistX1;
		_ctrl = _display ctrlCreate['RscText', -1];
		_ctrl ctrlSetPosition [
			-_MainWidth * safezoneW + safezoneX,
			_SubPosY * safezoneH + safezoneY,
			_SubWidth2 * safezoneW,
			_SubHeight * safezoneH
		];
		_ctrl ctrlCommit 0;
		_ctrl ctrlSetText _name;
		if ((_x select 1) isequalto (getplayeruid player)) then {
			_ctrl ctrlsetTextColor [0,1,0,1];
			_ImIn = true;
		};
		_ctrl ctrlsetbackgroundcolor [0.02,0,0.03,0.6];
		_ctrl ctrlSetPosition [
			_SubPosX * safezoneW + safezoneX,
			_SubPosY * safezoneH + safezoneY
		];
		_ctrl ctrlCommit 0.02;
		_SubPosX = _SubPosX + _SubDistX2;
		_ctrl = _display ctrlCreate['RscText', -1];
		_ctrl ctrlSetPosition [
			-_MainWidth * safezoneW + safezoneX,
			_SubPosY * safezoneH + safezoneY,
			_SubWidth3 * safezoneW,
			_SubHeight * safezoneH
		];
		_value = format [_calc,_value];
		_value = call compile _value;
		if (_value isEqualType "") then {
			_ctrl ctrlSetText _value;
		}
		else {
			_ctrl ctrlSetText str _value;
		};
		_ctrl ctrlsetbackgroundcolor [0.02,0,0.03,0.6];
		_ctrl ctrlCommit 0;
		_ctrl ctrlSetPosition [
			_SubPosX * safezoneW + safezoneX,
			_SubPosY * safezoneH + safezoneY
		];
		_ctrl ctrlCommit 0.015;
		waituntil {ctrlCommitted _ctrl};
		_SubPosY = _SubPosY+_SubDistY2;
	} foreach (EPOCH_Topstats select _foreachindex);
	if (!_ImIn) then {
		_SubPosX = _posX;
		_ctrl = _display ctrlCreate['RscText', -1];
		_ctrl ctrlSetPosition [
			-_MainWidth * safezoneW + safezoneX,
			_SubPosY * safezoneH + safezoneY,
			_SubWidth1 * safezoneW,
			_SubHeight * safezoneH
		];
		_ctrl ctrlCommit 0;
		_ctrl ctrlSetText '#';
		_ctrl ctrlsetbackgroundcolor [0.02,0,0.03,0.6];
		_ctrl ctrlSetPosition [
			_SubPosX * safezoneW + safezoneX,
			_SubPosY * safezoneH + safezoneY
		];
		_ctrl ctrlCommit 0.02;
		_SubPosX = _SubPosX + _SubDistX1;
		_ctrl = _display ctrlCreate['RscText', -1];
		_ctrl ctrlSetPosition [
			-_MainWidth * safezoneW + safezoneX,
			_SubPosY * safezoneH + safezoneY,
			_SubWidth2 * safezoneW,
			_SubHeight * safezoneH
		];
		_ctrl ctrlCommit 0;
		_txt = name player;
		_ctrl ctrlSetText _txt;
		_ctrl ctrlsetTextColor [0,1,0,1];
		_ctrl ctrlsetbackgroundcolor [0.02,0,0.03,0.6];
		_ctrl ctrlSetPosition [
			_SubPosX * safezoneW + safezoneX,
			_SubPosY * safezoneH + safezoneY
		];
		_ctrl ctrlCommit 0.02;
		_SubPosX = _SubPosX + _SubDistX2;
		_ctrl = _display ctrlCreate['RscText', -1];
		_ctrl ctrlSetPosition [
			-_MainWidth * safezoneW + safezoneX,
			_SubPosY * safezoneH + safezoneY,
			_SubWidth3 * safezoneW,
			_SubHeight * safezoneH
		];
		_value = missionNamespace getVariable [format ['Epoch_total%1',_stattype],0];
		_value = format [_calc,_value];
		_value = call compile _value;
		if (_value isEqualType "") then {
			_ctrl ctrlSetText _value;
		}
		else {
			_ctrl ctrlSetText str _value;
		};
		_ctrl ctrlsetbackgroundcolor [0.02,0,0.03,0.6];
		_ctrl ctrlCommit 0;
		_ctrl ctrlSetPosition [
			_SubPosX * safezoneW + safezoneX,
			_SubPosY * safezoneH + safezoneY
		];
		_ctrl ctrlCommit 0.02;
		waituntil {ctrlCommitted _ctrl};
		_SubPosY = _SubPosY+_SubDistY2;
	};
	_c = _c + 1;
	if (_c > 6) then {
		_posX = _ZeroX;
		_posY = _posY+_MainDistY;
		_c = 1;
	}
	else {
		_posX = _posX+_MainDistX;
	};
} foreach _UsedStats;
