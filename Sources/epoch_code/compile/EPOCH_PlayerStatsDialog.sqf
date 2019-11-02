/*
	Author: He-Man - EpochMod.com

	Contributors:

	Description:
	Fill Player Stats Dialog

	Licence:
	Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Github:
	https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/EPOCH_PlayerStatsDialog.sqf
*/
private ["_display","_UsedStats","_ctrlNo","_txt","_value"];
disableSerialization;
_display = findDisplay -1200;
if (isnull _display) exitwith {};
_UsedStats = ["CfgEpochClient", "PlayerStatsDialogEntries", []] call EPOCH_fnc_returnConfigEntryV2;
_ctrlNo = 1100;
{
	_ctrl = _display displayCtrl _ctrlNo;
	_txt = '';
	{
		_x params ["_stattype","_entrytext",["_calc","%1"]];
		_value = missionNamespace getVariable [format ['EPOCH_total%1',_stattype],0];
		_value = format [_calc,_value];
		_value = call compile _value;
		_txt = _txt + format ['<t color=''#ffff00''> %1:</t> %2 <br />',_entrytext,_value];
	} foreach _x;
	_ctrl ctrlSetStructuredText parseText _txt;
	_ctrlNo = _ctrlNo + 1;
} foreach _UsedStats;