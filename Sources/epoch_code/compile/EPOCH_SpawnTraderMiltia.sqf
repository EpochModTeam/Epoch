//Make _trgt = trader and join militia to traders group
_trgt = player;
_nrBuilds = nearestObjects [getPosATL _trgt,["house"],50];

_grp = createGroup RESISTANCE;
for "_i" from 1 to 3 step 1 do
{
	_startPos = [];
    while {count _startPos < 1} do {
    _garrCount = 0;
    _rndHouse = _nrBuilds select (floor random(count _nrBuilds));

        while {format ["%1", _rndHouse buildingPos (_garrCount)] != "[0,0,0]" } do {
        _garrCount = _garrCount + 1;
        };

        if (_garrCount > 0) then {
            _startPos = _rndHouse buildingPos (floor random _garrCount);
        };
    };

	_unit = _grp createUnit["B_G_Soldier_F", _startPos, [], 0, "CAN_COLLIDE"];
	_unit addEventHandler ["FiredNear", "group (_this select 0) setVariable[""shotsFired"",[(_this select 1),(_this select 2)]]"];	
	_unit addEventHandler ["Killed", "group (_this select 0) setVariable[""killer"",_this select 1]"];
	[_unit] execFSM "\x\addons\a3_epoch_code\System\Trader_Militia.fsm";
};
