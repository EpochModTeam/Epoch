switch EPOCH_modKeys do {
case [true,false,false]:{rmx_var_favBar_current = rmx_var_favBar_MShift;};
case [false,true,false]:{rmx_var_favBar_current = rmx_var_favBar_MCtrl;};
case [false,false,true]:{rmx_var_favBar_current = rmx_var_favBar_MAlt;};
default {rmx_var_favBar_current = rmx_var_favBar_MNone;};
};
call epoch_favBar_drawCurrent;
call epoch_favBar_refresh;
true 