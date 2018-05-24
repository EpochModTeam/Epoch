/*
	Author: He-Man - EpochMod.com

    Contributors:

	Description:
	Epoch use Defibrillator function

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/EPOCH_DefibrillatorUse.sqf
*/

private ["_item","_energyneeded","_totalDefis","_CurDefiArr"];

params ["_unit"];

if (isplayer _unit) then {
	_item = 'ItemDefibrillator';
	if (_item in magazines player) then {
		_energyneeded = 3;
		_totalDefis = (magazinesammo player) select {(_x select 0) isequalto _item};
		_CurDefiArr = [];
		{
			if ((_x select 1) >= _energyneeded) exitwith {
				_CurDefiArr = _totalDefis deleteat _foreachindex;
			};
		} foreach _totalDefis;
		if (_CurDefiArr isequalto []) exitwith {
			["Defibrillator needs more Energy",5] call Epoch_Message;
		};
		if ((_CurDefiArr select 1) - _energyneeded > 0) then {
			_CurDefiArr set [1,(_CurDefiArr select 1) - _energyneeded];
			_totalDefis pushback _CurDefiArr;
		};
		player removemagazines _item;
		{
			_x call EPOCH_fnc_addMagazineOverflow;
		} foreach _totalDefis;
		_unit spawn {
			player playMove 'AinvPknlMstpSnonWrflDnon_medic0';
			player playMove 'AinvPknlMstpSnonWrflDnon_medicEnd';
			uisleep 8;
			if (alive player && isplayer _this) then {
				[_this,player,Epoch_personalToken] remoteExec ['EPOCH_server_revivePlayer',2];
			};
		};
	}
	else {
		['You need a Defibrillator to Revive',5] call Epoch_Message;
	};
}
else {
	['This Player can not be revived',5] call Epoch_Message;
};