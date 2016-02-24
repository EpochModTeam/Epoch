private["_unit"];

_unit = createAgent ["Construct_F", getPos player, [], 520, "FORM"];
{_unit disableAI _x}forEach["TARGET","AUTOTARGET","FSM"];
[_unit] execFSM "epoch_code\System\Construct_Brain.fsm";