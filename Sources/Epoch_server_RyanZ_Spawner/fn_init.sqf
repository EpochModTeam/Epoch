if !(isclass (configFile >> "CfgPatches" >> "Ryanzombies")) exitwith {
	diag_log "Epoch Debug: RyanZ Spawner skipped - RyanZombies seems to not run on this Server";
};
[] spawn {
	waituntil {uisleep 1; !isnil "Ryanzombiesdamage" && !isnil "Ryanzombieshealth" && !isnil "Ryanzombieslimit" && !isnil "RZ_fnc_zombie_attackHuman" && !isnil "RZ_CrawlerAggressiveArray"};
	uisleep 15;

	RZ_fnc_zombie_attackHuman = {
		params ["_zombie","_target"]; 
		_dir = _zombie getDir _target;
		_zombie setdir _dir;
		[_zombie, "AwopPercMstpSgthWnonDnon_throw"] remoteExecCall ["fnc_RyanZombies_SwitchMove"];
		_attackSound = selectRandom ([_zombie,"attack"] call RZ_fnc_zombie_getZombieSoundArray);
		playsound3d [_attackSound, _zombie, false, getPosASL _zombie, 1, pitch _zombie];
		_target allowfleeing 1;
		sleep 0.3;
		_attackSpeed = [Ryanzombiesattackspeed,0.3] select (_zombie getVariable "RZ_isDemon");
		if ([_zombie,_target] call RZ_fnc_zombie_canAttackHuman) then {
			_hitSound = selectRandom ([_zombie,"hit"] call RZ_fnc_zombie_getZombieSoundArray);
			playsound3d [_hitSound, _target, false, getPosASL _target, 1, pitch _zombie];	
			if (isnil "ryanzombiesdisablebleeding") then { 
				[_target, 10] remoteExecCall ["fnc_RyanZombies_Bleeding"]; 
			};
			_scream = selectRandom RZ_HumanScreamArray;
			[_target, _scream] remoteExecCall ["say3d"];
			_vel = velocity _target;
			_dir = direction _zombie;
			_strength = _zombie call RZ_fnc_zombie_getHumanVelocityStrength;
			[_target, [(_vel select 0) + (sin _dir * _strength), (_vel select 1) + (cos _dir * _strength), (_vel select 2) + random 1]] remoteExecCall ["fnc_RyanZombies_Velocity"];
			[] remoteexec ['Epoch_ZedAttack',_target];
		};
		sleep _attackSpeed;
	};
	RZ_fnc_zombie_checkForNewTarget =
	{
		private _zombie = _this;
		private _civilians = [];
		if !(isnil "ryanzombiescivilianattacks") then 
		{
			_civilians = nearestobjects [_zombie, ["Civilian"], 100 min Ryanzombieslimit]; 
			_civsToDelete = [];
			{
				if (!alive _x || _x getvariable ["ace_medical_inReviveState",false] || lifeState _x == "INCAPACITATED") then 
				{
					_civsToDelete pushback _x;
				};
			} foreach _civilians;
			_civilians = _civilians - _civsToDelete;
		};
		
		private _target = _zombie findNearestEnemy _zombie;
		if (count _civilians != 0) then
		{
			_civiliantarget = _civilians select 0;
			if (!isNull _target && ((_target distance _zombie) < (_civiliantarget distance _zombie))) exitwith {};
			if (_zombie knowsabout _civiliantarget > 0.5) then 
			{
				_target = _civiliantarget; 
			};
		};
		if(!isNull _target) then 
		{
			if(_zombie distance _target > Ryanzombieslimit) exitWith { _target = objNull; };	
		};
		_zombie setVariable ["RZ_Target",_target];
		_target
	};
	RZ_fnc_zombie_canAttackHuman = 
	{
		params ["_zombie","_target"];
		if(!alive _zombie || !alive _target || _target getvariable ["ace_medical_inReviveState",false] ||  lifeState _target == "INCAPACITATED") exitWith { false };
		_maxAttackDistance = _zombie call RZ_fnc_zombie_maxAttackDistanceToHuman;
		((_zombie distance _target) < _maxAttackDistance && !(lineIntersects [eyepos _zombie, eyepos _target,_zombie,_target]))
	};
	MyZeds = [];
	Epoch_ZedSpawner = {
		params [["_output",[]]];
		if !(_output isequalto []) then {
			_output params ["_target","_Spawncount","_pos","_NearHouses"];
			_group = creategroup [RESISTANCE,true];
			for "_i" from 1 to _Spawncount do {
				_randomPos = [_pos,random 15,random 360] call BIS_fnc_relPos;
				_Zed = _group createUnit [selectrandom ZedClasses, _randomPos, [], 5, "NONE"];
				if (Epoch_ryanzombiesglow isEqualTo 1) then {
					_Zed setface (selectrandom RZ_FaceArray);
				};
				MyZeds pushback _Zed;
				uisleep 0.15;
			};
			_FirstWp = [_target, 10, 50, 1, 0, 50, 0] call BIS_fnc_findSafePos;
			if (count _FirstWp == 2) then {
				_FirstWp pushback 0;
				_wp = _group addwaypoint [_FirstWp,5];
				_wp setWaypointSpeed "LIMITED";
				{
					_x domove _FirstWp;
				} foreach (units _group);
			};
			_NearHouses = _NearHouses call Bis_fnc_ArrayShuffle;
			{
				if (!isnull _x) then {
					_wp = _group addwaypoint [_x,5];
					_wp setWaypointSpeed "LIMITED";
				};
			} foreach _NearHouses;
			if (count (waypoints _group) < 20) then {
				for "_1" from 1 to 20 do {
					_randomPos = [_pos,60,random 360] call BIS_fnc_relPos;
					_wp = _group addwaypoint [_randomPos,5];
					_wp setWaypointSpeed "LIMITED";
				};
			};
			_group setCurrentWaypoint [_group, 1];
		};
	};

	[] spawn {
		_Ryanzombiesdamage 				= getnumber (configfile >> "Epoch_ZedSpawner" >> "Ryanzombiesdamage");
		_Ryanzombieshealth 				= getnumber (configfile >> "Epoch_ZedSpawner" >> "Ryanzombieshealth");
		_ryanzombiesinfectedchance 		= getnumber (configfile >> "Epoch_ZedSpawner" >> "ryanzombiesinfectedchance");
		_ryanzombiesinfectedrate 		= getnumber (configfile >> "Epoch_ZedSpawner" >> "ryanzombiesinfectedrate");
		_ryanzombiesinfectedsymptoms 	= getnumber (configfile >> "Epoch_ZedSpawner" >> "ryanzombiesinfectedsymptoms");
		_ryanzombiesinfecteddeath 		= getnumber (configfile >> "Epoch_ZedSpawner" >> "ryanzombiesinfecteddeath");
		_ryanzombiesantivirusduration 	= getnumber (configfile >> "Epoch_ZedSpawner" >> "ryanzombiesantivirusduration");
		_ryanzombiesglow 				= getnumber (configfile >> "Epoch_ZedSpawner" >> "ryanzombiesglow");
		_Ryanzombieslimit 				= getnumber (configfile >> "Epoch_ZedSpawner" >> "Ryanzombieslimit");
		_NoZedAreas 					= getarray (configfile >> "Epoch_ZedSpawner" >> "NoZedAreas");
		_MaxOverallZeds 				= getnumber (configfile >> "Epoch_ZedSpawner" >> "MaxOverallZeds");
		_DeleteDistance 				= getnumber (configfile >> "Epoch_ZedSpawner" >> "DeleteDistance");
		_StuckOrDeadCheckTime 			= getnumber (configfile >> "Epoch_ZedSpawner" >> "StuckOrDeadCheckTime");
		_BlackListedVehicles 			= getarray (configfile >> "Epoch_ZedSpawner" >> "BlackListedVehicles");
		_ZedSpawnArr 					= getarray (configfile >> "Epoch_ZedSpawner" >> "ZedSpawnArr");
		_ZedClasses 					= getarray (configfile >> "Epoch_ZedSpawner" >> "ZedClasses");
		_ZedCheckTimer					= getnumber (configfile >> "Epoch_ZedSpawner" >> "ZedCheckTimer");

		_params = [
			_Ryanzombiesdamage,
			_Ryanzombieshealth,
			_ryanzombiesinfectedchance,
			_ryanzombiesinfectedrate,
			_ryanzombiesinfectedsymptoms,
			_ryanzombiesinfecteddeath,
			_ryanzombiesantivirusduration,
			_NoZedAreas,
			_MaxOverallZeds,
			_BlackListedVehicles,
			_ZedSpawnArr,
			_ZedCheckTimer
		];
		Epoch_ryanzombiesglow = _ryanzombiesglow;
		Ryanzombieslimit = _Ryanzombieslimit;
		ZedClasses = _ZedClasses;
		RZ_FaceArray = ["RyanZombieFace1_Glowing","RyanZombieFace2_Glowing","RyanZombieFace3_Glowing","RyanZombieFace4_Glowing","RyanZombieFace5_Glowing","RyanZombieFace6_Glowing"];

		_ZombieSpawn = compilefinal preprocessfilelinenumbers "Epoch_RyanZ_Spawner\ZedSpawner\Epoch_ZombieSpawn.sqf";
		[_params,_ZombieSpawn] remoteExec ["BIS_fnc_spawn", -2, "Epoch_ZedSpawner"];
		[] spawn _ZombieSpawn;

		_ZedCleanup = {
			params [["_target",objnull]];
			if !(MyZeds isEqualto []) then {
				_Zed = MyZeds deleteat 0;
				_del = (_Zed nearEntities _DeleteDistance) select {isplayer _x} isEqualto [];
				if !(_del) then {
					_Checktime = _Zed getvariable ["Epoch_RyanZ_StuckCheck",0];
					if (diag_ticktime > _Checktime) then {
						_LastPos = _Zed getvariable ["Epoch_RyanZ_LastPos",[0,0,0]];
						if ((getposATL _Zed) distance _lastpos < 2) exitwith {
							_del = true;				
						};
						_Zed setvariable ["Epoch_RyanZ_StuckCheck",diag_ticktime + _StuckOrDeadCheckTime];
					};
					if (_del) exitwith {};
					{
						if (_Zed distance2d _x < 150) exitwith {
							_del = true;				
						};
					} foreach (missionnamespace getvariable ["Epoch_PlotPoles",[]]);
					_Zed setvariable ["Epoch_RyanZ_LastPos",getposATL _Zed];
				};
				if (_del) then {
					deletevehicle _Zed;
				}
				else {
					MyZeds pushback _Zed;
				};
			};
		};
		_run2sec = diag_ticktime;
		while {true} do {
			if (diag_ticktime > _run2sec) then {
				[objnull] call _ZedCleanup;
				_run2sec = diag_ticktime + 2;
			};
			uisleep 0.5;
		};
	};
	diag_log "Epoch Debug: RyanZ Spawner Started";
};