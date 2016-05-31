/*
	Author: Andrew Gregory - EpochMod.com

    Contributors:

	Description:
	Create a local marker, with options.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/master/Sources/epoch_code/compile/functions/EPOCH_fnc_createMarker.sqf

    Example:
    [player, position player, "ICON", "mil_dot", "Hi, I am a marker.. yay.", "ColorRed", [0.7,0.7], "Border", 42, 0.6] call EPOCH_fnc_createMarker

    Parameter(s):
		_this select 0: ANY - Marker name.
		_this select 1: ARRAY / OBJECT - Marker Position (Object should be acceptable)
		_this select 2 - 9: STRING(S) - Marker parameters.

	Returns:

*/
_paramres = params [["_trgt", str(diag_tickTime)],["_mPos", position player],["_mShape","ICON"],["_mType","mil_dot"],["_mColor","ColorBlack"],["_mSize",[0.7,0.7]],["_mBrush",""],["_mDir",0],["_mText",""],["_mAlpha",1],["_mName",""]];
diag_log format["Epoch: ADMIN: Creating marker at %1 called %2 (Params:%3).", _mPos, _trgt, _paramres];

if(_mName == "")then{_mName = str(_trgt) + str(diag_tickTime);};
_mrkr = createMarkerLocal [_mName, _mPos];
_mrkr setMarkerShapeLocal _mShape;
_mrkr setMarkerTypeLocal _mType;
if!(_mText=="")then{_mrkr setMarkerTextLocal _mText;};
_mrkr setMarkerSizeLocal _mSize;
_mrkr setMarkerColorLocal _mColor;
if!(_mBrush == "")then{_mrkr setMarkerBrushLocal _mBrush;};
_mrkr setMarkerDirLocal _mDir;
_mrkr setMarkerAlphaLocal _mAlpha;