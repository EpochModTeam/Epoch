@ECHO OFF
SET STEAMUN=admin@youremail.net
SET STEAMPW=chamgeme
SET ARMASVRPATH=C:\Arma3Server
SET ARMAAPPID=107410

:: Requires CUP CORE and MAPS!
:: Use -mod line with quotes to support spaces in folder
:: Example: -mod="@Epoch;@CUP Terrains - Core;@CUP Terrains - Maps;@esseker"

:: Install Esseker

SET MODFOLDER=@esseker
SET ARMAWORKSHOPID=498101407

:: remove old folder
rd /s/q "%ARMASVRPATH%\%MODFOLDER%"

:: update workshop mod
START "" /WAIT steamcmd.exe +login %STEAMUN% %STEAMPW% +workshop_download_item %ARMAAPPID% %ARMAWORKSHOPID% +quit

:: copy files back to server
xcopy /s/e/y/q/i "steamapps\workshop\content\%ARMAAPPID%\%ARMAWORKSHOPID%" "%ARMASVRPATH%\%MODFOLDER%"
