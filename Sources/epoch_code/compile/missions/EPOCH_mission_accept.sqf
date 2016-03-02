_index = lbValue[1500, lbCurSel 1500];

_config = "MissionList" call EPOCH_returnConfig;
_disabledMissions = getArray(_config >> "traderMissionDisabled");
if (_index in _disabledMissions) exitWith{ titleText["Invalid Mission", "PLAIN", 3]; };

_nrEnts = player nearEntities ["Man", 20];
_trader = objNull;
{
	if ((_x getVariable ["AI_SLOT", -1 ] > -1)) exitWith {
		_trader = _x;
	};
}forEach _nrEnts;

if !(isNull _trader) then {
	switch _index do {
		case 0:	{
				[player,_trader] execFSM "\x\addons\a3_epoch_code\System\Trader_Missions_Delivery.fsm";
		};
		case 1:	{
				[player,_trader] execFSM "\x\addons\a3_epoch_code\System\Trader_Missions_Animal_Control.fsm";
		};
		case 2:	{
				[player,_trader] execFSM "\x\addons\a3_epoch_code\System\Trader_Missions_UAV.fsm";
		};
		case 3:	{
				[] execFSM "\x\addons\a3_epoch_code\System\Trader_Missions_VIP.fsm";
		};
		case 4:	{
				_formatMsg = format["<t size='0.8' shadow='0' color='#99ffffff'>The time is %1:%2.</t>",date select 3, date select 4];
				_dt = [_formatMsg, 0, 1, 6, 2, 0, 1] spawn bis_fnc_dynamictext;
		};
		case 5:	{
				_players = [];
				_playersOut = [];
				_grpWith = false;
				_msg = "Apart from you";
				_grp = group player;
				_players = nearestObjects [player, ["Epoch_Man_base_F","Epoch_Female_base_F"], 750];
				_players = _players - [player];
					{
						if!(group _x == _grp)then{
						_playersOut pushBack _x;
						}else{
						_grpWith = true;
						};
					} forEach _players;

					if(_grpWith)then{
					_msg = "Apart from your team and you";
					};
				_trdrMsg = format["%2 %1, I haven't seen anybody for a while.",name player,_msg];

					if (count _playersOut > 0) then {
						_player = selectRandom _playersOut;
						_trdrMsg = format["The last person picked up by the UAV was %1.",name _player];
					};
				_dt = [format["<t size='0.8' shadow='0' color='#99ffffff'>%1</t>",_trdrMsg], 0, 1, 6, 2, 0, 1] spawn bis_fnc_dynamictext;
		};
		case 6:
				{
				_newsArr = ["My dog was shot. That made me sad.","Business has been quiet since word got out that sappers are in the area.","Looters are expecting too much crypto for all the junk they bring in.","What do I look like ? A newspaper vendor. Go Away.","The sun came up again this morning.. That's good news I suppose.","Keep your dog fed with raw or cooked carcasses.","Sappers are known to be good for their pelts. Just don't get too close to one","Some very strange rumours that a Construct was seen in the mountains. Those things are just bedtime stories to scare kids with.","UAVs are a good source of components.","Some say this town is haunted by malevolent spirits.","I hear the military are helping survivors with air drops. Your loot is always welcome here if you find one.","Jammers seem to scare away some of the bad.. things.","Help Military Support Crew spot you with smoke or chemlights.","Hmm, have heard bar stories of a new monster on the loose. You watch yourself out there."];
				_config = 'CfgEpochClient' call EPOCH_returnConfig;
				_customNews = getArray(_config >> "EPOCH_news");
					if(count _customNews > 0)then{
						{
						_newsArr pushBack _x;
						} forEach _customNews;
					};
				_formatMsg = format["<t size='0.8' shadow='0' color='#99ffffff'>%1</t>",selectRandom _newsArr];
				_dt = [_formatMsg, 0, 1, 6, 2, 0, 1] spawn bis_fnc_dynamictext;
		};
		case 7:	{
				_responseArr = ["My name..? What does it matter.","Hey buddy you rock up here unannounced and suddenly we're friends ? On your bike if you aren't buying or selling.",format["My name.. I am known as %1",name _trader], format["When names mattered I was called %1",name _trader],"I forget.. At least, I try to forget."];
				_formatMsg = format["<t size='0.8' shadow='0' color='#99ffffff'>%1</t>",selectRandom _responseArr];
				_dt = [_formatMsg, 0, 1, 6, 2, 0, 1] spawn bis_fnc_dynamictext;
				};
		case 8:	{
				"Epoch_Sapper_F" call EPOCH_unitSpawn;
		};
		case 9:	{
				call EPOCH_spawn_looters;
		};
		default {
				_dt = ["Quit your jabbering and get the hell out of here.", 0, 1, 6, 2, 0, 1] spawn bis_fnc_dynamictext;
		};
	};

} else {
	titletext["Trader Lost. Goodbye.", "PLAIN DOWN", 3];
};
