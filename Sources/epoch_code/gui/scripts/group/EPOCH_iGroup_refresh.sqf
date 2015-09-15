if !(Epoch_invited_GroupUIDs isEqualTo Epoch_invited_GroupUIDsPrev) then {
	Epoch_invited_GroupUIDsPrev = Epoch_invited_GroupUIDs;
	lbClear 1500;
	{
		_index = lbAdd[1500, _x select 1];
		lbSetData[1500, _index, _x select 0];
	} forEach Epoch_invited_GroupUIDs;
	//hint str(Epoch_invited_GroupUIDs);
};