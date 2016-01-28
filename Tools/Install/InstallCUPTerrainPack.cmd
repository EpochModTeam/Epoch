@ECHO OFF
SET STEAMUN=admin@youremail.net
SET STEAMPW=chamgeme
SET ARMASVRPATH=C:\Arma3Server
SET ARMAAPPID=107410

:: Use -mod line with quotes to support spaces in folder
:: Example: -mod="@Epoch;@CUP Terrains - Core;@CUP Terrains - Maps;"

:: Install CUP CORE

SET MODFOLDER=@CUP Terrains - Core
SET ARMAWORKSHOPID=583496184

:: remove old folder
rd /s/q "%ARMASVRPATH%\%MODFOLDER%"

:: update workshop mod
START "" /WAIT steamcmd.exe +login %STEAMUN% %STEAMPW% +workshop_download_item %ARMAAPPID% %ARMAWORKSHOPID% +quit

:: copy files back to server
xcopy /s/e/y/q/i "steamapps\workshop\content\%ARMAAPPID%\%ARMAWORKSHOPID%" "%ARMASVRPATH%\%MODFOLDER%"


:: Install CUP MAPS

SET MODFOLDER=@CUP Terrains - Maps
SET ARMAWORKSHOPID=583544987

:: remove old folder
rd /s/q "%ARMASVRPATH%\%MODFOLDER%"

:: update workshop mod
START "" /WAIT steamcmd.exe +login %STEAMUN% %STEAMPW% +workshop_download_item %ARMAAPPID% %ARMAWORKSHOPID% +quit

:: copy files back to server
xcopy /s/e/y/q/i "steamapps\workshop\content\%ARMAAPPID%\%ARMAWORKSHOPID%" "%ARMASVRPATH%\%MODFOLDER%"
