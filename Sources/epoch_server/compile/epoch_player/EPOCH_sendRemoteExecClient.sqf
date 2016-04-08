// input
/*
1 = _remoteExecClient_NAMES
2 = _rnd_strings_REC
3 = _skn_PVC_INDEX
*/

private '_index';
_index = %1 find (_this select 0 select 0);
if (_index != -1) then {
	[%2 select _index, _this select 0 select 1] remoteExec ['EPOCH_%3',(_this select 1)];
};
