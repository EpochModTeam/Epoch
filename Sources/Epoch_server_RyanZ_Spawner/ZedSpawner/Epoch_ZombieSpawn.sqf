waituntil {uisleep 1; !isnil "Ryanzombiesdamage" && !isnil "Ryanzombieshealth" && !isnil "Ryanzombieslimit" && !isnil "RZ_fnc_zombie_attackHuman" && !isnil "RZ_CrawlerAggressiveArray"};
uisleep 15;

params [
	["_Ryanzombiesdamage",0.018],
	["_Ryanzombieshealth",0.95],
	["_ryanzombiesinfectedchance",0],
	["_ryanzombiesinfectedrate",0],
	["_ryanzombiesinfectedsymptoms",0],
	["_ryanzombiesinfecteddeath",0],
	["_ryanzombiesantivirusduration",0],
	["_NoZedAreas",[]],
	["_MaxOverallZeds",50],
	["_BlackListedVehicles",["SHIP","AIR"]],
	["_ZedSpawnArr",
		[
			[0,15,0,2,3],
			[2,15,1,2,4],
			[4,20,1,3,5],
			[6,20,2,4,6],
			[8,25,2,4,7],
			[10,25,3,5,8],
			[15,30,3,6,10],
			[20,30,4,7,10],
			[25,35,5,7,15]
		]
	],
	["_ZedCheckTimer",50]
];


Ryanzombiesdamage 				= _Ryanzombiesdamage;
Ryanzombieshealth 				= _Ryanzombieshealth;
ryanzombiesinfectedchance 		= _ryanzombiesinfectedchance;
ryanzombiesinfectedrate 		= _ryanzombiesinfectedrate;
ryanzombiesinfectedsymptoms 	= _ryanzombiesinfectedsymptoms;
ryanzombiesinfecteddeath 		= _ryanzombiesinfecteddeath;
ryanzombiesantivirusduration 	= _ryanzombiesantivirusduration;
NoZedAreas						= _NoZedAreas;
MaxOverallZeds					= _MaxOverallZeds;
BlackListedVehicles				= _BlackListedVehicles;
ZedSpawnArr						= _ZedSpawnArr;

ryanzombiesglow = nil;					// Do not change it here! Just in the config!
ryanzombiesglowdemondisable = false;

RZ_CrawlerAggressiveArray = RZ_NormalZombieAggressiveArray;

Epoch_ZedAttack = {
	_soundEffectFinal = "A3\sounds_f\weapons\silenced\silent-23.wss";
	_unit = player;
	_soundEffectRange = 0;
	playSound3D [_soundEffectFinal, _unit, false, getPosASL _unit, 1, 1, _soundEffectRange];	
	addCamShake [3,0.5,30];
	player setdamage (damage player + Ryanzombiesdamage);
};

reverse ZedSpawnArr;
_ZedSpawnCheckTime = diag_ticktime;
_ZedSpawnCheck = {
	params [["_target",objnull]];
	_output = [];
	if (!isnull _target && alive _target) then {
		if (isobjecthidden _target) exitwith {};
		if ({vehicle _target iskindof _x} count BlackListedVehicles > 0) exitwith {};
		if (speed (vehicle _target) > 25) exitwith {};
		if ({_x distance2d _target < 150} count (missionnamespace getvariable ["Epoch_Plotpoles",[]]) > 0) exitwith {};
		_OverallZeds = (entities [["EPOCH_RyanZombie_1","RyanZombieCivilian_F"],[],true,false]);
		_AliveZeds = _OverallZeds select {alive _x};
		if ((count _AliveZeds) <= MaxOverallZeds) then {
			_NearHouses = (_target nearObjects ["house", 100]) select {!((_x buildingPos -1) isEqualTo [])};
			_housecount = count _NearHouses;
			_spawnArray = [0,0,0,0,0];
			{
				_x params ["_HousesInRange"];
				if (_housecount >= _HousesInRange) exitwith {
					_spawnArray = _x;					
				};				
			} foreach ZedSpawnArr;
			_spawnArray params ["_HousesInRange","_SpawnChance","_MinSpawn","_MaxSpawn","_maxZedsInRange"];
			_Spawncount = _MinSpawn + (round (random (_MaxSpawn - _MinSpawn)));
			if (_SpawnChance > (random 100)) then {
				_nearplayer = count ((_target nearEntities 100) select {isplayer _x});
				_Spawncount = round (_Spawncount / _nearplayer);
				if (_Spawncount > 0) then {
					_NearZeds = count (_OverallZeds select {_target distance _x < 200});
					if (_NearZeds < _maxZedsInRange) then {
						_pos = [_target, 50, 100, 1, 0, 50, 0] call BIS_fnc_findSafePos;
						if (count _pos == 2) then {
							_Spawncount = (_Spawncount min (_maxZedsInRange - _NearZeds) min (MaxOverallZeds - (count _OverallZeds)));
							_output = [_target,_Spawncount,_pos,_NearHouses];
						};
					};
				};
			};
		};
	};
	_output
};


if (!isserver && hasinterface) exitwith {
	while {true} do {
		if (diag_ticktime > _ZedSpawnCheckTime) then {
			_output = [player] call _ZedSpawnCheck;
			if !(_output isEqualto []) then {
				[_output] remoteexec ["Epoch_ZedSpawner",2];
			};
			_ZedSpawnCheckTime = diag_ticktime + _ZedCheckTimer;
		};
		uisleep 0.5;
	};
};
