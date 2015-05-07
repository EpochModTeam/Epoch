@echo off

:::::::::::::: CONFIG ::::::::::::::::::

:: Set your Arma3 Epoch Base installation directory. LEAVE OFF THE ENDING \
set arma3srvpath=C:\Program Files (x86)\Steam\SteamApps\common\Arma 3

:: Set your Default server profile name. This is the name of the directory that stores your server.cfg
:: This will be used in the case that you don't launch this script without the server param.
:: Example: SC, US6, Chicago13, ect
:: DEFAULTPROFILE
set srvname=SC
:: Delete Original log files after they have been rotated? This keeps your logs more organized and saves space.
:: This will not work unless the server is stopped first. This option works best set to 1 when using FireDaemon's Pre/Post Service tab
set deloriglogs=1

::::::::::: ADVANCED CONFIG ::::::::::::
:: Don't touch anything below this point unless you know what your doing.

:: Setting Server Profile to Use
IF "%1"=="" (
set servername=%srvname%
) else (
set servername=%1
)

TITLE  ArmaIII Epoch %servername% Server Log Rotater

:: Set Debug Mode
set debug=0
:: Set Debug Timeout in seconds
set dbsecs=10

::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
:::::::::::::::::::::::::::  STOP EDITING ::::::::::::::::::::::::::::::::::::::
::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

:: Display Debug output
if %debug% == 1 (
echo Server Name = %servername%
echo ArmaIII Server Path = "%arma3srvpath%"
timeout %dbsecs%
)

:: Set Time and Date
SET HOUR=%time:~0,2%
SET dtStamp9=%date:~-4%%date:~4,2%%date:~7,2%_0%time:~1,1%%time:~3,2%_%time:~6,2%
SET dtStamp24=%date:~-4%%date:~4,2%%date:~7,2%_%time:~0,2%%time:~3,2%_%time:~6,2%
::Make Date Stamp
if "%HOUR:~0,1%" == " " (SET dtStamp=%dtStamp9%) else (SET dtStamp=%dtStamp24%)
ECHO Todays Date and time (%date%)(%time%) / %dtStamp%
if %debug% == 1 (
timeout %dbsecs%
)

echo (%date%) (%time%) Starting Log Rotation.

:: Make the Rotated Log Directorys
if exist "%arma3srvpath%\%servername%\RotatedLogs" goto maketsdir
mkdir "%arma3srvpath%\%servername%\RotatedLogs"
:maketsdir
if exist "%arma3srvpath%\%servername%\RotatedLogs\%dtStamp%" goto makebedir
mkdir "%arma3srvpath%\%servername%\RotatedLogs\%dtStamp%"
:makebedir
if exist "%arma3srvpath%\%servername%\RotatedLogs\%dtStamp%\BattlEye" goto rotatelogs
mkdir "%arma3srvpath%\%servername%\RotatedLogs\%dtStamp%\BattlEye"

if exist "%arma3srvpath%\DBbackups\RotatedLogs\%dtStamp%\DBbackups" goto rotatelogs
mkdir "%arma3srvpath%\DBbackups\RotatedLogs\%dtStamp%\DBbackups"

