_object = _this;
_type = typeof _object;
if (({alive _x && isplayer _x} count (_object nearentities 6)) > 1) exitwith {
	["You should not defuse Bombs next to other Players!",5] call Epoch_Message; 
};
player playMove 'AinvPknlMstpSnonWrflDnon_medic0';
player playMove 'AinvPknlMstpSnonWrflDnon_medicEnd';
_object say3d 'vehicle_repair';
uisleep 5;
if (alive player && !isnull _object) then {
	_reward = gettext (configfile >> "cfgammo" >> _type >> "defaultMagazine");
	if !(_reward isequalto "") then {
		_chance = ["CfgEpochClient", "DefuseBombChance", 0.4] call EPOCH_fnc_returnConfigEntryV2;
		if (_chance >= ((random 100) / 100)) then {
			deletevehicle _object;
			_reward call EPOCH_fnc_addItemOverflow;
			[format ['Sucessfully defused %1 - You have it now in your Inventory',_reward call Epoch_ItemDisplayName],5] call Epoch_Message;
		}
		else {
				['Oh No... The Bomb will explode in a few seconds... RUN!!!!',5] call Epoch_Message; 
				for '_i' from 1 to 6 do {
					playSound3D ['a3\sounds_f\air\heli_attack_02\alarm.wss', player, false,getposasl _object, 1, 1, 300];
					uisleep 1;
				};
				'HelicopterExploSmall' createVehicle (position _object);
				deletevehicle _object;
		};
	}
	else {
		[format ['Sorry, can not defuse %1',_type],5] call Epoch_Message;
	};
};	

