@Echo Off
SETLOCAL ENABLEDELAYEDEXPANSION

REM path to compiled mod
SET WORKSHOP_PATH=C:\Program Files (x86)\Steam\steamapps\common\Arma 3\@epochhive

REM steam workshop id to update
SET WORKSHOPID=1399533789

REM Arma 3 tools folder path
SET TOOLSPATH=C:\Program Files (x86)\Steam\steamapps\common\Arma 3 Tools

REM set tool paths
SET AddonBuilder=%TOOLSPATH%\AddonBuilder
SET Publisher=%TOOLSPATH%\Publisher

REM path to sources
SET MAIN_PATH=C:\Jenkins\workspace\hModTeam_Epoch_experimental-4BF7YIB2XXMEG3NYNJNCJCCUWHF7IEANIHR4LFGH2DZDQBP37UIA
SET SOURCE_PATH=%MAIN_PATH%\Sources

SET AB_includes_path="C:\GITTEMP\includes.txt"

REM set build and version paths
SET currentVersion="%MAIN_PATH%\version.txt"
SET currentBuild="%MAIN_PATH%\build.txt"

SET /p BUILDNUMBER=<%currentBuild%
SET /A BUILDNUMBER = BUILDNUMBER + 1
echo %BUILDNUMBER% > %currentBuild%

REM build all pbos
for /d %%D in ("%SOURCE_PATH%\*") do (
	if exist "%%~fD\config.cpp" (
		SET pboBuild="%%~fD\build.hpp"
		echo build=%BUILDNUMBER%; > !pboBuild!
		REM START "AddonBuilder" /min /WAIT "%AddonBuilder%\AddonBuilder.exe" "P:\%%~nxD" "%WORKSHOP_PATH%\addons" -packonly -clear -prefix="%%~nxD" -project="P:\%%~nxD" -include=%AB_includes_path%
		START "AddonBuilder" /min /WAIT "%AddonBuilder%\AddonBuilder.exe" "%%~fD" "%WORKSHOP_PATH%\addons" -packonly -clear -prefix="%%~nxD" -project="%%~fD" -include=%AB_includes_path%
		echo %%~nxD
	)
)

::allmaps
echo building mpmissions pbo's
SET clientBuildInc="%MAIN_PATH%\Sources\epoch_config\build.hpp"
echo build=%BUILDNUMBER%; > !clientBuildInc!

SET OUTPUT_PATH=%WORKSHOP_PATH%\MPMissions

for /f "tokens=*" %%G in ('dir /b /s /a:d "!SOURCE_PATH!\mpmissions\epoch.*"') do (
	SET MISSION=%%~nxG
	rd /s/q p:\!MISSION!
	rem Moving files into temp folder
	xcopy /s/e/y/q/i/d "!SOURCE_PATH!\mpmissions\!MISSION!" P:\!MISSION!
	xcopy /s/y/q/i/f "!SOURCE_PATH!\description.ext" P:\!MISSION!
	xcopy /s/e/y/q/i/d "!SOURCE_PATH!\epoch_code" P:\!MISSION!\epoch_code
	xcopy /s/e/y/q/i/d "!SOURCE_PATH!\epoch_config" P:\!MISSION!\epoch_config
	START "" /min /WAIT "%AddonBuilder%\AddonBuilder.exe" "P:\!MISSION!" "!OUTPUT_PATH!" -clear -prefix=\ -project=P:\ -include=!AB_includes_path!
	echo building !MISSION! pbo
)


REM upload to steam Workshop
SET SOURCE_PATH=%MAIN_PATH%\Server_Install_Pack

REM copy mod from steamcmd cache to server
REM xcopy /s/e/y/q/i "%SOURCE_PATH%\mpmissions" "%WORKSHOP_PATH%\mpmissions"
REM xcopy /s/e/y/q/i "%SOURCE_PATH%\@epochhive\addons" "%WORKSHOP_PATH%\addons"
xcopy /s/e/y/q/i "%SOURCE_PATH%\sc\battleye" "%WORKSHOP_PATH%\sc\battleye"

START "" /WAIT "%Publisher%\PublisherCmd.exe" update /id:%WORKSHOPID% /changeNote:"Build: %BUILDNUMBER% See Changelog: https://github.com/EpochModTeam/Epoch/blob/experimental/changelog.md" /path:"%WORKSHOP_PATH%"

exit /b 0
