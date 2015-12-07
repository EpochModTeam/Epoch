private ["_item","_data","_index","_control","_filterArray","_weapons","_magazines","_items","_sizeOut","_arrayMags","_arrayWeapons"];

disableSerialization;

_control = _this select 0;
_index = _this select 1;

// [weapons, mags, items]
_filterArray = [
	[true,true,true], 	// all
	// [true,false,false], // weapons only
	[false,true,false], // mags only
	[false,false,true]  // items only
];

lbClear 1500;

// _weapons = ((_filterArray select _index) select 0);
_magazines = ((_filterArray select _index) select 1);
_items = ((_filterArray select _index) select 2);

_sizeOut = lbSize 1501;
_array = [];
if (_sizeOut > 0) then {
	for "_i" from 0 to (_sizeOut - 1) do {
		_item = lbData [1501, _i];
		_array pushBack _item;
	};
};
/*
if (_weapons) then {
	{
		if !(_x in _array) then {
			_index = lbAdd [1500, _x call EPOCH_itemDisplayName];
			lbSetData [1500, _index, _x];
			lbSetPicture [1500, _index, _x call EPOCH_itemPicture];
		} else {
			_array set [_array find _x,nil];
		};
	} forEach weapons player;
};
*/
if (_magazines) then {
	{
		if (getNumber(configfile >> "CfgMagazines" >> _x >> "count") == 1) then {
			if !(_x in _array) then {
				_index = lbAdd[1500, _x call EPOCH_itemDisplayName];
				lbSetData[1500, _index, _x];
				lbSetPicture[1500, _index, _x call EPOCH_itemPicture];
			}
			else {
				_array set[_array find _x, nil];
			};
		};
	} forEach magazines player;
};

if (_items) then {
	{
		if !(_x in _array) then {
			_index = lbAdd [1500, _x call EPOCH_itemDisplayName];
			lbSetData [1500, _index, _x];
			lbSetPicture [1500, _index, _x call EPOCH_itemPicture];
		} else {
			_array set [_array find _x,nil];
		};
	} forEach items player;
};
