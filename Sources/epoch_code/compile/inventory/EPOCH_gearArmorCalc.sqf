private ["_passThrough","_armor"];
_passThrough = getNumber(configFile >> "CfgWeapons" >> _this >> "ItemInfo" >> "passThrough");
_armor = getNumber(configFile >> "CfgWeapons" >> _this >> "ItemInfo" >> "armor");
([_passThrough,_armor] call EPOCH_factorArmor)
