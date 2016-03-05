@Echo Off
rem Building server Pbos...
SETLOCAL ENABLEDELAYEDEXPANSION

For /F "Tokens=2* skip=2" %%A In ('REG QUERY "HKEY_LOCAL_MACHINE\SOFTWARE\WOW6432Node\Bohemia Interactive\addonbuilder" /v "Path"') Do (set TOOLS_PATH=%%B)
IF not DEFINED TOOLS_PATH ( echo "Arma 3 tools not found." )

SET CURRENT_PATH=%CD%
SET findWord=\Tools\Build
SET replaceWord=
SET MAIN_PATH=!CURRENT_PATH:%findWord%=%replaceWord%!
SET currentVersion="%MAIN_PATH%\version.txt"
SET currentBuild="%MAIN_PATH%\currentBuild.txt"
SET currentBuildInc="%MAIN_PATH%\Sources\epoch_config\build.hpp"
SET AB_includes_path="%CURRENT_PATH%\includes.txt"

rem Increase build number
SET /p BUILDNUMBER=<%currentBuild%
SET /A BUILDNUMBER = BUILDNUMBER + 1
echo %BUILDNUMBER% > %currentBuild%
echo build=%BUILDNUMBER%; > !currentBuildInc!

rem server pbo
SET SOURCE_PATH=%MAIN_PATH%\Sources\epoch_server
SET OUTPUT_PATH=%MAIN_PATH%\Server_Install_Pack\@EpochHive\addons
SET TEMP_PATH=x\addons\a3_epoch_server
rd /s/q p:\!TEMP_PATH!
xcopy /s/e/y/q/i "!SOURCE_PATH!" p:\!TEMP_PATH!
START "" /min /WAIT /b "!TOOLS_PATH!\AddonBuilder.exe" "P:\!TEMP_PATH!" "!OUTPUT_PATH!" -clear -prefix="!TEMP_PATH!" -project=P:\ -include=!AB_includes_path!

rem server core pbo
SET SOURCE_PATH=%MAIN_PATH%\Sources\epoch_server_core
SET OUTPUT_PATH=%MAIN_PATH%\Server_Install_Pack\@EpochHive\addons
SET TEMP_PATH=epoch_server_core
rd /s/q p:\!TEMP_PATH!
xcopy /s/e/y/q/i "!SOURCE_PATH!" p:\!TEMP_PATH!
START "" /min /WAIT /b "!TOOLS_PATH!\AddonBuilder.exe" "P:\!TEMP_PATH!" "!OUTPUT_PATH!" -clear -prefix="!TEMP_PATH!" -project=P:\ -include=!AB_includes_path!

rem server settings pbo
SET SOURCE_PATH=%MAIN_PATH%\Sources\epoch_server_settings
SET OUTPUT_PATH=%MAIN_PATH%\Server_Install_Pack\@EpochHive\addons
SET TEMP_PATH=a3_epoch_server_settings
rd /s/q p:\!TEMP_PATH!
xcopy /s/e/y/q/i "!SOURCE_PATH!" p:\!TEMP_PATH!
START "" /min /WAIT /b "!TOOLS_PATH!\AddonBuilder.exe" "P:\!TEMP_PATH!" "!OUTPUT_PATH!" -packonly -clear -prefix="!TEMP_PATH!" -project=P:\ -include=!AB_includes_path!

rem mpmissions pbos
SET SOURCE_PATH=%MAIN_PATH%\Sources
SET OUTPUT_PATH=%MAIN_PATH%\Server_Install_Pack\MPMissions
for /f "tokens=*" %%G in ('dir /b /s /a:d "!SOURCE_PATH!\mpmissions\epoch.*"') do (
	SET MISSION=%%~nxG

	rem removing temp folder
	rd /s/q p:\!MISSION!

	rem Moving files into temp folder
	xcopy /s/e/y/q/i/d "!SOURCE_PATH!\mpmissions\!MISSION!" p:\!MISSION!
	xcopy /s/y/q/i/f "!SOURCE_PATH!\description.ext" p:\!MISSION!
	xcopy /s/e/y/q/i/d "!SOURCE_PATH!\epoch_code" p:\!MISSION!\epoch_code
	xcopy /s/e/y/q/i/d "!SOURCE_PATH!\epoch_config" p:\!MISSION!\epoch_config
	
	START "" /min /WAIT /b "!TOOLS_PATH!\AddonBuilder.exe" "P:\!MISSION!" "!OUTPUT_PATH!" -clear -prefix=\ -project=P:\ -include=!AB_includes_path!

)
