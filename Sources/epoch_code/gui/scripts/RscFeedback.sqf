disableserialization;

_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {
	case "onLoad": {
		_display = _params select 0;
		_ctrlFeedback = _display displayctrl IDC_RSCFEEDBACK_RSCFEEDBACK;
		if ((productversion select 4) == "Development") then {
			_ctrlFeedback htmlLoad "a3\ui_f\data\html\RscFeedback.html";
		} else {
			_ctrlFeedback ctrlshow false;
		};
	};
};