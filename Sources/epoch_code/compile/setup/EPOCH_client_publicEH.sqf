call compile ("
	'"+(_this select 0)+"' addPublicVariableEventHandler {
		"+(_this select 0)+" = nil;
		_data = (_this select 1) select 1;
		switch ((_this select 1) select 0) do {
			case "+str(_this select 1)+": { _data call EPOCH_tradeRequest };
			case "+str(_this select 2)+": { _data call EPOCH_client_repairVehicle };
			case "+str(_this select 3)+": { [_data,true] call EPOCH_client_lockVehicle };
			case "+str(_this select 4)+": { [_data,false] call EPOCH_client_lockVehicle };
			case "+str(_this select 5)+": { _data call EPOCH_client_fillVehicle };
			case "+str(_this select 6)+": { _data call EPOCH_clientRevive };
			case "+str(_this select 7)+": { _data call EPOCH_client_earthQuake };
			case "+str(_this select 8)+": { _data call EPOCH_unitSpawnIncrease };
			case "+str(_this select 9)+": { (_data select 0) say3D (EPOCH_sounds select (_data select 1)) };
			case "+str(_this select 10)+": { (_data select 0) switchMove (_data select 1) };
			case "+str(_this select 11)+": { EPOCH_bankBalance = _data; };
			case "+str(_this select 12)+": { _data call EPOCH_effectCrypto  };
			case "+str(_this select 13)+": { Epoch_my_Group = []; Epoch_my_GroupUID = '' };
			case "+str(_this select 14)+": { _data spawn EPOCH_client_rejectPlayer };
			case "+str(_this select 15)+": { Epoch_my_Group = _data; call EPOCH_Group_update };
			case "+str(_this select 16)+": { Epoch_my_GroupUID = _data };
			case "+str(_this select 17)+": { _data call EPOCH_Group_invitePlayer };
			case "+str(_this select 18)+": { _data call EPOCH_handleServerMessage };
			case "+str(_this select 19)+": { {missionNamespace setVariable[format['EPOCH_player%1', _x], EPOCH_defaultVars select(EPOCH_customVars find _x)]} forEach['Temp','Hunger','Thirst','Toxicity','Stamina','HitPoints','BloodP']};
			case "+str(_this select 20)+": { _data call EPOCH_mission_returnObj };
		};
	};
");