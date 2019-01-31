_config = 'CfgEpochClient' call EPOCH_returnConfig;
_blacklist = (getArray(_config >> worldname >> 'blockedArea'));
if (isnil "Epoch_BlockedMarkeron") then {
	Epoch_BlockedMarkeron = false;
};
if (Epoch_BlockedMarkeron) then {
	{
		_x params ["_mPos","_size"];
		_mName = format ["blockedmarker_%1",_mPos];
		deleteMarkerlocal _mName;
	} foreach _blacklist;
	["Blocked Areas are now removed from your Map",5] call Epoch_Message;
}
else {
	_mShape = 'ELLIPSE';
	_mColor = 'ColorRed';
	_mBrush = 'Grid';
	_mAlpha = 0.8;
	{
		_x params ["_mPos","_size"];
		_msize = [_size,_size];
		_mName = format ["blockedmarker_%1",_mPos];
		_mrkr = createMarkerLocal [_mName, _mPos];
		_mName setMarkerShapeLocal _mShape;
		_mName setMarkerSizeLocal _mSize;
		_mName setMarkerColorLocal _mColor;
		_mName setMarkerBrushLocal _mBrush;
		_mName setMarkerAlphaLocal _mAlpha;
	} forEach _blacklist;
	["Blocked Areas are now shown on your Map",5] call Epoch_Message;
};
