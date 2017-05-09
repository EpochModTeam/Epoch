//[[[cog import generate_private_arrays ]]]
private ["_nameArr","_newName","_nrMn","_responseArr","_trader","_trdrCurrName"];
//[[[end]]]
_trader = objNull;
_nrMn = nearestObjects [player, ["C_Man_1"], 16];
_trader = _nrMn select 0;
if(_trader getVariable ["traderName",""]== "")then{
_nameArr = ["Aaron Clark","Kenneth Bente","Damian Clark","Raimonds Virtoss","Richie","Paden Sturtevant","Darren Harrison","Paul Tomany","Dan","Darren Harrison","Niklas Wagner","Andrew Gregory","Isaac Gregory","Florian Kinder","Denis Erygin","Alan Denham"];
_trdrCurrName = name _trader;
if((random 100) < 6 && !(_trdrCurrName in _nameArr))then{
_newName = selectRandom _nameArr;
_trader setName _newName;
_trader setVariable ["traderName",_newName, true];
};

};
_responseArr = ["I don't know. You can only be regenerated so many times before the memory starts to go..","You again..! Go bother someone else.",format["There was a time when names mattered, call me %1.",name _trader],"My name..? What does it matter.","Hey buddy you rock up here unannounced and suddenly we're friends ? On your bike if you aren't buying or selling.",format["My name.. I am known as %1",name _trader], format["When names mattered I was called %1",name _trader],"I forget.. At least, I try to forget."];
[selectRandom _responseArr, 5] call Epoch_message;
