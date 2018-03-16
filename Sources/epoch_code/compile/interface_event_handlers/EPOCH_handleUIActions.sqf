/*
	Author: DirtySanchez - ported from DonkeyPunch eXpoch http://DonkeyPunch.INFO

    Contributors:
	
	Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/interface_event_handlers/EPOCH_handleUIActions.sqf
*/
private['_msg', '_type', '_disableSlingLoad', '_slung'];
params [
	['_actionObj',objNull],
	['_player',objNull],
	['_index',0],
	['_actionName',''],
	['_actionDisplayName',''],
	['_priority',1],
	['_showWindow',false],
	['_hideOnUse',true],
	['_shortCut',''],
	['_visibility',false],
	['_eventName','']
];
_blocked = false;
_msg = '';
_type = typeOf _actionObj;
_config = 'CfgEpochClient' call EPOCH_returnConfig;
switch(_actionName)do{
	case 'FireInflame': {
		if (["CfgEpochClient", "ActionFireOnLighter", true] call EPOCH_fnc_returnConfigEntryV2) then {
			if!('lighter_epoch' in magazines player) then {
				_msg = 'You need a lighter';
				_blocked = true;
			}else{
				[player,'lighter_epoch',-5] call EPOCH_usedItemRepack;
				//[_actionObj] remoteExec ['EPOCH_server_addToFireSystem',2];
			};
		};
	};
	case 'FirePutDown': {
		if (["CfgEpochClient", "ActionBurnBarrelOffExtinguisher", true] call EPOCH_fnc_returnConfigEntryV2) then {
			if(_type isEqualTo 'BurnBarrel_EPOCH')then{
				if!('ItemFireExtinguisher' in magazines player) then {
					_msg = 'You need an extinguisher';
					_blocked = true;
				}else{
					[player,'ItemFireExtinguisher',-1] call EPOCH_usedItemRepack;
				};
			};
		};
	};
	case 'HookCargo': {
		if(EPOCH_ArmaSlingLoad)then{
			if (["CfgEpochClient", "ActionHookRope", true] call EPOCH_fnc_returnConfigEntryV2) then {
				if(driver vehicle player isEqualTo player)then{
					_slung = ropeAttachedObjects vehicle player;
					if(_slung isEqualTo [])then{
						if!('ItemRope' in magazines player) then {
							_msg = 'You need rope to hook';
							_blocked = true;
						}else{
							player removeItem 'ItemRope';
						};
					}else{
						player addItem 'ItemRope';
					};
				};
			};
		}else{
			_msg = 'Hook Malfunction, overrode by R3F or AdvSlingLoad';
			_blocked = true;
		};
	};
	case 'UnhookCargo': {
		if(EPOCH_ArmaSlingLoad)then{
			if (["CfgEpochClient", "ActionHookRope", true] call EPOCH_fnc_returnConfigEntryV2) then {
				player addItem 'ItemRope';
			};
		}else{
			_msg = 'Unhook Malfunction, overrode by R3F or AdvSlingLoad';
			_blocked = true;
		};
	};
};
if!(_msg isEqualTo '')then{
	[_msg,5,[[0,0,0,0.2],[1,1,1,1]]] call Epoch_message_stack;
};
_blocked