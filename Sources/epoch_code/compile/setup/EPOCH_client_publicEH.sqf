/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Custom RE handler with random variables

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_code/compile/setup/EPOCH_client_publicEH.sqf

    Example:
    ["aset","agte","eage",...] call EPOCH_client_publicEH;

    Parameter(s):
		_this select 0: STRING - main random string to listen for events
		_this select 1+: random strings
	Returns:
	NOTHING

call compile ("
	EPOCH_"+(_this select 0)+" = {
		_data = (_this select 1);
		switch (_this select 0) do {
			case "+str(_this select 1)+": { EPOCH_bankBalance = _data; };
			case "+str(_this select 2)+": { Epoch_my_Group = []; Epoch_my_GroupUID = '' };
			case "+str(_this select 3)+": { Epoch_my_Group = _data; call EPOCH_Group_update };
			case "+str(_this select 4)+": { Epoch_my_GroupUID = _data };
			case "+str(_this select 5)+": { {missionNamespace setVariable[format['EPOCH_player%1', _x], EPOCH_defaultVars select(EPOCH_customVars find _x)]} forEach['Temp','Hunger','Thirst','Toxicity','Stamina','HitPoints','BloodP','Alcohol','Radiation']};
			case "+str(_this select 6)+": { EPOCH_TRADE_COMPLETE = _data };

		};
	};
");
*/
