private ["_display","_case","_colorHighlight","_bullet","_message","_yText1","_hText1","_positionTextField","_textField"];
_display = _this select 1 select 0;
_case = _this select 1 select 1;

_buttonSpoiler = _display displayctrl 2400;

[_display,"RscWelcomeEpoch"] call bis_fnc_guiEffectTiles;

_colorHighlight = ["GUI", "BCG_RGB"] call BIS_fnc_displayColorGet;
_colorHighlight = _colorHighlight call BIS_fnc_colorRGBtoHTML;

_bullet = "<t size='0.5' color='" + _colorHighlight + "'><img image='A3\Ui_f\data\IGUI\RscIngameUI\RscHint\indent_square' /></t>";
_message = "<br />";

switch _case do {
	case "Welcome": {
		_message = _message + "<t align='center' size='6' shadow='0'><img image='\x\addons\a3_epoch_code\Data\EpochLogo' /></t><br />";
		_message = _message + "<t color='" + _colorHighlight + "'>NEW TO EPOCH?</t><br />";
		_message = _message + "Epoch is a <t color='" + _colorHighlight + "'>open world survival mod</t> set in the year 2035, Just two years after the mass extinction of billions of people.
		Those that remain are left with remnants of a once technological society. Try to <t color='" + _colorHighlight + "'>survive, build, or explore</t> your way through the <t color='" + _colorHighlight + "'>harsh dynamic environment</t>.<br /><br />";

		_message = _message + _bullet + " Fully persistent open world with custom hive backend made just for A3 Epoch.<br />";
		_message = _message + _bullet + " Base building re-envisioned for Arma 3 PhysX. Persists exact position, direction, and angle.<br />";
		_message = _message + _bullet + " Persistent tracking of vehicles position, color, direction, and inventory.<br />";
		_message = _message + _bullet + " Random encounters with several different types of antagonists.<br />";
		_message = _message + _bullet + " Custom vehicles and weapons including melee weapons.<br />";
		_message = _message + _bullet + " Male and Female players with custom apparel.<br />";
		_message = _message + _bullet + " ​Explore and Loot: Wrecked ships, Abandoned vehicles and buildings, and more!<br /><br /><br />";
		_message = _message + "<t align='center' size='8' shadow='0'><img image='a3\missions_f_gamma\data\img\Faction_OPFOR_briefing_CA'/></t><br /><br />";

		_message = _message + "<t color='" + _colorHighlight + "'>EPOCH VETERAN?</t><br />";
		_message = _message + "As compared to Arma 2 Epoch, ...<br /><br />";
		_message = _message + _bullet + " Barter based economy backed by a crypto currency.<br />";
		_message = _message + _bullet + " Roaming and city based NPC traders.<br />";
		_message = _message + _bullet + " Improved base building with snap assisted placement.<br /><br />";

		_message = _message + "<t align='center' size='8' shadow='0'><img image='a3\missions_f_gamma\data\img\Faction_BLUFOR_briefing_CA' /></t><br /><br />";

		_message = _message + "More at www.epochmod.com<br /><br />";
		_message = _message + "Epoch Mod is currently in development by AWOL, Skaronator, Axeman, Sequisha, Fank and Kiory.<br /><br />";
	};
	case "Changelog": {

	};
	case "Custom": {
		if (!isNil "Epoch_customMessage") then {
			_message = Epoch_customMessage;
			Epoch_customMessage = nil;
		};
	};
};
_textField = _display displayCtrl 1100;
_textField ctrlSetStructuredText (parseText _message);
_positionTextField = ctrlPosition _textField;
_yText1 = _positionTextField select 1;
_hText1 = ctrlTextHeight _textField;

_textField ctrlSetPosition [_positionTextField select 0, _yText1, _positionTextField select 2, _hText1];
_textField ctrlcommit 0;

_buttonSpoiler ctrlShow false;
