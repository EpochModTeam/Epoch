@echo on
setlocal

rd P:\temp /s /q

SET bin=D:\SteamLibrary\SteamApps\common\Arma 3 Tools\AddonBuilder
SET arma=E:\Steam\SteamApps\common\Arma 3
SET patch=E:\Steam\SteamApps\common\Arma 3\x\addons
SET modPath=%arma%\@EpochDev\Addons
SET devPath=%arma%\@EpochDevTools\Addons

:: Array
SET list=epoch_code epoch_config a3_epoch_language
SET devlist=rmx_init rmx_sandbox
:: Loops trough array and makes PBO if folder exists
for %%i in (%list%) do (
	IF EXIST %patch%\%%i (
		"%bin%\AddonBuilder.exe" "%patch%\%%i" "%patch%"  -prefix="x\addons\a3_%%i" -include=F:\includes.txt -temp=P:\temp -packonly
	)
)
for %%i in (%devlist%) do (
	IF EXIST %patch%\%%i (
		"%bin%\AddonBuilder.exe" "%patch%\%%i" "%patch%"  -prefix="x\addons\%%i" -include=F:\includes.txt -temp=P:\temp -packonly
	)
)

for %%i in (%devlist%) do (
	move /Y "%patch%\%%i.pbo" "%devPath%"
)

::for %%i in (%list%) do (
::	rename "%patch%\%%i.pbo" "a3_%%i.pbo"
::)

move /Y "%patch%\*.pbo" "%modPath%"

set IP=192.168.1.100
set PORT=2302

rem timeout 3
rem start "MP" "%arma%\arma3.exe" -connect=%IP% -port=%PORT%  -filePatching -window -mod=@EpochExperimental;@EpochDevLibs; -malloc=system -skipintro -noSplash -noPause -world=empty -showScriptErrors -password=test123
@exit