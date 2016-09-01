/*
	Author: Andrew Gregory - EpochMod.com

    Contributors:

	Description:
	A3 Epoch call sapper migration

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/EPOCH_callSapperMigration.sqf
*/
//[[[cog import generate_private_arrays ]]]
private ["_abortAfter","_axeSapper","_dirTo","_disableAI","_finish","_notReady","_nrPlyrs","_pos","_sapperCount","_start","_trgt"];
//[[[end]]]

 _disableAI = {
	{_this disableAI _x}forEach["TARGET","AUTOTARGET","FSM"];
};

_trgt = player;
if(count _this > 0)then{
_trgt = _this select 0;
};
_sapperCount = 8;
if(count _this > 1)then{
_sapperCount = _this select 1;
};
_notReady = true;
_abortAfter = 0;
_start = [];
_finish = [];
while {_notReady} do {
    _start =  _trgt getPos [480, random 360];
    _dirTo = [_start,_trgt,18] call EPOCH_fnc_dirToFuzzy;
    _finish = _start getPos [((_start distance _trgt) * 2),_dirTo];
    _nrPlyrs = nearestObjects [_start, ["Epoch_Female_base_F","Epoch_Man_base_F"],200];
    if((!(surfaceIsWater _start) && !(surfaceIsWater _finish) && (count _nrPlyrs < 1)) || _abortAfter > 41)then{
        _notReady = false;
    };
    _abortAfter = _abortAfter + 1;
};

if(_abortAfter < 42)then{

	[_sapperCount,_start,_disableAI,_finish]spawn{
	params["_sapperCount","_start","_disableAI","_finish",["_pos",[]],["_axeSapper", objNull]];
		for "_i" from 1 to _sapperCount step 1 do  {
			_pos = _start findEmptyPosition [0,20,"Epoch_Sapper_F"];
			_axeSapper = createAgent ["Epoch_Sapper_F", _pos, [], 12, "FORM"];
			waitUntil {_axeSapper == _axeSapper};
			_axeSapper call _disableAI;
			EPOCHSapperMigrationHandle = [_axeSapper,_finish] execFSM "\x\addons\a3_epoch_code\System\sapperSwarmMember.fsm";
			uiSleep 0.75;
		};
		Epoch_axeMigrationRunning = true;
	};
};
