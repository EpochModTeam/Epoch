//unregister dynamic IDCs

rmx_var_traderMenuActive = false;

(rmx_var_traderGroupCTRLs select 0) call epoch_getIDC;
(rmx_var_traderGroupCTRLs select 1) call epoch_getIDC;

{
	{
		_x call epoch_getIDC;
	} forEach _x;
}forEach rmx_var_traderLeftMenuCTRLs;

{
	{
		_x call epoch_getIDC;
	} forEach _x;
}forEach rmx_var_traderRightMenuCTRLs;

