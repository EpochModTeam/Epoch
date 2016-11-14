/*
	Author: Andrew Gregory - EpochMod.com

    Contributors:

	Description:
	Create a local marker, with options.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/EPOCH_makeMarker.sqf

    Example:
    [player, position player, "ICON", "mil_dot", "ColorBlack", [0.7,0.7], "Border", 42, "Hi, I am a marker.. yay.", 0.6,"markerName"] call EPOCH_makeMarker

    Parameter(s):
		_this select 0: Target Object - Used if name not supplied
		_this select 1: ARRAY / OBJECT - Marker Position (Object should be acceptable)
		_this select 2 - 9: STRING(S) - Marker parameters.

	Returns:

*/
//[[[cog import generate_private_arrays ]]]
private ["_mName","_mrkr"];
//[[[end]]]
params [["_trgt", str(diag_tickTime)],["_mPos", position player],["_mShape","ICON"],["_mType","mil_dot"],["_mColor","ColorBlack"],["_mSize",[0.7,0.7]],["_mBrush",""],["_mDir",0],["_mText",""],["_mAlpha",1],["_mName",""]];
diag_log format["Epoch: DEBUG: Creating marker at %1 called %2 (Params:%3).", _mPos, _trgt, _this];

if(_mName == "")then{_mName = str(_trgt) + str(diag_tickTime);};
_mrkr = createMarkerLocal [_mName, _mPos];
_mName setMarkerShapeLocal _mShape;
_mName setMarkerTypeLocal _mType;
if!(_mText == "")then{_mName setMarkerTextLocal _mText;};
_mName setMarkerSizeLocal _mSize;
_mName setMarkerColorLocal _mColor;
if!(_mBrush == "")then{_mName setMarkerBrushLocal _mBrush;};
_mName setMarkerDirLocal _mDir;
_mName setMarkerAlphaLocal _mAlpha;
