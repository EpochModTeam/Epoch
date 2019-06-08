_string = "";
{
	_x params ["_BuildingType","_LootArray"];
	if (_foreachindex > 0) then {
		_string = _string + "
";
	};
	_string = _string + "class " + _BuildingType + " : Default
{";
	{
		_x params ["_loottype","_positionsarray"];
		_postype = switch _loottype do {
			case "Bunk_EPOCH": {"bedPos"};
			case "Shelf_EPOCH": {"shelfPos"};
			case "Fridge_EPOCH": {"fridgePos"};
			case "Bed_EPOCH": {"bedPos"};
			case "Couch_EPOCH": {"couchPos"};
			case "wardrobe_epoch": {"wardrobePos"};
			case "cooker_epoch": {"cookerPos"};
			case "Chair_EPOCH": {"chairPos"};
			case "ChairRed_EPOCH": {"chairPos"};
			case "Filing_EPOCH": {"filingPos"};
			case "Pelican_EPOCH": {"pelicanPos"};
			case "Table_EPOCH": {"tablePos"};
			case "locker_epoch": {"lockerPos"};
			case "ToolRack_EPOCH": {"toolRackPos"};
			case "Shoebox_EPOCH": {"shoeboxPos"};
			case "Tarp_EPOCH": {"palletPos"};
			case "Freezer_EPOCH": {"freezerPos"};
			case "Cabinet_EPOCH": {"cabinetPos"};
			case "toilet_epoch": {"toiletPos"};
			case "KitchenSink_epoch": {"kitchenSinkPos"};
			default {systemchat _loottype};
		};
		_string = _string + "
" + "    " + _postype + "[] = {";
		{
			_x params ["_pos","_dir"];
			if (_foreachindex > 0) then {
				_string = _string + ",";
			};
			_string = _string + "{{";
			_string = _string + str (_pos select 0);
			_string = _string + ",";
			_string = _string + str (_pos select 1);
			_string = _string + ",";
			_string = _string + str (_pos select 2);
			_string = _string + "},";
			_string = _string + str _dir;
			_string = _string + "}";
		} foreach _positionsarray;
		_string = _string + "};";
	} foreach _LootArray;
	_string = _string + "
};";
} foreach Lootarray;
LootarrayStr = _string;
copytoclipboard LootarrayStr;
