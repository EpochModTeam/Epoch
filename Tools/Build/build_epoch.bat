@Echo Off
cls
color A
SETLOCAL ENABLEDELAYEDEXPANSION

For /F "Tokens=2* skip=2" %%A In ('REG QUERY "HKLM\SOFTWARE\WOW6432Node\Bohemia Interactive\addonbuilder" /v "Path"') Do (set TOOLS_PATH=%%B)
IF not DEFINED TOOLS_PATH ( 
	echo Arma 3 tools not found.
	goto end
)

SET CURRENT_PATH=%CD%
SET findWord=\Tools\Build
SET replaceWord=
SET MAIN_PATH=!CURRENT_PATH:%findWord%=%replaceWord%!
SET currentVersion="%MAIN_PATH%\version.txt"

SET currentBuild="%MAIN_PATH%\build.txt"
SET clientBuildInc="%MAIN_PATH%\Sources\epoch_config\build.hpp"
SET serverBuildInc="%MAIN_PATH%\Sources\epoch_server\build.hpp"
SET settingsBuildInc="%MAIN_PATH%\Sources\epoch_server_settings\build.hpp"
SET coreBuildInc="%MAIN_PATH%\Sources\epoch_server_core\build.hpp"

SET AB_includes_path="%CURRENT_PATH%\includes.txt"

:parse
IF "%~1"=="" GOTO endparse
IF "%~1"=="-build" (
	set choice=%~2
	GOTO endparse
)
SHIFT
GOTO parse
:endparse
REM ready for action!

:start
IF not DEFINED choice ( 
	ECHO ===============================================
	ECHO ==          Epoch Build Script v1.0          ==
	ECHO == 1. Build Server                           ==
	ECHO == 2. Build Settings                         ==
	ECHO == 3. Build Core                             ==
	ECHO == 4. Build All Maps                         ==
	ECHO == 5. Build Everything                       ==
	ECHO ===============================================
	set /p choice=Please select an option.
)
if '%choice%'=='' ECHO "%choice%" is not valid please try again
if '%choice%'=='1' (
	call :increaseBuild
	call :server
)
if '%choice%'=='2' (
	call :increaseBuild
	call :settings
)
if '%choice%'=='3' (
	call :increaseBuild
	call :core
)
if '%choice%'=='4' (
	call :increaseBuild
	call :allmaps
)
if '%choice%'=='5' (
	echo building Everything
	call :increaseBuild
	call :server
)
ECHO.
goto start
:increaseBuild
SET /p BUILDNUMBER=<%currentBuild%
SET /A BUILDNUMBER = BUILDNUMBER + 1
echo %BUILDNUMBER% > %currentBuild%
GOTO :EOF
:server
echo building server pbo
echo build=%BUILDNUMBER%; > !serverBuildInc!
SET SOURCE_PATH=%MAIN_PATH%\Sources\epoch_server
SET OUTPUT_PATH=%MAIN_PATH%\Server_Install_Pack\@EpochHive\addons
SET TEMP_PATH=x\addons\a3_epoch_server
rd /s/q p:\!TEMP_PATH!
xcopy /s/e/y/q/i "!SOURCE_PATH!" p:\!TEMP_PATH!
START "" /min /WAIT "!TOOLS_PATH!\AddonBuilder.exe" "P:\!TEMP_PATH!" "!OUTPUT_PATH!" -clear -prefix="!TEMP_PATH!" -project=P:\ -include=!AB_includes_path!
if '%choice%'=='5' (
	call :settings
) else (
	goto end
)
:settings
echo building settings pbo
echo build=%BUILDNUMBER%; > !settingsBuildInc!
SET SOURCE_PATH=%MAIN_PATH%\Sources\epoch_server_settings
SET OUTPUT_PATH=%MAIN_PATH%\Server_Install_Pack\@EpochHive\addons
SET TEMP_PATH=a3_epoch_server_settings
rd /s/q p:\!TEMP_PATH!
xcopy /s/e/y/q/i "!SOURCE_PATH!" p:\!TEMP_PATH!
START "" /min /WAIT "!TOOLS_PATH!\AddonBuilder.exe" "P:\!TEMP_PATH!" "!OUTPUT_PATH!" -packonly -clear -prefix="!TEMP_PATH!" -project=P:\ -include=!AB_includes_path!
if '%choice%'=='5' (
	call :core
) else (
	goto end
)
:core
echo building core pbo
echo build=%BUILDNUMBER%; > !coreBuildInc!
SET SOURCE_PATH=%MAIN_PATH%\Sources\epoch_server_core
SET OUTPUT_PATH=%MAIN_PATH%\Server_Install_Pack\@EpochHive\addons
SET TEMP_PATH=epoch_server_core
rd /s/q p:\!TEMP_PATH!
xcopy /s/e/y/q/i "!SOURCE_PATH!" p:\!TEMP_PATH!
START "" /min /WAIT "!TOOLS_PATH!\AddonBuilder.exe" "P:\!TEMP_PATH!" "!OUTPUT_PATH!" -clear -prefix="!TEMP_PATH!" -project=P:\ -include=!AB_includes_path!
if '%choice%'=='5' (
	call :allmaps
) else (
	goto end
)
:allmaps
echo building mpmissions pbo's	
echo build=%BUILDNUMBER%; > !clientBuildInc!
SET SOURCE_PATH=%MAIN_PATH%\Sources
SET OUTPUT_PATH=%MAIN_PATH%\Server_Install_Pack\MPMissions
for /f "tokens=*" %%G in ('dir /b /s /a:d "!SOURCE_PATH!\mpmissions\epoch.*"') do (
	SET MISSION=%%~nxG
	echo building !MISSION! pbo
	rd /s/q p:\!MISSION!
	rem Moving files into temp folder
	xcopy /s/e/y/q/i/d "!SOURCE_PATH!\mpmissions\!MISSION!" p:\!MISSION!
	xcopy /s/y/q/i/f "!SOURCE_PATH!\description.ext" p:\!MISSION!
	xcopy /s/e/y/q/i/d "!SOURCE_PATH!\epoch_code" p:\!MISSION!\epoch_code
	xcopy /s/e/y/q/i/d "!SOURCE_PATH!\epoch_config" p:\!MISSION!\epoch_config	
	START "" /min /WAIT "!TOOLS_PATH!\AddonBuilder.exe" "P:\!MISSION!" "!OUTPUT_PATH!" -clear -prefix=\ -project=P:\ -include=!AB_includes_path!
)
goto end
:end
pause
exit