:rotatelogs
:: Starting Log Rotation. If there are any other logs, just follow the format below, and make sure to NOT touch any of the varibles.
copy "%arma3srvpath%\%servername%\BattlEye\scripts.log" "%arma3srvpath%\%servername%\RotatedLogs\%dtStamp%\BattlEye\scripts.log"
copy "%arma3srvpath%\%servername%\BattlEye\createvehicle.log" "%arma3srvpath%\%servername%\RotatedLogs\%dtStamp%\BattlEye\createvehicle.log"
copy "%arma3srvpath%\%servername%\BattlEye\deletevehicle.log" "%arma3srvpath%\%servername%\RotatedLogs\%dtStamp%\BattlEye\deletevehicle.log"
copy "%arma3srvpath%\%servername%\BattlEye\attachto.log" "%arma3srvpath%\%servername%\RotatedLogs\%dtStamp%\BattlEye\attachto.log"
copy "%arma3srvpath%\%servername%\BattlEye\publicvariable.log" "%arma3srvpath%\%servername%\RotatedLogs\%dtStamp%\BattlEye\publicvariable.log"
copy "%arma3srvpath%\%servername%\BattlEye\remoteexec.log" "%arma3srvpath%\%servername%\RotatedLogs\%dtStamp%\BattlEye\remoteexec.log"
copy "%arma3srvpath%\%servername%\BattlEye\selectplayer.log" "%arma3srvpath%\%servername%\RotatedLogs\%dtStamp%\BattlEye\selectplayer.log"
copy "%arma3srvpath%\%servername%\BattlEye\setpos.log" "%arma3srvpath%\%servername%\RotatedLogs\%dtStamp%\BattlEye\setpos.log"
copy "%arma3srvpath%\%servername%\BattlEye\setvariable.log" "%arma3srvpath%\%servername%\RotatedLogs\%dtStamp%\BattlEye\setvariable.log"
copy "%arma3srvpath%\%servername%\BattlEye\setdamage.log" "%arma3srvpath%\%servername%\RotatedLogs\%dtStamp%\BattlEye\setdamage.log"
copy "%arma3srvpath%\%servername%\BattlEye\addmagazinecargo.log" "%arma3srvpath%\%servername%\RotatedLogs\%dtStamp%\BattlEye\addmagazinecargo.log"
copy "%arma3srvpath%\%servername%\BattlEye\addbackpackcargo.log" "%arma3srvpath%\%servername%\RotatedLogs\%dtStamp%\BattlEye\addbackpackcargo.log"
copy "%arma3srvpath%\%servername%\BattlEye\addweaponcargo.log" "%arma3srvpath%\%servername%\RotatedLogs\%dtStamp%\BattlEye\addweaponcargo.log"
copy "%arma3srvpath%\%servername%\BattlEye\mpeventhandler.log" "%arma3srvpath%\%servername%\RotatedLogs\%dtStamp%\BattlEye\mpeventhandler.log"
::copy "%arma3srvpath%\dump.rdb" "%arma3srvpath%\DBbackups\RotatedLogs\%dtStamp%\DBbackups\dump.rdb"
copy "%arma3srvpath%\DB\dump.rdb" "%arma3srvpath%\DBbackups\RotatedLogs\%dtStamp%\DBbackups\dump.rdb"
copy "%arma3srvpath%\%servername%\A3Master_*.log" "%arma3srvpath%\%servername%\RotatedLogs\%dtStamp%\A3Master_*.log"
copy "%arma3srvpath%\%servername%\arma3server_*.rpt" "%arma3srvpath%\%servername%\RotatedLogs\%dtStamp%\arma3server_*.rpt"


echo (%date%) (%time%) Logs are backed up now...
echo (%date%) (%time%) Removing original log files.
del /Q /F "%arma3srvpath%\%servername%\BattlEye\scripts.log"
del /Q /F "%arma3srvpath%\%servername%\BattlEye\createvehicle.log"
del /Q /F "%arma3srvpath%\%servername%\BattlEye\attachto.log"
del /Q /F "%arma3srvpath%\%servername%\BattlEye\deletevehicle.log"
del /Q /F "%arma3srvpath%\%servername%\BattlEye\selectplayer.log"
del /Q /F "%arma3srvpath%\%servername%\BattlEye\publicvariable.log"
del /Q /F "%arma3srvpath%\%servername%\BattlEye\remoteexec.log"
del /Q /F "%arma3srvpath%\%servername%\BattlEye\setpos.log"
del /Q /F "%arma3srvpath%\%servername%\BattlEye\setvariable.log"
del /Q /F "%arma3srvpath%\%servername%\BattlEye\addmagazinecargo.log"
del /Q /F "%arma3srvpath%\%servername%\BattlEye\addbackpackcargo.log"
del /Q /F "%arma3srvpath%\%servername%\BattlEye\addweaponcargo.log"
del /Q /F "%arma3srvpath%\%servername%\BattlEye\mpeventhandler.log"
del /Q /F "%arma3srvpath%\%servername%\BattlEye\setdamage.log"
del /Q /F "%arma3srvpath%\%servername%\A3Master_*.log"
del /Q /F "%arma3srvpath%\%servername%\arma3server_*.rpt"

if %debug% == 1 (
timeout %dbsecs%
)

:: Done
exit