disableserialization;
_display = finddisplay 9898;
call EPOCH_EPad_clearscreen;
_htmlctrl = (_display displayctrl 1901);
_htmlctrl ctrlshow true;
_html = "epoch_code\gui\scripts\e_pad\Apps\E_Pad.html";
_htmlctrl htmlLoad _html;