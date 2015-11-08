//
_playerObject = _this select 0;
if !(alive player && alive _playerObject && !isPlayer _playerObject) then {
	_ply = player;
	_group = group player;
	selectPlayer _playerObject;
	deleteVehicle _ply;
	// deleteGroup _group;

	Epoch_canBeRevived = false;

	Epoch_personalToken = _this select 1;

	// call EPOCH_clientInit;
	[] spawn EPOCH_masterLoop_v2;
	[5, 100] call EPOCH_niteLight;

	closeDialog 0;
	("BIS_fnc_respawnCounter" call BIS_fnc_rscLayer) cutText ["","PLAIN"];

	player addEventHandler ["Respawn", {(_this select 0) call EPOCH_clientRespawn}];
	player addEventHandler ["Put", {(_this select 1) call EPOCH_interact;_this call EPOCH_PutHandler}];
  player addEventHandler ["Take", {(_this select 1) call EPOCH_interact;_this call EPOCH_UnisexCheck}];
	player addEventHandler ["InventoryClosed", { if !(EPOCH_arr_interactedObjs isEqualTo[]) then{EPOCH_arr_interactedObjs remoteExec["EPOCH_server_save_vehicles", 2]; EPOCH_arr_interactedObjs = []; }; }];
	player addEventHandler ["InventoryOpened", {_this spawn EPOCH_initUI; (locked (_this select 1) in [2, 3] || (_this select 1) getVariable["EPOCH_Locked", false]) }];
  player addEventHandler ["Fired", {_this call EPOCH_fnc_playerFired}];
  player addEventHandler ["Killed", {_this call EPOCH_fnc_playerDeath}];
} else {
	deleteVehicle _playerObject;
};

true call EPOCH_pushCustomVar;
